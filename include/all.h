#include <ctype.h>
#include <emmintrin.h>
#include <errno.h>
#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>
#include <signal.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #include <sys/kern_control.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/times.h>
#include <time.h>
#include <unistd.h>

#include "base.h"
#include "cuda-helper.h"
#include "cuda.h"
#include "func.h"
#include "limits.h"
#include "nvml-helper.h"
#include "nvml.h"
#include "vdpau.h"

typedef struct vgpuDevice_t { // 整个结构体  152 字节
    CUcontext *ctx;           // 偏移 0
    CUcontext *vctx;          // 偏移 8
    int index;                // 偏移 0x10
    int add_gpu_flag;         // 偏移 20
    int64_t devIndex;         // 偏移 24
    char *busIdLegacy;        // 偏移 0x20
    nvmlDevice_t vhandle;     // 偏移 0x28    40
    nvmlDevice_t vdevice;     // 偏移 0x30   48
    char uuid[16];            // 偏移 56
    nvmlDevice_t *handle;     // 偏移 0x40
    int64_t d6;               // 偏移 72
    int64_t e7;               // 偏移 0x50
    int64_t f8;               // 偏移 88
    int64_t f9;               // 偏移 0x60
    int64_t f0;               // 偏移 104
    int64_t f22;              // 偏移 0x70  // 进制相关的
    int64_t f11;              // 偏移 120
    int64_t f113;             // 偏移 0x80
    int64_t f114;             // 偏移 136
    int64_t f115;             // 偏移 0x90
    int64_t f116;             // 偏移 152
    //    asd detail;
} vmDevice;
