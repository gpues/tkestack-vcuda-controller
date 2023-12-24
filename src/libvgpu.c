#include "include/all.h"

extern u_int64_t context_size;
extern vgpuDevice vdevices[0x10];
extern unsigned int virtual_nvml_devices[17];
extern int allocmode;
extern int pidfound;
extern void *cuda_library_entry[1024];
extern pthread_once_t pre_cuinit_flag;
extern pthread_once_t post_cuinit_flag;
extern unsigned int record_cuda_map[16];
extern int record_nvml_map[0x10];
extern unsigned int cuda_to_nvml_map[0x10];
extern unsigned int virtual_map[0x10];

extern int env_utilization_switch;

size_t map_cuda_visible_devices() {
    printf("%s %s", __FILE__, __LINE__);
    parse_cuda_visible_env();
    return 0LL;
}

int postInit() {
    printf("%s %s", __FILE__, __LINE__);
    char *env;

    map_cuda_visible_devices();
    if (getenv("CUDA_OVERSUBSCRIBE") && (env = getenv("CUDA_OVERSUBSCRIBE"), !strcmp(env, "true")))
        allocmode = 0;
    else
        allocmode = 2;
    allocator_init();
    lock_shrreg();
    assigning_virtual_pcibusID();
    unlock_shrreg();
    try_lock_unified_lock();
    size_t success = set_task_pid();
    try_unlock_unified_lock();

    LINFO("Initialized");
    if (success) {
        printf("%s %s", __FILE__, __LINE__);
        LWARN("SET_TASK_PID FAILED.");
        pidfound = 0;
    }
    else {
        printf("%s %s", __FILE__, __LINE__);
        pidfound = 1;
    }
    env_utilization_switch = set_env_utilization_switch();
    return init_utilization_watcher();
}
void preInit() {
    printf("%s %s", __FILE__, __LINE__);
    LINFO("Initializing.....");
    load_cuda_libraries();
    nvmlInit();
    for (int i = 0; i <= 15; ++i) {
        printf("%s %s", __FILE__, __LINE__);
        record_cuda_map[i] = record_nvml_map[i];
        cuda_to_nvml_map[i] = i;
    }
    ensure_initialized();
    map_cuda_visible_devices();
}
CUresult cuInit(unsigned int Flags) {
    printf("%s %s", __FILE__, __LINE__);
    LINFO("Hijacking %s", "cuInit");
    pthread_once(&pre_cuinit_flag, preInit);
    CUresult res = CUDA_ENTRY_CALL(cuda_library_entry, cuInit, Flags);
    if (res) {
        printf("%s %s", __FILE__, __LINE__);
        LERROR("cuInit failed:%d", res);
        return res;
    }
    else {
        printf("%s %s", __FILE__, __LINE__);
        pthread_once(&post_cuinit_flag, (void (*)(void))postInit);
        return 0LL;
    }
}
