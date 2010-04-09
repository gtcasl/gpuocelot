/*!
	\file LLVMUniformVectorization.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief transformation pass on LLVM functions that performs vectorization for kernels with
			entirely uniform control flow
*/

// C++ includes

// Ocelot includes
#include <ocelot/analysis/interface/LLVMUniformVectorization.h>

// LLVM includes
#ifdef HAVE_LLVM
#include <llvm/LLVMContext.h>
#include <llvm/Analysis/Verifier.h>
#include <llvm/Assembly/Parser.h>
#include <llvm/ExecutionEngine/ExecutionEngine.h>
#include <llvm/ExecutionEngine/JIT.h> 
#include <llvm/ExecutionEngine/GenericValue.h> 
#include <llvm/Module.h>
#include <llvm/PassManager.h>
#if( DEBUG_LLVM == 1 )
#include <llvm/Support/Debug.h>
#endif
#include <llvm/Support/SourceMgr.h>
#include <llvm/Support/raw_ostream.h>
#include <llvm/Target/TargetData.h>
#include <llvm/Target/TargetSelect.h>
#include <llvm/Transforms/Scalar.h>
#endif

// Hydrazine includes
#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

//////////////////////////////////////////////////////////////////////////////////////////////////

analysis::LLVMUniformVectorization::LLVMUniformVectorization(int _warpSize):
	llvm::FunctionPass(this),
	warpSize(_warpSize)
{

}

analysis::LLVMUniformVectorization::~LLVMUniformVectorization() {

}

bool analysis::LLVMUniformVectorization::runOnFunction(llvm::Function &F) {
	typedef llvm::Function::BasicBlockListType BasicBlockList;
	BasicBlockList & basicBlocks = F.getBasicBlockList();
	for (BasicBlockList::iterator bb_it = basicBlocks.begin(); bb_it != basicBlocks.end(); ++bb_it) {


	}

	return true;
}


//////////////////////////////////////////////////////////////////////////////////////////////////

