#include "include/base.h"
#include "include/cuda-helper.h"
#include "include/func.h"
#include "include/nvml-helper.h"
#include "include/nvml.h"
#include "stdio.h"
#include "string.h"
unsigned int cuda_to_nvml_map[0x10];
extern device vdevices[0x10];
extern unsigned int virtual_map[0x10];
extern u_int64_t context_size;
extern void *cuda_library_entry[];

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
            *pctx = vdevices[cuda_to_nvml_map[dev]].vctx;
        }
        else {
            LINFO("Hijacking %s", "cuDevicePrimaryCtxRetain");
            res = CUDA_ENTRY_CALL(cuda_library_entry, cuDevicePrimaryCtxRetain, pctx, virtual_map[dev]);
            if (!vdevices[cuda_to_nvml_map[dev]].vctx) {
                vdevices[cuda_to_nvml_map[dev]].vctx = *pctx;

                if (!vdevices[cuda_to_nvml_map[dev]].ctx) {
                    vdevices[cuda_to_nvml_map[dev]].ctx = vdevices[cuda_to_nvml_map[dev]].vctx;
                }
            }
        }
        if (!vdevices[cuda_to_nvml_map[dev]].add_gpu_flag) {
            add_gpu_device_memory_usage(getpid(), dev, context_size, 0LL);
        }
        vdevices[cuda_to_nvml_map[dev]].add_gpu_flag = 1;
        *pctx = vdevices[cuda_to_nvml_map[dev]].ctx;

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
