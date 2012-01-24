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
		typedef analysis::KernelPartitioningPass::SubkernelId SubkernelId;
		typedef analysis::KernelPartitioningPass::Subkernel Subkernel;
		typedef analysis::KernelPartitioningPass::KernelGraph KernelGraph;
		typedef std::map< llvm::BasicBlock *, ir::BasicBlock::Pointer > LLVMtoOcelotBlockMap;
		typedef std::unordered_map< ir::BasicBlock::Pointer, llvm::BasicBlock * > OcelotToLLVMBlockMap;
		typedef std::map< SubkernelId, llvm::BasicBlock *> EntryMap;

		//! \brief usage of a thread-local parameter (either thread ID or local memory ptr)
		class ThreadLocalArgument {
		public:
		
			llvm::Instruction *ptrThreadDescriptorArray;
			
			llvm::Value * context;
		
			llvm::Instruction * threadId_x;
			llvm::Instruction * threadId_y;
			llvm::Instruction * threadId_z;
			
			llvm::Instruction * blockDim_x;
			llvm::Instruction * blockDim_y;
			llvm::Instruction * blockDim_z;
			
			llvm::Instruction * blockId_x;
			llvm::Instruction * blockId_y;
			llvm::Instruction * blockId_z;
			
			llvm::Instruction * gridDim_x;
			llvm::Instruction * gridDim_y;
			llvm::Instruction * gridDim_z;
			
			llvm::Instruction * localPointer;
			llvm::Instruction * sharedPointer;
			llvm::Instruction * constantPointer;
			llvm::Instruction * parameterPointer;
			llvm::Instruction * argumentPointer;
			llvm::Instruction * globallyScopedLocal;
			llvm::Instruction * externalSharedSize;
			llvm::Instruction * metadataPointer;
		};
		typedef std::vector< ThreadLocalArgument > ThreadLocalArgumentVector;

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
		
		//! \brief scheduler block
		class SchedulerBlock {
		public:
			//! \brief data structure maps entry Ids to entry blocks
			EntryMap entries;
			
			//! \brief actual bloock
			llvm::BasicBlock *block;
			
			//! \brief actual default entry
			llvm::BasicBlock *defaultEntry;
			
			//! \brief
			ThreadLocalArgumentVector threadLocalArguments;
		};
		
		/*!
			\brief per-function data structures related to the transformation
		*/
		class Translation {
		public:
			Translation(llvm::Function *f, Subkernel *subkernel, LLVMUniformVectorization *pass);
			~Translation();

		protected:
		
			/*! \brief given an instruction from the scalar set, get a set of scalar values that are 
				either replicated scalar instructions from the vectorized set or extracted vector elements */
			InstructionVector getInstructionAsReplicated(llvm::Value *inst, llvm::Instruction *before=0);

			/*! \brief given an instruction from the scalar set, get a vector from the vectorized set that
				is either a promoted-to-vector instruction or a set of scalar values packed into a vector*/
			llvm::Instruction *getInstructionAsVectorized(llvm::Value *inst, llvm::Instruction *before=0);
		
		protected:	
			llvm::LLVMContext & context() const;
			llvm::IntegerType *getTyInt(int n) const;
			llvm::ConstantInt *getConstInt32(int n) const;
			llvm::ConstantInt *getConstInt16(short n) const;
		
		protected:
		
			void _computeLLVMToOcelotBlockMap();
			
			void _scalarPreprocess();
			
			void _loadThreadLocal(ThreadLocalArgument &local, int suffix, llvm::BasicBlock *block);
			
			void _initializeSchedulerEntryBlock();
			
			void _completeSchedulerEntryBlock();
			
			void _enumerateEntries();
			
		protected:
		
			void _transformWarpSynchronous();
			
			void _replicateInstructions();
			
			void _resolveDependencies();
			
			void _vectorizeReplicated();
			
			void _finalizeTranslation();
		
		protected:
			
			
		protected:
		
			//! \brief references function being transformed
			llvm::Function *function;
			
			//! \brief corresponding subkernel
			Subkernel *subkernel;
			
			LLVMUniformVectorization *pass;
			
			//! \brief maps LLVM blocks to identically named Ocelot blocks from the source kernel
			LLVMtoOcelotBlockMap llvmToOcelotBlockMap;
			
			//! \brief maps Ocelot blocks to LLVM blocks (inverse of llvmToOcelotBlockmap)
			OcelotToLLVMBlockMap ocelotToLlvmBlockMap;
			
			//! \brief maps
			VectorizedInstructionMap vectorizedInstructionMap;
				
			//! \brief
			SchedulerBlock schedulerEntryBlock;
		};
	
	public:
	
		/*!
			\brief vectorizes kernels assuming all control flow is uniform across warps

			\param warpSize number of logical threads per warp
		*/
		LLVMUniformVectorization(KernelGraph *_kernelGraph, SubkernelId subkernelId, int warpSize = 1);
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

		llvm::LLVMContext & context() const;
		
	public:
		//! pointer to module 
		const llvm::Module *M;
		
		//! references the KernelGraph being translated
		KernelGraph *kernelGraph;
		
		//! 
		SubkernelId subkernelId;

		//! \brief number of consecutive threads to pack into a single hardware thread
		int warpSize;

		static char ID;
	};
}

#endif

