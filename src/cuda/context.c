#include "include/all.h"

extern void *cuda_library_entry[];
extern device vdevices[16];
extern unsigned int cuda_to_nvml_map[0x10];
extern bool duplicate_devices;
extern unsigned int virtual_map[0x10];
extern u_int64_t context_size;
extern unsigned int virtual_nvml_devices[17];

CUresult cuCtxCreate_v2(CUcontext *pctx, unsigned int flags, CUdevice dev) {
    LINFO("into cuCtxCreate pctx=%p flags=%d dev=%d", pctx, flags, dev);
    LINFO("Hijacking %s", "cuCtxCreate_v2");
    CUresult res = CUDA_ENTRY_CALL(cuda_library_entry, cuCtxCreate_v2, pctx, flags, dev);
    if (vdevices[cuda_to_nvml_map[dev]].vctx) {
        LERROR(" Duplicate cuCtxCreate, this may indicate errors");
    }
    else {
        vdevices[cuda_to_nvml_map[dev]].vctx = pctx;
        if (!vdevices[cuda_to_nvml_map[dev]].ctx)
            vdevices[cuda_to_nvml_map[dev]].ctx = vdevices[cuda_to_nvml_map[dev]].vctx;
    }
    if (!vdevices[cuda_to_nvml_map[dev]].add_gpu_flag) {
        add_gpu_device_memory_usage(getpid(), dev, context_size, 0LL);
    }
    vdevices[cuda_to_nvml_map[dev]].add_gpu_flag = 1;
    return res;
}

CUresult cuCtxDestroy_v2(CUcontext ctx) {
    LINFO("into cuCtxDestroy_v2 ctx=%p", ctx);
    LINFO("Hijacking %s", "cuCtxDestroy_v2");
    CUcontext c = ctx_remap(ctx);
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxDestroy_v2, c);
}

CUresult cuCtxGetApiVersion(CUcontext ctx, unsigned int *version) {
    LINFO("into cuCtxGetApiVersion ctx=%p", ctx);
    LINFO("Hijacking %s", "cuCtxGetApiVersion");
    CUcontext c = ctx_remap(ctx);
    CUresult res = CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetApiVersion, c, version);
    if (res) {
        LERROR("cuCtxGetApiVersion res=%d", res);
        exit(0);
    }
    return 0LL;
}

CUresult cuCtxGetCacheConfig(CUfunc_cache *pconfig) {
    LINFO("Hijacking %s", "cuCtxGetCacheConfig");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetCacheConfig, pconfig);
}

CUresult cuCtxGetCurrent(CUcontext *pctx) {
    LINFO("into cuCtxGetCurrent ctx=%lx", *pctx);
    LINFO("Hijacking %s", "cuCtxGetCurrent");
    CUresult res = CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetCurrent, pctx);

    CUcontext c = *pctx;
    *pctx = ctx_reversemap(*pctx);
    if (c != *pctx && !duplicate_devices) {
        LWARN("getCurrent Not found");
    }
    return res;
}

CUresult cuDevicePrimaryCtxRetain(CUcontext *pctx, CUdevice dev) {
    CUresult res;
    LINFO("vctx=%lx dev=%d virtual_map=%d context_size=%d", *(size_t **)vdevices[dev].vctx, dev, virtual_map[dev], context_size);
    if (context_size) {
        if (dev > 0 && virtual_map[dev] == virtual_map[dev - 1]) {
            if (!vdevices[cuda_to_nvml_map[dev]].vctx) {
                LINFO("Hijacking %s", "cuCtxCreate_v2");
                res = CUDA_ENTRY_CALL(cuda_library_entry, cuCtxCreate_v2, &vdevices[cuda_to_nvml_map[dev]].vctx, 0LL, virtual_map[dev]);
                if (res) {
                    LWARN("device primary ctx retain: createctx failed:%d", res);
                    return res;
                }
                if (!vdevices[cuda_to_nvml_map[dev]].ctx) {
                    vdevices[cuda_to_nvml_map[dev]].ctx = vdevices[cuda_to_nvml_map[dev]].vctx;
                }
                LWARN("Newed ctx=%lx", vdevices[cuda_to_nvml_map[dev]].vctx);
            }
            pctx = vdevices[cuda_to_nvml_map[dev]].vctx;
        }
        else {
            LINFO("Hijacking %s", "cuDevicePrimaryCtxRetain");
            res = CUDA_ENTRY_CALL(cuda_library_entry, cuDevicePrimaryCtxRetain, pctx, virtual_map[dev]);
            if (!vdevices[cuda_to_nvml_map[dev]].vctx) {
                vdevices[cuda_to_nvml_map[dev]].vctx = pctx;

                if (!vdevices[cuda_to_nvml_map[dev]].ctx) {
                    vdevices[cuda_to_nvml_map[dev]].ctx = vdevices[cuda_to_nvml_map[dev]].vctx;
                }
            }
        }
        if (!vdevices[cuda_to_nvml_map[dev]].add_gpu_flag) {
            add_gpu_device_memory_usage(getpid(), dev, context_size, 0LL);
        }
        vdevices[cuda_to_nvml_map[dev]].add_gpu_flag = 1;
        pctx = vdevices[cuda_to_nvml_map[dev]].ctx;

        LINFO("after primary ctx retain dev=%d res=%d pctx=%lx", *pctx);
        return res;
    }
    else {
        LINFO("Hijacking %s", "cuDevicePrimaryCtxRetain");
        res = CUDA_ENTRY_CALL(cuda_library_entry, cuDevicePrimaryCtxRetain, pctx, virtual_map[dev]);
        if (!res) {
            vdevices[cuda_to_nvml_map[dev]].add_gpu_flag = 1;
        }

        return res;
    }
}

CUresult cuCtxGetDevice(CUdevice *device) {
    LINFO("Hijacking %s", "cuCtxGetDevice");
    CUresult res = CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetDevice, device);
    if (!res || duplicate_devices) {
        if (duplicate_devices) {
            LINFO("Hijacking %s", "cuCtxGetCurrent");
            CUcontext c;
            CUresult cRes = CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetCurrent, &c);
            if (c) {
                if ((unsigned int)getdevicefromctx(device, c)) {
                    LERROR("cuCtxGetDevice Not Found. tid=%ld ctx=%p:%p", c, *(const void **)&vdevices[2]);
                    return 201LL;
                }
                else {
                    LINFO("cuCtxGetDevice tid=%ld ctx=%lx dev=%d", pthread_self(), c, *device);
                    return cRes;
                }
            }
            else {
                return 201LL;
            }
        }
        else {
            return res;
        }
    }
    else {
        LINFO("cuCtxGetDevice failed");
        return res;
    }
}

CUresult cuCtxGetFlags(unsigned int *flags) {
    LINFO("into cuCtxGetFlags flags=%p", flags);
    LINFO("Hijacking %s", "cuCtxGetFlags");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetFlags, flags);
}

CUresult cuCtxGetLimit(size_t *pvalue, CUlimit limit) {
    LINFO("into cuCtxGetLimit pvalue=%p", pvalue);
    LINFO("Hijacking %s", "cuCtxGetLimit");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetLimit, pvalue, limit);
}

CUresult cuCtxGetSharedMemConfig(CUsharedconfig *pConfig) {
    LINFO("cuCtxGetSharedMemConfig pConfig=%p", pConfig);
    LINFO("Hijacking %s", "cuCtxGetSharedMemConfig");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetSharedMemConfig, pConfig);
}

CUresult cuCtxGetStreamPriorityRange(int *leastPriority, int *greatestPriority) {
    LINFO("Hijacking %s", "cuCtxGetStreamPriorityRange");
    CUresult res = CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetStreamPriorityRange, leastPriority, greatestPriority);
    if (res) {
        LWARN("cuCtxGetStreamPriorityRange err=%d", res);
    }
    return res;
}

CUresult cuCtxPopCurrent_v2(CUcontext *pctx) {
    LINFO("Hijacking %s", "cuCtxPopCurrent_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxGetLimit, pctx);
}

CUresult cuCtxPushCurrent_v2(CUcontext ctx) {
    LINFO("cuCtxPushCurrent ctx=%p", ctx);
    LINFO("Hijacking %s", "cuCtxPushCurrent_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxPushCurrent_v2, ctx);
}

CUresult cuCtxSetCacheConfig(CUfunc_cache config) {
    LINFO("cuCtxSetCacheConfig config=%d", config);
    LINFO("Hijacking %s", "cuCtxSetCacheConfig");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxSetCacheConfig, config);
}

CUresult cuCtxSetCurrent(CUcontext ctx) {
    LINFO("cuCtxSetCurrent %lx", ctx);
    if (ctx) {
        int index = 0;
        CUcontext vctx;
        for (int i = 0; i < virtual_nvml_devices[0]; ++i) {
            if (ctx == *vdevices[i].ctx || ctx == *vdevices[i].vctx) {
                vctx = *vdevices[i].vctx;
                index = i;
                break;
            }
        }
        if ((size_t)vctx == 0xFFFFFFFFLL) {
            LINFO("cuCtxSetCurrent: Ctx Not Found %lx", ctx);
            exit(0);
        }
        if (!vctx) {
            LINFO("Hijacking %s", "cuCtxCreate_v2");
            CUresult cRes = CUDA_ENTRY_CALL(cuda_library_entry, cuCtxCreate_v2, &vdevices[index].vctx, 0LL, virtual_map[index]);
            if (cRes) {
                LINFO("reate context failed %d", cRes);
            }
            else {
                LINFO("New virtual ctx created:%d:%lx:%lx", index, vdevices[index].vctx, ctx);
                vctx = *vdevices[index].vctx;
                add_gpu_device_memory_usage(getpid(), index, context_size, 0LL);
            }
        }
        LINFO("Hijacking %s", "cuCtxSetCurrent");
        CUresult cRes = CUDA_ENTRY_CALL(cuda_library_entry, cuCtxSetCurrent, vctx);
        if (cRes) {
            LWARN("cuCtxSetCurrent failed res=%d", cRes);
        }
        return cRes;
    }
    else {
        LINFO("Hijacking %s", "cuCtxSetCurrent");
        return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxSetCurrent, 0);
    }
}

CUresult cuCtxSetLimit(CUlimit limit, size_t value) {
    LINFO("Hijacking %s", "cuCtxSetLimit");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxSetLimit, limit, value);
}

CUresult cuCtxSetSharedMemConfig(CUsharedconfig config) {
    LINFO("Hijacking %s", "cuCtxSetSharedMemConfig");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxSetSharedMemConfig, config);
}

CUresult cuCtxSynchronize(void) {
    LINFO("Hijacking %s", "cuCtxSynchronize");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuCtxSynchronize);
}

CUresult cuDevicePrimaryCtxGetState(CUdevice dev, unsigned int *flags, int *active) {
    LINFO("Hijacking %s", "cuDevicePrimaryCtxGetState");
    int _active;
    CUresult res = CUDA_ENTRY_CALL(cuda_library_entry, cuDevicePrimaryCtxGetState, virtual_map[dev], flags, &_active);
    *active = _active;
    *active = vdevices[cuda_to_nvml_map[dev]].add_gpu_flag;
    return res;
}

CUresult cuDevicePrimaryCtxRelease_v2(CUdevice dev) {
    LINFO("Hijacking %s", "cuDevicePrimaryCtxRelease_v2");
    CUresult res = CUDA_ENTRY_CALL(cuda_library_entry, cuDevicePrimaryCtxRelease_v2, virtual_map[dev]);
    LINFO("into cuDevicePrimaryCtxRelease dev=%d ret=%d", dev, res);
    if (vdevices[cuda_to_nvml_map[dev]].add_gpu_flag == 1) {
        vdevices[cuda_to_nvml_map[dev]].add_gpu_flag = 0;
        return res;
    }
    else {
        LINFO("primary context not retained:%d", dev);
        return res;
    }
}

CUresult cuDevicePrimaryCtxSetFlags_v2(CUdevice dev, unsigned int flags) {
    char *v2;        // rax
    char *v3;        // r12
    pthread_t v4;    // rbx
    unsigned int v5; // eax
    char *v6;        // rax
    char *v7;        // r12
    pthread_t v8;    // rbx
    unsigned int v9; // eax

    LINFO("into cuDevicePrimaryCtxSetFlags dev=%d flags=%d", dev, flags);
    LINFO("Hijacking %s", "cuDevicePrimaryCtxSetFlags_v2");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuDevicePrimaryCtxRelease_v2, virtual_map[dev], flags);
}
