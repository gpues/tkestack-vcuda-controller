#include "include/all.h"
extern void *nvml_library_entry[1024];

nvmlReturn_t nvmlComputeInstanceDestroy(nvmlComputeInstance_t computeInstance) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlComputeInstanceDestroy");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlComputeInstanceDestroy, computeInstance);
}
nvmlReturn_t nvmlComputeInstanceGetInfo(nvmlComputeInstance_t computeInstance, nvmlComputeInstanceInfo_t *info) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlComputeInstanceGetInfo");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlComputeInstanceGetInfo, computeInstance, info);
}
nvmlReturn_t nvmlComputeInstanceGetInfo_v2(nvmlComputeInstance_t computeInstance, nvmlComputeInstanceInfo_t *info) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlComputeInstanceGetInfo_v2");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlComputeInstanceGetInfo_v2, computeInstance, info);
}
nvmlReturn_t nvmlDeviceClearEccErrorCounts(nvmlDevice_t device, nvmlEccCounterType_t counterType) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceClearEccErrorCounts");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceClearEccErrorCounts, device, counterType);
}
nvmlReturn_t nvmlDeviceDiscoverGpus(nvmlPciInfo_t *pciInfo) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceDiscoverGpus");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceDiscoverGpus, pciInfo);
}
nvmlReturn_t nvmlDeviceGetCount(unsigned int *deviceCount) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetCount");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetCount, deviceCount);
}
nvmlReturn_t nvmlDeviceGetCount_v2(unsigned int *deviceCount) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetCount_v2");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetCount_v2, deviceCount);
}
nvmlReturn_t nvmlDeviceGetHandleByIndex_v2(unsigned int index, nvmlDevice_t *device) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetHandleByIndex_v2");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetHandleByIndex_v2, index, device);
}
nvmlReturn_t nvmlDeviceGetHandleByPciBusId(const char *pciBusId, nvmlDevice_t *device) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetHandleByPciBusId");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetHandleByPciBusId, pciBusId, device);
}
nvmlReturn_t nvmlDeviceGetHandleBySerial(const char *serial, nvmlDevice_t *device) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetHandleBySerial");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetHandleBySerial, serial, device);
}
nvmlReturn_t nvmlDeviceGetHandleByUUID(const char *uuid, nvmlDevice_t *device) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetHandleByUUID");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetHandleByUUID, uuid, device);
}
nvmlReturn_t nvmlDeviceGetP2PStatus(nvmlDevice_t device1, nvmlDevice_t device2, nvmlGpuP2PCapsIndex_t p2pIndex, nvmlGpuP2PStatus_t *p2pStatus) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetP2PStatus");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetP2PStatus, device1, device2, p2pIndex, p2pStatus);
}
nvmlReturn_t nvmlDeviceGetTopologyCommonAncestor(nvmlDevice_t device1, nvmlDevice_t device2, nvmlGpuTopologyLevel_t *pathInfo) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceGetTopologyCommonAncestor");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetTopologyCommonAncestor, device1, device2, pathInfo);
}
nvmlReturn_t nvmlDeviceModifyDrainState(nvmlPciInfo_t *pciInfo, nvmlEnableState_t newState) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceModifyDrainState");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceModifyDrainState, pciInfo, newState);
}
nvmlReturn_t nvmlDeviceOnSameBoard(nvmlDevice_t device1, nvmlDevice_t device2, int *onSameBoard) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceOnSameBoard");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceOnSameBoard, device1, device2, onSameBoard);
}
nvmlReturn_t nvmlDeviceQueryDrainState(nvmlPciInfo_t *pciInfo, nvmlEnableState_t *currentState) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceQueryDrainState");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceQueryDrainState, pciInfo, currentState);
}
nvmlReturn_t nvmlDeviceRemoveGpu(nvmlPciInfo_t *pciInfo) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceRemoveGpu");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceRemoveGpu, pciInfo);
}
nvmlReturn_t nvmlDeviceRemoveGpu_v2(nvmlPciInfo_t *pciInfo, nvmlDetachGpuState_t gpuState, nvmlPcieLinkState_t linkState) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceRemoveGpu_v2");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceRemoveGpu_v2, pciInfo, gpuState, linkState);
}
nvmlReturn_t nvmlDeviceResetApplicationsClocks(nvmlDevice_t device) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceResetApplicationsClocks");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceResetApplicationsClocks, device);
}
nvmlReturn_t nvmlDeviceResetGpuLockedClocks(nvmlDevice_t device) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceResetGpuLockedClocks");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceResetGpuLockedClocks, device);
}
nvmlReturn_t nvmlDeviceResetMemoryLockedClocks(nvmlDevice_t device) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceResetMemoryLockedClocks");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceResetMemoryLockedClocks, device);
}
nvmlReturn_t nvmlDeviceSetCpuAffinity(nvmlDevice_t device) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceSetCpuAffinity");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetCpuAffinity, device);
}
nvmlReturn_t nvmlDeviceValidateInforom(nvmlDevice_t device) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlDeviceValidateInforom");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceValidateInforom, device);
}
nvmlReturn_t nvmlEventSetCreate(nvmlEventSet_t *set) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlEventSetCreate");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlEventSetCreate, set);
}
nvmlReturn_t nvmlEventSetFree(nvmlEventSet_t set) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlEventSetFree");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlEventSetFree, set);
}
nvmlReturn_t nvmlEventSetWait(nvmlEventSet_t set, nvmlEventData_t *data, unsigned int timeoutms) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlEventSetWait");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlEventSetWait, set, data, timeoutms);
}
nvmlReturn_t nvmlEventSetWait_v2(nvmlEventSet_t set, nvmlEventData_t *data, unsigned int timeoutms) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlEventSetWait_v2");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlEventSetWait_v2, set, data, timeoutms);
}
nvmlReturn_t nvmlGetBlacklistDeviceCount(unsigned int *deviceCount) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlGetBlacklistDeviceCount");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlGetBlacklistDeviceCount, deviceCount);
}
nvmlReturn_t nvmlGetBlacklistDeviceInfoByIndex(unsigned int index, nvmlBlacklistDeviceInfo_t *info) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlGetBlacklistDeviceInfoByIndex");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlGetBlacklistDeviceInfoByIndex, index, info);
}
nvmlReturn_t nvmlGetExcludedDeviceCount(unsigned int *deviceCount) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlGetExcludedDeviceCount");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlGetExcludedDeviceCount, deviceCount);
}
nvmlReturn_t nvmlGetExcludedDeviceInfoByIndex(unsigned int index, nvmlExcludedDeviceInfo_t *info) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlGetExcludedDeviceInfoByIndex");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlGetExcludedDeviceInfoByIndex, index, info);
}
nvmlReturn_t nvmlGetVgpuCompatibility(nvmlVgpuMetadata_t *vgpuMetadata, nvmlVgpuPgpuMetadata_t *pgpuMetadata, nvmlVgpuPgpuCompatibility_t *compatibilityInfo) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlGetVgpuCompatibility");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlGetVgpuCompatibility, vgpuMetadata, pgpuMetadata, compatibilityInfo);
}
nvmlReturn_t nvmlGetVgpuVersion(nvmlVgpuVersion_t *supported, nvmlVgpuVersion_t *current) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlGetVgpuVersion");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlGetVgpuVersion, supported, current);
}
nvmlReturn_t nvmlGpuInstanceCreateComputeInstance(nvmlGpuInstance_t gpuInstance, unsigned int profileId, nvmlComputeInstance_t *computeInstance) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlGpuInstanceCreateComputeInstance");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlGpuInstanceCreateComputeInstance, gpuInstance, profileId, computeInstance);
}
nvmlReturn_t nvmlGpuInstanceDestroy(nvmlGpuInstance_t gpuInstance) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlGpuInstanceDestroy");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlGpuInstanceDestroy, gpuInstance);
}
nvmlReturn_t nvmlGpuInstanceGetComputeInstanceById(nvmlGpuInstance_t gpuInstance, unsigned int id, nvmlComputeInstance_t *computeInstance) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlGpuInstanceGetComputeInstanceById");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlGpuInstanceGetComputeInstanceById, gpuInstance, id, computeInstance);
}
nvmlReturn_t nvmlGpuInstanceGetComputeInstanceProfileInfo(nvmlGpuInstance_t gpuInstance, unsigned int profile, unsigned int engProfile, nvmlComputeInstanceProfileInfo_t *info) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlGpuInstanceGetComputeInstanceProfileInfo");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlGpuInstanceGetComputeInstanceProfileInfo, gpuInstance, profile, engProfile, info);
}
nvmlReturn_t nvmlGpuInstanceGetComputeInstanceRemainingCapacity(nvmlGpuInstance_t gpuInstance, unsigned int profileId, unsigned int *count) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlGpuInstanceGetComputeInstanceRemainingCapacity");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlGpuInstanceGetComputeInstanceRemainingCapacity, gpuInstance, profileId, count);
}
nvmlReturn_t nvmlGpuInstanceGetComputeInstances(nvmlGpuInstance_t gpuInstance, unsigned int profileId, nvmlComputeInstance_t *computeInstances, unsigned int *count) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlGpuInstanceGetComputeInstances");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlGpuInstanceGetComputeInstances, gpuInstance, profileId, computeInstances, count);
}
nvmlReturn_t nvmlGpuInstanceGetInfo(nvmlGpuInstance_t gpuInstance, nvmlGpuInstanceInfo_t *info) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlGpuInstanceGetInfo");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlGpuInstanceGetInfo, gpuInstance, info);
}
nvmlReturn_t nvmlInternalGetExportTable(const void **ppExportTable, void *pExportTableId) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlInternalGetExportTable");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlInternalGetExportTable, ppExportTable, pExportTableId);
}
nvmlReturn_t nvmlSetVgpuVersion(nvmlVgpuVersion_t *vgpuVersion) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlSetVgpuVersion");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlSetVgpuVersion, vgpuVersion);
}
nvmlReturn_t nvmlShutdown() {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlShutdown");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlShutdown, );
}
nvmlReturn_t nvmlSystemGetCudaDriverVersion(int *cudaDriverVersion) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlSystemGetCudaDriverVersion");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlSystemGetCudaDriverVersion, cudaDriverVersion);
}
nvmlReturn_t nvmlSystemGetCudaDriverVersion_v2(int *cudaDriverVersion) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlSystemGetCudaDriverVersion_v2");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlSystemGetCudaDriverVersion_v2, cudaDriverVersion);
}
nvmlReturn_t nvmlSystemGetDriverVersion(char *version, unsigned int length) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlSystemGetDriverVersion");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlSystemGetDriverVersion, version, length);
}
nvmlReturn_t nvmlSystemGetHicVersion(unsigned int *hwbcCount, nvmlHwbcEntry_t *hwbcEntries) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlSystemGetHicVersion");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlSystemGetHicVersion, hwbcCount, hwbcEntries);
}
nvmlReturn_t nvmlSystemGetNVMLVersion(char *version, unsigned int length) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlSystemGetNVMLVersion");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlSystemGetNVMLVersion, version, length);
}
nvmlReturn_t nvmlSystemGetProcessName(unsigned int pid, char *name, unsigned int length) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlSystemGetProcessName");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlSystemGetProcessName, pid, name, length);
}
nvmlReturn_t nvmlSystemGetTopologyGpuSet(unsigned int cpuNumber, unsigned int *count, nvmlDevice_t *deviceArray) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlSystemGetTopologyGpuSet");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlSystemGetTopologyGpuSet, cpuNumber, count, deviceArray);
}
nvmlReturn_t nvmlUnitGetCount(unsigned int *unitCount) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlUnitGetCount");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlUnitGetCount, unitCount);
}
nvmlReturn_t nvmlUnitGetDevices(nvmlUnit_t unit, unsigned int *deviceCount, nvmlDevice_t *devices) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlUnitGetDevices");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlUnitGetDevices, unit, deviceCount, devices);
}
nvmlReturn_t nvmlUnitGetFanSpeedInfo(nvmlUnit_t unit, nvmlUnitFanSpeeds_t *fanSpeeds) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlUnitGetFanSpeedInfo");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlUnitGetFanSpeedInfo, unit, fanSpeeds);
}
nvmlReturn_t nvmlUnitGetHandleByIndex(unsigned int index, nvmlUnit_t *unit) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlUnitGetHandleByIndex");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlUnitGetHandleByIndex, index, unit);
}
nvmlReturn_t nvmlUnitGetLedState(nvmlUnit_t unit, nvmlLedState_t *state) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlUnitGetLedState");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlUnitGetLedState, unit, state);
}
nvmlReturn_t nvmlUnitGetPsuInfo(nvmlUnit_t unit, nvmlPSUInfo_t *psu) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlUnitGetPsuInfo");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlUnitGetPsuInfo, unit, psu);
}
nvmlReturn_t nvmlUnitGetTemperature(nvmlUnit_t unit, unsigned int type, unsigned int *temp) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlUnitGetTemperature");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlUnitGetTemperature, unit, type, temp);
}
nvmlReturn_t nvmlUnitGetUnitInfo(nvmlUnit_t unit, nvmlUnitInfo_t *info) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlUnitGetUnitInfo");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlUnitGetUnitInfo, unit, info);
}
nvmlReturn_t nvmlUnitSetLedState(nvmlUnit_t unit, nvmlLedColor_t color) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlUnitSetLedState");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlUnitSetLedState, unit, color);
}
nvmlReturn_t nvmlVgpuInstanceClearAccountingPids(nvmlVgpuInstance_t vgpuInstance) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlVgpuInstanceClearAccountingPids");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceClearAccountingPids, vgpuInstance);
}
nvmlReturn_t nvmlVgpuInstanceGetAccountingMode(nvmlVgpuInstance_t vgpuInstance, nvmlEnableState_t *mode) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlVgpuInstanceGetAccountingMode");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetAccountingMode, vgpuInstance, mode);
}
nvmlReturn_t nvmlVgpuInstanceGetAccountingPids(nvmlVgpuInstance_t vgpuInstance, unsigned int *count, unsigned int *pids) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlVgpuInstanceGetAccountingPids");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetAccountingPids, vgpuInstance, count, pids);
}
nvmlReturn_t nvmlVgpuInstanceGetAccountingStats(nvmlVgpuInstance_t vgpuInstance, unsigned int pid, nvmlAccountingStats_t *stats) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlVgpuInstanceGetAccountingStats");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetAccountingStats, vgpuInstance, pid, stats);
}
nvmlReturn_t nvmlVgpuInstanceGetEccMode(nvmlVgpuInstance_t vgpuInstance, nvmlEnableState_t *eccMode) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlVgpuInstanceGetEccMode");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetEccMode, vgpuInstance, eccMode);
}
nvmlReturn_t nvmlVgpuInstanceGetEncoderCapacity(nvmlVgpuInstance_t vgpuInstance, unsigned int *encoderCapacity) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlVgpuInstanceGetEncoderCapacity");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetEncoderCapacity, vgpuInstance, encoderCapacity);
}
nvmlReturn_t nvmlVgpuInstanceGetEncoderSessions(nvmlVgpuInstance_t vgpuInstance, unsigned int *sessionCount, nvmlEncoderSessionInfo_t *sessionInfo) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlVgpuInstanceGetEncoderSessions");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetEncoderSessions, vgpuInstance, sessionCount, sessionInfo);
}
nvmlReturn_t nvmlVgpuInstanceGetEncoderStats(nvmlVgpuInstance_t vgpuInstance, unsigned int *sessionCount, unsigned int *averageFps, unsigned int *averageLatency) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlVgpuInstanceGetEncoderStats");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetEncoderStats, vgpuInstance, sessionCount, averageFps, averageLatency);
}
nvmlReturn_t nvmlVgpuInstanceGetFBCSessions(nvmlVgpuInstance_t vgpuInstance, unsigned int *sessionCount, nvmlFBCSessionInfo_t *sessionInfo) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlVgpuInstanceGetFBCSessions");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetFBCSessions, vgpuInstance, sessionCount, sessionInfo);
}
nvmlReturn_t nvmlVgpuInstanceGetFBCStats(nvmlVgpuInstance_t vgpuInstance, nvmlFBCStats_t *fbcStats) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlVgpuInstanceGetFBCStats");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetFBCStats, vgpuInstance, fbcStats);
}
nvmlReturn_t nvmlVgpuInstanceGetFbUsage(nvmlVgpuInstance_t vgpuInstance, unsigned long long *fbUsage) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlVgpuInstanceGetFbUsage");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetFbUsage, vgpuInstance, fbUsage);
}
nvmlReturn_t nvmlVgpuInstanceGetFrameRateLimit(nvmlVgpuInstance_t vgpuInstance, unsigned int *frameRateLimit) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlVgpuInstanceGetFrameRateLimit");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetFrameRateLimit, vgpuInstance, frameRateLimit);
}
nvmlReturn_t nvmlVgpuInstanceGetGpuInstanceId(nvmlVgpuInstance_t vgpuInstance, unsigned int *gpuInstanceId) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlVgpuInstanceGetGpuInstanceId");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetGpuInstanceId, vgpuInstance, gpuInstanceId);
}
nvmlReturn_t nvmlVgpuInstanceGetLicenseInfo(nvmlVgpuInstance_t vgpuInstance, nvmlVgpuLicenseInfo_t *licenseInfo) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlVgpuInstanceGetLicenseInfo");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetLicenseInfo, vgpuInstance, licenseInfo);
}
nvmlReturn_t nvmlVgpuInstanceGetLicenseStatus(nvmlVgpuInstance_t vgpuInstance, unsigned int *licensed) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlVgpuInstanceGetLicenseStatus");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetLicenseStatus, vgpuInstance, licensed);
}
nvmlReturn_t nvmlVgpuInstanceGetMdevUUID(nvmlVgpuInstance_t vgpuInstance, char *mdevUuid, unsigned int size) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlVgpuInstanceGetMdevUUID");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetMdevUUID, vgpuInstance, mdevUuid, size);
}
nvmlReturn_t nvmlVgpuInstanceGetMetadata(nvmlVgpuInstance_t vgpuInstance, nvmlVgpuMetadata_t *vgpuMetadata, unsigned int *bufferSize) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlVgpuInstanceGetMetadata");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetMetadata, vgpuInstance, vgpuMetadata, bufferSize);
}
nvmlReturn_t nvmlVgpuInstanceGetType(nvmlVgpuInstance_t vgpuInstance, nvmlVgpuTypeId_t *vgpuTypeId) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlVgpuInstanceGetType");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetType, vgpuInstance, vgpuTypeId);
}
nvmlReturn_t nvmlVgpuInstanceGetUUID(nvmlVgpuInstance_t vgpuInstance, char *uuid, unsigned int size) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlVgpuInstanceGetUUID");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetUUID, vgpuInstance, uuid, size);
}
nvmlReturn_t nvmlVgpuInstanceGetVmDriverVersion(nvmlVgpuInstance_t vgpuInstance, char *version, unsigned int length) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlVgpuInstanceGetVmDriverVersion");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetVmDriverVersion, vgpuInstance, version, length);
}
nvmlReturn_t nvmlVgpuInstanceGetVmID(nvmlVgpuInstance_t vgpuInstance, char *vmId, unsigned int size, nvmlVgpuVmIdType_t *vmIdType) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlVgpuInstanceGetVmID");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetVmID, vgpuInstance, vmId, size, vmIdType);
}
nvmlReturn_t nvmlVgpuInstanceSetEncoderCapacity(nvmlVgpuInstance_t vgpuInstance, unsigned int encoderCapacity) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlVgpuInstanceSetEncoderCapacity");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceSetEncoderCapacity, vgpuInstance, encoderCapacity);
}
nvmlReturn_t nvmlVgpuTypeGetClass(nvmlVgpuTypeId_t vgpuTypeId, char *vgpuTypeClass, unsigned int *size) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlVgpuTypeGetClass");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuTypeGetClass, vgpuTypeId, vgpuTypeClass, size);
}
nvmlReturn_t nvmlVgpuTypeGetDeviceID(nvmlVgpuTypeId_t vgpuTypeId, unsigned long long *deviceID, unsigned long long *subsystemID) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlVgpuTypeGetDeviceID");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuTypeGetDeviceID, vgpuTypeId, deviceID, subsystemID);
}
nvmlReturn_t nvmlVgpuTypeGetFrameRateLimit(nvmlVgpuTypeId_t vgpuTypeId, unsigned int *frameRateLimit) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlVgpuTypeGetFrameRateLimit");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuTypeGetFrameRateLimit, vgpuTypeId, frameRateLimit);
}
nvmlReturn_t nvmlVgpuTypeGetFramebufferSize(nvmlVgpuTypeId_t vgpuTypeId, unsigned long long *fbSize) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlVgpuTypeGetFramebufferSize");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuTypeGetFramebufferSize, vgpuTypeId, fbSize);
}
nvmlReturn_t nvmlVgpuTypeGetGpuInstanceProfileId(nvmlVgpuTypeId_t vgpuTypeId, unsigned int *gpuInstanceProfileId) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlVgpuTypeGetGpuInstanceProfileId");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuTypeGetGpuInstanceProfileId, vgpuTypeId, gpuInstanceProfileId);
}
nvmlReturn_t nvmlVgpuTypeGetLicense(nvmlVgpuTypeId_t vgpuTypeId, char *vgpuTypeLicenseString, unsigned int size) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlVgpuTypeGetLicense");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuTypeGetLicense, vgpuTypeId, vgpuTypeLicenseString, size);
}
nvmlReturn_t nvmlVgpuTypeGetMaxInstancesPerVm(nvmlVgpuTypeId_t vgpuTypeId, unsigned int *vgpuInstanceCountPerVm) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlVgpuTypeGetMaxInstancesPerVm");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuTypeGetMaxInstancesPerVm, vgpuTypeId, vgpuInstanceCountPerVm);
}
nvmlReturn_t nvmlVgpuTypeGetName(nvmlVgpuTypeId_t vgpuTypeId, char *vgpuTypeName, unsigned int *size) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlVgpuTypeGetName");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuTypeGetName, vgpuTypeId, vgpuTypeName, size);
}
nvmlReturn_t nvmlVgpuTypeGetNumDisplayHeads(nvmlVgpuTypeId_t vgpuTypeId, unsigned int *numDisplayHeads) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlVgpuTypeGetNumDisplayHeads");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuTypeGetNumDisplayHeads, vgpuTypeId, numDisplayHeads);
}
nvmlReturn_t nvmlVgpuTypeGetResolution(nvmlVgpuTypeId_t vgpuTypeId, unsigned int displayIndex, unsigned int *xdim, unsigned int *ydim) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "nvmlVgpuTypeGetResolution");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuTypeGetResolution, vgpuTypeId, displayIndex, xdim, ydim);
}