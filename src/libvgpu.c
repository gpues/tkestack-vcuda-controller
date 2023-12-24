#include "include/all.h"

extern u_int64_t context_size;
extern vmDevice vdevices[0x10];
extern unsigned int virtual_nvml_devices[17];
extern int allocmode;
extern int pidfound;
extern void *cuda_library_entry[1024];
extern pthread_once_t init_virtual_map_flag;
extern pthread_once_t post_cuinit_flag;
extern unsigned int record_cuda_map[16];
extern int record_nvml_map[0x10];
extern unsigned int cuda_to_nvml_map[0x10];
extern unsigned int virtual_map[0x10];
extern int env_utilization_switch;
extern int dlmap_count;
extern void *(*real_dlsym)(void *, const char *);

pthread_once_t pre_cuinit_flag = PTHREAD_ONCE_INIT;
pthread_once_t dlsym_init_flag = PTHREAD_ONCE_INIT;
pthread_mutex_t dlsym_lock;

size_t map_cuda_visible_devices() {
    parse_cuda_visible_env();
    return 0;
}

void postInit() {
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
        LWARN("SET_TASK_PID FAILED.");
        pidfound = 0;
    }
    else {
        pidfound = 1;
    }
    env_utilization_switch = set_env_utilization_switch();
    init_utilization_watcher();
}

void nvml_preInit() {
    LINFO("load_env_from_file");
    load_env_from_file("/overrideEnv");
    load_nvml_libraries();
}

void preInit() {
    LINFO("Initializing.....");
    load_cuda_libraries();
    nvmlInit();
    for (int i = 0; i <= 15; ++i) {
        record_cuda_map[i] = record_nvml_map[i];
        cuda_to_nvml_map[i] = i;
    }
    ensure_initialized();
    LINFO("map_cuda_visible_devices.....");
    map_cuda_visible_devices();
}

CUresult cuInit(unsigned int Flags) {
    LINFO("Hijacking %s", "cuInit");
    pthread_once(&pre_cuinit_flag, preInit);
    CUresult res = CUDA_ENTRY_CALL(cuda_library_entry, cuInit, Flags);
    if (res) {
        LERROR("cuInit failed:%d", res);
        return res;
    }
    else {
        pthread_once(&post_cuinit_flag, postInit);
        return 0LL;
    }
}

void init_dlsym() {
    LINFO("init_dlsym");
    pthread_mutex_init(&dlsym_lock, 0);
    dlmap_count = 0;
    memset(&dlmap, 0, 0x640uLL);
}

int64_t check_dlmap(pthread_t p, void *handle) {
    for (int i = dlmap.count - 1; i >= 0; --i) {
        if (p == dlmap.entries[i].p && handle == dlmap.entries[i].handle) {
            return 1LL;
        }
    }
    int index = dlmap.count % MAX_DLMAP_COUNT;
    dlmap.entries[index].p = p;
    dlmap.entries[index].handle = handle;
    ++dlmap.count;
    return 0LL;
}

void *dlsym(void *handle, char *symbol) {
    LINFO("into dlsym %s %d", symbol, handle);
    void *cuda_func;
    void *nvml_func;
    pthread_once(&dlsym_init_flag, init_dlsym);

    if (!real_dlsym) {
        real_dlsym = (real_dlsym_func)my_dlvsym((void *)0xFFFFFFFFFFFFFFFFLL, "dlsym", "GLIBC_2.2.5");
        if (!real_dlsym) {
            LERROR("real dlsym not found");
        }
    }
    if ((size_t)handle == -1) {
        void *h = ((real_dlsym_func)real_dlsym)((void *)-1, symbol);
        pthread_mutex_lock(&dlsym_lock);

        if (check_dlmap(pthread_self(), h)) {
            LINFO("recursive dlsym : %s", symbol);
            h = 0;
        }
        pthread_mutex_unlock(&dlsym_lock);
        return h;
    }
    else if (*(char *)symbol == 'c' && *(char *)(symbol + 1) == 'u' && (pthread_once(&pre_cuinit_flag, preInit), cuda_func = find_cuda_symbols_in_table((const char *)symbol), cuda_func != 0)) {
        LINFO("into cuda %s %d ", symbol, cuda_func);
        return cuda_func;
    }
    else if (*(char *)symbol == 'n' && *(char *)(symbol + 1) == 'v' && *(char *)(symbol + 2) == 'm' && *(char *)(symbol + 3) == 'l' && (nvml_func = find_nvml_symbols_in_table((const char *)symbol), nvml_func != 0)) {
        LINFO("into nvml %d ", nvml_func);
        return nvml_func;
    }
    else {
        LINFO("into dlsym %s ", symbol);
        //        LINFO("into dlsym %s %d", symbol, find_nvml_symbols_in_table((const char *)symbol) );
        void *res = ((real_dlsym_func)real_dlsym)(handle, symbol);
        LINFO("%d %s %d ", handle, symbol, res);
        return res;
    }
}

void *my_dlsym(void *handle, char *symbol) {
    LINFO("my_dlsym");
    return dlsym(handle, symbol);
}
