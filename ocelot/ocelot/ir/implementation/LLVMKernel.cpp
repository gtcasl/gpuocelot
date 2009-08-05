/*!
	\file LLVMKernel.cpp
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Saturday August 1, 2009
	\brief The source file for the LLVMKernel class.
*/

#ifndef LLVM_KERNEL_CPP_INCLUDED
#define LLVM_KERNEL_CPP_INCLUDED

#include <ocelot/ir/interface/LLVMKernel.h>
#include <hydrazine/implementation/debug.h>

namespace ir
{

	LLVMKernel::LLVMKernel()
	{
		ISA = Instruction::LLVM;
	}

	LLVMKernel::LLVMKernel( const Kernel& k ) : Kernel( k )
	{
		ISA = Instruction::LLVM;
	}
		
	void LLVMKernel::assemble()
	{
		assertM( false, "Assemble not implemented." );
	}
	
	bool LLVMKernel::assembled() const
	{
		return !_code.empty();
	}
	
	const std::string& LLVMKernel::code() const
	{
		return _code;
	}
	
	const LLVMKernel::LLVMStatementVector& LLVMKernel::llvmStatements() const
	{
		return _statements;
	}

}

#endif

