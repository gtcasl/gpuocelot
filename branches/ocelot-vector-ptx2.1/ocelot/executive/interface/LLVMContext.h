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
					unsigned int x;
					unsigned int y;
					unsigned int z;
			};
	
		public:
			Dimension tid; //! Thread ids [0]
			Dimension ntid; //! CTA dimensions [1]
			Dimension ctaid; //! CTA ids [2]
			Dimension nctaid; //! Kernel dimensions [3]
		
		public:
			char* local; //! Pointer to local memory [4]
			char* shared; //! Pointer to shared memory [5]
			char* constant; //! Pointer to constant memory [6]
			char* parameter; //! Pointer to parameter memory [7]
			char* argument; //! Pointer to argument memory [8]
		
		public:
			/*! \brief Generic pointer back to other state */
			char* metadata; // [9]
	};
	
	class ThreadDescriptor {
	public:
		enum ThreadExitType {
			Subkernel_exit = 0,
			Barrier_exit = 1,
			Kernel_exit = 2,
			Divergent_branch = 3,
			Convergent_branch = 4,
			ThreadExitType_unknown
		};
		
	public:
		char *localMemory;
		ThreadExitType type;
		int targetSubkernelID;
		LLVMContext::Dimension tid;
	};
}

#endif

