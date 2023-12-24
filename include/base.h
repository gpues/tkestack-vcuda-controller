#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>
#include <unistd.h>

#include "stdint.h"

char *curr_time();

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

#define CAS(ptr, old, new) __sync_bool_compare_and_swap((ptr), (old), (new))

#define LINFO(format, ...)                                                                                                                  \
    ({                                                                                                                                      \
        char *_print_level_str = getenv("LOGGER_LEVEL");                                                                                    \
        unsigned long _print_level = 10;                                                                                                    \
        if (_print_level_str) {                                                                                                             \
            _print_level = strtoul(_print_level_str, NULL, 10);                                                                             \
            _print_level = _print_level < 0 ? 3 : _print_level;                                                                             \
        }                                                                                                                                   \
        if (1 <= _print_level) {                                                                                                            \
            printf("[%s %s %d %s:%d] " format "\n", HOOK_LOG_TAG, curr_time(), getpid(), HOOK_LOG_FILE(__FILE__), __LINE__, ##__VA_ARGS__); \
        }                                                                                                                                   \
    })

#define LWARN(format, ...)                                                                                                                        \
    ({                                                                                                                                            \
        char *_print_level_str = getenv("LOGGER_LEVEL");                                                                                          \
        int _print_level = 10;                                                                                                                    \
        if (_print_level_str) {                                                                                                                   \
            _print_level = strtoul(_print_level_str, NULL, 10);                                                                                   \
            _print_level = _print_level < 0 ? 3 : _print_level;                                                                                   \
        }                                                                                                                                         \
        if (1 < _print_level) {                                                                                                                   \
            printf("[%s Warn(%s %d %s:%d)] " format "\n", HOOK_LOG_TAG, curr_time(), getpid(), HOOK_LOG_FILE(__FILE__), __LINE__, ##__VA_ARGS__); \
        }                                                                                                                                         \
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
    char uuid[96];
} sharedRegionUuid;

typedef struct sharedRegionT_t {
    int32_t initializedFlag;     // 0
    int32_t smInitFlag;          // 4
    u_int32_t ownerPid;          // 8
    int sem;                     // 12
    u_int64_t num;               // 16
    sharedRegionUuid uuids[16];  // 24
    u_int64_t limit[16];         // 1560
    u_int64_t sm_limit[16];      // 1688
    shrregProcSlotT procs[1024]; // 1816
    int32_t procnum;             // 804632
    int32_t utilizationSwitch;   // 804636
    int32_t recentKernel;        // 804640
    int32_t priority;            // 804644
} sharedRegionT;

typedef struct FatbinFileHeader_t {
    unsigned short kind;                // 0
    unsigned short version;             // 2
    u_int header_size;                  // 4
    u_int padded_payload_size;          // 8
    u_int unknown0;                     // 12 check if it's written into separately
    u_int payload_size;                 // 16
    u_int unknown1;                     // 20
    u_int unknown2;                     // 24
    u_int sm_version;                   // 28
    u_int bit_width;                    // 32
    u_int unknown3;                     // 36
    unsigned long unknown4;             // 40
    unsigned long unknown5;             // 48
    unsigned long uncompressed_payload; // 56
} FatbinFileHeader;

typedef struct FatbinHeader_t {
    u_int magic;                // 0
    unsigned short version;     // 4
    unsigned short header_size; // 6
    unsigned long files_size;   // 8  excluding frame header, size of all blocks framed by this frame
} FatbinHeader;

typedef struct FatbincWrapper_t {
    u_int magic;               // 0
    u_int version;             // 4
    FatbinHeader *data;        // 8
    void *filename_or_fatbins; // 16
} FatbincWrapper;

#define MAX_DLMAP_COUNT 100

struct DlMapEntry {
    pthread_t p;
    void *handle;
};

struct DlMap {
    struct DlMapEntry entries[MAX_DLMAP_COUNT];
    int count;
} dlmap;

typedef void *(*real_dlsym_func)(void *, const char *);
