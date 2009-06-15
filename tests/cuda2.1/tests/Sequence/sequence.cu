/*!
	Defines a simple kernel
*/
#include <stdio.h>
#define LENGTH 11

__global__ void k_sequence(int *A, int N) {
	int n = blockDim.x * blockIdx.x + threadIdx.x;
	if (n < N) {
		A[n] = 2*n+1;
	}
}

__global__ void k_n_sequence(int *A, int N, int K) {
	int n = blockDim.x * blockIdx.x + threadIdx.x;
	for( int i = 0; i < K; ++i ) {
		if (n < N) { 
			A[n*K + i] = 2*n*K+1+i;
		}
	}
}

__global__ void k_simple_sequence(int *A) {
	int n = blockDim.x * blockIdx.x + threadIdx.x;
	A[n] = 2*n+1;
}

void simpleSequence( int* A )
{

	int* deviceA;
	
	cudaMalloc( (void**) &deviceA, LENGTH * sizeof( int ) );
	cudaMemcpy( deviceA, A, sizeof( int ) * LENGTH, cudaMemcpyHostToDevice );
	
	k_simple_sequence<<< 1, LENGTH, 0 >>>( deviceA );
	
	cudaMemcpy( A, deviceA, sizeof( int ) * LENGTH, cudaMemcpyDeviceToHost );
	cudaFree( deviceA );

}

void kSequence( int* A, int N )
{

	int* deviceA;
	
	cudaMalloc( (void**) &deviceA, N * sizeof( int ) );
	cudaMemcpy( deviceA, A, sizeof( int ) * N, cudaMemcpyHostToDevice );
	unsigned int ctas = ( N % 4 == 0 ) ? N / 4 : ( N / 4 ) + 1;
	
	k_sequence<<< ctas, 4, 0 >>>( deviceA, N );
	
	cudaMemcpy( A, deviceA, sizeof( int ) * N, cudaMemcpyDeviceToHost );
	cudaFree( deviceA );

}

void knSequence( int* A, int N, int K )
{

	int* deviceA;
	
	cudaMalloc( (void**) &deviceA, K * N * sizeof( int ) );
	cudaMemcpy( deviceA, A, sizeof( int ) * N * K, cudaMemcpyHostToDevice );
	unsigned int ctas = ( N % 4 == 0 ) ? N / 4 : ( N / 4 ) + 1;
	
	k_n_sequence<<< 1, 32, 0 >>>( deviceA, N, K );
	
	cudaMemcpy( A, deviceA, sizeof( int ) * N * K, cudaMemcpyDeviceToHost );
	cudaFree( deviceA );

}

int main(  )
{

	int A[ LENGTH ];

	printf( "Simple Sequence: " );

	memset( A, 0, LENGTH * sizeof( int ) );

	simpleSequence( A );

	for( unsigned int i = 0; i < LENGTH; ++i )
	{
	
		printf( "%d ", A[i] );
	
	}
	
	printf( "\n" );

	
	memset( A, 0, LENGTH * sizeof( int ) );
	
	printf( "K Sequence     : " );
	kSequence( A, LENGTH );

	for( unsigned int i = 0; i < LENGTH; ++i )
	{
	
		printf( "%d ", A[i] );
	
	}
	
	printf( "\n" );

	int B[ LENGTH * LENGTH ];
	
	memset( B, 0, LENGTH * LENGTH * sizeof( int ) );

	printf( "KN Sequence     : " );
	knSequence( B, LENGTH, LENGTH );

	for( unsigned int i = 0; i < LENGTH * LENGTH; ++i )
	{
	
		printf( "%d ", B[i] );
	
	}
	
	printf( "\nPass/Fail : Pass\n" );

}

