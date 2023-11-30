#include <dlfcn.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "include/base.h"

nvmlReturn_t nvmlInitWithFlags(unsigned int flags) {
    load_necessary_data();
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlInitWithFlags");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(unsigned int) = (nvmlReturn_t(*)(unsigned int))dlsym(nvml_handle, "nvmlInitWithFlags");
    nvmlReturn_t rs = hookFunc(flags);
    TimeProfileDestroy(pprof);
    return rs;
}
nvmlReturn_t nvmlInit_v2() {
    load_necessary_data();
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlInit_v2");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)() = (nvmlReturn_t(*)())dlsym(nvml_handle, "nvmlInit_v2");
    nvmlReturn_t rs = hookFunc();
    TimeProfileDestroy(pprof);
    return rs;
}
nvmlReturn_t nvmlInit() {
    load_necessary_data();
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlInit");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)() = (nvmlReturn_t(*)())dlsym(nvml_handle, "nvmlInit");
    nvmlReturn_t rs = hookFunc();
    TimeProfileDestroy(pprof);
    return rs;
}

nvmlReturn_t nvmlDeviceGetComputeRunningProcesses(nvmlDevice_t device, unsigned int *infoCount, nvmlProcessInfo_v1_t *infos) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetComputeRunningProcesses");
    cudaCache *cc = NULL;
    nvmlReturn_t rs = UnMarshalCudaCache(Compute, infoCount, cc);
    for (unsigned int i = 0; i < *infoCount; i++) {
        infos[i].pid = cc[i].PID;
        infos[i].usedGpuMemory = cc[i].MemoryUsed;
    }
    if (*infoCount == 0) {
        void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
        nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *, nvmlProcessInfo_v1_t *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *, nvmlProcessInfo_v1_t *))dlsym(nvml_handle, "nvmlDeviceGetComputeRunningProcesses");
        HOOK_CHECK(hookFunc);
        rs = hookFunc(device, infoCount, infos);
    }
    TimeProfileDestroy(pprof);
    return rs;
}
nvmlReturn_t nvmlDeviceGetComputeRunningProcesses_v2(nvmlDevice_t device, unsigned int *infoCount, nvmlProcessInfo_v2_t *infos) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetComputeRunningProcesses_v2");
    cudaCache *cc = NULL;
    nvmlReturn_t rs = UnMarshalCudaCache(Compute, infoCount, cc);
    for (unsigned int i = 0; i < *infoCount; i++) {
        infos[i].pid = cc[i].PID;
        infos[i].usedGpuMemory = cc[i].MemoryUsed;
    }
    if (*infoCount == 0) {
        void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
        nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *, nvmlProcessInfo_v2_t *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *, nvmlProcessInfo_v2_t *))dlsym(nvml_handle, "nvmlDeviceGetComputeRunningProcesses_v2");
        HOOK_CHECK(hookFunc);
        rs = hookFunc(device, infoCount, infos);
    }
    TimeProfileDestroy(pprof);
    return rs;
}
nvmlReturn_t nvmlDeviceGetComputeRunningProcesses_v3(nvmlDevice_t device, unsigned int *infoCount, nvmlProcessInfo_t *infos) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetComputeRunningProcesses_v3");
    cudaCache *cc = NULL;
    nvmlReturn_t rs = UnMarshalCudaCache(Compute, infoCount, cc);
    for (unsigned int i = 0; i < *infoCount; i++) {
        infos[i].pid = cc[i].PID;
        infos[i].usedGpuMemory = cc[i].MemoryUsed;
    }
    if (*infoCount == 0) {
        void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
        nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *, nvmlProcessInfo_t *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *, nvmlProcessInfo_t *))dlsym(nvml_handle, "nvmlDeviceGetComputeRunningProcesses_v3");
        HOOK_CHECK(hookFunc);
        rs = hookFunc(device, infoCount, infos);
    }
    TimeProfileDestroy(pprof);
    return rs;
}

nvmlReturn_t nvmlDeviceGetGraphicsRunningProcesses(nvmlDevice_t device, unsigned int *infoCount, nvmlProcessInfo_v1_t *infos) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetGraphicsRunningProcesses");
    cudaCache *cc = NULL;
    nvmlReturn_t rs = UnMarshalCudaCache(Compute, infoCount, cc);
    for (unsigned int i = 0; i < *infoCount; i++) {
        infos[i].pid = cc[i].PID;
        infos[i].usedGpuMemory = cc[i].MemoryUsed;
    }
    if (*infoCount == 0) {
        void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
        nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *, nvmlProcessInfo_v1_t *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *, nvmlProcessInfo_v1_t *))dlsym(nvml_handle, "nvmlDeviceGetComputeRunningProcesses");
        HOOK_CHECK(hookFunc);
        rs = hookFunc(device, infoCount, infos);
    }
    TimeProfileDestroy(pprof);
    return rs;
}
nvmlReturn_t nvmlDeviceGetGraphicsRunningProcesses_v2(nvmlDevice_t device, unsigned int *infoCount, nvmlProcessInfo_v2_t *infos) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetGraphicsRunningProcesses_v2");
    cudaCache *cc = NULL;
    nvmlReturn_t rs = UnMarshalCudaCache(Compute, infoCount, cc);
    for (unsigned int i = 0; i < *infoCount; i++) {
        infos[i].pid = cc[i].PID;
        infos[i].usedGpuMemory = cc[i].MemoryUsed;
    }
    if (*infoCount == 0) {
        void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
        nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *, nvmlProcessInfo_v2_t *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *, nvmlProcessInfo_v2_t *))dlsym(nvml_handle, "nvmlDeviceGetGraphicsRunningProcesses_v2");
        HOOK_CHECK(hookFunc);
        rs = hookFunc(device, infoCount, infos);
    }
    TimeProfileDestroy(pprof);
    return rs;
}
nvmlReturn_t nvmlDeviceGetGraphicsRunningProcesses_v3(nvmlDevice_t device, unsigned int *infoCount, nvmlProcessInfo_t *infos) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetGraphicsRunningProcesses_v3");
    cudaCache *cc = NULL;
    nvmlReturn_t rs = UnMarshalCudaCache(Compute, infoCount, cc);
    for (unsigned int i = 0; i < *infoCount; i++) {
        infos[i].pid = cc[i].PID;
        infos[i].usedGpuMemory = cc[i].MemoryUsed;
    }
    if (*infoCount == 0) {
        void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
        nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *, nvmlProcessInfo_t *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *, nvmlProcessInfo_t *))dlsym(nvml_handle, "nvmlDeviceGetGraphicsRunningProcesses_v3");
        HOOK_CHECK(hookFunc);
        rs = hookFunc(device, infoCount, infos);
    }
    TimeProfileDestroy(pprof);
    return rs;
}
nvmlReturn_t nvmlDeviceGetSupportedEventTypes ( nvmlDevice_t device, unsigned long long* eventTypes );
