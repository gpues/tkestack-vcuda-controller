#include "include/all.h"

extern int record_nvml_map[0x10];
extern unsigned int cuda_to_nvml_map[0x10];
extern unsigned int virtual_nvml_devices[17];
extern unsigned int virtual_devices[17];
extern unsigned int virtual_map[0x10];
extern void *cuda_library_entry[1024];
extern sharedRegionT *global_config;
extern vgpuDevice vdevices[16];
extern bool duplicate_devices;

CUuuid cudart_interface_guid = {
    .bytes =
        {
            0x6b,
            0xd5,
            0xfb,
            0x6c,
            0x5b,
            0xf4,
            0xe7,
            0x4a,
            0x89,
            0x87,
            0xd9,
            0x39,
            0x12,
            0xfd,
            0x9d,
            0xf9,
        },
};
size_t assigning_virtual_pcibusID() {
    printf("%s %s", __FILE__, __LINE__);
    printf("%s %s", __FILE__, __LINE__); // 分配虚拟的 busID
    const void ***ppExportTable = NULL;
    LINFO("assigning_virtual_pcibusID num=%d", virtual_devices[0]);

    cuGetExportTable(ppExportTable, (CUuuid *)&cudart_interface_guid);
    int offset = 0;
    for (int i = 0; i < virtual_devices[0]; ++i) {
        printf("%s %s", __FILE__, __LINE__);
        printf("%s %s", __FILE__, __LINE__);
        if (!vdevices[cuda_to_nvml_map[i]].busIdLegacy) {
            printf("%s %s", __FILE__, __LINE__);
            printf("%s %s", __FILE__, __LINE__);
            vdevices[cuda_to_nvml_map[i]].busIdLegacy = malloc(0x10);
            LINFO("Hijacking %s", "cuDeviceGetPCIBusId");
            CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetPCIBusId, vdevices[i].busIdLegacy, 0x10, virtual_map[i]);

            if (virtual_map[i] == virtual_map[i - 1] && i) {
                printf("%s %s", __FILE__, __LINE__);
                printf("%s %s", __FILE__, __LINE__);
                ++offset;
                // 虚拟设备,末尾自增
                vdevices[i].busIdLegacy[strlen(vdevices[i].busIdLegacy) - 1] = (char)(vdevices[i].busIdLegacy[strlen(vdevices[i].busIdLegacy) - 1] + offset);
            }
            else {
                printf("%s %s", __FILE__, __LINE__);
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
    printf("%s %s", __FILE__, __LINE__);
    signed int i;
    if (!ctx)
        return 0LL;
    for (i = 0; i < virtual_nvml_devices[0]; ++i) {
        printf("%s %s", __FILE__, __LINE__);
        if (ctx == *vdevices[i].ctx || ctx == *vdevices[i].vctx)
            return *vdevices[i].vctx;
    }
    return ctx;
}

CUcontext ctx_reversemap(CUcontext ctx) {
    printf("%s %s", __FILE__, __LINE__);
    signed int i;
    if (!ctx)
        return 0LL;
    for (i = 0; i < virtual_nvml_devices[0]; ++i) {
        printf("%s %s", __FILE__, __LINE__);
        if (ctx == *vdevices[i].vctx)
            return *vdevices[i].ctx;
    }
    return ctx;
}

CUresult cuDeviceCanAccessPeer(int *canAccessPeer, CUdevice dev, CUdevice peerDev) {
    printf("%s %s", __FILE__, __LINE__);
    LINFO("cuDeviceCanAccessPeer %d %d %d", dev, peerDev, dup);
    if (duplicate_devices) {
        printf("%s %s", __FILE__, __LINE__);
        *canAccessPeer = 0;
        return 0LL;
    }
    else {
        printf("%s %s", __FILE__, __LINE__);
        LINFO("Hijacking %s", "cuDeviceCanAccessPeer");
        return CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceCanAccessPeer, canAccessPeer, dev, peerDev);
    }
}

CUresult cuDeviceGet(CUdevice *device, int ordinal) {
    printf("%s %s", __FILE__, __LINE__);
    LINFO("into cuDeviceGet ordinal=%d", ordinal);
    *device = ordinal;
    return CUDA_SUCCESS;
}

CUresult cuDeviceGetAttribute(int *pi, CUdevice_attribute attrib, CUdevice dev) {
    printf("%s %s", __FILE__, __LINE__);
    if (duplicate_devices == 1 && (attrib == CU_DEVICE_ATTRIBUTE_COOPERATIVE_LAUNCH || attrib == CU_DEVICE_ATTRIBUTE_COOPERATIVE_MULTI_DEVICE_LAUNCH)) {
        printf("%s %s", __FILE__, __LINE__);
        *pi = 0;
        LINFO("cuDeviceGetAttribute dev=%d attrib=%d disable cooperative", dev, attrib);
        return 0LL;
    }
    else {
        printf("%s %s", __FILE__, __LINE__);
        LINFO("Hijacking %s", "cuDeviceGetAttribute");
        CUresult res = CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetAttribute, pi, attrib, virtual_map[dev]);

        LINFO("[%d]cuDeviceGetAttribute dev=%d->%d attrib=%d %d", res, dev, virtual_map[dev], attrib, *pi);
        return res;
    }
}

CUresult cuDeviceGetByPCIBusId(CUdevice *dev, const char *pciBusId) {
    printf("%s %s", __FILE__, __LINE__);
    LINFO("into cuDeviceGetByPCIBusId pciBusid=%s", pciBusId);
    int i;
    for (i = 0;; ++i) {
        printf("%s %s", __FILE__, __LINE__);
        if (i >= (int)virtual_devices[0]) {
            printf("%s %s", __FILE__, __LINE__);
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
    printf("%s %s", __FILE__, __LINE__);
    LINFO("Hijacking %s", "cuDeviceGetCount");
    CUresult res = CUDA_ENTRY_CALL(cuda_library_entry, cuDeviceGetCount, count);
    if (res) {
        printf("%s %s", __FILE__, __LINE__);
        LWARN("cuDeviceGetCount failed,res=%d", res);
        return res;
    }
    else {
        printf("%s %s", __FILE__, __LINE__);
        *count = (int)virtual_devices[0];
        return 0LL;
    }
}

CUresult cuDeviceGetPCIBusId(char *pciBusId, int len, CUdevice dev) {
    printf("%s %s", __FILE__, __LINE__);
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
    printf("%s %s", __FILE__, __LINE__);
    LINFO("Hijacking %s", "cuDeviceTotalMem_v2");
    ensure_initialized();
    *bytes = get_current_device_memory_limit(dev);
    return CUDA_SUCCESS;
}

CUresult cuDriverGetVersion(int *driverVersion) {
    printf("%s %s", __FILE__, __LINE__);
    LINFO("Hijacking %s", "cuDriverGetVersion");
    CUresult res = CUDA_ENTRY_CALL(cuda_library_entry, cuDriverGetVersion, driverVersion);
    if (!res) {
        printf("%s %s", __FILE__, __LINE__);
        if (driverVersion) {
            printf("%s %s", __FILE__, __LINE__);
            LINFO("driver version=%d", *driverVersion);
        }
    }
    return res;
}