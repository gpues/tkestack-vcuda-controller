#include <dlfcn.h>
#include <libc.h>
#include <pthread.h>
#include <string.h>

#include "include/base.h"
#include "include/cuda-helper.h"
#include "include/func.h"

extern u_int64_t context_size;
extern pthread_mutex_t dlsym_lock;
extern device vdevices[0x10];
extern unsigned int virtual_nvml_devices[17];
char *real_realpath;
extern int dlmap_count;
extern char *dlmap[1000];
extern bool real_dlsym;
extern pthread_once_t dlsym_init_flag;
extern int allocmode;
extern int pidfound;
extern void *cuda_library_entry[];

unsigned long strtoul(const char *nptr, char **endptr, int base);

extern int env_utilization_switch;

void *init_dlsym() {
    LINFO("init_dlsym");
    pthread_mutex_init(&dlsym_lock, 0LL);
    dlmap_count = 0;
    return memset(&dlmap, 0, 0x640uLL);
}

size_t check_dlmap(int a1, size_t a2) {
    int v2; // eax
    int i;  // [rsp+18h] [rbp-8h]
    int v5; // [rsp+1Ch] [rbp-4h]

    v2 = dlmap_count;
    if (dlmap_count > 100)
        v2 = 100;
    for (i = v2 - 1; i >= 0; --i) {
        if (a1 == *((_DWORD *)&dlmap + 4 * i) && a2 == *((_QWORD *)&dlmap + 2 * i + 1))
            return 1LL;
    }
    v5 = dlmap_count % 100;
    *((_DWORD *)&dlmap + 4 * (dlmap_count % 100)) = a1;
    *((_QWORD *)&dlmap + 2 * v5 + 1) = a2;
    ++dlmap_count;
    return 0LL;
}

size_t dlsym(size_t a1, size_t a2) {
    char *v2;         // rax
    char *v3;         // r12
    pthread_t v4;     // rbx
    unsigned int v5;  // eax
    char *v6;         // r12
    pthread_t v7;     // rbx
    unsigned int v8;  // eax
    char *v9;         // rax
    char *v10;        // r12
    pthread_t v11;    // rbx
    unsigned int v12; // eax
    unsigned int v14; // [rsp+14h] [rbp-2Ch]
    __int64 v15;      // [rsp+18h] [rbp-28h]
    __int64 v16;      // [rsp+20h] [rbp-20h]
    __int64 v17;      // [rsp+28h] [rbp-18h]

    pthread_once(dlsym_init_flag, (void (*)(void))init_dlsym);
    LINFO("into dlsym %s", (const char *)a2);
    if (!real_dlsym) {
        real_dlsym = (__int64(__fastcall *)(_QWORD, _QWORD))dlvsym((void *)0xFFFFFFFFFFFFFFFFLL, "dlsym", "GLIBC_2.2.5");
        if (!real_dlsym) {
            real_dlsym = (__int64(__fastcall *)(_QWORD, _QWORD))_dl_sym(-1LL, "dlsym", dlsym);
            if (!real_dlsym) {
                LINFO("real dlsym not found");
            }
        }
    }

    if (a1 == -1) {
        v15 = real_dlsym(-1LL, a2);
        pthread_mutex_lock(&dlsym_lock);
        v14 = pthread_self();
        if ((unsigned int)check_dlmap(v14, v15)) {
            LINFO("recursive dlsym : %s", (const char *)a2);
            v15 = 0LL;
        }
        pthread_mutex_unlock(&dlsym_lock);
        return v15;
    }
    else if (*(char *)a2 == 99 && *(char *)(a2 + 1) == 117 && (pthread_once(&pre_cuinit_flag, (void (*)(void))preInit), (v16 = __dlsym_hook_section(a1, a2)) != 0)) {
        return v16;
    }
    else if (*(char *)a2 == 110 && *(char *)(a2 + 1) == 118 && *(char *)(a2 + 2) == 109 && *(char *)(a2 + 3) == 108 && (v17 = __dlsym_hook_section_nvml(a1, a2)) != 0) {
        return v17;
    }
    else {
        return real_dlsym(a1, a2);
    }
}

#ifdef MY_REALPATH_DEFINED
const char *realpath(const char *realpath, const char *a2) {
    char dest[7];
    LINFO("INTO realpath:%s", realpath);
    if (!real_realpath) {
        real_realpath = dlvsym((void *)0xFFFFFFFFFFFFFFFFLL, "realpath", "GLIBC_2.3");
        if (!real_realpath) {
            LWARN("real_realpath first assign failed");
            real_realpath = real_dlsym(-1LL, "realpath");
        }
    }
    int found = 0;
    for (int i = 0; i < virtual_nvml_devices[0]; ++i) {
        if (*vdevices[i].busIdLegacy) {
            if (strlen(vdevices[i].busIdLegacy) > 6) {
                strcpy(dest, vdevices[i].busIdLegacy + 5);
                if (!comparelwr(&realpath[strlen(realpath) - 7], dest)) {
                    found = 1;
                    break;
                }
            }
        }
    }
    const char *v19;

    if (found) {
        char *v20 = (char *)malloc(strlen(realpath));
        strcpy(v20, realpath);
        v20[strlen(v20) - 1] = '0';
        v19 = (const char *)real_realpath(v20, a2);
        free(v20);
    }
    else {
        v19 = (const char *)real_realpath(realpath, a2);
    }
    LINFO("resolved_path=%s,rr=%s", a2, v19);
    return v19;
}
#endif

size_t map_cuda_visible_devices() {
    parse_cuda_visible_env();
    return 0LL;
}

int postInit() {
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
    return init_utilization_watcher();
}
