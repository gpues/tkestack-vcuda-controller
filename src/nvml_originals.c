
// auto generate 294 apis

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <dlfcn.h>
#include "include/base.h"

const  char * nvmlErrorString(nvmlReturn_t result) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlErrorString");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    const  char * (*hookFunc)(nvmlReturn_t) = (const  char *(*)(nvmlReturn_t)) dlsym(nvml_handle, "nvmlErrorString");
    HOOK_CHECK(hookFunc);
    const  char * rs = hookFunc(result);
    TimeProfileDestroy(pprof);
    return rs;
}

nvmlReturn_t nvmlComputeInstanceDestroy(nvmlComputeInstance_t computeInstance) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlComputeInstanceDestroy");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlComputeInstance_t) = (nvmlReturn_t(*)(nvmlComputeInstance_t)) dlsym(nvml_handle, "nvmlComputeInstanceDestroy");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(computeInstance);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlComputeInstanceGetInfo(nvmlComputeInstance_t computeInstance, nvmlComputeInstanceInfo_t * info) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlComputeInstanceGetInfo");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlComputeInstance_t, nvmlComputeInstanceInfo_t *) = (nvmlReturn_t(*)(nvmlComputeInstance_t, nvmlComputeInstanceInfo_t *)) dlsym(nvml_handle, "nvmlComputeInstanceGetInfo");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(computeInstance, info);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlComputeInstanceGetInfo_v2(nvmlComputeInstance_t computeInstance, nvmlComputeInstanceInfo_t * info) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlComputeInstanceGetInfo_v2");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlComputeInstance_t, nvmlComputeInstanceInfo_t *) = (nvmlReturn_t(*)(nvmlComputeInstance_t, nvmlComputeInstanceInfo_t *)) dlsym(nvml_handle, "nvmlComputeInstanceGetInfo_v2");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(computeInstance, info);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceCcuGetStreamState(nvmlDevice_t device, unsigned int * state) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceCcuGetStreamState");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceCcuGetStreamState");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, state);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceCcuSetStreamState(nvmlDevice_t device, unsigned int state) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceCcuSetStreamState");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int)) dlsym(nvml_handle, "nvmlDeviceCcuSetStreamState");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, state);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceClearAccountingPids(nvmlDevice_t device) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceClearAccountingPids");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t) = (nvmlReturn_t(*)(nvmlDevice_t)) dlsym(nvml_handle, "nvmlDeviceClearAccountingPids");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceClearCpuAffinity(nvmlDevice_t device) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceClearCpuAffinity");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t) = (nvmlReturn_t(*)(nvmlDevice_t)) dlsym(nvml_handle, "nvmlDeviceClearCpuAffinity");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceClearEccErrorCounts(nvmlDevice_t device, nvmlEccCounterType_t counterType) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceClearEccErrorCounts");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlEccCounterType_t) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlEccCounterType_t)) dlsym(nvml_handle, "nvmlDeviceClearEccErrorCounts");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, counterType);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceClearFieldValues(nvmlDevice_t device, int valuesCount, nvmlFieldValue_t * values) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceClearFieldValues");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, int, nvmlFieldValue_t *) = (nvmlReturn_t(*)(nvmlDevice_t, int, nvmlFieldValue_t *)) dlsym(nvml_handle, "nvmlDeviceClearFieldValues");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, valuesCount, values);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceCreateGpuInstance(nvmlDevice_t device, unsigned int profileId, nvmlGpuInstance_t * gpuInstance) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceCreateGpuInstance");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int, nvmlGpuInstance_t *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int, nvmlGpuInstance_t *)) dlsym(nvml_handle, "nvmlDeviceCreateGpuInstance");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, profileId, gpuInstance);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceCreateGpuInstanceWithPlacement(nvmlDevice_t device, unsigned int profileId, const nvmlGpuInstancePlacement_t * placement, nvmlGpuInstance_t * gpuInstance) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceCreateGpuInstanceWithPlacement");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int, const nvmlGpuInstancePlacement_t *, nvmlGpuInstance_t *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int, const nvmlGpuInstancePlacement_t *, nvmlGpuInstance_t *)) dlsym(nvml_handle, "nvmlDeviceCreateGpuInstanceWithPlacement");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, profileId, placement, gpuInstance);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceDiscoverGpus(nvmlPciInfo_t * pciInfo) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceDiscoverGpus");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlPciInfo_t *) = (nvmlReturn_t(*)(nvmlPciInfo_t *)) dlsym(nvml_handle, "nvmlDeviceDiscoverGpus");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(pciInfo);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceFreezeNvLinkUtilizationCounter(nvmlDevice_t device, unsigned int link, unsigned int counter, nvmlEnableState_t freeze) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceFreezeNvLinkUtilizationCounter");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int, unsigned int, nvmlEnableState_t) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int, unsigned int, nvmlEnableState_t)) dlsym(nvml_handle, "nvmlDeviceFreezeNvLinkUtilizationCounter");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, link, counter, freeze);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetAPIRestriction(nvmlDevice_t device, nvmlRestrictedAPI_t apiType, nvmlEnableState_t * isRestricted) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetAPIRestriction");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlRestrictedAPI_t, nvmlEnableState_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlRestrictedAPI_t, nvmlEnableState_t *)) dlsym(nvml_handle, "nvmlDeviceGetAPIRestriction");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, apiType, isRestricted);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetAccountingBufferSize(nvmlDevice_t device, unsigned int * bufferSize) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetAccountingBufferSize");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetAccountingBufferSize");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, bufferSize);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetAccountingMode(nvmlDevice_t device, nvmlEnableState_t * mode) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetAccountingMode");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlEnableState_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlEnableState_t *)) dlsym(nvml_handle, "nvmlDeviceGetAccountingMode");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, mode);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetAccountingPids(nvmlDevice_t device, unsigned int * count, unsigned int * pids) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetAccountingPids");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetAccountingPids");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, count, pids);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetAccountingStats(nvmlDevice_t device, unsigned int pid, nvmlAccountingStats_t * stats) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetAccountingStats");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int, nvmlAccountingStats_t *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int, nvmlAccountingStats_t *)) dlsym(nvml_handle, "nvmlDeviceGetAccountingStats");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, pid, stats);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetActiveVgpus(nvmlDevice_t device, unsigned int * vgpuCount, nvmlVgpuInstance_t * vgpuInstances) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetActiveVgpus");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *, nvmlVgpuInstance_t *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *, nvmlVgpuInstance_t *)) dlsym(nvml_handle, "nvmlDeviceGetActiveVgpus");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, vgpuCount, vgpuInstances);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetAdaptiveClockInfoStatus(nvmlDevice_t device, unsigned int * adaptiveClockStatus) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetAdaptiveClockInfoStatus");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetAdaptiveClockInfoStatus");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, adaptiveClockStatus);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetApplicationsClock(nvmlDevice_t device, nvmlClockType_t clockType, unsigned int * clockMHz) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetApplicationsClock");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlClockType_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlClockType_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetApplicationsClock");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, clockType, clockMHz);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetArchitecture(nvmlDevice_t device, nvmlDeviceArchitecture_t * arch) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetArchitecture");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlDeviceArchitecture_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlDeviceArchitecture_t *)) dlsym(nvml_handle, "nvmlDeviceGetArchitecture");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, arch);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetAttributes(nvmlDevice_t device, nvmlDeviceAttributes_t * attributes) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetAttributes");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlDeviceAttributes_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlDeviceAttributes_t *)) dlsym(nvml_handle, "nvmlDeviceGetAttributes");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, attributes);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetAttributes_v2(nvmlDevice_t device, nvmlDeviceAttributes_t * attributes) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetAttributes_v2");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlDeviceAttributes_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlDeviceAttributes_t *)) dlsym(nvml_handle, "nvmlDeviceGetAttributes_v2");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, attributes);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetAutoBoostedClocksEnabled(nvmlDevice_t device, nvmlEnableState_t * isEnabled, nvmlEnableState_t * defaultIsEnabled) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetAutoBoostedClocksEnabled");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlEnableState_t *, nvmlEnableState_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlEnableState_t *, nvmlEnableState_t *)) dlsym(nvml_handle, "nvmlDeviceGetAutoBoostedClocksEnabled");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, isEnabled, defaultIsEnabled);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetBAR1MemoryInfo(nvmlDevice_t device, nvmlBAR1Memory_t * bar1Memory) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetBAR1MemoryInfo");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlBAR1Memory_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlBAR1Memory_t *)) dlsym(nvml_handle, "nvmlDeviceGetBAR1MemoryInfo");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, bar1Memory);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetBoardId(nvmlDevice_t device, unsigned int * boardId) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetBoardId");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetBoardId");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, boardId);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetBoardPartNumber(nvmlDevice_t device, char * partNumber, unsigned int length) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetBoardPartNumber");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, char *, unsigned int) = (nvmlReturn_t(*)(nvmlDevice_t, char *, unsigned int)) dlsym(nvml_handle, "nvmlDeviceGetBoardPartNumber");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, partNumber, length);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetBrand(nvmlDevice_t device, nvmlBrandType_t * type) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetBrand");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlBrandType_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlBrandType_t *)) dlsym(nvml_handle, "nvmlDeviceGetBrand");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, type);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetBridgeChipInfo(nvmlDevice_t device, nvmlBridgeChipHierarchy_t * bridgeHierarchy) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetBridgeChipInfo");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlBridgeChipHierarchy_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlBridgeChipHierarchy_t *)) dlsym(nvml_handle, "nvmlDeviceGetBridgeChipInfo");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, bridgeHierarchy);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetBusType(nvmlDevice_t device, nvmlBusType_t * type) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetBusType");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlBusType_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlBusType_t *)) dlsym(nvml_handle, "nvmlDeviceGetBusType");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, type);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetClkMonStatus(nvmlDevice_t device, nvmlClkMonStatus_t * status) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetClkMonStatus");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlClkMonStatus_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlClkMonStatus_t *)) dlsym(nvml_handle, "nvmlDeviceGetClkMonStatus");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, status);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetClock(nvmlDevice_t device, nvmlClockType_t clockType, nvmlClockId_t clockId, unsigned int * clockMHz) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetClock");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlClockType_t, nvmlClockId_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlClockType_t, nvmlClockId_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetClock");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, clockType, clockId, clockMHz);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetClockInfo(nvmlDevice_t device, nvmlClockType_t type, unsigned int * clock) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetClockInfo");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlClockType_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlClockType_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetClockInfo");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, type, clock);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetComputeInstanceId(nvmlDevice_t device, unsigned int * id) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetComputeInstanceId");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetComputeInstanceId");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, id);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetComputeMode(nvmlDevice_t device, nvmlComputeMode_t * mode) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetComputeMode");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlComputeMode_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlComputeMode_t *)) dlsym(nvml_handle, "nvmlDeviceGetComputeMode");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, mode);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetCount(unsigned int * deviceCount) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetCount");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(unsigned int *) = (nvmlReturn_t(*)(unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetCount");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(deviceCount);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetCount_v2(unsigned int * deviceCount) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetCount_v2");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(unsigned int *) = (nvmlReturn_t(*)(unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetCount_v2");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(deviceCount);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetCpuAffinity(nvmlDevice_t device, unsigned int cpuSetSize, unsigned long * cpuSet) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetCpuAffinity");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int, unsigned long *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int, unsigned long *)) dlsym(nvml_handle, "nvmlDeviceGetCpuAffinity");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, cpuSetSize, cpuSet);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetCpuAffinityWithinScope(nvmlDevice_t device, unsigned int cpuSetSize, unsigned long * cpuSet, nvmlAffinityScope_t scope) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetCpuAffinityWithinScope");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int, unsigned long *, nvmlAffinityScope_t) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int, unsigned long *, nvmlAffinityScope_t)) dlsym(nvml_handle, "nvmlDeviceGetCpuAffinityWithinScope");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, cpuSetSize, cpuSet, scope);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetCreatableVgpus(nvmlDevice_t device, unsigned int * vgpuCount, nvmlVgpuTypeId_t * vgpuTypeIds) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetCreatableVgpus");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *, nvmlVgpuTypeId_t *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *, nvmlVgpuTypeId_t *)) dlsym(nvml_handle, "nvmlDeviceGetCreatableVgpus");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, vgpuCount, vgpuTypeIds);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetCudaComputeCapability(nvmlDevice_t device, int * major, int * minor) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetCudaComputeCapability");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, int *, int *) = (nvmlReturn_t(*)(nvmlDevice_t, int *, int *)) dlsym(nvml_handle, "nvmlDeviceGetCudaComputeCapability");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, major, minor);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetCurrPcieLinkGeneration(nvmlDevice_t device, unsigned int * currLinkGen) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetCurrPcieLinkGeneration");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetCurrPcieLinkGeneration");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, currLinkGen);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetCurrPcieLinkWidth(nvmlDevice_t device, unsigned int * currLinkWidth) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetCurrPcieLinkWidth");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetCurrPcieLinkWidth");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, currLinkWidth);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetCurrentClocksThrottleReasons(nvmlDevice_t device, unsigned long long * clocksThrottleReasons) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetCurrentClocksThrottleReasons");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned long long *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned long long *)) dlsym(nvml_handle, "nvmlDeviceGetCurrentClocksThrottleReasons");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, clocksThrottleReasons);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetDecoderUtilization(nvmlDevice_t device, unsigned int * utilization, unsigned int * samplingPeriodUs) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetDecoderUtilization");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetDecoderUtilization");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, utilization, samplingPeriodUs);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetDefaultApplicationsClock(nvmlDevice_t device, nvmlClockType_t clockType, unsigned int * clockMHz) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetDefaultApplicationsClock");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlClockType_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlClockType_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetDefaultApplicationsClock");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, clockType, clockMHz);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetDefaultEccMode(nvmlDevice_t device, nvmlEnableState_t * defaultMode) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetDefaultEccMode");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlEnableState_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlEnableState_t *)) dlsym(nvml_handle, "nvmlDeviceGetDefaultEccMode");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, defaultMode);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetDetailedEccErrors(nvmlDevice_t device, nvmlMemoryErrorType_t errorType, nvmlEccCounterType_t counterType, nvmlEccErrorCounts_t * eccCounts) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetDetailedEccErrors");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlMemoryErrorType_t, nvmlEccCounterType_t, nvmlEccErrorCounts_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlMemoryErrorType_t, nvmlEccCounterType_t, nvmlEccErrorCounts_t *)) dlsym(nvml_handle, "nvmlDeviceGetDetailedEccErrors");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, errorType, counterType, eccCounts);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetDeviceHandleFromMigDeviceHandle(nvmlDevice_t migDevice, nvmlDevice_t * device) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetDeviceHandleFromMigDeviceHandle");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlDevice_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlDevice_t *)) dlsym(nvml_handle, "nvmlDeviceGetDeviceHandleFromMigDeviceHandle");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(migDevice, device);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetDisplayActive(nvmlDevice_t device, nvmlEnableState_t * isActive) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetDisplayActive");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlEnableState_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlEnableState_t *)) dlsym(nvml_handle, "nvmlDeviceGetDisplayActive");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, isActive);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetDisplayMode(nvmlDevice_t device, nvmlEnableState_t * display) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetDisplayMode");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlEnableState_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlEnableState_t *)) dlsym(nvml_handle, "nvmlDeviceGetDisplayMode");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, display);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetDriverModel(nvmlDevice_t device, nvmlDriverModel_t * current, nvmlDriverModel_t * pending) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetDriverModel");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlDriverModel_t *, nvmlDriverModel_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlDriverModel_t *, nvmlDriverModel_t *)) dlsym(nvml_handle, "nvmlDeviceGetDriverModel");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, current, pending);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetDynamicPstatesInfo(nvmlDevice_t device, nvmlGpuDynamicPstatesInfo_t * pDynamicPstatesInfo) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetDynamicPstatesInfo");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlGpuDynamicPstatesInfo_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlGpuDynamicPstatesInfo_t *)) dlsym(nvml_handle, "nvmlDeviceGetDynamicPstatesInfo");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, pDynamicPstatesInfo);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetEccMode(nvmlDevice_t device, nvmlEnableState_t * current, nvmlEnableState_t * pending) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetEccMode");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlEnableState_t *, nvmlEnableState_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlEnableState_t *, nvmlEnableState_t *)) dlsym(nvml_handle, "nvmlDeviceGetEccMode");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, current, pending);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetEncoderCapacity(nvmlDevice_t device, nvmlEncoderType_t encoderQueryType, unsigned int * encoderCapacity) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetEncoderCapacity");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlEncoderType_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlEncoderType_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetEncoderCapacity");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, encoderQueryType, encoderCapacity);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetEncoderSessions(nvmlDevice_t device, unsigned int * sessionCount, nvmlEncoderSessionInfo_t * sessionInfos) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetEncoderSessions");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *, nvmlEncoderSessionInfo_t *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *, nvmlEncoderSessionInfo_t *)) dlsym(nvml_handle, "nvmlDeviceGetEncoderSessions");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, sessionCount, sessionInfos);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetEncoderStats(nvmlDevice_t device, unsigned int * sessionCount, unsigned int * averageFps, unsigned int * averageLatency) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetEncoderStats");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *, unsigned int *, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *, unsigned int *, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetEncoderStats");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, sessionCount, averageFps, averageLatency);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetEncoderUtilization(nvmlDevice_t device, unsigned int * utilization, unsigned int * samplingPeriodUs) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetEncoderUtilization");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetEncoderUtilization");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, utilization, samplingPeriodUs);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetEnforcedPowerLimit(nvmlDevice_t device, unsigned int * limit) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetEnforcedPowerLimit");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetEnforcedPowerLimit");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, limit);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetFBCSessions(nvmlDevice_t device, unsigned int * sessionCount, nvmlFBCSessionInfo_t * sessionInfo) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetFBCSessions");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *, nvmlFBCSessionInfo_t *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *, nvmlFBCSessionInfo_t *)) dlsym(nvml_handle, "nvmlDeviceGetFBCSessions");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, sessionCount, sessionInfo);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetFBCStats(nvmlDevice_t device, nvmlFBCStats_t * fbcStats) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetFBCStats");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlFBCStats_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlFBCStats_t *)) dlsym(nvml_handle, "nvmlDeviceGetFBCStats");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, fbcStats);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetFanSpeed(nvmlDevice_t device, unsigned int * speed) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetFanSpeed");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetFanSpeed");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, speed);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetFanSpeed_v2(nvmlDevice_t device, unsigned int fan, unsigned int * speed) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetFanSpeed_v2");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetFanSpeed_v2");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, fan, speed);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetFieldValues(nvmlDevice_t device, int valuesCount, nvmlFieldValue_t * values) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetFieldValues");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, int, nvmlFieldValue_t *) = (nvmlReturn_t(*)(nvmlDevice_t, int, nvmlFieldValue_t *)) dlsym(nvml_handle, "nvmlDeviceGetFieldValues");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, valuesCount, values);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetGpcClkMinMaxVfOffset(nvmlDevice_t device, int * minOffset, int * maxOffset) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetGpcClkMinMaxVfOffset");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, int *, int *) = (nvmlReturn_t(*)(nvmlDevice_t, int *, int *)) dlsym(nvml_handle, "nvmlDeviceGetGpcClkMinMaxVfOffset");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, minOffset, maxOffset);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetGpcClkVfOffset(nvmlDevice_t device, int * offset) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetGpcClkVfOffset");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, int *) = (nvmlReturn_t(*)(nvmlDevice_t, int *)) dlsym(nvml_handle, "nvmlDeviceGetGpcClkVfOffset");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, offset);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetGpuInstanceById(nvmlDevice_t device, unsigned int id, nvmlGpuInstance_t * gpuInstance) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetGpuInstanceById");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int, nvmlGpuInstance_t *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int, nvmlGpuInstance_t *)) dlsym(nvml_handle, "nvmlDeviceGetGpuInstanceById");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, id, gpuInstance);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetGpuInstanceId(nvmlDevice_t device, unsigned int * id) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetGpuInstanceId");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetGpuInstanceId");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, id);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetGpuInstancePossiblePlacements(nvmlDevice_t device, unsigned int profileId, nvmlGpuInstancePlacement_t * placements, unsigned int * count) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetGpuInstancePossiblePlacements");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int, nvmlGpuInstancePlacement_t *, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int, nvmlGpuInstancePlacement_t *, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetGpuInstancePossiblePlacements");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, profileId, placements, count);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetGpuInstancePossiblePlacements_v2(nvmlDevice_t device, unsigned int profileId, nvmlGpuInstancePlacement_t * placements, unsigned int * count) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetGpuInstancePossiblePlacements_v2");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int, nvmlGpuInstancePlacement_t *, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int, nvmlGpuInstancePlacement_t *, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetGpuInstancePossiblePlacements_v2");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, profileId, placements, count);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetGpuInstanceProfileInfo(nvmlDevice_t device, unsigned int profile, nvmlGpuInstanceProfileInfo_t * info) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetGpuInstanceProfileInfo");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int, nvmlGpuInstanceProfileInfo_t *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int, nvmlGpuInstanceProfileInfo_t *)) dlsym(nvml_handle, "nvmlDeviceGetGpuInstanceProfileInfo");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, profile, info);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetGpuInstanceProfileInfoV(nvmlDevice_t device, unsigned int profile, nvmlGpuInstanceProfileInfo_v2_t * info) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetGpuInstanceProfileInfoV");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int, nvmlGpuInstanceProfileInfo_v2_t *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int, nvmlGpuInstanceProfileInfo_v2_t *)) dlsym(nvml_handle, "nvmlDeviceGetGpuInstanceProfileInfoV");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, profile, info);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetGpuInstanceRemainingCapacity(nvmlDevice_t device, unsigned int profileId, unsigned int * count) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetGpuInstanceRemainingCapacity");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetGpuInstanceRemainingCapacity");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, profileId, count);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetGpuInstances(nvmlDevice_t device, unsigned int profileId, nvmlGpuInstance_t * gpuInstances, unsigned int * count) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetGpuInstances");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int, nvmlGpuInstance_t *, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int, nvmlGpuInstance_t *, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetGpuInstances");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, profileId, gpuInstances, count);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetGpuMaxPcieLinkGeneration(nvmlDevice_t device, unsigned int * maxLinkGenDevice) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetGpuMaxPcieLinkGeneration");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetGpuMaxPcieLinkGeneration");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, maxLinkGenDevice);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetGpuOperationMode(nvmlDevice_t device, nvmlGpuOperationMode_t * current, nvmlGpuOperationMode_t * pending) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetGpuOperationMode");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlGpuOperationMode_t *, nvmlGpuOperationMode_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlGpuOperationMode_t *, nvmlGpuOperationMode_t *)) dlsym(nvml_handle, "nvmlDeviceGetGpuOperationMode");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, current, pending);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetGridLicensableFeatures(nvmlDevice_t device, nvmlGridLicensableFeatures_t * pGridLicensableFeatures) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetGridLicensableFeatures");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlGridLicensableFeatures_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlGridLicensableFeatures_t *)) dlsym(nvml_handle, "nvmlDeviceGetGridLicensableFeatures");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, pGridLicensableFeatures);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetGridLicensableFeatures_v2(nvmlDevice_t device, nvmlGridLicensableFeatures_t * pGridLicensableFeatures) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetGridLicensableFeatures_v2");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlGridLicensableFeatures_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlGridLicensableFeatures_t *)) dlsym(nvml_handle, "nvmlDeviceGetGridLicensableFeatures_v2");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, pGridLicensableFeatures);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetGridLicensableFeatures_v3(nvmlDevice_t device, nvmlGridLicensableFeatures_t * pGridLicensableFeatures) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetGridLicensableFeatures_v3");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlGridLicensableFeatures_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlGridLicensableFeatures_t *)) dlsym(nvml_handle, "nvmlDeviceGetGridLicensableFeatures_v3");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, pGridLicensableFeatures);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetGridLicensableFeatures_v4(nvmlDevice_t device, nvmlGridLicensableFeatures_t * pGridLicensableFeatures) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetGridLicensableFeatures_v4");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlGridLicensableFeatures_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlGridLicensableFeatures_t *)) dlsym(nvml_handle, "nvmlDeviceGetGridLicensableFeatures_v4");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, pGridLicensableFeatures);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetGspFirmwareMode(nvmlDevice_t device, unsigned int * isEnabled, unsigned int * defaultMode) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetGspFirmwareMode");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetGspFirmwareMode");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, isEnabled, defaultMode);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetGspFirmwareVersion(nvmlDevice_t device, char * version) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetGspFirmwareVersion");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, char *) = (nvmlReturn_t(*)(nvmlDevice_t, char *)) dlsym(nvml_handle, "nvmlDeviceGetGspFirmwareVersion");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, version);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetHandleByIndex(unsigned int index, nvmlDevice_t * device) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetHandleByIndex");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(unsigned int, nvmlDevice_t *) = (nvmlReturn_t(*)(unsigned int, nvmlDevice_t *)) dlsym(nvml_handle, "nvmlDeviceGetHandleByIndex");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(index, device);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetHandleByIndex_v2(unsigned int index, nvmlDevice_t * device) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetHandleByIndex_v2");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(unsigned int, nvmlDevice_t *) = (nvmlReturn_t(*)(unsigned int, nvmlDevice_t *)) dlsym(nvml_handle, "nvmlDeviceGetHandleByIndex_v2");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(index, device);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetHandleByPciBusId(const char * pciBusId, nvmlDevice_t * device) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetHandleByPciBusId");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(const char *, nvmlDevice_t *) = (nvmlReturn_t(*)(const char *, nvmlDevice_t *)) dlsym(nvml_handle, "nvmlDeviceGetHandleByPciBusId");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(pciBusId, device);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetHandleByPciBusId_v2(const char * pciBusId, nvmlDevice_t * device) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetHandleByPciBusId_v2");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(const char *, nvmlDevice_t *) = (nvmlReturn_t(*)(const char *, nvmlDevice_t *)) dlsym(nvml_handle, "nvmlDeviceGetHandleByPciBusId_v2");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(pciBusId, device);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetHandleBySerial(const char * serial, nvmlDevice_t * device) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetHandleBySerial");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(const char *, nvmlDevice_t *) = (nvmlReturn_t(*)(const char *, nvmlDevice_t *)) dlsym(nvml_handle, "nvmlDeviceGetHandleBySerial");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(serial, device);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetHandleByUUID(const char * uuid, nvmlDevice_t * device) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetHandleByUUID");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(const char *, nvmlDevice_t *) = (nvmlReturn_t(*)(const char *, nvmlDevice_t *)) dlsym(nvml_handle, "nvmlDeviceGetHandleByUUID");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(uuid, device);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetHostVgpuMode(nvmlDevice_t device, nvmlHostVgpuMode_t * pHostVgpuMode) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetHostVgpuMode");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlHostVgpuMode_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlHostVgpuMode_t *)) dlsym(nvml_handle, "nvmlDeviceGetHostVgpuMode");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, pHostVgpuMode);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetIndex(nvmlDevice_t device, unsigned int * index) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetIndex");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetIndex");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, index);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetInforomConfigurationChecksum(nvmlDevice_t device, unsigned int * checksum) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetInforomConfigurationChecksum");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetInforomConfigurationChecksum");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, checksum);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetInforomImageVersion(nvmlDevice_t device, char * version, unsigned int length) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetInforomImageVersion");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, char *, unsigned int) = (nvmlReturn_t(*)(nvmlDevice_t, char *, unsigned int)) dlsym(nvml_handle, "nvmlDeviceGetInforomImageVersion");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, version, length);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetInforomVersion(nvmlDevice_t device, nvmlInforomObject_t object, char * version, unsigned int length) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetInforomVersion");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlInforomObject_t, char *, unsigned int) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlInforomObject_t, char *, unsigned int)) dlsym(nvml_handle, "nvmlDeviceGetInforomVersion");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, object, version, length);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetIrqNum(nvmlDevice_t device, unsigned int * irqNum) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetIrqNum");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetIrqNum");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, irqNum);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetMPSComputeRunningProcesses(nvmlDevice_t device, unsigned int * infoCount, nvmlProcessInfo_v1_t * infos) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetMPSComputeRunningProcesses");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *, nvmlProcessInfo_v1_t *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *, nvmlProcessInfo_v1_t *)) dlsym(nvml_handle, "nvmlDeviceGetMPSComputeRunningProcesses");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, infoCount, infos);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetMPSComputeRunningProcesses_v2(nvmlDevice_t device, unsigned int * infoCount, nvmlProcessInfo_v2_t * infos) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetMPSComputeRunningProcesses_v2");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *, nvmlProcessInfo_v2_t *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *, nvmlProcessInfo_v2_t *)) dlsym(nvml_handle, "nvmlDeviceGetMPSComputeRunningProcesses_v2");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, infoCount, infos);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetMPSComputeRunningProcesses_v3(nvmlDevice_t device, unsigned int * infoCount, nvmlProcessInfo_t * infos) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetMPSComputeRunningProcesses_v3");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *, nvmlProcessInfo_t *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *, nvmlProcessInfo_t *)) dlsym(nvml_handle, "nvmlDeviceGetMPSComputeRunningProcesses_v3");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, infoCount, infos);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetMaxClockInfo(nvmlDevice_t device, nvmlClockType_t type, unsigned int * clock) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetMaxClockInfo");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlClockType_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlClockType_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetMaxClockInfo");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, type, clock);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetMaxCustomerBoostClock(nvmlDevice_t device, nvmlClockType_t clockType, unsigned int * clockMHz) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetMaxCustomerBoostClock");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlClockType_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlClockType_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetMaxCustomerBoostClock");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, clockType, clockMHz);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetMaxMigDeviceCount(nvmlDevice_t device, unsigned int * count) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetMaxMigDeviceCount");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetMaxMigDeviceCount");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, count);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetMaxPcieLinkGeneration(nvmlDevice_t device, unsigned int * maxLinkGen) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetMaxPcieLinkGeneration");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetMaxPcieLinkGeneration");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, maxLinkGen);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetMaxPcieLinkWidth(nvmlDevice_t device, unsigned int * maxLinkWidth) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetMaxPcieLinkWidth");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetMaxPcieLinkWidth");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, maxLinkWidth);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetMemClkMinMaxVfOffset(nvmlDevice_t device, int * minOffset, int * maxOffset) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetMemClkMinMaxVfOffset");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, int *, int *) = (nvmlReturn_t(*)(nvmlDevice_t, int *, int *)) dlsym(nvml_handle, "nvmlDeviceGetMemClkMinMaxVfOffset");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, minOffset, maxOffset);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetMemClkVfOffset(nvmlDevice_t device, int * offset) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetMemClkVfOffset");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, int *) = (nvmlReturn_t(*)(nvmlDevice_t, int *)) dlsym(nvml_handle, "nvmlDeviceGetMemClkVfOffset");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, offset);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetMemoryAffinity(nvmlDevice_t device, unsigned int nodeSetSize, unsigned long * nodeSet, nvmlAffinityScope_t scope) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetMemoryAffinity");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int, unsigned long *, nvmlAffinityScope_t) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int, unsigned long *, nvmlAffinityScope_t)) dlsym(nvml_handle, "nvmlDeviceGetMemoryAffinity");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, nodeSetSize, nodeSet, scope);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetMemoryBusWidth(nvmlDevice_t device, unsigned int * busWidth) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetMemoryBusWidth");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetMemoryBusWidth");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, busWidth);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetMemoryErrorCounter(nvmlDevice_t device, nvmlMemoryErrorType_t errorType, nvmlEccCounterType_t counterType, nvmlMemoryLocation_t locationType, unsigned long long * count) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetMemoryErrorCounter");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlMemoryErrorType_t, nvmlEccCounterType_t, nvmlMemoryLocation_t, unsigned long long *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlMemoryErrorType_t, nvmlEccCounterType_t, nvmlMemoryLocation_t, unsigned long long *)) dlsym(nvml_handle, "nvmlDeviceGetMemoryErrorCounter");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, errorType, counterType, locationType, count);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetMemoryInfo(nvmlDevice_t device, nvmlMemory_t * memory) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetMemoryInfo");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlMemory_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlMemory_t *)) dlsym(nvml_handle, "nvmlDeviceGetMemoryInfo");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, memory);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetMemoryInfo_v2(nvmlDevice_t device, nvmlMemory_v2_t * memory) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetMemoryInfo_v2");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlMemory_v2_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlMemory_v2_t *)) dlsym(nvml_handle, "nvmlDeviceGetMemoryInfo_v2");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, memory);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetMigDeviceHandleByIndex(nvmlDevice_t device, unsigned int index, nvmlDevice_t * migDevice) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetMigDeviceHandleByIndex");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int, nvmlDevice_t *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int, nvmlDevice_t *)) dlsym(nvml_handle, "nvmlDeviceGetMigDeviceHandleByIndex");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, index, migDevice);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetMigMode(nvmlDevice_t device, unsigned int * currentMode, unsigned int * pendingMode) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetMigMode");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetMigMode");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, currentMode, pendingMode);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetMinMaxClockOfPState(nvmlDevice_t device, nvmlClockType_t type, nvmlPstates_t pstate, unsigned int * minClockMHz, unsigned int * maxClockMHz) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetMinMaxClockOfPState");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlClockType_t, nvmlPstates_t, unsigned int *, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlClockType_t, nvmlPstates_t, unsigned int *, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetMinMaxClockOfPState");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, type, pstate, minClockMHz, maxClockMHz);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetMinMaxFanSpeed(nvmlDevice_t device, unsigned int * minSpeed, unsigned int * maxSpeed) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetMinMaxFanSpeed");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetMinMaxFanSpeed");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, minSpeed, maxSpeed);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetMinorNumber(nvmlDevice_t device, unsigned int * minorNumber) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetMinorNumber");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetMinorNumber");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, minorNumber);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetMultiGpuBoard(nvmlDevice_t device, unsigned int * multiGpuBool) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetMultiGpuBoard");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetMultiGpuBoard");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, multiGpuBool);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetName(nvmlDevice_t device, char * name, unsigned int length) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetName");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, char *, unsigned int) = (nvmlReturn_t(*)(nvmlDevice_t, char *, unsigned int)) dlsym(nvml_handle, "nvmlDeviceGetName");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, name, length);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetNumFans(nvmlDevice_t device, unsigned int * numFans) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetNumFans");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetNumFans");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, numFans);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetNumGpuCores(nvmlDevice_t device, unsigned int * numCores) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetNumGpuCores");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetNumGpuCores");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, numCores);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetNvLinkCapability(nvmlDevice_t device, unsigned int link, nvmlNvLinkCapability_t capability, unsigned int * capResult) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetNvLinkCapability");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int, nvmlNvLinkCapability_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int, nvmlNvLinkCapability_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetNvLinkCapability");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, link, capability, capResult);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetNvLinkErrorCounter(nvmlDevice_t device, unsigned int link, nvmlNvLinkErrorCounter_t counter, unsigned long long * counterValue) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetNvLinkErrorCounter");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int, nvmlNvLinkErrorCounter_t, unsigned long long *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int, nvmlNvLinkErrorCounter_t, unsigned long long *)) dlsym(nvml_handle, "nvmlDeviceGetNvLinkErrorCounter");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, link, counter, counterValue);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetNvLinkRemoteDeviceType(nvmlDevice_t device, unsigned int link, nvmlIntNvLinkDeviceType_t * pNvLinkDeviceType) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetNvLinkRemoteDeviceType");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int, nvmlIntNvLinkDeviceType_t *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int, nvmlIntNvLinkDeviceType_t *)) dlsym(nvml_handle, "nvmlDeviceGetNvLinkRemoteDeviceType");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, link, pNvLinkDeviceType);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetNvLinkRemotePciInfo(nvmlDevice_t device, unsigned int link, nvmlPciInfo_t * pci) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetNvLinkRemotePciInfo");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int, nvmlPciInfo_t *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int, nvmlPciInfo_t *)) dlsym(nvml_handle, "nvmlDeviceGetNvLinkRemotePciInfo");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, link, pci);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetNvLinkRemotePciInfo_v2(nvmlDevice_t device, unsigned int link, nvmlPciInfo_t * pci) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetNvLinkRemotePciInfo_v2");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int, nvmlPciInfo_t *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int, nvmlPciInfo_t *)) dlsym(nvml_handle, "nvmlDeviceGetNvLinkRemotePciInfo_v2");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, link, pci);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetNvLinkState(nvmlDevice_t device, unsigned int link, nvmlEnableState_t * isActive) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetNvLinkState");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int, nvmlEnableState_t *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int, nvmlEnableState_t *)) dlsym(nvml_handle, "nvmlDeviceGetNvLinkState");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, link, isActive);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetNvLinkUtilizationControl(nvmlDevice_t device, unsigned int link, unsigned int counter, nvmlNvLinkUtilizationControl_t * control) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetNvLinkUtilizationControl");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int, unsigned int, nvmlNvLinkUtilizationControl_t *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int, unsigned int, nvmlNvLinkUtilizationControl_t *)) dlsym(nvml_handle, "nvmlDeviceGetNvLinkUtilizationControl");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, link, counter, control);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetNvLinkUtilizationCounter(nvmlDevice_t device, unsigned int link, unsigned int counter, unsigned long long * rxcounter, unsigned long long * txcounter) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetNvLinkUtilizationCounter");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int, unsigned int, unsigned long long *, unsigned long long *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int, unsigned int, unsigned long long *, unsigned long long *)) dlsym(nvml_handle, "nvmlDeviceGetNvLinkUtilizationCounter");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, link, counter, rxcounter, txcounter);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetNvLinkVersion(nvmlDevice_t device, unsigned int link, unsigned int * version) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetNvLinkVersion");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetNvLinkVersion");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, link, version);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetP2PStatus(nvmlDevice_t device1, nvmlDevice_t device2, nvmlGpuP2PCapsIndex_t p2pIndex, nvmlGpuP2PStatus_t * p2pStatus) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetP2PStatus");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlDevice_t, nvmlGpuP2PCapsIndex_t, nvmlGpuP2PStatus_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlDevice_t, nvmlGpuP2PCapsIndex_t, nvmlGpuP2PStatus_t *)) dlsym(nvml_handle, "nvmlDeviceGetP2PStatus");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device1, device2, p2pIndex, p2pStatus);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetPciInfo(nvmlDevice_t device, nvmlPciInfo_t * pci) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetPciInfo");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlPciInfo_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlPciInfo_t *)) dlsym(nvml_handle, "nvmlDeviceGetPciInfo");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, pci);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetPciInfo_v2(nvmlDevice_t device, nvmlPciInfo_t * pci) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetPciInfo_v2");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlPciInfo_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlPciInfo_t *)) dlsym(nvml_handle, "nvmlDeviceGetPciInfo_v2");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, pci);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetPciInfo_v3(nvmlDevice_t device, nvmlPciInfo_t * pci) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetPciInfo_v3");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlPciInfo_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlPciInfo_t *)) dlsym(nvml_handle, "nvmlDeviceGetPciInfo_v3");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, pci);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetPcieLinkMaxSpeed(nvmlDevice_t device, unsigned int * maxSpeed) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetPcieLinkMaxSpeed");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetPcieLinkMaxSpeed");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, maxSpeed);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetPcieReplayCounter(nvmlDevice_t device, unsigned int * value) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetPcieReplayCounter");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetPcieReplayCounter");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, value);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetPcieSpeed(nvmlDevice_t device, unsigned int * pcieSpeed) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetPcieSpeed");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetPcieSpeed");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, pcieSpeed);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetPcieThroughput(nvmlDevice_t device, nvmlPcieUtilCounter_t counter, unsigned int * value) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetPcieThroughput");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlPcieUtilCounter_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlPcieUtilCounter_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetPcieThroughput");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, counter, value);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetPerformanceState(nvmlDevice_t device, nvmlPstates_t * pState) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetPerformanceState");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlPstates_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlPstates_t *)) dlsym(nvml_handle, "nvmlDeviceGetPerformanceState");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, pState);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetPersistenceMode(nvmlDevice_t device, nvmlEnableState_t * mode) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetPersistenceMode");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlEnableState_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlEnableState_t *)) dlsym(nvml_handle, "nvmlDeviceGetPersistenceMode");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, mode);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetPgpuMetadataString(nvmlDevice_t device, char * pgpuMetadata, unsigned int * bufferSize) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetPgpuMetadataString");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, char *, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, char *, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetPgpuMetadataString");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, pgpuMetadata, bufferSize);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetPowerManagementDefaultLimit(nvmlDevice_t device, unsigned int * defaultLimit) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetPowerManagementDefaultLimit");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetPowerManagementDefaultLimit");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, defaultLimit);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetPowerManagementLimit(nvmlDevice_t device, unsigned int * limit) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetPowerManagementLimit");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetPowerManagementLimit");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, limit);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetPowerManagementLimitConstraints(nvmlDevice_t device, unsigned int * minLimit, unsigned int * maxLimit) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetPowerManagementLimitConstraints");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetPowerManagementLimitConstraints");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, minLimit, maxLimit);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetPowerManagementMode(nvmlDevice_t device, nvmlEnableState_t * mode) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetPowerManagementMode");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlEnableState_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlEnableState_t *)) dlsym(nvml_handle, "nvmlDeviceGetPowerManagementMode");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, mode);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetPowerMode(nvmlDevice_t device, unsigned int * powerModeId) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetPowerMode");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetPowerMode");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, powerModeId);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetPowerSource(nvmlDevice_t device, nvmlPowerSource_t * powerSource) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetPowerSource");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlPowerSource_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlPowerSource_t *)) dlsym(nvml_handle, "nvmlDeviceGetPowerSource");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, powerSource);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetPowerState(nvmlDevice_t device, nvmlPstates_t * pState) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetPowerState");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlPstates_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlPstates_t *)) dlsym(nvml_handle, "nvmlDeviceGetPowerState");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, pState);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetPowerUsage(nvmlDevice_t device, unsigned int * power) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetPowerUsage");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetPowerUsage");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, power);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetProcessUtilization(nvmlDevice_t device, nvmlProcessUtilizationSample_t * utilization, unsigned int * processSamplesCount, unsigned long long lastSeenTimeStamp) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetProcessUtilization");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlProcessUtilizationSample_t *, unsigned int *, unsigned long long) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlProcessUtilizationSample_t *, unsigned int *, unsigned long long)) dlsym(nvml_handle, "nvmlDeviceGetProcessUtilization");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, utilization, processSamplesCount, lastSeenTimeStamp);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetRemappedRows(nvmlDevice_t device, unsigned int * corrRows, unsigned int * uncRows, unsigned int * isPending, unsigned int * failureOccurred) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetRemappedRows");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *, unsigned int *, unsigned int *, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *, unsigned int *, unsigned int *, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetRemappedRows");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, corrRows, uncRows, isPending, failureOccurred);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetRetiredPages(nvmlDevice_t device, nvmlPageRetirementCause_t cause, unsigned int * pageCount, unsigned long long * addresses) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetRetiredPages");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlPageRetirementCause_t, unsigned int *, unsigned long long *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlPageRetirementCause_t, unsigned int *, unsigned long long *)) dlsym(nvml_handle, "nvmlDeviceGetRetiredPages");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, cause, pageCount, addresses);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetRetiredPagesPendingStatus(nvmlDevice_t device, nvmlEnableState_t * isPending) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetRetiredPagesPendingStatus");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlEnableState_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlEnableState_t *)) dlsym(nvml_handle, "nvmlDeviceGetRetiredPagesPendingStatus");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, isPending);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetRetiredPages_v2(nvmlDevice_t device, nvmlPageRetirementCause_t cause, unsigned int * pageCount, unsigned long long * addresses, unsigned long long * timestamps) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetRetiredPages_v2");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlPageRetirementCause_t, unsigned int *, unsigned long long *, unsigned long long *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlPageRetirementCause_t, unsigned int *, unsigned long long *, unsigned long long *)) dlsym(nvml_handle, "nvmlDeviceGetRetiredPages_v2");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, cause, pageCount, addresses, timestamps);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetRowRemapperHistogram(nvmlDevice_t device, nvmlRowRemapperHistogramValues_t * values) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetRowRemapperHistogram");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlRowRemapperHistogramValues_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlRowRemapperHistogramValues_t *)) dlsym(nvml_handle, "nvmlDeviceGetRowRemapperHistogram");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, values);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetSamples(nvmlDevice_t device, nvmlSamplingType_t type, unsigned long long lastSeenTimeStamp, nvmlValueType_t * sampleValType, unsigned int * sampleCount, nvmlSample_t * samples) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetSamples");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlSamplingType_t, unsigned long long, nvmlValueType_t *, unsigned int *, nvmlSample_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlSamplingType_t, unsigned long long, nvmlValueType_t *, unsigned int *, nvmlSample_t *)) dlsym(nvml_handle, "nvmlDeviceGetSamples");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, type, lastSeenTimeStamp, sampleValType, sampleCount, samples);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetSerial(nvmlDevice_t device, char * serial, unsigned int length) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetSerial");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, char *, unsigned int) = (nvmlReturn_t(*)(nvmlDevice_t, char *, unsigned int)) dlsym(nvml_handle, "nvmlDeviceGetSerial");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, serial, length);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetSupportedClocksThrottleReasons(nvmlDevice_t device, unsigned long long * supportedClocksThrottleReasons) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetSupportedClocksThrottleReasons");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned long long *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned long long *)) dlsym(nvml_handle, "nvmlDeviceGetSupportedClocksThrottleReasons");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, supportedClocksThrottleReasons);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetSupportedEventTypes(nvmlDevice_t device, unsigned long long * eventTypes) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetSupportedEventTypes");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned long long *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned long long *)) dlsym(nvml_handle, "nvmlDeviceGetSupportedEventTypes");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, eventTypes);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetSupportedGraphicsClocks(nvmlDevice_t device, unsigned int memoryClockMHz, unsigned int * count, unsigned int * clocksMHz) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetSupportedGraphicsClocks");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int, unsigned int *, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int, unsigned int *, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetSupportedGraphicsClocks");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, memoryClockMHz, count, clocksMHz);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetSupportedMemoryClocks(nvmlDevice_t device, unsigned int * count, unsigned int * clocksMHz) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetSupportedMemoryClocks");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetSupportedMemoryClocks");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, count, clocksMHz);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetSupportedPerformanceStates(nvmlDevice_t device, nvmlPstates_t * pstates, unsigned int size) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetSupportedPerformanceStates");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlPstates_t *, unsigned int) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlPstates_t *, unsigned int)) dlsym(nvml_handle, "nvmlDeviceGetSupportedPerformanceStates");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, pstates, size);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetSupportedPowerModes(nvmlDevice_t device, unsigned int * supportedPowerModes) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetSupportedPowerModes");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetSupportedPowerModes");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, supportedPowerModes);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetSupportedVgpus(nvmlDevice_t device, unsigned int * vgpuCount, nvmlVgpuTypeId_t * vgpuTypeIds) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetSupportedVgpus");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *, nvmlVgpuTypeId_t *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *, nvmlVgpuTypeId_t *)) dlsym(nvml_handle, "nvmlDeviceGetSupportedVgpus");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, vgpuCount, vgpuTypeIds);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetTargetFanSpeed(nvmlDevice_t device, unsigned int fan, unsigned int * targetSpeed) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetTargetFanSpeed");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetTargetFanSpeed");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, fan, targetSpeed);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetTemperature(nvmlDevice_t device, nvmlTemperatureSensors_t sensorType, unsigned int * temp) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetTemperature");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlTemperatureSensors_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlTemperatureSensors_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetTemperature");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, sensorType, temp);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetTemperatureThreshold(nvmlDevice_t device, nvmlTemperatureThresholds_t thresholdType, unsigned int * temp) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetTemperatureThreshold");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlTemperatureThresholds_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlTemperatureThresholds_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetTemperatureThreshold");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, thresholdType, temp);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetThermalSettings(nvmlDevice_t device, unsigned int sensorIndex, nvmlGpuThermalSettings_t * pThermalSettings) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetThermalSettings");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int, nvmlGpuThermalSettings_t *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int, nvmlGpuThermalSettings_t *)) dlsym(nvml_handle, "nvmlDeviceGetThermalSettings");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, sensorIndex, pThermalSettings);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetTopologyCommonAncestor(nvmlDevice_t device1, nvmlDevice_t device2, nvmlGpuTopologyLevel_t * pathInfo) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetTopologyCommonAncestor");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlDevice_t, nvmlGpuTopologyLevel_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlDevice_t, nvmlGpuTopologyLevel_t *)) dlsym(nvml_handle, "nvmlDeviceGetTopologyCommonAncestor");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device1, device2, pathInfo);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetTopologyNearestGpus(nvmlDevice_t device, nvmlGpuTopologyLevel_t level, unsigned int * count, nvmlDevice_t * deviceArray) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetTopologyNearestGpus");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlGpuTopologyLevel_t, unsigned int *, nvmlDevice_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlGpuTopologyLevel_t, unsigned int *, nvmlDevice_t *)) dlsym(nvml_handle, "nvmlDeviceGetTopologyNearestGpus");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, level, count, deviceArray);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetTotalEccErrors(nvmlDevice_t device, nvmlMemoryErrorType_t errorType, nvmlEccCounterType_t counterType, unsigned long long * eccCounts) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetTotalEccErrors");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlMemoryErrorType_t, nvmlEccCounterType_t, unsigned long long *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlMemoryErrorType_t, nvmlEccCounterType_t, unsigned long long *)) dlsym(nvml_handle, "nvmlDeviceGetTotalEccErrors");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, errorType, counterType, eccCounts);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetTotalEnergyConsumption(nvmlDevice_t device, unsigned long long * energy) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetTotalEnergyConsumption");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned long long *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned long long *)) dlsym(nvml_handle, "nvmlDeviceGetTotalEnergyConsumption");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, energy);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetUUID(nvmlDevice_t device, char * uuid, unsigned int length) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetUUID");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, char *, unsigned int) = (nvmlReturn_t(*)(nvmlDevice_t, char *, unsigned int)) dlsym(nvml_handle, "nvmlDeviceGetUUID");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, uuid, length);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetUtilizationRates(nvmlDevice_t device, nvmlUtilization_t * utilization) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetUtilizationRates");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlUtilization_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlUtilization_t *)) dlsym(nvml_handle, "nvmlDeviceGetUtilizationRates");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, utilization);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetVbiosVersion(nvmlDevice_t device, char * version, unsigned int length) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetVbiosVersion");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, char *, unsigned int) = (nvmlReturn_t(*)(nvmlDevice_t, char *, unsigned int)) dlsym(nvml_handle, "nvmlDeviceGetVbiosVersion");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, version, length);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetVgpuMetadata(nvmlDevice_t device, nvmlVgpuPgpuMetadata_t * pgpuMetadata, unsigned int * bufferSize) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetVgpuMetadata");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlVgpuPgpuMetadata_t *, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlVgpuPgpuMetadata_t *, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceGetVgpuMetadata");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, pgpuMetadata, bufferSize);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetVgpuProcessUtilization(nvmlDevice_t device, unsigned long long lastSeenTimeStamp, unsigned int * vgpuProcessSamplesCount, nvmlVgpuProcessUtilizationSample_t * utilizationSamples) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetVgpuProcessUtilization");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned long long, unsigned int *, nvmlVgpuProcessUtilizationSample_t *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned long long, unsigned int *, nvmlVgpuProcessUtilizationSample_t *)) dlsym(nvml_handle, "nvmlDeviceGetVgpuProcessUtilization");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, lastSeenTimeStamp, vgpuProcessSamplesCount, utilizationSamples);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetVgpuUtilization(nvmlDevice_t device, unsigned long long lastSeenTimeStamp, nvmlValueType_t * sampleValType, unsigned int * vgpuInstanceSamplesCount, nvmlVgpuInstanceUtilizationSample_t * utilizationSamples) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetVgpuUtilization");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned long long, nvmlValueType_t *, unsigned int *, nvmlVgpuInstanceUtilizationSample_t *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned long long, nvmlValueType_t *, unsigned int *, nvmlVgpuInstanceUtilizationSample_t *)) dlsym(nvml_handle, "nvmlDeviceGetVgpuUtilization");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, lastSeenTimeStamp, sampleValType, vgpuInstanceSamplesCount, utilizationSamples);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetViolationStatus(nvmlDevice_t device, nvmlPerfPolicyType_t perfPolicyType, nvmlViolationTime_t * violTime) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetViolationStatus");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlPerfPolicyType_t, nvmlViolationTime_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlPerfPolicyType_t, nvmlViolationTime_t *)) dlsym(nvml_handle, "nvmlDeviceGetViolationStatus");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, perfPolicyType, violTime);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceGetVirtualizationMode(nvmlDevice_t device, nvmlGpuVirtualizationMode_t * pVirtualMode) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceGetVirtualizationMode");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlGpuVirtualizationMode_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlGpuVirtualizationMode_t *)) dlsym(nvml_handle, "nvmlDeviceGetVirtualizationMode");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, pVirtualMode);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceIsMigDeviceHandle(nvmlDevice_t device, unsigned int * isMigDevice) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceIsMigDeviceHandle");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int *)) dlsym(nvml_handle, "nvmlDeviceIsMigDeviceHandle");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, isMigDevice);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceModifyDrainState(nvmlPciInfo_t * pciInfo, nvmlEnableState_t newState) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceModifyDrainState");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlPciInfo_t *, nvmlEnableState_t) = (nvmlReturn_t(*)(nvmlPciInfo_t *, nvmlEnableState_t)) dlsym(nvml_handle, "nvmlDeviceModifyDrainState");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(pciInfo, newState);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceOnSameBoard(nvmlDevice_t device1, nvmlDevice_t device2, int * onSameBoard) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceOnSameBoard");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlDevice_t, int *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlDevice_t, int *)) dlsym(nvml_handle, "nvmlDeviceOnSameBoard");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device1, device2, onSameBoard);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceQueryDrainState(nvmlPciInfo_t * pciInfo, nvmlEnableState_t * currentState) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceQueryDrainState");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlPciInfo_t *, nvmlEnableState_t *) = (nvmlReturn_t(*)(nvmlPciInfo_t *, nvmlEnableState_t *)) dlsym(nvml_handle, "nvmlDeviceQueryDrainState");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(pciInfo, currentState);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceRegisterEvents(nvmlDevice_t device, unsigned long long eventTypes, nvmlEventSet_t set) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceRegisterEvents");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned long long, nvmlEventSet_t) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned long long, nvmlEventSet_t)) dlsym(nvml_handle, "nvmlDeviceRegisterEvents");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, eventTypes, set);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceRemoveGpu(nvmlPciInfo_t * pciInfo) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceRemoveGpu");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlPciInfo_t *) = (nvmlReturn_t(*)(nvmlPciInfo_t *)) dlsym(nvml_handle, "nvmlDeviceRemoveGpu");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(pciInfo);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceRemoveGpu_v2(nvmlPciInfo_t * pciInfo, nvmlDetachGpuState_t gpuState, nvmlPcieLinkState_t linkState) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceRemoveGpu_v2");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlPciInfo_t *, nvmlDetachGpuState_t, nvmlPcieLinkState_t) = (nvmlReturn_t(*)(nvmlPciInfo_t *, nvmlDetachGpuState_t, nvmlPcieLinkState_t)) dlsym(nvml_handle, "nvmlDeviceRemoveGpu_v2");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(pciInfo, gpuState, linkState);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceResetApplicationsClocks(nvmlDevice_t device) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceResetApplicationsClocks");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t) = (nvmlReturn_t(*)(nvmlDevice_t)) dlsym(nvml_handle, "nvmlDeviceResetApplicationsClocks");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceResetGpuLockedClocks(nvmlDevice_t device) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceResetGpuLockedClocks");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t) = (nvmlReturn_t(*)(nvmlDevice_t)) dlsym(nvml_handle, "nvmlDeviceResetGpuLockedClocks");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceResetMemoryLockedClocks(nvmlDevice_t device) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceResetMemoryLockedClocks");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t) = (nvmlReturn_t(*)(nvmlDevice_t)) dlsym(nvml_handle, "nvmlDeviceResetMemoryLockedClocks");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceResetNvLinkErrorCounters(nvmlDevice_t device, unsigned int link) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceResetNvLinkErrorCounters");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int)) dlsym(nvml_handle, "nvmlDeviceResetNvLinkErrorCounters");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, link);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceResetNvLinkUtilizationCounter(nvmlDevice_t device, unsigned int link, unsigned int counter) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceResetNvLinkUtilizationCounter");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int, unsigned int) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int, unsigned int)) dlsym(nvml_handle, "nvmlDeviceResetNvLinkUtilizationCounter");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, link, counter);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceSetAPIRestriction(nvmlDevice_t device, nvmlRestrictedAPI_t apiType, nvmlEnableState_t isRestricted) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceSetAPIRestriction");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlRestrictedAPI_t, nvmlEnableState_t) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlRestrictedAPI_t, nvmlEnableState_t)) dlsym(nvml_handle, "nvmlDeviceSetAPIRestriction");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, apiType, isRestricted);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceSetAccountingMode(nvmlDevice_t device, nvmlEnableState_t mode) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceSetAccountingMode");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlEnableState_t) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlEnableState_t)) dlsym(nvml_handle, "nvmlDeviceSetAccountingMode");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, mode);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceSetApplicationsClocks(nvmlDevice_t device, unsigned int memClockMHz, unsigned int graphicsClockMHz) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceSetApplicationsClocks");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int, unsigned int) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int, unsigned int)) dlsym(nvml_handle, "nvmlDeviceSetApplicationsClocks");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, memClockMHz, graphicsClockMHz);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceSetAutoBoostedClocksEnabled(nvmlDevice_t device, nvmlEnableState_t enabled) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceSetAutoBoostedClocksEnabled");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlEnableState_t) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlEnableState_t)) dlsym(nvml_handle, "nvmlDeviceSetAutoBoostedClocksEnabled");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, enabled);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceSetComputeMode(nvmlDevice_t device, nvmlComputeMode_t mode) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceSetComputeMode");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlComputeMode_t) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlComputeMode_t)) dlsym(nvml_handle, "nvmlDeviceSetComputeMode");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, mode);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceSetCpuAffinity(nvmlDevice_t device) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceSetCpuAffinity");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t) = (nvmlReturn_t(*)(nvmlDevice_t)) dlsym(nvml_handle, "nvmlDeviceSetCpuAffinity");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceSetDefaultAutoBoostedClocksEnabled(nvmlDevice_t device, nvmlEnableState_t enabled, unsigned int flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceSetDefaultAutoBoostedClocksEnabled");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlEnableState_t, unsigned int) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlEnableState_t, unsigned int)) dlsym(nvml_handle, "nvmlDeviceSetDefaultAutoBoostedClocksEnabled");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, enabled, flags);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceSetDefaultFanSpeed_v2(nvmlDevice_t device, unsigned int fan) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceSetDefaultFanSpeed_v2");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int)) dlsym(nvml_handle, "nvmlDeviceSetDefaultFanSpeed_v2");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, fan);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceSetDriverModel(nvmlDevice_t device, nvmlDriverModel_t driverModel, unsigned int flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceSetDriverModel");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlDriverModel_t, unsigned int) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlDriverModel_t, unsigned int)) dlsym(nvml_handle, "nvmlDeviceSetDriverModel");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, driverModel, flags);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceSetEccMode(nvmlDevice_t device, nvmlEnableState_t ecc) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceSetEccMode");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlEnableState_t) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlEnableState_t)) dlsym(nvml_handle, "nvmlDeviceSetEccMode");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, ecc);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceSetFanSpeed_v2(nvmlDevice_t device, unsigned int fan, unsigned int speed) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceSetFanSpeed_v2");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int, unsigned int) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int, unsigned int)) dlsym(nvml_handle, "nvmlDeviceSetFanSpeed_v2");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, fan, speed);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceSetGpcClkVfOffset(nvmlDevice_t device, int offset) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceSetGpcClkVfOffset");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, int) = (nvmlReturn_t(*)(nvmlDevice_t, int)) dlsym(nvml_handle, "nvmlDeviceSetGpcClkVfOffset");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, offset);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceSetGpuLockedClocks(nvmlDevice_t device, unsigned int minGpuClockMHz, unsigned int maxGpuClockMHz) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceSetGpuLockedClocks");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int, unsigned int) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int, unsigned int)) dlsym(nvml_handle, "nvmlDeviceSetGpuLockedClocks");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, minGpuClockMHz, maxGpuClockMHz);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceSetGpuOperationMode(nvmlDevice_t device, nvmlGpuOperationMode_t mode) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceSetGpuOperationMode");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlGpuOperationMode_t) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlGpuOperationMode_t)) dlsym(nvml_handle, "nvmlDeviceSetGpuOperationMode");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, mode);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceSetMemClkVfOffset(nvmlDevice_t device, int offset) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceSetMemClkVfOffset");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, int) = (nvmlReturn_t(*)(nvmlDevice_t, int)) dlsym(nvml_handle, "nvmlDeviceSetMemClkVfOffset");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, offset);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceSetMemoryLockedClocks(nvmlDevice_t device, unsigned int minMemClockMHz, unsigned int maxMemClockMHz) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceSetMemoryLockedClocks");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int, unsigned int) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int, unsigned int)) dlsym(nvml_handle, "nvmlDeviceSetMemoryLockedClocks");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, minMemClockMHz, maxMemClockMHz);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceSetMigMode(nvmlDevice_t device, unsigned int mode, nvmlReturn_t * activationStatus) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceSetMigMode");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int, nvmlReturn_t *) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int, nvmlReturn_t *)) dlsym(nvml_handle, "nvmlDeviceSetMigMode");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, mode, activationStatus);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceSetNvLinkUtilizationControl(nvmlDevice_t device, unsigned int link, unsigned int counter, nvmlNvLinkUtilizationControl_t * control, unsigned int reset) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceSetNvLinkUtilizationControl");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int, unsigned int, nvmlNvLinkUtilizationControl_t *, unsigned int) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int, unsigned int, nvmlNvLinkUtilizationControl_t *, unsigned int)) dlsym(nvml_handle, "nvmlDeviceSetNvLinkUtilizationControl");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, link, counter, control, reset);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceSetPersistenceMode(nvmlDevice_t device, nvmlEnableState_t mode) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceSetPersistenceMode");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlEnableState_t) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlEnableState_t)) dlsym(nvml_handle, "nvmlDeviceSetPersistenceMode");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, mode);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceSetPowerManagementLimit(nvmlDevice_t device, unsigned int limit) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceSetPowerManagementLimit");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int)) dlsym(nvml_handle, "nvmlDeviceSetPowerManagementLimit");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, limit);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceSetPowerMode(nvmlDevice_t device, unsigned int powerModeId) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceSetPowerMode");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int)) dlsym(nvml_handle, "nvmlDeviceSetPowerMode");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, powerModeId);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceSetTemperatureThreshold(nvmlDevice_t device, nvmlTemperatureThresholds_t thresholdType, int * temp) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceSetTemperatureThreshold");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlTemperatureThresholds_t, int *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlTemperatureThresholds_t, int *)) dlsym(nvml_handle, "nvmlDeviceSetTemperatureThreshold");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, thresholdType, temp);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceSetVirtualizationMode(nvmlDevice_t device, nvmlGpuVirtualizationMode_t virtualMode) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceSetVirtualizationMode");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlGpuVirtualizationMode_t) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlGpuVirtualizationMode_t)) dlsym(nvml_handle, "nvmlDeviceSetVirtualizationMode");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, virtualMode);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlDeviceValidateInforom(nvmlDevice_t device) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlDeviceValidateInforom");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t) = (nvmlReturn_t(*)(nvmlDevice_t)) dlsym(nvml_handle, "nvmlDeviceValidateInforom");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlEventSetCreate(nvmlEventSet_t * set) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlEventSetCreate");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlEventSet_t *) = (nvmlReturn_t(*)(nvmlEventSet_t *)) dlsym(nvml_handle, "nvmlEventSetCreate");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(set);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlEventSetFree(nvmlEventSet_t set) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlEventSetFree");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlEventSet_t) = (nvmlReturn_t(*)(nvmlEventSet_t)) dlsym(nvml_handle, "nvmlEventSetFree");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(set);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlEventSetWait(nvmlEventSet_t set, nvmlEventData_t * data, unsigned int timeoutms) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlEventSetWait");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlEventSet_t, nvmlEventData_t *, unsigned int) = (nvmlReturn_t(*)(nvmlEventSet_t, nvmlEventData_t *, unsigned int)) dlsym(nvml_handle, "nvmlEventSetWait");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(set, data, timeoutms);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlEventSetWait_v2(nvmlEventSet_t set, nvmlEventData_t * data, unsigned int timeoutms) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlEventSetWait_v2");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlEventSet_t, nvmlEventData_t *, unsigned int) = (nvmlReturn_t(*)(nvmlEventSet_t, nvmlEventData_t *, unsigned int)) dlsym(nvml_handle, "nvmlEventSetWait_v2");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(set, data, timeoutms);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlGetExcludedDeviceCount(unsigned int * deviceCount) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlGetExcludedDeviceCount");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(unsigned int *) = (nvmlReturn_t(*)(unsigned int *)) dlsym(nvml_handle, "nvmlGetExcludedDeviceCount");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(deviceCount);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlGetExcludedDeviceInfoByIndex(unsigned int index, nvmlExcludedDeviceInfo_t * info) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlGetExcludedDeviceInfoByIndex");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(unsigned int, nvmlExcludedDeviceInfo_t *) = (nvmlReturn_t(*)(unsigned int, nvmlExcludedDeviceInfo_t *)) dlsym(nvml_handle, "nvmlGetExcludedDeviceInfoByIndex");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(index, info);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlGetVgpuCompatibility(nvmlVgpuMetadata_t * vgpuMetadata, nvmlVgpuPgpuMetadata_t * pgpuMetadata, nvmlVgpuPgpuCompatibility_t * compatibilityInfo) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlGetVgpuCompatibility");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlVgpuMetadata_t *, nvmlVgpuPgpuMetadata_t *, nvmlVgpuPgpuCompatibility_t *) = (nvmlReturn_t(*)(nvmlVgpuMetadata_t *, nvmlVgpuPgpuMetadata_t *, nvmlVgpuPgpuCompatibility_t *)) dlsym(nvml_handle, "nvmlGetVgpuCompatibility");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(vgpuMetadata, pgpuMetadata, compatibilityInfo);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlGetVgpuVersion(nvmlVgpuVersion_t * supported, nvmlVgpuVersion_t * current) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlGetVgpuVersion");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlVgpuVersion_t *, nvmlVgpuVersion_t *) = (nvmlReturn_t(*)(nvmlVgpuVersion_t *, nvmlVgpuVersion_t *)) dlsym(nvml_handle, "nvmlGetVgpuVersion");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(supported, current);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlGpmMetricsGet(nvmlGpmMetricsGet_t * metricsGet) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlGpmMetricsGet");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlGpmMetricsGet_t *) = (nvmlReturn_t(*)(nvmlGpmMetricsGet_t *)) dlsym(nvml_handle, "nvmlGpmMetricsGet");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(metricsGet);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlGpmMigSampleGet(nvmlDevice_t device, unsigned int gpuInstanceId, nvmlGpmSample_t gpmSample) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlGpmMigSampleGet");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, unsigned int, nvmlGpmSample_t) = (nvmlReturn_t(*)(nvmlDevice_t, unsigned int, nvmlGpmSample_t)) dlsym(nvml_handle, "nvmlGpmMigSampleGet");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, gpuInstanceId, gpmSample);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlGpmQueryDeviceSupport(nvmlDevice_t device, nvmlGpmSupport_t * gpmSupport) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlGpmQueryDeviceSupport");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlGpmSupport_t *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlGpmSupport_t *)) dlsym(nvml_handle, "nvmlGpmQueryDeviceSupport");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, gpmSupport);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlGpmSampleAlloc(nvmlGpmSample_t * gpmSample) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlGpmSampleAlloc");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlGpmSample_t *) = (nvmlReturn_t(*)(nvmlGpmSample_t *)) dlsym(nvml_handle, "nvmlGpmSampleAlloc");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(gpmSample);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlGpmSampleFree(nvmlGpmSample_t gpmSample) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlGpmSampleFree");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlGpmSample_t) = (nvmlReturn_t(*)(nvmlGpmSample_t)) dlsym(nvml_handle, "nvmlGpmSampleFree");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(gpmSample);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlGpmSampleGet(nvmlDevice_t device, nvmlGpmSample_t gpmSample) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlGpmSampleGet");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlGpmSample_t) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlGpmSample_t)) dlsym(nvml_handle, "nvmlGpmSampleGet");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, gpmSample);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlGpuInstanceCreateComputeInstance(nvmlGpuInstance_t gpuInstance, unsigned int profileId, nvmlComputeInstance_t * computeInstance) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlGpuInstanceCreateComputeInstance");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlGpuInstance_t, unsigned int, nvmlComputeInstance_t *) = (nvmlReturn_t(*)(nvmlGpuInstance_t, unsigned int, nvmlComputeInstance_t *)) dlsym(nvml_handle, "nvmlGpuInstanceCreateComputeInstance");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(gpuInstance, profileId, computeInstance);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlGpuInstanceCreateComputeInstanceWithPlacement(nvmlGpuInstance_t gpuInstance, unsigned int profileId, const nvmlComputeInstancePlacement_t * placement, nvmlComputeInstance_t * computeInstance) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlGpuInstanceCreateComputeInstanceWithPlacement");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlGpuInstance_t, unsigned int, const nvmlComputeInstancePlacement_t *, nvmlComputeInstance_t *) = (nvmlReturn_t(*)(nvmlGpuInstance_t, unsigned int, const nvmlComputeInstancePlacement_t *, nvmlComputeInstance_t *)) dlsym(nvml_handle, "nvmlGpuInstanceCreateComputeInstanceWithPlacement");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(gpuInstance, profileId, placement, computeInstance);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlGpuInstanceDestroy(nvmlGpuInstance_t gpuInstance) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlGpuInstanceDestroy");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlGpuInstance_t) = (nvmlReturn_t(*)(nvmlGpuInstance_t)) dlsym(nvml_handle, "nvmlGpuInstanceDestroy");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(gpuInstance);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlGpuInstanceGetComputeInstanceById(nvmlGpuInstance_t gpuInstance, unsigned int id, nvmlComputeInstance_t * computeInstance) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlGpuInstanceGetComputeInstanceById");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlGpuInstance_t, unsigned int, nvmlComputeInstance_t *) = (nvmlReturn_t(*)(nvmlGpuInstance_t, unsigned int, nvmlComputeInstance_t *)) dlsym(nvml_handle, "nvmlGpuInstanceGetComputeInstanceById");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(gpuInstance, id, computeInstance);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlGpuInstanceGetComputeInstancePossiblePlacements(nvmlGpuInstance_t gpuInstance, unsigned int profileId, nvmlComputeInstancePlacement_t * placements, unsigned int * count) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlGpuInstanceGetComputeInstancePossiblePlacements");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlGpuInstance_t, unsigned int, nvmlComputeInstancePlacement_t *, unsigned int *) = (nvmlReturn_t(*)(nvmlGpuInstance_t, unsigned int, nvmlComputeInstancePlacement_t *, unsigned int *)) dlsym(nvml_handle, "nvmlGpuInstanceGetComputeInstancePossiblePlacements");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(gpuInstance, profileId, placements, count);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlGpuInstanceGetComputeInstanceProfileInfo(nvmlGpuInstance_t gpuInstance, unsigned int profile, unsigned int engProfile, nvmlComputeInstanceProfileInfo_t * info) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlGpuInstanceGetComputeInstanceProfileInfo");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlGpuInstance_t, unsigned int, unsigned int, nvmlComputeInstanceProfileInfo_t *) = (nvmlReturn_t(*)(nvmlGpuInstance_t, unsigned int, unsigned int, nvmlComputeInstanceProfileInfo_t *)) dlsym(nvml_handle, "nvmlGpuInstanceGetComputeInstanceProfileInfo");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(gpuInstance, profile, engProfile, info);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlGpuInstanceGetComputeInstanceProfileInfoV(nvmlGpuInstance_t gpuInstance, unsigned int profile, unsigned int engProfile, nvmlComputeInstanceProfileInfo_v2_t * info) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlGpuInstanceGetComputeInstanceProfileInfoV");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlGpuInstance_t, unsigned int, unsigned int, nvmlComputeInstanceProfileInfo_v2_t *) = (nvmlReturn_t(*)(nvmlGpuInstance_t, unsigned int, unsigned int, nvmlComputeInstanceProfileInfo_v2_t *)) dlsym(nvml_handle, "nvmlGpuInstanceGetComputeInstanceProfileInfoV");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(gpuInstance, profile, engProfile, info);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlGpuInstanceGetComputeInstanceRemainingCapacity(nvmlGpuInstance_t gpuInstance, unsigned int profileId, unsigned int * count) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlGpuInstanceGetComputeInstanceRemainingCapacity");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlGpuInstance_t, unsigned int, unsigned int *) = (nvmlReturn_t(*)(nvmlGpuInstance_t, unsigned int, unsigned int *)) dlsym(nvml_handle, "nvmlGpuInstanceGetComputeInstanceRemainingCapacity");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(gpuInstance, profileId, count);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlGpuInstanceGetComputeInstances(nvmlGpuInstance_t gpuInstance, unsigned int profileId, nvmlComputeInstance_t * computeInstances, unsigned int * count) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlGpuInstanceGetComputeInstances");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlGpuInstance_t, unsigned int, nvmlComputeInstance_t *, unsigned int *) = (nvmlReturn_t(*)(nvmlGpuInstance_t, unsigned int, nvmlComputeInstance_t *, unsigned int *)) dlsym(nvml_handle, "nvmlGpuInstanceGetComputeInstances");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(gpuInstance, profileId, computeInstances, count);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlGpuInstanceGetInfo(nvmlGpuInstance_t gpuInstance, nvmlGpuInstanceInfo_t * info) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlGpuInstanceGetInfo");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlGpuInstance_t, nvmlGpuInstanceInfo_t *) = (nvmlReturn_t(*)(nvmlGpuInstance_t, nvmlGpuInstanceInfo_t *)) dlsym(nvml_handle, "nvmlGpuInstanceGetInfo");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(gpuInstance, info);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlInternalGetExportTable(const void * * ppExportTable, void * pExportTableId) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlInternalGetExportTable");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(const void * *, void *) = (nvmlReturn_t(*)(const void * *, void *)) dlsym(nvml_handle, "nvmlInternalGetExportTable");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(ppExportTable, pExportTableId);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlSetVgpuVersion(nvmlVgpuVersion_t * vgpuVersion) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlSetVgpuVersion");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlVgpuVersion_t *) = (nvmlReturn_t(*)(nvmlVgpuVersion_t *)) dlsym(nvml_handle, "nvmlSetVgpuVersion");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(vgpuVersion);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlShutdown() {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlShutdown");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)() = (nvmlReturn_t(*)()) dlsym(nvml_handle, "nvmlShutdown");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc();
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlSystemGetCudaDriverVersion(int * cudaDriverVersion) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlSystemGetCudaDriverVersion");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(int *) = (nvmlReturn_t(*)(int *)) dlsym(nvml_handle, "nvmlSystemGetCudaDriverVersion");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(cudaDriverVersion);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlSystemGetCudaDriverVersion_v2(int * cudaDriverVersion) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlSystemGetCudaDriverVersion_v2");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(int *) = (nvmlReturn_t(*)(int *)) dlsym(nvml_handle, "nvmlSystemGetCudaDriverVersion_v2");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(cudaDriverVersion);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlSystemGetDriverVersion(char * version, unsigned int length) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlSystemGetDriverVersion");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(char *, unsigned int) = (nvmlReturn_t(*)(char *, unsigned int)) dlsym(nvml_handle, "nvmlSystemGetDriverVersion");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(version, length);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlSystemGetHicVersion(unsigned int * hwbcCount, nvmlHwbcEntry_t * hwbcEntries) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlSystemGetHicVersion");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(unsigned int *, nvmlHwbcEntry_t *) = (nvmlReturn_t(*)(unsigned int *, nvmlHwbcEntry_t *)) dlsym(nvml_handle, "nvmlSystemGetHicVersion");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(hwbcCount, hwbcEntries);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlSystemGetNVMLVersion(char * version, unsigned int length) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlSystemGetNVMLVersion");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(char *, unsigned int) = (nvmlReturn_t(*)(char *, unsigned int)) dlsym(nvml_handle, "nvmlSystemGetNVMLVersion");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(version, length);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlSystemGetProcessName(unsigned int pid, char * name, unsigned int length) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlSystemGetProcessName");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(unsigned int, char *, unsigned int) = (nvmlReturn_t(*)(unsigned int, char *, unsigned int)) dlsym(nvml_handle, "nvmlSystemGetProcessName");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(pid, name, length);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlSystemGetTopologyGpuSet(unsigned int cpuNumber, unsigned int * count, nvmlDevice_t * deviceArray) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlSystemGetTopologyGpuSet");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(unsigned int, unsigned int *, nvmlDevice_t *) = (nvmlReturn_t(*)(unsigned int, unsigned int *, nvmlDevice_t *)) dlsym(nvml_handle, "nvmlSystemGetTopologyGpuSet");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(cpuNumber, count, deviceArray);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlUnitGetCount(unsigned int * unitCount) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlUnitGetCount");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(unsigned int *) = (nvmlReturn_t(*)(unsigned int *)) dlsym(nvml_handle, "nvmlUnitGetCount");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(unitCount);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlUnitGetDevices(nvmlUnit_t unit, unsigned int * deviceCount, nvmlDevice_t * devices) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlUnitGetDevices");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlUnit_t, unsigned int *, nvmlDevice_t *) = (nvmlReturn_t(*)(nvmlUnit_t, unsigned int *, nvmlDevice_t *)) dlsym(nvml_handle, "nvmlUnitGetDevices");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(unit, deviceCount, devices);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlUnitGetFanSpeedInfo(nvmlUnit_t unit, nvmlUnitFanSpeeds_t * fanSpeeds) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlUnitGetFanSpeedInfo");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlUnit_t, nvmlUnitFanSpeeds_t *) = (nvmlReturn_t(*)(nvmlUnit_t, nvmlUnitFanSpeeds_t *)) dlsym(nvml_handle, "nvmlUnitGetFanSpeedInfo");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(unit, fanSpeeds);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlUnitGetHandleByIndex(unsigned int index, nvmlUnit_t * unit) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlUnitGetHandleByIndex");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(unsigned int, nvmlUnit_t *) = (nvmlReturn_t(*)(unsigned int, nvmlUnit_t *)) dlsym(nvml_handle, "nvmlUnitGetHandleByIndex");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(index, unit);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlUnitGetLedState(nvmlUnit_t unit, nvmlLedState_t * state) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlUnitGetLedState");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlUnit_t, nvmlLedState_t *) = (nvmlReturn_t(*)(nvmlUnit_t, nvmlLedState_t *)) dlsym(nvml_handle, "nvmlUnitGetLedState");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(unit, state);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlUnitGetPsuInfo(nvmlUnit_t unit, nvmlPSUInfo_t * psu) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlUnitGetPsuInfo");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlUnit_t, nvmlPSUInfo_t *) = (nvmlReturn_t(*)(nvmlUnit_t, nvmlPSUInfo_t *)) dlsym(nvml_handle, "nvmlUnitGetPsuInfo");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(unit, psu);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlUnitGetTemperature(nvmlUnit_t unit, unsigned int type, unsigned int * temp) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlUnitGetTemperature");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlUnit_t, unsigned int, unsigned int *) = (nvmlReturn_t(*)(nvmlUnit_t, unsigned int, unsigned int *)) dlsym(nvml_handle, "nvmlUnitGetTemperature");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(unit, type, temp);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlUnitGetUnitInfo(nvmlUnit_t unit, nvmlUnitInfo_t * info) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlUnitGetUnitInfo");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlUnit_t, nvmlUnitInfo_t *) = (nvmlReturn_t(*)(nvmlUnit_t, nvmlUnitInfo_t *)) dlsym(nvml_handle, "nvmlUnitGetUnitInfo");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(unit, info);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlUnitSetLedState(nvmlUnit_t unit, nvmlLedColor_t color) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlUnitSetLedState");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlUnit_t, nvmlLedColor_t) = (nvmlReturn_t(*)(nvmlUnit_t, nvmlLedColor_t)) dlsym(nvml_handle, "nvmlUnitSetLedState");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(unit, color);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlVgpuInstanceClearAccountingPids(nvmlVgpuInstance_t vgpuInstance) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlVgpuInstanceClearAccountingPids");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlVgpuInstance_t) = (nvmlReturn_t(*)(nvmlVgpuInstance_t)) dlsym(nvml_handle, "nvmlVgpuInstanceClearAccountingPids");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(vgpuInstance);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlVgpuInstanceGetAccountingMode(nvmlVgpuInstance_t vgpuInstance, nvmlEnableState_t * mode) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlVgpuInstanceGetAccountingMode");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlVgpuInstance_t, nvmlEnableState_t *) = (nvmlReturn_t(*)(nvmlVgpuInstance_t, nvmlEnableState_t *)) dlsym(nvml_handle, "nvmlVgpuInstanceGetAccountingMode");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(vgpuInstance, mode);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlVgpuInstanceGetAccountingPids(nvmlVgpuInstance_t vgpuInstance, unsigned int * count, unsigned int * pids) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlVgpuInstanceGetAccountingPids");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlVgpuInstance_t, unsigned int *, unsigned int *) = (nvmlReturn_t(*)(nvmlVgpuInstance_t, unsigned int *, unsigned int *)) dlsym(nvml_handle, "nvmlVgpuInstanceGetAccountingPids");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(vgpuInstance, count, pids);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlVgpuInstanceGetAccountingStats(nvmlVgpuInstance_t vgpuInstance, unsigned int pid, nvmlAccountingStats_t * stats) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlVgpuInstanceGetAccountingStats");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlVgpuInstance_t, unsigned int, nvmlAccountingStats_t *) = (nvmlReturn_t(*)(nvmlVgpuInstance_t, unsigned int, nvmlAccountingStats_t *)) dlsym(nvml_handle, "nvmlVgpuInstanceGetAccountingStats");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(vgpuInstance, pid, stats);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlVgpuInstanceGetEccMode(nvmlVgpuInstance_t vgpuInstance, nvmlEnableState_t * eccMode) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlVgpuInstanceGetEccMode");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlVgpuInstance_t, nvmlEnableState_t *) = (nvmlReturn_t(*)(nvmlVgpuInstance_t, nvmlEnableState_t *)) dlsym(nvml_handle, "nvmlVgpuInstanceGetEccMode");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(vgpuInstance, eccMode);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlVgpuInstanceGetEncoderCapacity(nvmlVgpuInstance_t vgpuInstance, unsigned int * encoderCapacity) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlVgpuInstanceGetEncoderCapacity");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlVgpuInstance_t, unsigned int *) = (nvmlReturn_t(*)(nvmlVgpuInstance_t, unsigned int *)) dlsym(nvml_handle, "nvmlVgpuInstanceGetEncoderCapacity");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(vgpuInstance, encoderCapacity);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlVgpuInstanceGetEncoderSessions(nvmlVgpuInstance_t vgpuInstance, unsigned int * sessionCount, nvmlEncoderSessionInfo_t * sessionInfo) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlVgpuInstanceGetEncoderSessions");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlVgpuInstance_t, unsigned int *, nvmlEncoderSessionInfo_t *) = (nvmlReturn_t(*)(nvmlVgpuInstance_t, unsigned int *, nvmlEncoderSessionInfo_t *)) dlsym(nvml_handle, "nvmlVgpuInstanceGetEncoderSessions");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(vgpuInstance, sessionCount, sessionInfo);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlVgpuInstanceGetEncoderStats(nvmlVgpuInstance_t vgpuInstance, unsigned int * sessionCount, unsigned int * averageFps, unsigned int * averageLatency) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlVgpuInstanceGetEncoderStats");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlVgpuInstance_t, unsigned int *, unsigned int *, unsigned int *) = (nvmlReturn_t(*)(nvmlVgpuInstance_t, unsigned int *, unsigned int *, unsigned int *)) dlsym(nvml_handle, "nvmlVgpuInstanceGetEncoderStats");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(vgpuInstance, sessionCount, averageFps, averageLatency);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlVgpuInstanceGetFBCSessions(nvmlVgpuInstance_t vgpuInstance, unsigned int * sessionCount, nvmlFBCSessionInfo_t * sessionInfo) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlVgpuInstanceGetFBCSessions");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlVgpuInstance_t, unsigned int *, nvmlFBCSessionInfo_t *) = (nvmlReturn_t(*)(nvmlVgpuInstance_t, unsigned int *, nvmlFBCSessionInfo_t *)) dlsym(nvml_handle, "nvmlVgpuInstanceGetFBCSessions");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(vgpuInstance, sessionCount, sessionInfo);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlVgpuInstanceGetFBCStats(nvmlVgpuInstance_t vgpuInstance, nvmlFBCStats_t * fbcStats) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlVgpuInstanceGetFBCStats");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlVgpuInstance_t, nvmlFBCStats_t *) = (nvmlReturn_t(*)(nvmlVgpuInstance_t, nvmlFBCStats_t *)) dlsym(nvml_handle, "nvmlVgpuInstanceGetFBCStats");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(vgpuInstance, fbcStats);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlVgpuInstanceGetFbUsage(nvmlVgpuInstance_t vgpuInstance, unsigned long long * fbUsage) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlVgpuInstanceGetFbUsage");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlVgpuInstance_t, unsigned long long *) = (nvmlReturn_t(*)(nvmlVgpuInstance_t, unsigned long long *)) dlsym(nvml_handle, "nvmlVgpuInstanceGetFbUsage");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(vgpuInstance, fbUsage);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlVgpuInstanceGetFrameRateLimit(nvmlVgpuInstance_t vgpuInstance, unsigned int * frameRateLimit) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlVgpuInstanceGetFrameRateLimit");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlVgpuInstance_t, unsigned int *) = (nvmlReturn_t(*)(nvmlVgpuInstance_t, unsigned int *)) dlsym(nvml_handle, "nvmlVgpuInstanceGetFrameRateLimit");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(vgpuInstance, frameRateLimit);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlVgpuInstanceGetGpuInstanceId(nvmlVgpuInstance_t vgpuInstance, unsigned int * gpuInstanceId) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlVgpuInstanceGetGpuInstanceId");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlVgpuInstance_t, unsigned int *) = (nvmlReturn_t(*)(nvmlVgpuInstance_t, unsigned int *)) dlsym(nvml_handle, "nvmlVgpuInstanceGetGpuInstanceId");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(vgpuInstance, gpuInstanceId);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlVgpuInstanceGetGpuPciId(nvmlVgpuInstance_t vgpuInstance, char * vgpuPciId, unsigned int * length) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlVgpuInstanceGetGpuPciId");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlVgpuInstance_t, char *, unsigned int *) = (nvmlReturn_t(*)(nvmlVgpuInstance_t, char *, unsigned int *)) dlsym(nvml_handle, "nvmlVgpuInstanceGetGpuPciId");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(vgpuInstance, vgpuPciId, length);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlVgpuInstanceGetLicenseInfo(nvmlVgpuInstance_t vgpuInstance, nvmlVgpuLicenseInfo_t * licenseInfo) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlVgpuInstanceGetLicenseInfo");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlVgpuInstance_t, nvmlVgpuLicenseInfo_t *) = (nvmlReturn_t(*)(nvmlVgpuInstance_t, nvmlVgpuLicenseInfo_t *)) dlsym(nvml_handle, "nvmlVgpuInstanceGetLicenseInfo");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(vgpuInstance, licenseInfo);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlVgpuInstanceGetLicenseInfo_v2(nvmlVgpuInstance_t vgpuInstance, nvmlVgpuLicenseInfo_t * licenseInfo) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlVgpuInstanceGetLicenseInfo_v2");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlVgpuInstance_t, nvmlVgpuLicenseInfo_t *) = (nvmlReturn_t(*)(nvmlVgpuInstance_t, nvmlVgpuLicenseInfo_t *)) dlsym(nvml_handle, "nvmlVgpuInstanceGetLicenseInfo_v2");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(vgpuInstance, licenseInfo);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlVgpuInstanceGetLicenseStatus(nvmlVgpuInstance_t vgpuInstance, unsigned int * licensed) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlVgpuInstanceGetLicenseStatus");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlVgpuInstance_t, unsigned int *) = (nvmlReturn_t(*)(nvmlVgpuInstance_t, unsigned int *)) dlsym(nvml_handle, "nvmlVgpuInstanceGetLicenseStatus");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(vgpuInstance, licensed);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlVgpuInstanceGetMdevUUID(nvmlVgpuInstance_t vgpuInstance, char * mdevUuid, unsigned int size) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlVgpuInstanceGetMdevUUID");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlVgpuInstance_t, char *, unsigned int) = (nvmlReturn_t(*)(nvmlVgpuInstance_t, char *, unsigned int)) dlsym(nvml_handle, "nvmlVgpuInstanceGetMdevUUID");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(vgpuInstance, mdevUuid, size);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlVgpuInstanceGetMetadata(nvmlVgpuInstance_t vgpuInstance, nvmlVgpuMetadata_t * vgpuMetadata, unsigned int * bufferSize) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlVgpuInstanceGetMetadata");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlVgpuInstance_t, nvmlVgpuMetadata_t *, unsigned int *) = (nvmlReturn_t(*)(nvmlVgpuInstance_t, nvmlVgpuMetadata_t *, unsigned int *)) dlsym(nvml_handle, "nvmlVgpuInstanceGetMetadata");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(vgpuInstance, vgpuMetadata, bufferSize);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlVgpuInstanceGetType(nvmlVgpuInstance_t vgpuInstance, nvmlVgpuTypeId_t * vgpuTypeId) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlVgpuInstanceGetType");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlVgpuInstance_t, nvmlVgpuTypeId_t *) = (nvmlReturn_t(*)(nvmlVgpuInstance_t, nvmlVgpuTypeId_t *)) dlsym(nvml_handle, "nvmlVgpuInstanceGetType");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(vgpuInstance, vgpuTypeId);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlVgpuInstanceGetUUID(nvmlVgpuInstance_t vgpuInstance, char * uuid, unsigned int size) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlVgpuInstanceGetUUID");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlVgpuInstance_t, char *, unsigned int) = (nvmlReturn_t(*)(nvmlVgpuInstance_t, char *, unsigned int)) dlsym(nvml_handle, "nvmlVgpuInstanceGetUUID");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(vgpuInstance, uuid, size);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlVgpuInstanceGetVmDriverVersion(nvmlVgpuInstance_t vgpuInstance, char * version, unsigned int length) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlVgpuInstanceGetVmDriverVersion");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlVgpuInstance_t, char *, unsigned int) = (nvmlReturn_t(*)(nvmlVgpuInstance_t, char *, unsigned int)) dlsym(nvml_handle, "nvmlVgpuInstanceGetVmDriverVersion");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(vgpuInstance, version, length);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlVgpuInstanceGetVmID(nvmlVgpuInstance_t vgpuInstance, char * vmId, unsigned int size, nvmlVgpuVmIdType_t * vmIdType) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlVgpuInstanceGetVmID");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlVgpuInstance_t, char *, unsigned int, nvmlVgpuVmIdType_t *) = (nvmlReturn_t(*)(nvmlVgpuInstance_t, char *, unsigned int, nvmlVgpuVmIdType_t *)) dlsym(nvml_handle, "nvmlVgpuInstanceGetVmID");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(vgpuInstance, vmId, size, vmIdType);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlVgpuInstanceSetEncoderCapacity(nvmlVgpuInstance_t vgpuInstance, unsigned int encoderCapacity) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlVgpuInstanceSetEncoderCapacity");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlVgpuInstance_t, unsigned int) = (nvmlReturn_t(*)(nvmlVgpuInstance_t, unsigned int)) dlsym(nvml_handle, "nvmlVgpuInstanceSetEncoderCapacity");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(vgpuInstance, encoderCapacity);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlVgpuTypeGetCapabilities(nvmlVgpuTypeId_t vgpuTypeId, nvmlVgpuCapability_t capability, unsigned int * capResult) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlVgpuTypeGetCapabilities");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlVgpuTypeId_t, nvmlVgpuCapability_t, unsigned int *) = (nvmlReturn_t(*)(nvmlVgpuTypeId_t, nvmlVgpuCapability_t, unsigned int *)) dlsym(nvml_handle, "nvmlVgpuTypeGetCapabilities");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(vgpuTypeId, capability, capResult);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlVgpuTypeGetClass(nvmlVgpuTypeId_t vgpuTypeId, char * vgpuTypeClass, unsigned int * size) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlVgpuTypeGetClass");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlVgpuTypeId_t, char *, unsigned int *) = (nvmlReturn_t(*)(nvmlVgpuTypeId_t, char *, unsigned int *)) dlsym(nvml_handle, "nvmlVgpuTypeGetClass");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(vgpuTypeId, vgpuTypeClass, size);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlVgpuTypeGetDeviceID(nvmlVgpuTypeId_t vgpuTypeId, unsigned long long * deviceID, unsigned long long * subsystemID) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlVgpuTypeGetDeviceID");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlVgpuTypeId_t, unsigned long long *, unsigned long long *) = (nvmlReturn_t(*)(nvmlVgpuTypeId_t, unsigned long long *, unsigned long long *)) dlsym(nvml_handle, "nvmlVgpuTypeGetDeviceID");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(vgpuTypeId, deviceID, subsystemID);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlVgpuTypeGetFrameRateLimit(nvmlVgpuTypeId_t vgpuTypeId, unsigned int * frameRateLimit) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlVgpuTypeGetFrameRateLimit");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlVgpuTypeId_t, unsigned int *) = (nvmlReturn_t(*)(nvmlVgpuTypeId_t, unsigned int *)) dlsym(nvml_handle, "nvmlVgpuTypeGetFrameRateLimit");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(vgpuTypeId, frameRateLimit);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlVgpuTypeGetFramebufferSize(nvmlVgpuTypeId_t vgpuTypeId, unsigned long long * fbSize) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlVgpuTypeGetFramebufferSize");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlVgpuTypeId_t, unsigned long long *) = (nvmlReturn_t(*)(nvmlVgpuTypeId_t, unsigned long long *)) dlsym(nvml_handle, "nvmlVgpuTypeGetFramebufferSize");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(vgpuTypeId, fbSize);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlVgpuTypeGetGpuInstanceProfileId(nvmlVgpuTypeId_t vgpuTypeId, unsigned int * gpuInstanceProfileId) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlVgpuTypeGetGpuInstanceProfileId");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlVgpuTypeId_t, unsigned int *) = (nvmlReturn_t(*)(nvmlVgpuTypeId_t, unsigned int *)) dlsym(nvml_handle, "nvmlVgpuTypeGetGpuInstanceProfileId");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(vgpuTypeId, gpuInstanceProfileId);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlVgpuTypeGetLicense(nvmlVgpuTypeId_t vgpuTypeId, char * vgpuTypeLicenseString, unsigned int size) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlVgpuTypeGetLicense");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlVgpuTypeId_t, char *, unsigned int) = (nvmlReturn_t(*)(nvmlVgpuTypeId_t, char *, unsigned int)) dlsym(nvml_handle, "nvmlVgpuTypeGetLicense");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(vgpuTypeId, vgpuTypeLicenseString, size);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlVgpuTypeGetMaxInstances(nvmlDevice_t device, nvmlVgpuTypeId_t vgpuTypeId, unsigned int * vgpuInstanceCount) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlVgpuTypeGetMaxInstances");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlDevice_t, nvmlVgpuTypeId_t, unsigned int *) = (nvmlReturn_t(*)(nvmlDevice_t, nvmlVgpuTypeId_t, unsigned int *)) dlsym(nvml_handle, "nvmlVgpuTypeGetMaxInstances");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(device, vgpuTypeId, vgpuInstanceCount);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlVgpuTypeGetMaxInstancesPerVm(nvmlVgpuTypeId_t vgpuTypeId, unsigned int * vgpuInstanceCountPerVm) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlVgpuTypeGetMaxInstancesPerVm");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlVgpuTypeId_t, unsigned int *) = (nvmlReturn_t(*)(nvmlVgpuTypeId_t, unsigned int *)) dlsym(nvml_handle, "nvmlVgpuTypeGetMaxInstancesPerVm");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(vgpuTypeId, vgpuInstanceCountPerVm);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlVgpuTypeGetName(nvmlVgpuTypeId_t vgpuTypeId, char * vgpuTypeName, unsigned int * size) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlVgpuTypeGetName");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlVgpuTypeId_t, char *, unsigned int *) = (nvmlReturn_t(*)(nvmlVgpuTypeId_t, char *, unsigned int *)) dlsym(nvml_handle, "nvmlVgpuTypeGetName");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(vgpuTypeId, vgpuTypeName, size);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlVgpuTypeGetNumDisplayHeads(nvmlVgpuTypeId_t vgpuTypeId, unsigned int * numDisplayHeads) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlVgpuTypeGetNumDisplayHeads");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlVgpuTypeId_t, unsigned int *) = (nvmlReturn_t(*)(nvmlVgpuTypeId_t, unsigned int *)) dlsym(nvml_handle, "nvmlVgpuTypeGetNumDisplayHeads");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(vgpuTypeId, numDisplayHeads);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}

nvmlReturn_t nvmlVgpuTypeGetResolution(nvmlVgpuTypeId_t vgpuTypeId, unsigned int displayIndex, unsigned int * xdim, unsigned int * ydim) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlVgpuTypeGetResolution");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(nvmlVgpuTypeId_t, unsigned int, unsigned int *, unsigned int *) = (nvmlReturn_t(*)(nvmlVgpuTypeId_t, unsigned int, unsigned int *, unsigned int *)) dlsym(nvml_handle, "nvmlVgpuTypeGetResolution");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(vgpuTypeId, displayIndex, xdim, ydim);
    nvmlTimeProfileDestroy(pprof, rs);
    return rs;
}
