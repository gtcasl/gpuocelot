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

void LLVMFunctionCallStack::call(unsigned int l, unsigned int a, unsigned int i)
{
	_stack.resize(_stack.size() + l + a);
	_sizes.push_back(ParameterAndLocalSize(l, a, i));
}

void LLVMFunctionCallStack::returned()
{
	const ParameterAndLocalSize& sizes = _sizes.back();
	_stack.resize(_stack.size() - sizes.localSize - sizes.parameterSize);
	_sizes.pop_back();
}

void LLVMFunctionCallStack::setKernelArgumentMemory(char* memory)
{
	assert(_stack.size() == 0);
	_argumentMemory = memory;
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

char* LLVMFunctionCallStack::argumentMemory()
{
	if(_sizes.size() < 2) return _argumentMemory;
	
	const ParameterAndLocalSize& sizes = _sizes.back();
	unsigned int previousParameterSize = _sizes[_sizes.size()-2].parameterSize;
	return &_stack[_stack.size() - sizes.localSize - sizes.parameterSize
		- previousParameterSize];
}

unsigned int LLVMFunctionCallStack::functionId() const
{
	const ParameterAndLocalSize& sizes = _sizes.back();
	return sizes.functionId;
}

LLVMFunctionCallStack::ParameterAndLocalSize::ParameterAndLocalSize(
	unsigned int l, unsigned int a, unsigned int id) : localSize(l), 
	parameterSize(a), functionId(id)
{
	
}

}

#endif

