#include <dlfcn.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "include/base.h"

nvmlReturn_t nvmlInitWithFlags(unsigned int flags) {
    load_necessary_data();
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlInitWithFlags");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)(unsigned int) = (nvmlReturn_t(*)(unsigned int))dlsym(nvml_handle, "nvmlInitWithFlags");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc(flags);
    TimeProfileDestroy(pprof);
    return rs;
}
nvmlReturn_t nvmlInit_v2() {
    load_necessary_data();
    HOOK_TRACE_PROFILE *pprof = TimeProfile("nvmlInit_v2");
    void *nvml_handle = dlopen(NvmlSo(), RTLD_GLOBAL | RTLD_LAZY);
    nvmlReturn_t (*hookFunc)() = (nvmlReturn_t(*)())dlsym(nvml_handle, "nvmlInit_v2");
    HOOK_CHECK(hookFunc);
    nvmlReturn_t rs = hookFunc();
    TimeProfileDestroy(pprof);
    return rs;
}