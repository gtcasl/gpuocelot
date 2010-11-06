/*!
	\file Memory.cu
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Tuesday May 8, 2009
	\brief The source file for basic Cuda memory management functions
*/

#ifndef MEMORY_CU_INCLUDED
#define MEMORY_CU_INCLUDED

#include <hydrazine/cuda/Memory.h>

namespace hydrazine
{

namespace cuda
{
	
	__global__ void memcpy(void* destination, 
		const void* source, size_t length)
	{
		_memcpy<MemcpyBase>( destination, source, length );
	}
	
}

}

#endif

