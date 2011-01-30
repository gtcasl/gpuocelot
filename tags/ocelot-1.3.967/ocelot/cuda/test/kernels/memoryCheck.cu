// file: memoryCheck.cu
__global__ void badMemoryReference(int *A) {
	A[threadIdx.x] = 0;					// line 3 - faulting store
}

int main() {
/*
	int *invalidPtr = 0x0234;		// pointer arbitrarily chosen,
															//   not allocated via cudaMalloc()
*/										
	int *invalidPtr = reinterpret_cast<int *>(0x0234);
	
	int *validPtr = 0;
	cudaMalloc((void **)&validPtr, sizeof(int)*64);
	
	badMemoryReference<<< dim3(1,1), dim3(64, 1) >>>( invalidPtr );
	
	return 0;
}

