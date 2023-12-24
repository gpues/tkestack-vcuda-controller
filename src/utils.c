#include <dlfcn.h>
#include <pthread.h>
#include <regex.h>
#include <stdio.h>

#include "include/all.h"

extern int virtual_map[0x10];
extern unsigned int virtual_devices[17];
extern unsigned int cuda_to_nvml_map[0x10];
extern u_int64_t context_size;
extern vmDevice vdevices[0x10];
extern int record_nvml_map[0x10];
extern void *cuda_library_entry[1024];
extern sharedRegionT *global_config;
extern int env_utilization_switch;
extern char *unified_lock;
extern unsigned int record_cuda_map[16];
extern volatile int g_cur_cuda_cores;
extern struct timespec g_cycle;

void matchRegex(const char *pattern, const char *matchString, char *version) {
    regex_t regex;
    int reti;
    regmatch_t matches[1];
    char msgbuf[512];

    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) {
        LERROR("Could not compile regex: %s", DRIVER_VERSION_MATCH_PATTERN);
        return;
    }

    reti = regexec(&regex, matchString, 1, matches, 0);
    switch (reti) {
        case 0:
            strncpy(version, matchString + matches[0].rm_so, matches[0].rm_eo - matches[0].rm_so);
            version[matches[0].rm_eo - matches[0].rm_so] = '\0';
            break;
        case REG_NOMATCH:
            LERROR("Regex does not match for string: %s", matchString);
            break;
        default:
            regerror(reti, &regex, msgbuf, sizeof(msgbuf));
            LERROR("Regex match failed: %s", msgbuf);
    }

    regfree(&regex);
}

void read_version_from_proc(char *version) {
    char *line = NULL;
    size_t len = 0;
    FILE *fp = fopen(DRIVER_VERSION_PROC_PATH, "r");
    if (fp == NULL) {
        LERROR("can't open %s, error %s", DRIVER_VERSION_PROC_PATH, strerror(errno));
        return;
    }
    while ((getline(&line, &len, fp) != -1)) {
        if (strncmp(line, "NVRM", 4) == 0) {
            matchRegex(DRIVER_VERSION_MATCH_PATTERN, line, version);
            break;
        }
    }
    fclose(fp);
}

size_t getextrapid(unsigned int prevPidsCount, unsigned int currentPidsCount, nvmlProcessInfo_v1_t *prevPidsPtr, nvmlProcessInfo_v1_t *currentPidsPtr) {
    for (int i = 0; i < prevPidsCount; ++i) {
        LINFO("prev pids[%d]=%d", i, prevPidsPtr[i].pid);
    }
    for (int j = 0; j < currentPidsCount; ++j) {
        LINFO("current pids[%d]=%d", j, currentPidsPtr[j].pid);
    }
    if (currentPidsCount == prevPidsCount)
        return 0LL;
    for (int k = 0; k < currentPidsCount; ++k) {
        int found = 0;
        for (int m = 0; prevPidsCount > m; ++m) {
            if (currentPidsPtr[k].pid == prevPidsPtr[m].pid) {
                found = 1;
                break;
            }
        }
        if (!found)
            return *(unsigned int *)(0x10 * (int)k + currentPidsPtr);
    }
    return 0LL;
}

// 比较两个数组进行合并
size_t mergepid(const unsigned int *prevPidsCount, const unsigned int *currentPidsCount, nvmlProcessInfo_v1_t *prevPidsPtr, nvmlProcessInfo_v1_t *currentPidsPtr) {
    for (int i = 0; i < *prevPidsCount; ++i) {
        int found = 0;
        for (int j = 0; j < *currentPidsCount; ++j) {
            LINFO("merged pid=%d", prevPidsPtr[i].pid);
            if (prevPidsPtr[i].pid == currentPidsPtr[j].pid) {
                found = 1;
                break;
            }
        }
        if (!found) {
            // 当前的列表中没有找到，就合并
            LINFO("merged pid=%d", prevPidsPtr[i].pid);
            currentPidsPtr[*currentPidsCount].pid = prevPidsPtr[i].pid;
            currentPidsCount++;
        }
    }
    return 0LL;
}

size_t set_task_pid() {
    unsigned int currentPidsCount;        // [rsp+8h] [rbp-C064h] BYREF
    unsigned int i;                       // [rsp+Ch] [rbp-C060h]
    unsigned int HandleByIndex;           // [rsp+18h] [rbp-C054h]
    unsigned int v73;                     // [rsp+20h] [rbp-C04Ch]
    unsigned int ComputeRunningProcesses; // [rsp+24h] [rbp-C048h]
    unsigned int v75;                     // [rsp+28h] [rbp-C044h]

    const int PIDMAX = 16384;
    int dev;
    nvmlProcessInfo_v1_t currentPidsPtr[PIDMAX]; // [rsp+803Ch] [rbp-4030h] BYREF
    nvmlProcessInfo_v1_t prevPidsPtr[PIDMAX];
    CUcontext ptcx;
    unsigned int prevPidsCount = 0;

    currentPidsCount = 0;
    nvmlReturn_t res = nvmlInit();
    if (res) {
        LWARN("NVML error at line %d: %d", __LINE__, res);
        return res;
    }
    else {
        nvmlDevice_t nd;
        HandleByIndex = nvmlDeviceGetHandleByIndex(virtual_map[0], &nd);
        if (HandleByIndex) {
            LWARN("NVML error at line %d: %d", __LINE__, HandleByIndex);
            return HandleByIndex;
        }
        else {
            unsigned int prevCurrentPidsCount = -1;
            for (i = 0;; ++i) {
                if (i >= virtual_devices[0]) {
                    prevCurrentPidsCount = currentPidsCount;
                    currentPidsCount = 0;
                    memset(prevPidsPtr, 0, 0x4000uLL);
                    if (cuDevicePrimaryCtxRetain(&ptcx, 0LL)) {
                        LERROR("Driver error at %d: %d", __LINE__, errno);
                        return cuDevicePrimaryCtxRetain(&ptcx, 0LL);
                    }
                    else {
                        dev = -1;
                        for (i = 0;; ++i) {
                            if (i >= virtual_devices[0]) {
                                LINFO("current processes num = %u %u", prevCurrentPidsCount, currentPidsCount);
                                for (i = 0; i < currentPidsCount; ++i) {
                                    LINFO("current pid in use is %d %d", i, currentPidsPtr[i].pid);
                                }
                                size_t hpid = getextrapid(prevCurrentPidsCount, prevPidsCount, &prevPidsPtr[0], &currentPidsPtr[0]);
                                if (hpid) {
                                    LINFO("hostPid=%d", 190LL, hpid);
                                    if (!set_host_pid(hpid)) {
                                        for (i = 0; i < prevPidsCount; ++i) {
                                            if (hpid == currentPidsPtr[i].pid) {
                                                LINFO("Primary Context Size==%lld", 190LL, prevPidsPtr[i].usedGpuMemory);
                                                context_size = prevPidsPtr[i].usedGpuMemory;
                                                break;
                                            }
                                        }
                                    }
                                    if (cuDevicePrimaryCtxRelease_v2(0LL)) {
                                        LERROR("Driver error at %d: %d", __LINE__, cuDevicePrimaryCtxRelease_v2(0LL));
                                        return cuDevicePrimaryCtxRelease_v2(0LL);
                                    }
                                    else {
                                        vdevices[cuda_to_nvml_map[0]].add_gpu_flag = 0;
                                        return 0LL;
                                    }
                                }
                                else {
                                    LWARN("host pid is error");
                                    return 9LL;
                                }
                            }
                            if (dev != virtual_map[i])
                                break;
                        LABEL_59:;
                        }
                        dev = virtual_map[i];
                        LWARN("CHECKING... %d:%d ", i, cuda_to_nvml_map[i]);
                        v73 = nvmlDeviceGetHandleByIndex(cuda_to_nvml_map[i], &nd);
                        if (v73) {
                            LWARN("NVML error at line %d: %d", __LINE__, v73);
                            return v73;
                        }
                        else {
                            while (1) {
                                ComputeRunningProcesses = nvmlDeviceGetComputeRunningProcesses(nd, &prevPidsCount, &prevPidsPtr[0]);
                                if (ComputeRunningProcesses) {
                                    if (ComputeRunningProcesses != NVML_ERROR_INSUFFICIENT_SIZE)
                                        break;
                                }
                                if (ComputeRunningProcesses != NVML_ERROR_INSUFFICIENT_SIZE) {
                                    mergepid(&prevPidsCount, &currentPidsCount, &prevPidsPtr[0], &currentPidsPtr[0]);
                                    goto LABEL_59;
                                }
                            }
                            LWARN("Device2GetComputeRunningProcesses failed %d", ComputeRunningProcesses);
                            return ComputeRunningProcesses;
                        }
                    }
                }
                if (dev != virtual_map[i])
                    break;
            LABEL_31:;
            }
            dev = virtual_map[i];
            v75 = nvmlDeviceGetHandleByIndex(cuda_to_nvml_map[i], &nd);
            if (v75) {
                LWARN("NVML error at line %d: %d", __LINE__, v75);
                return v75;
            }
            else {
                while (1) {
                    ComputeRunningProcesses = nvmlDeviceGetComputeRunningProcesses(nd, &prevCurrentPidsCount, &prevPidsPtr[0]);
                    if (ComputeRunningProcesses) {
                        if (ComputeRunningProcesses != NVML_ERROR_INSUFFICIENT_SIZE)
                            break;
                    }
                    if (ComputeRunningProcesses != NVML_ERROR_INSUFFICIENT_SIZE) {
                        mergepid(&prevCurrentPidsCount, &currentPidsCount, &prevPidsPtr[0], &currentPidsPtr[0]);
                        goto LABEL_31;
                    }
                }
                LWARN("Device2GetComputeRunningProcesses failed %d,%d %d", ComputeRunningProcesses, i, virtual_map[i]);
                return ComputeRunningProcesses;
            }
        }
    }
}

unsigned int getenvcount() {
    const char *s = getenv("CUDA_VISIBLE_DEVICES");
    if (s && *s) {
        LINFO("get from env %s", s);
        int count = 0;
        for (int i = 0; i < strlen(s); ++i) {
            if (s[i] == ',')
                ++count;
        }
        return (count + 1);
    }
    else {
        LINFO("get default cuda %d", virtual_devices[0]);
        return virtual_devices[0];
    }
}

size_t prior_function(char *a1) {
    char *v2;
    v2 = &a1[strlen(a1) - 3];
    if (*v2 != '_' || v2[1] != 'v')
        return 0LL;
    if (v2[2] == '2')
        *v2 = 0;
    else
        --v2[2];
    return 1;
}

void try_unlock_unified_lock() {
    LINFO("try unlock_unified_lock:%d", remove(unified_lock));
}

bool need_cuda_virtualize() {
    char *env = getenv("CUDA_VISIBLE_DEVICES");
    if (!env || !*env)
        return 0LL;

    int count;
    LINFO("Hijacking %s", "cuDeviceGetCount");
    CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetCount, &count);
    LWARN("count1=%d", count);
    return getenvcount() == count;
}

size_t parse_cuda_visible_env() {
    char *nptr = getenv("CUDA_VISIBLE_DEVICES");
    int lastIndex = -1;

    if (need_cuda_virtualize() && getenv("NVIDIA_DEVICE_MAP")) {
        int decCount = 0;
        for (int i = 0; i < strlen(nptr); ++i) {
            if (nptr[i] == ',' || !i) {
                int cudaIndex;
                if (i)
                    cudaIndex = atoi(&nptr[i + 1]);
                else
                    cudaIndex = atoi(nptr);
                if (lastIndex != -1 && virtual_map[cudaIndex] == virtual_map[lastIndex]) {
                    LWARN("device index %d and %d are the same physical device, it may incur an error, try selecting different combinations", cudaIndex, lastIndex);
                }
                else {
                    cuda_to_nvml_map[decCount] = cudaIndex;
                    record_cuda_map[decCount] = record_nvml_map[cudaIndex];
                    lastIndex = cudaIndex;
                    ++decCount;
                }
            }
        }
        for (int j = 0; j < decCount; ++j) {
            LWARN("i=%d:%d:%d:%d", j, virtual_map[j], record_cuda_map[j], cuda_to_nvml_map[j]);
        }
        virtual_devices[0] = decCount;
        LWARN("virtual_devices=%d", virtual_devices[0]);
        return (unsigned int)(decCount + 1);
    }
    else {
        unsigned int devCount = 0;
        if (!getenv("NVIDIA_DEVICE_MAP") && need_cuda_virtualize()) {
            memset(record_cuda_map, 0, sizeof(record_cuda_map));
            for (int k = 0; k < strlen(nptr); ++k) {
                if (nptr[k] == ' ' || !k) {
                    int devIndex = k ? atoi(&nptr[k + 1]) : atoi(nptr);
                    if (lastIndex == -1 || virtual_map[devIndex] != virtual_map[lastIndex]) {
                        record_cuda_map[devCount] = record_nvml_map[devIndex];
                        ++devCount;
                        lastIndex = devIndex;
                    }
                }
            }
            virtual_devices[0] = devCount;
        }
        LWARN("get default cuda %d from %s", virtual_devices[0], getenv("CUDA_VISIBLE_DEVICES"));
        return virtual_devices[0];
    }
}

size_t get_utilization_switch() {
    if (env_utilization_switch == 1)
        return 1LL;
    if (env_utilization_switch == 2)
        return 0LL;
    return global_config->procnum;
}

void try_lock_unified_lock() {
    int fd = open(unified_lock, O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    int count = 0;
    LINFO("try_lock_unified_lock:%d filename=%s", fd, unified_lock);
    while (fd == -1) {
        if (count == 20) {
            LINFO("unified_lock expired,removing...");
            remove(unified_lock);
        }
        else {
            LINFO("unified_lock locked, waiting 1 second...");
            sleep(rand() % 5 + 1);
        }
        ++count;
        fd = open(unified_lock, O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    }
}

char *curr_time() {
    time_t *nullptr = NULL;
    time_t raw_time = time(nullptr);
    struct tm *time_info = localtime(&raw_time);
    static char now_time[64];
    now_time[strftime(now_time, sizeof(now_time), "%Y-%m-%d %H:%M:%S", time_info)] = '\0';
    return now_time;
}

u_int64_t rate_limiter(unsigned int grids, unsigned int blocks) {
    while (global_config->recentKernel < 0)
        sleep(1u);
    global_config->recentKernel = 2;
    u_int64_t result = get_current_device_sm_limit(0LL);
    if (result <= 99) {
        result = get_current_device_sm_limit(0LL);
        if (result) {
            result = get_utilization_switch();
            if (result) {
                LINFO("grid: %d, blocks: %d", grids, blocks);
                LERROR("launch kernel %d, curr core: %d", grids, g_cur_cuda_cores);
                int before_cuda_cores;
            CHECK:
                do {
                    before_cuda_cores = g_cur_cuda_cores;
                    LINFO("current core: %d", g_cur_cuda_cores);
                    if (before_cuda_cores < 0) {
                        nanosleep(&g_cycle, NULL);
                        goto CHECK;
                    }
                } while (!CAS(&g_cur_cuda_cores, g_cur_cuda_cores - grids, g_cur_cuda_cores));
            }
        }
    }
    return result;
}

void *my_dlvsym(void *handle, const char *symbol, const char *version) {
    return dlvsym(handle, symbol, version);
}
