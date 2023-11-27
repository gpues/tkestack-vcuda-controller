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

    int fd;
    int item;
    int rsize;

    int i, j, k;

    int pids_table[MAX_PIDS];
    int pids_table_size;

    unsigned int device_num;
    nvmlDevice_t dev;
    nvmlProcessInfo_v1_t pids_on_device[MAX_PIDS];
    unsigned int size_on_device = MAX_PIDS;

    struct timeval cur;
    size_t microsec;
    nvmlProcessUtilizationSample_t processes_sample[MAX_PIDS];
    unsigned int processes_num = MAX_PIDS;

    unsigned int sm_util;
    uint64_t memory;
    nvmlProcessInfo_v1_t *process_match = NULL;
    nvmlProcessUtilizationSample_t *sample_match = NULL;

    fd = open(PIDS_CONFIG_PATH, O_RDONLY);
    if (unlikely(fd == -1)) {
        HLOG(FATAL, "can't open %s", PIDS_CONFIG_PATH);
    }

    for (item = 0; item < MAX_PIDS; item++) {
        rsize = (int)read(fd, pids_table + item, sizeof(int));
        if (unlikely(rsize != sizeof(int))) {
            break;
        }
    }

    for (i = 0; i < item; i++) {
        HLOG(INFO, "pid: %d", pids_table[i]);
    }

    pids_table_size = item;

    HLOG(INFO, "read %d items from %s", pids_table_size, PIDS_CONFIG_PATH);
    read_controller_configuration();
    nvmlInit();

    ret = nvmlDeviceGetCount(&device_num);
    if (unlikely(ret)) {
        HLOG(ERROR, "Get device number return %d", ret);
        return 1;
    }

    for (i = 0; i < device_num; i++) {
        ret = nvmlDeviceGetHandleByIndex(i, &dev);
        if (unlikely(ret)) {
            HLOG(ERROR, "Get device %d return %d", i, ret);
            continue;
        }

        size_on_device = MAX_PIDS;
        ret = nvmlDeviceGetComputeRunningProcesses(dev, &size_on_device, pids_on_device);
        if (ret != NVML_SUCCESS) {
            HLOG(INFO, "Get process gpu memory return %d", ret);
            continue;
        }

        for (j = 0; j < size_on_device; j++) {
            HLOG(INFO, "summary: %d used %lld", pids_on_device[j].pid, pids_on_device[j].usedGpuMemory);
        }

        processes_num = MAX_PIDS;
        gettimeofday(&cur, NULL);
        microsec = (cur.tv_sec - 1) * 1000UL * 1000UL + cur.tv_usec;
        ret = nvmlDeviceGetProcessUtilization(dev, processes_sample, &processes_num, microsec);
        if (ret != NVML_SUCCESS) {
            HLOG(ERROR, "Get process utilization return %d", ret);
            continue;
        }

        for (j = 0; j < processes_num; j++) {
            HLOG(INFO, "summary: %d util %d", processes_sample[j].pid, processes_sample[j].smUtil);
        }

        fprintf(stderr, "Device\tProcess\tUtilization\tMemory\n");
        for (j = 0; j < pids_table_size; j++) {
            process_match = NULL;
            sample_match = NULL;

            for (k = 0; k < size_on_device; k++) {
                if (pids_on_device[k].pid == pids_table[j]) {
                    process_match = &pids_on_device[k];
                }
            }

            for (k = 0; k < processes_num; k++) {
                if (processes_sample[k].pid == pids_table[j]) {
                    sample_match = &processes_sample[k];
                }
            }

            if (process_match) {
                memory = process_match->usedGpuMemory;
                memory >>= 20;
                if (sample_match) {
                    sm_util = sample_match->smUtil;
                }
                else {
                    sm_util = 0;
                }
                fprintf(stderr, "%-6d\txxx\t%-11d\t%-6 %llu MB\n", i, sm_util, memory);
            }
        }
    }

    nvmlShutdown();
    close(fd);
}
