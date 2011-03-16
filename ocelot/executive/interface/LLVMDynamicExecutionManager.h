/*!
	\file LLVMDynamicExecutionManager.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief implements a dynamic execution environment 
*/

#ifndef OCELOT_EXECUTIVE_LLVMDYNAMICEXECUTIONMANAGER_H_INCLUDED
#define OCELOT_EXECUTIVE_LLVMDYNAMICEXECUTIONMANAGER_H_INCLUDED

// C++ includes

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
		
	public:
		
		static LLVMDynamicExecutionManager & get();
		
	public:
		LLVMDynamicExecutionManager();
		~LLVMDynamicExecutionManager();
		
		/*! \brief locks the translation cache and fetches a translation */
		const LLVMDynamicTranslationCache::Translation *getOrInsertTranslationById(
			LLVMDynamicTranslationCache::HyperblockId, int ws=1);

		/*! \brief launches a pre-configured LLVMDynamicKernel */
		void launch(const LLVMDynamicKernel & kernel);
				
	private:
		//! \brief global lock
		void lock();
		
		//! \brief global unlock
		void unlock();
		
	private:
	
		//! \brief stores a listing
		LLVMDynamicTranslationCache translationCache;
		
		
	public:
	
		static LLVMDynamicExecutionManager _instance;
	};

}

#endif

