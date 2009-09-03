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
#include <hydrazine/interface/Version.h>

namespace ir
{

	LLVMKernel::LLVMKernel()
	{
		ISA = Instruction::LLVM;
	}

	LLVMKernel::LLVMKernel( const Kernel& k, const executive::Executive* c ) 
		: ExecutableKernel( k, c )
	{
		ISA = Instruction::LLVM;
	}

	void LLVMKernel::launchGrid(int width, int height)
	{
		assertM( false, "launchGrid not implemented.");	
	}	
	
	void LLVMKernel::setKernelShape(int x, int y, int z)
	{
		assertM( false, "setKernelShape not implemented.");
	}

	bool LLVMKernel::executable()
	{
		return true;
	}

	void LLVMKernel::assemble()
	{
		_code.clear();
		
		hydrazine::Version version;
		
		_code += "// Code assembled by Ocelot LLVMKernel " + version.toString() 
			+ "\n\n";
		_code += "define @__ocelotTranslated_" + name 
			+ "() noreturn nounwind\n";
		_code += "{\n";
		
		for( LLVMStatementVector::const_iterator 
			statement = llvmStatements().begin(); 
			statement != llvmStatements().end(); ++statement )
		{
			if( statement->type != LLVMStatement::Label ) _code += "\t";
			_code += statement->toString() + "\n";
		}
		
		_code += "}\n";
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

