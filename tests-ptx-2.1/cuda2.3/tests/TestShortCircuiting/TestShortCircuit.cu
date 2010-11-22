/*  \file TestShortCircuit.cu
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Tuesday November 9, 2010
	\brief A CUDA assembly test for short-circuiting control flow.
*/

const unsigned int threads = 512;

__device__ bool out[threads];

__global__ void short_circuit()
{
	unsigned int id = threadIdx.x;
	
	bool b0 = (id >> 0) & 0x1;
	bool b1 = (id >> 1) & 0x1;
	bool b2 = (id >> 2) & 0x1;
	bool b3 = (id >> 3) & 0x1;
	bool b4 = (id >> 4) & 0x1;
	bool b5 = (id >> 5) & 0x1;
	bool b6 = (id >> 6) & 0x1;
	bool b7 = (id >> 7) & 0x1;
	bool b8 = (id >> 8) & 0x1;
	
	
	if(((b0 && (b1 || b2)) || (b3 || (b4 && b5))) && (b6 || (b7 && b8)))
	{
		out[id] = true;
	}
	else
	{
		out[id] = false;
	}
}

int main(int argc, char** argv)
{
	short_circuit<<<1, threads>>>();
}


