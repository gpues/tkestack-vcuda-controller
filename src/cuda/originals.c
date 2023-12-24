#include "include/all.h"
extern void *cuda_library_entry[1024];

CUresult cuArray3DCreate(CUarray *pHandle, const CUDA_ARRAY3D_DESCRIPTOR *pAllocateArray) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuArray3DCreate");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuArray3DCreate, pHandle, pAllocateArray);
}
CUresult cuArray3DGetDescriptor(CUDA_ARRAY3D_DESCRIPTOR *pArrayDescriptor, CUarray hArray) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuArray3DGetDescriptor");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuArray3DGetDescriptor, pArrayDescriptor, hArray);
}
CUresult cuArrayCreate(CUarray *pHandle, const CUDA_ARRAY_DESCRIPTOR *pAllocateArray) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuArrayCreate");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuArrayCreate, pHandle, pAllocateArray);
}
CUresult cuArrayGetDescriptor(CUDA_ARRAY_DESCRIPTOR *pArrayDescriptor, CUarray hArray) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuArrayGetDescriptor");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuArrayGetDescriptor, pArrayDescriptor, hArray);
}
CUresult cuArrayGetDescriptor_v2(CUDA_ARRAY_DESCRIPTOR *pArrayDescriptor, CUarray hArray) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuArrayGetDescriptor_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuArrayGetDescriptor_v2, pArrayDescriptor, hArray);
}
CUresult cuArrayGetPlane(CUarray *pPlaneArray, CUarray hArray, unsigned int planeIdx) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuArrayGetPlane");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuArrayGetPlane, pPlaneArray, hArray, planeIdx);
}
CUresult cuArrayGetSparseProperties(CUDA_ARRAY_SPARSE_PROPERTIES *sparseProperties, CUarray array) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuArrayGetSparseProperties");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuArrayGetSparseProperties, sparseProperties, array);
}
CUresult cuCtxAttach(CUcontext *pctx, unsigned int flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuCtxAttach");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxAttach, pctx, flags);
}
CUresult cuCtxCreate(CUcontext *pctx, unsigned int flags, CUdevice dev) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuCtxCreate");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxCreate, pctx, flags, dev);
}
CUresult cuCtxCreate_v3(CUcontext *pctx, CUexecAffinityParam *paramsArray, int numParams, unsigned int flags, CUdevice dev) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuCtxCreate_v3");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxCreate_v3, pctx, paramsArray, numParams, flags, dev);
}
CUresult cuCtxDestroy(CUcontext ctx) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuCtxDestroy");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxDestroy, ctx);
}
CUresult cuCtxDetach(CUcontext ctx) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuCtxDetach");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxDetach, ctx);
}
CUresult cuCtxDisablePeerAccess(CUcontext peerContext) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuCtxDisablePeerAccess");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxDisablePeerAccess, peerContext);
}
CUresult cuCtxEnablePeerAccess(CUcontext peerContext, unsigned int Flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuCtxEnablePeerAccess");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxEnablePeerAccess, peerContext, Flags);
}
CUresult cuCtxGetExecAffinity(CUexecAffinityParam *pExecAffinity, CUexecAffinityType type) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuCtxGetExecAffinity");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetExecAffinity, pExecAffinity, type);
}
CUresult cuCtxPopCurrent(CUcontext *pctx) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuCtxPopCurrent");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxPopCurrent, pctx);
}
CUresult cuCtxPushCurrent(CUcontext ctx) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuCtxPushCurrent");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxPushCurrent, ctx);
}
CUresult cuCtxResetPersistingL2Cache() {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuCtxResetPersistingL2Cache");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxResetPersistingL2Cache, );
}
CUresult cuDestroyExternalMemory(CUexternalMemory extMem) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuDestroyExternalMemory");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDestroyExternalMemory, extMem);
}
CUresult cuDestroyExternalSemaphore(CUexternalSemaphore extSem) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuDestroyExternalSemaphore");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDestroyExternalSemaphore, extSem);
}
CUresult cuDeviceComputeCapability(int *major, int *minor, CUdevice dev) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuDeviceComputeCapability");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceComputeCapability, major, minor, dev);
}
CUresult cuDeviceGetDefaultMemPool(CUmemoryPool *pool_out, CUdevice dev) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuDeviceGetDefaultMemPool");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetDefaultMemPool, pool_out, dev);
}
CUresult cuDeviceGetExecAffinitySupport(int *pi, CUexecAffinityType type, CUdevice dev) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuDeviceGetExecAffinitySupport");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetExecAffinitySupport, pi, type, dev);
}
CUresult cuDeviceGetGraphMemAttribute(CUdevice device, CUgraphMem_attribute attr, void *value) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuDeviceGetGraphMemAttribute");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetGraphMemAttribute, device, attr, value);
}
CUresult cuDeviceGetLuid(char *luid, unsigned int *deviceNodeMask, CUdevice dev) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuDeviceGetLuid");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetLuid, luid, deviceNodeMask, dev);
}
CUresult cuDeviceGetMemPool(CUmemoryPool *pool, CUdevice dev) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuDeviceGetMemPool");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetMemPool, pool, dev);
}
CUresult cuDeviceGetName(char *name, int len, CUdevice dev) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuDeviceGetName");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetName, name, len, dev);
}
CUresult cuDeviceGetNvSciSyncAttributes(void *nvSciSyncAttrList, CUdevice dev, int flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuDeviceGetNvSciSyncAttributes");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetNvSciSyncAttributes, nvSciSyncAttrList, dev, flags);
}
CUresult cuDeviceGetP2PAttribute(int *value, CUdevice_P2PAttribute attrib, CUdevice srcDevice, CUdevice dstDevice) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuDeviceGetP2PAttribute");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetP2PAttribute, value, attrib, srcDevice, dstDevice);
}
CUresult cuDeviceGetProperties(CUdevprop *prop, CUdevice dev) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuDeviceGetProperties");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetProperties, prop, dev);
}
CUresult cuDeviceGetTexture1DLinearMaxWidth(size_t *maxWidthInElements, CUarray_format format, unsigned numChannels, CUdevice dev) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuDeviceGetTexture1DLinearMaxWidth");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetTexture1DLinearMaxWidth, maxWidthInElements, format, numChannels, dev);
}
CUresult cuDeviceGetUuid(CUuuid *uuid, CUdevice dev) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuDeviceGetUuid");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetUuid, uuid, dev);
}
CUresult cuDeviceGetUuid_v2(CUuuid *uuid, CUdevice dev) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuDeviceGetUuid_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetUuid_v2, uuid, dev);
}
CUresult cuDeviceGraphMemTrim(CUdevice device) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuDeviceGraphMemTrim");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGraphMemTrim, device);
}
CUresult cuDevicePrimaryCtxRelease(CUdevice dev) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuDevicePrimaryCtxRelease");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDevicePrimaryCtxRelease, dev);
}
CUresult cuDevicePrimaryCtxReset(CUdevice dev) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuDevicePrimaryCtxReset");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDevicePrimaryCtxReset, dev);
}
CUresult cuDevicePrimaryCtxReset_v2(CUdevice dev) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuDevicePrimaryCtxReset_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDevicePrimaryCtxReset_v2, dev);
}
CUresult cuDevicePrimaryCtxSetFlags(CUdevice dev, unsigned int flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuDevicePrimaryCtxSetFlags");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDevicePrimaryCtxSetFlags, dev, flags);
}
CUresult cuDeviceSetGraphMemAttribute(CUdevice device, CUgraphMem_attribute attr, void *value) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuDeviceSetGraphMemAttribute");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceSetGraphMemAttribute, device, attr, value);
}
CUresult cuDeviceSetMemPool(CUdevice dev, CUmemoryPool pool) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuDeviceSetMemPool");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceSetMemPool, dev, pool);
}
CUresult cuDeviceTotalMem(size_t *bytes, CUdevice dev) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuDeviceTotalMem");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceTotalMem, bytes, dev);
}
CUresult cuEGLApiInit() {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuEGLApiInit");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuEGLApiInit, );
}
CUresult cuEGLInit() {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuEGLInit");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuEGLInit, );
}
CUresult cuEGLStreamConsumerAcquireFrame(CUeglStreamConnection *conn, CUgraphicsResource *pCudaResource, CUstream *pStream, unsigned int timeout) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuEGLStreamConsumerAcquireFrame");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuEGLStreamConsumerAcquireFrame, conn, pCudaResource, pStream, timeout);
}
CUresult cuEGLStreamConsumerConnect(CUeglStreamConnection *conn, EGLStreamKHR stream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuEGLStreamConsumerConnect");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuEGLStreamConsumerConnect, conn, stream);
}
CUresult cuEGLStreamConsumerConnectWithFlags(CUeglStreamConnection *conn, EGLStreamKHR stream, unsigned int flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuEGLStreamConsumerConnectWithFlags");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuEGLStreamConsumerConnectWithFlags, conn, stream, flags);
}
CUresult cuEGLStreamConsumerDisconnect(CUeglStreamConnection *conn) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuEGLStreamConsumerDisconnect");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuEGLStreamConsumerDisconnect, conn);
}
CUresult cuEGLStreamConsumerReleaseFrame(CUeglStreamConnection *conn, CUgraphicsResource pCudaResource, CUstream *pStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuEGLStreamConsumerReleaseFrame");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuEGLStreamConsumerReleaseFrame, conn, pCudaResource, pStream);
}
CUresult cuEGLStreamProducerConnect(CUeglStreamConnection *conn, EGLStreamKHR stream, EGLint width, EGLint height) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuEGLStreamProducerConnect");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuEGLStreamProducerConnect, conn, stream, width, height);
}
CUresult cuEGLStreamProducerDisconnect(CUeglStreamConnection *conn) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuEGLStreamProducerDisconnect");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuEGLStreamProducerDisconnect, conn);
}
CUresult cuEGLStreamProducerPresentFrame(CUeglStreamConnection *conn, CUeglFrame eglframe, CUstream *pStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuEGLStreamProducerPresentFrame");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuEGLStreamProducerPresentFrame, conn, eglframe, pStream);
}
CUresult cuEGLStreamProducerReturnFrame(CUeglStreamConnection *conn, CUeglFrame *eglframe, CUstream *pStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuEGLStreamProducerReturnFrame");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuEGLStreamProducerReturnFrame, conn, eglframe, pStream);
}
CUresult cuEventCreate(CUevent *phEvent, unsigned int Flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuEventCreate");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuEventCreate, phEvent, Flags);
}
CUresult cuEventDestroy(CUevent hEvent) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuEventDestroy");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuEventDestroy, hEvent);
}
CUresult cuEventDestroy_v2(CUevent hEvent) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuEventDestroy_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuEventDestroy_v2, hEvent);
}
CUresult cuEventElapsedTime(float *pMilliseconds, CUevent hStart, CUevent hEnd) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuEventElapsedTime");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuEventElapsedTime, pMilliseconds, hStart, hEnd);
}
CUresult cuEventQuery(CUevent hEvent) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuEventQuery");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuEventQuery, hEvent);
}
CUresult cuEventRecord(CUevent hEvent, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuEventRecord");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuEventRecord, hEvent, hStream);
}
CUresult cuEventRecordWithFlags(CUevent hEvent, CUstream hStream, unsigned int flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuEventRecordWithFlags");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuEventRecordWithFlags, hEvent, hStream, flags);
}
CUresult cuEventRecordWithFlags_ptsz(CUevent hEvent, CUstream hStream, unsigned int flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuEventRecordWithFlags_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuEventRecordWithFlags_ptsz, hEvent, hStream, flags);
}
CUresult cuEventRecord_ptsz(CUevent hEvent, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuEventRecord_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuEventRecord_ptsz, hEvent, hStream);
}
CUresult cuEventSynchronize(CUevent hEvent) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuEventSynchronize");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuEventSynchronize, hEvent);
}
CUresult cuExternalMemoryGetMappedBuffer(CUdeviceptr *devPtr, CUexternalMemory extMem, const CUDA_EXTERNAL_MEMORY_BUFFER_DESC *bufferDesc) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuExternalMemoryGetMappedBuffer");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuExternalMemoryGetMappedBuffer, devPtr, extMem, bufferDesc);
}
CUresult cuExternalMemoryGetMappedMipmappedArray(CUmipmappedArray *mipmap, CUexternalMemory extMem, const CUDA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC *mipmapDesc) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuExternalMemoryGetMappedMipmappedArray");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuExternalMemoryGetMappedMipmappedArray, mipmap, extMem, mipmapDesc);
}
CUresult cuFlushGPUDirectRDMAWrites(CUflushGPUDirectRDMAWritesTarget target, CUflushGPUDirectRDMAWritesScope scope) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuFlushGPUDirectRDMAWrites");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuFlushGPUDirectRDMAWrites, target, scope);
}
CUresult cuFuncGetAttribute(int *pi, CUfunction_attribute attrib, CUfunction hfunc) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuFuncGetAttribute");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuFuncGetAttribute, pi, attrib, hfunc);
}
CUresult cuFuncGetModule(CUmodule *hmod, CUfunction hfunc) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuFuncGetModule");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuFuncGetModule, hmod, hfunc);
}
CUresult cuFuncSetAttribute(CUfunction hfunc, CUfunction_attribute attrib, int value) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuFuncSetAttribute");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuFuncSetAttribute, hfunc, attrib, value);
}
CUresult cuFuncSetBlockShape(CUfunction hfunc, int x, int y, int z) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuFuncSetBlockShape");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuFuncSetBlockShape, hfunc, x, y, z);
}
CUresult cuFuncSetCacheConfig(CUfunction hfunc, CUfunc_cache config) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuFuncSetCacheConfig");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuFuncSetCacheConfig, hfunc, config);
}
CUresult cuFuncSetSharedMemConfig(CUfunction hfunc, CUsharedconfig config) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuFuncSetSharedMemConfig");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuFuncSetSharedMemConfig, hfunc, config);
}
CUresult cuFuncSetSharedSize(CUfunction hfunc, unsigned int bytes) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuFuncSetSharedSize");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuFuncSetSharedSize, hfunc, bytes);
}
CUresult cuGLCtxCreate(CUcontext *pCtx, unsigned int Flags, CUdevice device) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGLCtxCreate");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGLCtxCreate, pCtx, Flags, device);
}
CUresult cuGLCtxCreate_v2(CUcontext *pCtx, unsigned int Flags, CUdevice device) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGLCtxCreate_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGLCtxCreate_v2, pCtx, Flags, device);
}
CUresult cuGLGetDevices(unsigned int *pCudaDeviceCount, CUdevice *pCudaDevices, unsigned int cudaDeviceCount, CUGLDeviceList deviceList) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGLGetDevices");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGLGetDevices, pCudaDeviceCount, pCudaDevices, cudaDeviceCount, deviceList);
}
CUresult cuGLGetDevices_v2(unsigned int *pCudaDeviceCount, CUdevice *pCudaDevices, unsigned int cudaDeviceCount, CUGLDeviceList deviceList) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGLGetDevices_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGLGetDevices_v2, pCudaDeviceCount, pCudaDevices, cudaDeviceCount, deviceList);
}
CUresult cuGLInit() {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGLInit");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGLInit, );
}
CUresult cuGLMapBufferObject(CUdeviceptr *dptr, size_t *size, GLuint buffer) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGLMapBufferObject");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGLMapBufferObject, dptr, size, buffer);
}
CUresult cuGLMapBufferObjectAsync(CUdeviceptr *dptr, size_t *size, GLuint buffer, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGLMapBufferObjectAsync");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGLMapBufferObjectAsync, dptr, size, buffer, hStream);
}
CUresult cuGLMapBufferObjectAsync_v2(CUdeviceptr *dptr, size_t *size, GLuint buffer, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGLMapBufferObjectAsync_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGLMapBufferObjectAsync_v2, dptr, size, buffer, hStream);
}
CUresult cuGLMapBufferObjectAsync_v2_ptsz(CUdeviceptr *dptr, size_t *size, GLuint buffer, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGLMapBufferObjectAsync_v2_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGLMapBufferObjectAsync_v2_ptsz, dptr, size, buffer, hStream);
}
CUresult cuGLMapBufferObject_v2(CUdeviceptr *dptr, size_t *size, GLuint buffer) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGLMapBufferObject_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGLMapBufferObject_v2, dptr, size, buffer);
}
CUresult cuGLMapBufferObject_v2_ptds(CUdeviceptr *dptr, size_t *size, GLuint buffer) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGLMapBufferObject_v2_ptds");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGLMapBufferObject_v2_ptds, dptr, size, buffer);
}
CUresult cuGLRegisterBufferObject(GLuint buffer) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGLRegisterBufferObject");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGLRegisterBufferObject, buffer);
}
CUresult cuGLSetBufferObjectMapFlags(GLuint buffer, unsigned int Flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGLSetBufferObjectMapFlags");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGLSetBufferObjectMapFlags, buffer, Flags);
}
CUresult cuGLUnmapBufferObject(GLuint buffer) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGLUnmapBufferObject");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGLUnmapBufferObject, buffer);
}
CUresult cuGLUnmapBufferObjectAsync(GLuint buffer, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGLUnmapBufferObjectAsync");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGLUnmapBufferObjectAsync, buffer, hStream);
}
CUresult cuGLUnregisterBufferObject(GLuint buffer) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGLUnregisterBufferObject");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGLUnregisterBufferObject, buffer);
}
CUresult cuGetErrorName(CUresult error, const char **pStr) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGetErrorName");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGetErrorName, error, pStr);
}
CUresult cuGetErrorString(CUresult error, const char **pStr) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGetErrorString");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGetErrorString, error, pStr);
}
CUresult cuGraphAddChildGraphNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, CUgraph childGraph) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphAddChildGraphNode");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddChildGraphNode, phGraphNode, hGraph, dependencies, numDependencies, childGraph);
}
CUresult cuGraphAddDependencies(CUgraph hGraph, const CUgraphNode *from, const CUgraphNode *to, size_t numDependencies) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphAddDependencies");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddDependencies, hGraph, from, to, numDependencies);
}
CUresult cuGraphAddEmptyNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphAddEmptyNode");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddEmptyNode, phGraphNode, hGraph, dependencies, numDependencies);
}
CUresult cuGraphAddEventRecordNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, CUevent event) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphAddEventRecordNode");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddEventRecordNode, phGraphNode, hGraph, dependencies, numDependencies, event);
}
CUresult cuGraphAddEventWaitNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, CUevent event) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphAddEventWaitNode");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddEventWaitNode, phGraphNode, hGraph, dependencies, numDependencies, event);
}
CUresult cuGraphAddExternalSemaphoresSignalNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, const CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *nodeParams) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphAddExternalSemaphoresSignalNode");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddExternalSemaphoresSignalNode, phGraphNode, hGraph, dependencies, numDependencies, nodeParams);
}
CUresult cuGraphAddExternalSemaphoresWaitNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, const CUDA_EXT_SEM_WAIT_NODE_PARAMS *nodeParams) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphAddExternalSemaphoresWaitNode");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddExternalSemaphoresWaitNode, phGraphNode, hGraph, dependencies, numDependencies, nodeParams);
}
CUresult cuGraphAddHostNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, const CUDA_HOST_NODE_PARAMS *nodeParams) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphAddHostNode");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddHostNode, phGraphNode, hGraph, dependencies, numDependencies, nodeParams);
}
CUresult cuGraphAddKernelNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, const CUDA_KERNEL_NODE_PARAMS *nodeParams) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphAddKernelNode");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddKernelNode, phGraphNode, hGraph, dependencies, numDependencies, nodeParams);
}
CUresult cuGraphAddKernelNode_v2(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, const void *nodeParams) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphAddKernelNode_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddKernelNode_v2, phGraphNode, hGraph, dependencies, numDependencies, nodeParams);
}
CUresult cuGraphAddMemAllocNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, CUDA_MEM_ALLOC_NODE_PARAMS *nodeParams) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphAddMemAllocNode");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddMemAllocNode, phGraphNode, hGraph, dependencies, numDependencies, nodeParams);
}
CUresult cuGraphAddMemFreeNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, CUdeviceptr dptr) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphAddMemFreeNode");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddMemFreeNode, phGraphNode, hGraph, dependencies, numDependencies, dptr);
}
CUresult cuGraphAddMemcpyNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, const CUDA_MEMCPY3D *copyParams, CUcontext ctx) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphAddMemcpyNode");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddMemcpyNode, phGraphNode, hGraph, dependencies, numDependencies, copyParams, ctx);
}
CUresult cuGraphAddMemsetNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, const CUDA_MEMSET_NODE_PARAMS *memsetParams, CUcontext ctx) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphAddMemsetNode");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddMemsetNode, phGraphNode, hGraph, dependencies, numDependencies, memsetParams, ctx);
}
CUresult cuGraphChildGraphNodeGetGraph(CUgraphNode hNode, CUgraph *phGraph) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphChildGraphNodeGetGraph");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphChildGraphNodeGetGraph, hNode, phGraph);
}
CUresult cuGraphClone(CUgraph *phGraphClone, CUgraph originalGraph) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphClone");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphClone, phGraphClone, originalGraph);
}
CUresult cuGraphCreate(CUgraph *phGraph, unsigned int flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphCreate");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphCreate, phGraph, flags);
}
CUresult cuGraphDebugDotPrint(CUgraph hGraph, const char *path, unsigned int flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphDebugDotPrint");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphDebugDotPrint, hGraph, path, flags);
}
CUresult cuGraphDestroy(CUgraph hGraph) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphDestroy");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphDestroy, hGraph);
}
CUresult cuGraphDestroyNode(CUgraphNode hNode) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphDestroyNode");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphDestroyNode, hNode);
}
CUresult cuGraphEventRecordNodeGetEvent(CUgraphNode hNode, CUevent *event_out) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphEventRecordNodeGetEvent");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphEventRecordNodeGetEvent, hNode, event_out);
}
CUresult cuGraphEventRecordNodeSetEvent(CUgraphNode hNode, CUevent event) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphEventRecordNodeSetEvent");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphEventRecordNodeSetEvent, hNode, event);
}
CUresult cuGraphEventWaitNodeGetEvent(CUgraphNode hNode, CUevent *event_out) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphEventWaitNodeGetEvent");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphEventWaitNodeGetEvent, hNode, event_out);
}
CUresult cuGraphEventWaitNodeSetEvent(CUgraphNode hNode, CUevent event) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphEventWaitNodeSetEvent");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphEventWaitNodeSetEvent, hNode, event);
}
CUresult cuGraphExecChildGraphNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, CUgraph childGraph) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphExecChildGraphNodeSetParams");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecChildGraphNodeSetParams, hGraphExec, hNode, childGraph);
}
CUresult cuGraphExecDestroy(CUgraphExec hGraphExec) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphExecDestroy");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecDestroy, hGraphExec);
}
CUresult cuGraphExecEventRecordNodeSetEvent(CUgraphExec hGraphExec, CUgraphNode hNode, CUevent event) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphExecEventRecordNodeSetEvent");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecEventRecordNodeSetEvent, hGraphExec, hNode, event);
}
CUresult cuGraphExecEventWaitNodeSetEvent(CUgraphExec hGraphExec, CUgraphNode hNode, CUevent event) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphExecEventWaitNodeSetEvent");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecEventWaitNodeSetEvent, hGraphExec, hNode, event);
}
CUresult cuGraphExecExternalSemaphoresSignalNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, const CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *nodeParams) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphExecExternalSemaphoresSignalNodeSetParams");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecExternalSemaphoresSignalNodeSetParams, hGraphExec, hNode, nodeParams);
}
CUresult cuGraphExecExternalSemaphoresWaitNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, const CUDA_EXT_SEM_WAIT_NODE_PARAMS *nodeParams) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphExecExternalSemaphoresWaitNodeSetParams");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecExternalSemaphoresWaitNodeSetParams, hGraphExec, hNode, nodeParams);
}
CUresult cuGraphExecHostNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, const CUDA_HOST_NODE_PARAMS *nodeParams) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphExecHostNodeSetParams");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecHostNodeSetParams, hGraphExec, hNode, nodeParams);
}
CUresult cuGraphExecKernelNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, const CUDA_KERNEL_NODE_PARAMS *nodeParams) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphExecKernelNodeSetParams");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecKernelNodeSetParams, hGraphExec, hNode, nodeParams);
}
CUresult cuGraphExecMemcpyNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, const CUDA_MEMCPY3D *copyParams, CUcontext ctx) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphExecMemcpyNodeSetParams");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecMemcpyNodeSetParams, hGraphExec, hNode, copyParams, ctx);
}
CUresult cuGraphExecMemsetNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, const CUDA_MEMSET_NODE_PARAMS *memsetParams, CUcontext ctx) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphExecMemsetNodeSetParams");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecMemsetNodeSetParams, hGraphExec, hNode, memsetParams, ctx);
}
CUresult cuGraphExecUpdate(CUgraphExec hGraphExec, CUgraph hGraph, CUgraphNode *hErrorNode_out, CUgraphExecUpdateResult *updateResult_out) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphExecUpdate");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecUpdate, hGraphExec, hGraph, hErrorNode_out, updateResult_out);
}
CUresult cuGraphExternalSemaphoresSignalNodeGetParams(CUgraphNode hNode, CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *params_out) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphExternalSemaphoresSignalNodeGetParams");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExternalSemaphoresSignalNodeGetParams, hNode, params_out);
}
CUresult cuGraphExternalSemaphoresSignalNodeSetParams(CUgraphNode hNode, const CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *nodeParams) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphExternalSemaphoresSignalNodeSetParams");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExternalSemaphoresSignalNodeSetParams, hNode, nodeParams);
}
CUresult cuGraphExternalSemaphoresWaitNodeGetParams(CUgraphNode hNode, CUDA_EXT_SEM_WAIT_NODE_PARAMS *params_out) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphExternalSemaphoresWaitNodeGetParams");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExternalSemaphoresWaitNodeGetParams, hNode, params_out);
}
CUresult cuGraphExternalSemaphoresWaitNodeSetParams(CUgraphNode hNode, const CUDA_EXT_SEM_WAIT_NODE_PARAMS *nodeParams) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphExternalSemaphoresWaitNodeSetParams");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExternalSemaphoresWaitNodeSetParams, hNode, nodeParams);
}
CUresult cuGraphGetEdges(CUgraph hGraph, CUgraphNode *from, CUgraphNode *to, size_t *numEdges) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphGetEdges");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphGetEdges, hGraph, from, to, numEdges);
}
CUresult cuGraphGetNodes(CUgraph hGraph, CUgraphNode *nodes, size_t *numNodes) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphGetNodes");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphGetNodes, hGraph, nodes, numNodes);
}
CUresult cuGraphGetRootNodes(CUgraph hGraph, CUgraphNode *rootNodes, size_t *numRootNodes) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphGetRootNodes");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphGetRootNodes, hGraph, rootNodes, numRootNodes);
}
CUresult cuGraphHostNodeGetParams(CUgraphNode hNode, CUDA_HOST_NODE_PARAMS *nodeParams) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphHostNodeGetParams");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphHostNodeGetParams, hNode, nodeParams);
}
CUresult cuGraphHostNodeSetParams(CUgraphNode hNode, const CUDA_HOST_NODE_PARAMS *nodeParams) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphHostNodeSetParams");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphHostNodeSetParams, hNode, nodeParams);
}
CUresult cuGraphInstantiate(CUgraphExec *phGraphExec, CUgraph hGraph, CUgraphNode *phErrorNode, char *logBuffer, size_t bufferSize) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphInstantiate");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphInstantiate, phGraphExec, hGraph, phErrorNode, logBuffer, bufferSize);
}
CUresult cuGraphInstantiateWithFlags(CUgraphExec *phGraphExec, CUgraph hGraph, unsigned long long flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphInstantiateWithFlags");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphInstantiateWithFlags, phGraphExec, hGraph, flags);
}
CUresult cuGraphInstantiate_v2(CUgraphExec *phGraphExec, CUgraph hGraph, CUgraphNode *phErrorNode, char *logBuffer, size_t bufferSize) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphInstantiate_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphInstantiate_v2, phGraphExec, hGraph, phErrorNode, logBuffer, bufferSize);
}
CUresult cuGraphKernelNodeCopyAttributes(CUgraphNode dst, CUgraphNode src) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphKernelNodeCopyAttributes");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphKernelNodeCopyAttributes, dst, src);
}
CUresult cuGraphKernelNodeGetAttribute(CUgraphNode hNode, CUkernelNodeAttrID attr, CUkernelNodeAttrValue *value_out) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphKernelNodeGetAttribute");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphKernelNodeGetAttribute, hNode, attr, value_out);
}
CUresult cuGraphKernelNodeGetParams(CUgraphNode hNode, CUDA_KERNEL_NODE_PARAMS *nodeParams) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphKernelNodeGetParams");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphKernelNodeGetParams, hNode, nodeParams);
}
CUresult cuGraphKernelNodeGetParams_v2(CUgraphNode hNode, void *nodeParams) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphKernelNodeGetParams_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphKernelNodeGetParams_v2, hNode, nodeParams);
}
CUresult cuGraphKernelNodeSetAttribute(CUgraphNode hNode, CUkernelNodeAttrID attr, const CUkernelNodeAttrValue *value) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphKernelNodeSetAttribute");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphKernelNodeSetAttribute, hNode, attr, value);
}
CUresult cuGraphKernelNodeSetParams(CUgraphNode hNode, const CUDA_KERNEL_NODE_PARAMS *nodeParams) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphKernelNodeSetParams");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphKernelNodeSetParams, hNode, nodeParams);
}
CUresult cuGraphKernelNodeSetParams_v2(CUgraphNode hNode, const void *nodeParams) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphKernelNodeSetParams_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphKernelNodeSetParams_v2, hNode, nodeParams);
}
CUresult cuGraphLaunch(CUgraphExec hGraphExec, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphLaunch");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphLaunch, hGraphExec, hStream);
}
CUresult cuGraphLaunch_ptsz(CUgraphExec hGraphExec, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphLaunch_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphLaunch_ptsz, hGraphExec, hStream);
}
CUresult cuGraphMemAllocNodeGetParams(CUgraphNode hNode, CUDA_MEM_ALLOC_NODE_PARAMS *params_out) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphMemAllocNodeGetParams");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphMemAllocNodeGetParams, hNode, params_out);
}
CUresult cuGraphMemFreeNodeGetParams(CUgraphNode hNode, CUdeviceptr *dptr_out) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphMemFreeNodeGetParams");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphMemFreeNodeGetParams, hNode, dptr_out);
}
CUresult cuGraphMemcpyNodeGetParams(CUgraphNode hNode, CUDA_MEMCPY3D *nodeParams) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphMemcpyNodeGetParams");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphMemcpyNodeGetParams, hNode, nodeParams);
}
CUresult cuGraphMemcpyNodeSetParams(CUgraphNode hNode, const CUDA_MEMCPY3D *nodeParams) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphMemcpyNodeSetParams");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphMemcpyNodeSetParams, hNode, nodeParams);
}
CUresult cuGraphMemsetNodeGetParams(CUgraphNode hNode, CUDA_MEMSET_NODE_PARAMS *nodeParams) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphMemsetNodeGetParams");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphMemsetNodeGetParams, hNode, nodeParams);
}
CUresult cuGraphMemsetNodeSetParams(CUgraphNode hNode, const CUDA_MEMSET_NODE_PARAMS *nodeParams) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphMemsetNodeSetParams");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphMemsetNodeSetParams, hNode, nodeParams);
}
CUresult cuGraphNodeFindInClone(CUgraphNode *phNode, CUgraphNode hOriginalNode, CUgraph hClonedGraph) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphNodeFindInClone");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphNodeFindInClone, phNode, hOriginalNode, hClonedGraph);
}
CUresult cuGraphNodeGetDependencies(CUgraphNode hNode, CUgraphNode *dependencies, size_t *numDependencies) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphNodeGetDependencies");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphNodeGetDependencies, hNode, dependencies, numDependencies);
}
CUresult cuGraphNodeGetDependentNodes(CUgraphNode hNode, CUgraphNode *dependentNodes, size_t *numDependentNodes) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphNodeGetDependentNodes");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphNodeGetDependentNodes, hNode, dependentNodes, numDependentNodes);
}
CUresult cuGraphNodeGetType(CUgraphNode hNode, CUgraphNodeType *type) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphNodeGetType");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphNodeGetType, hNode, type);
}
CUresult cuGraphReleaseUserObject(CUgraph graph, CUuserObject object, unsigned int count) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphReleaseUserObject");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphReleaseUserObject, graph, object, count);
}
CUresult cuGraphRemoveDependencies(CUgraph hGraph, const CUgraphNode *from, const CUgraphNode *to, size_t numDependencies) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphRemoveDependencies");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphRemoveDependencies, hGraph, from, to, numDependencies);
}
CUresult cuGraphRetainUserObject(CUgraph graph, CUuserObject object, unsigned int count, unsigned int flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphRetainUserObject");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphRetainUserObject, graph, object, count, flags);
}
CUresult cuGraphUpload(CUgraphExec hGraphExec, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphUpload");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphUpload, hGraphExec, hStream);
}
CUresult cuGraphUpload_ptsz(CUgraphExec hGraphExec, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphUpload_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphUpload_ptsz, hGraphExec, hStream);
}
CUresult cuGraphicsEGLRegisterImage(CUgraphicsResource *pCudaResource, EGLImageKHR image, unsigned int flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphicsEGLRegisterImage");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsEGLRegisterImage, pCudaResource, image, flags);
}
CUresult cuGraphicsGLRegisterBuffer(CUgraphicsResource *pCudaResource, GLuint buffer, unsigned int Flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphicsGLRegisterBuffer");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsGLRegisterBuffer, pCudaResource, buffer, Flags);
}
CUresult cuGraphicsGLRegisterImage(CUgraphicsResource *pCudaResource, GLuint image, GLenum target, unsigned int Flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphicsGLRegisterImage");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsGLRegisterImage, pCudaResource, image, target, Flags);
}
CUresult cuGraphicsMapResources(unsigned int count, CUgraphicsResource *resources, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphicsMapResources");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsMapResources, count, resources, hStream);
}
CUresult cuGraphicsMapResources_ptsz(unsigned int count, CUgraphicsResource *resources, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphicsMapResources_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsMapResources_ptsz, count, resources, hStream);
}
CUresult cuGraphicsResourceGetMappedEglFrame(CUeglFrame *eglFrame, CUgraphicsResource resource, unsigned int index, unsigned int mipLevel) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphicsResourceGetMappedEglFrame");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsResourceGetMappedEglFrame, eglFrame, resource, index, mipLevel);
}
CUresult cuGraphicsResourceGetMappedMipmappedArray(CUmipmappedArray *pMipmappedArray, CUgraphicsResource resource) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphicsResourceGetMappedMipmappedArray");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsResourceGetMappedMipmappedArray, pMipmappedArray, resource);
}
CUresult cuGraphicsResourceGetMappedPointer(CUdeviceptr *pDevPtr, size_t *pSize, CUgraphicsResource resource) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphicsResourceGetMappedPointer");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsResourceGetMappedPointer, pDevPtr, pSize, resource);
}
CUresult cuGraphicsResourceGetMappedPointer_v2(CUdeviceptr *pDevPtr, size_t *pSize, CUgraphicsResource resource) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphicsResourceGetMappedPointer_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsResourceGetMappedPointer_v2, pDevPtr, pSize, resource);
}
CUresult cuGraphicsResourceSetMapFlags(CUgraphicsResource resource, unsigned int flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphicsResourceSetMapFlags");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsResourceSetMapFlags, resource, flags);
}
CUresult cuGraphicsResourceSetMapFlags_v2(CUgraphicsResource resource, unsigned int flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphicsResourceSetMapFlags_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsResourceSetMapFlags_v2, resource, flags);
}
CUresult cuGraphicsSubResourceGetMappedArray(CUarray *pArray, CUgraphicsResource resource, unsigned int arrayIndex, unsigned int mipLevel) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphicsSubResourceGetMappedArray");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsSubResourceGetMappedArray, pArray, resource, arrayIndex, mipLevel);
}
CUresult cuGraphicsUnmapResources(unsigned int count, CUgraphicsResource *resources, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphicsUnmapResources");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsUnmapResources, count, resources, hStream);
}
CUresult cuGraphicsUnmapResources_ptsz(unsigned int count, CUgraphicsResource *resources, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphicsUnmapResources_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsUnmapResources_ptsz, count, resources, hStream);
}
CUresult cuGraphicsUnregisterResource(CUgraphicsResource resource) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphicsUnregisterResource");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsUnregisterResource, resource);
}
CUresult cuGraphicsVDPAURegisterOutputSurface(CUgraphicsResource *pCudaResource, VdpOutputSurface vdpSurface, unsigned int flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphicsVDPAURegisterOutputSurface");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsVDPAURegisterOutputSurface, pCudaResource, vdpSurface, flags);
}
CUresult cuGraphicsVDPAURegisterVideoSurface(CUgraphicsResource *pCudaResource, VdpVideoSurface vdpSurface, unsigned int flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuGraphicsVDPAURegisterVideoSurface");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphicsVDPAURegisterVideoSurface, pCudaResource, vdpSurface, flags);
}
CUresult cuImportExternalMemory(CUexternalMemory *extMem_out, const CUDA_EXTERNAL_MEMORY_HANDLE_DESC *memHandleDesc) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuImportExternalMemory");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuImportExternalMemory, extMem_out, memHandleDesc);
}
CUresult cuImportExternalSemaphore(CUexternalSemaphore *extSem_out, const CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC *semHandleDesc) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuImportExternalSemaphore");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuImportExternalSemaphore, extSem_out, semHandleDesc);
}
CUresult cuIpcGetEventHandle(CUipcEventHandle *pHandle, CUevent event) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuIpcGetEventHandle");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuIpcGetEventHandle, pHandle, event);
}
CUresult cuIpcOpenEventHandle(CUevent *phEvent, CUipcEventHandle handle) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuIpcOpenEventHandle");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuIpcOpenEventHandle, phEvent, handle);
}
CUresult cuIpcOpenMemHandle(CUdeviceptr *pdptr, CUipcMemHandle handle, unsigned int Flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuIpcOpenMemHandle");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuIpcOpenMemHandle, pdptr, handle, Flags);
}
CUresult cuLaunch(CUfunction f) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuLaunch");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLaunch, f);
}
CUresult cuLaunchCooperativeKernelMultiDevice(CUDA_LAUNCH_PARAMS *launchParamsList, unsigned int numDevices, unsigned int flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuLaunchCooperativeKernelMultiDevice");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLaunchCooperativeKernelMultiDevice, launchParamsList, numDevices, flags);
}
CUresult cuLaunchGrid(CUfunction f, int grid_width, int grid_height) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuLaunchGrid");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLaunchGrid, f, grid_width, grid_height);
}
CUresult cuLaunchGridAsync(CUfunction f, int grid_width, int grid_height, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuLaunchGridAsync");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLaunchGridAsync, f, grid_width, grid_height, hStream);
}
CUresult cuLaunchHostFunc(CUstream hStream, CUhostFn fn, void *userData) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuLaunchHostFunc");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLaunchHostFunc, hStream, fn, userData);
}
CUresult cuLaunchHostFunc_ptsz(CUstream hStream, CUhostFn fn, void *userData) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuLaunchHostFunc_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLaunchHostFunc_ptsz, hStream, fn, userData);
}
CUresult cuLinkAddData(CUlinkState state, CUjitInputType type, void *data, size_t size, const char *name, unsigned int numOptions, CUjit_option *options, void **optionValues) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuLinkAddData");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLinkAddData, state, type, data, size, name, numOptions, options, optionValues);
}
CUresult cuLinkAddData_v2(CUlinkState state, CUjitInputType type, void *data, size_t size, const char *name, unsigned int numOptions, CUjit_option *options, void **optionValues) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuLinkAddData_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLinkAddData_v2, state, type, data, size, name, numOptions, options, optionValues);
}
CUresult cuLinkAddFile(CUlinkState state, CUjitInputType type, const char *path, unsigned int numOptions, CUjit_option *options, void **optionValues) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuLinkAddFile");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLinkAddFile, state, type, path, numOptions, options, optionValues);
}
CUresult cuLinkAddFile_v2(CUlinkState state, CUjitInputType type, const char *path, unsigned int numOptions, CUjit_option *options, void **optionValues) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuLinkAddFile_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLinkAddFile_v2, state, type, path, numOptions, options, optionValues);
}
CUresult cuLinkComplete(CUlinkState state, void **cubinOut, size_t *sizeOut) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuLinkComplete");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLinkComplete, state, cubinOut, sizeOut);
}
CUresult cuLinkCreate(unsigned int numOptions, CUjit_option *options, void **optionValues, CUlinkState *stateOut) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuLinkCreate");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLinkCreate, numOptions, options, optionValues, stateOut);
}
CUresult cuLinkCreate_v2(unsigned int numOptions, CUjit_option *options, void **optionValues, CUlinkState *stateOut) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuLinkCreate_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLinkCreate_v2, numOptions, options, optionValues, stateOut);
}
CUresult cuLinkDestroy(CUlinkState state) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuLinkDestroy");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLinkDestroy, state);
}
CUresult cuMemAlloc(CUdeviceptr *dptr, size_t bytesize) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemAlloc");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemAlloc, dptr, bytesize);
}
CUresult cuMemAllocAsync(CUdeviceptr *dptr, size_t bytesize, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemAllocAsync");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemAllocAsync, dptr, bytesize, hStream);
}
CUresult cuMemAllocAsync_ptsz(CUdeviceptr *dptr, size_t bytesize, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemAllocAsync_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemAllocAsync_ptsz, dptr, bytesize, hStream);
}
CUresult cuMemAllocFromPoolAsync(CUdeviceptr *dptr, size_t bytesize, CUmemoryPool pool, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemAllocFromPoolAsync");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemAllocFromPoolAsync, dptr, bytesize, pool, hStream);
}
CUresult cuMemAllocFromPoolAsync_ptsz(CUdeviceptr *dptr, size_t bytesize, CUmemoryPool pool, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemAllocFromPoolAsync_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemAllocFromPoolAsync_ptsz, dptr, bytesize, pool, hStream);
}
CUresult cuMemAllocHost(void **pp, size_t bytesize) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemAllocHost");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemAllocHost, pp, bytesize);
}
CUresult cuMemAllocPitch(CUdeviceptr *dptr, size_t *pPitch, size_t WidthInBytes, size_t Height, unsigned int ElementSizeBytes) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemAllocPitch");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemAllocPitch, dptr, pPitch, WidthInBytes, Height, ElementSizeBytes);
}
CUresult cuMemCreate(CUmemGenericAllocationHandle *handle, size_t size, const CUmemAllocationProp *prop, unsigned long long flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemCreate");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemCreate, handle, size, prop, flags);
}
CUresult cuMemExportToShareableHandle(void *shareableHandle, CUmemGenericAllocationHandle handle, CUmemAllocationHandleType handleType, unsigned long long flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemExportToShareableHandle");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemExportToShareableHandle, shareableHandle, handle, handleType, flags);
}
CUresult cuMemFree(CUdeviceptr dptr) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemFree");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemFree, dptr);
}
CUresult cuMemFreeAsync(CUdeviceptr dptr, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemFreeAsync");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemFreeAsync, dptr, hStream);
}
CUresult cuMemFreeAsync_ptsz(CUdeviceptr dptr, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemFreeAsync_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemFreeAsync_ptsz, dptr, hStream);
}
CUresult cuMemFreeHost(void *p) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemFreeHost");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemFreeHost, p);
}
CUresult cuMemGetAccess(unsigned long long *flags, const CUmemLocation *location, CUdeviceptr ptr) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemGetAccess");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemGetAccess, flags, location, ptr);
}
CUresult cuMemGetAddressRange(CUdeviceptr *pbase, size_t *psize, CUdeviceptr dptr) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemGetAddressRange");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemGetAddressRange, pbase, psize, dptr);
}
CUresult cuMemGetAllocationGranularity(size_t *granularity, const CUmemAllocationProp *prop, CUmemAllocationGranularity_flags option) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemGetAllocationGranularity");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemGetAllocationGranularity, granularity, prop, option);
}
CUresult cuMemGetAllocationPropertiesFromHandle(CUmemAllocationProp *prop, CUmemGenericAllocationHandle handle) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemGetAllocationPropertiesFromHandle");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemGetAllocationPropertiesFromHandle, prop, handle);
}
CUresult cuMemGetInfo(size_t *free, size_t *total) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemGetInfo");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemGetInfo, free, total);
}
CUresult cuMemHostGetDevicePointer(CUdeviceptr *pdptr, void *p, unsigned int Flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemHostGetDevicePointer");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemHostGetDevicePointer, pdptr, p, Flags);
}
CUresult cuMemHostGetDevicePointer_v2(CUdeviceptr *pdptr, void *p, unsigned int Flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemHostGetDevicePointer_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemHostGetDevicePointer_v2, pdptr, p, Flags);
}
CUresult cuMemHostGetFlags(unsigned int *pFlags, void *p) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemHostGetFlags");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemHostGetFlags, pFlags, p);
}
CUresult cuMemHostRegister(void *p, size_t bytesize, unsigned int Flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemHostRegister");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemHostRegister, p, bytesize, Flags);
}
CUresult cuMemImportFromShareableHandle(CUmemGenericAllocationHandle *handle, void *osHandle, CUmemAllocationHandleType shHandleType) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemImportFromShareableHandle");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemImportFromShareableHandle, handle, osHandle, shHandleType);
}
CUresult cuMemMapArrayAsync(CUarrayMapInfo *mapInfoList, unsigned int count, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemMapArrayAsync");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemMapArrayAsync, mapInfoList, count, hStream);
}
CUresult cuMemMapArrayAsync_ptsz(CUarrayMapInfo *mapInfoList, unsigned int count, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemMapArrayAsync_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemMapArrayAsync_ptsz, mapInfoList, count, hStream);
}
CUresult cuMemPoolCreate(CUmemoryPool *pool, const CUmemPoolProps *poolProps) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemPoolCreate");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolCreate, pool, poolProps);
}
CUresult cuMemPoolDestroy(CUmemoryPool pool) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemPoolDestroy");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolDestroy, pool);
}
CUresult cuMemPoolExportPointer(CUmemPoolPtrExportData *shareData_out, CUdeviceptr ptr) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemPoolExportPointer");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolExportPointer, shareData_out, ptr);
}
CUresult cuMemPoolExportToShareableHandle(void *handle_out, CUmemoryPool pool, CUmemAllocationHandleType handleType, unsigned long long flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemPoolExportToShareableHandle");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolExportToShareableHandle, handle_out, pool, handleType, flags);
}
CUresult cuMemPoolGetAccess(CUmemAccess_flags *flags, CUmemoryPool memPool, CUmemLocation *location) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemPoolGetAccess");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolGetAccess, flags, memPool, location);
}
CUresult cuMemPoolGetAttribute(CUmemoryPool pool, CUmemPool_attribute attr, void *value) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemPoolGetAttribute");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolGetAttribute, pool, attr, value);
}
CUresult cuMemPoolImportFromShareableHandle(CUmemoryPool *pool_out, void *handle, CUmemAllocationHandleType handleType, unsigned long long flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemPoolImportFromShareableHandle");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolImportFromShareableHandle, pool_out, handle, handleType, flags);
}
CUresult cuMemPoolImportPointer(CUdeviceptr *ptr_out, CUmemoryPool pool, CUmemPoolPtrExportData *shareData) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemPoolImportPointer");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolImportPointer, ptr_out, pool, shareData);
}
CUresult cuMemPoolSetAccess(CUmemoryPool pool, const CUmemAccessDesc *map, size_t count) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemPoolSetAccess");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolSetAccess, pool, map, count);
}
CUresult cuMemPoolSetAttribute(CUmemoryPool pool, CUmemPool_attribute attr, void *value) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemPoolSetAttribute");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolSetAttribute, pool, attr, value);
}
CUresult cuMemPoolTrimTo(CUmemoryPool pool, size_t minBytesToKeep) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemPoolTrimTo");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolTrimTo, pool, minBytesToKeep);
}
CUresult cuMemPrefetchAsync(CUdeviceptr devPtr, size_t count, CUdevice dstDevice, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemPrefetchAsync");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPrefetchAsync, devPtr, count, dstDevice, hStream);
}
CUresult cuMemPrefetchAsync_ptsz(CUdeviceptr devPtr, size_t count, CUdevice dstDevice, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemPrefetchAsync_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPrefetchAsync_ptsz, devPtr, count, dstDevice, hStream);
}
CUresult cuMemRangeGetAttribute(void *data, size_t dataSize, CUmem_range_attribute attribute, CUdeviceptr devPtr, size_t count) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemRangeGetAttribute");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemRangeGetAttribute, data, dataSize, attribute, devPtr, count);
}
CUresult cuMemRangeGetAttributes(void **data, size_t *dataSizes, CUmem_range_attribute *attributes, size_t numAttributes, CUdeviceptr devPtr, size_t count) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemRangeGetAttributes");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemRangeGetAttributes, data, dataSizes, attributes, numAttributes, devPtr, count);
}
CUresult cuMemRetainAllocationHandle(CUmemGenericAllocationHandle *handle, void *addr) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemRetainAllocationHandle");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemRetainAllocationHandle, handle, addr);
}
CUresult cuMemcpy2D(const CUDA_MEMCPY2D *pCopy) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpy2D");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy2D, pCopy);
}
CUresult cuMemcpy2DAsync(const CUDA_MEMCPY2D *pCopy, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpy2DAsync");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy2DAsync, pCopy, hStream);
}
CUresult cuMemcpy2DAsync_v2(const CUDA_MEMCPY2D *pCopy, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpy2DAsync_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy2DAsync_v2, pCopy, hStream);
}
CUresult cuMemcpy2DAsync_v2_ptsz(const CUDA_MEMCPY2D *pCopy, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpy2DAsync_v2_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy2DAsync_v2_ptsz, pCopy, hStream);
}
CUresult cuMemcpy2DUnaligned(const CUDA_MEMCPY2D *pCopy) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpy2DUnaligned");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy2DUnaligned, pCopy);
}
CUresult cuMemcpy2DUnaligned_v2(const CUDA_MEMCPY2D *pCopy) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpy2DUnaligned_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy2DUnaligned_v2, pCopy);
}
CUresult cuMemcpy2DUnaligned_v2_ptds(const CUDA_MEMCPY2D *pCopy) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpy2DUnaligned_v2_ptds");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy2DUnaligned_v2_ptds, pCopy);
}
CUresult cuMemcpy2D_v2(const CUDA_MEMCPY2D *pCopy) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpy2D_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy2D_v2, pCopy);
}
CUresult cuMemcpy3D(const CUDA_MEMCPY3D *pCopy) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpy3D");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy3D, pCopy);
}
CUresult cuMemcpy3DAsync(const CUDA_MEMCPY3D *pCopy, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpy3DAsync");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy3DAsync, pCopy, hStream);
}
CUresult cuMemcpy3DAsync_v2(const CUDA_MEMCPY3D *pCopy, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpy3DAsync_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy3DAsync_v2, pCopy, hStream);
}
CUresult cuMemcpy3DAsync_v2_ptsz(const CUDA_MEMCPY3D *pCopy, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpy3DAsync_v2_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy3DAsync_v2_ptsz, pCopy, hStream);
}
CUresult cuMemcpy3DPeer(const CUDA_MEMCPY3D_PEER *pCopy) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpy3DPeer");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy3DPeer, pCopy);
}
CUresult cuMemcpy3DPeerAsync(const CUDA_MEMCPY3D_PEER *pCopy, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpy3DPeerAsync");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy3DPeerAsync, pCopy, hStream);
}
CUresult cuMemcpy3DPeerAsync_ptsz(const CUDA_MEMCPY3D_PEER *pCopy, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpy3DPeerAsync_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy3DPeerAsync_ptsz, pCopy, hStream);
}
CUresult cuMemcpy3DPeer_ptds(const CUDA_MEMCPY3D_PEER *pCopy) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpy3DPeer_ptds");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy3DPeer_ptds, pCopy);
}
CUresult cuMemcpy3D_v2(const CUDA_MEMCPY3D *pCopy) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpy3D_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy3D_v2, pCopy);
}
CUresult cuMemcpy3D_v2_ptds(const CUDA_MEMCPY3D *pCopy) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpy3D_v2_ptds");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy3D_v2_ptds, pCopy);
}
CUresult cuMemcpyAsync_ptsz(CUdeviceptr dst, CUdeviceptr src, size_t ByteCount, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpyAsync_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAsync_ptsz, dst, src, ByteCount, hStream);
}
CUresult cuMemcpyAtoA(CUarray dstArray, size_t dstOffset, CUarray srcArray, size_t srcOffset, size_t ByteCount) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpyAtoA");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAtoA, dstArray, dstOffset, srcArray, srcOffset, ByteCount);
}
CUresult cuMemcpyAtoA_v2(CUarray dstArray, size_t dstOffset, CUarray srcArray, size_t srcOffset, size_t ByteCount) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpyAtoA_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAtoA_v2, dstArray, dstOffset, srcArray, srcOffset, ByteCount);
}
CUresult cuMemcpyAtoA_v2_ptds(CUarray dstArray, size_t dstOffset, CUarray srcArray, size_t srcOffset, size_t ByteCount) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpyAtoA_v2_ptds");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAtoA_v2_ptds, dstArray, dstOffset, srcArray, srcOffset, ByteCount);
}
CUresult cuMemcpyAtoD(CUdeviceptr dstDevice, CUarray srcArray, size_t srcOffset, size_t ByteCount) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpyAtoD");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAtoD, dstDevice, srcArray, srcOffset, ByteCount);
}
CUresult cuMemcpyAtoD_v2_ptds(CUdeviceptr dstDevice, CUarray srcArray, size_t srcOffset, size_t ByteCount) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpyAtoD_v2_ptds");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAtoD_v2_ptds, dstDevice, srcArray, srcOffset, ByteCount);
}
CUresult cuMemcpyAtoH(void *dstHost, CUarray srcArray, size_t srcOffset, size_t ByteCount) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpyAtoH");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAtoH, dstHost, srcArray, srcOffset, ByteCount);
}
CUresult cuMemcpyAtoHAsync(void *dstHost, CUarray srcArray, size_t srcOffset, size_t ByteCount, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpyAtoHAsync");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAtoHAsync, dstHost, srcArray, srcOffset, ByteCount, hStream);
}
CUresult cuMemcpyAtoHAsync_v2(void *dstHost, CUarray srcArray, size_t srcOffset, size_t ByteCount, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpyAtoHAsync_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAtoHAsync_v2, dstHost, srcArray, srcOffset, ByteCount, hStream);
}
CUresult cuMemcpyAtoHAsync_v2_ptsz(void *dstHost, CUarray srcArray, size_t srcOffset, size_t ByteCount, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpyAtoHAsync_v2_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAtoHAsync_v2_ptsz, dstHost, srcArray, srcOffset, ByteCount, hStream);
}
CUresult cuMemcpyAtoH_v2(void *dstHost, CUarray srcArray, size_t srcOffset, size_t ByteCount) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpyAtoH_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAtoH_v2, dstHost, srcArray, srcOffset, ByteCount);
}
CUresult cuMemcpyAtoH_v2_ptds(void *dstHost, CUarray srcArray, size_t srcOffset, size_t ByteCount) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpyAtoH_v2_ptds");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAtoH_v2_ptds, dstHost, srcArray, srcOffset, ByteCount);
}
CUresult cuMemcpyDtoA(CUarray dstArray, size_t dstOffset, CUdeviceptr srcDevice, size_t ByteCount) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpyDtoA");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoA, dstArray, dstOffset, srcDevice, ByteCount);
}
CUresult cuMemcpyDtoA_v2_ptds(CUarray dstArray, size_t dstOffset, CUdeviceptr srcDevice, size_t ByteCount) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpyDtoA_v2_ptds");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoA_v2_ptds, dstArray, dstOffset, srcDevice, ByteCount);
}
CUresult cuMemcpyDtoD(CUdeviceptr dstDevice, CUdeviceptr srcDevice, size_t ByteCount) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpyDtoD");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoD, dstDevice, srcDevice, ByteCount);
}
CUresult cuMemcpyDtoDAsync(CUdeviceptr dstDevice, CUdeviceptr srcDevice, size_t ByteCount, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpyDtoDAsync");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoDAsync, dstDevice, srcDevice, ByteCount, hStream);
}
CUresult cuMemcpyDtoDAsync_v2_ptsz(CUdeviceptr dstDevice, CUdeviceptr srcDevice, size_t ByteCount, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpyDtoDAsync_v2_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoDAsync_v2_ptsz, dstDevice, srcDevice, ByteCount, hStream);
}
CUresult cuMemcpyDtoD_v2_ptds(CUdeviceptr dstDevice, CUdeviceptr srcDevice, size_t ByteCount) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpyDtoD_v2_ptds");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoD_v2_ptds, dstDevice, srcDevice, ByteCount);
}
CUresult cuMemcpyDtoH(void *dstHost, CUdeviceptr srcDevice, size_t ByteCount) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpyDtoH");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoH, dstHost, srcDevice, ByteCount);
}
CUresult cuMemcpyDtoHAsync(void *dstHost, CUdeviceptr srcDevice, size_t ByteCount, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpyDtoHAsync");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoHAsync, dstHost, srcDevice, ByteCount, hStream);
}
CUresult cuMemcpyDtoHAsync_v2_ptsz(void *dstHost, CUdeviceptr srcDevice, size_t ByteCount, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpyDtoHAsync_v2_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoHAsync_v2_ptsz, dstHost, srcDevice, ByteCount, hStream);
}
CUresult cuMemcpyDtoH_v2_ptds(void *dstHost, CUdeviceptr srcDevice, size_t ByteCount) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpyDtoH_v2_ptds");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoH_v2_ptds, dstHost, srcDevice, ByteCount);
}
CUresult cuMemcpyHtoA(CUarray dstArray, size_t dstOffset, const void *srcHost, size_t ByteCount) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpyHtoA");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyHtoA, dstArray, dstOffset, srcHost, ByteCount);
}
CUresult cuMemcpyHtoAAsync(CUarray dstArray, size_t dstOffset, const void *srcHost, size_t ByteCount, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpyHtoAAsync");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyHtoAAsync, dstArray, dstOffset, srcHost, ByteCount, hStream);
}
CUresult cuMemcpyHtoAAsync_v2(CUarray dstArray, size_t dstOffset, const void *srcHost, size_t ByteCount, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpyHtoAAsync_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyHtoAAsync_v2, dstArray, dstOffset, srcHost, ByteCount, hStream);
}
CUresult cuMemcpyHtoAAsync_v2_ptsz(CUarray dstArray, size_t dstOffset, const void *srcHost, size_t ByteCount, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpyHtoAAsync_v2_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyHtoAAsync_v2_ptsz, dstArray, dstOffset, srcHost, ByteCount, hStream);
}
CUresult cuMemcpyHtoA_v2(CUarray dstArray, size_t dstOffset, const void *srcHost, size_t ByteCount) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpyHtoA_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyHtoA_v2, dstArray, dstOffset, srcHost, ByteCount);
}
CUresult cuMemcpyHtoA_v2_ptds(CUarray dstArray, size_t dstOffset, const void *srcHost, size_t ByteCount) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpyHtoA_v2_ptds");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyHtoA_v2_ptds, dstArray, dstOffset, srcHost, ByteCount);
}
CUresult cuMemcpyHtoD(CUdeviceptr dstDevice, const void *srcHost, size_t ByteCount) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpyHtoD");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyHtoD, dstDevice, srcHost, ByteCount);
}
CUresult cuMemcpyHtoDAsync(CUdeviceptr dstDevice, const void *srcHost, size_t ByteCount, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpyHtoDAsync");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyHtoDAsync, dstDevice, srcHost, ByteCount, hStream);
}
CUresult cuMemcpyHtoDAsync_v2_ptsz(CUdeviceptr dstDevice, const void *srcHost, size_t ByteCount, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpyHtoDAsync_v2_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyHtoDAsync_v2_ptsz, dstDevice, srcHost, ByteCount, hStream);
}
CUresult cuMemcpyHtoD_v2_ptds(CUdeviceptr dstDevice, const void *srcHost, size_t ByteCount) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpyHtoD_v2_ptds");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyHtoD_v2_ptds, dstDevice, srcHost, ByteCount);
}
CUresult cuMemcpyPeerAsync_ptsz(CUdeviceptr dstDevice, CUcontext dstContext, CUdeviceptr srcDevice, CUcontext srcContext, size_t ByteCount, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpyPeerAsync_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyPeerAsync_ptsz, dstDevice, dstContext, srcDevice, srcContext, ByteCount, hStream);
}
CUresult cuMemcpyPeer_ptds(CUdeviceptr dstDevice, CUcontext dstContext, CUdeviceptr srcDevice, CUcontext srcContext, size_t ByteCount) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpyPeer_ptds");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyPeer_ptds, dstDevice, dstContext, srcDevice, srcContext, ByteCount);
}
CUresult cuMemcpy_ptds(CUdeviceptr dst, CUdeviceptr src, size_t ByteCount) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemcpy_ptds");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy_ptds, dst, src, ByteCount);
}
CUresult cuMemsetD16(CUdeviceptr dstDevice, unsigned short us, size_t N) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemsetD16");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD16, dstDevice, us, N);
}
CUresult cuMemsetD16Async_ptsz(CUdeviceptr dstDevice, unsigned short us, size_t N, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemsetD16Async_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD16Async_ptsz, dstDevice, us, N, hStream);
}
CUresult cuMemsetD16_v2_ptds(CUdeviceptr dstDevice, unsigned short us, size_t N) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemsetD16_v2_ptds");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD16_v2_ptds, dstDevice, us, N);
}
CUresult cuMemsetD2D16(CUdeviceptr dstDevice, size_t dstPitch, unsigned short us, size_t Width, size_t Height) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemsetD2D16");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D16, dstDevice, dstPitch, us, Width, Height);
}
CUresult cuMemsetD2D16Async_ptsz(CUdeviceptr dstDevice, size_t dstPitch, unsigned short us, size_t Width, size_t Height, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemsetD2D16Async_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D16Async_ptsz, dstDevice, dstPitch, us, Width, Height, hStream);
}
CUresult cuMemsetD2D16_v2_ptds(CUdeviceptr dstDevice, size_t dstPitch, unsigned short us, size_t Width, size_t Height) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemsetD2D16_v2_ptds");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D16_v2_ptds, dstDevice, dstPitch, us, Width, Height);
}
CUresult cuMemsetD2D32(CUdeviceptr dstDevice, size_t dstPitch, unsigned int ui, size_t Width, size_t Height) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemsetD2D32");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D32, dstDevice, dstPitch, ui, Width, Height);
}
CUresult cuMemsetD2D32Async_ptsz(CUdeviceptr dstDevice, size_t dstPitch, unsigned int ui, size_t Width, size_t Height, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemsetD2D32Async_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D32Async_ptsz, dstDevice, dstPitch, ui, Width, Height, hStream);
}
CUresult cuMemsetD2D32_v2_ptds(CUdeviceptr dstDevice, size_t dstPitch, unsigned int ui, size_t Width, size_t Height) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemsetD2D32_v2_ptds");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D32_v2_ptds, dstDevice, dstPitch, ui, Width, Height);
}
CUresult cuMemsetD2D8(CUdeviceptr dstDevice, size_t dstPitch, unsigned char uc, size_t Width, size_t Height) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemsetD2D8");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D8, dstDevice, dstPitch, uc, Width, Height);
}
CUresult cuMemsetD2D8Async_ptsz(CUdeviceptr dstDevice, size_t dstPitch, unsigned char uc, size_t Width, size_t Height, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemsetD2D8Async_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D8Async_ptsz, dstDevice, dstPitch, uc, Width, Height, hStream);
}
CUresult cuMemsetD2D8_v2_ptds(CUdeviceptr dstDevice, size_t dstPitch, unsigned char uc, size_t Width, size_t Height) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemsetD2D8_v2_ptds");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D8_v2_ptds, dstDevice, dstPitch, uc, Width, Height);
}
CUresult cuMemsetD32(CUdeviceptr dstDevice, unsigned int ui, size_t N) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemsetD32");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD32, dstDevice, ui, N);
}
CUresult cuMemsetD32Async_ptsz(CUdeviceptr dstDevice, unsigned int ui, size_t N, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemsetD32Async_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD32Async_ptsz, dstDevice, ui, N, hStream);
}
CUresult cuMemsetD32_v2_ptds(CUdeviceptr dstDevice, unsigned int ui, size_t N) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemsetD32_v2_ptds");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD32_v2_ptds, dstDevice, ui, N);
}
CUresult cuMemsetD8(CUdeviceptr dstDevice, unsigned char uc, size_t N) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemsetD8");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD8, dstDevice, uc, N);
}
CUresult cuMemsetD8Async_ptsz(CUdeviceptr dstDevice, unsigned char uc, size_t N, CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemsetD8Async_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD8Async_ptsz, dstDevice, uc, N, hStream);
}
CUresult cuMemsetD8_v2_ptds(CUdeviceptr dstDevice, unsigned char uc, size_t N) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMemsetD8_v2_ptds");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD8_v2_ptds, dstDevice, uc, N);
}
CUresult cuMipmappedArrayDestroy(CUmipmappedArray hMipmappedArray) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMipmappedArrayDestroy");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMipmappedArrayDestroy, hMipmappedArray);
}
CUresult cuMipmappedArrayGetLevel(CUarray *pLevelArray, CUmipmappedArray hMipmappedArray, unsigned int level) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMipmappedArrayGetLevel");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMipmappedArrayGetLevel, pLevelArray, hMipmappedArray, level);
}
CUresult cuMipmappedArrayGetSparseProperties(CUDA_ARRAY_SPARSE_PROPERTIES *sparseProperties, CUmipmappedArray mipmap) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuMipmappedArrayGetSparseProperties");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMipmappedArrayGetSparseProperties, sparseProperties, mipmap);
}
CUresult cuModuleGetFunction(CUfunction *hfunc, CUmodule hmod, const char *name) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuModuleGetFunction");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleGetFunction, hfunc, hmod, name);
}
CUresult cuModuleGetGlobal(CUdeviceptr *dptr, size_t *bytes, CUmodule hmod, const char *name) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuModuleGetGlobal");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleGetGlobal, dptr, bytes, hmod, name);
}
CUresult cuModuleGetGlobal_v2(CUdeviceptr *dptr, size_t *bytes, CUmodule hmod, const char *name) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuModuleGetGlobal_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleGetGlobal_v2, dptr, bytes, hmod, name);
}
CUresult cuModuleGetSurfRef(CUsurfref *pSurfRef, CUmodule hmod, const char *name) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuModuleGetSurfRef");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleGetSurfRef, pSurfRef, hmod, name);
}
CUresult cuModuleGetTexRef(CUtexref *pTexRef, CUmodule hmod, const char *name) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuModuleGetTexRef");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleGetTexRef, pTexRef, hmod, name);
}
CUresult cuModuleLoad(CUmodule *module, const char *fname) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuModuleLoad");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleLoad, module, fname);
}
CUresult cuModuleLoadData(CUmodule *module, const void *image) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuModuleLoadData");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleLoadData, module, image);
}
CUresult cuModuleLoadDataEx(CUmodule *module, const void *image, unsigned int numOptions, CUjit_option *options, void **optionValues) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuModuleLoadDataEx");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleLoadDataEx, module, image, numOptions, options, optionValues);
}
CUresult cuModuleLoadFatBinary(CUmodule *module, const void *fatCubin) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuModuleLoadFatBinary");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleLoadFatBinary, module, fatCubin);
}
CUresult cuModuleUnload(CUmodule hmod) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuModuleUnload");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleUnload, hmod);
}
CUresult cuOccupancyAvailableDynamicSMemPerBlock(size_t *dynamicSmemSize, CUfunction func, int numBlocks, int blockSize) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuOccupancyAvailableDynamicSMemPerBlock");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuOccupancyAvailableDynamicSMemPerBlock, dynamicSmemSize, func, numBlocks, blockSize);
}
CUresult cuOccupancyMaxActiveBlocksPerMultiprocessor(int *numBlocks, CUfunction func, int blockSize, size_t dynamicSMemSize) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuOccupancyMaxActiveBlocksPerMultiprocessor");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuOccupancyMaxActiveBlocksPerMultiprocessor, numBlocks, func, blockSize, dynamicSMemSize);
}
CUresult cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(int *numBlocks, CUfunction func, int blockSize, size_t dynamicSMemSize, unsigned int flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags, numBlocks, func, blockSize, dynamicSMemSize, flags);
}
CUresult cuOccupancyMaxPotentialBlockSize(int *minGridSize, int *blockSize, CUfunction func, CUoccupancyB2DSize blockSizeToDynamicSMemSize, size_t dynamicSMemSize, int blockSizeLimit) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuOccupancyMaxPotentialBlockSize");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuOccupancyMaxPotentialBlockSize, minGridSize, blockSize, func, blockSizeToDynamicSMemSize, dynamicSMemSize, blockSizeLimit);
}
CUresult cuOccupancyMaxPotentialBlockSizeWithFlags(int *minGridSize, int *blockSize, CUfunction func, CUoccupancyB2DSize blockSizeToDynamicSMemSize, size_t dynamicSMemSize, int blockSizeLimit, unsigned int flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuOccupancyMaxPotentialBlockSizeWithFlags");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuOccupancyMaxPotentialBlockSizeWithFlags, minGridSize, blockSize, func, blockSizeToDynamicSMemSize, dynamicSMemSize, blockSizeLimit, flags);
}
CUresult cuParamSetSize(CUfunction hfunc, unsigned int numbytes) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuParamSetSize");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuParamSetSize, hfunc, numbytes);
}
CUresult cuParamSetTexRef(CUfunction hfunc, int texunit, CUtexref hTexRef) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuParamSetTexRef");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuParamSetTexRef, hfunc, texunit, hTexRef);
}
CUresult cuParamSetf(CUfunction hfunc, int vgpu_offset, float value) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuParamSetf");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuParamSetf, hfunc, vgpu_offset, value);
}
CUresult cuParamSeti(CUfunction hfunc, int vgpu_offset, unsigned int value) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuParamSeti");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuParamSeti, hfunc, vgpu_offset, value);
}
CUresult cuParamSetv(CUfunction hfunc, int vgpu_offset, void *ptr, unsigned int numbytes) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuParamSetv");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuParamSetv, hfunc, vgpu_offset, ptr, numbytes);
}
CUresult cuProfilerInitialize(const char *configFile, const char *outputFile, CUoutput_mode outputMode) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuProfilerInitialize");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuProfilerInitialize, configFile, outputFile, outputMode);
}
CUresult cuProfilerStart() {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuProfilerStart");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuProfilerStart, );
}
CUresult cuProfilerStop() {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuProfilerStop");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuProfilerStop, );
}
CUresult cuSignalExternalSemaphoresAsync(const CUexternalSemaphore *extSemArray, const CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS *paramsArray, unsigned int numExtSems, CUstream stream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuSignalExternalSemaphoresAsync");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuSignalExternalSemaphoresAsync, extSemArray, paramsArray, numExtSems, stream);
}
CUresult cuSignalExternalSemaphoresAsync_ptsz(const CUexternalSemaphore *extSemArray, const CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS *paramsArray, unsigned int numExtSems, CUstream stream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuSignalExternalSemaphoresAsync_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuSignalExternalSemaphoresAsync_ptsz, extSemArray, paramsArray, numExtSems, stream);
}
CUresult cuStreamAddCallback(CUstream hStream, CUstreamCallback callback, void *userData, unsigned int flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamAddCallback");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamAddCallback, hStream, callback, userData, flags);
}
CUresult cuStreamAddCallback_ptsz(CUstream hStream, CUstreamCallback callback, void *userData, unsigned int flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamAddCallback_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamAddCallback_ptsz, hStream, callback, userData, flags);
}
CUresult cuStreamAttachMemAsync(CUstream hStream, CUdeviceptr dptr, size_t length, unsigned int flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamAttachMemAsync");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamAttachMemAsync, hStream, dptr, length, flags);
}
CUresult cuStreamAttachMemAsync_ptsz(CUstream hStream, CUdeviceptr dptr, size_t length, unsigned int flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamAttachMemAsync_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamAttachMemAsync_ptsz, hStream, dptr, length, flags);
}
CUresult cuStreamBatchMemOp(CUstream stream, unsigned int count, CUstreamBatchMemOpParams *paramArray, unsigned int flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamBatchMemOp");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamBatchMemOp, stream, count, paramArray, flags);
}
CUresult cuStreamBatchMemOp_ptsz(CUstream stream, unsigned int count, CUstreamBatchMemOpParams *paramArray, unsigned int flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamBatchMemOp_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamBatchMemOp_ptsz, stream, count, paramArray, flags);
}
CUresult cuStreamBeginCapture(CUstream hStream, CUstreamCaptureMode mode) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamBeginCapture");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamBeginCapture, hStream, mode);
}
CUresult cuStreamBeginCapture_ptsz(CUstream hStream, CUstreamCaptureMode mode) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamBeginCapture_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamBeginCapture_ptsz, hStream, mode);
}
CUresult cuStreamBeginCapture_v2(CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamBeginCapture_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamBeginCapture_v2, hStream);
}
CUresult cuStreamBeginCapture_v2_ptsz(CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamBeginCapture_v2_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamBeginCapture_v2_ptsz, hStream);
}
CUresult cuStreamCopyAttributes(CUstream dst, CUstream src) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamCopyAttributes");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamCopyAttributes, dst, src);
}
CUresult cuStreamCopyAttributes_ptsz(CUstream dst, CUstream src) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamCopyAttributes_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamCopyAttributes_ptsz, dst, src);
}
CUresult cuStreamCreate(CUstream *phStream, unsigned int Flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamCreate");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamCreate, phStream, Flags);
}
CUresult cuStreamCreateWithPriority(CUstream *phStream, unsigned int flags, int priority) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamCreateWithPriority");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamCreateWithPriority, phStream, flags, priority);
}
CUresult cuStreamDestroy(CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamDestroy");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamDestroy, hStream);
}
CUresult cuStreamDestroy_v2(CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamDestroy_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamDestroy_v2, hStream);
}
CUresult cuStreamEndCapture(CUstream hStream, CUgraph *phGraph) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamEndCapture");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamEndCapture, hStream, phGraph);
}
CUresult cuStreamEndCapture_ptsz(CUstream hStream, CUgraph *phGraph) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamEndCapture_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamEndCapture_ptsz, hStream, phGraph);
}
CUresult cuStreamGetAttribute(CUstream hStream, CUstreamAttrID attr, CUstreamAttrValue *value_out) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamGetAttribute");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamGetAttribute, hStream, attr, value_out);
}
CUresult cuStreamGetAttribute_ptsz(CUstream hStream, CUstreamAttrID attr, CUstreamAttrValue *value_out) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamGetAttribute_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamGetAttribute_ptsz, hStream, attr, value_out);
}
CUresult cuStreamGetCaptureInfo(CUstream hStream, CUstreamCaptureStatus *captureStatus_out, cuuint64_t *id_out) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamGetCaptureInfo");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamGetCaptureInfo, hStream, captureStatus_out, id_out);
}
CUresult cuStreamGetCaptureInfo_ptsz(CUstream hStream, CUstreamCaptureStatus *captureStatus, cuuint64_t *id) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamGetCaptureInfo_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamGetCaptureInfo_ptsz, hStream, captureStatus, id);
}
CUresult cuStreamGetCaptureInfo_v2(CUstream hStream, CUstreamCaptureStatus *captureStatus_out, cuuint64_t *id_out, CUgraph *graph_out, const CUgraphNode **dependencies_out, size_t *numDependencies_out) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamGetCaptureInfo_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamGetCaptureInfo_v2, hStream, captureStatus_out, id_out, graph_out, dependencies_out, numDependencies_out);
}
CUresult cuStreamGetCaptureInfo_v2_ptsz(CUstream hStream, CUstreamCaptureStatus *captureStatus, cuuint64_t *id) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamGetCaptureInfo_v2_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamGetCaptureInfo_v2_ptsz, hStream, captureStatus, id);
}
CUresult cuStreamGetCtx(CUstream hStream, CUcontext *pctx) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamGetCtx");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamGetCtx, hStream, pctx);
}
CUresult cuStreamGetCtx_ptsz(CUstream hStream, CUcontext *pctx) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamGetCtx_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamGetCtx_ptsz, hStream, pctx);
}
CUresult cuStreamGetFlags(CUstream hStream, unsigned int *flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamGetFlags");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamGetFlags, hStream, flags);
}
CUresult cuStreamGetFlags_ptsz(CUstream hStream, unsigned int *flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamGetFlags_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamGetFlags_ptsz, hStream, flags);
}
CUresult cuStreamGetPriority(CUstream hStream, int *priority) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamGetPriority");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamGetPriority, hStream, priority);
}
CUresult cuStreamGetPriority_ptsz(CUstream hStream, int *priority) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamGetPriority_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamGetPriority_ptsz, hStream, priority);
}
CUresult cuStreamIsCapturing(CUstream hStream, CUstreamCaptureStatus *captureStatus) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamIsCapturing");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamIsCapturing, hStream, captureStatus);
}
CUresult cuStreamIsCapturing_ptsz(CUstream hStream, CUstreamCaptureStatus *captureStatus) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamIsCapturing_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamIsCapturing_ptsz, hStream, captureStatus);
}
CUresult cuStreamQuery(CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamQuery");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamQuery, hStream);
}
CUresult cuStreamQuery_ptsz(CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamQuery_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamQuery_ptsz, hStream);
}
CUresult cuStreamSetAttribute(CUstream hStream, CUstreamAttrID attr, const CUstreamAttrValue *value) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamSetAttribute");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamSetAttribute, hStream, attr, value);
}
CUresult cuStreamSetAttribute_ptsz(CUstream hStream, CUstreamAttrID attr, const CUstreamAttrValue *value) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamSetAttribute_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamSetAttribute_ptsz, hStream, attr, value);
}
CUresult cuStreamSynchronize(CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamSynchronize");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamSynchronize, hStream);
}
CUresult cuStreamSynchronize_ptsz(CUstream hStream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamSynchronize_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamSynchronize_ptsz, hStream);
}
CUresult cuStreamUpdateCaptureDependencies(CUstream hStream, CUgraphNode *dependencies, size_t numDependencies, unsigned int flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamUpdateCaptureDependencies");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamUpdateCaptureDependencies, hStream, dependencies, numDependencies, flags);
}
CUresult cuStreamUpdateCaptureDependencies_ptsz(CUstream hStream, CUgraphNode *dependencies, size_t numDependencies, unsigned int flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamUpdateCaptureDependencies_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamUpdateCaptureDependencies_ptsz, hStream, dependencies, numDependencies, flags);
}
CUresult cuStreamWaitEvent(CUstream hStream, CUevent hEvent, unsigned int Flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamWaitEvent");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWaitEvent, hStream, hEvent, Flags);
}
CUresult cuStreamWaitEvent_ptsz(CUstream hStream, CUevent hEvent, unsigned int Flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamWaitEvent_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWaitEvent_ptsz, hStream, hEvent, Flags);
}
CUresult cuStreamWaitValue32(CUstream stream, CUdeviceptr addr, cuuint32_t value, unsigned int flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamWaitValue32");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWaitValue32, stream, addr, value, flags);
}
CUresult cuStreamWaitValue32_ptsz(CUstream stream, CUdeviceptr addr, cuuint32_t value, unsigned int flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamWaitValue32_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWaitValue32_ptsz, stream, addr, value, flags);
}
CUresult cuStreamWaitValue64(CUstream stream, CUdeviceptr addr, cuuint64_t value, unsigned int flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamWaitValue64");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWaitValue64, stream, addr, value, flags);
}
CUresult cuStreamWaitValue64_ptsz(CUstream stream, CUdeviceptr addr, cuuint64_t value, unsigned int flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamWaitValue64_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWaitValue64_ptsz, stream, addr, value, flags);
}
CUresult cuStreamWriteValue32(CUstream stream, CUdeviceptr addr, cuuint32_t value, unsigned int flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamWriteValue32");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWriteValue32, stream, addr, value, flags);
}
CUresult cuStreamWriteValue32_ptsz(CUstream stream, CUdeviceptr addr, cuuint32_t value, unsigned int flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamWriteValue32_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWriteValue32_ptsz, stream, addr, value, flags);
}
CUresult cuStreamWriteValue64(CUstream stream, CUdeviceptr addr, cuuint64_t value, unsigned int flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamWriteValue64");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWriteValue64, stream, addr, value, flags);
}
CUresult cuStreamWriteValue64_ptsz(CUstream stream, CUdeviceptr addr, cuuint64_t value, unsigned int flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuStreamWriteValue64_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamWriteValue64_ptsz, stream, addr, value, flags);
}
CUresult cuSurfObjectCreate(CUsurfObject *pSurfObject, const CUDA_RESOURCE_DESC *pResDesc) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuSurfObjectCreate");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuSurfObjectCreate, pSurfObject, pResDesc);
}
CUresult cuSurfObjectDestroy(CUsurfObject surfObject) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuSurfObjectDestroy");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuSurfObjectDestroy, surfObject);
}
CUresult cuSurfObjectGetResourceDesc(CUDA_RESOURCE_DESC *pResDesc, CUsurfObject surfObject) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuSurfObjectGetResourceDesc");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuSurfObjectGetResourceDesc, pResDesc, surfObject);
}
CUresult cuSurfRefGetArray(CUarray *phArray, CUsurfref hSurfRef) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuSurfRefGetArray");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuSurfRefGetArray, phArray, hSurfRef);
}
CUresult cuSurfRefSetArray(CUsurfref hSurfRef, CUarray hArray, unsigned int Flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuSurfRefSetArray");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuSurfRefSetArray, hSurfRef, hArray, Flags);
}
CUresult cuTexObjectCreate(CUtexObject *pTexObject, const CUDA_RESOURCE_DESC *pResDesc, const CUDA_TEXTURE_DESC *pTexDesc, const CUDA_RESOURCE_VIEW_DESC *pResViewDesc) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuTexObjectCreate");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexObjectCreate, pTexObject, pResDesc, pTexDesc, pResViewDesc);
}
CUresult cuTexObjectDestroy(CUtexObject texObject) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuTexObjectDestroy");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexObjectDestroy, texObject);
}
CUresult cuTexObjectGetResourceDesc(CUDA_RESOURCE_DESC *pResDesc, CUtexObject texObject) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuTexObjectGetResourceDesc");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexObjectGetResourceDesc, pResDesc, texObject);
}
CUresult cuTexObjectGetResourceViewDesc(CUDA_RESOURCE_VIEW_DESC *pResViewDesc, CUtexObject texObject) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuTexObjectGetResourceViewDesc");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexObjectGetResourceViewDesc, pResViewDesc, texObject);
}
CUresult cuTexObjectGetTextureDesc(CUDA_TEXTURE_DESC *pTexDesc, CUtexObject texObject) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuTexObjectGetTextureDesc");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexObjectGetTextureDesc, pTexDesc, texObject);
}
CUresult cuTexRefCreate(CUtexref *pTexRef) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuTexRefCreate");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefCreate, pTexRef);
}
CUresult cuTexRefDestroy(CUtexref hTexRef) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuTexRefDestroy");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefDestroy, hTexRef);
}
CUresult cuTexRefGetAddress(CUdeviceptr *pdptr, CUtexref hTexRef) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuTexRefGetAddress");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetAddress, pdptr, hTexRef);
}
CUresult cuTexRefGetAddressMode(CUaddress_mode *pam, CUtexref hTexRef, int dim) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuTexRefGetAddressMode");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetAddressMode, pam, hTexRef, dim);
}
CUresult cuTexRefGetAddress_v2(CUdeviceptr *pdptr, CUtexref hTexRef) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuTexRefGetAddress_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetAddress_v2, pdptr, hTexRef);
}
CUresult cuTexRefGetArray(CUarray *phArray, CUtexref hTexRef) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuTexRefGetArray");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetArray, phArray, hTexRef);
}
CUresult cuTexRefGetBorderColor(float *pBorderColor, CUtexref hTexRef) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuTexRefGetBorderColor");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetBorderColor, pBorderColor, hTexRef);
}
CUresult cuTexRefGetFilterMode(CUfilter_mode *pfm, CUtexref hTexRef) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuTexRefGetFilterMode");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetFilterMode, pfm, hTexRef);
}
CUresult cuTexRefGetFlags(unsigned int *pFlags, CUtexref hTexRef) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuTexRefGetFlags");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetFlags, pFlags, hTexRef);
}
CUresult cuTexRefGetFormat(CUarray_format *pFormat, int *pNumChannels, CUtexref hTexRef) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuTexRefGetFormat");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetFormat, pFormat, pNumChannels, hTexRef);
}
CUresult cuTexRefGetMaxAnisotropy(int *pmaxAniso, CUtexref hTexRef) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuTexRefGetMaxAnisotropy");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetMaxAnisotropy, pmaxAniso, hTexRef);
}
CUresult cuTexRefGetMipmapFilterMode(CUfilter_mode *pfm, CUtexref hTexRef) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuTexRefGetMipmapFilterMode");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetMipmapFilterMode, pfm, hTexRef);
}
CUresult cuTexRefGetMipmapLevelBias(float *pbias, CUtexref hTexRef) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuTexRefGetMipmapLevelBias");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetMipmapLevelBias, pbias, hTexRef);
}
CUresult cuTexRefGetMipmapLevelClamp(float *pminMipmapLevelClamp, float *pmaxMipmapLevelClamp, CUtexref hTexRef) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuTexRefGetMipmapLevelClamp");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetMipmapLevelClamp, pminMipmapLevelClamp, pmaxMipmapLevelClamp, hTexRef);
}
CUresult cuTexRefGetMipmappedArray(CUmipmappedArray *phMipmappedArray, CUtexref hTexRef) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuTexRefGetMipmappedArray");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefGetMipmappedArray, phMipmappedArray, hTexRef);
}
CUresult cuTexRefSetAddress(size_t *ByteOffset, CUtexref hTexRef, CUdeviceptr dptr, size_t bytes) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuTexRefSetAddress");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetAddress, ByteOffset, hTexRef, dptr, bytes);
}
CUresult cuTexRefSetAddress2D(CUtexref hTexRef, const CUDA_ARRAY_DESCRIPTOR *desc, CUdeviceptr dptr, size_t Pitch) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuTexRefSetAddress2D");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetAddress2D, hTexRef, desc, dptr, Pitch);
}
CUresult cuTexRefSetAddress2D_v2(CUtexref hTexRef, const CUDA_ARRAY_DESCRIPTOR *desc, CUdeviceptr dptr, size_t Pitch) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuTexRefSetAddress2D_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetAddress2D_v2, hTexRef, desc, dptr, Pitch);
}
CUresult cuTexRefSetAddress2D_v3(CUtexref hTexRef, const CUDA_ARRAY_DESCRIPTOR *desc, CUdeviceptr dptr, size_t Pitch) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuTexRefSetAddress2D_v3");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetAddress2D_v3, hTexRef, desc, dptr, Pitch);
}
CUresult cuTexRefSetAddressMode(CUtexref hTexRef, int dim, CUaddress_mode am) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuTexRefSetAddressMode");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetAddressMode, hTexRef, dim, am);
}
CUresult cuTexRefSetAddress_v2(size_t *ByteOffset, CUtexref hTexRef, CUdeviceptr dptr, size_t bytes) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuTexRefSetAddress_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetAddress_v2, ByteOffset, hTexRef, dptr, bytes);
}
CUresult cuTexRefSetArray(CUtexref hTexRef, CUarray hArray, unsigned int Flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuTexRefSetArray");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetArray, hTexRef, hArray, Flags);
}
CUresult cuTexRefSetBorderColor(CUtexref hTexRef, float *pBorderColor) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuTexRefSetBorderColor");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetBorderColor, hTexRef, pBorderColor);
}
CUresult cuTexRefSetFilterMode(CUtexref hTexRef, CUfilter_mode fm) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuTexRefSetFilterMode");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetFilterMode, hTexRef, fm);
}
CUresult cuTexRefSetFlags(CUtexref hTexRef, unsigned int Flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuTexRefSetFlags");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetFlags, hTexRef, Flags);
}
CUresult cuTexRefSetFormat(CUtexref hTexRef, CUarray_format fmt, int NumPackedComponents) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuTexRefSetFormat");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetFormat, hTexRef, fmt, NumPackedComponents);
}
CUresult cuTexRefSetMaxAnisotropy(CUtexref hTexRef, unsigned int maxAniso) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuTexRefSetMaxAnisotropy");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetMaxAnisotropy, hTexRef, maxAniso);
}
CUresult cuTexRefSetMipmapFilterMode(CUtexref hTexRef, CUfilter_mode fm) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuTexRefSetMipmapFilterMode");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetMipmapFilterMode, hTexRef, fm);
}
CUresult cuTexRefSetMipmapLevelBias(CUtexref hTexRef, float bias) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuTexRefSetMipmapLevelBias");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetMipmapLevelBias, hTexRef, bias);
}
CUresult cuTexRefSetMipmapLevelClamp(CUtexref hTexRef, float minMipmapLevelClamp, float maxMipmapLevelClamp) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuTexRefSetMipmapLevelClamp");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetMipmapLevelClamp, hTexRef, minMipmapLevelClamp, maxMipmapLevelClamp);
}
CUresult cuTexRefSetMipmappedArray(CUtexref hTexRef, CUmipmappedArray hMipmappedArray, unsigned int Flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuTexRefSetMipmappedArray");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuTexRefSetMipmappedArray, hTexRef, hMipmappedArray, Flags);
}
CUresult cuThreadExchangeStreamCaptureMode(CUstreamCaptureMode *mode) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuThreadExchangeStreamCaptureMode");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuThreadExchangeStreamCaptureMode, mode);
}
CUresult cuUserObjectCreate(CUuserObject *object_out, void *ptr, CUhostFn destroy, unsigned int initialRefcount, unsigned int flags) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuUserObjectCreate");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuUserObjectCreate, object_out, ptr, destroy, initialRefcount, flags);
}
CUresult cuUserObjectRelease(CUuserObject object, unsigned int count) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuUserObjectRelease");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuUserObjectRelease, object, count);
}
CUresult cuUserObjectRetain(CUuserObject object, unsigned int count) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuUserObjectRetain");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuUserObjectRetain, object, count);
}
CUresult cuVDPAUCtxCreate(CUcontext *pCtx, unsigned int flags, CUdevice device, VdpDevice vdpDevice, VdpGetProcAddress *vdpGetProcAddress) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuVDPAUCtxCreate");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuVDPAUCtxCreate, pCtx, flags, device, vdpDevice, vdpGetProcAddress);
}
CUresult cuVDPAUCtxCreate_v2(CUcontext *pCtx, unsigned int flags, CUdevice device, VdpDevice vdpDevice, VdpGetProcAddress *vdpGetProcAddress) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuVDPAUCtxCreate_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuVDPAUCtxCreate_v2, pCtx, flags, device, vdpDevice, vdpGetProcAddress);
}
CUresult cuVDPAUGetDevice(CUdevice *pDevice, VdpDevice vdpDevice, VdpGetProcAddress *vdpGetProcAddress) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuVDPAUGetDevice");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuVDPAUGetDevice, pDevice, vdpDevice, vdpGetProcAddress);
}
CUresult cuWaitExternalSemaphoresAsync(const CUexternalSemaphore *extSemArray, const CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS *paramsArray, unsigned int numExtSems, CUstream stream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuWaitExternalSemaphoresAsync");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuWaitExternalSemaphoresAsync, extSemArray, paramsArray, numExtSems, stream);
}
CUresult cuWaitExternalSemaphoresAsync_ptsz(const CUexternalSemaphore *extSemArray, const CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS *paramsArray, unsigned int numExtSems, CUstream stream) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cuWaitExternalSemaphoresAsync_ptsz");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuWaitExternalSemaphoresAsync_ptsz, extSemArray, paramsArray, numExtSems, stream);
}