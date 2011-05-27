

all: MemoryBound

run: MemoryBound
	./MemoryBound

MemoryBound: memoryBound.cu.cpp
	g++ memoryBound.cu.cpp `OcelotConfig --libs` -o MemoryBound -O2

memoryBound.cu.cpp: memoryBound.cu
	nvcc -arch=sm_20 memoryBound.cu -cuda

clean:
	rm -f MemoryBound memoryBound.cu.cpp

