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
#include <hydrazine/implementation/Exception.h>
#include <ocelot/translator/interface/PTXToLLVMTranslator.h>

#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1

#include <configure.h>

#ifdef HAVE_LLVM
#include <llvm/Assembly/Parser.h>
#include <llvm/Module.h>
#include <llvm/Analysis/Verifier.h>
#endif

namespace executive
{
	void LLVMExecutableKernel::_pad( unsigned int& padding, 
		unsigned int& size, unsigned int alignment )
	{
		padding = alignment - ( size % alignment );
		padding = ( alignment == padding ) ? 0 : padding;
		size += padding;
	}

	void LLVMExecutableKernel::_buildModule()
	{
		#ifdef HAVE_LLVM
		if( _module == 0 )
		{
			report( "Building LLVM module for kernel \"" << name << "\"" );
			
			_allocateMemory();

			translator::PTXToLLVMTranslator translator;
			
			report( " Translating to llvm." );
			ir::LLVMKernel* llvmKernel = static_cast< 
					ir::LLVMKernel* >( translator.translate( this ) );

			report( " Assembling llvm module." );
			llvmKernel->assemble();

			report( " Parsing llvm assembly." );
			llvm::ParseError error;
			_module = new llvm::Module( name );
			_module = llvm::ParseAssemblyString( llvmKernel->code().c_str(), 
				_module, error );
			
			int line = -1;
			int column = -1;
			error.getErrorLocation( line, column );
			if( line != -1 )
			{
				report( "  Translated Kernel:\n" 
					<< llvmKernel->numberedCode() );
				std::stringstream message;
				message << "LLVM Parser failed for kernel: \"" 
					<< name << "\" : (" << line << ", " << column << ") : \"" 
					<< error.getRawMessage() + "\"";
				throw hydrazine::Exception( message.str() );
			}
			
			delete llvmKernel;
			
			report( " Checking module for errors." );
			std::string verifyError;
			if( llvm::verifyModule( *_module, 
				llvm::ReturnStatusAction, &verifyError ) )
			{
				throw hydrazine::Exception( "LLVM Verifier failed for kernel: " 
					+ name + " : \"" + verifyError + "\"" );
			}
			
		}
		#else
		assertM( false, "Building LLVM Module requires LLVM support." );
		#endif
	}
	
	void LLVMExecutableKernel::_allocateMemory()
	{
		report( " Allocating Memory" );
		for( PTXInstructionVector::iterator 
			instruction = instructions.begin(); 
			instruction != instructions.end(); ++instruction )
		{
			
		}
	}
	
	LLVMExecutableKernel::LLVMExecutableKernel( ir::Kernel& k, 
		const executive::Executive* c ) : ExecutableKernel( k, c ), 
		_module( 0 )
	{
	}
	
	LLVMExecutableKernel::~LLVMExecutableKernel()
	{
		delete _module;
	}

	void LLVMExecutableKernel::launchGrid( int x, int y )
	{	
		_buildModule();
		report( "Launching kernel \"" << name << "\" on grid ( x = " 
			<< x << ", y = " << y << " )"  );
		assertM( false, "Launching grid not implemented." );
	}
	
	void LLVMExecutableKernel::setKernelShape( int x, int y, int z )
	{
		report( "Setting CTA \"" << name << "\" shape ( x = " << x << ", y = " 
			<< y << ", z = " << z << " )"  );
		_ctaDimensions.x = x;
		_ctaDimensions.y = y;
		_ctaDimensions.z = z;
	}

	void LLVMExecutableKernel::updateParameterMemory()
	{
		_buildModule();
		assertM( false, "Updating parameter memory not implemented." );
	}
}

#endif

