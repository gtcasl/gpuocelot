/*  \file TestExceptions.cu
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Tuesday November 9, 2010
	\brief A CUDA assembly test for unstructured control 
		flow mimicking exceptions.
*/

#include <cstdlib>

const unsigned int threads = 512;
const unsigned int iterations = 100;

__device__ unsigned int output[threads];
__device__ unsigned int input[threads];

extern "C" __global__ void exception_in_divergent_call(unsigned int id)
{
	goto Try_Label;
	
	Try_Label:
		unsigned int result = 0;
		if(threadIdx.x == id)
		{
			goto Function_1_Begin;
		}
		else
		{
			goto Function_2_Begin;
		}

	Function_1_Begin:
		if(input[threadIdx.x] != id) goto Catch_Label;
		
		result = input[threadIdx.x];
		goto Function_Return;

	Function_2_Begin:
		if(input[threadIdx.x] == id) goto Catch_Label;
		
		result = threadIdx.x;
		goto Function_Return;

	Function_Return:
		for(unsigned int i = 0; i < iterations; ++i)
		{
			result = (result >> 1) ^ threadIdx.x;
		}
		
		output[threadIdx.x] = result;
		return;

	Catch_Label:
		output[threadIdx.x] = (unsigned int)-1; // error occurred
		return;

}

extern "C" __global__ void exception_in_loop(int iterations)
{
	goto Try_Label;
	
	Try_Label:
		unsigned int result = 0;
		goto Function_Begin;

	Function_Begin:
		for(unsigned int i = 0; i < threadIdx.x; ++i)
		{
			if(input[i] > blockDim.x) goto Catch_Label;
			result += input[i];
		}
		
		for(unsigned int i = 0; i < iterations; ++i)
		{
			result = (result >> 1) ^ threadIdx.x;
		}
		
		goto Function_Return;



	Function_Return:	
		output[threadIdx.x] = result;
		return;

	Catch_Label:
		output[threadIdx.x] = (unsigned int)-1; // error occurred
		return;
}

extern "C" __global__ void exception_in_conditional()
{
	goto Try_Label;
	
	Try_Label:
		unsigned int result = 0;
		goto Function_Begin;

	Function_Begin:
		if(input[threadIdx.x] > 0)
		{
			if(input[threadIdx.x] > blockDim.x) goto Catch_Label;
			result = input[threadIdx.x];
		}
		
		for(unsigned int i = 0; i < iterations; ++i)
		{
			result = (result >> 1) + threadIdx.x;
		}
		
		goto Function_Return;

	Function_Return:	
		output[threadIdx.x] = result;
		return;

	Catch_Label:
		output[threadIdx.x] = (unsigned int)-1; // error occurred
		return;
}

int main(int argc, char** argv)
{
	unsigned int* in;

	srand(0);

	cudaGetSymbolAddress((void**)&in, "input");

	unsigned int refIn[threads];

	for(unsigned int i = 0; i < threads; i++)
	{
		refIn[i] = i;
	}
	
	cudaMemcpy(in, refIn, threads * sizeof(unsigned int),
		cudaMemcpyHostToDevice);
	
	exception_in_divergent_call<<<1, threads>>>(0);
	
	for(unsigned int i = 0; i < threads; i++)
	{
		refIn[i] = std::rand() % threads;
	}
	
	cudaMemcpy(in, refIn, threads * sizeof(unsigned int),
		cudaMemcpyHostToDevice);
	
	exception_in_loop<<<1, threads>>>(iterations);
	
	for(unsigned int i = 0; i < threads; i++)
	{
		refIn[i] = std::rand() & 1;
	}
	
	cudaMemcpy(in, refIn, threads * sizeof(unsigned int),
		cudaMemcpyHostToDevice);
	
	exception_in_conditional<<<1, threads>>>();
}


