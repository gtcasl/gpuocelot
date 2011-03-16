/*!
	\file LLVMDynamicTranslationCache.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief implements a dynamic execution environment 
*/

#ifndef OCELOT_EXECUTIVE_LLVMDYNAMICTRANSLATIONCACHE_H_INCLUDED
#define OCELOT_EXECUTIVE_LLVMDYNAMICTRANSLATIONCACHE_H_INCLUDED

// Ocelot includes
#include <ocelot/analysis/interface/HyperblockFormationPass.h>
#include <ocelot/translator/interface/Translator.h>

namespace llvm {
	class Module;
	class Function;
}

namespace executive {

	class LLVMDynamicExecutionManager;
	class LLVMContext;
	class Device;

	/*!
		\brief 
	*/
	class LLVMDynamicTranslationCache {
	public:
		typedef analysis::HyperblockFormation::HyperblockId HyperblockId;
		typedef void (*TranslatedFunction)(LLVMContext *);
		
	public:
	
		/*!
			\brief data structure regarding an individual translation 
		*/
		class Translation {
		public:
			Translation();
			~Translation();
			
			//! \brief executes a translation
			void execute(LLVMContext *contexts) const;
			
		public:
		
			//! \brief subkernel
			ir::PTXKernel *subkernel;
			
			//! \brief references translated form of subkernel
			llvm::Function *translation;
			
			//! \brief pointer to compiled function
			TranslatedFunction function;
			
			//! \brief stores information needed by the translated function and the execution manager
			void *metadata;
			
			//! \brief id of entry
			HyperblockId entryId;
			
			//! \brief size of a warp
			int warpSize;
		};
		
		//! \brief maps warp size onto particular translations
		typedef std::map< int, const Translation *> TranslationWarpMap;
		
		//! \brief maps HyperblockIds onto sets of translations
		typedef std::unordered_map< HyperblockId, TranslationWarpMap > TranslationMap;
		
		typedef std::map< std::string, analysis::HyperblockFormation::KernelDecomposition > KernelDecompositionMap;
				
		/*!
			\brief stores module-level information such as the decomposition of kernels
				to hyperblocks
		*/
		class ModuleMetadata {
		public:
		
			//! \brief registered PTX module
			const ir::Module *ptxModule;
			
			//! \brief target device
			executive::Device *device;
			
			//! \brief references the containing LLVM module
			llvm::Module *llvmModule;
		
			//! \brief kernel decomposition of hyperblocks 
			KernelDecompositionMap kernels;
		};
		typedef std::unordered_map< std::string, ModuleMetadata> ModuleMap;
	
	public:
	
		LLVMDynamicTranslationCache();
		~LLVMDynamicTranslationCache();
		
		//! \brief loads a module into the translation cache
		bool loadModule(const ir::Module *module, executive::Device *device);
		
		//! \brief searches for an existing translation and returns false if doesn't exist
		const Translation *getTranslationById(HyperblockId id, int ws=1) const;
		
		//! \brief searches for an existing translation and compiles it if it doesn't exist
		const Translation *getOrInsertTranslationById(HyperblockId, int ws=1);
	
	private:
	
		/*!
			\brief entry point of PTX->LLVM compilation
		*/
		void *compileTranslation(
			LLVMDynamicTranslationCache::Translation &translation,
			llvm::Module * & module,
			ir::PTXKernel *parent,
			translator::Translator::OptimizationLevel optimization,
			executive::Device *device);
	
	private:
	
		//! \brief reference to the owning execution manager
		LLVMDynamicExecutionManager *executionManager;
	
		//! \brief stores information
		ModuleMap modules;
		
		//! \brief 
		TranslationMap translations;
	};
}

#endif

