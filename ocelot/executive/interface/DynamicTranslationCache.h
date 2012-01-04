/*!
	\file DynamicTranslationCache.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date November 11, 2011
	\brief cache of translations
*/

#ifndef OCELOT_EXECUTIVE_DYNAMICTRANSLATIONCACHE_H_INCLUDED
#define OCELOT_EXECUTIVE_DYNAMICTRANSLATIONCACHE_H_INCLUDED

// C++ includes
#include <map>

// Ocelot includes
#include <ocelot/ir/interface/Module.h>
#include <ocelot/executive/interface/LLVMContext.h>
#include <ocelot/analysis/interface/KernelPartitioningPass.h>
#include <ocelot/executive/interface/DynamicMulticoreExecutive.h>

namespace llvm {
	class Function;
}

namespace executive {

	class DynamicMulticoreKernel;
	class DynamicMulticoreDevice;

	class DynamicTranslationCache {
	public:
		typedef translator::Translator::OptimizationLevel OptimizationLevel;
		typedef analysis::KernelPartitioningPass::SubkernelId SubkernelId;
		typedef analysis::KernelPartitioningPass::KernelGraph KernelGraph;
		
		typedef void (*ExecutableFunction)(LLVMContext *);
	
		//! \brief stores the actual JIT-compiled subkernel 
		class Translation {
		public:
		public:
			Translation(llvm::Function *llvmFunction = 0);
		
			void execute(LLVMContext **contexts) const;
		
		protected:
		
			//! \brief
			llvm::Function *llvmFunction;
			
			//! \brief
			ExecutableFunction function;
			
			//! \brief stores information needed by the translated function and the execution manager
			void *metadata;
		};
		
		//! maps warp size onto a particular translation instance
		typedef std::map< int, Translation* > WarpTranslationMap;
		typedef std::map< SubkernelId, Translation *> TranslationMap;
		typedef std::map< SUbkernelId, WarpTranslationMap> TranslationCacheMap;
		
		class TranslatedSubkernel {
		public:
		
		public:
			//! \brief source LLVM function
			llvm::Function *llvmFunction;

			//! \brief stores information needed by the translated function and the execution manager
			void *metadata;
			
			//! 
			WarpTranslationMap translations;
		};
		
		//! maps subkernelId onto a set of translations
		typedef std::map<SubkernelId, TranslatedSubkernel > TranslatedSubkernelMap;
		
		/*!
			\brief 
		*/
		class TranslatedKernel {			
		public:
			TranslatedKernel(DynamicMulticoreKernel *_kernel);
			
		public:
		
			//! \brief 
			llvm::Module *llvmModule;
			
			//! \brief
			DynamicMulticoreKernel *kernel;
			
			//! \brief mapping of translated subkernels
			TranslatedSubkernelMap subkernels;
			
			//! \brief maximum amount of local memory required for translated kernel
			size_t localMemorySize;
			
			//! \brief size of each [static] shared memory declaration
			size_t sharedMemorySize;
		};
		typedef std::unordered_map< std::string, TranslatedKernel *> TranslatedKernelNameMap;
		typedef std::unordered_map< SubkernelId, TranslatedKernel *> SubkernelParentMap;

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
			
		
			//! \brief kernel decomposition of hyperblocks 
			TranslatedKernelNameMap kernels;
		};
		typedef std::unordered_map< std::string, ModuleMetadata> ModuleMap;
	
	public:
		DynamicTranslationCache();
		~DynamicTranslationCache();
		
		void registerKernel(DynamicMulticoreKernel *kernel);
		
		//! \brief loads a module into the translation cache
		bool loadModule(const ir::Module *module, DynamicMulticoreDevice *device);
		
		/*!
			\brief gets the translation corresponding to a particular warp size
		*/
		Translation *getOrInsertTranslation(int warpsize, SubkernelId subkernel, 
			unsigned int specialization = 0);
		
	private:
	
		void _translateKernel(TranslatedKernel &kernel);
		
		Translation *_specializeTranslation(TranslatedKernel &kernel, SubkernelId subkernelId, 
			OptimizationLevel optimizationLevel, int warpSize, unsigned int specialization = 0);
		
	protected:
	
		//! \brief reference to the owning execution manager
		DynamicExecutionManager *executionManager;

		//! \brief target device
		executive::DynamicMulticoreDevice *device;
			
		//! \brief stores information
		ModuleMap modules;
		
		//! \brief 
		SubkernelParentMap subkernelsToKernel;
	
		TranslationCacheMap translationCache;
	};

}

#endif


