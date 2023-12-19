#include <pthread.h>
#include <stdlib.h>

#include "include/base.h"
#include "include/func.h"
#include "include/nvml-helper.h"
#include "include/nvml.h"
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
