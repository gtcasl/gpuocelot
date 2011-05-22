/*!
	\file LLVMDynamicExecutionManager.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief implements a dynamic execution environment for LLVM kernels
*/

// Ocelot includes
#include <ocelot/executive/interface/LLVMDynamicExecutionManager.h>
#include <ocelot/executive/interface/LLVMDynamicExecutive.h>
#include <ocelot/ir/interface/Module.h>
#include <ocelot/api/interface/OcelotConfiguration.h>

// Hydrazine Includes
#include <hydrazine/implementation/debug.h>

// Standard Library Includes
#include <algorithm>

/////////////////////////////////////////////////////////////////////////////////////////////////

#define Ocelot_Exception(x) { std::stringstream ss; ss << x; std::cerr << __FILE__ << ":" \
	<< __LINE__ << " " << x << std::endl; throw hydrazine::Exception(ss.str()); }

/////////////////////////////////////////////////////////////////////////////////////////////////

// Preprocessor Macros
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

/////////////////////////////////////////////////////////////////////////////////////////////////

namespace executive {

//! singleton instance
LLVMDynamicExecutionManager LLVMDynamicExecutionManager::_instance;

LLVMDynamicExecutionManager & LLVMDynamicExecutionManager::get() {
	return _instance;
}

LLVMDynamicExecutionManager::LLVMDynamicExecutionManager() {
	workerThreadLimit = api::OcelotConfiguration::get().executive.workerThreadLimit;
}

LLVMDynamicExecutionManager::~LLVMDynamicExecutionManager() {

}

class WorkerThreadContext {
public:
	LLVMDynamicExecutionManager *executionManager;
	int workerId;
};

static void * workerThreadHelper(void *ptr) {
	WorkerThreadContext *context = static_cast<WorkerThreadContext*>(ptr);
	LLVMDynamicExecutionManager *executionManager = context->executionManager;
	
	executionManager->workerThread(context->workerId);
	
	pthread_exit(0);
	return 0;
}

/*!
	\brief executes a kernel
*/
void LLVMDynamicExecutionManager::launch(const LLVMDynamicKernel & kernel, int sharedMemorySize) {
	
	report("Launching LLVM kernel '" << kernel.name << "'.");
	
	translationCache.loadModule(kernel.module, kernel.device);
	
	executingKernel.translatedKernel = translationCache.getTranslatedKernel(
		kernel.module->path(), kernel.name);
	executingKernel.kernel = &kernel;
	executingKernel.gridDim = kernel.gridDim();
	executingKernel.blockDim = kernel.blockDim();
	executingKernel.sharedMemorySize = sharedMemorySize;
	
	report("  loaded. Executing grid " << executingKernel.gridDim.x << ", " << executingKernel.gridDim.y);
	report("  block dim: " << executingKernel.blockDim.x << ", " << executingKernel.blockDim.y << ", " << executingKernel.blockDim.z);
	report("  entry id: " << executingKernel.translatedKernel->entryId);
	report("  local memory size: " << executingKernel.translatedKernel->localMemorySize << " bytes");
	report("  shared memory size: " << executingKernel.translatedKernel->sharedMemorySize << " bytes ");
	report("  " << workerThreadLimit << " worker threads");
	
	// spawn worker threads
	if (workerThreadLimit > 1) {
		std::vector< pthread_t > threadIds;
		std::vector< WorkerThreadContext > contexts;
		contexts.reserve(workerThreadLimit);
		threadIds.resize(workerThreadLimit);
		
		report("Spawning " << workerThreadLimit << " threads.");
		
		if (pthread_mutex_init(&mutex, 0)) {
			Ocelot_Exception("Failed to initialize the global mutex.");
		}
				
		for (unsigned int threadId = 0; threadId < workerThreadLimit; ++threadId) {
			WorkerThreadContext ctx = {this, threadId};
			contexts.push_back(ctx);
			if (pthread_create(&threadIds[threadId], 0, workerThreadHelper, &contexts[threadId])) {
				Ocelot_Exception("Failed to create worker thread");
			}
		}
		for (unsigned int threadId = 0; threadId < workerThreadLimit; ++threadId) {
			void *return_ptr = 0;
			pthread_join(threadIds[threadId], &return_ptr);
		}
		
		pthread_mutex_destroy(&mutex);
	}
	else {
		workerThread(0);
	}
}

//! \brief entry point for worker thread
void LLVMDynamicExecutionManager::workerThread(int workerId) {
	LLVMDynamicExecutive executive(executingKernel.kernel, 0, executingKernel.translatedKernel,
		executingKernel.sharedMemorySize);
	
	int totalCtas = executingKernel.gridDim.x * executingKernel.gridDim.y;
	int ctaStart = workerId;
	for (; ctaStart < totalCtas; ctaStart += workerThreadLimit) {
		LLVMDynamicExecutive executive(executingKernel.kernel, 0, executingKernel.translatedKernel, 
			executingKernel.sharedMemorySize);
	
		ir::Dim3 ctaId(ctaStart % executingKernel.gridDim.x, ctaStart / executingKernel.gridDim.x );
		report("Worker " << workerId << " executing CTA " << ctaId.x << ", " << ctaId.y);
	
		executive.addCta(ctaId);
		executive.execute();
	}
}

/*! \brief locks the translation cache and fetches a translation */
const LLVMDynamicTranslationCache::Translation *
LLVMDynamicExecutionManager::getOrInsertTranslationById(
	LLVMDynamicTranslationCache::EntryId id, 
	int ws) {

	report("LLVMDynamicExecutionManager::getOrInsertTranslation( id: " 
		<< id << ", warpsize: " << ws << ")");
	
	lock();

	const LLVMDynamicTranslationCache::Translation *translation =
		 translationCache.getOrInsertTranslationById(id, ws);

	unlock();
	
	return translation;
}

//! \brief global lock
void LLVMDynamicExecutionManager::lock() {
	report("Locking dynamic execution manager");
	pthread_mutex_lock(&mutex);
}

//! \brief global unlock
void LLVMDynamicExecutionManager::unlock() {
	report("Unlocking dynamic execution manager");
	pthread_mutex_unlock(&mutex);
}


}
