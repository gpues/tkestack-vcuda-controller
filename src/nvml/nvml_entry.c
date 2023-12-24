#include "include/all.h"

extern void *nvml_library_entry[1024];
extern vgpuDevice vdevices[16];
extern unsigned int virtual_nvml_devices[17];

nvmlReturn_t nvmlDeviceClearAccountingPids(nvmlDevice_t device) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceClearAccountingPids");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceClearAccountingPids, handle_remap(device));
}
nvmlReturn_t nvmlDeviceClearCpuAffinity(nvmlDevice_t device) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceClearCpuAffinity");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceClearCpuAffinity, handle_remap(device));
}

nvmlReturn_t nvmlDeviceCreateGpuInstance(nvmlDevice_t device, unsigned int profileId, nvmlGpuInstance_t *gpuInstance) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceCreateGpuInstance");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceCreateGpuInstance, handle_remap(device), profileId, gpuInstance);
}
nvmlReturn_t nvmlDeviceCreateGpuInstanceWithPlacement(nvmlDevice_t device, unsigned int profileId, const nvmlGpuInstancePlacement_t *placement, nvmlGpuInstance_t *gpuInstance) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceCreateGpuInstanceWithPlacement");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceCreateGpuInstanceWithPlacement, handle_remap(device), profileId, placement, gpuInstance);
}
nvmlReturn_t nvmlDeviceFreezeNvLinkUtilizationCounter(nvmlDevice_t device, unsigned int link, unsigned int counter, nvmlEnableState_t freeze) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceFreezeNvLinkUtilizationCounter");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceFreezeNvLinkUtilizationCounter, handle_remap(device), link, counter, freeze);
}
nvmlReturn_t nvmlDeviceGetAccountingBufferSize(nvmlDevice_t device, unsigned int *bufferSize) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetAccountingBufferSize");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetAccountingBufferSize, handle_remap(device), bufferSize);
}
nvmlReturn_t nvmlDeviceGetAccountingMode(nvmlDevice_t device, nvmlEnableState_t *mode) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetAccountingMode");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetAccountingMode, handle_remap(device), mode);
}
nvmlReturn_t nvmlDeviceGetAccountingPids(nvmlDevice_t device, unsigned int *count, unsigned int *pids) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetAccountingPids");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetAccountingPids, handle_remap(device), count, pids);
}
nvmlReturn_t nvmlDeviceGetAccountingStats(nvmlDevice_t device, unsigned int pid, nvmlAccountingStats_t *stats) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetAccountingStats");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetAccountingStats, handle_remap(device), pid, stats);
}
nvmlReturn_t nvmlDeviceGetActiveVgpus(nvmlDevice_t device, unsigned int *vgpuCount, nvmlVgpuInstance_t *vgpuInstances) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetActiveVgpus");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetActiveVgpus, handle_remap(device), vgpuCount, vgpuInstances);
}
nvmlReturn_t nvmlDeviceGetApplicationsClock(nvmlDevice_t device, nvmlClockType_t clockType, unsigned int *clockMHz) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetApplicationsClock");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetApplicationsClock, handle_remap(device), clockType, clockMHz);
}
nvmlReturn_t nvmlDeviceGetAPIRestriction(nvmlDevice_t device, nvmlRestrictedAPI_t apiType, nvmlEnableState_t *isRestricted) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetAPIRestriction");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetAPIRestriction, handle_remap(device), apiType, isRestricted);
}
nvmlReturn_t nvmlDeviceGetArchitecture(nvmlDevice_t device, nvmlDeviceArchitecture_t *arch) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetArchitecture");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetArchitecture, handle_remap(device), arch);
}
nvmlReturn_t nvmlDeviceGetAttributes(nvmlDevice_t device, nvmlDeviceAttributes_t *attributes) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetAttributes");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetAttributes, handle_remap(device), attributes);
}
nvmlReturn_t nvmlDeviceGetAttributes_v2(nvmlDevice_t device, nvmlDeviceAttributes_t *attributes) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetAttributes_v2");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetAttributes_v2, handle_remap(device), attributes);
}
nvmlReturn_t nvmlDeviceGetAutoBoostedClocksEnabled(nvmlDevice_t device, nvmlEnableState_t *isEnabled, nvmlEnableState_t *defaultIsEnabled) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetAutoBoostedClocksEnabled");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetAutoBoostedClocksEnabled, handle_remap(device), isEnabled, defaultIsEnabled);
}

nvmlReturn_t nvmlDeviceGetBAR1MemoryInfo(nvmlDevice_t device, nvmlBAR1Memory_t *bar1Memory) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetBAR1MemoryInfo");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetBAR1MemoryInfo, handle_remap(device), bar1Memory);
}
nvmlReturn_t nvmlDeviceGetBoardId(nvmlDevice_t device, unsigned int *boardId) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetBoardId");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetBoardId, handle_remap(device), boardId);
}
nvmlReturn_t nvmlDeviceGetBoardPartNumber(nvmlDevice_t device, char *partNumber, unsigned int length) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetBoardPartNumber");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetBoardPartNumber, handle_remap(device), partNumber, length);
}
nvmlReturn_t nvmlDeviceGetBrand(nvmlDevice_t device, nvmlBrandType_t *type) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetBrand");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetBrand, handle_remap(device), type);
}
nvmlReturn_t nvmlDeviceGetBridgeChipInfo(nvmlDevice_t device, nvmlBridgeChipHierarchy_t *bridgeHierarchy) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetBridgeChipInfo");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetBridgeChipInfo, handle_remap(device), bridgeHierarchy);
}
nvmlReturn_t nvmlDeviceGetBusType(nvmlDevice_t device, nvmlBusType_t *type) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetBusType");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetBusType, handle_remap(device), type);
}
nvmlReturn_t nvmlDeviceGetClkMonStatus(nvmlDevice_t device, nvmlClkMonStatus_t *status) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetClkMonStatus");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetClkMonStatus, handle_remap(device), status);
}
nvmlReturn_t nvmlDeviceGetClock(nvmlDevice_t device, nvmlClockType_t clockType, nvmlClockId_t clockId, unsigned int *clockMHz) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetClock");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetClock, handle_remap(device), clockType, clockId, clockMHz);
}
nvmlReturn_t nvmlDeviceGetClockInfo(nvmlDevice_t device, nvmlClockType_t type, unsigned int *clock) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetClockInfo");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetClockInfo, handle_remap(device), type, clock);
}
nvmlReturn_t nvmlDeviceGetComputeInstanceId(nvmlDevice_t device, unsigned int *id) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetComputeInstanceId");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetComputeInstanceId, handle_remap(device), id);
}
nvmlReturn_t nvmlDeviceGetComputeMode(nvmlDevice_t device, nvmlComputeMode_t *mode) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetComputeMode");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetComputeMode, handle_remap(device), mode);
}
nvmlReturn_t nvmlDeviceGetComputeRunningProcesses_v2(nvmlDevice_t device, unsigned int *infoCount, nvmlProcessInfo_v2_t *infos) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetComputeRunningProcesses_v2");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetComputeRunningProcesses_v2, handle_remap(device), infoCount, infos);
}
nvmlReturn_t nvmlDeviceGetCpuAffinity(nvmlDevice_t device, unsigned int cpuSetSize, unsigned long *cpuSet) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetCpuAffinity");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetCpuAffinity, handle_remap(device), cpuSetSize, cpuSet);
}
nvmlReturn_t nvmlDeviceGetCpuAffinityWithinScope(nvmlDevice_t device, unsigned int cpuSetSize, unsigned long *cpuSet, nvmlAffinityScope_t scope) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetCpuAffinityWithinScope");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetCpuAffinityWithinScope, handle_remap(device), cpuSetSize, cpuSet, scope);
}
nvmlReturn_t nvmlDeviceGetCreatableVgpus(nvmlDevice_t device, unsigned int *vgpuCount, nvmlVgpuTypeId_t *vgpuTypeIds) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetCreatableVgpus");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetCreatableVgpus, handle_remap(device), vgpuCount, vgpuTypeIds);
}
nvmlReturn_t nvmlDeviceGetCudaComputeCapability(nvmlDevice_t device, int *major, int *minor) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetCudaComputeCapability");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetCudaComputeCapability, handle_remap(device), major, minor);
}
nvmlReturn_t nvmlDeviceGetCurrPcieLinkGeneration(nvmlDevice_t device, unsigned int *currLinkGen) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetCurrPcieLinkGeneration");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetCurrPcieLinkGeneration, handle_remap(device), currLinkGen);
}
nvmlReturn_t nvmlDeviceGetCurrPcieLinkWidth(nvmlDevice_t device, unsigned int *currLinkWidth) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetCurrPcieLinkWidth");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetCurrPcieLinkWidth, handle_remap(device), currLinkWidth);
}
nvmlReturn_t nvmlDeviceGetCurrentClocksThrottleReasons(nvmlDevice_t device, unsigned long long *clocksThrottleReasons) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetCurrentClocksThrottleReasons");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetCurrentClocksThrottleReasons, handle_remap(device), clocksThrottleReasons);
}
nvmlReturn_t nvmlDeviceGetDecoderUtilization(nvmlDevice_t device, unsigned int *utilization, unsigned int *samplingPeriodUs) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetDecoderUtilization");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetDecoderUtilization, handle_remap(device), utilization, samplingPeriodUs);
}
nvmlReturn_t nvmlDeviceGetDefaultApplicationsClock(nvmlDevice_t device, nvmlClockType_t clockType, unsigned int *clockMHz) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetDefaultApplicationsClock");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetDefaultApplicationsClock, handle_remap(device), clockType, clockMHz);
}
nvmlReturn_t nvmlDeviceGetDetailedEccErrors(nvmlDevice_t device, nvmlMemoryErrorType_t errorType, nvmlEccCounterType_t counterType, nvmlEccErrorCounts_t *eccCounts) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetDetailedEccErrors");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetDetailedEccErrors, handle_remap(device), errorType, counterType, eccCounts);
}
nvmlReturn_t nvmlDeviceGetDeviceHandleFromMigDeviceHandle(nvmlDevice_t migDevice, nvmlDevice_t *device) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetDeviceHandleFromMigDeviceHandle");
    nvmlReturn_t res = NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetDeviceHandleFromMigDeviceHandle, migDevice, handle_remap(*device));
    *device = handle_remap(*device);
    return res;
}
nvmlReturn_t nvmlDeviceGetDisplayActive(nvmlDevice_t device, nvmlEnableState_t *isActive) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetDisplayActive");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetDisplayActive, handle_remap(device), isActive);
}
nvmlReturn_t nvmlDeviceGetDisplayMode(nvmlDevice_t device, nvmlEnableState_t *display) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetDisplayMode");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetDisplayMode, handle_remap(device), display);
}
nvmlReturn_t nvmlDeviceGetDriverModel(nvmlDevice_t device, nvmlDriverModel_t *current, nvmlDriverModel_t *pending) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetDriverModel");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetDriverModel, handle_remap(device), current, pending);
}
nvmlReturn_t nvmlDeviceGetEccMode(nvmlDevice_t device, nvmlEnableState_t *current, nvmlEnableState_t *pending) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetEccMode");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetEccMode, handle_remap(device), current, pending);
}
nvmlReturn_t nvmlDeviceGetEncoderCapacity(nvmlDevice_t device, nvmlEncoderType_t encoderQueryType, unsigned int *encoderCapacity) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetEncoderCapacity");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetEncoderCapacity, handle_remap(device), encoderQueryType, encoderCapacity);
}
nvmlReturn_t nvmlDeviceGetEncoderSessions(nvmlDevice_t device, unsigned int *sessionCount, nvmlEncoderSessionInfo_t *sessionInfos) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetEncoderSessions");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetEncoderSessions, handle_remap(device), sessionCount, sessionInfos);
}
nvmlReturn_t nvmlDeviceGetEncoderStats(nvmlDevice_t device, unsigned int *sessionCount, unsigned int *averageFps, unsigned int *averageLatency) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetEncoderStats");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetEncoderStats, handle_remap(device), sessionCount, averageFps, averageLatency);
}
nvmlReturn_t nvmlDeviceGetEncoderUtilization(nvmlDevice_t device, unsigned int *utilization, unsigned int *samplingPeriodUs) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetEncoderUtilization");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetEncoderUtilization, handle_remap(device), utilization, samplingPeriodUs);
}
nvmlReturn_t nvmlDeviceGetEnforcedPowerLimit(nvmlDevice_t device, unsigned int *limit) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetEnforcedPowerLimit");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetEnforcedPowerLimit, handle_remap(device), limit);
}
nvmlReturn_t nvmlDeviceGetFBCSessions(nvmlDevice_t device, unsigned int *sessionCount, nvmlFBCSessionInfo_t *sessionInfo) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetFBCSessions");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetFBCSessions, handle_remap(device), sessionCount, sessionInfo);
}
nvmlReturn_t nvmlDeviceGetFBCStats(nvmlDevice_t device, nvmlFBCStats_t *fbcStats) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetFBCStats");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetFBCStats, handle_remap(device), fbcStats);
}
nvmlReturn_t nvmlDeviceGetFanSpeed(nvmlDevice_t device, unsigned int *speed) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetFanSpeed");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetFanSpeed, handle_remap(device), speed);
}
nvmlReturn_t nvmlDeviceGetFanSpeed_v2(nvmlDevice_t device, unsigned int fan, unsigned int *speed) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetFanSpeed_v2");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetFanSpeed_v2, handle_remap(device), fan, speed);
}
nvmlReturn_t nvmlDeviceGetFieldValues(nvmlDevice_t device, int valuesCount, nvmlFieldValue_t *values) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetFieldValues");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetFieldValues, handle_remap(device), valuesCount, values);
}
nvmlReturn_t nvmlDeviceGetGpuInstanceById(nvmlDevice_t device, unsigned int id, nvmlGpuInstance_t *gpuInstance) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetGpuInstanceById");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetGpuInstanceById, handle_remap(device), id, gpuInstance);
}
nvmlReturn_t nvmlDeviceGetGpuInstanceId(nvmlDevice_t device, unsigned int *id) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetGpuInstanceId");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetGpuInstanceId, handle_remap(device), id);
}
nvmlReturn_t nvmlDeviceGetGpuInstancePossiblePlacements(nvmlDevice_t device, unsigned int profileId, nvmlGpuInstancePlacement_t *placements, unsigned int *count) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetGpuInstancePossiblePlacements");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetGpuInstancePossiblePlacements, handle_remap(device), profileId, placements, count);
}
nvmlReturn_t nvmlDeviceGetGpuInstancePossiblePlacements_v2(nvmlDevice_t device, unsigned int profileId, nvmlGpuInstancePlacement_t *placements, unsigned int *count) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetGpuInstancePossiblePlacements_v2");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetGpuInstancePossiblePlacements_v2, handle_remap(device), profileId, placements, count);
}
nvmlReturn_t nvmlDeviceGetGpuInstanceProfileInfo(nvmlDevice_t device, unsigned int profile, nvmlGpuInstanceProfileInfo_t *info) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetGpuInstanceProfileInfo");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetGpuInstanceProfileInfo, handle_remap(device), profile, info);
}
nvmlReturn_t nvmlDeviceGetGpuInstanceRemainingCapacity(nvmlDevice_t device, unsigned int profileId, unsigned int *count) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetGpuInstanceRemainingCapacity");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetGpuInstanceRemainingCapacity, handle_remap(device), profileId, count);
}
nvmlReturn_t nvmlDeviceGetGpuInstances(nvmlDevice_t device, unsigned int profileId, nvmlGpuInstance_t *gpuInstances, unsigned int *count) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetGpuInstances");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetGpuInstances, handle_remap(device), profileId, gpuInstances, count);
}
nvmlReturn_t nvmlDeviceGetGpuOperationMode(nvmlDevice_t device, nvmlGpuOperationMode_t *current, nvmlGpuOperationMode_t *pending) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetGpuOperationMode");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetGpuOperationMode, handle_remap(device), current, pending);
}
nvmlReturn_t nvmlDeviceGetGraphicsRunningProcesses(nvmlDevice_t device, unsigned int *infoCount, nvmlProcessInfo_v1_t *infos) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetGraphicsRunningProcesses");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetGraphicsRunningProcesses, handle_remap(device), infoCount, infos);
}
nvmlReturn_t nvmlDeviceGetGraphicsRunningProcesses_v2(nvmlDevice_t device, unsigned int *infoCount, nvmlProcessInfo_v2_t *infos) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetGraphicsRunningProcesses_v2");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetGraphicsRunningProcesses_v2, handle_remap(device), infoCount, infos);
}
nvmlReturn_t nvmlDeviceGetGridLicensableFeatures(nvmlDevice_t device, nvmlGridLicensableFeatures_t *pGridLicensableFeatures) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetGridLicensableFeatures");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetGridLicensableFeatures, handle_remap(device), pGridLicensableFeatures);
}
nvmlReturn_t nvmlDeviceGetGridLicensableFeatures_v2(nvmlDevice_t device, nvmlGridLicensableFeatures_t *pGridLicensableFeatures) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetGridLicensableFeatures_v2");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetGridLicensableFeatures_v2, handle_remap(device), pGridLicensableFeatures);
}
nvmlReturn_t nvmlDeviceGetGridLicensableFeatures_v3(nvmlDevice_t device, nvmlGridLicensableFeatures_t *pGridLicensableFeatures) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetGridLicensableFeatures_v3");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetGridLicensableFeatures_v3, handle_remap(device), pGridLicensableFeatures);
}
nvmlReturn_t nvmlDeviceGetGridLicensableFeatures_v4(nvmlDevice_t device, nvmlGridLicensableFeatures_t *pGridLicensableFeatures) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetGridLicensableFeatures_v4");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetGridLicensableFeatures_v4, handle_remap(device), pGridLicensableFeatures);
}
nvmlReturn_t nvmlDeviceGetHostVgpuMode(nvmlDevice_t device, nvmlHostVgpuMode_t *pHostVgpuMode) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetHostVgpuMode");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetHostVgpuMode, handle_remap(device), pHostVgpuMode);
}
nvmlReturn_t nvmlDeviceGetIndex(nvmlDevice_t device, unsigned int *index) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetIndex");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetIndex, handle_remap(device), index);
}
nvmlReturn_t nvmlDeviceGetInforomConfigurationChecksum(nvmlDevice_t device, unsigned int *checksum) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetInforomConfigurationChecksum");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetInforomConfigurationChecksum, handle_remap(device), checksum);
}
nvmlReturn_t nvmlDeviceGetInforomImageVersion(nvmlDevice_t device, char *version, unsigned int length) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetInforomImageVersion");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetInforomImageVersion, handle_remap(device), version, length);
}
nvmlReturn_t nvmlDeviceGetInforomVersion(nvmlDevice_t device, nvmlInforomObject_t object, char *version, unsigned int length) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetInforomVersion");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetInforomVersion, handle_remap(device), object, version, length);
}
nvmlReturn_t nvmlDeviceGetIrqNum(nvmlDevice_t device, unsigned int *irqNum) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetIrqNum");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetIrqNum, handle_remap(device), irqNum);
}
nvmlReturn_t nvmlDeviceGetMPSComputeRunningProcesses(nvmlDevice_t device, unsigned int *infoCount, nvmlProcessInfo_v1_t *infos) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetMPSComputeRunningProcesses");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMPSComputeRunningProcesses, handle_remap(device), infoCount, infos);
}
nvmlReturn_t nvmlDeviceGetMPSComputeRunningProcesses_v2(nvmlDevice_t device, unsigned int *infoCount, nvmlProcessInfo_v2_t *infos) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetMPSComputeRunningProcesses_v2");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMPSComputeRunningProcesses_v2, handle_remap(device), infoCount, infos);
}
nvmlReturn_t nvmlDeviceGetMaxClockInfo(nvmlDevice_t device, nvmlClockType_t type, unsigned int *clock) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetMaxClockInfo");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMaxClockInfo, handle_remap(device), type, clock);
}
nvmlReturn_t nvmlDeviceGetMaxCustomerBoostClock(nvmlDevice_t device, nvmlClockType_t clockType, unsigned int *clockMHz) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetMaxCustomerBoostClock");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMaxCustomerBoostClock, handle_remap(device), clockType, clockMHz);
}
nvmlReturn_t nvmlDeviceGetMaxMigDeviceCount(nvmlDevice_t device, unsigned int *count) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetMaxMigDeviceCount");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMaxMigDeviceCount, handle_remap(device), count);
}
nvmlReturn_t nvmlDeviceGetMaxPcieLinkGeneration(nvmlDevice_t device, unsigned int *maxLinkGen) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetMaxPcieLinkGeneration");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMaxPcieLinkGeneration, handle_remap(device), maxLinkGen);
}
nvmlReturn_t nvmlDeviceGetMaxPcieLinkWidth(nvmlDevice_t device, unsigned int *maxLinkWidth) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetMaxPcieLinkWidth");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMaxPcieLinkWidth, handle_remap(device), maxLinkWidth);
}
nvmlReturn_t nvmlDeviceGetMemoryAffinity(nvmlDevice_t device, unsigned int nodeSetSize, unsigned long *nodeSet, nvmlAffinityScope_t scope) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetMemoryAffinity");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMemoryAffinity, handle_remap(device), nodeSetSize, nodeSet, scope);
}
nvmlReturn_t nvmlDeviceGetMemoryErrorCounter(nvmlDevice_t device, nvmlMemoryErrorType_t errorType, nvmlEccCounterType_t counterType, nvmlMemoryLocation_t locationType, unsigned long long *count) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetMemoryErrorCounter");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMemoryErrorCounter, handle_remap(device), errorType, counterType, locationType, count);
}
nvmlReturn_t nvmlDeviceGetMemoryInfo(nvmlDevice_t device, nvmlMemory_t *memory) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetMemoryInfo");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMemoryInfo, handle_remap(device), memory);
}
nvmlReturn_t nvmlDeviceGetMemoryInfo_v2(nvmlDevice_t device, nvmlMemory_v2_t *memory) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetMemoryInfo_v2");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMemoryInfo_v2, handle_remap(device), memory);
}
nvmlReturn_t nvmlDeviceGetMigDeviceHandleByIndex(nvmlDevice_t device, unsigned int index, nvmlDevice_t *migDevice) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetMigDeviceHandleByIndex");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMigDeviceHandleByIndex, handle_remap(device), index, migDevice);
}
nvmlReturn_t nvmlDeviceGetMigMode(nvmlDevice_t device, unsigned int *currentMode, unsigned int *pendingMode) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetMigMode");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMigMode, handle_remap(device), currentMode, pendingMode);
}
nvmlReturn_t nvmlDeviceGetMinorNumber(nvmlDevice_t device, unsigned int *minorNumber) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetMinorNumber");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMinorNumber, handle_remap(device), minorNumber);
}
nvmlReturn_t nvmlDeviceGetMultiGpuBoard(nvmlDevice_t device, unsigned int *multiGpuBool) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetMultiGpuBoard");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMultiGpuBoard, handle_remap(device), multiGpuBool);
}
nvmlReturn_t nvmlDeviceGetName(nvmlDevice_t device, char *name, unsigned int length) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetName");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetName, handle_remap(device), name, length);
}
nvmlReturn_t nvmlDeviceGetNvLinkCapability(nvmlDevice_t device, unsigned int link, nvmlNvLinkCapability_t capability, unsigned int *capResult) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetNvLinkCapability");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetNvLinkCapability, handle_remap(device), link, capability, capResult);
}
nvmlReturn_t nvmlDeviceGetNvLinkErrorCounter(nvmlDevice_t device, unsigned int link, nvmlNvLinkErrorCounter_t counter, unsigned long long *counterValue) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetNvLinkErrorCounter");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetNvLinkErrorCounter, handle_remap(device), link, counter, counterValue);
}
nvmlReturn_t nvmlDeviceGetNvLinkRemoteDeviceType(nvmlDevice_t device, unsigned int link, nvmlIntNvLinkDeviceType_t *pNvLinkDeviceType) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetNvLinkRemoteDeviceType");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetNvLinkRemoteDeviceType, handle_remap(device), link, pNvLinkDeviceType);
}
nvmlReturn_t nvmlDeviceGetNvLinkRemotePciInfo(nvmlDevice_t device, unsigned int link, nvmlPciInfo_t *pci) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetNvLinkRemotePciInfo");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetNvLinkRemotePciInfo, handle_remap(device), link, pci);
}
nvmlReturn_t nvmlDeviceGetNvLinkRemotePciInfo_v2(nvmlDevice_t device, unsigned int link, nvmlPciInfo_t *pci) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetNvLinkRemotePciInfo_v2");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetNvLinkRemotePciInfo_v2, handle_remap(device), link, pci);
}
nvmlReturn_t nvmlDeviceGetNvLinkState(nvmlDevice_t device, unsigned int link, nvmlEnableState_t *isActive) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetNvLinkState");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetNvLinkState, handle_remap(device), link, isActive);
}
nvmlReturn_t nvmlDeviceGetNvLinkUtilizationControl(nvmlDevice_t device, unsigned int link, unsigned int counter, nvmlNvLinkUtilizationControl_t *control) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetNvLinkUtilizationControl");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetNvLinkUtilizationControl, handle_remap(device), link, counter, control);
}
nvmlReturn_t nvmlDeviceGetNvLinkUtilizationCounter(nvmlDevice_t device, unsigned int link, unsigned int counter, unsigned long long *rxcounter, unsigned long long *txcounter) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetNvLinkUtilizationCounter");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetNvLinkUtilizationCounter, handle_remap(device), link, counter, rxcounter, txcounter);
}
nvmlReturn_t nvmlDeviceGetNvLinkVersion(nvmlDevice_t device, unsigned int link, unsigned int *version) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetNvLinkVersion");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetNvLinkVersion, handle_remap(device), link, version);
}

nvmlReturn_t nvmlDeviceGetPcieReplayCounter(nvmlDevice_t device, unsigned int *value) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetPcieReplayCounter");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPcieReplayCounter, handle_remap(device), value);
}
nvmlReturn_t nvmlDeviceGetPcieThroughput(nvmlDevice_t device, nvmlPcieUtilCounter_t counter, unsigned int *value) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetPcieThroughput");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPcieThroughput, handle_remap(device), counter, value);
}
nvmlReturn_t nvmlDeviceGetPerformanceState(nvmlDevice_t device, nvmlPstates_t *pState) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetPerformanceState");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPerformanceState, handle_remap(device), pState);
}
nvmlReturn_t nvmlDeviceGetPersistenceMode(nvmlDevice_t device, nvmlEnableState_t *mode) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetPersistenceMode");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPersistenceMode, handle_remap(device), mode);
}
nvmlReturn_t nvmlDeviceGetPgpuMetadataString(nvmlDevice_t device, char *pgpuMetadata, unsigned int *bufferSize) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetPgpuMetadataString");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPgpuMetadataString, handle_remap(device), pgpuMetadata, bufferSize);
}
nvmlReturn_t nvmlDeviceGetPowerManagementDefaultLimit(nvmlDevice_t device, unsigned int *defaultLimit) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetPowerManagementDefaultLimit");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPowerManagementDefaultLimit, handle_remap(device), defaultLimit);
}
nvmlReturn_t nvmlDeviceGetPowerManagementLimit(nvmlDevice_t device, unsigned int *limit) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetPowerManagementLimit");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPowerManagementLimit, handle_remap(device), limit);
}
nvmlReturn_t nvmlDeviceGetPowerManagementLimitConstraints(nvmlDevice_t device, unsigned int *minLimit, unsigned int *maxLimit) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetPowerManagementLimitConstraints");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPowerManagementLimitConstraints, handle_remap(device), minLimit, maxLimit);
}
nvmlReturn_t nvmlDeviceGetPowerManagementMode(nvmlDevice_t device, nvmlEnableState_t *mode) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetPowerManagementMode");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPowerManagementMode, handle_remap(device), mode);
}
nvmlReturn_t nvmlDeviceGetPowerState(nvmlDevice_t device, nvmlPstates_t *pState) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetPowerState");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPowerState, handle_remap(device), pState);
}
nvmlReturn_t nvmlDeviceGetPowerUsage(nvmlDevice_t device, unsigned int *power) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetPowerUsage");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPowerUsage, handle_remap(device), power);
}
nvmlReturn_t nvmlDeviceGetRemappedRows(nvmlDevice_t device, unsigned int *corrRows, unsigned int *uncRows, unsigned int *isPending, unsigned int *failureOccurred) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetRemappedRows");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetRemappedRows, handle_remap(device), corrRows, uncRows, isPending, failureOccurred);
}
nvmlReturn_t nvmlDeviceGetRetiredPages(nvmlDevice_t device, nvmlPageRetirementCause_t cause, unsigned int *pageCount, unsigned long long *addresses) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetRetiredPages");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetRetiredPages, handle_remap(device), cause, pageCount, addresses);
}
nvmlReturn_t nvmlDeviceGetRetiredPagesPendingStatus(nvmlDevice_t device, nvmlEnableState_t *isPending) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetRetiredPagesPendingStatus");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetRetiredPagesPendingStatus, handle_remap(device), isPending);
}
nvmlReturn_t nvmlDeviceGetRetiredPages_v2(nvmlDevice_t device, nvmlPageRetirementCause_t cause, unsigned int *pageCount, unsigned long long *addresses, unsigned long long *timestamps) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetRetiredPages_v2");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetRetiredPages_v2, handle_remap(device), cause, pageCount, addresses, timestamps);
}
nvmlReturn_t nvmlDeviceGetRowRemapperHistogram(nvmlDevice_t device, nvmlRowRemapperHistogramValues_t *values) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetRowRemapperHistogram");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetRowRemapperHistogram, handle_remap(device), values);
}
nvmlReturn_t nvmlDeviceGetSamples(nvmlDevice_t device, nvmlSamplingType_t type, unsigned long long lastSeenTimeStamp, nvmlValueType_t *sampleValType, unsigned int *sampleCount, nvmlSample_t *samples) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetSamples");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetSamples, handle_remap(device), type, lastSeenTimeStamp, sampleValType, sampleCount, samples);
}
nvmlReturn_t nvmlDeviceGetSerial(nvmlDevice_t device, char *serial, unsigned int length) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetSerial");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetSerial, handle_remap(device), serial, length);
}
nvmlReturn_t nvmlDeviceGetSupportedClocksThrottleReasons(nvmlDevice_t device, unsigned long long *supportedClocksThrottleReasons) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetSupportedClocksThrottleReasons");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetSupportedClocksThrottleReasons, handle_remap(device), supportedClocksThrottleReasons);
}
nvmlReturn_t nvmlDeviceGetSupportedEventTypes(nvmlDevice_t device, unsigned long long *eventTypes) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetSupportedEventTypes");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetSupportedEventTypes, handle_remap(device), eventTypes);
}
nvmlReturn_t nvmlDeviceGetSupportedGraphicsClocks(nvmlDevice_t device, unsigned int memoryClockMHz, unsigned int *count, unsigned int *clocksMHz) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetSupportedGraphicsClocks");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetSupportedGraphicsClocks, handle_remap(device), memoryClockMHz, count, clocksMHz);
}
nvmlReturn_t nvmlDeviceGetSupportedMemoryClocks(nvmlDevice_t device, unsigned int *count, unsigned int *clocksMHz) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetSupportedMemoryClocks");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetSupportedMemoryClocks, handle_remap(device), count, clocksMHz);
}
nvmlReturn_t nvmlDeviceGetSupportedVgpus(nvmlDevice_t device, unsigned int *vgpuCount, nvmlVgpuTypeId_t *vgpuTypeIds) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetSupportedVgpus");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetSupportedVgpus, handle_remap(device), vgpuCount, vgpuTypeIds);
}
nvmlReturn_t nvmlDeviceGetTemperature(nvmlDevice_t device, nvmlTemperatureSensors_t sensorType, unsigned int *temp) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetTemperature");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetTemperature, handle_remap(device), sensorType, temp);
}
nvmlReturn_t nvmlDeviceGetTemperatureThreshold(nvmlDevice_t device, nvmlTemperatureThresholds_t thresholdType, unsigned int *temp) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetTemperatureThreshold");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetTemperatureThreshold, handle_remap(device), thresholdType, temp);
}
nvmlReturn_t nvmlDeviceGetTopologyNearestGpus(nvmlDevice_t device, nvmlGpuTopologyLevel_t level, unsigned int *count, nvmlDevice_t *deviceArray) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetTopologyNearestGpus");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetTopologyNearestGpus, handle_remap(device), level, count, deviceArray);
}
nvmlReturn_t nvmlDeviceGetTotalEccErrors(nvmlDevice_t device, nvmlMemoryErrorType_t errorType, nvmlEccCounterType_t counterType, unsigned long long *eccCounts) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetTotalEccErrors");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetTotalEccErrors, handle_remap(device), errorType, counterType, eccCounts);
}
nvmlReturn_t nvmlDeviceGetTotalEnergyConsumption(nvmlDevice_t device, unsigned long long *energy) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetTotalEnergyConsumption");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetTotalEnergyConsumption, handle_remap(device), energy);
}
nvmlReturn_t nvmlDeviceGetUtilizationRates(nvmlDevice_t device, nvmlUtilization_t *utilization) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetUtilizationRates");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetUtilizationRates, handle_remap(device), utilization);
}
nvmlReturn_t nvmlDeviceGetVbiosVersion(nvmlDevice_t device, char *version, unsigned int length) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetVbiosVersion");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetVbiosVersion, handle_remap(device), version, length);
}
nvmlReturn_t nvmlDeviceGetVgpuMetadata(nvmlDevice_t device, nvmlVgpuPgpuMetadata_t *pgpuMetadata, unsigned int *bufferSize) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetVgpuMetadata");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetVgpuMetadata, handle_remap(device), pgpuMetadata, bufferSize);
}
nvmlReturn_t nvmlDeviceGetVgpuProcessUtilization(nvmlDevice_t device, unsigned long long lastSeenTimeStamp, unsigned int *vgpuProcessSamplesCount, nvmlVgpuProcessUtilizationSample_t *utilizationSamples) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetVgpuProcessUtilization");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetVgpuProcessUtilization, handle_remap(device), lastSeenTimeStamp, vgpuProcessSamplesCount, utilizationSamples);
}
nvmlReturn_t nvmlDeviceGetVgpuUtilization(nvmlDevice_t device, unsigned long long lastSeenTimeStamp, nvmlValueType_t *sampleValType, unsigned int *vgpuInstanceSamplesCount, nvmlVgpuInstanceUtilizationSample_t *utilizationSamples) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetVgpuUtilization");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetVgpuUtilization, handle_remap(device), lastSeenTimeStamp, sampleValType, vgpuInstanceSamplesCount, utilizationSamples);
}
nvmlReturn_t nvmlDeviceGetViolationStatus(nvmlDevice_t device, nvmlPerfPolicyType_t perfPolicyType, nvmlViolationTime_t *violTime) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetViolationStatus");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetViolationStatus, handle_remap(device), perfPolicyType, violTime);
}
nvmlReturn_t nvmlDeviceGetVirtualizationMode(nvmlDevice_t device, nvmlGpuVirtualizationMode_t *pVirtualMode) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetVirtualizationMode");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetVirtualizationMode, handle_remap(device), pVirtualMode);
}
nvmlReturn_t nvmlDeviceIsMigDeviceHandle(nvmlDevice_t device, unsigned int *isMigDevice) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceIsMigDeviceHandle");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceIsMigDeviceHandle, handle_remap(device), isMigDevice);
}
nvmlReturn_t nvmlDeviceRegisterEvents(nvmlDevice_t device, unsigned long long eventTypes, nvmlEventSet_t set) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceRegisterEvents");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceRegisterEvents, handle_remap(device), eventTypes, set);
}
nvmlReturn_t nvmlDeviceResetNvLinkErrorCounters(nvmlDevice_t device, unsigned int link) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceResetNvLinkErrorCounters");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceResetNvLinkErrorCounters, handle_remap(device), link);
}
nvmlReturn_t nvmlDeviceResetNvLinkUtilizationCounter(nvmlDevice_t device, unsigned int link, unsigned int counter) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceResetNvLinkUtilizationCounter");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceResetNvLinkUtilizationCounter, handle_remap(device), link, counter);
}
nvmlReturn_t nvmlDeviceSetAPIRestriction(nvmlDevice_t device, nvmlRestrictedAPI_t apiType, nvmlEnableState_t isRestricted) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceSetAPIRestriction");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetAPIRestriction, handle_remap(device), apiType, isRestricted);
}
nvmlReturn_t nvmlDeviceSetAccountingMode(nvmlDevice_t device, nvmlEnableState_t mode) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceSetAccountingMode");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetAccountingMode, handle_remap(device), mode);
}
nvmlReturn_t nvmlDeviceSetApplicationsClocks(nvmlDevice_t device, unsigned int memClockMHz, unsigned int graphicsClockMHz) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceSetApplicationsClocks");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetApplicationsClocks, handle_remap(device), memClockMHz, graphicsClockMHz);
}
nvmlReturn_t nvmlDeviceSetAutoBoostedClocksEnabled(nvmlDevice_t device, nvmlEnableState_t enabled) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceSetAutoBoostedClocksEnabled");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetAutoBoostedClocksEnabled, handle_remap(device), enabled);
}
nvmlReturn_t nvmlDeviceSetComputeMode(nvmlDevice_t device, nvmlComputeMode_t mode) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceSetComputeMode");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetComputeMode, handle_remap(device), mode);
}
nvmlReturn_t nvmlDeviceSetDefaultAutoBoostedClocksEnabled(nvmlDevice_t device, nvmlEnableState_t enabled, unsigned int flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceSetDefaultAutoBoostedClocksEnabled");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetDefaultAutoBoostedClocksEnabled, handle_remap(device), enabled, flags);
}
nvmlReturn_t nvmlDeviceSetDriverModel(nvmlDevice_t device, nvmlDriverModel_t driverModel, unsigned int flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceSetDriverModel");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetDriverModel, handle_remap(device), driverModel, flags);
}
nvmlReturn_t nvmlDeviceSetEccMode(nvmlDevice_t device, nvmlEnableState_t ecc) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceSetEccMode");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetEccMode, handle_remap(device), ecc);
}
nvmlReturn_t nvmlDeviceSetGpuLockedClocks(nvmlDevice_t device, unsigned int minGpuClockMHz, unsigned int maxGpuClockMHz) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceSetGpuLockedClocks");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetGpuLockedClocks, handle_remap(device), minGpuClockMHz, maxGpuClockMHz);
}
nvmlReturn_t nvmlDeviceSetGpuOperationMode(nvmlDevice_t device, nvmlGpuOperationMode_t mode) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceSetGpuOperationMode");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetGpuOperationMode, handle_remap(device), mode);
}
nvmlReturn_t nvmlDeviceSetMemoryLockedClocks(nvmlDevice_t device, unsigned int minMemClockMHz, unsigned int maxMemClockMHz) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceSetMemoryLockedClocks");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetMemoryLockedClocks, handle_remap(device), minMemClockMHz, maxMemClockMHz);
}
nvmlReturn_t nvmlDeviceSetMigMode(nvmlDevice_t device, unsigned int mode, nvmlReturn_t *activationStatus) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceSetMigMode");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetMigMode, handle_remap(device), mode, activationStatus);
}
nvmlReturn_t nvmlDeviceSetNvLinkUtilizationControl(nvmlDevice_t device, unsigned int link, unsigned int counter, nvmlNvLinkUtilizationControl_t *control, unsigned int reset) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceSetNvLinkUtilizationControl");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetNvLinkUtilizationControl, handle_remap(device), link, counter, control, reset);
}
nvmlReturn_t nvmlDeviceSetPersistenceMode(nvmlDevice_t device, nvmlEnableState_t mode) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceSetPersistenceMode");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetPersistenceMode, handle_remap(device), mode);
}
nvmlReturn_t nvmlDeviceSetPowerManagementLimit(nvmlDevice_t device, unsigned int limit) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceSetPowerManagementLimit");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetPowerManagementLimit, handle_remap(device), limit);
}
nvmlReturn_t nvmlDeviceSetTemperatureThreshold(nvmlDevice_t device, nvmlTemperatureThresholds_t thresholdType, int *temp) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceSetTemperatureThreshold");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetTemperatureThreshold, handle_remap(device), thresholdType, temp);
}
nvmlReturn_t nvmlDeviceSetVirtualizationMode(nvmlDevice_t device, nvmlGpuVirtualizationMode_t virtualMode) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceSetVirtualizationMode");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetVirtualizationMode, handle_remap(device), virtualMode);
}
nvmlReturn_t nvmlVgpuTypeGetMaxInstances(nvmlDevice_t device, nvmlVgpuTypeId_t vgpuTypeId, unsigned int *vgpuInstanceCount) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlVgpuTypeGetMaxInstances");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuTypeGetMaxInstances, handle_remap(device), vgpuTypeId, vgpuInstanceCount);
}

nvmlReturn_t nvmlDeviceGetProcessUtilization(nvmlDevice_t device, nvmlProcessUtilizationSample_t *utilization, unsigned int *processSamplesCount, unsigned long long lastSeenTimeStamp) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetProcessUtilization");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetProcessUtilization, handle_remap(device), utilization, processSamplesCount, lastSeenTimeStamp);
}