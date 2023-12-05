# !/usr/bin/python3
# coding=utf-8

from __future__ import absolute_import
from __future__ import division
from __future__ import print_function
from __future__ import with_statement

import optparse
import os
import sys

from CppHeaderParser import CppHeader


class CodeGenerate():
    def __init__(self, type_, file_, output_, return_type):
        self.header = None
        self.type = type_
        self.return_type = return_type
        self.file = file_
        self.output = output_

        self.func_list = []

        self.originals_file = self.output + "/" + self.type + "_originals.c"
        self.hook_file = self.output + "/" + self.type + "_hook.c"
        self.originals_map = {}

        self.hook_include = """
// auto generate $hook_num$ apis

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <dlfcn.h>
#include "include/base.h"
"""
        self.hook_template = """
$ret$ $func_name$($func_param$) {
    HOOK_TRACE_PROFILE *pprof = TimeProfile("$func_name$");
    void *$type$_handle = dlopen($so_type$, RTLD_GLOBAL | RTLD_LAZY);
    $ret$ (*hookFunc)($param_type$) = ($ret$(*)($param_type$)) dlsym($type$_handle, "$func_name$");
    HOOK_CHECK(hookFunc);
    $ret$ rs = hookFunc($param_name_strip$);
    $type$TimeProfileDestroy(pprof, rs);
    return rs;
}
"""
        self.cuda_hook = {
            "cuDriverGetVersion": 1,
            "cuInit": 1,
            "cuGetProcAddress": 1,
            "cuMemAllocManaged": 1,
            "cuMemAllocPitch": 1,
            "cuMemAlloc": 1,
            "cuArrayCreate": 1,
            "cuArrayCreate_v2": 1,
            "cuMemAllocPitch_v2": 1,
            "cuArray3DCreate": 1,
            "cuMipmappedArrayCreate": 1,
            "cuDeviceTotalMem": 1,
            "cuMemGetInfo": 1,
            "cuLaunchKernel": 1,
            "cuLaunch": 1,
            "cuLaunchCooperativeKernel": 1,
            "cuLaunchGrid": 1,
            "cuLaunchGridAsync": 1,
            "cuFuncSetBlockShape": 1,
            "cuLaunchKernel_ptsz": 1,
            "cuLaunchCooperativeKernel_ptsz": 1,
            "cuArray3DCreate_v2": 1,
            "cuDeviceTotalMem_v2": 1,
            "cuMemAlloc_v2": 1,
            "cuMemGetInfo_v2": 1,
        }
        self.nvml_hook = {
            "nvmlInitWithFlags": 1,
            "nvmlInit_v2": 1,
            "nvmlInit": 1,
            "nvmlDeviceGetGraphicsRunningProcesses": 1,
            "nvmlDeviceGetGraphicsRunningProcesses_v2": 1,
            "nvmlDeviceGetGraphicsRunningProcesses_v3": 1,
            "nvmlDeviceGetComputeRunningProcesses": 1,
            "nvmlDeviceGetComputeRunningProcesses_v2": 1,
            "nvmlDeviceGetComputeRunningProcesses_v3": 1,
            "nvmlDeviceGetMPSComputeRunningProcesses": 1,
            "nvmlDeviceGetMPSComputeRunningProcesses_v2": 1,
            "nvmlDeviceGetMPSComputeRunningProcesses_v3": 1,
            "nvmlDeviceIsMigDeviceHandle": 1,
            "nvmlDeviceGetDeviceHandleFromMigDeviceHandle": 1,
            "nvmlDeviceGetIndex": 1,
            "nvmlDeviceGetMemoryInfo_v2": 1,
            "nvmlErrorString": 1,
        }
        self.nvml_discard = {
            #     "nvmlInit": 1,
            #     "nvmlDeviceGetPciInfo": 1,
            #     "nvmlDeviceGetCount": 1,
            #     "nvmlDeviceGetHandleByIndex": 1,
            #     "nvmlDeviceGetHandleByPciBusId": 1,
            #     "nvmlDeviceGetNvLinkRemotePciInfo": 1,
            #     "nvmlDeviceRemoveGpu": 1,
            #     "nvmlDeviceGetGridLicensableFeatures": 1,
            #     "nvmlEventSetWait": 1,
            #     "nvmlDeviceGetAttributes": 1,
            #     "nvmlComputeInstanceGetInfo": 1,
            #     "nvmlDeviceGetComputeRunningProcesses": 1,
            #     "nvmlDeviceGetGraphicsRunningProcesses": 1,
            #     "nvmlDeviceGetMPSComputeRunningProcesses": 1,
            #     "nvmlBlacklistDeviceInfo_t": 1,
            #     "nvmlGetBlacklistDeviceCount": 1,
            #     "nvmlGetBlacklistDeviceInfoByIndex": 1,
            #     "nvmlDeviceGetGpuInstancePossiblePlacements": 1,
            #     "nvmlVgpuInstanceGetLicenseInfo": 1,
        }
        self.cuda_discard = {}
        self.cuda_map = {}
        self.nvml_map = {}

    def parse_header(self):
        with open(self.file, 'r') as f:
            data = f.read()
        with open('./%s_append.txt' % self.type, 'r', encoding='utf8') as f:
            data += '\n' + f.read()
        self.header = CppHeader(data, argType='string')
        print("{} total func num: {}".format(self.type, len(self.header.functions)))

    def generate_func(self):
        for func in self.header.functions:
            func_name = func["name"]
            ret = func["rtnType"].replace(
                "CUDAAPI", "").replace(
                "__CUDA_DEPRECATED", "").replace(
                "DECLDIR", "").replace(
                "CUDARTAPI_CDECL", "").replace(
                "CUDARTAPI", "").replace(
                "__host__", "").replace(
                "__cudart_builtin__", "").replace(
                "CUDNNWINAPI", "").replace(
                "CUBLASWINAPI", "").replace(
                "CUBLASAPI", "").replace(
                "CUFFTAPI", "").replace(
                "NVTX_DECLSPEC", "").replace(
                "NVTX_API", "").replace(
                "CURANDAPI", "").replace(
                "CUSPARSEAPI", "").replace(
                "CUSOLVERAPI", "").replace(
                "NVJPEGAPI", "").strip(' ')

            func_param = ""
            param_type = ""
            param_name = ""
            for param in func["parameters"]:
                if len(func_param) > 0:
                    func_param += ", "
                    param_type += ", "
                    param_name += ", "
                func_param += (param["type"] + " " + param["name"])
                param_type += param["type"]
                param_name += param["name"]
            if param_name != "":
                param_name = ', ' + param_name
            hook_func = self.hook_template
            hook_func = hook_func.replace("$ret$", ret)
            hook_func = hook_func.replace("$func_param$", func_param)
            hook_func = hook_func.replace("$param_type$", param_type)
            hook_func = hook_func.replace("$param_name$", param_name)
            hook_func = hook_func.replace("$param_name_strip$", param_name.strip(' ,'))
            hook_func = hook_func.replace("$type$", self.type)
            hook_func = hook_func.replace("$so_type$", self.type.title() + 'So()')

            hook_func = hook_func.replace('$return_type$', self.return_type)

            _m = getattr(self, self.type + '_map')  # type:dict
            new_func_name = _m.get(func_name) if _m.get(func_name) else func_name
            _h = getattr(self, self.type + '_hook')  # type:dict
            if _h.get(func_name):
                continue
            _d = getattr(self, self.type + '_discard')  # type:dict
            if _d.get(func_name):
                continue

            if new_func_name != func_name:
                continue
                # raw_hook_func = hook_func.replace("$func_name$", func_name)
                # self.originals_map[raw_hook_func] = 1
                # hook_func = hook_func.replace("$func_name$", new_func_name)
                # self.originals_map[hook_func] = 1
            else:
                hook_func = hook_func.replace("$func_name$", func_name)
                self.originals_map[hook_func] = 1

        print("{} valid func num: {}".format(self.type, len(self.originals_map)))

    def save_output(self):
        if not os.path.exists(self.output):
            os.makedirs(self.output)

        with open(self.originals_file, 'w') as fh:
            hook_include = self.hook_include.replace("$hook_num$", str(
                len(self.originals_map))).replace("$type$", self.type)
            fh.write(hook_include)
            for hook in sorted(list(self.originals_map.keys())):
                fh.write(hook)


def main():
    # sys.argv.extend(['-t', 'nvml', '-f', '../include/nvml.h', '-o', '../src', '--rt', 'nvmlReturn_t'])
    # sys.argv.extend(['-t', 'cuda', '-f', '../include/cuda.h', '-o', '../src', '--rt', 'CUresult'])
    usage = "python3 code_generate.py -t/--type cuda -f/--file include/cuda.h -o/--output output"
    parser = optparse.OptionParser(usage)
    parser.add_option(
        '-t',
        '--type',
        dest='type',
        type='string',
        help='header type',
        default='cuda')
    parser.add_option(
        '--rt',
        '--return-type',
        dest='return_type',
        type='string',
        help='return type',
        default='CUresult')
    parser.add_option(
        '-f',
        '--file',
        dest='file',
        type='string',
        help='header file',
        default='include/cuda.h')
    parser.add_option(
        '-o',
        '--output',
        dest='output',
        type='string',
        help='output path',
        default='output')

    options, args = parser.parse_args()
    type_ = options.type
    file_ = options.file
    return_type = options.return_type
    output_ = options.output

    code_gen = CodeGenerate(type_, file_, output_, return_type)
    code_gen.parse_header()
    code_gen.generate_func()
    code_gen.save_output()


if __name__ == '__main__':
    main()
