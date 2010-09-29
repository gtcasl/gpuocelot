/*! \file LLVMFunctionCallStack.h
	\date Monday September 27, 2010
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The header file for the LLVMFunctionCallStack class.
*/

#ifndef LLVM_FUNCTION_CALL_STACK_H_INCLUDED
#define LLVM_FUNCTION_CALL_STACK_H_INCLUDED

// Standard Library Includes
#include <vector>

namespace executive
{

/*! \brief A class for managing a call stack for a single PTX thread */
class LLVMFunctionCallStack
{
public:
	void call(unsigned int localSize, unsigned int argumentSize);
	void returned();

	char* localMemory();
	char* argumentMemory();
	char* previousArgumentMemory();

private:
	class ArgumentAndLocalSize
	{
	public:
		ArgumentAndLocalSize(unsigned int localSize, unsigned int argumentSize);
	
	public:
		unsigned int localSize;
		unsigned int argumentSize;
	};

	typedef std::vector<char> DataVector;
	typedef std::vector<ArgumentAndLocalSize> SizeVector;
	
private:
	DataVector _stack;
	SizeVector _sizes;
};

}

#endif

