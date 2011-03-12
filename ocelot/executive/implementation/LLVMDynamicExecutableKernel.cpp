/*! 
	\file LLVMDynamicExecutableKernel.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date March 2011
	\brief Implements a dynamic llvm executable kernel
*/

// Ocelot Includes
#include <ocelot/executive/interface/LLVMDynamicExecutableKernel.h>
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

static unsigned int pad(unsigned int& size, unsigned int alignment) {
	unsigned int padding = alignment - (size % alignment);
	padding = (alignment == padding) ? 0 : padding;
	size += padding;
	return padding;
}

executive::LLVMDynamicExecutableKernel::LLVMDynamicExecutableKernel(
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

executive::LLVMDynamicExecutableKernel::~LLVMDynamicExecutableKernel() {

	delete[] _argumentMemory;
	delete[] _constantMemory;
}

void executive::LLVMDynamicExecutableKernel::launchGrid(int x, int y) {	

	report( "Launching kernel \"" << name 
		<< "\" on grid ( x = " 
		<< x << ", y = " << y << " )"  );
	
	_gridDim.x = x;
	_gridDim.y = y;
	
	hydrazine::Timer timer;
	
	timer.start();
	
	LLVMExecutionManager::launch(*this);
	
	timer.stop();
	
	if (api::OcelotConfiguration::get().executive.printKernelRuntimes) {
		std::cout << "{ \"kernel\": " << name << ", \"runtime\": " << timer.seconds() << ", "
			<< "\"warpSize\": " << api::OcelotConfiguration::get().executive.warpSize << ", "
			<< "\"gridDim\": ["
			<< _gridDim.x << ", " << _gridDim.y << ", " << _gridDim.z << "], \"blockDim\": [" 
			<< _blockDim.x << ", " << _blockDim.y << ", " << _blockDim.z << "] }\n";
	}
}

void executive::LLVMDynamicExecutableKernel::setKernelShape( int x, int y, int z ) {
	report( "Setting CTA shape to ( x = " << x << ", y = " 
		<< y << ", z = " << z << " ) for kernel \"" << name << "\""  );

	_blockDim.x = x;
	_blockDim.y = y;
	_blockDim.z = z;
}

void executive::LLVMDynamicExecutableKernel::setExternSharedMemorySize(unsigned int bytes) {
	_externSharedMemorySize = bytes;
}

void executive::LLVMDynamicExecutableKernel::setWorkerThreads(unsigned int threadLimit) {
	LLVMExecutionManager::setWorkerThreadCount(
		std::min(device->properties().multiprocessorCount, threadLimit));
}

void executive::LLVMDynamicExecutableKernel::updateArgumentMemory() {

}

void executive::LLVMDynamicExecutableKernel::updateMemory() {
	report( "Updating Memory" );

}

executive::ExecutableKernel::TextureVector 
	executive::LLVMDynamicExecutableKernel::textureReferences() const {
	
	return TextureVector();
}

char* executive::LLVMDynamicExecutableKernel::argumentMemory() const {
	return _argumentMemory;
}

char* executive::LLVMDynamicExecutableKernel::constantMemory() const {
	return _constantMemory;
}

executive::LLVMDynamicExecutableKernel::OptimizationLevel 
	executive::LLVMDynamicExecutableKernel::optimization() const {
	return _optimizationLevel;
}

void executive::LLVMDynamicExecutableKernel::addTraceGenerator(
	trace::TraceGenerator *generator) {
	assertM(false, "No trace generation support in LLVM kernel.");
}

void executive::LLVMDynamicExecutableKernel::removeTraceGenerator(
	trace::TraceGenerator *generator) {
	assertM(false, "No trace generation support in LLVM kernel.");	
}

