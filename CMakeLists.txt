cmake_minimum_required(VERSION 3.5)
project(hijack C CXX)

add_definitions(-D_GNU_SOURCE)
add_compile_options(-Wall -Wshadow -Werror=format-truncation=0)

include_directories(${CMAKE_SOURCE_DIR})

if (${ENABLE_DEBUG})
    add_compile_options(-g -O0)
else ()
    add_compile_options(-g -O2)
endif ()

set(STATIC_C_LIBRARIES -static-libgcc -static-libstdc++)

if (${USE_ORIGINAL})
    add_definitions(-DUSE_ORIGINAL)
    # controller related
    add_library(vgpu SHARED
            src/hijack_call.c
            include/hijack-info.h
            include/cuda-subset.h
            include/nvml-subset.h
            include/auto-cuda-helper.h
            include/auto-nvml-helper.h
            src/auto_cuda_originals.c
            src/auto_nvml_entry.c
            src/loader.c
            src/register.c
            include/json/cJSON.c
            include/json/cJSON.h)
    target_link_libraries(vgpu ${STATIC_C_LIBRARIES})
else (NOT ${USE_ORIGINAL})
    # controller related
    add_library(vgpu SHARED
            src/hijack_call.c
            include/hijack-info.h
            include/cuda-subset.h
            include/nvml-subset.h
            include/auto-cuda-helper.h
            include/auto-nvml-helper.h
            src/auto_cuda_originals.c
            src/auto_nvml_entry.c
            src/loader.c
            src/register.c
            include/json/cJSON.c
            include/json/cJSON.h)

    target_link_libraries(vgpu ${STATIC_C_LIBRARIES})

    # process monitor
    add_executable(nvml-monitor
            tools/monitor_dockernized.c
            src/loader.c
            src/register.c
            include/json/cJSON.c
            include/json/cJSON.h)
    target_link_libraries(nvml-monitor ${STATIC_C_LIBRARIES} -ldl -lpthread)
endif ()

#target_compile_options(cuda-control PUBLIC $<$<COMPILE_LANGUAGE:CXX>:-std=c++11>)

