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

static const unsigned int globalAlignment = 16;

template<typename T>
static T align(T address, unsigned int alignment = globalAlignment)
{
	typedef long long unsigned int Address;
	Address a = (Address) address;
	
	Address remainder = a % alignment;

	Address aligned = remainder == 0 ? a : a + (alignment - remainder);
	return (T)(size_t)aligned;
}

namespace executive
{
	EmulatorCallStack::EmulatorCallStack(unsigned int threads,
		unsigned int initialArgumentSize,
		unsigned int initialFrameSize, unsigned int registers, 
		unsigned int localSize, unsigned int sharedSize) :
		_stackPointer(0),
		_threadCount(threads),
		_localMemoryBase(align(3 * sizeof(unsigned int))
			+ align(initialFrameSize) * threads),
		_registerFileBase(_localMemoryBase + align(localSize) * threads),
		_stackFrameSizes(1, align(initialArgumentSize)),
		_localMemorySizes(1, align(localSize)),
		_registerFileSizes(1, align(registers,
			globalAlignment / sizeof(RegisterType))),
		_sharedMemorySizes(1, sharedSize)
	{
		_stackFrameSizes.push_back(align(initialFrameSize));
		
		_resizeSharedMemory(sharedSize);
		
		_resizeStack(threads * align(initialFrameSize)
			+ threads * registerCount() * sizeof(RegisterType)
			+ threads * localMemorySize() + 3 * sizeof(unsigned int));
	}

	void* EmulatorCallStack::stackFramePointer(unsigned int thread)
	{
		assert(thread < _threadCount);
		assert(!_stack.empty());
		return _stackBase(_stackPointer + align(3 * sizeof(unsigned int))
			+ thread * stackFrameSize());
	}

	void* EmulatorCallStack::savedStackFramePointer(unsigned int thread)
	{
		assert(!_stack.empty());
		return _stackBase(_savedOffset + thread * _savedFrameSize);
	}

	void* EmulatorCallStack::previousStackFramePointer(unsigned int thread)
	{
		assert(thread < _threadCount);
		assert(_stackFrameSizes.size() > 1);
		unsigned int previousIndex = _stackFrameSizes.size() - 2;
		unsigned int totalPreviousSize =
			(_stackFrameSizes.at(previousIndex)
			+ _registerFileSizes.at(previousIndex - 1) * sizeof(RegisterType)
			+ _localMemorySizes.at(previousIndex - 1)) * _threadCount;
		return _stackBase(_stackPointer
			- totalPreviousSize + thread * previousFrameSize());
	}

	void* EmulatorCallStack::callerFramePointer(unsigned int thread)
	{
		assert(thread < _threadCount);
		return _stackBase(callerOffset() + thread * callerFrameSize());
	}

	void* EmulatorCallStack::offsetToPointer(unsigned int offset)
	{
		assert(offset < _stackSize());
		return _stackBase(offset);
	}
	
	unsigned int EmulatorCallStack::offset() const
	{
		return _stackPointer + align(3 * sizeof(unsigned int));
	}
	
	void EmulatorCallStack::saveFrame()
	{
		_savedOffset    = offset();
		_savedFrameSize = stackFrameSize();
	}
	
	EmulatorCallStack::RegisterType* EmulatorCallStack::registerFilePointer(
		unsigned int thread)
	{
		assert(thread < _threadCount);
		assert(!_registerFileSizes.empty());
		return (RegisterType*)_stackBase(_registerFileBase 
			+ thread * registerCount() * sizeof(RegisterType));
	}

	const EmulatorCallStack::RegisterType* 
		EmulatorCallStack::registerFilePointer(unsigned int thread) const
	{
		assert(thread < _threadCount);
		assert(!_registerFileSizes.empty());
		return (RegisterType*)_stackBase(_registerFileBase 
			+ thread * registerCount() * sizeof(RegisterType));
	}
	
	void* EmulatorCallStack::localMemoryPointer(unsigned int thread)
	{
		assert(thread < _threadCount);
		assert(!_registerFileSizes.empty());
		return (RegisterType*)_stackBase(_localMemoryBase 
			+ thread * localMemorySize());
	}
	
	void* EmulatorCallStack::sharedMemoryPointer()
	{
		return align(_sharedMemory.data());
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

	unsigned int EmulatorCallStack::returnPC() const
	{
		// The first value on a stack frame is the return address
		return *(unsigned int*)_stackBase(_stackPointer);
	}

	unsigned int EmulatorCallStack::callerOffset() const
	{
		return *(unsigned int*)_stackBase(
			_stackPointer + sizeof(unsigned int) );
	}

	unsigned int EmulatorCallStack::callerFrameSize() const
	{
		return *(unsigned int*)_stackBase(
		_stackPointer + 2 * sizeof(unsigned int) );
	}
	
	void EmulatorCallStack::pushFrame(unsigned int stackSize, 
		unsigned int registers, unsigned int localSize, unsigned int sharedSize,
		unsigned int returnPC, unsigned int callerStackFrame,
		unsigned int callerFrameSize)
	{
		stackSize = align(stackSize);
		registers = align(registers, globalAlignment / sizeof(RegisterType));
		localSize = align(localSize);
		
		unsigned int totalPreviousSize = (stackFrameSize()
			+ registerCount() * sizeof(RegisterType)
			+ localMemorySize()) * _threadCount
			+ align(3 * sizeof(unsigned int));

		unsigned int totalNewSize = (stackSize + localSize
			+ registers * sizeof(RegisterType)) * _threadCount
			+ align(3 * sizeof(unsigned int));
		
		_stackPointer += totalPreviousSize;
		_localMemoryBase = _stackPointer + align(3 * sizeof(unsigned int))
			+ stackSize * _threadCount;
		_registerFileBase = _localMemoryBase + localSize * _threadCount;
		
		_stackFrameSizes.push_back(stackSize);
		_localMemorySizes.push_back(localSize);
		_registerFileSizes.push_back(registers);
		_sharedMemorySizes.push_back(sharedSize);
		
		_resizeStack(_stackSize() + totalNewSize);
		
		*((unsigned int*) _stackBase(_stackPointer)) = returnPC;	
		*((unsigned int*) _stackBase(
			_stackPointer + sizeof(unsigned int))) = callerStackFrame;	
		*((unsigned int*) _stackBase(
			_stackPointer + 2 * sizeof(unsigned int))) = callerFrameSize;	
		
		_resizeSharedMemory(std::max(_sharedMemorySize(),
			sharedSize));
	}

	void EmulatorCallStack::popFrame()
	{
		assert(!_stackFrameSizes.empty());
		unsigned int totalSize = (stackFrameSize() 
			+ registerCount() * sizeof(RegisterType) + localMemorySize()) 
			* _threadCount + align(3 * sizeof(unsigned int));

		_stackFrameSizes.pop_back();
		_localMemorySizes.pop_back();
		_registerFileSizes.pop_back();
		_sharedMemorySizes.pop_back();

		unsigned int totalPreviousSize = (stackFrameSize() 
			+ registerCount() * sizeof(RegisterType) + localMemorySize()) 
			* _threadCount + align(3 * sizeof(unsigned int));
		_stackPointer -= totalPreviousSize;
		
		_localMemoryBase = _stackPointer + align(3 * sizeof(unsigned int)) 
			+ _threadCount * stackFrameSize();
		_registerFileBase = _localMemoryBase + localMemorySize() * _threadCount;
		
		_stack.resize(_stack.size() - totalSize);
	}

	void* EmulatorCallStack::_stackBase(unsigned int byteOffset) const
	{
		return (char*)align(_stack.data()) + byteOffset;
	}
	
	void EmulatorCallStack::_resizeStack(unsigned int size)
	{
		_stack.resize(size + globalAlignment);
	}
	
	unsigned int EmulatorCallStack::_stackSize() const
	{
		return _stack.size() - globalAlignment;
	}
	
	void EmulatorCallStack::_resizeSharedMemory(unsigned int size)
	{
		_sharedMemory.resize(size + globalAlignment);
	}
	
	unsigned int EmulatorCallStack::_sharedMemorySize() const
	{
		return _sharedMemory.size() - globalAlignment;
	}

}

#endif

