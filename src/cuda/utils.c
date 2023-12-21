#include "include/all.h"

extern pthread_mutex_t mutex;
extern int64_t **device_overallocated[3];
extern void *cuda_library_entry[];
extern size_t IPCSIZE;

size_t add_chunk(size_t *dptr, size_t bytesize) {
    int64_t v24[4];
    CUdevice dev;
    CUcontext pctx;
    CUresult res;
    cuCtxGetDevice(&dev);
    if (oom_check(dev, bytesize))
        return 0xFFFFFFFFLL;
    if (cuCtxGetCurrent(&pctx)) {
        LERROR("cuCtxGetCurrent failed");
        return 0xFFFFFFFFLL;
    }
    else {
        if (bytesize > IPCSIZE) {
            (*v24)[1] = bytesize;
            res = cuMemoryAllocate((CUdeviceptr *)v24[0], bytesize, (CUmemAccessDesc *)v24[1], (CUmemGenericAllocationHandle *)v24[3]);
        }
        else {
            LINFO("Hijacking cuMemAlloc_v2");
            res = CUDA_ENTRY_CALL(cuda_library_entry, cuMemAlloc_v2, v24, bytesize);
        }
        if (res) {
            LERROR("cuMemoryAllocate failed res=%d", res);
            return res;
        }
        else {
            if (*device_overallocated) {
                v24[2] = (int64_t) * (int64_t **)device_overallocated[1];
                **device_overallocated[2] = v24[0];
                *device_overallocated[1] = v24[0];
                ++*device_overallocated[2];
            }
            else {
                *device_overallocated = v24[0];
                **device_overallocated[2] = 1;
                **device_overallocated[1] = v24[0];
            }
            *dptr = v24[0];
            cuCtxGetDevice(&dev);
            add_gpu_device_memory_usage(getpid(), dev, bytesize, 2);
            return 0LL;
        }
    }
}

size_t allocate_raw(size_t *dptr, size_t bytesize) {
    pthread_mutex_lock(&mutex);
    unsigned int res = add_chunk(dptr, bytesize);
    pthread_mutex_unlock(&mutex);
    return res;
}
