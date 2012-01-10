/*!
	\file KernelPartitioningPass.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date November 17, 2011
	\brief partitions a PTX kernel into subkernels, inserts 
*/

#ifndef OCELOT_ANALYSIS_KERNELPARTITIONINGPASS_H_INCLUDED
#define OCELOT_ANALYSIS_KERNELPARTITIONINGPASS_H_INCLUDED

// C++ includes
#include <set>
#include <unordered_set>
#include <map>

// Ocelot includes
#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/analysis/interface/DataflowGraph.h>

namespace analysis {

	class KernelPartitioningPass {
	public:
		typedef unsigned int SubkernelId;
		
		typedef analysis::DataflowGraph::RegisterSet RegisterSet;
		
		enum ThreadExitType {
			Thread_entry = 0,
			Thread_fallthrough = 1,
			Thread_branch = 2,
			Thread_tailcall = 3,
			Thread_call = 4,
			Thread_barrier = 5,
			Thread_exit = 6,
			Thread_exit_other = 7,
			Thread_subkernel = 8,
			ThreadExitType_invalid
		};
		static std::string toString(const ThreadExitType &code);
		
		class ExternalEdge {
		public:
			ExternalEdge(): entryId(0), exitStatus(Thread_subkernel) { }
			ExternalEdge(const ir::BasicBlock::Edge &edge, 
				ir::BasicBlock::Pointer _handler,
				SubkernelId _entryId = 0,
				ThreadExitType _exit = Thread_subkernel): 
				sourceEdge(edge), handler(_handler), entryId(_entryId), exitStatus(_exit) { }
			
			static SubkernelId getSubkernelId(SubkernelId entryId) {
				return (entryId >> 16);
			}
			static SubkernelId getEntryId(SubkernelId entryId) {
				return (entryId & 0x0ffff);
			}
			static SubkernelId getEncodedEntry(SubkernelId subkernelId, SubkernelId entryId) {
				return ((subkernelId << 16) | (entryId & 0x0ffff));
			}
		
		public:
			//! \brief edge in original kernel
			ir::BasicBlock::Edge sourceEdge;
			
			//! \brief 
			ir::BasicBlock::Pointer handler;
			
			//! \brief identifies the entry point taken by the edge
			SubkernelId entryId;
			
			//! \brief block within the subkernel that is the source or destination for external edge
			ir::BasicBlock::Pointer frontierBlock;
			
			//! \brief indicates disposition of exit edge
			ThreadExitType exitStatus;
		};
		typedef std::vector<ExternalEdge> ExternalEdgeVector;
		typedef std::unordered_set< ir::BasicBlock::Pointer > BasicBlockSet;
		typedef std::map< analysis::DataflowGraph::RegisterId, size_t> RegisterOffsetMap;
		typedef std::unordered_map< ir::BasicBlock::Pointer, ExternalEdgeVector > ExternalEdgeMap;
		
		//!
		class Subkernel {
		public:
			Subkernel(SubkernelId _id);
			
			void create(ir::PTXKernel *source,
				analysis::DataflowGraph *sourceDfg,
				const RegisterOffsetMap &registerOffsets);
			
			void createHandlers(
				analysis::DataflowGraph *sourceDfg,
				const RegisterOffsetMap &registerOffsets);
			
		protected:
		
			void _create(ir::PTXKernel *source);
			
			void _partitionBlocksAtBarrier();
			
			void _createExternalHandlers(
				analysis::DataflowGraph *sourceDfg, 
				analysis::DataflowGraph *subkernelDfg,
				const RegisterOffsetMap &registerOffsets);
				
			void _createBarrierHandlers(
				analysis::DataflowGraph *sourceDfg,
				analysis::DataflowGraph *subkernelDfg,
				const RegisterOffsetMap &registerOffsets);
				
			void _createDivergenceHandlers(
				analysis::DataflowGraph *sourceDfg,
				analysis::DataflowGraph *subkernelDfg,
				const RegisterOffsetMap &registerOffsets);
			
			void _updateHandlerControlFlow(ExternalEdgeMap &edges);
			
			void _determineRegisterUses(analysis::DataflowGraph::RegisterSet &uses);
				
			void _createScheduler();
			
			void _createExit(analysis::DataflowGraph::iterator block, analysis::DataflowGraph *subkernelDfg, 
				ThreadExitType type, SubkernelId target);
			
		public:
		
			//! \brief 
			SubkernelId id;
			
			//! \brief list of blocks in SOURCE subkernel
			BasicBlockSet sourceBlocks;
			
			//! \brief actual partition
			ir::PTXKernel *subkernel;
			
			// out edges
			ExternalEdgeVector outEdges;
			
			// in edges
			ExternalEdgeVector inEdges;
			
			//! entry points for barriers
			ExternalEdgeVector barrierEntries;
			
			//! divergent entry handlers
			ExternalEdgeVector divergentEntries;
			
			//! divergent exit handlers
			ExternalEdgeVector divergentExits;
		};
		typedef std::map< SubkernelId, Subkernel> SubkernelMap;
		
		//!
		class KernelGraph {
		public:
			KernelGraph(ir::PTXKernel *_kernel, SubkernelId baseId = 0);
			~KernelGraph();
		
			size_t localMemorySize() const;
		
		protected:
		
			void _partition(SubkernelId baseId);
			void _linkExternalEdges();
			
			void _createSpillRegion(size_t spillSize);
			void _createHandlers();
			
			size_t _computeRegisterOffsets();
			
			void _partitionMaximumSize(SubkernelId baseId);
			void _partitionMinimumSize(SubkernelId baseId);
		
		public:
		
			SubkernelId getEntrySubkernel() const;
			
		private:
		
			//! data flow graph of the source kernel
			analysis::DataflowGraph *_sourceKernelDfg;
			
		public:
			//! source kernel
			ir::PTXKernel *ptxKernel;
			
			//! partitioning of subkernels
			SubkernelMap subkernels;
			
			//! \brief identifies the entry subkernel
			SubkernelId entrySubkernelId;
			
			//! \brief maps registers to offset
			RegisterOffsetMap registerOffsets;
		};
	
	public:
		KernelPartitioningPass();
		~KernelPartitioningPass();
		
		KernelGraph *runOnFunction(ir::PTXKernel &ptxKernel, SubkernelId baseId = 0);

	};
}

#endif

