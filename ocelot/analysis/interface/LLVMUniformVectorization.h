/*!
	\file LLVMUniformVectorization.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief transformation pass on LLVM functions that performs vectorization for kernels with
			entirely uniform control flow
*/

#ifndef OCELOT_ANALYSIS_LLVMUNIFORMVECTORIZATION_H_INCLUDED
#define OCELOT_ANALYSIS_LLVMUNIFORMVECTORIZATION_H_INCLUDED

// C++ includes

// Ocelot includes

// Hydrazine includes

// LLVM includes
#include <llvm/Module.h>
#include <llvm/PassManager.h>

namespace analysis
{

	/*!
		\brief pass applied to kernels with completely uniform control flow for warps of a given
			size
	*/
	class LLVMUniformVectorization: public llvm::FunctionPass {
	public:
		/*!
			\brief vectorizes kernels assuming all control flow is uniform across warps

			\param warpSize number of logical threads per warp
		*/
		LLVMUniformVectorization(int warpSize=4);
		~LLVMUniformVectorization();

	public:

		//! \brief entry point for pass
		virtual bool runOnFunction(llvm::Function &F);

	public:

		//! \brief number of consecutive threads to pack into a single hardware thread
		int warpSize;
	};

}

#endif

