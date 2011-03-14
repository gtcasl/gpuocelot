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
	class HyperblockFormation: public ModulePass {
	public:
		typedef std::vector<ir::PTXKernel*> KernelVector;
		typedef unsigned int HyperblockId;
		
		class Hyperblock {
		public:
		
			//! \brief stores subkernel backing hyperblock
			ir::PTXKernel *subkernel;
			
			//! \brief kernel-wide unique identifier assigned to hyperblock
			HyperblockId hyperblockId;
			
			//! \brief identifies the label of the entry block
			std::string entryBlock;
		};
		
		/*!
			\brief stores information describing kernel decomposition
		*/
		class KernelDecomposition {
		public:
			typedef std::unordered_map< std::string, HyperblockId> HyperblockEntryMap;
			typedef std::unordered_map< HyperblockId, Hyperblock > HyperblockMap;
			
		public:
		
			//! \brief reference to parent kernel
			const ir::PTXKernel *parent;
		
			//! \brief set of hyperblocks forming a kernel
			HyperblockMap hyperblocks;
			
			//! \brief identifies 
			HyperblockEntryMap hyperblockEntries;
			
			//! \brief identifies first hyperblock of subkernel
			HyperblockId entry;
		};
	public:

		HyperblockFormation();
		
		void initialize(const ir::Module& m);
		void runOnKernel(KernelDecomposition &decomposition, ir::Kernel& parent, HyperblockId baseId = 0);
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
	};
}

#endif

