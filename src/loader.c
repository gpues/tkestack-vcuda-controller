/*
 * Tencent is pleased to support the open source community by making TKEStack available.
 *
 * Copyright (C) 2012-2019 Tencent. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not use
 * this file except in compliance with the License. You may obtain a copy of the
 * License at
 *
 * https://opensource.org/licenses/Apache-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OF ANY KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations under the License.
 */

//
// Created by thomas on 6/15/18.
//
#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <regex.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include "include/auto-cuda-helper.h"
#include "include/auto-nvml-helper.h"
#include "include/json/cJSON.h"

entry_t cuda_library_entry[] = {
    {.name = "cuInit"},
    {.name = "cuDeviceGet"},
    {.name = "cuDeviceGetCount"},
    {.name = "cuDeviceGetName"},
    {.name = "cuDeviceTotalMem_v2"},
    {.name = "cuDeviceGetAttribute"},
    {.name = "cuDeviceGetP2PAttribute"},
    {.name = "cuDriverGetVersion"},
    {.name = "cuDeviceGetByPCIBusId"},
    {.name = "cuDeviceGetPCIBusId"},
    {.name = "cuDevicePrimaryCtxRetain"},
    {.name = "cuDevicePrimaryCtxRelease"},
    {.name = "cuDevicePrimaryCtxSetFlags"},
    {.name = "cuDevicePrimaryCtxGetState"},
    {.name = "cuDevicePrimaryCtxReset"},
    {.name = "cuCtxCreate_v2"},
    {.name = "cuCtxGetFlags"},
    {.name = "cuCtxSetCurrent"},
    {.name = "cuCtxGetCurrent"},
    {.name = "cuCtxDetach"},
    {.name = "cuCtxGetApiVersion"},
    {.name = "cuCtxGetDevice"},
    {.name = "cuCtxGetLimit"},
    {.name = "cuCtxSetLimit"},
    {.name = "cuCtxGetCacheConfig"},
    {.name = "cuCtxSetCacheConfig"},
    {.name = "cuCtxGetSharedMemConfig"},
    {.name = "cuCtxGetStreamPriorityRange"},
    {.name = "cuCtxSetSharedMemConfig"},
    {.name = "cuCtxSynchronize"},
    {.name = "cuModuleLoad"},
    {.name = "cuModuleLoadData"},
    {.name = "cuModuleLoadFatBinary"},
    {.name = "cuModuleUnload"},
    {.name = "cuModuleGetFunction"},
    {.name = "cuModuleGetGlobal_v2"},
    {.name = "cuModuleGetTexRef"},
    {.name = "cuModuleGetSurfRef"},
    {.name = "cuLinkCreate"},
    {.name = "cuLinkAddData"},
    {.name = "cuLinkAddFile"},
    {.name = "cuLinkComplete"},
    {.name = "cuLinkDestroy"},
    {.name = "cuMemGetInfo_v2"},
    {.name = "cuMemAllocManaged"},
    {.name = "cuMemAlloc_v2"},
    {.name = "cuMemAllocPitch_v2"},
    {.name = "cuMemFree_v2"},
    {.name = "cuMemGetAddressRange_v2"},
    {.name = "cuMemFreeHost"},
    {.name = "cuMemHostAlloc"},
    {.name = "cuMemHostGetDevicePointer_v2"},
    {.name = "cuMemHostGetFlags"},
    {.name = "cuMemHostRegister_v2"},
    {.name = "cuMemHostUnregister"},
    {.name = "cuPointerGetAttribute"},
    {.name = "cuPointerGetAttributes"},
    {.name = "cuMemcpy"},
    {.name = "cuMemcpy_ptds"},
    {.name = "cuMemcpyAsync"},
    {.name = "cuMemcpyAsync_ptsz"},
    {.name = "cuMemcpyPeer"},
    {.name = "cuMemcpyPeer_ptds"},
    {.name = "cuMemcpyPeerAsync"},
    {.name = "cuMemcpyPeerAsync_ptsz"},
    {.name = "cuMemcpyHtoD_v2"},
    {.name = "cuMemcpyHtoD_v2_ptds"},
    {.name = "cuMemcpyHtoDAsync_v2"},
    {.name = "cuMemcpyHtoDAsync_v2_ptsz"},
    {.name = "cuMemcpyDtoH_v2"},
    {.name = "cuMemcpyDtoH_v2_ptds"},
    {.name = "cuMemcpyDtoHAsync_v2"},
    {.name = "cuMemcpyDtoHAsync_v2_ptsz"},
    {.name = "cuMemcpyDtoD_v2"},
    {.name = "cuMemcpyDtoD_v2_ptds"},
    {.name = "cuMemcpyDtoDAsync_v2"},
    {.name = "cuMemcpyDtoDAsync_v2_ptsz"},
    {.name = "cuMemcpy2DUnaligned_v2"},
    {.name = "cuMemcpy2DUnaligned_v2_ptds"},
    {.name = "cuMemcpy2DAsync_v2"},
    {.name = "cuMemcpy2DAsync_v2_ptsz"},
    {.name = "cuMemcpy3D_v2"},
    {.name = "cuMemcpy3D_v2_ptds"},
    {.name = "cuMemcpy3DAsync_v2"},
    {.name = "cuMemcpy3DAsync_v2_ptsz"},
    {.name = "cuMemcpy3DPeer"},
    {.name = "cuMemcpy3DPeer_ptds"},
    {.name = "cuMemcpy3DPeerAsync"},
    {.name = "cuMemcpy3DPeerAsync_ptsz"},
    {.name = "cuMemsetD8_v2"},
    {.name = "cuMemsetD8_v2_ptds"},
    {.name = "cuMemsetD8Async"},
    {.name = "cuMemsetD8Async_ptsz"},
    {.name = "cuMemsetD2D8_v2"},
    {.name = "cuMemsetD2D8_v2_ptds"},
    {.name = "cuMemsetD2D8Async"},
    {.name = "cuMemsetD2D8Async_ptsz"},
    {.name = "cuFuncSetCacheConfig"},
    {.name = "cuFuncSetSharedMemConfig"},
    {.name = "cuFuncGetAttribute"},
    {.name = "cuArrayCreate_v2"},
    {.name = "cuArrayGetDescriptor_v2"},
    {.name = "cuArray3DCreate_v2"},
    {.name = "cuArray3DGetDescriptor_v2"},
    {.name = "cuArrayDestroy"},
    {.name = "cuMipmappedArrayCreate"},
    {.name = "cuMipmappedArrayGetLevel"},
    {.name = "cuMipmappedArrayDestroy"},
    {.name = "cuTexRefCreate"},
    {.name = "cuTexRefDestroy"},
    {.name = "cuTexRefSetArray"},
    {.name = "cuTexRefSetMipmappedArray"},
    {.name = "cuTexRefSetAddress_v2"},
    {.name = "cuTexRefSetAddress2D_v3"},
    {.name = "cuTexRefSetFormat"},
    {.name = "cuTexRefSetAddressMode"},
    {.name = "cuTexRefSetFilterMode"},
    {.name = "cuTexRefSetMipmapFilterMode"},
    {.name = "cuTexRefSetMipmapLevelBias"},
    {.name = "cuTexRefSetMipmapLevelClamp"},
    {.name = "cuTexRefSetMaxAnisotropy"},
    {.name = "cuTexRefSetFlags"},
    {.name = "cuTexRefSetBorderColor"},
    {.name = "cuTexRefGetBorderColor"},
    {.name = "cuSurfRefSetArray"},
    {.name = "cuTexObjectCreate"},
    {.name = "cuTexObjectDestroy"},
    {.name = "cuTexObjectGetResourceDesc"},
    {.name = "cuTexObjectGetTextureDesc"},
    {.name = "cuTexObjectGetResourceViewDesc"},
    {.name = "cuSurfObjectCreate"},
    {.name = "cuSurfObjectDestroy"},
    {.name = "cuSurfObjectGetResourceDesc"},
    {.name = "cuLaunchKernel"},
    {.name = "cuLaunchKernel_ptsz"},
    {.name = "cuEventCreate"},
    {.name = "cuEventRecord"},
    {.name = "cuEventRecord_ptsz"},
    {.name = "cuEventQuery"},
    {.name = "cuEventSynchronize"},
    {.name = "cuEventDestroy_v2"},
    {.name = "cuEventElapsedTime"},
    {.name = "cuStreamWaitValue32"},
    {.name = "cuStreamWaitValue32_ptsz"},
    {.name = "cuStreamWriteValue32"},
    {.name = "cuStreamWriteValue32_ptsz"},
    {.name = "cuStreamBatchMemOp"},
    {.name = "cuStreamBatchMemOp_ptsz"},
    {.name = "cuStreamCreate"},
    {.name = "cuStreamCreateWithPriority"},
    {.name = "cuStreamGetPriority"},
    {.name = "cuStreamGetPriority_ptsz"},
    {.name = "cuStreamGetFlags"},
    {.name = "cuStreamGetFlags_ptsz"},
    {.name = "cuStreamDestroy_v2"},
    {.name = "cuStreamWaitEvent"},
    {.name = "cuStreamWaitEvent_ptsz"},
    {.name = "cuStreamAddCallback"},
    {.name = "cuStreamAddCallback_ptsz"},
    {.name = "cuStreamSynchronize"},
    {.name = "cuStreamSynchronize_ptsz"},
    {.name = "cuStreamQuery"},
    {.name = "cuStreamQuery_ptsz"},
    {.name = "cuStreamAttachMemAsync"},
    {.name = "cuStreamAttachMemAsync_ptsz"},
    {.name = "cuDeviceCanAccessPeer"},
    {.name = "cuCtxEnablePeerAccess"},
    {.name = "cuCtxDisablePeerAccess"},
    {.name = "cuIpcGetEventHandle"},
    {.name = "cuIpcOpenEventHandle"},
    {.name = "cuIpcGetMemHandle"},
    {.name = "cuIpcOpenMemHandle"},
    {.name = "cuIpcCloseMemHandle"},
    {.name = "cuGLCtxCreate_v2"},
    {.name = "cuGLInit"},
    {.name = "cuGLGetDevices"},
    {.name = "cuGLRegisterBufferObject"},
    {.name = "cuGLMapBufferObject_v2"},
    {.name = "cuGLMapBufferObject_v2_ptds"},
    {.name = "cuGLMapBufferObjectAsync_v2"},
    {.name = "cuGLMapBufferObjectAsync_v2_ptsz"},
    {.name = "cuGLUnmapBufferObject"},
    {.name = "cuGLUnmapBufferObjectAsync"},
    {.name = "cuGLUnregisterBufferObject"},
    {.name = "cuGLSetBufferObjectMapFlags"},
    {.name = "cuGraphicsGLRegisterImage"},
    {.name = "cuGraphicsGLRegisterBuffer"},
    {.name = "cuGraphicsUnregisterResource"},
    {.name = "cuGraphicsMapResources"},
    {.name = "cuGraphicsMapResources_ptsz"},
    {.name = "cuGraphicsUnmapResources"},
    {.name = "cuGraphicsUnmapResources_ptsz"},
    {.name = "cuGraphicsResourceSetMapFlags_v2"},
    {.name = "cuGraphicsSubResourceGetMappedArray"},
    {.name = "cuGraphicsResourceGetMappedMipmappedArray"},
    {.name = "cuGraphicsResourceGetMappedPointer_v2"},
    {.name = "cuProfilerInitialize"},
    {.name = "cuProfilerStart"},
    {.name = "cuProfilerStop"},
    {.name = "cuVDPAUGetDevice"},
    {.name = "cuVDPAUCtxCreate_v2"},
    {.name = "cuGraphicsVDPAURegisterVideoSurface"},
    {.name = "cuGraphicsVDPAURegisterOutputSurface"},
    {.name = "cuGetExportTable"},
    {.name = "cuOccupancyMaxActiveBlocksPerMultiprocessor"},
    {.name = "cuMemAdvise"},
    {.name = "cuMemPrefetchAsync"},
    {.name = "cuMemPrefetchAsync_ptsz"},
    {.name = "cuMemRangeGetAttribute"},
    {.name = "cuMemRangeGetAttributes"},
    {.name = "cuGetErrorString"},
    {.name = "cuGetErrorName"},
    {.name = "cuArray3DCreate"},
    {.name = "cuArray3DGetDescriptor"},
    {.name = "cuArrayCreate"},
    {.name = "cuArrayGetDescriptor"},
    {.name = "cuCtxAttach"},
    {.name = "cuCtxCreate"},
    {.name = "cuCtxDestroy"},
    {.name = "cuCtxDestroy_v2"},
    {.name = "cuCtxPopCurrent"},
    {.name = "cuCtxPopCurrent_v2"},
    {.name = "cuCtxPushCurrent"},
    {.name = "cuCtxPushCurrent_v2"},
    {.name = "cudbgApiAttach"},
    {.name = "cudbgApiDetach"},
    {.name = "cudbgApiInit"},
    {.name = "cudbgGetAPI"},
    {.name = "cudbgGetAPIVersion"},
    {.name = "cudbgMain"},
    {.name = "cudbgReportDriverApiError"},
    {.name = "cudbgReportDriverInternalError"},
    {.name = "cuDeviceComputeCapability"},
    {.name = "cuDeviceGetProperties"},
    {.name = "cuDeviceTotalMem"},
    {.name = "cuEGLInit"},
    {.name = "cuEGLStreamConsumerAcquireFrame"},
    {.name = "cuEGLStreamConsumerConnect"},
    {.name = "cuEGLStreamConsumerConnectWithFlags"},
    {.name = "cuEGLStreamConsumerDisconnect"},
    {.name = "cuEGLStreamConsumerReleaseFrame"},
    {.name = "cuEGLStreamProducerConnect"},
    {.name = "cuEGLStreamProducerDisconnect"},
    {.name = "cuEGLStreamProducerPresentFrame"},
    {.name = "cuEGLStreamProducerReturnFrame"},
    {.name = "cuEventDestroy"},
    {.name = "cuFuncSetAttribute"},
    {.name = "cuFuncSetBlockShape"},
    {.name = "cuFuncSetSharedSize"},
    {.name = "cuGLCtxCreate"},
    {.name = "cuGLGetDevices_v2"},
    {.name = "cuGLMapBufferObject"},
    {.name = "cuGLMapBufferObjectAsync"},
    {.name = "cuGraphicsEGLRegisterImage"},
    {.name = "cuGraphicsResourceGetMappedEglFrame"},
    {.name = "cuGraphicsResourceGetMappedPointer"},
    {.name = "cuGraphicsResourceSetMapFlags"},
    {.name = "cuLaunch"},
    {.name = "cuLaunchCooperativeKernel"},
    {.name = "cuLaunchCooperativeKernelMultiDevice"},
    {.name = "cuLaunchCooperativeKernel_ptsz"},
    {.name = "cuLaunchGrid"},
    {.name = "cuLaunchGridAsync"},
    {.name = "cuLinkAddData_v2"},
    {.name = "cuLinkAddFile_v2"},
    {.name = "cuLinkCreate_v2"},
    {.name = "cuMemAlloc"},
    {.name = "cuMemAllocHost"},
    {.name = "cuMemAllocHost_v2"},
    {.name = "cuMemAllocPitch"},
    {.name = "cuMemcpy2D"},
    {.name = "cuMemcpy2DAsync"},
    {.name = "cuMemcpy2DUnaligned"},
    {.name = "cuMemcpy2D_v2"},
    {.name = "cuMemcpy2D_v2_ptds"},
    {.name = "cuMemcpy3D"},
    {.name = "cuMemcpy3DAsync"},
    {.name = "cuMemcpyAtoA"},
    {.name = "cuMemcpyAtoA_v2"},
    {.name = "cuMemcpyAtoA_v2_ptds"},
    {.name = "cuMemcpyAtoD"},
    {.name = "cuMemcpyAtoD_v2"},
    {.name = "cuMemcpyAtoD_v2_ptds"},
    {.name = "cuMemcpyAtoH"},
    {.name = "cuMemcpyAtoHAsync"},
    {.name = "cuMemcpyAtoHAsync_v2"},
    {.name = "cuMemcpyAtoHAsync_v2_ptsz"},
    {.name = "cuMemcpyAtoH_v2"},
    {.name = "cuMemcpyAtoH_v2_ptds"},
    {.name = "cuMemcpyDtoA"},
    {.name = "cuMemcpyDtoA_v2"},
    {.name = "cuMemcpyDtoA_v2_ptds"},
    {.name = "cuMemcpyDtoD"},
    {.name = "cuMemcpyDtoDAsync"},
    {.name = "cuMemcpyDtoH"},
    {.name = "cuMemcpyDtoHAsync"},
    {.name = "cuMemcpyHtoA"},
    {.name = "cuMemcpyHtoAAsync"},
    {.name = "cuMemcpyHtoAAsync_v2"},
    {.name = "cuMemcpyHtoAAsync_v2_ptsz"},
    {.name = "cuMemcpyHtoA_v2"},
    {.name = "cuMemcpyHtoA_v2_ptds"},
    {.name = "cuMemcpyHtoD"},
    {.name = "cuMemcpyHtoDAsync"},
    {.name = "cuMemFree"},
    {.name = "cuMemGetAddressRange"},
    //{.name = "cuMemGetAttribute"},
    //{.name = "cuMemGetAttribute_v2"},
    {.name = "cuMemGetInfo"},
    {.name = "cuMemHostGetDevicePointer"},
    {.name = "cuMemHostRegister"},
    {.name = "cuMemsetD16"},
    {.name = "cuMemsetD16Async"},
    {.name = "cuMemsetD16Async_ptsz"},
    {.name = "cuMemsetD16_v2"},
    {.name = "cuMemsetD16_v2_ptds"},
    {.name = "cuMemsetD2D16"},
    {.name = "cuMemsetD2D16Async"},
    {.name = "cuMemsetD2D16Async_ptsz"},
    {.name = "cuMemsetD2D16_v2"},
    {.name = "cuMemsetD2D16_v2_ptds"},
    {.name = "cuMemsetD2D32"},
    {.name = "cuMemsetD2D32Async"},
    {.name = "cuMemsetD2D32Async_ptsz"},
    {.name = "cuMemsetD2D32_v2"},
    {.name = "cuMemsetD2D32_v2_ptds"},
    {.name = "cuMemsetD2D8"},
    {.name = "cuMemsetD32"},
    {.name = "cuMemsetD32Async"},
    {.name = "cuMemsetD32Async_ptsz"},
    {.name = "cuMemsetD32_v2"},
    {.name = "cuMemsetD32_v2_ptds"},
    {.name = "cuMemsetD8"},
    {.name = "cuModuleGetGlobal"},
    {.name = "cuModuleLoadDataEx"},
    {.name = "cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags"},
    {.name = "cuOccupancyMaxPotentialBlockSize"},
    {.name = "cuOccupancyMaxPotentialBlockSizeWithFlags"},
    {.name = "cuParamSetf"},
    {.name = "cuParamSeti"},
    {.name = "cuParamSetSize"},
    {.name = "cuParamSetTexRef"},
    {.name = "cuParamSetv"},
    {.name = "cuPointerSetAttribute"},
    {.name = "cuStreamDestroy"},
    {.name = "cuStreamWaitValue64"},
    {.name = "cuStreamWaitValue64_ptsz"},
    {.name = "cuStreamWriteValue64"},
    {.name = "cuStreamWriteValue64_ptsz"},
    {.name = "cuSurfRefGetArray"},
    {.name = "cuTexRefGetAddress"},
    {.name = "cuTexRefGetAddressMode"},
    {.name = "cuTexRefGetAddress_v2"},
    {.name = "cuTexRefGetArray"},
    {.name = "cuTexRefGetFilterMode"},
    {.name = "cuTexRefGetFlags"},
    {.name = "cuTexRefGetFormat"},
    {.name = "cuTexRefGetMaxAnisotropy"},
    {.name = "cuTexRefGetMipmapFilterMode"},
    {.name = "cuTexRefGetMipmapLevelBias"},
    {.name = "cuTexRefGetMipmapLevelClamp"},
    {.name = "cuTexRefGetMipmappedArray"},
    {.name = "cuTexRefSetAddress"},
    {.name = "cuTexRefSetAddress2D"},
    {.name = "cuTexRefSetAddress2D_v2"},
    {.name = "cuVDPAUCtxCreate"},
    {.name = "cuEGLApiInit"},
    {.name = "cuDestroyExternalMemory"},
    {.name = "cuDestroyExternalSemaphore"},
    {.name = "cuDeviceGetUuid"},
    {.name = "cuExternalMemoryGetMappedBuffer"},
    {.name = "cuExternalMemoryGetMappedMipmappedArray"},
    {.name = "cuGraphAddChildGraphNode"},
    {.name = "cuGraphAddDependencies"},
    {.name = "cuGraphAddEmptyNode"},
    {.name = "cuGraphAddHostNode"},
    {.name = "cuGraphAddKernelNode"},
    {.name = "cuGraphAddMemcpyNode"},
    {.name = "cuGraphAddMemsetNode"},
    {.name = "cuGraphChildGraphNodeGetGraph"},
    {.name = "cuGraphClone"},
    {.name = "cuGraphCreate"},
    {.name = "cuGraphDestroy"},
    {.name = "cuGraphDestroyNode"},
    {.name = "cuGraphExecDestroy"},
    {.name = "cuGraphGetEdges"},
    {.name = "cuGraphGetNodes"},
    {.name = "cuGraphGetRootNodes"},
    {.name = "cuGraphHostNodeGetParams"},
    {.name = "cuGraphHostNodeSetParams"},
    {.name = "cuGraphInstantiate"},
    {.name = "cuGraphKernelNodeGetParams"},
    {.name = "cuGraphKernelNodeSetParams"},
    {.name = "cuGraphLaunch"},
    {.name = "cuGraphLaunch_ptsz"},
    {.name = "cuGraphMemcpyNodeGetParams"},
    {.name = "cuGraphMemcpyNodeSetParams"},
    {.name = "cuGraphMemsetNodeGetParams"},
    {.name = "cuGraphMemsetNodeSetParams"},
    {.name = "cuGraphNodeFindInClone"},
    {.name = "cuGraphNodeGetDependencies"},
    {.name = "cuGraphNodeGetDependentNodes"},
    {.name = "cuGraphNodeGetType"},
    {.name = "cuGraphRemoveDependencies"},
    {.name = "cuImportExternalMemory"},
    {.name = "cuImportExternalSemaphore"},
    {.name = "cuLaunchHostFunc"},
    {.name = "cuLaunchHostFunc_ptsz"},
    {.name = "cuSignalExternalSemaphoresAsync"},
    {.name = "cuSignalExternalSemaphoresAsync_ptsz"},
    {.name = "cuStreamBeginCapture"},
    {.name = "cuStreamBeginCapture_ptsz"},
    {.name = "cuStreamEndCapture"},
    {.name = "cuStreamEndCapture_ptsz"},
    {.name = "cuStreamGetCtx"},
    {.name = "cuStreamGetCtx_ptsz"},
    {.name = "cuStreamIsCapturing"},
    {.name = "cuStreamIsCapturing_ptsz"},
    {.name = "cuWaitExternalSemaphoresAsync"},
    {.name = "cuWaitExternalSemaphoresAsync_ptsz"},
    {.name = "cuGraphExecKernelNodeSetParams"},
    {.name = "cuStreamBeginCapture_v2"},
    {.name = "cuStreamBeginCapture_v2_ptsz"},
    {.name = "cuStreamGetCaptureInfo"},
    {.name = "cuStreamGetCaptureInfo_ptsz"},
    {.name = "cuThreadExchangeStreamCaptureMode"},
};

entry_t nvml_library_entry[] = {
    {.name = "nvmlInit"},
    {.name = "nvmlShutdown"},
    {.name = "nvmlErrorString"},
    {.name = "nvmlDeviceGetHandleByIndex"},
    {.name = "nvmlDeviceGetComputeRunningProcesses"},
    {.name = "nvmlDeviceGetPciInfo"},
    {.name = "nvmlDeviceGetProcessUtilization"},
    {.name = "nvmlDeviceGetCount"},
    {.name = "nvmlDeviceClearAccountingPids"},
    {.name = "nvmlDeviceClearCpuAffinity"},
    {.name = "nvmlDeviceClearEccErrorCounts"},
    {.name = "nvmlDeviceDiscoverGpus"},
    {.name = "nvmlDeviceFreezeNvLinkUtilizationCounter"},
    {.name = "nvmlDeviceGetAccountingBufferSize"},
    {.name = "nvmlDeviceGetAccountingMode"},
    {.name = "nvmlDeviceGetAccountingPids"},
    {.name = "nvmlDeviceGetAccountingStats"},
    {.name = "nvmlDeviceGetActiveVgpus"},
    {.name = "nvmlDeviceGetAPIRestriction"},
    {.name = "nvmlDeviceGetApplicationsClock"},
    {.name = "nvmlDeviceGetAutoBoostedClocksEnabled"},
    {.name = "nvmlDeviceGetBAR1MemoryInfo"},
    {.name = "nvmlDeviceGetBoardId"},
    {.name = "nvmlDeviceGetBoardPartNumber"},
    {.name = "nvmlDeviceGetBrand"},
    {.name = "nvmlDeviceGetBridgeChipInfo"},
    {.name = "nvmlDeviceGetClock"},
    {.name = "nvmlDeviceGetClockInfo"},
    {.name = "nvmlDeviceGetComputeMode"},
    {.name = "nvmlDeviceGetCount_v2"},
    {.name = "nvmlDeviceGetCpuAffinity"},
    {.name = "nvmlDeviceGetCreatableVgpus"},
    {.name = "nvmlDeviceGetCudaComputeCapability"},
    {.name = "nvmlDeviceGetCurrentClocksThrottleReasons"},
    {.name = "nvmlDeviceGetCurrPcieLinkGeneration"},
    {.name = "nvmlDeviceGetCurrPcieLinkWidth"},
    {.name = "nvmlDeviceGetDecoderUtilization"},
    {.name = "nvmlDeviceGetDefaultApplicationsClock"},
    {.name = "nvmlDeviceGetDetailedEccErrors"},
    {.name = "nvmlDeviceGetDisplayActive"},
    {.name = "nvmlDeviceGetDisplayMode"},
    {.name = "nvmlDeviceGetDriverModel"},
    {.name = "nvmlDeviceGetEccMode"},
    {.name = "nvmlDeviceGetEncoderCapacity"},
    {.name = "nvmlDeviceGetEncoderSessions"},
    {.name = "nvmlDeviceGetEncoderStats"},
    {.name = "nvmlDeviceGetEncoderUtilization"},
    {.name = "nvmlDeviceGetEnforcedPowerLimit"},
    {.name = "nvmlDeviceGetFanSpeed"},
    {.name = "nvmlDeviceGetFanSpeed_v2"},
    {.name = "nvmlDeviceGetFieldValues"},
    {.name = "nvmlDeviceGetGpuOperationMode"},
    {.name = "nvmlDeviceGetGraphicsRunningProcesses"},
    {.name = "nvmlDeviceGetGridLicensableFeatures"},
    {.name = "nvmlDeviceGetHandleByIndex_v2"},
    {.name = "nvmlDeviceGetHandleByPciBusId"},
    {.name = "nvmlDeviceGetHandleByPciBusId_v2"},
    {.name = "nvmlDeviceGetHandleBySerial"},
    {.name = "nvmlDeviceGetHandleByUUID"},
    {.name = "nvmlDeviceGetIndex"},
    {.name = "nvmlDeviceGetInforomConfigurationChecksum"},
    {.name = "nvmlDeviceGetInforomImageVersion"},
    {.name = "nvmlDeviceGetInforomVersion"},
    {.name = "nvmlDeviceGetMaxClockInfo"},
    {.name = "nvmlDeviceGetMaxCustomerBoostClock"},
    {.name = "nvmlDeviceGetMaxPcieLinkGeneration"},
    {.name = "nvmlDeviceGetMaxPcieLinkWidth"},
    {.name = "nvmlDeviceGetMemoryErrorCounter"},
    {.name = "nvmlDeviceGetMemoryInfo"},
    {.name = "nvmlDeviceGetMinorNumber"},
    {.name = "nvmlDeviceGetMPSComputeRunningProcesses"},
    {.name = "nvmlDeviceGetMultiGpuBoard"},
    {.name = "nvmlDeviceGetName"},
    {.name = "nvmlDeviceGetNvLinkCapability"},
    {.name = "nvmlDeviceGetNvLinkErrorCounter"},
    {.name = "nvmlDeviceGetNvLinkRemotePciInfo"},
    {.name = "nvmlDeviceGetNvLinkRemotePciInfo_v2"},
    {.name = "nvmlDeviceGetNvLinkState"},
    {.name = "nvmlDeviceGetNvLinkUtilizationControl"},
    {.name = "nvmlDeviceGetNvLinkUtilizationCounter"},
    {.name = "nvmlDeviceGetNvLinkVersion"},
    {.name = "nvmlDeviceGetP2PStatus"},
    {.name = "nvmlDeviceGetPcieReplayCounter"},
    {.name = "nvmlDeviceGetPcieThroughput"},
    {.name = "nvmlDeviceGetPciInfo_v2"},
    {.name = "nvmlDeviceGetPciInfo_v3"},
    {.name = "nvmlDeviceGetPerformanceState"},
    {.name = "nvmlDeviceGetPersistenceMode"},
    {.name = "nvmlDeviceGetPowerManagementDefaultLimit"},
    {.name = "nvmlDeviceGetPowerManagementLimit"},
    {.name = "nvmlDeviceGetPowerManagementLimitConstraints"},
    {.name = "nvmlDeviceGetPowerManagementMode"},
    {.name = "nvmlDeviceGetPowerState"},
    {.name = "nvmlDeviceGetPowerUsage"},
    {.name = "nvmlDeviceGetRetiredPages"},
    {.name = "nvmlDeviceGetRetiredPagesPendingStatus"},
    {.name = "nvmlDeviceGetSamples"},
    {.name = "nvmlDeviceGetSerial"},
    {.name = "nvmlDeviceGetSupportedClocksThrottleReasons"},
    {.name = "nvmlDeviceGetSupportedEventTypes"},
    {.name = "nvmlDeviceGetSupportedGraphicsClocks"},
    {.name = "nvmlDeviceGetSupportedMemoryClocks"},
    {.name = "nvmlDeviceGetSupportedVgpus"},
    {.name = "nvmlDeviceGetTemperature"},
    {.name = "nvmlDeviceGetTemperatureThreshold"},
    {.name = "nvmlDeviceGetTopologyCommonAncestor"},
    {.name = "nvmlDeviceGetTopologyNearestGpus"},
    {.name = "nvmlDeviceGetTotalEccErrors"},
    {.name = "nvmlDeviceGetTotalEnergyConsumption"},
    {.name = "nvmlDeviceGetUtilizationRates"},
    {.name = "nvmlDeviceGetUUID"},
    {.name = "nvmlDeviceGetVbiosVersion"},
    {.name = "nvmlDeviceGetVgpuMetadata"},
    {.name = "nvmlDeviceGetVgpuProcessUtilization"},
    {.name = "nvmlDeviceGetVgpuUtilization"},
    {.name = "nvmlDeviceGetViolationStatus"},
    {.name = "nvmlDeviceGetVirtualizationMode"},
    {.name = "nvmlDeviceModifyDrainState"},
    {.name = "nvmlDeviceOnSameBoard"},
    {.name = "nvmlDeviceQueryDrainState"},
    {.name = "nvmlDeviceRegisterEvents"},
    {.name = "nvmlDeviceRemoveGpu"},
    {.name = "nvmlDeviceRemoveGpu_v2"},
    {.name = "nvmlDeviceResetApplicationsClocks"},
    {.name = "nvmlDeviceResetNvLinkErrorCounters"},
    {.name = "nvmlDeviceResetNvLinkUtilizationCounter"},
    {.name = "nvmlDeviceSetAccountingMode"},
    {.name = "nvmlDeviceSetAPIRestriction"},
    {.name = "nvmlDeviceSetApplicationsClocks"},
    {.name = "nvmlDeviceSetAutoBoostedClocksEnabled"},
    /** We hijack this call*/
    {.name = "nvmlDeviceSetComputeMode"},
    {.name = "nvmlDeviceSetCpuAffinity"},
    {.name = "nvmlDeviceSetDefaultAutoBoostedClocksEnabled"},
    {.name = "nvmlDeviceSetDriverModel"},
    {.name = "nvmlDeviceSetEccMode"},
    {.name = "nvmlDeviceSetGpuOperationMode"},
    {.name = "nvmlDeviceSetNvLinkUtilizationControl"},
    {.name = "nvmlDeviceSetPersistenceMode"},
    {.name = "nvmlDeviceSetPowerManagementLimit"},
    {.name = "nvmlDeviceSetVirtualizationMode"},
    {.name = "nvmlDeviceValidateInforom"},
    {.name = "nvmlEventSetCreate"},
    {.name = "nvmlEventSetFree"},
    {.name = "nvmlEventSetWait"},
    {.name = "nvmlGetVgpuCompatibility"},
    {.name = "nvmlInit_v2"},
    {.name = "nvmlInitWithFlags"},
    {.name = "nvmlInternalGetExportTable"},
    {.name = "nvmlSystemGetCudaDriverVersion"},
    {.name = "nvmlSystemGetCudaDriverVersion_v2"},
    {.name = "nvmlSystemGetDriverVersion"},
    {.name = "nvmlSystemGetHicVersion"},
    {.name = "nvmlSystemGetNVMLVersion"},
    {.name = "nvmlSystemGetProcessName"},
    {.name = "nvmlSystemGetTopologyGpuSet"},
    {.name = "nvmlUnitGetCount"},
    {.name = "nvmlUnitGetDevices"},
    {.name = "nvmlUnitGetFanSpeedInfo"},
    {.name = "nvmlUnitGetHandleByIndex"},
    {.name = "nvmlUnitGetLedState"},
    {.name = "nvmlUnitGetPsuInfo"},
    {.name = "nvmlUnitGetTemperature"},
    {.name = "nvmlUnitGetUnitInfo"},
    {.name = "nvmlUnitSetLedState"},
    {.name = "nvmlVgpuInstanceGetEncoderCapacity"},
    {.name = "nvmlVgpuInstanceGetEncoderSessions"},
    {.name = "nvmlVgpuInstanceGetEncoderStats"},
    {.name = "nvmlVgpuInstanceGetFbUsage"},
    {.name = "nvmlVgpuInstanceGetFrameRateLimit"},
    {.name = "nvmlVgpuInstanceGetLicenseStatus"},
    {.name = "nvmlVgpuInstanceGetMetadata"},
    {.name = "nvmlVgpuInstanceGetType"},
    {.name = "nvmlVgpuInstanceGetUUID"},
    {.name = "nvmlVgpuInstanceGetVmDriverVersion"},
    {.name = "nvmlVgpuInstanceGetVmID"},
    {.name = "nvmlVgpuInstanceSetEncoderCapacity"},
    {.name = "nvmlVgpuTypeGetClass"},
    {.name = "nvmlVgpuTypeGetDeviceID"},
    {.name = "nvmlVgpuTypeGetFramebufferSize"},
    {.name = "nvmlVgpuTypeGetFrameRateLimit"},
    {.name = "nvmlVgpuTypeGetLicense"},
    {.name = "nvmlVgpuTypeGetMaxInstances"},
    {.name = "nvmlVgpuTypeGetName"},
    {.name = "nvmlVgpuTypeGetNumDisplayHeads"},
    {.name = "nvmlVgpuTypeGetResolution"},
    {.name = "nvmlDeviceGetFBCSessions"},
    {.name = "nvmlDeviceGetFBCStats"},
    {.name = "nvmlDeviceGetGridLicensableFeatures_v2"},
    {.name = "nvmlDeviceGetRetiredPages_v2"},
    {.name = "nvmlDeviceResetGpuLockedClocks"},
    {.name = "nvmlDeviceSetGpuLockedClocks"},
    {.name = "nvmlGetBlacklistDeviceCount"},
    {.name = "nvmlGetBlacklistDeviceInfoByIndex"},
    {.name = "nvmlVgpuInstanceGetAccountingMode"},
    {.name = "nvmlVgpuInstanceGetAccountingPids"},
    {.name = "nvmlVgpuInstanceGetAccountingStats"},
    {.name = "nvmlVgpuInstanceGetFBCSessions"},
    {.name = "nvmlVgpuInstanceGetFBCStats"},
    {.name = "nvmlVgpuTypeGetMaxInstancesPerVm"},
    {.name = "nvmlGetVgpuVersion"},
    {.name = "nvmlSetVgpuVersion"},
};

/** register once set */
static pthread_once_t g_cuda_set = PTHREAD_ONCE_INIT;
static pthread_once_t g_driver_set = PTHREAD_ONCE_INIT;

resource_data_t g_vcuda_config = {
    .pod_uid = "",
    .limit = 0,
    .container_name = "",
    .utilization = 0,
    .gpu_memory = 0,
    .enable = 1,
};

static char base_dir[FILENAME_MAX] = EMPTY_PREFIX;
char config_path[FILENAME_MAX] = CONTROLLER_CONFIG_PATH;
char pid_path[FILENAME_MAX] = PIDS_CONFIG_PATH;
char driver_version[FILENAME_MAX] = "1";

char *Marshal(resource_data_t t) {
    cJSON *monitor = cJSON_CreateObject();

    cJSON_AddItemToObject(monitor, "pod_uid", cJSON_CreateString(t.pod_uid));
    cJSON_AddItemToObject(monitor, "limit", cJSON_CreateNumber(t.limit));
    cJSON_AddItemToObject(monitor, "occupied", cJSON_CreateString(t.occupied));
    cJSON_AddItemToObject(monitor, "container_name", cJSON_CreateString(t.container_name));
    cJSON_AddItemToObject(monitor, "bus_id", cJSON_CreateString(t.bus_id));
    cJSON_AddItemToObject(monitor, "gpu_memory", cJSON_CreateNumber(t.gpu_memory));
    cJSON_AddItemToObject(monitor, "utilization", cJSON_CreateNumber(t.utilization));
    cJSON_AddItemToObject(monitor, "hard_limit", cJSON_CreateNumber(t.hard_limit));
    cJSON_AddItemToObject(monitor, "enable", cJSON_CreateNumber(t.enable));
    cJSON *version = cJSON_CreateObject();
    cJSON_AddItemToObject(monitor, "driver_version", version);
    cJSON_AddItemToObject(version, "major", cJSON_CreateNumber(t.driver_version.major));
    cJSON_AddItemToObject(version, "minor", cJSON_CreateNumber(t.driver_version.minor));
    return cJSON_Print(monitor);
}

resource_data_t UnMarshal(char *s) {
    resource_data_t t = {};
    cJSON *monitor_json = cJSON_Parse(s);

    cJSON *pod_uid = cJSON_GetObjectItemCaseSensitive(monitor_json, "pod_uid");
    if (pod_uid != NULL) {
        t.pod_uid = pod_uid->valuestring;
    }
    cJSON *occupied = cJSON_GetObjectItemCaseSensitive(monitor_json, "occupied");
    if (occupied != NULL) {
        t.occupied = occupied->valuestring;
    }
    cJSON *container_name = cJSON_GetObjectItemCaseSensitive(monitor_json, "container_name");
    if (container_name != NULL) {
        t.container_name = container_name->valuestring;
    }
    cJSON *bus_id = cJSON_GetObjectItemCaseSensitive(monitor_json, "bus_id");
    if (bus_id != NULL) {
        t.bus_id = bus_id->valuestring;
    }

    cJSON *limit = cJSON_GetObjectItemCaseSensitive(monitor_json, "limit");
    if (limit != NULL) {
        t.limit = limit->valueint;
    }
    cJSON *gpu_memory = cJSON_GetObjectItemCaseSensitive(monitor_json, "gpu_memory");
    if (gpu_memory != NULL) {
        t.gpu_memory = gpu_memory->valueint;
    }
    cJSON *utilization = cJSON_GetObjectItemCaseSensitive(monitor_json, "utilization");
    if (utilization != NULL) {
        t.utilization = utilization->valueint;
    }
    cJSON *enable = cJSON_GetObjectItemCaseSensitive(monitor_json, "enable");
    if (enable != NULL) {
        t.enable = enable->valueint;
    }
    cJSON *hard_limit = cJSON_GetObjectItemCaseSensitive(monitor_json, "hard_limit");
    if (hard_limit != NULL) {
        t.hard_limit = hard_limit->valueint;
    }
    cJSON *driver_version_tmp = cJSON_GetObjectItem(monitor_json, "driver_version");
    if (driver_version_tmp != NULL) {
        cJSON *major = cJSON_GetObjectItemCaseSensitive(driver_version_tmp, "major");
        if (major != NULL) {
            t.driver_version.major = major->valueint;
        }
        cJSON *minor = cJSON_GetObjectItemCaseSensitive(driver_version_tmp, "minor");
        if (minor != NULL) {
            t.driver_version.minor = minor->valueint;
        }
        t.driver_version.major = cJSON_GetObjectItemCaseSensitive(driver_version_tmp, "minor")->valueint;
    }

    return t;
}

static void load_driver_libraries() {
    void *table = NULL;
    char driver_filename[FILENAME_MAX];
    int i;

    snprintf(driver_filename, FILENAME_MAX - 1, "%s.%s", DRIVER_ML_LIBRARY_PREFIX, driver_version);
    driver_filename[FILENAME_MAX - 1] = '\0';

    table = dlopen(driver_filename, RTLD_NOW | RTLD_NODELETE);
    if (unlikely(!table)) {
        LOGGER(FATAL, "can't find library %s", driver_filename);
    }

    for (i = 0; i < NVML_ENTRY_END; i++) {
        nvml_library_entry[i].fn_ptr = dlsym(table, nvml_library_entry[i].name);
        if (unlikely(!nvml_library_entry[i].fn_ptr)) {
            LOGGER(4, "can't find function %s in %s", driver_filename, nvml_library_entry[i].name);
        }
    }

    dlclose(table);
}

static void load_cuda_single_library(int idx) {
    void *table = NULL;
    char cuda_filename[FILENAME_MAX];

    snprintf(cuda_filename, FILENAME_MAX - 1, "%s.%s", CUDA_LIBRARY_PREFIX, driver_version);
    cuda_filename[FILENAME_MAX - 1] = '\0';

    table = dlopen(cuda_filename, RTLD_NOW | RTLD_NODELETE);
    if (unlikely(!table)) {
        LOGGER(FATAL, "can't find library %s", cuda_filename);
    }

    cuda_library_entry[idx].fn_ptr = dlsym(table, cuda_library_entry[idx].name);
    if (unlikely(!cuda_library_entry[idx].fn_ptr)) {
        LOGGER(4, "can't find function %s in %s", cuda_filename, cuda_library_entry[idx].name);
    }

    dlclose(table);
}

void load_cuda_libraries() {
    void *table = NULL;
    int i = 0;
    char cuda_filename[FILENAME_MAX];

    LOGGER(4, "Start hijacking");

    snprintf(cuda_filename, FILENAME_MAX - 1, "%s.%s", CUDA_LIBRARY_PREFIX, driver_version);
    cuda_filename[FILENAME_MAX - 1] = '\0';
    cuda_filename[FILENAME_MAX - 1] = '\0';

    table = dlopen(cuda_filename, RTLD_NOW | RTLD_NODELETE);
    if (unlikely(!table)) {
        LOGGER(FATAL, "can't find library %s", cuda_filename);
    }

    for (i = 0; i < CUDA_ENTRY_END; i++) {
        cuda_library_entry[i].fn_ptr = dlsym(table, cuda_library_entry[i].name);
        if (unlikely(!cuda_library_entry[i].fn_ptr)) {
            LOGGER(4, "can't find function %s in %s", cuda_filename, cuda_library_entry[i].name);
        }
    }

    dlclose(table);
}

// #lizard forgives
int get_cgroup_data(const char *pid_cgroup, char *pod_uid, char *container_id, size_t size) {
    int ret = 1;
    FILE *cgroup_fd = NULL;
    char *token = NULL, *last_ptr = NULL, *last_second = NULL;
    char *cgroup_ptr = NULL;
    char buffer[4096];
    int is_systemd = 0;
    char *prune_pos = NULL;

    cgroup_fd = fopen(pid_cgroup, "r");
    if (unlikely(!cgroup_fd)) {
        LOGGER(4, "can't open %s, error %s", pid_cgroup, strerror(errno));
        goto DONE;
    }

    /**
     * find memory cgroup name
     */
    while (!feof(cgroup_fd)) {
        buffer[0] = '\0';
        if (unlikely(!fgets(buffer, sizeof(buffer), cgroup_fd))) {
            LOGGER(4, "can't get line from %s", pid_cgroup);
            goto DONE;
        }

        buffer[strlen(buffer) - 1] = '\0';

        last_ptr = NULL;
        token = buffer;
        for (token = strtok_r(token, ":", &last_ptr); token; token = NULL, token = strtok_r(token, ":", &last_ptr)) {
            if (!strcmp(token, "memory")) {
                cgroup_ptr = strtok_r(NULL, ":", &last_ptr);
                break;
            }
        }

        if (cgroup_ptr) {
            break;
        }
    }

    if (!cgroup_ptr) {
        LOGGER(4, "can't find memory cgroup from %s", pid_cgroup);
        goto DONE;
    }

    /**
     * find container id
     */
    last_ptr = NULL;
    last_second = NULL;
    token = cgroup_ptr;
    while (*token) {
        if (*token == '/') {
            last_second = last_ptr;
            last_ptr = token;
        }
        ++token;
    }

    if (!last_ptr) {
        goto DONE;
    }

    strncpy(container_id, last_ptr + 1, size);
    container_id[size - 1] = '\0';

    /**
     * if cgroup is systemd, cgroup pattern should be like
     * /kubepods.slice/kubepods-besteffort.slice/kubepods-besteffort-pod27882189_b4d9_11e9_b287_ec0d9ae89a20.slice/docker-4aa615892ab2a014d52178bdf3da1c4a45c8ddfb5171dd6e39dc910f96693e14.scope
     */
    if ((prune_pos = strstr(container_id, ".scope"))) {
        is_systemd = 1;
        *prune_pos = '\0';
    }

    /**
     * find pod uid
     */
    *last_ptr = '\0';
    if (!last_second) {
        goto DONE;
    }

    strncpy(pod_uid, last_second, size);
    pod_uid[size - 1] = '\0';

    if (is_systemd && (prune_pos = strstr(pod_uid, ".slice"))) {
        *prune_pos = '\0';
    }

    /**
     * remove unnecessary chars from $container_id and $pod_uid
     */
    if (is_systemd) {
        prune_pos = strstr(container_id, "docker-");
        if (!prune_pos) {
            LOGGER(4, "no docker- prefix");
            goto DONE;
        }
        prune_pos += strlen("docker-");
        memmove(container_id, prune_pos, strlen(prune_pos));
        container_id[strlen(prune_pos)] = '\0';

        prune_pos = strstr(pod_uid, "-pod");
        if (!prune_pos) {
            LOGGER(4, "no pod string");
            goto DONE;
        }
        prune_pos += strlen("-pod");
        memmove(pod_uid, prune_pos, strlen(prune_pos));
        pod_uid[strlen(prune_pos)] = '\0';
        prune_pos = pod_uid;
        while (*prune_pos) {
            if (*prune_pos == '_') {
                *prune_pos = '-';
            }
            ++prune_pos;
        }
    }
    else {
        memmove(pod_uid, pod_uid + strlen("/pod"), strlen(pod_uid));
    }

    ret = 0;
DONE:
    if (cgroup_fd) {
        fclose(cgroup_fd);
    }
    return ret;
}

static int get_path_by_cgroup(const char *pid_cgroup) {
    int ret = 1;
    char pod_uid[4096], container_id[4096];

    if (is_custom_config_path()) {
        return 0;
    }

    if (unlikely(get_cgroup_data(pid_cgroup, pod_uid, container_id, sizeof(container_id)))) {
        LOGGER(4, "can't find container id from %s", pid_cgroup);
        goto DONE;
    }

    snprintf(base_dir, sizeof(base_dir), "%s/%s", VCUDA_CONFIG_PATH, container_id);
    snprintf(config_path, sizeof(config_path), "%s/%s", base_dir, CONTROLLER_CONFIG_NAME);
    snprintf(pid_path, sizeof(pid_path), "%s/%s", base_dir, PIDS_CONFIG_NAME);

    LOGGER(4, "config file: %s", config_path);
    LOGGER(4, "pid file: %s", pid_path);
    ret = 0;

    LOGGER(4, "register to remote: pod uid: %s, cont id: %s", pod_uid, container_id);
    register_to_remote_with_data("", pod_uid, container_id);
DONE:
    return ret;
}

static int is_default_config_path() {
    int fd = -1;

    fd = open(config_path, O_RDONLY);
    if (fd == -1) {
        return 0;
    }

    close(fd);

    return 1;
}

static void matchRegex(const char *pattern, const char *matchString, char *version) {
    regex_t regex;
    int reti;
    regmatch_t matches[1];
    char msgbuf[512];

    reti = regcomp(&regex, pattern, REG_EXTENDED);
    if (reti) {
        LOGGER(4, "Could not compile regex: %s", DRIVER_VERSION_MATCH_PATTERN);
        return;
    }

    reti = regexec(&regex, matchString, 1, matches, 0);
    switch (reti) {
        case 0:
            strncpy(version, matchString + matches[0].rm_so, matches[0].rm_eo - matches[0].rm_so);
            version[matches[0].rm_eo - matches[0].rm_so] = '\0';
            break;
        case REG_NOMATCH:
            LOGGER(4, "Regex does not match for string: %s", matchString);
            break;
        default:
            regerror(reti, &regex, msgbuf, sizeof(msgbuf));
            LOGGER(4, "Regex match failed: %s", msgbuf);
    }

    regfree(&regex);
    return;
}

static void read_version_from_proc(char *version) {
    char *line = NULL;
    size_t len = 0;

    FILE *fp = fopen(DRIVER_VERSION_PROC_PATH, "r");
    if (fp == NULL) {
        LOGGER(4, "can't open %s, error %s", DRIVER_VERSION_PROC_PATH, strerror(errno));
        return;
    }

    while ((getline(&line, &len, fp) != -1)) {
        if (strncmp(line, "NVRM", 4) == 0) {
            matchRegex(DRIVER_VERSION_MATCH_PATTERN, line, version);
            break;
        }
    }
    fclose(fp);
}

int read_controller_configuration() {
    int ret = 1;
    if (!is_default_config_path()) {
        if (get_path_by_cgroup("/proc/self/cgroup")) {
            LOGGER(FATAL, "can't get config file path");
        }
    }

    FILE *file;
    char *text = NULL;              // 用于存储所有文本的字符串
    char line[100];                 // 用于存储读取的每行文本
    size_t len = 0;                 // 用于记录当前文本的长度

    file = fopen(config_path, "r"); // 打开文件
    if (file == NULL) {
        LOGGER(4, "can't open %s, error %s", config_path, strerror(errno));
        goto DONE;
    }

    // 逐行读取文件内容并连接在一起
    while (fgets(line, sizeof(line), file) != NULL) {
        size_t line_len = strlen(line);
        char *new_text = realloc(text, len + line_len + 1); // 重新分配足够的空间来存储当前文本
        if (new_text == NULL) {
            printf("内存分配失败\n");
            free(text);   // 释放原始缓冲区的内存
            fclose(file); // 关闭文件
            return 1;
        }
        text = new_text;
        strcpy(text + len, line); // 将当前行文本连接到已有的文本之后
        len += line_len;          // 更新当前文本的长度
    }

    g_vcuda_config = UnMarshal(text);

    read_version_from_proc(driver_version);
    ret = 0;

    LOGGER(4, "pod uid          : %s", g_vcuda_config.pod_uid);
    LOGGER(4, "limit            : %d", g_vcuda_config.limit);
    LOGGER(4, "container name   : %s", g_vcuda_config.container_name);
    LOGGER(4, "total utilization: %d", g_vcuda_config.utilization);
    LOGGER(4, "total gpu memory : %d", g_vcuda_config.gpu_memory);
    LOGGER(4, "driver version   : %s", driver_version);
    LOGGER(4, "hard limit mode  : %d", g_vcuda_config.hard_limit);
    LOGGER(4, "enable mode      : %d", g_vcuda_config.enable);
DONE:
    if (likely(file)) {
        free(text);
        fclose(file); // 关闭文件
    }

    return ret;
}

void load_necessary_data() {
    read_controller_configuration();
    load_cuda_single_library(CUDA_ENTRY_ENUM(cuDriverGetVersion));

    pthread_once(&g_cuda_set, load_cuda_libraries);
    pthread_once(&g_driver_set, load_driver_libraries);
}

int is_custom_config_path() {
    return strcmp(base_dir, EMPTY_PREFIX) != 0;
}
