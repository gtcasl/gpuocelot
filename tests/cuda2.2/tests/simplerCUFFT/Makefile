#
# Makefile for simplerCUFFT application(s)
#

all: dftdrv dft simplerCUFFT.cu.cpp

dftdrv: kernel.ptx simplerCUFFTdriver.cpp
	g++ simplerCUFFTdriver.cpp -o dftdrv -O2 -L /usr/local/cuda2.3/cuda/lib64 -lcuda -I /usr/local/cuda2.3/cuda/include

dft: simplerCUFFT.cu
	nvcc $CUDA_SDK simplerCUFFT.cu -o dft -O2

simplerCUFFT.cu.cpp: simplerCUFFT.cu
	nvcc simplerCUFFT.cu -cuda -O2

clean:
	rm -f *~ dftdrv dft simplerCUFFT.cu.cpp

