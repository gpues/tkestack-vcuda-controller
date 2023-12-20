#include <pthread.h>
#include <stdlib.h>

#include "include/base.h"
#include "include/func.h"
#include "include/nvml-helper.h"
#include "stdio.h"
#include "string.h"

extern void *nvml_library_entry[];
extern device vdevices[16];
extern unsigned int virtual_nvml_devices[17];
static pthread_once_t init_virtual_map_flag = PTHREAD_ONCE_INIT;
static pthread_once_t init_virtual_map_flag_1 = PTHREAD_ONCE_INIT;
extern bool real_dlsym;

nvmlReturn_t nvmlDeviceGetUUID(nvmlDevice_t device, char *uuid, unsigned int length) {
    LINFO("Hijacking %s", "nvmlDeviceGetUUID");

    nvmlReturn_t res = NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetUUID, handle_remap((u_int64_t *)device), uuid, length);
    if (res)
        return res;

    unsigned int vdevice_index = get_vdevice_index((nvmlDevice_t *)device);
    strcpy(uuid, (char *)vdevices[vdevice_index].vdevice);
    return 0LL;
}

nvmlReturn_t nvmlDeviceGetPciInfo_v3(nvmlDevice_t device, nvmlPciInfo_t *pci) {
    LINFO("Hijacking %s", "nvmlDeviceGetPciInfo_v3");

    nvmlReturn_t res = NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPciInfo, handle_remap((u_int64_t *)device), pci);
    unsigned int vdevice_index = get_vdevice_index((nvmlDevice_t *)device);
    if (vdevices[vdevice_index].busIdLegacy) {
        vdevice_index = get_vdevice_index((nvmlDevice_t *)device);
        strncpy(pci->busIdLegacy, (char *)vdevices[vdevice_index].busIdLegacy, 0x10);
    }
    return res;
}

nvmlReturn_t nvmlDeviceGetPciInfo_v2(nvmlDevice_t device, nvmlPciInfo_t *pci) {
    LINFO("Hijacking %s", "nvmlDeviceGetPciInfo_v2");

    nvmlReturn_t res = NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPciInfo_v2, handle_remap((u_int64_t *)device), pci);
    unsigned int vdevice_index = get_vdevice_index((nvmlDevice_t *)device);
    if (vdevices[vdevice_index].busIdLegacy) {
        vdevice_index = get_vdevice_index((nvmlDevice_t *)device);
        strncpy(pci->busIdLegacy, (char *)vdevices[vdevice_index].busIdLegacy, 0x10);
    }
    return res;
}

nvmlReturn_t nvmlDeviceGetPciInfo(nvmlDevice_t device, nvmlPciInfo_t *pci) {
    LINFO("Hijacking %s", "nvmlDeviceGetPciInfo");

    nvmlReturn_t res = NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPciInfo, handle_remap((u_int64_t *)device), pci);
    unsigned int vdevice_index = get_vdevice_index((nvmlDevice_t *)device);
    if (vdevices[vdevice_index].busIdLegacy) {
        vdevice_index = get_vdevice_index((nvmlDevice_t *)device);
        strncpy(pci->busIdLegacy, (char *)vdevices[vdevice_index].busIdLegacy, 0x10);
    }
    return res;
}

nvmlReturn_t nvmlDeviceGetHandleByPciBusId_v2(const char *pciBusId, nvmlDevice_t *device) {
    LINFO("Hijacking %s", "nvmlDeviceGetHandleByPciBusId_v2");

    char dest[24];
    strncpy(dest, pciBusId, 0x10);
    my_strlwr(dest);

    for (int i = 0; i < virtual_nvml_devices[0]; ++i) {
        if (!(unsigned int)comparelwr(vdevices[i].busIdLegacy, dest)) {
            *device = *(nvmlDevice_t *)(char *)vdevices[i].busIdLegacy;
            return 0LL;
        }
    }
    return 2LL;
}

void load_nvml_libraries() {
    char s[4104];

    if (!real_dlsym) {
        LWARN("Warning dlsym not found before libraries load");
        real_dlsym = (__int64(__fastcall *)(_QWORD, _QWORD))_dl_sym(-1LL, "dlsym", dlsym);
        if (!real_dlsym) {
            LERROR("real dlsym not found");
        }
    }
    snprintf(s, 0xFFFuLL, "%s", "libnvidia-ml.so.1");
    s[4095] = 0;
    void *handle = dlopen(s, 4098);
    if (!handle) {
        LINFO("can't find library %s", s);
    }
    for (int i = 0; i <= 242; ++i) {
        LINFO("loading %s:%d", (const char *)*((_QWORD *)&nvml_library_entry + 2 * i + 1), i);
        *((_QWORD *)&nvml_library_entry + 2 * i) = real_dlsym(handle, *((_QWORD *)&nvml_library_entry + 2 * i + 1));
        if (!*((_QWORD *)&nvml_library_entry + 2 * i)) {
            LINFO("can't find function %s in %s", (const char *)*((_QWORD *)&nvml_library_entry + 2 * i + 1), s);
        }
    }
    LINFO("loaded nvml libraries");
    dlclose(handle);
    return;
}

void nvml_preInit() {
    load_env_from_file("/overrideEnv");
    return load_nvml_libraries();
}

void nvml_postInit() {
    init_virtual_map();
    return initial_virtual_devices();
}

nvmlReturn_t nvmlInit() {
    LINFO("nvmlInit");
    pthread_once(&init_virtual_map_flag, (void (*)(void))nvml_preInit);
    LINFO(" Hijacking %s", "nvmlInit_v2");
    nvmlReturn_t res = NVML_ENTRY_CALL(nvml_library_entry, nvmlInit_v2);
    pthread_once(&init_virtual_map_flag_1, (void (*)(void))nvml_postInit);
    return res;
}

nvmlReturn_t nvmlInit_v2() {
    LINFO("nvmlInit_v2");
    pthread_once(&init_virtual_map_flag, (void (*)(void))nvml_preInit);
    LINFO(" Hijacking %s", "nvmlInit_v2");
    nvmlReturn_t res = NVML_ENTRY_CALL(nvml_library_entry, nvmlInit_v2);
    pthread_once(&init_virtual_map_flag_1, (void (*)(void))nvml_postInit);
    return res;
}

nvmlReturn_t nvmlInitWithFlags(unsigned int flags) {
    LINFO("nvmlInitWithFlags");
    pthread_once(&init_virtual_map_flag, (void (*)(void))nvml_preInit);
    LINFO(" Hijacking %s", "nvmlInitWithFlags");
    nvmlReturn_t res = NVML_ENTRY_CALL(nvml_library_entry, nvmlInit_v2, flags);
    pthread_once(&init_virtual_map_flag_1, (void (*)(void))nvml_postInit);
    return res;
}

const char *nvmlErrorString(nvmlReturn_t result) {
    LINFO("Hijacking %s", "nvmlErrorString");
    const char *(*hookFunc)(nvmlReturn_t) = (const char *(*)(nvmlReturn_t))NVML_FIND_ENTRY(nvml_library_entry, nvmlErrorString);
    return hookFunc(result);
}