# !/usr/bin/python3
# coding=utf-8
import optparse
import os
import subprocess
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
        self.originals_map = {}
        self.nvml_header = '''#include "include/base.h"
#include "string.h"
extern void *nvml_library_entry[];'''

        self.cuda_header = '''#include "include/base.h"
#include "string.h"
extern void *cuda_library_entry[];
'''
        self.hook_template = """
$ret$ $func_name$($func_param$) {
    LINFO("Hijacking %s", "$func_name$");
    return $so_type$_ENTRY_CALL($type$_library_entry, $func_name$, $param_name_strip$);
}"""

        self.cuda_signs = []
        self.cuda_hook = []
        with open('../include/cuda-helper.h', 'r', encoding='utf8') as f:
            for line in f.readlines():
                line = line.split('//')[0].strip()
                if line.startswith('CUDA_ENTRY_ENUM('):
                    self.cuda_hook.append(line[len("CUDA_ENTRY_ENUM"):].strip('(),'))
        self.nvml_hook = []
        self.nvml_signs = []
        with open('../include/nvml-helper.h', 'r', encoding='utf8') as f:
            for line in f.readlines():
                line = line.split('//')[0].strip()
                if line.startswith('NVML_ENTRY_ENUM('):
                    self.nvml_hook.append(line[len("NVML_ENTRY_ENUM"):].strip('(),'))
        self.cuda_discard = {}

    def get_all_text(self):
        txt = ''
        for cd, dirs, files in os.walk('../src'):
            for file in files:
                p = os.path.join(cd, file)
                if file == "originals.c":
                    continue
                with open(p, 'r', encoding='utf8') as f:
                    txt += f.read()
        return txt

    def parse_header(self):
        with open(self.file, 'r') as f:
            data = f.read()
        with open('./%s_append.h' % self.type, 'r', encoding='utf8') as f:
            data += '\n' + f.read()
        self.header = CppHeader(data, argType='string')

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
            hook_func = hook_func.replace("$so_type$", self.type.upper())
            hook_func = hook_func.replace('$return_type$', self.return_type)
            hook_func = hook_func.replace("$func_name$", func_name)

            # self.originals_map[f"{self.return_type} {func_name}("] = hook_func
            self.originals_map[f" {func_name}("] = hook_func
            _m = getattr(self, f"{self.type}_signs", [])
            # nvmlReturn_t nvmlDeviceClearEccErrorCounts(nvmlDevice_t device, nvmlEccCounterType_t counterType) {
            _m.append(func['debug'].replace('CUDAAPI', '').replace('DECLDIR', '').replace('__CUDA_DEPRECATED', ''))

    def save_output(self):
        txt = self.get_all_text()

        with open(f"../src/{self.type}/originals.c", 'w', encoding='utf-8') as f:

            f.write(getattr(self, f"{self.type}_header"))
            f.write('\n')
            for item in sorted(list(set(getattr(self, f"{self.type}_signs", [])))):
                f.write(item + '\n')
            needs = []
            for func in sorted(list(set(getattr(self, f"{self.type}_hook", [])))):
                # k = f"{self.return_type} {func}("
                k = f" {func}("
                if k in txt:
                    continue
                if self.originals_map.get(k):
                    f.write(self.originals_map.get(k))
                else:
                    needs.append(func)
            print(needs)


def main():
    sys.argv.extend(['-t', 'nvml', '-f', './nvml.txt', '-o', '../src', '--rt', 'nvmlReturn_t'])
    # sys.argv.extend(['-t', 'cuda', '-f', './cuda.txt', '-o', '../src', '--rt', 'CUresult'])
    usage = "python3 code_generate.py -t/--type cuda -f/--file include/cuda.h -o/--output output"
    parser = optparse.OptionParser(usage)
    parser.add_option('-t', '--type', dest='type', type='string', help='', default='cuda')
    parser.add_option('--rt', '--return-type', dest='return_type', type='string', help='', default='CUresult')
    parser.add_option('-f', '--file', dest='file', type='string', help='', default='include/cuda.h')
    parser.add_option('-o', '--output', dest='output', type='string', help='', default='output')

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
