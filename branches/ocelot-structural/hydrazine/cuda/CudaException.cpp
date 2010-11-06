/*!
	\file CudaException.cpp
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Friday May 8, 2009 
	\brief The sources for the CUDA Exception class.
*/

#ifndef CUDA_EXCEPTION_CPP_INCLUDED
#define CUDA_EXCEPTION_CPP_INCLUDED

#include "CudaException.h"
#include <hydrazine/implementation/string.h>
#include <hydrazine/cuda/include/cuda.h>

namespace hydrazine
{

namespace cuda
{
	CudaException::CudaException( ) : code( cudaErrorUnknown )
	{
	}

	CudaException::CudaException( cudaError_t c ) : code( c )
	{
	}
	
	CudaException::~CudaException() throw()
	{
	}

	const char* CudaException::what() const throw()
	{
		return cudaGetErrorString( code );
	}

	void check( cudaError_t code )
	{
		if( code == cudaSuccess )
		{
			return;
		}
	
		throw cuda::CudaException( code );
	}

}

}

#endif

