/*!
	\file CudaException.h
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Friday May 8, 2009 
	\brief The headers for the CUDA Exception clas.
*/

#ifndef CUDA_EXCEPTION_H_INCLUDED
#define CUDA_EXCEPTION_H_INCLUDED

#include <hydrazine/cuda/include/cuda_runtime_api.h>
#include <exception>

namespace hydrazine
{

namespace cuda
{

	class CudaException : public std::exception
	{	
		public:
			cudaError_t code;
		
		public:	
			CudaException( );
			CudaException( cudaError_t code );
			~CudaException() throw();
			const char* what() const throw();
	};

	void check( cudaError_t );
}

}

#endif

