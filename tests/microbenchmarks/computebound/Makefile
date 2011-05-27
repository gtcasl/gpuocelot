#
# Makefile for akerr-computebound.c microbenchmark
#

all: ComputeCUDA

ComputeGCC: computebound.c
	gcc -D TOOLCHAIN=1 computebound.c -O2 -S -o akerr-computebound-gcc.s
	gcc -D TOOLCHAIN=1 computebound.c -O2 -o ComputeGCC


ComputeLLVM: computebound.c
	clang -D TOOLCHAIN=2 computebound.c -O2 -S -o akerr-computebound-llvm.s
	clang -D TOOLCHAIN=2 computebound.c -O2 -o ComputeLLVM

computebound.cu.cpp: computebound.cu	
	nvcc -arch=sm_20 computebound.cu -cuda -O2

ComputeCUDA: computebound.cu.cpp
	g++ computebound.cu.cpp -L/usr/local/lib `OcelotConfig --libs` -o ComputeCUDA

run: all
	./ComputeCUDA

clean:
	rm -f ComputeGCC ComputeLLVM *.o *.s

