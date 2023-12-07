cmake_minimum_required(VERSION 3.5)
project(hijack C CXX)

add_definitions(-D_GNU_SOURCE)
add_compile_options(-Wall -Wshadow -Werror -Wno-format -Wno-deprecated-non-prototype -Wimplicit-function-declaration -g)

include_directories(${CMAKE_SOURCE_DIR})

#set(STATIC_C_LIBRARIES -static-libgcc -static-libstdc++)
SET(LIBRARIES -ldl -lpthread)

add_definitions(-DUSE_ORIGINAL)
add_library(cuda-control SHARED
        include/json/cJSON.h
        include/json/cJSON.c
        include/base.h
        include/cuda.h
        include/nvml.h
        src/nvml_hook.c
        src/cuda_hook.c
        src/base.c
        src/loader.c
        src/nvml_originals.c
        src/cuda_originals.c
        )

add_executable(nvml main.c
        include/json/cJSON.h
        include/json/cJSON.c
        include/base.h
        include/cuda.h
        include/nvml.h
        src/nvml_hook.c
        src/cuda_hook.c
        src/base.c
        src/loader.c
        src/nvml_originals.c
        src/cuda_originals.c
        )

target_link_libraries(cuda-control ${STATIC_C_LIBRARIES} ${LIBRARIES})
target_compile_options(cuda-control PUBLIC $<$<COMPILE_LANGUAGE:CXX>:-std=c++11>)

target_link_libraries(nvml ${STATIC_C_LIBRARIES} ${LIBRARIES})
