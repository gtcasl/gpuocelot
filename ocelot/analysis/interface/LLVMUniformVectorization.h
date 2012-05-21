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
	/*
		\brief Performs vectorization and completes subkernel transformations
	*/
	class LLVMUniformVectorization: public llvm::FunctionPass {
	public:
		typedef std::set< llvm::Value * > ValueSet;
		typedef std::set< const llvm::Value * > ConstValueSet;
		typedef std::vector< llvm::Value *> ValueVector;
		typedef std::vector< llvm::Instruction *> InstructionVector;
		typedef std::set< llvm::Instruction * > InstructionSet;
		typedef analysis::KernelPartitioningPass::SubkernelId SubkernelId;
		typedef analysis::KernelPartitioningPass::Subkernel Subkernel;
		typedef analysis::KernelPartitioningPass::KernelGraph KernelGraph;
		typedef std::map< llvm::BasicBlock *, ir::BasicBlock::Pointer > LLVMtoOcelotBlockMap;
		typedef std::unordered_map< ir::BasicBlock::Pointer, llvm::BasicBlock * > OcelotToLLVMBlockMap;
		typedef std::map< SubkernelId, llvm::BasicBlock *> EntryMap;
		
		enum ThreadInvariantOptimizations {
			ThreadInvariant_scalarization = 1,
			ThreadInvariant_affineMemory = 2,
			ThreadInvariant_sameCta = 4,
			ThreadInvariant_consecutiveTids = 8,
		};

		//! \brief usage of a thread-local parameter (either thread ID or local memory ptr)
		class ThreadLocalArgument {
		public:
		
			llvm::Value * context;
		
			llvm::Instruction * threadId_x;		// always thread-local
			llvm::Instruction * threadId_y;		// always thread-local
			llvm::Instruction * threadId_z;		// always thread-local
			
			llvm::Instruction * blockDim_x;
			llvm::Instruction * blockDim_y;
			llvm::Instruction * blockDim_z;
			
			llvm::Instruction * blockId_x;
			llvm::Instruction * blockId_y;
			llvm::Instruction * blockId_z;
			
			llvm::Instruction * gridDim_x;
			llvm::Instruction * gridDim_y;
			llvm::Instruction * gridDim_z;
			
			llvm::Instruction * localPointer;		// always thread-local
			llvm::Instruction * sharedPointer;
			llvm::Instruction * constantPointer;
			llvm::Instruction * parameterPointer;		// always thread-local
			llvm::Instruction * argumentPointer;
			llvm::Instruction * globallyScopedLocal;		// always thread-local
			llvm::Instruction * externalSharedSize;
			llvm::Instruction * metadataPointer;
			
			llvm::Instruction *ptrThreadDescriptorArray;
			
			InstructionVector declarations;
			
			unsigned int threadIdUses;
		};
		typedef llvm::Instruction * ThreadLocalArgument::* ThreadLocalArgumentMemberPointer;
		typedef std::vector< ThreadLocalArgument > ThreadLocalArgumentVector;

		//! \brief pointer-to-member table for additional indrection on thread-local arguments
		static llvm::Instruction * analysis::LLVMUniformVectorization::ThreadLocalArgument::* 
			ThreadLocalArgumentInstances[];

		//! \brief pointer to pointer-to-member table offset so first element is localPointer
		static llvm::Instruction * analysis::LLVMUniformVectorization::ThreadLocalArgument::* 
			*ThreadLocalArgumentPointerInstances;
	
		//! \brief table indicating which pointer-to-members are thread-invariant if from same CTA
		static bool ThreadLocalArgumentVarianceMap[];

		//! \brief pointer to table offset so first element corresponds to localPointer
		static bool *ThreadLocalArgumentPointerVarianceMap;
		
		/*!
			\brief contains replicated and/or vectorized instructions
		*/
		class VectorizedInstruction {
		public:
			
			enum Flags {
				Thread_variant,
				Thread_invariant,
				Thread_affine,
				Flags_invalid
			};
			
		public:
		
			//!
			VectorizedInstruction(): vector(0), flags(Thread_variant) { }

			//! indicates value type can be inserted into a vector
			bool isPackable() const;

			//! indicates instructon may be replace with a vector equivalent
			bool isVectorizable() const;

		public:

			//! \brief replicated form of instruction
			InstructionVector replicated;

			//! \brief vectorized form of instruction
			llvm::Instruction *vector;
			
			//! \brief provides additional attributes related to vectorization
			Flags flags;
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
			\brief counter structure determining vectorization statistics
		*/
		class VectorizationStatistics {
		public:
			class Counter {
			public:
				Counter(): encountered(0), total(0) { }
				void clear() { encountered = total = 0; }
				void count(int enc) { ++total; encountered += enc; }
				void encounter() { ++encountered; ++total; }
				void notCounted() { ++total; }
				double fraction() const { return (double)encountered / (double)total; }
				void write(std::ostream &out) const;
			public:
				size_t encountered;
				size_t total;
			};
			
			void clear() {
				integerInstructions.clear();
				floatInstructions.clear();
				callInstructions.clear();
				storeInstructions.clear();
				loadInstructions.clear();
			}
			
			void write(std::ostream &out) const;
			void count(VectorizedInstruction &vec);
			
		public:
			Counter integerInstructions;
			Counter floatInstructions;
			Counter callInstructions;
			Counter storeInstructions;
			Counter loadInstructions;
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
			void _eliminateUselessExits();
			void _scalarOptimization();
			
			void _basicBlockPasses();
			void _eliminateBitcasts(llvm::Function::iterator bb_it);
			void _promoteGempPointerArithmetic(llvm::Function::iterator bb_it);
			void _eraseBlock(llvm::BasicBlock *block);
			void _eliminateEmptyBlocks();
			
			void _loadThreadLocal(ThreadLocalArgument &local, int suffix, 
				llvm::Instruction *before, llvm::BasicBlock *block = 0);
			void _prefetchLocalMemory(llvm::Instruction *localPtr, size_t localSize);
			
			void _initializeSchedulerEntryBlock();
			
			void _completeSchedulerEntryBlock();
			
			void _enumerateEntries();
			
			void _debugReporting();
			
			void _debugControlFlowMatrix();
			
			void _debugInsertStore(llvm::StoreInst *storeInst, llvm::Constant *func, size_t index);
			
			void _debugInsertLoad(llvm::LoadInst *loadInst, llvm::Constant *func, size_t index);
			
			void _computeVectorizationStatistics(VectorizationStatistics &statistics);
			
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
			
			llvm::Instruction *_getVectorizedInsertPoint(const VectorizedInstruction &vec);
			
			llvm::Instruction *_vectorize(VectorizedInstructionMap::iterator &vec_it);
			
			llvm::Instruction * _vectorizeBinaryOperator(llvm::BinaryOperator *inst, 
				VectorizedInstructionMap::iterator &vec_it);
			llvm::Instruction * _vectorizeCall(llvm::CallInst *inst, 
				VectorizedInstructionMap::iterator &vec_it);
			llvm::Instruction * _vectorizeUnvectorizable(llvm::Instruction *inst, 
				VectorizedInstructionMap::iterator &vec_it);			
			llvm::Instruction * _vectorizeFPIntConversion(llvm::Instruction *inst, 
				VectorizedInstructionMap::iterator &vec_it);
			
			void _finalizeTranslation();
			
			void _eliminateUnusedVectorPacking();
			
			
			void _affineMemoryAccesses();
			
			bool _isAffineValue(InstructionSet &affineSet, llvm::Instruction *ptr);
			
			llvm::Instruction * _vectorizeAffineMemory(llvm::Instruction *inst, 
				VectorizedInstructionMap::iterator &vec_it);
		
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

			\param kernelGraph partitionined PTX kernel
			\param subkernelId ID of subkernel
			\param warpSize number of logical threads per warp
			\param vectorize if true, enables vectorizing replicated instructions where possible
			\param threadInvariant controls flags related to scalarizing thread-invariant expressions 
				and affine operators
			\param affineMemory if true, and if (threadInvariant & (scalarization | sameCta)), 
				vectorizes affine memory accesses where possible
		*/
		LLVMUniformVectorization(
			KernelGraph *kernelGraph, 
			SubkernelId subkernelId, 
			int warpSize = 1, 
			bool vectorize = true, 
			int threadInvariant = (ThreadInvariant_scalarization | ThreadInvariant_sameCta ), 
			bool affineMemory = false);
		
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
		
		//! \brief flags for performing thread-invariant optimization
		int threadInvariant;
		
		//! \brief controls whether to attempt vectorizing affine memory operations
		bool vectorizeAffineMemory;
		
		//! 
		static char ID;
	};
}

#endif

