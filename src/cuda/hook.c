#include <dlfcn.h>

#include "include/all.h"

void *cuda_library_entry[1024];
extern vmDevice vdevices[16];
extern char *CUDA_FUNCS[1024];
// extern void *cuGetProcAddress_real;
extern char driver_version[FILENAME_MAX];
extern void *(*real_dlsym)(void *, const char *);

void load_cuda_libraries() {
    LINFO("Start hijacking cuda");
    read_version_from_proc((char *)&driver_version);
    char cuda_filename[FILENAME_MAX];
    snprintf(cuda_filename, FILENAME_MAX - 1, "%s.%s", CUDA_LIBRARY_PREFIX, driver_version);
    cuda_filename[FILENAME_MAX - 1] = '\0';
    LINFO("cuda_filename %s version: %s", cuda_filename, driver_version);

    void *cuda_handle = dlopen(cuda_filename, 4098);
    if (cuda_handle == 0) {
        LINFO("can't find library %s", cuda_filename);
    }
    for (int64_t i = 0; i < CUDA_ENTRY_END; ++i) {
        LINFO("LOADING %s %d/%d", CUDA_FUNCS[i], i, CUDA_ENTRY_END);
        void *hookFunc = real_dlsym(cuda_handle, CUDA_FUNCS[i]);
        cuda_library_entry[i] = hookFunc;
    }
    LINFO("loaded_cuda_libraries");
    dlclose(cuda_handle);
}

CUresult cuGetProcAddress_alt(const char *symbol, void **pfn, int cudaVersion, cuuint64_t flags) {
    LINFO("into cuGetProcAddress_alt symbol=%s:%d", symbol, cudaVersion);
    *pfn = (void *)find_cuda_symbols_in_table(symbol);
    if (*pfn) {
        LINFO("found symbol %s", symbol);
        return CUDA_SUCCESS;
    }
    else {
        LINFO("Hijacking %s", "cuGetProcAddress_alt");
        return CUDA_ENTRY_CALL(cuda_library_entry, cuGetProcAddress, symbol, pfn, cudaVersion, flags);
    }
}
CUresult cuGetProcAddress(const char *symbol, void **pfn, int cudaVersion, cuuint64_t flags) {
    LINFO("into cuGetProcAddress symbol=%s:%d", symbol, cudaVersion);
    *pfn = (void *)find_cuda_symbols_in_table(symbol);
    if (!strcmp(symbol, "cuGetProcAddress")) {
        LINFO("Hijacking %s", "cuGetProcAddress");
        CUresult res = CUDA_ENTRY_CALL(cuda_library_entry, cuGetProcAddress, symbol, pfn, cudaVersion, flags);
        if (!res) {
            //            cuGetProcAddress_real = *pfn;
            *pfn = cuGetProcAddress_alt;
        }
        return res;
    }
    else if (*pfn) {
        LINFO("found symbol %s", symbol);
        return CUDA_SUCCESS;
    }
    else {
        LINFO("Hijacking %s", "cuGetProcAddress");
        return CUDA_ENTRY_CALL(cuda_library_entry, cuGetProcAddress, symbol, pfn, cudaVersion, flags);
    }
}

CUresult cuGetProcAddress_v2_alt(const char *symbol, void **pfn, int driverVersion, cuuint64_t flags, CUdriverProcAddressQueryResult *symbolStatus) {
    LINFO("into cuGetProcAddress_v2_alt symbol=%s:%d", symbol, driverVersion);
    *pfn = (void *)find_cuda_symbols_in_table(symbol);
    if (*pfn) {
        LINFO("found symbol %s", symbol);
        return CUDA_SUCCESS;
    }
    else {
        LINFO("Hijacking %s", "cuGetProcAddress_v2_alt");
        return CUDA_ENTRY_CALL(cuda_library_entry, cuGetProcAddress_v2_alt, symbol, pfn, driverVersion, flags, symbolStatus);
    }
}
CUresult cuGetProcAddress_v2(const char *symbol, void **pfn, int driverVersion, cuuint64_t flags, CUdriverProcAddressQueryResult *symbolStatus) {
    LINFO("into cuGetProcAddress_v2 symbol=%s:%d", symbol, driverVersion);
    *pfn = (void *)find_cuda_symbols_in_table(symbol);
    if (!strcmp(symbol, "cuGetProcAddress_v2")) {
        LINFO("Hijacking %s", "cuGetProcAddress_v2");
        CUresult res = CUDA_ENTRY_CALL(cuda_library_entry, cuGetProcAddress_v2, symbol, pfn, driverVersion, flags, symbolStatus);
        if (!res) {
            //            cuGetProcAddress_real = *pfn;
            *pfn = cuGetProcAddress_v2_alt;
        }
        return res;
    }
    else if (*pfn) {
        LINFO("found symbol %s", symbol);
        return CUDA_SUCCESS;
    }
    else {
        LINFO("Hijacking %s", "cuGetProcAddress_v2");
        return CUDA_ENTRY_CALL(cuda_library_entry, cuGetProcAddress_v2, symbol, pfn, driverVersion, flags, symbolStatus);
    }
}

CUDBGResult cudbgGetAPI(uint32_t major, uint32_t minor, uint32_t rev, CUDBGAPI *api) {
    LINFO("Hijacking %s", "cudbgGetAPI");
    return CUDA_ENTRY_CALL(cuda_library_entry, cudbgGetAPI, major, minor, rev, api);
}
CUDBGResult cudbgGetAPIVersion(uint32_t *major, uint32_t *minor, uint32_t *rev) {
    LINFO("Hijacking %s", "cudbgGetAPIVersion");
    return CUDA_ENTRY_CALL(cuda_library_entry, cudbgGetAPIVersion, major, minor, rev);
}
CUDBGResult cudbgMain(int apiClientPid, uint32_t apiClientRevision, int sessionId, int attachState, int attachEventInitialized, int writeFd, int detachFd, int attachStubInUse, int enablePreemptionDebugging) {
    LINFO("Hijacking %s", "cudbgMain");
    return CUDA_ENTRY_CALL(cuda_library_entry, cudbgMain, apiClientPid, apiClientRevision, sessionId, attachState, attachEventInitialized, writeFd, detachFd, attachStubInUse, enablePreemptionDebugging);
}
// CUresult cuGetErrorString(CUresult error, const char **pStr);
CUresult cuGetErrorString(CUresult error, const char **pStr) {
    LINFO("Hijacking %s", "cuGetErrorString");
    return CUDA_ENTRY_CALL(cuda_library_entry, cuGetErrorString, error, pStr);
}