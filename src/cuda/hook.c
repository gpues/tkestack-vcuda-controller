#include <pthread.h>
#include <stdlib.h>

#include "include/base.h"
#include "stdio.h"
#include "string.h"

extern void *cuda_library_entry[];
extern device vdevices[16];
extern bool real_dlsym;

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
    return;
}
void cudbgApiDetach() {
    LINFO("Hijacking %s", "cudbgApiDetach");
    CUDA_ENTRY_CALL(cuda_library_entry, cudbgApiDetach);
    return;
}
void cudbgReportDriverApiError() {
    LINFO("Hijacking %s", "cudbgReportDriverApiError");
    CUDA_ENTRY_CALL(cuda_library_entry, cudbgReportDriverApiError, );
    return;
}
void cudbgReportDriverInternalError() {
    LINFO("Hijacking %s", "cudbgReportDriverInternalError");
    CUDA_ENTRY_CALL(cuda_library_entry, cudbgReportDriverInternalError, );
    return;
}
void cudbgApiInit(uint32_t arg) {
    LINFO("Hijacking %s", "cudbgApiInit");
    CUDA_ENTRY_CALL(cuda_library_entry, cudbgApiInit, arg);
    return;
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