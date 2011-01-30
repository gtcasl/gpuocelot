
/*!
	Fills an array with N elements according to some divergent control flow
	with a loop.
*/
__global__ void k_sequenceLooping(float *ptr, int N) {
	int i = threadIdx.x;
	ptr[i] = cos((float)i);

}

/*!
	Computes

		R = A * V

	where A is an M x N column-major vector, V is an N element vector, and R is an M element vector.

	M and N are assumed to be multiples of block size which is 8
*/
__global__ void k_matrixVectorProduct(const float *A, const float *V, float *R, int M, int N) {
#define BLOCKSIZE 8
	
	__shared__ float V_buffer[BLOCKSIZE];

	A += blockIdx.x * blockDim.x + threadIdx.x;
	V += threadIdx.x;

	float r = 0;

	for (int i = 0; i < N; i += blockDim.x) {
		V_buffer[threadIdx.x] = *V;
		__syncthreads();

		for (int j = 0; j < blockDim.x; j++) {
			float a = *A;
			r += a * V_buffer[j];
			A += M;
		}
		V += blockDim.x;

		__syncthreads();
	}

	R[blockDim.x * blockIdx.x + threadIdx.x] = r;
}



