#!/bin/bash

set -euo pipefail
SCRIPT_DIR=$( dirname "$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )")

echo $SCRIPT_DIR
WORK_PATH=$(cd $(dirname $0) && pwd) && cd $WORK_PATH

python3 code_generate.py -t cuda -f $SCRIPT_DIR/tools/cuda.txt -o ../src --rt CUresult
python3 code_generate.py -t nvml -f $SCRIPT_DIR/tools/nvml.txt -o ../src --rt nvmlReturn_t
