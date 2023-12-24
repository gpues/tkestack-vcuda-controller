dword_610C0     curren_owner
dword_610C8     child_init_flag
qword_610D0     global_config
qword_23D940    global_config
dword_6113C     g_sm_num
dword_61140     g_max_thread_per_sm
dword_61144     g_cur_cuda_cores
dword_61148     g_total_cuda_cores






todo

remove_chunk
cuGetExportTable
init_utilization_watcher
get_module_from_cubin
assigning_virtual_pcibusID
getextrapid
read_pcibus_from_file
ctx_reversemap
ctx_remap
readfromdir
cudart_interface_fn1
cuDeviceGetByPCIBusId
cuDevicePrimaryCtxGetState
cuDevicePrimaryCtxRetain
cuDevicePrimaryCtxRelease_v2
rm_gpu_device_memory_usage
put_device_info                         update device_plugin version to nvidia v0.14.0


fix node vmDevice order and upgrade to compatable with cuda 12.2
cuDeviceGetCount
cuDeviceTotalMem_v2
cuMemGetInfo_v2
cuGetProcAddress_v2
cuGetProcAddress_v2_alt
cuGetProcAddress_v2_ptsz
cuGraphInstantiateWithFlags
parse_cuda_visible_env
parser
put_device_info
need_cuda_virtualize
setthreadmap
cuDeviceGetCount
check_validator


postInit
preInit
rm_gpu_device_memory_usage
try_lock_unified_lock

 

NVIDIA_DEVICE_MAP 存储: i:devID ...


record_nvml_map
-  0 位置: 
-  1 位置: 
-  2 位置: 
-  3 位置: 
-  4 位置: 
-  5 位置: 记录了 NVIDIA_DEVICE_MAP 真实的对应序号的 的设备信息,不一定从0开始
-  6 位置: 
-  7 位置: 
-  8 位置: 
-  9 位置: 
- 10 位置: 
- 11 位置: 
- 12 位置: 
- 13 位置: 
- 14 位置: 
- 15 位置: 

virtual_map
-  0 位置:  
-  1 位置: 
-  2 位置: 
-  3 位置: 
-  4 位置: 
-  5 位置: 
-  6 位置: 
-  7 位置: 记录了 NVIDIA_DEVICE_MAP 真实的对应序号的 的设备信息,不一定从0开始
-  8 位置: 
-  9 位置: 
- 10 位置: 
- 11 位置: 
- 12 位置: 
- 13 位置: 
- 14 位置: 
- 15 位置: 

virtual_devices
-  0 位置: NVIDIA_DEVICE_MAP 挂载的数量
-  1 位置: 
-  2 位置: 
-  3 位置: 
-  4 位置: 
-  5 位置: 
-  6 位置: 
-  7 位置: 
-  8 位置: 
-  9 位置: 
- 10 位置: 
- 11 位置: 
- 12 位置: 
- 13 位置: 
- 14 位置: 
- 15 位置: 
- 16 位置: 
 


cuda_to_nvml_map
-  0 位置: 记录了NVIDIA_DEVICE_MAP挂载的第一块设备序号
-  1 位置: 
-  2 位置: 
-  3 位置: 
-  4 位置: 
-  5 位置: 
-  6 位置: 
-  7 位置: 
-  8 位置: 
-  9 位置: 
- 10 位置: 
- 11 位置: 
- 12 位置: 
- 13 位置: 
- 14 位置: 
- 15 位置: 

record_cuda_map ,在容器内 从0开始
-  0 位置: record_nvml_map [第一块设备序号] 的值 
-  1 位置: 
-  2 位置: 
-  3 位置: 
-  4 位置: 
-  5 位置: 
-  6 位置: 
-  7 位置: 
-  8 位置: 
-  9 位置: 
- 10 位置: 
- 11 位置: 
- 12 位置: 
- 13 位置: 
- 14 位置: 
- 15 位置: 
