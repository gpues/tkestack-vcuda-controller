#include <errno.h>
#include <pthread.h>
#include <regex.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "include/base.h"

resource_data_t g_vcuda_config = {
    .pod_uid = "",
    .limit = 0,
    .container_name = "",
    .utilization = 0,
    .gpu_memory = 0,
    .bus_id = "",
};

char *load_file(char *filename) {
    char *text = NULL;                               // 用于存储所有文本的字符串
    char line[1000];                                 // 用于存储读取的每行文本
    FILE *file = fopen(CONTROLLER_CONFIG_PATH, "r"); // 打开文件
    size_t len = 0;                                  // 用于记录当前文本的长度

    if (file == NULL) {
        HLOG(FATAL, "can't open %s, error %s", CONTROLLER_CONFIG_PATH, strerror(errno));
    }

    // 逐行读取文件内容并连接在一起
    while (fgets(line, sizeof(line), file) != NULL) {
        size_t line_len = strlen(line);
        char *new_text = realloc(text, len + line_len + 1); // 重新分配足够的空间来存储当前文本
        if (new_text == NULL) {
            free(text);   // 释放原始缓冲区的内存
            fclose(file); // 关闭文件
            HLOG(FATAL, "内存分配失败");
        }
        text = new_text;
        strcpy(text + len, line); // 将当前行文本连接到已有的文本之后
        len += line_len;          // 更新当前文本的长度
    }
    return text;
}

void read_controller_configuration() {
    char *text = load_file(CONTROLLER_CONFIG_PATH);
    g_vcuda_config = UnMarshal(text);
    HLOG(DEBUG, "pod uid          : %s", g_vcuda_config.pod_uid);
    HLOG(DEBUG, "limit            : %d", g_vcuda_config.limit);
    HLOG(DEBUG, "container name   : %s", g_vcuda_config.container_name);
    HLOG(DEBUG, "bus_id           : %s", g_vcuda_config.bus_id);
    HLOG(DEBUG, "total gpu memory : %d", g_vcuda_config.gpu_memory);
    HLOG(DEBUG, "total utilization: %d", g_vcuda_config.utilization);
    HLOG(DEBUG, "hard limit mode  : %d", g_vcuda_config.hard_limit);
    HLOG(DEBUG, "enable mode      : %d", g_vcuda_config.enable);
}
// static pthread_once_t g_cuda_config_set = PTHREAD_ONCE_INIT;
// static pthread_once_t g_cuda_set = PTHREAD_ONCE_INIT;
// static pthread_once_t g_init_set = PTHREAD_ONCE_INIT;
static pthread_once_t g_init_driver_version = PTHREAD_ONCE_INIT;
void load_necessary_data() {
    pthread_once(&g_init_driver_version, set_so_path_once);
    //    pthread_once(&g_cuda_config_set, set_so_path_once);
}

void cudaNecessary() {
    //    pthread_once(&g_cuda_set, write_cuda_config);
    //    pthread_once(&g_init_set, initialization);
}