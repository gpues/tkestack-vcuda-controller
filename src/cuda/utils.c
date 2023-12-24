#include "include/all.h"

extern pthread_mutex_t mutex;
extern size_t *device_overallocated[3];
extern void *cuda_library_entry[1024];
extern size_t IPCSIZE;

size_t add_chunk(size_t *dptr, size_t bytesize) {
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
        size_t *ptrArray = malloc(8 * 3);
        if (ptrArray && (*ptrArray = (size_t)(size_t *)malloc(8 * 4)) != 0) {
            ((size_t *)(*(size_t *)(ptrArray[0])))[0] = 0;
            ((size_t *)(*(size_t *)(ptrArray[0])))[1] = bytesize;
            ((size_t *)(*(size_t *)(ptrArray[0])))[3] = (size_t)malloc(8uLL);
            ((size_t *)(*(size_t *)(ptrArray[0])))[2] = dev;
            ptrArray[1] = 0LL;
            ptrArray[2] = 0LL;
            if (bytesize > IPCSIZE) {
                ((size_t *)(*(size_t *)(ptrArray[0])))[1] = bytesize;

                res = cuMemoryAllocate((CUdeviceptr *)ptrArray[0], bytesize, (CUmemAccessDesc *)ptrArray[1], (CUmemGenericAllocationHandle *)((size_t *)(*(size_t *)(ptrArray[0])))[3]);
            }
            else {
                LINFO("Hijacking cuMemAlloc_v2");
                res = CUDA_ENTRY_CALL(cuda_library_entry, cuMemAlloc_v2, ptrArray, bytesize);
            }
            if (res) {
                LERROR("cuMemoryAllocate failed res=%d", res);
                return res;
            }
            else {
                if (*device_overallocated) {
                    ptrArray[2] = *(size_t *)device_overallocated[1];
                    ((size_t *)(*(size_t *)(ptrArray[1])))[1] = (size_t)ptrArray;
                    *(size_t *)(device_overallocated[1]) = (size_t)ptrArray;
                    ++*(size_t *)(device_overallocated[2]);
                }
                else {
                    *device_overallocated = (size_t *)ptrArray;
                    *(size_t *)(device_overallocated[1]) = (size_t)ptrArray;
                    *(size_t *)(device_overallocated[2]) = 1;
                }
                *dptr = *(size_t *)(*ptrArray);
                cuCtxGetDevice(&dev);
                add_gpu_device_memory_usage(getpid(), dev, bytesize, 2);
                return 0LL;
            }
        }
        else {
            LERROR("malloc failed");
            return 0xFFFFFFFFLL;
        }
    }
}

size_t allocate_raw(size_t *dptr, size_t bytesize) {
    pthread_mutex_lock(&mutex);
    unsigned int res = add_chunk(dptr, bytesize);
    pthread_mutex_unlock(&mutex);
    return res;
}

// docker run --rm -it -v /usr/local/vgpu/ld.so.preload:/etc/ld.so.preload -v /root/hook/test/libvgpu.so:/usr/local/vgpu/libvgpu.so centos:7 bash