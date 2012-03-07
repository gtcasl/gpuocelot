/*!
	\file DynamicExecutionManager.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Nov 21, 2011
	\brief singleton instance of dynamic execution manager for multicore CPU backend
*/

#ifndef OCELOT_EXECUTIVE_DYNAMICEXECUTIONMANAGER_H_INCLUDED
#define OCELOT_EXECUTIVE_DYNAMICEXECUTIONMANAGER_H_INCLUDED

// C++ and other library includes
#include <pthread.h>

// Ocelot includes
#include <ocelot/executive/interface/DynamicTranslationCache.h>
#include <ocelot/executive/interface/DynamicMulticoreKernel.h>

typedef struct {
	size_t sharedMemorySize;
	int threadId;
	int pitch;
	
	pthread_barrier_t *launchBarrier;
	pthread_barrier_t *finishBarrier;
	executive::DynamicMulticoreKernel *kernel;
} WorkerThreadArgs;

#define MaxThreadCount 8

namespace executive {

	/*!
	
	*/
	class DynamicExecutionManager {	
	public:
		DynamicExecutionManager();
		~DynamicExecutionManager();
		
		static DynamicExecutionManager &get();
		
		void launch(DynamicMulticoreKernel &kernel, size_t sharedMemorySize);
		
	protected:
		
		WorkerThreadArgs arguments[MaxThreadCount];
		pthread_t threads[MaxThreadCount];
	
		pthread_barrier_t _launchBarrier;
		pthread_barrier_t _finishBarrier;
		
		static DynamicExecutionManager instance;
		
	public:
		//! owns the translation cache
		DynamicTranslationCache translationCache;
		
	};

}

#endif

