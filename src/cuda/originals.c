#include "include/all.h"
extern void *cuda_library_entry[1024];

CUresult cuCtxPopCurrent(CUcontext *pctx) {
    LINFO("Hijacking %s", "cuCtxPopCurrent");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxPopCurrent, pctx);
}
CUresult cuCtxPopCurrent_v2(CUcontext *pctx) {
    LINFO("Hijacking %s", "cuCtxPopCurrent_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxPopCurrent_v2, pctx);
}
CUresult cuCtxPushCurrent(CUcontext ctx) {
    LINFO("Hijacking %s", "cuCtxPushCurrent");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxPushCurrent, ctx);
}
CUresult cuCtxPushCurrent_v2(CUcontext ctx) {
    LINFO("Hijacking %s", "cuCtxPushCurrent_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxPushCurrent_v2, ctx);
}
CUresult cuCtxSetCacheConfig(CUfunc_cache config) {
    LINFO("Hijacking %s", "cuCtxSetCacheConfig");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxSetCacheConfig, config);
}
CUresult cuDestroyExternalMemory(CUexternalMemory extMem) {
    LINFO("Hijacking %s", "cuDestroyExternalMemory");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDestroyExternalMemory, extMem);
}
CUresult cuDestroyExternalSemaphore(CUexternalSemaphore extSem) {
    LINFO("Hijacking %s", "cuDestroyExternalSemaphore");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDestroyExternalSemaphore, extSem);
}
CUresult cuDeviceGetDefaultMemPool(CUmemoryPool *pool_out, CUdevice dev) {
    LINFO("Hijacking %s", "cuDeviceGetDefaultMemPool");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetDefaultMemPool, pool_out, dev);
}
CUresult cuDeviceGetLuid(char *luid, unsigned int *deviceNodeMask, CUdevice dev) {
    LINFO("Hijacking %s", "cuDeviceGetLuid");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetLuid, luid, deviceNodeMask, dev);
}
CUresult cuDeviceGetMemPool(CUmemoryPool *pool, CUdevice dev) {
    LINFO("Hijacking %s", "cuDeviceGetMemPool");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetMemPool, pool, dev);
}
CUresult cuDeviceGetName(char *name, int len, CUdevice dev) {
    LINFO("Hijacking %s", "cuDeviceGetName");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetName, name, len, dev);
}
CUresult cuDeviceGetP2PAttribute(int *value, CUdevice_P2PAttribute attrib, CUdevice srcDevice, CUdevice dstDevice) {
    LINFO("Hijacking %s", "cuDeviceGetP2PAttribute");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetP2PAttribute, value, attrib, srcDevice, dstDevice);
}
CUresult cuDeviceGetTexture1DLinearMaxWidth(size_t *maxWidthInElements, CUarray_format format, unsigned numChannels, CUdevice dev) {
    LINFO("Hijacking %s", "cuDeviceGetTexture1DLinearMaxWidth");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetTexture1DLinearMaxWidth, maxWidthInElements, format, numChannels, dev);
}
CUresult cuDeviceGetUuid(CUuuid *uuid, CUdevice dev) {
    LINFO("Hijacking %s", "cuDeviceGetUuid");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetUuid, uuid, dev);
}
CUresult cuDevicePrimaryCtxReset(CUdevice dev) {
    LINFO("Hijacking %s", "cuDevicePrimaryCtxReset");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDevicePrimaryCtxReset, dev);
}
CUresult cuDeviceSetMemPool(CUdevice dev, CUmemoryPool pool) {
    LINFO("Hijacking %s", "cuDeviceSetMemPool");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceSetMemPool, dev, pool);
}
CUresult cuEventCreate(CUevent *phEvent, unsigned int Flags) {
    LINFO("Hijacking %s", "cuEventCreate");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuEventCreate, phEvent, Flags);
}
CUresult cuEventDestroy_v2(CUevent hEvent) {
    LINFO("Hijacking %s", "cuEventDestroy_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuEventDestroy_v2, hEvent);
}
CUresult cuEventRecordWithFlags(CUevent hEvent, CUstream hStream, unsigned int flags) {
    LINFO("Hijacking %s", "cuEventRecordWithFlags");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuEventRecordWithFlags, hEvent, hStream, flags);
}
CUresult cuExternalMemoryGetMappedBuffer(CUdeviceptr *devPtr, CUexternalMemory extMem, const CUDA_EXTERNAL_MEMORY_BUFFER_DESC *bufferDesc) {
    LINFO("Hijacking %s", "cuExternalMemoryGetMappedBuffer");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuExternalMemoryGetMappedBuffer, devPtr, extMem, bufferDesc);
}
CUresult cuExternalMemoryGetMappedMipmappedArray(CUmipmappedArray *mipmap, CUexternalMemory extMem, const CUDA_EXTERNAL_MEMORY_MIPMAPPED_ARRAY_DESC *mipmapDesc) {
    LINFO("Hijacking %s", "cuExternalMemoryGetMappedMipmappedArray");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuExternalMemoryGetMappedMipmappedArray, mipmap, extMem, mipmapDesc);
}
CUresult cuFlushGPUDirectRDMAWrites(CUflushGPUDirectRDMAWritesTarget target, CUflushGPUDirectRDMAWritesScope scope) {
    LINFO("Hijacking %s", "cuFlushGPUDirectRDMAWrites");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuFlushGPUDirectRDMAWrites, target, scope);
}
CUresult cuFuncGetAttribute(int *pi, CUfunction_attribute attrib, CUfunction hfunc) {
    LINFO("Hijacking %s", "cuFuncGetAttribute");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuFuncGetAttribute, pi, attrib, hfunc);
}
CUresult cuFuncSetAttribute(CUfunction hfunc, CUfunction_attribute attrib, int value) {
    LINFO("Hijacking %s", "cuFuncSetAttribute");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuFuncSetAttribute, hfunc, attrib, value);
}
CUresult cuFuncSetCacheConfig(CUfunction hfunc, CUfunc_cache config) {
    LINFO("Hijacking %s", "cuFuncSetCacheConfig");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuFuncSetCacheConfig, hfunc, config);
}
CUresult cuFuncSetSharedMemConfig(CUfunction hfunc, CUsharedconfig config) {
    LINFO("Hijacking %s", "cuFuncSetSharedMemConfig");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuFuncSetSharedMemConfig, hfunc, config);
}
CUresult cuGetErrorName(CUresult error, const char **pStr) {
    LINFO("Hijacking %s", "cuGetErrorName");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGetErrorName, error, pStr);
}
CUresult cuGraphAddChildGraphNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, CUgraph childGraph) {
    LINFO("Hijacking %s", "cuGraphAddChildGraphNode");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddChildGraphNode, phGraphNode, hGraph, dependencies, numDependencies, childGraph);
}
CUresult cuGraphAddDependencies(CUgraph hGraph, const CUgraphNode *from, const CUgraphNode *to, size_t numDependencies) {
    LINFO("Hijacking %s", "cuGraphAddDependencies");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddDependencies, hGraph, from, to, numDependencies);
}
CUresult cuGraphAddEmptyNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies) {
    LINFO("Hijacking %s", "cuGraphAddEmptyNode");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddEmptyNode, phGraphNode, hGraph, dependencies, numDependencies);
}
CUresult cuGraphAddEventRecordNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, CUevent event) {
    LINFO("Hijacking %s", "cuGraphAddEventRecordNode");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddEventRecordNode, phGraphNode, hGraph, dependencies, numDependencies, event);
}
CUresult cuGraphAddEventWaitNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, CUevent event) {
    LINFO("Hijacking %s", "cuGraphAddEventWaitNode");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddEventWaitNode, phGraphNode, hGraph, dependencies, numDependencies, event);
}
CUresult cuGraphAddExternalSemaphoresSignalNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, const CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *nodeParams) {
    LINFO("Hijacking %s", "cuGraphAddExternalSemaphoresSignalNode");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddExternalSemaphoresSignalNode, phGraphNode, hGraph, dependencies, numDependencies, nodeParams);
}
CUresult cuGraphAddExternalSemaphoresWaitNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, const CUDA_EXT_SEM_WAIT_NODE_PARAMS *nodeParams) {
    LINFO("Hijacking %s", "cuGraphAddExternalSemaphoresWaitNode");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddExternalSemaphoresWaitNode, phGraphNode, hGraph, dependencies, numDependencies, nodeParams);
}
CUresult cuGraphAddHostNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, const CUDA_HOST_NODE_PARAMS *nodeParams) {
    LINFO("Hijacking %s", "cuGraphAddHostNode");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddHostNode, phGraphNode, hGraph, dependencies, numDependencies, nodeParams);
}
CUresult cuGraphAddKernelNode_v2(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, const void *nodeParams) {
    LINFO("Hijacking %s", "cuGraphAddKernelNode_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddKernelNode_v2, phGraphNode, hGraph, dependencies, numDependencies, nodeParams);
}
CUresult cuGraphAddMemcpyNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, const CUDA_MEMCPY3D *copyParams, CUcontext ctx) {
    LINFO("Hijacking %s", "cuGraphAddMemcpyNode");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddMemcpyNode, phGraphNode, hGraph, dependencies, numDependencies, copyParams, ctx);
}
CUresult cuGraphAddMemsetNode(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, const CUDA_MEMSET_NODE_PARAMS *memsetParams, CUcontext ctx) {
    LINFO("Hijacking %s", "cuGraphAddMemsetNode");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphAddMemsetNode, phGraphNode, hGraph, dependencies, numDependencies, memsetParams, ctx);
}
CUresult cuGraphChildGraphNodeGetGraph(CUgraphNode hNode, CUgraph *phGraph) {
    LINFO("Hijacking %s", "cuGraphChildGraphNodeGetGraph");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphChildGraphNodeGetGraph, hNode, phGraph);
}
CUresult cuGraphClone(CUgraph *phGraphClone, CUgraph originalGraph) {
    LINFO("Hijacking %s", "cuGraphClone");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphClone, phGraphClone, originalGraph);
}
CUresult cuGraphCreate(CUgraph *phGraph, unsigned int flags) {
    LINFO("Hijacking %s", "cuGraphCreate");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphCreate, phGraph, flags);
}
CUresult cuGraphDestroy(CUgraph hGraph) {
    LINFO("Hijacking %s", "cuGraphDestroy");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphDestroy, hGraph);
}
CUresult cuGraphDestroyNode(CUgraphNode hNode) {
    LINFO("Hijacking %s", "cuGraphDestroyNode");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphDestroyNode, hNode);
}
CUresult cuGraphEventRecordNodeGetEvent(CUgraphNode hNode, CUevent *event_out) {
    LINFO("Hijacking %s", "cuGraphEventRecordNodeGetEvent");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphEventRecordNodeGetEvent, hNode, event_out);
}
CUresult cuGraphEventRecordNodeSetEvent(CUgraphNode hNode, CUevent event) {
    LINFO("Hijacking %s", "cuGraphEventRecordNodeSetEvent");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphEventRecordNodeSetEvent, hNode, event);
}
CUresult cuGraphEventWaitNodeGetEvent(CUgraphNode hNode, CUevent *event_out) {
    LINFO("Hijacking %s", "cuGraphEventWaitNodeGetEvent");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphEventWaitNodeGetEvent, hNode, event_out);
}
CUresult cuGraphEventWaitNodeSetEvent(CUgraphNode hNode, CUevent event) {
    LINFO("Hijacking %s", "cuGraphEventWaitNodeSetEvent");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphEventWaitNodeSetEvent, hNode, event);
}
CUresult cuGraphExecDestroy(CUgraphExec hGraphExec) {
    LINFO("Hijacking %s", "cuGraphExecDestroy");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecDestroy, hGraphExec);
}
CUresult cuGraphExecExternalSemaphoresSignalNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, const CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *nodeParams) {
    LINFO("Hijacking %s", "cuGraphExecExternalSemaphoresSignalNodeSetParams");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecExternalSemaphoresSignalNodeSetParams, hGraphExec, hNode, nodeParams);
}
CUresult cuGraphExecExternalSemaphoresWaitNodeSetParams(CUgraphExec hGraphExec, CUgraphNode hNode, const CUDA_EXT_SEM_WAIT_NODE_PARAMS *nodeParams) {
    LINFO("Hijacking %s", "cuGraphExecExternalSemaphoresWaitNodeSetParams");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExecExternalSemaphoresWaitNodeSetParams, hGraphExec, hNode, nodeParams);
}
CUresult cuGraphExternalSemaphoresSignalNodeGetParams(CUgraphNode hNode, CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *params_out) {
    LINFO("Hijacking %s", "cuGraphExternalSemaphoresSignalNodeGetParams");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExternalSemaphoresSignalNodeGetParams, hNode, params_out);
}
CUresult cuGraphExternalSemaphoresSignalNodeSetParams(CUgraphNode hNode, const CUDA_EXT_SEM_SIGNAL_NODE_PARAMS *nodeParams) {
    LINFO("Hijacking %s", "cuGraphExternalSemaphoresSignalNodeSetParams");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExternalSemaphoresSignalNodeSetParams, hNode, nodeParams);
}
CUresult cuGraphExternalSemaphoresWaitNodeGetParams(CUgraphNode hNode, CUDA_EXT_SEM_WAIT_NODE_PARAMS *params_out) {
    LINFO("Hijacking %s", "cuGraphExternalSemaphoresWaitNodeGetParams");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExternalSemaphoresWaitNodeGetParams, hNode, params_out);
}
CUresult cuGraphExternalSemaphoresWaitNodeSetParams(CUgraphNode hNode, const CUDA_EXT_SEM_WAIT_NODE_PARAMS *nodeParams) {
    LINFO("Hijacking %s", "cuGraphExternalSemaphoresWaitNodeSetParams");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphExternalSemaphoresWaitNodeSetParams, hNode, nodeParams);
}
CUresult cuGraphGetEdges(CUgraph hGraph, CUgraphNode *from, CUgraphNode *to, size_t *numEdges) {
    LINFO("Hijacking %s", "cuGraphGetEdges");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphGetEdges, hGraph, from, to, numEdges);
}
CUresult cuGraphGetNodes(CUgraph hGraph, CUgraphNode *nodes, size_t *numNodes) {
    LINFO("Hijacking %s", "cuGraphGetNodes");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphGetNodes, hGraph, nodes, numNodes);
}
CUresult cuGraphGetRootNodes(CUgraph hGraph, CUgraphNode *rootNodes, size_t *numRootNodes) {
    LINFO("Hijacking %s", "cuGraphGetRootNodes");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphGetRootNodes, hGraph, rootNodes, numRootNodes);
}
CUresult cuGraphHostNodeGetParams(CUgraphNode hNode, CUDA_HOST_NODE_PARAMS *nodeParams) {
    LINFO("Hijacking %s", "cuGraphHostNodeGetParams");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphHostNodeGetParams, hNode, nodeParams);
}
CUresult cuGraphHostNodeSetParams(CUgraphNode hNode, const CUDA_HOST_NODE_PARAMS *nodeParams) {
    LINFO("Hijacking %s", "cuGraphHostNodeSetParams");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphHostNodeSetParams, hNode, nodeParams);
}
CUresult cuGraphInstantiate(CUgraphExec *phGraphExec, CUgraph hGraph, CUgraphNode *phErrorNode, char *logBuffer, size_t bufferSize) {
    LINFO("Hijacking %s", "cuGraphInstantiate");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphInstantiate, phGraphExec, hGraph, phErrorNode, logBuffer, bufferSize);
}
CUresult cuGraphInstantiateWithFlags(CUgraphExec *phGraphExec, CUgraph hGraph, unsigned long long flags) {
    LINFO("Hijacking %s", "cuGraphInstantiateWithFlags");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphInstantiateWithFlags, phGraphExec, hGraph, flags);
}
CUresult cuGraphKernelNodeGetParams_v2(CUgraphNode hNode, void *nodeParams) {
    LINFO("Hijacking %s", "cuGraphKernelNodeGetParams_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphKernelNodeGetParams_v2, hNode, nodeParams);
}
CUresult cuGraphKernelNodeSetParams_v2(CUgraphNode hNode, const void *nodeParams) {
    LINFO("Hijacking %s", "cuGraphKernelNodeSetParams_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphKernelNodeSetParams_v2, hNode, nodeParams);
}
CUresult cuGraphLaunch(CUgraphExec hGraphExec, CUstream hStream) {
    LINFO("Hijacking %s", "cuGraphLaunch");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphLaunch, hGraphExec, hStream);
}
CUresult cuGraphMemcpyNodeGetParams(CUgraphNode hNode, CUDA_MEMCPY3D *nodeParams) {
    LINFO("Hijacking %s", "cuGraphMemcpyNodeGetParams");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphMemcpyNodeGetParams, hNode, nodeParams);
}
CUresult cuGraphMemcpyNodeSetParams(CUgraphNode hNode, const CUDA_MEMCPY3D *nodeParams) {
    LINFO("Hijacking %s", "cuGraphMemcpyNodeSetParams");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphMemcpyNodeSetParams, hNode, nodeParams);
}
CUresult cuGraphMemsetNodeGetParams(CUgraphNode hNode, CUDA_MEMSET_NODE_PARAMS *nodeParams) {
    LINFO("Hijacking %s", "cuGraphMemsetNodeGetParams");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphMemsetNodeGetParams, hNode, nodeParams);
}
CUresult cuGraphMemsetNodeSetParams(CUgraphNode hNode, const CUDA_MEMSET_NODE_PARAMS *nodeParams) {
    LINFO("Hijacking %s", "cuGraphMemsetNodeSetParams");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphMemsetNodeSetParams, hNode, nodeParams);
}
CUresult cuGraphNodeFindInClone(CUgraphNode *phNode, CUgraphNode hOriginalNode, CUgraph hClonedGraph) {
    LINFO("Hijacking %s", "cuGraphNodeFindInClone");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphNodeFindInClone, phNode, hOriginalNode, hClonedGraph);
}
CUresult cuGraphNodeGetDependencies(CUgraphNode hNode, CUgraphNode *dependencies, size_t *numDependencies) {
    LINFO("Hijacking %s", "cuGraphNodeGetDependencies");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphNodeGetDependencies, hNode, dependencies, numDependencies);
}
CUresult cuGraphNodeGetDependentNodes(CUgraphNode hNode, CUgraphNode *dependentNodes, size_t *numDependentNodes) {
    LINFO("Hijacking %s", "cuGraphNodeGetDependentNodes");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphNodeGetDependentNodes, hNode, dependentNodes, numDependentNodes);
}
CUresult cuGraphNodeGetType(CUgraphNode hNode, CUgraphNodeType *type) {
    LINFO("Hijacking %s", "cuGraphNodeGetType");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphNodeGetType, hNode, type);
}
CUresult cuGraphRemoveDependencies(CUgraph hGraph, const CUgraphNode *from, const CUgraphNode *to, size_t numDependencies) {
    LINFO("Hijacking %s", "cuGraphRemoveDependencies");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphRemoveDependencies, hGraph, from, to, numDependencies);
}
CUresult cuGraphUpload(CUgraphExec hGraphExec, CUstream hStream) {
    LINFO("Hijacking %s", "cuGraphUpload");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGraphUpload, hGraphExec, hStream);
}
CUresult cuImportExternalMemory(CUexternalMemory *extMem_out, const CUDA_EXTERNAL_MEMORY_HANDLE_DESC *memHandleDesc) {
    LINFO("Hijacking %s", "cuImportExternalMemory");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuImportExternalMemory, extMem_out, memHandleDesc);
}
CUresult cuImportExternalSemaphore(CUexternalSemaphore *extSem_out, const CUDA_EXTERNAL_SEMAPHORE_HANDLE_DESC *semHandleDesc) {
    LINFO("Hijacking %s", "cuImportExternalSemaphore");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuImportExternalSemaphore, extSem_out, semHandleDesc);
}
CUresult cuLaunchKernelEx(const CUlaunchConfig *config, CUfunction f, void **kernelParams, void **extra) {
    LINFO("Hijacking %s", "cuLaunchKernelEx");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLaunchKernelEx, config, f, kernelParams, extra);
}
CUresult cuLinkAddData_v2(CUlinkState state, CUjitInputType type, void *data, size_t size, const char *name, unsigned int numOptions, CUjit_option *options, void **optionValues) {
    LINFO("Hijacking %s", "cuLinkAddData_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLinkAddData_v2, state, type, data, size, name, numOptions, options, optionValues);
}
CUresult cuLinkAddFile_v2(CUlinkState state, CUjitInputType type, const char *path, unsigned int numOptions, CUjit_option *options, void **optionValues) {
    LINFO("Hijacking %s", "cuLinkAddFile_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLinkAddFile_v2, state, type, path, numOptions, options, optionValues);
}
CUresult cuLinkComplete(CUlinkState state, void **cubinOut, size_t *sizeOut) {
    LINFO("Hijacking %s", "cuLinkComplete");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLinkComplete, state, cubinOut, sizeOut);
}
CUresult cuLinkCreate_v2(unsigned int numOptions, CUjit_option *options, void **optionValues, CUlinkState *stateOut) {
    LINFO("Hijacking %s", "cuLinkCreate_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLinkCreate_v2, numOptions, options, optionValues, stateOut);
}
CUresult cuLinkDestroy(CUlinkState state) {
    LINFO("Hijacking %s", "cuLinkDestroy");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLinkDestroy, state);
}
CUresult cuMemAllocAsync(CUdeviceptr *dptr, size_t bytesize, CUstream hStream) {
    LINFO("Hijacking %s", "cuMemAllocAsync");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemAllocAsync, dptr, bytesize, hStream);
}
CUresult cuMemAllocFromPoolAsync(CUdeviceptr *dptr, size_t bytesize, CUmemoryPool pool, CUstream hStream) {
    LINFO("Hijacking %s", "cuMemAllocFromPoolAsync");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemAllocFromPoolAsync, dptr, bytesize, pool, hStream);
}
CUresult cuMemCreate(CUmemGenericAllocationHandle *handle, size_t size, const CUmemAllocationProp *prop, unsigned long long flags) {
    LINFO("Hijacking %s", "cuMemCreate");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemCreate, handle, size, prop, flags);
}
CUresult cuMemFreeHost(void *p) {
    LINFO("Hijacking %s", "cuMemFreeHost");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemFreeHost, p);
}
CUresult cuMemGetAllocationGranularity(size_t *granularity, const CUmemAllocationProp *prop, CUmemAllocationGranularity_flags option) {
    LINFO("Hijacking %s", "cuMemGetAllocationGranularity");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemGetAllocationGranularity, granularity, prop, option);
}
CUresult cuMemHostGetDevicePointer_v2(CUdeviceptr *pdptr, void *p, unsigned int Flags) {
    LINFO("Hijacking %s", "cuMemHostGetDevicePointer_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemHostGetDevicePointer_v2, pdptr, p, Flags);
}
CUresult cuMemHostGetFlags(unsigned int *pFlags, void *p) {
    LINFO("Hijacking %s", "cuMemHostGetFlags");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemHostGetFlags, pFlags, p);
}
CUresult cuMemPoolCreate(CUmemoryPool *pool, const CUmemPoolProps *poolProps) {
    LINFO("Hijacking %s", "cuMemPoolCreate");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolCreate, pool, poolProps);
}
CUresult cuMemPoolDestroy(CUmemoryPool pool) {
    LINFO("Hijacking %s", "cuMemPoolDestroy");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolDestroy, pool);
}
CUresult cuMemPoolExportPointer(CUmemPoolPtrExportData *shareData_out, CUdeviceptr ptr) {
    LINFO("Hijacking %s", "cuMemPoolExportPointer");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolExportPointer, shareData_out, ptr);
}
CUresult cuMemPoolExportToShareableHandle(void *handle_out, CUmemoryPool pool, CUmemAllocationHandleType handleType, unsigned long long flags) {
    LINFO("Hijacking %s", "cuMemPoolExportToShareableHandle");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolExportToShareableHandle, handle_out, pool, handleType, flags);
}
CUresult cuMemPoolGetAccess(CUmemAccess_flags *flags, CUmemoryPool memPool, CUmemLocation *location) {
    LINFO("Hijacking %s", "cuMemPoolGetAccess");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolGetAccess, flags, memPool, location);
}
CUresult cuMemPoolGetAttribute(CUmemoryPool pool, CUmemPool_attribute attr, void *value) {
    LINFO("Hijacking %s", "cuMemPoolGetAttribute");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolGetAttribute, pool, attr, value);
}
CUresult cuMemPoolImportFromShareableHandle(CUmemoryPool *pool_out, void *handle, CUmemAllocationHandleType handleType, unsigned long long flags) {
    LINFO("Hijacking %s", "cuMemPoolImportFromShareableHandle");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolImportFromShareableHandle, pool_out, handle, handleType, flags);
}
CUresult cuMemPoolImportPointer(CUdeviceptr *ptr_out, CUmemoryPool pool, CUmemPoolPtrExportData *shareData) {
    LINFO("Hijacking %s", "cuMemPoolImportPointer");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolImportPointer, ptr_out, pool, shareData);
}
CUresult cuMemPoolSetAccess(CUmemoryPool pool, const CUmemAccessDesc *map, size_t count) {
    LINFO("Hijacking %s", "cuMemPoolSetAccess");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolSetAccess, pool, map, count);
}
CUresult cuMemPoolSetAttribute(CUmemoryPool pool, CUmemPool_attribute attr, void *value) {
    LINFO("Hijacking %s", "cuMemPoolSetAttribute");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolSetAttribute, pool, attr, value);
}
CUresult cuMemPoolTrimTo(CUmemoryPool pool, size_t minBytesToKeep) {
    LINFO("Hijacking %s", "cuMemPoolTrimTo");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPoolTrimTo, pool, minBytesToKeep);
}
CUresult cuMemPrefetchAsync(CUdeviceptr devPtr, size_t count, CUdevice dstDevice, CUstream hStream) {
    LINFO("Hijacking %s", "cuMemPrefetchAsync");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemPrefetchAsync, devPtr, count, dstDevice, hStream);
}
CUresult cuMemRangeGetAttribute(void *data, size_t dataSize, CUmem_range_attribute attribute, CUdeviceptr devPtr, size_t count) {
    LINFO("Hijacking %s", "cuMemRangeGetAttribute");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemRangeGetAttribute, data, dataSize, attribute, devPtr, count);
}
CUresult cuMemRangeGetAttributes(void **data, size_t *dataSizes, CUmem_range_attribute *attributes, size_t numAttributes, CUdeviceptr devPtr, size_t count) {
    LINFO("Hijacking %s", "cuMemRangeGetAttributes");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemRangeGetAttributes, data, dataSizes, attributes, numAttributes, devPtr, count);
}
CUresult cuMemcpy2DAsync_v2(const CUDA_MEMCPY2D *pCopy, CUstream hStream) {
    LINFO("Hijacking %s", "cuMemcpy2DAsync_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy2DAsync_v2, pCopy, hStream);
}
CUresult cuMemcpy2DUnaligned_v2(const CUDA_MEMCPY2D *pCopy) {
    LINFO("Hijacking %s", "cuMemcpy2DUnaligned_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy2DUnaligned_v2, pCopy);
}
CUresult cuMemcpy3DAsync_v2(const CUDA_MEMCPY3D *pCopy, CUstream hStream) {
    LINFO("Hijacking %s", "cuMemcpy3DAsync_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy3DAsync_v2, pCopy, hStream);
}
CUresult cuMemcpy3DPeer(const CUDA_MEMCPY3D_PEER *pCopy) {
    LINFO("Hijacking %s", "cuMemcpy3DPeer");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy3DPeer, pCopy);
}
CUresult cuMemcpy3DPeerAsync(const CUDA_MEMCPY3D_PEER *pCopy, CUstream hStream) {
    LINFO("Hijacking %s", "cuMemcpy3DPeerAsync");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy3DPeerAsync, pCopy, hStream);
}
CUresult cuMemcpy3D_v2(const CUDA_MEMCPY3D *pCopy) {
    LINFO("Hijacking %s", "cuMemcpy3D_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy3D_v2, pCopy);
}
CUresult cuMipmappedArrayDestroy(CUmipmappedArray hMipmappedArray) {
    LINFO("Hijacking %s", "cuMipmappedArrayDestroy");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMipmappedArrayDestroy, hMipmappedArray);
}
CUresult cuModuleGetFunction(CUfunction *hfunc, CUmodule hmod, const char *name) {
    LINFO("Hijacking %s", "cuModuleGetFunction");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleGetFunction, hfunc, hmod, name);
}
CUresult cuModuleGetGlobal_v2(CUdeviceptr *dptr, size_t *bytes, CUmodule hmod, const char *name) {
    LINFO("Hijacking %s", "cuModuleGetGlobal_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleGetGlobal_v2, dptr, bytes, hmod, name);
}
CUresult cuModuleGetLoadingMode(CUmoduleLoadingMode *mode) {
    LINFO("Hijacking %s", "cuModuleGetLoadingMode");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleGetLoadingMode, mode);
}
CUresult cuModuleGetSurfRef(CUsurfref *pSurfRef, CUmodule hmod, const char *name) {
    LINFO("Hijacking %s", "cuModuleGetSurfRef");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleGetSurfRef, pSurfRef, hmod, name);
}
CUresult cuModuleGetTexRef(CUtexref *pTexRef, CUmodule hmod, const char *name) {
    LINFO("Hijacking %s", "cuModuleGetTexRef");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleGetTexRef, pTexRef, hmod, name);
}
CUresult cuModuleLoad(CUmodule *module, const char *fname) {
    LINFO("Hijacking %s", "cuModuleLoad");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleLoad, module, fname);
}
CUresult cuModuleLoadData(CUmodule *module, const void *image) {
    LINFO("Hijacking %s", "cuModuleLoadData");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleLoadData, module, image);
}
CUresult cuModuleLoadDataEx(CUmodule *module, const void *image, unsigned int numOptions, CUjit_option *options, void **optionValues) {
    LINFO("Hijacking %s", "cuModuleLoadDataEx");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleLoadDataEx, module, image, numOptions, options, optionValues);
}
CUresult cuModuleLoadFatBinary(CUmodule *module, const void *fatCubin) {
    LINFO("Hijacking %s", "cuModuleLoadFatBinary");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleLoadFatBinary, module, fatCubin);
}
CUresult cuModuleUnload(CUmodule hmod) {
    LINFO("Hijacking %s", "cuModuleUnload");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuModuleUnload, hmod);
}
CUresult cuOccupancyMaxActiveBlocksPerMultiprocessor(int *numBlocks, CUfunction func, int blockSize, size_t dynamicSMemSize) {
    LINFO("Hijacking %s", "cuOccupancyMaxActiveBlocksPerMultiprocessor");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuOccupancyMaxActiveBlocksPerMultiprocessor, numBlocks, func, blockSize, dynamicSMemSize);
}
CUresult cuSignalExternalSemaphoresAsync(const CUexternalSemaphore *extSemArray, const CUDA_EXTERNAL_SEMAPHORE_SIGNAL_PARAMS *paramsArray, unsigned int numExtSems, CUstream stream) {
    LINFO("Hijacking %s", "cuSignalExternalSemaphoresAsync");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuSignalExternalSemaphoresAsync, extSemArray, paramsArray, numExtSems, stream);
}
CUresult cuStreamCreate(CUstream *phStream, unsigned int Flags) {
    LINFO("Hijacking %s", "cuStreamCreate");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamCreate, phStream, Flags);
}
CUresult cuStreamDestroy_v2(CUstream hStream) {
    LINFO("Hijacking %s", "cuStreamDestroy_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamDestroy_v2, hStream);
}
CUresult cuStreamSynchronize(CUstream hStream) {
    LINFO("Hijacking %s", "cuStreamSynchronize");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuStreamSynchronize, hStream);
}
CUresult cuWaitExternalSemaphoresAsync(const CUexternalSemaphore *extSemArray, const CUDA_EXTERNAL_SEMAPHORE_WAIT_PARAMS *paramsArray, unsigned int numExtSems, CUstream stream) {
    LINFO("Hijacking %s", "cuWaitExternalSemaphoresAsync");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuWaitExternalSemaphoresAsync, extSemArray, paramsArray, numExtSems, stream);
}