/*!
	\file DynamicExecutionManager.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Nov 21, 2011
	\brief singleton instance of dynamic execution manager for multicore CPU backend
*/

// Ocelot includes
#include <ocelot/executive/interface/DynamicExecutionManager.h>
#include <ocelot/executive/interface/DynamicMulticoreExecutive.h>

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

executive::DynamicExecutionManager executive::DynamicExecutionManager::instance;

executive::DynamicExecutionManager & executive::DynamicExecutionManager::get() {
	return instance;
}

executive::DynamicExecutionManager::DynamicExecutionManager() {
	report("DynamicExecutionManager()");
	
	// spawn worker threads
}

executive::DynamicExecutionManager::~DynamicExecutionManager() {
	report("~DynamicExecutionManager()");
	
	// cleanup workers and free resources
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void executive::DynamicExecutionManager::launch(executive::DynamicMulticoreKernel &kernel, 
	size_t sharedMemorySize) {
	
	report("DynamicExecutionManager::launch()");
	
	DynamicMulticoreExecutive executive(kernel, sharedMemorySize);
	
	for (int blockIdy = 0; blockIdy < kernel.gridDim().y; blockIdy++) {
		for (int blockIdx = 0; blockIdx < kernel.gridDim().z; blockIdx++) {
			report("Executing block " << blockIdx << ", " << blockIdy);
			
			executive.execute(ir::Dim3(blockIdx, blockIdy, 1));
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////

