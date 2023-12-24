#include "include/all.h"

extern void *cuda_library_entry[1024];
extern vgpuDevice vdevices[16];
extern unsigned int cuda_to_nvml_map[0x10];
extern bool duplicate_devices;
extern unsigned int virtual_map[0x10];
extern u_int64_t context_size;
extern unsigned int virtual_nvml_devices[17];

CUresult cuCtxCreate_v2(CUcontext *pctx, unsigned int flags, CUdevice dev) {
    printf("%s %s", __FILE__, __LINE__);
    printf("%s %s", __FILE__, __LINE__);
    LINFO("into cuCtxCreate pctx=%p flags=%d dev=%d", pctx, flags, dev);
    LINFO("Hijacking %s", "cuCtxCreate_v2");
    CUresult res = CUDA_ENTRY_CALL(cuda_library_entry, cuCtxCreate_v2, pctx, flags, dev);
    if (vdevices[cuda_to_nvml_map[dev]].vctx) {
        printf("%s %s", __FILE__, __LINE__);
        printf("%s %s", __FILE__, __LINE__);
        LERROR(" Duplicate cuCtxCreate, this may indicate errors");
    }
    else {
        printf("%s %s", __FILE__, __LINE__);
        printf("%s %s", __FILE__, __LINE__);
        vdevices[cuda_to_nvml_map[dev]].vctx = pctx;
        if (!vdevices[cuda_to_nvml_map[dev]].ctx)
            vdevices[cuda_to_nvml_map[dev]].ctx = vdevices[cuda_to_nvml_map[dev]].vctx;
    }
    if (!vdevices[cuda_to_nvml_map[dev]].add_gpu_flag) {
        printf("%s %s", __FILE__, __LINE__);
        printf("%s %s", __FILE__, __LINE__);
        add_gpu_device_memory_usage(getpid(), dev, context_size, 0LL);
    }
    vdevices[cuda_to_nvml_map[dev]].add_gpu_flag = 1;
    return res;
}

CUresult cuCtxDestroy_v2(CUcontext ctx) {
    printf("%s %s", __FILE__, __LINE__);
    printf("%s %s", __FILE__, __LINE__);
    LINFO("into cuCtxDestroy_v2 ctx=%p", ctx);
    LINFO("Hijacking %s", "cuCtxDestroy_v2");
    CUcontext c = ctx_remap(ctx);
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxDestroy_v2, c);
}

CUresult cuCtxGetApiVersion(CUcontext ctx, unsigned int *version) {
    printf("%s %s", __FILE__, __LINE__);
    printf("%s %s", __FILE__, __LINE__);
    LINFO("into cuCtxGetApiVersion ctx=%p", ctx);
    LINFO("Hijacking %s", "cuCtxGetApiVersion");
    CUcontext c = ctx_remap(ctx);
    CUresult res = CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetApiVersion, c, version);
    if (res) {
        printf("%s %s", __FILE__, __LINE__);
        printf("%s %s", __FILE__, __LINE__);
        LERROR("cuCtxGetApiVersion res=%d", res);
        exit(0);
    }
    return 0LL;
}

CUresult cuCtxGetCacheConfig(CUfunc_cache *pconfig) {
    printf("%s %s", __FILE__, __LINE__);
    printf("%s %s", __FILE__, __LINE__);
    LINFO("Hijacking %s", "cuCtxGetCacheConfig");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetCacheConfig, pconfig);
}

CUresult cuCtxGetCurrent(CUcontext *pctx) {
    printf("%s %s", __FILE__, __LINE__);
    printf("%s %s", __FILE__, __LINE__);
    LINFO("into cuCtxGetCurrent ctx=%lx", *pctx);
    LINFO("Hijacking %s", "cuCtxGetCurrent");
    CUresult res = CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetCurrent, pctx);

    CUcontext c = *pctx;
    *pctx = ctx_reversemap(*pctx);
    if (c != *pctx && !duplicate_devices) {
        printf("%s %s", __FILE__, __LINE__);
        LWARN("getCurrent Not found");
    }
    return res;
}

CUresult cuDevicePrimaryCtxRetain(CUcontext *pctx, CUdevice dev) {
    printf("%s %s", __FILE__, __LINE__);
    CUresult res = CUDA_SUCCESS;
    LINFO("vctx=%lx dev=%d virtual_map=%d context_size=%d", *(size_t **)vdevices[dev].vctx, dev, virtual_map[dev], context_size);
    if (context_size) {
        printf("%s %s", __FILE__, __LINE__);
        if (dev > 0 && virtual_map[dev] == virtual_map[dev - 1]) {
            printf("%s %s", __FILE__, __LINE__);
            if (!vdevices[cuda_to_nvml_map[dev]].vctx) {
                printf("%s %s", __FILE__, __LINE__);
                LINFO("Hijacking %s", "cuCtxCreate_v2");
                res = CUDA_ENTRY_CALL(cuda_library_entry, cuCtxCreate_v2, &vdevices[cuda_to_nvml_map[dev]].vctx, 0LL, virtual_map[dev]);
                if (res) {
                    printf("%s %s", __FILE__, __LINE__);
                    LWARN("device primary ctx retain: createctx failed:%d", res);
                    return res;
                }
                if (!vdevices[cuda_to_nvml_map[dev]].ctx) {
                    printf("%s %s", __FILE__, __LINE__);
                    vdevices[cuda_to_nvml_map[dev]].ctx = vdevices[cuda_to_nvml_map[dev]].vctx;
                }
                LWARN("Newed ctx=%lx", vdevices[cuda_to_nvml_map[dev]].vctx);
            }
            *pctx = *vdevices[cuda_to_nvml_map[dev]].vctx;
        }
        else {
            printf("%s %s", __FILE__, __LINE__);
            LINFO("Hijacking %s", "cuDevicePrimaryCtxRetain");
            res = CUDA_ENTRY_CALL(cuda_library_entry, cuDevicePrimaryCtxRetain, pctx, virtual_map[dev]);
            if (!vdevices[cuda_to_nvml_map[dev]].vctx) {
                printf("%s %s", __FILE__, __LINE__);
                vdevices[cuda_to_nvml_map[dev]].vctx = pctx;

                if (!vdevices[cuda_to_nvml_map[dev]].ctx) {
                    printf("%s %s", __FILE__, __LINE__);
                    vdevices[cuda_to_nvml_map[dev]].ctx = vdevices[cuda_to_nvml_map[dev]].vctx;
                }
            }
        }
        if (!vdevices[cuda_to_nvml_map[dev]].add_gpu_flag) {
            printf("%s %s", __FILE__, __LINE__);
            add_gpu_device_memory_usage(getpid(), dev, context_size, 0LL);
        }
        vdevices[cuda_to_nvml_map[dev]].add_gpu_flag = 1;
        pctx = vdevices[cuda_to_nvml_map[dev]].ctx;

        LINFO("after primary ctx retain dev=%d res=%d pctx=%lx", *pctx);
        return res;
    }
    else {
        printf("%s %s", __FILE__, __LINE__);
        LINFO("Hijacking %s", "cuDevicePrimaryCtxRetain");
        res = CUDA_ENTRY_CALL(cuda_library_entry, cuDevicePrimaryCtxRetain, pctx, virtual_map[dev]);
        if (!res) {
            printf("%s %s", __FILE__, __LINE__);
            vdevices[cuda_to_nvml_map[dev]].add_gpu_flag = 1;
        }

        return res;
    }
}

CUresult cuCtxGetDevice(CUdevice *device) {
    printf("%s %s", __FILE__, __LINE__);
    LINFO("Hijacking %s", "cuCtxGetDevice");
    CUresult res = CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetDevice, device);
    if (!res || duplicate_devices) {
        printf("%s %s", __FILE__, __LINE__);
        if (duplicate_devices) {
            printf("%s %s", __FILE__, __LINE__);
            LINFO("Hijacking %s", "cuCtxGetCurrent");
            CUcontext c;
            CUresult cRes = CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetCurrent, &c);
            if (c) {
                printf("%s %s", __FILE__, __LINE__);
                if ((unsigned int)getdevicefromctx(device, c)) {
                    printf("%s %s", __FILE__, __LINE__);
                    LERROR("cuCtxGetDevice Not Found. tid=%ld ctx=%p:%p", c, *(const void **)&vdevices[2]);
                    return 201LL;
                }
                else {
                    printf("%s %s", __FILE__, __LINE__);
                    LINFO("cuCtxGetDevice tid=%ld ctx=%lx dev=%d", pthread_self(), c, *device);
                    return cRes;
                }
            }
            else {
                printf("%s %s", __FILE__, __LINE__);
                return 201LL;
            }
        }
        else {
            printf("%s %s", __FILE__, __LINE__);
            return res;
        }
    }
    else {
        printf("%s %s", __FILE__, __LINE__);
        LINFO("cuCtxGetDevice failed");
        return res;
    }
}

CUresult cuCtxGetFlags(unsigned int *flags) {
    printf("%s %s", __FILE__, __LINE__);
    LINFO("into cuCtxGetFlags flags=%p", flags);
    LINFO("Hijacking %s", "cuCtxGetFlags");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetFlags, flags);
}

CUresult cuCtxGetLimit(size_t *pvalue, CUlimit limit) {
    printf("%s %s", __FILE__, __LINE__);
    LINFO("into cuCtxGetLimit pvalue=%p", pvalue);
    LINFO("Hijacking %s", "cuCtxGetLimit");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetLimit, pvalue, limit);
}

CUresult cuCtxGetSharedMemConfig(CUsharedconfig *pConfig) {
    printf("%s %s", __FILE__, __LINE__);
    LINFO("cuCtxGetSharedMemConfig pConfig=%p", pConfig);
    LINFO("Hijacking %s", "cuCtxGetSharedMemConfig");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetSharedMemConfig, pConfig);
}

CUresult cuCtxGetStreamPriorityRange(int *leastPriority, int *greatestPriority) {
    printf("%s %s", __FILE__, __LINE__);
    LINFO("Hijacking %s", "cuCtxGetStreamPriorityRange");
    CUresult res = CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetStreamPriorityRange, leastPriority, greatestPriority);
    if (res) {
        printf("%s %s", __FILE__, __LINE__);
        LWARN("cuCtxGetStreamPriorityRange err=%d", res);
    }
    return res;
}

CUresult cuCtxPopCurrent_v2(CUcontext *pctx) {
    printf("%s %s", __FILE__, __LINE__);
    LINFO("Hijacking %s", "cuCtxPopCurrent_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetLimit, pctx);
}

CUresult cuCtxPushCurrent_v2(CUcontext ctx) {
    printf("%s %s", __FILE__, __LINE__);
    LINFO("cuCtxPushCurrent ctx=%p", ctx);
    LINFO("Hijacking %s", "cuCtxPushCurrent_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxPushCurrent_v2, ctx);
}

CUresult cuCtxSetCacheConfig(CUfunc_cache config) {
    printf("%s %s", __FILE__, __LINE__);
    LINFO("cuCtxSetCacheConfig config=%d", config);
    LINFO("Hijacking %s", "cuCtxSetCacheConfig");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxSetCacheConfig, config);
}

CUresult cuCtxSetCurrent(CUcontext ctx) {
    printf("%s %s", __FILE__, __LINE__);
    LINFO("cuCtxSetCurrent %lx", ctx);
    if (ctx) {
        printf("%s %s", __FILE__, __LINE__);
        int index = 0;
        CUcontext vctx = 0;
        for (int i = 0; i < virtual_nvml_devices[0]; ++i) {
            printf("%s %s", __FILE__, __LINE__);
            if (ctx == *vdevices[i].ctx || ctx == *vdevices[i].vctx) {
                printf("%s %s", __FILE__, __LINE__);
                vctx = *vdevices[i].vctx;
                index = i;
                break;
            }
        }
        if ((size_t)vctx == 0xFFFFFFFFLL) {
            printf("%s %s", __FILE__, __LINE__);
            LINFO("cuCtxSetCurrent: Ctx Not Found %lx", ctx);
            exit(0);
        }
        if (!vctx) {
            printf("%s %s", __FILE__, __LINE__);
            LINFO("Hijacking %s", "cuCtxCreate_v2");
            CUresult cRes = CUDA_ENTRY_CALL(cuda_library_entry, cuCtxCreate_v2, &vdevices[index].vctx, 0LL, virtual_map[index]);
            if (cRes) {
                printf("%s %s", __FILE__, __LINE__);
                LINFO("reate context failed %d", cRes);
            }
            else {
                printf("%s %s", __FILE__, __LINE__);
                LINFO("New virtual ctx created:%d:%lx:%lx", index, vdevices[index].vctx, ctx);
                vctx = *vdevices[index].vctx;
                add_gpu_device_memory_usage(getpid(), index, context_size, 0LL);
            }
        }
        LINFO("Hijacking %s", "cuCtxSetCurrent");
        CUresult cRes = CUDA_ENTRY_CALL(cuda_library_entry, cuCtxSetCurrent, vctx);
        if (cRes) {
            printf("%s %s", __FILE__, __LINE__);
            LWARN("cuCtxSetCurrent failed res=%d", cRes);
        }
        return cRes;
    }
    else {
        printf("%s %s", __FILE__, __LINE__);
        LINFO("Hijacking %s", "cuCtxSetCurrent");
        return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxSetCurrent, 0);
    }
}

CUresult cuCtxSetLimit(CUlimit limit, size_t value) {
    printf("%s %s", __FILE__, __LINE__);
    LINFO("Hijacking %s", "cuCtxSetLimit");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxSetLimit, limit, value);
}

CUresult cuCtxSetSharedMemConfig(CUsharedconfig config) {
    printf("%s %s", __FILE__, __LINE__);
    LINFO("Hijacking %s", "cuCtxSetSharedMemConfig");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxSetSharedMemConfig, config);
}

CUresult cuCtxSynchronize(void) {
    printf("%s %s", __FILE__, __LINE__);
    LINFO("Hijacking %s", "cuCtxSynchronize");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxSynchronize);
}

CUresult cuDevicePrimaryCtxGetState(CUdevice dev, unsigned int *flags, int *active) {
    printf("%s %s", __FILE__, __LINE__);
    LINFO("Hijacking %s", "cuDevicePrimaryCtxGetState");
    int _active;
    CUresult res = CUDA_ENTRY_CALL(cuda_library_entry, cuDevicePrimaryCtxGetState, virtual_map[dev], flags, &_active);
    *active = _active;
    *active = vdevices[cuda_to_nvml_map[dev]].add_gpu_flag;
    return res;
}

CUresult cuDevicePrimaryCtxRelease_v2(CUdevice dev) {
    printf("%s %s", __FILE__, __LINE__);
    LINFO("Hijacking %s", "cuDevicePrimaryCtxRelease_v2");
    CUresult res = CUDA_ENTRY_CALL(cuda_library_entry, cuDevicePrimaryCtxRelease_v2, virtual_map[dev]);
    LINFO("into cuDevicePrimaryCtxRelease dev=%d ret=%d", dev, res);
    if (vdevices[cuda_to_nvml_map[dev]].add_gpu_flag == 1) {
        printf("%s %s", __FILE__, __LINE__);
        vdevices[cuda_to_nvml_map[dev]].add_gpu_flag = 0;
        return res;
    }
    else {
        printf("%s %s", __FILE__, __LINE__);
        LINFO("primary context not retained:%d", dev);
        return res;
    }
}

CUresult cuDevicePrimaryCtxSetFlags_v2(CUdevice dev, unsigned int flags) {
    printf("%s %s", __FILE__, __LINE__);
    LINFO("into cuDevicePrimaryCtxSetFlags dev=%d flags=%d", dev, flags);
    LINFO("Hijacking %s", "cuDevicePrimaryCtxSetFlags_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDevicePrimaryCtxRelease_v2, virtual_map[dev], flags);
}
