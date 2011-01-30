// file: raceCondition.cu
__global__ void raceCondition(int *A) {
	__shared__ int Shared[64];
	
	Shared[threadIdx.x] = A[threadIdx.x];
	
	// no synchronization barrier!
	
	A[threadIdx.x] = Shared[63 - threadIdx.x];	// line 9 - faulting load
}

int main() {
	
	int *validPtr = 0;
	cudaMalloc((void **)&validPtr, sizeof(int)*64);
	raceCondition<<< dim3(1,1), dim3(64, 1) >>>( validPtr );
	
	return 0;
}

