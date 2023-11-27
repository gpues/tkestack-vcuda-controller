#!/bin/bash
set -ex
set -euo pipefail

WORK_PATH=$(cd $(dirname $0) && pwd) && cd $WORK_PATH

rm -rf test
mkdir test
cd test
cmake -DCMAKE_BUILD_TYPE=Release ..
make -j$(nproc --ignore=2)
ln -s libcuda-control.so libcuda.so.1
ln -s libcuda-control.so libnvidia-ml.so.1

cd -

if command -v nvidia-smi >/dev/null 2>&1; then
    # 执行nvidia-smi命令
    LOGGER_LEVEL=9 LD_LIBRARY_PATH=./test/ nvidia-smi
fi;


