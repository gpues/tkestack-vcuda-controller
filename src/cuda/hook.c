#include "include/all.h"

void *cuda_library_entry[1024];
extern vgpuDevice vdevices[16];
extern char *CUDA_FUNCS[1024];
// extern void *cuGetProcAddress_real;
extern char driver_version[FILENAME_MAX];

void load_cuda_libraries() {
    LINFO("Start hijacking cuda");

    read_version_from_proc((char *)&driver_version);
    char cuda_filename[FILENAME_MAX];
    snprintf(cuda_filename, FILENAME_MAX - 1, "%s.%s", CUDA_LIBRARY_PREFIX, driver_version);
    cuda_filename[FILENAME_MAX - 1] = '\0';

    void *cuda_handle = dlopen(cuda_filename, RTLD_NOW | RTLD_NODELETE);
    if (!cuda_handle) {
        LINFO("%s", "----");
        LINFO("%s", "----");
        LINFO("can't find library %s", cuda_filename);
    }
    for (int64_t i = 0; i < CUDA_ENTRY_END; ++i) {
        LINFO("%s", "----");
        LINFO("%s", "----");
        void *hookFunc = dlsym(cuda_handle, CUDA_FUNCS[i]);
        cuda_library_entry[i] = hookFunc;
    }
    LINFO("loaded_cuda_libraries");
    //    dlclose(cuda_handle);
}

void cudbgApiAttach() {
    LINFO("%s", "----");
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cudbgApiAttach");
    CUDA_ENTRY_CALL(cuda_library_entry, cudbgApiAttach);
}
void cudbgApiDetach() {
    LINFO("%s", "----");
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cudbgApiDetach");
    CUDA_ENTRY_CALL(cuda_library_entry, cudbgApiDetach);
}
void cudbgReportDriverApiError() {
    LINFO("%s", "----");
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cudbgReportDriverApiError");
    CUDA_ENTRY_CALL(cuda_library_entry, cudbgReportDriverApiError, );
}
void cudbgReportDriverInternalError() {
    LINFO("%s", "----");
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cudbgReportDriverInternalError");
    CUDA_ENTRY_CALL(cuda_library_entry, cudbgReportDriverInternalError, );
}
void cudbgApiInit(uint32_t arg) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cudbgApiInit");
    CUDA_ENTRY_CALL(cuda_library_entry, cudbgApiInit, arg);
}

CUDBGResult cudbgGetAPI(uint32_t major, uint32_t minor, uint32_t rev, CUDBGAPI *api) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cudbgGetAPI");
    return CUDA_ENTRY_CALL(cuda_library_entry, cudbgGetAPI, major, minor, rev, api);
}
CUDBGResult cudbgGetAPIVersion(uint32_t *major, uint32_t *minor, uint32_t *rev) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cudbgGetAPIVersion");
    return CUDA_ENTRY_CALL(cuda_library_entry, cudbgGetAPIVersion, major, minor, rev);
}
CUDBGResult cudbgMain(int apiClientPid, uint32_t apiClientRevision, int sessionId, int attachState, int attachEventInitialized, int writeFd, int detachFd, int attachStubInUse, int enablePreemptionDebugging) {
    LINFO("%s", "----");
    LINFO("Hijacking %s", "cudbgMain");
    return CUDA_ENTRY_CALL(cuda_library_entry, cudbgMain, apiClientPid, apiClientRevision, sessionId, attachState, attachEventInitialized, writeFd, detachFd, attachStubInUse, enablePreemptionDebugging);
}

CUresult cuGetProcAddress_alt(const char *symbol, void **pfn, int cudaVersion, cuuint64_t flags) {
    LINFO("%s", "----");
    LINFO("into cuGetProcAddress_alt symbol=%s:%d", symbol, cudaVersion);
    *pfn = (void *)find_symbols_in_table(symbol);
    if (*pfn) {
        LINFO("%s", "----");
        LINFO("found symbol %s", symbol);
        return CUDA_SUCCESS;
    }
    else {
        LINFO("%s", "----");
        LINFO("Hijacking %s", "cuGetProcAddress_alt");
        return CUDA_ENTRY_CALL(cuda_library_entry, cuGetProcAddress, symbol, pfn, cudaVersion, flags);
    }
}
CUresult cuGetProcAddress(const char *symbol, void **pfn, int cudaVersion, cuuint64_t flags) {
    LINFO("%s", "----");
    LINFO("into cuGetProcAddress symbol=%s:%d", symbol, cudaVersion);
    *pfn = (void *)find_symbols_in_table(symbol);
    if (!strcmp(symbol, "cuGetProcAddress")) {
        LINFO("%s", "----");
        LINFO("Hijacking %s", "cuGetProcAddress");
        CUresult res = CUDA_ENTRY_CALL(cuda_library_entry, cuGetProcAddress, symbol, pfn, cudaVersion, flags);
        if (!res) {
            LINFO("%s", "----");
            //            cuGetProcAddress_real = *pfn;
            *pfn = cuGetProcAddress_alt;
        }
        return res;
    }
    else if (*pfn) {
        LINFO("%s", "----");
        LINFO("found symbol %s", symbol);
        return CUDA_SUCCESS;
    }
    else {
        LINFO("%s", "----");
        LINFO("Hijacking %s", "cuGetProcAddress");
        return CUDA_ENTRY_CALL(cuda_library_entry, cuGetProcAddress, symbol, pfn, cudaVersion, flags);
    }
}

CUresult cuGetProcAddress_v2_alt(const char *symbol, void **pfn, int driverVersion, cuuint64_t flags, CUdriverProcAddressQueryResult *symbolStatus) {
    LINFO("%s", "----");
    LINFO("into cuGetProcAddress_v2_alt symbol=%s:%d", symbol, driverVersion);
    *pfn = (void *)find_symbols_in_table(symbol);
    if (*pfn) {
        LINFO("%s", "----");
        LINFO("found symbol %s", symbol);
        return CUDA_SUCCESS;
    }
    else {
        LINFO("%s", "----");
        LINFO("Hijacking %s", "cuGetProcAddress_v2_alt");
        return CUDA_ENTRY_CALL(cuda_library_entry, cuGetProcAddress_v2_alt, symbol, pfn, driverVersion, flags, symbolStatus);
    }
}
CUresult cuGetProcAddress_v2(const char *symbol, void **pfn, int driverVersion, cuuint64_t flags, CUdriverProcAddressQueryResult *symbolStatus) {
    LINFO("%s", "----");
    LINFO("into cuGetProcAddress_v2 symbol=%s:%d", symbol, driverVersion);
    *pfn = (void *)find_symbols_in_table(symbol);
    if (!strcmp(symbol, "cuGetProcAddress_v2")) {
        LINFO("%s", "----");
        LINFO("Hijacking %s", "cuGetProcAddress_v2");
        CUresult res = CUDA_ENTRY_CALL(cuda_library_entry, cuGetProcAddress_v2, symbol, pfn, driverVersion, flags, symbolStatus);
        if (!res) {
            LINFO("%s", "----");
            //            cuGetProcAddress_real = *pfn;
            *pfn = cuGetProcAddress_v2_alt;
        }
        return res;
    }
    else if (*pfn) {
        LINFO("%s", "----");
        LINFO("found symbol %s", symbol);
        return CUDA_SUCCESS;
    }
    else {
        LINFO("%s", "----");
        LINFO("Hijacking %s", "cuGetProcAddress_v2");
        return CUDA_ENTRY_CALL(cuda_library_entry, cuGetProcAddress_v2, symbol, pfn, driverVersion, flags, symbolStatus);
    }
}