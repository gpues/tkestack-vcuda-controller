#include <regex.h>

#include "include/all.h"

void *nvml_library_entry[1024];
extern vgpuDevice vdevices[16];
extern unsigned int virtual_nvml_devices[17];
extern pthread_once_t init_virtual_map_flag;
extern pthread_once_t init_virtual_map_flag_1;
extern char *NVML_FUNCS[1024];
extern char driver_version[FILENAME_MAX];

void load_nvml_libraries() {
    printf("%s %s", __FILE__, __LINE__);
    LINFO("Start hijacking");
    read_version_from_proc((char *)&driver_version);

    char nvml_filename[FILENAME_MAX];
    snprintf(nvml_filename, FILENAME_MAX - 1, "%s.%s", NVML_LIBRARY_PREFIX, driver_version);
    LINFO("%s", nvml_filename);
    nvml_filename[FILENAME_MAX - 1] = '\0';

    void *nvml_handle = dlopen(nvml_filename, RTLD_GLOBAL | RTLD_LAZY);
    if (!nvml_handle) {
        printf("%s %s", __FILE__, __LINE__);
        LINFO("can't find library %s", nvml_filename);
    }
    for (int64_t i = 0; i < NVML_ENTRY_END; ++i) {
        printf("%s %s", __FILE__, __LINE__);
        void *hookFunc = dlsym(nvml_handle, NVML_FUNCS[i]);
        nvml_library_entry[i] = hookFunc;
    }
    LINFO("loaded_nvml_libraries");
    //    dlclose(nvml_handle);
}

nvmlReturn_t nvmlDeviceGetUUID(nvmlDevice_t device, char *uuid, unsigned int length) {
    printf("%s %s", __FILE__, __LINE__);
    LINFO("Hijacking %s", "nvmlDeviceGetUUID");

    nvmlReturn_t res = NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetUUID, handle_remap(device), uuid, length);
    if (res)
        return res;

    unsigned int vdevice_index = get_vdevice_index((nvmlDevice_t *)device);
    strcpy(uuid, (char *)vdevices[vdevice_index].vdevice);
    return 0LL;
}

nvmlReturn_t nvmlDeviceGetPciInfo_v3(nvmlDevice_t device, nvmlPciInfo_t *pci) {
    printf("%s %s", __FILE__, __LINE__);
    LINFO("Hijacking %s", "nvmlDeviceGetPciInfo_v3");

    nvmlReturn_t res = NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPciInfo, handle_remap(device), pci);
    unsigned int vdevice_index = get_vdevice_index((nvmlDevice_t *)device);
    if (vdevices[vdevice_index].busIdLegacy) {
        printf("%s %s", __FILE__, __LINE__);
        vdevice_index = get_vdevice_index((nvmlDevice_t *)device);
        strncpy(pci->busId, (char *)vdevices[vdevice_index].busIdLegacy, 0x10);
    }
    return res;
}

nvmlReturn_t nvmlDeviceGetPciInfo_v2(nvmlDevice_t device, nvmlPciInfo_t *pci) {
    printf("%s %s", __FILE__, __LINE__);
    LINFO("Hijacking %s", "nvmlDeviceGetPciInfo_v2");

    nvmlReturn_t res = NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPciInfo_v2, handle_remap(device), pci);
    unsigned int vdevice_index = get_vdevice_index((nvmlDevice_t *)device);
    if (vdevices[vdevice_index].busIdLegacy) {
        printf("%s %s", __FILE__, __LINE__);
        vdevice_index = get_vdevice_index((nvmlDevice_t *)device);
        strncpy(pci->busId, (char *)vdevices[vdevice_index].busIdLegacy, 0x10);
    }
    return res;
}

nvmlReturn_t nvmlDeviceGetPciInfo(nvmlDevice_t device, nvmlPciInfo_t *pci) {
    printf("%s %s", __FILE__, __LINE__);
    LINFO("Hijacking %s", "nvmlDeviceGetPciInfo");

    nvmlReturn_t res = NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetPciInfo, handle_remap(device), pci);
    unsigned int vdevice_index = get_vdevice_index((nvmlDevice_t *)device);
    if (vdevices[vdevice_index].busIdLegacy) {
        printf("%s %s", __FILE__, __LINE__);
        vdevice_index = get_vdevice_index((nvmlDevice_t *)device);
        strncpy(pci->busId, (char *)vdevices[vdevice_index].busIdLegacy, 0x10);
    }
    return res;
}

nvmlReturn_t nvmlDeviceGetHandleByPciBusId_v2(const char *pciBusId, nvmlDevice_t *device) {
    printf("%s %s", __FILE__, __LINE__);
    LINFO("Hijacking %s", "nvmlDeviceGetHandleByPciBusId_v2");

    char dest[24];
    strncpy(dest, pciBusId, 0x10);
    my_strlwr(dest);

    for (int i = 0; i < virtual_nvml_devices[0]; ++i) {
        printf("%s %s", __FILE__, __LINE__);
        if (!(unsigned int)comparelwr(vdevices[i].busIdLegacy, dest)) {
            printf("%s %s", __FILE__, __LINE__);
            *device = *(nvmlDevice_t *)(char *)vdevices[i].busIdLegacy;
            return 0LL;
        }
    }
    return 2LL;
}

void nvml_preInit() {
    printf("%s %s", __FILE__, __LINE__);
    load_env_from_file("/overrideEnv");
    load_nvml_libraries();
}

void nvml_postInit() {
    printf("%s %s", __FILE__, __LINE__);
    init_virtual_map();
    initial_virtual_devices();
}

nvmlReturn_t nvmlInit() {
    printf("%s %s", __FILE__, __LINE__);
    LINFO("nvmlInit");
    pthread_once(&init_virtual_map_flag, (void (*)(void))nvml_preInit);
    LINFO("Hijacking %s", "nvmlInit_v2");
    nvmlReturn_t res = NVML_ENTRY_CALL(nvml_library_entry, nvmlInit_v2);
    pthread_once(&init_virtual_map_flag_1, (void (*)(void))nvml_postInit);
    return res;
}

nvmlReturn_t nvmlInit_v2() {
    printf("%s %s", __FILE__, __LINE__);
    LINFO("nvmlInit_v2");
    pthread_once(&init_virtual_map_flag, (void (*)(void))nvml_preInit);
    LINFO("Hijacking %s", "nvmlInit_v2");
    nvmlReturn_t res = NVML_ENTRY_CALL(nvml_library_entry, nvmlInit_v2);
    pthread_once(&init_virtual_map_flag_1, (void (*)(void))nvml_postInit);
    return res;
}

nvmlReturn_t nvmlInitWithFlags(unsigned int flags) {
    printf("%s %s", __FILE__, __LINE__);
    LINFO("nvmlInitWithFlags");
    pthread_once(&init_virtual_map_flag, (void (*)(void))nvml_preInit);
    LINFO("Hijacking %s", "nvmlInitWithFlags");
    nvmlReturn_t res = NVML_ENTRY_CALL(nvml_library_entry, nvmlInitWithFlags, flags);
    pthread_once(&init_virtual_map_flag_1, (void (*)(void))nvml_postInit);
    return res;
}

const char *nvmlErrorString(nvmlReturn_t result) {
    printf("%s %s", __FILE__, __LINE__);
    LINFO("Hijacking %s", "nvmlErrorString");
    const char *(*hookFunc)(nvmlReturn_t) = (const char *(*)(nvmlReturn_t))NVML_FIND_ENTRY(nvml_library_entry, nvmlErrorString);
    return hookFunc(result);
}
