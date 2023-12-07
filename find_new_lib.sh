#!/usr/bin/env bash

set -o nounset
set -o pipefail

CUDA_LIBRARY=$1
ML_LIBRARY=$2

echo "find new library: "

while read item; do
  \grep -qF "$item" src/*
  if [ $? != 0 ]; then
    echo "cu------> $item"
  fi
done < <(nm -D ${CUDA_LIBRARY} | grep " T "| grep "cu[A-Z]" | awk '{print $3}')

while read item; do
  \grep -qF "$item" src/*
  if [ $? != 0 ]; then
    echo "nvml----> $item"
  fi
done < <(nm -D ${ML_LIBRARY} | grep " T " | grep "nvml[A-Z]"| awk '{print $3}')
