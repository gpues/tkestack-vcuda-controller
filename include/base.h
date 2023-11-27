#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>
#include <unistd.h>
#include "stdint.h"
#include "limits.h"
#include "cuda.h"
#include "nvml.h"
typedef struct {
    char *name;
    clock_t start;
} HOOK_TRACE_PROFILE;

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

#define HLOG(level, format, ...)                                                                                                                     \
    ({                                                                                                                                               \
        char *_print_level_str = getenv("LOGGER_LEVEL");                                                                                             \
        int _print_level = 0;                                                                                                                        \
        if (_print_level_str) {                                                                                                                      \
            _print_level = (int)strtoul(_print_level_str, NULL, 10);                                                                                 \
            _print_level = _print_level < 0 ? 3 : _print_level;                                                                                      \
        }                                                                                                                                            \
        if (level <= _print_level) {                                                                                                                 \
            fprintf(stderr, "[%s %s %d %s:%d] " format "\n", HOOK_LOG_TAG, curr_time(), getpid(), HOOK_LOG_FILE(__FILE__), __LINE__, ##__VA_ARGS__); \
        }                                                                                                                                            \
        if (level == FATAL) {                                                                                                                        \
            exit(-1);                                                                                                                                \
        }                                                                                                                                            \
    })
#define HOOK_CHECK(x)                            \
    do {                                         \
        if (HOOK_UNLIKELY(!(x))) {               \
            HLOG(FATAL, "Check failed: %s", #x); \
            exit(EXIT_FAILURE);                  \
        }                                        \
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

char *NvmlSo();
char *CudaSo();
#define DataLength 10000
typedef struct {
    char pod_uid[DataLength];
    char occupied[DataLength];
    char container_name[DataLength];
    char bus_id[DataLength];
    int limit;
    int gpu_memory;
    int utilization;
    int hard_limit;
    int enable; // 是否大于100份
} resource_data_t;

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
void *utilization_watcher(void *);
void load_pids_table(int, void *);
void get_used_gpu_memory(int, void *);
void get_used_gpu_utilization(int, void *);
void initialization();
void rate_limiter(unsigned int, unsigned int);
void change_token(int);
void read_controller_configuration();
int int_match(const void *, const void *);
int delta(int, int, int);
size_t get_array_base_size(int format);
CUresult cuArray3DCreate_helper(const CUDA_ARRAY3D_DESCRIPTOR *pAllocateArray);
CUresult cuArrayCreate_helper(const CUDA_ARRAY_DESCRIPTOR *pAllocateArray);
char *Marshal(resource_data_t t);
resource_data_t UnMarshal(char *s);

CUresult cuMemAlloc_v2(CUdeviceptr *dptr, size_t bytesize);
CUresult cuMemAllocPitch_v2(CUdeviceptr *dptr, size_t *pPitch, size_t WidthInBytes, size_t Height, unsigned int ElementSizeBytes);
CUresult cuArrayCreate_v2(CUarray *pHandle, const CUDA_ARRAY_DESCRIPTOR *pAllocateArray);
CUresult cuArray3DCreate_v2(CUarray *pHandle, const CUDA_ARRAY3D_DESCRIPTOR *pAllocateArray);
CUresult cuDeviceTotalMem_v2(size_t *bytes, CUdevice dev);
CUresult cuMemGetInfo_v2(size_t *free, size_t *total);
CUresult cuLaunchKernel_ptsz(CUfunction f, unsigned int gridDimX, unsigned int gridDimY, unsigned int gridDimZ, unsigned int blockDimX, unsigned int blockDimY, unsigned int blockDimZ, unsigned int sharedMemBytes, CUstream hStream, void **kernelParams, void **extra);
CUresult cuLaunchCooperativeKernel_ptsz(CUfunction f, unsigned int gridDimX, unsigned int gridDimY, unsigned int gridDimZ, unsigned int blockDimX, unsigned int blockDimY, unsigned int blockDimZ, unsigned int sharedMemBytes, CUstream hStream, void **kernelParams);
