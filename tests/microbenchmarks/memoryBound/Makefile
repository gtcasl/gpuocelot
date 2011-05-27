

all: MemoryStride

run: MemoryStride
	./MemoryStride

MemoryStride: memoryStride.cu.cpp
	g++ memoryStride.cu.cpp `OcelotConfig --libs` -o MemoryStride -O2

memoryStride.cu.cpp: memoryStride.cu
	nvcc -arch=sm_20 memoryStride.cu -cuda

clean:
	rm -f MemoryStride memoryStride.cu.cpp

