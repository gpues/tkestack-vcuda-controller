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
#include "include/json/cJSON.h"

int main(void) {
    int ret;
    int i, j;
    unsigned int device_num;
    nvmlInit();
    ret = nvmlDeviceGetCount(&device_num);
    if (unlikely(ret)) {
        HLOG(ERROR, "Get device number return %d", ret);
        return 1;
    }
    nvmlDevice_t dev;
    HLOG(INFO, "Get nvmlDeviceGetCount %d res %d", device_num, ret);
    for (i = 0; i < device_num; i++) {
        unsigned int size_on_device = 1024;
        nvmlProcessInfo_t infos[size_on_device];
        ret = nvmlDeviceGetHandleByIndex(i, &dev);
        HLOG(INFO, "nvmlDeviceGetHandleByIndex %d res %d", i, ret);
        ret = nvmlDeviceGetGraphicsRunningProcesses_v3(dev, &size_on_device, infos);
        HLOG(INFO, "nvmlDeviceGetGraphicsRunningProcesses_v3 %d res %d", size_on_device, ret);
        for (j = 0; j < size_on_device; j++) {
            HLOG(INFO, "summary: %d used %lld", infos[j].pid, infos[j].usedGpuMemory);
        }
    }
    nvmlShutdown();
    return 0;
}
