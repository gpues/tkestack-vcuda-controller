
build:
	docker run --rm -it -v `pwd`:/data registry.cn-hangzhou.aliyuncs.com/acejilam/nvidia-cuda:11.2.2-devel-cmake-ubuntu20.04 /data/run.sh

	docker run --rm -it -v `pwd`:/data -v /usr/local/vgpu/ld.so.preload:/etc/ld.so.preload -v /root/hook/test/libvgpu.so:/usr/local/vgpu/libvgpu.so registry.cn-hangzhou.aliyuncs.com/acejilam/tensorflow:2.14.0-gpu python3 /data/tools/cifar10_train.py


test:
	docker run --name=tf -it --runtime=nvidia --gpus all registry.cn-hangzhou.aliyuncs.com/acejilam/tensorflow:2.14.0-gpu bash
	# mkdir /etc/vcuda && cp ./tools/vcuda.config /etc/vcuda/
	# cd /data && LOGGER_LEVEL=9 LD_LIBRARY_PATH=/data/test nvidia-smi
	# cd /data && LOGGER_LEVEL=9 LD_LIBRARY_PATH=/data/test time python tools/cifar10_train.py



raw:
	docker run --rm -it -e LIBCUDA_LOG_LEVEL=99999 -v `pwd`:/data -v /usr/local/vgpu/ld.so.preload:/etc/ld.so.preload -v /root/hook/libvgpu.so:/usr/local/vgpu/libvgpu.so registry.cn-hangzhou.aliyuncs.com/acejilam/tensorflow:2.14.0-gpu  python3 /data/tools/cifar10_train.py
