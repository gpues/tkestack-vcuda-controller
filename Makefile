
build:
	docker run --rm -it -v `pwd`:/data registry.cn-hangzhou.aliyuncs.com/acejilam/nvidia-cuda:11.2.2-devel-cmake-ubuntu20.04 /data/run.sh


test:
	docker run --rm -it --runtime=nvidia --gpus all -v `pwd`:/data registry.cn-hangzhou.aliyuncs.com/acejilam/tensorflow:2.14.0-gpu bash
	# mkdir /etc/vcuda && cp ./tools/vcuda.config /etc/vcuda/
	# cd /data && LOGGER_LEVEL=9 LD_LIBRARY_PATH=/data/test nvidia-smi
	# cd /data && LOGGER_LEVEL=9 LD_LIBRARY_PATH=/data/test time python tools/cifar10_train.py