/*! \file EmulatorCallStack.cpp
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Friday July 9, 2010
	\brief The source file for the EmulatorCallStack class.
*/

#ifndef EMULATOR_CALL_STACK_CPP_INCLUDED
#define EMULATOR_CALL_STACK_CPP_INCLUDED

// Ocelot Includes
#include <ocelot/executive/interface/EmulatorCallStack.h>

// Standard Library Includes
#include <cassert>
#include <cstring>

namespace executive
{

	EmulatorCallStack::EmulatorCallStack(unsigned int threads, 
		unsigned int initialFrameSize, unsigned int registers, 
		unsigned int localSize, unsigned int sharedSize):
		_stackPointer(0),
		_threadCount(threads),
		_localMemoryBase(initialFrameSize * threads),
		_registerFileBase(_localMemoryBase + localSize * threads),
		_stackFrameSizes(1, initialFrameSize),
		_localMemorySizes(1, localSize),
		_registerFileSizes(1, registers),
		_sharedMemorySizes(1, sharedSize),
		_stack(threads * initialFrameSize 
			+ threads * registers * sizeof( RegisterType )
			+ threads * localSize),
		_sharedMemory(sharedSize)
	{

	}

	void* EmulatorCallStack::stackFramePointer(unsigned int thread)
	{
		assert(thread < _threadCount);
		assert(!_stack.empty());
		return &_stack[_stackPointer + thread * stackFrameSize()];
	}

	void* EmulatorCallStack::previousStackFramePointer(unsigned int thread)
	{
		assert(thread < _threadCount);
		assert(_stackFrameSizes.size() > 1);
		unsigned int previousIndex = _stackFrameSizes.size() - 2;
		unsigned int totalPreviousSize = (_stackFrameSizes[previousIndex]
			+ _registerFileSizes[previousIndex] * sizeof(RegisterType)
			+ _localMemorySizes[previousIndex]) * _threadCount;
		return &_stack[_stackPointer - totalPreviousSize 
			+ thread * previousFrameSize()];	
	}
	
	EmulatorCallStack::RegisterType* EmulatorCallStack::registerFilePointer(
		unsigned int thread)
	{
		assert(thread < _threadCount);
		assert(!_registerFileSizes.empty());
		return (RegisterType*)&_stack[_registerFileBase 
			+ thread * registerCount() * sizeof(RegisterType)];
	}
	
	void* EmulatorCallStack::localMemoryPointer(unsigned int thread)
	{
		assert(thread < _threadCount);
		assert(!_registerFileSizes.empty());
		return (RegisterType*)&_stack[_localMemoryBase 
			+ thread * localMemorySize()];
	}
	
	void* EmulatorCallStack::sharedMemoryPointer()
	{
		assert(!_sharedMemory.empty());
		return &_sharedMemory[0];
	}

	unsigned int EmulatorCallStack::registerCount() const
	{
		assert(!_registerFileSizes.empty());
		return _registerFileSizes.back();
	}
	
	unsigned int EmulatorCallStack::localMemorySize() const
	{
		assert(!_localMemorySizes.empty());
		return _localMemorySizes.back();
	}
	
	unsigned int EmulatorCallStack::sharedMemorySize() const
	{
		assert(!_sharedMemorySizes.empty());
		return _sharedMemorySizes.back();
	}
	
	unsigned int EmulatorCallStack::stackFrameSize() const
	{
		assert(!_stackFrameSizes.empty());
		return _stackFrameSizes.back();
	}

	unsigned int EmulatorCallStack::previousFrameSize() const
	{
		assert(_stackFrameSizes.size() > 1);
		return _stackFrameSizes[_stackFrameSizes.size() - 2];
	}

	unsigned int EmulatorCallStack::stackSize() const
	{
		return _stack.size();
	}

	void EmulatorCallStack::pushFrame(unsigned int stackSize, 
		unsigned int registers, unsigned int localSize, unsigned int sharedSize)
	{
		unsigned int totalPreviousSize = (stackFrameSize()
			+ registerCount() * sizeof(RegisterType)
			+ localMemorySize()) * _threadCount;

		unsigned int totalNewSize = (stackSize + localSize 
			+ registers * sizeof(RegisterType)) * _threadCount;
		
		_stackPointer += totalPreviousSize;
		_localMemoryBase = _stackPointer + stackSize * _threadCount;
		_registerFileBase = _localMemoryBase + localSize * _threadCount;
		
		_stackFrameSizes.push_back(stackSize);
		_localMemorySizes.push_back(localSize);
		_registerFileSizes.push_back(registers);
		_sharedMemorySizes.push_back(sharedSize);
		
		_stack.resize(_stack.size() + totalNewSize);
		
		_sharedMemory.resize(std::max(_sharedMemory.size(), sharedSize));
	}

	void EmulatorCallStack::popFrame()
	{
		assert(!_stackFrameSizes.empty());
		unsigned int totalSize = (stackFrameSize() 
			+ registerCount() * sizeof(RegisterType) + localMemorySize()) 
			* _threadCount;

		_stackFrameSizes.pop_back();
		_localMemorySizes.pop_back();
		_registerFileSizes.pop_back();
		_sharedMemorySizes.pop_back();

		unsigned int totalPreviousSize = (stackFrameSize() 
			+ registerCount() * sizeof(RegisterType) + localMemorySize()) 
			* _threadCount;
		_stackPointer -= totalPreviousSize;
		
		_localMemoryBase = _stackPointer + _threadCount * stackFrameSize();
		_registerFileBase = _localMemoryBase + localMemorySize() * _threadCount;
		
		_stack.resize(_stack.size() - totalSize);
	}

}

#endif

