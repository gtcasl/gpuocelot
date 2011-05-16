/*!
	\file LLVMDynamicTranslationCache.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief implements a dynamic execution environment 
*/

#ifndef OCELOT_EXECUTIVE_LLVMDYNAMICTRANSLATIONCACHE_H_INCLUDED
#define OCELOT_EXECUTIVE_LLVMDYNAMICTRANSLATIONCACHE_H_INCLUDED

// Ocelot includes
#include <ocelot/analysis/interface/KernelPartitioningPass.h>
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
		typedef analysis::KernelPartitioningPass::EntryId EntryId;
		typedef void (*TranslatedFunction)(LLVMContext *);
		
	public:
		
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
			\brief 
		*/
		class TranslatedKernel {
		public:
			TranslatedKernel();
			~TranslatedKernel();
			
		public:
			//! \brief 
			llvm::Module *sourceModule;
		
			//! \brief each kernel is translated as its own module
			llvm::Module *kernelModule;
			
			//! \brief source PTX kernel
			ir::PTXKernel *kernel;
			
			//! \brief unoptimized direct translation from PTX to LLVM
			llvm::Function *scalarTranslation;
		
			//! \brief id of entry
			EntryId entryId;
			
			//! \brief
			analysis::KernelPartitioningPass::KernelDecomposition decomposition;
		
			//! \brief 
			TranslationWarpMap translations;
			
			//! \brief stores information needed by the translated function and the execution manager
			void *metadata;
			
			//! \brief maximum amount of local memory required for translated kernel
			size_t localMemorySize;
			
			//! \brief size of each [static] shared memory declaration
			size_t sharedMemorySize;
		};
		
		typedef std::unordered_map< EntryId, TranslatedKernel *> TranslatedKernelMap;
		typedef std::unordered_map< std::string, TranslatedKernel *> TranslatedKernelNameMap;
						
		/*!
			\brief stores module-level information such as the decomposition of kernels
				to hyperblocks
		*/
		class ModuleMetadata {
		public:
			ModuleMetadata();
			~ModuleMetadata();
			
			void clear();
			
		public:
		
			//! \brief registered PTX module
			const ir::Module *ptxModule;
			
			//! \brief target device
			executive::Device *device;
		
			//! \brief kernel decomposition of hyperblocks 
			TranslatedKernelNameMap kernels;
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
		const Translation *getOrInsertTranslationById(EntryId, int ws=1);
	
	private:
	
		void translateFromPTX(
			TranslatedKernel &translatedKernel,
			translator::Translator::OptimizationLevel optimization,
			executive::Device *device);
		
		void specializeTranslation(
			TranslatedKernel &translatedSubkernel,
			Translation *translation,
			translator::Translator::OptimizationLevel optimization,
			executive::Device *device);
			
		void write(std::ostream &out);
	
	private:
	
		//! \brief reference to the owning execution manager
		LLVMDynamicExecutionManager *executionManager;
	
		//! \brief stores information
		ModuleMap modules;
		
		//! \brief references translated 
		TranslatedKernelMap kernelMap;
	};
}

#endif

