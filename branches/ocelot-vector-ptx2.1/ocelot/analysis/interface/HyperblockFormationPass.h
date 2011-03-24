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
#include <set>

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
		typedef std::vector< unsigned int> OffsetVector;
		typedef std::unordered_set< analysis::DataflowGraph::Register > RegisterSet;
		
		//! \brief indicates reason for thread exit
		enum ThreadExitCode {
			Thread_fallthrough = 0,
			Thread_branch = 1,
			Thread_tailcall = 3,
			Thread_call = 4,
			Thread_barrier = 5,
			Thread_exit = 6,
			Thread_exit_other = 7,
			ThreadExitCode_invalid
		};
		static std::string toString(const ThreadExitCode &code);
		
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
				
				std::string label;
			
				//! \brief references the external source or target hyperblock
				HyperblockId externalHyperblock;
				
				//! \brief set of live values flowing along an edge
				analysis::DataflowGraph::RegisterSet liveValues;
			};
			typedef std::vector< Edge > EdgeVector;
			
		public:
		
			//! \brief computes a set of all registers that are generated or used by the subkernel
			void computeLiveValues(RegisterSet &generated, RegisterSet &used);
		
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
	
		void _partitionAtBarrier(ir::PTXKernel &parentKernel);
		
		void _determineRegisterUses(
			RegisterSet &produced, 
			RegisterSet &used, 
			ir::PTXKernel &subkernel);
	
		//! \brief creates a spill region in the first block
		void _createSpillRegion(
			ir::PTXKernel &subkernel, 
			ir::PTXKernel &parentKernel,
			size_t spillSize);
		
		//! \brief restores live variables 
		size_t _createRestore(
			ir::PTXKernel &hyperblock,
			const RegisterSet &liveValues,
			OffsetVector &offsets);
			
		//! \brief stores live variables to local memory
		size_t _createStore(
			ir::PTXKernel &hyperblock,
			const RegisterSet &liveValues,
			OffsetVector &offsets);
			
		//! \brief writes the exit point 
		size_t _createHyperblockExit(
			Hyperblock &hyperblock);
			
		void _createExit(
			Hyperblock &hyperblock, 
			ir::BasicBlock::Pointer exitBlock, 
			const ir::PTXOperand &resumePoint,
			unsigned int exitCode);
			
		void _createExit(
			Hyperblock &hyperblock, 
			ir::BasicBlock::Pointer exitBlock,
			unsigned int exitCode);
	};
}

#endif

