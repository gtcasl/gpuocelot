/*  \file TestDivergentRecursion.cu
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Tuesday November 9, 2010
	\brief A CUDA assembly test for short-circuiting control flow.
*/

const unsigned int threads = 512;

__device__ bool out[threads];

__device__ unsigned int divergent_function(unsigned int id)
{
/*	if(id == 1) return 0;
	
	unsigned int result = 0;
	
	if(id & 0x10)
	{
		result = divergent_function(id - 2);
	}
	else
	{
		result = divergent_function(id - 1);
	}
	
	return result;
*/

	goto FunctionEntryPoint;

	FunctionEntryPoint:
		if(id > 1)
		{
			if(id & 2)
			{
				id -= 2;		
				goto FunctionEntryPoint;			
			}
			else
			{
				id -= 1;
				goto FunctionEntryPoint;
			}
		}
		return max(1, id) - 1;
}

__global__ void divergent_recusion()
{
	out[threadIdx.x] = divergent_function(threadIdx.x);
}

int main(int argc, char** argv)
{
	divergent_recusion<<<1, threads>>>();
}


