/*!
	\file LLVMUniformVectorization.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Nov 2011
	\brief transformation pass on LLVM functions that performs vectorization for kernels with
			entirely uniform control flow
	
*/

#ifndef OCELOT_ANALYSIS_LLVMUNIFORMVECTORIZATION_H_INCLUDED
#define OCELOT_ANALYSIS_LLVMUNIFORMVECTORIZATION_H_INCLUDED

// C++ includes
#include <list>
#include <map>
#include <vector>

// Ocelot includes
#include <ocelot/analysis/interface/KernelPartitioningPass.h>

// Hydrazine includes

// LLVM includes
#include <llvm/Module.h>
#include <llvm/PassManager.h>

// toggles uniform control flow warp-synchronous execution or scalar execution (1)
#define LLVM_UNIFORMCONTROL_WARPSIZE 2

namespace llvm {
	class Type;
	class IntegerType;
	class StructType;
	class ConstantInt;
	class GetElementPtrInst;
	class LoadInst;
	class BinaryOperator;
	class CallInst;
	class PHINode;
	class BasicBlock;
	class Instruction;
}

namespace analysis
{

	class LLVMUniformVectorization: public llvm::FunctionPass {
	public:
		typedef std::vector< llvm::Instruction *> InstructionVector;
		typedef analysis::KernelPartitioningPass::KernelGraph KernelGraph;

		//! \brief usage of a thread-local parameter (either thread ID or local memory ptr)
		class ThreadLocalArgument {
		public:
			typedef std::vector< llvm::Instruction *> ThreadLocalArgumentVector;
		public:
		
			llvm::Instruction *ptrThreadDescriptorArray;
			
			ThreadLocalArgumentVector contextObject;
		
			ThreadLocalArgumentVector threadId_x;
			ThreadLocalArgumentVector threadId_y;
			ThreadLocalArgumentVector threadId_z;
			
			ThreadLocalArgumentVector blockDim_x;
			ThreadLocalArgumentVector blockDim_y;
			ThreadLocalArgumentVector blockDim_z;
			
			ThreadLocalArgumentVector blockId_x;
			ThreadLocalArgumentVector blockId_y;
			ThreadLocalArgumentVector blockId_z;
			
			ThreadLocalArgumentVector gridDim_x;
			ThreadLocalArgumentVector gridDim_y;
			ThreadLocalArgumentVector gridDim_z;
			
			ThreadLocalArgumentVector localPointer;
			ThreadLocalArgumentVector sharedPointer;
			ThreadLocalArgumentVector constantPointer;
			ThreadLocalArgumentVector parameterPointer;
			ThreadLocalArgumentVector argumentPointer;
			ThreadLocalArgumentVector metadataPointer;
		};

		/*!
			\brief contains replicated and/or vectorized instructions
		*/
		class VectorizedInstruction {
		public:
			VectorizedInstruction(): vector(0) { }

			bool isVectorizable() const;
			
			void vectorize(llvm::Instruction *scalarInst, llvm::Instruction *before);
		
		private:
			

		public:

			//! \brief replicated form of instruction
			InstructionVector replicated;

			//! \brief vectorized form of instruction
			llvm::Instruction *vector;
		};
		typedef std::map< llvm::Instruction *, VectorizedInstruction > VectorizedInstructionMap;
		
		/*!
			\brief per-function data structures related to the transformation
		*/
		class Translation {
		public:
			Translation(llvm::Function *f, LLVMUniformVectorization *pass);
			~Translation();
			
			/*!
				\brief entry point to pass
			*/
			void runOnFunction();

		protected:
		
			/*! \brief given an instruction from the scalar set, get a set of scalar values that are 
				either replicated scalar instructions from the vectorized set or extracted vector elements */
			InstructionVector getInstructionAsReplicated(llvm::Value *inst, llvm::Instruction *before=0);

			/*! \brief given an instruction from the scalar set, get a vector from the vectorized set that
				is either a promoted-to-vector instruction or a set of scalar values packed into a vector*/
			llvm::Instruction *getInstructionAsVectorized(llvm::Value *inst, llvm::Instruction *before=0);
			
		protected:
		
			//! \brief references function being transformed
			llvm::Function *function;
			
			//! \brief maps
			VectorizedInstructionMap vectorizedInstructionMap;
		
		};
	
	public:
	
		/*!
			\brief vectorizes kernels assuming all control flow is uniform across warps

			\param warpSize number of logical threads per warp
		*/
		LLVMUniformVectorization(KernelGraph *_kernelGraph, int warpSize = 1);
		~LLVMUniformVectorization();

	public:
	
		virtual bool doInitialize(llvm::Module &M);

		//! \brief entry point for pass
		virtual bool runOnFunction(llvm::Function &F);

		//! \brief gets the name of the pass
		virtual const char *getPassName() const;

		//! \brief gets the kind of tye pass
		virtual llvm::PassKind getPassKind() const;

	public:
		llvm::IntegerType *getTyInt(int n) const;
	
		llvm::ConstantInt *getConstInt32(int n) const;
		llvm::ConstantInt *getConstInt16(short n) const;

	public:
		//! pointer to module 
		const llvm::Module *M;
		
		//! references the KernelGraph being translated
		KernelGraph *kernelGraph;

		//! \brief number of consecutive threads to pack into a single hardware thread
		int warpSize;

		static char ID;
	};
}

#endif

