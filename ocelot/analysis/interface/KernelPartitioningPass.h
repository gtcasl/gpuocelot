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
			Thread_return = 7,
			Thread_subkernel = 8,
			ThreadExitType_invalid
		};
		static std::string toString(const ThreadExitType &code);
		
		class ExternalEdge {
		public:
		
			enum Flags {
				F_normal = 0,
				F_external = 1,
				F_barrier = 2,
				F_divergence = 4,
				F_exit = 8,
				F_return = 16,
			};
			
		public:
			ExternalEdge(): entryId(0), exitStatus(Thread_subkernel), flags(0) { }
			ExternalEdge(const ir::BasicBlock::Edge &edge, 
				ir::BasicBlock::Pointer _handler,
				SubkernelId _entryId = 0,
				ThreadExitType _exit = Thread_subkernel,
				int _flags = 0): 
				sourceEdge(edge), handler(_handler), entryId(_entryId), exitStatus(_exit), flags(_flags) { }
			
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
			
			//! \brief identifies category of edge
			int flags;
		};
		typedef std::vector<ExternalEdge> ExternalEdgeVector;
		typedef std::unordered_set< ir::BasicBlock::Pointer > BasicBlockSet;
		typedef std::map< analysis::DataflowGraph::RegisterId, size_t> RegisterOffsetMap;
		typedef std::unordered_map< ir::BasicBlock::Pointer, ExternalEdgeVector > ExternalEdgeMap;
		typedef std::vector< ir::BasicBlock::Edge > EdgeVector;
		typedef std::unordered_map< ir::BasicBlock::Pointer, ir::BasicBlock::Pointer> BasicBlockMap;
		
		//!
		class Subkernel {
		public:
			Subkernel(SubkernelId _id);
			Subkernel();
			
			void create(ir::PTXKernel *source,
				analysis::DataflowGraph *sourceDfg,
				const RegisterOffsetMap &registerOffsets);
			
			void createHandlers(
				analysis::DataflowGraph *sourceDfg,
				const RegisterOffsetMap &registerOffsets);
			
		protected:
		
			void _create(ir::PTXKernel *source);
			
			void _partitionBlocksAtBarrier();
			

			void _analyzeExternalEdges(ir::PTXKernel *source, EdgeVector &internalEdges, BasicBlockMap &blockMapping);			
			void _analyzeBarriers(ir::PTXKernel *source, EdgeVector &internalEdges, BasicBlockMap &blockMapping);
			void _analyzeDivergentControlFlow(ir::PTXKernel *source, EdgeVector &internalEdges, BasicBlockMap &blockMapping);
			
			void _createExternalHandlers(
				analysis::DataflowGraph *sourceDfg, 
				analysis::DataflowGraph *subkernelDfg,
				const RegisterOffsetMap &registerOffsets);
				
			void _spillLiveValues(
				analysis::DataflowGraph *subkernelDfg, 
				analysis::DataflowGraph::iterator handlerDfg, 
				const analysis::DataflowGraph::RegisterSet &usedRegisters,
				const RegisterSet &aliveValues,
				const RegisterOffsetMap &registerOffsets,
				bool restore);
			
			void _updateHandlerControlFlow(ExternalEdgeMap &edges, analysis::DataflowGraph *subkernelDfg);
			
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
		};
		typedef std::map< SubkernelId, Subkernel> SubkernelMap;
		
		//!
		class KernelGraph {
		public:
			enum PartitioningHeuristic {
				Partition_maximum = 0,
				Partition_minimum,
				Partition_minimumWithBarriers,
				Partition_loops,
				PartitioningHeuristic_invalid
			};
			
		public:
		
			KernelGraph(ir::PTXKernel *_kernel, 
				SubkernelId baseId = 0, 
				PartitioningHeuristic _h = Partition_maximum);
			~KernelGraph();
		
			size_t localMemorySize() const;
			
			static std::string toString(PartitioningHeuristic h);
			static PartitioningHeuristic fromString(const std::string &s);
		
		protected:
		
			void _partition(SubkernelId baseId);
			void _linkExternalEdges();
			
			void _createSpillRegion(size_t spillSize);
			void _createHandlers();
			
			size_t _computeRegisterOffsets();
			
			void _partitionMaximumSize(SubkernelId baseId);
			void _partitionMinimumSize(SubkernelId baseId);
			void _partitionMiminumWithBarriers(SubkernelId baseId);
			void _partitionLoops(SubkernelId baseId);
		
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
			
			//! \brief identifies the partitioning heuristic to use
			PartitioningHeuristic heuristic;
		};
		
		class BarrierPartitioning {
		public:
			
			void runOnKernel(ir::PTXKernel &ptxKernel);
		};
	
	public:
		KernelPartitioningPass();
		~KernelPartitioningPass();
		
		KernelGraph *runOnFunction(ir::PTXKernel &ptxKernel, SubkernelId baseId = 0);

	};
}

#endif

