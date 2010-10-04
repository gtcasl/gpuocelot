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

// Standard Library Includes
#include <cstring>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace executive
{

static unsigned int pad(size_t& size, unsigned int alignment)
{
	unsigned int padding = alignment - (size % alignment);
	padding = (alignment == padding) ? 0 : padding;
	size += padding;
	return padding;
}

LLVMExecutableKernel::LLVMExecutableKernel(const ir::Kernel& k, 
	executive::Device* d, translator::Translator::OptimizationLevel l) : 
	ExecutableKernel(k, d), _optimizationLevel(l), _argumentMemory(0),
	_constantMemory(0)
{
	assert(!function());
	assertM( k.ISA == ir::Instruction::PTX, 
		"LLVMExecutable kernel must be constructed from a PTXKernel" );
	ISA = ir::Instruction::LLVM;
	
	_gridDim.z = 1;
}

LLVMExecutableKernel::~LLVMExecutableKernel()
{	
	delete[] _argumentMemory;
	delete[] _constantMemory;
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

void LLVMExecutableKernel::updateArgumentMemory()
{
	_allocateMemory();
	size_t size = 0;
	for(ParameterVector::iterator argument = arguments.begin();
		argument != arguments.end(); ++argument) 
	{
		pad(size, argument->getAlignment());
		for(ir::Parameter::ValueVector::iterator 
			value = argument->arrayValues.begin(); 
			value != argument->arrayValues.end(); ++value) 
		{
			assertM(size < argumentMemorySize(), "Size " << size 
				<< " not less than allocated parameter size " 
				<< argumentMemorySize());
			std::memcpy(_argumentMemory + size, &value->val_b16, 
				argument->getElementSize());
			size += argument->getElementSize();
		}
	}
}

void LLVMExecutableKernel::updateMemory()
{
}

ExecutableKernel::TextureVector LLVMExecutableKernel::textureReferences() const
{
	return TextureVector();
}

char* LLVMExecutableKernel::argumentMemory() const
{
	return _argumentMemory;
}

char* LLVMExecutableKernel::constantMemory() const
{
	return _constantMemory;
}

LLVMExecutableKernel::OptimizationLevel
	LLVMExecutableKernel::optimization() const
{
	return _optimizationLevel;
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

void LLVMExecutableKernel::_allocateMemory()
{
	_allocateArgumentMemory();
	_allocateConstantMemory();
}

void LLVMExecutableKernel::_allocateArgumentMemory()
{
	if(_argumentMemory != 0) return;
	report( "  Allocating parameter memory." );

	_argumentMemorySize = 0;

	AllocationMap map;

	for(ParameterVector::iterator argument = arguments.begin(); 
		argument != arguments.end(); ++argument)
	{
		pad(_argumentMemorySize, argument->getAlignment());

		report("   Allocated parameter " << argument->name << " from "
			<< _argumentMemorySize << " to " 
			<< (_argumentMemorySize + argument->getSize()));

		argument->offset = _argumentMemorySize;
		_argumentMemorySize += argument->getSize();

		map.insert(std::make_pair(argument->name, argument->offset));
	}

	report("  Allocated " << _argumentMemorySize << " for parameter memory.");

	_argumentMemory = new char[_argumentMemorySize];

	report("  Determining offsets of operands that use parameters");

	for(ir::ControlFlowGraph::iterator block = cfg()->begin(); 
		block != cfg()->end(); ++block)
	{
		for( ir::ControlFlowGraph::InstructionList::iterator 
			instruction = block->instructions.begin(); 
			instruction != block->instructions.end(); ++instruction )
		{
			ir::PTXInstruction& ptx = static_cast<
				ir::PTXInstruction&>(**instruction);

			ir::PTXOperand* operands[] = {&ptx.d, &ptx.a, &ptx.b, &ptx.c};

			if(ptx.opcode == ir::PTXInstruction::Mov
				|| ptx.opcode == ir::PTXInstruction::Ld
				|| ptx.opcode == ir::PTXInstruction::St)
			{
				for(unsigned int i = 0; i != 4; ++i)
				{
					if(operands[i]->addressMode == ir::PTXOperand::Address)
					{
						AllocationMap::iterator argument = map.find( 
							operands[i]->identifier);
						if(argument != map.end())
						{
							report("   For instruction \"" 
							<< ptx.toString() << "\" mapping \"" 
							<< argument->first << "\" to " 
							<< (argument->second + operands[i]->offset));
							operands[ i ]->offset += argument->second;
						}
					}
				}
			}
		}
	}
}

void LLVMExecutableKernel::_allocateConstantMemory()
{
	if(_constantMemory != 0) return;
	report( " Allocating Constant Memory" );
	_constMemorySize = 0;

	for(ir::Module::GlobalMap::const_iterator 
		global = module->globals().begin(); 
		global != module->globals().end(); ++global) 
	{
		if(global->second.statement.directive == ir::PTXStatement::Const) 
		{
			report( "   Found global constant variable " 
				<< global->second.statement.name << " of size " 
				<< global->second.statement.bytes() );
			pad(_constMemorySize, global->second.statement.alignment);
			_constants.insert(std::make_pair( 
				global->second.statement.name, _constMemorySize));
			_constMemorySize += global->second.statement.bytes();
		}
	}

	for(ir::ControlFlowGraph::iterator block = cfg()->begin(); 
		block != cfg()->end(); ++block)
	{
		for(ir::ControlFlowGraph::InstructionList::iterator 
			instruction = block->instructions.begin(); 
			instruction != block->instructions.end(); ++instruction)
		{
			ir::PTXInstruction& ptx = static_cast<
			ir::PTXInstruction&>(**instruction);
			ir::PTXOperand* operands[] = {&ptx.d, &ptx.a, &ptx.b, &ptx.c};

			if(ptx.opcode == ir::PTXInstruction::Mov
				|| ptx.opcode == ir::PTXInstruction::Ld
				|| ptx.opcode == ir::PTXInstruction::St)
			{
				for(unsigned int i = 0; i != 4; ++i)
				{
					if(operands[i]->addressMode == ir::PTXOperand::Address)
					{
						AllocationMap::iterator mapping = _constants.find( 
							operands[i]->identifier );
						if(_constants.end() != mapping) 
						{
							ptx.addressSpace = ir::PTXInstruction::Const;
							operands[i]->offset += mapping->second;
							report("   For instruction " 
							<< ptx.toString() 
							<< ", mapping constant label " << mapping->first 
							<< " to " << mapping->second );
						}
					}
				}
			}
		}
	}

	report("   Total constant memory size is " << _constMemorySize 
		<< ".");

	_constantMemory = new char[_constMemorySize];
}


}

#endif

