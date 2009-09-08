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

#include <configure.h>

#ifdef HAVE_LLVM
#include <llvm/Assembly/Parser.h>
#include <llvm/Module.h>
#endif

namespace executive
{
	void LLVMExecutableKernel::_buildModule()
	{
		#ifdef HAVE_LLVM
		if( _module == 0 )
		{
			llvm::ParseError error;
			_module = new llvm::Module( name );
			_module = llvm::ParseAssemblyString( _llvmCode.c_str(), 
				_module, error );
		}
		#else
		assertM( false, "Building LLVM Module requires LLVM support." );
		#endif
	}
	
	LLVMExecutableKernel::LLVMExecutableKernel( ir::LLVMKernel& k, 
		const executive::Executive* c ) : ExecutableKernel( k, c ), 
		_llvmCode( k.code() ), _module( 0 )
	{
	
	}
	
	LLVMExecutableKernel::~LLVMExecutableKernel()
	{
		delete _module;
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

