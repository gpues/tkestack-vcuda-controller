#!/usr/bin/env bash

set -o errexit
set -o nounset
set -o pipefail

CUDA_LIBRARY=$1
ML_LIBRARY=$2

echo "find new library: "

while read item; do
  grep -qF "$item" include/cuda.h
  if [ $? != 0 ]; then
    echo "$item"
  fi
done < <(nm -D ${CUDA_LIBRARY} | grep " T " | awk '{print $3}')

while read item; do
  grep -qF "$item" include/nvml.h
  if [ $? != 0 ]; then
    echo "$item"
  fi
done < <(nm -D ${ML_LIBRARY} | grep " T " | awk '{print $3}')
