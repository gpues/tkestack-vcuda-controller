#include "include/all.h"

extern u_int64_t initial_offset;
extern u_int64_t in_fs_offset;
extern int memory_override;
extern bool duplicate_devices;
extern void **cachePtr;
extern sharedRegionT *global_config;
extern int pidfound;
extern volatile int g_cur_cuda_cores;
extern volatile int g_total_cuda_cores;
extern unsigned int virtual_devices[17];
extern unsigned int virtual_map[0x10];
extern unsigned int record_cuda_map[0x10];

extern int g_max_thread_per_sm;
extern int g_sm_num;

static const struct timespec g_wait = {
    .tv_sec = 0,
    .tv_nsec = 120 * MILLISEC,
};

int64_t find_proc_by_hostpid(unsigned int pid) {
    int i;
    for (i = 0; i < global_config->procnum; ++i) {
        if (pid == global_config->procs[i].hostpid)
            return global_config->procs[i].pid;
    }
    return 0LL;
}

int64_t get_used_gpu_utilization(void *arg) {
    utilization_t *top_result = (utilization_t *)arg;

    struct timeval tv;
    nvmlReturn_t ret;
    nvmlProcessInfo_v1_t *pids_on_device[MAX_PIDS];
    nvmlProcessUtilizationSample_t processes_sample[MAX_PIDS]; // [rsp+4060h] [rbp-8030h] BYREF
    nvmlDevice_t dev;
    size_t microsec;
    unsigned int processes_num = 1024;
    unsigned int running_processes = 0;

    for (int i = 0;; ++i) {
        if (i >= virtual_devices[0])
            return 0LL;

        nvmlReturn_t res = nvmlDeviceGetHandleByIndex(0, &dev);
        if (res)
            break;
        ret = nvmlDeviceGetComputeRunningProcesses(dev, &running_processes, (nvmlProcessInfo_v1_t *)&pids_on_device);
        if (ret != 7) {
            gettimeofday(&tv, 0LL);
            microsec = (tv.tv_sec - 1) * 1000UL * 1000UL + tv.tv_usec;
            ret = nvmlDeviceGetProcessUtilization(dev, processes_sample, &processes_num, microsec);
            if (ret == 7) {
                top_result[i].allTimeStamp = 0;
                top_result[i].allUsedGpuMemory = 0;
                for (int j = 0; j < running_processes; ++j) {
                    int64_t proc_by_hostpid = find_proc_by_hostpid(pids_on_device[j]->pid);
                    if (proc_by_hostpid) {
                        LINFO("pid=%u monitor=%lld", pids_on_device[j]->pid, pids_on_device[j]->usedGpuMemory);
                        top_result->allUsedGpuMemory += pids_on_device[j]->usedGpuMemory;
                    }
                    set_gpu_device_memory_monitor(pids_on_device[j]->pid, i, (int64_t)top_result->allUsedGpuMemory);
                }
            }
            else {
                for (int j = 0; j < processes_num; ++j) {
                    int64_t proc_by_hostpid = find_proc_by_hostpid(processes_sample[j].pid);
                    if (proc_by_hostpid) {
                        top_result->allTimeStamp += processes_sample[j].timeStamp;
                        top_result->allUsedGpuMemory += pids_on_device[j]->usedGpuMemory;
                    }
                    set_gpu_device_memory_monitor(processes_sample[j].pid, i, (int64_t)top_result->allUsedGpuMemory);
                }
                if (top_result->allTimeStamp < 0)
                    top_result->allTimeStamp = 0;
                if (top_result->allUsedGpuMemory < 0)
                    top_result->allUsedGpuMemory = 0;
            }
        }
    }
    LWARN("NVML error at line %d: %d", ret);
    return ret;
}

int64_t reset_task_pid() {
    char s[1000];
    sprintf(s, "cat /proc/%d/status | grep Ngid | awk '{printf $2}' ", getpid());
    LWARN("reset task_pid=%s", s);
    char line[112];
    FILE *stream = popen(s, "r");
    if (!stream) {
        LERROR("reset task_pid failed");
    }
    fgets(line, 100, stream);
    LWARN("number=%s", line);
    fclose(stream);
    return 0LL;
}
int64_t update_host_pid() {
    for (int i = 0; i < global_config->procnum; ++i) {
        if (global_config->procs[i].pid == getpid() && global_config->procs[i].hostpid)
            pidfound = 1;
    }
    return 0LL;
}
void utilization_watcher() {
    nvmlInit();
    int share;
    unsigned int v13[18];

    utilization_t top_result = {
        .allTimeStamp = 0,
        .allUsedGpuMemory = 0,
    };
    int current_device_sm_limit = get_current_device_sm_limit(virtual_map[0]);

    LINFO(" upper_limit=%d", current_device_sm_limit);

    while (1) {
        do {
            nanosleep(&g_wait, NULL);
            if (pidfound)
                break;
            update_host_pid();
        } while (!pidfound);
        get_used_gpu_utilization(v13);
        if (share == g_total_cuda_cores && g_cur_cuda_cores < 0) {
            g_total_cuda_cores *= 2;
            share = g_total_cuda_cores;
        }

        share = delta(current_device_sm_limit, top_result.user_current, share);
        change_token(share);
    }
}

int init_utilization_watcher() {
    pthread_t newthread;
    sharedRegionT flags_bak = *global_config;
    LINFO("set core utilization limit to  %d", get_current_device_sm_limit(0LL));
    setspec();
    char *envName = getenv("MEMORY_OVERRIDE");
    memory_override = 0;
    if (!duplicate_devices && envName && *envName != '0')
        memory_override = *envName != 'f';
    if ((int)get_current_device_sm_limit(0) <= 'c' && (int)get_current_device_sm_limit(0LL) > 0)
        pthread_create(&newthread, 0LL, (void *(*)(void *))utilization_watcher, 0LL);
    return flags_bak.initializedFlag ^ global_config->initializedFlag;
}

int delta(int up_limit, int user_current, int share) {
    int utilization_diff = abs(up_limit - user_current) < 4 ? 4 : abs(up_limit - user_current);
    int increment = utilization_diff * g_sm_num * g_sm_num * g_max_thread_per_sm / 2560;

    /* Accelerate cuda cores allocation when utilization vary widely */
    if (utilization_diff > up_limit / 2) {
        increment = increment * utilization_diff * 2 / (up_limit + 1);
    }

    if (user_current > up_limit) {
        if (share < increment)
            return 0;
        return share - increment;
    }
    else if (increment + share > g_total_cuda_cores) {
        return g_total_cuda_cores;
    }
    else {
        return share + increment;
    }
}
