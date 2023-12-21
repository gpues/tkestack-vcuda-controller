#include "include/all.h"

extern int g_sm_num;
extern int g_max_thread_per_sm;

extern unsigned int curren_owner;
extern unsigned int vgpu_offset;
extern void *cachePtr;
extern int64_t in_fs_offset;
extern sharedRegionT *global_config;
extern int64_t initial_offset;
extern int memory_override;
extern bool duplicate_devices;
extern int fd;
extern int child_init_flag;
extern volatile int g_cur_cuda_cores;
extern volatile int g_total_cuda_cores;
extern unsigned int virtual_devices[17];
extern unsigned int virtual_map[0x10];
extern unsigned int record_cuda_map[0x10];
extern int env_utilization_switch;

int64_t setspec() {
    nvmlReturn_t res = nvmlInit();
    if (res) {
        LWARN("NVML error at line %d: %d", __LINE__, res);
        return res;
    }
    else if ((unsigned int)cuDeviceGetAttribute(&g_sm_num, 0x10, 0LL)) {
        unsigned int Attribute = (unsigned int)cuDeviceGetAttribute(&g_sm_num, 0x10, 0LL);
        LWARN("Driver error at %d: %d", __LINE__, Attribute);
        return Attribute;
    }
    else if ((unsigned int)cuDeviceGetAttribute(&g_max_thread_per_sm, 0x27, 0LL)) {
        unsigned int Attribute = (unsigned int)cuDeviceGetAttribute(&g_max_thread_per_sm, 0x27, 0LL);
        LWARN("Driver error at %d: %d", __LINE__, Attribute);
        return Attribute;
    }
    else {
        g_total_cuda_cores = FACTOR * g_max_thread_per_sm * g_sm_num;
        return 0LL;
    }
}

bool proc_alive(unsigned int pid) {
    char pidPath[1024];
    sprintf(pidPath, "/proc/%d/stat", pid);
    FILE *file = fopen(pidPath, "r");

    if (file == NULL) {
        return false;
    }
    char process_id[1024];
    char process_name[1024];
    char process_state;
    int count = fscanf(file, "%s %s %c", &process_id, process_name, &process_state);
    //     Z 僵尸
    //     X 即将被销毁
    //     x 即将被销毁
    if (count == 3)
        if (process_state == 'Z' || process_state == 'X' || process_state == 'x') {
            return false;
        }
    fclose(file);
    return true;
}

bool fix_lock_shrreg() {
    if (fd == -1) {
        LERROR("Uninitialized shrreg");
    }
    if (lockf(fd, F_LOCK, vgpu_offset)) {
        LERROR("Fail to upgraded lock: errno=%d", errno);
    }
    bool res = false;
    u_int32_t pid = global_config->ownerPid;
    if (pid) {
        int v26 = 0;
        if (pid == curren_owner) {
            LINFO("Detect onwer pid = self pid (%d), indicates pid loopback or race condition", pid);
            v26 = 1;
        }
        else if (!proc_alive(pid)) {
            LINFO("Kick dead owner proc (%d)", pid);
            v26 = 1;
        }

        if (v26 == 1) {
            LINFO("Take upgraded lock (%d)", curren_owner);
            global_config->ownerPid = curren_owner;
            res = true;
        }
    }

    if (lockf(F_ULOCK, 0, vgpu_offset)) {
        LERROR("Fail to upgraded unlock: errno=%d", errno);
    }
    return res;
}

int64_t lock_shrreg() {
    struct timespec abs_timeout;
    clock_gettime(CLOCK_REALTIME, &abs_timeout);
    abs_timeout.tv_sec += 10; // 设置等待时间为 10 秒
    sharedRegionT flags_bak = *global_config;
    int wait_count = 0;
    while (sem_timedwait(global_config + 0x10, &abs_timeout)) {
        if (errno == 110) {
            LWARN("Lock shrreg timeout, try fix (%d:%ld)", *(unsigned int *)global_config, *(unsigned int *)(global_config + 8));
        }
        unsigned int pid = *((unsigned int *)global_config + 8);
        if (pid && (pid == curren_owner || proc_alive(pid) == 1)) {
            LWARN("Owner proc dead (%d), try fix", pid);
            if (!fix_lock_shrreg()) {
                return global_config->initializedFlag ^ flags_bak.initializedFlag;
            }
        }
        else if (++wait_count > 30) {
            LWARN("Fail to lock shrreg in %d seconds", 300LL);
            if (!pid) {
                LWARN(" fix current_owner 0>%d", curren_owner);
                *(unsigned int *)(global_config + 8) = curren_owner;
                if (!fix_lock_shrreg()) {
                    return global_config->initializedFlag ^ flags_bak.initializedFlag;
                }
            }
        }
        else {
            LERROR("Failed to lock shrreg: %d", errno);
        }
    }
    *(unsigned int *)(global_config + 8) = curren_owner;
    _mm_mfence();
    return global_config->initializedFlag ^ flags_bak.initializedFlag;
}

void unlock_shrreg(void) {
    sharedRegionT flags_bak = *global_config;
    global_config->ownerPid = 0;
    sem_t sem = flags_bak.initializedFlag + 0x10;
    sem_post(&sem);
}

int enable_active_oom_killer;

int set_active_oom_killer() {
    const char *s1;
    s1 = getenv("ACTIVE_OOM_KILLER");
    if (!s1)
        return 1LL;
    if (!strcmp(s1, "false"))
        return 0LL;
    if (!strcmp(s1, "true"))
        return 1LL;
    if (!strcmp(s1, "0"))
        return 0LL;
    return 1LL;
}

int set_env_utilization_switch() {
    const char *s1;

    s1 = getenv("GPU_CORE_UTILIZATION_POLICY");
    if (!s1)
        return 0LL;
    if (!strcmp(s1, "FORCE") || !strcmp(s1, "force"))
        return 1LL;
    if (!strcmp(s1, "DISABLE") || !strcmp(s1, "disable"))
        return 2LL;
    else
        return 0LL;
}

int child_reinit_flag() {
    char *level = getenv("LIBCUDA_LOG_LEVEL");
    LINFO("Detect child pid: %d -> %d", getpid(), getenv("LIBCUDA_LOG_LEVEL"));
    child_init_flag = 0;
    return *(int *)level;
}

int64_t get_limit_from_env(char *envName) {
    char *envValue = getenv((const char *)envName);
    if (!envValue)
        return 0LL;
    int64_t envNameLen = strlen(envValue);
    if (!envNameLen)
        return 0LL;
    int64_t unit = 1LL;
    char *endptr = &envValue[envNameLen];
    switch (envValue[envNameLen - 1]) {
        case 'G':
        case 'g':
            --endptr;
            unit = 0x40000000LL;
            break;
        case 'M':
        case 'm':
            --endptr;
            unit = 160000LL;
            break;
        case 'K':
        case 'k':
            --endptr;
            unit = 1024LL;
            break;
    }
    int64_t count = strtoul(envValue, &endptr, 0);
    int64_t totalSize = unit * count;
    if (unit * count) {
        if (count == totalSize / unit) {
            return totalSize;
        }
        else {
            LERROR("Limit overflow: %s=%s\n\n", (const char *)envName, envValue);
            return 0LL;
        }
    }
    else {
        if (*(char *)(envName + 12) == 83) {
            LINFO("device core util limit set to 0, which means no limit: %s=%s\n", (const char *)envName, envValue);
        }
        else if (*(char *)(envName + 12) == 77) {
            LINFO("invalid device memory limit %s=%s", *envName, envValue);
        }
        else {
            LWARN("invalid env name:%s\n", (const char *)envName);
        }
        return 0LL;
    }
}

int64_t do_init_device_memory_limits(void *arg, int count) {
    int64_t *dml = (int64_t *)arg;
    unsigned int i; // [rsp+14h] [rbp-4Ch]
    sharedRegionT flags_bak = *global_config;
    // CUDA_DEVICE_MEMORY_LIMIT_1=38400m
    // CUDA_DEVICE_MEMORY_LIMIT_0=40960m
    int64_t limit_from_env = get_limit_from_env("CUDA_DEVICE_MEMORY_LIMIT");
    for (i = 0; (int)i < count; ++i) {
        char s[8];
        char dest[26];
        strcpy(dest, "CUDA_DEVICE_MEMORY_LIMIT");
        dest[25] = 0;
        snprintf(s, 8uLL, "_%d", i);
        strcat(dest, s);
        int64_t limit = get_limit_from_env(dest);
        if (limit) {
            dml[i] = limit;
        }
        else if (limit_from_env) {
            dml[i] = limit_from_env;
        }
        else {
            dml[i] = 0;
        }
    }
    return global_config->initializedFlag ^ flags_bak.initializedFlag;
}

int64_t do_init_device_sm_limits(void *arg, int count) {
    unsigned int i;
    int64_t *dml = (int64_t *)arg;
    sharedRegionT flags_bak = *global_config;
    int64_t limit_from_env = get_limit_from_env("CUDA_DEVICE_SM_LIMIT");
    if (!limit_from_env)
        limit_from_env = 100LL;
    for (i = 0; (int)i < count; ++i) {
        char s[8];
        char dest[22];
        strcpy(dest, "CUDA_DEVICE_SM_LIMIT");
        dest[21] = 0;
        snprintf(s, 8uLL, "_%d", i);
        strcat(dest, s);
        int64_t cuda_sm_limit = get_limit_from_env(dest);
        if (cuda_sm_limit)
            dml[i] = cuda_sm_limit;
        else
            dml[i] = limit_from_env;
    }
    return global_config->initializedFlag ^ flags_bak.initializedFlag;
}

u_int64_t get_timespec(int delay, struct timespec *t) {
    struct timeval tv;
    sharedRegionT flags_bak = *global_config;
    gettimeofday(&tv, 0LL);
    t->tv_sec = delay + tv.tv_sec;
    t->tv_nsec = 0;
    return global_config->initializedFlag ^ flags_bak.initializedFlag;
}

int64_t exit_handler() {
    //    char *v0;                // rax
    //    __int64 v1;              // rbx
    //    char *v2;                // r13
    //    pthread_t v3;            // r12
    //    unsigned int v4;         // eax
    //    char *v5;                // rax
    //    __int64 v6;              // rbx
    //    char *v7;                // r13
    //    pthread_t v8;            // r12
    //    unsigned int v9;         // eax
    //    __int64 v12;             // [rsp+8h] [rbp-48h]
    //    unsigned __int64 v14;    // [rsp+28h] [rbp-28h]

    struct timespec abstime;

    sharedRegionT flags_bak = *global_config;
    if (child_init_flag) {
        int i = 0;
        LINFO("Calling exit handler %d\n", getpid());
        get_timespec(3LL, &abstime);
        if (sem_timedwait((sem_t *)(global_config + 0x10), &abstime)) {
            LWARN("Failed to take lock on exit: errno=%d\n", errno);
        }
        else {
            global_config->ownerPid = curren_owner;
            while (i < global_config->procnum) {
                if (global_config->procs[i].pid == curren_owner) {
                    struct shrregProcSlotT_t source; // 置空
                    memcpy(&global_config->procs[i].pid, &source, sizeof(struct shrregProcSlotT_t));
                    break;
                }
                ++i;
            }
            _mm_mfence();
            global_config->ownerPid = 0LL;
            sem_post((sem_t *)(global_config + 0x10));
        }
    }
    return global_config->initializedFlag ^ flags_bak.initializedFlag;
}

int64_t put_device_info() {
    unsigned int UUID;
    nvmlDevice_t v17[6];
    v17[1] = *(nvmlDevice_t *)(in_fs_offset + 40);

    LINFO("put_device_info finished %d", virtual_devices[0]);

    *(int64_t *)(global_config + 48) = (int)virtual_devices[0];

    for (int i = 0;; ++i) {
        if (i >= (int)virtual_devices[0]) {
            return 0LL;
        }

        unsigned int HandleByIndex = nvmlDeviceGetHandleByIndex((unsigned int)i, v17);

        if (HandleByIndex) {
            LWARN("NVML error at line %d: %d", __LINE__, HandleByIndex);
            return HandleByIndex;
        }
        UUID = nvmlDeviceGetUUID(v17[0], (char *)&(global_config->uuids[i]), 96);
        if (UUID)
            break;
    }
    LWARN("NVML error at line %d: %d", __LINE__, UUID);
    return UUID;
}

int64_t try_create_shrreg() {
    LINFO("Try create shrreg");
    sharedRegionT flags_bak = *global_config;
    int file_size = sizeof(sharedRegionT);
    if (fd == -1 && (unsigned int)__cxa_atexit(exit_handler)) {
        LERROR("Register exit handler failed: %d", errno);
    }

    enable_active_oom_killer = set_active_oom_killer();
    env_utilization_switch = set_env_utilization_switch();
    __register_atfork(0LL, 0LL, 0LL, child_reinit_flag); // 注册在 fork 系统调用时要执行的函数
    int pid = getpid();
    fd = -1;
    umask(0);
    char *file = getenv("CUDA_DEVICE_MEMORY_SHARED_CACHE");
    if (!file)
        file = "/tmp/cudevshr.cache";
    nvmlInit();

    fd = open(file, O_RDWR | O_CREAT | O_EXCL, 0644);
    if (fd == -1) {
        LERROR("Fail to open shrreg %s: errno=%d", file, errno);
    }
    int unk;
    if (lseek(fd, file_size, 0) != file_size) {
        LERROR("Fail to init shrreg %s: errno=%d", file, errno);
    }
    if (write(fd, &unk, 1) != 1) {
        LERROR("Fail to write shrreg %s: errno=%d\n", file, errno);
    }
    if (lseek(fd, 0, 0)) {
        LERROR("Fail to reseek shrreg %s: errno=%d\n", file, errno);
    }

    cachePtr = mmap(0, file_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    sharedRegionT *ptr = (sharedRegionT *)cachePtr;
    if (!cachePtr) {
        LERROR("Fail to map shrreg %s: errno=%d\n", file, errno);
    }
    if (lockf(fd, 1, file_size)) {
        LERROR("Fail to lock shrreg %s: errno=%d\n", file, errno);
    }
    put_device_info();
    int magic = 19920718;
    int devCount = 0x10;
    int limits[devCount];
    if (*(int *)cachePtr == magic) {
        do_init_device_memory_limits(&limits, devCount);
        for (int i = 0; i <= devCount - 1; ++i) {
            //      offsetof(struct sharedRegionT_t, procs)
            if (limits[i] != ptr->limit[i]) {
                LERROR("Limit inconsistency detected for %dth device, %lu expected, get %lu", (unsigned int)i, limits[i], ptr->limit[i]);
            }
        }
        do_init_device_sm_limits(&limits, devCount);
        for (int j = 0; j <= devCount - 1; ++j) {
            if (limits[j] != ptr->sm_limit[j]) {
                char *level = getenv("LIBCUDA_LOG_LEVEL");
                if (level) {
                    if (atoi(level) > 2) {
                        LINFO("SM limit inconsistency detected for %dth device, %lu expected, get %lu\n", (unsigned int)j, limits[j], ptr->sm_limit[j]);
                    }
                }
            }
        }
    }
    else {
        do_init_device_memory_limits(ptr + offsetof(struct sharedRegionT_t, limit), devCount);
        do_init_device_sm_limits(ptr + offsetof(struct sharedRegionT_t, sm_limit), devCount);
        if (sem_init((sem_t *)(ptr + 0x10), 1, 1u)) {
            LERROR("Fail to init sem %s: errno=%d\n", file, errno);
        }
        _mm_mfence();
        *(int32_t *)(ptr + offsetof(struct sharedRegionT_t, smInitFlag)) = 0;
        *(int32_t *)(ptr + offsetof(struct sharedRegionT_t, utilizationSwitch)) = 1;
        *(int32_t *)(ptr + offsetof(struct sharedRegionT_t, recentKernel)) = 2;
        *(int32_t *)(ptr + offsetof(struct sharedRegionT_t, priority)) = 1;
        if (getenv("CUDA_TASK_PRIORITY")) {
            char *priority = getenv("CUDA_TASK_PRIORITY");
            *(int32_t *)(ptr + offsetof(struct sharedRegionT_t, priority)) = atoi(priority);
        }
        *(int32_t *)(ptr + offsetof(struct sharedRegionT_t, initializedFlag)) = magic;
    }

    if (lockf(fd, 0, file_size)) {
        LERROR("Fail to unlock shrreg %s: errno=%d\n", file, errno);
    }
    LINFO("shrreg created");
    return global_config->initializedFlag ^ flags_bak.initializedFlag;
}

u_int64_t get_gpu_memory_usage(unsigned int dev) {
    LINFO("get_gpu_memory_usage dev=%d", dev);

    ensure_initialized();
    u_int64_t total = 0LL;
    lock_shrreg();
    for (int i = 0; i < global_config->procnum; ++i) {
        LINFO("dev=%d pid=%d host pid=%d i=%lu", dev, global_config->procs[i].pid, global_config->procs[i].hostpid, global_config->procs[i].used[dev].total);
        total += global_config->procs[i].used[dev].total;
    }
    u_int64_t v16 = initial_offset + total;
    unlock_shrreg();
    return v16;
}
// add task device memory analysis
int64_t add_gpu_device_memory_usage(unsigned int pid, int devIndex, size_t bytesize, int flag) {
    int i;
    unsigned int dev = record_cuda_map[devIndex];

    LINFO("add_gpu_device_memory:%d %d %lu\n", pid, dev, bytesize);
    ensure_initialized();
    lock_shrreg();
    for (i = 0; i < global_config->procnum; ++i) {
        if (pid == global_config->procs[i].pid) {
            global_config->procs[i].used[dev].total += bytesize;
            if (flag == 2) {
                global_config->procs[i].used[dev].bufferSize += bytesize;
            }
            else if (flag <= 2) {
                if (flag) {
                    if (flag == 1)
                        global_config->procs[i].used[dev].moduleSize += bytesize;
                }
                else {
                    global_config->procs[i].used[dev].contextSize += bytesize;
                }
            }
        }
    }
    unlock_shrreg();
    u_int64_t gpu_memory_usage = get_gpu_memory_usage(dev);
    LINFO("gpu_device_memory_added:%d %d %lu -> %lu", pid, dev, bytesize, gpu_memory_usage);
    return 0LL;
}

bool check_validator(const char *name) {
    char dest[112];
    char s[1000];
    bool res;
    int64_t canary = *(int64_t *)(in_fs_offset + 40);
    remove("/tmp/vgpulicense");
    memset(s, 0, sizeof(s));
    memset(dest, 0, 0x64uLL);
    strncpy(dest, name, 0xFuLL);
    sprintf(s, "vgpuvalidator --decode %s", dest);
    LINFO("executing %s,uuid=%s,substr=%s", s, name, dest);

    FILE *f = popen(s, "w");
    pclose(f);
    FILE *stream = fopen("/tmp/vgpulicense", "r");
    if (!stream)
        exit(1);
    if (fgets(dest, 100, stream))
        res = dest[0] == 49;
    fclose(stream);
    if (!res)
        exit(1);
    return res;
}

int64_t resume_all() {
    int i;
    int64_t result;
    for (i = 0;; ++i) {
        result = global_config->procnum;
        if (i >= (int)result)
            break;

        int32_t pid = global_config->procs[i].pid;
        LINFO("Sending USR1 to %d", pid);
        kill(pid, 10);
    }
    return result;
}

unsigned int wait_status_all(int status) {
    unsigned int res = 1;
    unsigned int i;
    for (i = 0; (signed int)i < global_config->procnum; ++i) {
        LINFO("i=%d pid=%d status=%d", global_config->procs[i].pid, global_config->procs[i].status);
        if (status != global_config->procs[i].status) {
            int pid = global_config->procs[i].pid;
            if (pid != getpid())
                res = 0;
        }
    }
    LINFO("Return released=%d", res);
    return res;
}

int64_t suspend_all() {
    int i;
    unsigned int result;
    for (i = 0;; ++i) {
        result = global_config->procnum;
        if (i >= (int)result)
            break;
        int32_t pid = global_config->procs[i].pid;
        LINFO("Sending USR2 to %d", pid);

        kill(pid, 12);
    }
    return result;
}

int64_t set_host_pid(size_t hPid) {
    unsigned int result;
    for (int i = 0; i < global_config->procnum; ++i) {
        unsigned int pid = global_config->procs[i].pid;
        if (pid == getpid()) {
            LINFO("SET PID= %d", hPid);
            result = 1;
            global_config->procs[i].hostpid = hPid;
            for (int j = 0; j <= 15; ++j) {
                global_config->procs[i].monitorused[j] = 0;
            }
        }
    }
    if (result) {
        setspec();
        return 0LL;
    }
    else {
        LERROR("HOST PID NOT FOUND. %d", hPid);
        return 0xFFFFFFFFLL;
    }
}

u_int64_t get_current_device_memory_usage(CUdevice dev) {
    LINFO("compute_3d_array_alloc_bytes desc is null");
    clock_t c_start = clock();
    ensure_initialized();
    if (dev >= 0x10) {
        LINFO("Illegal device id: %d", dev);
    }

    u_int64_t gpu_memory_usage = get_gpu_memory_usage(dev);
    clock_t c_end = clock();
    LINFO("get_current_device_memory_usage:tick=%lu result=%lu", c_end - c_start, gpu_memory_usage);
    return gpu_memory_usage;
}

u_int64_t get_current_device_sm_limit(CUdevice dev) {
    ensure_initialized();
    if (dev >= 0x10) {
        LERROR("Illegal device id: %d", dev);
    }
    return global_config->sm_limit[dev];
}

u_int64_t get_gpu_memory_monitor(CUdevice dev) {
    LINFO("get_gpu_memory_monitor dev=%d", dev);

    u_int64_t used;
    ensure_initialized();
    lock_shrreg();
    for (int i = 0; i < global_config->procnum; ++i) {
        LINFO("dev=%d i=%lu,%lu", global_config->procs[i].monitorused[dev], global_config->procs[i].used[dev].total);
        used += global_config->procs[i].monitorused[dev];
    }
    unlock_shrreg();
    return used;
}

u_int64_t get_current_device_memory_monitor(CUdevice dev) {
    ensure_initialized();
    if (dev >= 0x10) {
        LERROR("Illegal device id: %d", dev);
    }

    return get_gpu_memory_monitor(dev);
}

u_int64_t get_current_device_memory_limit(unsigned int dev) {
    ensure_initialized();
    if (dev >= 0x10) {
        LERROR("Illegal device id: %d", dev);
    }
    return global_config->limit[dev];
}

int64_t clear_proc_slot_nolock(int64_t a1, int hPid) {
    int64_t result;
    int index;
    int seq = 0;
    unsigned int pid;
    while (1) {
        result = global_config->procnum;
        if (index >= (int)result) {
            break;
        }
        pid = global_config->procs[index].pid;
        if (pid) {
            if (hPid > 0 && !proc_alive(pid)) {
                LWARN("Kick dead proc %d", pid);
                struct shrregProcSlotT_t source; // 置空
                memcpy(&global_config->procs[index].pid, &source, sizeof(struct shrregProcSlotT_t));
                _mm_mfence();
            }
        }
        else {
            ++index;
        }
    }

    return result;
}

int64_t load_env_from_file(const char *filePath) {
    FILE *stream = fopen(filePath, "r");
    if (!stream) {
        return 0;
    }
    char line[1832];
START:
    while (!feof(stream)) {
        fgets(line, 10000, stream);

        if (!strcmp(line, (const char *)'=')) {
            break;
        }
        if (line[strlen(line) - 1] == '\n') {
            line[strlen(line) - 1] = 0;
        }
        for (int i = 0; i < strlen(line); ++i) {
            if (line[i] == '=') {
                line[i] = 0;
                setenv(line, &line[i + 1], 1);
                LINFO("SET %s to %s", line, &line[i + 1]);
                goto START;
            }
        }
    }
    return true;
}

size_t rm_gpu_device_memory_usage(unsigned int pid, int index, size_t bytesize, int flag) {
    unsigned int dev = record_cuda_map[index];
    LINFO("rm_gpu_device_memory:%d %d %lu", pid, dev, bytesize);
    ensure_initialized();
    lock_shrreg();
    for (int i = 0; i < global_config->procnum; ++i) {
        if (pid == global_config->procs[i].pid) {
            global_config->procs[i].used[dev].total -= bytesize;
            if (flag == 2) {
                global_config->procs[i].used[dev].bufferSize -= bytesize;
            }
            else if (flag <= 2) {
                if (flag) {
                    if (flag == 1)
                        global_config->procs[i].used[dev].moduleSize -= bytesize;
                }
                else {
                    global_config->procs[i].used[dev].contextSize -= bytesize;
                }
            }
        }
    }
    unlock_shrreg();
    return 0;
}

int64_t rm_quitted_process() {
    int pids[4096];
    char line[264];
    int v12;
    int res;

    FILE *stream = popen("ps ax", "r"); // 🐂
    memset(pids, 0, 4096);
    ensure_initialized();

    LINFO("rm_quitted_process");
    lock_shrreg();

    if (stream) {
        while (fgets(line, 256, stream)) {
            const char *nptr = strtok(line, " ");
            int v14 = atoi(nptr);
            if (v14) {
                for (int i = 0; i < global_config->procnum; ++i) {
                    if (v14 == global_config->procs[i].pid)
                        pids[i] = 1;
                }
            }
        }
        for (int j = 0; j < global_config->procnum; ++j) {
            if (pids[j]) {
                global_config->procs[v12].pid = global_config->procs[j].pid;
                struct shrregProcSlotT_t sst;
                memcpy(&global_config->procs[v12++].used[0].contextSize, &global_config->procs[j].used[0].contextSize, sizeof(sst.used));
            }
            else {
                LINFO("rm pid=%d", global_config->procs[j].pid);
                res = 1;
            }
        }
        global_config->procnum = v12;
        pclose(stream);
    }
    unlock_shrreg();

    return res;
}

int64_t nvml_get_device_memory_usage(unsigned int index) {
    int64_t v30[511];
    nvmlDevice_t dev;
    v30[510] = *(int64_t *)(in_fs_offset + 40);
    nvmlReturn_t res = nvmlDeviceGetHandleByIndex(index, &dev);
    if (res) {
        LERROR("NVML get device %d error, %s", nvmlErrorString(res));
    }

    unsigned int processCount = 1024;
    nvmlProcessInfo_v1_t *infos;
    LINFO("before nvmlDeviceGetComputeRunningProcesses");
    res = nvmlDeviceGetComputeRunningProcesses(dev, &processCount, infos);
    if (res) {
        LERROR("NVML get process error, %s", nvmlErrorString(res));
    }

    lock_shrreg();
    int loopCount;

    sharedRegionT flags_bak = *global_config;
    u_int64_t usedGpuMemory = 0;
    while (index < processCount) {
        for (int i = 0; i < global_config->procnum; ++i) {
            if (infos[loopCount].pid == global_config->procs[i].pid)
                usedGpuMemory += infos[loopCount].usedGpuMemory;
        }
        ++loopCount;
    }
    unlock_shrreg();
    LINFO("Device %d current memory %lu / %lu", usedGpuMemory, global_config->limit[index]);
}

int64_t set_current_device_memory_limit(unsigned int index, int64_t size) {
    ensure_initialized();
    if (index >= 0x10) {
        LERROR("Illegal device id: %d", index);
    }
    LINFO("dev %d new limit set to %ld", index, size);
    global_config->limit[index] = size;

    return 0;
}

int64_t set_current_device_sm_limit_scale(unsigned int index, unsigned int size) {
    ensure_initialized();
    if (global_config->smInitFlag == 1)
        return 0;

    if (index >= 0x10) {
        LERROR("Illegal device id: %d", index);
    }
    LINFO("dev %d new sm limit set mul by %d", index, size);
    global_config->sm_limit[index] += size;
    global_config->smInitFlag = 1;
    return 0;
}

int64_t set_gpu_device_memory_monitor(unsigned int pid, unsigned int deviceIndex, int64_t usedGpuMemory) {
    ensure_initialized();
    double v8;
    int64_t v9;
    double v10;
    lock_shrreg();
    for (int i = 0; i < global_config->procnum; ++i) {
        if (pid == global_config->procs->pid) {
            LINFO("set_gpu_device_memory_monitor:%d %d %lu->%lu", pid, deviceIndex, global_config->procs[i].used[deviceIndex].total, usedGpuMemory);
        }
        global_config->procs[i].monitorused[deviceIndex] = usedGpuMemory;
        if (memory_override == 1) {
            global_config->procs[i].used[deviceIndex].offset = usedGpuMemory - global_config->procs[i].used[deviceIndex].total;
            global_config->procs[i].used[deviceIndex].total = usedGpuMemory;
        }
        if (!duplicate_devices && global_config->limit[deviceIndex]) {
            if (usedGpuMemory < 0) {
                v8 = (double)(int)((usedGpuMemory & 1) | ((uint64_t)((uint32_t)usedGpuMemory) >> 1)) * 2;
            }
            else
                v8 = (double)(int)usedGpuMemory;

            int64_t limit = (int64_t)global_config->limit[deviceIndex];
            if (limit < 0)
                v10 = (double)(int)((v9 & 1) | (uint64_t)((uint32_t)limit >> 1)) * 2;
            else
                v10 = (double)(int)limit;
            if (v8 > v10 * 1.1 && enable_active_oom_killer > 0) {
                LERROR("device OOM encountered: usage=%lu limit=%lu", usedGpuMemory, global_config->limit[deviceIndex]);
                active_oom_killer();
            }
            break;
        }
    }
    unlock_shrreg();
    return 1;
}

int active_oom_killer() {
    int i; // [rsp+Ch] [rbp-4h]

    for (i = 0; i < global_config[0].procnum; ++i) {
        kill(global_config[0].procs[i].pid, 9);
    }
    return 0LL;
}

int64_t cu_maphostpid(unsigned int pid) {
    char *i;
    char nptr[264]; // [rsp+30h] [rbp-110h] BYREF
    if (!pid)
        return 0LL;
    FILE *v4 = popen("ps a -o pid=", "r");
    if (!v4)
        return pid;
    while (fgets(nptr, 256, v4)) {
        unsigned int v2 = atoi(nptr);
        sprintf(nptr, "/proc/%u/status", v2);
        FILE *stream = fopen(nptr, "r");
        if (stream) {
            while (fgets(nptr, 256, stream)) {
                if (nptr[0] == 78 && nptr[1] == 103) {
                    for (i = nptr; *i > 57 || *i <= 47; ++i) {
                        if (i - nptr > 255)
                            return pid;
                    }
                    if (pid == atoi(i))
                        return v2;
                    break;
                }
            }
            fclose(stream);
        }
    }
    pclose(v4);
    return pid;
}

size_t wait_status_self(int status) {
    int i; // [rsp+1Ch] [rbp-14h]

    for (i = 0; i < global_config[0].procnum; ++i) {
        if (global_config[0].procs[0].pid == getpid())
            return status == global_config[0].procs[0].status;
    }
    return 0xFFFFFFFFLL;
}

int32_t set_current_gpu_status(int32_t a1) {
    for (int i = 0; i < global_config->procnum; ++i) {
        if (getpid() == global_config->procs[i].pid) {
            global_config->procnum = a1;
            global_config->procs[i].status = a1;
            return global_config->procnum;
        }
    }
    return global_config->procnum;
}

int64_t find_symbols_in_table(const char *a1) {
    char dest[504]; // [rsp+20h] [rbp-200h] BYREF

    strcpy(dest, a1);
    *(_DWORD *)&dest[strlen(dest)] = 3372639;
    v2 = __dlsym_hook_section(0LL, dest);
    if (v2)
        return v2;
    dest[strlen(dest) - 1] = 50;
    v2 = __dlsym_hook_section(0LL, dest);
    if (v2)
        return v2;
    v2 = __dlsym_hook_section(0LL, a1);
    if (v2)
        return v2;
    else
        return 0LL;
}
int64_t get_listsize(int64_t a1, int64_t *a2) {
    if (*(_QWORD *)(a1 + 16)) {
        v3 = 0LL;
        for (i = *(_QWORD **)a1; i; i = (_QWORD *)i[1]) v3 += *(_QWORD *)(*i + 8LL);
        *a2 = v3;
        return 0LL;
    }
    else {
        *a2 = 0LL;
        return 0LL;
    }
}

size_t init_proc_slot_withlock(size_t a1) {
    int i;           // [rsp+Ch] [rbp-14h]
    int v3;          // [rsp+10h] [rbp-10h]
    unsigned int v4; // [rsp+14h] [rbp-Ch]
    __int64 v5;      // [rsp+18h] [rbp-8h]

    v4 = getpid();
    lock_shrreg(a1);
    v5 = qword_610D0;
    if (*(int *)(qword_610D0 + 804664) > 1023)
        exit_withlock(0xFFFFFFFFLL);
    signal(12, (__sighandler_t)sig_swap_stub);
    signal(10, (__sighandler_t)sig_restore_stub);
    v3 = 0;
    for (i = 0; i < *(_DWORD *)(v5 + 804664); ++i) {
        if (v4 == *(_DWORD *)(v5 + 784LL * i + 1848)) {
            *(_DWORD *)(v5 + 784LL * i + 2624) = 1;
            memset((void *)(784LL * i + 1840 + v5 + 16), 0, 0x280uLL);
            v3 = 1;
            break;
        }
    }
    if (!v3) {
        *(_DWORD *)(v5 + 784LL * *(int *)(v5 + 804664) + 1848) = v4;
        *(_DWORD *)(v5 + 784LL * *(int *)(v5 + 804664) + 2624) = 1;
        memset((void *)(784LL * *(int *)(v5 + 804664) + 1840 + v5 + 16), 0, 0x280uLL);
        ++*(_DWORD *)(v5 + 804664);
    }
    clear_proc_slot_nolock(v4, 1);
    return unlock_shrreg();
}
