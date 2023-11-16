# Copyright 2022. All Rights Reserved.
# Author: Bruce-Lee-LY
# Date: 23:47:56 on Sat, May 28, 2022
#
# Description: code generate for nvml-related dynamic libraries

# !/usr/bin/python3
# coding=utf-8

from __future__ import print_function
from __future__ import division
from __future__ import absolute_import
from __future__ import with_statement

import os
import optparse
from CppHeaderParser import CppHeader


def write_NVML_ENTRY_ENUM(funcs):
    with open('../include/auto-nvml-helper.h', 'r+', encoding='utf8') as f:
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
            f.write(f'    NVML_ENTRY_ENUM({func}),\n')

        f.write("""    NVML_ENTRY_END
} nvml_entry_enum_t;      """)


class CodeGenerate():
    def __init__(self, type_, file_):
        self.type = type_
        self.file = file_

        self.func_list = []

        self.hook_file = '../src/auto_nvml_entry.c'
        self.hook_list = []
        self.hook_include = """
// auto generate $hook_num$ apis

#include <pthread.h>

#include "include/hijack-info.h"
#include "include/auto-nvml-helper.h"

extern entry_t cuda_library_entry[];
extern entry_t nvml_library_entry[];
extern resource_data_t g_vcuda_config;

"""
        self.hook_template = """
$ret$ $func_name$($func_param$) {
    return NVML_ENTRY_CALL(nvml_library_entry, $func_name$,$param_name$);
}
"""

    def parsę_header(self):
        self.header = CppHeader(self.file)
        print(
            "{} total func num: {}".format(
                self.type, len(
                    self.header.functions)))

    def generate_func(self):
        for func in self.header.functions:
            func_name = func["name"]
            if func_name in self.func_list:
                continue
            else:
                self.func_list.append(func_name)
            self.func_list.sort()
            ret = func["rtnType"].replace(
                "NVMLAPI", "").replace(
                "__NVML_DEPRECATED", "").replace(
                "DECLDIR", "").replace(
                "NVMLRTAPI_CDECL", "").replace(
                "NVMLRTAPI", "").replace(
                "__host__", "").replace(
                "__nvmlrt_builtin__", "").replace(
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

            hook_func = self.hook_template
            self.hook_list.append(
                hook_func.replace(
                    "$ret$",
                    ret).replace(
                    "$func_name$",
                    func_name).replace(
                    "$func_param$",
                    func_param).replace(
                    "$param_type$",
                    param_type).replace(
                    "$param_name$",
                    param_name).replace(
                    "$type$",
                    self.type.upper()))
        print("{} valid func num: {}".format(self.type, len(self.func_list)))

    def save_output(self):

        with open(self.hook_file, 'w') as fh:
            hook_include = self.hook_include.replace("$hook_num$", str(
                len(self.hook_list))).replace("$type$", self.type)
            fh.write(hook_include)
            for hook in self.hook_list:
                fh.write(hook)
            fh.write('\n// InjectCudaLibraryEnumeratorEntry\n')


def main():
    code_gen = CodeGenerate("nvml", "./nvml.h")
    code_gen.parsę_header()
    code_gen.generate_func()
    code_gen.save_output()
    write_NVML_ENTRY_ENUM(code_gen.func_list)


if __name__ == '__main__':
    main()
