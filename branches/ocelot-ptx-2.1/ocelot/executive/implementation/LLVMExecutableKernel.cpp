/*! \file LLVMExecutableKernel.cpp
	\date Friday September 4, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The source file for the LLVMExecutableKernel class
*/

#ifndef LLVM_EXECUTABLE_KERNEL_CPP_INCLUDED
#define LLVM_EXECUTABLE_KERNEL_CPP_INCLUDED

// Ocelot Includes
#include <ocelot/executive/interface/LLVMExecutableKernel.h>
#include <ocelot/executive/interface/LLVMExecutionManager.h>
#include <ocelot/executive/interface/Device.h>

// Hydrazine Includes
#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace executive
{

LLVMExecutableKernel::LLVMExecutableKernel(const ir::Kernel& k, 
	executive::Device* d, translator::Translator::OptimizationLevel l) : 
	ExecutableKernel(k, d), _optimizationLevel(l)
{
	assertM( k.ISA == ir::Instruction::PTX, 
		"LLVMExecutable kernel must be constructed from a PTXKernel" );
	ISA = ir::Instruction::LLVM;
	
	_gridDim.z = 1;
}

LLVMExecutableKernel::~LLVMExecutableKernel()
{	

}

void LLVMExecutableKernel::launchGrid(int x, int y)
{	
	report( "Launching kernel \"" << name << "\" on grid ( x = " 
		<< x << ", y = " << y << " )"  );
	
	_gridDim.x = x;
	_gridDim.y = y;
	
	LLVMExecutionManager::launch(*this);
}

void LLVMExecutableKernel::setKernelShape( int x, int y, int z )
{
	report( "Setting CTA shape to ( x = " << x << ", y = " 
		<< y << ", z = " << z << " ) for kernel \"" << name << "\""  );

	_blockDim.x = x;
	_blockDim.y = y;
	_blockDim.z = z;
}

void LLVMExecutableKernel::setExternSharedMemorySize(unsigned int bytes)
{
	_externSharedMemorySize = bytes;
}

void LLVMExecutableKernel::setWorkerThreads(unsigned int threadLimit)
{
	LLVMExecutionManager::setWorkerThreadCount(
		std::min(device->properties().multiprocessorCount, threadLimit));
}

void LLVMExecutableKernel::updateParameterMemory()
{

}

void LLVMExecutableKernel::updateMemory()
{

}

ExecutableKernel::TextureVector LLVMExecutableKernel::textureReferences() const
{
	return TextureVector();
}

char* LLVMExecutableKernel::parameterMemory() const
{
	assertM(false, "Not Implemented");
}

char* LLVMExecutableKernel::constantMemory() const
{
	assertM(false, "Not Implemented");
}

void LLVMExecutableKernel::addTraceGenerator(
	trace::TraceGenerator *generator)
{
	assertM(false, "No trace generation support in LLVM kernel.");
}

void LLVMExecutableKernel::removeTraceGenerator(
	trace::TraceGenerator *generator)
{
	assertM(false, "No trace generation support in LLVM kernel.");	
}

std::string LLVMExecutableKernel::location( unsigned int statement ) const
{
	ir::Module::StatementVector::const_iterator s_it 
		= module->statements().begin();
	std::advance(s_it, statement);
	ir::Module::StatementVector::const_reverse_iterator s_rit 
		= ir::Module::StatementVector::const_reverse_iterator(s_it);
	unsigned int program = 0;
	unsigned int line = 0;
	unsigned int col = 0;
	for ( ; s_rit != module->statements().rend(); ++s_rit) {
		if (s_rit->directive == ir::PTXStatement::Loc) {
			line = s_rit->sourceLine;
			col = s_rit->sourceColumn;
			program = s_rit->sourceFile;
			break;
		}
	}

	std::string fileName;
	for ( s_it = module->statements().begin(); 
		s_it != module->statements().end(); ++s_it ) {
		if (s_it->directive == ir::PTXStatement::File) {
			if (s_it->sourceFile == program) {
				fileName = s_it->name;
				break;
			}
		}
	}

	std::stringstream stream;
	stream << fileName << ":" << line << ":" << col;
	return stream.str();
}

std::string LLVMExecutableKernel::instruction( 
	unsigned int statement ) const
{
	report("For module " << module->path());
	assert(statement < module->statements().size());
	ir::Module::StatementVector::const_iterator s_it 
		= module->statements().begin();
	std::advance(s_it, statement);
	assertM(s_it->instruction.valid() == "", s_it->instruction.valid());
	return s_it->instruction.toString();
}

}

#endif

