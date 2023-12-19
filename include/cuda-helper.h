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
#ifndef HIJACK_CUDA_HELPER_H
#define HIJACK_CUDA_HELPER_H
#ifdef __cplusplus
extern "C" {
#endif
#include <dlfcn.h>

#include "cuda.h"

/**
 *  CUDA library prefix
 */
#define CUDA_LIBRARY_PREFIX "libcuda.so"
#define CUDA_ENTRY_ENUM(x) ENTRY_##x
#define CUDA_FIND_ENTRY(table, sym) ({ (table)[CUDA_ENTRY_ENUM(sym)]; })
#define CUDA_ENTRY_CALL(table, sym, ...)                 \
    ({                                                   \
        cuda_sym_t _entry = CUDA_FIND_ENTRY(table, sym); \
        _entry(__VA_ARGS__);                             \
    })
#define CUDA_ENTRY_DEBUG_VOID_CALL(table, sym, ...)                 \
    ({                                                              \
        cuda_debug_void_sym_t _entry = CUDA_FIND_ENTRY(table, sym); \
        _entry(__VA_ARGS__);                                        \
    })
#define CUDA_ENTRY_DEBUG_RESULT_CALL(table, sym, ...)                 \
    ({                                                                \
        cuda_debug_result_sym_t _entry = CUDA_FIND_ENTRY(table, sym); \
        _entry(__VA_ARGS__);                                          \
    })
/**
 * CUDA library enumerator entry
 */
typedef enum {
    CUDA_ENTRY_ENUM(cuInit),
    CUDA_ENTRY_ENUM(cuDeviceGet),
    CUDA_ENTRY_ENUM(cuDeviceGetCount),
    CUDA_ENTRY_ENUM(cuDeviceGetName),
    CUDA_ENTRY_ENUM(cuDeviceTotalMem_v2),
    CUDA_ENTRY_ENUM(cuDeviceGetAttribute),
    CUDA_ENTRY_ENUM(cuDeviceGetP2PAttribute),
    CUDA_ENTRY_ENUM(cuDriverGetVersion),
    CUDA_ENTRY_ENUM(cuDeviceGetByPCIBusId),
    CUDA_ENTRY_ENUM(cuDeviceGetPCIBusId),
    CUDA_ENTRY_ENUM(cuDevicePrimaryCtxRetain),
    CUDA_ENTRY_ENUM(cuDevicePrimaryCtxRelease),
    CUDA_ENTRY_ENUM(cuDevicePrimaryCtxSetFlags),
    CUDA_ENTRY_ENUM(cuDevicePrimaryCtxGetState),
    CUDA_ENTRY_ENUM(cuDevicePrimaryCtxReset),
    CUDA_ENTRY_ENUM(cuCtxCreate_v2),
    CUDA_ENTRY_ENUM(cuCtxGetFlags),
    CUDA_ENTRY_ENUM(cuCtxSetCurrent),
    CUDA_ENTRY_ENUM(cuCtxGetCurrent),
    CUDA_ENTRY_ENUM(cuCtxDetach),
    CUDA_ENTRY_ENUM(cuCtxGetApiVersion),
    CUDA_ENTRY_ENUM(cuCtxGetDevice),
    CUDA_ENTRY_ENUM(cuCtxGetLimit),
    CUDA_ENTRY_ENUM(cuCtxSetLimit),
    CUDA_ENTRY_ENUM(cuCtxGetCacheConfig),
    CUDA_ENTRY_ENUM(cuCtxSetCacheConfig),
    CUDA_ENTRY_ENUM(cuCtxGetSharedMemConfig),
    CUDA_ENTRY_ENUM(cuCtxGetStreamPriorityRange),
    CUDA_ENTRY_ENUM(cuCtxSetSharedMemConfig),
    CUDA_ENTRY_ENUM(cuCtxSynchronize),
    CUDA_ENTRY_ENUM(cuModuleLoad),
    CUDA_ENTRY_ENUM(cuModuleLoadData),
    CUDA_ENTRY_ENUM(cuModuleLoadFatBinary),
    CUDA_ENTRY_ENUM(cuModuleUnload),
    CUDA_ENTRY_ENUM(cuModuleGetFunction),
    CUDA_ENTRY_ENUM(cuModuleGetGlobal_v2),
    CUDA_ENTRY_ENUM(cuModuleGetTexRef),
    CUDA_ENTRY_ENUM(cuModuleGetSurfRef),
    CUDA_ENTRY_ENUM(cuLinkCreate),
    CUDA_ENTRY_ENUM(cuLinkAddData),
    CUDA_ENTRY_ENUM(cuLinkAddFile),
    CUDA_ENTRY_ENUM(cuLinkComplete),
    CUDA_ENTRY_ENUM(cuLinkDestroy),
    CUDA_ENTRY_ENUM(cuMemGetInfo_v2),
    CUDA_ENTRY_ENUM(cuMemAllocManaged),
    CUDA_ENTRY_ENUM(cuMemAlloc_v2),
    CUDA_ENTRY_ENUM(cuMemAllocPitch_v2),
    CUDA_ENTRY_ENUM(cuMemFree_v2),
    CUDA_ENTRY_ENUM(cuMemGetAddressRange_v2),
    CUDA_ENTRY_ENUM(cuMemFreeHost), // 102
    CUDA_ENTRY_ENUM(cuMemHostAlloc),
    CUDA_ENTRY_ENUM(cuMemHostGetDevicePointer_v2), // 232
    CUDA_ENTRY_ENUM(cuMemHostGetFlags),            // 234
    CUDA_ENTRY_ENUM(cuMemHostRegister_v2),
    CUDA_ENTRY_ENUM(cuMemHostUnregister),
    CUDA_ENTRY_ENUM(cuPointerGetAttribute),  // 122
    CUDA_ENTRY_ENUM(cuPointerGetAttributes), // 124
    CUDA_ENTRY_ENUM(cuMemcpy),
    CUDA_ENTRY_ENUM(cuMemcpy_ptds),
    CUDA_ENTRY_ENUM(cuMemcpyAsync),
    CUDA_ENTRY_ENUM(cuMemcpyAsync_ptsz),
    CUDA_ENTRY_ENUM(cuMemcpyPeer),
    CUDA_ENTRY_ENUM(cuMemcpyPeer_ptds),
    CUDA_ENTRY_ENUM(cuMemcpyPeerAsync),
    CUDA_ENTRY_ENUM(cuMemcpyPeerAsync_ptsz),
    CUDA_ENTRY_ENUM(cuMemcpyHtoD_v2),
    CUDA_ENTRY_ENUM(cuMemcpyHtoD_v2_ptds),
    CUDA_ENTRY_ENUM(cuMemcpyHtoDAsync_v2),
    CUDA_ENTRY_ENUM(cuMemcpyHtoDAsync_v2_ptsz),
    CUDA_ENTRY_ENUM(cuMemcpyDtoH_v2),
    CUDA_ENTRY_ENUM(cuMemcpyDtoH_v2_ptds),
    CUDA_ENTRY_ENUM(cuMemcpyDtoHAsync_v2),
    CUDA_ENTRY_ENUM(cuMemcpyDtoHAsync_v2_ptsz),
    CUDA_ENTRY_ENUM(cuMemcpyDtoD_v2),
    CUDA_ENTRY_ENUM(cuMemcpyDtoD_v2_ptds),
    CUDA_ENTRY_ENUM(cuMemcpyDtoDAsync_v2),
    CUDA_ENTRY_ENUM(cuMemcpyDtoDAsync_v2_ptsz),
    CUDA_ENTRY_ENUM(cuMemcpy2DUnaligned_v2), // 260
    CUDA_ENTRY_ENUM(cuMemcpy2DUnaligned_v2_ptds),
    CUDA_ENTRY_ENUM(cuMemcpy2DAsync_v2), // 262
    CUDA_ENTRY_ENUM(cuMemcpy2DAsync_v2_ptsz),
    CUDA_ENTRY_ENUM(cuMemcpy3D_v2), // 264
    CUDA_ENTRY_ENUM(cuMemcpy3D_v2_ptds),
    CUDA_ENTRY_ENUM(cuMemcpy3DAsync_v2), // 266
    CUDA_ENTRY_ENUM(cuMemcpy3DAsync_v2_ptsz),
    CUDA_ENTRY_ENUM(cuMemcpy3DPeer), // 268
    CUDA_ENTRY_ENUM(cuMemcpy3DPeer_ptds),
    CUDA_ENTRY_ENUM(cuMemcpy3DPeerAsync), // 270
    CUDA_ENTRY_ENUM(cuMemcpy3DPeerAsync_ptsz),
    CUDA_ENTRY_ENUM(cuMemsetD8_v2), // 174
    CUDA_ENTRY_ENUM(cuMemsetD8_v2_ptds),
    CUDA_ENTRY_ENUM(cuMemsetD8Async), // 176
    CUDA_ENTRY_ENUM(cuMemsetD8Async_ptsz),
    CUDA_ENTRY_ENUM(cuMemsetD2D8_v2), // 166
    CUDA_ENTRY_ENUM(cuMemsetD2D8_v2_ptds),
    CUDA_ENTRY_ENUM(cuMemsetD2D8Async), // 168
    CUDA_ENTRY_ENUM(cuMemsetD2D8Async_ptsz),
    CUDA_ENTRY_ENUM(cuFuncSetCacheConfig),
    CUDA_ENTRY_ENUM(cuFuncSetSharedMemConfig),
    CUDA_ENTRY_ENUM(cuFuncGetAttribute),
    CUDA_ENTRY_ENUM(cuArrayGetDescriptor_v2),
    CUDA_ENTRY_ENUM(cuArray3DCreate_v2), // 86
    CUDA_ENTRY_ENUM(cuArrayCreate_v2),   // 88
    CUDA_ENTRY_ENUM(cuArray3DGetDescriptor_v2),
    CUDA_ENTRY_ENUM(cuArrayDestroy),         // 90
    CUDA_ENTRY_ENUM(cuMipmappedArrayCreate), // 114
    CUDA_ENTRY_ENUM(cuMipmappedArrayGetLevel),
    CUDA_ENTRY_ENUM(cuMipmappedArrayDestroy), // 116
    CUDA_ENTRY_ENUM(cuTexRefCreate),
    CUDA_ENTRY_ENUM(cuTexRefDestroy),
    CUDA_ENTRY_ENUM(cuTexRefSetArray),
    CUDA_ENTRY_ENUM(cuTexRefSetMipmappedArray),
    CUDA_ENTRY_ENUM(cuTexRefSetAddress_v2),
    CUDA_ENTRY_ENUM(cuTexRefSetAddress2D_v3),
    CUDA_ENTRY_ENUM(cuTexRefSetFormat),
    CUDA_ENTRY_ENUM(cuTexRefSetAddressMode),
    CUDA_ENTRY_ENUM(cuTexRefSetFilterMode),
    CUDA_ENTRY_ENUM(cuTexRefSetMipmapFilterMode),
    CUDA_ENTRY_ENUM(cuTexRefSetMipmapLevelBias),
    CUDA_ENTRY_ENUM(cuTexRefSetMipmapLevelClamp),
    CUDA_ENTRY_ENUM(cuTexRefSetMaxAnisotropy),
    CUDA_ENTRY_ENUM(cuTexRefSetFlags),
    CUDA_ENTRY_ENUM(cuTexRefSetBorderColor),
    CUDA_ENTRY_ENUM(cuTexRefGetBorderColor),
    CUDA_ENTRY_ENUM(cuSurfRefSetArray),
    CUDA_ENTRY_ENUM(cuTexObjectCreate),
    CUDA_ENTRY_ENUM(cuTexObjectDestroy),
    CUDA_ENTRY_ENUM(cuTexObjectGetResourceDesc),
    CUDA_ENTRY_ENUM(cuTexObjectGetTextureDesc),
    CUDA_ENTRY_ENUM(cuTexObjectGetResourceViewDesc),
    CUDA_ENTRY_ENUM(cuSurfObjectCreate),
    CUDA_ENTRY_ENUM(cuSurfObjectDestroy),
    CUDA_ENTRY_ENUM(cuSurfObjectGetResourceDesc),
    CUDA_ENTRY_ENUM(cuLaunchKernel), // 188
    CUDA_ENTRY_ENUM(cuLaunchKernel_ptsz),
    CUDA_ENTRY_ENUM(cuEventCreate),
    CUDA_ENTRY_ENUM(cuEventRecord),
    CUDA_ENTRY_ENUM(cuEventRecord_ptsz),
    CUDA_ENTRY_ENUM(cuEventQuery),
    CUDA_ENTRY_ENUM(cuEventSynchronize),
    CUDA_ENTRY_ENUM(cuEventDestroy_v2),
    CUDA_ENTRY_ENUM(cuEventElapsedTime),
    CUDA_ENTRY_ENUM(cuStreamWaitValue32),
    CUDA_ENTRY_ENUM(cuStreamWaitValue32_ptsz),
    CUDA_ENTRY_ENUM(cuStreamWriteValue32),
    CUDA_ENTRY_ENUM(cuStreamWriteValue32_ptsz),
    CUDA_ENTRY_ENUM(cuStreamBatchMemOp),
    CUDA_ENTRY_ENUM(cuStreamBatchMemOp_ptsz),
    CUDA_ENTRY_ENUM(cuStreamCreate),
    CUDA_ENTRY_ENUM(cuStreamCreateWithPriority),
    CUDA_ENTRY_ENUM(cuStreamGetPriority),
    CUDA_ENTRY_ENUM(cuStreamGetPriority_ptsz),
    CUDA_ENTRY_ENUM(cuStreamGetFlags),
    CUDA_ENTRY_ENUM(cuStreamGetFlags_ptsz),
    CUDA_ENTRY_ENUM(cuStreamDestroy_v2),
    CUDA_ENTRY_ENUM(cuStreamWaitEvent),
    CUDA_ENTRY_ENUM(cuStreamWaitEvent_ptsz),
    CUDA_ENTRY_ENUM(cuStreamAddCallback),
    CUDA_ENTRY_ENUM(cuStreamAddCallback_ptsz),
    CUDA_ENTRY_ENUM(cuStreamSynchronize),
    CUDA_ENTRY_ENUM(cuStreamSynchronize_ptsz),
    CUDA_ENTRY_ENUM(cuStreamQuery),
    CUDA_ENTRY_ENUM(cuStreamQuery_ptsz),
    CUDA_ENTRY_ENUM(cuStreamAttachMemAsync),
    CUDA_ENTRY_ENUM(cuStreamAttachMemAsync_ptsz),
    CUDA_ENTRY_ENUM(cuDeviceCanAccessPeer),
    CUDA_ENTRY_ENUM(cuCtxEnablePeerAccess),
    CUDA_ENTRY_ENUM(cuCtxDisablePeerAccess),
    CUDA_ENTRY_ENUM(cuIpcGetEventHandle),
    CUDA_ENTRY_ENUM(cuIpcOpenEventHandle),
    CUDA_ENTRY_ENUM(cuIpcOpenMemHandle),
    CUDA_ENTRY_ENUM(cuIpcCloseMemHandle), // 128
    CUDA_ENTRY_ENUM(cuIpcGetMemHandle),   // 130

    CUDA_ENTRY_ENUM(cuGLCtxCreate_v2),
    CUDA_ENTRY_ENUM(cuGLInit),
    CUDA_ENTRY_ENUM(cuGLGetDevices),
    CUDA_ENTRY_ENUM(cuGLRegisterBufferObject),
    CUDA_ENTRY_ENUM(cuGLMapBufferObject_v2),
    CUDA_ENTRY_ENUM(cuGLMapBufferObject_v2_ptds),
    CUDA_ENTRY_ENUM(cuGLMapBufferObjectAsync_v2),
    CUDA_ENTRY_ENUM(cuGLMapBufferObjectAsync_v2_ptsz),
    CUDA_ENTRY_ENUM(cuGLUnmapBufferObject),
    CUDA_ENTRY_ENUM(cuGLUnmapBufferObjectAsync),
    CUDA_ENTRY_ENUM(cuGLUnregisterBufferObject),
    CUDA_ENTRY_ENUM(cuGLSetBufferObjectMapFlags),
    CUDA_ENTRY_ENUM(cuGraphicsGLRegisterImage),
    CUDA_ENTRY_ENUM(cuGraphicsGLRegisterBuffer),
    CUDA_ENTRY_ENUM(cuGraphicsUnregisterResource),
    CUDA_ENTRY_ENUM(cuGraphicsMapResources),
    CUDA_ENTRY_ENUM(cuGraphicsMapResources_ptsz),
    CUDA_ENTRY_ENUM(cuGraphicsUnmapResources),
    CUDA_ENTRY_ENUM(cuGraphicsUnmapResources_ptsz),
    CUDA_ENTRY_ENUM(cuGraphicsResourceSetMapFlags_v2),
    CUDA_ENTRY_ENUM(cuGraphicsSubResourceGetMappedArray),
    CUDA_ENTRY_ENUM(cuGraphicsResourceGetMappedMipmappedArray),
    CUDA_ENTRY_ENUM(cuGraphicsResourceGetMappedPointer_v2),
    CUDA_ENTRY_ENUM(cuProfilerInitialize),
    CUDA_ENTRY_ENUM(cuProfilerStart),
    CUDA_ENTRY_ENUM(cuProfilerStop),
    CUDA_ENTRY_ENUM(cuVDPAUGetDevice),
    CUDA_ENTRY_ENUM(cuVDPAUCtxCreate_v2),
    CUDA_ENTRY_ENUM(cuGraphicsVDPAURegisterVideoSurface),
    CUDA_ENTRY_ENUM(cuGraphicsVDPAURegisterOutputSurface),
    CUDA_ENTRY_ENUM(cuGetExportTable),
    CUDA_ENTRY_ENUM(cuOccupancyMaxActiveBlocksPerMultiprocessor),
    CUDA_ENTRY_ENUM(cuMemAdvise),
    CUDA_ENTRY_ENUM(cuMemPrefetchAsync), // 272
    CUDA_ENTRY_ENUM(cuMemPrefetchAsync_ptsz),
    CUDA_ENTRY_ENUM(cuMemRangeGetAttribute),  // 274
    CUDA_ENTRY_ENUM(cuMemRangeGetAttributes), // 276
    CUDA_ENTRY_ENUM(cuGetErrorString),
    CUDA_ENTRY_ENUM(cuGetErrorName),
    CUDA_ENTRY_ENUM(cuArray3DCreate),
    CUDA_ENTRY_ENUM(cuArray3DGetDescriptor),
    CUDA_ENTRY_ENUM(cuArrayCreate),
    CUDA_ENTRY_ENUM(cuArrayGetDescriptor),
    CUDA_ENTRY_ENUM(cuCtxAttach),
    CUDA_ENTRY_ENUM(cuCtxCreate),
    CUDA_ENTRY_ENUM(cuCtxDestroy),
    CUDA_ENTRY_ENUM(cuCtxDestroy_v2),
    CUDA_ENTRY_ENUM(cuCtxPopCurrent),
    CUDA_ENTRY_ENUM(cuCtxPopCurrent_v2),
    CUDA_ENTRY_ENUM(cuCtxPushCurrent),
    CUDA_ENTRY_ENUM(cuCtxPushCurrent_v2),
    CUDA_ENTRY_ENUM(cudbgApiAttach),
    CUDA_ENTRY_ENUM(cudbgApiDetach),
    CUDA_ENTRY_ENUM(cudbgApiInit),
    CUDA_ENTRY_ENUM(cudbgGetAPI),
    CUDA_ENTRY_ENUM(cudbgGetAPIVersion),
    CUDA_ENTRY_ENUM(cudbgMain),
    CUDA_ENTRY_ENUM(cudbgReportDriverApiError),
    CUDA_ENTRY_ENUM(cudbgReportDriverInternalError),
    CUDA_ENTRY_ENUM(cuDeviceComputeCapability),
    CUDA_ENTRY_ENUM(cuDeviceGetProperties),
    CUDA_ENTRY_ENUM(cuDeviceTotalMem),
    CUDA_ENTRY_ENUM(cuEGLInit),
    CUDA_ENTRY_ENUM(cuEGLStreamConsumerAcquireFrame),
    CUDA_ENTRY_ENUM(cuEGLStreamConsumerConnect),
    CUDA_ENTRY_ENUM(cuEGLStreamConsumerConnectWithFlags),
    CUDA_ENTRY_ENUM(cuEGLStreamConsumerDisconnect),
    CUDA_ENTRY_ENUM(cuEGLStreamConsumerReleaseFrame),
    CUDA_ENTRY_ENUM(cuEGLStreamProducerConnect),
    CUDA_ENTRY_ENUM(cuEGLStreamProducerDisconnect),
    CUDA_ENTRY_ENUM(cuEGLStreamProducerPresentFrame),
    CUDA_ENTRY_ENUM(cuEGLStreamProducerReturnFrame),
    CUDA_ENTRY_ENUM(cuEventDestroy),
    CUDA_ENTRY_ENUM(cuFuncSetAttribute),
    CUDA_ENTRY_ENUM(cuFuncSetBlockShape),
    CUDA_ENTRY_ENUM(cuFuncSetSharedSize),
    CUDA_ENTRY_ENUM(cuGLCtxCreate),
    CUDA_ENTRY_ENUM(cuGLGetDevices_v2),
    CUDA_ENTRY_ENUM(cuGLMapBufferObject),
    CUDA_ENTRY_ENUM(cuGLMapBufferObjectAsync),
    CUDA_ENTRY_ENUM(cuGraphicsEGLRegisterImage),
    CUDA_ENTRY_ENUM(cuGraphicsResourceGetMappedEglFrame),
    CUDA_ENTRY_ENUM(cuGraphicsResourceGetMappedPointer),
    CUDA_ENTRY_ENUM(cuGraphicsResourceSetMapFlags),
    CUDA_ENTRY_ENUM(cuLaunch),
    CUDA_ENTRY_ENUM(cuLaunchCooperativeKernel), // 190
    CUDA_ENTRY_ENUM(cuLaunchCooperativeKernelMultiDevice),
    CUDA_ENTRY_ENUM(cuLaunchCooperativeKernel_ptsz),
    CUDA_ENTRY_ENUM(cuLaunchGrid),
    CUDA_ENTRY_ENUM(cuLaunchGridAsync),
    CUDA_ENTRY_ENUM(cuLinkAddData_v2),
    CUDA_ENTRY_ENUM(cuLinkAddFile_v2),
    CUDA_ENTRY_ENUM(cuLinkCreate_v2),
    CUDA_ENTRY_ENUM(cuMemAlloc),
    CUDA_ENTRY_ENUM(cuMemAllocHost),
    CUDA_ENTRY_ENUM(cuMemAllocHost_v2),
    CUDA_ENTRY_ENUM(cuMemAllocPitch),
    CUDA_ENTRY_ENUM(cuMemcpy2D),
    CUDA_ENTRY_ENUM(cuMemcpy2DAsync),
    CUDA_ENTRY_ENUM(cuMemcpy2DUnaligned),
    CUDA_ENTRY_ENUM(cuMemcpy2D_v2),
    CUDA_ENTRY_ENUM(cuMemcpy2D_v2_ptds),
    CUDA_ENTRY_ENUM(cuMemcpy3D),
    CUDA_ENTRY_ENUM(cuMemcpy3DAsync),
    CUDA_ENTRY_ENUM(cuMemcpyAtoA),
    CUDA_ENTRY_ENUM(cuMemcpyAtoA_v2),
    CUDA_ENTRY_ENUM(cuMemcpyAtoA_v2_ptds),
    CUDA_ENTRY_ENUM(cuMemcpyAtoD),
    CUDA_ENTRY_ENUM(cuMemcpyAtoD_v2),
    CUDA_ENTRY_ENUM(cuMemcpyAtoD_v2_ptds),
    CUDA_ENTRY_ENUM(cuMemcpyAtoH),
    CUDA_ENTRY_ENUM(cuMemcpyAtoHAsync),
    CUDA_ENTRY_ENUM(cuMemcpyAtoHAsync_v2),
    CUDA_ENTRY_ENUM(cuMemcpyAtoHAsync_v2_ptsz),
    CUDA_ENTRY_ENUM(cuMemcpyAtoH_v2),
    CUDA_ENTRY_ENUM(cuMemcpyAtoH_v2_ptds),
    CUDA_ENTRY_ENUM(cuMemcpyDtoA),
    CUDA_ENTRY_ENUM(cuMemcpyDtoA_v2),
    CUDA_ENTRY_ENUM(cuMemcpyDtoA_v2_ptds),
    CUDA_ENTRY_ENUM(cuMemcpyDtoD),
    CUDA_ENTRY_ENUM(cuMemcpyDtoDAsync),
    CUDA_ENTRY_ENUM(cuMemcpyDtoH),
    CUDA_ENTRY_ENUM(cuMemcpyDtoHAsync),
    CUDA_ENTRY_ENUM(cuMemcpyHtoA),
    CUDA_ENTRY_ENUM(cuMemcpyHtoAAsync),
    CUDA_ENTRY_ENUM(cuMemcpyHtoAAsync_v2),
    CUDA_ENTRY_ENUM(cuMemcpyHtoAAsync_v2_ptsz),
    CUDA_ENTRY_ENUM(cuMemcpyHtoA_v2),
    CUDA_ENTRY_ENUM(cuMemcpyHtoA_v2_ptds),
    CUDA_ENTRY_ENUM(cuMemcpyHtoD),
    CUDA_ENTRY_ENUM(cuMemcpyHtoDAsync),
    CUDA_ENTRY_ENUM(cuMemFree),
    CUDA_ENTRY_ENUM(cuMemGetAddressRange),
    // Deprecated
    // CUDA_ENTRY_ENUM(cuMemGetAttribute),
    // CUDA_ENTRY_ENUM(cuMemGetAttribute_v2),
    CUDA_ENTRY_ENUM(cuMemGetInfo),
    CUDA_ENTRY_ENUM(cuMemHostGetDevicePointer),
    CUDA_ENTRY_ENUM(cuMemHostRegister),
    CUDA_ENTRY_ENUM(cuMemsetD16),
    CUDA_ENTRY_ENUM(cuMemsetD16Async), // 156
    CUDA_ENTRY_ENUM(cuMemsetD16Async_ptsz),
    CUDA_ENTRY_ENUM(cuMemsetD16_v2), // 154
    CUDA_ENTRY_ENUM(cuMemsetD16_v2_ptds),
    CUDA_ENTRY_ENUM(cuMemsetD2D16),
    CUDA_ENTRY_ENUM(cuMemsetD2D16Async),
    CUDA_ENTRY_ENUM(cuMemsetD2D16Async_ptsz),
    CUDA_ENTRY_ENUM(cuMemsetD2D16_v2), // 158
    CUDA_ENTRY_ENUM(cuMemsetD2D16_v2_ptds),
    CUDA_ENTRY_ENUM(cuMemsetD2D32),
    CUDA_ENTRY_ENUM(cuMemsetD2D32Async), // 164
    CUDA_ENTRY_ENUM(cuMemsetD2D32Async_ptsz),
    CUDA_ENTRY_ENUM(cuMemsetD2D32_v2),
    CUDA_ENTRY_ENUM(cuMemsetD2D32_v2_ptds),
    CUDA_ENTRY_ENUM(cuMemsetD2D8),
    CUDA_ENTRY_ENUM(cuMemsetD32),
    CUDA_ENTRY_ENUM(cuMemsetD32Async), // 172
    CUDA_ENTRY_ENUM(cuMemsetD32Async_ptsz),
    CUDA_ENTRY_ENUM(cuMemsetD32_v2), // 170
    CUDA_ENTRY_ENUM(cuMemsetD32_v2_ptds),
    CUDA_ENTRY_ENUM(cuMemsetD8),
    CUDA_ENTRY_ENUM(cuModuleGetGlobal),
    CUDA_ENTRY_ENUM(cuModuleLoadDataEx),
    CUDA_ENTRY_ENUM(cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags),
    CUDA_ENTRY_ENUM(cuOccupancyMaxPotentialBlockSize),
    CUDA_ENTRY_ENUM(cuOccupancyMaxPotentialBlockSizeWithFlags),
    CUDA_ENTRY_ENUM(cuParamSetf),
    CUDA_ENTRY_ENUM(cuParamSeti),
    CUDA_ENTRY_ENUM(cuParamSetSize),
    CUDA_ENTRY_ENUM(cuParamSetTexRef),
    CUDA_ENTRY_ENUM(cuParamSetv),
    CUDA_ENTRY_ENUM(cuPointerSetAttribute), // 126
    CUDA_ENTRY_ENUM(cuStreamDestroy),
    CUDA_ENTRY_ENUM(cuStreamWaitValue64),
    CUDA_ENTRY_ENUM(cuStreamWaitValue64_ptsz),
    CUDA_ENTRY_ENUM(cuStreamWriteValue64),
    CUDA_ENTRY_ENUM(cuStreamWriteValue64_ptsz),
    CUDA_ENTRY_ENUM(cuSurfRefGetArray),
    CUDA_ENTRY_ENUM(cuTexRefGetAddress),
    CUDA_ENTRY_ENUM(cuTexRefGetAddressMode),
    CUDA_ENTRY_ENUM(cuTexRefGetAddress_v2),
    CUDA_ENTRY_ENUM(cuTexRefGetArray),
    CUDA_ENTRY_ENUM(cuTexRefGetFilterMode),
    CUDA_ENTRY_ENUM(cuTexRefGetFlags),
    CUDA_ENTRY_ENUM(cuTexRefGetFormat),
    CUDA_ENTRY_ENUM(cuTexRefGetMaxAnisotropy),
    CUDA_ENTRY_ENUM(cuTexRefGetMipmapFilterMode),
    CUDA_ENTRY_ENUM(cuTexRefGetMipmapLevelBias),
    CUDA_ENTRY_ENUM(cuTexRefGetMipmapLevelClamp),
    CUDA_ENTRY_ENUM(cuTexRefGetMipmappedArray),
    CUDA_ENTRY_ENUM(cuTexRefSetAddress),
    CUDA_ENTRY_ENUM(cuTexRefSetAddress2D),
    CUDA_ENTRY_ENUM(cuTexRefSetAddress2D_v2),
    CUDA_ENTRY_ENUM(cuVDPAUCtxCreate),
    CUDA_ENTRY_ENUM(cuEGLApiInit),
    CUDA_ENTRY_ENUM(cuExternalMemoryGetMappedBuffer),         // 280
    CUDA_ENTRY_ENUM(cuExternalMemoryGetMappedMipmappedArray), // 282
    CUDA_ENTRY_ENUM(cuDestroyExternalMemory),                 // 284
    CUDA_ENTRY_ENUM(cuDestroyExternalSemaphore),              // 292
    CUDA_ENTRY_ENUM(cuDeviceGetUuid),
    CUDA_ENTRY_ENUM(cuGraphAddChildGraphNode),
    CUDA_ENTRY_ENUM(cuGraphAddDependencies),
    CUDA_ENTRY_ENUM(cuGraphAddEmptyNode),
    CUDA_ENTRY_ENUM(cuGraphAddHostNode),
    CUDA_ENTRY_ENUM(cuGraphAddKernelNode),
    CUDA_ENTRY_ENUM(cuGraphAddMemcpyNode),
    CUDA_ENTRY_ENUM(cuGraphAddMemsetNode),
    CUDA_ENTRY_ENUM(cuGraphChildGraphNodeGetGraph),
    CUDA_ENTRY_ENUM(cuGraphClone),
    CUDA_ENTRY_ENUM(cuGraphCreate),
    CUDA_ENTRY_ENUM(cuGraphDestroy),
    CUDA_ENTRY_ENUM(cuGraphDestroyNode),
    CUDA_ENTRY_ENUM(cuGraphExecDestroy),
    CUDA_ENTRY_ENUM(cuGraphGetEdges),
    CUDA_ENTRY_ENUM(cuGraphGetNodes),
    CUDA_ENTRY_ENUM(cuGraphGetRootNodes),
    CUDA_ENTRY_ENUM(cuGraphHostNodeGetParams),
    CUDA_ENTRY_ENUM(cuGraphHostNodeSetParams),
    CUDA_ENTRY_ENUM(cuGraphInstantiate),
    CUDA_ENTRY_ENUM(cuGraphKernelNodeGetParams),
    CUDA_ENTRY_ENUM(cuGraphKernelNodeSetParams),
    CUDA_ENTRY_ENUM(cuGraphLaunch),
    CUDA_ENTRY_ENUM(cuGraphLaunch_ptsz),
    CUDA_ENTRY_ENUM(cuGraphMemcpyNodeGetParams),
    CUDA_ENTRY_ENUM(cuGraphMemcpyNodeSetParams),
    CUDA_ENTRY_ENUM(cuGraphMemsetNodeGetParams),
    CUDA_ENTRY_ENUM(cuGraphMemsetNodeSetParams),
    CUDA_ENTRY_ENUM(cuGraphNodeFindInClone),
    CUDA_ENTRY_ENUM(cuGraphNodeGetDependencies),
    CUDA_ENTRY_ENUM(cuGraphNodeGetDependentNodes),
    CUDA_ENTRY_ENUM(cuGraphNodeGetType),
    CUDA_ENTRY_ENUM(cuGraphRemoveDependencies),
    CUDA_ENTRY_ENUM(cuImportExternalMemory),    // 278
    CUDA_ENTRY_ENUM(cuImportExternalSemaphore), // 286
    CUDA_ENTRY_ENUM(cuLaunchHostFunc),
    CUDA_ENTRY_ENUM(cuLaunchHostFunc_ptsz),
    CUDA_ENTRY_ENUM(cuSignalExternalSemaphoresAsync), // 288
    CUDA_ENTRY_ENUM(cuSignalExternalSemaphoresAsync_ptsz),
    CUDA_ENTRY_ENUM(cuStreamBeginCapture),
    CUDA_ENTRY_ENUM(cuStreamBeginCapture_ptsz),
    CUDA_ENTRY_ENUM(cuStreamEndCapture),
    CUDA_ENTRY_ENUM(cuStreamEndCapture_ptsz),
    CUDA_ENTRY_ENUM(cuStreamGetCtx),
    CUDA_ENTRY_ENUM(cuStreamGetCtx_ptsz),
    CUDA_ENTRY_ENUM(cuStreamIsCapturing),
    CUDA_ENTRY_ENUM(cuStreamIsCapturing_ptsz),
    CUDA_ENTRY_ENUM(cuWaitExternalSemaphoresAsync), // 290
    CUDA_ENTRY_ENUM(cuWaitExternalSemaphoresAsync_ptsz),
    CUDA_ENTRY_ENUM(cuGraphExecKernelNodeSetParams),
    CUDA_ENTRY_ENUM(cuStreamBeginCapture_v2),
    CUDA_ENTRY_ENUM(cuStreamBeginCapture_v2_ptsz),
    CUDA_ENTRY_ENUM(cuStreamGetCaptureInfo),
    CUDA_ENTRY_ENUM(cuStreamGetCaptureInfo_ptsz),
    CUDA_ENTRY_ENUM(cuThreadExchangeStreamCaptureMode),
    CUDA_ENTRY_ENUM(cuDeviceGetNvSciSyncAttributes),
    CUDA_ENTRY_ENUM(cuGraphExecHostNodeSetParams),
    CUDA_ENTRY_ENUM(cuGraphExecMemcpyNodeSetParams),
    CUDA_ENTRY_ENUM(cuGraphExecMemsetNodeSetParams),
    CUDA_ENTRY_ENUM(cuGraphExecUpdate),
    CUDA_ENTRY_ENUM(cuMemAddressFree),
    CUDA_ENTRY_ENUM(cuMemAddressReserve), // 224
    CUDA_ENTRY_ENUM(cuMemCreate),         // 226
    CUDA_ENTRY_ENUM(cuMemExportToShareableHandle),
    CUDA_ENTRY_ENUM(cuMemGetAccess),
    CUDA_ENTRY_ENUM(cuMemGetAllocationGranularity),
    CUDA_ENTRY_ENUM(cuMemGetAllocationPropertiesFromHandle),
    CUDA_ENTRY_ENUM(cuMemImportFromShareableHandle),
    CUDA_ENTRY_ENUM(cuMemMap), // 228
    CUDA_ENTRY_ENUM(cuMemRelease),
    CUDA_ENTRY_ENUM(cuMemSetAccess),
    CUDA_ENTRY_ENUM(cuMemUnmap),
    CUDA_ENTRY_ENUM(cuCtxResetPersistingL2Cache),
    CUDA_ENTRY_ENUM(cuDevicePrimaryCtxRelease_v2),
    CUDA_ENTRY_ENUM(cuDevicePrimaryCtxReset_v2),
    CUDA_ENTRY_ENUM(cuDevicePrimaryCtxSetFlags_v2),
    CUDA_ENTRY_ENUM(cuFuncGetModule),
    CUDA_ENTRY_ENUM(cuGraphInstantiate_v2),
    CUDA_ENTRY_ENUM(cuGraphKernelNodeCopyAttributes),
    CUDA_ENTRY_ENUM(cuGraphKernelNodeGetAttribute),
    CUDA_ENTRY_ENUM(cuGraphKernelNodeSetAttribute),
    CUDA_ENTRY_ENUM(cuMemRetainAllocationHandle),
    CUDA_ENTRY_ENUM(cuOccupancyAvailableDynamicSMemPerBlock),
    CUDA_ENTRY_ENUM(cuStreamCopyAttributes),
    CUDA_ENTRY_ENUM(cuStreamCopyAttributes_ptsz),
    CUDA_ENTRY_ENUM(cuStreamGetAttribute),
    CUDA_ENTRY_ENUM(cuStreamGetAttribute_ptsz),
    CUDA_ENTRY_ENUM(cuStreamSetAttribute),
    CUDA_ENTRY_ENUM(cuStreamSetAttribute_ptsz),
    // 11.2
    CUDA_ENTRY_ENUM(cuArrayGetPlane),
    CUDA_ENTRY_ENUM(cuArrayGetSparseProperties),
    CUDA_ENTRY_ENUM(cuDeviceGetDefaultMemPool),
    CUDA_ENTRY_ENUM(cuDeviceGetLuid),
    CUDA_ENTRY_ENUM(cuDeviceGetMemPool),
    CUDA_ENTRY_ENUM(cuDeviceGetTexture1DLinearMaxWidth),
    CUDA_ENTRY_ENUM(cuDeviceSetMemPool),
    CUDA_ENTRY_ENUM(cuEventRecordWithFlags),
    CUDA_ENTRY_ENUM(cuEventRecordWithFlags_ptsz),
    CUDA_ENTRY_ENUM(cuGraphAddEventRecordNode),
    CUDA_ENTRY_ENUM(cuGraphAddEventWaitNode),
    CUDA_ENTRY_ENUM(cuGraphAddExternalSemaphoresSignalNode),
    CUDA_ENTRY_ENUM(cuGraphAddExternalSemaphoresWaitNode),
    CUDA_ENTRY_ENUM(cuGraphEventRecordNodeGetEvent),
    CUDA_ENTRY_ENUM(cuGraphEventRecordNodeSetEvent),
    CUDA_ENTRY_ENUM(cuGraphEventWaitNodeGetEvent),
    CUDA_ENTRY_ENUM(cuGraphEventWaitNodeSetEvent),
    CUDA_ENTRY_ENUM(cuGraphExecChildGraphNodeSetParams),
    CUDA_ENTRY_ENUM(cuGraphExecEventRecordNodeSetEvent),
    CUDA_ENTRY_ENUM(cuGraphExecEventWaitNodeSetEvent),
    CUDA_ENTRY_ENUM(cuGraphExecExternalSemaphoresSignalNodeSetParams),
    CUDA_ENTRY_ENUM(cuGraphExecExternalSemaphoresWaitNodeSetParams),
    CUDA_ENTRY_ENUM(cuGraphExternalSemaphoresSignalNodeGetParams),
    CUDA_ENTRY_ENUM(cuGraphExternalSemaphoresSignalNodeSetParams),
    CUDA_ENTRY_ENUM(cuGraphExternalSemaphoresWaitNodeGetParams),
    CUDA_ENTRY_ENUM(cuGraphExternalSemaphoresWaitNodeSetParams),
    CUDA_ENTRY_ENUM(cuGraphUpload),
    CUDA_ENTRY_ENUM(cuGraphUpload_ptsz),
    CUDA_ENTRY_ENUM(cuIpcOpenMemHandle_v2), // 132
    CUDA_ENTRY_ENUM(cuMemAllocAsync),       // 230
    CUDA_ENTRY_ENUM(cuMemAllocAsync_ptsz),
    CUDA_ENTRY_ENUM(cuMemAllocFromPoolAsync), // 250
    CUDA_ENTRY_ENUM(cuMemAllocFromPoolAsync_ptsz),
    CUDA_ENTRY_ENUM(cuMemFreeAsync),
    CUDA_ENTRY_ENUM(cuMemFreeAsync_ptsz),
    CUDA_ENTRY_ENUM(cuMemMapArrayAsync),
    CUDA_ENTRY_ENUM(cuMemMapArrayAsync_ptsz),
    CUDA_ENTRY_ENUM(cuMemPoolCreate),                    // 246
    CUDA_ENTRY_ENUM(cuMemPoolDestroy),                   // 248
    CUDA_ENTRY_ENUM(cuMemPoolExportPointer),             // 256
    CUDA_ENTRY_ENUM(cuMemPoolExportToShareableHandle),   // 252
    CUDA_ENTRY_ENUM(cuMemPoolGetAccess),                 // 244
    CUDA_ENTRY_ENUM(cuMemPoolGetAttribute),              // 240
    CUDA_ENTRY_ENUM(cuMemPoolImportFromShareableHandle), // 254
    CUDA_ENTRY_ENUM(cuMemPoolImportPointer),             // 258
    CUDA_ENTRY_ENUM(cuMemPoolSetAccess),                 // 242
    CUDA_ENTRY_ENUM(cuMemPoolSetAttribute),              // 238
    CUDA_ENTRY_ENUM(cuMemPoolTrimTo),                    // 236
    CUDA_ENTRY_ENUM(cuMipmappedArrayGetSparseProperties),
    CUDA_ENTRY_ENUM(cuCtxCreate_v3),
    CUDA_ENTRY_ENUM(cuCtxGetExecAffinity),
    CUDA_ENTRY_ENUM(cuDeviceGetExecAffinitySupport),
    CUDA_ENTRY_ENUM(cuDeviceGetGraphMemAttribute),
    CUDA_ENTRY_ENUM(cuDeviceGetUuid_v2),
    CUDA_ENTRY_ENUM(cuDeviceGraphMemTrim),
    CUDA_ENTRY_ENUM(cuDeviceSetGraphMemAttribute),
    CUDA_ENTRY_ENUM(cuFlushGPUDirectRDMAWrites),
    CUDA_ENTRY_ENUM(cuGetProcAddress),
    CUDA_ENTRY_ENUM(cuGraphAddMemAllocNode),
    CUDA_ENTRY_ENUM(cuGraphAddMemFreeNode),
    CUDA_ENTRY_ENUM(cuGraphDebugDotPrint),
    CUDA_ENTRY_ENUM(cuGraphInstantiateWithFlags),
    CUDA_ENTRY_ENUM(cuGraphMemAllocNodeGetParams),
    CUDA_ENTRY_ENUM(cuGraphMemFreeNodeGetParams),
    CUDA_ENTRY_ENUM(cuGraphReleaseUserObject),
    CUDA_ENTRY_ENUM(cuGraphRetainUserObject),
    CUDA_ENTRY_ENUM(cuStreamGetCaptureInfo_v2),
    CUDA_ENTRY_ENUM(cuStreamGetCaptureInfo_v2_ptsz),
    CUDA_ENTRY_ENUM(cuStreamUpdateCaptureDependencies),
    CUDA_ENTRY_ENUM(cuStreamUpdateCaptureDependencies_ptsz),
    CUDA_ENTRY_ENUM(cuUserObjectCreate),
    CUDA_ENTRY_ENUM(cuUserObjectRelease),
    CUDA_ENTRY_ENUM(cuUserObjectRetain),
    CUDA_ENTRY_END
} cuda_entry_enum_t;
/**
 * CUDA library function pointer
 */
typedef CUresult (*cuda_sym_t)();
/**
 * CUDA library debug function pointer
 */
typedef void (*cuda_debug_void_sym_t)();
#ifdef __cplusplus
}
#endif
#endif // HIJACK_CUDA_HELPER_H