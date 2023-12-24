#include "include/all.h"

extern int record_nvml_map[0x10];
extern unsigned int cuda_to_nvml_map[0x10];
extern unsigned int virtual_map[0x10];
extern vmDevice vdevices[16];
extern void *cuda_library_entry[1024];
static int initiated;
const void *export_func[4];

unsigned int (*f6bp2)(nvmlDevice_t *, int64_t);

CUresult (*f6bp6)(CUmodule *module, const FatbincWrapper *fatbinc_wrapper, void *ptr1, void *ptr2, void *ptr3);
unsigned int (*fc6p0)(int64_t, int64_t, int64_t, int64_t);

size_t cudart_interface_fn1(nvmlDevice_t *handle, unsigned int dev) {
    size_t res = f6bp2(handle, virtual_map[dev]);
    if (!vdevices[cuda_to_nvml_map[dev]].ctx) {
        if (dev && virtual_map[dev] == virtual_map[dev - 1]) {
            vdevices[cuda_to_nvml_map[dev]].ctx = (CUcontext *)(*(size_t *)handle + (size_t)dev);
            vdevices[cuda_to_nvml_map[dev]].vctx = 0LL;
        }
        else {
            vdevices[cuda_to_nvml_map[dev]].ctx = (CUcontext *)*handle;
            vdevices[cuda_to_nvml_map[dev]].vctx = (CUcontext *)*handle;
        }
    }
    *handle = (nvmlDevice_t)vdevices[cuda_to_nvml_map[dev]].ctx;
    LINFO("cudart_inferface_fn1 ret ctx=%lx dev=%d", *handle, dev);
    return res;
}

unsigned int context_local_storate_ctor(int64_t a1, int64_t a2, int64_t a3, int64_t a4) {
    LINFO("into context_local_storage_ctor......");
    return (unsigned int)fc6p0(a1, a2, a3, a4);
}

unsigned short FATBIN_FILE_HEADER_KIND_PTX = 0x01;
unsigned short FATBIN_FILE_HEADER_VERSION_CURRENT = 0x101;

u_int FATBINC_MAGIC = 0x466243B1;
u_int FATBINC_VERSION = 0x1;
u_int FATBIN_MAGIC = 0xBA55ED50;
u_int FATBIN_VERSION = 0x01;

CUresult get_module_from_cubin(CUmodule *module, const FatbincWrapper *fatbinc_wrapper, void *ptr1, void *ptr2, void *ptr3) {
    CUdevice dev;
    LINFO("get module_from_cubin version=%x:%d", *fatbinc_wrapper, fatbinc_wrapper->version);
    FatbinHeader *v45 = fatbinc_wrapper->data;

    LINFO("hversion %x:%d %d:%ld", v45->magic, v45->version, v45->header_size, v45->files_size);

    unsigned long bytesize = 0;
    if (module == NULL || (*fatbinc_wrapper).magic != FATBINC_MAGIC || (*fatbinc_wrapper).version != FATBINC_VERSION) {
        return CUDA_ERROR_INVALID_VALUE;
    }
    FatbinHeader *fatbin_header = (*fatbinc_wrapper).data;
    if ((*fatbin_header).magic != FATBIN_MAGIC || (*fatbin_header).version != FATBIN_VERSION) {
        return CUDA_ERROR_INVALID_VALUE;
    }

    size_t *file = (size_t *)(fatbin_header + fatbin_header->files_size);

    size_t *end = file + fatbin_header->files_size;
    size_t index = (size_t)file;
    while (index < (size_t)end) {
        FatbinFileHeader *f = (FatbinFileHeader *)(size_t *)index;
        if (f->kind == 1 || f->kind == 2) {
            bytesize = f->uncompressed_payload;
        }

        index = index + f->header_size + f->padded_payload_size;
    }
    CUresult res = f6bp6(module, fatbinc_wrapper, ptr1, ptr2, ptr3);
    if (!res) {
        cuCtxGetDevice(&dev);
        if (oom_check(dev, bytesize))
            return CUDA_ERROR_OUT_OF_MEMORY;
        add_gpu_device_memory_usage(getpid(), dev, bytesize, 1LL);
    }

    LINFO("get_module_from_cubin res=%d", res);

    return res;
}
unsigned int (*fd4p0)(unsigned int, long long, long long);
int64_t check_software_valid(unsigned int a1, int64_t a2, int64_t a3) {
    LWARN("into fd4p0 %d", a1);
    unsigned int res = fd4p0(a1, a2, a3);
    LINFO("res=%d", res);
    return res;
}

CUresult cuGetExportTable(const void ***ppExportTable, const CUuuid *pExportTableId) {
    void **v21;
    LINFO("Hijacking %s", "cuGetExportTable");
    CUresult res = CUDA_ENTRY_CALL(cuda_library_entry, cuGetExportTable, ppExportTable, pExportTableId);
    unsigned int cu = *(u_int8_t *)pExportTableId;
    LINFO("res=%d cuGetExportTable TableId=%p p=%p:%p:k=%x", res, ppExportTable, *ppExportTable, **ppExportTable, cu);
    if (cu == 107) {
        v21 = (void **)*ppExportTable;

        LINFO("Internal function call: 6b initiated=%d exportTable=%p", initiated, v21);
        if (!initiated) {
            f6bp2 = v21[2];
            f6bp6 = v21[6];
            initiated = 1;
        }
        // mprotect 用于更改虚拟内存区域的访问权限。可以将一个文件或者其他对象映射到进程的地址空间中，从而实现对这些对象的访问。其函数原型如下：
        mprotect((void *)((u_int64_t)v21 & (0xFFFFFFFFFFFFLL / sysconf(_SC_PAGE_SIZE) * sysconf(_SC_PAGE_SIZE))), sysconf(_SC_PAGE_SIZE), PROT_READ | PROT_WRITE);
        v21[2] = cudart_interface_fn1;
        v21[6] = get_module_from_cubin;
    }
    else if (cu == 212) {
        //        fd4p0 = ppExportTable[1];
        fd4p0 = (*ppExportTable)[1];
        for (int i = 0; i <= 2; ++i) {
            export_func[i] = ppExportTable[i];
        }
        export_func[3] = check_software_valid;
    }
    return res;
}

// size_t runtime_callback_hooks_fn1(size_t a1, size_t a2) {
//     LINFO("runtime_callback_hooks_fn1");
//     return fa0p1(a1, a2);
// }
// size_t runtime_callback_hooks_fn5(size_t a1, size_t a2) {
//     LINFO("runtime_callback_hooks_fn5");
//     return fa0p5(a1, a2);
// }
