/*! \file ExecutableKernel.h
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date December 22, 2009
	\brief implements a kernel that is executable on some device
*/

#ifndef IR_EXECUTABLE_KERNEL_CPP_INCLUDED
#define IR_EXECUTABLE_KERNEL_CPP_INCLUDED

#include <ocelot/ir/interface/ExecutableKernel.h>
#include <ocelot/trace/interface/TraceGenerator.h>

namespace ir 
{
	ExecutableKernel::ExecutableKernel( const Kernel& k, 
		const executive::Executive* c ) : Kernel( k ), context( c ), 
		_constMemorySize( 0 ), _localMemorySize( 0 ), _maxThreadsPerBlock( 0 ), 
		_registerCount( 0 ), _sharedMemorySize( 0 ), 
		_externSharedMemorySize( 0 ), _parameterMemorySize( 0 )
	{
	
	}
	
	ExecutableKernel::ExecutableKernel( const executive::Executive* c ) :
		context( c ), _constMemorySize( 0 ), _localMemorySize( 0 ), _maxThreadsPerBlock( 0 ), 
		_registerCount( 0 ), _sharedMemorySize( 0 ), 	_externSharedMemorySize( 0 ), 
		_parameterMemorySize( 0 )
	{
	
	}
	
	ExecutableKernel::~ExecutableKernel() 
	{
	
	}

	bool ExecutableKernel::executable() 
	{
		return false;
	}

	void ExecutableKernel::traceEvent( const trace::TraceEvent & event) const
	{
		for( TraceGeneratorVector::const_iterator 
			generator = _generators.begin(); 
			generator != _generators.end(); ++generator ) 
		{
			(*generator)->event(event);
		}
	}

	unsigned int ExecutableKernel::constMemorySize() const
	{
		return _constMemorySize; 
	}
	
	unsigned int ExecutableKernel::localMemorySize() const
	{ 
		return _localMemorySize; 
	}
	
	unsigned int ExecutableKernel::maxThreadsPerBlock() const
	{
		return _maxThreadsPerBlock; 
	}
	
	unsigned int ExecutableKernel::registerCount() const
	{ 
		return _registerCount; 
	}
	
	unsigned int ExecutableKernel::sharedMemorySize() const 
	{ 
		return _sharedMemorySize; 
	}
	
	unsigned int ExecutableKernel::externSharedMemorySize() const 
	{ 
		return _externSharedMemorySize; 
	}
	
	unsigned int ExecutableKernel::totalSharedMemorySize() const
	{
		return externSharedMemorySize() + sharedMemorySize();
	}

	unsigned int ExecutableKernel::parameterMemorySize() const 
	{ 
		return _parameterMemorySize; 
	}
	
	const ir::Dim3& ExecutableKernel::blockDim() const
	{
		return _blockDim;
	}

	const ir::Dim3& ExecutableKernel::gridDim() const
	{
		return _gridDim;
	}

}

#endif
