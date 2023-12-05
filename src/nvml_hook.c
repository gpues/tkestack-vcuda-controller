#include <dlfcn.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "include/base.h"

nvmlReturn_t nvmlInitWithFlags(unsigned int flags) {
    load_necessary_data();
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlInitWithFlags");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_NOW);
    nvmlReturn_t (*hookFunc)(unsigned int) = (nvmlReturn_t(*)(unsigned int))dlsym(nvml_handle, "nvmlInitWithFlags");
    nvmlReturn_t rs = hookFunc(flags);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}
nvmlReturn_t nvmlInit_v2() {
    load_necessary_data();
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlInit_v2");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)() = (nvmlReturn_t(*)())dlsym(nvml_handle, "nvmlInit_v2");
    nvmlReturn_t rs = hookFunc();
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}
nvmlReturn_t nvmlInit() {
    load_necessary_data();
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlInit");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)() = (nvmlReturn_t(*)())dlsym(nvml_handle, "nvmlInit");
    nvmlReturn_t rs = hookFunc();
    nvmlTimeProfileDestroy(pprof, rs);
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
    nvmlTimeProfileDestroy(pprof, rs);
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
    nvmlTimeProfileDestroy(pprof, rs);
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
    nvmlTimeProfileDestroy(pprof, rs);
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
    nvmlTimeProfileDestroy(pprof, rs);
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
    nvmlTimeProfileDestroy(pprof, rs);
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
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetMPSComputeRunningProcesses(nvmlDevice_t device, unsigned int *infoCount, nvmlProcessInfo_v1_t *infos) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetMPSComputeRunningProcesses");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *, nvmlProcessInfo_v1_t *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *, nvmlProcessInfo_v1_t *))dlsym(nvml_handle, "nvmlDeviceGetMPSComputeRunningProcesses");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, infoCount, infos);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetMPSComputeRunningProcesses_v2(nvmlDevice_t device, unsigned int *infoCount, nvmlProcessInfo_v2_t *infos) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetMPSComputeRunningProcesses_v2");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *, nvmlProcessInfo_v2_t *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *, nvmlProcessInfo_v2_t *))dlsym(nvml_handle, "nvmlDeviceGetMPSComputeRunningProcesses_v2");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, infoCount, infos);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetMPSComputeRunningProcesses_v3(nvmlDevice_t device, unsigned int *infoCount, nvmlProcessInfo_t *infos) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetMPSComputeRunningProcesses_v3");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *, nvmlProcessInfo_t *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *, nvmlProcessInfo_t *))dlsym(nvml_handle, "nvmlDeviceGetMPSComputeRunningProcesses_v3");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, infoCount, infos);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetSupportedEventTypes(nvmlDevice_t device, unsigned long long *eventTypes);

nvmlReturn_t nvmlDeviceIsMigDeviceHandle(nvmlDevice_t device, unsigned int *isMigDevice) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceIsMigDeviceHandle");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *))dlsym(nvml_handle, "nvmlDeviceIsMigDeviceHandle");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, isMigDevice);
    printf("nvmlDeviceIsMigDeviceHandle  %d   \n", *isMigDevice);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}
nvmlReturn_t nvmlDeviceGetDeviceHandleFromMigDeviceHandle(nvmlDevice_t migDevice, nvmlDevice_t *device) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetDeviceHandleFromMigDeviceHandle");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlDevice_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlDevice_t *))dlsym(nvml_handle, "nvmlDeviceGetDeviceHandleFromMigDeviceHandle");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(migDevice, device);
    printf("nvmlDeviceGetDeviceHandleFromMigDeviceHandle %d  \n", migDevice);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}
nvmlReturn_t nvmlDeviceGetIndex(nvmlDevice_t device, unsigned int *index) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetIndex");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *))dlsym(nvml_handle, "nvmlDeviceGetIndex");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, index);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetMemoryInfo_v2(nvmlDevice_t device, nvmlMemory_v2_t *memory) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetMemoryInfo_v2");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlMemory_v2_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlMemory_v2_t *))dlsym(nvml_handle, "nvmlDeviceGetMemoryInfo_v2");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, memory);
    printf("    nvmlDeviceGetMemoryInfo_v2 total:%lld used:%lld free:%lld reserved:%lld version:%d \n", memory->total, memory->used, memory->free, memory->reserved, memory->version);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

const char *nvmlErrorString(nvmlReturn_t result) {
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    const char *(*hookFunc)(nvmlReturn_t) = (const char *(*)(nvmlReturn_t))dlsym(nvml_handle, "nvmlErrorString");
    HOOK_CHECK(hookFunc);
    const char *rs = hookFunc(result);
    return rs;
}
