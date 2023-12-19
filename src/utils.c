#include <emmintrin.h>
#include <errno.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <stddef.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <time.h>

#include "include/base.h"
#include "include/cuda-helper.h"
#include "include/func.h"
#include "include/nvml.h"

extern int virtual_map[0x10];
extern unsigned int virtual_devices[17];
extern unsigned int cuda_to_nvml_map[0x10];
extern u_int64_t context_size;
extern device vdevices[0x10];
extern int record_nvml_map[0x10];
extern unsigned int record_cuda_map[17];
extern void *cuda_library_entry[];
extern sharedRegionT *flags;
extern int env_utilization_switch;
extern char *unified_lock;

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
        if (!found) { // 当前的列表中没有找到，就合并
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
    unsigned int v72;                     // [rsp+1Ch] [rbp-C050h]
    unsigned int v73;                     // [rsp+20h] [rbp-C04Ch]
    unsigned int ComputeRunningProcesses; // [rsp+24h] [rbp-C048h]
    unsigned int v75;                     // [rsp+28h] [rbp-C044h]
                                          // [rsp+4Ch] [rbp-C020h] BYREF
    char v80[16384];                      // [rsp+403Ch] [rbp-8030h] BYREF

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

size_t try_unlock_unified_lock() {
    LINFO("try unlock_unified_lock:%d", remove(unified_lock));
    return 0LL;
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
    int v34[102];
    unsigned int cudaIndex;
    char *nptr = getenv("CUDA_VISIBLE_DEVICES");
    unsigned int v28 = 0;
    int v30 = -1;
    if (need_cuda_virtualize() && getenv("NVIDIA_DEVICE_MAP")) {
        int v29 = 0;
        unsigned int v31 = -1;
        for (int i = 0; i < strlen(nptr); ++i) {
            if (nptr[i] == ',' || !i) {
                if (i)
                    cudaIndex = atoi(&nptr[i + 1]);
                else
                    cudaIndex = atoi(nptr);
                unsigned int v32 = cudaIndex;
                if (v31 != -1 && virtual_map[cudaIndex] == virtual_map[v31]) {
                    LWARN("device index %d and %d are the same physical device, it may incur an error, try selecting different combinations", v32, v31);
                }
                else {
                    cuda_to_nvml_map[v29] = cudaIndex;
                    record_cuda_map[v29] = record_nvml_map[cudaIndex];
                    v34[v29] = virtual_map[cuda_to_nvml_map[v29]];
                    v31 = cudaIndex;
                    ++v29;
                }
            }
        }
        for (int j = 0; (int)j < v29; ++j) {
            virtual_map[j] = v34[j];
            LWARN("i=%d:%d:%d:%d", j, virtual_map[j], (unsigned int)record_cuda_map[j], (unsigned int)cuda_to_nvml_map[j]);
        }

        virtual_devices[0] = v29;

        LWARN("virtual_devices=%d", virtual_devices[0]);
        return (unsigned int)(v29 + 1);
    }
    else {
        if (!getenv("NVIDIA_DEVICE_MAP") && (unsigned int)need_cuda_virtualize()) {
            memset(record_cuda_map, 0, sizeof(record_cuda_map));
            for (int k = 0; k < strlen(nptr); ++k) {
                if (nptr[k] == 44 || !k) {
                    int v0 = k ? atoi(&nptr[k + 1]) : atoi(nptr);
                    if (v30 == -1 || virtual_map[v0] != virtual_map[v30]) {
                        record_cuda_map[v28++] = record_nvml_map[v0];
                        v30 = v0;
                    }
                }
            }
            virtual_devices[0] = v28;
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
    return flags->procnum;
}

size_t try_lock_unified_lock() {
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
    return 0LL;
}