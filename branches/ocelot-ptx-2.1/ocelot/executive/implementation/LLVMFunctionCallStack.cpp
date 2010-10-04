/*! \file LLVMFunctionCallStack.cpp
	\date Monday September 27, 2010
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The source file for the LLVMFunctionCallStack class.
*/

#ifndef LLVM_FUNCTION_CALL_STACK_CPP_INCLUDED
#define LLVM_FUNCTION_CALL_STACK_CPP_INCLUDED

// Ocelot Includes
#include <ocelot/executive/interface/LLVMFunctionCallStack.h>

// Standard Library Includes
#include <cassert>

namespace executive
{

void LLVMFunctionCallStack::call(unsigned int l, unsigned int a)
{
	_stack.resize(_stack.size() + l + a);
	_sizes.push_back(ParameterAndLocalSize(l, a));
}

void LLVMFunctionCallStack::returned()
{
	const ParameterAndLocalSize& sizes = _sizes.back();
	_stack.resize(_stack.size() - sizes.localSize - sizes.parameterSize);
	_sizes.pop_back();
}

char* LLVMFunctionCallStack::localMemory()
{
	const ParameterAndLocalSize& sizes = _sizes.back();
	return &_stack[_stack.size() - sizes.localSize - sizes.parameterSize];
}

char* LLVMFunctionCallStack::parameterMemory()
{
	const ParameterAndLocalSize& sizes = _sizes.back();
	return &_stack[_stack.size() - sizes.parameterSize];	
}

char* LLVMFunctionCallStack::previousParameterMemory()
{
	assert(_sizes.size() > 1);
	const ParameterAndLocalSize& previousSizes = _sizes[_sizes.size() - 2];
	return localMemory() - previousSizes.parameterSize;	
}

LLVMFunctionCallStack::ParameterAndLocalSize::ParameterAndLocalSize(
	unsigned int l, unsigned int a) : localSize(l), parameterSize(a)
{
	
}

}

#endif

