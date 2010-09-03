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
#define LLVM_UNIFORMCONTROL_WARPSIZE 4

namespace analysis
{

	/*!
		\brief pass applied to kernels with completely uniform control flow for warps of a given
			size
	*/
	class LLVMUniformVectorization: public llvm::FunctionPass {
	public:
		typedef std::vector< llvm::Instruction *> InstructionVector;

		/*!
			\brief contains replicated and/or vectorized instructions
		*/
		class VectorizedInstruction {
		public:
			VectorizedInstruction(): vector(0) { }

			bool isVectorizable() const;

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

		/*!
			\brief object storing intermediate results needed by the translation
		*/
		class Translation {
		public:
			Translation(llvm::Function *f, int ws=LLVM_UNIFORMCONTROL_WARPSIZE): F(f), warpSize(ws) { }
			~Translation();
			
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
				\brief visit an instruction and either promotes to vector, or packs results into a vector
			*/
			void vectorize(llvm::Instruction *inst);
		
		public:
		
			/*!
				\brief pointer to LLVM function
			*/
			llvm::Function *F;
		
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
				\brief maps cloned getelementptr instruction obtaining ptr to tidx to its warp-sync thread ID
			*/
			std::map< llvm::Instruction *, int > threadIdxMap;

			/*!
				\brief maps cloned getelementptr instruction obtaining ptr to localMem to its warp-sync thread ID
			*/
			std::map< llvm::Instruction *, int > localMemPtrMap;
			
			/*!
				\brief indirect jumps based on warp id and last divergent branch handled by this block
			*/
			llvm::BasicBlock *schedulerBlock;
			
			/*!
				\brief maps basic blocks to warp scheduler blocks
			*/
			WarpSchedulerMap warpSchedulerBlocks;
			
			int warpSize;
		};

	public:
		/*!
			\brief vectorizes kernels assuming all control flow is uniform across warps

			\param warpSize number of logical threads per warp
		*/
		LLVMUniformVectorization(int warpSize = LLVM_UNIFORMCONTROL_WARPSIZE);
		~LLVMUniformVectorization();

	public:

		//! \brief entry point for pass
		virtual bool runOnFunction(llvm::Function &F);

		//! \brief gets the name of the pass
		virtual const char *getPassName() const;

		//! \brief gets the kind of tye pass
		virtual llvm::PassKind getPassKind() const;

	public:


	protected:

		/*!
			\brief entry point to pass
		*/
		void addWarpSynchronous(llvm::Function &F);
		
		/*!
			\brief visits every instruction in the scalar phase and inserts a set of cloned
				instructions in the parallel warp-synchronous block structure
		*/
		void addInterleavedInstructions(Translation &translation);
		
		/*!
			\brief visits all cloned instructions and resolves dependencies
		*/
		void resolveDependencies(Translation &translation);
		
		/*!
			\brief given a cloned instruction, update data dependencies to correspond to
				cloned instructions from previous blocks
		*/
		void updateDependencies(Translation &translation, llvm::Instruction *instr, int tid);
		
		/*!
			\brief loaded tidx values are incremented by threadID within warp
		*/
		void updateThreadIdxUses(Translation &translation);

		/*!
			\brief local memory is owned by each thread - compute the thread's actual localMemPointer 
				from its thread ID and LLVMContext::localSize
		*/
		void updateLocalMemAddresses(Translation &translation);
				
		/*!
			\brief replace dummy terminators in warp-synchronous block structure with
				tests for warp-synchronous behavior and either branches to successor blocks
				or returns to Ocelot multicore runtime
		*/
		void resolveControlFlow(Translation &translation);
		
		/*!
			\brief visits each of the warp scheduler blocks and changes control flow to point
				to warp-synchronous regions
		*/
		void updateSchedulerBlocks(Translation &translation);
		
		/*!
			\brief deals with a particular divergent branch
		*/
		void handleDivergentBranch(Translation &translation, DivergentBranch &divergent);
		
		/*!
			\brief emit spill code or handler for a branch known to be divergent
		*/
		void divergenceHandlerBranch(Translation &translation, DivergentBranch &divergent);
		
		/*!
			\brief inserts a schedular block that handles control flow
		*/
		void createSchedulerBlock(Translation &translation);
		
		void debugInsertCFGTraces(Translation &translation);
		
		/*!
			\brief prints a .dot file of the function's control flow graph - no instrucitons, just bb labels
		*/
		void debugEmitCFG(Translation &translation);
		
		/*!
			\brief this could probably be implemented as a second function pass, but examine
				collections of instructions of size <warpSize>, hoist or sink instructions, and
				make into vectors for vector processing
		*/
		void vectorize(Translation &translation);

	protected:

		/*!
			\brief performs breadth-first traversal of blocks in function F constructing a
				list of blocks visited
		*/
		void breadthFirstTraversal(BasicBlockList & traversal, llvm::Function *F);

	public:

		//! \brief number of consecutive threads to pack into a single hardware thread
		int warpSize;

		static char ID;
	};

}

#endif

