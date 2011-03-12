/*! 
	\file HyperblockFormationPass.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date March 2011
	\brief Defines a hyperblock formation pass for convergent execution
*/

#ifndef HYPERBLOCK_FORMATION_PASS_H_INCLUDED
#define HYPERBLOCK_FORMATION_PASS_H_INCLUDED

// Ocelot Includes
#include <ocelot/analysis/interface/Pass.h>
#include <ocelot/ir/interface/ControlFlowGraph.h>
#include <ocelot/ir/interface/PTXKernel.h>

// Standard Library Includes
#include <vector>
#include <unordered_set>
#include <unordered_map>

// Forward Declarations

namespace analysis {

	/*!
		\brief extracts hyperblocks from a PTX kernel
	*/
	class HyperblockFormationPass: public ModulePass {
	public:
		typedef std::vector<ir::PTXKernel*> KernelVector;
		
		/*!
		
		*/		
		class ExtractHyperblocksPass : public KernelPass {
		public:
			typedef std::unordered_map<ir::PTXKernel*, KernelVector> KernelVectorMap;
				
		public:
			ExtractHyperblocksPass();
			
			void initialize(const ir::Module& m);
			void runOnKernel(ir::Kernel& k);
			void finalize();
			
		private:
		
			//! \brief creates a spill region in the first block
			void _createSpillRegion(
				ir::PTXKernel &subkernel, 
				ir::PTXKernel &parentKernel, 
				ir::BasicBlock &restoreBlock);
			
			//! \brief restores live variables 
			size_t _createRestore(
				ir::PTXKernel &hyperblock,
				ir::PTXKernel &parentKernel,
				ir::BasicBlock &restoreBlock,
				DataflowGraph::IteratorMap::const_iterator dfgBlock);
				
			//! \brief stores live variables to local memory
			size_t _createStore(
				ir::PTXKernel &hyperblock,
				ir::PTXKernel &parentKernel,
				ir::BasicBlock &exitBlock,
				DataflowGraph::IteratorMap::const_iterator dfgBlock);
				
			//! \brief writes the exit point 
			size_t _createHyperblockExit(
				ir::PTXKernel &hyperblock,
				ir::PTXKernel &parentKernel,
				const ir::BasicBlock &parentBlock,
				ir::BasicBlock &clonedBlock,
				ir::BasicBlock &exitBlock);
			
		public:
			KernelVectorMap kernels;
		
		private:
			unsigned int _expectedRegionSize;
		};
			
	public:
	
		HyperblockFormationPass();
		void runOnModule(ir::Module& m);
		
	};
}

#endif

