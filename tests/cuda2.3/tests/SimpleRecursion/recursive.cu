
#include <iostream>

__noinline__ __host__ __device__ int fib(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fib(n-1)+fib(n-2);
    }
}

__global__ void fibonacci( int* array )
{
	int id = threadIdx.x + blockDim.x * blockIdx.x;
	array[id] = fib( array[id] );
}

#define N 64

int main()
{
	int* host = new int[N];
	int* reference = new int[N];
	int* device;
	cudaMalloc( (void**)&device, N * sizeof( int ) );
	
	for( unsigned int i = 0; i < N; ++i )
	{
		host[i] = i;
		reference[i] = i;
	}
	
	cudaMemcpy( device, host, N * sizeof( int ), cudaMemcpyHostToDevice );

	fibonacci<<< 1, N >>>( device );

	cudaMemcpy( host, device, N * sizeof( int ), cudaMemcpyDeviceToHost );
	
	bool pass = true;
	
	for( unsigned int i = 0; i < N; ++i )
	{
		reference[i] = fib( reference[i] );
		if( reference[i] != host[i] )
		{
			std::cout << "At index " << i << " gpu version computed " 
				<< host[i] << " while cpu computed " << reference[i] << "\n";
			pass = false;
			break;
		}
	}

	if( pass )
	{
		std::cout << "TEST PASSED\n";
	}
	else
	{
		std::cout << "TEST FAILED\n";
	}

	cudaFree( device );
	delete[] reference;	
	delete[] host;
}

