/*!
	\file LLVMExecutableKernel.cpp
	\date Friday September 4, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The source file for the LLVMExecutableKernel class
*/

#ifndef LLVM_EXECUTABLE_KERNEL_CPP_INCLUDED
#define LLVM_EXECUTABLE_KERNEL_CPP_INCLUDED

#include <ocelot/executive/interface/LLVMExecutableKernel.h>
#include <hydrazine/implementation/debug.h>

namespace executive
{
	LLVMExecutableKernel::LLVMExecutableKernel( ir::LLVMKernel& k, 
		const executive::Executive* c ) : ExecutableKernel( k, c )
	{
	
	}
	
	LLVMExecutableKernel::~LLVMExecutableKernel()
	{
	
	}

	void LLVMExecutableKernel::launchGrid( int width, int height )
	{	
		assertM( false, "Launching grid not implemented." );
	}
	
	void LLVMExecutableKernel::setKernelShape( int x, int y, int z )
	{
		_ctaDimensions.x = x;
		_ctaDimensions.y = y;
		_ctaDimensions.z = z;
	}

	void LLVMExecutableKernel::updateParameterMemory()
	{
		assertM( false, "Updating parameter memory not implemented." );
	}
}

#endif

