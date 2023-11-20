
all:
	docker run --rm -it -v `pwd`:/data registry.cn-hangzhou.aliyuncs.com/acejilam/nvidia-cuda:11.2.2-devel-cmake-ubuntu20.04 /data/build.sh