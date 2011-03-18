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

// HyperblockFormation::KernelDecomposition::HyperblockMap

namespace analysis {

	/*!
		\brief extracts hyperblocks from a PTX kernel
	*/
	class HyperblockFormation {
	public:
		typedef std::vector<ir::PTXKernel*> KernelVector;
		typedef unsigned int HyperblockId;
		typedef std::map< analysis::DataflowGraph::RegisterId, analysis::DataflowGraph::Register > RegisterMap;
		
		/*!
			\brief 
		*/
		class Hyperblock {
		public:
			/*!
				\brief 
			*/
			class Edge {
			public:	
			
			public:
				//! \brief edge type
				ir::BasicBlock::Edge::Type type;
				
				//! \brief reference to the actual external basic block
				ir::BasicBlock::Pointer externalBlock;
			
				//! \brief references the external source or target hyperblock
				HyperblockId externalHyperblock;
				
				//! \brief set of live values flowing along an edge
				analysis::DataflowGraph::RegisterSet liveValues;
			};
			typedef std::vector< Edge > EdgeVector;
			
		public:
		
			//! \brief stores subkernel backing hyperblock
			ir::PTXKernel *subkernel;
			
			//! \brief kernel-wide unique identifier assigned to hyperblock
			HyperblockId hyperblockId;
			
			//! \brief identifies the label of the entry block
			std::string entryBlock;
			
			// list of incoming edges
			EdgeVector in_edges;
			
			// list of out-going edges
			EdgeVector out_edges;
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
			ir::PTXKernel &parentKernel);
		
		//! \brief restores live variables 
		size_t _createRestore(
			ir::PTXKernel &hyperblock,
			const RegisterMap &liveValues);
			
		//! \brief stores live variables to local memory
		size_t _createStore(
			ir::PTXKernel &hyperblock,
			const RegisterMap &liveValues);
			
		//! \brief writes the exit point 
		size_t _createHyperblockExit(
			Hyperblock &hyperblock);		
	};
}

#endif

