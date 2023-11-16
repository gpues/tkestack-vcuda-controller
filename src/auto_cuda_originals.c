
// auto generate 375 apis

#include <assert.h>

#include "include/auto-cuda-helper.h"
#include "include/hijack-info.h"

extern entry_t cuda_library_entry[];

CUresult cuGetErrorString(CUresult error, const char **pStr) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGetErrorString, error, pStr);
}

CUresult cuGetErrorName(CUresult error, const char **pStr) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGetErrorName, error, pStr);
}

CUresult cuDeviceGet(CUdevice *device, int ordinal) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGet, device, ordinal);
}

CUresult cuDeviceGetCount(int *count) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetCount, count);
}

CUresult cuDeviceGetName(char *name, int len, CUdevice dev) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetName, name, len, dev);
}

CUresult cuDeviceGetUuid(CUuuid *uuid, CUdevice dev) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetUuid, uuid, dev);
}

CUresult cuDeviceGetUuid_v2(CUuuid *uuid, CUdevice dev) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetUuid_v2, uuid, dev);
}

CUresult cuDeviceGetLuid(char *luid, unsigned int *deviceNodeMask, CUdevice dev) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetLuid, luid, deviceNodeMask, dev);
}

CUresult cuDeviceGetTexture1DLinearMaxWidth(size_t *maxWidthInElements, CUarray_format format, unsigned numChannels, CUdevice dev) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetTexture1DLinearMaxWidth, maxWidthInElements, format, numChannels, dev);
}

CUresult cuDeviceGetAttribute(int *pi, CUdevice_attribute attrib, CUdevice dev) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetAttribute, pi, attrib, dev);
}

CUresult cuDeviceGetNvSciSyncAttributes(void *nvSciSyncAttrList, CUdevice dev, int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetNvSciSyncAttributes, nvSciSyncAttrList, dev, flags);
}

CUresult cuDeviceSetMemPool(CUdevice dev, CUmemoryPool pool) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceSetMemPool, dev, pool);
}

CUresult cuDeviceGetMemPool(CUmemoryPool *pool, CUdevice dev) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetMemPool, pool, dev);
}

CUresult cuDeviceGetDefaultMemPool(CUmemoryPool *pool_out, CUdevice dev) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetDefaultMemPool, pool_out, dev);
}

CUresult cuDeviceGetExecAffinitySupport(int *pi, CUexecAffinityType type, CUdevice dev) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetExecAffinitySupport, pi, type, dev);
}

CUresult cuFlushGPUDirectRDMAWrites(CUflushGPUDirectRDMAWritesTarget target, CUflushGPUDirectRDMAWritesScope scope) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuFlushGPUDirectRDMAWrites, target, scope);
}

CUresult cuDeviceGetProperties(CUdevprop *prop, CUdevice dev) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetProperties, prop, dev);
}

CUresult cuDeviceComputeCapability(int *major, int *minor, CUdevice dev) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceComputeCapability, major, minor, dev);
}

CUresult cuDevicePrimaryCtxRetain(CUcontext *pctx, CUdevice dev) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDevicePrimaryCtxRetain, pctx, dev);
}

CUresult cuDevicePrimaryCtxRelease(CUdevice dev) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDevicePrimaryCtxRelease, dev);
}

CUresult cuDevicePrimaryCtxSetFlags(CUdevice dev, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDevicePrimaryCtxSetFlags, dev, flags);
}

CUresult cuDevicePrimaryCtxGetState(CUdevice dev, unsigned int *flags, int *active) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDevicePrimaryCtxGetState, dev, flags, active);
}

CUresult cuDevicePrimaryCtxReset(CUdevice dev) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDevicePrimaryCtxReset, dev);
}

CUresult cuCtxCreate(CUcontext *pctx, unsigned int flags, CUdevice dev) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxCreate, pctx, flags, dev);
}

CUresult cuCtxCreate_v3(CUcontext *pctx, CUexecAffinityParam *paramsArray, int numParams, unsigned int flags, CUdevice dev) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxCreate_v3, pctx, paramsArray, numParams, flags, dev);
}

CUresult cuCtxDestroy(CUcontext ctx) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxDestroy, ctx);
}

CUresult cuCtxPushCurrent(CUcontext ctx) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxPushCurrent, ctx);
}

CUresult cuCtxPopCurrent(CUcontext *pctx) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxPopCurrent, pctx);
}

CUresult cuCtxSetCurrent(CUcontext ctx) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxSetCurrent, ctx);
}

CUresult cuCtxGetCurrent(CUcontext *pctx) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetCurrent, pctx);
}

CUresult cuCtxGetDevice(CUdevice *device) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetDevice, device);
}

CUresult cuCtxGetFlags(unsigned int *flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetFlags, flags);
}

CUresult cuCtxSetFlags(unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxSetFlags, flags);
}

CUresult cuCtxGetId(CUcontext ctx, unsigned long long *ctxId) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetId, ctx, ctxId);
}

CUresult cuCtxSynchronize() {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxSynchronize, );
}

CUresult cuCtxSetLimit(CUlimit limit, size_t value) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxSetLimit, limit, value);
}

CUresult cuCtxGetLimit(size_t *pvalue, CUlimit limit) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetLimit, pvalue, limit);
}

CUresult cuCtxGetCacheConfig(CUfunc_cache *pconfig) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetCacheConfig, pconfig);
}

CUresult cuCtxSetCacheConfig(CUfunc_cache config) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxSetCacheConfig, config);
}

CUresult cuCtxGetSharedMemConfig(CUsharedconfig *pConfig) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetSharedMemConfig, pConfig);
}

CUresult cuCtxSetSharedMemConfig(CUsharedconfig config) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxSetSharedMemConfig, config);
}

CUresult cuCtxGetApiVersion(CUcontext ctx, unsigned int *version) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetApiVersion, ctx, version);
}

CUresult cuCtxGetStreamPriorityRange(int *leastPriority, int *greatestPriority) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetStreamPriorityRange, leastPriority, greatestPriority);
}

CUresult cuCtxResetPersistingL2Cache() {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxResetPersistingL2Cache, );
}

CUresult cuCtxGetExecAffinity(CUexecAffinityParam *pExecAffinity, CUexecAffinityType type) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetExecAffinity, pExecAffinity, type);
}

CUresult cuCtxAttach(CUcontext *pctx, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxAttach, pctx, flags);
}

CUresult cuCtxDetach(CUcontext ctx) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxDetach, ctx);
}

CUresult cuModuleLoad(CUmodule *module, const char *fname) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleLoad, module, fname);
}

CUresult cuModuleLoadData(CUmodule *module, const void *image) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleLoadData, module, image);
}

CUresult cuModuleLoadDataEx(CUmodule *module, const void *image, unsigned int numOptions, CUjit_option *options, void **optionValues) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleLoadDataEx, module, image, numOptions, options, optionValues);
}

CUresult cuModuleLoadFatBinary(CUmodule *module, const void *fatCubin) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleLoadFatBinary, module, fatCubin);
}

CUresult cuModuleUnload(CUmodule hmod) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleUnload, hmod);
}

CUresult cuModuleGetLoadingMode(CUmoduleLoadingMode *mode) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleGetLoadingMode, mode);
}

CUresult cuModuleGetFunction(CUfunction *hfunc, CUmodule hmod, const char *name) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleGetFunction, hfunc, hmod, name);
}

CUresult cuModuleGetGlobal(CUdeviceptr *dptr, size_t *bytes, CUmodule hmod, const char *name) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleGetGlobal, dptr, bytes, hmod, name);
}

CUresult cuLinkCreate(unsigned int numOptions, CUjit_option *options, void **optionValues, CUlinkState *stateOut) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLinkCreate, numOptions, options, optionValues, stateOut);
}

CUresult cuLinkAddData(CUlinkState state, CUjitInputType type, void *data, size_t size, const char *name, unsigned int numOptions, CUjit_option *options, void **optionValues) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLinkAddData, state, type, data, size, name, numOptions, options, optionValues);
}

CUresult cuLinkAddFile(CUlinkState state, CUjitInputType type, const char *path, unsigned int numOptions, CUjit_option *options, void **optionValues) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLinkAddFile, state, type, path, numOptions, options, optionValues);
}

CUresult cuLinkComplete(CUlinkState state, void **cubinOut, size_t *sizeOut) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLinkComplete, state, cubinOut, sizeOut);
}

CUresult cuLinkDestroy(CUlinkState state) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLinkDestroy, state);
}

CUresult cuModuleGetTexRef(CUtexref *pTexRef, CUmodule hmod, const char *name) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleGetTexRef, pTexRef, hmod, name);
}

CUresult cuModuleGetSurfRef(CUsurfref *pSurfRef, CUmodule hmod, const char *name) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleGetSurfRef, pSurfRef, hmod, name);
}

CUresult cuLibraryLoadData(CUlibrary *library, const void *code, CUjit_option *jitOptions, void **jitOptionsValues, unsigned int numJitOptions, CUlibraryOption *libraryOptions, void **libraryOptionValues, unsigned int numLibraryOptions) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLibraryLoadData, library, code, jitOptions, jitOptionsValues, numJitOptions, libraryOptions, libraryOptionValues, numLibraryOptions);
}

CUresult cuLibraryLoadFromFile(CUlibrary *library, const char *fileName, CUjit_option *jitOptions, void **jitOptionsValues, unsigned int numJitOptions, CUlibraryOption *libraryOptions, void **libraryOptionValues, unsigned int numLibraryOptions) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLibraryLoadFromFile, library, fileName, jitOptions, jitOptionsValues, numJitOptions, libraryOptions, libraryOptionValues, numLibraryOptions);
}

CUresult cuLibraryUnload(CUlibrary library) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLibraryUnload, library);
}

CUresult cuLibraryGetKernel(CUkernel *pKernel, CUlibrary library, const char *name) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLibraryGetKernel, pKernel, library, name);
}

CUresult cuLibraryGetModule(CUmodule *pMod, CUlibrary library) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLibraryGetModule, pMod, library);
}

CUresult cuKernelGetFunction(CUfunction *pFunc, CUkernel kernel) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuKernelGetFunction, pFunc, kernel);
}

CUresult cuLibraryGetGlobal(CUdeviceptr *dptr, size_t *bytes, CUlibrary library, const char *name) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLibraryGetGlobal, dptr, bytes, library, name);
}

CUresult cuLibraryGetManaged(CUdeviceptr *dptr, size_t *bytes, CUlibrary library, const char *name) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLibraryGetManaged, dptr, bytes, library, name);
}

CUresult cuLibraryGetUnifiedFunction(void **fptr, CUlibrary library, const char *symbol) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLibraryGetUnifiedFunction, fptr, library, symbol);
}

CUresult cuKernelGetAttribute(int *pi, CUfunction_attribute attrib, CUkernel kernel, CUdevice dev) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuKernelGetAttribute, pi, attrib, kernel, dev);
}

CUresult cuKernelSetAttribute(CUfunction_attribute attrib, int val, CUkernel kernel, CUdevice dev) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuKernelSetAttribute, attrib, val, kernel, dev);
}

CUresult cuKernelSetCacheConfig(CUkernel kernel, CUfunc_cache config, CUdevice dev) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuKernelSetCacheConfig, kernel, config, dev);
}

CUresult cuKernelGetName(const char **name, CUkernel hfunc) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuKernelGetName, name, hfunc);
}

CUresult cuMemFree(CUdeviceptr dptr) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemFree, dptr);
}

CUresult cuMemGetAddressRange(CUdeviceptr *pbase, size_t *psize, CUdeviceptr dptr) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemGetAddressRange, pbase, psize, dptr);
}

CUresult cuMemAllocHost(void **pp, size_t bytesize) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemAllocHost, pp, bytesize);
}

CUresult cuMemFreeHost(void *p) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemFreeHost, p);
}

CUresult cuMemHostAlloc(void **pp, size_t bytesize, unsigned int Flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemHostAlloc, pp, bytesize, Flags);
}

CUresult cuMemHostGetDevicePointer(CUdeviceptr *pdptr, void *p, unsigned int Flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemHostGetDevicePointer, pdptr, p, Flags);
}

CUresult cuMemHostGetFlags(unsigned int *pFlags, void *p) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemHostGetFlags, pFlags, p);
}

CUresult cuDeviceGetByPCIBusId(CUdevice *dev, const char *pciBusId) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetByPCIBusId, dev, pciBusId);
}

CUresult cuDeviceGetPCIBusId(char *pciBusId, int len, CUdevice dev) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetPCIBusId, pciBusId, len, dev);
}

CUresult cuIpcGetEventHandle(CUipcEventHandle *pHandle, CUevent event) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuIpcGetEventHandle, pHandle, event);
}

CUresult cuIpcOpenEventHandle(CUevent *phEvent, CUipcEventHandle handle) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuIpcOpenEventHandle, phEvent, handle);
}

CUresult cuIpcGetMemHandle(CUipcMemHandle *pHandle, CUdeviceptr dptr) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuIpcGetMemHandle, pHandle, dptr);
}

CUresult cuIpcOpenMemHandle(CUdeviceptr *pdptr, CUipcMemHandle handle, unsigned int Flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuIpcOpenMemHandle, pdptr, handle, Flags);
}

CUresult cuIpcCloseMemHandle(CUdeviceptr dptr) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuIpcCloseMemHandle, dptr);
}

CUresult cuMemHostRegister(void *p, size_t bytesize, unsigned int Flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemHostRegister, p, bytesize, Flags);
}

CUresult cuMemHostUnregister(void *p) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemHostUnregister, p);
}

CUresult cuMemcpy(CUdeviceptr dst, CUdeviceptr src, size_t ByteCount) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy, dst, src, ByteCount);
}

CUresult cuMemcpyPeer(CUdeviceptr dstDevice, CUcontext dstContext, CUdeviceptr srcDevice, CUcontext srcContext, size_t ByteCount) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyPeer, dstDevice, dstContext, srcDevice, srcContext, ByteCount);
}

CUresult cuMemcpyHtoD(CUdeviceptr dstDevice, const void *srcHost, size_t ByteCount) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyHtoD, dstDevice, srcHost, ByteCount);
}

CUresult cuMemcpyDtoH(void *dstHost, CUdeviceptr srcDevice, size_t ByteCount) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoH, dstHost, srcDevice, ByteCount);
}

CUresult cuMemcpyDtoD(CUdeviceptr dstDevice, CUdeviceptr srcDevice, size_t ByteCount) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoD, dstDevice, srcDevice, ByteCount);
}

CUresult cuMemcpyDtoA(CUarray dstArray, size_t dstOffset, CUdeviceptr srcDevice, size_t ByteCount) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoA, dstArray, dstOffset, srcDevice, ByteCount);
}

CUresult cuMemcpyAtoD(CUdeviceptr dstDevice, CUarray srcArray, size_t srcOffset, size_t ByteCount) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAtoD, dstDevice, srcArray, srcOffset, ByteCount);
}

CUresult cuMemcpyHtoA(CUarray dstArray, size_t dstOffset, const void *srcHost, size_t ByteCount) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyHtoA, dstArray, dstOffset, srcHost, ByteCount);
}

CUresult cuMemcpyAtoH(void *dstHost, CUarray srcArray, size_t srcOffset, size_t ByteCount) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAtoH, dstHost, srcArray, srcOffset, ByteCount);
}

CUresult cuMemcpyAtoA(CUarray dstArray, size_t dstOffset, CUarray srcArray, size_t srcOffset, size_t ByteCount) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAtoA, dstArray, dstOffset, srcArray, srcOffset, ByteCount);
}

CUresult cuMemcpy2D(const CUDA_MEMCPY2D *pCopy) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy2D, pCopy);
}

CUresult cuMemcpy2DUnaligned(const CUDA_MEMCPY2D *pCopy) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy2DUnaligned, pCopy);
}

CUresult cuMemcpy3D(const CUDA_MEMCPY3D *pCopy) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy3D, pCopy);
}

CUresult cuMemcpy3DPeer(const CUDA_MEMCPY3D_PEER *pCopy) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy3DPeer, pCopy);
}

CUresult cuMemcpyAsync(CUdeviceptr dst, CUdeviceptr src, size_t ByteCount, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAsync, dst, src, ByteCount, hStream);
}

CUresult cuMemcpyPeerAsync(CUdeviceptr dstDevice, CUcontext dstContext, CUdeviceptr srcDevice, CUcontext srcContext, size_t ByteCount, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyPeerAsync, dstDevice, dstContext, srcDevice, srcContext, ByteCount, hStream);
}

CUresult cuMemcpyHtoDAsync(CUdeviceptr dstDevice, const void *srcHost, size_t ByteCount, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyHtoDAsync, dstDevice, srcHost, ByteCount, hStream);
}

CUresult cuMemcpyDtoHAsync(void *dstHost, CUdeviceptr srcDevice, size_t ByteCount, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoHAsync, dstHost, srcDevice, ByteCount, hStream);
}

CUresult cuMemcpyDtoDAsync(CUdeviceptr dstDevice, CUdeviceptr srcDevice, size_t ByteCount, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoDAsync, dstDevice, srcDevice, ByteCount, hStream);
}

CUresult cuMemcpyHtoAAsync(CUarray dstArray, size_t dstOffset, const void *srcHost, size_t ByteCount, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyHtoAAsync, dstArray, dstOffset, srcHost, ByteCount, hStream);
}

CUresult cuMemcpyAtoHAsync(void *dstHost, CUarray srcArray, size_t srcOffset, size_t ByteCount, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAtoHAsync, dstHost, srcArray, srcOffset, ByteCount, hStream);
}

CUresult cuMemcpy2DAsync(const CUDA_MEMCPY2D *pCopy, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy2DAsync, pCopy, hStream);
}

CUresult cuMemcpy3DAsync(const CUDA_MEMCPY3D *pCopy, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy3DAsync, pCopy, hStream);
}

CUresult cuMemcpy3DPeerAsync(const CUDA_MEMCPY3D_PEER *pCopy, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy3DPeerAsync, pCopy, hStream);
}

CUresult cuMemsetD8(CUdeviceptr dstDevice, unsigned char uc, size_t N) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD8, dstDevice, uc, N);
}

CUresult cuMemsetD16(CUdeviceptr dstDevice, unsigned short us, size_t N) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD16, dstDevice, us, N);
}

CUresult cuMemsetD32(CUdeviceptr dstDevice, unsigned int ui, size_t N) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD32, dstDevice, ui, N);
}

CUresult cuMemsetD2D8(CUdeviceptr dstDevice, size_t dstPitch, unsigned char uc, size_t Width, size_t Height) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D8, dstDevice, dstPitch, uc, Width, Height);
}

CUresult cuMemsetD2D16(CUdeviceptr dstDevice, size_t dstPitch, unsigned short us, size_t Width, size_t Height) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D16, dstDevice, dstPitch, us, Width, Height);
}

CUresult cuMemsetD2D32(CUdeviceptr dstDevice, size_t dstPitch, unsigned int ui, size_t Width, size_t Height) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D32, dstDevice, dstPitch, ui, Width, Height);
}

CUresult cuMemsetD8Async(CUdeviceptr dstDevice, unsigned char uc, size_t N, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD8Async, dstDevice, uc, N, hStream);
}

CUresult cuMemsetD16Async(CUdeviceptr dstDevice, unsigned short us, size_t N, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD16Async, dstDevice, us, N, hStream);
}

CUresult cuMemsetD32Async(CUdeviceptr dstDevice, unsigned int ui, size_t N, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD32Async, dstDevice, ui, N, hStream);
}

CUresult cuMemsetD2D8Async(CUdeviceptr dstDevice, size_t dstPitch, unsigned char uc, size_t Width, size_t Height, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D8Async, dstDevice, dstPitch, uc, Width, Height, hStream);
}

CUresult cuMemsetD2D16Async(CUdeviceptr dstDevice, size_t dstPitch, unsigned short us, size_t Width, size_t Height, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D16Async, dstDevice, dstPitch, us, Width, Height, hStream);
}

CUresult cuMemsetD2D32Async(CUdeviceptr dstDevice, size_t dstPitch, unsigned int ui, size_t Width, size_t Height, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D32Async, dstDevice, dstPitch, ui, Width, Height, hStream);
}

CUresult cuArrayGetDescriptor(CUDA_ARRAY_DESCRIPTOR *pArrayDescriptor, CUarray hArray) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuArrayGetDescriptor, pArrayDescriptor, hArray);
}

CUresult cuArrayGetSparseProperties(CUDA_ARRAY_SPARSE_PROPERTIES *sparseProperties, CUarray array) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuArrayGetSparseProperties, sparseProperties, array);
}

CUresult cuMipmappedArrayGetSparseProperties(CUDA_ARRAY_SPARSE_PROPERTIES *sparseProperties, CUmipmappedArray mipmap) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMipmappedArrayGetSparseProperties, sparseProperties, mipmap);
}

CUresult cuArrayGetMemoryRequirements(CUDA_ARRAY_MEMORY_REQUIREMENTS *memoryRequirements, CUarray array, CUdevice device) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuArrayGetMemoryRequirements, memoryRequirements, array, device);
}

CUresult cuMipmappedArrayGetMemoryRequirements(CUDA_ARRAY_MEMORY_REQUIREMENTS *memoryRequirements, CUmipmappedArray mipmap, CUdevice device) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMipmappedArrayGetMemoryRequirements, memoryRequirements, mipmap, device);
}

CUresult cuArrayGetPlane(CUarray *pPlaneArray, CUarray hArray, unsigned int planeIdx) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuArrayGetPlane, pPlaneArray, hArray, planeIdx);
}

CUresult cuArrayDestroy(CUarray hArray) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuArrayDestroy, hArray);
}

CUresult cuArray3DGetDescriptor(CUDA_ARRAY3D_DESCRIPTOR *pArrayDescriptor, CUarray hArray) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuArray3DGetDescriptor, pArrayDescriptor, hArray);
}

CUresult cuMipmappedArrayGetLevel(CUarray *pLevelArray, CUmipmappedArray hMipmappedArray, unsigned int level) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMipmappedArrayGetLevel, pLevelArray, hMipmappedArray, level);
}

CUresult cuMipmappedArrayDestroy(CUmipmappedArray hMipmappedArray) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMipmappedArrayDestroy, hMipmappedArray);
}

CUresult cuMemGetHandleForAddressRange(void *handle, CUdeviceptr dptr, size_t size, CUmemRangeHandleType handleType, unsigned long long flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemGetHandleForAddressRange, handle, dptr, size, handleType, flags);
}

CUresult cuMemFreeAsync(CUdeviceptr dptr, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemFreeAsync, dptr, hStream);
}

CUresult cuMemAllocAsync(CUdeviceptr *dptr, size_t bytesize, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemAllocAsync, dptr, bytesize, hStream);
}

CUresult cuMemPoolTrimTo(CUmemoryPool pool, size_t minBytesToKeep) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolTrimTo, pool, minBytesToKeep);
}

CUresult cuMemPoolSetAttribute(CUmemoryPool pool, CUmemPool_attribute attr, void *value) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolSetAttribute, pool, attr, value);
}

CUresult cuMemPoolGetAttribute(CUmemoryPool pool, CUmemPool_attribute attr, void *value) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolGetAttribute, pool, attr, value);
}

CUresult cuMemPoolSetAccess(CUmemoryPool pool, const CUmemAccessDesc *map, size_t count) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolSetAccess, pool, map, count);
}

CUresult cuMemPoolGetAccess(CUmemAccess_flags *flags, CUmemoryPool memPool, CUmemLocation *location) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolGetAccess, flags, memPool, location);
}

CUresult cuMemPoolCreate(CUmemoryPool *pool, const CUmemPoolProps *poolProps) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolCreate, pool, poolProps);
}

CUresult cuMemPoolDestroy(CUmemoryPool pool) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolDestroy, pool);
}

CUresult cuMemAllocFromPoolAsync(CUdeviceptr *dptr, size_t bytesize, CUmemoryPool pool, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemAllocFromPoolAsync, dptr, bytesize, pool, hStream);
}

CUresult cuMemPoolExportToShareableHandle(void *handle_out, CUmemoryPool pool, CUmemAllocationHandleType handleType, unsigned long long flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolExportToShareableHandle, handle_out, pool, handleType, flags);
}

CUresult cuMemPoolImportFromShareableHandle(CUmemoryPool *pool_out, void *handle, CUmemAllocationHandleType handleType, unsigned long long flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolImportFromShareableHandle, pool_out, handle, handleType, flags);
}

CUresult cuMemPoolExportPointer(CUmemPoolPtrExportData *shareData_out, CUdeviceptr ptr) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolExportPointer, shareData_out, ptr);
}

CUresult cuMemPoolImportPointer(CUdeviceptr *ptr_out, CUmemoryPool pool, CUmemPoolPtrExportData *shareData) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolImportPointer, ptr_out, pool, shareData);
}

CUresult cuMulticastCreate(CUmemGenericAllocationHandle *mcHandle, const CUmulticastObjectProp *prop) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMulticastCreate, mcHandle, prop);
}

CUresult cuMulticastAddDevice(CUmemGenericAllocationHandle mcHandle, CUdevice dev) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMulticastAddDevice, mcHandle, dev);
}

CUresult cuMulticastBindMem(CUmemGenericAllocationHandle mcHandle, size_t mcOffset, CUmemGenericAllocationHandle memHandle, size_t memOffset, size_t size, unsigned long long flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMulticastBindMem, mcHandle, mcOffset, memHandle, memOffset, size, flags);
}

CUresult cuMulticastBindAddr(CUmemGenericAllocationHandle mcHandle, size_t mcOffset, CUdeviceptr memptr, size_t size, unsigned long long flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMulticastBindAddr, mcHandle, mcOffset, memptr, size, flags);
}

CUresult cuMulticastUnbind(CUmemGenericAllocationHandle mcHandle, CUdevice dev, size_t mcOffset, size_t size) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMulticastUnbind, mcHandle, dev, mcOffset, size);
}

CUresult cuMulticastGetGranularity(size_t *granularity, const CUmulticastObjectProp *prop, CUmulticastGranularity_flags option) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMulticastGetGranularity, granularity, prop, option);
}

CUresult cuPointerGetAttribute(void *data, CUpointer_attribute attribute, CUdeviceptr ptr) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuPointerGetAttribute, data, attribute, ptr);
}

CUresult cuMemPrefetchAsync(CUdeviceptr devPtr, size_t count, CUdevice dstDevice, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPrefetchAsync, devPtr, count, dstDevice, hStream);
}

CUresult cuMemPrefetchAsync_v2(CUdeviceptr devPtr, size_t count, CUmemLocation location, unsigned int flags, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPrefetchAsync_v2, devPtr, count, location, flags, hStream);
}

CUresult cuMemAdvise(CUdeviceptr devPtr, size_t count, CUmem_advise advice, CUdevice device) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemAdvise, devPtr, count, advice, device);
}

CUresult cuMemAdvise_v2(CUdeviceptr devPtr, size_t count, CUmem_advise advice, CUmemLocation location) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemAdvise_v2, devPtr, count, advice, location);
}

CUresult cuMemRangeGetAttribute(void *data, size_t dataSize, CUmem_range_attribute attribute, CUdeviceptr devPtr, size_t count) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemRangeGetAttribute, data, dataSize, attribute, devPtr, count);
}

CUresult cuMemRangeGetAttributes(void **data, size_t *dataSizes, CUmem_range_attribute *attributes, size_t numAttributes, CUdeviceptr devPtr, size_t count) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemRangeGetAttributes, data, dataSizes, attributes, numAttributes, devPtr, count);
}

CUresult cuPointerSetAttribute(const void *value, CUpointer_attribute attribute, CUdeviceptr ptr) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuPointerSetAttribute, value, attribute, ptr);
}

CUresult cuPointerGetAttributes(unsigned int numAttributes, CUpointer_attribute *attributes, void **data, CUdeviceptr ptr) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuPointerGetAttributes, numAttributes, attributes, data, ptr);
}

CUresult cuStreamCreate(CUstream *phStream, unsigned int Flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamCreate, phStream, Flags);
}

CUresult cuStreamCreateWithPriority(CUstream *phStream, unsigned int flags, int priority) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamCreateWithPriority, phStream, flags, priority);
}

CUresult cuStreamGetPriority(CUstream hStream, int *priority) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamGetPriority, hStream, priority);
}

CUresult cuStreamGetFlags(CUstream hStream, unsigned int *flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamGetFlags, hStream, flags);
}

CUresult cuStreamGetId(CUstream hStream, unsigned long long *streamId) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamGetId, hStream, streamId);
}

CUresult cuStreamGetCtx(CUstream hStream, CUcontext *pctx) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamGetCtx, hStream, pctx);
}

CUresult cuStreamWaitEvent(CUstream hStream, CUevent hEvent, unsigned int Flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWaitEvent, hStream, hEvent, Flags);
}

CUresult cuStreamAddCallback(CUstream hStream, CUstreamCallback callback, void *userData, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamAddCallback, hStream, callback, userData, flags);
}

CUresult cuStreamBeginCapture(CUstream hStream, CUstreamCaptureMode mode) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamBeginCapture, hStream, mode);
}

CUresult cuStreamBeginCaptureToGraph(CUstream hStream, CUgraph hGraph, const CUgraphNode *dependencies, const CUgraphEdgeData *dependencyData, size_t numDependencies, CUstreamCaptureMode mode) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamBeginCaptureToGraph, hStream, hGraph, dependencies, dependencyData, numDependencies, mode);
}

CUresult cuThreadExchangeStreamCaptureMode(CUstreamCaptureMode *mode) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuThreadExchangeStreamCaptureMode, mode);
}

CUresult cuStreamEndCapture(CUstream hStream, CUgraph *phGraph) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamEndCapture, hStream, phGraph);
}

CUresult cuStreamIsCapturing(CUstream hStream, CUstreamCaptureStatus *captureStatus) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamIsCapturing, hStream, captureStatus);
}

CUresult cuStreamGetCaptureInfo(CUstream hStream, CUstreamCaptureStatus *captureStatus_out, cuuint64_t *id_out, CUgraph *graph_out, const CUgraphNode **dependencies_out, size_t *numDependencies_out) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamGetCaptureInfo, hStream, captureStatus_out, id_out, graph_out, dependencies_out, numDependencies_out);
}

CUresult cuStreamGetCaptureInfo_v3(CUstream hStream, CUstreamCaptureStatus *captureStatus_out, cuuint64_t *id_out, CUgraph *graph_out, const CUgraphNode **dependencies_out, const CUgraphEdgeData **edgeData_out, size_t *numDependencies_out) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamGetCaptureInfo_v3, hStream, captureStatus_out, id_out, graph_out, dependencies_out, edgeData_out, numDependencies_out);
}

CUresult cuStreamUpdateCaptureDependencies(CUstream hStream, CUgraphNode *dependencies, size_t numDependencies, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamUpdateCaptureDependencies, hStream, dependencies, numDependencies, flags);
}

CUresult cuStreamUpdateCaptureDependencies_v2(CUstream hStream, CUgraphNode *dependencies, const CUgraphEdgeData *dependencyData, size_t numDependencies, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamUpdateCaptureDependencies_v2, hStream, dependencies, dependencyData, numDependencies, flags);
}

CUresult cuStreamAttachMemAsync(CUstream hStream, CUdeviceptr dptr, size_t length, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamAttachMemAsync, hStream, dptr, length, flags);
}

CUresult cuStreamQuery(CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamQuery, hStream);
}

CUresult cuStreamSynchronize(CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamSynchronize, hStream);
}

CUresult cuStreamDestroy(CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamDestroy, hStream);
}

CUresult cuStreamCopyAttributes(CUstream dst, CUstream src) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamCopyAttributes, dst, src);
}

CUresult cuStreamGetAttribute(CUstream hStream, CUstreamAttrID attr, CUstreamAttrValue *value_out) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamGetAttribute, hStream, attr, value_out);
}

CUresult cuStreamSetAttribute(CUstream hStream, CUstreamAttrID attr, const CUstreamAttrValue *value) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamSetAttribute, hStream, attr, value);
}

CUresult cuEventCreate(CUevent *phEvent, unsigned int Flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuEventCreate, phEvent, Flags);
}

CUresult cuEventRecord(CUevent hEvent, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuEventRecord, hEvent, hStream);
}

CUresult cuEventRecordWithFlags(CUevent hEvent, CUstream hStream, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuEventRecordWithFlags, hEvent, hStream, flags);
}

CUresult cuEventQuery(CUevent hEvent) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuEventQuery, hEvent);
}

CUresult cuEventSynchronize(CUevent hEvent) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuEventSynchronize, hEvent);
}

CUresult cuEventDestroy(CUevent hEvent) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuEventDestroy, hEvent);
}

CUresult cuEventElapsedTime(float *pMilliseconds, CUevent hStart, CUevent hEnd) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuEventElapsedTime, pMilliseconds, hStart, hEnd);
}

CUresult cuImportExternalMemory(CUexternalMemory *extMem_out, const CUDA_EXTERNAL_MEMORY_HANDLE_DESC *memHandleDesc) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuImportExternalMemory, extMem_out, memHandleDesc);
}

CUresult cuExternalMemoryGetMappedBuffer(CUdeviceptr *devPtr, CUexternalMemory extMem, const CUDA_EXTERNAL_MEMORY_BUFFER_DESC *bufferDesc) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuExternalMemoryGetMappedBuffer, devPtr, extMem, bufferDesc);
}

CUresult cuExternalMemoryGetMappedMipmappedArray(CUmipmappedArray *mipmap, CUexternalMemory extMem, const CUDA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC *mipmapDesc) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuExternalMemoryGetMappedMipmappedArray, mipmap, extMem, mipmapDesc);
}

CUresult cuDestroyExternalMemory(CUexternalMemory extMem) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDestroyExternalMemory, extMem);
}

CUresult cuImportExternalSemaphore(CUexternalSemaphore *extSem_out, const CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC *semHandleDesc) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuImportExternalSemaphore, extSem_out, semHandleDesc);
}

CUresult cuSignalExternalSemaphoresAsync(const CUexternalSemaphore *extSemArray, const CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS *paramsArray, unsigned int numExtSems, CUstream stream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuSignalExternalSemaphoresAsync, extSemArray, paramsArray, numExtSems, stream);
}

CUresult cuWaitExternalSemaphoresAsync(const CUexternalSemaphore *extSemArray, const CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS *paramsArray, unsigned int numExtSems, CUstream stream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuWaitExternalSemaphoresAsync, extSemArray, paramsArray, numExtSems, stream);
}

CUresult cuDestroyExternalSemaphore(CUexternalSemaphore extSem) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDestroyExternalSemaphore, extSem);
}

CUresult cuStreamWaitValue32(CUstream stream, CUdeviceptr addr, cuuint32_t value, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWaitValue32, stream, addr, value, flags);
}

CUresult cuStreamWaitValue64(CUstream stream, CUdeviceptr addr, cuuint64_t value, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWaitValue64, stream, addr, value, flags);
}

CUresult cuStreamWriteValue32(CUstream stream, CUdeviceptr addr, cuuint32_t value, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWriteValue32, stream, addr, value, flags);
}

CUresult cuStreamWriteValue64(CUstream stream, CUdeviceptr addr, cuuint64_t value, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWriteValue64, stream, addr, value, flags);
}

CUresult cuStreamBatchMemOp(CUstream stream, unsigned int count, CUstreamBatchMemOpParams *paramArray, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamBatchMemOp, stream, count, paramArray, flags);
}

CUresult cuFuncGetAttribute(int *pi, CUfunction_attribute attrib, CUfunction hfunc) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuFuncGetAttribute, pi, attrib, hfunc);
}

CUresult cuFuncSetAttribute(CUfunction hfunc, CUfunction_attribute attrib, int value) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuFuncSetAttribute, hfunc, attrib, value);
}

CUresult cuFuncSetCacheConfig(CUfunction hfunc, CUfunc_cache config) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuFuncSetCacheConfig, hfunc, config);
}

CUresult cuFuncSetSharedMemConfig(CUfunction hfunc, CUsharedconfig config) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuFuncSetSharedMemConfig, hfunc, config);
}

CUresult cuFuncGetModule(CUmodule *hmod, CUfunction hfunc) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuFuncGetModule, hmod, hfunc);
}

CUresult cuFuncGetName(const char **name, CUfunction hfunc) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuFuncGetName, name, hfunc);
}

CUresult cuLaunchKernelEx(const CUlaunchConfig *config, CUfunction f, void **kernelParams, void **extra) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLaunchKernelEx, config, f, kernelParams, extra);
}

CUresult cuLaunchCooperativeKernelMultiDevice(CUDA_LAUNCH_PARAMS *launchParamsList, unsigned int numDevices, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLaunchCooperativeKernelMultiDevice, launchParamsList, numDevices, flags);
}

CUresult cuLaunchHostFunc(CUstream hStream, CUhostFn fn, void *userData) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLaunchHostFunc, hStream, fn, userData);
}

CUresult cuFuncSetSharedSize(CUfunction hfunc, unsigned int bytes) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuFuncSetSharedSize, hfunc, bytes);
}

CUresult cuParamSetSize(CUfunction hfunc, unsigned int numbytes) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuParamSetSize, hfunc, numbytes);
}

CUresult cuParamSeti(CUfunction hfunc, int offset, unsigned int value) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuParamSeti, hfunc, offset, value);
}

CUresult cuParamSetf(CUfunction hfunc, int offset, float value) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuParamSetf, hfunc, offset, value);
}

CUresult cuParamSetv(CUfunction hfunc, int offset, void *ptr, unsigned int numbytes) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuParamSetv, hfunc, offset, ptr, numbytes);
}

CUresult cuParamSetTexRef(CUfunction hfunc, int texunit, CUtexref hTexRef) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuParamSetTexRef, hfunc, texunit, hTexRef);
}

CUresult cuGraphCreate(CUgraph *phGraph, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphCreate, phGraph, flags);
}

CUresult cuGraphAddKernelNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, const CUDA_KERNEL_NODE_PARAMS *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddKernelNode, phGraphNode, hGraph, dependencies, numDependencies, nodeParams);
}

CUresult cuGraphKernelNodeGetParams(CUgraphNode hNode, CUDA_KERNEL_NODE_PARAMS *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphKernelNodeGetParams, hNode, nodeParams);
}

CUresult cuGraphKernelNodeSetParams(CUgraphNode hNode, const CUDA_KERNEL_NODE_PARAMS *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphKernelNodeSetParams, hNode, nodeParams);
}

CUresult cuGraphAddMemcpyNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, const CUDA_MEMCPY3D *copyParams, CUcontext ctx) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddMemcpyNode, phGraphNode, hGraph, dependencies, numDependencies, copyParams, ctx);
}

CUresult cuGraphMemcpyNodeGetParams(CUgraphNode hNode, CUDA_MEMCPY3D *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphMemcpyNodeGetParams, hNode, nodeParams);
}

CUresult cuGraphMemcpyNodeSetParams(CUgraphNode hNode, const CUDA_MEMCPY3D *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphMemcpyNodeSetParams, hNode, nodeParams);
}

CUresult cuGraphAddMemsetNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, const CUDA_MEMSET_NODE_PARAMS *memsetParams, CUcontext ctx) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddMemsetNode, phGraphNode, hGraph, dependencies, numDependencies, memsetParams, ctx);
}

CUresult cuGraphMemsetNodeGetParams(CUgraphNode hNode, CUDA_MEMSET_NODE_PARAMS *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphMemsetNodeGetParams, hNode, nodeParams);
}

CUresult cuGraphMemsetNodeSetParams(CUgraphNode hNode, const CUDA_MEMSET_NODE_PARAMS *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphMemsetNodeSetParams, hNode, nodeParams);
}

CUresult cuGraphAddHostNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, const CUDA_HOST_NODE_PARAMS *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddHostNode, phGraphNode, hGraph, dependencies, numDependencies, nodeParams);
}

CUresult cuGraphHostNodeGetParams(CUgraphNode hNode, CUDA_HOST_NODE_PARAMS *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphHostNodeGetParams, hNode, nodeParams);
}

CUresult cuGraphHostNodeSetParams(CUgraphNode hNode, const CUDA_HOST_NODE_PARAMS *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphHostNodeSetParams, hNode, nodeParams);
}

CUresult cuGraphAddChildGraphNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, CUgraph childGraph) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddChildGraphNode, phGraphNode, hGraph, dependencies, numDependencies, childGraph);
}

CUresult cuGraphChildGraphNodeGetGraph(CUgraphNode hNode, CUgraph *phGraph) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphChildGraphNodeGetGraph, hNode, phGraph);
}

CUresult cuGraphAddEmptyNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddEmptyNode, phGraphNode, hGraph, dependencies, numDependencies);
}

CUresult cuGraphAddEventRecordNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, CUevent event) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddEventRecordNode, phGraphNode, hGraph, dependencies, numDependencies, event);
}

CUresult cuGraphEventRecordNodeGetEvent(CUgraphNode hNode, CUevent *event_out) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphEventRecordNodeGetEvent, hNode, event_out);
}

CUresult cuGraphEventRecordNodeSetEvent(CUgraphNode hNode, CUevent event) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphEventRecordNodeSetEvent, hNode, event);
}

CUresult cuGraphAddEventWaitNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, CUevent event) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddEventWaitNode, phGraphNode, hGraph, dependencies, numDependencies, event);
}

CUresult cuGraphEventWaitNodeGetEvent(CUgraphNode hNode, CUevent *event_out) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphEventWaitNodeGetEvent, hNode, event_out);
}

CUresult cuGraphEventWaitNodeSetEvent(CUgraphNode hNode, CUevent event) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphEventWaitNodeSetEvent, hNode, event);
}

CUresult cuGraphAddExternalSemaphoresSignalNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, const CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddExternalSemaphoresSignalNode, phGraphNode, hGraph, dependencies, numDependencies, nodeParams);
}

CUresult cuGraphExternalSemaphoresSignalNodeGetParams(CUgraphNode hNode, CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *params_out) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExternalSemaphoresSignalNodeGetParams, hNode, params_out);
}

CUresult cuGraphExternalSemaphoresSignalNodeSetParams(CUgraphNode hNode, const CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExternalSemaphoresSignalNodeSetParams, hNode, nodeParams);
}

CUresult cuGraphAddExternalSemaphoresWaitNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, const CUDA_EXT_SEM_WAIT_NODE_PARAMS *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddExternalSemaphoresWaitNode, phGraphNode, hGraph, dependencies, numDependencies, nodeParams);
}

CUresult cuGraphExternalSemaphoresWaitNodeGetParams(CUgraphNode hNode, CUDA_EXT_SEM_WAIT_NODE_PARAMS *params_out) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExternalSemaphoresWaitNodeGetParams, hNode, params_out);
}

CUresult cuGraphExternalSemaphoresWaitNodeSetParams(CUgraphNode hNode, const CUDA_EXT_SEM_WAIT_NODE_PARAMS *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExternalSemaphoresWaitNodeSetParams, hNode, nodeParams);
}

CUresult cuGraphAddBatchMemOpNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, const CUDA_BATCH_MEM_OP_NODE_PARAMS *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddBatchMemOpNode, phGraphNode, hGraph, dependencies, numDependencies, nodeParams);
}

CUresult cuGraphBatchMemOpNodeGetParams(CUgraphNode hNode, CUDA_BATCH_MEM_OP_NODE_PARAMS *nodeParams_out) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphBatchMemOpNodeGetParams, hNode, nodeParams_out);
}

CUresult cuGraphBatchMemOpNodeSetParams(CUgraphNode hNode, const CUDA_BATCH_MEM_OP_NODE_PARAMS *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphBatchMemOpNodeSetParams, hNode, nodeParams);
}

CUresult cuGraphExecBatchMemOpNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, const CUDA_BATCH_MEM_OP_NODE_PARAMS *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecBatchMemOpNodeSetParams, hGraphExec, hNode, nodeParams);
}

CUresult cuGraphAddMemAllocNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, CUDA_MEM_ALLOC_NODE_PARAMS *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddMemAllocNode, phGraphNode, hGraph, dependencies, numDependencies, nodeParams);
}

CUresult cuGraphMemAllocNodeGetParams(CUgraphNode hNode, CUDA_MEM_ALLOC_NODE_PARAMS *params_out) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphMemAllocNodeGetParams, hNode, params_out);
}

CUresult cuGraphAddMemFreeNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, CUdeviceptr dptr) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddMemFreeNode, phGraphNode, hGraph, dependencies, numDependencies, dptr);
}

CUresult cuGraphMemFreeNodeGetParams(CUgraphNode hNode, CUdeviceptr *dptr_out) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphMemFreeNodeGetParams, hNode, dptr_out);
}

CUresult cuDeviceGraphMemTrim(CUdevice device) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGraphMemTrim, device);
}

CUresult cuDeviceGetGraphMemAttribute(CUdevice device, CUgraphMem_attribute attr, void *value) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetGraphMemAttribute, device, attr, value);
}

CUresult cuDeviceSetGraphMemAttribute(CUdevice device, CUgraphMem_attribute attr, void *value) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceSetGraphMemAttribute, device, attr, value);
}

CUresult cuGraphClone(CUgraph *phGraphClone, CUgraph originalGraph) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphClone, phGraphClone, originalGraph);
}

CUresult cuGraphNodeFindInClone(CUgraphNode *phNode, CUgraphNode hOriginalNode, CUgraph hClonedGraph) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphNodeFindInClone, phNode, hOriginalNode, hClonedGraph);
}

CUresult cuGraphNodeGetType(CUgraphNode hNode, CUgraphNodeType *type) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphNodeGetType, hNode, type);
}

CUresult cuGraphGetNodes(CUgraph hGraph, CUgraphNode *nodes, size_t *numNodes) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphGetNodes, hGraph, nodes, numNodes);
}

CUresult cuGraphGetRootNodes(CUgraph hGraph, CUgraphNode *rootNodes, size_t *numRootNodes) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphGetRootNodes, hGraph, rootNodes, numRootNodes);
}

CUresult cuGraphGetEdges(CUgraph hGraph, CUgraphNode *from, CUgraphNode *to, size_t *numEdges) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphGetEdges, hGraph, from, to, numEdges);
}

CUresult cuGraphGetEdges_v2(CUgraph hGraph, CUgraphNode *from, CUgraphNode *to, CUgraphEdgeData *edgeData, size_t *numEdges) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphGetEdges_v2, hGraph, from, to, edgeData, numEdges);
}

CUresult cuGraphNodeGetDependencies(CUgraphNode hNode, CUgraphNode *dependencies, size_t *numDependencies) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphNodeGetDependencies, hNode, dependencies, numDependencies);
}

CUresult cuGraphNodeGetDependencies_v2(CUgraphNode hNode, CUgraphNode *dependencies, CUgraphEdgeData *edgeData, size_t *numDependencies) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphNodeGetDependencies_v2, hNode, dependencies, edgeData, numDependencies);
}

CUresult cuGraphNodeGetDependentNodes(CUgraphNode hNode, CUgraphNode *dependentNodes, size_t *numDependentNodes) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphNodeGetDependentNodes, hNode, dependentNodes, numDependentNodes);
}

CUresult cuGraphNodeGetDependentNodes_v2(CUgraphNode hNode, CUgraphNode *dependentNodes, CUgraphEdgeData *edgeData, size_t *numDependentNodes) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphNodeGetDependentNodes_v2, hNode, dependentNodes, edgeData, numDependentNodes);
}

CUresult cuGraphAddDependencies(CUgraph hGraph, const CUgraphNode *from, const CUgraphNode *to, size_t numDependencies) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddDependencies, hGraph, from, to, numDependencies);
}

CUresult cuGraphAddDependencies_v2(CUgraph hGraph, const CUgraphNode *from, const CUgraphNode *to, const CUgraphEdgeData *edgeData, size_t numDependencies) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddDependencies_v2, hGraph, from, to, edgeData, numDependencies);
}

CUresult cuGraphRemoveDependencies(CUgraph hGraph, const CUgraphNode *from, const CUgraphNode *to, size_t numDependencies) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphRemoveDependencies, hGraph, from, to, numDependencies);
}

CUresult cuGraphRemoveDependencies_v2(CUgraph hGraph, const CUgraphNode *from, const CUgraphNode *to, const CUgraphEdgeData *edgeData, size_t numDependencies) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphRemoveDependencies_v2, hGraph, from, to, edgeData, numDependencies);
}

CUresult cuGraphDestroyNode(CUgraphNode hNode) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphDestroyNode, hNode);
}

CUresult cuGraphInstantiate(CUgraphExec *phGraphExec, CUgraph hGraph, unsigned long long flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphInstantiate, phGraphExec, hGraph, flags);
}

CUresult cuGraphInstantiateWithParams(CUgraphExec *phGraphExec, CUgraph hGraph, CUDA_GRAPH_INSTANTIATE_PARAMS *instantiateParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphInstantiateWithParams, phGraphExec, hGraph, instantiateParams);
}

CUresult cuGraphExecGetFlags(CUgraphExec hGraphExec, cuuint64_t *flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecGetFlags, hGraphExec, flags);
}

CUresult cuGraphExecKernelNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, const CUDA_KERNEL_NODE_PARAMS *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecKernelNodeSetParams, hGraphExec, hNode, nodeParams);
}

CUresult cuGraphExecMemcpyNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, const CUDA_MEMCPY3D *copyParams, CUcontext ctx) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecMemcpyNodeSetParams, hGraphExec, hNode, copyParams, ctx);
}

CUresult cuGraphExecMemsetNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, const CUDA_MEMSET_NODE_PARAMS *memsetParams, CUcontext ctx) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecMemsetNodeSetParams, hGraphExec, hNode, memsetParams, ctx);
}

CUresult cuGraphExecHostNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, const CUDA_HOST_NODE_PARAMS *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecHostNodeSetParams, hGraphExec, hNode, nodeParams);
}

CUresult cuGraphExecChildGraphNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, CUgraph childGraph) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecChildGraphNodeSetParams, hGraphExec, hNode, childGraph);
}

CUresult cuGraphExecEventRecordNodeSetEvent(CUgraphExec hGraphExec, CUgraphNode hNode, CUevent event) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecEventRecordNodeSetEvent, hGraphExec, hNode, event);
}

CUresult cuGraphExecEventWaitNodeSetEvent(CUgraphExec hGraphExec, CUgraphNode hNode, CUevent event) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecEventWaitNodeSetEvent, hGraphExec, hNode, event);
}

CUresult cuGraphExecExternalSemaphoresSignalNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, const CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecExternalSemaphoresSignalNodeSetParams, hGraphExec, hNode, nodeParams);
}

CUresult cuGraphExecExternalSemaphoresWaitNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, const CUDA_EXT_SEM_WAIT_NODE_PARAMS *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecExternalSemaphoresWaitNodeSetParams, hGraphExec, hNode, nodeParams);
}

CUresult cuGraphNodeSetEnabled(CUgraphExec hGraphExec, CUgraphNode hNode, unsigned int isEnabled) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphNodeSetEnabled, hGraphExec, hNode, isEnabled);
}

CUresult cuGraphNodeGetEnabled(CUgraphExec hGraphExec, CUgraphNode hNode, unsigned int *isEnabled) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphNodeGetEnabled, hGraphExec, hNode, isEnabled);
}

CUresult cuGraphUpload(CUgraphExec hGraphExec, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphUpload, hGraphExec, hStream);
}

CUresult cuGraphLaunch(CUgraphExec hGraphExec, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphLaunch, hGraphExec, hStream);
}

CUresult cuGraphExecDestroy(CUgraphExec hGraphExec) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecDestroy, hGraphExec);
}

CUresult cuGraphDestroy(CUgraph hGraph) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphDestroy, hGraph);
}

CUresult cuGraphExecUpdate(CUgraphExec hGraphExec, CUgraph hGraph, CUgraphExecUpdateResultInfo *resultInfo) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecUpdate, hGraphExec, hGraph, resultInfo);
}

CUresult cuGraphKernelNodeCopyAttributes(CUgraphNode dst, CUgraphNode src) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphKernelNodeCopyAttributes, dst, src);
}

CUresult cuGraphKernelNodeGetAttribute(CUgraphNode hNode, CUkernelNodeAttrID attr, CUkernelNodeAttrValue *value_out) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphKernelNodeGetAttribute, hNode, attr, value_out);
}

CUresult cuGraphKernelNodeSetAttribute(CUgraphNode hNode, CUkernelNodeAttrID attr, const CUkernelNodeAttrValue *value) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphKernelNodeSetAttribute, hNode, attr, value);
}

CUresult cuGraphDebugDotPrint(CUgraph hGraph, const char *path, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphDebugDotPrint, hGraph, path, flags);
}

CUresult cuUserObjectCreate(CUuserObject *object_out, void *ptr, CUhostFn destroy, unsigned int initialRefcount, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuUserObjectCreate, object_out, ptr, destroy, initialRefcount, flags);
}

CUresult cuUserObjectRetain(CUuserObject object, unsigned int count) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuUserObjectRetain, object, count);
}

CUresult cuUserObjectRelease(CUuserObject object, unsigned int count) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuUserObjectRelease, object, count);
}

CUresult cuGraphRetainUserObject(CUgraph graph, CUuserObject object, unsigned int count, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphRetainUserObject, graph, object, count, flags);
}

CUresult cuGraphReleaseUserObject(CUgraph graph, CUuserObject object, unsigned int count) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphReleaseUserObject, graph, object, count);
}

CUresult cuGraphAddNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, CUgraphNodeParams *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddNode, phGraphNode, hGraph, dependencies, numDependencies, nodeParams);
}

CUresult cuGraphAddNode_v2(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, const CUgraphEdgeData *dependencyData, size_t numDependencies, CUgraphNodeParams *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddNode_v2, phGraphNode, hGraph, dependencies, dependencyData, numDependencies, nodeParams);
}

CUresult cuGraphNodeSetParams(CUgraphNode hNode, CUgraphNodeParams *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphNodeSetParams, hNode, nodeParams);
}

CUresult cuGraphExecNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, CUgraphNodeParams *nodeParams) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecNodeSetParams, hGraphExec, hNode, nodeParams);
}

CUresult cuGraphConditionalHandleCreate(CUgraphConditionalHandle *pHandle_out, CUgraph hGraph, CUcontext ctx, unsigned int defaultLaunchValue, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphConditionalHandleCreate, pHandle_out, hGraph, ctx, defaultLaunchValue, flags);
}

CUresult cuOccupancyMaxActiveBlocksPerMultiprocessor(int *numBlocks, CUfunction func, int blockSize, size_t dynamicSMemSize) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuOccupancyMaxActiveBlocksPerMultiprocessor, numBlocks, func, blockSize, dynamicSMemSize);
}

CUresult cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(int *numBlocks, CUfunction func, int blockSize, size_t dynamicSMemSize, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags, numBlocks, func, blockSize, dynamicSMemSize, flags);
}

CUresult cuOccupancyMaxPotentialBlockSize(int *minGridSize, int *blockSize, CUfunction func, CUoccupancyB2DSize blockSizeToDynamicSMemSize, size_t dynamicSMemSize, int blockSizeLimit) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuOccupancyMaxPotentialBlockSize, minGridSize, blockSize, func, blockSizeToDynamicSMemSize, dynamicSMemSize, blockSizeLimit);
}

CUresult cuOccupancyMaxPotentialBlockSizeWithFlags(int *minGridSize, int *blockSize, CUfunction func, CUoccupancyB2DSize blockSizeToDynamicSMemSize, size_t dynamicSMemSize, int blockSizeLimit, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuOccupancyMaxPotentialBlockSizeWithFlags, minGridSize, blockSize, func, blockSizeToDynamicSMemSize, dynamicSMemSize, blockSizeLimit, flags);
}

CUresult cuOccupancyAvailableDynamicSMemPerBlock(size_t *dynamicSmemSize, CUfunction func, int numBlocks, int blockSize) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuOccupancyAvailableDynamicSMemPerBlock, dynamicSmemSize, func, numBlocks, blockSize);
}

CUresult cuOccupancyMaxPotentialClusterSize(int *clusterSize, CUfunction func, const CUlaunchConfig *config) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuOccupancyMaxPotentialClusterSize, clusterSize, func, config);
}

CUresult cuOccupancyMaxActiveClusters(int *numClusters, CUfunction func, const CUlaunchConfig *config) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuOccupancyMaxActiveClusters, numClusters, func, config);
}

CUresult cuTexRefSetArray(CUtexref hTexRef, CUarray hArray, unsigned int Flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetArray, hTexRef, hArray, Flags);
}

CUresult cuTexRefSetMipmappedArray(CUtexref hTexRef, CUmipmappedArray hMipmappedArray, unsigned int Flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetMipmappedArray, hTexRef, hMipmappedArray, Flags);
}

CUresult cuTexRefSetAddress(size_t *ByteOffset, CUtexref hTexRef, CUdeviceptr dptr, size_t bytes) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetAddress, ByteOffset, hTexRef, dptr, bytes);
}

CUresult cuTexRefSetAddress2D(CUtexref hTexRef, const CUDA_ARRAY_DESCRIPTOR *desc, CUdeviceptr dptr, size_t Pitch) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetAddress2D, hTexRef, desc, dptr, Pitch);
}

CUresult cuTexRefSetFormat(CUtexref hTexRef, CUarray_format fmt, int NumPackedComponents) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetFormat, hTexRef, fmt, NumPackedComponents);
}

CUresult cuTexRefSetAddressMode(CUtexref hTexRef, int dim, CUaddress_mode am) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetAddressMode, hTexRef, dim, am);
}

CUresult cuTexRefSetFilterMode(CUtexref hTexRef, CUfilter_mode fm) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetFilterMode, hTexRef, fm);
}

CUresult cuTexRefSetMipmapFilterMode(CUtexref hTexRef, CUfilter_mode fm) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetMipmapFilterMode, hTexRef, fm);
}

CUresult cuTexRefSetMipmapLevelBias(CUtexref hTexRef, float bias) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetMipmapLevelBias, hTexRef, bias);
}

CUresult cuTexRefSetMipmapLevelClamp(CUtexref hTexRef, float minMipmapLevelClamp, float maxMipmapLevelClamp) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetMipmapLevelClamp, hTexRef, minMipmapLevelClamp, maxMipmapLevelClamp);
}

CUresult cuTexRefSetMaxAnisotropy(CUtexref hTexRef, unsigned int maxAniso) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetMaxAnisotropy, hTexRef, maxAniso);
}

CUresult cuTexRefSetBorderColor(CUtexref hTexRef, float *pBorderColor) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetBorderColor, hTexRef, pBorderColor);
}

CUresult cuTexRefSetFlags(CUtexref hTexRef, unsigned int Flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetFlags, hTexRef, Flags);
}

CUresult cuTexRefGetAddress(CUdeviceptr *pdptr, CUtexref hTexRef) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetAddress, pdptr, hTexRef);
}

CUresult cuTexRefGetArray(CUarray *phArray, CUtexref hTexRef) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetArray, phArray, hTexRef);
}

CUresult cuTexRefGetMipmappedArray(CUmipmappedArray *phMipmappedArray, CUtexref hTexRef) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetMipmappedArray, phMipmappedArray, hTexRef);
}

CUresult cuTexRefGetAddressMode(CUaddress_mode *pam, CUtexref hTexRef, int dim) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetAddressMode, pam, hTexRef, dim);
}

CUresult cuTexRefGetFilterMode(CUfilter_mode *pfm, CUtexref hTexRef) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetFilterMode, pfm, hTexRef);
}

CUresult cuTexRefGetFormat(CUarray_format *pFormat, int *pNumChannels, CUtexref hTexRef) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetFormat, pFormat, pNumChannels, hTexRef);
}

CUresult cuTexRefGetMipmapFilterMode(CUfilter_mode *pfm, CUtexref hTexRef) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetMipmapFilterMode, pfm, hTexRef);
}

CUresult cuTexRefGetMipmapLevelBias(float *pbias, CUtexref hTexRef) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetMipmapLevelBias, pbias, hTexRef);
}

CUresult cuTexRefGetMipmapLevelClamp(float *pminMipmapLevelClamp, float *pmaxMipmapLevelClamp, CUtexref hTexRef) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetMipmapLevelClamp, pminMipmapLevelClamp, pmaxMipmapLevelClamp, hTexRef);
}

CUresult cuTexRefGetMaxAnisotropy(int *pmaxAniso, CUtexref hTexRef) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetMaxAnisotropy, pmaxAniso, hTexRef);
}

CUresult cuTexRefGetBorderColor(float *pBorderColor, CUtexref hTexRef) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetBorderColor, pBorderColor, hTexRef);
}

CUresult cuTexRefGetFlags(unsigned int *pFlags, CUtexref hTexRef) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetFlags, pFlags, hTexRef);
}

CUresult cuTexRefCreate(CUtexref *pTexRef) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefCreate, pTexRef);
}

CUresult cuTexRefDestroy(CUtexref hTexRef) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefDestroy, hTexRef);
}

CUresult cuSurfRefSetArray(CUsurfref hSurfRef, CUarray hArray, unsigned int Flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuSurfRefSetArray, hSurfRef, hArray, Flags);
}

CUresult cuSurfRefGetArray(CUarray *phArray, CUsurfref hSurfRef) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuSurfRefGetArray, phArray, hSurfRef);
}

CUresult cuTexObjectCreate(CUtexObject *pTexObject, const CUDA_RESOURCE_DESC *pResDesc, const CUDA_TEXTURE_DESC *pTexDesc, const CUDA_RESOURCE_VIEW_DESC *pResViewDesc) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexObjectCreate, pTexObject, pResDesc, pTexDesc, pResViewDesc);
}

CUresult cuTexObjectDestroy(CUtexObject texObject) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexObjectDestroy, texObject);
}

CUresult cuTexObjectGetResourceDesc(CUDA_RESOURCE_DESC *pResDesc, CUtexObject texObject) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexObjectGetResourceDesc, pResDesc, texObject);
}

CUresult cuTexObjectGetTextureDesc(CUDA_TEXTURE_DESC *pTexDesc, CUtexObject texObject) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexObjectGetTextureDesc, pTexDesc, texObject);
}

CUresult cuTexObjectGetResourceViewDesc(CUDA_RESOURCE_VIEW_DESC *pResViewDesc, CUtexObject texObject) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexObjectGetResourceViewDesc, pResViewDesc, texObject);
}

CUresult cuSurfObjectCreate(CUsurfObject *pSurfObject, const CUDA_RESOURCE_DESC *pResDesc) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuSurfObjectCreate, pSurfObject, pResDesc);
}

CUresult cuSurfObjectDestroy(CUsurfObject surfObject) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuSurfObjectDestroy, surfObject);
}

CUresult cuSurfObjectGetResourceDesc(CUDA_RESOURCE_DESC *pResDesc, CUsurfObject surfObject) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuSurfObjectGetResourceDesc, pResDesc, surfObject);
}

CUresult cuTensorMapEncodeTiled(CUtensorMap *tensorMap, CUtensorMapDataType tensorDataType, cuuint32_t tensorRank, void *globalAddress, const cuuint64_t *globalDim, const cuuint64_t *globalStrides, const cuuint32_t *boxDim, const cuuint32_t *elementStrides, CUtensorMapInterleave interleave, CUtensorMapSwizzle swizzle, CUtensorMapL2promotion l2Promotion, CUtensorMapFloatOOBfill oobFill) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTensorMapEncodeTiled, tensorMap, tensorDataType, tensorRank, globalAddress, globalDim, globalStrides, boxDim, elementStrides, interleave, swizzle, l2Promotion, oobFill);
}

CUresult cuTensorMapEncodeIm2col(CUtensorMap *tensorMap, CUtensorMapDataType tensorDataType, cuuint32_t tensorRank, void *globalAddress, const cuuint64_t *globalDim, const cuuint64_t *globalStrides, const int *pixelBoxLowerCorner, const int *pixelBoxUpperCorner, cuuint32_t channelsPerPixel, cuuint32_t pixelsPerColumn, const cuuint32_t *elementStrides, CUtensorMapInterleave interleave, CUtensorMapSwizzle swizzle, CUtensorMapL2promotion l2Promotion, CUtensorMapFloatOOBfill oobFill) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTensorMapEncodeIm2col, tensorMap, tensorDataType, tensorRank, globalAddress, globalDim, globalStrides, pixelBoxLowerCorner, pixelBoxUpperCorner, channelsPerPixel, pixelsPerColumn, elementStrides, interleave, swizzle, l2Promotion, oobFill);
}

CUresult cuTensorMapReplaceAddress(CUtensorMap *tensorMap, void *globalAddress) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTensorMapReplaceAddress, tensorMap, globalAddress);
}

CUresult cuDeviceCanAccessPeer(int *canAccessPeer, CUdevice dev, CUdevice peerDev) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceCanAccessPeer, canAccessPeer, dev, peerDev);
}

CUresult cuCtxEnablePeerAccess(CUcontext peerContext, unsigned int Flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxEnablePeerAccess, peerContext, Flags);
}

CUresult cuCtxDisablePeerAccess(CUcontext peerContext) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxDisablePeerAccess, peerContext);
}

CUresult cuDeviceGetP2PAttribute(int *value, CUdevice_P2PAttribute attrib, CUdevice srcDevice, CUdevice dstDevice) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetP2PAttribute, value, attrib, srcDevice, dstDevice);
}

CUresult cuGraphicsUnregisterResource(CUgraphicsResource resource) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsUnregisterResource, resource);
}

CUresult cuGraphicsSubResourceGetMappedArray(CUarray *pArray, CUgraphicsResource resource, unsigned int arrayIndex, unsigned int mipLevel) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsSubResourceGetMappedArray, pArray, resource, arrayIndex, mipLevel);
}

CUresult cuGraphicsResourceGetMappedMipmappedArray(CUmipmappedArray *pMipmappedArray, CUgraphicsResource resource) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsResourceGetMappedMipmappedArray, pMipmappedArray, resource);
}

CUresult cuGraphicsResourceGetMappedPointer(CUdeviceptr *pDevPtr, size_t *pSize, CUgraphicsResource resource) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsResourceGetMappedPointer, pDevPtr, pSize, resource);
}

CUresult cuGraphicsResourceSetMapFlags(CUgraphicsResource resource, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsResourceSetMapFlags, resource, flags);
}

CUresult cuGraphicsMapResources(unsigned int count, CUgraphicsResource *resources, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsMapResources, count, resources, hStream);
}

CUresult cuGraphicsUnmapResources(unsigned int count, CUgraphicsResource *resources, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsUnmapResources, count, resources, hStream);
}

CUresult cuCoredumpGetAttribute(CUcoredumpSettings attrib, void *value, size_t *size) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCoredumpGetAttribute, attrib, value, size);
}

CUresult cuCoredumpGetAttributeGlobal(CUcoredumpSettings attrib, void *value, size_t *size) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCoredumpGetAttributeGlobal, attrib, value, size);
}

CUresult cuCoredumpSetAttribute(CUcoredumpSettings attrib, void *value, size_t *size) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCoredumpSetAttribute, attrib, value, size);
}

CUresult cuCoredumpSetAttributeGlobal(CUcoredumpSettings attrib, void *value, size_t *size) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCoredumpSetAttributeGlobal, attrib, value, size);
}

CUresult cuGetExportTable(const void **ppExportTable, const CUuuid *pExportTableId) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGetExportTable, ppExportTable, pExportTableId);
}

CUresult cuTexRefSetAddress2D_v2(CUtexref hTexRef, const CUDA_ARRAY_DESCRIPTOR *desc, CUdeviceptr dptr, size_t Pitch) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetAddress2D_v2, hTexRef, desc, dptr, Pitch);
}

CUresult cuMemcpyHtoD_v2(CUdeviceptr dstDevice, const void *srcHost, size_t ByteCount) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyHtoD_v2, dstDevice, srcHost, ByteCount);
}

CUresult cuMemcpyDtoH_v2(void *dstHost, CUdeviceptr srcDevice, size_t ByteCount) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoH_v2, dstHost, srcDevice, ByteCount);
}

CUresult cuMemcpyDtoD_v2(CUdeviceptr dstDevice, CUdeviceptr srcDevice, size_t ByteCount) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoD_v2, dstDevice, srcDevice, ByteCount);
}

CUresult cuMemcpyDtoA_v2(CUarray dstArray, size_t dstOffset, CUdeviceptr srcDevice, size_t ByteCount) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoA_v2, dstArray, dstOffset, srcDevice, ByteCount);
}

CUresult cuMemcpyAtoD_v2(CUdeviceptr dstDevice, CUarray srcArray, size_t srcOffset, size_t ByteCount) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAtoD_v2, dstDevice, srcArray, srcOffset, ByteCount);
}

CUresult cuMemcpyHtoA_v2(CUarray dstArray, size_t dstOffset, const void *srcHost, size_t ByteCount) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyHtoA_v2, dstArray, dstOffset, srcHost, ByteCount);
}

CUresult cuMemcpyAtoH_v2(void *dstHost, CUarray srcArray, size_t srcOffset, size_t ByteCount) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAtoH_v2, dstHost, srcArray, srcOffset, ByteCount);
}

CUresult cuMemcpyAtoA_v2(CUarray dstArray, size_t dstOffset, CUarray srcArray, size_t srcOffset, size_t ByteCount) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAtoA_v2, dstArray, dstOffset, srcArray, srcOffset, ByteCount);
}

CUresult cuMemcpyHtoAAsync_v2(CUarray dstArray, size_t dstOffset, const void *srcHost, size_t ByteCount, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyHtoAAsync_v2, dstArray, dstOffset, srcHost, ByteCount, hStream);
}

CUresult cuMemcpyAtoHAsync_v2(void *dstHost, CUarray srcArray, size_t srcOffset, size_t ByteCount, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAtoHAsync_v2, dstHost, srcArray, srcOffset, ByteCount, hStream);
}

CUresult cuMemcpy2D_v2(const CUDA_MEMCPY2D *pCopy) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy2D_v2, pCopy);
}

CUresult cuMemcpy2DUnaligned_v2(const CUDA_MEMCPY2D *pCopy) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy2DUnaligned_v2, pCopy);
}

CUresult cuMemcpy3D_v2(const CUDA_MEMCPY3D *pCopy) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy3D_v2, pCopy);
}

CUresult cuMemcpyHtoDAsync_v2(CUdeviceptr dstDevice, const void *srcHost, size_t ByteCount, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyHtoDAsync_v2, dstDevice, srcHost, ByteCount, hStream);
}

CUresult cuMemcpyDtoHAsync_v2(void *dstHost, CUdeviceptr srcDevice, size_t ByteCount, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoHAsync_v2, dstHost, srcDevice, ByteCount, hStream);
}

CUresult cuMemcpyDtoDAsync_v2(CUdeviceptr dstDevice, CUdeviceptr srcDevice, size_t ByteCount, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoDAsync_v2, dstDevice, srcDevice, ByteCount, hStream);
}

CUresult cuMemcpy2DAsync_v2(const CUDA_MEMCPY2D *pCopy, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy2DAsync_v2, pCopy, hStream);
}

CUresult cuMemcpy3DAsync_v2(const CUDA_MEMCPY3D *pCopy, CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy3DAsync_v2, pCopy, hStream);
}

CUresult cuMemsetD8_v2(CUdeviceptr dstDevice, unsigned char uc, size_t N) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD8_v2, dstDevice, uc, N);
}

CUresult cuMemsetD16_v2(CUdeviceptr dstDevice, unsigned short us, size_t N) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD16_v2, dstDevice, us, N);
}

CUresult cuMemsetD32_v2(CUdeviceptr dstDevice, unsigned int ui, size_t N) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD32_v2, dstDevice, ui, N);
}

CUresult cuMemsetD2D8_v2(CUdeviceptr dstDevice, size_t dstPitch, unsigned char uc, size_t Width, size_t Height) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D8_v2, dstDevice, dstPitch, uc, Width, Height);
}

CUresult cuMemsetD2D16_v2(CUdeviceptr dstDevice, size_t dstPitch, unsigned short us, size_t Width, size_t Height) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D16_v2, dstDevice, dstPitch, us, Width, Height);
}

CUresult cuMemsetD2D32_v2(CUdeviceptr dstDevice, size_t dstPitch, unsigned int ui, size_t Width, size_t Height) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D32_v2, dstDevice, dstPitch, ui, Width, Height);
}

CUresult cuStreamWriteValue32_ptsz(CUstream stream, CUdeviceptr addr, cuuint32_t value, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWriteValue32_ptsz, stream, addr, value, flags);
}

CUresult cuStreamWaitValue32_ptsz(CUstream stream, CUdeviceptr addr, cuuint32_t value, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWaitValue32_ptsz, stream, addr, value, flags);
}

CUresult cuStreamWriteValue64_ptsz(CUstream stream, CUdeviceptr addr, cuuint64_t value, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWriteValue64_ptsz, stream, addr, value, flags);
}

CUresult cuStreamWaitValue64_ptsz(CUstream stream, CUdeviceptr addr, cuuint64_t value, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWaitValue64_ptsz, stream, addr, value, flags);
}

CUresult cuStreamBatchMemOp_ptsz(CUstream stream, unsigned int count, CUstreamBatchMemOpParams *paramArray, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamBatchMemOp_ptsz, stream, count, paramArray, flags);
}

CUresult cuStreamWriteValue32_v2(CUstream stream, CUdeviceptr addr, cuuint32_t value, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWriteValue32_v2, stream, addr, value, flags);
}

CUresult cuStreamWaitValue32_v2(CUstream stream, CUdeviceptr addr, cuuint32_t value, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWaitValue32_v2, stream, addr, value, flags);
}

CUresult cuStreamWriteValue64_v2(CUstream stream, CUdeviceptr addr, cuuint64_t value, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWriteValue64_v2, stream, addr, value, flags);
}

CUresult cuStreamWaitValue64_v2(CUstream stream, CUdeviceptr addr, cuuint64_t value, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWaitValue64_v2, stream, addr, value, flags);
}

CUresult cuStreamBatchMemOp_v2(CUstream stream, unsigned int count, CUstreamBatchMemOpParams *paramArray, unsigned int flags) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamBatchMemOp_v2, stream, count, paramArray, flags);
}

CUresult cuStreamBeginCapture_ptsz(CUstream hStream) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamBeginCapture_ptsz, hStream);
}

CUresult cuStreamBeginCapture_v2(CUstream hStream, CUstreamCaptureMode mode) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamBeginCapture_v2, hStream, mode);
}

CUresult cuStreamGetCaptureInfo_ptsz(CUstream hStream, CUstreamCaptureStatus *captureStatus_out, cuuint64_t *id_out) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamGetCaptureInfo_ptsz, hStream, captureStatus_out, id_out);
}

CUresult cuStreamGetCaptureInfo_v2(CUstream hStream, CUstreamCaptureStatus *captureStatus_out, cuuint64_t *id_out, CUgraph *graph_out, const CUgraphNode **dependencies_out, size_t *numDependencies_out) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamGetCaptureInfo_v2, hStream, captureStatus_out, id_out, graph_out, dependencies_out, numDependencies_out);
}

CUresult cuGraphInstantiate_v2(CUgraphExec *phGraphExec, CUgraph hGraph, CUgraphNode *phErrorNode, char *logBuffer, size_t bufferSize) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphInstantiate_v2, phGraphExec, hGraph, phErrorNode, logBuffer, bufferSize);
}

CUresult cuGetProcAddress_v2_ptsz(const char *symbol, void **funcPtr, int driverVersion, cuuint64_t flags, CUdriverProcAddressQueryResult *symbolStatus) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGetProcAddress_v2_ptsz, symbol, funcPtr, driverVersion, flags, symbolStatus);
}
