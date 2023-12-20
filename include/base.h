#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>
#include <unistd.h>

#include "cuda-helper.h"
#include "cuda-subset.h"
#include "func.h"
#include "limits.h"
#include "nvml-helper.h"
#include "nvml-subset.h"
#include "stdint.h"
#include "vdpau.h"

typedef struct {
    char *name;
    clock_t start;
} HOOK_TRACE_PROFILE;

void cudaTimeProfileDestroy(HOOK_TRACE_PROFILE *obj, CUresult rs);
void nvmlTimeProfileDestroy(HOOK_TRACE_PROFILE *obj, nvmlReturn_t rs);
void TimeProfileDestroy(HOOK_TRACE_PROFILE *obj);
HOOK_TRACE_PROFILE *TimeProfile(char *name);
char *curr_time();
typedef void (*atomic_fn_ptr)(int, void *);

#define HOOK_LIKELY(x) __builtin_expect(!!(x), 1)
#define HOOK_UNLIKELY(x) __builtin_expect(!!(x), 0)

#define HOOK_LOG_TAG "CUDA-HOOK"
#define HOOK_LOG_FILE(x) (strrchr(x, '/') ? (strrchr(x, '/') + 1) : x)
#define UNUSED __attribute__((unused))
#define MAX_PIDS (1024)
#define MILLISEC (1000UL * 1000UL)
#define TIME_TICK (10)
#define FACTOR (32)
#define MAX_UTILIZATION (100)
#define CHANGE_LIMIT_INTERVAL (30)
#define USAGE_THRESHOLD (5)
#define FACTOR (32)
#define GET_VALID_VALUE(x) (((x) >= 0 && (x) <= 100) ? (x) : 0)
#define CODEC_NORMALIZE(x) (x * 85 / 100)

typedef enum {
    DEBUG = 0,
    INFO = 1,
    ERROR = 2,
    WARNING = 3,
    FATAL = 4,
    VERBOSE = 5,
} log_level_enum_t;
// sub_4074F0
// Incompatible integer to pointer conversion initializing 'char *' with an expression of type 'int'

#define LINFO(format, ...)                                                                                                                  \
    ({                                                                                                                                      \
        char *_print_level_str = getenv("LOGGER_LEVEL");                                                                                    \
        unsigned long _print_level = 0;                                                                                                     \
        if (_print_level_str) {                                                                                                             \
            _print_level = strtoul(_print_level_str, NULL, 10);                                                                             \
            _print_level = _print_level < 0 ? 3 : _print_level;                                                                             \
        }                                                                                                                                   \
        if (1 <= _print_level) {                                                                                                            \
            printf("[%s %s %d %s:%d] " format "\n", HOOK_LOG_TAG, curr_time(), getpid(), HOOK_LOG_FILE(__FILE__), __LINE__, ##__VA_ARGS__); \
        }                                                                                                                                   \
    })

#define LWARN(format, ...)                                                                                                                         \
    ({                                                                                                                                             \
        char *_print_level_str = getenv("LOGGER_LEVEL");                                                                                           \
        int _print_level = 0;                                                                                                                      \
        if (_print_level_str) {                                                                                                                    \
            _print_level = strtoul(_print_level_str, NULL, 10);                                                                                    \
            _print_level = _print_level < 0 ? 3 : _print_level;                                                                                    \
        }                                                                                                                                          \
        if (1 < _print_level) {                                                                                                                    \
            printf("[ %s Warn(%s %d %s:%d)] " format "\n", HOOK_LOG_TAG, curr_time(), getpid(), HOOK_LOG_FILE(__FILE__), __LINE__, ##__VA_ARGS__); \
        }                                                                                                                                          \
    })

#define LERROR(format, ...) ({ printf("[ %s ERROR(pid:%s thread:%d %s:%d)] " format "\n", HOOK_LOG_TAG, curr_time(), getpid(), HOOK_LOG_FILE(__FILE__), __LINE__, ##__VA_ARGS__); })
#define LFATAL(format, ...)                                                                                                                                \
    ({                                                                                                                                                     \
        printf("[ %s ERROR(pid:%s thread:%d %s:%d)] " format "\n", HOOK_LOG_TAG, curr_time(), getpid(), HOOK_LOG_FILE(__FILE__), __LINE__, ##__VA_ARGS__); \
        exit(-1);                                                                                                                                          \
    })

#define LogAndWait(level, sl, format, ...)                                                                                                  \
    ({                                                                                                                                      \
        char *_print_level_str = getenv("LOGGER_LEVEL");                                                                                    \
        int _print_level = 0;                                                                                                               \
        if (_print_level_str) {                                                                                                             \
            _print_level = (int)strtoul(_print_level_str, NULL, 10);                                                                        \
            _print_level = _print_level < 0 ? 3 : _print_level;                                                                             \
        }                                                                                                                                   \
        if (level <= _print_level) {                                                                                                        \
            printf("[%s %s %d %s:%d] " format "\n", HOOK_LOG_TAG, curr_time(), getpid(), HOOK_LOG_FILE(__FILE__), __LINE__, ##__VA_ARGS__); \
        }                                                                                                                                   \
        sleep(sl);                                                                                                                          \
    })

#define HOOK_CHECK(x)                       \
    do {                                    \
        if (HOOK_UNLIKELY(!(x))) {          \
            printf("Check failed: %s", #x); \
        }                                   \
    } while (0)

#define likely(x) __builtin_expect(!!(x), 1)
#define unlikely(x) __builtin_expect(!!(x), 0)
#define ROUND_UP(n, base) ((n) % (base) ? (n) + (base) - (n) % (base) : (n))
#define CAS(ptr, old, new) __sync_bool_compare_and_swap((ptr), (old), (new))

#define CONTROLLER_CONFIG_NAME "vcuda.config"
#define VCUDA_CONFIG_PATH "/etc/vcuda"
#define PIDS_CONFIG_NAME "pids.config"

#define PIDS_CONFIG_PATH (VCUDA_CONFIG_PATH "/" PIDS_CONFIG_NAME)
#define CONTROLLER_CONFIG_PATH (VCUDA_CONFIG_PATH "/" CONTROLLER_CONFIG_NAME)
#define RPC_CLIENT_PATH "/usr/local/nvidia/bin/"
#define DRIVER_VERSION_PROC_PATH "/proc/driver/nvidia/version"

/*
 * nvmlInitWithFlags
 * nvmlInit_v2
 * cuGetProcAddress
 * cuInit
 * cuDriverGetVersion
 * */
void load_necessary_data();
void cudaNecessary();
void write_cuda_config();

void atomic_action(const char *, atomic_fn_ptr, void *);
void active_utilization_notifier();
void load_pids_table(int, void *);
void get_used_gpu_memory(int, void *);

void initialization();
void rate_limiter(unsigned int, unsigned int);
void change_token(int);
void set_so_path_once();
void read_controller_configuration();
char *load_file(char *filename);
int int_match(const void *, const void *);
int delta(int, int, int);
size_t get_array_base_size(int format);
CUresult cuArray3DCreate_helper(const CUDA_ARRAY3D_DESCRIPTOR *pAllocateArray);
CUresult cuArrayCreate_helper(const CUDA_ARRAY_DESCRIPTOR *pAllocateArray);

typedef enum {
    Compute = 0,
    Graphics = 1,
    ComputeAndGraphics = 2,
} ProcessType;

typedef struct {
    unsigned int PID;
    char *Name;
    long long int MemoryUsed;
    unsigned int Type; // 是否大于100份
} cudaCache;

#define DRIVER_VERSION_PROC_PATH "/proc/driver/nvidia/version"
#define DRIVER_VERSION_MATCH_PATTERN "([0-9]+)(\\.[0-9]+)+"
#define NVML_LIBRARY_PREFIX "libnvidia-ml.so"
#define CUDA_LIBRARY_PREFIX "libcuda.so"

/**
 * Flags to indicate search status. For more details see ::cuGetProcAddress
 */
typedef enum CUdriverProcAddressQueryResult_enum {
    CU_GET_PROC_ADDRESS_SUCCESS = 0,               /**< Symbol was succesfully found */
    CU_GET_PROC_ADDRESS_SYMBOL_NOT_FOUND = 1,      /**< Symbol was not found in search */
    CU_GET_PROC_ADDRESS_VERSION_NOT_SUFFICIENT = 2 /**< Symbol was found but version supplied was not sufficient */
} CUdriverProcAddressQueryResult;

typedef struct devMemLimit_t {
    int64_t memoryLimit;
} devMemLimit;

typedef struct {
    int user_current;
    int sys_current;
    int valid;
    uint64_t checktime;
    int sys_process_num;
    u_int64_t allTimeStamp;
    u_int64_t allUsedGpuMemory;

} utilization_t;

typedef struct {
    char uuid[96];
} uuid;

typedef struct {
    u_int64_t contextSize;
    u_int64_t moduleSize;
    u_int64_t bufferSize;
    u_int64_t offset;
    u_int64_t total;
} deviceMemory;

typedef struct shrregProcSlotT_t {
    int32_t pid;
    int32_t hostpid;
    deviceMemory used[16];
    u_int64_t monitorused[16];
    int32_t status;
} shrregProcSlotT;

typedef struct {
    char sem[32];
} semT;
typedef struct sharedRegionT_t {
    int32_t initializedFlag;
    int32_t smInitFlag;
    u_int32_t ownerPid;
    semT sem;
    u_int64_t num;
    uuid uuids[16];
    u_int64_t limit[16];
    u_int64_t sm_limit[16];
    shrregProcSlotT procs[1024];
    int32_t procnum;
    int32_t utilizationSwitch;
    int32_t recentKernel;
    int32_t priority;
} sharedRegionT;

typedef struct asd_t {
    void *ptr; // 偏移量 48
    uuid uuid; // 偏移量 56
    int64_t ss;
} asd;

typedef struct device_t {  // 整个结构体  152 字节
    CUcontext ctx;         // 偏移 0
    CUcontext vctx;        // 偏移 8
    int index;             // 偏移 0x10
    int add_gpu_flag;      // 偏移 20
    int64_t devIndex;      // 偏移 24
    char *busIdLegacy;     // 偏移 0x20
    nvmlDevice_t *vhandle; // 偏移 0x28
    nvmlDevice_t device;   // 偏移 0x30
    nvmlDevice_t vdevice;  // 偏移 56
    nvmlDevice_t *handle;  // 偏移 0x40
    int64_t d6;            // 偏移 72
    int64_t e7;            // 偏移 0x50
    int64_t f8;            // 偏移 88
    int64_t f9;            // 偏移 0x60
    int64_t f0;            // 偏移 104
    int64_t f22;           // 偏移 0x70  // 进制相关的
    int64_t f11;           // 偏移 120
    int64_t f113;          // 偏移 0x80
    int64_t f114;          // 偏移 136
    int64_t f115;          // 偏移 0x90
    int64_t f116;          // 偏移 152
    //    asd detail;
} device;
