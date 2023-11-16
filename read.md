- https://github.com/Tony-Tan/CUDA_Freshman
- https://github.com/Bruce-Lee-LY/cuda_hook
- https://muzhan.blog.csdn.net/article/details/120157690
- https://blog.csdn.net/inthat/article/details/119931358
- https://blog.csdn.net/leviopku/category_11340416.html
- https://zhuanlan.zhihu.com/p/622838762


- https://gitlab.com/nvidia/headers/cuda-individual/cudart
- https://blog.csdn.net/kunhe0512/article/details/128951128
- https://developer.nvidia.com/zh-cn/blog/cuda-virtual-address-management-cn/

- https://zhuanlan.zhihu.com/p/646091910
- https://segmentfault.com/a/1190000018460795
- CUDA 10.2 引入虚拟显存

- https://www.cnblogs.com/deny/p/16305744.html

```c

const char *nvmlErrorString(nvmlReturn_t result) {
  const char *(*_entry)(nvmlReturn_t) = NVML_FIND_ENTRY(nvml_library_entry, nvmlErrorString);
  return _entry(result);
}


CUresult cuLaunchKernel_ptsz(CUfunction f, unsigned int gridDimX, unsigned int gridDimY, unsigned int gridDimZ, unsigned int blockDimX, unsigned int blockDimY, unsigned int blockDimZ, unsigned int sharedMemBytes, CUstream hStream, void **kernelParams, void **extra) { 
     rate_limiter(gridDimX * gridDimY * gridDimZ, blockDimX * blockDimY * blockDimZ);
}
```
readelf -Ws /usr/bin/nvidia-smi