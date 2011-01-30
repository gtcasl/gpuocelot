#
# Makefile for simplerCUFFT application(s)
#

all: dftdrv dft

dftdrv: kernel.ptx simplerCUFFTdriver.cpp
	g++ simplerCUFFTdriver.cpp -o dftdrv -O2 -L /usr/local/cuda2.3/cuda/lib64 -lcuda -I /usr/local/cuda2.3/cuda/include

dft: simplerCUFFT.cpp
	nvcc simplerCUFFT.cpp -o dft -O2 -lcufft

clean:
	rm -f *~ dftdrv dft simplerCUFFT.cu.cpp

