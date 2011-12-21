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
			Thread_subkernel,
			ThreadExitType_invalid
		};
		static std::string toString(const ThreadExitType &code);
		
		class ExternalEdge {
		public:
			ExternalEdge(): sourceId(0), destinationId(0) { }
			ExternalEdge(const ir::BasicBlock::Edge &edge, 
				ir::BasicBlock::Pointer _handler,
				SubkernelId _src = 0, SubkernelId _dst = 0): 
				sourceEdge(edge), sourceId(_src), destinationId(_dst), handler(_handler) { }
		
		public:
			//! \brief edge in original kernel
			ir::BasicBlock::Edge sourceEdge;
			
			//! \brief contains mapping
			SubkernelId sourceId, destinationId;
			
			//! \brief 
			ir::BasicBlock::Pointer handler;
			
			//! \brief block within the subkernel that is the source or destination for external edge
			ir::BasicBlock::Pointer frontierBlock;
		};
		typedef std::vector<ExternalEdge> ExternalEdgeVector;
		typedef std::unordered_set< ir::BasicBlock::Pointer > BasicBlockSet;
		typedef std::map< analysis::DataflowGraph::RegisterId, size_t> RegisterOffsetMap;
		
		//!
		class Subkernel {
		public:
			Subkernel(SubkernelId _id);
			
			void create(ir::PTXKernel *source,
				const RegisterOffsetMap &registerOffsets);
			
		protected:
			void _create(ir::PTXKernel *source);
			
			void _createExternalHandlers(
				analysis::DataflowGraph *sourceDfg, 
				analysis::DataflowGraph *subkernelDfg,
				const RegisterOffsetMap &registerOffsets);
				
			void _createDivergenceHandlers();
			void _createExit(ir::BasicBlock::Pointer block, ThreadExitType type, SubkernelId target);
			
		public:
			SubkernelId id;
			
			//! \brief list of blocks in SOURCE subkernel
			BasicBlockSet sourceBlocks;
			
			//! \brief actual partition
			ir::PTXKernel *subkernel;
			
			// out edges
			ExternalEdgeVector outEdges;
			
			// in edges
			ExternalEdgeVector inEdges;
		};
		typedef std::map< SubkernelId, Subkernel> SubkernelMap;
		
		//!
		class KernelGraph {
		public:
			KernelGraph(ir::PTXKernel *_kernel, SubkernelId baseId = 0);
			~KernelGraph();
		
		protected:
		
			void _partition(SubkernelId baseId);
			void _createEntries();
			void _createExits();
			void _createSchedulers();
			void _createDivergenceHandlers();
			
			void _partitionMaximumSize(SubkernelId baseId);
			void _partitionMinimumSize(SubkernelId baseId);
			
		public:
			//! source kernel
			ir::PTXKernel *ptxKernel;
			
			//! partitioning of subkernels
			SubkernelMap subkernels;
			
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

