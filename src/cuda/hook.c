#include "include/all.h"

extern void *cuda_library_entry[];
extern device vdevices[16];
extern bool real_dlsym;
extern void *cuGetProcAddress_real;
u_int64_t load_cuda_libraries() {
    char dest[512];
    char s[4104];

    LINFO("Start hijacking");
    snprintf(s, 0xFFFuLL, "%s", "libcuda.so.1");
    s[4095] = 0;
    void *handle = dlopen(s, 4098);
    if (!handle) {
        LINFO("can't find library %s", s);
    }
    for (int i = 0; i <= 195; ++i) {
        LINFO("LOADING %s %d", v9, i);
        *(&cuda_library_entry + 2 * i) = (__int64(__fastcall *)(_QWORD))real_dlsym(handle, *(&cuda_library_entry + 2 * i + 1));
        if (!*(&cuda_library_entry + 2 * i)) {
            *(&cuda_library_entry + 2 * i) = (__int64(__fastcall *)(_QWORD))real_dlsym(-1LL, *(&cuda_library_entry + 2 * i + 1));
            if (!*(&cuda_library_entry + 2 * i)) {
                LINFO("can't find function %s in %s", (const char *)*(&cuda_library_entry + 2 * i + 1), s);
                memset(dest, 0, 0x1F4uLL);
                strcpy(dest, (const char *)*(&cuda_library_entry + 2 * i + 1));
                while ((unsigned int)prior_function(dest)) {
                    *(&cuda_library_entry + 2 * i) = (__int64(__fastcall *)(_QWORD))real_dlsym(-1LL, dest);
                    if (*(&cuda_library_entry + 2 * i)) {
                        LINFO("found prior function %s", dest);
                        break;
                    }
                }
            }
        }
    }

    LINFO("loaded_cuda_libraries");
    if (!cuda_library_entry) {
        LINFO("is NULL");
    }
    dlclose(handle);
    return;
}

void cudbgApiAttach() {
    LINFO("Hijacking %s", "cudbgApiAttach");
    CUDA_ENTRY_CALL(cuda_library_entry, cudbgApiAttach);
}
void cudbgApiDetach() {
    LINFO("Hijacking %s", "cudbgApiDetach");
    CUDA_ENTRY_CALL(cuda_library_entry, cudbgApiDetach);
}
void cudbgReportDriverApiError() {
    LINFO("Hijacking %s", "cudbgReportDriverApiError");
    CUDA_ENTRY_CALL(cuda_library_entry, cudbgReportDriverApiError, );
}
void cudbgReportDriverInternalError() {
    LINFO("Hijacking %s", "cudbgReportDriverInternalError");
    CUDA_ENTRY_CALL(cuda_library_entry, cudbgReportDriverInternalError, );
}
void cudbgApiInit(uint32_t arg) {
    LINFO("Hijacking %s", "cudbgApiInit");
    CUDA_ENTRY_CALL(cuda_library_entry, cudbgApiInit, arg);
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

CUresult cuGetProcAddress_alt(const char *symbol, void **pfn, int cudaVersion, cuuint64_t flags) {
    LINFO("into cuGetProcAddress_alt symbol=%s:%d", symbol, cudaVersion);
    *pfn = (void *)find_symbols_in_table(symbol);
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
    *pfn = (void *)find_symbols_in_table(symbol);
    if (!strcmp(symbol, "cuGetProcAddress")) {
        LINFO("Hijacking %s", "cuGetProcAddress");
        CUresult res = CUDA_ENTRY_CALL(cuda_library_entry, cuGetProcAddress, symbol, pfn, cudaVersion, flags);
        if (!res) {
            cuGetProcAddress_real = *pfn;
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
    *pfn = (void *)find_symbols_in_table(symbol);
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
    *pfn = (void *)find_symbols_in_table(symbol);
    if (!strcmp(symbol, "cuGetProcAddress_v2")) {
        LINFO("Hijacking %s", "cuGetProcAddress_v2");
        CUresult res = CUDA_ENTRY_CALL(cuda_library_entry, cuGetProcAddress, symbol, pfn, driverVersion, flags);
        if (!res) {
            cuGetProcAddress_real = *pfn;
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
        return CUDA_ENTRY_CALL(cuda_library_entry, cuGetProcAddress, symbol, pfn, driverVersion, flags);
    }
}