/*!
	\file LLVMUniformVectorization.h
	\author Andrew Kerr <arkerr@gatech.edu>
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
}

namespace analysis
{

	/*!
		\brief pass applied to kernels with completely uniform control flow for warps of a given
			size
	*/
	class LLVMUniformVectorization: public llvm::FunctionPass {
	public:
		typedef std::vector< llvm::Instruction *> InstructionVector;

		//! \brief usage of a thread-local parameter (either thread ID or local memory ptr)
		class ThreadLocalArgument {
		public:
			typedef std::vector< llvm::LoadInst *> ThreadLocalArgumentVector;
		public:
		
			llvm::Instruction *ptrThreadDescriptorArray;
		
			ThreadLocalArgumentVector localPointer;
			ThreadLocalArgumentVector parameterPointer;
			ThreadLocalArgumentVector threadId_x;
			ThreadLocalArgumentVector threadId_y;
			ThreadLocalArgumentVector threadId_z;
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

		typedef std::list< llvm::BasicBlock *> BasicBlockList;
		typedef std::map< llvm::Value *, VectorizedInstruction > WarpInstructionMap;
		typedef std::map< llvm::BasicBlock *, llvm::BasicBlock *> BasicBlockMap;

		/*!
			\brief data structure associated with a divergent branch
		*/
		class DivergentBranch {
		public:
			DivergentBranch();
			DivergentBranch(llvm::BasicBlock *scBlock, llvm::BasicBlock *wsBlock);
			
		public:
			/*!
				\brief basic block in scalar function terminated by divergent branch
			*/
			llvm::BasicBlock *scalarBlock;
			
			/*!
				\brief basic block in warp-synchronous phase whose terminator must be modified
			*/
			llvm::BasicBlock *warpBlock;
		
			/*!
				\brief basic block handling the event of a dynamic divergent branch
			*/
			llvm::BasicBlock *handler;
			
			/*!
				
			*/
		};
		
		typedef std::map< llvm::BasicBlock *, DivergentBranch > DivergentBranchMap;

		/*!
			\brief warp scheduler block
		*/
		class WarpScheduler {
		public:
			WarpScheduler();
			
		public:
		
			//! \brief start of region
			llvm::BasicBlock *start;
			
			//! \brief end of region
			llvm::BasicBlock *end;
		};
		
		typedef std::map< llvm::BasicBlock *, WarpScheduler > WarpSchedulerMap;
		
		//! \brief 
		class SubkernelEntry {
		public:
		
			//! \brief new entry block inserted by pass
			llvm::BasicBlock *prologue;
			
			//! \brief previous entry block
			llvm::BasicBlock *start;
		};

		/*!
			\brief object storing intermediate results needed by the translation
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
			
			//! \brief gets a warp-synchronous block from a scalar block
			llvm::BasicBlock * getWarpBlockFromScalar(llvm::BasicBlock *scalarBlock);
			
			//! \brief gets a scalar block corresponding to a warp-synchronous block
			llvm::BasicBlock * getScalarBlockFromWarp(llvm::BasicBlock *warpBlock);
		
			/*! \brief given an instruction from the scalar set, get a set of scalar values that are 
				either replicated scalar instructions from the vectorized set or extracted vector elements */
			InstructionVector getInstructionAsReplicated(llvm::Value *inst, llvm::Instruction *before=0);

			/*! \brief given an instruction from the scalar set, get a vector from the vectorized set that
				is either a promoted-to-vector instruction or a set of scalar values packed into a vector*/
			llvm::Instruction *getInstructionAsVectorized(llvm::Value *inst, llvm::Instruction *before=0);
			
			/*! 
				
			*/
			llvm::Value * getLocalMemorySize(llvm::Instruction *insertBefore);
			
			/*! 
				\brief gets a pointer to local memory
			*/
			llvm::Value * getLocalMemoryPointer(llvm::Instruction *insertBefore);

		protected:
		
			/*!
			
			*/
			void createSubkernelPrologue();
			
			/*!
			
			*/
			void finalizeSubkernel();
		
			/*!
				\brief visit an instruction and either promotes to vector, or packs results into a vector
			*/
			void vectorize(llvm::Instruction *inst);
		
			/*!
				\brief fetches metadata object and obtains thread local arguments
					(i.e. localMemory pointer, threadIdx.x)
			*/
			void loadThreadLocalArguments();
		
			/*!

				\brief performs breadth-first traversal of blocks in function F constructing a
					list of blocks visited
			*/
			void breadthFirstTraversal(BasicBlockList & traversal, llvm::Function *F);
		
			/*!
				\brief visits every instruction in the scalar phase and inserts a set of cloned
					instructions in the parallel warp-synchronous block structure
			*/
			void addInterleavedInstructions();
		
			/*!

				\brief visits all cloned instructions and resolves dependencies
			*/
			void resolveDependencies();
		
			/*!

				\brief given a cloned instruction, update data dependencies to correspond to

					cloned instructions from previous blocks
			*/
			void updateDependencies(llvm::Instruction *instr, int tid);
		
			/*!
				\brief updates users of threadIdx and localMemPtr
			*/
			void updateThreadLocalUses();
				
			/*!
				\brief replace dummy terminators in warp-synchronous block structure with
					tests for warp-synchronous behavior and either branches to successor blocks
					or returns to Ocelot multicore runtime
			*/
			void resolveControlFlow();
		
			/*!
				\brief visits each of the warp scheduler blocks and changes control flow to point
					to warp-synchronous regions

			*/
			void updateSchedulerBlocks();
		
			/*!
				\brief deals with a particular divergent branch

			*/
			void handleDivergentBranch(DivergentBranch &divergent);
		
			/*!
				\brief emit spill code or handler for a branch known to be divergent

			*/
			void divergenceHandlerBranch(DivergentBranch &divergent);
		
			/*!
				\brief inserts a schedular block that handles control flow

			*/
			void createSchedulerBlock();
		
			/*!
				\brief 
			*/
			void debugInsertCFGTraces();
		
			/*!
				\brief prints a .dot file of the function's control flow graph - no instrucitons, just bb labels
			*/
			void debugEmitCFG();
		
			/*!
				\brief this could probably be implemented as a second function pass, but examine
					collections of instructions of size <warpSize>, hoist or sink instructions, and
					make into vectors for vector processing
			*/
			void vectorize();
			
			
			void vectorizeBinaryOperator(
				llvm::BinaryOperator *, 
				VectorizedInstruction &vecInstr, 
				llvm::Instruction *before);
			void vectorizeCall(
				llvm::CallInst *, 
				VectorizedInstruction &vecInstr, 
				llvm::Instruction *before);
			void vectorizePhiNode(
				llvm::PHINode *, 
				VectorizedInstruction &vecInstr, 
				llvm::Instruction *before);
			
			/*!
				\brief visits subkernel exits and assigns exit descriptors
			*/
			void updateSubkernelExits();
		
		public:
		
			/*!
				\brief
			*/
			const LLVMUniformVectorization *pass;
		
			/*!
				\brief pointer to LLVM function
			*/
			llvm::Function *F;
			
			/*!
			
			*/
			int warpSize;
			
		public:
		
			/*!
				\brief traverses scalar blocks breadth-first
			*/
			BasicBlockList traversal;
		
			/*! \brief maps instructions from scalar phase onto vectors of instructions in warp
				synchronous phase
			*/
			WarpInstructionMap warpInstructionMap;
			
			/*!
				\brief maps scalar blocks onto warp-synchronous blocks
			*/
			BasicBlockMap warpBlocksMap;
			
			/*!
				\brief maps a warp-synchronous divergent branching block onto a data structure
					for handling divergence
			*/
			DivergentBranchMap divergingBranchMap;
			
			/*!
				\brief subkernel entry
			*/
			SubkernelEntry subkernelEntry;
			
			/*!
				\brief indirect jumps based on warp id and last divergent branch handled by this block
			*/
			llvm::BasicBlock *schedulerBlock;
			
			/*!
				\brief maps basic blocks to warp scheduler blocks
			*/
			WarpSchedulerMap warpSchedulerBlocks;
			
			/*!
				\brief pointer to array of thread descriptors indexed by tid
			*/
			llvm::GetElementPtrInst *gempThreadDescPtr;
			
			/*!
				\brief loaded values at beginning of subkernel
			*/
			ThreadLocalArgument threadLocalArguments;
		};

	public:
		/*!
			\brief vectorizes kernels assuming all control flow is uniform across warps

			\param warpSize number of logical threads per warp
		*/
		LLVMUniformVectorization(int warpSize = LLVM_UNIFORMCONTROL_WARPSIZE);
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
		const llvm::IntegerType *getTyInt(int n) const;
	
		llvm::ConstantInt *getConstInt32(int n) const;
		llvm::ConstantInt *getConstInt16(short n) const;

	public:
		//! pointer to module 
		const llvm::Module *M;

		//! \brief number of consecutive threads to pack into a single hardware thread
		int warpSize;
		
		//! \brief (int,int,int)
		llvm::Type *tyDimension;
		
		//! \brief type of Metadata object
		llvm::Type *tyMetadata;
		
		//! \brief type of ThreadDescriptor
		llvm::Type *tyThreadDescriptor;

		static char ID;
	};

}

#endif

