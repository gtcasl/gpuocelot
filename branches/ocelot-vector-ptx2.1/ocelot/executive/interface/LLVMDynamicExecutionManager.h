/*!
	\file LLVMDynamicExecutionManager.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief implements a dynamic execution environment 
*/

#ifndef OCELOT_EXECUTIVE_LLVMDYNAMICEXECUTIONMANAGER_H_INCLUDED
#define OCELOT_EXECUTIVE_LLVMDYNAMICEXECUTIONMANAGER_H_INCLUDED

// C++ includes
#include <pthread.h>

// Ocelot includes
#include <ocelot/executive/interface/LLVMDynamicTranslationCache.h>
#include <ocelot/translator/interface/Translator.h>
#include <ocelot/executive/interface/LLVMDynamicKernel.h>

namespace ir {
	class Module;
}

namespace executive {
	class Device;
}

namespace executive {

	class LLVMDynamicExecutionManager {
	public:
		typedef translator::Translator::OptimizationLevel OptimizationLevel;
		
		class KernelExecution {
		public:
			//! \brief 
			const LLVMDynamicKernel *kernel;

			//! \brief kernel to execute
			const LLVMDynamicTranslationCache::TranslatedKernel *translatedKernel;
	
			//! \brief block dimensions
			ir::Dim3 gridDim;
	
			//! \brief
			ir::Dim3 blockDim;
			
			//! \brief size in bytes of shared memory
			size_t sharedMemorySize;
		};
		
	public:
		
		static LLVMDynamicExecutionManager & get();
		
	public:
		LLVMDynamicExecutionManager();
		~LLVMDynamicExecutionManager();
		
		/*! \brief locks the translation cache and fetches a translation */
		const LLVMDynamicTranslationCache::Translation *getOrInsertTranslationById(
			LLVMDynamicTranslationCache::EntryId, int ws=1);

		/*! \brief launches a pre-configured LLVMDynamicKernel */
		void launch(const LLVMDynamicKernel & kernel, int sharedMemorySize);
		
		/*! \brief limits the number of worker threads */
		void setWorkerThreadCount(unsigned int threads = 1);
		
		/*! \brief gets the number of worker threads */
		unsigned int getWorkerThreadCount() const;
				
		//! \brief entry point for worker thread
		void workerThread(int workerId = 0);
		
	private:
		//! \brief global lock
		void lock();
		
		//! \brief global unlock
		void unlock();
		
		
	private:
	
		//! \brief stores a listing
		LLVMDynamicTranslationCache translationCache;
		
		//! \brief data structures shared among workers regarding currently executing kernel
		KernelExecution executingKernel;
		
		//! \brief number of worker threads
		unsigned int workerThreadLimit;
		
		//! \brief uses to manage the global lock
		pthread_mutex_t mutex;
		
	public:
	
		static LLVMDynamicExecutionManager _instance;
	};

}

#endif

