#include <cnp_runtime_api.h>

__device__ int array[10];

__global__ void nestedCall(int count)
{
	array[count] = count;

	if(count > 0) nestedCall<<<1, 1>>>(count - 1);
}

__global__ void mainKernel()
{
	nestedCall<<<1, 1>>>(10);
}



