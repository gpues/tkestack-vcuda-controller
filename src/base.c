#include "include/base.h"

#include <dlfcn.h>
#include <errno.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <sys/time.h>

#include "include/json/cJSON.h"
#include "stdio.h"
#include "string.h"
#include "time.h"
char *curr_time() {
    time_t *nullptr = NULL;
    time_t raw_time = time(nullptr);
    struct tm *time_info = localtime(&raw_time);
    static char now_time[64];
    now_time[strftime(now_time, sizeof(now_time), "%Y-%m-%d %H:%M:%S", time_info)] = '\0';
    return now_time;
}

char *CudaSo() {
    return "/lib/x86_64-linux-gnu/libcuda.so.1";
}
char *NvmlSo() {
    return "/lib/x86_64-linux-gnu/libnvidia-ml.so.1";
}

void TimeProfileDestroy(HOOK_TRACE_PROFILE *obj) {
    clock_t end = clock();
    double cpu_time_used = (double)(end - obj->start);
    HLOG(INFO, "%s exit, taken %.3f ms", obj->name, cpu_time_used);
}

HOOK_TRACE_PROFILE *TimeProfile(char *name) {
    HOOK_TRACE_PROFILE *wrapper = malloc(sizeof(HOOK_TRACE_PROFILE));
    wrapper->name = name;
    wrapper->start = clock();
    //    HLOG(INFO, "enter %s", name);
    return wrapper;
}
char *Marshal(resource_data_t t) {
    cJSON *monitor = cJSON_CreateObject();

    cJSON_AddItemToObject(monitor, "pod_uid", cJSON_CreateString(t.pod_uid));
    cJSON_AddItemToObject(monitor, "hard_limit", cJSON_CreateNumber(t.hard_limit));
    cJSON_AddItemToObject(monitor, "occupied", cJSON_CreateString(t.occupied));
    cJSON_AddItemToObject(monitor, "container_name", cJSON_CreateString(t.container_name));
    cJSON_AddItemToObject(monitor, "bus_id", cJSON_CreateString(t.bus_id));
    cJSON_AddItemToObject(monitor, "gpu_memory", cJSON_CreateNumber(t.gpu_memory));
    cJSON_AddItemToObject(monitor, "limit", cJSON_CreateNumber(t.limit));
    cJSON_AddItemToObject(monitor, "hard_limit", cJSON_CreateNumber(t.hard_limit));
    cJSON_AddItemToObject(monitor, "utilization", cJSON_CreateNumber(t.utilization));
    cJSON_AddItemToObject(monitor, "enable", cJSON_CreateNumber(t.enable));
    return cJSON_Print(monitor);
}

resource_data_t UnMarshal(char *s) {
    resource_data_t t = {};
    cJSON *monitor_json = cJSON_Parse(s);

    cJSON *pod_uid = cJSON_GetObjectItemCaseSensitive(monitor_json, "pod_uid");
    if (pod_uid != NULL) {
        strcpy(t.pod_uid, pod_uid->valuestring);
    }
    cJSON *occupied = cJSON_GetObjectItemCaseSensitive(monitor_json, "occupied");
    if (occupied != NULL) {
        strcpy(t.occupied, occupied->valuestring);
    }
    cJSON *container_name = cJSON_GetObjectItemCaseSensitive(monitor_json, "container_name");
    if (container_name != NULL) {
        strcpy(t.container_name, container_name->valuestring);
    }
    cJSON *bus_id = cJSON_GetObjectItemCaseSensitive(monitor_json, "bus_id");
    if (bus_id != NULL) {
        strcpy(t.bus_id, bus_id->valuestring);
    }
    cJSON *enable = cJSON_GetObjectItemCaseSensitive(monitor_json, "enable");
    if (bus_id != NULL) {
        t.enable = enable->valueint;
    }
    cJSON *limit = cJSON_GetObjectItemCaseSensitive(monitor_json, "limit");
    if (bus_id != NULL) {
        t.limit = limit->valueint;
    }
    cJSON *hard_limit = cJSON_GetObjectItemCaseSensitive(monitor_json, "hard_limit");
    if (bus_id != NULL) {
        t.hard_limit = hard_limit->valueint;
    }
    cJSON *gpu_memory = cJSON_GetObjectItemCaseSensitive(monitor_json, "gpu_memory");
    if (gpu_memory != NULL) {
        t.gpu_memory = gpu_memory->valueint;
    }
    cJSON *utilization = cJSON_GetObjectItemCaseSensitive(monitor_json, "utilization");
    if (utilization != NULL) {
        t.utilization = utilization->valueint;
    }

    return t;
}

extern resource_data_t g_vcuda_config;

static volatile int g_cur_cuda_cores = 0;
static volatile int g_total_cuda_cores = 0;

static int g_max_thread_per_sm = 0;
static int g_sm_num = 0; //  流处理多处理器，它是GPU的核心计算单元，也被称作为CUDA核或CUDA流处理器。SM是一个独立的处理单元，包含一组处理器核心、缓存和共享内存等资源。

static const struct timespec g_cycle = {
    .tv_sec = 0,
    .tv_nsec = TIME_TICK * MILLISEC,
};

static const struct timespec g_wait = {
    .tv_sec = 0,
    .tv_nsec = 120 * MILLISEC,
};

/** pid mapping related */
static int g_pids_table[MAX_PIDS];
static int g_pids_table_size;

typedef struct {
    int user_current;
    int sys_current;
    int valid;
    uint64_t checktime;
    unsigned int sys_process_num;
} utilization_t;

void *utilization_watcher(void *arg UNUSED) {
    utilization_t top_result = {
        .user_current = 0,
        .sys_current = 0,
        .sys_process_num = 0,
    };
    int sys_free = 0;
    int share = 0;
    int i = 0;
    unsigned int avg_sys_free = 0;
    unsigned int pre_sys_process_num = 1;
    int up_limit = g_vcuda_config.utilization;

    HLOG(INFO, "start %s", __FUNCTION__);
    HLOG(INFO, "sm: %d, thread per sm: %d", g_sm_num, g_max_thread_per_sm);
    while (1) {
        nanosleep(&g_wait, NULL);
        do {
            atomic_action(PIDS_CONFIG_PATH, get_used_gpu_utilization, (void *)&top_result);
        } while (!top_result.valid);

        sys_free = MAX_UTILIZATION - top_result.sys_current;

        if (g_vcuda_config.hard_limit) {
            /* Avoid usage jitter when application is initialized*/
            if (top_result.sys_process_num == 1 && top_result.user_current < up_limit / 10) {
                g_cur_cuda_cores = delta(g_vcuda_config.utilization, top_result.user_current, share);
                continue;
            }
            share = delta(g_vcuda_config.utilization, top_result.user_current, share);
        }
        else {
            if (pre_sys_process_num != top_result.sys_process_num) {
                /* When a new process comes, all processes are reset to initial value*/
                if (pre_sys_process_num < top_result.sys_process_num) {
                    share = g_max_thread_per_sm;
                    up_limit = g_vcuda_config.utilization;
                    i = 0;
                    avg_sys_free = 0;
                }
                pre_sys_process_num = top_result.sys_process_num;
            }

            /* 1.Only one process on the GPU
             * Allocate cuda cores according to the limit value.
             *
             * 2.Multiple processes on the GPU
             * First, change the up_limit of the process according to the
             * historical resource utilization. Second, allocate the cuda
             * cores according to the changed limit value.*/
            if (top_result.sys_process_num == 1) {
                share = delta(g_vcuda_config.limit, top_result.user_current, share);
            }
            else {
                i++;
                avg_sys_free += sys_free;
                if (i % CHANGE_LIMIT_INTERVAL == 0) {
                    if (avg_sys_free * 2 / CHANGE_LIMIT_INTERVAL > USAGE_THRESHOLD) {
                        up_limit = up_limit + g_vcuda_config.utilization / 10 > g_vcuda_config.limit ? g_vcuda_config.limit : up_limit + g_vcuda_config.utilization / 10;
                    }
                    i = 0;
                }
                avg_sys_free = i % (CHANGE_LIMIT_INTERVAL / 2) == 0 ? 0 : avg_sys_free;
                share = delta(up_limit, top_result.user_current, share);
            }
        }

        change_token(share);

        HLOG(INFO, "util: %d, up_limit: %d,  share: %d, cur: %d", top_result.user_current, up_limit, share, g_cur_cuda_cores);
    }
}
void active_utilization_notifier() {
    pthread_t tid;
    pthread_create(&tid, NULL, utilization_watcher, NULL);
#ifdef __APPLE__
    pthread_setname_np("utilization_watcher");
#else
    pthread_setname_np(tid, "utilization_watcher");
#endif
}
void write_cuda_config() {
    nvmlDevice_t nvml_dev;
    unsigned int deviceCount = 0;
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(unsigned int) = (CUresult(*)(unsigned int))dlsym(cuda_handle, "cuInit");
    HOOK_CHECK(hookFunc);
    hookFunc(0);
    nvmlInit();
    nvmlDeviceGetCount(&deviceCount);
    strcpy(g_vcuda_config.bus_id, "");
    for (int i = 0; i < deviceCount; i++) {
        nvmlPciInfo_t pci_info;
        nvmlReturn_t ret = nvmlDeviceGetHandleByIndex(i, &nvml_dev);
        if (ret != NVML_SUCCESS) {
            HLOG(FATAL, "can't find device 0, error %d", ret);
        }
        ret = nvmlDeviceGetPciInfo_v3(nvml_dev, &pci_info);
        if (ret != NVML_SUCCESS) {
            HLOG(FATAL, "can't find device 0, error %d", ret);
        }
        strcat(g_vcuda_config.bus_id, pci_info.busId);
        if (i + 1 < deviceCount) {
            strcat(g_vcuda_config.bus_id, ",");
        }
    }

    char *str = Marshal(g_vcuda_config);
    FILE *fp = fopen(CONTROLLER_CONFIG_PATH, "wb");
    if (fp == NULL) {
        HLOG(FATAL, "Failed to open file %s", CONTROLLER_CONFIG_PATH);
    }
    fwrite(str, sizeof(char), strlen(str), fp);
    fclose(fp);
}

void initialization() {
    HLOG(INFO, "enter %s", __FUNCTION__);
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(unsigned int) = (CUresult(*)(unsigned int))dlsym(cuda_handle, "cuInit");
    HOOK_CHECK(hookFunc);
    CUresult ret = hookFunc(0);
    const char *cuda_err_string = NULL;
    if (ret != CUDA_SUCCESS) {
        HLOG(FATAL, "cuInit error %s", cuGetErrorString((CUresult)ret, &cuda_err_string));
    }

    ret = cuDeviceGetAttribute(&g_sm_num, CU_DEVICE_ATTRIBUTE_MULTIPROCESSOR_COUNT, 0);

    if (ret != CUDA_SUCCESS) {
        HLOG(FATAL, "can't get processor number, error %s", cuGetErrorString((CUresult)ret, &cuda_err_string));
    }

    ret = cuDeviceGetAttribute(&g_max_thread_per_sm, CU_DEVICE_ATTRIBUTE_MAX_THREADS_PER_MULTIPROCESSOR, 0);
    if (ret != CUDA_SUCCESS) {
        HLOG(FATAL, "can't get max thread per processor, error %s", cuGetErrorString((CUresult)ret, &cuda_err_string));
    }

    g_total_cuda_cores = g_max_thread_per_sm * g_sm_num * FACTOR;
    HLOG(INFO, "total cuda cores: %d", g_total_cuda_cores);
    active_utilization_notifier();
}
void get_used_gpu_memory(int fd, void *arg) {
    size_t *used_memory = arg;
    nvmlDevice_t dev;
    nvmlProcessInfo_t *pids_on_device = NULL;
    unsigned int size_on_device = MAX_PIDS;
    int ret;
    unsigned int i;
    load_pids_table(fd, NULL);
    ret = nvmlDeviceGetHandleByIndex(0, &dev);
    if (unlikely(ret)) {
        HLOG(INFO, "nvmlDeviceGetHandleByIndex can't find device 0, return %d", ret);
        *used_memory = g_vcuda_config.gpu_memory;
        return;
    }

    ret = nvmlDeviceGetComputeRunningProcesses_v3(dev, &size_on_device, pids_on_device);
    if (unlikely(ret)) {
        HLOG(INFO, "nvmlDeviceGetComputeRunningProcesses_v3 can't get pids on device 0, return %d", ret);
        *used_memory = g_vcuda_config.gpu_memory;
        return;
    }

    for (i = 0; i < size_on_device; i++) {
        HLOG(INFO, "num:%d summary: %d used %lld", i, pids_on_device[i].pid, pids_on_device[i].usedGpuMemory);
    }

    for (i = 0; i < size_on_device; i++) {
        if (bsearch(&pids_on_device[i].pid, g_pids_table, (size_t)g_pids_table_size, sizeof(int), int_match)) {
            HLOG(INFO, "%d use memory: %lld", pids_on_device[i].pid, pids_on_device[i].usedGpuMemory);
            *used_memory += pids_on_device[i].usedGpuMemory;
        }
    }

    HLOG(INFO, "total used memory: %zu", *used_memory);
}
void rate_limiter(unsigned int grids, unsigned int blocks) {
    int before_cuda_cores = 0;
    unsigned int after_cuda_cores = 0;
    unsigned int kernel_size = grids;

    HLOG(INFO, "grid: %d, blocks: %d", grids, blocks);
    HLOG(INFO, "launch kernel %d, curr core: %d", kernel_size, g_cur_cuda_cores);
    if (g_vcuda_config.enable) {
        do {
        CHECK:
            before_cuda_cores = g_cur_cuda_cores;
            HLOG(INFO, "current core: %d", g_cur_cuda_cores);
            if (before_cuda_cores < 0) {
                nanosleep(&g_cycle, NULL);
                goto CHECK;
            }
            after_cuda_cores = before_cuda_cores - kernel_size;
        } while (!CAS(&g_cur_cuda_cores, before_cuda_cores, after_cuda_cores));
    }
}
size_t get_array_base_size(int format) {
    size_t base_size = 0;

    switch (format) {
        case CU_AD_FORMAT_UNSIGNED_INT8:
        case CU_AD_FORMAT_SIGNED_INT8:
            base_size = 8;
            break;
        case CU_AD_FORMAT_UNSIGNED_INT16:
        case CU_AD_FORMAT_SIGNED_INT16:
        case CU_AD_FORMAT_HALF:
            base_size = 16;
            break;
        case CU_AD_FORMAT_UNSIGNED_INT32:
        case CU_AD_FORMAT_SIGNED_INT32:
        case CU_AD_FORMAT_FLOAT:
            base_size = 32;
            break;
        default:
            base_size = 32;
    }

    return base_size;
}
CUresult cuArray3DCreate_helper(const CUDA_ARRAY3D_DESCRIPTOR *pAllocateArray) {
    size_t used = 0;
    size_t base_size = 0;
    size_t request_size = 0;
    CUresult ret = CUDA_SUCCESS;

    if (g_vcuda_config.enable) {
        base_size = get_array_base_size(pAllocateArray->Format);
        request_size = base_size * pAllocateArray->NumChannels * pAllocateArray->Height * pAllocateArray->Width * pAllocateArray->Depth;

        atomic_action(PIDS_CONFIG_PATH, get_used_gpu_memory, (void *)&used);
        HLOG(INFO, "%s %d %d", Marshal(g_vcuda_config), used, request_size);

        if (unlikely(used + request_size > g_vcuda_config.gpu_memory)) {
            ret = CUDA_ERROR_OUT_OF_MEMORY;
            goto DONE;
        }
    }
DONE:
    return ret;
}
CUresult cuArrayCreate_helper(const CUDA_ARRAY_DESCRIPTOR *pAllocateArray) {
    size_t used = 0;
    size_t base_size = 0;
    size_t request_size = 0;
    CUresult ret = CUDA_SUCCESS;

    if (g_vcuda_config.enable) {
        base_size = get_array_base_size(pAllocateArray->Format);
        request_size = base_size * pAllocateArray->NumChannels * pAllocateArray->Height * pAllocateArray->Width;

        atomic_action(PIDS_CONFIG_PATH, get_used_gpu_memory, (void *)&used);
        HLOG(INFO, "%s %d %d", Marshal(g_vcuda_config), used, request_size);

        if (unlikely(used + request_size > g_vcuda_config.gpu_memory)) {
            ret = CUDA_ERROR_OUT_OF_MEMORY;
            goto DONE;
        }
    }

DONE:
    return ret;
}
int delta(int up_limit, int user_current, int share) {
    int utilization_diff = abs(up_limit - user_current) < 5 ? 5 : abs(up_limit - user_current);
    int increment = g_sm_num * g_sm_num * g_max_thread_per_sm / 256 * utilization_diff / 10;

    /* Accelerate cuda cores allocation when utilization vary widely */
    if (utilization_diff > up_limit / 2) {
        increment = increment * utilization_diff * 2 / (up_limit + 1);
    }

    if (unlikely(increment < 0)) {
        HLOG(INFO, "overflow: %d, current sm: %d, thread_per_sm: %d, diff: %d", increment, g_sm_num, g_max_thread_per_sm, utilization_diff);
    }

    if (user_current <= up_limit) {
        share = share + increment > g_total_cuda_cores ? g_total_cuda_cores : share + increment;
    }
    else {
        share = share - increment < 0 ? 0 : share - increment;
    }

    return share;
}
void load_pids_table(int fd, void *arg UNUSED) {
    int item = 0;
    int rsize = 0;
    int i = 0;

    for (item = 0; item < MAX_PIDS; item++) {
        rsize = (int)read(fd, g_pids_table + item, sizeof(int));
        if (unlikely(rsize != sizeof(int))) {
            break;
        }
    }

    for (i = 0; i < item; i++) {
        HLOG(INFO, "pid: %d", g_pids_table[i]);
    }

    g_pids_table_size = item;

    HLOG(INFO, "read %d items from %s", g_pids_table_size, PIDS_CONFIG_PATH);
}
void atomic_action(const char *filename, atomic_fn_ptr fn_ptr, void *arg) {
    int fd;

    fd = open(filename, O_RDONLY);
    if (unlikely(fd == -1)) {
        HLOG(FATAL, "can't open %s, error %s", filename, strerror(errno));
    }
    fn_ptr(fd, arg);
    close(fd);
}
void get_used_gpu_utilization(int fd, void *arg) {
    nvmlProcessUtilizationSample_t processes_sample[MAX_PIDS];
    unsigned int processes_num = 0;
    unsigned int running_processes = 0;
    nvmlProcessInfo_t *pids_on_device = NULL;
    nvmlDevice_t dev;
    utilization_t *top_result = (utilization_t *)arg;
    nvmlReturn_t ret;
    struct timeval cur;
    size_t microsec;
    int codec_util = 0;

    int i;

    ret = nvmlDeviceGetHandleByIndex(0, &dev);
    if (unlikely(ret)) {
        HLOG(INFO, "nvmlDeviceGetHandleByIndex: %s", nvmlErrorString(ret));
        return;
    }

    ret = nvmlDeviceGetComputeRunningProcesses_v3(dev, &running_processes, pids_on_device);
    if (unlikely(ret)) {
        HLOG(INFO, "nvmlDeviceGetComputeRunningProcesses_v3: %s", nvmlErrorString(ret));
        return;
    }

    top_result->sys_process_num = running_processes;

    load_pids_table(fd, NULL);
    gettimeofday(&cur, NULL);
    microsec = (cur.tv_sec - 1) * 1000UL * 1000UL + cur.tv_usec;
    top_result->checktime = microsec;
    ret = nvmlDeviceGetProcessUtilization(dev, processes_sample, &processes_num, microsec);
    if (unlikely(ret)) {
        HLOG(INFO, "nvmlDeviceGetProcessUtilization: %s", nvmlErrorString(ret));
        return;
    }

    top_result->user_current = 0;
    top_result->sys_current = 0;
    for (i = 0; i < processes_num; i++) {
        if (processes_sample[i].timeStamp >= top_result->checktime) {
            top_result->valid = 1;
            top_result->sys_current += GET_VALID_VALUE(processes_sample[i].smUtil);

            codec_util = GET_VALID_VALUE(processes_sample[i].encUtil) + GET_VALID_VALUE(processes_sample[i].decUtil);
            top_result->sys_current += CODEC_NORMALIZE(codec_util);

            HLOG(INFO, "try to find %d from pid tables", processes_sample[i].pid);
            if (likely(bsearch(&processes_sample[i].pid, g_pids_table, (size_t)g_pids_table_size, sizeof(int), int_match))) {
                top_result->user_current += GET_VALID_VALUE(processes_sample[i].smUtil);

                codec_util = GET_VALID_VALUE(processes_sample[i].encUtil) + GET_VALID_VALUE(processes_sample[i].decUtil);
                top_result->user_current += CODEC_NORMALIZE(codec_util);
            }
        }
    }

    HLOG(INFO, "sys utilization: %d", top_result->sys_current);
    HLOG(INFO, "used utilization: %d", top_result->user_current);
}
void change_token(int delta) {
    int cuda_cores_before = 0, cuda_cores_after = 0;

    HLOG(INFO, "delta: %d, curr: %d", delta, g_cur_cuda_cores);
    do {
        cuda_cores_before = g_cur_cuda_cores;
        cuda_cores_after = cuda_cores_before + delta;

        if (unlikely(cuda_cores_after > g_total_cuda_cores)) {
            cuda_cores_after = g_total_cuda_cores;
        }
    } while (!CAS(&g_cur_cuda_cores, cuda_cores_before, cuda_cores_after));
}
int int_match(const void *a, const void *b) {
    const int *ra = (const int *)a;
    const int *rb = (const int *)b;

    if (*ra < *rb) {
        return -1;
    }

    if (*ra > *rb) {
        return 1;
    }

    return 0;
}
