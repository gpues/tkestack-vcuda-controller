#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>
#include <unistd.h>

#include "cuda.h"
#include "limits.h"
#include "nvml.h"
#include "stdint.h"

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
#define HLOG(level, format, ...)                                                                                                            \
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
void set_so_path_once();
void read_controller_configuration();
char *load_file(char *filename);
int int_match(const void *, const void *);
int delta(int, int, int);
size_t get_array_base_size(int format);
CUresult cuArray3DCreate_helper(const CUDA_ARRAY3D_DESCRIPTOR *pAllocateArray);
CUresult cuArrayCreate_helper(const CUDA_ARRAY_DESCRIPTOR *pAllocateArray);
char *Marshal(resource_data_t t);
resource_data_t UnMarshal(char *s);

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
nvmlReturn_t UnMarshalCudaCache(ProcessType t, unsigned int *processCount, cudaCache *cc);

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

CUresult cuMemAlloc_v2(CUdeviceptr *dptr, size_t bytesize);
CUresult cuMemAllocPitch_v2(CUdeviceptr *dptr, size_t *pPitch, size_t WidthInBytes, size_t Height, unsigned int ElementSizeBytes);
CUresult cuArrayCreate_v2(CUarray *pHandle, const CUDA_ARRAY_DESCRIPTOR *pAllocateArray);
CUresult cuDeviceTotalMem_v2(size_t *bytes, CUdevice dev);
CUresult cuMemGetInfo_v2(size_t *free, size_t *total);
CUresult cuLaunchKernel_ptsz(CUfunction f, unsigned int gridDimX, unsigned int gridDimY, unsigned int gridDimZ, unsigned int blockDimX, unsigned int blockDimY, unsigned int blockDimZ, unsigned int sharedMemBytes, CUstream hStream, void **kernelParams, void **extra);
CUresult cuLaunchCooperativeKernel_ptsz(CUfunction f, unsigned int gridDimX, unsigned int gridDimY, unsigned int gridDimZ, unsigned int blockDimX, unsigned int blockDimY, unsigned int blockDimZ, unsigned int sharedMemBytes, CUstream hStream, void **kernelParams);
CUresult cuMemsetD2D16_v2(CUdeviceptr dstDevice, size_t dstPitch, unsigned short us, size_t Width, size_t Height);
CUresult cuMemcpyHtoD_v2_ptds(CUdeviceptr dstDevice, const void *srcHost, size_t ByteCount);
CUresult cuMemcpyHtoD_v2(CUdeviceptr dstDevice, const void *srcHost, size_t ByteCount);
CUresult cuMemsetD2D32_v2(CUdeviceptr dstDevice, size_t dstPitch, unsigned int ui, size_t Width, size_t Height);
CUresult cuArray3DCreate_v2(CUarray *pHandle, const CUDA_ARRAY3D_DESCRIPTOR *pAllocateArray);
CUresult cuCtxCreate_v2(CUcontext *pctx, unsigned int flags, CUdevice dev);
CUresult cuCtxDestroy_v2(CUcontext ctx);
CUresult cuCtxPopCurrent_v2(CUcontext *pctx);
CUresult cuCtxPushCurrent_v2(CUcontext ctx);
CUresult cuDevicePrimaryCtxRelease_v2(CUdevice dev);
CUresult cuDevicePrimaryCtxSetFlags_v2(CUdevice dev, unsigned int flags);
CUresult cuEventDestroy_v2(CUevent hEvent);
CUresult cuIpcOpenMemHandle_v2(CUdeviceptr *pdptr, CUipcMemHandle handle, unsigned int Flags);
CUresult cuLinkAddData_v2(CUlinkState state, CUjitInputType type, void *data, size_t size, const char *name, unsigned int numOptions, CUjit_option *options, void **optionValues);
CUresult cuLinkAddFile_v2(CUlinkState state, CUjitInputType type, const char *path, unsigned int numOptions, CUjit_option *options, void **optionValues);
CUresult cuMemsetD16_v2(CUdeviceptr dstDevice, unsigned short us, size_t N);
CUresult cuMemcpyDtoH_v2(void *dstHost, CUdeviceptr srcDevice, size_t ByteCount);
CUresult cuMemGetAddressRange_v2(CUdeviceptr *pbase, size_t *psize, CUdeviceptr dptr);
CUresult cuMemHostGetDevicePointer_v2(CUdeviceptr *pdptr, void *p, unsigned int Flags);
CUresult cuMemHostRegister_v2(void *p, size_t bytesize, unsigned int Flags);
CUresult cuMemcpy2DAsync_v2(const CUDA_MEMCPY2D *pCopy, CUstream hStream);
CUresult cuMemcpy2DUnaligned_v2(const CUDA_MEMCPY2D *pCopy);
CUresult cuMemcpy3DAsync_v2(const CUDA_MEMCPY3D *pCopy, CUstream hStream);
CUresult cuMemcpyDtoA_v2(CUarray dstArray, size_t dstOffset, CUdeviceptr srcDevice, size_t ByteCount);
CUresult cuMemcpyDtoDAsync_v2(CUdeviceptr dstDevice, CUdeviceptr srcDevice, size_t ByteCount, CUstream hStream);
CUresult cuMemcpyDtoD_v2(CUdeviceptr dstDevice, CUdeviceptr srcDevice, size_t ByteCount);
CUresult cuMemcpyDtoHAsync_v2(void *dstHost, CUdeviceptr srcDevice, size_t ByteCount, CUstream hStream);
CUresult cuMemsetD32_v2(CUdeviceptr dstDevice, unsigned int ui, size_t N);
CUresult cuMemsetD8_v2(CUdeviceptr dstDevice, unsigned char uc, size_t N);
CUresult cuModuleGetGlobal_v2(CUdeviceptr *dptr, size_t *bytes, CUmodule hmod, const char *name);
CUresult cuLinkCreate_v2(unsigned int numOptions, CUjit_option *options, void **optionValues, CUlinkState *stateOut);
CUresult cuMemAllocHost_v2(void **pp, size_t bytesize);
CUresult cuMemFree_v2(CUdeviceptr dptr);
CUresult cuMemcpy3D_v2(const CUDA_MEMCPY3D *pCopy);
CUresult cuMemcpyHtoDAsync_v2(CUdeviceptr dstDevice, const void *srcHost, size_t ByteCount, CUstream hStream);
CUresult cuMemsetD2D8_v2(CUdeviceptr dstDevice, size_t dstPitch, unsigned char uc, size_t Width, size_t Height);
CUresult cuStreamDestroy_v2(CUstream hStream);
CUresult cuGetProcAddress_v2_alt(const char *symbol, void **funcPtr, int driverVersion, cuuint64_t flags, CUdriverProcAddressQueryResult *symbolStatus);
CUresult cuGetProcAddress_v2_ptsz(const char *symbol, void **funcPtr, int driverVersion, cuuint64_t flags, CUdriverProcAddressQueryResult *symbolStatus);
CUresult cuGetProcAddress_v2(const char *symbol, void **funcPtr, int driverVersion, cuuint64_t flags, CUdriverProcAddressQueryResult *symbolStatus);
CUresult cuMemcpyAtoD_v2(CUdeviceptr a1, CUarray a2, size_t a3, size_t a4);
CUresult cuGraphKernelNodeGetParams_v2(CUgraphNode hNode, CUDA_KERNEL_NODE_PARAMS *nodeParams);
CUresult cuGraphKernelNodeSetParams_v2(CUgraphNode hNode, const CUDA_KERNEL_NODE_PARAMS *nodeParams);
CUresult cuGetProcAddress_alt(const char *symbol, void **pfn, int cudaVersion, cuuint64_t flags, CUdriverProcAddressQueryResult *symbolStatus);
CUresult cuGraphAddKernelNode_v2(CUgraphNode *phGraphNode, CUgraph hGraph, const CUgraphNode *dependencies, size_t numDependencies, const CUDA_KERNEL_NODE_PARAMS *nodeParams);
CUresult cuMapMemory(CUdeviceptr *dptr, size_t bytesize, const CUmemAccessDesc *desc, size_t count);
CUresult cuVGPUViewAllocator(void **ptr, size_t size);
CUresult cuMemoryFree(void *ptr, size_t size);
CUresult cuMemoryAllocate(CUdeviceptr *dptr, size_t bytesize);
CUresult cuUnmapMemory(CUdeviceptr dptr, size_t bytesize);
nvmlReturn_t nvmlInternalGetExportTable(const void **ppExportTable, void *pExportTableId);
nvmlReturn_t nvmlGpuInstanceGetComputeInstancePossiblePlacements(nvmlGpuInstance_t gpuInstance, unsigned int profileId, nvmlComputeInstancePlacement_t *placements, unsigned int *count);
nvmlReturn_t nvmlGpuInstanceCreateComputeInstanceWithPlacement(nvmlGpuInstance_t gpuInstance, unsigned int profileId, const nvmlComputeInstancePlacement_t *placement, nvmlComputeInstance_t *computeInstance);
nvmlReturn_t nvmlGpmMigSampleGet(nvmlDevice_t device, unsigned int gpuInstanceId, nvmlGpmSample_t gpmSample);
nvmlReturn_t nvmlDeviceGetGpuMaxPcieLinkGeneration(nvmlDevice_t device, unsigned int *maxLinkGenDevice);
nvmlReturn_t nvmlDeviceClearFieldValues(nvmlDevice_t device, int valuesCount, nvmlFieldValue_t *values);
nvmlReturn_t nvmlDeviceCcuSetStreamState(nvmlDevice_t device, unsigned int state);
nvmlReturn_t nvmlDeviceCcuGetStreamState(nvmlDevice_t device, unsigned int *state);
