#include <stdbool.h>

#include "cuda-subset.h"
#include "nvml-subset.h"

void ensure_initialized();
size_t wait_status_self(int status);
int64_t check_oom();
size_t compute_3d_array_alloc_bytes(const CUDA_ARRAY3D_DESCRIPTOR *pAllocateArray);
size_t compute_array_alloc_bytes(const CUDA_ARRAY_DESCRIPTOR *pAllocateArray);
int64_t check_memory_type(CUdeviceptr ptr);
u_int64_t get_current_device_memory_usage(CUdevice dev);
u_int64_t get_current_device_sm_limit(CUdevice dev);
int64_t lock_shrreg();
bool fix_lock_shrreg();
bool proc_alive(unsigned int pid);
void unlock_shrreg(void);
int64_t setspec();
int64_t set_gpu_device_memory_monitor(unsigned int pid, unsigned int deviceIndex, int64_t usedGpuMemory);
int active_oom_killer();
u_int64_t get_current_device_memory_limit(unsigned int dev);

u_int64_t get_gpu_memory_usage(unsigned int dev);
int64_t add_gpu_device_memory_usage(unsigned int pid, int devIndex, size_t bytesize, int a4);
int64_t oom_check(int devIndex, size_t bytesize);
int64_t rm_quitted_process();
size_t add_chunk_only(size_t dptr, size_t bytesize);
size_t allocate_raw(size_t *dptr, size_t bytesize);

size_t rm_gpu_device_memory_usage(unsigned int pid, int index, size_t bytesize, int flag);
size_t free_raw(size_t bytesize);
nvmlDevice_t handle_remap(nvmlDevice_t handle);
int set_env_utilization_switch();
int64_t set_host_pid(size_t hPid);
int get_vdevice_index(nvmlDevice_t *handle);
unsigned int comparelwr(const char *a1, const char *a2);
void my_strlwr(char *str);
int64_t init_virtual_map();
int64_t load_env_from_file(const char *filePath);
int allocator_init();
size_t assigning_virtual_pcibusID();
int64_t reset_task_pid();
size_t try_unlock_unified_lock();
size_t set_task_pid();
size_t try_lock_unified_lock();
size_t parse_cuda_visible_env();
int init_utilization_watcher();
CUcontext ctx_remap(CUcontext ctx);
CUcontext ctx_reversemap(CUcontext ctx);
int64_t find_symbols_in_table(const char *a1);

u_int64_t load_cuda_libraries();

CUresult cuArray3DCreate_helper(const CUDA_ARRAY3D_DESCRIPTOR *pAllocateArray);
CUresult cuArrayCreate_helper(const CUDA_ARRAY_DESCRIPTOR *pAllocateArray);