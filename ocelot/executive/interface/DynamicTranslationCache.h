/*!
	\file DynamicTranslationCache.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date November 11, 2011
	\brief cache of translations
*/

#ifndef OCELOT_EXECUTIVE_DYNAMICTRANSLATIONCACHE_H_INCLUDED
#define OCELOT_EXECUTIVE_DYNAMICTRANSLATIONCACHE_H_INCLUDED

#include <ocelot/executive/interface/LLVMContext.h>
#include <ocelot/analysis/interface/KernelPartitioningPass.h>

namespace llvm {
	class Function;
}

namespace executive {

	class DynamicTranslationCache {
	public:
		typedef analysis::KernelPartitioningPass::SubkernelId SubkernelId;
		typedef void (*ExecutableFunction)(LLVMContext *);
	
		//! \brief 
		class Translation {
		public:
		public:
			Translation(llvm::Function *llvmFunction);
		
			void execute();
		
		protected:
			//! \brief
			llvm::Function *llvmFunction;
			
			//! \brief
			ExecutableFunction function;
		};
		
		typedef std::map<SubkernelId, Translation * > TranslationMap;
		typedef std::map< int, TranslationMap> WarpTranslationMap;
	
	public:
		DynamicTranslationCache();
		~DynamicTranslationCache();
		
		/*!
			\brief gets the translation corresponding to a particular warp size
		*/
		Translation *getOrInsertTranslation(int warpsize, SubkernelId subkernel, 
			unsigned int specialization = 0);
		
	protected:
	
		//! \brief 
		WarpTranslationMap translations;
	
	};

}

#endif


