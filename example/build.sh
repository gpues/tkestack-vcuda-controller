nvcc -I -L/usr/lib -lnvidia-ml -o t1 t1.cu -cudart shared
cuda-memcheck ./t1

#docker run --gpus all -it nvcr.io/nvidia/pytorch:20.08-py3