#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
#include <sys/kern_control.h>

#include "include/base.h"

int memory_override;
sharedRegionT *flags; //   [ _,pid,sem,_, _,_,_,_,_]
int64_t in_fs_offset;
int64_t initial_offset;
unsigned int curren_owner;
unsigned int offset = 804680LL;

static int g_sm_num = 0; //  流处理多处理器，它是GPU的核心计算单元，也被称作为CUDA核或CUDA流处理器。SM是一个独立的处理单元，包含一组处理器核心、缓存和共享内存等资源。
static int g_max_thread_per_sm = 0;
static volatile int g_cur_cuda_cores = 0;
static volatile int g_total_cuda_cores = 0;
int pidfound;
int allocmode;
int fd;
int child_init_flag;
int virtual_devices[17]; // count ,0,....15
int record_cuda_map[17];
unsigned int virtual_nvml_devices;
bool duplicate_devices;
void *cuda_library_entry[] = {

};

void *nvml_library_entry[] = {

};

int record_nvml_map[16];
nvmlDevice_t *virtual_map[16];
pthread_mutex_t mutex;

size_t *device_overallocated[3];
size_t IPCSIZE;
size_t *cuarray_format_bytes;
u_int64_t context_size;
unsigned int cuda_to_nvml_map[16];
device vdevices[16];
bool real_dlsym;

pthread_mutex_t dlsym_lock;
int dlmap_count;
char *dlmap[1000];

pthread_once_t dlsym_init_flag = PTHREAD_ONCE_INIT;

int env_utilization_switch;

char *unified_lock = "/tmp/vgpulock/lock";