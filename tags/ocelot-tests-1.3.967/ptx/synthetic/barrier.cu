
__global__ void barrier( int* in, int* out )
{
	__shared__ int shared[8];
	shared[ ( threadIdx.x + 1 ) % blockDim.x ] = in[ threadIdx.x ];
	__syncthreads();
	out[ threadIdx.x ] = shared[ threadIdx.x ];
}

