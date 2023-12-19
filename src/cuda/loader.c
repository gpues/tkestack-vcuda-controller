#include <pthread.h>
#include <semaphore.h>
#include <stddef.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "include/base.h"
#include "include/func.h"

extern void *cuda_library_entry[];
extern sharedRegionT *flags;
extern u_int64_t *initial_offset;
extern u_int64_t *in_fs_offset;

static pthread_once_t g_init_set = PTHREAD_ONCE_INIT;
extern int64_t **device_overallocated[3];
extern size_t *cuarray_format_bytes;

size_t compute_array_alloc_bytes(const CUDA_ARRAY_DESCRIPTOR *pAllocateArray) {
    if (pAllocateArray) {
        LINFO("compute_array_alloc_bytes height=%ld width=%ld", pAllocateArray->Height, pAllocateArray->Width);
    }
    else {
        LINFO("compute_array_alloc_bytes desc is null");
    }
    size_t res = pAllocateArray->Width * pAllocateArray->Format;
    if (pAllocateArray->Height) {
        res *= pAllocateArray->Height;
    }

    return res * cuarray_format_bytes[pAllocateArray->NumChannels];
}
size_t compute_3d_array_alloc_bytes(const CUDA_ARRAY3D_DESCRIPTOR *pAllocateArray) {
    if (pAllocateArray) {
        LINFO("compute_3d_array_alloc_bytes height=%ld width=%ld", pAllocateArray->Height, pAllocateArray->Width);
    }
    else {
        LINFO("compute_3d_array_alloc_bytes desc is null");
    }
    size_t res = pAllocateArray->Width * pAllocateArray->Format;
    if (pAllocateArray->Height) {
        res *= pAllocateArray->Height;
    }
    if (pAllocateArray->Depth) {
        res *= pAllocateArray->Depth;
    }
    return res * cuarray_format_bytes[pAllocateArray->NumChannels];
}

int64_t check_memory_type(CUdeviceptr ptr) {
    int64_t cPtr = **device_overallocated[0];
    while (true) {
        if (cPtr == 0) {
            return 1;
        }
        if ((**(uint64_t **)cPtr <= (uint64_t)ptr) && ((uint64_t)ptr <= (uint64_t)(*(int64_t *)(*(int64_t *)cPtr + 8) + **(int64_t **)cPtr)))
            break;
        cPtr = *(int64_t *)(cPtr + 8);
    }
    return 2;
}

void ensure_initialized() {
    pthread_once(&g_init_set, initialization);
}
