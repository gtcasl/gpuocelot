/*!
	\file DynamicMulticoreKernel.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Nov 11, 2011
	\brief implements a dynamic multicore kernel
*/

// C++ includes
#include <cstring>

// Ocelot includes
#include <ocelot/api/interface/OcelotConfiguration.h>
#include <ocelot/ir/interface/Module.h>
#include <ocelot/executive/interface/DynamicMulticoreKernel.h>
#include <ocelot/executive/interface/DynamicMulticoreCPUDevice.h>
#include <ocelot/executive/interface/DynamicExecutionManager.h>

// Hydrazine includes
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/math.h>

//////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1

////////////////////////////////////////////////////////////////////////////////////////////////////

static unsigned int pad(unsigned int& size, unsigned int alignment)
{
	unsigned int padding = alignment - (size % alignment);
	padding = (alignment == padding) ? 0 : padding;
	size += padding;
	return padding;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

executive::DynamicMulticoreKernel::DynamicMulticoreKernel(executive::Device* d) {
	assert(0 && "invalid control path");
}

executive::DynamicMulticoreKernel::DynamicMulticoreKernel(const ir::IRKernel& _kernel,
	executive::DynamicMulticoreDevice* _d): 
_kernelGraph(0), _ptxKernel(0), _device(_d), _argumentMemory(0), _constantMemory(0) {

	report("DynamicMulticoreKernel(kernel, device)");

	assert(!function());
	assertM(_kernel.ISA == ir::Instruction::PTX, 
		"LLVMExecutable kernel must be constructed from a PTXKernel");
	ISA = ir::Instruction::DynamicLLVM;
	
	_gridDim.z = 1;
	
	_ptxKernel = static_cast<const ir::PTXKernel *>(&_kernel);
		
	name = _kernel.name;
	arguments = _kernel.arguments;
	module = _kernel.module;
	
	report(" partitioning PTX kernel");
	
	analysis::KernelPartitioningPass partitioningPass;
	_kernelGraph = partitioningPass.runOnFunction(* const_cast<ir::PTXKernel *>(_ptxKernel));
	
	mapArgumentOffsets();
}

executive::DynamicMulticoreKernel::~DynamicMulticoreKernel() {
	delete[] _argumentMemory;
	delete[] _constantMemory;
	
	if (_kernelGraph) {
		delete _kernelGraph;
	}
}


analysis::KernelPartitioningPass::KernelGraph *executive::DynamicMulticoreKernel::kernelGraph() const {
	return _kernelGraph;
}

/*!	\brief Launch a kernel on a 2D grid */
void executive::DynamicMulticoreKernel::launchGrid(int width, int height, int depth) {

	report( "Launching kernel \"" << name << "\" on grid ( x = " 
		<< width << ", y = " << height << " )"  );
	report("  shared memory size: " << this->sharedMemorySize() + this->externSharedMemorySize());
	
	_gridDim.x = width;
	_gridDim.y = height;
	
	DynamicExecutionManager::get().launch(*this, 
		this->sharedMemorySize() + this->externSharedMemorySize());
}


/*!	\brief Sets the shape of a kernel */
void executive::DynamicMulticoreKernel::setKernelShape(int x, int y, int z) {
	report( "Setting CTA shape to ( x = " << x << ", y = " 
		<< y << ", z = " << z << " ) for kernel \"" << name << "\""  );

	_blockDim.x = x;
	_blockDim.y = y;
	_blockDim.z = z;
}

/*! \brief Changes the amount of external shared memory */
void executive::DynamicMulticoreKernel::setExternSharedMemorySize(unsigned int bytes) {

	_externSharedMemorySize = bytes;
}

/*! \brief Sets the max number of pthreads this kernel can use */
void executive::DynamicMulticoreKernel::setWorkerThreads(unsigned int workerThreadLimit) {

}
	
/*! \brief Indicate that the kernels arguments have been updated */
void executive::DynamicMulticoreKernel::updateArgumentMemory() {

	_allocateMemory();
	unsigned int size = 0;
	for(ParameterVector::iterator argument = arguments.begin(); 
		argument != arguments.end(); ++argument) {
		
		pad(size, argument->getAlignment());
		
		for(ir::Parameter::ValueVector::iterator value = argument->arrayValues.begin(); 
			value != argument->arrayValues.end(); ++value) {
		
			assertM(size < argumentMemorySize(), "Size " << size 
				<< " not less than allocated parameter size " << argumentMemorySize());
			
			std::memcpy(_argumentMemory + size, &value->val_b16, argument->getElementSize());
			size += argument->getElementSize();
		}
	}
}

/*! \brief Indicate that other memory has been updated */
void executive::DynamicMulticoreKernel::updateMemory() {

	report( "Updating Memory" );
	unsigned int bytes = 0;

	for (ir::Module::GlobalMap::const_iterator constant = module->globals().begin(); 
		constant != module->globals().end(); ++constant) {
		
		if (constant->second.statement.directive == ir::PTXStatement::Const) {
		
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


void executive::DynamicMulticoreKernel::_allocateMemory() {
	_allocateArgumentMemory();
	_allocateConstantMemory();
}

void executive::DynamicMulticoreKernel::_allocateArgumentMemory() {

	if (_argumentMemory != 0) {
		return;
	}
	report( "  Allocating argument memory." );

	_argumentMemorySize = 0;

	for(ParameterVector::iterator argument = arguments.begin(); 
		argument != arguments.end(); ++argument) {
		
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

void executive::DynamicMulticoreKernel::_allocateConstantMemory() {
	if (_constantMemory != 0) {
		return;
	}
	
	report( " Allocating Constant Memory" );
	_constMemorySize = 0;

	for(ir::Module::GlobalMap::const_iterator global = module->globals().begin(); 
		global != module->globals().end(); ++global) {
		
		if (global->second.statement.directive == ir::PTXStatement::Const) {
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


/*! sets an external function table for the emulated kernel */
void executive::DynamicMulticoreKernel::setExternalFunctionSet(
	const ir::ExternalFunctionSet& s) {

}

/*! clear the external function table for the emulated kernel */
void executive::DynamicMulticoreKernel::clearExternalFunctionSet() {

}

/*! \brief Get a vector of all textures references by the kernel */
executive::ExecutableKernel::TextureVector executive::DynamicMulticoreKernel::textureReferences() const {
	return TextureVector();
}

