# Copyright 2022. All Rights Reserved.
# Author: Bruce-Lee-LY
# Date: 23:47:56 on Sat, May 28, 2022
#
# Description: code generate for cuda-related dynamic libraries

# !/usr/bin/python3
# coding=utf-8

from __future__ import print_function
from __future__ import division
from __future__ import absolute_import
from __future__ import with_statement

import os
import optparse
from CppHeaderParser import CppHeader


def write_CUDA_ENTRY_ENUM(funcs):
    with open('../include/auto-cuda-helper.h', 'r+', encoding='utf8') as f:
        byte_count = 0
        for line in f.readlines():
            if 'InjectCudaLibraryEnumeratorEntry' in line:
                byte_count += len(line)
                break
            else:
                byte_count += len(line)
        f.seek(byte_count)
        f.truncate()
        f.write('\ntypedef enum {\n')
        for func in funcs:
            f.write(f'    CUDA_ENTRY_ENUM({func}),\n')

        f.write("""    CUDA_ENTRY_END
} cuda_entry_enum_t;      """)


class CodeGenerate():
    def __init__(self, type_, file_):
        self.type = type_
        self.file = file_

        self.func_list = []
        self.hook_funcs = [
            "cuDriverGetVersion",
            "cuInit",
            "cuGetProcAddress",
            "cuMemAllocManaged",
            "cuMemAlloc_v2",
            "cuMemAlloc",
            "cuMemAllocPitch_v2",
            "cuMemAllocPitch",
            "cuArrayCreate_v2",
            "cuArrayCreate",
            "cuArray3DCreate_v2",
            "cuArray3DCreate",
            "cuMipmappedArrayCreate",
            "cuDeviceTotalMem_v2",
            "cuDeviceTotalMem",
            "cuMemGetInfo_v2",
            "cuMemGetInfo",
            "cuLaunchKernel_ptsz",
            "cuLaunchKernel",
            "cuLaunch",
            "cuLaunchCooperativeKernel_ptsz",
            "cuLaunchCooperativeKernel",
            "cuLaunchGrid",
            "cuLaunchGridAsync",
            "cuFuncSetBlockShape",
        ]

        self.hook_file = '../src/auto_cuda_originals.c'
        self.hook_list = []
        self.hook_include = """
// auto generate $hook_num$ apis

#include <assert.h>

#include "include/auto-cuda-helper.h"
#include "include/hijack-info.h"

extern entry_t cuda_library_entry[];

"""
        self.hook_template = """
$ret$ $func_name$($func_param$) {
    return CUDA_ENTRY_CALL(cuda_library_entry, $func_name$, $param_name$);
}
"""

    def parsę_header(self):
        self.header = CppHeader(self.file)
        print(
            "{} total func num: {}".format(
                self.type, len(
                    self.header.functions)))
        with open('../src/hijack_call.c', 'r', encoding='utf8') as f:
            data = f.read()
            for func in self.header.functions:
                func_name = func["name"]
                if func_name + '(' in data:
                    self.hook_funcs.append(func_name)

    def generate_func(self):
        for func in self.header.functions:
            func_name = func["name"]
            if func_name in self.func_list:
                continue
            else:
                self.func_list.append(func_name)
            self.func_list.sort()
            ret = (func["rtnType"].replace("CUDAAPI", "").replace("__CUDA_DEPRECATED", "").replace("DECLDIR", "").
                   replace("CUDARTAPI_CDECL", "").replace("CUDARTAPI", "").replace("__host__", "").
                   replace("__cudart_builtin__", "").replace("CUDNNWINAPI", "").replace("CUBLASWINAPI", "").
                   replace("CUBLASAPI", "").replace("CUFFTAPI", "").replace("NVTX_DECLSPEC", "").
                   replace("NVTX_API", "").replace("CURANDAPI", "").replace("CUSPARSEAPI", "").
                   replace("CUSOLVERAPI", "").replace("NVJPEGAPI", "").strip(' '))

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
            if func_name not in self.hook_funcs:
                self.hook_list.append(
                    self.hook_template.replace("$ret$", ret).replace("$func_name$", func_name).replace(
                        "$func_param$", func_param).replace("$param_type$", param_type).replace(
                        "$param_name$", param_name).replace("$type$", self.type.upper()))

        print("{} valid func num: {}".format(self.type, len(self.func_list)))

    def save_output(self):

        with open(self.hook_file, 'w') as fh:
            hook_include = self.hook_include.replace("$hook_num$", str(
                len(self.hook_list) - len(self.hook_funcs))).replace("$type$", self.type)
            fh.write(hook_include)
            for hook in self.hook_list:
                fh.write(hook)


def main():
    code_gen = CodeGenerate("cuda", "./cuda.h")
    code_gen.parsę_header()
    code_gen.generate_func()
    code_gen.save_output()
    code_gen.hook_funcs.extend(code_gen.func_list)
    write_CUDA_ENTRY_ENUM(list(set(code_gen.hook_funcs)))


if __name__ == '__main__':
    main()
