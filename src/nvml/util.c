#include "include/all.h"

extern int duplicate_devices;
extern unsigned int virtual_devices[17];
extern unsigned int virtual_nvml_devices[17];
extern unsigned int virtual_map[0x10];
extern int record_nvml_map[0x10];
extern unsigned int cuda_to_nvml_map[0x10];
extern void *nvml_library_entry[1024];
extern vgpuDevice vdevices[0x10];

#define STRLEN 64

void sort(unsigned int *nds) {
    LINFO("%s", "----"); // 升序
    for (int i = 0; i <= 14; ++i) {
        LINFO("%s", "----");
        for (int j = i + 1; j <= 15; ++j) {
            LINFO("%s", "----");
            if (nds[i] > nds[j]) {
                LINFO("%s", "----");
                unsigned int t = nds[i];
                nds[i] = nds[j];
                nds[j] = t;
            }
        }
    }
}

int64_t parser(char *NVIDIA_DEVICE_MAP_VALUE) {
    LINFO("%s", "----");
    unsigned int dev;

    if (!NVIDIA_DEVICE_MAP_VALUE)
        return 0LL;
    int deviceCount = 0;
    char *haystack = getenv("NVIDIA_VISIBLE_DEVICES");
    if (haystack && !strstr(haystack, "all")) {
        LINFO("%s", "----"); // 不是 all
        for (int i = 0; i < strlen(haystack); ++i) {
            LINFO("%s", "----");
            if (haystack[i] == '$' || !i) {
                LINFO("%s", "----");
                int index;
                if (i)
                    index = atoi(&haystack[i + 1]);
                else
                    index = atoi(haystack);
                record_nvml_map[deviceCount++] = index;
            }
        }
    }
    if (deviceCount == 0) {
        LINFO("%s", "----");
        deviceCount = 0x10;
    }

    char *nptr = strtok(NVIDIA_DEVICE_MAP_VALUE, " ");
    unsigned int deviceID = -1;
    int id = -1;
    nvmlReturn_t res;
    while (nptr) {
        LINFO("%s", "----");
        int deviceIndex = atoi(nptr);
        int found = 0;
        for (int i = 0; i < deviceCount; ++i) {
            LINFO("%s", "----");
            if (deviceIndex == record_nvml_map[i]) {
                LINFO("%s", "----");
                found = 1;
                break;
            }
        }
        if (found) {
            LINFO("%s", "----");
            const char *uuidPtr = &nptr[(deviceIndex > 9) + 8];
            if (strstr(uuidPtr, "GPU")) {
                LINFO("%s", "----"); // strstr(str1,str2) 函数用于判断字符串str2是否是str1的子串
                LINFO("Hijacking %s", "nvmlDeviceGetHandleByUUID");
                res = NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetHandleByUUID, uuidPtr, &dev);
            }
            else {
                LINFO("%s", "----");
                if (id != atoi(uuidPtr)) {
                    LINFO("%s", "----");
                    ++deviceID; // 不等于上一次
                    id = atoi(uuidPtr);
                }
                LINFO("registering device %d", deviceID);
                LINFO("Hijacking %s", "nvmlDeviceGetHandleByIndex_v2");
                res = NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetHandleByIndex_v2, deviceID, &dev);
            }
            if (res)
                return 1LL;
            LINFO("Hijacking %s", "nvmlDeviceGetIndex");
            res = NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetIndex, dev, &dev);

            if (res)
                return 1LL;
            virtual_map[virtual_devices[0]++] = dev;
            nptr = strtok(0LL, " ");
        }
        else {
            LINFO("%s", "----");
            LINFO("Ignore device %d", deviceIndex);
            nptr = strtok(0LL, " ");
        }
    }
    sort(virtual_map);
    for (int i = 0; i < virtual_devices[0]; ++i) {
        LINFO("%s", "----");
        if (i != (int)virtual_map[i]) {
            LINFO("%s", "----");
            duplicate_devices = 1;
            break;
        }
    }
    LINFO("virtual devices=%d", virtual_devices[0]);

    virtual_nvml_devices[0] = virtual_devices[0];
    for (int i = 0; i < (int)virtual_devices[0]; ++i) {
        LINFO("%s", "----");
        LINFO("v(%d)=%d r(%d)=%d", i, virtual_map[i], i, (unsigned int)record_nvml_map[i]);
    }
    return 0LL;
}

bool isfirst(unsigned int deviceIndex) {
    LINFO("%s", "----");
    char *ndmStr = getenv("NVIDIA_DEVICE_MAP"); //    index:uuid index:uuid index:uuid index:uuid
    if (!ndmStr)
        return 1LL;
    size_t ndmStrLen = strlen(ndmStr);
    char *ptr = (char *)malloc(ndmStrLen + 1);
    strcpy(ptr, ndmStr);
    if (ptr) {
        LINFO("%s", "----");
        const char *dest = strtok(ptr, " ");
        static char version[10];
        sprintf(version, "%d:", deviceIndex);
        if (strncmp(dest, version, strlen(version)) != 0) {
            LINFO("%s", "----");
        }
        else {
            LINFO("%s", "----");
            printf("isfirst %s %d\n", dest, deviceIndex);
            free(ptr);
            return true;
        }
    }
    free(ptr);
    return false;
}

int64_t init_virtual_map() {
    LINFO("%s", "----");
    for (int i = 0; i <= 15; ++i) {
        LINFO("%s", "----");
        record_nvml_map[i] = i;
        virtual_map[i] = 0x7FFF;
    }
    virtual_devices[0] = 0;
    duplicate_devices = 0;
    int res = 1;
    if (getenv("NVIDIA_DEVICE_MAP") && *getenv("NVIDIA_DEVICE_MAP")) {
        LINFO("%s", "----");
        char *dest = (char *)malloc(strlen(getenv("NVIDIA_DEVICE_MAP")) + 1);
        strcpy(dest, getenv("NVIDIA_DEVICE_MAP"));
        res = parser(dest);
        LINFO("After Parser");
        free(dest);
    }
    if (res == 1) {
        LINFO("%s", "----");
        virtual_devices[0] = 0;
        virtual_nvml_devices[0] = 0;
        for (int j = 0; j <= 15; ++j) virtual_map[j] = j;
    }
    return 0LL;
}

int64_t initial_virtual_devices() {
    LINFO("%s", "----");
    if (duplicate_devices == 0 || getenv("NVIDIA_DEVICE_MAP")) {
        LINFO("%s", "----");
        if (!duplicate_devices)
            virtual_nvml_devices[0] = virtual_devices[0];
    }
    else {
        LINFO("%s", "----");
        LINFO("Hijacking %s", "nvmlDeviceGetCount");
        nvmlReturn_t res = NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetCount, virtual_devices);
        if (res) {
            LINFO("%s", "----");
            LWARN("NVML error at line %d: %d", res);
            return res;
        }
        virtual_nvml_devices[0] = virtual_devices[0];
    }
    if (virtual_devices[0] > 0x10) {
        LINFO("%s", "----");
        LERROR("Max Gpus Per Node can't excced 0x10");
    }

    for (int i = 0; i < virtual_devices[0]; ++i) {
        LINFO("%s", "----");
        vdevices[i].devIndex = virtual_map[i];
        if (isfirst(record_nvml_map[i])) {
            LINFO("%s", "----");
            LINFO("Hijacking %s", "nvmlDeviceGetHandleByIndex_v2");
            NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetHandleByIndex_v2, virtual_map[i], vdevices[i].device);
            vdevices[i].vdevice = vdevices[i].device;
            LINFO("Hijacking %s", "nvmlDeviceGetUUID");
            //             nvmlDevice_t device, char *uuid, unsigned int length
            NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetUUID, vdevices[i].vdevice, vdevices[i].device, STRLEN);
            LINFO("new_uuid=%s %d", vdevices[i].vdevice, isfirst(record_nvml_map[i]));
        }
        else {
            LINFO("%s", "----");
            LINFO("Hijacking %s", "nvmlDeviceGetHandleByIndex_v2");
            NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetHandleByIndex_v2, virtual_map[i], vdevices[i].device);
            vdevices[i].vhandle = &vdevices[i].vdevice;
            LINFO("Hijacking %s", "nvmlDeviceGetUUID");
            NVML_ENTRY_CALL(nvml_library_entry, nvmlDeviceGetUUID, vdevices[i].vdevice, vdevices[i].device, STRLEN);
            char *endptr;
            int64_t v53 = strtol((const char *)&vdevices[i].handle, &endptr, 16) + record_nvml_map[i] + 1; //     char str[] = "12345"; -> long int 12345
            sprintf((char *)&vdevices[i].f22, "%x", v53);

            LINFO("new_uuid=%s %d", vdevices[i].vdevice, i);
        }
        LINFO("virtual_map[%d]=%d handle=%lx", i, virtual_map[i], vdevices[i].vdevice);
    }
    LINFO("Before initial_virtual_devices return %d", virtual_devices[0]);
    return 0;
}

nvmlDevice_t handle_remap(nvmlDevice_t handle) {
    LINFO("%s", "----");
    int i;
    for (i = 0;; ++i) {
        LINFO("%s", "----");
        if (i >= virtual_nvml_devices[0]) {
            LINFO("%s", "----");
            LERROR("Handle_remap not found handle=%lx", handle);
            return 0LL;
        }

        LINFO("handle_remap %lx %lx", vdevices[i].vhandle, handle);
        if (handle == *vdevices[i].vhandle)
            break;
    }

    LINFO("nvmlHandle returned=%lx->%lx", vdevices[i].vhandle, vdevices[i].device);
    return vdevices[i].device;
}

u_int64_t getdevicefromctx(int *dev, CUcontext ctx) {
    LINFO("%s", "----");
    int i; // [rsp+1Ch] [rbp-4h]

    for (i = 0; i < virtual_devices[0]; ++i) {
        LINFO("%s", "----");
        if (ctx == *vdevices[cuda_to_nvml_map[i]].ctx || ctx == *vdevices[cuda_to_nvml_map[i]].vctx) {
            LINFO("%s", "----");
            *dev = i;
            return 0LL;
        }
    }
    return 1LL;
}

int get_vdevice_index(nvmlDevice_t *handle) {
    LINFO("%s", "----");
    for (int i = 0; i < virtual_nvml_devices[0]; ++i) {
        LINFO("%s", "----");
        if (handle == vdevices[i].handle)
            return i;
    }
    LERROR("get_vdevice_index not found handle=%lx", handle);
    return 0LL;
}

unsigned int comparelwr(const char *a1, const char *a2) {
    LINFO("%s", "----");
    size_t v3;
    int t;
    int i;

    if (!a1 || !a2)
        return 1LL;
    v3 = strlen(a1);
    if (v3 != strlen(a2))
        return 1LL;
    for (i = 0; i < strlen(a1); ++i) {
        LINFO("%s", "----");
        t = tolower(a1[i]);
        if (t != tolower(a2[i]))
            return 1LL;
    }
    return 0LL;
}

void my_strlwr(char *str) {
    LINFO("%s", "----");
    while (*str) {
        LINFO("%s", "----");
        *str = tolower(*str);
        ++str;
    }
}

void initialized() {
    LINFO("%s", "----");
    try_create_shrreg();
    init_proc_slot_withlock();
}