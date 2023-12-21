#include "include/all.h"

extern int record_nvml_map[0x10];
extern unsigned int cuda_to_nvml_map[0x10];
extern unsigned int virtual_map[0x10];
extern device vdevices[16];
extern void *cuda_library_entry[];
const void *export_func[4];
int initiated;

int64_t cudart_interface_fn1(nvmlDevice_t *handle, unsigned int dev) {
    if (!vdevices[cuda_to_nvml_map[dev]].ctx) {
        if (dev && virtual_map[dev] == virtual_map[dev - 1]) {
            vdevices[cuda_to_nvml_map[dev]].ctx = (CUcontext)((int64_t *)*handle + (int)dev);
            vdevices[cuda_to_nvml_map[dev]].vctx = 0LL;
        }
        else {
            vdevices[cuda_to_nvml_map[dev]].ctx = (CUcontext *)handle;
            vdevices[cuda_to_nvml_map[dev]].vctx = (CUcontext *)handle;
        }
    }
    *handle = (nvmlDevice_t)vdevices[cuda_to_nvml_map[dev]].ctx;
    LINFO("cudart_inferface_fn1 ret ctx=%lx dev=%d", *handle, dev);
    return virtual_map[dev];
}

unsigned int (*fd4p0)(unsigned int, int64_t, int64_t);
unsigned int (*f6bp2)(unsigned int, int64_t, int64_t);
unsigned int (*f6bp6)(int64_t, unsigned int *, int64_t, int64_t, int64_t);
unsigned int (*fc6p0)(int64_t, int64_t, int64_t, int64_t);

unsigned int context_local_storate_ctor(int64_t a1, int64_t a2, int64_t a3, int64_t a4) {
    LINFO("into context_local_storage_ctor......");
    return (unsigned int)fc6p0(a1, a2, a3, a4);
}

int64_t get_module_from_cubin(int64_t a1, unsigned int *a2, int64_t a3, int64_t a4, int64_t a5) {
    CUdevice dev;
    LINFO("get module_from_cubin version=%x:%d", *a2, a2[1]);
    v45 = (unsigned int *)&(a2[1]);
    LINFO("hversion %x:%d %d:%ld", *v45, *((u_int16_t *)v45 + 2), *((u_int16_t *)v45 + 3), *((_QWORD *)v45 + 1));

    v46 = v45;
    int64_t bytesize = 0LL;
    v44 = 0LL;
    //     二维数组？
    for (u_int16_t *i = (u_int16_t *)(v45 + 4); i < (u_int16_t *)((char *)v46 + *((_QWORD *)v45 + 1)); i = (u_int16_t *)((char *)i + v25)) {
        v47 = i;
        LINFO("get_module_from_cubin: kind=%d version=%d size=%d lsize=%d un=%ld", *v47, v47[1], *((unsigned int *)v47 + 2), *((unsigned int *)v47 + 4), *((_QWORD *)v47 + 7))
        if ((*v47 == 1 || *v47 == 2) && (!v44 || v44[1] == v47[1]))
            bytesize = *((_QWORD *)v47 + 7);
        v44 = i;
        if (*v47 == 1)
            v25 = *((unsigned int *)v47 + 2) + 72LL;
        else
            v25 = *((unsigned int *)v47 + 2) + 64LL;
    }
    v41 = f6bp6(a1, a2, a3, a4, a5);
    if (!v41) {
        cuCtxGetDevice(&dev);
        if ((unsigned int)oom_check(dev, bytesize))
            return 2LL;
        add_gpu_device_memory_usage(getpid(), dev, bytesize, 1LL);
    }

    LINFO("get_module_from_cubin res=%d", v41);

    return v41;
}

int64_t check_software_valid(unsigned int a1, int64_t a2, int64_t a3) {
    LWARN("into fd4p0 %d", a1);
    unsigned int res = fd4p0(a1, a2, a3);
    LINFO("res=%d", res);
    return res;
}

CUresult cuGetExportTable(const void ***ppExportTable, const CUuuid *pExportTableId) {
    const void **v21;

    LINFO("Hijacking %s", "cuGetExportTable");
    CUresult res = CUDA_ENTRY_CALL(cuda_library_entry, cuGetExportTable, ppExportTable, pExportTableId);

    int64_t cu = *(int64_t *)pExportTableId;
    LINFO("res=%d cuGetExportTable TableId=%p p=%p:%p:k=%x", res, ppExportTable, *ppExportTable, **ppExportTable, cu);
    if (cu == 107) {
        v21 = *ppExportTable;

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
        fd4p0 = (*ppExportTable)[1];
        for (int i = 0; i <= 2; ++i) {
            export_func[i] = *ppExportTable[i];
        }
        export_func[3] = check_software_valid;
    }
    return res;
}

size_t runtime_callback_hooks_fn1(size_t a1, size_t a2) {
    LINFO("runtime_callback_hooks_fn1");
    return fa0p1(a1, a2);
}
size_t runtime_callback_hooks_fn5(size_t a1, size_t a2) {
    LINFO("runtime_callback_hooks_fn5");
    return fa0p5(a1, a2);
}
