/*
 * Tencent is pleased to support the open source community by making TKEStack
 * available.
 *
 * Copyright (C) 2012-2019 Tencent. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 * https://opensource.org/licenses/Apache-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OF ANY KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations under the License.
 */

#ifndef HIJACK_NVML_HELPER_H
#define HIJACK_NVML_HELPER_H

#ifdef __cplusplus
extern "C" {
#endif

#include <dlfcn.h>

/**
 * NVML management library prefix
 */
#define DRIVER_ML_LIBRARY_PREFIX "libnvidia-ml.so"

#define NVML_ENTRY_ENUM(x) ENTRY_##x

#define NVML_FIND_ENTRY(table, sym) ({ (table)[NVML_ENTRY_ENUM(sym)]; })
#define NVML_ENTRY_CALL(table, sym, ...)                            \
    ({                                                              \
        int (*hookFunc)() = (int (*)())NVML_FIND_ENTRY(table, sym); \
        hookFunc(__VA_ARGS__);                                      \
    })

/**
 * NVML management library enumerator entry
 */
typedef enum {
    NVML_ENTRY_ENUM(nvmlInit),
    NVML_ENTRY_ENUM(nvmlShutdown),
    NVML_ENTRY_ENUM(nvmlErrorString),
    NVML_ENTRY_ENUM(nvmlDeviceGetHandleByIndex),
    NVML_ENTRY_ENUM(nvmlDeviceGetComputeRunningProcesses),
    NVML_ENTRY_ENUM(nvmlDeviceGetPciInfo),
    NVML_ENTRY_ENUM(nvmlDeviceGetProcessUtilization),
    NVML_ENTRY_ENUM(nvmlDeviceGetCount),
    NVML_ENTRY_ENUM(nvmlDeviceClearAccountingPids),
    NVML_ENTRY_ENUM(nvmlDeviceClearCpuAffinity),
    NVML_ENTRY_ENUM(nvmlDeviceClearEccErrorCounts),
    NVML_ENTRY_ENUM(nvmlDeviceDiscoverGpus),
    NVML_ENTRY_ENUM(nvmlDeviceFreezeNvLinkUtilizationCounter),
    NVML_ENTRY_ENUM(nvmlDeviceGetAccountingBufferSize),
    NVML_ENTRY_ENUM(nvmlDeviceGetAccountingMode),
    NVML_ENTRY_ENUM(nvmlDeviceGetAccountingPids),
    NVML_ENTRY_ENUM(nvmlDeviceGetAccountingStats),
    NVML_ENTRY_ENUM(nvmlDeviceGetActiveVgpus),
    NVML_ENTRY_ENUM(nvmlDeviceGetAPIRestriction),
    NVML_ENTRY_ENUM(nvmlDeviceGetApplicationsClock),
    NVML_ENTRY_ENUM(nvmlDeviceGetAutoBoostedClocksEnabled),
    NVML_ENTRY_ENUM(nvmlDeviceGetBAR1MemoryInfo),
    NVML_ENTRY_ENUM(nvmlDeviceGetBoardId),
    NVML_ENTRY_ENUM(nvmlDeviceGetBoardPartNumber),
    NVML_ENTRY_ENUM(nvmlDeviceGetBrand),
    NVML_ENTRY_ENUM(nvmlDeviceGetBridgeChipInfo),
    NVML_ENTRY_ENUM(nvmlDeviceGetClock),
    NVML_ENTRY_ENUM(nvmlDeviceGetClockInfo),
    NVML_ENTRY_ENUM(nvmlDeviceGetComputeMode),
    NVML_ENTRY_ENUM(nvmlDeviceGetCount_v2),
    NVML_ENTRY_ENUM(nvmlDeviceGetCpuAffinity),
    NVML_ENTRY_ENUM(nvmlDeviceGetCreatableVgpus),
    NVML_ENTRY_ENUM(nvmlDeviceGetCudaComputeCapability),
    NVML_ENTRY_ENUM(nvmlDeviceGetCurrentClocksThrottleReasons),
    NVML_ENTRY_ENUM(nvmlDeviceGetCurrPcieLinkGeneration),
    NVML_ENTRY_ENUM(nvmlDeviceGetCurrPcieLinkWidth),
    NVML_ENTRY_ENUM(nvmlDeviceGetDecoderUtilization),
    NVML_ENTRY_ENUM(nvmlDeviceGetDefaultApplicationsClock),
    NVML_ENTRY_ENUM(nvmlDeviceGetDetailedEccErrors),
    NVML_ENTRY_ENUM(nvmlDeviceGetDisplayActive),
    NVML_ENTRY_ENUM(nvmlDeviceGetDisplayMode),
    NVML_ENTRY_ENUM(nvmlDeviceGetDriverModel),
    NVML_ENTRY_ENUM(nvmlDeviceGetEccMode),
    NVML_ENTRY_ENUM(nvmlDeviceGetEncoderCapacity),
    NVML_ENTRY_ENUM(nvmlDeviceGetEncoderSessions),
    NVML_ENTRY_ENUM(nvmlDeviceGetEncoderStats),
    NVML_ENTRY_ENUM(nvmlDeviceGetEncoderUtilization),
    NVML_ENTRY_ENUM(nvmlDeviceGetEnforcedPowerLimit),
    NVML_ENTRY_ENUM(nvmlDeviceGetFanSpeed),
    NVML_ENTRY_ENUM(nvmlDeviceGetFanSpeed_v2),
    NVML_ENTRY_ENUM(nvmlDeviceGetFieldValues),
    NVML_ENTRY_ENUM(nvmlDeviceGetGpuOperationMode),
    NVML_ENTRY_ENUM(nvmlDeviceGetGraphicsRunningProcesses),
    NVML_ENTRY_ENUM(nvmlDeviceGetGridLicensableFeatures),
    NVML_ENTRY_ENUM(nvmlDeviceGetHandleByIndex_v2),
    NVML_ENTRY_ENUM(nvmlDeviceGetHandleByPciBusId),
    NVML_ENTRY_ENUM(nvmlDeviceGetHandleByPciBusId_v2),
    NVML_ENTRY_ENUM(nvmlDeviceGetHandleBySerial),
    NVML_ENTRY_ENUM(nvmlDeviceGetHandleByUUID),
    NVML_ENTRY_ENUM(nvmlDeviceGetIndex),
    NVML_ENTRY_ENUM(nvmlDeviceGetInforomConfigurationChecksum),
    NVML_ENTRY_ENUM(nvmlDeviceGetInforomImageVersion),
    NVML_ENTRY_ENUM(nvmlDeviceGetInforomVersion),
    NVML_ENTRY_ENUM(nvmlDeviceGetMaxClockInfo),
    NVML_ENTRY_ENUM(nvmlDeviceGetMaxCustomerBoostClock),
    NVML_ENTRY_ENUM(nvmlDeviceGetMaxPcieLinkGeneration),
    NVML_ENTRY_ENUM(nvmlDeviceGetMaxPcieLinkWidth),
    NVML_ENTRY_ENUM(nvmlDeviceGetMemoryErrorCounter),
    NVML_ENTRY_ENUM(nvmlDeviceGetMemoryInfo),
    NVML_ENTRY_ENUM(nvmlDeviceGetMinorNumber),
    NVML_ENTRY_ENUM(nvmlDeviceGetMPSComputeRunningProcesses),
    NVML_ENTRY_ENUM(nvmlDeviceGetMultiGpuBoard),
    NVML_ENTRY_ENUM(nvmlDeviceGetName),
    NVML_ENTRY_ENUM(nvmlDeviceGetNvLinkCapability),
    NVML_ENTRY_ENUM(nvmlDeviceGetNvLinkErrorCounter),
    NVML_ENTRY_ENUM(nvmlDeviceGetNvLinkRemotePciInfo),
    NVML_ENTRY_ENUM(nvmlDeviceGetNvLinkRemotePciInfo_v2),
    NVML_ENTRY_ENUM(nvmlDeviceGetNvLinkState),
    NVML_ENTRY_ENUM(nvmlDeviceGetNvLinkUtilizationControl),
    NVML_ENTRY_ENUM(nvmlDeviceGetNvLinkUtilizationCounter),
    NVML_ENTRY_ENUM(nvmlDeviceGetNvLinkVersion),
    NVML_ENTRY_ENUM(nvmlDeviceGetP2PStatus),
    NVML_ENTRY_ENUM(nvmlDeviceGetPcieReplayCounter),
    NVML_ENTRY_ENUM(nvmlDeviceGetPcieThroughput),
    NVML_ENTRY_ENUM(nvmlDeviceGetPciInfo_v2),
    NVML_ENTRY_ENUM(nvmlDeviceGetPciInfo_v3),
    NVML_ENTRY_ENUM(nvmlDeviceGetPerformanceState),
    NVML_ENTRY_ENUM(nvmlDeviceGetPersistenceMode),
    NVML_ENTRY_ENUM(nvmlDeviceGetPowerManagementDefaultLimit),
    NVML_ENTRY_ENUM(nvmlDeviceGetPowerManagementLimit),
    NVML_ENTRY_ENUM(nvmlDeviceGetPowerManagementLimitConstraints),
    NVML_ENTRY_ENUM(nvmlDeviceGetPowerManagementMode),
    NVML_ENTRY_ENUM(nvmlDeviceGetPowerState),
    NVML_ENTRY_ENUM(nvmlDeviceGetPowerUsage),
    NVML_ENTRY_ENUM(nvmlDeviceGetRetiredPages),
    NVML_ENTRY_ENUM(nvmlDeviceGetRetiredPagesPendingStatus),
    NVML_ENTRY_ENUM(nvmlDeviceGetSamples),
    NVML_ENTRY_ENUM(nvmlDeviceGetSerial),
    NVML_ENTRY_ENUM(nvmlDeviceGetSupportedClocksThrottleReasons),
    NVML_ENTRY_ENUM(nvmlDeviceGetSupportedEventTypes),
    NVML_ENTRY_ENUM(nvmlDeviceGetSupportedGraphicsClocks),
    NVML_ENTRY_ENUM(nvmlDeviceGetSupportedMemoryClocks),
    NVML_ENTRY_ENUM(nvmlDeviceGetSupportedVgpus),
    NVML_ENTRY_ENUM(nvmlDeviceGetTemperature),
    NVML_ENTRY_ENUM(nvmlDeviceGetTemperatureThreshold),
    NVML_ENTRY_ENUM(nvmlDeviceGetTopologyCommonAncestor),
    NVML_ENTRY_ENUM(nvmlDeviceGetTopologyNearestGpus),
    NVML_ENTRY_ENUM(nvmlDeviceGetTotalEccErrors),
    NVML_ENTRY_ENUM(nvmlDeviceGetTotalEnergyConsumption),
    NVML_ENTRY_ENUM(nvmlDeviceGetUtilizationRates),
    NVML_ENTRY_ENUM(nvmlDeviceGetUUID),
    NVML_ENTRY_ENUM(nvmlDeviceGetVbiosVersion),
    NVML_ENTRY_ENUM(nvmlDeviceGetVgpuMetadata),
    NVML_ENTRY_ENUM(nvmlDeviceGetVgpuProcessUtilization),
    NVML_ENTRY_ENUM(nvmlDeviceGetVgpuUtilization),
    NVML_ENTRY_ENUM(nvmlDeviceGetViolationStatus),
    NVML_ENTRY_ENUM(nvmlDeviceGetVirtualizationMode),
    NVML_ENTRY_ENUM(nvmlDeviceModifyDrainState),
    NVML_ENTRY_ENUM(nvmlDeviceOnSameBoard),
    NVML_ENTRY_ENUM(nvmlDeviceQueryDrainState),
    NVML_ENTRY_ENUM(nvmlDeviceRegisterEvents),
    NVML_ENTRY_ENUM(nvmlDeviceRemoveGpu),
    NVML_ENTRY_ENUM(nvmlDeviceRemoveGpu_v2),
    NVML_ENTRY_ENUM(nvmlDeviceResetApplicationsClocks),
    NVML_ENTRY_ENUM(nvmlDeviceResetNvLinkErrorCounters),
    NVML_ENTRY_ENUM(nvmlDeviceResetNvLinkUtilizationCounter),
    NVML_ENTRY_ENUM(nvmlDeviceSetAccountingMode),
    NVML_ENTRY_ENUM(nvmlDeviceSetAPIRestriction),
    NVML_ENTRY_ENUM(nvmlDeviceSetApplicationsClocks),
    NVML_ENTRY_ENUM(nvmlDeviceSetAutoBoostedClocksEnabled),
    NVML_ENTRY_ENUM(nvmlDeviceSetComputeMode),
    NVML_ENTRY_ENUM(nvmlDeviceSetCpuAffinity),
    NVML_ENTRY_ENUM(nvmlDeviceSetDefaultAutoBoostedClocksEnabled),
    NVML_ENTRY_ENUM(nvmlDeviceSetDriverModel),
    NVML_ENTRY_ENUM(nvmlDeviceSetEccMode),
    NVML_ENTRY_ENUM(nvmlDeviceSetGpuOperationMode),
    NVML_ENTRY_ENUM(nvmlDeviceSetNvLinkUtilizationControl),
    NVML_ENTRY_ENUM(nvmlDeviceSetPersistenceMode),
    NVML_ENTRY_ENUM(nvmlDeviceSetPowerManagementLimit),
    NVML_ENTRY_ENUM(nvmlDeviceSetVirtualizationMode),
    NVML_ENTRY_ENUM(nvmlDeviceValidateInforom),
    NVML_ENTRY_ENUM(nvmlEventSetCreate),
    NVML_ENTRY_ENUM(nvmlEventSetFree),
    NVML_ENTRY_ENUM(nvmlEventSetWait),
    NVML_ENTRY_ENUM(nvmlGetVgpuCompatibility),
    NVML_ENTRY_ENUM(nvmlInit_v2),
    NVML_ENTRY_ENUM(nvmlInitWithFlags),
    NVML_ENTRY_ENUM(nvmlInternalGetExportTable),
    NVML_ENTRY_ENUM(nvmlSystemGetCudaDriverVersion),
    NVML_ENTRY_ENUM(nvmlSystemGetCudaDriverVersion_v2),
    NVML_ENTRY_ENUM(nvmlSystemGetDriverVersion),
    NVML_ENTRY_ENUM(nvmlSystemGetHicVersion),
    NVML_ENTRY_ENUM(nvmlSystemGetNVMLVersion),
    NVML_ENTRY_ENUM(nvmlSystemGetProcessName),
    NVML_ENTRY_ENUM(nvmlSystemGetTopologyGpuSet),
    NVML_ENTRY_ENUM(nvmlUnitGetCount),
    NVML_ENTRY_ENUM(nvmlUnitGetDevices),
    NVML_ENTRY_ENUM(nvmlUnitGetFanSpeedInfo),
    NVML_ENTRY_ENUM(nvmlUnitGetHandleByIndex),
    NVML_ENTRY_ENUM(nvmlUnitGetLedState),
    NVML_ENTRY_ENUM(nvmlUnitGetPsuInfo),
    NVML_ENTRY_ENUM(nvmlUnitGetTemperature),
    NVML_ENTRY_ENUM(nvmlUnitGetUnitInfo),
    NVML_ENTRY_ENUM(nvmlUnitSetLedState),
    NVML_ENTRY_ENUM(nvmlVgpuInstanceGetEncoderCapacity),
    NVML_ENTRY_ENUM(nvmlVgpuInstanceGetEncoderSessions),
    NVML_ENTRY_ENUM(nvmlVgpuInstanceGetEncoderStats),
    NVML_ENTRY_ENUM(nvmlVgpuInstanceGetFbUsage),
    NVML_ENTRY_ENUM(nvmlVgpuInstanceGetFrameRateLimit),
    NVML_ENTRY_ENUM(nvmlVgpuInstanceGetLicenseStatus),
    NVML_ENTRY_ENUM(nvmlVgpuInstanceGetMetadata),
    NVML_ENTRY_ENUM(nvmlVgpuInstanceGetType),
    NVML_ENTRY_ENUM(nvmlVgpuInstanceGetUUID),
    NVML_ENTRY_ENUM(nvmlVgpuInstanceGetVmDriverVersion),
    NVML_ENTRY_ENUM(nvmlVgpuInstanceGetVmID),
    NVML_ENTRY_ENUM(nvmlVgpuInstanceSetEncoderCapacity),
    NVML_ENTRY_ENUM(nvmlVgpuTypeGetClass),
    NVML_ENTRY_ENUM(nvmlVgpuTypeGetDeviceID),
    NVML_ENTRY_ENUM(nvmlVgpuTypeGetFramebufferSize),
    NVML_ENTRY_ENUM(nvmlVgpuTypeGetFrameRateLimit),
    NVML_ENTRY_ENUM(nvmlVgpuTypeGetLicense),
    NVML_ENTRY_ENUM(nvmlVgpuTypeGetMaxInstances),
    NVML_ENTRY_ENUM(nvmlVgpuTypeGetName),
    NVML_ENTRY_ENUM(nvmlVgpuTypeGetNumDisplayHeads),
    NVML_ENTRY_ENUM(nvmlVgpuTypeGetResolution),
    NVML_ENTRY_ENUM(nvmlDeviceGetFBCSessions),
    NVML_ENTRY_ENUM(nvmlDeviceGetFBCStats),
    NVML_ENTRY_ENUM(nvmlDeviceGetGridLicensableFeatures_v2),
    NVML_ENTRY_ENUM(nvmlDeviceGetRetiredPages_v2),
    NVML_ENTRY_ENUM(nvmlDeviceResetGpuLockedClocks),
    NVML_ENTRY_ENUM(nvmlDeviceSetGpuLockedClocks),
    NVML_ENTRY_ENUM(nvmlGetBlacklistDeviceCount),
    NVML_ENTRY_ENUM(nvmlGetBlacklistDeviceInfoByIndex),
    NVML_ENTRY_ENUM(nvmlVgpuInstanceGetAccountingMode),
    NVML_ENTRY_ENUM(nvmlVgpuInstanceGetAccountingPids),
    NVML_ENTRY_ENUM(nvmlVgpuInstanceGetAccountingStats),
    NVML_ENTRY_ENUM(nvmlVgpuInstanceGetFBCSessions),
    NVML_ENTRY_ENUM(nvmlVgpuInstanceGetFBCStats),
    NVML_ENTRY_ENUM(nvmlVgpuTypeGetMaxInstancesPerVm),
    NVML_ENTRY_ENUM(nvmlGetVgpuVersion),
    NVML_ENTRY_ENUM(nvmlSetVgpuVersion),
    NVML_ENTRY_ENUM(nvmlDeviceGetGridLicensableFeatures_v3),
    NVML_ENTRY_ENUM(nvmlDeviceGetHostVgpuMode),
    NVML_ENTRY_ENUM(nvmlDeviceGetPgpuMetadataString),
    NVML_ENTRY_ENUM(nvmlVgpuInstanceGetEccMode),
    NVML_ENTRY_ENUM(nvmlComputeInstanceDestroy),
    NVML_ENTRY_ENUM(nvmlComputeInstanceGetInfo),
    NVML_ENTRY_ENUM(nvmlDeviceCreateGpuInstance),
    NVML_ENTRY_ENUM(nvmlDeviceGetArchitecture),
    NVML_ENTRY_ENUM(nvmlDeviceGetAttributes),
    NVML_ENTRY_ENUM(nvmlDeviceGetAttributes_v2),
    NVML_ENTRY_ENUM(nvmlDeviceGetComputeInstanceId),
    NVML_ENTRY_ENUM(nvmlDeviceGetCpuAffinityWithinScope),
    NVML_ENTRY_ENUM(nvmlDeviceGetDeviceHandleFromMigDeviceHandle),
    NVML_ENTRY_ENUM(nvmlDeviceGetGpuInstanceById),
    NVML_ENTRY_ENUM(nvmlDeviceGetGpuInstanceId),
    NVML_ENTRY_ENUM(nvmlDeviceGetGpuInstancePossiblePlacements),
    NVML_ENTRY_ENUM(nvmlDeviceGetGpuInstanceProfileInfo),
    NVML_ENTRY_ENUM(nvmlDeviceGetGpuInstanceRemainingCapacity),
    NVML_ENTRY_ENUM(nvmlDeviceGetGpuInstances),
    NVML_ENTRY_ENUM(nvmlDeviceGetMaxMigDeviceCount),
    NVML_ENTRY_ENUM(nvmlDeviceGetMemoryAffinity),
    NVML_ENTRY_ENUM(nvmlDeviceGetMigDeviceHandleByIndex),
    NVML_ENTRY_ENUM(nvmlDeviceGetMigMode),
    NVML_ENTRY_ENUM(nvmlDeviceGetRemappedRows),
    NVML_ENTRY_ENUM(nvmlDeviceGetRowRemapperHistogram),
    NVML_ENTRY_ENUM(nvmlDeviceIsMigDeviceHandle),
    NVML_ENTRY_ENUM(nvmlDeviceSetMigMode),
    NVML_ENTRY_ENUM(nvmlEventSetWait_v2),
    NVML_ENTRY_ENUM(nvmlGpuInstanceCreateComputeInstance),
    NVML_ENTRY_ENUM(nvmlGpuInstanceDestroy),
    NVML_ENTRY_ENUM(nvmlGpuInstanceGetComputeInstanceById),
    NVML_ENTRY_ENUM(nvmlGpuInstanceGetComputeInstanceProfileInfo),
    NVML_ENTRY_ENUM(nvmlGpuInstanceGetComputeInstanceRemainingCapacity),
    NVML_ENTRY_ENUM(nvmlGpuInstanceGetComputeInstances),
    NVML_ENTRY_ENUM(nvmlGpuInstanceGetInfo),
    NVML_ENTRY_ENUM(nvmlVgpuInstanceClearAccountingPids),
    NVML_ENTRY_ENUM(nvmlVgpuInstanceGetMdevUUID),
    NVML_ENTRY_ENUM(nvmlComputeInstanceGetInfo_v2),
    NVML_ENTRY_ENUM(nvmlDeviceGetComputeRunningProcesses_v2),
    NVML_ENTRY_ENUM(nvmlDeviceGetGraphicsRunningProcesses_v2),
    NVML_ENTRY_ENUM(nvmlDeviceSetTemperatureThreshold),
    NVML_ENTRY_ENUM(nvmlRetry_NvRmControl),
    NVML_ENTRY_ENUM(nvmlVgpuInstanceGetGpuInstanceId),
    NVML_ENTRY_ENUM(nvmlVgpuTypeGetGpuInstanceProfileId),
    NVML_ENTRY_ENUM(nvmlDeviceCreateGpuInstanceWithPlacement),
    NVML_ENTRY_ENUM(nvmlDeviceGetBusType),
    NVML_ENTRY_ENUM(nvmlDeviceGetClkMonStatus),
    NVML_ENTRY_ENUM(nvmlDeviceGetGpuInstancePossiblePlacements_v2),
    NVML_ENTRY_ENUM(nvmlDeviceGetGridLicensableFeatures_v4),
    NVML_ENTRY_ENUM(nvmlDeviceGetIrqNum),
    NVML_ENTRY_ENUM(nvmlDeviceGetMPSComputeRunningProcesses_v2),
    NVML_ENTRY_ENUM(nvmlDeviceGetNvLinkRemoteDeviceType),
    NVML_ENTRY_ENUM(nvmlDeviceResetMemoryLockedClocks),
    NVML_ENTRY_ENUM(nvmlDeviceSetMemoryLockedClocks),
    NVML_ENTRY_ENUM(nvmlGetExcludedDeviceCount),
    NVML_ENTRY_ENUM(nvmlGetExcludedDeviceInfoByIndex),
    NVML_ENTRY_ENUM(nvmlVgpuInstanceGetLicenseInfo),
    NVML_ENTRY_ENUM(nvmlDeviceGetMemoryInfo_v2),
    NVML_ENTRY_END
} nvml_entry_enum_t;

#ifdef __cplusplus
}
#endif

#endif // HIJACK_NVML_HELPER_H