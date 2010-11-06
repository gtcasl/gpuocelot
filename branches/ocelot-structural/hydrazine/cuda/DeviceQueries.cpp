/*!
	\file DeviceQueries.cpp
	\date Thursday June 18, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The source file for the set of cuda device query functions.
*/

#ifndef DEVICE_QUERIES_CPP_INCLUDED
#define DEVICE_QUERIES_CPP_INCLUDED

#include <hydrazine/cuda/CudaException.h>
#include <hydrazine/cuda/include/cuda_runtime_api.h>

namespace hydrazine
{

namespace cuda
{
	unsigned int warpSize()
	{
		int device;
		cudaDeviceProp properties;
		check( cudaGetDevice( &device ) );
		check( cudaGetDeviceProperties( &properties, device ) );
		return properties.warpSize;
	}
}

}

#endif

