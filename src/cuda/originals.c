#include "include/cuda-helper.h"
#include "include/cuda.h"
#include "src/var.h"
CUresult cuArray3DGetDescriptor_v2(CUDA_ARRAY3D_DESCRIPTOR *pArrayDescriptor, CUarray hArray) {
    return CUDA_ENTRY_CALL(cuda_library_entry, cuArray3DGetDescriptor_v2, pArrayDescriptor, hArray);
}