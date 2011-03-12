/*!
	\file LLVMDynamicExecutionManager.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief orchestrates the execution of a collection of CTAs through a decomposition of PTX kernels
	\date March 2011
*/

// C++ includes
#include <algorithm>

// Ocelot includes
#include <ocelot/executive/interface/LLVMDynamicExecutionManager.h>

#include <ocelot/executive/interface/LLVMWorkerThread.h>
#include <ocelot/executive/interface/LLVMModuleManager.h>
#include <ocelot/executive/interface/LLVMExecutableKernel.h>

#include <ocelot/ir/interface/Module.h>
#include <ocelot/api/interface/OcelotConfiguration.h>

// Hydrazine includes
#include <hydrazine/implementation/debug.h>

// Preprocessor Macros
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

/////////////////////////////////////////////////////////////////////////////////////////////////

executive::LLVMDynamicExecutionManager::Manager() {
}

executive::LLVMDynamicExecutionManager::~Manager() {

}

/*! \brief Launches a kernel on a grid using a context */
void executive::LLVMDynamicExecutionManager::launch(const DynamicExecutableKernel& kernel) {

	typedef api::OcelotConfiguration Config;
	
	report("Launching LLVM kernel '" << kernel.name << "'.");
	if(!threads()) {
		setWorkerThreadCount(std::min(hydrazine::getHardwareThreadCount(),
			(unsigned)Config::get().executive.workerThreadLimit));
	}
}

/*! \brief Changes the number of worker threads */
void executive::LLVMDynamicExecutionManager::setWorkerThreadCount(unsigned int threads) {

}

/*! \brief Gets the current number of threads */
unsigned int executive::LLVMDynamicExecutionManager::threads() const {
	return 1;
}

/*! \brief Flush references to translated kernels */
void executive::LLVMDynamicExecutionManager::flushTranslatedKernels() {

}

/////////////////////////////////////////////////////////////////////////////////////////////////	
	
/*! \brief Launches a kernel on a grid using a context */
void executive::LLVMDynamicExecutionManager::launch(const DynamicExecutableKernel& kernel) {
	_manager.launch(kernel);
}

/*! \brief Changes the number of worker threads */
void executive::LLVMDynamicExecutionManager::setWorkerThreadCount(unsigned int threads) {
	_manager.setWorkerThreadCount(threads);
}

/*! \brief Gets the current number of threads */
unsigned int executive::LLVMDynamicExecutionManager::threads() {
	return _manager.threads();
}

/*! \brief Flush references to translated kernels */
void executive::LLVMDynamicExecutionManager::flushTranslatedKernels() {
	_manager.flushTranslatedKernels();
}

/////////////////////////////////////////////////////////////////////////////////////////////////
