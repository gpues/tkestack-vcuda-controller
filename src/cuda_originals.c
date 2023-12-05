
// auto generate 351 apis

#include <dlfcn.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "include/base.h"

CUresult cuArray3DGetDescriptor(CUDA_ARRAY3D_DESCRIPTOR *pArrayDescriptor, CUarray hArray) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuArray3DGetDescriptor");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUDA_ARRAY3D_DESCRIPTOR *, CUarray) = (CUresult(*)(CUDA_ARRAY3D_DESCRIPTOR *, CUarray))dlsym(cuda_handle, "cuArray3DGetDescriptor");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pArrayDescriptor, hArray);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuArrayDestroy(CUarray hArray) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuArrayDestroy");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUarray) = (CUresult(*)(CUarray))dlsym(cuda_handle, "cuArrayDestroy");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hArray);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuArrayGetDescriptor(CUDA_ARRAY_DESCRIPTOR *pArrayDescriptor, CUarray hArray) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuArrayGetDescriptor");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUDA_ARRAY_DESCRIPTOR *, CUarray) = (CUresult(*)(CUDA_ARRAY_DESCRIPTOR *, CUarray))dlsym(cuda_handle, "cuArrayGetDescriptor");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pArrayDescriptor, hArray);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuArrayGetMemoryRequirements(CUDA_ARRAY_MEMORY_REQUIREMENTS *memoryRequirements, CUarray array, CUdevice device) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuArrayGetMemoryRequirements");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUDA_ARRAY_MEMORY_REQUIREMENTS *, CUarray, CUdevice) = (CUresult(*)(CUDA_ARRAY_MEMORY_REQUIREMENTS *, CUarray, CUdevice))dlsym(cuda_handle, "cuArrayGetMemoryRequirements");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(memoryRequirements, array, device);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuArrayGetPlane(CUarray *pPlaneArray, CUarray hArray, unsigned int planeIdx) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuArrayGetPlane");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUarray *, CUarray, unsigned int) = (CUresult(*)(CUarray *, CUarray, unsigned int))dlsym(cuda_handle, "cuArrayGetPlane");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pPlaneArray, hArray, planeIdx);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuArrayGetSparseProperties(CUDA_ARRAY_SPARSE_PROPERTIES *sparseProperties, CUarray array) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuArrayGetSparseProperties");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUDA_ARRAY_SPARSE_PROPERTIES *, CUarray) = (CUresult(*)(CUDA_ARRAY_SPARSE_PROPERTIES *, CUarray))dlsym(cuda_handle, "cuArrayGetSparseProperties");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(sparseProperties, array);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuCtxAttach(CUcontext *pctx, unsigned int flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuCtxAttach");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUcontext *, unsigned int) = (CUresult(*)(CUcontext *, unsigned int))dlsym(cuda_handle, "cuCtxAttach");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pctx, flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuCtxCreate(CUcontext *pctx, unsigned int flags, CUdevice dev) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuCtxCreate");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUcontext *, unsigned int, CUdevice) = (CUresult(*)(CUcontext *, unsigned int, CUdevice))dlsym(cuda_handle, "cuCtxCreate");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pctx, flags, dev);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuCtxCreate_v3(CUcontext *pctx, CUexecAffinityParam *paramsArray, int numParams, unsigned int flags, CUdevice dev) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuCtxCreate_v3");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUcontext *, CUexecAffinityParam *, int, unsigned int, CUdevice) = (CUresult(*)(CUcontext *, CUexecAffinityParam *, int, unsigned int, CUdevice))dlsym(cuda_handle, "cuCtxCreate_v3");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pctx, paramsArray, numParams, flags, dev);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuCtxDestroy(CUcontext ctx) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuCtxDestroy");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUcontext) = (CUresult(*)(CUcontext))dlsym(cuda_handle, "cuCtxDestroy");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(ctx);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuCtxDetach(CUcontext ctx) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuCtxDetach");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUcontext) = (CUresult(*)(CUcontext))dlsym(cuda_handle, "cuCtxDetach");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(ctx);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuCtxDisablePeerAccess(CUcontext peerContext) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuCtxDisablePeerAccess");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUcontext) = (CUresult(*)(CUcontext))dlsym(cuda_handle, "cuCtxDisablePeerAccess");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(peerContext);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuCtxEnablePeerAccess(CUcontext peerContext, unsigned int Flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuCtxEnablePeerAccess");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUcontext, unsigned int) = (CUresult(*)(CUcontext, unsigned int))dlsym(cuda_handle, "cuCtxEnablePeerAccess");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(peerContext, Flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuCtxGetApiVersion(CUcontext ctx, unsigned int *version) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuCtxGetApiVersion");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUcontext, unsigned int *) = (CUresult(*)(CUcontext, unsigned int *))dlsym(cuda_handle, "cuCtxGetApiVersion");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(ctx, version);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuCtxGetCacheConfig(CUfunc_cache *pconfig) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuCtxGetCacheConfig");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUfunc_cache *) = (CUresult(*)(CUfunc_cache *))dlsym(cuda_handle, "cuCtxGetCacheConfig");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pconfig);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuCtxGetCurrent(CUcontext *pctx) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuCtxGetCurrent");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUcontext *) = (CUresult(*)(CUcontext *))dlsym(cuda_handle, "cuCtxGetCurrent");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pctx);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuCtxGetDevice(CUdevice *device) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuCtxGetDevice");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdevice *) = (CUresult(*)(CUdevice *))dlsym(cuda_handle, "cuCtxGetDevice");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(device);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuCtxGetExecAffinity(CUexecAffinityParam *pExecAffinity, CUexecAffinityType type) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuCtxGetExecAffinity");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUexecAffinityParam *, CUexecAffinityType) = (CUresult(*)(CUexecAffinityParam *, CUexecAffinityType))dlsym(cuda_handle, "cuCtxGetExecAffinity");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pExecAffinity, type);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuCtxGetFlags(unsigned int *flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuCtxGetFlags");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(unsigned int *) = (CUresult(*)(unsigned int *))dlsym(cuda_handle, "cuCtxGetFlags");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuCtxGetLimit(size_t *pvalue, CUlimit limit) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuCtxGetLimit");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(size_t *, CUlimit) = (CUresult(*)(size_t *, CUlimit))dlsym(cuda_handle, "cuCtxGetLimit");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pvalue, limit);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuCtxGetSharedMemConfig(CUsharedconfig *pConfig) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuCtxGetSharedMemConfig");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUsharedconfig *) = (CUresult(*)(CUsharedconfig *))dlsym(cuda_handle, "cuCtxGetSharedMemConfig");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pConfig);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuCtxGetStreamPriorityRange(int *leastPriority, int *greatestPriority) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuCtxGetStreamPriorityRange");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(int *, int *) = (CUresult(*)(int *, int *))dlsym(cuda_handle, "cuCtxGetStreamPriorityRange");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(leastPriority, greatestPriority);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuCtxPopCurrent(CUcontext *pctx) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuCtxPopCurrent");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUcontext *) = (CUresult(*)(CUcontext *))dlsym(cuda_handle, "cuCtxPopCurrent");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pctx);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuCtxPushCurrent(CUcontext ctx) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuCtxPushCurrent");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUcontext) = (CUresult(*)(CUcontext))dlsym(cuda_handle, "cuCtxPushCurrent");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(ctx);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuCtxResetPersistingL2Cache() {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuCtxResetPersistingL2Cache");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)() = (CUresult(*)())dlsym(cuda_handle, "cuCtxResetPersistingL2Cache");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc();
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuCtxSetCacheConfig(CUfunc_cache config) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuCtxSetCacheConfig");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUfunc_cache) = (CUresult(*)(CUfunc_cache))dlsym(cuda_handle, "cuCtxSetCacheConfig");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(config);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuCtxSetCurrent(CUcontext ctx) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuCtxSetCurrent");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUcontext) = (CUresult(*)(CUcontext))dlsym(cuda_handle, "cuCtxSetCurrent");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(ctx);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuCtxSetLimit(CUlimit limit, size_t value) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuCtxSetLimit");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUlimit, size_t) = (CUresult(*)(CUlimit, size_t))dlsym(cuda_handle, "cuCtxSetLimit");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(limit, value);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuCtxSetSharedMemConfig(CUsharedconfig config) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuCtxSetSharedMemConfig");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUsharedconfig) = (CUresult(*)(CUsharedconfig))dlsym(cuda_handle, "cuCtxSetSharedMemConfig");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(config);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuCtxSynchronize() {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuCtxSynchronize");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)() = (CUresult(*)())dlsym(cuda_handle, "cuCtxSynchronize");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc();
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuDestroyExternalMemory(CUexternalMemory extMem) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuDestroyExternalMemory");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUexternalMemory) = (CUresult(*)(CUexternalMemory))dlsym(cuda_handle, "cuDestroyExternalMemory");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(extMem);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuDestroyExternalSemaphore(CUexternalSemaphore extSem) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuDestroyExternalSemaphore");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUexternalSemaphore) = (CUresult(*)(CUexternalSemaphore))dlsym(cuda_handle, "cuDestroyExternalSemaphore");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(extSem);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuDeviceCanAccessPeer(int *canAccessPeer, CUdevice dev, CUdevice peerDev) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuDeviceCanAccessPeer");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(int *, CUdevice, CUdevice) = (CUresult(*)(int *, CUdevice, CUdevice))dlsym(cuda_handle, "cuDeviceCanAccessPeer");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(canAccessPeer, dev, peerDev);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuDeviceComputeCapability(int *major, int *minor, CUdevice dev) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuDeviceComputeCapability");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(int *, int *, CUdevice) = (CUresult(*)(int *, int *, CUdevice))dlsym(cuda_handle, "cuDeviceComputeCapability");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(major, minor, dev);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuDeviceGet(CUdevice *device, int ordinal) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuDeviceGet");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdevice *, int) = (CUresult(*)(CUdevice *, int))dlsym(cuda_handle, "cuDeviceGet");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(device, ordinal);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuDeviceGetAttribute(int *pi, CUdevice_attribute attrib, CUdevice dev) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuDeviceGetAttribute");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(int *, CUdevice_attribute, CUdevice) = (CUresult(*)(int *, CUdevice_attribute, CUdevice))dlsym(cuda_handle, "cuDeviceGetAttribute");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pi, attrib, dev);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuDeviceGetByPCIBusId(CUdevice *dev, const char *pciBusId) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuDeviceGetByPCIBusId");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdevice *, const char *) = (CUresult(*)(CUdevice *, const char *))dlsym(cuda_handle, "cuDeviceGetByPCIBusId");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dev, pciBusId);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuDeviceGetCount(int *count) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuDeviceGetCount");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(int *) = (CUresult(*)(int *))dlsym(cuda_handle, "cuDeviceGetCount");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(count);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuDeviceGetDefaultMemPool(CUmemoryPool *pool_out, CUdevice dev) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuDeviceGetDefaultMemPool");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUmemoryPool *, CUdevice) = (CUresult(*)(CUmemoryPool *, CUdevice))dlsym(cuda_handle, "cuDeviceGetDefaultMemPool");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pool_out, dev);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuDeviceGetExecAffinitySupport(int *pi, CUexecAffinityType type, CUdevice dev) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuDeviceGetExecAffinitySupport");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(int *, CUexecAffinityType, CUdevice) = (CUresult(*)(int *, CUexecAffinityType, CUdevice))dlsym(cuda_handle, "cuDeviceGetExecAffinitySupport");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pi, type, dev);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuDeviceGetGraphMemAttribute(CUdevice device, CUgraphMem_attribute attr, void *value) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuDeviceGetGraphMemAttribute");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdevice, CUgraphMem_attribute, void *) = (CUresult(*)(CUdevice, CUgraphMem_attribute, void *))dlsym(cuda_handle, "cuDeviceGetGraphMemAttribute");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(device, attr, value);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuDeviceGetLuid(char *luid, unsigned int *deviceNodeMask, CUdevice dev) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuDeviceGetLuid");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(char *, unsigned int *, CUdevice) = (CUresult(*)(char *, unsigned int *, CUdevice))dlsym(cuda_handle, "cuDeviceGetLuid");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(luid, deviceNodeMask, dev);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuDeviceGetMemPool(CUmemoryPool *pool, CUdevice dev) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuDeviceGetMemPool");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUmemoryPool *, CUdevice) = (CUresult(*)(CUmemoryPool *, CUdevice))dlsym(cuda_handle, "cuDeviceGetMemPool");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pool, dev);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuDeviceGetName(char *name, int len, CUdevice dev) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuDeviceGetName");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(char *, int, CUdevice) = (CUresult(*)(char *, int, CUdevice))dlsym(cuda_handle, "cuDeviceGetName");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(name, len, dev);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuDeviceGetNvSciSyncAttributes(void *nvSciSyncAttrList, CUdevice dev, int flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuDeviceGetNvSciSyncAttributes");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(void *, CUdevice, int) = (CUresult(*)(void *, CUdevice, int))dlsym(cuda_handle, "cuDeviceGetNvSciSyncAttributes");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(nvSciSyncAttrList, dev, flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuDeviceGetP2PAttribute(int *value, CUdevice_P2PAttribute attrib, CUdevice srcDevice, CUdevice dstDevice) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuDeviceGetP2PAttribute");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(int *, CUdevice_P2PAttribute, CUdevice, CUdevice) = (CUresult(*)(int *, CUdevice_P2PAttribute, CUdevice, CUdevice))dlsym(cuda_handle, "cuDeviceGetP2PAttribute");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(value, attrib, srcDevice, dstDevice);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuDeviceGetPCIBusId(char *pciBusId, int len, CUdevice dev) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuDeviceGetPCIBusId");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(char *, int, CUdevice) = (CUresult(*)(char *, int, CUdevice))dlsym(cuda_handle, "cuDeviceGetPCIBusId");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pciBusId, len, dev);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuDeviceGetProperties(CUdevprop *prop, CUdevice dev) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuDeviceGetProperties");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdevprop *, CUdevice) = (CUresult(*)(CUdevprop *, CUdevice))dlsym(cuda_handle, "cuDeviceGetProperties");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(prop, dev);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuDeviceGetTexture1DLinearMaxWidth(size_t *maxWidthInElements, CUarray_format format, unsigned numChannels, CUdevice dev) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuDeviceGetTexture1DLinearMaxWidth");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(size_t *, CUarray_format, unsigned, CUdevice) = (CUresult(*)(size_t *, CUarray_format, unsigned, CUdevice))dlsym(cuda_handle, "cuDeviceGetTexture1DLinearMaxWidth");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(maxWidthInElements, format, numChannels, dev);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuDeviceGetUuid(CUuuid *uuid, CUdevice dev) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuDeviceGetUuid");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUuuid *, CUdevice) = (CUresult(*)(CUuuid *, CUdevice))dlsym(cuda_handle, "cuDeviceGetUuid");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(uuid, dev);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuDeviceGetUuid_v2(CUuuid *uuid, CUdevice dev) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuDeviceGetUuid_v2");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUuuid *, CUdevice) = (CUresult(*)(CUuuid *, CUdevice))dlsym(cuda_handle, "cuDeviceGetUuid_v2");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(uuid, dev);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuDeviceGraphMemTrim(CUdevice device) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuDeviceGraphMemTrim");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdevice) = (CUresult(*)(CUdevice))dlsym(cuda_handle, "cuDeviceGraphMemTrim");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(device);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuDevicePrimaryCtxGetState(CUdevice dev, unsigned int *flags, int *active) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuDevicePrimaryCtxGetState");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdevice, unsigned int *, int *) = (CUresult(*)(CUdevice, unsigned int *, int *))dlsym(cuda_handle, "cuDevicePrimaryCtxGetState");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dev, flags, active);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuDevicePrimaryCtxRelease(CUdevice dev) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuDevicePrimaryCtxRelease");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdevice) = (CUresult(*)(CUdevice))dlsym(cuda_handle, "cuDevicePrimaryCtxRelease");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dev);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuDevicePrimaryCtxReset(CUdevice dev) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuDevicePrimaryCtxReset");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdevice) = (CUresult(*)(CUdevice))dlsym(cuda_handle, "cuDevicePrimaryCtxReset");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dev);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuDevicePrimaryCtxRetain(CUcontext *pctx, CUdevice dev) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuDevicePrimaryCtxRetain");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUcontext *, CUdevice) = (CUresult(*)(CUcontext *, CUdevice))dlsym(cuda_handle, "cuDevicePrimaryCtxRetain");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pctx, dev);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuDevicePrimaryCtxSetFlags(CUdevice dev, unsigned int flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuDevicePrimaryCtxSetFlags");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdevice, unsigned int) = (CUresult(*)(CUdevice, unsigned int))dlsym(cuda_handle, "cuDevicePrimaryCtxSetFlags");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dev, flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuDeviceSetGraphMemAttribute(CUdevice device, CUgraphMem_attribute attr, void *value) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuDeviceSetGraphMemAttribute");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdevice, CUgraphMem_attribute, void *) = (CUresult(*)(CUdevice, CUgraphMem_attribute, void *))dlsym(cuda_handle, "cuDeviceSetGraphMemAttribute");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(device, attr, value);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuDeviceSetMemPool(CUdevice dev, CUmemoryPool pool) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuDeviceSetMemPool");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdevice, CUmemoryPool) = (CUresult(*)(CUdevice, CUmemoryPool))dlsym(cuda_handle, "cuDeviceSetMemPool");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dev, pool);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuEventCreate(CUevent *phEvent, unsigned int Flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuEventCreate");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUevent *, unsigned int) = (CUresult(*)(CUevent *, unsigned int))dlsym(cuda_handle, "cuEventCreate");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(phEvent, Flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuEventDestroy(CUevent hEvent) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuEventDestroy");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUevent) = (CUresult(*)(CUevent))dlsym(cuda_handle, "cuEventDestroy");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hEvent);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuEventElapsedTime(float *pMilliseconds, CUevent hStart, CUevent hEnd) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuEventElapsedTime");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(float *, CUevent, CUevent) = (CUresult(*)(float *, CUevent, CUevent))dlsym(cuda_handle, "cuEventElapsedTime");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pMilliseconds, hStart, hEnd);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuEventQuery(CUevent hEvent) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuEventQuery");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUevent) = (CUresult(*)(CUevent))dlsym(cuda_handle, "cuEventQuery");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hEvent);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuEventRecord(CUevent hEvent, CUstream hStream) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuEventRecord");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUevent, CUstream) = (CUresult(*)(CUevent, CUstream))dlsym(cuda_handle, "cuEventRecord");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hEvent, hStream);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuEventRecordWithFlags(CUevent hEvent, CUstream hStream, unsigned int flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuEventRecordWithFlags");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUevent, CUstream, unsigned int) = (CUresult(*)(CUevent, CUstream, unsigned int))dlsym(cuda_handle, "cuEventRecordWithFlags");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hEvent, hStream, flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuEventSynchronize(CUevent hEvent) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuEventSynchronize");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUevent) = (CUresult(*)(CUevent))dlsym(cuda_handle, "cuEventSynchronize");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hEvent);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuExternalMemoryGetMappedBuffer(CUdeviceptr *devPtr, CUexternalMemory extMem, const CUDA_EXTERNAL_MEMORY_BUFFER_DESC *bufferDesc) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuExternalMemoryGetMappedBuffer");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr *, CUexternalMemory, const CUDA_EXTERNAL_MEMORY_BUFFER_DESC *) = (CUresult(*)(CUdeviceptr *, CUexternalMemory, const CUDA_EXTERNAL_MEMORY_BUFFER_DESC *))dlsym(cuda_handle, "cuExternalMemoryGetMappedBuffer");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(devPtr, extMem, bufferDesc);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuExternalMemoryGetMappedMipmappedArray(CUmipmappedArray *mipmap, CUexternalMemory extMem, const CUDA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC *mipmapDesc) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuExternalMemoryGetMappedMipmappedArray");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUmipmappedArray *, CUexternalMemory, const CUDA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC *) = (CUresult(*)(CUmipmappedArray *, CUexternalMemory, const CUDA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC *))dlsym(cuda_handle, "cuExternalMemoryGetMappedMipmappedArray");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(mipmap, extMem, mipmapDesc);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuFlushGPUDirectRDMAWrites(CUflushGPUDirectRDMAWritesTarget target, CUflushGPUDirectRDMAWritesScope scope) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuFlushGPUDirectRDMAWrites");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUflushGPUDirectRDMAWritesTarget, CUflushGPUDirectRDMAWritesScope) = (CUresult(*)(CUflushGPUDirectRDMAWritesTarget, CUflushGPUDirectRDMAWritesScope))dlsym(cuda_handle, "cuFlushGPUDirectRDMAWrites");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(target, scope);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuFuncGetAttribute(int *pi, CUfunction_attribute attrib, CUfunction hfunc) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuFuncGetAttribute");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(int *, CUfunction_attribute, CUfunction) = (CUresult(*)(int *, CUfunction_attribute, CUfunction))dlsym(cuda_handle, "cuFuncGetAttribute");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pi, attrib, hfunc);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuFuncGetModule(CUmodule *hmod, CUfunction hfunc) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuFuncGetModule");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUmodule *, CUfunction) = (CUresult(*)(CUmodule *, CUfunction))dlsym(cuda_handle, "cuFuncGetModule");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hmod, hfunc);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuFuncSetAttribute(CUfunction hfunc, CUfunction_attribute attrib, int value) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuFuncSetAttribute");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUfunction, CUfunction_attribute, int) = (CUresult(*)(CUfunction, CUfunction_attribute, int))dlsym(cuda_handle, "cuFuncSetAttribute");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hfunc, attrib, value);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuFuncSetCacheConfig(CUfunction hfunc, CUfunc_cache config) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuFuncSetCacheConfig");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUfunction, CUfunc_cache) = (CUresult(*)(CUfunction, CUfunc_cache))dlsym(cuda_handle, "cuFuncSetCacheConfig");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hfunc, config);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuFuncSetSharedMemConfig(CUfunction hfunc, CUsharedconfig config) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuFuncSetSharedMemConfig");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUfunction, CUsharedconfig) = (CUresult(*)(CUfunction, CUsharedconfig))dlsym(cuda_handle, "cuFuncSetSharedMemConfig");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hfunc, config);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuFuncSetSharedSize(CUfunction hfunc, unsigned int bytes) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuFuncSetSharedSize");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUfunction, unsigned int) = (CUresult(*)(CUfunction, unsigned int))dlsym(cuda_handle, "cuFuncSetSharedSize");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hfunc, bytes);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGetErrorName(CUresult error, const char **pStr) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGetErrorName");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUresult, const char **) = (CUresult(*)(CUresult, const char **))dlsym(cuda_handle, "cuGetErrorName");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(error, pStr);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGetErrorString(CUresult error, const char **pStr) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGetErrorString");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUresult, const char **) = (CUresult(*)(CUresult, const char **))dlsym(cuda_handle, "cuGetErrorString");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(error, pStr);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGetExportTable(const void **ppExportTable, const CUuuid *pExportTableId) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGetExportTable");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(const void **, const CUuuid *) = (CUresult(*)(const void **, const CUuuid *))dlsym(cuda_handle, "cuGetExportTable");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(ppExportTable, pExportTableId);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphAddBatchMemOpNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, const CUDA_BATCH_MEM_OP_NODE_PARAMS *nodeParams) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphAddBatchMemOpNode");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode *, CUgraph, const CUgraphNode *, size_t, const CUDA_BATCH_MEM_OP_NODE_PARAMS *) = (CUresult(*)(CUgraphNode *, CUgraph, const CUgraphNode *, size_t, const CUDA_BATCH_MEM_OP_NODE_PARAMS *))dlsym(cuda_handle, "cuGraphAddBatchMemOpNode");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(phGraphNode, hGraph, dependencies, numDependencies, nodeParams);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphAddChildGraphNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, CUgraph childGraph) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphAddChildGraphNode");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode *, CUgraph, const CUgraphNode *, size_t, CUgraph) = (CUresult(*)(CUgraphNode *, CUgraph, const CUgraphNode *, size_t, CUgraph))dlsym(cuda_handle, "cuGraphAddChildGraphNode");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(phGraphNode, hGraph, dependencies, numDependencies, childGraph);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphAddDependencies(CUgraph hGraph, const CUgraphNode *from, const CUgraphNode *to, size_t numDependencies) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphAddDependencies");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraph, const CUgraphNode *, const CUgraphNode *, size_t) = (CUresult(*)(CUgraph, const CUgraphNode *, const CUgraphNode *, size_t))dlsym(cuda_handle, "cuGraphAddDependencies");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hGraph, from, to, numDependencies);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphAddEmptyNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphAddEmptyNode");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode *, CUgraph, const CUgraphNode *, size_t) = (CUresult(*)(CUgraphNode *, CUgraph, const CUgraphNode *, size_t))dlsym(cuda_handle, "cuGraphAddEmptyNode");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(phGraphNode, hGraph, dependencies, numDependencies);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphAddEventRecordNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, CUevent event) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphAddEventRecordNode");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode *, CUgraph, const CUgraphNode *, size_t, CUevent) = (CUresult(*)(CUgraphNode *, CUgraph, const CUgraphNode *, size_t, CUevent))dlsym(cuda_handle, "cuGraphAddEventRecordNode");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(phGraphNode, hGraph, dependencies, numDependencies, event);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphAddEventWaitNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, CUevent event) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphAddEventWaitNode");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode *, CUgraph, const CUgraphNode *, size_t, CUevent) = (CUresult(*)(CUgraphNode *, CUgraph, const CUgraphNode *, size_t, CUevent))dlsym(cuda_handle, "cuGraphAddEventWaitNode");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(phGraphNode, hGraph, dependencies, numDependencies, event);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphAddExternalSemaphoresSignalNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, const CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *nodeParams) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphAddExternalSemaphoresSignalNode");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode *, CUgraph, const CUgraphNode *, size_t, const CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *) = (CUresult(*)(CUgraphNode *, CUgraph, const CUgraphNode *, size_t, const CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *))dlsym(cuda_handle, "cuGraphAddExternalSemaphoresSignalNode");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(phGraphNode, hGraph, dependencies, numDependencies, nodeParams);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphAddExternalSemaphoresWaitNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, const CUDA_EXT_SEM_WAIT_NODE_PARAMS *nodeParams) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphAddExternalSemaphoresWaitNode");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode *, CUgraph, const CUgraphNode *, size_t, const CUDA_EXT_SEM_WAIT_NODE_PARAMS *) = (CUresult(*)(CUgraphNode *, CUgraph, const CUgraphNode *, size_t, const CUDA_EXT_SEM_WAIT_NODE_PARAMS *))dlsym(cuda_handle, "cuGraphAddExternalSemaphoresWaitNode");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(phGraphNode, hGraph, dependencies, numDependencies, nodeParams);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphAddHostNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, const CUDA_HOST_NODE_PARAMS *nodeParams) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphAddHostNode");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode *, CUgraph, const CUgraphNode *, size_t, const CUDA_HOST_NODE_PARAMS *) = (CUresult(*)(CUgraphNode *, CUgraph, const CUgraphNode *, size_t, const CUDA_HOST_NODE_PARAMS *))dlsym(cuda_handle, "cuGraphAddHostNode");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(phGraphNode, hGraph, dependencies, numDependencies, nodeParams);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphAddKernelNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, const CUDA_KERNEL_NODE_PARAMS *nodeParams) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphAddKernelNode");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode *, CUgraph, const CUgraphNode *, size_t, const CUDA_KERNEL_NODE_PARAMS *) = (CUresult(*)(CUgraphNode *, CUgraph, const CUgraphNode *, size_t, const CUDA_KERNEL_NODE_PARAMS *))dlsym(cuda_handle, "cuGraphAddKernelNode");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(phGraphNode, hGraph, dependencies, numDependencies, nodeParams);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphAddMemAllocNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, CUDA_MEM_ALLOC_NODE_PARAMS *nodeParams) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphAddMemAllocNode");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode *, CUgraph, const CUgraphNode *, size_t, CUDA_MEM_ALLOC_NODE_PARAMS *) = (CUresult(*)(CUgraphNode *, CUgraph, const CUgraphNode *, size_t, CUDA_MEM_ALLOC_NODE_PARAMS *))dlsym(cuda_handle, "cuGraphAddMemAllocNode");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(phGraphNode, hGraph, dependencies, numDependencies, nodeParams);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphAddMemFreeNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, CUdeviceptr dptr) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphAddMemFreeNode");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode *, CUgraph, const CUgraphNode *, size_t, CUdeviceptr) = (CUresult(*)(CUgraphNode *, CUgraph, const CUgraphNode *, size_t, CUdeviceptr))dlsym(cuda_handle, "cuGraphAddMemFreeNode");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(phGraphNode, hGraph, dependencies, numDependencies, dptr);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphAddMemcpyNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, const CUDA_MEMCPY3D *copyParams, CUcontext ctx) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphAddMemcpyNode");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode *, CUgraph, const CUgraphNode *, size_t, const CUDA_MEMCPY3D *, CUcontext) = (CUresult(*)(CUgraphNode *, CUgraph, const CUgraphNode *, size_t, const CUDA_MEMCPY3D *, CUcontext))dlsym(cuda_handle, "cuGraphAddMemcpyNode");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(phGraphNode, hGraph, dependencies, numDependencies, copyParams, ctx);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphAddMemsetNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, const CUDA_MEMSET_NODE_PARAMS *memsetParams, CUcontext ctx) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphAddMemsetNode");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode *, CUgraph, const CUgraphNode *, size_t, const CUDA_MEMSET_NODE_PARAMS *, CUcontext) = (CUresult(*)(CUgraphNode *, CUgraph, const CUgraphNode *, size_t, const CUDA_MEMSET_NODE_PARAMS *, CUcontext))dlsym(cuda_handle, "cuGraphAddMemsetNode");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(phGraphNode, hGraph, dependencies, numDependencies, memsetParams, ctx);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphBatchMemOpNodeGetParams(CUgraphNode hNode, CUDA_BATCH_MEM_OP_NODE_PARAMS *nodeParams_out) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphBatchMemOpNodeGetParams");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode, CUDA_BATCH_MEM_OP_NODE_PARAMS *) = (CUresult(*)(CUgraphNode, CUDA_BATCH_MEM_OP_NODE_PARAMS *))dlsym(cuda_handle, "cuGraphBatchMemOpNodeGetParams");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hNode, nodeParams_out);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphBatchMemOpNodeSetParams(CUgraphNode hNode, const CUDA_BATCH_MEM_OP_NODE_PARAMS *nodeParams) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphBatchMemOpNodeSetParams");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode, const CUDA_BATCH_MEM_OP_NODE_PARAMS *) = (CUresult(*)(CUgraphNode, const CUDA_BATCH_MEM_OP_NODE_PARAMS *))dlsym(cuda_handle, "cuGraphBatchMemOpNodeSetParams");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hNode, nodeParams);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphChildGraphNodeGetGraph(CUgraphNode hNode, CUgraph *phGraph) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphChildGraphNodeGetGraph");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode, CUgraph *) = (CUresult(*)(CUgraphNode, CUgraph *))dlsym(cuda_handle, "cuGraphChildGraphNodeGetGraph");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hNode, phGraph);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphClone(CUgraph *phGraphClone, CUgraph originalGraph) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphClone");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraph *, CUgraph) = (CUresult(*)(CUgraph *, CUgraph))dlsym(cuda_handle, "cuGraphClone");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(phGraphClone, originalGraph);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphCreate(CUgraph *phGraph, unsigned int flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphCreate");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraph *, unsigned int) = (CUresult(*)(CUgraph *, unsigned int))dlsym(cuda_handle, "cuGraphCreate");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(phGraph, flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphDebugDotPrint(CUgraph hGraph, const char *path, unsigned int flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphDebugDotPrint");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraph, const char *, unsigned int) = (CUresult(*)(CUgraph, const char *, unsigned int))dlsym(cuda_handle, "cuGraphDebugDotPrint");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hGraph, path, flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphDestroy(CUgraph hGraph) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphDestroy");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraph) = (CUresult(*)(CUgraph))dlsym(cuda_handle, "cuGraphDestroy");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hGraph);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphDestroyNode(CUgraphNode hNode) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphDestroyNode");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode) = (CUresult(*)(CUgraphNode))dlsym(cuda_handle, "cuGraphDestroyNode");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hNode);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphEventRecordNodeGetEvent(CUgraphNode hNode, CUevent *event_out) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphEventRecordNodeGetEvent");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode, CUevent *) = (CUresult(*)(CUgraphNode, CUevent *))dlsym(cuda_handle, "cuGraphEventRecordNodeGetEvent");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hNode, event_out);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphEventRecordNodeSetEvent(CUgraphNode hNode, CUevent event) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphEventRecordNodeSetEvent");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode, CUevent) = (CUresult(*)(CUgraphNode, CUevent))dlsym(cuda_handle, "cuGraphEventRecordNodeSetEvent");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hNode, event);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphEventWaitNodeGetEvent(CUgraphNode hNode, CUevent *event_out) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphEventWaitNodeGetEvent");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode, CUevent *) = (CUresult(*)(CUgraphNode, CUevent *))dlsym(cuda_handle, "cuGraphEventWaitNodeGetEvent");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hNode, event_out);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphEventWaitNodeSetEvent(CUgraphNode hNode, CUevent event) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphEventWaitNodeSetEvent");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode, CUevent) = (CUresult(*)(CUgraphNode, CUevent))dlsym(cuda_handle, "cuGraphEventWaitNodeSetEvent");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hNode, event);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphExecBatchMemOpNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, const CUDA_BATCH_MEM_OP_NODE_PARAMS *nodeParams) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphExecBatchMemOpNodeSetParams");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphExec, CUgraphNode, const CUDA_BATCH_MEM_OP_NODE_PARAMS *) = (CUresult(*)(CUgraphExec, CUgraphNode, const CUDA_BATCH_MEM_OP_NODE_PARAMS *))dlsym(cuda_handle, "cuGraphExecBatchMemOpNodeSetParams");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hGraphExec, hNode, nodeParams);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphExecChildGraphNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, CUgraph childGraph) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphExecChildGraphNodeSetParams");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphExec, CUgraphNode, CUgraph) = (CUresult(*)(CUgraphExec, CUgraphNode, CUgraph))dlsym(cuda_handle, "cuGraphExecChildGraphNodeSetParams");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hGraphExec, hNode, childGraph);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphExecDestroy(CUgraphExec hGraphExec) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphExecDestroy");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphExec) = (CUresult(*)(CUgraphExec))dlsym(cuda_handle, "cuGraphExecDestroy");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hGraphExec);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphExecEventRecordNodeSetEvent(CUgraphExec hGraphExec, CUgraphNode hNode, CUevent event) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphExecEventRecordNodeSetEvent");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphExec, CUgraphNode, CUevent) = (CUresult(*)(CUgraphExec, CUgraphNode, CUevent))dlsym(cuda_handle, "cuGraphExecEventRecordNodeSetEvent");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hGraphExec, hNode, event);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphExecEventWaitNodeSetEvent(CUgraphExec hGraphExec, CUgraphNode hNode, CUevent event) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphExecEventWaitNodeSetEvent");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphExec, CUgraphNode, CUevent) = (CUresult(*)(CUgraphExec, CUgraphNode, CUevent))dlsym(cuda_handle, "cuGraphExecEventWaitNodeSetEvent");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hGraphExec, hNode, event);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphExecExternalSemaphoresSignalNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, const CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *nodeParams) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphExecExternalSemaphoresSignalNodeSetParams");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphExec, CUgraphNode, const CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *) = (CUresult(*)(CUgraphExec, CUgraphNode, const CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *))dlsym(cuda_handle, "cuGraphExecExternalSemaphoresSignalNodeSetParams");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hGraphExec, hNode, nodeParams);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphExecExternalSemaphoresWaitNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, const CUDA_EXT_SEM_WAIT_NODE_PARAMS *nodeParams) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphExecExternalSemaphoresWaitNodeSetParams");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphExec, CUgraphNode, const CUDA_EXT_SEM_WAIT_NODE_PARAMS *) = (CUresult(*)(CUgraphExec, CUgraphNode, const CUDA_EXT_SEM_WAIT_NODE_PARAMS *))dlsym(cuda_handle, "cuGraphExecExternalSemaphoresWaitNodeSetParams");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hGraphExec, hNode, nodeParams);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphExecHostNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, const CUDA_HOST_NODE_PARAMS *nodeParams) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphExecHostNodeSetParams");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphExec, CUgraphNode, const CUDA_HOST_NODE_PARAMS *) = (CUresult(*)(CUgraphExec, CUgraphNode, const CUDA_HOST_NODE_PARAMS *))dlsym(cuda_handle, "cuGraphExecHostNodeSetParams");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hGraphExec, hNode, nodeParams);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphExecKernelNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, const CUDA_KERNEL_NODE_PARAMS *nodeParams) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphExecKernelNodeSetParams");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphExec, CUgraphNode, const CUDA_KERNEL_NODE_PARAMS *) = (CUresult(*)(CUgraphExec, CUgraphNode, const CUDA_KERNEL_NODE_PARAMS *))dlsym(cuda_handle, "cuGraphExecKernelNodeSetParams");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hGraphExec, hNode, nodeParams);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphExecMemcpyNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, const CUDA_MEMCPY3D *copyParams, CUcontext ctx) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphExecMemcpyNodeSetParams");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphExec, CUgraphNode, const CUDA_MEMCPY3D *, CUcontext) = (CUresult(*)(CUgraphExec, CUgraphNode, const CUDA_MEMCPY3D *, CUcontext))dlsym(cuda_handle, "cuGraphExecMemcpyNodeSetParams");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hGraphExec, hNode, copyParams, ctx);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphExecMemsetNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, const CUDA_MEMSET_NODE_PARAMS *memsetParams, CUcontext ctx) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphExecMemsetNodeSetParams");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphExec, CUgraphNode, const CUDA_MEMSET_NODE_PARAMS *, CUcontext) = (CUresult(*)(CUgraphExec, CUgraphNode, const CUDA_MEMSET_NODE_PARAMS *, CUcontext))dlsym(cuda_handle, "cuGraphExecMemsetNodeSetParams");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hGraphExec, hNode, memsetParams, ctx);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphExecUpdate(CUgraphExec hGraphExec, CUgraph hGraph, CUgraphNode *hErrorNode_out, CUgraphExecUpdateResult *updateResult_out) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphExecUpdate");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphExec, CUgraph, CUgraphNode *, CUgraphExecUpdateResult *) = (CUresult(*)(CUgraphExec, CUgraph, CUgraphNode *, CUgraphExecUpdateResult *))dlsym(cuda_handle, "cuGraphExecUpdate");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hGraphExec, hGraph, hErrorNode_out, updateResult_out);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphExternalSemaphoresSignalNodeGetParams(CUgraphNode hNode, CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *params_out) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphExternalSemaphoresSignalNodeGetParams");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode, CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *) = (CUresult(*)(CUgraphNode, CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *))dlsym(cuda_handle, "cuGraphExternalSemaphoresSignalNodeGetParams");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hNode, params_out);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphExternalSemaphoresSignalNodeSetParams(CUgraphNode hNode, const CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *nodeParams) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphExternalSemaphoresSignalNodeSetParams");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode, const CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *) = (CUresult(*)(CUgraphNode, const CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *))dlsym(cuda_handle, "cuGraphExternalSemaphoresSignalNodeSetParams");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hNode, nodeParams);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphExternalSemaphoresWaitNodeGetParams(CUgraphNode hNode, CUDA_EXT_SEM_WAIT_NODE_PARAMS *params_out) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphExternalSemaphoresWaitNodeGetParams");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode, CUDA_EXT_SEM_WAIT_NODE_PARAMS *) = (CUresult(*)(CUgraphNode, CUDA_EXT_SEM_WAIT_NODE_PARAMS *))dlsym(cuda_handle, "cuGraphExternalSemaphoresWaitNodeGetParams");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hNode, params_out);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphExternalSemaphoresWaitNodeSetParams(CUgraphNode hNode, const CUDA_EXT_SEM_WAIT_NODE_PARAMS *nodeParams) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphExternalSemaphoresWaitNodeSetParams");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode, const CUDA_EXT_SEM_WAIT_NODE_PARAMS *) = (CUresult(*)(CUgraphNode, const CUDA_EXT_SEM_WAIT_NODE_PARAMS *))dlsym(cuda_handle, "cuGraphExternalSemaphoresWaitNodeSetParams");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hNode, nodeParams);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphGetEdges(CUgraph hGraph, CUgraphNode *from, CUgraphNode *to, size_t *numEdges) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphGetEdges");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraph, CUgraphNode *, CUgraphNode *, size_t *) = (CUresult(*)(CUgraph, CUgraphNode *, CUgraphNode *, size_t *))dlsym(cuda_handle, "cuGraphGetEdges");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hGraph, from, to, numEdges);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphGetNodes(CUgraph hGraph, CUgraphNode *nodes, size_t *numNodes) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphGetNodes");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraph, CUgraphNode *, size_t *) = (CUresult(*)(CUgraph, CUgraphNode *, size_t *))dlsym(cuda_handle, "cuGraphGetNodes");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hGraph, nodes, numNodes);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphGetRootNodes(CUgraph hGraph, CUgraphNode *rootNodes, size_t *numRootNodes) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphGetRootNodes");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraph, CUgraphNode *, size_t *) = (CUresult(*)(CUgraph, CUgraphNode *, size_t *))dlsym(cuda_handle, "cuGraphGetRootNodes");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hGraph, rootNodes, numRootNodes);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphHostNodeGetParams(CUgraphNode hNode, CUDA_HOST_NODE_PARAMS *nodeParams) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphHostNodeGetParams");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode, CUDA_HOST_NODE_PARAMS *) = (CUresult(*)(CUgraphNode, CUDA_HOST_NODE_PARAMS *))dlsym(cuda_handle, "cuGraphHostNodeGetParams");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hNode, nodeParams);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphHostNodeSetParams(CUgraphNode hNode, const CUDA_HOST_NODE_PARAMS *nodeParams) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphHostNodeSetParams");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode, const CUDA_HOST_NODE_PARAMS *) = (CUresult(*)(CUgraphNode, const CUDA_HOST_NODE_PARAMS *))dlsym(cuda_handle, "cuGraphHostNodeSetParams");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hNode, nodeParams);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphInstantiate(CUgraphExec *phGraphExec, CUgraph hGraph, CUgraphNode *phErrorNode, char *logBuffer, size_t bufferSize) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphInstantiate");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphExec *, CUgraph, CUgraphNode *, char *, size_t) = (CUresult(*)(CUgraphExec *, CUgraph, CUgraphNode *, char *, size_t))dlsym(cuda_handle, "cuGraphInstantiate");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(phGraphExec, hGraph, phErrorNode, logBuffer, bufferSize);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphInstantiateWithFlags(CUgraphExec *phGraphExec, CUgraph hGraph, unsigned long long flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphInstantiateWithFlags");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphExec *, CUgraph, unsigned long long) = (CUresult(*)(CUgraphExec *, CUgraph, unsigned long long))dlsym(cuda_handle, "cuGraphInstantiateWithFlags");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(phGraphExec, hGraph, flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphKernelNodeCopyAttributes(CUgraphNode dst, CUgraphNode src) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphKernelNodeCopyAttributes");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode, CUgraphNode) = (CUresult(*)(CUgraphNode, CUgraphNode))dlsym(cuda_handle, "cuGraphKernelNodeCopyAttributes");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dst, src);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphKernelNodeGetAttribute(CUgraphNode hNode, CUkernelNodeAttrID attr, CUkernelNodeAttrValue *value_out) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphKernelNodeGetAttribute");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode, CUkernelNodeAttrID, CUkernelNodeAttrValue *) = (CUresult(*)(CUgraphNode, CUkernelNodeAttrID, CUkernelNodeAttrValue *))dlsym(cuda_handle, "cuGraphKernelNodeGetAttribute");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hNode, attr, value_out);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphKernelNodeGetParams(CUgraphNode hNode, CUDA_KERNEL_NODE_PARAMS *nodeParams) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphKernelNodeGetParams");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode, CUDA_KERNEL_NODE_PARAMS *) = (CUresult(*)(CUgraphNode, CUDA_KERNEL_NODE_PARAMS *))dlsym(cuda_handle, "cuGraphKernelNodeGetParams");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hNode, nodeParams);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphKernelNodeSetAttribute(CUgraphNode hNode, CUkernelNodeAttrID attr, const CUkernelNodeAttrValue *value) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphKernelNodeSetAttribute");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode, CUkernelNodeAttrID, const CUkernelNodeAttrValue *) = (CUresult(*)(CUgraphNode, CUkernelNodeAttrID, const CUkernelNodeAttrValue *))dlsym(cuda_handle, "cuGraphKernelNodeSetAttribute");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hNode, attr, value);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphKernelNodeSetParams(CUgraphNode hNode, const CUDA_KERNEL_NODE_PARAMS *nodeParams) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphKernelNodeSetParams");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode, const CUDA_KERNEL_NODE_PARAMS *) = (CUresult(*)(CUgraphNode, const CUDA_KERNEL_NODE_PARAMS *))dlsym(cuda_handle, "cuGraphKernelNodeSetParams");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hNode, nodeParams);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphLaunch(CUgraphExec hGraphExec, CUstream hStream) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphLaunch");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphExec, CUstream) = (CUresult(*)(CUgraphExec, CUstream))dlsym(cuda_handle, "cuGraphLaunch");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hGraphExec, hStream);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphMemAllocNodeGetParams(CUgraphNode hNode, CUDA_MEM_ALLOC_NODE_PARAMS *params_out) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphMemAllocNodeGetParams");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode, CUDA_MEM_ALLOC_NODE_PARAMS *) = (CUresult(*)(CUgraphNode, CUDA_MEM_ALLOC_NODE_PARAMS *))dlsym(cuda_handle, "cuGraphMemAllocNodeGetParams");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hNode, params_out);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphMemFreeNodeGetParams(CUgraphNode hNode, CUdeviceptr *dptr_out) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphMemFreeNodeGetParams");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode, CUdeviceptr *) = (CUresult(*)(CUgraphNode, CUdeviceptr *))dlsym(cuda_handle, "cuGraphMemFreeNodeGetParams");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hNode, dptr_out);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphMemcpyNodeGetParams(CUgraphNode hNode, CUDA_MEMCPY3D *nodeParams) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphMemcpyNodeGetParams");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode, CUDA_MEMCPY3D *) = (CUresult(*)(CUgraphNode, CUDA_MEMCPY3D *))dlsym(cuda_handle, "cuGraphMemcpyNodeGetParams");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hNode, nodeParams);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphMemcpyNodeSetParams(CUgraphNode hNode, const CUDA_MEMCPY3D *nodeParams) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphMemcpyNodeSetParams");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode, const CUDA_MEMCPY3D *) = (CUresult(*)(CUgraphNode, const CUDA_MEMCPY3D *))dlsym(cuda_handle, "cuGraphMemcpyNodeSetParams");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hNode, nodeParams);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphMemsetNodeGetParams(CUgraphNode hNode, CUDA_MEMSET_NODE_PARAMS *nodeParams) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphMemsetNodeGetParams");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode, CUDA_MEMSET_NODE_PARAMS *) = (CUresult(*)(CUgraphNode, CUDA_MEMSET_NODE_PARAMS *))dlsym(cuda_handle, "cuGraphMemsetNodeGetParams");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hNode, nodeParams);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphMemsetNodeSetParams(CUgraphNode hNode, const CUDA_MEMSET_NODE_PARAMS *nodeParams) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphMemsetNodeSetParams");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode, const CUDA_MEMSET_NODE_PARAMS *) = (CUresult(*)(CUgraphNode, const CUDA_MEMSET_NODE_PARAMS *))dlsym(cuda_handle, "cuGraphMemsetNodeSetParams");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hNode, nodeParams);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphNodeFindInClone(CUgraphNode *phNode, CUgraphNode hOriginalNode, CUgraph hClonedGraph) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphNodeFindInClone");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode *, CUgraphNode, CUgraph) = (CUresult(*)(CUgraphNode *, CUgraphNode, CUgraph))dlsym(cuda_handle, "cuGraphNodeFindInClone");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(phNode, hOriginalNode, hClonedGraph);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphNodeGetDependencies(CUgraphNode hNode, CUgraphNode *dependencies, size_t *numDependencies) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphNodeGetDependencies");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode, CUgraphNode *, size_t *) = (CUresult(*)(CUgraphNode, CUgraphNode *, size_t *))dlsym(cuda_handle, "cuGraphNodeGetDependencies");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hNode, dependencies, numDependencies);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphNodeGetDependentNodes(CUgraphNode hNode, CUgraphNode *dependentNodes, size_t *numDependentNodes) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphNodeGetDependentNodes");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode, CUgraphNode *, size_t *) = (CUresult(*)(CUgraphNode, CUgraphNode *, size_t *))dlsym(cuda_handle, "cuGraphNodeGetDependentNodes");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hNode, dependentNodes, numDependentNodes);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphNodeGetEnabled(CUgraphExec hGraphExec, CUgraphNode hNode, unsigned int *isEnabled) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphNodeGetEnabled");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphExec, CUgraphNode, unsigned int *) = (CUresult(*)(CUgraphExec, CUgraphNode, unsigned int *))dlsym(cuda_handle, "cuGraphNodeGetEnabled");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hGraphExec, hNode, isEnabled);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphNodeGetType(CUgraphNode hNode, CUgraphNodeType *type) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphNodeGetType");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphNode, CUgraphNodeType *) = (CUresult(*)(CUgraphNode, CUgraphNodeType *))dlsym(cuda_handle, "cuGraphNodeGetType");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hNode, type);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphNodeSetEnabled(CUgraphExec hGraphExec, CUgraphNode hNode, unsigned int isEnabled) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphNodeSetEnabled");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphExec, CUgraphNode, unsigned int) = (CUresult(*)(CUgraphExec, CUgraphNode, unsigned int))dlsym(cuda_handle, "cuGraphNodeSetEnabled");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hGraphExec, hNode, isEnabled);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphReleaseUserObject(CUgraph graph, CUuserObject object, unsigned int count) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphReleaseUserObject");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraph, CUuserObject, unsigned int) = (CUresult(*)(CUgraph, CUuserObject, unsigned int))dlsym(cuda_handle, "cuGraphReleaseUserObject");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(graph, object, count);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphRemoveDependencies(CUgraph hGraph, const CUgraphNode *from, const CUgraphNode *to, size_t numDependencies) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphRemoveDependencies");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraph, const CUgraphNode *, const CUgraphNode *, size_t) = (CUresult(*)(CUgraph, const CUgraphNode *, const CUgraphNode *, size_t))dlsym(cuda_handle, "cuGraphRemoveDependencies");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hGraph, from, to, numDependencies);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphRetainUserObject(CUgraph graph, CUuserObject object, unsigned int count, unsigned int flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphRetainUserObject");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraph, CUuserObject, unsigned int, unsigned int) = (CUresult(*)(CUgraph, CUuserObject, unsigned int, unsigned int))dlsym(cuda_handle, "cuGraphRetainUserObject");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(graph, object, count, flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphUpload(CUgraphExec hGraphExec, CUstream hStream) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphUpload");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphExec, CUstream) = (CUresult(*)(CUgraphExec, CUstream))dlsym(cuda_handle, "cuGraphUpload");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hGraphExec, hStream);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphicsMapResources(unsigned int count, CUgraphicsResource *resources, CUstream hStream) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphicsMapResources");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(unsigned int, CUgraphicsResource *, CUstream) = (CUresult(*)(unsigned int, CUgraphicsResource *, CUstream))dlsym(cuda_handle, "cuGraphicsMapResources");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(count, resources, hStream);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphicsResourceGetMappedMipmappedArray(CUmipmappedArray *pMipmappedArray, CUgraphicsResource resource) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphicsResourceGetMappedMipmappedArray");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUmipmappedArray *, CUgraphicsResource) = (CUresult(*)(CUmipmappedArray *, CUgraphicsResource))dlsym(cuda_handle, "cuGraphicsResourceGetMappedMipmappedArray");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pMipmappedArray, resource);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphicsResourceGetMappedPointer(CUdeviceptr *pDevPtr, size_t *pSize, CUgraphicsResource resource) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphicsResourceGetMappedPointer");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr *, size_t *, CUgraphicsResource) = (CUresult(*)(CUdeviceptr *, size_t *, CUgraphicsResource))dlsym(cuda_handle, "cuGraphicsResourceGetMappedPointer");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pDevPtr, pSize, resource);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphicsResourceSetMapFlags(CUgraphicsResource resource, unsigned int flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphicsResourceSetMapFlags");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphicsResource, unsigned int) = (CUresult(*)(CUgraphicsResource, unsigned int))dlsym(cuda_handle, "cuGraphicsResourceSetMapFlags");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(resource, flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphicsSubResourceGetMappedArray(CUarray *pArray, CUgraphicsResource resource, unsigned int arrayIndex, unsigned int mipLevel) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphicsSubResourceGetMappedArray");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUarray *, CUgraphicsResource, unsigned int, unsigned int) = (CUresult(*)(CUarray *, CUgraphicsResource, unsigned int, unsigned int))dlsym(cuda_handle, "cuGraphicsSubResourceGetMappedArray");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pArray, resource, arrayIndex, mipLevel);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphicsUnmapResources(unsigned int count, CUgraphicsResource *resources, CUstream hStream) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphicsUnmapResources");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(unsigned int, CUgraphicsResource *, CUstream) = (CUresult(*)(unsigned int, CUgraphicsResource *, CUstream))dlsym(cuda_handle, "cuGraphicsUnmapResources");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(count, resources, hStream);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuGraphicsUnregisterResource(CUgraphicsResource resource) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGraphicsUnregisterResource");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUgraphicsResource) = (CUresult(*)(CUgraphicsResource))dlsym(cuda_handle, "cuGraphicsUnregisterResource");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(resource);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuImportExternalMemory(CUexternalMemory *extMem_out, const CUDA_EXTERNAL_MEMORY_HANDLE_DESC *memHandleDesc) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuImportExternalMemory");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUexternalMemory *, const CUDA_EXTERNAL_MEMORY_HANDLE_DESC *) = (CUresult(*)(CUexternalMemory *, const CUDA_EXTERNAL_MEMORY_HANDLE_DESC *))dlsym(cuda_handle, "cuImportExternalMemory");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(extMem_out, memHandleDesc);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuImportExternalSemaphore(CUexternalSemaphore *extSem_out, const CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC *semHandleDesc) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuImportExternalSemaphore");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUexternalSemaphore *, const CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC *) = (CUresult(*)(CUexternalSemaphore *, const CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC *))dlsym(cuda_handle, "cuImportExternalSemaphore");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(extSem_out, semHandleDesc);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuIpcCloseMemHandle(CUdeviceptr dptr) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuIpcCloseMemHandle");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr) = (CUresult(*)(CUdeviceptr))dlsym(cuda_handle, "cuIpcCloseMemHandle");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dptr);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuIpcGetEventHandle(CUipcEventHandle *pHandle, CUevent event) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuIpcGetEventHandle");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUipcEventHandle *, CUevent) = (CUresult(*)(CUipcEventHandle *, CUevent))dlsym(cuda_handle, "cuIpcGetEventHandle");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pHandle, event);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuIpcGetMemHandle(CUipcMemHandle *pHandle, CUdeviceptr dptr) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuIpcGetMemHandle");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUipcMemHandle *, CUdeviceptr) = (CUresult(*)(CUipcMemHandle *, CUdeviceptr))dlsym(cuda_handle, "cuIpcGetMemHandle");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pHandle, dptr);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuIpcOpenEventHandle(CUevent *phEvent, CUipcEventHandle handle) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuIpcOpenEventHandle");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUevent *, CUipcEventHandle) = (CUresult(*)(CUevent *, CUipcEventHandle))dlsym(cuda_handle, "cuIpcOpenEventHandle");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(phEvent, handle);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuIpcOpenMemHandle(CUdeviceptr *pdptr, CUipcMemHandle handle, unsigned int Flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuIpcOpenMemHandle");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr *, CUipcMemHandle, unsigned int) = (CUresult(*)(CUdeviceptr *, CUipcMemHandle, unsigned int))dlsym(cuda_handle, "cuIpcOpenMemHandle");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pdptr, handle, Flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuLaunchCooperativeKernelMultiDevice(CUDA_LAUNCH_PARAMS *launchParamsList, unsigned int numDevices, unsigned int flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuLaunchCooperativeKernelMultiDevice");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUDA_LAUNCH_PARAMS *, unsigned int, unsigned int) = (CUresult(*)(CUDA_LAUNCH_PARAMS *, unsigned int, unsigned int))dlsym(cuda_handle, "cuLaunchCooperativeKernelMultiDevice");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(launchParamsList, numDevices, flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuLaunchHostFunc(CUstream hStream, CUhostFn fn, void *userData) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuLaunchHostFunc");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUstream, CUhostFn, void *) = (CUresult(*)(CUstream, CUhostFn, void *))dlsym(cuda_handle, "cuLaunchHostFunc");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hStream, fn, userData);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuLaunchKernelEx(const CUlaunchConfig *config, CUfunction f, void **kernelParams, void **extra) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuLaunchKernelEx");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(const CUlaunchConfig *, CUfunction, void **, void **) = (CUresult(*)(const CUlaunchConfig *, CUfunction, void **, void **))dlsym(cuda_handle, "cuLaunchKernelEx");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(config, f, kernelParams, extra);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuLinkAddData(CUlinkState state, CUjitInputType type, void *data, size_t size, const char *name, unsigned int numOptions, CUjit_option *options, void **optionValues) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuLinkAddData");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUlinkState, CUjitInputType, void *, size_t, const char *, unsigned int, CUjit_option *, void **) = (CUresult(*)(CUlinkState, CUjitInputType, void *, size_t, const char *, unsigned int, CUjit_option *, void **))dlsym(cuda_handle, "cuLinkAddData");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(state, type, data, size, name, numOptions, options, optionValues);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuLinkAddFile(CUlinkState state, CUjitInputType type, const char *path, unsigned int numOptions, CUjit_option *options, void **optionValues) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuLinkAddFile");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUlinkState, CUjitInputType, const char *, unsigned int, CUjit_option *, void **) = (CUresult(*)(CUlinkState, CUjitInputType, const char *, unsigned int, CUjit_option *, void **))dlsym(cuda_handle, "cuLinkAddFile");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(state, type, path, numOptions, options, optionValues);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuLinkComplete(CUlinkState state, void **cubinOut, size_t *sizeOut) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuLinkComplete");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUlinkState, void **, size_t *) = (CUresult(*)(CUlinkState, void **, size_t *))dlsym(cuda_handle, "cuLinkComplete");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(state, cubinOut, sizeOut);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuLinkCreate(unsigned int numOptions, CUjit_option *options, void **optionValues, CUlinkState *stateOut) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuLinkCreate");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(unsigned int, CUjit_option *, void **, CUlinkState *) = (CUresult(*)(unsigned int, CUjit_option *, void **, CUlinkState *))dlsym(cuda_handle, "cuLinkCreate");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(numOptions, options, optionValues, stateOut);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuLinkDestroy(CUlinkState state) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuLinkDestroy");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUlinkState) = (CUresult(*)(CUlinkState))dlsym(cuda_handle, "cuLinkDestroy");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(state);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemAddressFree(CUdeviceptr ptr, size_t size) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemAddressFree");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr, size_t) = (CUresult(*)(CUdeviceptr, size_t))dlsym(cuda_handle, "cuMemAddressFree");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(ptr, size);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemAddressReserve(CUdeviceptr *ptr, size_t size, size_t alignment, CUdeviceptr addr, unsigned long long flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemAddressReserve");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr *, size_t, size_t, CUdeviceptr, unsigned long long) = (CUresult(*)(CUdeviceptr *, size_t, size_t, CUdeviceptr, unsigned long long))dlsym(cuda_handle, "cuMemAddressReserve");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(ptr, size, alignment, addr, flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemAdvise(CUdeviceptr devPtr, size_t count, CUmem_advise advice, CUdevice device) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemAdvise");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr, size_t, CUmem_advise, CUdevice) = (CUresult(*)(CUdeviceptr, size_t, CUmem_advise, CUdevice))dlsym(cuda_handle, "cuMemAdvise");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(devPtr, count, advice, device);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemAllocAsync(CUdeviceptr *dptr, size_t bytesize, CUstream hStream) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemAllocAsync");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr *, size_t, CUstream) = (CUresult(*)(CUdeviceptr *, size_t, CUstream))dlsym(cuda_handle, "cuMemAllocAsync");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dptr, bytesize, hStream);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemAllocFromPoolAsync(CUdeviceptr *dptr, size_t bytesize, CUmemoryPool pool, CUstream hStream) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemAllocFromPoolAsync");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr *, size_t, CUmemoryPool, CUstream) = (CUresult(*)(CUdeviceptr *, size_t, CUmemoryPool, CUstream))dlsym(cuda_handle, "cuMemAllocFromPoolAsync");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dptr, bytesize, pool, hStream);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemAllocHost(void **pp, size_t bytesize) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemAllocHost");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(void **, size_t) = (CUresult(*)(void **, size_t))dlsym(cuda_handle, "cuMemAllocHost");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pp, bytesize);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemCreate(CUmemGenericAllocationHandle *handle, size_t size, const CUmemAllocationProp *prop, unsigned long long flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemCreate");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUmemGenericAllocationHandle *, size_t, const CUmemAllocationProp *, unsigned long long) = (CUresult(*)(CUmemGenericAllocationHandle *, size_t, const CUmemAllocationProp *, unsigned long long))dlsym(cuda_handle, "cuMemCreate");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(handle, size, prop, flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemExportToShareableHandle(void *shareableHandle, CUmemGenericAllocationHandle handle, CUmemAllocationHandleType handleType, unsigned long long flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemExportToShareableHandle");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(void *, CUmemGenericAllocationHandle, CUmemAllocationHandleType, unsigned long long) = (CUresult(*)(void *, CUmemGenericAllocationHandle, CUmemAllocationHandleType, unsigned long long))dlsym(cuda_handle, "cuMemExportToShareableHandle");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(shareableHandle, handle, handleType, flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemFree(CUdeviceptr dptr) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemFree");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr) = (CUresult(*)(CUdeviceptr))dlsym(cuda_handle, "cuMemFree");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dptr);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemFreeAsync(CUdeviceptr dptr, CUstream hStream) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemFreeAsync");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr, CUstream) = (CUresult(*)(CUdeviceptr, CUstream))dlsym(cuda_handle, "cuMemFreeAsync");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dptr, hStream);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemFreeHost(void *p) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemFreeHost");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(void *) = (CUresult(*)(void *))dlsym(cuda_handle, "cuMemFreeHost");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(p);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemGetAccess(unsigned long long *flags, const CUmemLocation *location, CUdeviceptr ptr) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemGetAccess");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(unsigned long long *, const CUmemLocation *, CUdeviceptr) = (CUresult(*)(unsigned long long *, const CUmemLocation *, CUdeviceptr))dlsym(cuda_handle, "cuMemGetAccess");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(flags, location, ptr);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemGetAddressRange(CUdeviceptr *pbase, size_t *psize, CUdeviceptr dptr) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemGetAddressRange");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr *, size_t *, CUdeviceptr) = (CUresult(*)(CUdeviceptr *, size_t *, CUdeviceptr))dlsym(cuda_handle, "cuMemGetAddressRange");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pbase, psize, dptr);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemGetAllocationGranularity(size_t *granularity, const CUmemAllocationProp *prop, CUmemAllocationGranularity_flags option) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemGetAllocationGranularity");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(size_t *, const CUmemAllocationProp *, CUmemAllocationGranularity_flags) = (CUresult(*)(size_t *, const CUmemAllocationProp *, CUmemAllocationGranularity_flags))dlsym(cuda_handle, "cuMemGetAllocationGranularity");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(granularity, prop, option);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemGetAllocationPropertiesFromHandle(CUmemAllocationProp *prop, CUmemGenericAllocationHandle handle) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemGetAllocationPropertiesFromHandle");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUmemAllocationProp *, CUmemGenericAllocationHandle) = (CUresult(*)(CUmemAllocationProp *, CUmemGenericAllocationHandle))dlsym(cuda_handle, "cuMemGetAllocationPropertiesFromHandle");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(prop, handle);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemGetHandleForAddressRange(void *handle, CUdeviceptr dptr, size_t size, CUmemRangeHandleType handleType, unsigned long long flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemGetHandleForAddressRange");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(void *, CUdeviceptr, size_t, CUmemRangeHandleType, unsigned long long) = (CUresult(*)(void *, CUdeviceptr, size_t, CUmemRangeHandleType, unsigned long long))dlsym(cuda_handle, "cuMemGetHandleForAddressRange");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(handle, dptr, size, handleType, flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemHostAlloc(void **pp, size_t bytesize, unsigned int Flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemHostAlloc");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(void **, size_t, unsigned int) = (CUresult(*)(void **, size_t, unsigned int))dlsym(cuda_handle, "cuMemHostAlloc");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pp, bytesize, Flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemHostGetDevicePointer(CUdeviceptr *pdptr, void *p, unsigned int Flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemHostGetDevicePointer");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr *, void *, unsigned int) = (CUresult(*)(CUdeviceptr *, void *, unsigned int))dlsym(cuda_handle, "cuMemHostGetDevicePointer");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pdptr, p, Flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemHostGetFlags(unsigned int *pFlags, void *p) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemHostGetFlags");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(unsigned int *, void *) = (CUresult(*)(unsigned int *, void *))dlsym(cuda_handle, "cuMemHostGetFlags");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pFlags, p);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemHostRegister(void *p, size_t bytesize, unsigned int Flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemHostRegister");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(void *, size_t, unsigned int) = (CUresult(*)(void *, size_t, unsigned int))dlsym(cuda_handle, "cuMemHostRegister");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(p, bytesize, Flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemHostUnregister(void *p) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemHostUnregister");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(void *) = (CUresult(*)(void *))dlsym(cuda_handle, "cuMemHostUnregister");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(p);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemImportFromShareableHandle(CUmemGenericAllocationHandle *handle, void *osHandle, CUmemAllocationHandleType shHandleType) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemImportFromShareableHandle");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUmemGenericAllocationHandle *, void *, CUmemAllocationHandleType) = (CUresult(*)(CUmemGenericAllocationHandle *, void *, CUmemAllocationHandleType))dlsym(cuda_handle, "cuMemImportFromShareableHandle");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(handle, osHandle, shHandleType);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemMap(CUdeviceptr ptr, size_t size, size_t offset, CUmemGenericAllocationHandle handle, unsigned long long flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemMap");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr, size_t, size_t, CUmemGenericAllocationHandle, unsigned long long) = (CUresult(*)(CUdeviceptr, size_t, size_t, CUmemGenericAllocationHandle, unsigned long long))dlsym(cuda_handle, "cuMemMap");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(ptr, size, offset, handle, flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemMapArrayAsync(CUarrayMapInfo *mapInfoList, unsigned int count, CUstream hStream) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemMapArrayAsync");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUarrayMapInfo *, unsigned int, CUstream) = (CUresult(*)(CUarrayMapInfo *, unsigned int, CUstream))dlsym(cuda_handle, "cuMemMapArrayAsync");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(mapInfoList, count, hStream);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemPoolCreate(CUmemoryPool *pool, const CUmemPoolProps *poolProps) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemPoolCreate");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUmemoryPool *, const CUmemPoolProps *) = (CUresult(*)(CUmemoryPool *, const CUmemPoolProps *))dlsym(cuda_handle, "cuMemPoolCreate");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pool, poolProps);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemPoolDestroy(CUmemoryPool pool) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemPoolDestroy");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUmemoryPool) = (CUresult(*)(CUmemoryPool))dlsym(cuda_handle, "cuMemPoolDestroy");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pool);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemPoolExportPointer(CUmemPoolPtrExportData *shareData_out, CUdeviceptr ptr) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemPoolExportPointer");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUmemPoolPtrExportData *, CUdeviceptr) = (CUresult(*)(CUmemPoolPtrExportData *, CUdeviceptr))dlsym(cuda_handle, "cuMemPoolExportPointer");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(shareData_out, ptr);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemPoolExportToShareableHandle(void *handle_out, CUmemoryPool pool, CUmemAllocationHandleType handleType, unsigned long long flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemPoolExportToShareableHandle");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(void *, CUmemoryPool, CUmemAllocationHandleType, unsigned long long) = (CUresult(*)(void *, CUmemoryPool, CUmemAllocationHandleType, unsigned long long))dlsym(cuda_handle, "cuMemPoolExportToShareableHandle");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(handle_out, pool, handleType, flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemPoolGetAccess(CUmemAccess_flags *flags, CUmemoryPool memPool, CUmemLocation *location) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemPoolGetAccess");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUmemAccess_flags *, CUmemoryPool, CUmemLocation *) = (CUresult(*)(CUmemAccess_flags *, CUmemoryPool, CUmemLocation *))dlsym(cuda_handle, "cuMemPoolGetAccess");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(flags, memPool, location);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemPoolGetAttribute(CUmemoryPool pool, CUmemPool_attribute attr, void *value) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemPoolGetAttribute");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUmemoryPool, CUmemPool_attribute, void *) = (CUresult(*)(CUmemoryPool, CUmemPool_attribute, void *))dlsym(cuda_handle, "cuMemPoolGetAttribute");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pool, attr, value);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemPoolImportFromShareableHandle(CUmemoryPool *pool_out, void *handle, CUmemAllocationHandleType handleType, unsigned long long flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemPoolImportFromShareableHandle");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUmemoryPool *, void *, CUmemAllocationHandleType, unsigned long long) = (CUresult(*)(CUmemoryPool *, void *, CUmemAllocationHandleType, unsigned long long))dlsym(cuda_handle, "cuMemPoolImportFromShareableHandle");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pool_out, handle, handleType, flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemPoolImportPointer(CUdeviceptr *ptr_out, CUmemoryPool pool, CUmemPoolPtrExportData *shareData) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemPoolImportPointer");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr *, CUmemoryPool, CUmemPoolPtrExportData *) = (CUresult(*)(CUdeviceptr *, CUmemoryPool, CUmemPoolPtrExportData *))dlsym(cuda_handle, "cuMemPoolImportPointer");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(ptr_out, pool, shareData);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemPoolSetAccess(CUmemoryPool pool, const CUmemAccessDesc *map, size_t count) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemPoolSetAccess");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUmemoryPool, const CUmemAccessDesc *, size_t) = (CUresult(*)(CUmemoryPool, const CUmemAccessDesc *, size_t))dlsym(cuda_handle, "cuMemPoolSetAccess");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pool, map, count);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemPoolSetAttribute(CUmemoryPool pool, CUmemPool_attribute attr, void *value) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemPoolSetAttribute");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUmemoryPool, CUmemPool_attribute, void *) = (CUresult(*)(CUmemoryPool, CUmemPool_attribute, void *))dlsym(cuda_handle, "cuMemPoolSetAttribute");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pool, attr, value);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemPoolTrimTo(CUmemoryPool pool, size_t minBytesToKeep) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemPoolTrimTo");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUmemoryPool, size_t) = (CUresult(*)(CUmemoryPool, size_t))dlsym(cuda_handle, "cuMemPoolTrimTo");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pool, minBytesToKeep);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemPrefetchAsync(CUdeviceptr devPtr, size_t count, CUdevice dstDevice, CUstream hStream) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemPrefetchAsync");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr, size_t, CUdevice, CUstream) = (CUresult(*)(CUdeviceptr, size_t, CUdevice, CUstream))dlsym(cuda_handle, "cuMemPrefetchAsync");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(devPtr, count, dstDevice, hStream);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemRangeGetAttribute(void *data, size_t dataSize, CUmem_range_attribute attribute, CUdeviceptr devPtr, size_t count) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemRangeGetAttribute");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(void *, size_t, CUmem_range_attribute, CUdeviceptr, size_t) = (CUresult(*)(void *, size_t, CUmem_range_attribute, CUdeviceptr, size_t))dlsym(cuda_handle, "cuMemRangeGetAttribute");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(data, dataSize, attribute, devPtr, count);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemRangeGetAttributes(void **data, size_t *dataSizes, CUmem_range_attribute *attributes, size_t numAttributes, CUdeviceptr devPtr, size_t count) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemRangeGetAttributes");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(void **, size_t *, CUmem_range_attribute *, size_t, CUdeviceptr, size_t) = (CUresult(*)(void **, size_t *, CUmem_range_attribute *, size_t, CUdeviceptr, size_t))dlsym(cuda_handle, "cuMemRangeGetAttributes");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(data, dataSizes, attributes, numAttributes, devPtr, count);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemRelease(CUmemGenericAllocationHandle handle) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemRelease");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUmemGenericAllocationHandle) = (CUresult(*)(CUmemGenericAllocationHandle))dlsym(cuda_handle, "cuMemRelease");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(handle);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemRetainAllocationHandle(CUmemGenericAllocationHandle *handle, void *addr) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemRetainAllocationHandle");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUmemGenericAllocationHandle *, void *) = (CUresult(*)(CUmemGenericAllocationHandle *, void *))dlsym(cuda_handle, "cuMemRetainAllocationHandle");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(handle, addr);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemSetAccess(CUdeviceptr ptr, size_t size, const CUmemAccessDesc *desc, size_t count) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemSetAccess");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr, size_t, const CUmemAccessDesc *, size_t) = (CUresult(*)(CUdeviceptr, size_t, const CUmemAccessDesc *, size_t))dlsym(cuda_handle, "cuMemSetAccess");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(ptr, size, desc, count);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemUnmap(CUdeviceptr ptr, size_t size) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemUnmap");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr, size_t) = (CUresult(*)(CUdeviceptr, size_t))dlsym(cuda_handle, "cuMemUnmap");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(ptr, size);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemcpy(CUdeviceptr dst, CUdeviceptr src, size_t ByteCount) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemcpy");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr, CUdeviceptr, size_t) = (CUresult(*)(CUdeviceptr, CUdeviceptr, size_t))dlsym(cuda_handle, "cuMemcpy");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dst, src, ByteCount);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemcpy2D(const CUDA_MEMCPY2D *pCopy) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemcpy2D");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(const CUDA_MEMCPY2D *) = (CUresult(*)(const CUDA_MEMCPY2D *))dlsym(cuda_handle, "cuMemcpy2D");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pCopy);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemcpy2DAsync(const CUDA_MEMCPY2D *pCopy, CUstream hStream) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemcpy2DAsync");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(const CUDA_MEMCPY2D *, CUstream) = (CUresult(*)(const CUDA_MEMCPY2D *, CUstream))dlsym(cuda_handle, "cuMemcpy2DAsync");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pCopy, hStream);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemcpy2DUnaligned(const CUDA_MEMCPY2D *pCopy) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemcpy2DUnaligned");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(const CUDA_MEMCPY2D *) = (CUresult(*)(const CUDA_MEMCPY2D *))dlsym(cuda_handle, "cuMemcpy2DUnaligned");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pCopy);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemcpy3D(const CUDA_MEMCPY3D *pCopy) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemcpy3D");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(const CUDA_MEMCPY3D *) = (CUresult(*)(const CUDA_MEMCPY3D *))dlsym(cuda_handle, "cuMemcpy3D");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pCopy);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemcpy3DAsync(const CUDA_MEMCPY3D *pCopy, CUstream hStream) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemcpy3DAsync");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(const CUDA_MEMCPY3D *, CUstream) = (CUresult(*)(const CUDA_MEMCPY3D *, CUstream))dlsym(cuda_handle, "cuMemcpy3DAsync");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pCopy, hStream);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemcpy3DPeer(const CUDA_MEMCPY3D_PEER *pCopy) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemcpy3DPeer");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(const CUDA_MEMCPY3D_PEER *) = (CUresult(*)(const CUDA_MEMCPY3D_PEER *))dlsym(cuda_handle, "cuMemcpy3DPeer");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pCopy);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemcpy3DPeerAsync(const CUDA_MEMCPY3D_PEER *pCopy, CUstream hStream) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemcpy3DPeerAsync");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(const CUDA_MEMCPY3D_PEER *, CUstream) = (CUresult(*)(const CUDA_MEMCPY3D_PEER *, CUstream))dlsym(cuda_handle, "cuMemcpy3DPeerAsync");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pCopy, hStream);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemcpyAsync(CUdeviceptr dst, CUdeviceptr src, size_t ByteCount, CUstream hStream) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemcpyAsync");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr, CUdeviceptr, size_t, CUstream) = (CUresult(*)(CUdeviceptr, CUdeviceptr, size_t, CUstream))dlsym(cuda_handle, "cuMemcpyAsync");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dst, src, ByteCount, hStream);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemcpyAtoA(CUarray dstArray, size_t dstOffset, CUarray srcArray, size_t srcOffset, size_t ByteCount) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemcpyAtoA");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUarray, size_t, CUarray, size_t, size_t) = (CUresult(*)(CUarray, size_t, CUarray, size_t, size_t))dlsym(cuda_handle, "cuMemcpyAtoA");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dstArray, dstOffset, srcArray, srcOffset, ByteCount);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemcpyAtoD(CUdeviceptr dstDevice, CUarray srcArray, size_t srcOffset, size_t ByteCount) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemcpyAtoD");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr, CUarray, size_t, size_t) = (CUresult(*)(CUdeviceptr, CUarray, size_t, size_t))dlsym(cuda_handle, "cuMemcpyAtoD");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dstDevice, srcArray, srcOffset, ByteCount);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemcpyAtoH(void *dstHost, CUarray srcArray, size_t srcOffset, size_t ByteCount) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemcpyAtoH");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(void *, CUarray, size_t, size_t) = (CUresult(*)(void *, CUarray, size_t, size_t))dlsym(cuda_handle, "cuMemcpyAtoH");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dstHost, srcArray, srcOffset, ByteCount);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemcpyAtoHAsync(void *dstHost, CUarray srcArray, size_t srcOffset, size_t ByteCount, CUstream hStream) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemcpyAtoHAsync");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(void *, CUarray, size_t, size_t, CUstream) = (CUresult(*)(void *, CUarray, size_t, size_t, CUstream))dlsym(cuda_handle, "cuMemcpyAtoHAsync");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dstHost, srcArray, srcOffset, ByteCount, hStream);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemcpyDtoA(CUarray dstArray, size_t dstOffset, CUdeviceptr srcDevice, size_t ByteCount) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemcpyDtoA");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUarray, size_t, CUdeviceptr, size_t) = (CUresult(*)(CUarray, size_t, CUdeviceptr, size_t))dlsym(cuda_handle, "cuMemcpyDtoA");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dstArray, dstOffset, srcDevice, ByteCount);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemcpyDtoD(CUdeviceptr dstDevice, CUdeviceptr srcDevice, size_t ByteCount) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemcpyDtoD");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr, CUdeviceptr, size_t) = (CUresult(*)(CUdeviceptr, CUdeviceptr, size_t))dlsym(cuda_handle, "cuMemcpyDtoD");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dstDevice, srcDevice, ByteCount);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemcpyDtoDAsync(CUdeviceptr dstDevice, CUdeviceptr srcDevice, size_t ByteCount, CUstream hStream) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemcpyDtoDAsync");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr, CUdeviceptr, size_t, CUstream) = (CUresult(*)(CUdeviceptr, CUdeviceptr, size_t, CUstream))dlsym(cuda_handle, "cuMemcpyDtoDAsync");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dstDevice, srcDevice, ByteCount, hStream);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemcpyDtoH(void *dstHost, CUdeviceptr srcDevice, size_t ByteCount) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemcpyDtoH");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(void *, CUdeviceptr, size_t) = (CUresult(*)(void *, CUdeviceptr, size_t))dlsym(cuda_handle, "cuMemcpyDtoH");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dstHost, srcDevice, ByteCount);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemcpyDtoHAsync(void *dstHost, CUdeviceptr srcDevice, size_t ByteCount, CUstream hStream) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemcpyDtoHAsync");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(void *, CUdeviceptr, size_t, CUstream) = (CUresult(*)(void *, CUdeviceptr, size_t, CUstream))dlsym(cuda_handle, "cuMemcpyDtoHAsync");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dstHost, srcDevice, ByteCount, hStream);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemcpyHtoA(CUarray dstArray, size_t dstOffset, const void *srcHost, size_t ByteCount) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemcpyHtoA");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUarray, size_t, const void *, size_t) = (CUresult(*)(CUarray, size_t, const void *, size_t))dlsym(cuda_handle, "cuMemcpyHtoA");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dstArray, dstOffset, srcHost, ByteCount);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemcpyHtoAAsync(CUarray dstArray, size_t dstOffset, const void *srcHost, size_t ByteCount, CUstream hStream) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemcpyHtoAAsync");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUarray, size_t, const void *, size_t, CUstream) = (CUresult(*)(CUarray, size_t, const void *, size_t, CUstream))dlsym(cuda_handle, "cuMemcpyHtoAAsync");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dstArray, dstOffset, srcHost, ByteCount, hStream);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemcpyHtoD(CUdeviceptr dstDevice, const void *srcHost, size_t ByteCount) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemcpyHtoD");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr, const void *, size_t) = (CUresult(*)(CUdeviceptr, const void *, size_t))dlsym(cuda_handle, "cuMemcpyHtoD");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dstDevice, srcHost, ByteCount);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemcpyHtoDAsync(CUdeviceptr dstDevice, const void *srcHost, size_t ByteCount, CUstream hStream) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemcpyHtoDAsync");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr, const void *, size_t, CUstream) = (CUresult(*)(CUdeviceptr, const void *, size_t, CUstream))dlsym(cuda_handle, "cuMemcpyHtoDAsync");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dstDevice, srcHost, ByteCount, hStream);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemcpyPeer(CUdeviceptr dstDevice, CUcontext dstContext, CUdeviceptr srcDevice, CUcontext srcContext, size_t ByteCount) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemcpyPeer");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr, CUcontext, CUdeviceptr, CUcontext, size_t) = (CUresult(*)(CUdeviceptr, CUcontext, CUdeviceptr, CUcontext, size_t))dlsym(cuda_handle, "cuMemcpyPeer");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dstDevice, dstContext, srcDevice, srcContext, ByteCount);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemcpyPeerAsync(CUdeviceptr dstDevice, CUcontext dstContext, CUdeviceptr srcDevice, CUcontext srcContext, size_t ByteCount, CUstream hStream) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemcpyPeerAsync");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr, CUcontext, CUdeviceptr, CUcontext, size_t, CUstream) = (CUresult(*)(CUdeviceptr, CUcontext, CUdeviceptr, CUcontext, size_t, CUstream))dlsym(cuda_handle, "cuMemcpyPeerAsync");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dstDevice, dstContext, srcDevice, srcContext, ByteCount, hStream);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemsetD16(CUdeviceptr dstDevice, unsigned short us, size_t N) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemsetD16");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr, unsigned short, size_t) = (CUresult(*)(CUdeviceptr, unsigned short, size_t))dlsym(cuda_handle, "cuMemsetD16");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dstDevice, us, N);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemsetD16Async(CUdeviceptr dstDevice, unsigned short us, size_t N, CUstream hStream) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemsetD16Async");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr, unsigned short, size_t, CUstream) = (CUresult(*)(CUdeviceptr, unsigned short, size_t, CUstream))dlsym(cuda_handle, "cuMemsetD16Async");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dstDevice, us, N, hStream);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemsetD2D16(CUdeviceptr dstDevice, size_t dstPitch, unsigned short us, size_t Width, size_t Height) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemsetD2D16");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr, size_t, unsigned short, size_t, size_t) = (CUresult(*)(CUdeviceptr, size_t, unsigned short, size_t, size_t))dlsym(cuda_handle, "cuMemsetD2D16");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dstDevice, dstPitch, us, Width, Height);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemsetD2D16Async(CUdeviceptr dstDevice, size_t dstPitch, unsigned short us, size_t Width, size_t Height, CUstream hStream) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemsetD2D16Async");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr, size_t, unsigned short, size_t, size_t, CUstream) = (CUresult(*)(CUdeviceptr, size_t, unsigned short, size_t, size_t, CUstream))dlsym(cuda_handle, "cuMemsetD2D16Async");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dstDevice, dstPitch, us, Width, Height, hStream);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemsetD2D32(CUdeviceptr dstDevice, size_t dstPitch, unsigned int ui, size_t Width, size_t Height) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemsetD2D32");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr, size_t, unsigned int, size_t, size_t) = (CUresult(*)(CUdeviceptr, size_t, unsigned int, size_t, size_t))dlsym(cuda_handle, "cuMemsetD2D32");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dstDevice, dstPitch, ui, Width, Height);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemsetD2D32Async(CUdeviceptr dstDevice, size_t dstPitch, unsigned int ui, size_t Width, size_t Height, CUstream hStream) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemsetD2D32Async");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr, size_t, unsigned int, size_t, size_t, CUstream) = (CUresult(*)(CUdeviceptr, size_t, unsigned int, size_t, size_t, CUstream))dlsym(cuda_handle, "cuMemsetD2D32Async");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dstDevice, dstPitch, ui, Width, Height, hStream);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemsetD2D8(CUdeviceptr dstDevice, size_t dstPitch, unsigned char uc, size_t Width, size_t Height) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemsetD2D8");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr, size_t, unsigned char, size_t, size_t) = (CUresult(*)(CUdeviceptr, size_t, unsigned char, size_t, size_t))dlsym(cuda_handle, "cuMemsetD2D8");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dstDevice, dstPitch, uc, Width, Height);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemsetD2D8Async(CUdeviceptr dstDevice, size_t dstPitch, unsigned char uc, size_t Width, size_t Height, CUstream hStream) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemsetD2D8Async");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr, size_t, unsigned char, size_t, size_t, CUstream) = (CUresult(*)(CUdeviceptr, size_t, unsigned char, size_t, size_t, CUstream))dlsym(cuda_handle, "cuMemsetD2D8Async");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dstDevice, dstPitch, uc, Width, Height, hStream);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemsetD32(CUdeviceptr dstDevice, unsigned int ui, size_t N) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemsetD32");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr, unsigned int, size_t) = (CUresult(*)(CUdeviceptr, unsigned int, size_t))dlsym(cuda_handle, "cuMemsetD32");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dstDevice, ui, N);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemsetD32Async(CUdeviceptr dstDevice, unsigned int ui, size_t N, CUstream hStream) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemsetD32Async");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr, unsigned int, size_t, CUstream) = (CUresult(*)(CUdeviceptr, unsigned int, size_t, CUstream))dlsym(cuda_handle, "cuMemsetD32Async");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dstDevice, ui, N, hStream);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemsetD8(CUdeviceptr dstDevice, unsigned char uc, size_t N) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemsetD8");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr, unsigned char, size_t) = (CUresult(*)(CUdeviceptr, unsigned char, size_t))dlsym(cuda_handle, "cuMemsetD8");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dstDevice, uc, N);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMemsetD8Async(CUdeviceptr dstDevice, unsigned char uc, size_t N, CUstream hStream) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemsetD8Async");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr, unsigned char, size_t, CUstream) = (CUresult(*)(CUdeviceptr, unsigned char, size_t, CUstream))dlsym(cuda_handle, "cuMemsetD8Async");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dstDevice, uc, N, hStream);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMipmappedArrayDestroy(CUmipmappedArray hMipmappedArray) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMipmappedArrayDestroy");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUmipmappedArray) = (CUresult(*)(CUmipmappedArray))dlsym(cuda_handle, "cuMipmappedArrayDestroy");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hMipmappedArray);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMipmappedArrayGetLevel(CUarray *pLevelArray, CUmipmappedArray hMipmappedArray, unsigned int level) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMipmappedArrayGetLevel");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUarray *, CUmipmappedArray, unsigned int) = (CUresult(*)(CUarray *, CUmipmappedArray, unsigned int))dlsym(cuda_handle, "cuMipmappedArrayGetLevel");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pLevelArray, hMipmappedArray, level);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMipmappedArrayGetMemoryRequirements(CUDA_ARRAY_MEMORY_REQUIREMENTS *memoryRequirements, CUmipmappedArray mipmap, CUdevice device) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMipmappedArrayGetMemoryRequirements");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUDA_ARRAY_MEMORY_REQUIREMENTS *, CUmipmappedArray, CUdevice) = (CUresult(*)(CUDA_ARRAY_MEMORY_REQUIREMENTS *, CUmipmappedArray, CUdevice))dlsym(cuda_handle, "cuMipmappedArrayGetMemoryRequirements");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(memoryRequirements, mipmap, device);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuMipmappedArrayGetSparseProperties(CUDA_ARRAY_SPARSE_PROPERTIES *sparseProperties, CUmipmappedArray mipmap) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMipmappedArrayGetSparseProperties");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUDA_ARRAY_SPARSE_PROPERTIES *, CUmipmappedArray) = (CUresult(*)(CUDA_ARRAY_SPARSE_PROPERTIES *, CUmipmappedArray))dlsym(cuda_handle, "cuMipmappedArrayGetSparseProperties");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(sparseProperties, mipmap);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuModuleGetFunction(CUfunction *hfunc, CUmodule hmod, const char *name) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuModuleGetFunction");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUfunction *, CUmodule, const char *) = (CUresult(*)(CUfunction *, CUmodule, const char *))dlsym(cuda_handle, "cuModuleGetFunction");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hfunc, hmod, name);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuModuleGetGlobal(CUdeviceptr *dptr, size_t *bytes, CUmodule hmod, const char *name) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuModuleGetGlobal");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr *, size_t *, CUmodule, const char *) = (CUresult(*)(CUdeviceptr *, size_t *, CUmodule, const char *))dlsym(cuda_handle, "cuModuleGetGlobal");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dptr, bytes, hmod, name);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuModuleGetLoadingMode(CUmoduleLoadingMode *mode) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuModuleGetLoadingMode");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUmoduleLoadingMode *) = (CUresult(*)(CUmoduleLoadingMode *))dlsym(cuda_handle, "cuModuleGetLoadingMode");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(mode);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuModuleGetSurfRef(CUsurfref *pSurfRef, CUmodule hmod, const char *name) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuModuleGetSurfRef");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUsurfref *, CUmodule, const char *) = (CUresult(*)(CUsurfref *, CUmodule, const char *))dlsym(cuda_handle, "cuModuleGetSurfRef");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pSurfRef, hmod, name);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuModuleGetTexRef(CUtexref *pTexRef, CUmodule hmod, const char *name) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuModuleGetTexRef");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUtexref *, CUmodule, const char *) = (CUresult(*)(CUtexref *, CUmodule, const char *))dlsym(cuda_handle, "cuModuleGetTexRef");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pTexRef, hmod, name);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuModuleLoad(CUmodule *module, const char *fname) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuModuleLoad");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUmodule *, const char *) = (CUresult(*)(CUmodule *, const char *))dlsym(cuda_handle, "cuModuleLoad");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(module, fname);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuModuleLoadData(CUmodule *module, const void *image) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuModuleLoadData");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUmodule *, const void *) = (CUresult(*)(CUmodule *, const void *))dlsym(cuda_handle, "cuModuleLoadData");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(module, image);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuModuleLoadDataEx(CUmodule *module, const void *image, unsigned int numOptions, CUjit_option *options, void **optionValues) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuModuleLoadDataEx");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUmodule *, const void *, unsigned int, CUjit_option *, void **) = (CUresult(*)(CUmodule *, const void *, unsigned int, CUjit_option *, void **))dlsym(cuda_handle, "cuModuleLoadDataEx");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(module, image, numOptions, options, optionValues);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuModuleLoadFatBinary(CUmodule *module, const void *fatCubin) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuModuleLoadFatBinary");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUmodule *, const void *) = (CUresult(*)(CUmodule *, const void *))dlsym(cuda_handle, "cuModuleLoadFatBinary");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(module, fatCubin);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuModuleUnload(CUmodule hmod) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuModuleUnload");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUmodule) = (CUresult(*)(CUmodule))dlsym(cuda_handle, "cuModuleUnload");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hmod);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuOccupancyAvailableDynamicSMemPerBlock(size_t *dynamicSmemSize, CUfunction func, int numBlocks, int blockSize) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuOccupancyAvailableDynamicSMemPerBlock");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(size_t *, CUfunction, int, int) = (CUresult(*)(size_t *, CUfunction, int, int))dlsym(cuda_handle, "cuOccupancyAvailableDynamicSMemPerBlock");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dynamicSmemSize, func, numBlocks, blockSize);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuOccupancyMaxActiveBlocksPerMultiprocessor(int *numBlocks, CUfunction func, int blockSize, size_t dynamicSMemSize) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuOccupancyMaxActiveBlocksPerMultiprocessor");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(int *, CUfunction, int, size_t) = (CUresult(*)(int *, CUfunction, int, size_t))dlsym(cuda_handle, "cuOccupancyMaxActiveBlocksPerMultiprocessor");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(numBlocks, func, blockSize, dynamicSMemSize);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags(int *numBlocks, CUfunction func, int blockSize, size_t dynamicSMemSize, unsigned int flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(int *, CUfunction, int, size_t, unsigned int) = (CUresult(*)(int *, CUfunction, int, size_t, unsigned int))dlsym(cuda_handle, "cuOccupancyMaxActiveBlocksPerMultiprocessorWithFlags");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(numBlocks, func, blockSize, dynamicSMemSize, flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuOccupancyMaxActiveClusters(int *numClusters, CUfunction func, const CUlaunchConfig *config) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuOccupancyMaxActiveClusters");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(int *, CUfunction, const CUlaunchConfig *) = (CUresult(*)(int *, CUfunction, const CUlaunchConfig *))dlsym(cuda_handle, "cuOccupancyMaxActiveClusters");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(numClusters, func, config);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuOccupancyMaxPotentialBlockSize(int *minGridSize, int *blockSize, CUfunction func, CUoccupancyB2DSize blockSizeToDynamicSMemSize, size_t dynamicSMemSize, int blockSizeLimit) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuOccupancyMaxPotentialBlockSize");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(int *, int *, CUfunction, CUoccupancyB2DSize, size_t, int) = (CUresult(*)(int *, int *, CUfunction, CUoccupancyB2DSize, size_t, int))dlsym(cuda_handle, "cuOccupancyMaxPotentialBlockSize");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(minGridSize, blockSize, func, blockSizeToDynamicSMemSize, dynamicSMemSize, blockSizeLimit);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuOccupancyMaxPotentialBlockSizeWithFlags(int *minGridSize, int *blockSize, CUfunction func, CUoccupancyB2DSize blockSizeToDynamicSMemSize, size_t dynamicSMemSize, int blockSizeLimit, unsigned int flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuOccupancyMaxPotentialBlockSizeWithFlags");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(int *, int *, CUfunction, CUoccupancyB2DSize, size_t, int, unsigned int) = (CUresult(*)(int *, int *, CUfunction, CUoccupancyB2DSize, size_t, int, unsigned int))dlsym(cuda_handle, "cuOccupancyMaxPotentialBlockSizeWithFlags");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(minGridSize, blockSize, func, blockSizeToDynamicSMemSize, dynamicSMemSize, blockSizeLimit, flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuOccupancyMaxPotentialClusterSize(int *clusterSize, CUfunction func, const CUlaunchConfig *config) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuOccupancyMaxPotentialClusterSize");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(int *, CUfunction, const CUlaunchConfig *) = (CUresult(*)(int *, CUfunction, const CUlaunchConfig *))dlsym(cuda_handle, "cuOccupancyMaxPotentialClusterSize");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(clusterSize, func, config);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuParamSetSize(CUfunction hfunc, unsigned int numbytes) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuParamSetSize");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUfunction, unsigned int) = (CUresult(*)(CUfunction, unsigned int))dlsym(cuda_handle, "cuParamSetSize");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hfunc, numbytes);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuParamSetTexRef(CUfunction hfunc, int texunit, CUtexref hTexRef) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuParamSetTexRef");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUfunction, int, CUtexref) = (CUresult(*)(CUfunction, int, CUtexref))dlsym(cuda_handle, "cuParamSetTexRef");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hfunc, texunit, hTexRef);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuParamSetf(CUfunction hfunc, int offset, float value) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuParamSetf");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUfunction, int, float) = (CUresult(*)(CUfunction, int, float))dlsym(cuda_handle, "cuParamSetf");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hfunc, offset, value);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuParamSeti(CUfunction hfunc, int offset, unsigned int value) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuParamSeti");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUfunction, int, unsigned int) = (CUresult(*)(CUfunction, int, unsigned int))dlsym(cuda_handle, "cuParamSeti");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hfunc, offset, value);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuParamSetv(CUfunction hfunc, int offset, void *ptr, unsigned int numbytes) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuParamSetv");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUfunction, int, void *, unsigned int) = (CUresult(*)(CUfunction, int, void *, unsigned int))dlsym(cuda_handle, "cuParamSetv");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hfunc, offset, ptr, numbytes);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuPointerGetAttribute(void *data, CUpointer_attribute attribute, CUdeviceptr ptr) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuPointerGetAttribute");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(void *, CUpointer_attribute, CUdeviceptr) = (CUresult(*)(void *, CUpointer_attribute, CUdeviceptr))dlsym(cuda_handle, "cuPointerGetAttribute");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(data, attribute, ptr);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuPointerGetAttributes(unsigned int numAttributes, CUpointer_attribute *attributes, void **data, CUdeviceptr ptr) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuPointerGetAttributes");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(unsigned int, CUpointer_attribute *, void **, CUdeviceptr) = (CUresult(*)(unsigned int, CUpointer_attribute *, void **, CUdeviceptr))dlsym(cuda_handle, "cuPointerGetAttributes");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(numAttributes, attributes, data, ptr);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuPointerSetAttribute(const void *value, CUpointer_attribute attribute, CUdeviceptr ptr) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuPointerSetAttribute");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(const void *, CUpointer_attribute, CUdeviceptr) = (CUresult(*)(const void *, CUpointer_attribute, CUdeviceptr))dlsym(cuda_handle, "cuPointerSetAttribute");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(value, attribute, ptr);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuSignalExternalSemaphoresAsync(const CUexternalSemaphore *extSemArray, const CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS *paramsArray, unsigned int numExtSems, CUstream stream) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuSignalExternalSemaphoresAsync");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(const CUexternalSemaphore *, const CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS *, unsigned int, CUstream) = (CUresult(*)(const CUexternalSemaphore *, const CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS *, unsigned int, CUstream))dlsym(cuda_handle, "cuSignalExternalSemaphoresAsync");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(extSemArray, paramsArray, numExtSems, stream);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuStreamAddCallback(CUstream hStream, CUstreamCallback callback, void *userData, unsigned int flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuStreamAddCallback");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUstream, CUstreamCallback, void *, unsigned int) = (CUresult(*)(CUstream, CUstreamCallback, void *, unsigned int))dlsym(cuda_handle, "cuStreamAddCallback");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hStream, callback, userData, flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuStreamAttachMemAsync(CUstream hStream, CUdeviceptr dptr, size_t length, unsigned int flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuStreamAttachMemAsync");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUstream, CUdeviceptr, size_t, unsigned int) = (CUresult(*)(CUstream, CUdeviceptr, size_t, unsigned int))dlsym(cuda_handle, "cuStreamAttachMemAsync");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hStream, dptr, length, flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuStreamBatchMemOp(CUstream stream, unsigned int count, CUstreamBatchMemOpParams *paramArray, unsigned int flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuStreamBatchMemOp");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUstream, unsigned int, CUstreamBatchMemOpParams *, unsigned int) = (CUresult(*)(CUstream, unsigned int, CUstreamBatchMemOpParams *, unsigned int))dlsym(cuda_handle, "cuStreamBatchMemOp");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(stream, count, paramArray, flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuStreamBatchMemOp_v2(CUstream stream, unsigned int count, CUstreamBatchMemOpParams *paramArray, unsigned int flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuStreamBatchMemOp_v2");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUstream, unsigned int, CUstreamBatchMemOpParams *, unsigned int) = (CUresult(*)(CUstream, unsigned int, CUstreamBatchMemOpParams *, unsigned int))dlsym(cuda_handle, "cuStreamBatchMemOp_v2");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(stream, count, paramArray, flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuStreamBeginCapture(CUstream hStream, CUstreamCaptureMode mode) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuStreamBeginCapture");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUstream, CUstreamCaptureMode) = (CUresult(*)(CUstream, CUstreamCaptureMode))dlsym(cuda_handle, "cuStreamBeginCapture");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hStream, mode);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuStreamCopyAttributes(CUstream dst, CUstream src) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuStreamCopyAttributes");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUstream, CUstream) = (CUresult(*)(CUstream, CUstream))dlsym(cuda_handle, "cuStreamCopyAttributes");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dst, src);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuStreamCreate(CUstream *phStream, unsigned int Flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuStreamCreate");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUstream *, unsigned int) = (CUresult(*)(CUstream *, unsigned int))dlsym(cuda_handle, "cuStreamCreate");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(phStream, Flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuStreamCreateWithPriority(CUstream *phStream, unsigned int flags, int priority) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuStreamCreateWithPriority");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUstream *, unsigned int, int) = (CUresult(*)(CUstream *, unsigned int, int))dlsym(cuda_handle, "cuStreamCreateWithPriority");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(phStream, flags, priority);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuStreamDestroy(CUstream hStream) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuStreamDestroy");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUstream) = (CUresult(*)(CUstream))dlsym(cuda_handle, "cuStreamDestroy");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hStream);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuStreamEndCapture(CUstream hStream, CUgraph *phGraph) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuStreamEndCapture");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUstream, CUgraph *) = (CUresult(*)(CUstream, CUgraph *))dlsym(cuda_handle, "cuStreamEndCapture");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hStream, phGraph);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuStreamGetAttribute(CUstream hStream, CUstreamAttrID attr, CUstreamAttrValue *value_out) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuStreamGetAttribute");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUstream, CUstreamAttrID, CUstreamAttrValue *) = (CUresult(*)(CUstream, CUstreamAttrID, CUstreamAttrValue *))dlsym(cuda_handle, "cuStreamGetAttribute");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hStream, attr, value_out);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuStreamGetCaptureInfo(CUstream hStream, CUstreamCaptureStatus *captureStatus_out, cuuint64_t *id_out) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuStreamGetCaptureInfo");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUstream, CUstreamCaptureStatus *, cuuint64_t *) = (CUresult(*)(CUstream, CUstreamCaptureStatus *, cuuint64_t *))dlsym(cuda_handle, "cuStreamGetCaptureInfo");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hStream, captureStatus_out, id_out);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuStreamGetCaptureInfo_v2(CUstream hStream, CUstreamCaptureStatus *captureStatus_out, cuuint64_t *id_out, CUgraph *graph_out, const CUgraphNode **dependencies_out, size_t *numDependencies_out) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuStreamGetCaptureInfo_v2");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUstream, CUstreamCaptureStatus *, cuuint64_t *, CUgraph *, const CUgraphNode **, size_t *) = (CUresult(*)(CUstream, CUstreamCaptureStatus *, cuuint64_t *, CUgraph *, const CUgraphNode **, size_t *))dlsym(cuda_handle, "cuStreamGetCaptureInfo_v2");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hStream, captureStatus_out, id_out, graph_out, dependencies_out, numDependencies_out);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuStreamGetCtx(CUstream hStream, CUcontext *pctx) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuStreamGetCtx");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUstream, CUcontext *) = (CUresult(*)(CUstream, CUcontext *))dlsym(cuda_handle, "cuStreamGetCtx");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hStream, pctx);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuStreamGetFlags(CUstream hStream, unsigned int *flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuStreamGetFlags");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUstream, unsigned int *) = (CUresult(*)(CUstream, unsigned int *))dlsym(cuda_handle, "cuStreamGetFlags");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hStream, flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuStreamGetPriority(CUstream hStream, int *priority) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuStreamGetPriority");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUstream, int *) = (CUresult(*)(CUstream, int *))dlsym(cuda_handle, "cuStreamGetPriority");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hStream, priority);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuStreamIsCapturing(CUstream hStream, CUstreamCaptureStatus *captureStatus) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuStreamIsCapturing");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUstream, CUstreamCaptureStatus *) = (CUresult(*)(CUstream, CUstreamCaptureStatus *))dlsym(cuda_handle, "cuStreamIsCapturing");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hStream, captureStatus);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuStreamQuery(CUstream hStream) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuStreamQuery");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUstream) = (CUresult(*)(CUstream))dlsym(cuda_handle, "cuStreamQuery");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hStream);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuStreamSetAttribute(CUstream hStream, CUstreamAttrID attr, const CUstreamAttrValue *value) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuStreamSetAttribute");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUstream, CUstreamAttrID, const CUstreamAttrValue *) = (CUresult(*)(CUstream, CUstreamAttrID, const CUstreamAttrValue *))dlsym(cuda_handle, "cuStreamSetAttribute");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hStream, attr, value);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuStreamSynchronize(CUstream hStream) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuStreamSynchronize");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUstream) = (CUresult(*)(CUstream))dlsym(cuda_handle, "cuStreamSynchronize");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hStream);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuStreamUpdateCaptureDependencies(CUstream hStream, CUgraphNode *dependencies, size_t numDependencies, unsigned int flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuStreamUpdateCaptureDependencies");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUstream, CUgraphNode *, size_t, unsigned int) = (CUresult(*)(CUstream, CUgraphNode *, size_t, unsigned int))dlsym(cuda_handle, "cuStreamUpdateCaptureDependencies");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hStream, dependencies, numDependencies, flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuStreamWaitEvent(CUstream hStream, CUevent hEvent, unsigned int Flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuStreamWaitEvent");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUstream, CUevent, unsigned int) = (CUresult(*)(CUstream, CUevent, unsigned int))dlsym(cuda_handle, "cuStreamWaitEvent");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hStream, hEvent, Flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuStreamWaitValue32(CUstream stream, CUdeviceptr addr, cuuint32_t value, unsigned int flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuStreamWaitValue32");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUstream, CUdeviceptr, cuuint32_t, unsigned int) = (CUresult(*)(CUstream, CUdeviceptr, cuuint32_t, unsigned int))dlsym(cuda_handle, "cuStreamWaitValue32");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(stream, addr, value, flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuStreamWaitValue32_v2(CUstream stream, CUdeviceptr addr, cuuint32_t value, unsigned int flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuStreamWaitValue32_v2");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUstream, CUdeviceptr, cuuint32_t, unsigned int) = (CUresult(*)(CUstream, CUdeviceptr, cuuint32_t, unsigned int))dlsym(cuda_handle, "cuStreamWaitValue32_v2");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(stream, addr, value, flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuStreamWaitValue64(CUstream stream, CUdeviceptr addr, cuuint64_t value, unsigned int flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuStreamWaitValue64");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUstream, CUdeviceptr, cuuint64_t, unsigned int) = (CUresult(*)(CUstream, CUdeviceptr, cuuint64_t, unsigned int))dlsym(cuda_handle, "cuStreamWaitValue64");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(stream, addr, value, flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuStreamWaitValue64_v2(CUstream stream, CUdeviceptr addr, cuuint64_t value, unsigned int flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuStreamWaitValue64_v2");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUstream, CUdeviceptr, cuuint64_t, unsigned int) = (CUresult(*)(CUstream, CUdeviceptr, cuuint64_t, unsigned int))dlsym(cuda_handle, "cuStreamWaitValue64_v2");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(stream, addr, value, flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuStreamWriteValue32(CUstream stream, CUdeviceptr addr, cuuint32_t value, unsigned int flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuStreamWriteValue32");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUstream, CUdeviceptr, cuuint32_t, unsigned int) = (CUresult(*)(CUstream, CUdeviceptr, cuuint32_t, unsigned int))dlsym(cuda_handle, "cuStreamWriteValue32");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(stream, addr, value, flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuStreamWriteValue32_v2(CUstream stream, CUdeviceptr addr, cuuint32_t value, unsigned int flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuStreamWriteValue32_v2");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUstream, CUdeviceptr, cuuint32_t, unsigned int) = (CUresult(*)(CUstream, CUdeviceptr, cuuint32_t, unsigned int))dlsym(cuda_handle, "cuStreamWriteValue32_v2");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(stream, addr, value, flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuStreamWriteValue64(CUstream stream, CUdeviceptr addr, cuuint64_t value, unsigned int flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuStreamWriteValue64");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUstream, CUdeviceptr, cuuint64_t, unsigned int) = (CUresult(*)(CUstream, CUdeviceptr, cuuint64_t, unsigned int))dlsym(cuda_handle, "cuStreamWriteValue64");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(stream, addr, value, flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuStreamWriteValue64_v2(CUstream stream, CUdeviceptr addr, cuuint64_t value, unsigned int flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuStreamWriteValue64_v2");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUstream, CUdeviceptr, cuuint64_t, unsigned int) = (CUresult(*)(CUstream, CUdeviceptr, cuuint64_t, unsigned int))dlsym(cuda_handle, "cuStreamWriteValue64_v2");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(stream, addr, value, flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuSurfObjectCreate(CUsurfObject *pSurfObject, const CUDA_RESOURCE_DESC *pResDesc) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuSurfObjectCreate");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUsurfObject *, const CUDA_RESOURCE_DESC *) = (CUresult(*)(CUsurfObject *, const CUDA_RESOURCE_DESC *))dlsym(cuda_handle, "cuSurfObjectCreate");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pSurfObject, pResDesc);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuSurfObjectDestroy(CUsurfObject surfObject) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuSurfObjectDestroy");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUsurfObject) = (CUresult(*)(CUsurfObject))dlsym(cuda_handle, "cuSurfObjectDestroy");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(surfObject);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuSurfObjectGetResourceDesc(CUDA_RESOURCE_DESC *pResDesc, CUsurfObject surfObject) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuSurfObjectGetResourceDesc");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUDA_RESOURCE_DESC *, CUsurfObject) = (CUresult(*)(CUDA_RESOURCE_DESC *, CUsurfObject))dlsym(cuda_handle, "cuSurfObjectGetResourceDesc");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pResDesc, surfObject);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuSurfRefGetArray(CUarray *phArray, CUsurfref hSurfRef) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuSurfRefGetArray");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUarray *, CUsurfref) = (CUresult(*)(CUarray *, CUsurfref))dlsym(cuda_handle, "cuSurfRefGetArray");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(phArray, hSurfRef);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuSurfRefSetArray(CUsurfref hSurfRef, CUarray hArray, unsigned int Flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuSurfRefSetArray");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUsurfref, CUarray, unsigned int) = (CUresult(*)(CUsurfref, CUarray, unsigned int))dlsym(cuda_handle, "cuSurfRefSetArray");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hSurfRef, hArray, Flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuTexObjectCreate(CUtexObject *pTexObject, const CUDA_RESOURCE_DESC *pResDesc, const CUDA_TEXTURE_DESC *pTexDesc, const CUDA_RESOURCE_VIEW_DESC *pResViewDesc) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuTexObjectCreate");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUtexObject *, const CUDA_RESOURCE_DESC *, const CUDA_TEXTURE_DESC *, const CUDA_RESOURCE_VIEW_DESC *) = (CUresult(*)(CUtexObject *, const CUDA_RESOURCE_DESC *, const CUDA_TEXTURE_DESC *, const CUDA_RESOURCE_VIEW_DESC *))dlsym(cuda_handle, "cuTexObjectCreate");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pTexObject, pResDesc, pTexDesc, pResViewDesc);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuTexObjectDestroy(CUtexObject texObject) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuTexObjectDestroy");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUtexObject) = (CUresult(*)(CUtexObject))dlsym(cuda_handle, "cuTexObjectDestroy");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(texObject);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuTexObjectGetResourceDesc(CUDA_RESOURCE_DESC *pResDesc, CUtexObject texObject) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuTexObjectGetResourceDesc");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUDA_RESOURCE_DESC *, CUtexObject) = (CUresult(*)(CUDA_RESOURCE_DESC *, CUtexObject))dlsym(cuda_handle, "cuTexObjectGetResourceDesc");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pResDesc, texObject);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuTexObjectGetResourceViewDesc(CUDA_RESOURCE_VIEW_DESC *pResViewDesc, CUtexObject texObject) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuTexObjectGetResourceViewDesc");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUDA_RESOURCE_VIEW_DESC *, CUtexObject) = (CUresult(*)(CUDA_RESOURCE_VIEW_DESC *, CUtexObject))dlsym(cuda_handle, "cuTexObjectGetResourceViewDesc");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pResViewDesc, texObject);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuTexObjectGetTextureDesc(CUDA_TEXTURE_DESC *pTexDesc, CUtexObject texObject) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuTexObjectGetTextureDesc");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUDA_TEXTURE_DESC *, CUtexObject) = (CUresult(*)(CUDA_TEXTURE_DESC *, CUtexObject))dlsym(cuda_handle, "cuTexObjectGetTextureDesc");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pTexDesc, texObject);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuTexRefCreate(CUtexref *pTexRef) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuTexRefCreate");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUtexref *) = (CUresult(*)(CUtexref *))dlsym(cuda_handle, "cuTexRefCreate");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pTexRef);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuTexRefDestroy(CUtexref hTexRef) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuTexRefDestroy");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUtexref) = (CUresult(*)(CUtexref))dlsym(cuda_handle, "cuTexRefDestroy");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hTexRef);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuTexRefGetAddress(CUdeviceptr *pdptr, CUtexref hTexRef) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuTexRefGetAddress");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr *, CUtexref) = (CUresult(*)(CUdeviceptr *, CUtexref))dlsym(cuda_handle, "cuTexRefGetAddress");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pdptr, hTexRef);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuTexRefGetAddressMode(CUaddress_mode *pam, CUtexref hTexRef, int dim) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuTexRefGetAddressMode");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUaddress_mode *, CUtexref, int) = (CUresult(*)(CUaddress_mode *, CUtexref, int))dlsym(cuda_handle, "cuTexRefGetAddressMode");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pam, hTexRef, dim);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuTexRefGetArray(CUarray *phArray, CUtexref hTexRef) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuTexRefGetArray");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUarray *, CUtexref) = (CUresult(*)(CUarray *, CUtexref))dlsym(cuda_handle, "cuTexRefGetArray");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(phArray, hTexRef);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuTexRefGetBorderColor(float *pBorderColor, CUtexref hTexRef) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuTexRefGetBorderColor");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(float *, CUtexref) = (CUresult(*)(float *, CUtexref))dlsym(cuda_handle, "cuTexRefGetBorderColor");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pBorderColor, hTexRef);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuTexRefGetFilterMode(CUfilter_mode *pfm, CUtexref hTexRef) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuTexRefGetFilterMode");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUfilter_mode *, CUtexref) = (CUresult(*)(CUfilter_mode *, CUtexref))dlsym(cuda_handle, "cuTexRefGetFilterMode");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pfm, hTexRef);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuTexRefGetFlags(unsigned int *pFlags, CUtexref hTexRef) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuTexRefGetFlags");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(unsigned int *, CUtexref) = (CUresult(*)(unsigned int *, CUtexref))dlsym(cuda_handle, "cuTexRefGetFlags");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pFlags, hTexRef);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuTexRefGetFormat(CUarray_format *pFormat, int *pNumChannels, CUtexref hTexRef) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuTexRefGetFormat");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUarray_format *, int *, CUtexref) = (CUresult(*)(CUarray_format *, int *, CUtexref))dlsym(cuda_handle, "cuTexRefGetFormat");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pFormat, pNumChannels, hTexRef);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuTexRefGetMaxAnisotropy(int *pmaxAniso, CUtexref hTexRef) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuTexRefGetMaxAnisotropy");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(int *, CUtexref) = (CUresult(*)(int *, CUtexref))dlsym(cuda_handle, "cuTexRefGetMaxAnisotropy");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pmaxAniso, hTexRef);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuTexRefGetMipmapFilterMode(CUfilter_mode *pfm, CUtexref hTexRef) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuTexRefGetMipmapFilterMode");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUfilter_mode *, CUtexref) = (CUresult(*)(CUfilter_mode *, CUtexref))dlsym(cuda_handle, "cuTexRefGetMipmapFilterMode");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pfm, hTexRef);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuTexRefGetMipmapLevelBias(float *pbias, CUtexref hTexRef) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuTexRefGetMipmapLevelBias");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(float *, CUtexref) = (CUresult(*)(float *, CUtexref))dlsym(cuda_handle, "cuTexRefGetMipmapLevelBias");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pbias, hTexRef);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuTexRefGetMipmapLevelClamp(float *pminMipmapLevelClamp, float *pmaxMipmapLevelClamp, CUtexref hTexRef) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuTexRefGetMipmapLevelClamp");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(float *, float *, CUtexref) = (CUresult(*)(float *, float *, CUtexref))dlsym(cuda_handle, "cuTexRefGetMipmapLevelClamp");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(pminMipmapLevelClamp, pmaxMipmapLevelClamp, hTexRef);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuTexRefGetMipmappedArray(CUmipmappedArray *phMipmappedArray, CUtexref hTexRef) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuTexRefGetMipmappedArray");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUmipmappedArray *, CUtexref) = (CUresult(*)(CUmipmappedArray *, CUtexref))dlsym(cuda_handle, "cuTexRefGetMipmappedArray");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(phMipmappedArray, hTexRef);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuTexRefSetAddress(size_t *ByteOffset, CUtexref hTexRef, CUdeviceptr dptr, size_t bytes) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuTexRefSetAddress");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(size_t *, CUtexref, CUdeviceptr, size_t) = (CUresult(*)(size_t *, CUtexref, CUdeviceptr, size_t))dlsym(cuda_handle, "cuTexRefSetAddress");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(ByteOffset, hTexRef, dptr, bytes);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuTexRefSetAddress2D(CUtexref hTexRef, const CUDA_ARRAY_DESCRIPTOR *desc, CUdeviceptr dptr, size_t Pitch) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuTexRefSetAddress2D");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUtexref, const CUDA_ARRAY_DESCRIPTOR *, CUdeviceptr, size_t) = (CUresult(*)(CUtexref, const CUDA_ARRAY_DESCRIPTOR *, CUdeviceptr, size_t))dlsym(cuda_handle, "cuTexRefSetAddress2D");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hTexRef, desc, dptr, Pitch);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuTexRefSetAddressMode(CUtexref hTexRef, int dim, CUaddress_mode am) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuTexRefSetAddressMode");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUtexref, int, CUaddress_mode) = (CUresult(*)(CUtexref, int, CUaddress_mode))dlsym(cuda_handle, "cuTexRefSetAddressMode");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hTexRef, dim, am);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuTexRefSetArray(CUtexref hTexRef, CUarray hArray, unsigned int Flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuTexRefSetArray");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUtexref, CUarray, unsigned int) = (CUresult(*)(CUtexref, CUarray, unsigned int))dlsym(cuda_handle, "cuTexRefSetArray");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hTexRef, hArray, Flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuTexRefSetBorderColor(CUtexref hTexRef, float *pBorderColor) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuTexRefSetBorderColor");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUtexref, float *) = (CUresult(*)(CUtexref, float *))dlsym(cuda_handle, "cuTexRefSetBorderColor");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hTexRef, pBorderColor);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuTexRefSetFilterMode(CUtexref hTexRef, CUfilter_mode fm) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuTexRefSetFilterMode");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUtexref, CUfilter_mode) = (CUresult(*)(CUtexref, CUfilter_mode))dlsym(cuda_handle, "cuTexRefSetFilterMode");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hTexRef, fm);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuTexRefSetFlags(CUtexref hTexRef, unsigned int Flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuTexRefSetFlags");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUtexref, unsigned int) = (CUresult(*)(CUtexref, unsigned int))dlsym(cuda_handle, "cuTexRefSetFlags");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hTexRef, Flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuTexRefSetFormat(CUtexref hTexRef, CUarray_format fmt, int NumPackedComponents) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuTexRefSetFormat");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUtexref, CUarray_format, int) = (CUresult(*)(CUtexref, CUarray_format, int))dlsym(cuda_handle, "cuTexRefSetFormat");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hTexRef, fmt, NumPackedComponents);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuTexRefSetMaxAnisotropy(CUtexref hTexRef, unsigned int maxAniso) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuTexRefSetMaxAnisotropy");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUtexref, unsigned int) = (CUresult(*)(CUtexref, unsigned int))dlsym(cuda_handle, "cuTexRefSetMaxAnisotropy");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hTexRef, maxAniso);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuTexRefSetMipmapFilterMode(CUtexref hTexRef, CUfilter_mode fm) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuTexRefSetMipmapFilterMode");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUtexref, CUfilter_mode) = (CUresult(*)(CUtexref, CUfilter_mode))dlsym(cuda_handle, "cuTexRefSetMipmapFilterMode");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hTexRef, fm);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuTexRefSetMipmapLevelBias(CUtexref hTexRef, float bias) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuTexRefSetMipmapLevelBias");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUtexref, float) = (CUresult(*)(CUtexref, float))dlsym(cuda_handle, "cuTexRefSetMipmapLevelBias");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hTexRef, bias);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuTexRefSetMipmapLevelClamp(CUtexref hTexRef, float minMipmapLevelClamp, float maxMipmapLevelClamp) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuTexRefSetMipmapLevelClamp");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUtexref, float, float) = (CUresult(*)(CUtexref, float, float))dlsym(cuda_handle, "cuTexRefSetMipmapLevelClamp");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hTexRef, minMipmapLevelClamp, maxMipmapLevelClamp);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuTexRefSetMipmappedArray(CUtexref hTexRef, CUmipmappedArray hMipmappedArray, unsigned int Flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuTexRefSetMipmappedArray");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUtexref, CUmipmappedArray, unsigned int) = (CUresult(*)(CUtexref, CUmipmappedArray, unsigned int))dlsym(cuda_handle, "cuTexRefSetMipmappedArray");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hTexRef, hMipmappedArray, Flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuThreadExchangeStreamCaptureMode(CUstreamCaptureMode *mode) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuThreadExchangeStreamCaptureMode");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUstreamCaptureMode *) = (CUresult(*)(CUstreamCaptureMode *))dlsym(cuda_handle, "cuThreadExchangeStreamCaptureMode");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(mode);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuUserObjectCreate(CUuserObject *object_out, void *ptr, CUhostFn destroy, unsigned int initialRefcount, unsigned int flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuUserObjectCreate");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUuserObject *, void *, CUhostFn, unsigned int, unsigned int) = (CUresult(*)(CUuserObject *, void *, CUhostFn, unsigned int, unsigned int))dlsym(cuda_handle, "cuUserObjectCreate");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(object_out, ptr, destroy, initialRefcount, flags);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuUserObjectRelease(CUuserObject object, unsigned int count) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuUserObjectRelease");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUuserObject, unsigned int) = (CUresult(*)(CUuserObject, unsigned int))dlsym(cuda_handle, "cuUserObjectRelease");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(object, count);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuUserObjectRetain(CUuserObject object, unsigned int count) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuUserObjectRetain");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUuserObject, unsigned int) = (CUresult(*)(CUuserObject, unsigned int))dlsym(cuda_handle, "cuUserObjectRetain");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(object, count);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}

CUresult cuWaitExternalSemaphoresAsync(const CUexternalSemaphore *extSemArray, const CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS *paramsArray, unsigned int numExtSems, CUstream stream) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuWaitExternalSemaphoresAsync");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(const CUexternalSemaphore *, const CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS *, unsigned int, CUstream) = (CUresult(*)(const CUexternalSemaphore *, const CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS *, unsigned int, CUstream))dlsym(cuda_handle, "cuWaitExternalSemaphoresAsync");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(extSemArray, paramsArray, numExtSems, stream);
    cudaTimeProfileDestroy(pprof, rs);
    return rs;
}
