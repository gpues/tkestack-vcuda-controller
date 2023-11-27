/*
 * Tencent is pleased to support the open source community by making TKEStack available.
 *
 * Copyright (C) 2012-2019 Tencent. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not use
 * this file except in compliance with the License. You may obtain a copy of the
 * License at
 *
 * https://opensource.org/licenses/Apache-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OF ANY KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations under the License.
 */

//
// Created by thomas on 5/17/18.
//
#include <stdint.h>
#include <fcntl.h>
#include <string.h>
#include <sys/time.h>
#include <unistd.h>
#include "include/base.h"

int main(void) {
    int ret;

    int i, j;

    unsigned int device_num = MAX_PIDS;
    read_controller_configuration();
    nvmlInit();
    ret = nvmlDeviceGetCount(&device_num);
    if (unlikely(ret)) {
        HLOG(ERROR, "Get device number return %d", ret);
        return 1;
    }

    for (i = 0; i < device_num; i++) {
        nvmlProcessInfo_v1_t *pids_on_device = malloc(sizeof(nvmlProcessInfo_t) * MAX_PIDS);

        nvmlDevice_t dev;

        HLOG(INFO, "Get device %d return %d", i, ret);
        ret = nvmlDeviceGetHandleByIndex(i, &dev);
        if (unlikely(ret)) {
            HLOG(ERROR, "Get device %d return %d", i, ret);
            continue;
        }
        unsigned int size_on_device;
        ret = nvmlDeviceGetGraphicsRunningProcesses(dev, &size_on_device, pids_on_device);
        if (ret != NVML_SUCCESS) {
            // todo 有问题
            HLOG(INFO, "Get process gpu memory return %d %d ", ret, size_on_device);
            continue;
        }
        HLOG(INFO, "Get process %d ", size_on_device);
        for (j = 0; j < size_on_device; j++) {
            HLOG(INFO, "summary: %d used %lld", pids_on_device[j].pid, pids_on_device[j].usedGpuMemory);
        }
    }

    nvmlShutdown();
}
