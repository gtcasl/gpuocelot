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
	_sizes.push_back(ArgumentAndLocalSize(l, a));
}

void LLVMFunctionCallStack::returned()
{
	const ArgumentAndLocalSize& sizes = _sizes.back();
	_stack.resize(_stack.size() - sizes.localSize - sizes.argumentSize);
	_sizes.pop_back();
}

char* LLVMFunctionCallStack::localMemory()
{
	const ArgumentAndLocalSize& sizes = _sizes.back();
	return &_stack[_stack.size() - sizes.localSize - sizes.argumentSize];
}

char* LLVMFunctionCallStack::argumentMemory()
{
	const ArgumentAndLocalSize& sizes = _sizes.back();
	return &_stack[_stack.size() - sizes.argumentSize];	
}

char* LLVMFunctionCallStack::previousArgumentMemory()
{
	assert(_sizes.size() > 1);
	const ArgumentAndLocalSize& previousSizes = _sizes[_sizes.size() - 2];
	return localMemory() - previousSizes.argumentSize;	
}

LLVMFunctionCallStack::ArgumentAndLocalSize::ArgumentAndLocalSize(
	unsigned int l, unsigned int a) : localSize(l), argumentSize(a)
{
	
}

}

#endif

