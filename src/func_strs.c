char *CUDA_FUNCS[1024] = {
    "cuInit", "cudbgMain", "cudbgGetAPIVersion", "cuArray3DGetDescriptor_v2", "cudbgGetAPI", "cuGetProcAddress_v2_alt", "cuMemAddressFree", "cuMemRelease", "cuMemoryAllocate", "cuDeviceGetAttribute", "cuMemUnmap", "cuMemoryFree", "cuUnmapMemory", "cuMemSetAccess", "cuDeviceGet", "cuDeviceGetCount", "cuDeviceGetName", "cuDeviceCanAccessPeer", "cuDeviceGetP2PAttribute", "cuDeviceGetByPCIBusId", "cuDeviceGetPCIBusId", "cuDeviceGetUuid", "cuDeviceGetDefaultMemPool", "cuDeviceGetLuid", "cuDeviceGetMemPool", "cuDeviceTotalMem_v2", "cuDriverGetVersion", "cuDeviceGetTexture1DLinearMaxWidth", "cuDeviceSetMemPool", "cuFlushGPUDirectRDMAWrites", "cuDevicePrimaryCtxGetState", "cuDevicePrimaryCtxRetain", "cuDevicePrimaryCtxSetFlags_v2", "cuDevicePrimaryCtxRelease", "cuDevicePrimaryCtxRelease_v2", "cuCtxGetDevice", "cuCtxCreate_v2", "cuCtxDestroy_v2", "cuCtxGetApiVersion", "cuCtxGetCacheConfig", "cuCtxGetCurrent", "cuCtxGetFlags", "cuCtxGetLimit", "cuCtxGetSharedMemConfig", "cuCtxGetStreamPriorityRange", "cuCtxPopCurrent", "cuCtxPopCurrent_v2", "cuCtxPushCurrent", "cuCtxPushCurrent_v2", "cuCtxSetCacheConfig", "cuCtxSetCurrent", "cuCtxSetLimit", "cuCtxSetSharedMemConfig", "cuCtxSynchronize", "cuGetExportTable", "cuStreamCreate", "cuStreamDestroy_v2", "cuStreamSynchronize", "cuArray3DCreate_v2", "cuArrayCreate_v2", "cuArrayDestroy", "cuMemAlloc_v2", "cuMemAllocHost_v2", "cuMemAllocManaged", "cuMemAllocPitch_v2", "cuMemFree_v2", "cuMemFreeHost", "cuMemHostAlloc", "cuMemHostRegister_v2", "cuMemHostUnregister", "cuMemcpyDtoH_v2", "cuMemcpyHtoD_v2", "cuMipmappedArrayCreate", "cuMipmappedArrayDestroy", "cuMemGetInfo_v2", "cuMemcpy", "cuPointerGetAttribute", "cuPointerGetAttributes", "cuPointerSetAttribute", "cuIpcCloseMemHandle", "cuIpcGetMemHandle", "cuIpcOpenMemHandle_v2", "cuMemGetAddressRange_v2", "cuMemcpyAsync", "cuMemcpyAtoD_v2", "cuMemcpyDtoA_v2", "cuMemcpyDtoD_v2", "cuMemcpyDtoDAsync_v2", "cuMemcpyDtoHAsync_v2", "cuMemcpyHtoDAsync_v2", "cuMemcpyPeer", "cuMemcpyPeerAsync", "cuMemsetD16_v2", "cuMemsetD16Async", "cuMemsetD2D16_v2", "cuMemsetD2D16Async", "cuMemsetD2D32_v2", "cuMemsetD2D32Async", "cuMemsetD2D8_v2", "cuMemsetD2D8Async", "cuMemsetD32_v2", "cuMemsetD32Async", "cuMemsetD8_v2", "cuMemsetD8Async", "cuMemAdvise", "cuFuncSetCacheConfig", "cuFuncSetSharedMemConfig", "cuFuncGetAttribute", "cuFuncSetAttribute", "cuLaunchKernel", "cuLaunchCooperativeKernel", "cuEventCreate", "cuEventDestroy_v2", "cuModuleLoad", "cuModuleLoadData", "cuModuleLoadDataEx", "cuModuleLoadFatBinary", "cuModuleGetFunction", "cuModuleUnload", "cuModuleGetGlobal_v2", "cuModuleGetTexRef", "cuModuleGetSurfRef", "cuLinkAddData_v2", "cuLinkCreate_v2", "cuLinkAddFile_v2", "cuLinkComplete", "cuLinkDestroy", "cuMemAddressReserve", "cuMemCreate", "cuMemMap", "cuMemAllocAsync", "cuMemHostGetDevicePointer_v2", "cuMemHostGetFlags", "cuMemPoolTrimTo", "cuMemPoolSetAttribute", "cuMemPoolGetAttribute", "cuMemPoolSetAccess", "cuMemPoolGetAccess", "cuMemPoolCreate", "cuMemPoolDestroy", "cuMemAllocFromPoolAsync", "cuMemPoolExportToShareableHandle", "cuMemPoolImportFromShareableHandle", "cuMemPoolExportPointer", "cuMemPoolImportPointer", "cuMemcpy2DUnaligned_v2", "cuMemcpy2DAsync_v2", "cuMemcpy3D_v2", "cuMemcpy3DAsync_v2", "cuMemcpy3DPeer", "cuMemcpy3DPeerAsync", "cuMemPrefetchAsync", "cuMemRangeGetAttribute", "cuMemRangeGetAttributes", "cuImportExternalMemory", "cuExternalMemoryGetMappedBuffer", "cuExternalMemoryGetMappedMipmappedArray", "cuDestroyExternalMemory", "cuImportExternalSemaphore", "cuSignalExternalSemaphoresAsync", "cuWaitExternalSemaphoresAsync", "cuDestroyExternalSemaphore", "cuGraphCreate", "cuGraphAddKernelNode_v2", "cuGraphKernelNodeGetParams_v2", "cuGraphKernelNodeSetParams_v2", "cuGraphAddMemcpyNode", "cuGraphMemcpyNodeGetParams", "cuGraphMemcpyNodeSetParams", "cuGraphAddMemsetNode", "cuGraphMemsetNodeGetParams", "cuGraphMemsetNodeSetParams", "cuGraphAddHostNode", "cuGraphHostNodeGetParams", "cuGraphHostNodeSetParams", "cuGraphAddChildGraphNode", "cuGraphChildGraphNodeGetGraph", "cuGraphAddEmptyNode", "cuGraphAddEventRecordNode", "cuGraphEventRecordNodeGetEvent", "cuGraphEventRecordNodeSetEvent", "cuGraphAddEventWaitNode", "cuGraphEventWaitNodeGetEvent", "cuGraphEventWaitNodeSetEvent", "cuGraphAddExternalSemaphoresSignalNode", "cuGraphExternalSemaphoresSignalNodeGetParams", "cuGraphExternalSemaphoresSignalNodeSetParams", "cuGraphAddExternalSemaphoresWaitNode", "cuGraphExternalSemaphoresWaitNodeGetParams", "cuGraphExternalSemaphoresWaitNodeSetParams", "cuGraphExecExternalSemaphoresSignalNodeSetParams", "cuGraphExecExternalSemaphoresWaitNodeSetParams", "cuGraphClone", "cuGraphNodeFindInClone", "cuGraphNodeGetType", "cuGraphGetNodes", "cuGraphGetRootNodes", "cuGraphGetEdges", "cuGraphNodeGetDependencies", "cuGraphNodeGetDependentNodes", "cuGraphAddDependencies", "cuGraphRemoveDependencies", "cuGraphDestroyNode", "cuGraphInstantiate", "cuGraphInstantiateWithFlags", "cuGraphUpload", "cuGraphLaunch", "cuGraphExecDestroy", "cuGraphDestroy", "cuGetProcAddress", "cuGetProcAddress_v2", "cuGetErrorString", "cuMemGetAllocationGranularity", "cuModuleGetLoadingMode", "cuEventRecordWithFlags", "cuGetErrorName", "cuOccupancyMaxActiveBlocksPerMultiprocessor", "cuDevicePrimaryCtxReset", "cuLaunchKernelEx",
};
char *NVML_FUNCS[1024] = {
    "nvmlInit", "nvmlShutdown", "nvmlErrorString", "nvmlDeviceGetHandleByIndex", "nvmlDeviceGetComputeRunningProcesses", "nvmlDeviceGetPciInfo", "nvmlDeviceGetProcessUtilization", "nvmlDeviceGetCount", "nvmlDeviceClearAccountingPids", "nvmlDeviceClearCpuAffinity", "nvmlDeviceClearEccErrorCounts", "nvmlDeviceDiscoverGpus", "nvmlDeviceFreezeNvLinkUtilizationCounter", "nvmlDeviceGetAccountingBufferSize", "nvmlDeviceGetAccountingMode", "nvmlDeviceGetAccountingPids", "nvmlDeviceGetAccountingStats", "nvmlDeviceGetActiveVgpus", "nvmlDeviceGetAPIRestriction", "nvmlDeviceGetApplicationsClock", "nvmlDeviceGetAutoBoostedClocksEnabled", "nvmlDeviceGetBAR1MemoryInfo", "nvmlDeviceGetBoardId", "nvmlDeviceGetBoardPartNumber", "nvmlDeviceGetBrand", "nvmlDeviceGetBridgeChipInfo", "nvmlDeviceGetClock", "nvmlDeviceGetClockInfo", "nvmlDeviceGetComputeMode", "nvmlDeviceGetCount_v2", "nvmlDeviceGetCpuAffinity", "nvmlDeviceGetCreatableVgpus", "nvmlDeviceGetCudaComputeCapability", "nvmlDeviceGetCurrentClocksThrottleReasons", "nvmlDeviceGetCurrPcieLinkGeneration", "nvmlDeviceGetCurrPcieLinkWidth", "nvmlDeviceGetDecoderUtilization", "nvmlDeviceGetDefaultApplicationsClock", "nvmlDeviceGetDetailedEccErrors", "nvmlDeviceGetDisplayActive", "nvmlDeviceGetDisplayMode", "nvmlDeviceGetDriverModel", "nvmlDeviceGetEccMode", "nvmlDeviceGetEncoderCapacity", "nvmlDeviceGetEncoderSessions", "nvmlDeviceGetEncoderStats", "nvmlDeviceGetEncoderUtilization", "nvmlDeviceGetEnforcedPowerLimit", "nvmlDeviceGetFanSpeed", "nvmlDeviceGetFanSpeed_v2", "nvmlDeviceGetFieldValues", "nvmlDeviceGetGpuOperationMode", "nvmlDeviceGetGraphicsRunningProcesses", "nvmlDeviceGetGridLicensableFeatures", "nvmlDeviceGetHandleByIndex_v2", "nvmlDeviceGetHandleByPciBusId", "nvmlDeviceGetHandleByPciBusId_v2", "nvmlDeviceGetHandleBySerial", "nvmlDeviceGetHandleByUUID", "nvmlDeviceGetIndex", "nvmlDeviceGetInforomConfigurationChecksum", "nvmlDeviceGetInforomImageVersion", "nvmlDeviceGetInforomVersion", "nvmlDeviceGetMaxClockInfo", "nvmlDeviceGetMaxCustomerBoostClock", "nvmlDeviceGetMaxPcieLinkGeneration", "nvmlDeviceGetMaxPcieLinkWidth", "nvmlDeviceGetMemoryErrorCounter", "nvmlDeviceGetMemoryInfo", "nvmlDeviceGetMemoryInfo_v2", "nvmlDeviceGetMinorNumber", "nvmlDeviceGetMPSComputeRunningProcesses", "nvmlDeviceGetMultiGpuBoard", "nvmlDeviceGetName", "nvmlDeviceGetNvLinkCapability", "nvmlDeviceGetNvLinkErrorCounter", "nvmlDeviceGetNvLinkRemotePciInfo", "nvmlDeviceGetNvLinkRemotePciInfo_v2", "nvmlDeviceGetNvLinkState", "nvmlDeviceGetNvLinkUtilizationControl", "nvmlDeviceGetNvLinkUtilizationCounter", "nvmlDeviceGetNvLinkVersion", "nvmlDeviceGetP2PStatus", "nvmlDeviceGetPcieReplayCounter", "nvmlDeviceGetPcieThroughput", "nvmlDeviceGetPciInfo_v2", "nvmlDeviceGetPciInfo_v3", "nvmlDeviceGetPerformanceState", "nvmlDeviceGetPersistenceMode", "nvmlDeviceGetPowerManagementDefaultLimit", "nvmlDeviceGetPowerManagementLimit", "nvmlDeviceGetPowerManagementLimitConstraints", "nvmlDeviceGetPowerManagementMode", "nvmlDeviceGetPowerState", "nvmlDeviceGetPowerUsage", "nvmlDeviceGetRetiredPages", "nvmlDeviceGetRetiredPagesPendingStatus", "nvmlDeviceGetSamples", "nvmlDeviceGetSerial", "nvmlDeviceGetSupportedClocksThrottleReasons", "nvmlDeviceGetSupportedEventTypes", "nvmlDeviceGetSupportedGraphicsClocks", "nvmlDeviceGetSupportedMemoryClocks", "nvmlDeviceGetSupportedVgpus", "nvmlDeviceGetTemperature", "nvmlDeviceGetTemperatureThreshold", "nvmlDeviceGetTopologyCommonAncestor", "nvmlDeviceGetTopologyNearestGpus", "nvmlDeviceGetTotalEccErrors", "nvmlDeviceGetTotalEnergyConsumption", "nvmlDeviceGetUtilizationRates", "nvmlDeviceGetUUID", "nvmlDeviceGetVbiosVersion", "nvmlDeviceGetVgpuMetadata", "nvmlDeviceGetVgpuProcessUtilization", "nvmlDeviceGetVgpuUtilization", "nvmlDeviceGetViolationStatus", "nvmlDeviceGetVirtualizationMode", "nvmlDeviceModifyDrainState", "nvmlDeviceOnSameBoard", "nvmlDeviceQueryDrainState", "nvmlDeviceRegisterEvents", "nvmlDeviceRemoveGpu", "nvmlDeviceRemoveGpu_v2", "nvmlDeviceResetApplicationsClocks", "nvmlDeviceResetNvLinkErrorCounters", "nvmlDeviceResetNvLinkUtilizationCounter", "nvmlDeviceSetAccountingMode", "nvmlDeviceSetAPIRestriction", "nvmlDeviceSetApplicationsClocks", "nvmlDeviceSetAutoBoostedClocksEnabled", "nvmlDeviceSetComputeMode", "nvmlDeviceSetCpuAffinity", "nvmlDeviceSetDefaultAutoBoostedClocksEnabled", "nvmlDeviceSetDriverModel", "nvmlDeviceSetEccMode", "nvmlDeviceSetGpuOperationMode", "nvmlDeviceSetNvLinkUtilizationControl", "nvmlDeviceSetPersistenceMode", "nvmlDeviceSetPowerManagementLimit", "nvmlDeviceSetVirtualizationMode", "nvmlDeviceValidateInforom", "nvmlEventSetCreate", "nvmlEventSetFree", "nvmlEventSetWait", "nvmlGetVgpuCompatibility", "nvmlInit_v2", "nvmlInitWithFlags", "nvmlInternalGetExportTable", "nvmlSystemGetCudaDriverVersion", "nvmlSystemGetCudaDriverVersion_v2", "nvmlSystemGetDriverVersion", "nvmlSystemGetHicVersion", "nvmlSystemGetNVMLVersion", "nvmlSystemGetProcessName", "nvmlSystemGetTopologyGpuSet", "nvmlUnitGetCount", "nvmlUnitGetDevices", "nvmlUnitGetFanSpeedInfo", "nvmlUnitGetHandleByIndex", "nvmlUnitGetLedState", "nvmlUnitGetPsuInfo", "nvmlUnitGetTemperature", "nvmlUnitGetUnitInfo", "nvmlUnitSetLedState", "nvmlVgpuInstanceGetEncoderCapacity", "nvmlVgpuInstanceGetEncoderSessions", "nvmlVgpuInstanceGetEncoderStats", "nvmlVgpuInstanceGetFbUsage", "nvmlVgpuInstanceGetFrameRateLimit", "nvmlVgpuInstanceGetLicenseStatus", "nvmlVgpuInstanceGetMetadata", "nvmlVgpuInstanceGetType", "nvmlVgpuInstanceGetUUID", "nvmlVgpuInstanceGetVmDriverVersion", "nvmlVgpuInstanceGetVmID", "nvmlVgpuInstanceSetEncoderCapacity", "nvmlVgpuTypeGetClass", "nvmlVgpuTypeGetDeviceID", "nvmlVgpuTypeGetFramebufferSize", "nvmlVgpuTypeGetFrameRateLimit", "nvmlVgpuTypeGetLicense", "nvmlVgpuTypeGetMaxInstances", "nvmlVgpuTypeGetName", "nvmlVgpuTypeGetNumDisplayHeads", "nvmlVgpuTypeGetResolution", "nvmlDeviceGetFBCSessions", "nvmlDeviceGetFBCStats", "nvmlDeviceGetGridLicensableFeatures_v2", "nvmlDeviceGetRetiredPages_v2", "nvmlDeviceResetGpuLockedClocks", "nvmlDeviceSetGpuLockedClocks", "nvmlVgpuInstanceGetAccountingMode", "nvmlVgpuInstanceGetAccountingPids", "nvmlVgpuInstanceGetAccountingStats", "nvmlVgpuInstanceGetFBCSessions", "nvmlVgpuInstanceGetFBCStats", "nvmlVgpuTypeGetMaxInstancesPerVm", "nvmlGetVgpuVersion", "nvmlSetVgpuVersion", "nvmlDeviceGetGridLicensableFeatures_v3", "nvmlDeviceGetHostVgpuMode", "nvmlDeviceGetPgpuMetadataString", "nvmlVgpuInstanceGetEccMode", "nvmlComputeInstanceDestroy", "nvmlComputeInstanceGetInfo", "nvmlDeviceCreateGpuInstance", "nvmlDeviceGetArchitecture", "nvmlDeviceGetAttributes", "nvmlDeviceGetAttributes_v2", "nvmlDeviceGetComputeInstanceId", "nvmlDeviceGetCpuAffinityWithinScope", "nvmlDeviceGetDeviceHandleFromMigDeviceHandle", "nvmlDeviceGetGpuInstanceById", "nvmlDeviceGetGpuInstanceId", "nvmlDeviceGetGpuInstancePossiblePlacements", "nvmlDeviceGetGpuInstanceProfileInfo", "nvmlDeviceGetGpuInstanceRemainingCapacity", "nvmlDeviceGetGpuInstances", "nvmlDeviceGetMaxMigDeviceCount", "nvmlDeviceGetMemoryAffinity", "nvmlDeviceGetMigDeviceHandleByIndex", "nvmlDeviceGetMigMode", "nvmlDeviceGetRemappedRows", "nvmlDeviceGetRowRemapperHistogram", "nvmlDeviceIsMigDeviceHandle", "nvmlDeviceSetMigMode", "nvmlEventSetWait_v2", "nvmlGpuInstanceCreateComputeInstance", "nvmlGpuInstanceDestroy", "nvmlGpuInstanceGetComputeInstanceById", "nvmlGpuInstanceGetComputeInstanceProfileInfo", "nvmlGpuInstanceGetComputeInstanceRemainingCapacity", "nvmlGpuInstanceGetComputeInstances", "nvmlGpuInstanceGetInfo", "nvmlVgpuInstanceClearAccountingPids", "nvmlVgpuInstanceGetMdevUUID", "nvmlComputeInstanceGetInfo_v2", "nvmlDeviceGetComputeRunningProcesses_v2", "nvmlDeviceGetGraphicsRunningProcesses_v2", "nvmlDeviceSetTemperatureThreshold", "nvmlVgpuInstanceGetGpuInstanceId", "nvmlVgpuTypeGetGpuInstanceProfileId",
};
