/*!
	\file FatBinaryContext.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief object for interacting with CUDA Fat Binaries
*/

#ifndef OCELOT_CUDA_FATBINARYCONTEXT_H_INCLUDED
#define OCELOT_CUDA_FATBINARYCONTEXT_H_INCLUDED

#include <ocelot/cuda/interface/cudaFatBinary.h>

namespace cuda {
	/*!	\brief Class allowing sharing of a fat binary among threads	*/
	class FatBinaryContext {
	public:
		FatBinaryContext(const void *);
		FatBinaryContext();
	
		//! pointer to CUBIN structure
		const void *cubin_ptr;
		
	public:
		const char *name() const;
		const char *ptx() const;
	};
}

#endif

