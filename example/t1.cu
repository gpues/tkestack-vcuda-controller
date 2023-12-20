#include "nvml.h"
#include <dlfcn.h>
#include <inttypes.h>
#include <limits.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    // First initialize NVML library
    result = nvmlInit();
    if (NVML_SUCCESS != result) {
        printf("Failed to initialize NVML: %s\n", nvmlErrorString(result));
        return 1;
    }

    result = nvmlInitWithFlags(1) printf("nvmlInitWithFlags: %s\n", nvmlErrorString(result));
    unsigned int deviceCount;
    result = nvmlDeviceGetCount_v2(&deviceCount);
    if (result != NVML_SUCCESS) {
        printf("err: %d\n", result);
    }
    else {
        printf("Number of devices: %d\n", deviceCount);
    }
    return 0;
}