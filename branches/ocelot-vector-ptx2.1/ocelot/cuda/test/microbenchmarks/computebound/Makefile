#
# Makefile for akerr-computebound.c microbenchmark
#

all: ComputeGCC ComputeLLVM

ComputeGCC: akerr-computebound.c
	gcc -D TOOLCHAIN=1 akerr-computebound.c -O2 -S -o akerr-computebound-gcc.s
	gcc -D TOOLCHAIN=1 akerr-computebound.c -O2 -o ComputeGCC


ComputeLLVM: akerr-computebound.c
	clang -D TOOLCHAIN=2 akerr-computebound.c -O2 -S -o akerr-computebound-llvm.s
	clang -D TOOLCHAIN=2 akerr-computebound.c -O2 -o ComputeLLVM

run: all
	@./ComputeGCC
	@./ComputeLLVM

clean:
	rm -f ComputeGCC ComputeLLVM *.o *.s

