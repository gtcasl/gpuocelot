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
	
		class TranslatedKernel;
		
		/*!
			\brief data structure regarding an individual translation of a subkernel
		*/
		class Translation {
		public:
			Translation();
			~Translation();
			
			//! \brief executes a translation
			void execute(LLVMContext *contexts) const;
			
		public:
			//! \brief LLVM function backing translation
			llvm::Function *llvmFunction;
			
			//! \brief pointer to compiled function
			TranslatedFunction function;
			
			//! \brief stores information needed by the translated function and the execution manager
			void *metadata;
						
			//! \brief size of a warp
			int warpSize;
		};
		
		//! \brief maps warp size onto particular translations
		typedef std::map< int, const Translation *> TranslationWarpMap;
		
		/*!
			\brief contains elements of the kernel decomposition as well as a set of existing translations
		*/
		class TranslatedSubkernel {
		public:
			TranslatedSubkernel();
			~TranslatedSubkernel();
			
		public:
			//! \brief each kernel is translated as its own module
			llvm::Module *kernelModule;
			
			//! \brief pointer to parent kernel
			TranslatedKernel *parent;
		
			//! \brief subkernel
			ir::PTXKernel *subkernel;
			
			//! \brief id of entry
			HyperblockId entryId;
		
			//! \brief 
			TranslationWarpMap translations;
			
			//! \brief each translated subkernel offers a certain storage requirement
			size_t localMemorySize;
		};
		typedef std::unordered_map< HyperblockId, TranslatedSubkernel *> TranslatedSubkernelMap;
		
		/*!
			\brief data structure for translated kernels
		*/
		class TranslatedKernel {
		public:
			TranslatedKernel();
			~TranslatedKernel();
			
		public:
		
			//! \brief this data structure maintains the kernel's structure
			analysis::HyperblockFormation::KernelDecomposition decomposition;
			
			//! \brief
			ir::PTXKernel *kernel;
			
			//! \brief
			HyperblockId entryBlockId;
			
			//! \brief set of translations for each subkernel
			TranslatedSubkernelMap subkernels;
			
			//! \brief maximum amount of local memory required for translated kernel
			size_t localMemorySize;
			
			//! \brief size of each [static] shared memory declaration
			size_t sharedMemorySize;
		};
		
		typedef std::map< std::string, TranslatedKernel * > KernelTranslationMap;
				
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
		
			//! \brief kernel decomposition of hyperblocks 
			KernelTranslationMap kernels;
		};
		typedef std::unordered_map< std::string, ModuleMetadata> ModuleMap;
	
	public:
	
		LLVMDynamicTranslationCache();
		~LLVMDynamicTranslationCache();
		
		//! \brief loads a module into the translation cache
		bool loadModule(const ir::Module *module, executive::Device *device);
		
		//! \brief gets a translated kernel by name
		const TranslatedKernel *getTranslatedKernel(const std::string &module, const std::string &kernel);
				
		//! \brief searches for an existing translation and compiles it if it doesn't exist
		const Translation *getOrInsertTranslationById(HyperblockId, int ws=1);
	
	private:
	
		/*!
			\brief entry point of PTX->LLVM compilation
		*/
		void *compileTranslation(
			TranslatedKernel &translatedKernel,
			TranslatedSubkernel &translatedSubkernel,
			Translation &translation,
			ir::PTXKernel *parent,
			translator::Translator::OptimizationLevel optimization,
			executive::Device *device);
	
	private:
	
		//! \brief reference to the owning execution manager
		LLVMDynamicExecutionManager *executionManager;
	
		//! \brief stores information
		ModuleMap modules;
		
		//! \brief references translated 
		TranslatedSubkernelMap subkernelMap;
	};
}

#endif

