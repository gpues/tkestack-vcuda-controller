#include "include/all.h"

extern unsigned int virtual_devices[17];
extern void *cuda_library_entry[1024];
extern pthread_mutex_t mutex;
extern size_t *device_overallocated[3];
extern unsigned int record_cuda_map[16];
extern sharedRegionT *global_config;

int64_t oom_check(int devIndex, size_t bytesize) {
    LINFO("%s", "----");
    LINFO("%s", "----");
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

size_t add_chunk_only(CUdeviceptr dptr, size_t bytesize) {
    LINFO("%s", "----");
    LINFO("%s", "----");
    CUdevice dev;
    pthread_mutex_lock(&mutex);
    CUcontext cut;
    cuCtxGetDevice(&dev);
    if (oom_check(dev, bytesize)) {
        LINFO("%s", "----");
        pthread_mutex_unlock(&mutex);
        return 0xFFFFFFFFLL;
    }
    else if ((unsigned int)cuCtxGetCurrent(&cut)) {
        LINFO("%s", "----");
        LERROR("cuCtxGetCurrent failed");
        return 0xFFFFFFFFLL;
    }
    else {
        LINFO("%s", "----");
        size_t *ptrArray = malloc(8 * 3);
        // ptrArray [
        //  0,----->  [0,1,2,3 ->malloc(8) ]
        //  1,
        //  2
        // ]
        // device_overallocated [
        //  0,----->  [0,1,2,3 ->malloc(8) ]
        //  1,
        //  2
        // ]
        if (ptrArray && (*ptrArray = (size_t)(size_t *)malloc(8 * 4)) != 0) {
            LINFO("%s", "----");
            ((size_t *)(*(size_t *)(ptrArray[0])))[0] = 0;
            ((size_t *)(*(size_t *)(ptrArray[0])))[1] = bytesize;
            ((size_t *)(*(size_t *)(ptrArray[0])))[3] = (size_t)malloc(8uLL);
            ((size_t *)(*(size_t *)(ptrArray[0])))[2] = dev;
            ptrArray[1] = 0LL;
            ptrArray[2] = 0LL;

            if (*device_overallocated) {
                LINFO("%s", "----");
                ptrArray[2] = *(size_t *)device_overallocated[1];
                ((size_t *)(*(size_t *)(ptrArray[1])))[1] = (size_t)ptrArray;
                *(size_t *)(device_overallocated[1]) = (size_t)ptrArray;
                ++*(size_t *)(device_overallocated[2]);
            }
            else {
                LINFO("%s", "----");
                *device_overallocated = ptrArray;
                *(size_t *)(device_overallocated[1]) = (size_t)ptrArray;
                *(size_t *)(device_overallocated[2]) = 1;
            }
            ((size_t *)(*(size_t *)(ptrArray[0])))[0] = dptr;
            cuCtxGetDevice(&dev);
            add_gpu_device_memory_usage(getpid(), dev, bytesize, 2);
            pthread_mutex_unlock(&mutex);
            return 0LL;
        }
        else {
            LINFO("%s", "----");
            LERROR("malloc failed");
            return 0xFFFFFFFFLL;
        }
    }
}

size_t remove_chunk(size_t *doa, size_t bytesize) {
    LINFO("%s", "----");
    size_t *ptr;

    if (doa[2])
        return 0xFFFFFFFFLL;
    for (ptr = doa;; ptr += sizeof(size_t)) {
        LINFO("%s", "----");
        if (ptr == 0)
            return 0xFFFFFFFFLL;
        if (bytesize == **(size_t **)ptr)
            break;
    }

    cuMemoryFree(ptr, bytesize);
    if (ptr[2]) {
        LINFO("%s", "----");
        ptr[3] = ptr[1];
    }
    if (ptr[1]) {
        LINFO("%s", "----");
        ptr[3] = ptr[2];
        ptr[1] = ptr[2];
    }
    if (ptr[0]) {
        LINFO("%s", "----");
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
    LINFO("%s", "----");
    pthread_mutex_lock(&mutex);
    unsigned int res = remove_chunk(*device_overallocated, bytesize);
    pthread_mutex_unlock(&mutex);
    return res;
}

int allocator_init() {
    LINFO("%s", "----");
    LINFO("Allocator_init");
    device_overallocated[0] = 0LL;
    device_overallocated[1] = 0LL;
    device_overallocated[2] = 0LL;
    return pthread_mutex_init(&mutex, 0LL);
}

size_t view_vgpu_allocator() {
    LINFO("%s", "----");
    size_t total = 0LL;
    LINFO("[view1]:overallocated:");
    for (int i = 0; i < 3; i++) {
        LINFO("%s", "----");
        LINFO("(%p %lu)", *(size_t *)*device_overallocated[i], *(size_t *)*device_overallocated[i + 1]);
        total += *(size_t *)*device_overallocated[i];
    }

    LINFO("total=%lu", total);
    u_int64_t current_device_memory_usage = get_current_device_memory_usage(0);
    LINFO("current_device_memory_usage:%lu", current_device_memory_usage);
    return 0LL;
}
