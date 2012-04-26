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
	class LoadInst;
	class StoreInst;
}

namespace analysis
{

	class LLVMUniformVectorization: public llvm::FunctionPass {
	public:
		typedef std::set< llvm::Value * > ValueSet;
		typedef std::set< const llvm::Value * > ConstValueSet;
		typedef std::vector< llvm::Value *> ValueVector;
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
			
			llvm::Instruction *ptrThreadDescriptorArray;
		};
		typedef std::vector< ThreadLocalArgument > ThreadLocalArgumentVector;

		/*!
			\brief contains replicated and/or vectorized instructions
		*/
		class VectorizedInstruction {
		public:
			VectorizedInstruction(): vector(0) { }

			bool isPackable() const;

			bool isVectorizable() const;

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
			\brief set of expressions for which each thread in a warp's value is equal to:
				base-value + offset + constant * (tid - base-tid)
		*/
		class AffineValue {
		public:
			AffineValue();
			AffineValue(llvm::Value *_base, llvm::Constant *offset = 0, llvm::Constant *_constant = 0);
		
			//! \brief true if value is thread-invariant across CTA
			bool invariant() const;
		
		public:
			llvm::Value *base;
			
			llvm::Constant *offset;
			
			llvm::Constant *constant;
		};
		
		//! \brief maps
		typedef std::map< llvm::Value *, AffineValue > AffineValueMap;
		
		//! \brief computes set of instructions that are affine
		class AffineVarianceAnalysis {
		public:
		
			AffineVarianceAnalysis(llvm::Function *function, 
				const ThreadLocalArgumentVector &threadLocalArguments);
			~AffineVarianceAnalysis();
			
		protected:
		
			void _enumerateInvariants();
						
			void _compute();
			
		protected:
		
			llvm::Function *function;
			
			const ThreadLocalArgumentVector & threadLocal;
		
		public:
		
			ConstValueSet invariantSet;
			
			ValueSet threadId;
			
			AffineValueMap affineValues;
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
			llvm::ConstantInt *getConstInt64(size_t n) const;
		
		protected:
		
			void _computeLLVMToOcelotBlockMap();
			
			void _scalarPreprocess();
			
			void _propagateConstants();
			void _hoistDeclarationBlocks();
			void _scalarOptimization();
			
			void _basicBlockPasses();
			void _eliminateBitcasts(llvm::Function::iterator bb_it);
			void _promoteGempPointerArithmetic(llvm::Function::iterator bb_it);
			void _eraseBlock(llvm::BasicBlock *block);
			void _eliminateEmptyBlocks();
			
			void _loadThreadLocal(ThreadLocalArgument &local, int suffix, 
				llvm::Instruction *before, llvm::BasicBlock *block = 0);
			
			void _initializeSchedulerEntryBlock();
			
			void _completeSchedulerEntryBlock();
			
			void _enumerateEntries();
			
			void _debugReporting();
			
			void _debugControlFlowMatrix();
			
			void _debugInsertStore(llvm::StoreInst *storeInst, llvm::Constant *func, size_t index);
			
			void _debugInsertLoad(llvm::LoadInst *loadInst, llvm::Constant *func, size_t index);
			
		protected:
		
			void _transformWarpSynchronous();
			
			void _identifyScheduler();
			
			void _replicateInstructions();
			
			void _packThreadLocal();
			
			void _replicateInstruction(llvm::Instruction *inst);
			
			void _resolveDependencies();
			
			void _updateDependency( );
			
			void _removeScalar();
			
			void _divergenceHandling();
			
			void _updateDivergentBlock(
				const analysis::KernelPartitioningPass::DivergentBranch &divergence, 
				const analysis::KernelPartitioningPass::ExternalEdge &outEdge);
			
			void _vectorizeReplicated();
			
			llvm::Instruction *_vectorize(VectorizedInstructionMap::iterator &vec_it);
			
			llvm::Instruction * _vectorizeBinaryOperator(llvm::BinaryOperator *inst, 
				VectorizedInstructionMap::iterator &vec_it);
			llvm::Instruction * _vectorizeCall(llvm::CallInst *inst, 
				VectorizedInstructionMap::iterator &vec_it);
			llvm::Instruction * _vectorizeUnvectorizable(llvm::Instruction *inst, 
				VectorizedInstructionMap::iterator &vec_it);
			
			void _finalizeTranslation();
			
			void _eliminateUnusedVectorPacking();
		
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
		LLVMUniformVectorization(KernelGraph *_kernelGraph, SubkernelId subkernelId, int warpSize = 1, bool vectorize = true);
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
		//llvm::IntegerType *getTyInt(int n) const;
	
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
		
		//! \brief controls whether subkernel is vectorized when warpSize > 1
		bool vectorizeConvergent;

		static char ID;
	};
}

#endif

