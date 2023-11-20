#docker run --rm -it -v `pwd`:/data registry.cn-hangzhou.aliyuncs.com/acejilam/nvidia-cuda:11.2.2-devel-cmake-ubuntu20.04 bash /data/build.sh

cd /data && rm -rf build && mkdir -p build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
make
