#include <pthread.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "include/base.h"
#include "include/cuda-helper.h"
#include "include/func.h"

extern unsigned int virtual_devices[17];
extern void *cuda_library_entry[];
extern pthread_mutex_t mutex;
extern size_t **device_overallocated[3];
extern unsigned int record_cuda_map[17];
extern sharedRegionT *flags;

int64_t oom_check(int devIndex, size_t bytesize) {
    CUdevice dev;
    int deviceCount;
    LINFO("Hijacking %s", "cuDeviceGetCount");
    CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetCount, &deviceCount);

    if (deviceCount != virtual_devices[0])
        return 0LL;
    unsigned int deviceQuery = 0;
    if (devIndex == -1)
        cuCtxGetDevice(&dev);
    else
        deviceQuery = devIndex;
    u_int64_t current_device_memory_limit = get_current_device_memory_limit(deviceQuery);
    u_int64_t gpu_memory_usage = get_gpu_memory_usage(deviceQuery);
    if (!current_device_memory_limit)
        return 0LL;
    u_int64_t v20 = gpu_memory_usage + bytesize;
    LINFO("_usage=%lu limit=%lu new_allocated=%lu", gpu_memory_usage, current_device_memory_limit);
    if (v20 <= current_device_memory_limit)
        return 0LL;

    LERROR("Device %d OOM %lu / %lu", v20, current_device_memory_limit);

    if ((int)rm_quitted_process() <= 0)
        return 1LL;
    else
        return oom_check(devIndex, bytesize);
}

size_t add_chunk_only(size_t dptr, size_t bytesize) {
    size_t v16[4];
    CUdevice dev;
    pthread_mutex_lock(&mutex);
    CUcontext cut;
    cuCtxGetDevice(&dev);
    if (oom_check(dev, bytesize)) {
        pthread_mutex_unlock(&mutex);
        return 0xFFFFFFFFLL;
    }
    else if ((unsigned int)cuCtxGetCurrent(&cut)) {
        LERROR("cuCtxGetCurrent failed");
        return 0xFFFFFFFFLL;
    }
    else {
        device_overallocated[1] = (void *)v16[0];
        device_overallocated[2] = (void *)v16[0];
        if (**device_overallocated[0] != 0) {
            ++device_overallocated[2];
        }
        else {
            **device_overallocated[2] = 1;
        }
        *v16[0] = (void *)dptr;
        cuCtxGetDevice(&dev);
        add_gpu_device_memory_usage(getpid(), dev, bytesize, 2);
        pthread_mutex_unlock(&mutex);
        return 0LL;
    }
}

size_t remove_chunk(size_t *doa, size_t bytesize) {
    int v3;          // ebx
    unsigned int v4; // eax
    int v5;          // [rsp+14h] [rbp-2Ch] BYREF
    size_t *ptr;     // [rsp+18h] [rbp-28h]

    if (doa[2])
        return 0xFFFFFFFFLL;
    for (ptr = doa;; ptr += sizeof(size_t)) {
        if (ptr == 0)
            return 0xFFFFFFFFLL;
        if (bytesize == **(size_t **)ptr)
            break;
    }

    cuMemoryFree(ptr, bytesize);
    if (ptr[2]) {
        ptr[3] = ptr[1];
    }
    if (ptr[1]) {
        ptr[3] = ptr[2];
        ptr[1] = ptr[2];
    }
    if (ptr[0]) {
        ptr[0] = ptr[1];
    }

    free((void *)ptr[3]);
    free((void *)ptr[0]);
    free(ptr);
    --doa[2];
    CUdevice dev;
    cuCtxGetDevice(&dev);
    rm_gpu_device_memory_usage(getpid(), dev, *(size_t *)ptr[1], 2);
    return 0LL;
}

size_t free_raw(size_t bytesize) {
    pthread_mutex_lock(&mutex);
    unsigned int v2 = remove_chunk(*device_overallocated[0], bytesize);
    pthread_mutex_unlock(&mutex);
    return v2;
}

int allocator_init() {
    LINFO("Allocator_init");
    device_overallocated[0] = 0LL;
    device_overallocated[1] = 0LL;
    device_overallocated[2] = 0LL;
    return pthread_mutex_init(&mutex, 0LL);
}

size_t view_vgpu_allocator() {
    size_t total = 0LL;
    LINFO("[view1]:overallocated:");
    for (int i = 0; i < 3; i++) {
        LINFO("(%p %lu)", **device_overallocated[i], **device_overallocated[i + 1]);
        total += **device_overallocated[i];
    }

    LINFO("total=%lu", total);
    u_int64_t current_device_memory_usage = get_current_device_memory_usage(0);
    LINFO("current_device_memory_usage:%lu", current_device_memory_usage);
    return 0LL;
}
