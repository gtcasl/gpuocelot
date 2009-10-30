/*!
	\file LLVMContext.h
	\date Tuesday September 8, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The header file for the LLVMContext class.
*/

#ifndef LLVM_CONTEXT_H_INCLUDED
#define LLVM_CONTEXT_H_INCLUDED

#include <cstring>

namespace executive
{
	/*! \brief A class contains the state for executing a kernel */
	class LLVMContext
	{
		public:
			/*! \brief A 3-D dimension corresponding to the CUDA notion */
			class Dimension
			{
				public:
					unsigned short x;
					unsigned short y;
					unsigned short z;
			};
	
		public:
			Dimension tid; //! Thread ids
			Dimension ntid; //! CTA dimensions
			Dimension ctaid; //! CTA ids
			Dimension nctaid; //! Kernel dimensions
		
		public:
			char* local; //! Pointer to local memory
			char* shared; //! Pointer to shared memory
			char* constant; //! Pointer to constant memory
			char* parameter; //! Pointer to parameter memory
			
		public:
			size_t localSize; //! Local memory per thread
			size_t sharedSize; //! Shared memory
			size_t constantSize; //! Constant memory
			size_t parameterSize; //! Parameter memory
			
		public:
			/*! \brief Generic pointer back to other state */
			char* other;
	};

}

#endif

