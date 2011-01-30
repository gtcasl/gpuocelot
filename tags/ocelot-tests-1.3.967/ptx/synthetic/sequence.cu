/*!
	Defines a simple kernel
*/

__global__ void k_sequence(int *A, int N) {
	int n = blockDim.x * blockIdx.x + threadIdx.x;
	if (n < N) {
		A[n] = 2*n+1;
	}
}

__global__ void k_simple_sequence(int *A) {
	int n = blockDim.x * blockIdx.x + threadIdx.x;
	A[n] = 2*n+1;
}

int main()
{
	k_sequence<<< 1, 1, 0 >>>( 0, 1);
}

