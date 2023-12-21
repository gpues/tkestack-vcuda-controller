#include "include/all.h"

extern int record_nvml_map[0x10];
extern unsigned int cuda_to_nvml_map[0x10];
extern void *nvml_library_entry[];
extern unsigned int virtual_nvml_devices[17];
extern unsigned int virtual_devices[17];
extern unsigned int virtual_map[0x10];
extern void *cuda_library_entry[];
extern sharedRegionT *global_config;
extern device vdevices[16];
extern bool duplicate_devices;

size_t assigning_virtual_pcibusID() {
    const void **ppExportTable;
    LINFO("assigning_virtual_pcibusID num=%d", virtual_devices[0]);
    CUuuid pExportTableId = cudart_interface_guid[0];
        cuGetExportTable(ppExportTable, &pExportTableId);
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
    signed int i;
    if (!ctx)
        return 0LL;
    for (i = 0; i < virtual_nvml_devices[0]; ++i) {
        if (ctx == *vdevices[i].ctx || ctx == *vdevices[i].vctx)
            return *vdevices[i].vctx;
    }
    return ctx;
}

CUcontext ctx_reversemap(CUcontext ctx) {
    signed int i;
    if (!ctx)
        return 0LL;
    for (i = 0; i < virtual_nvml_devices[0]; ++i) {
        if (ctx == *vdevices[i].vctx)
            return *vdevices[i].ctx;
    }
    return ctx;
}

CUresult cuDeviceCanAccessPeer(int *canAccessPeer, CUdevice dev, CUdevice peerDev) {
    LINFO("cuDeviceCanAccessPeer %d %d %d", dev, peerDev, dup);
    if (duplicate_devices) {
        *canAccessPeer = 0;
        return 0LL;
    }
    else {
        LINFO("Hijacking %s", "cuDeviceCanAccessPeer");
        return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceCanAccessPeer, canAccessPeer, dev, peerDev);
    }
}

CUresult cuDeviceGet(CUdevice *device, int ordinal) {
    LINFO("into cuDeviceGet ordinal=%d", ordinal);
    *device = ordinal;
    return 0LL;
}

CUresult cuDeviceGetAttribute(int *pi, CUdevice_attribute attrib, CUdevice dev) {
    if (duplicate_devices == 1 && (attrib == CU_DEVICE_ATTRIBUTE_COOPERATIVE_LAUNCH || attrib == CU_DEVICE_ATTRIBUTE_COOPERATIVE_MULTI_DEVICE_LAUNCH)) {
        *pi = 0;
        LINFO("cuDeviceGetAttribute dev=%d attrib=%d disable cooperative", dev, attrib);
        return 0LL;
    }
    else {
        LINFO("Hijacking %s", "cuDeviceGetAttribute");
        CUresult res = CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetAttribute, pi, attrib, virtual_map[dev]);

        LINFO("[%d]cuDeviceGetAttribute dev=%d->%d attrib=%d %d", res, dev, virtual_map[dev], attrib, *pi);
        return res;
    }
}

CUresult cuDeviceGetByPCIBusId(CUdevice *dev, const char *pciBusId) {
    LINFO("into cuDeviceGetByPCIBusId pciBusid=%s", pciBusId);
    int i;
    for (i = 0;; ++i) {
        if (i >= (int)virtual_devices[0]) {
            LINFO("Hijacking %s", "cuDeviceGetByPCIBusId");
            return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetByPCIBusId, dev, pciBusId);
        }
        if (!strcmp(*(const char **)&vdevices[i].busIdLegacy, pciBusId))
            break;
    }
    *dev = i;
    LINFO("cuDeviceGetByPCIBusId pciBusid=%s dev=%d matched", pciBusId, *dev);
    return 0LL;
}

CUresult cuDeviceGetCount(int *count) {
    LINFO("Hijacking %s", "cuDeviceGetCount");
    CUresult res = CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetCount, count);
    if (res) {
        LWARN("cuDeviceGetCount failed,res=%d", res);
        return res;
    }
    else {
        *count = (int)virtual_devices[0];
        return 0LL;
    }
}

CUresult cuDeviceGetPCIBusId(char *pciBusId, int len, CUdevice dev) {
    LINFO("into cuDeviceGetPCIBusId dev=%d len=%d", dev, len);
    LINFO("Hijacking %s", "cuDeviceGetPCIBusId");
    CUresult res = CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetPCIBusId, pciBusId, len, virtual_map[dev]);

    LINFO("PCIBUSID=%s %s", pciBusId, res);
    strncpy(pciBusId, *(const char **)&vdevices[38 * cuda_to_nvml_map[dev] + 8], (int)len);
    if (!res)
        return 0LL;

    LWARN("Driver error at %d: %d", __LINE__, res);
    return res;
}
CUresult cuDeviceTotalMem_v2(size_t *bytes, CUdevice dev) {
    LINFO("Hijacking %s", "cuDeviceTotalMem_v2");
    ensure_initialized();
    *bytes = get_current_device_memory_limit(dev);
    return CUDA_SUCCESS;
}

CUresult cuDriverGetVersion(int *driverVersion) {
    LINFO("Hijacking %s", "cuDriverGetVersion");
    dlsym(0, "cuDriverGetVersion");
    CUresult res = CUDA_ENTRY_CALL(cuda_library_entry, cuDriverGetVersion, driverVersion);
    if (!res) {
        if (driverVersion) {
            LINFO("driver version=%d", *driverVersion);
        }
    }
}