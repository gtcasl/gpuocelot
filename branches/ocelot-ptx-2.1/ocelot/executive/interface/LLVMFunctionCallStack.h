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
	void call(unsigned int localSize, unsigned int parameterSize, 
		unsigned int functionId);
	void returned();

	void setKernelArgumentMemory(char* memory);

	char* localMemory();
	char* parameterMemory();
	char* argumentMemory();
	unsigned int functionId() const;

private:
	class ParameterAndLocalSize
	{
	public:
		ParameterAndLocalSize(unsigned int localSize,
			unsigned int parameterSize, unsigned int functionId);
	
	public:
		unsigned int localSize;
		unsigned int parameterSize;
		unsigned int functionId;
	};

	typedef std::vector<char> DataVector;
	typedef std::vector<ParameterAndLocalSize> SizeVector;
	
private:
	DataVector _stack;
	SizeVector _sizes;
	char*      _argumentMemory;

};

}

#endif

