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
			char* local;
			char* shared;
			char* constant;
			char* parameter;
			
		public:
			size_t localSize;
			size_t sharedSize;
			size_t constantSize;
			size_t parameterSize;
	};

}

#endif

