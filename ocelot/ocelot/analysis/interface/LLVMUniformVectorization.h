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

namespace analysis
{

	/*!
		\brief pass applied to kernels with completely uniform control flow for warps of a given
			size
	*/
	class LLVMUniformVectorization: public llvm::FunctionPass {
	public:
		typedef std::list< llvm::BasicBlock *> BasicBlockList;
		typedef std::map< llvm::Value *, std::vector< llvm::Instruction *> > WarpInstructionMap;
		typedef std::map< llvm::BasicBlock *, llvm::BasicBlock *> BasicBlockMap;

		/*!
			\brief object storing intermediate results needed by the translation
		*/
		class Translation {
		public:
			Translation(llvm::Function *f): F(f) { }
			~Translation();
		
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
				\brief maps cloned getelementptr instruction obtaining ptr to tidx to its warp-sync thread ID
			*/
			std::map< llvm::Instruction *, int > threadIdxMap;
		};

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
			\brief given a cloned instruction, update data dependencies to correspond to
				cloned instructions from previous blocks
		*/
		void updateDependencies(Translation &translation, llvm::Instruction *instr, int tid);
		
		void updateThreadIdxUses(Translation &translation);
		
		/*!
			\brief replace dummy terminators in warp-synchronous block structure with
				tests for warp-synchronous behavior and either branches to successor blocks
				or returns to Ocelot multicore runtime
		*/
		void resolveControlFlow(Translation &translation);
		
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
	};

}

#endif

