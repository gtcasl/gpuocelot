/*! 
	\file KernelPartitioningPass.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date March 2011
	\brief Defines an arbitrary partitioning pass similar to subkernels
*/

#ifndef ANALYSIS_KERNELPARTITIONINGPASS_H_INCLUDED
#define ANALYSIS_KERNELPARTITIONINGPASS_H_INCLUDED

// Ocelot Includes
#include <ocelot/analysis/interface/Pass.h>
#include <ocelot/ir/interface/ControlFlowGraph.h>
#include <ocelot/ir/interface/PTXKernel.h>

// Standard Library Includes
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <set>

namespace analysis {

	class KernelPartitioningPass {
	public:
		typedef unsigned int EntryId;
		
		typedef std::vector<ir::PTXKernel*> KernelVector;
		typedef std::map< analysis::DataflowGraph::RegisterId, analysis::DataflowGraph::Register > RegisterMap;
		typedef std::vector< unsigned int> OffsetVector;
		typedef std::unordered_set< analysis::DataflowGraph::Register > RegisterSet;
		typedef std::set< ir::BasicBlock::Pointer > BasicBlockSet;
		typedef std::map< EntryId, std::string > EntryIdBlockLabelMap;
		
		//! \brief indicates reason for thread exit
		enum ThreadExitCode {
			Thread_entry = 0,
			Thread_fallthrough = 1,
			Thread_branch = 2,
			Thread_tailcall = 3,
			Thread_call = 4,
			Thread_barrier = 5,
			Thread_exit = 6,
			Thread_exit_other = 7,
			ThreadExitCode_invalid
		};
		static std::string toString(const ThreadExitCode &code);
		
	public:
	
		/*!
			\brief object representing additional control handling
		*/
		class KernelTransitionPoint {			
		public:
		
		public:

			//! \brief every kernel transition gets a unique id, whether entry or exit		
			EntryId id;
			
			//! \brief whether the kernel transition is an entry, an exit at a branch, or exit at barrier
			ThreadExitCode type;
		
			//! \brief values live at the kernel entry or exit point
			RegisterSet liveValues;
			
			//! \brief references the original basic block
			ir::BasicBlock::Pointer block;
			
			//! \brief references a transition handler block for placing spill code
			ir::BasicBlock::Pointer handler;
			
			//! \brief control edge between transition point and block
			ir::ControlFlowGraph::edge_iterator edge;
		};
		typedef std::map< EntryId, KernelTransitionPoint > KernelTransitionPointMap;
		typedef std::map< std::string, std::pair< EntryId, EntryId > > BlockEntryTransitionMap;
	
		/*!
			\brief stores a transformed kernel
		*/
		class KernelDecomposition {
		public:
		
			KernelDecomposition();
			
			void runOnKernel(ir::PTXKernel *kernel, EntryId base = 0);
			
		private:
		
			//! \brief
			void _createSpillRegion(size_t spillSize);
		
			//! \brief 
			void _initializeDecomposition();
		
			//! \brief partitions blocks in parent kernel such that bar.sync is last instruction
			void _partitionBlocksAtBarrier();
		
			//! \brief 
			void _identifyTransitionPoints();
			
			//! \brief inserts spill and restore code into each transition
			void _constructTransition(KernelTransitionPoint &transition);
			
			//! \brief 
			void _transformExitTransitions(KernelTransitionPoint &transition);
			
			//! \brief inserts an exit code into a transition block - assumes it's an exit transition
			void _createExitCode(
				KernelTransitionPoint &transition,
				ThreadExitCode exitCode);
	
			//! \brief inserts an exit code into a transition block - assumes it's an exit transition
			void _createExitCode(
				KernelTransitionPoint &transition,
				const ir::PTXOperand &resumePointOperand,
				ThreadExitCode exitCode);
			
			void _createDummyScheduler();
			
		public:
		
			//! \brief 
			ir::PTXKernel *kernel;
			
			//! \brief id of first basic block
			EntryId baseId;
			
			//! \brief	
			OffsetVector registerOffsets;
			
			//! \brief maps a block label to its kernel transition point data structure
			KernelTransitionPointMap transitionPoints;
			
			//! \brief maps a basic block label to a vector of its transitions
			BlockEntryTransitionMap entryTransitions;
		
			//! \brief basic block of scheduler to be completed later
			ir::BasicBlock::Pointer scheduler;
		};
	
	public:
	
		KernelPartitioningPass();
		
		void initialize(const ir::Module& m);
		void runOnKernel(KernelDecomposition &decomposition, ir::Kernel& parent, EntryId baseId = 0);
		void finalize();
		
	public:
	
	};
}

#endif
