/*!
	\file DynamicExecutionManager.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Nov 21, 2011
	\brief singleton instance of dynamic execution manager for multicore CPU backend
*/

// C++ and other libraries
#include <pthread.h>

// Ocelot includes
#include <ocelot/api/interface/OcelotConfiguration.h>
#include <ocelot/executive/interface/DynamicMulticoreDevice.h>
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

#define REPORT_BASE 0

////////////////////////////////////////////////////////////////////////////////////////////////////

executive::DynamicExecutionManager executive::DynamicExecutionManager::instance;

executive::DynamicExecutionManager & executive::DynamicExecutionManager::get() {
	return instance;
}

executive::DynamicExecutionManager::DynamicExecutionManager(): translationCache(this) {
	report("DynamicExecutionManager()");
	
	// spawn worker threads
}

executive::DynamicExecutionManager::~DynamicExecutionManager() {
	report("~DynamicExecutionManager()");
	
	// cleanup workers and free resources
}

////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct {
	size_t sharedMemorySize;
	int threadId;
	int pitch;
	executive::DynamicMulticoreKernel *kernel;
} WorkerThreadArgs;

static void * executionManagerWorkerThread(void *args) {
	
	const WorkerThreadArgs *arguments = static_cast<const WorkerThreadArgs *>(args);
	
	int gridDimy = arguments->kernel->gridDim().y;
	int gridDimx = arguments->kernel->gridDim().x;
	
	if (arguments->threadId < gridDimx * gridDimy) {
		// start executing	
		executive::DynamicMulticoreExecutive executive(*arguments->kernel, arguments->sharedMemorySize);
		for (int blockId = arguments->threadId; blockId < gridDimx * gridDimy; blockId += arguments->pitch) {
			executive.execute(ir::Dim3(blockId % gridDimx, blockId / gridDimx, 0));
		}
	}
	
	return 0;
}

void executive::DynamicExecutionManager::launch(executive::DynamicMulticoreKernel &kernel, 
	size_t sharedMemorySize) {
	
	report("DynamicExecutionManager::launch() - dynamic sharedMemorySize = " << sharedMemorySize);

	translationCache.loadModule(kernel.module, static_cast<executive::DynamicMulticoreDevice*>(kernel.device));
	
	// make the kernel graph available to the dynamic translation cache if need be
	translationCache.registerKernel(&kernel);
	sharedMemorySize += kernel.totalSharedMemorySize();
	
	int workerThreads = api::OcelotConfiguration::get().executive.workerThreadLimit;
	const int MaxThreadCount = 8;
	assert(workerThreads <= MaxThreadCount && "Too many worker threads");
	
	report(" launching grid " << kernel.gridDim().x << " x " << kernel.gridDim().y 
		<< " on " << workerThreads << " threads");
	
	if (workerThreads == 1) {
	
		// start executing
		report("  sharedMemorySize() = " << kernel.sharedMemorySize());
		report("  externSharedMemorySize() = " << kernel.externSharedMemorySize());
		report("  totalSharedMemorySize() = " << kernel.totalSharedMemorySize());
	
		DynamicMulticoreExecutive executive(kernel, sharedMemorySize);
	
		for (int blockIdy = 0; blockIdy < kernel.gridDim().y; blockIdy++) {
			for (int blockIdx = 0; blockIdx < kernel.gridDim().x; blockIdx++) {
				report("Executing block " << blockIdx << ", " << blockIdy);
			
				executive.execute(ir::Dim3(blockIdx, blockIdy, 1));
			}
		}
	}
	else {
		
		WorkerThreadArgs arguments[MaxThreadCount];
		pthread_t threads[MaxThreadCount];
		
		for (int i = 0; i < workerThreads; i++) {
			arguments[i].sharedMemorySize = sharedMemorySize;
			arguments[i].kernel = &kernel;
			arguments[i].pitch = workerThreads;
			arguments[i].threadId = i;
			int ret = pthread_create(&threads[i], 0, executionManagerWorkerThread, &arguments[i]);
			assert(!ret && "Failed to create worker thread");
		}
		
		for (int i = 0; i < workerThreads; i++) {
			void *valuePtr = 0;
			pthread_join(threads[i], &valuePtr);
		}
	}
}

// emma was here. :-)

////////////////////////////////////////////////////////////////////////////////////////////////////

