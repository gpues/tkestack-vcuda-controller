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
        printf("%s %s", __FILE__, __LINE__);
        printf("%s %s", __FILE__, __LINE__);
        LINFO("can't find library %s", cuda_filename);
    }
    for (int64_t i = 0; i < CUDA_ENTRY_END; ++i) {
        printf("%s %s", __FILE__, __LINE__);
        printf("%s %s", __FILE__, __LINE__);
        void *hookFunc = dlsym(cuda_handle, CUDA_FUNCS[i]);
        cuda_library_entry[i] = hookFunc;
    }
    LINFO("loaded_cuda_libraries");
    //    dlclose(cuda_handle);
}

void cudbgApiAttach() {
    printf("%s %s", __FILE__, __LINE__);
    printf("%s %s", __FILE__, __LINE__);
    LINFO("Hijacking %s", "cudbgApiAttach");
    CUDA_ENTRY_CALL(cuda_library_entry, cudbgApiAttach);
}
void cudbgApiDetach() {
    printf("%s %s", __FILE__, __LINE__);
    printf("%s %s", __FILE__, __LINE__);
    LINFO("Hijacking %s", "cudbgApiDetach");
    CUDA_ENTRY_CALL(cuda_library_entry, cudbgApiDetach);
}
void cudbgReportDriverApiError() {
    printf("%s %s", __FILE__, __LINE__);
    printf("%s %s", __FILE__, __LINE__);
    LINFO("Hijacking %s", "cudbgReportDriverApiError");
    CUDA_ENTRY_CALL(cuda_library_entry, cudbgReportDriverApiError, );
}
void cudbgReportDriverInternalError() {
    printf("%s %s", __FILE__, __LINE__);
    printf("%s %s", __FILE__, __LINE__);
    LINFO("Hijacking %s", "cudbgReportDriverInternalError");
    CUDA_ENTRY_CALL(cuda_library_entry, cudbgReportDriverInternalError, );
}
void cudbgApiInit(uint32_t arg) {
    printf("%s %s", __FILE__, __LINE__);
    LINFO("Hijacking %s", "cudbgApiInit");
    CUDA_ENTRY_CALL(cuda_library_entry, cudbgApiInit, arg);
}

CUDBGResult cudbgGetAPI(uint32_t major, uint32_t minor, uint32_t rev, CUDBGAPI *api) {
    printf("%s %s", __FILE__, __LINE__);
    LINFO("Hijacking %s", "cudbgGetAPI");
    return CUDA_ENTRY_CALL(cuda_library_entry, cudbgGetAPI, major, minor, rev, api);
}
CUDBGResult cudbgGetAPIVersion(uint32_t *major, uint32_t *minor, uint32_t *rev) {
    printf("%s %s", __FILE__, __LINE__);
    LINFO("Hijacking %s", "cudbgGetAPIVersion");
    return CUDA_ENTRY_CALL(cuda_library_entry, cudbgGetAPIVersion, major, minor, rev);
}
CUDBGResult cudbgMain(int apiClientPid, uint32_t apiClientRevision, int sessionId, int attachState, int attachEventInitialized, int writeFd, int detachFd, int attachStubInUse, int enablePreemptionDebugging) {
    printf("%s %s", __FILE__, __LINE__);
    LINFO("Hijacking %s", "cudbgMain");
    return CUDA_ENTRY_CALL(cuda_library_entry, cudbgMain, apiClientPid, apiClientRevision, sessionId, attachState, attachEventInitialized, writeFd, detachFd, attachStubInUse, enablePreemptionDebugging);
}

CUresult cuGetProcAddress_alt(const char *symbol, void **pfn, int cudaVersion, cuuint64_t flags) {
    printf("%s %s", __FILE__, __LINE__);
    LINFO("into cuGetProcAddress_alt symbol=%s:%d", symbol, cudaVersion);
    *pfn = (void *)find_symbols_in_table(symbol);
    if (*pfn) {
        printf("%s %s", __FILE__, __LINE__);
        LINFO("found symbol %s", symbol);
        return CUDA_SUCCESS;
    }
    else {
        printf("%s %s", __FILE__, __LINE__);
        LINFO("Hijacking %s", "cuGetProcAddress_alt");
        return CUDA_ENTRY_CALL(cuda_library_entry, cuGetProcAddress, symbol, pfn, cudaVersion, flags);
    }
}
CUresult cuGetProcAddress(const char *symbol, void **pfn, int cudaVersion, cuuint64_t flags) {
    printf("%s %s", __FILE__, __LINE__);
    LINFO("into cuGetProcAddress symbol=%s:%d", symbol, cudaVersion);
    *pfn = (void *)find_symbols_in_table(symbol);
    if (!strcmp(symbol, "cuGetProcAddress")) {
        printf("%s %s", __FILE__, __LINE__);
        LINFO("Hijacking %s", "cuGetProcAddress");
        CUresult res = CUDA_ENTRY_CALL(cuda_library_entry, cuGetProcAddress, symbol, pfn, cudaVersion, flags);
        if (!res) {
            printf("%s %s", __FILE__, __LINE__);
            //            cuGetProcAddress_real = *pfn;
            *pfn = cuGetProcAddress_alt;
        }
        return res;
    }
    else if (*pfn) {
        printf("%s %s", __FILE__, __LINE__);
        LINFO("found symbol %s", symbol);
        return CUDA_SUCCESS;
    }
    else {
        printf("%s %s", __FILE__, __LINE__);
        LINFO("Hijacking %s", "cuGetProcAddress");
        return CUDA_ENTRY_CALL(cuda_library_entry, cuGetProcAddress, symbol, pfn, cudaVersion, flags);
    }
}

CUresult cuGetProcAddress_v2_alt(const char *symbol, void **pfn, int driverVersion, cuuint64_t flags, CUdriverProcAddressQueryResult *symbolStatus) {
    printf("%s %s", __FILE__, __LINE__);
    LINFO("into cuGetProcAddress_v2_alt symbol=%s:%d", symbol, driverVersion);
    *pfn = (void *)find_symbols_in_table(symbol);
    if (*pfn) {
        printf("%s %s", __FILE__, __LINE__);
        LINFO("found symbol %s", symbol);
        return CUDA_SUCCESS;
    }
    else {
        printf("%s %s", __FILE__, __LINE__);
        LINFO("Hijacking %s", "cuGetProcAddress_v2_alt");
        return CUDA_ENTRY_CALL(cuda_library_entry, cuGetProcAddress_v2_alt, symbol, pfn, driverVersion, flags, symbolStatus);
    }
}
CUresult cuGetProcAddress_v2(const char *symbol, void **pfn, int driverVersion, cuuint64_t flags, CUdriverProcAddressQueryResult *symbolStatus) {
    printf("%s %s", __FILE__, __LINE__);
    LINFO("into cuGetProcAddress_v2 symbol=%s:%d", symbol, driverVersion);
    *pfn = (void *)find_symbols_in_table(symbol);
    if (!strcmp(symbol, "cuGetProcAddress_v2")) {
        printf("%s %s", __FILE__, __LINE__);
        LINFO("Hijacking %s", "cuGetProcAddress_v2");
        CUresult res = CUDA_ENTRY_CALL(cuda_library_entry, cuGetProcAddress_v2, symbol, pfn, driverVersion, flags, symbolStatus);
        if (!res) {
            printf("%s %s", __FILE__, __LINE__);
            //            cuGetProcAddress_real = *pfn;
            *pfn = cuGetProcAddress_v2_alt;
        }
        return res;
    }
    else if (*pfn) {
        printf("%s %s", __FILE__, __LINE__);
        LINFO("found symbol %s", symbol);
        return CUDA_SUCCESS;
    }
    else {
        printf("%s %s", __FILE__, __LINE__);
        LINFO("Hijacking %s", "cuGetProcAddress_v2");
        return CUDA_ENTRY_CALL(cuda_library_entry, cuGetProcAddress_v2, symbol, pfn, driverVersion, flags, symbolStatus);
    }
}