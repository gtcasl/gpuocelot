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
#include <fstream>

// Ocelot includes
#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/analysis/interface/DataflowGraph.h>

namespace analysis {

	class KernelPartitioningPass {
	public:
		typedef unsigned int SubkernelId;
		
		typedef analysis::DataflowGraph::RegisterSet RegisterSet;
		typedef analysis::DataflowGraph::RegisterId RegisterId;
		typedef std::set< RegisterId> RegisterIdSet;
		
		enum PartitioningHeuristic {
			Partition_maximum = 0,
			Partition_minimum,
			Partition_minimumWithBarriers,
			Partition_loops,
			PartitioningHeuristic_invalid
		};
		static std::string toString(PartitioningHeuristic h);
		static PartitioningHeuristic fromString(const std::string &s);
		
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

		/*!
			\brief handles external edges among subkernels
		*/
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
			
			// Subkernel or barrier yield
			ExternalEdge(const ir::BasicBlock::Edge &edge, 
				ir::BasicBlock::Pointer _handler,
				SubkernelId _entryId = 0,
				ThreadExitType _exit = Thread_subkernel,
				int _flags = 0): 
				sourceEdge(edge), handler(_handler), entryId(_entryId), exitStatus(_exit), flags(_flags) { }

			// Divergence yield
			ExternalEdge(
				ir::BasicBlock::Pointer _source,
				ir::BasicBlock::Pointer _handler, 
				SubkernelId _entryId = 0, 
				ThreadExitType _exit = Thread_branch, 
				int _flags = 0): sourceEdge(_source, _source, ir::BasicBlock::Edge::Invalid), 
					handler(_handler), entryId(_entryId), exitStatus(_exit), flags(_flags) { }

			// Divergent entry
			ExternalEdge(
				ir::BasicBlock::Pointer _source,
				ir::BasicBlock::Pointer _frontierBlock,
				ir::BasicBlock::Pointer _handler,
				SubkernelId _entryId,
				int _flags = F_divergence
			): 
			sourceEdge(_source, _source, ir::BasicBlock::Edge::Invalid), 
				handler(_handler), entryId(_entryId), frontierBlock(_frontierBlock), flags(_flags) { }

			//! \brief returns a block whose aliveOut 
			ir::BasicBlock::Pointer criticalLiveness() const {
				return sourceEdge.head;
			}

		public:
					
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
		typedef ExternalEdgeVector::iterator ExternalEdgePointer;
		typedef std::unordered_set< ir::BasicBlock::Pointer > BasicBlockSet;
		typedef std::map< analysis::DataflowGraph::RegisterId, size_t> RegisterOffsetMap;
		typedef std::unordered_map< ir::BasicBlock::Pointer, ExternalEdgeVector > ExternalEdgeMap;
		typedef std::vector< ir::BasicBlock::Edge > EdgeVector;
		typedef std::unordered_map< ir::BasicBlock::Pointer, ir::BasicBlock::Pointer> BasicBlockMap;
		typedef std::vector< BasicBlockSet > PartitionVector;
		
		/*!
			\brief handles divergent branches within subkernels
		*/
		class DivergentBranch {
		public:
			enum Flags {
				Diverge_true_internal = 1,
				Diverge_false_internal = 2,
				Diverge_true_external = 4,
				Diverge_false_external = 8,
			};
		
		public:
			DivergentBranch(): flags(0) {}
			
			DivergentBranch(int _flags, ir::BasicBlock::Pointer _frontier, ExternalEdgeVector::iterator _out):
				flags(_flags), frontierBlock(_frontier), outEdge(_out) { }
				
			~DivergentBranch() {}
				
		public:
			//! \brief indicates 
			int flags;
			
			//! \brief kernel basic block which must be transformed to interact with yield handlers
			ir::BasicBlock::Pointer frontierBlock;
		
			//! \brief 
			ExternalEdgeVector::iterator outEdge;
			
			//! \brief
			SubkernelId targetEntryIds[2];
		};
		typedef std::vector< DivergentBranch > DivergentBranchVector;
		
		/*!
			\brief structure storing divergent entries
		*/
		class DivergentEntry {
		public:
			DivergentEntry() {}
			
			DivergentEntry(ExternalEdgePointer _takenIn, ExternalEdgePointer _notTakenIn): 
				takenInEdge(_takenIn), nottakenInEdge(_notTakenIn) {}
			
			~DivergentEntry() {}
			
		public:
		
			//! entry edge
			ExternalEdgePointer takenInEdge;
			
			ExternalEdgePointer nottakenInEdge;
		};
		typedef std::vector< DivergentEntry > DivergentEntryVector;
		
		//!
		class Subkernel {
		public:
			Subkernel(SubkernelId _id);
			Subkernel();
			~Subkernel();
			
			void finish();
			
			void create(ir::PTXKernel *source,
				analysis::DataflowGraph *sourceDfg,
				const RegisterOffsetMap &registerOffsets);
			
			void createHandlers(
				analysis::DataflowGraph *sourceDfg,
				const RegisterOffsetMap &registerOffsets);
				
			ExternalEdgeVector::const_iterator getEntryEdge(SubkernelId entryId) const;
			
		protected:
		
			void _create(ir::PTXKernel *source);
			
			void _partitionBlocksAtBarrier();
			
			void _analyzeExternalEdges(ir::PTXKernel *source, EdgeVector &internalEdges, BasicBlockMap &blockMapping);			
			void _analyzeBarriers(ir::PTXKernel *source, EdgeVector &internalEdges, BasicBlockMap &blockMapping);
			void _analyzeDivergentControlFlow(ir::PTXKernel *source, EdgeVector &internalEdges, BasicBlockMap &blockMapping);
			
			//! \param inverseBlockMapping maps subkernel blocks onto blocks from the PTX kernel
			void _createDivergentBranch(BasicBlockMap &inverseBlockMapping, ir::BasicBlock::Pointer bb_it);
			
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
			
			// divergent branches
			DivergentBranchVector divergentBranches;
			
			// divergent entries
			DivergentEntryVector divergentEntries;
		};
		typedef std::map< SubkernelId, Subkernel> SubkernelMap;
		
		class KernelGraph;
		
		class AnnotatedWriter {
		public:
			AnnotatedWriter();
			virtual ~AnnotatedWriter();
		public:
			virtual std::string escape(const std::string &s) const;
			virtual std::ostream &write(std::ostream &out, const KernelGraph &kernelGraph);
			virtual std::ostream &write(std::ostream &out, const Subkernel &subkernel);
			virtual std::ostream &write(std::ostream &out, ir::BasicBlock::ConstPointer &block);
			virtual std::ostream &writeEntryHandler(std::ostream &out, ir::BasicBlock::ConstPointer &block);
			virtual std::ostream &writeExitHandler(std::ostream &out, ir::BasicBlock::ConstPointer &block);
		};
		
		//!
		class KernelGraph {
		public:
			
		public:
		
			KernelGraph(ir::PTXKernel *_kernel, 
				SubkernelId baseId = 0, 
				PartitioningHeuristic _h = Partition_minimum,
				size_t _size = 1000);
			~KernelGraph();
		
			size_t localMemorySize() const;
			
		protected:
		
			void _partition(PartitionVector &partitions);

			size_t _computeRegisterOffsets(const PartitionVector &partitions);			
			void _partitionComplete(SubkernelId baseId, const PartitionVector &partitions);
			
			static RegisterIdSet _toRegisterIdSet(const RegisterSet &set);
			void _filterRegisterUses(RegisterIdSet &liveRegisterSet, const BasicBlockSet &partition);
			
			void _linkExternalEdges();
			void _createSpillRegion(size_t spillSize);
			void _createHandlers();
			
		protected:
			
			void _partitionMaximumSize(PartitionVector &partitions);
			void _partitionMinimumSize(PartitionVector &partitions);
			void _partitionMiminumWithBarriers(PartitionVector &partitions);
			void _partitionLoops(PartitionVector &partitions);

		public:
		
			SubkernelId getEntrySubkernel() const;
			
			std::ostream & write(std::ostream &out, AnnotatedWriter &writer);
			
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
			
			//! \brief number of instructions per subkernel
			size_t subkernelSize;
		};
		
		class BarrierPartitioning {
		public:
			
			void runOnKernel(ir::PTXKernel &ptxKernel);
		};
		
		class StrictTypeTransformation {
		public:
			void runOnKernel(ir::PTXKernel &ptxKernel);
		};
	
	public:
		KernelPartitioningPass();
		~KernelPartitioningPass();
		
		KernelGraph *runOnFunction(ir::PTXKernel &ptxKernel, SubkernelId baseId = 0, 
			PartitioningHeuristic _h = Partition_maximum, size_t subkernelSize = 1000);

	};
}

#endif

