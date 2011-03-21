/* 
	\file DynamicMulticoreCPUDevice.cpp
	\author Andrew Kerr <arkerr@gatech.edu>, Gregory Diamos <gregory.diamos@gatech.edu>
	\date March 2011
	\brief implements a dynamic execution environment for multicore CPUs
*/

// ocelot includes
#include <ocelot/executive/interface/ExecutableKernel.h>
#include <ocelot/executive/interface/DynamicMulticoreCPUDevice.h>
#include <ocelot/executive/interface/LLVMDynamicKernel.h>

/*
#include <ocelot/executive/interface/LLVMExecutableKernel.h>
#include <ocelot/executive/interface/LLVMModuleManager.h>
#include <ocelot/executive/interface/LLVMExecutionManager.h>
*/

// hydrazine includes
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/interface/Casts.h>
#include <hydrazine/interface/SystemCompatibility.h>
#include <hydrazine/implementation/debug.h>

// Standard Library Includes
#include <cstring>

// Macros
#define Throw(x) {std::stringstream s; s << x; \
	throw hydrazine::Exception(s.str());}


// Preprocessor Macros
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

/////////////////////////////////////////////////////////////////////////////////////////////////

#define REPORT_BASE 0

/////////////////////////////////////////////////////////////////////////////////////////////////

namespace executive {

DynamicMulticoreCPUDevice::Module::Module(const ir::Module* m, Device* d) 
	: EmulatorDevice::Module(m, d)
{

}

DynamicMulticoreCPUDevice::Module::~Module() {
	assert(ir->loaded());
	/*
	if(!LLVMModuleManager::isModuleLoaded(ir->path())) return;

	LLVMModuleManager::unloadModule(ir->path());
	LLVMExecutionManager::flushTranslatedKernels();
	*/
}

ExecutableKernel* DynamicMulticoreCPUDevice::Module::getKernel(
	const std::string& name) {
	report("DynamicMulticoreCPUDevice::Module::getKernel( '" << name << "' )");
	
	KernelMap::iterator kernel = kernels.find(name);
	if(kernel != kernels.end()) {
		return kernel->second;
	}
	
	ir::Module::KernelMap::const_iterator ptxKernel_it = ir->kernels().find(name);
		
	DynamicMulticoreCPUDevice* cpu = static_cast<DynamicMulticoreCPUDevice*>(device);
	assert(cpu);
	
	if(ptxKernel_it != ir->kernels().end()) {
		ir::PTXKernel *ptxKernel = static_cast<ir::PTXKernel *>(ptxKernel_it->second);
		kernel = kernels.insert(std::make_pair(name, new LLVMDynamicKernel(*ptxKernel, device))).first;
			
		return kernel->second;
	}
	
	return 0;
}

DynamicMulticoreCPUDevice::DynamicMulticoreCPUDevice(unsigned int flags) 
	: 
	EmulatorDevice(flags), 
	_workerThreads(-1),
	_optimizationLevel(translator::Translator::NoOptimization)
{
	_properties.ISA = ir::Instruction::LLVM;
	std::strcpy(_properties.name,	"Ocelot Dynamic Multicore CPU Backend (LLVM-JIT)");
	_properties.multiprocessorCount = hydrazine::getHardwareThreadCount();
	_properties.clockRate = 2000;
}

void DynamicMulticoreCPUDevice::load(const ir::Module* module) {
	if(_modules.count(module->path()) != 0) {
		Throw("Duplicate module - " << module->path());
	}
	_modules.insert(std::make_pair(module->path(), new Module(module, this)));	
}

ExecutableKernel* DynamicMulticoreCPUDevice::getKernel(
	const std::string& moduleName, const std::string& kernelName)
{
	ModuleMap::iterator module = _modules.find(moduleName);
	
	report("DynamicMulticoreCPUDevice::getKernel( mod: '" << moduleName << "', kernel: '" << kernelName << "' )");
	
	if(module == _modules.end()) return 0;
	
	return module->second->getKernel(kernelName);
}

void DynamicMulticoreCPUDevice::launch(const std::string& moduleName, 
	const std::string& kernelName, const ir::Dim3& grid, 
	const ir::Dim3& block, size_t sharedMemory, 
	const void* argumentBlock, size_t argumentBlockSize, 
	const trace::TraceGeneratorVector& traceGenerators)
{
	ModuleMap::iterator module = _modules.find(moduleName);
	report("DynamicMulticoreCPUDevice::launch( mod: '" << moduleName << "', kernel: '" << kernelName << "' )");
	
	if(module == _modules.end())
	{
		Throw("Unknown module - " << moduleName);
	}
	
	ExecutableKernel* kernel = module->second->getKernel(kernelName);
	
	if(kernel == 0)
	{
		Throw("Unknown kernel - " << kernelName 
			<< " in module " << moduleName);
	}
	
	if(kernel->sharedMemorySize() + sharedMemory > 
		(size_t)properties().sharedMemPerBlock)
	{
		Throw("Out of shared memory for kernel \""
			<< kernel->name << "\" : \n\tpreallocated "
			<< kernel->sharedMemorySize() << " + requested " 
			<< sharedMemory << " is greater than available " 
			<< properties().sharedMemPerBlock << " for device " 
			<< properties().name);
	}
	
	if(kernel->constMemorySize() > (size_t)properties().totalConstantMemory)
	{
		Throw("Out of shared memory for kernel \""
			<< kernel->name << "\" : \n\tpreallocated "
			<< kernel->constMemorySize() << " is greater than available " 
			<< properties().totalConstantMemory << " for device " 
			<< properties().name);
	}
	
	kernel->setKernelShape(block.x, block.y, block.z);
	kernel->setArgumentBlock((const unsigned char*)argumentBlock, 
		argumentBlockSize);
	kernel->updateArgumentMemory();
	kernel->updateMemory();
	kernel->setExternSharedMemorySize(sharedMemory);
	kernel->setWorkerThreads(_workerThreads);
	
	kernel->launchGrid(grid.x, grid.y);
}

void DynamicMulticoreCPUDevice::limitWorkerThreads(unsigned int threads)
{
	_workerThreads = threads;
}

void DynamicMulticoreCPUDevice::setOptimizationLevel(
	translator::Translator::OptimizationLevel level)
{
	_optimizationLevel = level;
}
}


