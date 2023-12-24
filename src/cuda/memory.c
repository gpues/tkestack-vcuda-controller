#include "include/all.h"

extern void *cuda_library_entry[1024];
extern int pidfound;
extern int allocmode;
CUmemGenericAllocationHandle (*get_allochandle_from_dptr)(CUdeviceptr dptr);
void *getallochandle(const CUmemGenericAllocationHandle *handle, size_t bytesize, CUmemAccessDesc *desc);

int64_t check_oom() {
    printf("%s %s", __FILE__, __LINE__);
    CUdevice dev;
    CUdevice res = cuCtxGetDevice(&dev);
    if (!res) {
        printf("%s %s", __FILE__, __LINE__);
        return oom_check(0, dev);
    };
    LINFO("Driver error at %d: %d", __LINE__, res);
    return 1;
};

CUresult cuPointerSetAttribute(const void *value, CUpointer_attribute attribute, CUdeviceptr ptr) {
    printf("%s %s", __FILE__, __LINE__);
    LWARN("cuPointSetAttribue value=%p attribute=%d ptr=%llx", value, attribute, ptr);
    ensure_initialized();
    while (!wait_status_self(1LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LogAndWait(INFO, 1u, "");
    };
    LWARN("Hijacking %s", "cuPointerSetAttribute");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuPointerSetAttribute, value, attribute, ptr);
}
CUresult cuPointerGetAttribute(void *data, CUpointer_attribute attribute, CUdeviceptr ptr) {
    printf("%s %s", __FILE__, __LINE__);
    LWARN("cuPointGetAttribue data=%p attribute=%d ptr=%llx", data, attribute, ptr);
    ensure_initialized();
    while (!wait_status_self(1LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LogAndWait(INFO, 1u, "");
    };
    LWARN("Hijacking %s", "cuPointerGetAttribute");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuPointerGetAttribute, data, attribute, ptr);
}
CUresult cuPointerGetAttributes(unsigned int numAttributes, CUpointer_attribute *attributes, void **data, CUdeviceptr ptr) {
    printf("%s %s", __FILE__, __LINE__);
    LWARN("cuPointGetAttribue data=%p attribute=%d ptr=%llx", data, ptr);
    ensure_initialized();
    while (!wait_status_self(1LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LogAndWait(INFO, 1u, "");
    };
    LWARN("Hijacking %s", "cuPointerGetAttributes");
    CUresult res = CUDA_ENTRY_CALL(cuda_library_entry, cuPointerGetAttributes, numAttributes, attributes, data, ptr);
    for (unsigned int i = 0; numAttributes > i; ++i) {
        printf("%s %s", __FILE__, __LINE__);
        if (*(CUpointer_attribute *)(4LL * (int)i + attributes) == 2) {
            printf("%s %s", __FILE__, __LINE__);
            unsigned int r = check_memory_type(ptr);
            LWARN("check result = %d %d", r, *(void **)data[i]);
        }
        else if (*(CUpointer_attribute *)(4LL * (int)i + attributes) == 2) {
            printf("%s %s", __FILE__, __LINE__);
            *(void **)data[i] = 0;
        }
    }

    return res;
}
CUresult cuMemsetD2D32Async(CUdeviceptr dstDevice, size_t dstPitch, unsigned int ui, size_t Width, size_t Height, CUstream hStream) {
    printf("%s %s", __FILE__, __LINE__);
    ensure_initialized();
    while (!wait_status_self(1LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LogAndWait(INFO, 1u, "");
    };
    LWARN("cuMemsetD2D32Async");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D32Async, dstDevice, dstPitch, ui, Width, Height, hStream);
}
CUresult cuMemsetD32Async(CUdeviceptr dstDevice, unsigned int ui, size_t N, CUstream hStream) {
    printf("%s %s", __FILE__, __LINE__);
    ensure_initialized();
    while (!wait_status_self(1LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LogAndWait(INFO, 1u, "");
    };
    LWARN("cuMemsetD32Async");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD32Async, dstDevice, ui, N, hStream);
}
CUresult cuMipmappedArrayCreate(CUmipmappedArray *pHandle, const CUDA_ARRAY3D_DESCRIPTOR *pMipmappedArrayDesc, unsigned int numMipmapLevels) {
    printf("%s %s", __FILE__, __LINE__);
    LWARN("cuMipmappedArrayCreate");
    LWARN("Hijacking %s", "cuMipmappedArrayCreate");
    CUresult res = CUDA_ENTRY_CALL(cuda_library_entry, cuMipmappedArrayCreate, pHandle, pMipmappedArrayDesc, numMipmapLevels);
    if (res) {
        printf("%s %s", __FILE__, __LINE__);
        return res;
    }
    if (!check_oom()) {
        printf("%s %s", __FILE__, __LINE__);
        return CUDA_SUCCESS;
    }
    LWARN("Hijacking %s", "cuMipmappedArrayDestroy");
    CUDA_ENTRY_CALL(cuda_library_entry, cuMipmappedArrayDestroy, pHandle);
    return CUDA_ERROR_OUT_OF_MEMORY;
}
CUresult cuMemsetD16Async(CUdeviceptr dstDevice, unsigned short us, size_t N, CUstream hStream) {
    printf("%s %s", __FILE__, __LINE__);
    ensure_initialized();
    LogAndWait(WARNING, 1u, "");
    LWARN("cuMemsetD16Async");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD16Async, dstDevice, us, N, hStream);
}
CUresult cuMemsetD16_v2(CUdeviceptr dstDevice, unsigned short us, size_t N) {
    printf("%s %s", __FILE__, __LINE__);
    ensure_initialized();
    while (!wait_status_self(1LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LogAndWait(INFO, 1u, "");
    };
    LWARN("Hijacking %s", "cuMemsetD16_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD16_v2, dstDevice, us, N);
}
CUresult cuMemsetD2D16_v2(CUdeviceptr dstDevice, size_t dstPitch, unsigned short us, size_t Width, size_t Height) {
    printf("%s %s", __FILE__, __LINE__);
    ensure_initialized();
    while (!wait_status_self(1LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LogAndWait(INFO, 1u, "");
    };
    LogAndWait(WARNING, 1u, "");
    LWARN("cuMemsetD16Async");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D16_v2, dstDevice, dstPitch, us, Width, Height);
}
CUresult cuMemsetD32_v2(CUdeviceptr dstDevice, unsigned int ui, size_t N) {
    printf("%s %s", __FILE__, __LINE__);
    ensure_initialized();
    while (!wait_status_self(1LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LogAndWait(INFO, 1u, "");
    };
    LWARN("Hijacking %s", "cuMemsetD32_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD32_v2, dstDevice, ui, N);
}
CUresult cuMemsetD8_v2(CUdeviceptr dstDevice, unsigned char uc, size_t N) {
    printf("%s %s", __FILE__, __LINE__);
    ensure_initialized();
    while (!wait_status_self(1LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LogAndWait(INFO, 1u, "");
    };
    LWARN("Hijacking %s", "cuMemsetD8_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD8_v2, dstDevice, uc, N);
}
CUresult cuMemsetD2D8Async(CUdeviceptr dstDevice, size_t dstPitch, unsigned char uc, size_t Width, size_t Height, CUstream hStream) {
    printf("%s %s", __FILE__, __LINE__);
    ensure_initialized();
    while (!wait_status_self(1LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LogAndWait(INFO, 1u, "");
    };
    LogAndWait(WARNING, 1u, "");
    LWARN("cuMemsetD2D8Async");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D8Async, dstDevice, dstPitch, uc, Width, Height, hStream);
}
CUresult cuMemsetD8Async(CUdeviceptr dstDevice, unsigned char uc, size_t N, CUstream hStream) {
    printf("%s %s", __FILE__, __LINE__);
    ensure_initialized();
    while (!wait_status_self(1LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LogAndWait(INFO, 1u, "");
    };
    LWARN("Hijacking %s", "cuMemsetD8Async");
    return CUDA_SUCCESS;
}
CUresult cuArray3DCreate_v2(CUarray *pHandle, const CUDA_ARRAY3D_DESCRIPTOR *pAllocateArray) {
    printf("%s %s", __FILE__, __LINE__);
    LWARN("cuArray3DCreate_v2");
    compute_3d_array_alloc_bytes(pAllocateArray);
    LWARN("Hijacking %s", "cuArray3DCreate_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDestroyExternalSemaphore, pHandle, pAllocateArray);
}
CUresult cuArrayCreate_v2(CUarray *pHandle, const CUDA_ARRAY_DESCRIPTOR *pAllocateArray) {
    printf("%s %s", __FILE__, __LINE__);
    LWARN("cuArrayCreate_v2");
    compute_array_alloc_bytes(pAllocateArray);
    LWARN("Hijacking %s", "Driver error at %d: %d", __LINE__, "cuArrayCreate_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuArrayCreate_v2, pHandle, pAllocateArray);
}
CUresult cuArray3DGetDescriptor_v2(CUDA_ARRAY3D_DESCRIPTOR *desc, CUarray hArray) {
    printf("%s %s", __FILE__, __LINE__);
    LWARN("cuArray3DGetDescriptor_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuArray3DGetDescriptor_v2, desc, hArray);
}
CUresult cuArrayDestroy(CUarray hArray) {
    printf("%s %s", __FILE__, __LINE__);
    LWARN("cuArrayDestroy");
    CUDA_ARRAY3D_DESCRIPTOR desc;
    CUresult res = cuArray3DGetDescriptor_v2(&desc, hArray);
    if (res) {
        printf("%s %s", __FILE__, __LINE__);
        LWARN("Hijacking %s", "Driver error at %d: %d", __LINE__, res);
        return res;
    }
    else {
        printf("%s %s", __FILE__, __LINE__);
        compute_3d_array_alloc_bytes(&desc);
        LWARN("Hijacking %s", "Hijacking %s", "cuArrayDestroy");
        return CUDA_ENTRY_CALL(cuda_library_entry, cuArrayDestroy, hArray);
    }
}

CUresult cuLaunchCooperativeKernel(CUfunction f, unsigned int gridDimX, unsigned int gridDimY, unsigned int gridDimZ, unsigned int blockDimX, unsigned int blockDimY, unsigned int blockDimZ, unsigned int sharedMemBytes, CUstream hStream, void **kernelParams) {
    printf("%s %s", __FILE__, __LINE__);
    ensure_initialized();
    while (!wait_status_self(1LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LogAndWait(INFO, 1u, "");
    };
    LWARN("Hijacking %s", "cuLaunchCooperativeKernel");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLaunchCooperativeKernel, f, gridDimX, gridDimY, gridDimZ, blockDimX, blockDimY, blockDimZ, sharedMemBytes, hStream, kernelParams);
}
CUresult cuMemAlloc_v2(CUdeviceptr *dptr, size_t bytesize) {
    printf("%s %s", __FILE__, __LINE__);
    LWARN("into cuMemAllocing_v2 dptr=%p bytesize=%ld", dptr, bytesize);
    ensure_initialized();
    while (!wait_status_self(1LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LogAndWait(INFO, 1u, "");
    };

    unsigned int raw = allocate_raw((size_t *)dptr, bytesize);
    if (raw)
        return raw;
    LWARN("res=%d, cuMemAlloc_v2 success dptr=%p bytesize=%lu", *dptr, bytesize);

    return CUDA_SUCCESS;
}
CUresult cuMemcpyAsync(CUdeviceptr dst, CUdeviceptr src, size_t ByteCount, CUstream hStream) {
    printf("%s %s", __FILE__, __LINE__);
    LWARN("cuMemcpyAsync,dst=%llx src=%llx count=%lu", dst, src, ByteCount, hStream);
    ensure_initialized();
    while (!wait_status_self(1LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LogAndWait(INFO, 1u, "");
    };
    LWARN("Hijacking %s", "cuMemcpyAsync");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAsync, dst, src, ByteCount, hStream);
}
CUresult cuMemcpyDtoA_v2(CUarray dstArray, size_t dstOffset, CUdeviceptr srcDevice, size_t ByteCount) {
    printf("%s %s", __FILE__, __LINE__);
    LWARN("cuMemcpyDtoA_v2,src=%llx count=%lu", srcDevice, ByteCount);
    ensure_initialized();
    while (!wait_status_self(1LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LogAndWait(INFO, 1u, "");
    };
    LWARN("Hijacking %s", "cuMemcpyDtoA_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoA_v2, dstArray, dstOffset, srcDevice, ByteCount);
}
CUresult cuMemcpyDtoD_v2(CUdeviceptr dstDevice, CUdeviceptr srcDevice, size_t ByteCount) {
    printf("%s %s", __FILE__, __LINE__);
    LWARN("cuMemcpyDtoD_v2,src=%llx count=%lu", srcDevice, ByteCount);
    ensure_initialized();
    while (!wait_status_self(1LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LogAndWait(INFO, 1u, "");
    };
    LWARN("Hijacking %s", "cuMemcpyDtoD_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoD_v2, dstDevice, srcDevice, ByteCount);
}
CUresult cuMemcpyAtoD_v2(CUdeviceptr dstDevice, CUarray a2, size_t ByteCount, size_t a4) {
    printf("%s %s", __FILE__, __LINE__);
    LWARN("cuMemcpyAtoD_v2,dst=%llx count=%lu", dstDevice, a4);
    ensure_initialized();
    while (!wait_status_self(1LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LogAndWait(INFO, 1u, "");
    };
    LWARN("Hijacking %s", "cuMemcpyAtoD_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyAtoD_v2, dstDevice, a2, ByteCount, a4);
}
CUresult cuMemcpyDtoDAsync_v2(CUdeviceptr dstDevice, CUdeviceptr srcDevice, size_t ByteCount, CUstream hStream) {
    printf("%s %s", __FILE__, __LINE__);
    LWARN("cuMemcpyDtoDAsync_v2,dst=%llx src=%llx count=%lu", dstDevice, srcDevice, ByteCount);
    ensure_initialized();
    while (!wait_status_self(1LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LogAndWait(INFO, 1u, "");
    };
    LWARN("Hijacking %s", "cuMemcpyDtoDAsync_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoDAsync_v2, dstDevice, srcDevice, ByteCount, hStream);
}
CUresult cuMemcpyDtoH_v2(void *dstHost, CUdeviceptr srcDevice, size_t ByteCount) {
    printf("%s %s", __FILE__, __LINE__);
    LWARN("cuMemcpyDtoH_v2,dst=%p src=%llx count=%lu", dstHost, srcDevice, ByteCount);
    ensure_initialized();
    while (!wait_status_self(1LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LogAndWait(INFO, 1u, "");
    };
    LWARN("Hijacking %s", "cuMemcpyDtoH_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoH_v2, dstHost, srcDevice, ByteCount);
}
CUresult cuMemcpyDtoHAsync_v2(void *dstHost, CUdeviceptr srcDevice, size_t ByteCount, CUstream hStream) {
    printf("%s %s", __FILE__, __LINE__);
    LWARN("cuMemcpyDtoHAsync_v2,dst=%p src=%llx count=%lu", dstHost, srcDevice, ByteCount);
    ensure_initialized();
    while (!wait_status_self(1LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LogAndWait(INFO, 1u, "");
    };
    LWARN("Hijacking %s", "cuMemcpyDtoHAsync_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyDtoHAsync_v2, dstHost, srcDevice, ByteCount, hStream);
}
CUresult cuMemcpyHtoD_v2(CUdeviceptr dstDevice, const void *srcHost, size_t ByteCount) {
    printf("%s %s", __FILE__, __LINE__);
    LWARN("cuMemcpyHtoD_v2,srcDevice=%llx dstHost=%p count=%lu", dstDevice, srcHost, ByteCount);
    ensure_initialized();
    while (!wait_status_self(1LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LogAndWait(INFO, 1u, "");
    };
    LWARN("Hijacking %s", "cuMemcpyHtoD_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyHtoD_v2, dstDevice, srcHost, ByteCount);
}
CUresult cuMemcpyHtoDAsync_v2(CUdeviceptr dstDevice, const void *srcHost, size_t ByteCount, CUstream hStream) {
    printf("%s %s", __FILE__, __LINE__);
    LWARN("cuMemcpyHtoDAsync_v2,dst=%llx src=%p count=%lu", dstDevice, srcHost, ByteCount);
    ensure_initialized();
    while (!wait_status_self(1LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LogAndWait(INFO, 1u, "");
    };
    LWARN("Hijacking %s", "cuMemcpyHtoDAsync_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyHtoDAsync_v2, dstDevice, srcHost, ByteCount, hStream);
}
CUresult cuMemMap(CUdeviceptr ptr, size_t size, size_t offset, CUmemGenericAllocationHandle handle, unsigned long long flags) {
    printf("%s %s", __FILE__, __LINE__);
    LWARN("cuMemMap");
    LWARN("Hijacking %s", "cuMemMap");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemMap, ptr, size, offset, handle, flags);
}
CUresult cuMemAdvise(CUdeviceptr devPtr, size_t count, CUmem_advise advice, CUdevice device) {
    printf("%s %s", __FILE__, __LINE__);
    LWARN("cuMemAdvise devPtr=%llx count=%lx", devPtr, count);
    ensure_initialized();
    while (!wait_status_self(1LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LogAndWait(INFO, 1u, "");
    };
    LWARN("Hijacking %s", "cuMemAdvise");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemAdvise, devPtr, count);
}
CUresult cuMemAllocManaged(CUdeviceptr *dptr, size_t bytesize, unsigned int flags) {
    printf("%s %s", __FILE__, __LINE__);
    LWARN("cuMemAllocManaged dptr=%p bytesize=%ld", dptr, bytesize);
    ensure_initialized();
    while (!wait_status_self(1LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LogAndWait(INFO, 1u, "");
    };
    LWARN("Hijacking %s", "cuCtxGetDevice");
    CUdevice dev;
    CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetDevice, &dev);

    if (oom_check(dev, bytesize)) {
        printf("%s %s", __FILE__, __LINE__);
        return CUDA_ERROR_OUT_OF_MEMORY;
    }

    LWARN("Hijacking %s", "cuMemAllocManaged");

    CUresult v23 = CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetDevice, dptr, bytesize, flags);
    if (!v23) {
        printf("%s %s", __FILE__, __LINE__);
        add_chunk_only(*dptr, bytesize);
    }
    return v23;
}
CUresult cuIpcCloseMemHandle(CUdeviceptr dptr) {
    printf("%s %s", __FILE__, __LINE__);
    LWARN("cuIpcCloseMemHandle dptr=%llx", dptr);
    ensure_initialized();
    while (!wait_status_self(1LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LogAndWait(INFO, 1u, "");
    };
    LWARN("Hijacking %s", "cuIpcCloseMemHandle");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuIpcCloseMemHandle, dptr);
}
CUresult cuIpcGetMemHandle(CUipcMemHandle *pHandle, CUdeviceptr dptr) {
    printf("%s %s", __FILE__, __LINE__);
    LWARN("cuIpcGetMemHandle dptr=%llx", dptr);
    ensure_initialized();
    while (!wait_status_self(1LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LogAndWait(INFO, 1u, "");
    };
    LWARN("Hijacking %s", "cuIpcGetMemHandle");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuIpcGetMemHandle, pHandle, dptr);
}
CUresult cuIpcOpenMemHandle_v2(CUdeviceptr *pdptr, CUipcMemHandle handle, unsigned int Flags) {
    printf("%s %s", __FILE__, __LINE__);
    LWARN("cuIpcOpenMemHandle_v2 dptr=%llx", pdptr);
    ensure_initialized();
    while (!wait_status_self(1LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LogAndWait(INFO, 1u, "");
    };
    LWARN("Hijacking %s", "cuIpcOpenMemHandle_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuIpcOpenMemHandle_v2, pdptr, handle, Flags);
}
CUresult cuLaunchKernel(CUfunction f, unsigned int gridDimX, unsigned int gridDimY, unsigned int gridDimZ, unsigned int blockDimX, unsigned int blockDimY, unsigned int blockDimZ, unsigned int sharedMemBytes, CUstream hStream, void **kernelParams, void **extra) {
    printf("%s %s", __FILE__, __LINE__);
    ensure_initialized();
    while (!wait_status_self(1LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LogAndWait(INFO, 1u, "");
    };
    if (pidfound == 1) {
        printf("%s %s", __FILE__, __LINE__);
        rate_limiter(gridDimZ * gridDimY * gridDimX, blockDimZ * blockDimY * blockDimX);
    }

    LWARN("Hijacking %s", "cuLaunchKernel");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuLaunchKernel, f, gridDimX, gridDimY, gridDimZ, blockDimX, blockDimY, blockDimZ, sharedMemBytes, hStream, kernelParams, extra);
}
CUresult cuMapMemory(CUdeviceptr *dptr, size_t bytesize, const CUmemAccessDesc *desc, size_t count) {
    printf("%s %s", __FILE__, __LINE__);
    CUdevice cDev;

    LINFO("cuMapMemory dptr=%llx %p bytesize=%lu", *desc, dptr, bytesize);

    if (desc != NULL) {
        printf("%s %s", __FILE__, __LINE__);
        *dptr = (int64_t)desc;
    }
    else if (cuMemAddressReserve(dptr, bytesize, 0LL, 0LL, 0LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LINFO("Driver error at %d: %d", __LINE__, cuMemAddressReserve(dptr, bytesize, 0LL, 0LL, 0LL));
        return cuMemAddressReserve(dptr, bytesize, 0LL, 0LL, 0LL);
    }

    if (cuMemMap(*dptr, bytesize, 0LL, count, 0LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LINFO("Driver error at %d: %d", __LINE__, cuMemMap(*dptr, bytesize, 0LL, count, 0LL));
        return cuMemMap(*dptr, bytesize, 0LL, count, 0LL);
    }
    else {
        printf("%s %s", __FILE__, __LINE__);
        CUdevice dev;
        cuDeviceGetCount(&dev);
        void *ptr = malloc(12LL * dev);
        signed int i;
        for (i = 0;; ++i) {
            printf("%s %s", __FILE__, __LINE__);
            if (i >= dev) {
                printf("%s %s", __FILE__, __LINE__);
                if (cuMemSetAccess(*dptr, bytesize, ptr, dev)) {
                    printf("%s %s", __FILE__, __LINE__);
                    LINFO("Driver error at %d: %d", __LINE__, cuMemSetAccess(*dptr, bytesize, ptr, dev));
                    return cuMemSetAccess(*dptr, bytesize, ptr, dev);
                }
                else {
                    printf("%s %s", __FILE__, __LINE__);
                    free(ptr);
                    LINFO("cuMaped dptr=%p size=%lu", (const void *)*dptr, bytesize);
                    return CUDA_SUCCESS;
                }
            }
            *((size_t *)ptr + 3 * i) = 1;
            if (cuDeviceGet(&cDev, i))
                break;
            *((size_t *)ptr + 3 * i + 1) = cDev;
            *((size_t *)ptr + 3 * i + 2) = 3;
        }
        LINFO("Driver error at %d: %d", __LINE__, cuDeviceGet(&cDev, i));
        return cuDeviceGet(&cDev, i);
    }
}
CUresult cuMemHostAlloc(void **pp, size_t bytesize, unsigned int Flags) {
    printf("%s %s", __FILE__, __LINE__);
    LWARN("cuMemHostAlloc hptr=%p bytesize=%lu", pp, bytesize);
    ensure_initialized();
    while (!wait_status_self(1LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LogAndWait(INFO, 1u, "");
    };
    LWARN("Hijacking %s", "cuMemHostAlloc");
    CUresult res = CUDA_ENTRY_CALL(cuda_library_entry, cuMemHostAlloc, pp, bytesize, Flags);
    if (res)
        return res;
    if (!check_oom())
        return CUDA_SUCCESS;
    LWARN("Hijacking %s", "cuMemFreeHost");
    CUDA_ENTRY_CALL(cuda_library_entry, cuMemFreeHost, *pp);
    *pp = 0LL;
    return CUDA_ERROR_OUT_OF_MEMORY;
}
CUresult cuMemHostRegister_v2(void *p, size_t bytesize, unsigned int Flags) {
    printf("%s %s", __FILE__, __LINE__);
    LWARN("cuMemHostRegister_v2 hptr=%p bytesize=%ld", p, bytesize);
    CUdevice dev;
    cuCtxGetDevice(&dev);
    ensure_initialized();
    while (!wait_status_self(1LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LogAndWait(INFO, 1u, "");
    };
    LWARN("Hijacking %s", "cuMemHostRegister_v2");
    CUresult res = CUDA_ENTRY_CALL(cuda_library_entry, cuMemHostRegister_v2, p, bytesize, Flags);
    LWARN("cuMemHostRegister_v2 returned :%d(%p:%ld", p, bytesize);
    if (res)
        return res;
    if (!check_oom()) {
        printf("%s %s", __FILE__, __LINE__);
        return res;
    }
    LWARN("Hijacking %s", "cuMemHostUnregister");
    CUDA_ENTRY_CALL(cuda_library_entry, cuMemHostUnregister, p);
    return CUDA_ERROR_OUT_OF_MEMORY;
}
CUresult cuMemHostUnregister(void *p) {
    printf("%s %s", __FILE__, __LINE__);
    LWARN("cuMemHostUnregister hptr=%p", p);
    ensure_initialized();
    while (!wait_status_self(1LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LogAndWait(INFO, 1u, "");
    };
    LWARN("Hijacking %s", "cuMemHostUnregister");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemHostUnregister, p);
}
CUresult cuMemAllocPitch_v2(CUdeviceptr *dptr, size_t *pPitch, size_t WidthInBytes, size_t Height, unsigned int ElementSizeBytes) {
    printf("%s %s", __FILE__, __LINE__);
    LWARN("cuMemAllocPitch_v2 dptr=%p (%ld,%ld)", dptr, WidthInBytes, Height);

    size_t v29 = Height * ((WidthInBytes - 1) / (int64_t)ElementSizeBytes + 1) * ElementSizeBytes;
    ensure_initialized();
    while (!wait_status_self(1LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LogAndWait(INFO, 1u, "");
    };
    LWARN("Hijacking %s", "cuCtxGetDevice");
    if (check_oom()) {
        printf("%s %s", __FILE__, __LINE__);
        return CUDA_ERROR_OUT_OF_MEMORY;
    }
    LWARN("Hijacking %s", "cuMemAllocPitch_v2");
    CUresult res = CUDA_ENTRY_CALL(cuda_library_entry, cuMemHostUnregister, dptr, pPitch, WidthInBytes, Height, ElementSizeBytes);

    if (!res)
        add_chunk_only(*dptr, v29);
    return res;
}
CUresult cuMemcpy(CUdeviceptr dst, CUdeviceptr src, size_t ByteCount) {
    printf("%s %s", __FILE__, __LINE__);
    LWARN("cuMemcpy dst=%llx src=%llx count=%lu", dst, src, ByteCount);
    ensure_initialized();
    while (!wait_status_self(1LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LogAndWait(INFO, 1u, "");
    };
    LWARN("Hijacking %s", "cuMemcpy");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpy, dst, src, ByteCount);
}
CUresult cuMemcpyPeer(CUdeviceptr dstDevice, CUcontext dstContext, CUdeviceptr srcDevice, CUcontext srcContext, size_t ByteCount) {
    printf("%s %s", __FILE__, __LINE__);
    LWARN("cuMemcpyPeer dstDevice=%llx srcDevice=%llx", dstDevice, srcDevice);
    ensure_initialized();
    while (!wait_status_self(1LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LogAndWait(INFO, 1u, "");
    };
    LWARN("Hijacking %s", "cuMemcpyPeer");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyPeer, dstDevice, srcDevice, srcContext, ByteCount);
}
CUresult cuMemcpyPeerAsync(CUdeviceptr dstDevice, CUcontext dstContext, CUdeviceptr srcDevice, CUcontext srcContext, size_t ByteCount, CUstream hStream) {
    printf("%s %s", __FILE__, __LINE__);
    LWARN("into cuMemcpyPeerAsync dstDevice=%llx srcDevice=%llx", dstDevice, srcDevice);
    ensure_initialized();
    while (!wait_status_self(1LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LogAndWait(INFO, 1u, "");
    };
    LWARN("Hijacking %s", "cuMemcpyPeerAsync");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemcpyPeerAsync, dstDevice, dstContext, srcDevice, srcContext, ByteCount, hStream);
}
CUresult cuMemFree_v2(CUdeviceptr dptr) {
    printf("%s %s", __FILE__, __LINE__);
    LWARN("cuMemFree_v2 dptr=%llx", dptr);
    ensure_initialized();
    while (!wait_status_self(1LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LogAndWait(INFO, 1u, "");
    };

    if (!dptr) {
        printf("%s %s", __FILE__, __LINE__);
        return CUDA_SUCCESS;
    }
    unsigned int res = free_raw(dptr);
    LWARN("after free_raw dptr=%p res=%d", dptr, res);
    return res;
}
CUresult cuMemGetInfo_v2(size_t *free, size_t *total) {
    printf("%s %s", __FILE__, __LINE__);
    LWARN("cuMemGetInfo_v2");
    ensure_initialized();

    CUdevice dev;
    cuCtxGetDevice(&dev);
    if (dev) {
        printf("%s %s", __FILE__, __LINE__);
        LINFO("Driver error at %d: %d", __LINE__, dev);
        return dev;
    }
    else {
        printf("%s %s", __FILE__, __LINE__);
        u_int64_t current_device_memory_usage = get_current_device_memory_usage(0);
        u_int64_t current_device_memory_limit = get_current_device_memory_limit(0);
        if (current_device_memory_limit) {
            printf("%s %s", __FILE__, __LINE__);
            if (current_device_memory_limit >= current_device_memory_usage) {
                printf("%s %s", __FILE__, __LINE__);
                LWARN("Hijacking %s", "cuMemGetInfo_v2");
                CUDA_ENTRY_CALL(cuda_library_entry, cuMemGetInfo_v2, free, total);
                LWARN("orig free=%ld total=%ld limit=%ld usage=%ld", current_device_memory_limit, current_device_memory_usage);

                *free = current_device_memory_limit - current_device_memory_usage;
                *total = current_device_memory_limit;
                return CUDA_SUCCESS;
            }
            else {
                printf("%s %s", __FILE__, __LINE__);
                LWARN("limit < usage; usage=%ld, limit=%ld", current_device_memory_usage, current_device_memory_limit);
                return CUDA_ERROR_INVALID_VALUE;
            }
        }
        else {
            printf("%s %s", __FILE__, __LINE__);
            LWARN("Hijacking %s", "cuMemGetInfo_v2");
            CUDA_ENTRY_CALL(cuda_library_entry, cuMemGetInfo_v2, free, total);
            LWARN("orig free=%ld total=%ld", *free, *total);
            *free = *total - current_device_memory_usage;
            LWARN("after free=%ld total=%ld", *free, *total);
            return CUDA_SUCCESS;
        }
    }
}
CUresult cuUnmapMemory(CUdeviceptr dptr, size_t bytesize) {
    printf("%s %s", __FILE__, __LINE__);
    LWARN("cuUnmapMemory dptr=%llx free=%d", dptr, bytesize);
    LWARN("Hijacking %s", "cuPointerGetAttribute");

    int64_t memory_section_size;
    CUDA_ENTRY_CALL(cuda_library_entry, cuPointerGetAttribute, &memory_section_size, 12LL, dptr);

    LWARN(" Unmap memory_section_size = %ld", memory_section_size);
    if (cuMemUnmap(dptr, memory_section_size)) {
        printf("%s %s", __FILE__, __LINE__);
        LWARN("Driver error at %d: %d", __LINE__, cuMemUnmap(dptr, memory_section_size));
        return cuMemUnmap(dptr, memory_section_size);
    }
    else {
        printf("%s %s", __FILE__, __LINE__);
        CUmemGenericAllocationHandle *allochandle_from_dptr = (CUmemGenericAllocationHandle *)get_allochandle_from_dptr(dptr);

        if (cuMemRelease(*allochandle_from_dptr)) {
            printf("%s %s", __FILE__, __LINE__);
            LWARN("Driver error at %d: %d", __LINE__, cuMemRelease(*allochandle_from_dptr));
            return cuMemRelease(*allochandle_from_dptr);
        }
        else if (bytesize && cuMemAddressFree(dptr, memory_section_size)) {
            printf("%s %s", __FILE__, __LINE__);
            LWARN("Driver error at %d: %d", __LINE__, cuMemAddressFree(dptr, memory_section_size));
            return cuMemAddressFree(dptr, memory_section_size);
        }
        else {
            printf("%s %s", __FILE__, __LINE__);
            LWARN("Unmap memory_section %p complete", dptr);
            return CUDA_SUCCESS;
        }
    }
}
CUresult cuMemoryFree(void *ptr, size_t size) {
    printf("%s %s", __FILE__, __LINE__);
    if (allocmode == 2) {
        printf("%s %s", __FILE__, __LINE__);
        goto LABEL_14;
    }
    if (allocmode > 2) {
        printf("%s %s", __FILE__, __LINE__);
        return CUDA_SUCCESS;
    }
    if (!allocmode) {
        printf("%s %s", __FILE__, __LINE__);
    LABEL_14:
        LWARN("Hijacking %s", "cuMemFree_v2");
        return CUDA_ENTRY_CALL(cuda_library_entry, cuMemFree_v2, ptr, size);
    }
    else if (allocmode == 1) {
        printf("%s %s", __FILE__, __LINE__);
        return cuUnmapMemory((int64_t)(ptr), 1u);
    }
    return CUDA_SUCCESS;
}
CUresult cuMemsetD2D16Async(CUdeviceptr dstDevice, size_t dstPitch, unsigned short us, size_t Width, size_t Height, CUstream hStream) {
    printf("%s %s", __FILE__, __LINE__);
    ensure_initialized();
    while (!wait_status_self(1LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LogAndWait(INFO, 1u, "");
    };
    LWARN("Hijacking %s", "cuMemsetD2D16Async");

    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D16Async, dstDevice, dstPitch, us, Width, Height, hStream);
}
CUresult cuMemsetD2D32_v2(CUdeviceptr dstDevice, size_t dstPitch, unsigned int ui, size_t Width, size_t Height) {
    printf("%s %s", __FILE__, __LINE__);
    ensure_initialized();
    while (!wait_status_self(1LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LogAndWait(INFO, 1u, "");
    };
    LWARN("Hijacking %s", "cuMemsetD2D32_v2");

    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D32_v2, dstDevice, dstPitch, ui, Width, Height);
}
CUresult cuMemAllocHost_v2(void **pp, size_t bytesize) {
    printf("%s %s", __FILE__, __LINE__);
    LWARN("cuMemAllocHost_v2 hptr=%p bytesize=%ld", pp, bytesize);
    ensure_initialized();
    while (!wait_status_self(1LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LogAndWait(INFO, 1u, "");
    };
    LWARN("Hijacking %s", "cuMemAllocHost_v2");
    CUresult res = CUDA_ENTRY_CALL(cuda_library_entry, cuMemAllocHost_v2, pp, bytesize);
    if (res)
        return res;
    if (!check_oom()) {
        printf("%s %s", __FILE__, __LINE__);
        return CUDA_SUCCESS;
    }
    LWARN("Hijacking %s", "cuMemFreeHost");
    CUDA_ENTRY_CALL(cuda_library_entry, cuMemFreeHost, *pp);
    return CUDA_ERROR_OUT_OF_MEMORY;
}
CUresult cuMemsetD2D8_v2(CUdeviceptr dstDevice, size_t dstPitch, unsigned char uc, size_t Width, size_t Height) {
    printf("%s %s", __FILE__, __LINE__);
    ensure_initialized();
    while (!wait_status_self(1LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LogAndWait(INFO, 1u, "");
    };
    LWARN("Hijacking %s", "cuMemsetD2D8_v2");

    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemsetD2D8_v2, dstDevice, dstPitch, uc, Width, Height);
}
CUresult cuMemGetAddressRange_v2(CUdeviceptr *pbase, size_t *psize, CUdeviceptr dptr) {
    printf("%s %s", __FILE__, __LINE__);
    LWARN("cuMemGetAddressRange_v2,dptr=%llx", dptr);
    ensure_initialized();
    while (!wait_status_self(1LL)) {
        printf("%s %s", __FILE__, __LINE__);
        LogAndWait(INFO, 1u, "");
    };
    LWARN("Hijacking %s", "cuMemGetAddressRange_v2");

    return CUDA_ENTRY_CALL(cuda_library_entry, cuMemGetAddressRange_v2, pbase, psize, dptr);
}
CUresult cuMemoryAllocate(CUdeviceptr *dptr, size_t bytesize, CUmemAccessDesc *desc, const CUmemGenericAllocationHandle *handle) {
    printf("%s %s", __FILE__, __LINE__);
    if (allocmode == 2) {
        printf("%s %s", __FILE__, __LINE__);
        if (desc != NULL) {
            printf("%s %s", __FILE__, __LINE__);
            *dptr = (int64_t)desc;
        }
        LWARN("Hijacking %s", "cuMemAlloc_v2");
        return CUDA_ENTRY_CALL(cuda_library_entry, cuMemAlloc_v2, dptr, bytesize);
    }
    else if (allocmode <= 2) {
        printf("%s %s", __FILE__, __LINE__);
        if (allocmode) {
            printf("%s %s", __FILE__, __LINE__);
            if (allocmode == 1) {
                printf("%s %s", __FILE__, __LINE__);
                getallochandle(handle, bytesize, desc);
                return (size_t)cuMapMemory(dptr, (size_t)desc, 0LL, *handle);
            }
        }
        else {
            printf("%s %s", __FILE__, __LINE__);
            if (desc != NULL) {
                printf("%s %s", __FILE__, __LINE__);
                *desc = *(CUmemAccessDesc *)bytesize;
            }
            LWARN("Hijacking %s", "cuMemAllocManaged");
            return CUDA_ENTRY_CALL(cuda_library_entry, cuMemAllocManaged, dptr, bytesize, 1LL);
        }
    }

    return CUDA_SUCCESS;
}
