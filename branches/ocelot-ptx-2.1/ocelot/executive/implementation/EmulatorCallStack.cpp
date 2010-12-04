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
		unsigned int localSize, unsigned int sharedSize) :
		_stackPointer(0),
		_threadCount(threads),
		_localMemoryBase(3 * sizeof(unsigned int) + initialFrameSize * threads),
		_registerFileBase(_localMemoryBase + localSize * threads),
		_stackFrameSizes(1, initialFrameSize),
		_localMemorySizes(1, localSize),
		_registerFileSizes(1, registers),
		_sharedMemorySizes(1, sharedSize),
		_stack(threads * initialFrameSize 
			+ threads * registers * sizeof( RegisterType )
			+ threads * localSize + 3 * sizeof(unsigned int)),
		_sharedMemory(sharedSize)
	{

	}

	void* EmulatorCallStack::stackFramePointer(unsigned int thread)
	{
		assert(thread < _threadCount);
		assert(!_stack.empty());
		return &_stack.at(_stackPointer + 3 * sizeof(unsigned int) 
			+ thread * stackFrameSize());
	}

	void* EmulatorCallStack::previousStackFramePointer(unsigned int thread)
	{
		assert(thread < _threadCount);
		assert(_stackFrameSizes.size() > 1);
		unsigned int previousIndex = _stackFrameSizes.size() - 2;
		unsigned int totalPreviousSize = (_stackFrameSizes.at(previousIndex)
			+ _registerFileSizes.at(previousIndex) * sizeof(RegisterType)
			+ _localMemorySizes.at(previousIndex)) * _threadCount
			+ 3 * sizeof(unsigned int);
		return &_stack.at(_stackPointer + 3 * sizeof(unsigned int) 
			- totalPreviousSize + thread * previousFrameSize());
	}

	void* EmulatorCallStack::offsetToPointer(unsigned int offset)
	{
		assert(offset < _stack.size());
		return &_stack.at(offset);
	}
	
	unsigned int EmulatorCallStack::offset() const
	{
		return _stackPointer + 3 * sizeof(unsigned int);
	}
	
	EmulatorCallStack::RegisterType* EmulatorCallStack::registerFilePointer(
		unsigned int thread)
	{
		assert(thread < _threadCount);
		assert(!_registerFileSizes.empty());
		return (RegisterType*)&_stack.at(_registerFileBase 
			+ thread * registerCount() * sizeof(RegisterType));
	}

	const EmulatorCallStack::RegisterType* 
		EmulatorCallStack::registerFilePointer(unsigned int thread) const
	{
		assert(thread < _threadCount);
		assert(!_registerFileSizes.empty());
		return (RegisterType*)&_stack.at(_registerFileBase 
			+ thread * registerCount() * sizeof(RegisterType));
	}
	
	void* EmulatorCallStack::localMemoryPointer(unsigned int thread)
	{
		assert(thread < _threadCount);
		assert(!_registerFileSizes.empty());
		return (RegisterType*)&_stack.at(_localMemoryBase 
			+ thread * localMemorySize());
	}
	
	void* EmulatorCallStack::sharedMemoryPointer()
	{
		assert(!_sharedMemory.empty());
		return &_sharedMemory.at(0);
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
		return _stackFrameSizes.at(_stackFrameSizes.size() - 2);
	}

	unsigned int EmulatorCallStack::stackSize() const
	{
		return _stack.size();
	}

	unsigned int EmulatorCallStack::returnPC() const
	{
		// The first value on a stack frame is the return address
		return *(unsigned int*)&_stack.at( _stackPointer );
	}

	unsigned int EmulatorCallStack::callerOffset() const
	{
		return *(unsigned int*)&_stack.at(
			_stackPointer + sizeof(unsigned int) );
	}

	unsigned int EmulatorCallStack::callerFrameSize() const
	{
		return *(unsigned int*)&_stack.at(
		_stackPointer + 2 * sizeof(unsigned int) );
	}
	
	void EmulatorCallStack::pushFrame(unsigned int stackSize, 
		unsigned int registers, unsigned int localSize, unsigned int sharedSize,
		unsigned int returnPC, unsigned int callerStackFrame,
		unsigned int callerFrameSize)
	{
		unsigned int totalPreviousSize = (stackFrameSize()
			+ registerCount() * sizeof(RegisterType)
			+ localMemorySize()) * _threadCount + 3 * sizeof(unsigned int);

		unsigned int totalNewSize = (stackSize + localSize
			+ registers * sizeof(RegisterType)) * _threadCount
			+ 3 * sizeof(unsigned int);
		
		_stackPointer += totalPreviousSize;
		_localMemoryBase = _stackPointer + 3 * sizeof(unsigned int) 
			+ stackSize * _threadCount;
		_registerFileBase = _localMemoryBase + localSize * _threadCount;
		
		_stackFrameSizes.push_back(stackSize);
		_localMemorySizes.push_back(localSize);
		_registerFileSizes.push_back(registers);
		_sharedMemorySizes.push_back(sharedSize);
		
		_stack.resize(_stack.size() + totalNewSize);
		
		*((unsigned int*) &_stack.at(_stackPointer)) = returnPC;	
		*((unsigned int*) &_stack.at(
			_stackPointer + sizeof(unsigned int))) = callerStackFrame;	
		*((unsigned int*) &_stack.at(
			_stackPointer + 2 * sizeof(unsigned int))) = callerFrameSize;	
		
		_sharedMemory.resize(std::max(_sharedMemory.size(), (size_t)sharedSize));
	}

	void EmulatorCallStack::popFrame()
	{
		assert(!_stackFrameSizes.empty());
		unsigned int totalSize = (stackFrameSize() 
			+ registerCount() * sizeof(RegisterType) + localMemorySize()) 
			* _threadCount + 3 * sizeof(unsigned int);

		_stackFrameSizes.pop_back();
		_localMemorySizes.pop_back();
		_registerFileSizes.pop_back();
		_sharedMemorySizes.pop_back();

		unsigned int totalPreviousSize = (stackFrameSize() 
			+ registerCount() * sizeof(RegisterType) + localMemorySize()) 
			* _threadCount + 3 * sizeof(unsigned int);
		_stackPointer -= totalPreviousSize;
		
		_localMemoryBase = _stackPointer + 3 * sizeof(unsigned int) 
			+ _threadCount * stackFrameSize();
		_registerFileBase = _localMemoryBase + localMemorySize() * _threadCount;
		
		_stack.resize(_stack.size() - totalSize);
	}

}

#endif

