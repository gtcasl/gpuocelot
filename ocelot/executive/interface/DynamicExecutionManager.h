/*!
	\file DynamicExecutionManager.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Nov 21, 2011
	\brief singleton instance of dynamic execution manager for multicore CPU backend
*/

#ifndef OCELOT_EXECUTIVE_DYNAMICEXECUTIONMANAGER_H_INCLUDED
#define OCELOT_EXECUTIVE_DYNAMICEXECUTIONMANAGER_H_INCLUDED

#include <ocelot/executive/interface/DynamicTranslationCache.h>
#include <ocelot/executive/interface/DynamicMulticoreKernel.h>

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
	
		static DynamicExecutionManager instance;
		
	public:
		//! owns the translation cache
		DynamicTranslationCache translationCache;
		
	};

}

#endif

