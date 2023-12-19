#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include "include/base.h"
#include "include/cuda-helper.h"
#include "include/func.h"
extern int record_nvml_map[0x10];
extern unsigned int cuda_to_nvml_map[0x10];
extern void *nvml_library_entry[];
extern unsigned int virtual_nvml_devices[17];
extern unsigned int virtual_devices[17];
extern unsigned int virtual_map[0x10];
extern void *cuda_library_entry[];
extern sharedRegionT *flags;
extern device vdevices[16];

size_t assigning_virtual_pcibusID() {
    const void **ppExportTable;
    LINFO("assigning_virtual_pcibusID num=%d", virtual_devices[0]);
    CUuuid pExportTableId = cudart_interface_guid[0];
    //    cuGetExportTable(ppExportTable, &pExportTableId);
    int offset = 0;
    for (int i = 0; i < (int)virtual_devices[0]; ++i) {
        if (!vdevices[cuda_to_nvml_map[i]].vctx) {
            vdevices[cuda_to_nvml_map[i]].busIdLegacy = malloc(0x10);
            LINFO("Hijacking %s", "cuDeviceGetPCIBusId");
            CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetPCIBusId, vdevices[i].busIdLegacy, 0x10, virtual_map[i]);

            if (virtual_map[i] == virtual_map[i - 1] && i) {
                ++offset;
                // 虚拟设备,末尾自增
                vdevices[i].busIdLegacy[strlen(vdevices[i].busIdLegacy) - 1] = (char)(vdevices[i].busIdLegacy[strlen(vdevices[i].busIdLegacy) - 1] + offset);
            }
            else {
                offset = 0;
            }
            vdevices[cuda_to_nvml_map[i]].add_gpu_flag = 0;
            vdevices[cuda_to_nvml_map[i]].ctx = 0;
            vdevices[cuda_to_nvml_map[i]].vctx = 0;
            vdevices[cuda_to_nvml_map[i]].index = i;

            LINFO("Assigning pcibusid %s to %d:%ld", *vdevices[i].busIdLegacy, i, *vdevices[i].vhandle);
        }
    }
    return 0LL;
}

CUcontext ctx_remap(CUcontext ctx) {
    signed int i; // [rsp+14h] [rbp-4h]

    if (!ctx)
        return 0LL;
    for (i = 0; i < virtual_nvml_devices[0]; ++i) {
        if (ctx == vdevices[i].ctx || ctx == vdevices[i].vctx)
            return vdevices[i].vctx;
    }
    return ctx;
}
CUcontext ctx_reversemap(CUcontext ctx) {
    signed int i; // [rsp+14h] [rbp-4h]

    if (!ctx)
        return 0LL;
    for (i = 0; i < virtual_nvml_devices[0]; ++i) {
        if (ctx == vdevices[i].vctx)
            return vdevices[i].ctx;
    }
    return ctx;
}