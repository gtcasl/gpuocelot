/*! 
	\file LLVMDynamicKernel.cpp
	\date March 2011
	\author Andrew Kerr <arkerr@gatech.edu>, Gregory Diamos <gregory.diamos@gatech.edu>
	\brief Implements a dynamic executable kernel
*/

// Ocelot Includes
#include <ocelot/executive/interface/LLVMDynamicKernel.h>
#include <ocelot/executive/interface/LLVMDynamicExecutionManager.h>
#include <ocelot/executive/interface/Device.h>
#include <ocelot/api/interface/OcelotConfiguration.h>

// Hydrazine Includes
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/Timer.h>

// Standard Library Includes
#include <cstring>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace executive
{

static unsigned int pad(unsigned int& size, unsigned int alignment)
{
	unsigned int padding = alignment - (size % alignment);
	padding = (alignment == padding) ? 0 : padding;
	size += padding;
	return padding;
}

LLVMDynamicKernel::LLVMDynamicKernel(
	const ir::Kernel& k, 
	executive::Device* d, 
	translator::Translator::OptimizationLevel l)
: 
	ExecutableKernel(d), 
	_optimizationLevel(l),
	 _argumentMemory(0),
	_constantMemory(0)
{
	assert(!function());
	assertM(k.ISA == ir::Instruction::PTX, 
		"LLVMExecutable kernel must be constructed from a PTXKernel");
	ISA = ir::Instruction::LLVM;
	
	_gridDim.z = 1;
	
	name = k.name;
	arguments = k.arguments;
	module = k.module;
	
	mapArgumentOffsets();
}

LLVMDynamicKernel::~LLVMDynamicKernel()
{	
	delete[] _argumentMemory;
	delete[] _constantMemory;
}

void LLVMDynamicKernel::launchGrid(int x, int y)
{	
	report( "Launching kernel \"" << name << "\" on grid ( x = " 
		<< x << ", y = " << y << " )"  );
	
	_gridDim.x = x;
	_gridDim.y = y;
	
	hydrazine::Timer timer;
	
	timer.start();
	
	LLVMDynamicExecutionManager::get().launch(*this, this->sharedMemorySize());
	
	timer.stop();
	
	if (api::OcelotConfiguration::get().executive.printKernelRuntimes) {
		std::cout << "{ \"kernel\": " << name << ", \"runtime\": " << timer.seconds() << ", "
			<< "\"warpSize\": " << api::OcelotConfiguration::get().executive.warpSize << ", "
			<< "\"gridDim\": ["
			<< _gridDim.x << ", " << _gridDim.y << ", " << _gridDim.z << "], \"blockDim\": [" 
			<< _blockDim.x << ", " << _blockDim.y << ", " << _blockDim.z << "] }\n";
	}
}

void LLVMDynamicKernel::setKernelShape( int x, int y, int z )
{
	report( "Setting CTA shape to ( x = " << x << ", y = " 
		<< y << ", z = " << z << " ) for kernel \"" << name << "\""  );

	_blockDim.x = x;
	_blockDim.y = y;
	_blockDim.z = z;
}

void LLVMDynamicKernel::setExternSharedMemorySize(unsigned int bytes)
{
	_externSharedMemorySize = bytes;
}

void LLVMDynamicKernel::setWorkerThreads(unsigned int threadLimit)
{
/*	LLVMExecutionManager::setWorkerThreadCount(
		std::min(device->properties().multiprocessorCount, threadLimit));
		*/
}

void LLVMDynamicKernel::updateArgumentMemory()
{
	_allocateMemory();
	unsigned int size = 0;
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

void LLVMDynamicKernel::updateMemory()
{
	report( "Updating Memory" );

	report( " Updating Constant Memory" );
	unsigned int bytes = 0;

	for(ir::Module::GlobalMap::const_iterator 
		constant = module->globals().begin(); 
		constant != module->globals().end(); ++constant) 
	{
		if(constant->second.statement.directive == ir::PTXStatement::Const) 
		{
			report( "   Updating global constant variable " 
				<< constant->second.statement.name << " of size " 
				<< constant->second.statement.bytes() );
			pad(bytes, constant->second.statement.alignment);

			assert(device != 0);
			Device::MemoryAllocation* global = device->getGlobalAllocation(
				module->path(), constant->second.statement.name);

			assert(global != 0);
			assert(global->size() + bytes <= _constMemorySize);

			memcpy(_constantMemory + bytes, global->pointer(), global->size());

			bytes += global->size();
		}
	}
}


ExecutableKernel::TextureVector LLVMDynamicKernel::textureReferences() const
{
	return TextureVector();
}

char* LLVMDynamicKernel::argumentMemory() const
{
	return _argumentMemory;
}

char* LLVMDynamicKernel::constantMemory() const
{
	return _constantMemory;
}

LLVMDynamicKernel::OptimizationLevel LLVMDynamicKernel::optimization() const {
	return _optimizationLevel;
}

void LLVMDynamicKernel::addTraceGenerator(
	trace::TraceGenerator *generator)
{
	assertM(false, "No trace generation support in LLVM kernel.");
}

void LLVMDynamicKernel::removeTraceGenerator(
	trace::TraceGenerator *generator)
{
	assertM(false, "No trace generation support in LLVM kernel.");	
}

void LLVMDynamicKernel::_allocateMemory()
{
	_allocateArgumentMemory();
	_allocateConstantMemory();
}

void LLVMDynamicKernel::_allocateArgumentMemory()
{
	if(_argumentMemory != 0) return;
	report( "  Allocating argument memory." );

	_argumentMemorySize = 0;

	for(ParameterVector::iterator argument = arguments.begin(); 
		argument != arguments.end(); ++argument)
	{
		pad(_argumentMemorySize, argument->getAlignment());

		report("   Allocated argument " << argument->name << " from "
			<< _argumentMemorySize << " to " 
			<< (_argumentMemorySize + argument->getSize()));

		argument->offset = _argumentMemorySize;
		_argumentMemorySize += argument->getSize();
	}

	report("  Allocated " << _argumentMemorySize << " for argument memory.");

	_argumentMemory = new char[_argumentMemorySize];
}

void LLVMDynamicKernel::_allocateConstantMemory()
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
			_constMemorySize += global->second.statement.bytes();
		}
	}

	report("   Total constant memory size is " << _constMemorySize << ".");

	_constantMemory = new char[_constMemorySize];
}

}


