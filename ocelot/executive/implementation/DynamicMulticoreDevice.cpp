/*!
	\file DynamicMulticoreDevice.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date November 11, 2011
	\brief demonstrates integrated concepts of subkernel formation and vectorization
*/

// C++ includes
#include <cstring>

// Ocelot includes
#include <ocelot/api/interface/OcelotConfiguration.h>
#include <ocelot/executive/interface/DynamicMulticoreDevice.h>
#include <ocelot/executive/interface/DynamicMulticoreKernel.h>

// Hydrazine includes
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/math.h>

//////////////////////////////////////////////////////////////////////////////////////////////////

#define Ocelot_Exception(x) { std::stringstream ss; ss << x; std::cerr << x << std::endl; \
	throw hydrazine::Exception(ss.str()); }
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1

////////////////////////////////////////////////////////////////////////////////////////////////////

executive::DynamicMulticoreDevice::Configuration::Configuration() {
	maximumWarpSize = api::OcelotConfiguration::get().executive.warpSize;
	schedulingPolicy = TS_StaticRoundRobin;
}

executive::DynamicMulticoreDevice::Module::Module(const ir::Module *_module): ptxModule(_module) {

}
executive::DynamicMulticoreDevice::Module::Module(): ptxModule(0) {

}

////////////////////////////////////////////////////////////////////////////////////////////////////

executive::DynamicMulticoreDevice::DynamicMulticoreDevice(int _flags): EmulatorDevice(_flags) {
	
	_properties.ISA = ir::Instruction::DynamicLLVM;
	_properties.addressSpace = 0;
	std::strcpy(_properties.name, "Ocelot Dynamic Multicore CPU");
	
	report("DynamicMulticoreDevice()");
}

executive::DynamicMulticoreDevice::~DynamicMulticoreDevice() {

}

////////////////////////////////////////////////////////////////////////////////////////////////////

/*! \brief Load a module, must have a unique name */
void executive::DynamicMulticoreDevice::load(const ir::Module* module) {
	report("DynamicMulticoreDevice::load(" << module->path() << ")");
	modules[module->path()] = Module(module);
	_modules.insert(std::make_pair(module->path(), 
		new EmulatorDevice::Module(module, this)));
}


/*! \brief Unload a module by name */
void executive::DynamicMulticoreDevice::unload(const std::string& name) {
	report("DynamicMulticoreDevice::unload(" << name << ")");
	ModuleMap::iterator mod_it = modules.find(name);
	if (mod_it != modules.end()) {
		modules.erase(mod_it);
	}
}


/*! \brief Get a translated kernel from the device */
executive::ExecutableKernel* executive::DynamicMulticoreDevice::getKernel(const std::string& module, 
	const std::string& kernel) {
	report("DynamicMulticoreDevice::getKernel(" << module << ", " << kernel << ")");
	
	ModuleMap::iterator mod_it = modules.find(module);
	if (mod_it == modules.end()) {
		Ocelot_Exception("Failed to locate module");
	}
	
	DynamicMulticoreKernel *multicoreKernel = 0;
	DynamicMulticoreKernelMap::iterator kernel_it = mod_it->second.kernels.find(kernel);
	if (kernel_it == mod_it->second.kernels.end()) {
		const ir::Module::KernelMap &kernelMap = mod_it->second.ptxModule->kernels();
		ir::Module::KernelMap::const_iterator ptx_kernel_it = kernelMap.find(kernel);
		
		if (ptx_kernel_it  != kernelMap.end()) {
			const ir::PTXKernel *ptxKernel = ptx_kernel_it->second;
			multicoreKernel = new DynamicMulticoreKernel(*ptxKernel, this, getFreeSubkernelId());
			mod_it->second.kernels[kernel] = multicoreKernel;
		}
	}
	else {
		multicoreKernel = kernel_it->second;
	}
	
	return multicoreKernel;
}


/*! \brief helper function for launching a kernel
	\param module module name
	\param kernel kernel name
	\param grid grid dimensions
	\param block block dimensions
	\param sharedMemory shared memory size
	\param argumentBlock array of bytes for parameter memory
	\param argumentBlockSize number of bytes in parameter memory
	\param traceGenerators vector of trace generators to add 
		and remove from kernel
*/
void executive::DynamicMulticoreDevice::launch(
	const std::string& module, 
	const std::string& kernel,
	const ir::Dim3& grid, 
	const ir::Dim3& block, 
	size_t sharedMemory, 
	const void* argumentBlock, 
	size_t argumentBlockSize, 
	const trace::TraceGeneratorVector &traceGenerators,
	const ir::ExternalFunctionSet* externals) {

	report("DynamicMulticoreDevice::launch(" << module << ", " << kernel << ")");
	
	ExecutableKernel *executableKernel = getKernel(module, kernel);
	if (!executableKernel) {
		Ocelot_Exception("Failed to locate kernel");
	}
	
	if(executableKernel->sharedMemorySize() + sharedMemory > 
		(size_t)properties().sharedMemPerBlock)
	{
		Ocelot_Exception("Out of shared memory for kernel \""
			<< executableKernel->name << "\" : \n\tpreallocated "
			<< executableKernel->sharedMemorySize() << " + requested " 
			<< sharedMemory << " is greater than available " 
			<< properties().sharedMemPerBlock << " for device " 
			<< properties().name);
	}
	
	if(executableKernel->constMemorySize() > (size_t)properties().totalConstantMemory)
	{
		Ocelot_Exception("Out of shared memory for kernel \""
			<< executableKernel->name << "\" : \n\tpreallocated "
			<< executableKernel->constMemorySize() << " is greater than available " 
			<< properties().totalConstantMemory << " for device " 
			<< properties().name);
	}
	
	executableKernel->setKernelShape(block.x, block.y, block.z);
	executableKernel->setArgumentBlock((const unsigned char*)argumentBlock, 
		argumentBlockSize);
	executableKernel->updateArgumentMemory();
	executableKernel->updateMemory();
	executableKernel->setExternSharedMemorySize(sharedMemory);
	executableKernel->setExternalFunctionSet(*externals);

	for(trace::TraceGeneratorVector::const_iterator 
		gen = traceGenerators.begin(); 
		gen != traceGenerators.end(); ++gen) 
	{
		executableKernel->addTraceGenerator(*gen);
	}

	try
	{
		executableKernel->launchGrid(grid.x, grid.y, grid.z);
	}
	catch(...)
	{
		for(trace::TraceGeneratorVector::const_iterator 
			gen = traceGenerators.begin(); 
			gen != traceGenerators.end(); ++gen) 
		{
			executableKernel->removeTraceGenerator(*gen);
		}
		throw;
	}
	
	for(trace::TraceGeneratorVector::const_iterator 
		gen = traceGenerators.begin(); 
		gen != traceGenerators.end(); ++gen) 
	{
		executableKernel->removeTraceGenerator(*gen);
	}
	
	executableKernel->clearExternalFunctionSet();
}
	
/*! \brief Get the last error from this device */
unsigned int executive::DynamicMulticoreDevice::getLastError() {
	return 0;
}

/*! \brief Wait until all asynchronous operations have completed */
void executive::DynamicMulticoreDevice::synchronize() {

}

/*! \brief Limit the worker threads used by this device */
void executive::DynamicMulticoreDevice::limitWorkerThreads(unsigned int threads) {

}

/*! \brief Set the optimization level for kernels in this device */
void executive::DynamicMulticoreDevice::setOptimizationLevel(
	translator::Translator::OptimizationLevel level) {

}

executive::DynamicMulticoreKernel::SubkernelId 
	executive::DynamicMulticoreDevice::getFreeSubkernelId() const {
	DynamicMulticoreKernel::SubkernelId baseId = 0;
	for (ModuleMap::const_iterator module_it = modules.begin(); module_it != modules.end();
		++module_it ) {
		
		for (DynamicMulticoreKernelMap::const_iterator kernel_it = module_it->second.kernels.begin();
			kernel_it != module_it->second.kernels.end(); ++kernel_it) {
		
			baseId = std::max(baseId, kernel_it->second->getSubkernelIdRange().second);
		}
	}
	return baseId + 1;
}

