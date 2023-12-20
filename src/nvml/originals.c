#include "include/base.h"
#include "string.h"
extern void *nvml_library_entry[];
const  char * nvmlErrorString ( nvmlReturn_t result ) ;
nvmlReturn_t  nvmlComputeInstanceDestroy ( nvmlComputeInstance_t computeInstance ) ;
nvmlReturn_t  nvmlComputeInstanceGetInfo ( nvmlComputeInstance_t computeInstance , nvmlComputeInstanceInfo_t * info ) ;
nvmlReturn_t  nvmlComputeInstanceGetInfo_v2 ( nvmlComputeInstance_t computeInstance , nvmlComputeInstanceInfo_t * info ) ;
nvmlReturn_t  nvmlDeviceClearAccountingPids ( nvmlDevice_t device ) ;
nvmlReturn_t  nvmlDeviceClearCpuAffinity ( nvmlDevice_t device ) ;
nvmlReturn_t  nvmlDeviceClearEccErrorCounts ( nvmlDevice_t device , nvmlEccCounterType_t counterType ) ;
nvmlReturn_t  nvmlDeviceCreateGpuInstance ( nvmlDevice_t device , unsigned int profileId , nvmlGpuInstance_t * gpuInstance ) ;
nvmlReturn_t  nvmlDeviceCreateGpuInstanceWithPlacement ( nvmlDevice_t device , unsigned int profileId , const nvmlGpuInstancePlacement_t * placement , nvmlGpuInstance_t * gpuInstance ) ;
nvmlReturn_t  nvmlDeviceDiscoverGpus ( nvmlPciInfo_t * pciInfo ) ;
nvmlReturn_t  nvmlDeviceFreezeNvLinkUtilizationCounter ( nvmlDevice_t device , unsigned int link , unsigned int counter , nvmlEnableState_t freeze ) ;
nvmlReturn_t  nvmlDeviceGetAPIRestriction ( nvmlDevice_t device , nvmlRestrictedAPI_t apiType , nvmlEnableState_t * isRestricted ) ;
nvmlReturn_t  nvmlDeviceGetAccountingBufferSize ( nvmlDevice_t device , unsigned int * bufferSize ) ;
nvmlReturn_t  nvmlDeviceGetAccountingMode ( nvmlDevice_t device , nvmlEnableState_t * mode ) ;
nvmlReturn_t  nvmlDeviceGetAccountingPids ( nvmlDevice_t device , unsigned int * count , unsigned int * pids ) ;
nvmlReturn_t  nvmlDeviceGetAccountingStats ( nvmlDevice_t device , unsigned int pid , nvmlAccountingStats_t * stats ) ;
nvmlReturn_t  nvmlDeviceGetActiveVgpus ( nvmlDevice_t device , unsigned int * vgpuCount , nvmlVgpuInstance_t * vgpuInstances ) ;
nvmlReturn_t  nvmlDeviceGetApplicationsClock ( nvmlDevice_t device , nvmlClockType_t clockType , unsigned int * clockMHz ) ;
nvmlReturn_t  nvmlDeviceGetArchitecture ( nvmlDevice_t device , nvmlDeviceArchitecture_t * arch ) ;
nvmlReturn_t  nvmlDeviceGetAttributes ( nvmlDevice_t device , nvmlDeviceAttributes_t * attributes ) ;
nvmlReturn_t  nvmlDeviceGetAttributes_v2 ( nvmlDevice_t device , nvmlDeviceAttributes_t * attributes ) ;
nvmlReturn_t  nvmlDeviceGetAutoBoostedClocksEnabled ( nvmlDevice_t device , nvmlEnableState_t * isEnabled , nvmlEnableState_t * defaultIsEnabled ) ;
nvmlReturn_t  nvmlDeviceGetBAR1MemoryInfo ( nvmlDevice_t device , nvmlBAR1Memory_t * bar1Memory ) ;
nvmlReturn_t  nvmlDeviceGetBoardId ( nvmlDevice_t device , unsigned int * boardId ) ;
nvmlReturn_t  nvmlDeviceGetBoardPartNumber ( nvmlDevice_t device , char * partNumber , unsigned int length ) ;
nvmlReturn_t  nvmlDeviceGetBrand ( nvmlDevice_t device , nvmlBrandType_t * type ) ;
nvmlReturn_t  nvmlDeviceGetBridgeChipInfo ( nvmlDevice_t device , nvmlBridgeChipHierarchy_t * bridgeHierarchy ) ;
nvmlReturn_t  nvmlDeviceGetBusType ( nvmlDevice_t device , nvmlBusType_t * type ) ;
nvmlReturn_t  nvmlDeviceGetClkMonStatus ( nvmlDevice_t device , nvmlClkMonStatus_t * status ) ;
nvmlReturn_t  nvmlDeviceGetClock ( nvmlDevice_t device , nvmlClockType_t clockType , nvmlClockId_t clockId , unsigned int * clockMHz ) ;
nvmlReturn_t  nvmlDeviceGetClockInfo ( nvmlDevice_t device , nvmlClockType_t type , unsigned int * clock ) ;
nvmlReturn_t  nvmlDeviceGetComputeInstanceId ( nvmlDevice_t device , unsigned int * id ) ;
nvmlReturn_t  nvmlDeviceGetComputeMode ( nvmlDevice_t device , nvmlComputeMode_t * mode ) ;
nvmlReturn_t  nvmlDeviceGetComputeRunningProcesses ( nvmlDevice_t device , unsigned int * infoCount , nvmlProcessInfo_v1_t * infos ) ;
nvmlReturn_t  nvmlDeviceGetComputeRunningProcesses_v2 ( nvmlDevice_t device , unsigned int * infoCount , nvmlProcessInfo_v2_t * infos ) ;
nvmlReturn_t  nvmlDeviceGetComputeRunningProcesses_v3 ( nvmlDevice_t device , unsigned int * infoCount , nvmlProcessInfo_t * infos ) ;
nvmlReturn_t  nvmlDeviceGetCount ( unsigned int * deviceCount ) ;
nvmlReturn_t  nvmlDeviceGetCount_v2 ( unsigned int * deviceCount ) ;
nvmlReturn_t  nvmlDeviceGetCpuAffinity ( nvmlDevice_t device , unsigned int cpuSetSize , unsigned long * cpuSet ) ;
nvmlReturn_t  nvmlDeviceGetCpuAffinityWithinScope ( nvmlDevice_t device , unsigned int cpuSetSize , unsigned long * cpuSet , nvmlAffinityScope_t scope ) ;
nvmlReturn_t  nvmlDeviceGetCreatableVgpus ( nvmlDevice_t device , unsigned int * vgpuCount , nvmlVgpuTypeId_t * vgpuTypeIds ) ;
nvmlReturn_t  nvmlDeviceGetCudaComputeCapability ( nvmlDevice_t device , int * major , int * minor ) ;
nvmlReturn_t  nvmlDeviceGetCurrPcieLinkGeneration ( nvmlDevice_t device , unsigned int * currLinkGen ) ;
nvmlReturn_t  nvmlDeviceGetCurrPcieLinkWidth ( nvmlDevice_t device , unsigned int * currLinkWidth ) ;
nvmlReturn_t  nvmlDeviceGetCurrentClocksThrottleReasons ( nvmlDevice_t device , unsigned long long * clocksThrottleReasons ) ;
nvmlReturn_t  nvmlDeviceGetDecoderUtilization ( nvmlDevice_t device , unsigned int * utilization , unsigned int * samplingPeriodUs ) ;
nvmlReturn_t  nvmlDeviceGetDefaultApplicationsClock ( nvmlDevice_t device , nvmlClockType_t clockType , unsigned int * clockMHz ) ;
nvmlReturn_t  nvmlDeviceGetDefaultEccMode ( nvmlDevice_t device , nvmlEnableState_t * defaultMode ) ;
nvmlReturn_t  nvmlDeviceGetDetailedEccErrors ( nvmlDevice_t device , nvmlMemoryErrorType_t errorType , nvmlEccCounterType_t counterType , nvmlEccErrorCounts_t * eccCounts ) ;
nvmlReturn_t  nvmlDeviceGetDeviceHandleFromMigDeviceHandle ( nvmlDevice_t migDevice , nvmlDevice_t * device ) ;
nvmlReturn_t  nvmlDeviceGetDisplayActive ( nvmlDevice_t device , nvmlEnableState_t * isActive ) ;
nvmlReturn_t  nvmlDeviceGetDisplayMode ( nvmlDevice_t device , nvmlEnableState_t * display ) ;
nvmlReturn_t  nvmlDeviceGetDriverModel ( nvmlDevice_t device , nvmlDriverModel_t * current , nvmlDriverModel_t * pending ) ;
nvmlReturn_t  nvmlDeviceGetDynamicPstatesInfo ( nvmlDevice_t device , nvmlGpuDynamicPstatesInfo_t * pDynamicPstatesInfo ) ;
nvmlReturn_t  nvmlDeviceGetEccMode ( nvmlDevice_t device , nvmlEnableState_t * current , nvmlEnableState_t * pending ) ;
nvmlReturn_t  nvmlDeviceGetEncoderCapacity ( nvmlDevice_t device , nvmlEncoderType_t encoderQueryType , unsigned int * encoderCapacity ) ;
nvmlReturn_t  nvmlDeviceGetEncoderSessions ( nvmlDevice_t device , unsigned int * sessionCount , nvmlEncoderSessionInfo_t * sessionInfos ) ;
nvmlReturn_t  nvmlDeviceGetEncoderStats ( nvmlDevice_t device , unsigned int * sessionCount , unsigned int * averageFps , unsigned int * averageLatency ) ;
nvmlReturn_t  nvmlDeviceGetEncoderUtilization ( nvmlDevice_t device , unsigned int * utilization , unsigned int * samplingPeriodUs ) ;
nvmlReturn_t  nvmlDeviceGetEnforcedPowerLimit ( nvmlDevice_t device , unsigned int * limit ) ;
nvmlReturn_t  nvmlDeviceGetFBCSessions ( nvmlDevice_t device , unsigned int * sessionCount , nvmlFBCSessionInfo_t * sessionInfo ) ;
nvmlReturn_t  nvmlDeviceGetFBCStats ( nvmlDevice_t device , nvmlFBCStats_t * fbcStats ) ;
nvmlReturn_t  nvmlDeviceGetFanSpeed ( nvmlDevice_t device , unsigned int * speed ) ;
nvmlReturn_t  nvmlDeviceGetFanSpeed_v2 ( nvmlDevice_t device , unsigned int fan , unsigned int * speed ) ;
nvmlReturn_t  nvmlDeviceGetFieldValues ( nvmlDevice_t device , int valuesCount , nvmlFieldValue_t * values ) ;
nvmlReturn_t  nvmlDeviceGetGpcClkMinMaxVfOffset ( nvmlDevice_t device , int * minOffset , int * maxOffset ) ;
nvmlReturn_t  nvmlDeviceGetGpcClkVfOffset ( nvmlDevice_t device , int * vgpu_offset ) ;
nvmlReturn_t  nvmlDeviceGetGpuInstanceById ( nvmlDevice_t device , unsigned int id , nvmlGpuInstance_t * gpuInstance ) ;
nvmlReturn_t  nvmlDeviceGetGpuInstanceId ( nvmlDevice_t device , unsigned int * id ) ;
nvmlReturn_t  nvmlDeviceGetGpuInstancePossiblePlacements ( nvmlDevice_t device , unsigned int profileId , nvmlGpuInstancePlacement_t * placements , unsigned int * count ) ;
nvmlReturn_t  nvmlDeviceGetGpuInstancePossiblePlacements_v2 ( nvmlDevice_t device , unsigned int profileId , nvmlGpuInstancePlacement_t * placements , unsigned int * count ) ;
nvmlReturn_t  nvmlDeviceGetGpuInstanceProfileInfo ( nvmlDevice_t device , unsigned int profile , nvmlGpuInstanceProfileInfo_t * info ) ;
nvmlReturn_t  nvmlDeviceGetGpuInstanceProfileInfoV ( nvmlDevice_t device , unsigned int profile , nvmlGpuInstanceProfileInfo_v2_t * info ) ;
nvmlReturn_t  nvmlDeviceGetGpuInstanceRemainingCapacity ( nvmlDevice_t device , unsigned int profileId , unsigned int * count ) ;
nvmlReturn_t  nvmlDeviceGetGpuInstances ( nvmlDevice_t device , unsigned int profileId , nvmlGpuInstance_t * gpuInstances , unsigned int * count ) ;
nvmlReturn_t  nvmlDeviceGetGpuOperationMode ( nvmlDevice_t device , nvmlGpuOperationMode_t * current , nvmlGpuOperationMode_t * pending ) ;
nvmlReturn_t  nvmlDeviceGetGraphicsRunningProcesses ( nvmlDevice_t device , unsigned int * infoCount , nvmlProcessInfo_v1_t * infos ) ;
nvmlReturn_t  nvmlDeviceGetGraphicsRunningProcesses_v2 ( nvmlDevice_t device , unsigned int * infoCount , nvmlProcessInfo_v2_t * infos ) ;
nvmlReturn_t  nvmlDeviceGetGraphicsRunningProcesses_v3 ( nvmlDevice_t device , unsigned int * infoCount , nvmlProcessInfo_t * infos ) ;
nvmlReturn_t  nvmlDeviceGetGridLicensableFeatures ( nvmlDevice_t device , nvmlGridLicensableFeatures_t * pGridLicensableFeatures ) ;
nvmlReturn_t  nvmlDeviceGetGridLicensableFeatures_v2 ( nvmlDevice_t device , nvmlGridLicensableFeatures_t * pGridLicensableFeatures ) ;
nvmlReturn_t  nvmlDeviceGetGridLicensableFeatures_v3 ( nvmlDevice_t device , nvmlGridLicensableFeatures_t * pGridLicensableFeatures ) ;
nvmlReturn_t  nvmlDeviceGetGridLicensableFeatures_v4 ( nvmlDevice_t device , nvmlGridLicensableFeatures_t * pGridLicensableFeatures ) ;
nvmlReturn_t  nvmlDeviceGetGspFirmwareMode ( nvmlDevice_t device , unsigned int * isEnabled , unsigned int * defaultMode ) ;
nvmlReturn_t  nvmlDeviceGetGspFirmwareVersion ( nvmlDevice_t device , char * version ) ;
nvmlReturn_t  nvmlDeviceGetHandleByIndex ( unsigned int index , nvmlDevice_t * device ) ;
nvmlReturn_t  nvmlDeviceGetHandleByIndex_v2 ( unsigned int index , nvmlDevice_t * device ) ;
nvmlReturn_t  nvmlDeviceGetHandleByPciBusId ( const char * pciBusId , nvmlDevice_t * device ) ;
nvmlReturn_t  nvmlDeviceGetHandleByPciBusId_v2 ( const char * pciBusId , nvmlDevice_t * device ) ;
nvmlReturn_t  nvmlDeviceGetHandleBySerial ( const char * serial , nvmlDevice_t * device ) ;
nvmlReturn_t  nvmlDeviceGetHandleByUUID ( const char * uuid , nvmlDevice_t * device ) ;
nvmlReturn_t  nvmlDeviceGetHostVgpuMode ( nvmlDevice_t device , nvmlHostVgpuMode_t * pHostVgpuMode ) ;
nvmlReturn_t  nvmlDeviceGetIndex ( nvmlDevice_t device , unsigned int * index ) ;
nvmlReturn_t  nvmlDeviceGetInforomConfigurationChecksum ( nvmlDevice_t device , unsigned int * checksum ) ;
nvmlReturn_t  nvmlDeviceGetInforomImageVersion ( nvmlDevice_t device , char * version , unsigned int length ) ;
nvmlReturn_t  nvmlDeviceGetInforomVersion ( nvmlDevice_t device , nvmlInforomObject_t object , char * version , unsigned int length ) ;
nvmlReturn_t  nvmlDeviceGetIrqNum ( nvmlDevice_t device , unsigned int * irqNum ) ;
nvmlReturn_t  nvmlDeviceGetMPSComputeRunningProcesses ( nvmlDevice_t device , unsigned int * infoCount , nvmlProcessInfo_v1_t * infos ) ;
nvmlReturn_t  nvmlDeviceGetMPSComputeRunningProcesses_v2 ( nvmlDevice_t device , unsigned int * infoCount , nvmlProcessInfo_v2_t * infos ) ;
nvmlReturn_t  nvmlDeviceGetMPSComputeRunningProcesses_v3 ( nvmlDevice_t device , unsigned int * infoCount , nvmlProcessInfo_t * infos ) ;
nvmlReturn_t  nvmlDeviceGetMaxClockInfo ( nvmlDevice_t device , nvmlClockType_t type , unsigned int * clock ) ;
nvmlReturn_t  nvmlDeviceGetMaxCustomerBoostClock ( nvmlDevice_t device , nvmlClockType_t clockType , unsigned int * clockMHz ) ;
nvmlReturn_t  nvmlDeviceGetMaxMigDeviceCount ( nvmlDevice_t device , unsigned int * count ) ;
nvmlReturn_t  nvmlDeviceGetMaxPcieLinkGeneration ( nvmlDevice_t device , unsigned int * maxLinkGen ) ;
nvmlReturn_t  nvmlDeviceGetMaxPcieLinkWidth ( nvmlDevice_t device , unsigned int * maxLinkWidth ) ;
nvmlReturn_t  nvmlDeviceGetMemClkMinMaxVfOffset ( nvmlDevice_t device , int * minOffset , int * maxOffset ) ;
nvmlReturn_t  nvmlDeviceGetMemClkVfOffset ( nvmlDevice_t device , int * vgpu_offset ) ;
nvmlReturn_t  nvmlDeviceGetMemoryAffinity ( nvmlDevice_t device , unsigned int nodeSetSize , unsigned long * nodeSet , nvmlAffinityScope_t scope ) ;
nvmlReturn_t  nvmlDeviceGetMemoryBusWidth ( nvmlDevice_t device , unsigned int * busWidth ) ;
nvmlReturn_t  nvmlDeviceGetMemoryErrorCounter ( nvmlDevice_t device , nvmlMemoryErrorType_t errorType , nvmlEccCounterType_t counterType , nvmlMemoryLocation_t locationType , unsigned long long * count ) ;
nvmlReturn_t  nvmlDeviceGetMemoryInfo ( nvmlDevice_t device , nvmlMemory_t * memory ) ;
nvmlReturn_t  nvmlDeviceGetMemoryInfo_v2 ( nvmlDevice_t device , nvmlMemory_v2_t * memory ) ;
nvmlReturn_t  nvmlDeviceGetMigDeviceHandleByIndex ( nvmlDevice_t device , unsigned int index , nvmlDevice_t * migDevice ) ;
nvmlReturn_t  nvmlDeviceGetMigMode ( nvmlDevice_t device , unsigned int * currentMode , unsigned int * pendingMode ) ;
nvmlReturn_t  nvmlDeviceGetMinMaxClockOfPState ( nvmlDevice_t device , nvmlClockType_t type , nvmlPstates_t pstate , unsigned int * minClockMHz , unsigned int * maxClockMHz ) ;
nvmlReturn_t  nvmlDeviceGetMinMaxFanSpeed ( nvmlDevice_t device , unsigned int * minSpeed , unsigned int * maxSpeed ) ;
nvmlReturn_t  nvmlDeviceGetMinorNumber ( nvmlDevice_t device , unsigned int * minorNumber ) ;
nvmlReturn_t  nvmlDeviceGetMultiGpuBoard ( nvmlDevice_t device , unsigned int * multiGpuBool ) ;
nvmlReturn_t  nvmlDeviceGetName ( nvmlDevice_t device , char * name , unsigned int length ) ;
nvmlReturn_t  nvmlDeviceGetNumFans ( nvmlDevice_t device , unsigned int * numFans ) ;
nvmlReturn_t  nvmlDeviceGetNumGpuCores ( nvmlDevice_t device , unsigned int * numCores ) ;
nvmlReturn_t  nvmlDeviceGetNvLinkCapability ( nvmlDevice_t device , unsigned int link , nvmlNvLinkCapability_t capability , unsigned int * capResult ) ;
nvmlReturn_t  nvmlDeviceGetNvLinkErrorCounter ( nvmlDevice_t device , unsigned int link , nvmlNvLinkErrorCounter_t counter , unsigned long long * counterValue ) ;
nvmlReturn_t  nvmlDeviceGetNvLinkRemoteDeviceType ( nvmlDevice_t device , unsigned int link , nvmlIntNvLinkDeviceType_t * pNvLinkDeviceType ) ;
nvmlReturn_t  nvmlDeviceGetNvLinkRemotePciInfo ( nvmlDevice_t device , unsigned int link , nvmlPciInfo_t * pci ) ;
nvmlReturn_t  nvmlDeviceGetNvLinkRemotePciInfo_v2 ( nvmlDevice_t device , unsigned int link , nvmlPciInfo_t * pci ) ;
nvmlReturn_t  nvmlDeviceGetNvLinkState ( nvmlDevice_t device , unsigned int link , nvmlEnableState_t * isActive ) ;
nvmlReturn_t  nvmlDeviceGetNvLinkUtilizationControl ( nvmlDevice_t device , unsigned int link , unsigned int counter , nvmlNvLinkUtilizationControl_t * control ) ;
nvmlReturn_t  nvmlDeviceGetNvLinkUtilizationCounter ( nvmlDevice_t device , unsigned int link , unsigned int counter , unsigned long long * rxcounter , unsigned long long * txcounter ) ;
nvmlReturn_t  nvmlDeviceGetNvLinkVersion ( nvmlDevice_t device , unsigned int link , unsigned int * version ) ;
nvmlReturn_t  nvmlDeviceGetP2PStatus ( nvmlDevice_t device1 , nvmlDevice_t device2 , nvmlGpuP2PCapsIndex_t p2pIndex , nvmlGpuP2PStatus_t * p2pStatus ) ;
nvmlReturn_t  nvmlDeviceGetPciInfo ( nvmlDevice_t device , nvmlPciInfo_t * pci ) ;
nvmlReturn_t  nvmlDeviceGetPciInfo_v2 ( nvmlDevice_t device , nvmlPciInfo_t * pci ) ;
nvmlReturn_t  nvmlDeviceGetPciInfo_v3 ( nvmlDevice_t device , nvmlPciInfo_t * pci ) ;
nvmlReturn_t  nvmlDeviceGetPcieLinkMaxSpeed ( nvmlDevice_t device , unsigned int * maxSpeed ) ;
nvmlReturn_t  nvmlDeviceGetPcieReplayCounter ( nvmlDevice_t device , unsigned int * value ) ;
nvmlReturn_t  nvmlDeviceGetPcieSpeed ( nvmlDevice_t device , unsigned int * pcieSpeed ) ;
nvmlReturn_t  nvmlDeviceGetPcieThroughput ( nvmlDevice_t device , nvmlPcieUtilCounter_t counter , unsigned int * value ) ;
nvmlReturn_t  nvmlDeviceGetPerformanceState ( nvmlDevice_t device , nvmlPstates_t * pState ) ;
nvmlReturn_t  nvmlDeviceGetPersistenceMode ( nvmlDevice_t device , nvmlEnableState_t * mode ) ;
nvmlReturn_t  nvmlDeviceGetPgpuMetadataString ( nvmlDevice_t device , char * pgpuMetadata , unsigned int * bufferSize ) ;
nvmlReturn_t  nvmlDeviceGetPowerManagementDefaultLimit ( nvmlDevice_t device , unsigned int * defaultLimit ) ;
nvmlReturn_t  nvmlDeviceGetPowerManagementLimit ( nvmlDevice_t device , unsigned int * limit ) ;
nvmlReturn_t  nvmlDeviceGetPowerManagementLimitConstraints ( nvmlDevice_t device , unsigned int * minLimit , unsigned int * maxLimit ) ;
nvmlReturn_t  nvmlDeviceGetPowerManagementMode ( nvmlDevice_t device , nvmlEnableState_t * mode ) ;
nvmlReturn_t  nvmlDeviceGetPowerMode ( nvmlDevice_t device , unsigned int * powerModeId ) ;
nvmlReturn_t  nvmlDeviceGetPowerSource ( nvmlDevice_t device , nvmlPowerSource_t * powerSource ) ;
nvmlReturn_t  nvmlDeviceGetPowerState ( nvmlDevice_t device , nvmlPstates_t * pState ) ;
nvmlReturn_t  nvmlDeviceGetPowerUsage ( nvmlDevice_t device , unsigned int * power ) ;
nvmlReturn_t  nvmlDeviceGetProcessUtilization ( nvmlDevice_t device , nvmlProcessUtilizationSample_t * utilization , unsigned int * processSamplesCount , unsigned long long lastSeenTimeStamp ) ;
nvmlReturn_t  nvmlDeviceGetRemappedRows ( nvmlDevice_t device , unsigned int * corrRows , unsigned int * uncRows , unsigned int * isPending , unsigned int * failureOccurred ) ;
nvmlReturn_t  nvmlDeviceGetRetiredPages ( nvmlDevice_t device , nvmlPageRetirementCause_t cause , unsigned int * pageCount , unsigned long long * addresses ) ;
nvmlReturn_t  nvmlDeviceGetRetiredPagesPendingStatus ( nvmlDevice_t device , nvmlEnableState_t * isPending ) ;
nvmlReturn_t  nvmlDeviceGetRetiredPages_v2 ( nvmlDevice_t device , nvmlPageRetirementCause_t cause , unsigned int * pageCount , unsigned long long * addresses , unsigned long long * timestamps ) ;
nvmlReturn_t  nvmlDeviceGetRowRemapperHistogram ( nvmlDevice_t device , nvmlRowRemapperHistogramValues_t * values ) ;
nvmlReturn_t  nvmlDeviceGetSamples ( nvmlDevice_t device , nvmlSamplingType_t type , unsigned long long lastSeenTimeStamp , nvmlValueType_t * sampleValType , unsigned int * sampleCount , nvmlSample_t * samples ) ;
nvmlReturn_t  nvmlDeviceGetSerial ( nvmlDevice_t device , char * serial , unsigned int length ) ;
nvmlReturn_t  nvmlDeviceGetSupportedClocksThrottleReasons ( nvmlDevice_t device , unsigned long long * supportedClocksThrottleReasons ) ;
nvmlReturn_t  nvmlDeviceGetSupportedEventTypes ( nvmlDevice_t device , unsigned long long * eventTypes ) ;
nvmlReturn_t  nvmlDeviceGetSupportedGraphicsClocks ( nvmlDevice_t device , unsigned int memoryClockMHz , unsigned int * count , unsigned int * clocksMHz ) ;
nvmlReturn_t  nvmlDeviceGetSupportedMemoryClocks ( nvmlDevice_t device , unsigned int * count , unsigned int * clocksMHz ) ;
nvmlReturn_t  nvmlDeviceGetSupportedPerformanceStates ( nvmlDevice_t device , nvmlPstates_t * pstates , unsigned int size ) ;
nvmlReturn_t  nvmlDeviceGetSupportedPowerModes ( nvmlDevice_t device , unsigned int * supportedPowerModes ) ;
nvmlReturn_t  nvmlDeviceGetSupportedVgpus ( nvmlDevice_t device , unsigned int * vgpuCount , nvmlVgpuTypeId_t * vgpuTypeIds ) ;
nvmlReturn_t  nvmlDeviceGetTargetFanSpeed ( nvmlDevice_t device , unsigned int fan , unsigned int * targetSpeed ) ;
nvmlReturn_t  nvmlDeviceGetTemperature ( nvmlDevice_t device , nvmlTemperatureSensors_t sensorType , unsigned int * temp ) ;
nvmlReturn_t  nvmlDeviceGetTemperatureThreshold ( nvmlDevice_t device , nvmlTemperatureThresholds_t thresholdType , unsigned int * temp ) ;
nvmlReturn_t  nvmlDeviceGetThermalSettings ( nvmlDevice_t device , unsigned int sensorIndex , nvmlGpuThermalSettings_t * pThermalSettings ) ;
nvmlReturn_t  nvmlDeviceGetTopologyCommonAncestor ( nvmlDevice_t device1 , nvmlDevice_t device2 , nvmlGpuTopologyLevel_t * pathInfo ) ;
nvmlReturn_t  nvmlDeviceGetTopologyNearestGpus ( nvmlDevice_t device , nvmlGpuTopologyLevel_t level , unsigned int * count , nvmlDevice_t * deviceArray ) ;
nvmlReturn_t  nvmlDeviceGetTotalEccErrors ( nvmlDevice_t device , nvmlMemoryErrorType_t errorType , nvmlEccCounterType_t counterType , unsigned long long * eccCounts ) ;
nvmlReturn_t  nvmlDeviceGetTotalEnergyConsumption ( nvmlDevice_t device , unsigned long long * energy ) ;
nvmlReturn_t  nvmlDeviceGetUUID ( nvmlDevice_t device , char * uuid , unsigned int length ) ;
nvmlReturn_t  nvmlDeviceGetUtilizationRates ( nvmlDevice_t device , nvmlUtilization_t * utilization ) ;
nvmlReturn_t  nvmlDeviceGetVbiosVersion ( nvmlDevice_t device , char * version , unsigned int length ) ;
nvmlReturn_t  nvmlDeviceGetVgpuMetadata ( nvmlDevice_t device , nvmlVgpuPgpuMetadata_t * pgpuMetadata , unsigned int * bufferSize ) ;
nvmlReturn_t  nvmlDeviceGetVgpuProcessUtilization ( nvmlDevice_t device , unsigned long long lastSeenTimeStamp , unsigned int * vgpuProcessSamplesCount , nvmlVgpuProcessUtilizationSample_t * utilizationSamples ) ;
nvmlReturn_t  nvmlDeviceGetVgpuUtilization ( nvmlDevice_t device , unsigned long long lastSeenTimeStamp , nvmlValueType_t * sampleValType , unsigned int * vgpuInstanceSamplesCount , nvmlVgpuInstanceUtilizationSample_t * utilizationSamples ) ;
nvmlReturn_t  nvmlDeviceGetViolationStatus ( nvmlDevice_t device , nvmlPerfPolicyType_t perfPolicyType , nvmlViolationTime_t * violTime ) ;
nvmlReturn_t  nvmlDeviceGetVirtualizationMode ( nvmlDevice_t device , nvmlGpuVirtualizationMode_t * pVirtualMode ) ;
nvmlReturn_t  nvmlDeviceIsMigDeviceHandle ( nvmlDevice_t device , unsigned int * isMigDevice ) ;
nvmlReturn_t  nvmlDeviceModifyDrainState ( nvmlPciInfo_t * pciInfo , nvmlEnableState_t newState ) ;
nvmlReturn_t  nvmlDeviceOnSameBoard ( nvmlDevice_t device1 , nvmlDevice_t device2 , int * onSameBoard ) ;
nvmlReturn_t  nvmlDeviceQueryDrainState ( nvmlPciInfo_t * pciInfo , nvmlEnableState_t * currentState ) ;
nvmlReturn_t  nvmlDeviceRegisterEvents ( nvmlDevice_t device , unsigned long long eventTypes , nvmlEventSet_t set ) ;
nvmlReturn_t  nvmlDeviceRemoveGpu ( nvmlPciInfo_t * pciInfo ) ;
nvmlReturn_t  nvmlDeviceRemoveGpu_v2 ( nvmlPciInfo_t * pciInfo , nvmlDetachGpuState_t gpuState , nvmlPcieLinkState_t linkState ) ;
nvmlReturn_t  nvmlDeviceResetApplicationsClocks ( nvmlDevice_t device ) ;
nvmlReturn_t  nvmlDeviceResetGpuLockedClocks ( nvmlDevice_t device ) ;
nvmlReturn_t  nvmlDeviceResetMemoryLockedClocks ( nvmlDevice_t device ) ;
nvmlReturn_t  nvmlDeviceResetNvLinkErrorCounters ( nvmlDevice_t device , unsigned int link ) ;
nvmlReturn_t  nvmlDeviceResetNvLinkUtilizationCounter ( nvmlDevice_t device , unsigned int link , unsigned int counter ) ;
nvmlReturn_t  nvmlDeviceSetAPIRestriction ( nvmlDevice_t device , nvmlRestrictedAPI_t apiType , nvmlEnableState_t isRestricted ) ;
nvmlReturn_t  nvmlDeviceSetAccountingMode ( nvmlDevice_t device , nvmlEnableState_t mode ) ;
nvmlReturn_t  nvmlDeviceSetApplicationsClocks ( nvmlDevice_t device , unsigned int memClockMHz , unsigned int graphicsClockMHz ) ;
nvmlReturn_t  nvmlDeviceSetAutoBoostedClocksEnabled ( nvmlDevice_t device , nvmlEnableState_t enabled ) ;
nvmlReturn_t  nvmlDeviceSetComputeMode ( nvmlDevice_t device , nvmlComputeMode_t mode ) ;
nvmlReturn_t  nvmlDeviceSetCpuAffinity ( nvmlDevice_t device ) ;
nvmlReturn_t  nvmlDeviceSetDefaultAutoBoostedClocksEnabled ( nvmlDevice_t device , nvmlEnableState_t enabled , unsigned int flags ) ;
nvmlReturn_t  nvmlDeviceSetDefaultFanSpeed_v2 ( nvmlDevice_t device , unsigned int fan ) ;
nvmlReturn_t  nvmlDeviceSetDriverModel ( nvmlDevice_t device , nvmlDriverModel_t driverModel , unsigned int flags ) ;
nvmlReturn_t  nvmlDeviceSetEccMode ( nvmlDevice_t device , nvmlEnableState_t ecc ) ;
nvmlReturn_t  nvmlDeviceSetFanSpeed_v2 ( nvmlDevice_t device , unsigned int fan , unsigned int speed ) ;
nvmlReturn_t  nvmlDeviceSetGpcClkVfOffset ( nvmlDevice_t device , int vgpu_offset ) ;
nvmlReturn_t  nvmlDeviceSetGpuLockedClocks ( nvmlDevice_t device , unsigned int minGpuClockMHz , unsigned int maxGpuClockMHz ) ;
nvmlReturn_t  nvmlDeviceSetGpuOperationMode ( nvmlDevice_t device , nvmlGpuOperationMode_t mode ) ;
nvmlReturn_t  nvmlDeviceSetMemClkVfOffset ( nvmlDevice_t device , int vgpu_offset ) ;
nvmlReturn_t  nvmlDeviceSetMemoryLockedClocks ( nvmlDevice_t device , unsigned int minMemClockMHz , unsigned int maxMemClockMHz ) ;
nvmlReturn_t  nvmlDeviceSetMigMode ( nvmlDevice_t device , unsigned int mode , nvmlReturn_t * activationStatus ) ;
nvmlReturn_t  nvmlDeviceSetNvLinkUtilizationControl ( nvmlDevice_t device , unsigned int link , unsigned int counter , nvmlNvLinkUtilizationControl_t * control , unsigned int reset ) ;
nvmlReturn_t  nvmlDeviceSetPersistenceMode ( nvmlDevice_t device , nvmlEnableState_t mode ) ;
nvmlReturn_t  nvmlDeviceSetPowerManagementLimit ( nvmlDevice_t device , unsigned int limit ) ;
nvmlReturn_t  nvmlDeviceSetPowerMode ( nvmlDevice_t device , unsigned int powerModeId ) ;
nvmlReturn_t  nvmlDeviceSetTemperatureThreshold ( nvmlDevice_t device , nvmlTemperatureThresholds_t thresholdType , int * temp ) ;
nvmlReturn_t  nvmlDeviceSetVirtualizationMode ( nvmlDevice_t device , nvmlGpuVirtualizationMode_t virtualMode ) ;
nvmlReturn_t  nvmlDeviceValidateInforom ( nvmlDevice_t device ) ;
nvmlReturn_t  nvmlEventSetCreate ( nvmlEventSet_t * set ) ;
nvmlReturn_t  nvmlEventSetFree ( nvmlEventSet_t set ) ;
nvmlReturn_t  nvmlEventSetWait ( nvmlEventSet_t set , nvmlEventData_t * data , unsigned int timeoutms ) ;
nvmlReturn_t  nvmlEventSetWait_v2 ( nvmlEventSet_t set , nvmlEventData_t * data , unsigned int timeoutms ) ;
nvmlReturn_t  nvmlGetExcludedDeviceCount ( unsigned int * deviceCount ) ;
nvmlReturn_t  nvmlGetExcludedDeviceInfoByIndex ( unsigned int index , nvmlExcludedDeviceInfo_t * info ) ;
nvmlReturn_t  nvmlGetVgpuCompatibility ( nvmlVgpuMetadata_t * vgpuMetadata , nvmlVgpuPgpuMetadata_t * pgpuMetadata , nvmlVgpuPgpuCompatibility_t * compatibilityInfo ) ;
nvmlReturn_t  nvmlGetVgpuVersion ( nvmlVgpuVersion_t * supported , nvmlVgpuVersion_t * current ) ;
nvmlReturn_t  nvmlGpmMetricsGet ( nvmlGpmMetricsGet_t * metricsGet ) ;
nvmlReturn_t  nvmlGpmQueryDeviceSupport ( nvmlDevice_t device , nvmlGpmSupport_t * gpmSupport ) ;
nvmlReturn_t  nvmlGpmSampleAlloc ( nvmlGpmSample_t * gpmSample ) ;
nvmlReturn_t  nvmlGpmSampleFree ( nvmlGpmSample_t gpmSample ) ;
nvmlReturn_t  nvmlGpmSampleGet ( nvmlDevice_t device , nvmlGpmSample_t gpmSample ) ;
nvmlReturn_t  nvmlGpuInstanceCreateComputeInstance ( nvmlGpuInstance_t gpuInstance , unsigned int profileId , nvmlComputeInstance_t * computeInstance ) ;
nvmlReturn_t  nvmlGpuInstanceDestroy ( nvmlGpuInstance_t gpuInstance ) ;
nvmlReturn_t  nvmlGpuInstanceGetComputeInstanceById ( nvmlGpuInstance_t gpuInstance , unsigned int id , nvmlComputeInstance_t * computeInstance ) ;
nvmlReturn_t  nvmlGpuInstanceGetComputeInstanceProfileInfo ( nvmlGpuInstance_t gpuInstance , unsigned int profile , unsigned int engProfile , nvmlComputeInstanceProfileInfo_t * info ) ;
nvmlReturn_t  nvmlGpuInstanceGetComputeInstanceProfileInfoV ( nvmlGpuInstance_t gpuInstance , unsigned int profile , unsigned int engProfile , nvmlComputeInstanceProfileInfo_v2_t * info ) ;
nvmlReturn_t  nvmlGpuInstanceGetComputeInstanceRemainingCapacity ( nvmlGpuInstance_t gpuInstance , unsigned int profileId , unsigned int * count ) ;
nvmlReturn_t  nvmlGpuInstanceGetComputeInstances ( nvmlGpuInstance_t gpuInstance , unsigned int profileId , nvmlComputeInstance_t * computeInstances , unsigned int * count ) ;
nvmlReturn_t  nvmlGpuInstanceGetInfo ( nvmlGpuInstance_t gpuInstance , nvmlGpuInstanceInfo_t * info ) ;
nvmlReturn_t  nvmlInit ( void ) ;
nvmlReturn_t  nvmlInitWithFlags ( unsigned int flags ) ;
nvmlReturn_t  nvmlInit_v2 ( void ) ;
nvmlReturn_t  nvmlSetVgpuVersion ( nvmlVgpuVersion_t * vgpuVersion ) ;
nvmlReturn_t  nvmlShutdown ( void ) ;
nvmlReturn_t  nvmlSystemGetCudaDriverVersion ( int * cudaDriverVersion ) ;
nvmlReturn_t  nvmlSystemGetCudaDriverVersion_v2 ( int * cudaDriverVersion ) ;
nvmlReturn_t  nvmlSystemGetDriverVersion ( char * version , unsigned int length ) ;
nvmlReturn_t  nvmlSystemGetHicVersion ( unsigned int * hwbcCount , nvmlHwbcEntry_t * hwbcEntries ) ;
nvmlReturn_t  nvmlSystemGetNVMLVersion ( char * version , unsigned int length ) ;
nvmlReturn_t  nvmlSystemGetProcessName ( unsigned int pid , char * name , unsigned int length ) ;
nvmlReturn_t  nvmlSystemGetTopologyGpuSet ( unsigned int cpuNumber , unsigned int * count , nvmlDevice_t * deviceArray ) ;
nvmlReturn_t  nvmlUnitGetCount ( unsigned int * unitCount ) ;
nvmlReturn_t  nvmlUnitGetDevices ( nvmlUnit_t unit , unsigned int * deviceCount , nvmlDevice_t * devices ) ;
nvmlReturn_t  nvmlUnitGetFanSpeedInfo ( nvmlUnit_t unit , nvmlUnitFanSpeeds_t * fanSpeeds ) ;
nvmlReturn_t  nvmlUnitGetHandleByIndex ( unsigned int index , nvmlUnit_t * unit ) ;
nvmlReturn_t  nvmlUnitGetLedState ( nvmlUnit_t unit , nvmlLedState_t * state ) ;
nvmlReturn_t  nvmlUnitGetPsuInfo ( nvmlUnit_t unit , nvmlPSUInfo_t * psu ) ;
nvmlReturn_t  nvmlUnitGetTemperature ( nvmlUnit_t unit , unsigned int type , unsigned int * temp ) ;
nvmlReturn_t  nvmlUnitGetUnitInfo ( nvmlUnit_t unit , nvmlUnitInfo_t * info ) ;
nvmlReturn_t  nvmlUnitSetLedState ( nvmlUnit_t unit , nvmlLedColor_t color ) ;
nvmlReturn_t  nvmlVgpuInstanceClearAccountingPids ( nvmlVgpuInstance_t vgpuInstance ) ;
nvmlReturn_t  nvmlVgpuInstanceGetAccountingMode ( nvmlVgpuInstance_t vgpuInstance , nvmlEnableState_t * mode ) ;
nvmlReturn_t  nvmlVgpuInstanceGetAccountingPids ( nvmlVgpuInstance_t vgpuInstance , unsigned int * count , unsigned int * pids ) ;
nvmlReturn_t  nvmlVgpuInstanceGetAccountingStats ( nvmlVgpuInstance_t vgpuInstance , unsigned int pid , nvmlAccountingStats_t * stats ) ;
nvmlReturn_t  nvmlVgpuInstanceGetEccMode ( nvmlVgpuInstance_t vgpuInstance , nvmlEnableState_t * eccMode ) ;
nvmlReturn_t  nvmlVgpuInstanceGetEncoderCapacity ( nvmlVgpuInstance_t vgpuInstance , unsigned int * encoderCapacity ) ;
nvmlReturn_t  nvmlVgpuInstanceGetEncoderSessions ( nvmlVgpuInstance_t vgpuInstance , unsigned int * sessionCount , nvmlEncoderSessionInfo_t * sessionInfo ) ;
nvmlReturn_t  nvmlVgpuInstanceGetEncoderStats ( nvmlVgpuInstance_t vgpuInstance , unsigned int * sessionCount , unsigned int * averageFps , unsigned int * averageLatency ) ;
nvmlReturn_t  nvmlVgpuInstanceGetFBCSessions ( nvmlVgpuInstance_t vgpuInstance , unsigned int * sessionCount , nvmlFBCSessionInfo_t * sessionInfo ) ;
nvmlReturn_t  nvmlVgpuInstanceGetFBCStats ( nvmlVgpuInstance_t vgpuInstance , nvmlFBCStats_t * fbcStats ) ;
nvmlReturn_t  nvmlVgpuInstanceGetFbUsage ( nvmlVgpuInstance_t vgpuInstance , unsigned long long * fbUsage ) ;
nvmlReturn_t  nvmlVgpuInstanceGetFrameRateLimit ( nvmlVgpuInstance_t vgpuInstance , unsigned int * frameRateLimit ) ;
nvmlReturn_t  nvmlVgpuInstanceGetGpuInstanceId ( nvmlVgpuInstance_t vgpuInstance , unsigned int * gpuInstanceId ) ;
nvmlReturn_t  nvmlVgpuInstanceGetGpuPciId ( nvmlVgpuInstance_t vgpuInstance , char * vgpuPciId , unsigned int * length ) ;
nvmlReturn_t  nvmlVgpuInstanceGetLicenseInfo ( nvmlVgpuInstance_t vgpuInstance , nvmlVgpuLicenseInfo_t * licenseInfo ) ;
nvmlReturn_t  nvmlVgpuInstanceGetLicenseInfo_v2 ( nvmlVgpuInstance_t vgpuInstance , nvmlVgpuLicenseInfo_t * licenseInfo ) ;
nvmlReturn_t  nvmlVgpuInstanceGetLicenseStatus ( nvmlVgpuInstance_t vgpuInstance , unsigned int * licensed ) ;
nvmlReturn_t  nvmlVgpuInstanceGetMdevUUID ( nvmlVgpuInstance_t vgpuInstance , char * mdevUuid , unsigned int size ) ;
nvmlReturn_t  nvmlVgpuInstanceGetMetadata ( nvmlVgpuInstance_t vgpuInstance , nvmlVgpuMetadata_t * vgpuMetadata , unsigned int * bufferSize ) ;
nvmlReturn_t  nvmlVgpuInstanceGetType ( nvmlVgpuInstance_t vgpuInstance , nvmlVgpuTypeId_t * vgpuTypeId ) ;
nvmlReturn_t  nvmlVgpuInstanceGetUUID ( nvmlVgpuInstance_t vgpuInstance , char * uuid , unsigned int size ) ;
nvmlReturn_t  nvmlVgpuInstanceGetVmDriverVersion ( nvmlVgpuInstance_t vgpuInstance , char * version , unsigned int length ) ;
nvmlReturn_t  nvmlVgpuInstanceGetVmID ( nvmlVgpuInstance_t vgpuInstance , char * vmId , unsigned int size , nvmlVgpuVmIdType_t * vmIdType ) ;
nvmlReturn_t  nvmlVgpuInstanceSetEncoderCapacity ( nvmlVgpuInstance_t vgpuInstance , unsigned int encoderCapacity ) ;
nvmlReturn_t  nvmlVgpuTypeGetCapabilities ( nvmlVgpuTypeId_t vgpuTypeId , nvmlVgpuCapability_t capability , unsigned int * capResult ) ;
nvmlReturn_t  nvmlVgpuTypeGetClass ( nvmlVgpuTypeId_t vgpuTypeId , char * vgpuTypeClass , unsigned int * size ) ;
nvmlReturn_t  nvmlVgpuTypeGetDeviceID ( nvmlVgpuTypeId_t vgpuTypeId , unsigned long long * deviceID , unsigned long long * subsystemID ) ;
nvmlReturn_t  nvmlVgpuTypeGetFrameRateLimit ( nvmlVgpuTypeId_t vgpuTypeId , unsigned int * frameRateLimit ) ;
nvmlReturn_t  nvmlVgpuTypeGetFramebufferSize ( nvmlVgpuTypeId_t vgpuTypeId , unsigned long long * fbSize ) ;
nvmlReturn_t  nvmlVgpuTypeGetGpuInstanceProfileId ( nvmlVgpuTypeId_t vgpuTypeId , unsigned int * gpuInstanceProfileId ) ;
nvmlReturn_t  nvmlVgpuTypeGetLicense ( nvmlVgpuTypeId_t vgpuTypeId , char * vgpuTypeLicenseString , unsigned int size ) ;
nvmlReturn_t  nvmlVgpuTypeGetMaxInstances ( nvmlDevice_t device , nvmlVgpuTypeId_t vgpuTypeId , unsigned int * vgpuInstanceCount ) ;
nvmlReturn_t  nvmlVgpuTypeGetMaxInstancesPerVm ( nvmlVgpuTypeId_t vgpuTypeId , unsigned int * vgpuInstanceCountPerVm ) ;
nvmlReturn_t  nvmlVgpuTypeGetName ( nvmlVgpuTypeId_t vgpuTypeId , char * vgpuTypeName , unsigned int * size ) ;
nvmlReturn_t  nvmlVgpuTypeGetNumDisplayHeads ( nvmlVgpuTypeId_t vgpuTypeId , unsigned int * numDisplayHeads ) ;
nvmlReturn_t  nvmlVgpuTypeGetResolution ( nvmlVgpuTypeId_t vgpuTypeId , unsigned int displayIndex , unsigned int * xdim , unsigned int * ydim ) ;
nvmlReturn_t nvmlDeviceCcuGetStreamState ( nvmlDevice_t device , unsigned int * state ) ;
nvmlReturn_t nvmlDeviceCcuSetStreamState ( nvmlDevice_t device , unsigned int state ) ;
nvmlReturn_t nvmlDeviceClearFieldValues ( nvmlDevice_t device , int valuesCount , nvmlFieldValue_t * values ) ;
nvmlReturn_t nvmlDeviceGetGpuMaxPcieLinkGeneration ( nvmlDevice_t device , unsigned int * maxLinkGenDevice ) ;
nvmlReturn_t nvmlDeviceGetSupportedEventTypes ( nvmlDevice_t device , unsigned long long * eventTypes ) ;
nvmlReturn_t nvmlGpmMigSampleGet ( nvmlDevice_t device , unsigned int gpuInstanceId , nvmlGpmSample_t gpmSample ) ;
nvmlReturn_t nvmlGpuInstanceCreateComputeInstanceWithPlacement ( nvmlGpuInstance_t gpuInstance , unsigned int profileId , const nvmlComputeInstancePlacement_t * placement , nvmlComputeInstance_t * computeInstance ) ;
nvmlReturn_t nvmlGpuInstanceGetComputeInstancePossiblePlacements ( nvmlGpuInstance_t gpuInstance , unsigned int profileId , nvmlComputeInstancePlacement_t * placements , unsigned int * count ) ;
nvmlReturn_t nvmlInternalGetExportTable ( const void * * ppExportTable , void * pExportTableId ) ;

nvmlReturn_t nvmlComputeInstanceDestroy(nvmlComputeInstance_t computeInstance) {
    LINFO("Hijacking %s", "nvmlComputeInstanceDestroy");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlComputeInstanceDestroy, computeInstance);
}
nvmlReturn_t nvmlComputeInstanceGetInfo(nvmlComputeInstance_t computeInstance, nvmlComputeInstanceInfo_t * info) {
    LINFO("Hijacking %s", "nvmlComputeInstanceGetInfo");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlComputeInstanceGetInfo, computeInstance, info);
}
nvmlReturn_t nvmlComputeInstanceGetInfo_v2(nvmlComputeInstance_t computeInstance, nvmlComputeInstanceInfo_t * info) {
    LINFO("Hijacking %s", "nvmlComputeInstanceGetInfo_v2");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlComputeInstanceGetInfo_v2, computeInstance, info);
}
nvmlReturn_t nvmlDeviceClearAccountingPids(nvmlDevice_t device) {
    LINFO("Hijacking %s", "nvmlDeviceClearAccountingPids");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceClearAccountingPids, device);
}
nvmlReturn_t nvmlDeviceClearCpuAffinity(nvmlDevice_t device) {
    LINFO("Hijacking %s", "nvmlDeviceClearCpuAffinity");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceClearCpuAffinity, device);
}
nvmlReturn_t nvmlDeviceClearEccErrorCounts(nvmlDevice_t device, nvmlEccCounterType_t counterType) {
    LINFO("Hijacking %s", "nvmlDeviceClearEccErrorCounts");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceClearEccErrorCounts, device, counterType);
}
nvmlReturn_t nvmlDeviceCreateGpuInstance(nvmlDevice_t device, unsigned int profileId, nvmlGpuInstance_t * gpuInstance) {
    LINFO("Hijacking %s", "nvmlDeviceCreateGpuInstance");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceCreateGpuInstance, device, profileId, gpuInstance);
}
nvmlReturn_t nvmlDeviceCreateGpuInstanceWithPlacement(nvmlDevice_t device, unsigned int profileId, const nvmlGpuInstancePlacement_t * placement, nvmlGpuInstance_t * gpuInstance) {
    LINFO("Hijacking %s", "nvmlDeviceCreateGpuInstanceWithPlacement");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceCreateGpuInstanceWithPlacement, device, profileId, placement, gpuInstance);
}
nvmlReturn_t nvmlDeviceDiscoverGpus(nvmlPciInfo_t * pciInfo) {
    LINFO("Hijacking %s", "nvmlDeviceDiscoverGpus");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceDiscoverGpus, pciInfo);
}
nvmlReturn_t nvmlDeviceFreezeNvLinkUtilizationCounter(nvmlDevice_t device, unsigned int link, unsigned int counter, nvmlEnableState_t freeze) {
    LINFO("Hijacking %s", "nvmlDeviceFreezeNvLinkUtilizationCounter");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceFreezeNvLinkUtilizationCounter, device, link, counter, freeze);
}
nvmlReturn_t nvmlDeviceGetAPIRestriction(nvmlDevice_t device, nvmlRestrictedAPI_t apiType, nvmlEnableState_t * isRestricted) {
    LINFO("Hijacking %s", "nvmlDeviceGetAPIRestriction");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetAPIRestriction, device, apiType, isRestricted);
}
nvmlReturn_t nvmlDeviceGetAccountingBufferSize(nvmlDevice_t device, unsigned int * bufferSize) {
    LINFO("Hijacking %s", "nvmlDeviceGetAccountingBufferSize");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetAccountingBufferSize, device, bufferSize);
}
nvmlReturn_t nvmlDeviceGetAccountingMode(nvmlDevice_t device, nvmlEnableState_t * mode) {
    LINFO("Hijacking %s", "nvmlDeviceGetAccountingMode");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetAccountingMode, device, mode);
}
nvmlReturn_t nvmlDeviceGetAccountingPids(nvmlDevice_t device, unsigned int * count, unsigned int * pids) {
    LINFO("Hijacking %s", "nvmlDeviceGetAccountingPids");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetAccountingPids, device, count, pids);
}
nvmlReturn_t nvmlDeviceGetAccountingStats(nvmlDevice_t device, unsigned int pid, nvmlAccountingStats_t * stats) {
    LINFO("Hijacking %s", "nvmlDeviceGetAccountingStats");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetAccountingStats, device, pid, stats);
}
nvmlReturn_t nvmlDeviceGetActiveVgpus(nvmlDevice_t device, unsigned int * vgpuCount, nvmlVgpuInstance_t * vgpuInstances) {
    LINFO("Hijacking %s", "nvmlDeviceGetActiveVgpus");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetActiveVgpus, device, vgpuCount, vgpuInstances);
}
nvmlReturn_t nvmlDeviceGetApplicationsClock(nvmlDevice_t device, nvmlClockType_t clockType, unsigned int * clockMHz) {
    LINFO("Hijacking %s", "nvmlDeviceGetApplicationsClock");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetApplicationsClock, device, clockType, clockMHz);
}
nvmlReturn_t nvmlDeviceGetArchitecture(nvmlDevice_t device, nvmlDeviceArchitecture_t * arch) {
    LINFO("Hijacking %s", "nvmlDeviceGetArchitecture");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetArchitecture, device, arch);
}
nvmlReturn_t nvmlDeviceGetAttributes(nvmlDevice_t device, nvmlDeviceAttributes_t * attributes) {
    LINFO("Hijacking %s", "nvmlDeviceGetAttributes");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetAttributes, device, attributes);
}
nvmlReturn_t nvmlDeviceGetAttributes_v2(nvmlDevice_t device, nvmlDeviceAttributes_t * attributes) {
    LINFO("Hijacking %s", "nvmlDeviceGetAttributes_v2");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetAttributes_v2, device, attributes);
}
nvmlReturn_t nvmlDeviceGetAutoBoostedClocksEnabled(nvmlDevice_t device, nvmlEnableState_t * isEnabled, nvmlEnableState_t * defaultIsEnabled) {
    LINFO("Hijacking %s", "nvmlDeviceGetAutoBoostedClocksEnabled");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetAutoBoostedClocksEnabled, device, isEnabled, defaultIsEnabled);
}
nvmlReturn_t nvmlDeviceGetBAR1MemoryInfo(nvmlDevice_t device, nvmlBAR1Memory_t * bar1Memory) {
    LINFO("Hijacking %s", "nvmlDeviceGetBAR1MemoryInfo");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetBAR1MemoryInfo, device, bar1Memory);
}
nvmlReturn_t nvmlDeviceGetBoardId(nvmlDevice_t device, unsigned int * boardId) {
    LINFO("Hijacking %s", "nvmlDeviceGetBoardId");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetBoardId, device, boardId);
}
nvmlReturn_t nvmlDeviceGetBoardPartNumber(nvmlDevice_t device, char * partNumber, unsigned int length) {
    LINFO("Hijacking %s", "nvmlDeviceGetBoardPartNumber");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetBoardPartNumber, device, partNumber, length);
}
nvmlReturn_t nvmlDeviceGetBrand(nvmlDevice_t device, nvmlBrandType_t * type) {
    LINFO("Hijacking %s", "nvmlDeviceGetBrand");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetBrand, device, type);
}
nvmlReturn_t nvmlDeviceGetBridgeChipInfo(nvmlDevice_t device, nvmlBridgeChipHierarchy_t * bridgeHierarchy) {
    LINFO("Hijacking %s", "nvmlDeviceGetBridgeChipInfo");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetBridgeChipInfo, device, bridgeHierarchy);
}
nvmlReturn_t nvmlDeviceGetBusType(nvmlDevice_t device, nvmlBusType_t * type) {
    LINFO("Hijacking %s", "nvmlDeviceGetBusType");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetBusType, device, type);
}
nvmlReturn_t nvmlDeviceGetClkMonStatus(nvmlDevice_t device, nvmlClkMonStatus_t * status) {
    LINFO("Hijacking %s", "nvmlDeviceGetClkMonStatus");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetClkMonStatus, device, status);
}
nvmlReturn_t nvmlDeviceGetClock(nvmlDevice_t device, nvmlClockType_t clockType, nvmlClockId_t clockId, unsigned int * clockMHz) {
    LINFO("Hijacking %s", "nvmlDeviceGetClock");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetClock, device, clockType, clockId, clockMHz);
}
nvmlReturn_t nvmlDeviceGetClockInfo(nvmlDevice_t device, nvmlClockType_t type, unsigned int * clock) {
    LINFO("Hijacking %s", "nvmlDeviceGetClockInfo");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetClockInfo, device, type, clock);
}
nvmlReturn_t nvmlDeviceGetComputeInstanceId(nvmlDevice_t device, unsigned int * id) {
    LINFO("Hijacking %s", "nvmlDeviceGetComputeInstanceId");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetComputeInstanceId, device, id);
}
nvmlReturn_t nvmlDeviceGetComputeMode(nvmlDevice_t device, nvmlComputeMode_t * mode) {
    LINFO("Hijacking %s", "nvmlDeviceGetComputeMode");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetComputeMode, device, mode);
}
nvmlReturn_t nvmlDeviceGetComputeRunningProcesses_v2(nvmlDevice_t device, unsigned int * infoCount, nvmlProcessInfo_v2_t * infos) {
    LINFO("Hijacking %s", "nvmlDeviceGetComputeRunningProcesses_v2");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetComputeRunningProcesses_v2, device, infoCount, infos);
}
nvmlReturn_t nvmlDeviceGetCount(unsigned int * deviceCount) {
    LINFO("Hijacking %s", "nvmlDeviceGetCount");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetCount, deviceCount);
}
nvmlReturn_t nvmlDeviceGetCount_v2(unsigned int * deviceCount) {
    LINFO("Hijacking %s", "nvmlDeviceGetCount_v2");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetCount_v2, deviceCount);
}
nvmlReturn_t nvmlDeviceGetCpuAffinity(nvmlDevice_t device, unsigned int cpuSetSize, unsigned long * cpuSet) {
    LINFO("Hijacking %s", "nvmlDeviceGetCpuAffinity");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetCpuAffinity, device, cpuSetSize, cpuSet);
}
nvmlReturn_t nvmlDeviceGetCpuAffinityWithinScope(nvmlDevice_t device, unsigned int cpuSetSize, unsigned long * cpuSet, nvmlAffinityScope_t scope) {
    LINFO("Hijacking %s", "nvmlDeviceGetCpuAffinityWithinScope");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetCpuAffinityWithinScope, device, cpuSetSize, cpuSet, scope);
}
nvmlReturn_t nvmlDeviceGetCreatableVgpus(nvmlDevice_t device, unsigned int * vgpuCount, nvmlVgpuTypeId_t * vgpuTypeIds) {
    LINFO("Hijacking %s", "nvmlDeviceGetCreatableVgpus");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetCreatableVgpus, device, vgpuCount, vgpuTypeIds);
}
nvmlReturn_t nvmlDeviceGetCudaComputeCapability(nvmlDevice_t device, int * major, int * minor) {
    LINFO("Hijacking %s", "nvmlDeviceGetCudaComputeCapability");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetCudaComputeCapability, device, major, minor);
}
nvmlReturn_t nvmlDeviceGetCurrPcieLinkGeneration(nvmlDevice_t device, unsigned int * currLinkGen) {
    LINFO("Hijacking %s", "nvmlDeviceGetCurrPcieLinkGeneration");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetCurrPcieLinkGeneration, device, currLinkGen);
}
nvmlReturn_t nvmlDeviceGetCurrPcieLinkWidth(nvmlDevice_t device, unsigned int * currLinkWidth) {
    LINFO("Hijacking %s", "nvmlDeviceGetCurrPcieLinkWidth");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetCurrPcieLinkWidth, device, currLinkWidth);
}
nvmlReturn_t nvmlDeviceGetCurrentClocksThrottleReasons(nvmlDevice_t device, unsigned long long * clocksThrottleReasons) {
    LINFO("Hijacking %s", "nvmlDeviceGetCurrentClocksThrottleReasons");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetCurrentClocksThrottleReasons, device, clocksThrottleReasons);
}
nvmlReturn_t nvmlDeviceGetDecoderUtilization(nvmlDevice_t device, unsigned int * utilization, unsigned int * samplingPeriodUs) {
    LINFO("Hijacking %s", "nvmlDeviceGetDecoderUtilization");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetDecoderUtilization, device, utilization, samplingPeriodUs);
}
nvmlReturn_t nvmlDeviceGetDefaultApplicationsClock(nvmlDevice_t device, nvmlClockType_t clockType, unsigned int * clockMHz) {
    LINFO("Hijacking %s", "nvmlDeviceGetDefaultApplicationsClock");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetDefaultApplicationsClock, device, clockType, clockMHz);
}
nvmlReturn_t nvmlDeviceGetDetailedEccErrors(nvmlDevice_t device, nvmlMemoryErrorType_t errorType, nvmlEccCounterType_t counterType, nvmlEccErrorCounts_t * eccCounts) {
    LINFO("Hijacking %s", "nvmlDeviceGetDetailedEccErrors");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetDetailedEccErrors, device, errorType, counterType, eccCounts);
}
nvmlReturn_t nvmlDeviceGetDeviceHandleFromMigDeviceHandle(nvmlDevice_t migDevice, nvmlDevice_t * device) {
    LINFO("Hijacking %s", "nvmlDeviceGetDeviceHandleFromMigDeviceHandle");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetDeviceHandleFromMigDeviceHandle, migDevice, device);
}
nvmlReturn_t nvmlDeviceGetDisplayActive(nvmlDevice_t device, nvmlEnableState_t * isActive) {
    LINFO("Hijacking %s", "nvmlDeviceGetDisplayActive");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetDisplayActive, device, isActive);
}
nvmlReturn_t nvmlDeviceGetDisplayMode(nvmlDevice_t device, nvmlEnableState_t * display) {
    LINFO("Hijacking %s", "nvmlDeviceGetDisplayMode");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetDisplayMode, device, display);
}
nvmlReturn_t nvmlDeviceGetDriverModel(nvmlDevice_t device, nvmlDriverModel_t * current, nvmlDriverModel_t * pending) {
    LINFO("Hijacking %s", "nvmlDeviceGetDriverModel");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetDriverModel, device, current, pending);
}
nvmlReturn_t nvmlDeviceGetEccMode(nvmlDevice_t device, nvmlEnableState_t * current, nvmlEnableState_t * pending) {
    LINFO("Hijacking %s", "nvmlDeviceGetEccMode");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetEccMode, device, current, pending);
}
nvmlReturn_t nvmlDeviceGetEncoderCapacity(nvmlDevice_t device, nvmlEncoderType_t encoderQueryType, unsigned int * encoderCapacity) {
    LINFO("Hijacking %s", "nvmlDeviceGetEncoderCapacity");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetEncoderCapacity, device, encoderQueryType, encoderCapacity);
}
nvmlReturn_t nvmlDeviceGetEncoderSessions(nvmlDevice_t device, unsigned int * sessionCount, nvmlEncoderSessionInfo_t * sessionInfos) {
    LINFO("Hijacking %s", "nvmlDeviceGetEncoderSessions");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetEncoderSessions, device, sessionCount, sessionInfos);
}
nvmlReturn_t nvmlDeviceGetEncoderStats(nvmlDevice_t device, unsigned int * sessionCount, unsigned int * averageFps, unsigned int * averageLatency) {
    LINFO("Hijacking %s", "nvmlDeviceGetEncoderStats");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetEncoderStats, device, sessionCount, averageFps, averageLatency);
}
nvmlReturn_t nvmlDeviceGetEncoderUtilization(nvmlDevice_t device, unsigned int * utilization, unsigned int * samplingPeriodUs) {
    LINFO("Hijacking %s", "nvmlDeviceGetEncoderUtilization");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetEncoderUtilization, device, utilization, samplingPeriodUs);
}
nvmlReturn_t nvmlDeviceGetEnforcedPowerLimit(nvmlDevice_t device, unsigned int * limit) {
    LINFO("Hijacking %s", "nvmlDeviceGetEnforcedPowerLimit");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetEnforcedPowerLimit, device, limit);
}
nvmlReturn_t nvmlDeviceGetFBCSessions(nvmlDevice_t device, unsigned int * sessionCount, nvmlFBCSessionInfo_t * sessionInfo) {
    LINFO("Hijacking %s", "nvmlDeviceGetFBCSessions");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetFBCSessions, device, sessionCount, sessionInfo);
}
nvmlReturn_t nvmlDeviceGetFBCStats(nvmlDevice_t device, nvmlFBCStats_t * fbcStats) {
    LINFO("Hijacking %s", "nvmlDeviceGetFBCStats");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetFBCStats, device, fbcStats);
}
nvmlReturn_t nvmlDeviceGetFanSpeed(nvmlDevice_t device, unsigned int * speed) {
    LINFO("Hijacking %s", "nvmlDeviceGetFanSpeed");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetFanSpeed, device, speed);
}
nvmlReturn_t nvmlDeviceGetFanSpeed_v2(nvmlDevice_t device, unsigned int fan, unsigned int * speed) {
    LINFO("Hijacking %s", "nvmlDeviceGetFanSpeed_v2");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetFanSpeed_v2, device, fan, speed);
}
nvmlReturn_t nvmlDeviceGetFieldValues(nvmlDevice_t device, int valuesCount, nvmlFieldValue_t * values) {
    LINFO("Hijacking %s", "nvmlDeviceGetFieldValues");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetFieldValues, device, valuesCount, values);
}
nvmlReturn_t nvmlDeviceGetGpuInstanceById(nvmlDevice_t device, unsigned int id, nvmlGpuInstance_t * gpuInstance) {
    LINFO("Hijacking %s", "nvmlDeviceGetGpuInstanceById");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetGpuInstanceById, device, id, gpuInstance);
}
nvmlReturn_t nvmlDeviceGetGpuInstanceId(nvmlDevice_t device, unsigned int * id) {
    LINFO("Hijacking %s", "nvmlDeviceGetGpuInstanceId");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetGpuInstanceId, device, id);
}
nvmlReturn_t nvmlDeviceGetGpuInstancePossiblePlacements(nvmlDevice_t device, unsigned int profileId, nvmlGpuInstancePlacement_t * placements, unsigned int * count) {
    LINFO("Hijacking %s", "nvmlDeviceGetGpuInstancePossiblePlacements");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetGpuInstancePossiblePlacements, device, profileId, placements, count);
}
nvmlReturn_t nvmlDeviceGetGpuInstancePossiblePlacements_v2(nvmlDevice_t device, unsigned int profileId, nvmlGpuInstancePlacement_t * placements, unsigned int * count) {
    LINFO("Hijacking %s", "nvmlDeviceGetGpuInstancePossiblePlacements_v2");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetGpuInstancePossiblePlacements_v2, device, profileId, placements, count);
}
nvmlReturn_t nvmlDeviceGetGpuInstanceProfileInfo(nvmlDevice_t device, unsigned int profile, nvmlGpuInstanceProfileInfo_t * info) {
    LINFO("Hijacking %s", "nvmlDeviceGetGpuInstanceProfileInfo");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetGpuInstanceProfileInfo, device, profile, info);
}
nvmlReturn_t nvmlDeviceGetGpuInstanceRemainingCapacity(nvmlDevice_t device, unsigned int profileId, unsigned int * count) {
    LINFO("Hijacking %s", "nvmlDeviceGetGpuInstanceRemainingCapacity");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetGpuInstanceRemainingCapacity, device, profileId, count);
}
nvmlReturn_t nvmlDeviceGetGpuInstances(nvmlDevice_t device, unsigned int profileId, nvmlGpuInstance_t * gpuInstances, unsigned int * count) {
    LINFO("Hijacking %s", "nvmlDeviceGetGpuInstances");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetGpuInstances, device, profileId, gpuInstances, count);
}
nvmlReturn_t nvmlDeviceGetGpuOperationMode(nvmlDevice_t device, nvmlGpuOperationMode_t * current, nvmlGpuOperationMode_t * pending) {
    LINFO("Hijacking %s", "nvmlDeviceGetGpuOperationMode");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetGpuOperationMode, device, current, pending);
}
nvmlReturn_t nvmlDeviceGetGraphicsRunningProcesses(nvmlDevice_t device, unsigned int * infoCount, nvmlProcessInfo_v1_t * infos) {
    LINFO("Hijacking %s", "nvmlDeviceGetGraphicsRunningProcesses");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetGraphicsRunningProcesses, device, infoCount, infos);
}
nvmlReturn_t nvmlDeviceGetGraphicsRunningProcesses_v2(nvmlDevice_t device, unsigned int * infoCount, nvmlProcessInfo_v2_t * infos) {
    LINFO("Hijacking %s", "nvmlDeviceGetGraphicsRunningProcesses_v2");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetGraphicsRunningProcesses_v2, device, infoCount, infos);
}
nvmlReturn_t nvmlDeviceGetGridLicensableFeatures(nvmlDevice_t device, nvmlGridLicensableFeatures_t * pGridLicensableFeatures) {
    LINFO("Hijacking %s", "nvmlDeviceGetGridLicensableFeatures");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetGridLicensableFeatures, device, pGridLicensableFeatures);
}
nvmlReturn_t nvmlDeviceGetGridLicensableFeatures_v2(nvmlDevice_t device, nvmlGridLicensableFeatures_t * pGridLicensableFeatures) {
    LINFO("Hijacking %s", "nvmlDeviceGetGridLicensableFeatures_v2");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetGridLicensableFeatures_v2, device, pGridLicensableFeatures);
}
nvmlReturn_t nvmlDeviceGetGridLicensableFeatures_v3(nvmlDevice_t device, nvmlGridLicensableFeatures_t * pGridLicensableFeatures) {
    LINFO("Hijacking %s", "nvmlDeviceGetGridLicensableFeatures_v3");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetGridLicensableFeatures_v3, device, pGridLicensableFeatures);
}
nvmlReturn_t nvmlDeviceGetGridLicensableFeatures_v4(nvmlDevice_t device, nvmlGridLicensableFeatures_t * pGridLicensableFeatures) {
    LINFO("Hijacking %s", "nvmlDeviceGetGridLicensableFeatures_v4");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetGridLicensableFeatures_v4, device, pGridLicensableFeatures);
}
nvmlReturn_t nvmlDeviceGetHandleByIndex_v2(unsigned int index, nvmlDevice_t * device) {
    LINFO("Hijacking %s", "nvmlDeviceGetHandleByIndex_v2");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetHandleByIndex_v2, index, device);
}
nvmlReturn_t nvmlDeviceGetHandleByPciBusId(const char * pciBusId, nvmlDevice_t * device) {
    LINFO("Hijacking %s", "nvmlDeviceGetHandleByPciBusId");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetHandleByPciBusId, pciBusId, device);
}
nvmlReturn_t nvmlDeviceGetHandleBySerial(const char * serial, nvmlDevice_t * device) {
    LINFO("Hijacking %s", "nvmlDeviceGetHandleBySerial");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetHandleBySerial, serial, device);
}
nvmlReturn_t nvmlDeviceGetHandleByUUID(const char * uuid, nvmlDevice_t * device) {
    LINFO("Hijacking %s", "nvmlDeviceGetHandleByUUID");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetHandleByUUID, uuid, device);
}
nvmlReturn_t nvmlDeviceGetHostVgpuMode(nvmlDevice_t device, nvmlHostVgpuMode_t * pHostVgpuMode) {
    LINFO("Hijacking %s", "nvmlDeviceGetHostVgpuMode");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetHostVgpuMode, device, pHostVgpuMode);
}
nvmlReturn_t nvmlDeviceGetIndex(nvmlDevice_t device, unsigned int * index) {
    LINFO("Hijacking %s", "nvmlDeviceGetIndex");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetIndex, device, index);
}
nvmlReturn_t nvmlDeviceGetInforomConfigurationChecksum(nvmlDevice_t device, unsigned int * checksum) {
    LINFO("Hijacking %s", "nvmlDeviceGetInforomConfigurationChecksum");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetInforomConfigurationChecksum, device, checksum);
}
nvmlReturn_t nvmlDeviceGetInforomImageVersion(nvmlDevice_t device, char * version, unsigned int length) {
    LINFO("Hijacking %s", "nvmlDeviceGetInforomImageVersion");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetInforomImageVersion, device, version, length);
}
nvmlReturn_t nvmlDeviceGetInforomVersion(nvmlDevice_t device, nvmlInforomObject_t object, char * version, unsigned int length) {
    LINFO("Hijacking %s", "nvmlDeviceGetInforomVersion");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetInforomVersion, device, object, version, length);
}
nvmlReturn_t nvmlDeviceGetIrqNum(nvmlDevice_t device, unsigned int * irqNum) {
    LINFO("Hijacking %s", "nvmlDeviceGetIrqNum");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetIrqNum, device, irqNum);
}
nvmlReturn_t nvmlDeviceGetMPSComputeRunningProcesses(nvmlDevice_t device, unsigned int * infoCount, nvmlProcessInfo_v1_t * infos) {
    LINFO("Hijacking %s", "nvmlDeviceGetMPSComputeRunningProcesses");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMPSComputeRunningProcesses, device, infoCount, infos);
}
nvmlReturn_t nvmlDeviceGetMPSComputeRunningProcesses_v2(nvmlDevice_t device, unsigned int * infoCount, nvmlProcessInfo_v2_t * infos) {
    LINFO("Hijacking %s", "nvmlDeviceGetMPSComputeRunningProcesses_v2");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMPSComputeRunningProcesses_v2, device, infoCount, infos);
}
nvmlReturn_t nvmlDeviceGetMaxClockInfo(nvmlDevice_t device, nvmlClockType_t type, unsigned int * clock) {
    LINFO("Hijacking %s", "nvmlDeviceGetMaxClockInfo");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMaxClockInfo, device, type, clock);
}
nvmlReturn_t nvmlDeviceGetMaxCustomerBoostClock(nvmlDevice_t device, nvmlClockType_t clockType, unsigned int * clockMHz) {
    LINFO("Hijacking %s", "nvmlDeviceGetMaxCustomerBoostClock");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMaxCustomerBoostClock, device, clockType, clockMHz);
}
nvmlReturn_t nvmlDeviceGetMaxMigDeviceCount(nvmlDevice_t device, unsigned int * count) {
    LINFO("Hijacking %s", "nvmlDeviceGetMaxMigDeviceCount");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMaxMigDeviceCount, device, count);
}
nvmlReturn_t nvmlDeviceGetMaxPcieLinkGeneration(nvmlDevice_t device, unsigned int * maxLinkGen) {
    LINFO("Hijacking %s", "nvmlDeviceGetMaxPcieLinkGeneration");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMaxPcieLinkGeneration, device, maxLinkGen);
}
nvmlReturn_t nvmlDeviceGetMaxPcieLinkWidth(nvmlDevice_t device, unsigned int * maxLinkWidth) {
    LINFO("Hijacking %s", "nvmlDeviceGetMaxPcieLinkWidth");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMaxPcieLinkWidth, device, maxLinkWidth);
}
nvmlReturn_t nvmlDeviceGetMemoryAffinity(nvmlDevice_t device, unsigned int nodeSetSize, unsigned long * nodeSet, nvmlAffinityScope_t scope) {
    LINFO("Hijacking %s", "nvmlDeviceGetMemoryAffinity");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMemoryAffinity, device, nodeSetSize, nodeSet, scope);
}
nvmlReturn_t nvmlDeviceGetMemoryErrorCounter(nvmlDevice_t device, nvmlMemoryErrorType_t errorType, nvmlEccCounterType_t counterType, nvmlMemoryLocation_t locationType, unsigned long long * count) {
    LINFO("Hijacking %s", "nvmlDeviceGetMemoryErrorCounter");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMemoryErrorCounter, device, errorType, counterType, locationType, count);
}
nvmlReturn_t nvmlDeviceGetMemoryInfo(nvmlDevice_t device, nvmlMemory_t * memory) {
    LINFO("Hijacking %s", "nvmlDeviceGetMemoryInfo");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMemoryInfo, device, memory);
}
nvmlReturn_t nvmlDeviceGetMemoryInfo_v2(nvmlDevice_t device, nvmlMemory_v2_t * memory) {
    LINFO("Hijacking %s", "nvmlDeviceGetMemoryInfo_v2");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMemoryInfo_v2, device, memory);
}
nvmlReturn_t nvmlDeviceGetMigDeviceHandleByIndex(nvmlDevice_t device, unsigned int index, nvmlDevice_t * migDevice) {
    LINFO("Hijacking %s", "nvmlDeviceGetMigDeviceHandleByIndex");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMigDeviceHandleByIndex, device, index, migDevice);
}
nvmlReturn_t nvmlDeviceGetMigMode(nvmlDevice_t device, unsigned int * currentMode, unsigned int * pendingMode) {
    LINFO("Hijacking %s", "nvmlDeviceGetMigMode");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMigMode, device, currentMode, pendingMode);
}
nvmlReturn_t nvmlDeviceGetMinorNumber(nvmlDevice_t device, unsigned int * minorNumber) {
    LINFO("Hijacking %s", "nvmlDeviceGetMinorNumber");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMinorNumber, device, minorNumber);
}
nvmlReturn_t nvmlDeviceGetMultiGpuBoard(nvmlDevice_t device, unsigned int * multiGpuBool) {
    LINFO("Hijacking %s", "nvmlDeviceGetMultiGpuBoard");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetMultiGpuBoard, device, multiGpuBool);
}
nvmlReturn_t nvmlDeviceGetName(nvmlDevice_t device, char * name, unsigned int length) {
    LINFO("Hijacking %s", "nvmlDeviceGetName");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetName, device, name, length);
}
nvmlReturn_t nvmlDeviceGetNvLinkCapability(nvmlDevice_t device, unsigned int link, nvmlNvLinkCapability_t capability, unsigned int * capResult) {
    LINFO("Hijacking %s", "nvmlDeviceGetNvLinkCapability");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetNvLinkCapability, device, link, capability, capResult);
}
nvmlReturn_t nvmlDeviceGetNvLinkErrorCounter(nvmlDevice_t device, unsigned int link, nvmlNvLinkErrorCounter_t counter, unsigned long long * counterValue) {
    LINFO("Hijacking %s", "nvmlDeviceGetNvLinkErrorCounter");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetNvLinkErrorCounter, device, link, counter, counterValue);
}
nvmlReturn_t nvmlDeviceGetNvLinkRemoteDeviceType(nvmlDevice_t device, unsigned int link, nvmlIntNvLinkDeviceType_t * pNvLinkDeviceType) {
    LINFO("Hijacking %s", "nvmlDeviceGetNvLinkRemoteDeviceType");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetNvLinkRemoteDeviceType, device, link, pNvLinkDeviceType);
}
nvmlReturn_t nvmlDeviceGetNvLinkRemotePciInfo(nvmlDevice_t device, unsigned int link, nvmlPciInfo_t * pci) {
    LINFO("Hijacking %s", "nvmlDeviceGetNvLinkRemotePciInfo");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetNvLinkRemotePciInfo, device, link, pci);
}
nvmlReturn_t nvmlDeviceGetNvLinkRemotePciInfo_v2(nvmlDevice_t device, unsigned int link, nvmlPciInfo_t * pci) {
    LINFO("Hijacking %s", "nvmlDeviceGetNvLinkRemotePciInfo_v2");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetNvLinkRemotePciInfo_v2, device, link, pci);
}
nvmlReturn_t nvmlDeviceGetNvLinkState(nvmlDevice_t device, unsigned int link, nvmlEnableState_t * isActive) {
    LINFO("Hijacking %s", "nvmlDeviceGetNvLinkState");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetNvLinkState, device, link, isActive);
}
nvmlReturn_t nvmlDeviceGetNvLinkUtilizationControl(nvmlDevice_t device, unsigned int link, unsigned int counter, nvmlNvLinkUtilizationControl_t * control) {
    LINFO("Hijacking %s", "nvmlDeviceGetNvLinkUtilizationControl");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetNvLinkUtilizationControl, device, link, counter, control);
}
nvmlReturn_t nvmlDeviceGetNvLinkUtilizationCounter(nvmlDevice_t device, unsigned int link, unsigned int counter, unsigned long long * rxcounter, unsigned long long * txcounter) {
    LINFO("Hijacking %s", "nvmlDeviceGetNvLinkUtilizationCounter");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetNvLinkUtilizationCounter, device, link, counter, rxcounter, txcounter);
}
nvmlReturn_t nvmlDeviceGetNvLinkVersion(nvmlDevice_t device, unsigned int link, unsigned int * version) {
    LINFO("Hijacking %s", "nvmlDeviceGetNvLinkVersion");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetNvLinkVersion, device, link, version);
}
nvmlReturn_t nvmlDeviceGetP2PStatus(nvmlDevice_t device1, nvmlDevice_t device2, nvmlGpuP2PCapsIndex_t p2pIndex, nvmlGpuP2PStatus_t * p2pStatus) {
    LINFO("Hijacking %s", "nvmlDeviceGetP2PStatus");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetP2PStatus, device1, device2, p2pIndex, p2pStatus);
}
nvmlReturn_t nvmlDeviceGetPcieReplayCounter(nvmlDevice_t device, unsigned int * value) {
    LINFO("Hijacking %s", "nvmlDeviceGetPcieReplayCounter");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPcieReplayCounter, device, value);
}
nvmlReturn_t nvmlDeviceGetPcieThroughput(nvmlDevice_t device, nvmlPcieUtilCounter_t counter, unsigned int * value) {
    LINFO("Hijacking %s", "nvmlDeviceGetPcieThroughput");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPcieThroughput, device, counter, value);
}
nvmlReturn_t nvmlDeviceGetPerformanceState(nvmlDevice_t device, nvmlPstates_t * pState) {
    LINFO("Hijacking %s", "nvmlDeviceGetPerformanceState");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPerformanceState, device, pState);
}
nvmlReturn_t nvmlDeviceGetPersistenceMode(nvmlDevice_t device, nvmlEnableState_t * mode) {
    LINFO("Hijacking %s", "nvmlDeviceGetPersistenceMode");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPersistenceMode, device, mode);
}
nvmlReturn_t nvmlDeviceGetPgpuMetadataString(nvmlDevice_t device, char * pgpuMetadata, unsigned int * bufferSize) {
    LINFO("Hijacking %s", "nvmlDeviceGetPgpuMetadataString");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPgpuMetadataString, device, pgpuMetadata, bufferSize);
}
nvmlReturn_t nvmlDeviceGetPowerManagementDefaultLimit(nvmlDevice_t device, unsigned int * defaultLimit) {
    LINFO("Hijacking %s", "nvmlDeviceGetPowerManagementDefaultLimit");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPowerManagementDefaultLimit, device, defaultLimit);
}
nvmlReturn_t nvmlDeviceGetPowerManagementLimit(nvmlDevice_t device, unsigned int * limit) {
    LINFO("Hijacking %s", "nvmlDeviceGetPowerManagementLimit");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPowerManagementLimit, device, limit);
}
nvmlReturn_t nvmlDeviceGetPowerManagementLimitConstraints(nvmlDevice_t device, unsigned int * minLimit, unsigned int * maxLimit) {
    LINFO("Hijacking %s", "nvmlDeviceGetPowerManagementLimitConstraints");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPowerManagementLimitConstraints, device, minLimit, maxLimit);
}
nvmlReturn_t nvmlDeviceGetPowerManagementMode(nvmlDevice_t device, nvmlEnableState_t * mode) {
    LINFO("Hijacking %s", "nvmlDeviceGetPowerManagementMode");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPowerManagementMode, device, mode);
}
nvmlReturn_t nvmlDeviceGetPowerState(nvmlDevice_t device, nvmlPstates_t * pState) {
    LINFO("Hijacking %s", "nvmlDeviceGetPowerState");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPowerState, device, pState);
}
nvmlReturn_t nvmlDeviceGetPowerUsage(nvmlDevice_t device, unsigned int * power) {
    LINFO("Hijacking %s", "nvmlDeviceGetPowerUsage");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPowerUsage, device, power);
}
nvmlReturn_t nvmlDeviceGetRemappedRows(nvmlDevice_t device, unsigned int * corrRows, unsigned int * uncRows, unsigned int * isPending, unsigned int * failureOccurred) {
    LINFO("Hijacking %s", "nvmlDeviceGetRemappedRows");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetRemappedRows, device, corrRows, uncRows, isPending, failureOccurred);
}
nvmlReturn_t nvmlDeviceGetRetiredPages(nvmlDevice_t device, nvmlPageRetirementCause_t cause, unsigned int * pageCount, unsigned long long * addresses) {
    LINFO("Hijacking %s", "nvmlDeviceGetRetiredPages");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetRetiredPages, device, cause, pageCount, addresses);
}
nvmlReturn_t nvmlDeviceGetRetiredPagesPendingStatus(nvmlDevice_t device, nvmlEnableState_t * isPending) {
    LINFO("Hijacking %s", "nvmlDeviceGetRetiredPagesPendingStatus");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetRetiredPagesPendingStatus, device, isPending);
}
nvmlReturn_t nvmlDeviceGetRetiredPages_v2(nvmlDevice_t device, nvmlPageRetirementCause_t cause, unsigned int * pageCount, unsigned long long * addresses, unsigned long long * timestamps) {
    LINFO("Hijacking %s", "nvmlDeviceGetRetiredPages_v2");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetRetiredPages_v2, device, cause, pageCount, addresses, timestamps);
}
nvmlReturn_t nvmlDeviceGetRowRemapperHistogram(nvmlDevice_t device, nvmlRowRemapperHistogramValues_t * values) {
    LINFO("Hijacking %s", "nvmlDeviceGetRowRemapperHistogram");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetRowRemapperHistogram, device, values);
}
nvmlReturn_t nvmlDeviceGetSamples(nvmlDevice_t device, nvmlSamplingType_t type, unsigned long long lastSeenTimeStamp, nvmlValueType_t * sampleValType, unsigned int * sampleCount, nvmlSample_t * samples) {
    LINFO("Hijacking %s", "nvmlDeviceGetSamples");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetSamples, device, type, lastSeenTimeStamp, sampleValType, sampleCount, samples);
}
nvmlReturn_t nvmlDeviceGetSerial(nvmlDevice_t device, char * serial, unsigned int length) {
    LINFO("Hijacking %s", "nvmlDeviceGetSerial");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetSerial, device, serial, length);
}
nvmlReturn_t nvmlDeviceGetSupportedClocksThrottleReasons(nvmlDevice_t device, unsigned long long * supportedClocksThrottleReasons) {
    LINFO("Hijacking %s", "nvmlDeviceGetSupportedClocksThrottleReasons");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetSupportedClocksThrottleReasons, device, supportedClocksThrottleReasons);
}
nvmlReturn_t nvmlDeviceGetSupportedEventTypes(nvmlDevice_t device, unsigned long long * eventTypes) {
    LINFO("Hijacking %s", "nvmlDeviceGetSupportedEventTypes");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetSupportedEventTypes, device, eventTypes);
}
nvmlReturn_t nvmlDeviceGetSupportedGraphicsClocks(nvmlDevice_t device, unsigned int memoryClockMHz, unsigned int * count, unsigned int * clocksMHz) {
    LINFO("Hijacking %s", "nvmlDeviceGetSupportedGraphicsClocks");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetSupportedGraphicsClocks, device, memoryClockMHz, count, clocksMHz);
}
nvmlReturn_t nvmlDeviceGetSupportedMemoryClocks(nvmlDevice_t device, unsigned int * count, unsigned int * clocksMHz) {
    LINFO("Hijacking %s", "nvmlDeviceGetSupportedMemoryClocks");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetSupportedMemoryClocks, device, count, clocksMHz);
}
nvmlReturn_t nvmlDeviceGetSupportedVgpus(nvmlDevice_t device, unsigned int * vgpuCount, nvmlVgpuTypeId_t * vgpuTypeIds) {
    LINFO("Hijacking %s", "nvmlDeviceGetSupportedVgpus");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetSupportedVgpus, device, vgpuCount, vgpuTypeIds);
}
nvmlReturn_t nvmlDeviceGetTemperature(nvmlDevice_t device, nvmlTemperatureSensors_t sensorType, unsigned int * temp) {
    LINFO("Hijacking %s", "nvmlDeviceGetTemperature");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetTemperature, device, sensorType, temp);
}
nvmlReturn_t nvmlDeviceGetTemperatureThreshold(nvmlDevice_t device, nvmlTemperatureThresholds_t thresholdType, unsigned int * temp) {
    LINFO("Hijacking %s", "nvmlDeviceGetTemperatureThreshold");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetTemperatureThreshold, device, thresholdType, temp);
}
nvmlReturn_t nvmlDeviceGetTopologyCommonAncestor(nvmlDevice_t device1, nvmlDevice_t device2, nvmlGpuTopologyLevel_t * pathInfo) {
    LINFO("Hijacking %s", "nvmlDeviceGetTopologyCommonAncestor");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetTopologyCommonAncestor, device1, device2, pathInfo);
}
nvmlReturn_t nvmlDeviceGetTopologyNearestGpus(nvmlDevice_t device, nvmlGpuTopologyLevel_t level, unsigned int * count, nvmlDevice_t * deviceArray) {
    LINFO("Hijacking %s", "nvmlDeviceGetTopologyNearestGpus");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetTopologyNearestGpus, device, level, count, deviceArray);
}
nvmlReturn_t nvmlDeviceGetTotalEccErrors(nvmlDevice_t device, nvmlMemoryErrorType_t errorType, nvmlEccCounterType_t counterType, unsigned long long * eccCounts) {
    LINFO("Hijacking %s", "nvmlDeviceGetTotalEccErrors");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetTotalEccErrors, device, errorType, counterType, eccCounts);
}
nvmlReturn_t nvmlDeviceGetTotalEnergyConsumption(nvmlDevice_t device, unsigned long long * energy) {
    LINFO("Hijacking %s", "nvmlDeviceGetTotalEnergyConsumption");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetTotalEnergyConsumption, device, energy);
}
nvmlReturn_t nvmlDeviceGetUtilizationRates(nvmlDevice_t device, nvmlUtilization_t * utilization) {
    LINFO("Hijacking %s", "nvmlDeviceGetUtilizationRates");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetUtilizationRates, device, utilization);
}
nvmlReturn_t nvmlDeviceGetVbiosVersion(nvmlDevice_t device, char * version, unsigned int length) {
    LINFO("Hijacking %s", "nvmlDeviceGetVbiosVersion");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetVbiosVersion, device, version, length);
}
nvmlReturn_t nvmlDeviceGetVgpuMetadata(nvmlDevice_t device, nvmlVgpuPgpuMetadata_t * pgpuMetadata, unsigned int * bufferSize) {
    LINFO("Hijacking %s", "nvmlDeviceGetVgpuMetadata");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetVgpuMetadata, device, pgpuMetadata, bufferSize);
}
nvmlReturn_t nvmlDeviceGetVgpuProcessUtilization(nvmlDevice_t device, unsigned long long lastSeenTimeStamp, unsigned int * vgpuProcessSamplesCount, nvmlVgpuProcessUtilizationSample_t * utilizationSamples) {
    LINFO("Hijacking %s", "nvmlDeviceGetVgpuProcessUtilization");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetVgpuProcessUtilization, device, lastSeenTimeStamp, vgpuProcessSamplesCount, utilizationSamples);
}
nvmlReturn_t nvmlDeviceGetVgpuUtilization(nvmlDevice_t device, unsigned long long lastSeenTimeStamp, nvmlValueType_t * sampleValType, unsigned int * vgpuInstanceSamplesCount, nvmlVgpuInstanceUtilizationSample_t * utilizationSamples) {
    LINFO("Hijacking %s", "nvmlDeviceGetVgpuUtilization");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetVgpuUtilization, device, lastSeenTimeStamp, sampleValType, vgpuInstanceSamplesCount, utilizationSamples);
}
nvmlReturn_t nvmlDeviceGetViolationStatus(nvmlDevice_t device, nvmlPerfPolicyType_t perfPolicyType, nvmlViolationTime_t * violTime) {
    LINFO("Hijacking %s", "nvmlDeviceGetViolationStatus");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetViolationStatus, device, perfPolicyType, violTime);
}
nvmlReturn_t nvmlDeviceGetVirtualizationMode(nvmlDevice_t device, nvmlGpuVirtualizationMode_t * pVirtualMode) {
    LINFO("Hijacking %s", "nvmlDeviceGetVirtualizationMode");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetVirtualizationMode, device, pVirtualMode);
}
nvmlReturn_t nvmlDeviceIsMigDeviceHandle(nvmlDevice_t device, unsigned int * isMigDevice) {
    LINFO("Hijacking %s", "nvmlDeviceIsMigDeviceHandle");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceIsMigDeviceHandle, device, isMigDevice);
}
nvmlReturn_t nvmlDeviceModifyDrainState(nvmlPciInfo_t * pciInfo, nvmlEnableState_t newState) {
    LINFO("Hijacking %s", "nvmlDeviceModifyDrainState");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceModifyDrainState, pciInfo, newState);
}
nvmlReturn_t nvmlDeviceOnSameBoard(nvmlDevice_t device1, nvmlDevice_t device2, int * onSameBoard) {
    LINFO("Hijacking %s", "nvmlDeviceOnSameBoard");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceOnSameBoard, device1, device2, onSameBoard);
}
nvmlReturn_t nvmlDeviceQueryDrainState(nvmlPciInfo_t * pciInfo, nvmlEnableState_t * currentState) {
    LINFO("Hijacking %s", "nvmlDeviceQueryDrainState");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceQueryDrainState, pciInfo, currentState);
}
nvmlReturn_t nvmlDeviceRegisterEvents(nvmlDevice_t device, unsigned long long eventTypes, nvmlEventSet_t set) {
    LINFO("Hijacking %s", "nvmlDeviceRegisterEvents");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceRegisterEvents, device, eventTypes, set);
}
nvmlReturn_t nvmlDeviceRemoveGpu(nvmlPciInfo_t * pciInfo) {
    LINFO("Hijacking %s", "nvmlDeviceRemoveGpu");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceRemoveGpu, pciInfo);
}
nvmlReturn_t nvmlDeviceRemoveGpu_v2(nvmlPciInfo_t * pciInfo, nvmlDetachGpuState_t gpuState, nvmlPcieLinkState_t linkState) {
    LINFO("Hijacking %s", "nvmlDeviceRemoveGpu_v2");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceRemoveGpu_v2, pciInfo, gpuState, linkState);
}
nvmlReturn_t nvmlDeviceResetApplicationsClocks(nvmlDevice_t device) {
    LINFO("Hijacking %s", "nvmlDeviceResetApplicationsClocks");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceResetApplicationsClocks, device);
}
nvmlReturn_t nvmlDeviceResetGpuLockedClocks(nvmlDevice_t device) {
    LINFO("Hijacking %s", "nvmlDeviceResetGpuLockedClocks");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceResetGpuLockedClocks, device);
}
nvmlReturn_t nvmlDeviceResetMemoryLockedClocks(nvmlDevice_t device) {
    LINFO("Hijacking %s", "nvmlDeviceResetMemoryLockedClocks");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceResetMemoryLockedClocks, device);
}
nvmlReturn_t nvmlDeviceResetNvLinkErrorCounters(nvmlDevice_t device, unsigned int link) {
    LINFO("Hijacking %s", "nvmlDeviceResetNvLinkErrorCounters");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceResetNvLinkErrorCounters, device, link);
}
nvmlReturn_t nvmlDeviceResetNvLinkUtilizationCounter(nvmlDevice_t device, unsigned int link, unsigned int counter) {
    LINFO("Hijacking %s", "nvmlDeviceResetNvLinkUtilizationCounter");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceResetNvLinkUtilizationCounter, device, link, counter);
}
nvmlReturn_t nvmlDeviceSetAPIRestriction(nvmlDevice_t device, nvmlRestrictedAPI_t apiType, nvmlEnableState_t isRestricted) {
    LINFO("Hijacking %s", "nvmlDeviceSetAPIRestriction");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetAPIRestriction, device, apiType, isRestricted);
}
nvmlReturn_t nvmlDeviceSetAccountingMode(nvmlDevice_t device, nvmlEnableState_t mode) {
    LINFO("Hijacking %s", "nvmlDeviceSetAccountingMode");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetAccountingMode, device, mode);
}
nvmlReturn_t nvmlDeviceSetApplicationsClocks(nvmlDevice_t device, unsigned int memClockMHz, unsigned int graphicsClockMHz) {
    LINFO("Hijacking %s", "nvmlDeviceSetApplicationsClocks");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetApplicationsClocks, device, memClockMHz, graphicsClockMHz);
}
nvmlReturn_t nvmlDeviceSetAutoBoostedClocksEnabled(nvmlDevice_t device, nvmlEnableState_t enabled) {
    LINFO("Hijacking %s", "nvmlDeviceSetAutoBoostedClocksEnabled");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetAutoBoostedClocksEnabled, device, enabled);
}
nvmlReturn_t nvmlDeviceSetComputeMode(nvmlDevice_t device, nvmlComputeMode_t mode) {
    LINFO("Hijacking %s", "nvmlDeviceSetComputeMode");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetComputeMode, device, mode);
}
nvmlReturn_t nvmlDeviceSetCpuAffinity(nvmlDevice_t device) {
    LINFO("Hijacking %s", "nvmlDeviceSetCpuAffinity");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetCpuAffinity, device);
}
nvmlReturn_t nvmlDeviceSetDefaultAutoBoostedClocksEnabled(nvmlDevice_t device, nvmlEnableState_t enabled, unsigned int flags) {
    LINFO("Hijacking %s", "nvmlDeviceSetDefaultAutoBoostedClocksEnabled");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetDefaultAutoBoostedClocksEnabled, device, enabled, flags);
}
nvmlReturn_t nvmlDeviceSetDriverModel(nvmlDevice_t device, nvmlDriverModel_t driverModel, unsigned int flags) {
    LINFO("Hijacking %s", "nvmlDeviceSetDriverModel");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetDriverModel, device, driverModel, flags);
}
nvmlReturn_t nvmlDeviceSetEccMode(nvmlDevice_t device, nvmlEnableState_t ecc) {
    LINFO("Hijacking %s", "nvmlDeviceSetEccMode");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetEccMode, device, ecc);
}
nvmlReturn_t nvmlDeviceSetGpuLockedClocks(nvmlDevice_t device, unsigned int minGpuClockMHz, unsigned int maxGpuClockMHz) {
    LINFO("Hijacking %s", "nvmlDeviceSetGpuLockedClocks");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetGpuLockedClocks, device, minGpuClockMHz, maxGpuClockMHz);
}
nvmlReturn_t nvmlDeviceSetGpuOperationMode(nvmlDevice_t device, nvmlGpuOperationMode_t mode) {
    LINFO("Hijacking %s", "nvmlDeviceSetGpuOperationMode");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetGpuOperationMode, device, mode);
}
nvmlReturn_t nvmlDeviceSetMemoryLockedClocks(nvmlDevice_t device, unsigned int minMemClockMHz, unsigned int maxMemClockMHz) {
    LINFO("Hijacking %s", "nvmlDeviceSetMemoryLockedClocks");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetMemoryLockedClocks, device, minMemClockMHz, maxMemClockMHz);
}
nvmlReturn_t nvmlDeviceSetMigMode(nvmlDevice_t device, unsigned int mode, nvmlReturn_t * activationStatus) {
    LINFO("Hijacking %s", "nvmlDeviceSetMigMode");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetMigMode, device, mode, activationStatus);
}
nvmlReturn_t nvmlDeviceSetNvLinkUtilizationControl(nvmlDevice_t device, unsigned int link, unsigned int counter, nvmlNvLinkUtilizationControl_t * control, unsigned int reset) {
    LINFO("Hijacking %s", "nvmlDeviceSetNvLinkUtilizationControl");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetNvLinkUtilizationControl, device, link, counter, control, reset);
}
nvmlReturn_t nvmlDeviceSetPersistenceMode(nvmlDevice_t device, nvmlEnableState_t mode) {
    LINFO("Hijacking %s", "nvmlDeviceSetPersistenceMode");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetPersistenceMode, device, mode);
}
nvmlReturn_t nvmlDeviceSetPowerManagementLimit(nvmlDevice_t device, unsigned int limit) {
    LINFO("Hijacking %s", "nvmlDeviceSetPowerManagementLimit");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetPowerManagementLimit, device, limit);
}
nvmlReturn_t nvmlDeviceSetTemperatureThreshold(nvmlDevice_t device, nvmlTemperatureThresholds_t thresholdType, int * temp) {
    LINFO("Hijacking %s", "nvmlDeviceSetTemperatureThreshold");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetTemperatureThreshold, device, thresholdType, temp);
}
nvmlReturn_t nvmlDeviceSetVirtualizationMode(nvmlDevice_t device, nvmlGpuVirtualizationMode_t virtualMode) {
    LINFO("Hijacking %s", "nvmlDeviceSetVirtualizationMode");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceSetVirtualizationMode, device, virtualMode);
}
nvmlReturn_t nvmlDeviceValidateInforom(nvmlDevice_t device) {
    LINFO("Hijacking %s", "nvmlDeviceValidateInforom");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceValidateInforom, device);
}
nvmlReturn_t nvmlEventSetCreate(nvmlEventSet_t * set) {
    LINFO("Hijacking %s", "nvmlEventSetCreate");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlEventSetCreate, set);
}
nvmlReturn_t nvmlEventSetFree(nvmlEventSet_t set) {
    LINFO("Hijacking %s", "nvmlEventSetFree");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlEventSetFree, set);
}
nvmlReturn_t nvmlEventSetWait(nvmlEventSet_t set, nvmlEventData_t * data, unsigned int timeoutms) {
    LINFO("Hijacking %s", "nvmlEventSetWait");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlEventSetWait, set, data, timeoutms);
}
nvmlReturn_t nvmlEventSetWait_v2(nvmlEventSet_t set, nvmlEventData_t * data, unsigned int timeoutms) {
    LINFO("Hijacking %s", "nvmlEventSetWait_v2");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlEventSetWait_v2, set, data, timeoutms);
}
nvmlReturn_t nvmlGetExcludedDeviceCount(unsigned int * deviceCount) {
    LINFO("Hijacking %s", "nvmlGetExcludedDeviceCount");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlGetExcludedDeviceCount, deviceCount);
}
nvmlReturn_t nvmlGetExcludedDeviceInfoByIndex(unsigned int index, nvmlExcludedDeviceInfo_t * info) {
    LINFO("Hijacking %s", "nvmlGetExcludedDeviceInfoByIndex");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlGetExcludedDeviceInfoByIndex, index, info);
}
nvmlReturn_t nvmlGetVgpuCompatibility(nvmlVgpuMetadata_t * vgpuMetadata, nvmlVgpuPgpuMetadata_t * pgpuMetadata, nvmlVgpuPgpuCompatibility_t * compatibilityInfo) {
    LINFO("Hijacking %s", "nvmlGetVgpuCompatibility");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlGetVgpuCompatibility, vgpuMetadata, pgpuMetadata, compatibilityInfo);
}
nvmlReturn_t nvmlGetVgpuVersion(nvmlVgpuVersion_t * supported, nvmlVgpuVersion_t * current) {
    LINFO("Hijacking %s", "nvmlGetVgpuVersion");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlGetVgpuVersion, supported, current);
}
nvmlReturn_t nvmlGpuInstanceCreateComputeInstance(nvmlGpuInstance_t gpuInstance, unsigned int profileId, nvmlComputeInstance_t * computeInstance) {
    LINFO("Hijacking %s", "nvmlGpuInstanceCreateComputeInstance");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlGpuInstanceCreateComputeInstance, gpuInstance, profileId, computeInstance);
}
nvmlReturn_t nvmlGpuInstanceDestroy(nvmlGpuInstance_t gpuInstance) {
    LINFO("Hijacking %s", "nvmlGpuInstanceDestroy");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlGpuInstanceDestroy, gpuInstance);
}
nvmlReturn_t nvmlGpuInstanceGetComputeInstanceById(nvmlGpuInstance_t gpuInstance, unsigned int id, nvmlComputeInstance_t * computeInstance) {
    LINFO("Hijacking %s", "nvmlGpuInstanceGetComputeInstanceById");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlGpuInstanceGetComputeInstanceById, gpuInstance, id, computeInstance);
}
nvmlReturn_t nvmlGpuInstanceGetComputeInstanceProfileInfo(nvmlGpuInstance_t gpuInstance, unsigned int profile, unsigned int engProfile, nvmlComputeInstanceProfileInfo_t * info) {
    LINFO("Hijacking %s", "nvmlGpuInstanceGetComputeInstanceProfileInfo");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlGpuInstanceGetComputeInstanceProfileInfo, gpuInstance, profile, engProfile, info);
}
nvmlReturn_t nvmlGpuInstanceGetComputeInstanceRemainingCapacity(nvmlGpuInstance_t gpuInstance, unsigned int profileId, unsigned int * count) {
    LINFO("Hijacking %s", "nvmlGpuInstanceGetComputeInstanceRemainingCapacity");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlGpuInstanceGetComputeInstanceRemainingCapacity, gpuInstance, profileId, count);
}
nvmlReturn_t nvmlGpuInstanceGetComputeInstances(nvmlGpuInstance_t gpuInstance, unsigned int profileId, nvmlComputeInstance_t * computeInstances, unsigned int * count) {
    LINFO("Hijacking %s", "nvmlGpuInstanceGetComputeInstances");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlGpuInstanceGetComputeInstances, gpuInstance, profileId, computeInstances, count);
}
nvmlReturn_t nvmlGpuInstanceGetInfo(nvmlGpuInstance_t gpuInstance, nvmlGpuInstanceInfo_t * info) {
    LINFO("Hijacking %s", "nvmlGpuInstanceGetInfo");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlGpuInstanceGetInfo, gpuInstance, info);
}
nvmlReturn_t nvmlInternalGetExportTable(const void * * ppExportTable, void * pExportTableId) {
    LINFO("Hijacking %s", "nvmlInternalGetExportTable");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlInternalGetExportTable, ppExportTable, pExportTableId);
}
nvmlReturn_t nvmlSetVgpuVersion(nvmlVgpuVersion_t * vgpuVersion) {
    LINFO("Hijacking %s", "nvmlSetVgpuVersion");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlSetVgpuVersion, vgpuVersion);
}
nvmlReturn_t nvmlShutdown() {
    LINFO("Hijacking %s", "nvmlShutdown");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlShutdown, );
}
nvmlReturn_t nvmlSystemGetCudaDriverVersion(int * cudaDriverVersion) {
    LINFO("Hijacking %s", "nvmlSystemGetCudaDriverVersion");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlSystemGetCudaDriverVersion, cudaDriverVersion);
}
nvmlReturn_t nvmlSystemGetCudaDriverVersion_v2(int * cudaDriverVersion) {
    LINFO("Hijacking %s", "nvmlSystemGetCudaDriverVersion_v2");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlSystemGetCudaDriverVersion_v2, cudaDriverVersion);
}
nvmlReturn_t nvmlSystemGetDriverVersion(char * version, unsigned int length) {
    LINFO("Hijacking %s", "nvmlSystemGetDriverVersion");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlSystemGetDriverVersion, version, length);
}
nvmlReturn_t nvmlSystemGetHicVersion(unsigned int * hwbcCount, nvmlHwbcEntry_t * hwbcEntries) {
    LINFO("Hijacking %s", "nvmlSystemGetHicVersion");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlSystemGetHicVersion, hwbcCount, hwbcEntries);
}
nvmlReturn_t nvmlSystemGetNVMLVersion(char * version, unsigned int length) {
    LINFO("Hijacking %s", "nvmlSystemGetNVMLVersion");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlSystemGetNVMLVersion, version, length);
}
nvmlReturn_t nvmlSystemGetProcessName(unsigned int pid, char * name, unsigned int length) {
    LINFO("Hijacking %s", "nvmlSystemGetProcessName");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlSystemGetProcessName, pid, name, length);
}
nvmlReturn_t nvmlSystemGetTopologyGpuSet(unsigned int cpuNumber, unsigned int * count, nvmlDevice_t * deviceArray) {
    LINFO("Hijacking %s", "nvmlSystemGetTopologyGpuSet");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlSystemGetTopologyGpuSet, cpuNumber, count, deviceArray);
}
nvmlReturn_t nvmlUnitGetCount(unsigned int * unitCount) {
    LINFO("Hijacking %s", "nvmlUnitGetCount");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlUnitGetCount, unitCount);
}
nvmlReturn_t nvmlUnitGetDevices(nvmlUnit_t unit, unsigned int * deviceCount, nvmlDevice_t * devices) {
    LINFO("Hijacking %s", "nvmlUnitGetDevices");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlUnitGetDevices, unit, deviceCount, devices);
}
nvmlReturn_t nvmlUnitGetFanSpeedInfo(nvmlUnit_t unit, nvmlUnitFanSpeeds_t * fanSpeeds) {
    LINFO("Hijacking %s", "nvmlUnitGetFanSpeedInfo");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlUnitGetFanSpeedInfo, unit, fanSpeeds);
}
nvmlReturn_t nvmlUnitGetHandleByIndex(unsigned int index, nvmlUnit_t * unit) {
    LINFO("Hijacking %s", "nvmlUnitGetHandleByIndex");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlUnitGetHandleByIndex, index, unit);
}
nvmlReturn_t nvmlUnitGetLedState(nvmlUnit_t unit, nvmlLedState_t * state) {
    LINFO("Hijacking %s", "nvmlUnitGetLedState");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlUnitGetLedState, unit, state);
}
nvmlReturn_t nvmlUnitGetPsuInfo(nvmlUnit_t unit, nvmlPSUInfo_t * psu) {
    LINFO("Hijacking %s", "nvmlUnitGetPsuInfo");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlUnitGetPsuInfo, unit, psu);
}
nvmlReturn_t nvmlUnitGetTemperature(nvmlUnit_t unit, unsigned int type, unsigned int * temp) {
    LINFO("Hijacking %s", "nvmlUnitGetTemperature");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlUnitGetTemperature, unit, type, temp);
}
nvmlReturn_t nvmlUnitGetUnitInfo(nvmlUnit_t unit, nvmlUnitInfo_t * info) {
    LINFO("Hijacking %s", "nvmlUnitGetUnitInfo");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlUnitGetUnitInfo, unit, info);
}
nvmlReturn_t nvmlUnitSetLedState(nvmlUnit_t unit, nvmlLedColor_t color) {
    LINFO("Hijacking %s", "nvmlUnitSetLedState");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlUnitSetLedState, unit, color);
}
nvmlReturn_t nvmlVgpuInstanceClearAccountingPids(nvmlVgpuInstance_t vgpuInstance) {
    LINFO("Hijacking %s", "nvmlVgpuInstanceClearAccountingPids");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceClearAccountingPids, vgpuInstance);
}
nvmlReturn_t nvmlVgpuInstanceGetAccountingMode(nvmlVgpuInstance_t vgpuInstance, nvmlEnableState_t * mode) {
    LINFO("Hijacking %s", "nvmlVgpuInstanceGetAccountingMode");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetAccountingMode, vgpuInstance, mode);
}
nvmlReturn_t nvmlVgpuInstanceGetAccountingPids(nvmlVgpuInstance_t vgpuInstance, unsigned int * count, unsigned int * pids) {
    LINFO("Hijacking %s", "nvmlVgpuInstanceGetAccountingPids");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetAccountingPids, vgpuInstance, count, pids);
}
nvmlReturn_t nvmlVgpuInstanceGetAccountingStats(nvmlVgpuInstance_t vgpuInstance, unsigned int pid, nvmlAccountingStats_t * stats) {
    LINFO("Hijacking %s", "nvmlVgpuInstanceGetAccountingStats");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetAccountingStats, vgpuInstance, pid, stats);
}
nvmlReturn_t nvmlVgpuInstanceGetEccMode(nvmlVgpuInstance_t vgpuInstance, nvmlEnableState_t * eccMode) {
    LINFO("Hijacking %s", "nvmlVgpuInstanceGetEccMode");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetEccMode, vgpuInstance, eccMode);
}
nvmlReturn_t nvmlVgpuInstanceGetEncoderCapacity(nvmlVgpuInstance_t vgpuInstance, unsigned int * encoderCapacity) {
    LINFO("Hijacking %s", "nvmlVgpuInstanceGetEncoderCapacity");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetEncoderCapacity, vgpuInstance, encoderCapacity);
}
nvmlReturn_t nvmlVgpuInstanceGetEncoderSessions(nvmlVgpuInstance_t vgpuInstance, unsigned int * sessionCount, nvmlEncoderSessionInfo_t * sessionInfo) {
    LINFO("Hijacking %s", "nvmlVgpuInstanceGetEncoderSessions");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetEncoderSessions, vgpuInstance, sessionCount, sessionInfo);
}
nvmlReturn_t nvmlVgpuInstanceGetEncoderStats(nvmlVgpuInstance_t vgpuInstance, unsigned int * sessionCount, unsigned int * averageFps, unsigned int * averageLatency) {
    LINFO("Hijacking %s", "nvmlVgpuInstanceGetEncoderStats");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetEncoderStats, vgpuInstance, sessionCount, averageFps, averageLatency);
}
nvmlReturn_t nvmlVgpuInstanceGetFBCSessions(nvmlVgpuInstance_t vgpuInstance, unsigned int * sessionCount, nvmlFBCSessionInfo_t * sessionInfo) {
    LINFO("Hijacking %s", "nvmlVgpuInstanceGetFBCSessions");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetFBCSessions, vgpuInstance, sessionCount, sessionInfo);
}
nvmlReturn_t nvmlVgpuInstanceGetFBCStats(nvmlVgpuInstance_t vgpuInstance, nvmlFBCStats_t * fbcStats) {
    LINFO("Hijacking %s", "nvmlVgpuInstanceGetFBCStats");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetFBCStats, vgpuInstance, fbcStats);
}
nvmlReturn_t nvmlVgpuInstanceGetFbUsage(nvmlVgpuInstance_t vgpuInstance, unsigned long long * fbUsage) {
    LINFO("Hijacking %s", "nvmlVgpuInstanceGetFbUsage");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetFbUsage, vgpuInstance, fbUsage);
}
nvmlReturn_t nvmlVgpuInstanceGetFrameRateLimit(nvmlVgpuInstance_t vgpuInstance, unsigned int * frameRateLimit) {
    LINFO("Hijacking %s", "nvmlVgpuInstanceGetFrameRateLimit");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetFrameRateLimit, vgpuInstance, frameRateLimit);
}
nvmlReturn_t nvmlVgpuInstanceGetGpuInstanceId(nvmlVgpuInstance_t vgpuInstance, unsigned int * gpuInstanceId) {
    LINFO("Hijacking %s", "nvmlVgpuInstanceGetGpuInstanceId");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetGpuInstanceId, vgpuInstance, gpuInstanceId);
}
nvmlReturn_t nvmlVgpuInstanceGetLicenseInfo(nvmlVgpuInstance_t vgpuInstance, nvmlVgpuLicenseInfo_t * licenseInfo) {
    LINFO("Hijacking %s", "nvmlVgpuInstanceGetLicenseInfo");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetLicenseInfo, vgpuInstance, licenseInfo);
}
nvmlReturn_t nvmlVgpuInstanceGetLicenseStatus(nvmlVgpuInstance_t vgpuInstance, unsigned int * licensed) {
    LINFO("Hijacking %s", "nvmlVgpuInstanceGetLicenseStatus");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetLicenseStatus, vgpuInstance, licensed);
}
nvmlReturn_t nvmlVgpuInstanceGetMdevUUID(nvmlVgpuInstance_t vgpuInstance, char * mdevUuid, unsigned int size) {
    LINFO("Hijacking %s", "nvmlVgpuInstanceGetMdevUUID");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetMdevUUID, vgpuInstance, mdevUuid, size);
}
nvmlReturn_t nvmlVgpuInstanceGetMetadata(nvmlVgpuInstance_t vgpuInstance, nvmlVgpuMetadata_t * vgpuMetadata, unsigned int * bufferSize) {
    LINFO("Hijacking %s", "nvmlVgpuInstanceGetMetadata");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetMetadata, vgpuInstance, vgpuMetadata, bufferSize);
}
nvmlReturn_t nvmlVgpuInstanceGetType(nvmlVgpuInstance_t vgpuInstance, nvmlVgpuTypeId_t * vgpuTypeId) {
    LINFO("Hijacking %s", "nvmlVgpuInstanceGetType");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetType, vgpuInstance, vgpuTypeId);
}
nvmlReturn_t nvmlVgpuInstanceGetUUID(nvmlVgpuInstance_t vgpuInstance, char * uuid, unsigned int size) {
    LINFO("Hijacking %s", "nvmlVgpuInstanceGetUUID");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetUUID, vgpuInstance, uuid, size);
}
nvmlReturn_t nvmlVgpuInstanceGetVmDriverVersion(nvmlVgpuInstance_t vgpuInstance, char * version, unsigned int length) {
    LINFO("Hijacking %s", "nvmlVgpuInstanceGetVmDriverVersion");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetVmDriverVersion, vgpuInstance, version, length);
}
nvmlReturn_t nvmlVgpuInstanceGetVmID(nvmlVgpuInstance_t vgpuInstance, char * vmId, unsigned int size, nvmlVgpuVmIdType_t * vmIdType) {
    LINFO("Hijacking %s", "nvmlVgpuInstanceGetVmID");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceGetVmID, vgpuInstance, vmId, size, vmIdType);
}
nvmlReturn_t nvmlVgpuInstanceSetEncoderCapacity(nvmlVgpuInstance_t vgpuInstance, unsigned int encoderCapacity) {
    LINFO("Hijacking %s", "nvmlVgpuInstanceSetEncoderCapacity");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuInstanceSetEncoderCapacity, vgpuInstance, encoderCapacity);
}
nvmlReturn_t nvmlVgpuTypeGetClass(nvmlVgpuTypeId_t vgpuTypeId, char * vgpuTypeClass, unsigned int * size) {
    LINFO("Hijacking %s", "nvmlVgpuTypeGetClass");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuTypeGetClass, vgpuTypeId, vgpuTypeClass, size);
}
nvmlReturn_t nvmlVgpuTypeGetDeviceID(nvmlVgpuTypeId_t vgpuTypeId, unsigned long long * deviceID, unsigned long long * subsystemID) {
    LINFO("Hijacking %s", "nvmlVgpuTypeGetDeviceID");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuTypeGetDeviceID, vgpuTypeId, deviceID, subsystemID);
}
nvmlReturn_t nvmlVgpuTypeGetFrameRateLimit(nvmlVgpuTypeId_t vgpuTypeId, unsigned int * frameRateLimit) {
    LINFO("Hijacking %s", "nvmlVgpuTypeGetFrameRateLimit");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuTypeGetFrameRateLimit, vgpuTypeId, frameRateLimit);
}
nvmlReturn_t nvmlVgpuTypeGetFramebufferSize(nvmlVgpuTypeId_t vgpuTypeId, unsigned long long * fbSize) {
    LINFO("Hijacking %s", "nvmlVgpuTypeGetFramebufferSize");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuTypeGetFramebufferSize, vgpuTypeId, fbSize);
}
nvmlReturn_t nvmlVgpuTypeGetGpuInstanceProfileId(nvmlVgpuTypeId_t vgpuTypeId, unsigned int * gpuInstanceProfileId) {
    LINFO("Hijacking %s", "nvmlVgpuTypeGetGpuInstanceProfileId");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuTypeGetGpuInstanceProfileId, vgpuTypeId, gpuInstanceProfileId);
}
nvmlReturn_t nvmlVgpuTypeGetLicense(nvmlVgpuTypeId_t vgpuTypeId, char * vgpuTypeLicenseString, unsigned int size) {
    LINFO("Hijacking %s", "nvmlVgpuTypeGetLicense");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuTypeGetLicense, vgpuTypeId, vgpuTypeLicenseString, size);
}
nvmlReturn_t nvmlVgpuTypeGetMaxInstances(nvmlDevice_t device, nvmlVgpuTypeId_t vgpuTypeId, unsigned int * vgpuInstanceCount) {
    LINFO("Hijacking %s", "nvmlVgpuTypeGetMaxInstances");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuTypeGetMaxInstances, device, vgpuTypeId, vgpuInstanceCount);
}
nvmlReturn_t nvmlVgpuTypeGetMaxInstancesPerVm(nvmlVgpuTypeId_t vgpuTypeId, unsigned int * vgpuInstanceCountPerVm) {
    LINFO("Hijacking %s", "nvmlVgpuTypeGetMaxInstancesPerVm");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuTypeGetMaxInstancesPerVm, vgpuTypeId, vgpuInstanceCountPerVm);
}
nvmlReturn_t nvmlVgpuTypeGetName(nvmlVgpuTypeId_t vgpuTypeId, char * vgpuTypeName, unsigned int * size) {
    LINFO("Hijacking %s", "nvmlVgpuTypeGetName");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuTypeGetName, vgpuTypeId, vgpuTypeName, size);
}
nvmlReturn_t nvmlVgpuTypeGetNumDisplayHeads(nvmlVgpuTypeId_t vgpuTypeId, unsigned int * numDisplayHeads) {
    LINFO("Hijacking %s", "nvmlVgpuTypeGetNumDisplayHeads");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuTypeGetNumDisplayHeads, vgpuTypeId, numDisplayHeads);
}
nvmlReturn_t nvmlVgpuTypeGetResolution(nvmlVgpuTypeId_t vgpuTypeId, unsigned int displayIndex, unsigned int * xdim, unsigned int * ydim) {
    LINFO("Hijacking %s", "nvmlVgpuTypeGetResolution");
    return NVML_ENTRY_CALL(nvml_library_entry, nvmlVgpuTypeGetResolution, vgpuTypeId, displayIndex, xdim, ydim);
}