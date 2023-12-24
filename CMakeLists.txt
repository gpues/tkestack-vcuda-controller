cmake_minimum_required(VERSION 3.5)
project(demo C CXX)


add_definitions(-D_GNU_SOURCE)
add_compile_options(-Wall -Wshadow -Werror -Wno-format -Wno-deprecated-non-prototype -Wimplicit-function-declaration -g)

include_directories(${CMAKE_SOURCE_DIR})

#set(STATIC_C_LIBRARIES -static-libgcc -static-libstdc++)
SET(LIBRARIES -ldl -lpthread)
set(CMAKE_CXX_STANDARD 11)

add_definitions(-DUSE_ORIGINAL)
add_library(vgpu SHARED
        include/base.h
        include/func.h
        include/cuda-helper.h
        include/nvml-helper.h
        src/multiprocess/multiprocess_memory_limit.c
        src/multiprocess/multiprocess_utilization_watcher.c
        src/var.c
        src/nvml/util.c
        src/nvml/hook.c
        src/utils.c
        src/libvgpu.c
        src/allocator/allocator.c
        src/cuda/originals.c
        src/cuda/utils.c
        src/cuda/memory.c
        src/cuda/loader.c
        src/cuda/device.c
        src/cuda/export_table.c
        src/cuda/context.c
        src/cuda/hook.c
        src/nvml/originals.c
        include/nvml-subset.h
        include/cuda-subset.h
        include/vdpau.h
        include/cuda.h
        include/nvml.h
        src/nvml/nvml_entry.c
        include/all.h
        src/func_strs.c )

target_link_libraries(vgpu ${STATIC_C_LIBRARIES} ${LIBRARIES})
target_compile_options(vgpu PUBLIC $<$<COMPILE_LANGUAGE:CXX>:-std=c++11>)
