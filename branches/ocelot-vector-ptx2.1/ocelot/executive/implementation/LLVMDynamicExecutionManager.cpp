/*!
	\file LLVMDynamicExecutionManager.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief implements a dynamic execution environment for LLVM kernels
*/

// Ocelot includes
#include <ocelot/executive/interface/LLVMDynamicExecutionManager.h>
#include <ocelot/executive/interface/LLVMDynamicExecutive.h>
#include <ocelot/ir/interface/Module.h>

// Hydrazine Includes
#include <hydrazine/implementation/debug.h>

// Standard Library Includes
#include <algorithm>

// Preprocessor Macros
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1

namespace executive {

//! singleton instance
LLVMDynamicExecutionManager LLVMDynamicExecutionManager::_instance;

LLVMDynamicExecutionManager & LLVMDynamicExecutionManager::get() {
	return _instance;
}

LLVMDynamicExecutionManager::LLVMDynamicExecutionManager() {

}

LLVMDynamicExecutionManager::~LLVMDynamicExecutionManager() {

}

/*!
	\brief executes a kernel
*/
void LLVMDynamicExecutionManager::launch(const LLVMDynamicKernel & kernel) {
	
	report("Launching LLVM kernel '" << kernel.name << "'.");
	
	translationCache.loadModule(kernel.module, kernel.device);

	LLVMDynamicTranslationCache::HyperblockId entryId = translationCache.getEntryId(
		kernel.module->path(), 
		kernel.name);
	
	ir::Dim3 gridDim(kernel.gridDim());
	ir::Dim3 blockDim(kernel.blockDim());
	int totalCtas = gridDim.x * gridDim.y;
	report("  loaded. Executing grid " << gridDim.x << ", " << gridDim.y);
	report("  block dim: " << blockDim.x << ", " << blockDim.y << ", " << blockDim.z);
	report("  entry id: " << entryId);
	
	
	for (int ctaStart = 0; ctaStart < totalCtas; ctaStart++) {
		LLVMDynamicExecutive executive(&kernel, 0, entryId);
		ir::Dim3 ctaId(ctaStart % gridDim.y, ctaStart / gridDim.y );
		report("Executing CTA " << ctaId.x << ", " << ctaId.y);
		
		executive.addCta(ctaId);
		executive.execute();
	}
}

/*! \brief locks the translation cache and fetches a translation */
const LLVMDynamicTranslationCache::Translation *
LLVMDynamicExecutionManager::getOrInsertTranslationById(
	LLVMDynamicTranslationCache::HyperblockId id, 
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
}

//! \brief global unlock
void LLVMDynamicExecutionManager::unlock() {
	report("Unlocking dynamic execution manager");
}

}
