#include "include/all.h"

extern void *cuda_library_entry[1024];
extern sharedRegionT *global_config;
extern u_int64_t *initial_offset;

extern pthread_once_t g_init_set;
extern size_t **device_overallocated[3];
extern size_t *cuarray_format_bytes;

size_t compute_array_alloc_bytes(const CUDA_ARRAY_DESCRIPTOR *pAllocateArray) {
    printf("%s %s", __FILE__, __LINE__);
    printf("%s %s", __FILE__, __LINE__);
    if (pAllocateArray) {
        printf("%s %s", __FILE__, __LINE__);
        LINFO("compute_array_alloc_bytes height=%ld width=%ld", pAllocateArray->Height, pAllocateArray->Width);
    }
    else {
        printf("%s %s", __FILE__, __LINE__);
        LINFO("compute_array_alloc_bytes desc is null");
        return 0;
    }
    size_t res = pAllocateArray->Width * pAllocateArray->Format;
    if (pAllocateArray->Height) {
        printf("%s %s", __FILE__, __LINE__);
        res *= pAllocateArray->Height;
    }

    return res * cuarray_format_bytes[pAllocateArray->NumChannels];
}
size_t compute_3d_array_alloc_bytes(const CUDA_ARRAY3D_DESCRIPTOR *pAllocateArray) {
    printf("%s %s", __FILE__, __LINE__);
    if (pAllocateArray) {
        printf("%s %s", __FILE__, __LINE__);
        LINFO("compute_3d_array_alloc_bytes height=%ld width=%ld", pAllocateArray->Height, pAllocateArray->Width);
    }
    else {
        printf("%s %s", __FILE__, __LINE__);
        LINFO("compute_3d_array_alloc_bytes desc is null");
        return 0;
    }
    size_t res = pAllocateArray->Width * pAllocateArray->Format;
    if (pAllocateArray->Height) {
        printf("%s %s", __FILE__, __LINE__);
        res *= pAllocateArray->Height;
    }
    if (pAllocateArray->Depth) {
        printf("%s %s", __FILE__, __LINE__);
        res *= pAllocateArray->Depth;
    }
    return res * cuarray_format_bytes[pAllocateArray->NumChannels];
}

// device_overallocated [
//  0,----->  [0,1,2,3 ->malloc(8) ]
//  1,
//  2
// ]
int64_t check_memory_type(CUdeviceptr ptr) {
    printf("%s %s", __FILE__, __LINE__);
    size_t *i = (size_t *)*device_overallocated;
    for (; i; i = (size_t *)i[1]) {
        printf("%s %s", __FILE__, __LINE__);
        if (ptr >= *(size_t *)*i && ptr <= *(size_t *)*i + *(size_t *)(*i + 8LL))
            return 2LL;
    }
    return 1LL;
}

void ensure_initialized() {
    printf("%s %s", __FILE__, __LINE__);
    pthread_once(&g_init_set, initialized);
}
