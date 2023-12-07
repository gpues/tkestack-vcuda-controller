#include <dlfcn.h>
#include <pthread.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "include/base.h"

extern resource_data_t g_vcuda_config;

static uint32_t g_block_locker = 0;

extern int g_block_x;
extern int g_block_y;
extern int g_block_z;

int g_block_x = 1, g_block_y = 1, g_block_z = 1;

CUresult cuDriverGetVersion(int *driverVersion) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuDriverGetVersion");

    load_necessary_data();
    cudaNecessary();
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(int *) = (CUresult(*)(int *))dlsym(cuda_handle, "cuDriverGetVersion");
    CUresult rs = hookFunc(driverVersion);
    TimeProfileDestroy(pprof);
    return rs;
}
CUresult cuInit(unsigned int Flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuInit");
    load_necessary_data();
    cudaNecessary();
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(unsigned int) = (CUresult(*)(unsigned int))dlsym(cuda_handle, "cuInit");
    CUresult rs = hookFunc(Flags);
    TimeProfileDestroy(pprof);
    return rs;
}
CUresult cuGetProcAddress(const char *symbol, void **pfn, int cudaVersion, cuuint64_t flags) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuGetProcAddress");
    load_necessary_data();
    cudaNecessary();
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(const char *, void **, int, cuuint64_t) = (CUresult(*)(const char *, void **, int, cuuint64_t))dlsym(cuda_handle, "cuGetProcAddress");
    CUresult rs = hookFunc(symbol, pfn, cudaVersion, flags);
    *pfn = hookFunc;
    TimeProfileDestroy(pprof);
    return rs;
}
CUresult cuDeviceTotalMem(size_t *bytes, CUdevice dev) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuDeviceTotalMem");
    if (g_vcuda_config.enable) {
        *bytes = g_vcuda_config.gpu_memory;

        return CUDA_SUCCESS;
    }

    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(size_t *, CUdevice) = (CUresult(*)(size_t *, CUdevice))dlsym(cuda_handle, "cuDeviceTotalMem");
    CUresult rs = hookFunc(bytes, dev);
    TimeProfileDestroy(pprof);
    return rs;
}
CUresult cuMemGetInfo(size_t *free, size_t *total) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemGetInfo");
    size_t used = 0;

    if (g_vcuda_config.enable) {
        atomic_action(PIDS_CONFIG_PATH, get_used_gpu_memory, (void *)&used);
        *total = g_vcuda_config.gpu_memory;
        *free = used > g_vcuda_config.gpu_memory ? 0 : g_vcuda_config.gpu_memory - used;
        HLOG(INFO, "%s %s %s %s", Marshal(g_vcuda_config), total, used, free);
        return CUDA_SUCCESS;
    }

    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(size_t *, size_t *) = (CUresult(*)(size_t *, size_t *))dlsym(cuda_handle, "cuMemGetInfo");
    CUresult rs = hookFunc(free, total);
    TimeProfileDestroy(pprof);
    return rs;
}
CUresult cuLaunchKernel(CUfunction f, unsigned int gridDimX, unsigned int gridDimY, unsigned int gridDimZ, unsigned int blockDimX, unsigned int blockDimY, unsigned int blockDimZ, unsigned int sharedMemBytes, CUstream hStream, void **kernelParams, void **extra) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuLaunchKernel");
    rate_limiter(gridDimX * gridDimY * gridDimZ, blockDimX * blockDimY * blockDimZ);
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUfunction, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, CUstream, void **, void **) = (CUresult(*)(CUfunction, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, CUstream, void **, void **))dlsym(cuda_handle, "cuLaunchKernel");
    CUresult rs = hookFunc(f, gridDimX, gridDimY, gridDimZ, blockDimX, blockDimY, blockDimZ, sharedMemBytes, hStream, kernelParams, extra);
    TimeProfileDestroy(pprof);
    return rs;
}
CUresult cuLaunch(CUfunction f) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuLaunch");
    rate_limiter(1, g_block_x * g_block_y * g_block_z);
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUfunction) = (CUresult(*)(CUfunction))dlsym(cuda_handle, "cuLaunch");
    CUresult rs = hookFunc(f);
    TimeProfileDestroy(pprof);
    return rs;
}
CUresult cuLaunchCooperativeKernel(CUfunction f, unsigned int gridDimX, unsigned int gridDimY, unsigned int gridDimZ, unsigned int blockDimX, unsigned int blockDimY, unsigned int blockDimZ, unsigned int sharedMemBytes, CUstream hStream, void **kernelParams) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuLaunchCooperativeKernel");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUfunction, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, CUstream, void **) = (CUresult(*)(CUfunction, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, CUstream, void **))dlsym(cuda_handle, "cuLaunchCooperativeKernel");
    CUresult rs = hookFunc(f, gridDimX, gridDimY, gridDimZ, blockDimX, blockDimY, blockDimZ, sharedMemBytes, hStream, kernelParams);
    TimeProfileDestroy(pprof);
    return rs;
}
CUresult cuLaunchGrid(CUfunction f, int grid_width, int grid_height) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuLaunchGrid");
    rate_limiter(grid_width * grid_height, g_block_x * g_block_y * g_block_z);
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUfunction, int, int) = (CUresult(*)(CUfunction, int, int))dlsym(cuda_handle, "cuLaunchGrid");
    CUresult rs = hookFunc(f, grid_width, grid_height);
    TimeProfileDestroy(pprof);
    return rs;
}
CUresult cuLaunchGridAsync(CUfunction f, int grid_width, int grid_height, CUstream hStream) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuLaunchGridAsync");
    rate_limiter(grid_width * grid_height, g_block_x * g_block_y * g_block_z);
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUfunction, int, int, CUstream) = (CUresult(*)(CUfunction, int, int, CUstream))dlsym(cuda_handle, "cuLaunchGridAsync");
    CUresult rs = hookFunc(f, grid_width, grid_height, hStream);
    TimeProfileDestroy(pprof);
    return rs;
}
CUresult cuFuncSetBlockShape(CUfunction hfunc, int x, int y, int z) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuFuncSetBlockShape");

    if (g_vcuda_config.enable) {
        while (!CAS(&g_block_locker, 0, 1)) {
        }
        g_block_x = x;
        g_block_y = y;
        g_block_z = z;
        HLOG(INFO, "Set block shape: %d, %d, %d", x, y, z);
        while (!CAS(&g_block_locker, 1, 0)) {
        }
    }

    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUfunction, int, int, int) = (CUresult(*)(CUfunction, int, int, int))dlsym(cuda_handle, "cuFuncSetBlockShape");
    CUresult rs = hookFunc(hfunc, x, y, z);
    TimeProfileDestroy(pprof);
    return rs;
}
CUresult cuLaunchKernel_ptsz(CUfunction f, unsigned int gridDimX, unsigned int gridDimY, unsigned int gridDimZ, unsigned int blockDimX, unsigned int blockDimY, unsigned int blockDimZ, unsigned int sharedMemBytes, CUstream hStream, void **kernelParams, void **extra) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuLaunchKernel_ptsz");
    rate_limiter(gridDimX * gridDimY * gridDimZ, blockDimX * blockDimY * blockDimZ);
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUfunction, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, CUstream, void **, void **) = (CUresult(*)(CUfunction, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, CUstream, void **, void **))dlsym(cuda_handle, "cuLaunchKernel_ptsz");
    CUresult rs = hookFunc(f, gridDimX, gridDimY, gridDimZ, blockDimX, blockDimY, blockDimZ, sharedMemBytes, hStream, kernelParams, extra);
    TimeProfileDestroy(pprof);
    return rs;
}
CUresult cuLaunchCooperativeKernel_ptsz(CUfunction f, unsigned int gridDimX, unsigned int gridDimY, unsigned int gridDimZ, unsigned int blockDimX, unsigned int blockDimY, unsigned int blockDimZ, unsigned int sharedMemBytes, CUstream hStream, void **kernelParams) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuLaunchCooperativeKernel_ptsz");
    rate_limiter(gridDimX * gridDimY * gridDimZ, blockDimX * blockDimY * blockDimZ);
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUfunction, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, CUstream, void **) = (CUresult(*)(CUfunction, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, CUstream, void **))dlsym(cuda_handle, "cuLaunchCooperativeKernel_ptsz");
    CUresult rs = hookFunc(f, gridDimX, gridDimY, gridDimZ, blockDimX, blockDimY, blockDimZ, sharedMemBytes, hStream, kernelParams);
    TimeProfileDestroy(pprof);
    return rs;
}
CUresult cuDeviceTotalMem_v2(size_t *bytes, CUdevice dev) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuDeviceTotalMem_v2");
    if (g_vcuda_config.enable) {
        *bytes = g_vcuda_config.gpu_memory;

        return CUDA_SUCCESS;
    }

    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(size_t *, CUdevice) = (CUresult(*)(size_t *, CUdevice))dlsym(cuda_handle, "cuDeviceTotalMem_v2");
    CUresult rs = hookFunc(bytes, dev);
    TimeProfileDestroy(pprof);
    return rs;
}
CUresult cuMemGetInfo_v2(size_t *free, size_t *total) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemGetInfo_v2");
    size_t used = 0;
    if (g_vcuda_config.enable) {
        atomic_action(PIDS_CONFIG_PATH, get_used_gpu_memory, (void *)&used);
        *total = g_vcuda_config.gpu_memory;
        *free = used > g_vcuda_config.gpu_memory ? 0 : g_vcuda_config.gpu_memory - used;
        HLOG(INFO, "%s %s %s %s", Marshal(g_vcuda_config), total, used, free);
        return CUDA_SUCCESS;
    }
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(size_t *, size_t *) = (CUresult(*)(size_t *, size_t *))dlsym(cuda_handle, "cuMemGetInfo_v2");
    CUresult rs = hookFunc(free, total);
    TimeProfileDestroy(pprof);
    return rs;
}

CUresult cuMemAlloc(CUdeviceptr *dptr, size_t bytesize) {
    size_t used = 0;
    size_t request_size = bytesize;
    CUresult ret;

    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemAlloc");
    if (g_vcuda_config.enable) {
        atomic_action(PIDS_CONFIG_PATH, get_used_gpu_memory, (void *)&used);
        HLOG(INFO, "%s %d %d", Marshal(g_vcuda_config), used, request_size);
        if (unlikely(used + request_size > g_vcuda_config.gpu_memory)) {
            ret = CUDA_ERROR_OUT_OF_MEMORY;
            goto DONE;
        }
    }

    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr *, size_t) = (CUresult(*)(CUdeviceptr *, size_t))dlsym(cuda_handle, "cuMemAlloc");
    ret = hookFunc(dptr, bytesize);
DONE:
    TimeProfileDestroy(pprof);
    return ret;
}
CUresult cuMemAllocManaged(CUdeviceptr *dptr, size_t bytesize, unsigned int flags) {
    size_t used = 0;
    size_t request_size = bytesize;
    CUresult ret;
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemAllocManaged");
    if (g_vcuda_config.enable) {
        atomic_action(PIDS_CONFIG_PATH, get_used_gpu_memory, (void *)&used);
        HLOG(INFO, "%s %d %d", Marshal(g_vcuda_config), used, request_size);
        if (unlikely(used + request_size > g_vcuda_config.gpu_memory)) {
            ret = CUDA_ERROR_OUT_OF_MEMORY;
            goto DONE;
        }
    }

    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr *, size_t, unsigned int) = (CUresult(*)(CUdeviceptr *, size_t, unsigned int))dlsym(cuda_handle, "cuMemAllocManaged");
    ret = hookFunc(dptr, bytesize, flags);
DONE:
    TimeProfileDestroy(pprof);
    return ret;
}
CUresult cuMemAllocPitch(CUdeviceptr *dptr, size_t *pPitch, size_t WidthInBytes, size_t Height, unsigned int ElementSizeBytes) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemAllocPitch");
    size_t used = 0;
    size_t request_size = ROUND_UP(WidthInBytes * Height, ElementSizeBytes);
    CUresult ret;

    if (g_vcuda_config.enable) {
        atomic_action(PIDS_CONFIG_PATH, get_used_gpu_memory, (void *)&used);
        HLOG(INFO, "%s %d %d", Marshal(g_vcuda_config), used, request_size);
        if (unlikely(used + request_size > g_vcuda_config.gpu_memory)) {
            ret = CUDA_ERROR_OUT_OF_MEMORY;
            goto DONE;
        }
    }

    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr *, size_t *, size_t, size_t, unsigned int) = (CUresult(*)(CUdeviceptr *, size_t *, size_t, size_t, unsigned int))dlsym(cuda_handle, "cuMemAllocPitch");
    ret = hookFunc(dptr, pPitch, WidthInBytes, Height, ElementSizeBytes);
DONE:
    TimeProfileDestroy(pprof);
    return ret;
}
CUresult cuMemAllocPitch_v2(CUdeviceptr *dptr, size_t *pPitch, size_t WidthInBytes, size_t Height, unsigned int ElementSizeBytes) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemAllocPitch_v2");

    size_t used = 0;
    size_t request_size = ROUND_UP(WidthInBytes * Height, ElementSizeBytes);
    CUresult ret;

    if (g_vcuda_config.enable) {
        atomic_action(PIDS_CONFIG_PATH, get_used_gpu_memory, (void *)&used);
        HLOG(INFO, "%s %d %d", Marshal(g_vcuda_config), used, request_size);
        if (unlikely(used + request_size > g_vcuda_config.gpu_memory)) {
            ret = CUDA_ERROR_OUT_OF_MEMORY;
            goto DONE;
        }
    }

    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr *, size_t *, size_t, size_t, unsigned int) = (CUresult(*)(CUdeviceptr *, size_t *, size_t, size_t, unsigned int))dlsym(cuda_handle, "cuMemAllocPitch_v2");
    ret = hookFunc(dptr, pPitch, WidthInBytes, Height, ElementSizeBytes);
DONE:
    TimeProfileDestroy(pprof);
    return ret;
}
CUresult cuMemAlloc_v2(CUdeviceptr *dptr, size_t bytesize) {
    size_t used = 0;
    size_t request_size = bytesize;
    CUresult ret;
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemAlloc_v2");
    if (g_vcuda_config.enable) {
        atomic_action(PIDS_CONFIG_PATH, get_used_gpu_memory, (void *)&used);
        HLOG(INFO, "%s %d %d", Marshal(g_vcuda_config), used, request_size);

        if (unlikely(used + request_size > g_vcuda_config.gpu_memory)) {
            ret = CUDA_ERROR_OUT_OF_MEMORY;
            goto DONE;
        }
    }
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr *, size_t) = (CUresult(*)(CUdeviceptr *, size_t))dlsym(cuda_handle, "cuMemAlloc_v2");
    ret = hookFunc(dptr, bytesize);
DONE:
    TimeProfileDestroy(pprof);
    return ret;
}
CUresult cuArrayCreate(CUarray *pHandle, const CUDA_ARRAY_DESCRIPTOR *pAllocateArray) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuArrayCreate");
    CUresult ret;

    ret = cuArrayCreate_helper(pAllocateArray);
    if (ret != CUDA_SUCCESS) {
        goto DONE;
    }

    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUarray *, const CUDA_ARRAY_DESCRIPTOR *) = (CUresult(*)(CUarray *, const CUDA_ARRAY_DESCRIPTOR *))dlsym(cuda_handle, "cuArrayCreate");
    ret = hookFunc(pHandle, pAllocateArray);
DONE:
    TimeProfileDestroy(pprof);
    return ret;
}
CUresult cuArrayCreate_v2(CUarray *pHandle, const CUDA_ARRAY_DESCRIPTOR *pAllocateArray) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuArrayCreate_v2");
    CUresult ret;
    ret = cuArrayCreate_helper(pAllocateArray);
    if (ret != CUDA_SUCCESS) {
        goto DONE;
    }

    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUarray *, const CUDA_ARRAY_DESCRIPTOR *) = (CUresult(*)(CUarray *, const CUDA_ARRAY_DESCRIPTOR *))dlsym(cuda_handle, "cuArrayCreate_v2");
    ret = hookFunc(pHandle, pAllocateArray);
DONE:
    TimeProfileDestroy(pprof);
    return ret;
}
CUresult cuArray3DCreate(CUarray *pHandle, const CUDA_ARRAY3D_DESCRIPTOR *pAllocateArray) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuArray3DCreate");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUarray *, const CUDA_ARRAY3D_DESCRIPTOR *) = (CUresult(*)(CUarray *, const CUDA_ARRAY3D_DESCRIPTOR *))dlsym(cuda_handle, "cuArray3DCreate");
    CUresult rs = hookFunc(pHandle, pAllocateArray);
    TimeProfileDestroy(pprof);
    return rs;
}
CUresult cuArray3DCreate_v2(CUarray *pHandle, const CUDA_ARRAY3D_DESCRIPTOR *pAllocateArray) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuArray3DCreate_v2");
    CUresult ret = cuArray3DCreate_helper(pAllocateArray);
    if (ret != CUDA_SUCCESS) {
        goto DONE;
    }
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUarray *, const CUDA_ARRAY3D_DESCRIPTOR *) = (CUresult(*)(CUarray *, const CUDA_ARRAY3D_DESCRIPTOR *))dlsym(cuda_handle, "cuArray3DCreate_v2");
    ret = hookFunc(pHandle, pAllocateArray);
DONE:
    TimeProfileDestroy(pprof);
    return ret;
}
CUresult cuMipmappedArrayCreate(CUmipmappedArray *pHandle, const CUDA_ARRAY3D_DESCRIPTOR *pMipmappedArrayDesc, unsigned int numMipmapLevels) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMipmappedArrayCreate");
    size_t used = 0;

    size_t request_size = 0;
    size_t base_size = 0;
    CUresult ret;

    if (g_vcuda_config.enable) {
        base_size = get_array_base_size(pMipmappedArrayDesc->Format);
        request_size = base_size * pMipmappedArrayDesc->NumChannels * pMipmappedArrayDesc->Height * pMipmappedArrayDesc->Width * pMipmappedArrayDesc->Depth;

        atomic_action(PIDS_CONFIG_PATH, get_used_gpu_memory, (void *)&used);
        HLOG(INFO, "%s %d %d", Marshal(g_vcuda_config), used, request_size);

        if (used + request_size > g_vcuda_config.gpu_memory) {
            ret = CUDA_ERROR_OUT_OF_MEMORY;
            goto DONE;
        }
    }

    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUmipmappedArray *, const CUDA_ARRAY3D_DESCRIPTOR *, unsigned int) = (CUresult(*)(CUmipmappedArray *, const CUDA_ARRAY3D_DESCRIPTOR *, unsigned int))dlsym(cuda_handle, "cuMipmappedArrayCreate");
    ret = hookFunc(pHandle, pMipmappedArrayDesc, numMipmapLevels);
DONE:
    TimeProfileDestroy(pprof);
    return ret;
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
CUresult cuMemFree_v2(CUdeviceptr dptr) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemFree_v2");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr) = (CUresult(*)(CUdeviceptr))dlsym(cuda_handle, "cuMemFree_v2");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(dptr);
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
CUresult cuArrayDestroy(CUarray hArray) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuArrayDestroy");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUarray) = (CUresult(*)(CUarray))dlsym(cuda_handle, "cuArrayDestroy");
    HOOK_CHECK(hookFunc);
    CUresult rs = hookFunc(hArray);
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

CUresult cuMapMemory(CUdeviceptr *dptr, size_t bytesize, const CUmemAccessDesc *desc, size_t count) {
    HLOG(INFO, "cuMapMemory dptr=%llx %p bytesize=%lu", *dptr, bytesize);
    if (*dptr == 0) {
        cuMemAddressReserve(dptr, bytesize, 0, 0, 0);
    };
    //    cuMemMap(dptr, bytesize, 0, handle, 0);
    int dc;
    cuDeviceGetCount(&dc);
    for (int i = 0; i < count; i++) {
        //        CUdevice device;
        //        int ordinal;
        //        cuDeviceGet(&device, ordinal);
        cuMemSetAccess(*dptr, bytesize, desc, count);
    }
    return 0;
}
CUresult cuVGPUViewAllocator(void **ptr, size_t size) {
    CUdevice currentDevice;
    if (cuCtxGetDevice(&currentDevice) != CUDA_SUCCESS)
        return CUDA_ERROR_OUT_OF_MEMORY;

    CUmemAllocationProp prop;
    memset(&prop, 0, sizeof(CUmemAllocationProp));
    prop.type = CU_MEM_ALLOCATION_TYPE_PINNED;
    prop.location.type = CU_MEM_LOCATION_TYPE_DEVICE;
    prop.location.id = currentDevice;

    size_t granularity = 0;
    if (cuMemGetAllocationGranularity(&granularity, &prop, CU_MEM_ALLOC_GRANULARITY_MINIMUM) != CUDA_SUCCESS) {
        return CUDA_ERROR_OUT_OF_MEMORY;
    }

    size = ((size - 1) / granularity + 1) * granularity;

    CUdeviceptr dptr;
    if (cuMemAddressReserve(&dptr, size, 0, 0, 0) != CUDA_SUCCESS) {
        return CUDA_ERROR_OUT_OF_MEMORY;
    }

    CUmemGenericAllocationHandle allocationHandle;
    if (cuMemCreate(&allocationHandle, size, &prop, 0) != CUDA_SUCCESS) {
        return CUDA_ERROR_OUT_OF_MEMORY;
    }

    if (cuMemMap(dptr, size, 0, allocationHandle, 0) != CUDA_SUCCESS) {
        return CUDA_ERROR_OUT_OF_MEMORY;
    }

    if (cuMemRelease(allocationHandle) != CUDA_SUCCESS) {
        return CUDA_ERROR_OUT_OF_MEMORY;
    }

    CUmemAccessDesc accessDescriptor;
    accessDescriptor.location.id = prop.location.id;
    accessDescriptor.location.type = prop.location.type;
    accessDescriptor.flags = CU_MEM_ACCESS_FLAGS_PROT_READWRITE;
    if (cuMemSetAccess(dptr, size, &accessDescriptor, 1) != CUDA_SUCCESS) {
        return CUDA_ERROR_OUT_OF_MEMORY;
    }

    *ptr = (void *)dptr;

    return CUDA_SUCCESS;
}
CUresult cuMemoryFree(void *ptr, size_t size) {
    if (!ptr) {
        return CUDA_SUCCESS;
    }
    CUdevice currentDevice;
    if (cuCtxGetDevice(&currentDevice) != CUDA_SUCCESS)
        return CUDA_ERROR_OUT_OF_MEMORY;
    CUmemAllocationProp prop = {};
    memset(&prop, 0, sizeof(CUmemAllocationProp));
    prop.type = CU_MEM_ALLOCATION_TYPE_PINNED;
    prop.location.type = CU_MEM_LOCATION_TYPE_DEVICE;
    prop.location.id = currentDevice;

    size_t granularity = 0;
    if (cuMemGetAllocationGranularity(&granularity, &prop, CU_MEM_ALLOC_GRANULARITY_MINIMUM) != CUDA_SUCCESS) {
        return CUDA_ERROR_OUT_OF_MEMORY;
    }

    size = ((size - 1) / granularity + 1) * granularity;

    if (cuMemUnmap((CUdeviceptr)ptr, size) != CUDA_SUCCESS || cuMemAddressFree((CUdeviceptr)ptr, size) != CUDA_SUCCESS) {
        return CUDA_ERROR_INVALID_VALUE;
    }

    return CUDA_SUCCESS;
}
CUresult cuMemoryAllocate(CUdeviceptr *dptr, size_t bytesize) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemoryAllocate");
    void *cuda_handle = dlopen(CudaSo(), RTLD_GLOBAL | RTLD_LAZY);
    CUresult (*hookFunc)(CUdeviceptr *, size_t) = (CUresult(*)(CUdeviceptr *, size_t))dlsym(cuda_handle, "cuMemAlloc_v2");
    CUresult rs = hookFunc(dptr, bytesize);
    cuMemAllocManaged(dptr, bytesize, 0);
    cuMapMemory(dptr, bytesize, 0, 0);
    TimeProfileDestroy(pprof);
    return rs;
}
CUresult cuUnmapMemory(CUdeviceptr dptr, size_t bytesize) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("cuMemoryAllocate");
    cuMemUnmap(dptr, bytesize);
    cuMemRelease(0);
    cuMemAddressFree(dptr, bytesize);
    void *xx;
    cuPointerGetAttribute(&xx, 0, dptr + bytesize);
    TimeProfileDestroy(pprof);
    return CUDA_SUCCESS;
}