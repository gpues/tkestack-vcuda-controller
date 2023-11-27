#!/bin/bash

set -euo pipefail

WORK_PATH=$(cd $(dirname $0) && pwd) && cd $WORK_PATH

python3 code_generate.py -t cuda -f ../include/cuda.h -o ../src --rt CUresult
python3 code_generate.py -t nvml -f ../include/nvml.h -o ../src --rt nvmlReturn_t
