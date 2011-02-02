/*  \file TestDivergentRecursion.cu
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Tuesday November 9, 2010
	\brief A CUDA assembly test for short-circuiting control flow.
*/

const unsigned int threads    = 512;
const unsigned int iterations = 100;

__device__ bool out[threads];

__device__ unsigned int divergent_function(unsigned int id)
{
	unsigned int count               = id;
	unsigned int functionReturnPoint = 0;

	if(threadIdx.x & 0x1)
	{
		functionReturnPoint = 0;
		goto FunctionEntryPoint;
		FunctionReturnPoint0:
		count |= 0x1;
	}
	else if(threadIdx.x != 0)
	{
		functionReturnPoint = 1;
		goto FunctionEntryPoint;
		FunctionReturnPoint1:
		count |= 0x2;
	}
	else
	{
		count = 0;
	}

	return count;

	FunctionEntryPoint:
		for(unsigned int i = 0; i < iterations; ++i) count = (count >> 1) + i;		
		if(functionReturnPoint == 0)
			goto FunctionReturnPoint0;
		else
			goto FunctionReturnPoint1;
}

__global__ void divergent_recusion()
{
	out[threadIdx.x] = divergent_function(threadIdx.x);
}

int main(int argc, char** argv)
{
	divergent_recusion<<<1, threads>>>();
}


