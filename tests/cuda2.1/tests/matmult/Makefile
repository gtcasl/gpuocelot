#
#
#

all: mult

matmult.o: matmult.cu
	nvcc matmult.cu -c -O2 --maxrregcount 32

mult: mult.c matmult.o
	gcc -O2 mult.c matmult.o -o mult -I $(CUDA_INSTALL_PATH)/include \
	-L$(CUDA_LIBRARY_PATH) -lcudart

run: mult
	./mult

clean:
	rm -f mult *.o *~

