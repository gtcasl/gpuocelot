/*!
	\file KernelPartitioningPass.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date November 17, 2011
	\brief implements kernel partitioning
*/

// C++ includes
#include <stdio.h>

// Boost includes
#include <boost/lexical_cast.hpp>

// Ocelot includes

#include <ocelot/ir/interface/Kernel.h>
#include <ocelot/analysis/interface/DataflowGraph.h>
#include <ocelot/analysis/interface/KernelPartitioningPass.h>

#include <ocelot/analysis/interface/ControlTree.h>
#include <ocelot/analysis/interface/DominatorTree.h>

// Hydrazine includes
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/math.h>
#include <hydrazine/implementation/string.h>

//////////////////////////////////////////////////////////////////////////////////////////////////

#define Ocelot_Exception(x) { std::stringstream ss; ss << x; std::cerr << x << std::endl; \
	throw hydrazine::Exception(ss.str()); }
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

////////////////////////////////////////////////////////////////////////////////////////////////////

#define REPORT_EMIT_SUBKERNEL_PTX 1
#define REPORT_EMIT_SOURCE_PTXKERNEL 0

#define REPORT_BASE 0

////////////////////////////////////////////////////////////////////////////////////////////////////

#define EMIT_PARTITIONED_KERNELGRAPH 0					// emits to .dot text files in directory
#define EMIT_KERNELGRAPH_ORIGINAL_PTX 0					// if 1, shows PTX for original basic blocks
#define EMIT_KERNELGRAPH_SUCCINCT_HANDLERS 0		// enables replacing actual instructions in handler blocks

////////////////////////////////////////////////////////////////////////////////////////////////////

static ir::PTXInstruction *getTerminator(ir::BasicBlock::Pointer block) {
	return static_cast<ir::PTXInstruction*>(block->instructions.back());
}

static bool doesBarrierTerminateBlock(ir::BasicBlock::Pointer block) {
	if (block->instructions.size()) {
		return static_cast<ir::PTXInstruction*>(block->instructions.back())->opcode == ir::PTXInstruction::Bar;
	}
	return false;
}
			
////////////////////////////////////////////////////////////////////////////////////////////////////	

analysis::KernelPartitioningPass::KernelPartitioningPass() {

}

analysis::KernelPartitioningPass::~KernelPartitioningPass() {
}

analysis::KernelPartitioningPass::KernelGraph *
	analysis::KernelPartitioningPass::runOnFunction(ir::PTXKernel &ptxKernel, SubkernelId baseId,
		PartitioningHeuristic _h, size_t _size) {
	
	report("KernelPartitioningPass::runOnFunction(" << ptxKernel.name << ")");
		
	analysis::KernelPartitioningPass::BarrierPartitioning barrierPass;
	barrierPass.runOnKernel(ptxKernel);
	
	KernelGraph *graph = new KernelGraph(&ptxKernel, baseId, _h, _size);
	
#if EMIT_PARTITIONED_KERNELGRAPH
	std::ofstream output(ptxKernel.name + ".dot");
	AnnotatedWriter writer;
	graph->write(output, writer);
#endif
	
	return graph;
}

#define CASE(x) case x: return #x
std::string analysis::KernelPartitioningPass::toString(const ThreadExitType &code) {
	switch (code) {
		CASE(Thread_entry);
		CASE(Thread_fallthrough);
		CASE(Thread_branch);
		CASE(Thread_tailcall);
		CASE(Thread_call);
		CASE(Thread_barrier);
		CASE(Thread_exit);
		CASE(Thread_return);
		CASE(Thread_subkernel);
		CASE(ThreadExitType_invalid);
		default: break;
	}
	return "ThreadExitType_invalid";
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void analysis::KernelPartitioningPass::BarrierPartitioning::runOnKernel(ir::PTXKernel &ptxKernel) {
	report("partitioning blocks at barriers");

	ir::ControlFlowGraph *kernelCfg = ptxKernel.cfg();
	int barrierCount = 0;

	for (ir::ControlFlowGraph::iterator bb_it = kernelCfg->begin(); 
		bb_it != kernelCfg->end(); ++bb_it) {

		unsigned int n = 0;
		for (ir::BasicBlock::InstructionList::iterator inst_it = (bb_it)->instructions.begin();
			inst_it != (bb_it)->instructions.end(); ++inst_it, n++) {
			ir::PTXInstruction *inst = static_cast<ir::PTXInstruction *>(*inst_it);
			
			if (inst->opcode == ir::PTXInstruction::Ret) {
				inst->opcode = ir::PTXInstruction::Exit;
			}
			
			if (inst->opcode == ir::PTXInstruction::Bar) {
				report("  barrier in block " << bb_it->label << "(instruction " << n << ")");
				if (n + 1 < (unsigned int)(bb_it)->instructions.size()) {
				
					std::string label = (bb_it)->label + "_bar";
					// ir::ControlFlowGraph::iterator block = 
					kernelCfg->split_block(bb_it, n+1, 
						ir::BasicBlock::Edge::FallThrough, label);
					++barrierCount;
					break;
				}
			}
			else {
				// found a barrier that is the last instruction in a basic block - this could potentially
				// be along the subkernel frontier, so make sure this gets handled correctly.
			}
		}
	}
	report("  encountered " << barrierCount << " barriers");
}

////////////////////////////////////////////////////////////////////////////////////////////////////

void analysis::KernelPartitioningPass::StrictTypeTransformation::runOnKernel(ir::PTXKernel &ptxKernel) {

	ir::PTXKernel::RegisterVector registers = ptxKernel.getReferencedRegisters();
	
	ir::ControlFlowGraph *kernelCfg = ptxKernel.cfg();

	report("StrictTypeTransformation::runOnKernel(" << ptxKernel.name << ")");
	for (ir::ControlFlowGraph::iterator bb_it = kernelCfg->begin(); 
		bb_it != kernelCfg->end(); ++bb_it) {

		unsigned int n = 0;
		for (ir::BasicBlock::InstructionList::iterator inst_it = (bb_it)->instructions.begin();
			inst_it != (bb_it)->instructions.end(); ++inst_it, n++) {
			ir::PTXInstruction *inst = static_cast<ir::PTXInstruction *>(*inst_it);
			
			if (inst->d.addressMode == ir::PTXOperand::Register && 
				ir::PTXOperand::bytes(inst->d.type) !=  ir::PTXOperand::bytes(inst->type) &&
				inst->d.type != ir::PTXOperand::pred) {
				report("  " << inst->toString() << "; // d.type = " << ir::PTXOperand::toString(inst->d.type) 
					<< ", inst->type = " << ir::PTXOperand::toString(inst->type));
				inst->d.type = inst->type;
			}			
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////

analysis::KernelPartitioningPass::KernelGraph::KernelGraph(
	ir::PTXKernel *_kernel, 
	SubkernelId baseId,
	PartitioningHeuristic _h,
	size_t _size)
: 
	ptxKernel(_kernel),
	heuristic(_h),
	subkernelSize(_size)
{
	// data flow analysis
	_sourceKernelDfg = new analysis::DataflowGraph;
	_sourceKernelDfg->analyze(*ptxKernel);
	
	report(" KernelGraph( partitioning with heuristic " << toString(heuristic) << ")");
	
#if REPORT_BASE && REPORT_EMIT_SOURCE_PTXKERNEL
	report("Partitioning kernel " << _kernel->name);
	_kernel->write(std::cout);
#endif
	
	PartitionVector partitions;
	_partition(partitions);
	
	size_t spillRegionSize = _computeRegisterOffsets(partitions);
	
	_createSpillRegion(spillRegionSize);
	_partitionComplete(baseId, partitions);
	
	_linkExternalEdges();
	_createHandlers();
}

analysis::KernelPartitioningPass::KernelGraph::~KernelGraph() {
	if (_sourceKernelDfg) {
		delete _sourceKernelDfg;
	}
	for (SubkernelMap::iterator sk_it = subkernels.begin(); sk_it != subkernels.end(); ++sk_it) {
		sk_it->second.finish();
	}	
	subkernels.clear();
}

////////////////////////////////////////////////////////////////////////////////////////////////////

std::string analysis::KernelPartitioningPass::toString(
	analysis::KernelPartitioningPass::PartitioningHeuristic h) {

	switch (h) {
		case Partition_maximum:
			return "maximum";
		case Partition_minimum:
			return "minimum";
		case Partition_minimumWithBarriers:
			return "minimumWithBarriers";
		case Partition_loops:
			return "loops";
		default:
			break;
	}
	return "invalid";
}

analysis::KernelPartitioningPass::PartitioningHeuristic
	analysis::KernelPartitioningPass::fromString(const std::string &s) {

	PartitioningHeuristic h[] = {
		Partition_maximum,
		Partition_minimum,
		Partition_minimumWithBarriers,
		Partition_loops,
		PartitioningHeuristic_invalid
	};
	const char *str[] = {
		"maximum", "minimum", "minimumWithBarriers", "loops", 0
	};
	for (int i = 0; h[i] != PartitioningHeuristic_invalid; i++) {
		if (std::string(str[i]) == s) {
			return h[i];
		}
	}
	return PartitioningHeuristic_invalid;
}

////////////////////////////////////////////////////////////////////////////////////////////////////

// Partitioning heuristics implemented here. Try out several. 
//
// - partitionMaximumSize: the entire kernel is one subkernel with compulsory exits at barriers
// - partitionMinimumSize: subkernel consists of just one basic block with all edges 
// - partitionMinimumWithBarriers: consists of one to two basic blocks if adjacent via barrier edge 
// - partitionLoops: subkernel contains loop header and body


void analysis::KernelPartitioningPass::KernelGraph::_partitionMaximumSize(PartitionVector &partitions) {

	report("KernelGraph::_partitionMaximumSize()");
	
	
	// add all blocks to subkernel
	ir::ControlFlowGraph *cfg = ptxKernel->cfg();
	BasicBlockSet subkernel;
	for (ir::ControlFlowGraph::iterator bb_it = cfg->begin(); bb_it != cfg->end(); ++bb_it) {
		subkernel.insert(bb_it);
	}
	partitions.push_back(subkernel);
}

void analysis::KernelPartitioningPass::KernelGraph::_partitionMinimumSize(PartitionVector &partitions) {

	report("KernelGraph::_partitionMinimumSize()");
	
		// add all blocks to subkernel
	ir::ControlFlowGraph *cfg = ptxKernel->cfg();
	for (ir::ControlFlowGraph::iterator bb_it = cfg->begin(); bb_it != cfg->end(); ++bb_it) {
		if (!bb_it->instructions.size()) {
			continue;
		}
		
		BasicBlockSet subkernel;
		subkernel.insert(bb_it);
		partitions.push_back(subkernel);
	}
}

void analysis::KernelPartitioningPass::KernelGraph::_partitionMiminumWithBarriers(
	PartitionVector &partitions) {
	report("KernelGraph::_partitionMiminumWithBarriers()");
	
	BasicBlockSet visited;
	BasicBlockSet activePartition;
	
	// add all blocks to subkernel
	ir::ControlFlowGraph *cfg = ptxKernel->cfg();
	ir::ControlFlowGraph::BlockPointerVector topological = cfg->topological_sequence();
	
	for (ir::ControlFlowGraph::BlockPointerVector::iterator bb_it = topological.begin(); 
		bb_it != topological.end(); ++bb_it) {
		ir::BasicBlock::Pointer block = *bb_it;
		
		if (!block->instructions.size()) {
			continue;
		}

		if (visited.find(block) == visited.end()) {
			activePartition.insert(block);
			
			ir::BasicBlock::Pointer succ = block;
			for (; getTerminator(succ)->opcode == ir::PTXInstruction::Bar; ) {
				succ = succ->out_edges[0]->tail;
				activePartition.insert(succ);
			}
			
			visited.insert(activePartition.begin(), activePartition.end());
			partitions.push_back(activePartition);
			activePartition.clear();
		}
	}
}

static size_t partitionLoops_totalInstructions(
	const analysis::KernelPartitioningPass::BasicBlockSet &partition) {

	size_t total = 0;
	for (analysis::KernelPartitioningPass::BasicBlockSet::const_iterator it = partition.begin();
		it != partition.end(); ++it) { 

		total += (*it)->instructions.size();
	}
	return total;
}

static void partitionLoops_addHelper(const analysis::ControlTree::Node *node, 
	analysis::KernelPartitioningPass::PartitionVector &partitionVector, 
	std::unordered_map< ir::BasicBlock::ConstPointer, ir::BasicBlock::Pointer > & pointerMap,
	const size_t instructionThreshold) {

	if (!node) {
		return;
	}

	switch (node->rtype()) {
	case analysis::ControlTree::Inst:           // Instructions (e.g. basic block)
	{
		const analysis::ControlTree::InstNode *instNode = 
			static_cast<const analysis::ControlTree::InstNode *>(node);
		
		if (!partitionVector.size() || (instructionThreshold && 
			partitionLoops_totalInstructions(partitionVector.back()) + instNode->insts().size() 
				> instructionThreshold)) {
			analysis::KernelPartitioningPass::BasicBlockSet newPartition;
			
			newPartition.insert(pointerMap[instNode->bb()]);
			partitionVector.push_back(newPartition);
		}
		else {
			partitionVector.back().insert(pointerMap[instNode->bb()]);
		}
	}
		break;
	case analysis::ControlTree::IfThen:         // If-Then
	{
		const analysis::ControlTree::IfThenNode *regionNode = 
			static_cast<const analysis::ControlTree::IfThenNode *>(node);
		
		partitionLoops_addHelper(regionNode->cond(), partitionVector, pointerMap, instructionThreshold);
		partitionLoops_addHelper(regionNode->ifTrue(), partitionVector, pointerMap, instructionThreshold);
		partitionLoops_addHelper(regionNode->ifFalse(), partitionVector, pointerMap, instructionThreshold);
	}
		break;
	case analysis::ControlTree::Block:          // Block of nodes
	case analysis::ControlTree::Natural:        // Natural loop with side exits
	case analysis::ControlTree::While:          // While loop
	{
		const analysis::ControlTree::Node *regionNode = node;
		
		bool overrideInstructionThreshold = (node->rtype() == analysis::ControlTree::Natural ||
			node->rtype() == analysis::ControlTree::While);
		
		if (overrideInstructionThreshold &&
			partitionVector.size() && partitionVector.back().size()) {
			analysis::KernelPartitioningPass::BasicBlockSet newPartition;
			partitionVector.push_back(newPartition);
		}
		
		for (analysis::ControlTree::NodeList::const_iterator child_it = regionNode->children().begin();
			child_it != regionNode->children().end(); ++child_it) {
			
			const analysis::ControlTree::Node *child = *child_it;
			partitionLoops_addHelper(child, partitionVector, pointerMap, 
				(overrideInstructionThreshold ? 0 : instructionThreshold));
		}
	}
	case analysis::ControlTree::Invalid:
	default:
		break;
	}
}

void analysis::KernelPartitioningPass::KernelGraph::_partitionLoops(PartitionVector &partitions) {
	typedef analysis::ControlTree CT;
	typedef analysis::ControlTree::Node CTNode;
	
	ir::ControlFlowGraph *cfg = ptxKernel->cfg();
	ir::ControlFlowGraph::BlockPointerVector topological = cfg->topological_sequence();
	
	std::unordered_map< ir::BasicBlock::ConstPointer, ir::BasicBlock::Pointer > pointerMap;
	
	ir::BasicBlock::ConstPointer const_bb_it = cfg->begin();
	ir::BasicBlock::Pointer bb_it = cfg->begin();
	
	for (; bb_it != cfg->end(); ++bb_it, ++const_bb_it) {
		// fill out pointer map
		assert(bb_it->label == const_bb_it->label);
		pointerMap[const_bb_it] = bb_it;
	}
	
	analysis::ControlTree controlTree(cfg);
	
	// start at leaves of control tree, merge children of nodes into partitions as we rise until
	// each partition reaches some maximum size
	partitionLoops_addHelper(controlTree.get_root_node(), partitions, pointerMap, subkernelSize);
		
	// emit
	#if REPORT_BASE
	report(" partitions: [");
	for (PartitionVector::iterator partition_it = partitions.begin(); 
		partition_it != partitions.end(); ++partition_it ) {
	
		report(" " << partition_it->size() << " blocks (" 
			<< partitionLoops_totalInstructions(*partition_it) << " instructions): {");
		for (BasicBlockSet::iterator bbs_it = partition_it->begin(); 
			bbs_it != partition_it->end(); ++bbs_it) {
			report("  " << (*bbs_it)->label);
		}
		report(" }");
	}
	report("]");
	#endif
	
	BasicBlockSet coveredBlocks;
	for (PartitionVector::iterator partition_it = partitions.begin();
		partition_it != partitions.end(); ++partition_it) {
		coveredBlocks.insert(partition_it->begin(), partition_it->end());
	}
	for (ir::ControlFlowGraph::BlockPointerVector::iterator bb_it = topological.begin();
		bb_it != topological.end(); ++bb_it) {
		if (coveredBlocks.find(*bb_it) == coveredBlocks.end()) {
			partitions.back().insert(*bb_it);
		}
	}
	
	// assert entry node is in first partition
	assert(partitions.size());
	bool foundEntry = false;
	for (BasicBlockSet::iterator bb_it = partitions.front().begin();
		bb_it != partitions.front().end(); ++bb_it) {
		if ((*bb_it)->label == "entry") {
			foundEntry = true;
			break;
		}
	}
	assert(foundEntry && "first partition must contain entry node");
}

/*!
	\brief constructs a partitioning of the PTX kernel according to some heuristic
		then uses these to create subkernels
*/
void analysis::KernelPartitioningPass::KernelGraph::_partition(PartitionVector &partitions) {
	//
	// select partitioning heuristic here
	//
	// A partitioning constructs a set of basic-block sets. The edges are then
	// classified as internal if they do not cross partitions and external if they do.
	// External edges are further classified as in-edges or out-edges from the perspective
	// of each subkernel.
	//
	
	// construct subkernels according to one of several partitioning heuristics	
	switch (heuristic) {
		case Partition_maximum:
			_partitionMaximumSize(partitions);
			break;
		case Partition_minimum:
			_partitionMinimumSize(partitions);
			break;
		case Partition_minimumWithBarriers:
			_partitionMiminumWithBarriers(partitions);
			break;
		case Partition_loops:
			_partitionLoops(partitions);
			break;
		default:
			assert(0 && "invalid partitioning heuristic");
			break;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////

/*!
	\brief creates new subkernels based on partitions
*/
void analysis::KernelPartitioningPass::KernelGraph::_partitionComplete(SubkernelId baseId, 
	const PartitionVector &partitions) {

	for (std::vector< BasicBlockSet >::const_iterator sk_it = partitions.begin(); 
		sk_it != partitions.end();
		++sk_it) {
				
		Subkernel subkernel(baseId + subkernels.size());
		subkernel.sourceBlocks = *sk_it;
		subkernel.create(ptxKernel, _sourceKernelDfg, registerOffsets);
		subkernels.insert(std::make_pair(subkernel.id, subkernel));
		
		if (subkernels.size() == 1) {
			entrySubkernelId = subkernel.id;
		}
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////

/*!
	\brief inserts local variable declarations for spill regions, resume points, and resume status
*/
void analysis::KernelPartitioningPass::KernelGraph::_createSpillRegion(size_t spillSize) {
	
	ir::PTXStatement resumeTarget(ir::PTXStatement::Local);
		
	resumeTarget.type = ir::PTXOperand::u32;
	resumeTarget.name = "_Zocelot_resume_point";
	
	ptxKernel->locals.insert(std::make_pair(resumeTarget.name, ir::Local(resumeTarget)));
	
	ir::PTXStatement resumeStatus(ir::PTXStatement::Local);
	resumeStatus.type = ir::PTXOperand::u32;
	resumeStatus.name = "_Zocelot_resume_status";
	ptxKernel->locals.insert(std::make_pair(resumeStatus.name, ir::Local(resumeStatus)));
	
	ir::PTXStatement spillRegion(ir::PTXStatement::Local);
	spillRegion.type = ir::PTXOperand::b8;
	spillRegion.name = "_Zocelot_spill_area";
	spillRegion.array.stride.push_back((unsigned int)spillSize);
	
	ptxKernel->locals.insert(std::make_pair(spillRegion.name, ir::Local(spillRegion)));
		
	report("  Spill region size is " << spillSize);
}

void analysis::KernelPartitioningPass::KernelGraph::_linkExternalEdges() {

	report("Linking external edges");
	
	report("  but first!");	
	for (SubkernelMap::iterator subkernel_it = subkernels.begin(); subkernel_it != subkernels.end(); 
		++subkernel_it) {

		Subkernel &subkernel = subkernel_it->second;
		
		report("  subkernel " << subkernel.subkernel->name << " out edges: ");
		for (ExternalEdgeVector::iterator edge_it = subkernel.outEdges.begin(); 
			edge_it != subkernel.outEdges.end(); ++edge_it) {
			if (edge_it->flags == ExternalEdge::F_divergence) {
				report("    divergent branch");
			}
			else {
				report("    " << edge_it->sourceEdge.head->label << " -> " << edge_it->sourceEdge.tail->label);
			}
		}
	
		report("  and here are all the in_edges:");
		for (ExternalEdgeVector::iterator edge_it = subkernel.inEdges.begin(); 
			edge_it != subkernel.inEdges.end(); ++edge_it) {
			if (edge_it->flags == ExternalEdge::F_divergence) {
				report("    divergent branch");
			}
			else {
				report("    " << edge_it->sourceEdge.head->label << " -> " << edge_it->sourceEdge.tail->label);
			}
		}
	}
	
	report("  now linking");
	for (SubkernelMap::iterator subkernel_it = subkernels.begin(); subkernel_it != subkernels.end(); 
		++subkernel_it) {
		
		Subkernel &subkernel = subkernel_it->second;
		for (ExternalEdgeVector::iterator edge_it = subkernel.outEdges.begin(); 
			edge_it != subkernel.outEdges.end(); ++edge_it) {
			
			bool found = false;
			for (SubkernelMap::iterator checksk_it = subkernels.begin(); 
				checksk_it != subkernels.end() && !found;
				++checksk_it) {
				
				Subkernel &checksk = checksk_it->second;
				bool sameSubkernel = (checksk.id == subkernel.id);
				
				if (sameSubkernel) {
					report("   same subkernel");
				}
				
				for (ExternalEdgeVector::iterator inedge_it = checksk.inEdges.begin(); 
					inedge_it != checksk.inEdges.end() && !found; ++inedge_it) {
				
					ExternalEdge &inEdge = *inedge_it;
					if (inEdge.sourceEdge.head == edge_it->sourceEdge.head && 
						inEdge.sourceEdge.tail == edge_it->sourceEdge.tail) {
					
						if (inEdge.sourceEdge.type == edge_it->sourceEdge.type) {
							edge_it->entryId = inEdge.entryId;
							found = true;
							report("  linking " << edge_it->handler->label << " to " << inEdge.handler->label 
								<< " (entry " << edge_it->entryId << ")");
						}
						else {
							report("  NOT linking " << edge_it->handler->label << " to " << inEdge.handler->label 
								<< " (entry " << edge_it->entryId << ") due to mis-matched edge types: " 
								<< edge_it->sourceEdge.type << " -> " << inEdge.sourceEdge.type);
						}
					}
				}	
			}
			if (!found) {
				report(" failed to link external edge: " << edge_it->sourceEdge.head->label << " -> " 
					<< edge_it->sourceEdge.tail->label);
				edge_it->entryId = 0;
				edge_it->exitStatus = Thread_exit;
			}
		}
	}
}

/*!

*/
void analysis::KernelPartitioningPass::KernelGraph::_createHandlers() {
	for (SubkernelMap::iterator subkernel_it = subkernels.begin(); subkernel_it != subkernels.end();
		++subkernel_it) {
		Subkernel &subkernel = subkernel_it->second;
		subkernel.createHandlers(_sourceKernelDfg, registerOffsets);
	}
}

analysis::KernelPartitioningPass::SubkernelId 
	analysis::KernelPartitioningPass::KernelGraph::getEntrySubkernel() const {
	
	return entrySubkernelId;
}

/*!
	\brief compute basic mapping
*/
size_t analysis::KernelPartitioningPass::KernelGraph::_computeRegisterOffsets(
	const PartitionVector &partitions) {
	
	analysis::DataflowGraph::IteratorMap cfgToDfg = _sourceKernelDfg->getCFGtoDFGMap();
	
	RegisterIdSet liveRegisters;
	
	for (PartitionVector::const_iterator partition_it = partitions.begin();	
		partition_it != partitions.end(); ++partition_it) {

		RegisterIdSet subkernelRegisters;
		
		for (BasicBlockSet::const_iterator bb_it = partition_it->begin(); bb_it != partition_it->end();
			++bb_it) {
			
			bool externalOut = false;
			bool externalIn = false;
			
			// see if successors are in same partition
			for (ir::BasicBlock::BlockPointerVector::const_iterator succ_it = (*bb_it)->successors.begin();
				succ_it != (*bb_it)->successors.end(); ++succ_it) {
				BasicBlockSet::const_iterator it = partition_it->find(*bb_it);
				if (it != partition_it->end()) {
					externalOut = true;
					break;
				}
			}
			
			for (ir::BasicBlock::BlockPointerVector::const_iterator succ_it = (*bb_it)->predecessors.begin();
				succ_it != (*bb_it)->predecessors.end(); ++succ_it) {
				BasicBlockSet::const_iterator it = partition_it->find(*bb_it);
				if (it != partition_it->end()) {
					externalIn = true;
					break;
				}
			}
			
			if (externalOut) {		
				RegisterIdSet aliveValues = _toRegisterIdSet(cfgToDfg[*bb_it]->aliveOut());
				liveRegisters.insert(aliveValues.begin(), aliveValues.end());
			}
			if (externalIn) {		
				RegisterIdSet aliveValues = _toRegisterIdSet(cfgToDfg[*bb_it]->aliveIn());
				liveRegisters.insert(aliveValues.begin(), aliveValues.end());
			}
		}
		
		_filterRegisterUses(subkernelRegisters, *partition_it);
		
		liveRegisters.insert(subkernelRegisters.begin(), subkernelRegisters.end());
	}
	
	report("LiveRegisters [count: " << liveRegisters.size() << "]");
	report("  saved " <<  sizeof(int*)*(_sourceKernelDfg->maxRegister() - liveRegisters.size()) 
		<< " bytes per thread");
	
	registerOffsets.clear();
	size_t bytes = 0;
	for (RegisterIdSet::const_iterator reg_it = liveRegisters.begin(); 
		reg_it != liveRegisters.end(); ++reg_it) {
		registerOffsets[*reg_it] = bytes;
		bytes += sizeof(int*);
	}

	return bytes;
}

analysis::KernelPartitioningPass::RegisterIdSet
	analysis::KernelPartitioningPass::KernelGraph::_toRegisterIdSet(const RegisterSet &registerSet) {

	RegisterIdSet set;
	for (RegisterSet::const_iterator reg_it = registerSet.begin(); reg_it != registerSet.end(); 
		++reg_it) {
		set.insert(reg_it->id);
	}
	return set;
}

template <typename T>
static void inplaceSetIntersection(T &result, const T& filter) {
	for (typename T::iterator it = result.begin(); it != result.end(); ++it) {
		if (filter.find(*it) == filter.end()) {
			typename T::iterator kill = it;
			++it;
			result.erase(kill);
		}
	}
}

void analysis::KernelPartitioningPass::KernelGraph::_filterRegisterUses(
	RegisterIdSet &liveRegisterSet, const BasicBlockSet &partition) {
	
	RegisterIdSet uses;
	for (BasicBlockSet::const_iterator bb_it = partition.begin(); bb_it != partition.end(); ++bb_it) {
		for (ir::BasicBlock::InstructionList::iterator inst_it = (*bb_it )->instructions.begin();
			inst_it != (*bb_it )->instructions.end(); ++inst_it) {
			ir::PTXInstruction *instr = static_cast<ir::PTXInstruction*>(*inst_it);
			
			ir::PTXOperand ir::PTXInstruction::*operands[] = {
				&ir::PTXInstruction::pg,
				&ir::PTXInstruction::pq,
				&ir::PTXInstruction::d,
				&ir::PTXInstruction::a,
				&ir::PTXInstruction::b,
				&ir::PTXInstruction::c
			};
			for (int i = 0; i < 6; i++) {
				ir::PTXOperand &operand = (instr->*operands[i]);
				if (operand.addressMode == ir::PTXOperand::Register || 
					operand.addressMode == ir::PTXOperand::Indirect) {
					uses.insert(operand.reg);
				}
			}
		}
	}
	
	// intersect liveRegisterSet with uses	
	inplaceSetIntersection(liveRegisterSet, uses);
}

size_t analysis::KernelPartitioningPass::KernelGraph::localMemorySize() const {
	SubkernelMap::const_iterator subkernel_it = subkernels.find(entrySubkernelId);

	size_t localsSize = 0;
	for (ir::Kernel::LocalMap::const_iterator local_it = subkernel_it->second.subkernel->locals.begin();
		local_it != subkernel_it->second.subkernel->locals.end(); ++local_it ) {
	
		localsSize += local_it->second.getSize();
	}
	return localsSize;
}

////////////////////////////////////////////////////////////////////////////////////////////////////	

analysis::KernelPartitioningPass::AnnotatedWriter::AnnotatedWriter() { }
analysis::KernelPartitioningPass::AnnotatedWriter::~AnnotatedWriter() { }

std::string analysis::KernelPartitioningPass::AnnotatedWriter::escape(const std::string &s) const {
	std::string ns = s;
	for (size_t i = 0; i < ns.size(); i++) {
		if (ns.at(i) == '$' ) {
			ns[i] = ' ';
		}
	}
	return hydrazine::toGraphVizParsableLabel(ns);
}

std::ostream & analysis::KernelPartitioningPass::AnnotatedWriter::write(
	std::ostream &out, const KernelGraph &kernelGraph) {
	
	out << "digraph G {\n";
	
	// subkernels
	out << "\n  // subkernels\n";
	for (SubkernelMap::const_iterator sk_it = kernelGraph.subkernels.begin(); 
		sk_it != kernelGraph.subkernels.end(); ++sk_it) {
		write(out, sk_it->second);
	}	
	
	// external edges
	out << "\n  // external edges\n";
	for (SubkernelMap::const_iterator sk_it = kernelGraph.subkernels.begin(); 
		sk_it != kernelGraph.subkernels.end(); ++sk_it) {
		
		for (ExternalEdgeVector::const_iterator edge_it = sk_it->second.outEdges.begin(); 
			edge_it != sk_it->second.outEdges.end(); ++edge_it) {
			
			SubkernelMap::const_iterator targetSubkernel_it = kernelGraph.subkernels.find(edge_it->entryId >> 16);
			if (targetSubkernel_it != kernelGraph.subkernels.end()) {
		
				ExternalEdgeVector::const_iterator targetEdge_it = targetSubkernel_it->second.getEntryEdge(edge_it->entryId);
				std::string target = "exit";
				if (targetEdge_it != targetSubkernel_it->second.inEdges.end()) {
					target = targetEdge_it->handler->label;
				}
				out << escape(edge_it->handler->label) << " -> " 
					<< escape(target) << " [style=bold,label=\"entry id: 0x" << std::hex << edge_it->entryId << std::dec << "\"];";
			}
		}
	}
	
	out << "entry [shape=Mdiamond];\n";
	
	out << "}\n";
	return out;
}

//! writes a single subkernel
std::ostream &analysis::KernelPartitioningPass::AnnotatedWriter::write(std::ostream &out, 
	const Subkernel &subkernel) {
	
	out << "subgraph cluster" << escape(subkernel.subkernel->name) << " {\n";
	out << "color=black;\n";
	out << "label=\"" << escape(subkernel.subkernel->name) << "(id " << subkernel.id << ")\";\n";
	
	std::map< std::string, bool > handlerBlocks;
	std::set< std::string > internalBlocks;
	
	for (ExternalEdgeVector::const_iterator edge_it = subkernel.inEdges.begin();
		edge_it != subkernel.inEdges.end(); ++edge_it) {
		handlerBlocks[edge_it->handler->label] = false;
	}
	for (ExternalEdgeVector::const_iterator edge_it = subkernel.outEdges.begin();
		edge_it != subkernel.outEdges.end(); ++edge_it) {
		handlerBlocks[edge_it->handler->label] = true;		
	}
		
	// blocks
	for (ir::ControlFlowGraph::const_iterator bb_it = subkernel.subkernel->cfg()->begin();
		bb_it != subkernel.subkernel->cfg()->end(); ++bb_it) {
		
		ir::BasicBlock::ConstPointer block = bb_it;
		bool special = handlerBlocks.find(bb_it->label) != handlerBlocks.end();
		internalBlocks.insert(block->label);
		if (special) {
			if (handlerBlocks[bb_it->label]) {
				writeExitHandler(out, block);
			}
			else {
				writeEntryHandler(out, block);
			}
		}
		else {
			write(out, block);
		}
	}
	
	// internal edges
	for (ir::ControlFlowGraph::const_iterator bb_it = subkernel.subkernel->cfg()->begin();
		bb_it != subkernel.subkernel->cfg()->end(); ++bb_it) {
	
		for (ir::BasicBlock::EdgePointerVector::const_iterator out_it = bb_it->out_edges.begin();
			out_it != bb_it->out_edges.end(); ++out_it) {
			std::string style = "";

			if (internalBlocks.find((*out_it)->tail->label) != internalBlocks.end()) {
				out << "  " << escape((*out_it)->head->label) << " -> " << escape((*out_it)->tail->label);
				switch ((*out_it)->type) {
				case ir::BasicBlock::Edge::Branch:
					out << " [color=blue]";
					break;
				case ir::BasicBlock::Edge::FallThrough:
					out << " [color=slategray]";
					break;
				case ir::BasicBlock::Edge::Dummy:
					out << " [style=dotted,color=darkgrey]";
					break;
				default: break;
				}
				out << ";\n";
			}
		}
	}
	
	out << "}\n";
	return out;
}

std::ostream &analysis::KernelPartitioningPass::AnnotatedWriter::write(std::ostream &out, 
	ir::BasicBlock::ConstPointer &block) {
	
	std::string style = "";
	std::string shape = "shape=record,";
	if (block->label == "entry") {
		shape = "shape=Mdiamond,";
	}
	else if (block->label == "exit") {
		shape = "shape=Msquare,";
	}
	
	out << "  " << escape(block->label) << " [" << shape << style << "label=\"{" << escape(block->label);
	if (block->label != "entry" && block->label != "exit") {
#if EMIT_KERNELGRAPH_ORIGINAL_PTX
		for (ir::BasicBlock::InstructionList::const_iterator inst_it = block->instructions.begin();
			inst_it != block->instructions.end(); ++inst_it) {
			
			out << " | " << escape((*inst_it)->toString());
		}
#else
		out << " | .. original PTX omitted ..";	
#endif
	}
	out << "}\"];\n";
	
	return out;
}

std::ostream &analysis::KernelPartitioningPass::AnnotatedWriter::writeEntryHandler(
	std::ostream &out, ir::BasicBlock::ConstPointer &block) {

	std::string style = "";
	std::string shape = "shape=record,";
	if (block->label == "entry") {
		shape = "shape=Mdiamond,";
	}
	else if (block->label == "exit") {
		shape = "shape=Msquare,";
	}
	
	out << "  " << escape(block->label) << " [" << shape << style 
		<< "label=\"{" << escape(block->label);

	std::map< std::string, ir::PTXOperand::RegisterType > symbolMap;
	symbolMap["_Zocelot_spill_area"] = 0x0ffffff;
	symbolMap["_Zocelot_resume_status"] = 0x0ffffff;
	symbolMap["_Zocelot_resume_point"] = 0x0ffffff;

	for (ir::BasicBlock::InstructionList::const_iterator inst_it = block->instructions.begin();
		inst_it != block->instructions.end(); ++inst_it){ 
		const ir::PTXInstruction *inst = static_cast<ir::PTXInstruction*>(*inst_it);
		
		bool displayInstruction = true;
#if EMIT_KERNELGRAPH_SUCCINCT_HANDLERS
		if (inst->opcode == ir::PTXInstruction::Mov && inst->a.addressMode == ir::PTXOperand::Address) {
			symbolMap[inst->a.identifier] = inst->d.reg;
			displayInstruction = false;
		}
		else if (inst->opcode == ir::PTXInstruction::Ld && inst->addressSpace == ir::PTXInstruction::Local) {
			if (symbolMap["_Zocelot_spill_area"] == inst->a.reg) {
				out << " | restore r" << std::dec << inst->d.reg << ", offset: " << inst->a.offset;
				displayInstruction = false;
			}
		}
#endif
		
		if (displayInstruction) {
			out << " |" << escape(inst->toString()) << " ";
		}
	}

	out << "}\"];\n";
	return out;
}

std::ostream &analysis::KernelPartitioningPass::AnnotatedWriter::writeExitHandler(
	std::ostream &out, ir::BasicBlock::ConstPointer &block) {

	std::string style = "";
	std::string shape = "shape=record,";
	if (block->label == "entry") {
		shape = "shape=Mdiamond,";
	}
	else if (block->label == "exit") {
		shape = "shape=Msquare,";
	}
	
	out << "  " << escape(block->label) << " [" << shape << style << "label=\"{" << escape(block->label);

	std::map< std::string, ir::PTXOperand::RegisterType > symbolMap;
	symbolMap["_Zocelot_spill_area"] = 0x0ffffff;
	symbolMap["_Zocelot_resume_status"] = 0x0ffffff;
	symbolMap["_Zocelot_resume_point"] = 0x0ffffff;

#if EMIT_KERNELGRAPH_SUCCINCT_HANDLERS
	ThreadExitType exitType = Thread_subkernel;
#endif

	for (ir::BasicBlock::InstructionList::const_iterator inst_it = block->instructions.begin();
		inst_it != block->instructions.end(); ++inst_it){ 
		const ir::PTXInstruction *inst = static_cast<ir::PTXInstruction*>(*inst_it);
		
		bool displayInstruction = true;
#if EMIT_KERNELGRAPH_SUCCINCT_HANDLERS
		if (inst->opcode == ir::PTXInstruction::Mov && inst->a.addressMode == ir::PTXOperand::Address) {
			symbolMap[inst->a.identifier] = inst->d.reg;
			displayInstruction = false;
		}
		else if (inst->opcode == ir::PTXInstruction::St && inst->addressSpace == ir::PTXInstruction::Local) {
			if (symbolMap["_Zocelot_spill_area"] == inst->d.reg) {
				out << " | store r" << std::dec << inst->a.reg << ", offset: " << inst->d.offset;
				displayInstruction = false;
			}
			else if (symbolMap["_Zocelot_resume_status"] == inst->d.reg) {
				exitType = (ThreadExitType)inst->a.imm_uint;
				displayInstruction = false;
			}
			else if (symbolMap["_Zocelot_resume_point"] == inst->d.reg) {
				out << " | resume point 0x" << std::hex << inst->a.imm_uint << std::hex;
				displayInstruction = false;
			}
		}
		else if (inst->opcode == ir::PTXInstruction::Exit) {
			out << " | yield " << toString(exitType);
			displayInstruction = false;
		}
#endif

		if (displayInstruction) {
			out << " |" << escape(inst->toString()) << " ";
		}
	}

	out << "}\"];\n";
	return out;
}
		
std::ostream & analysis::KernelPartitioningPass::KernelGraph::write(std::ostream &out,
	analysis::KernelPartitioningPass::AnnotatedWriter &writer) {
	return writer.write(out, *this);
}

////////////////////////////////////////////////////////////////////////////////////////////////////	

analysis::KernelPartitioningPass::Subkernel::Subkernel(SubkernelId _id): id(_id) {

}

analysis::KernelPartitioningPass::Subkernel::Subkernel() {
}

analysis::KernelPartitioningPass::Subkernel::~Subkernel() {
}

void analysis::KernelPartitioningPass::Subkernel::finish() {
	delete subkernel;
	subkernel = 0;
}

analysis::KernelPartitioningPass::ExternalEdgeVector::const_iterator
	analysis::KernelPartitioningPass::Subkernel::getEntryEdge(SubkernelId entryId) const {

	for (ExternalEdgeVector::const_iterator edge_it = inEdges.begin(); 
		edge_it != inEdges.end(); ++edge_it) {
	
		if (entryId == edge_it->entryId) {
			return edge_it;
		}
	}
	return inEdges.end();
}

void analysis::KernelPartitioningPass::Subkernel::create(ir::PTXKernel *source,
	analysis::DataflowGraph *sourceDfg,
	const RegisterOffsetMap &registerOffsets) {

	report("Subkernel::create(" << source->name << ")");
	
	_create(source);
}

void analysis::KernelPartitioningPass::Subkernel::createHandlers(
	analysis::DataflowGraph *sourceDfg,
	const RegisterOffsetMap &registerOffsets) {
	
	analysis::DataflowGraph subkernelDfg;
	subkernelDfg.analyze(*subkernel);
	
	_createExternalHandlers(sourceDfg, &subkernelDfg, registerOffsets);
	
	#if REPORT_BASE && REPORT_EMIT_SUBKERNEL_PTX
	report("subkernel->write");
	subkernel->write(std::cout);
	#endif
}


void analysis::KernelPartitioningPass::Subkernel::_create(ir::PTXKernel *source) {

	report("Subkernel::_create(" << source->name << " id: " << id << ")");
	
	std::stringstream ss;
	ss << "_subkernel_" << source->name << "_" << id;
	
	subkernel = new ir::PTXKernel(ss.str(), false, source->module);
	
	for (ir::Kernel::ParameterVector::const_iterator arg_it = source->arguments.begin();
		arg_it != source->arguments.end(); ++arg_it) {
		
		subkernel->arguments.push_back(*arg_it);
	}
	for (ir::Kernel::LocalMap::const_iterator local_it = source->locals.begin(); 
		local_it != source->locals.end(); ++local_it) {
		subkernel->locals.insert(std::make_pair(local_it->first, local_it->second));
	}
	
	std::vector< ir::BasicBlock::Edge > internalEdges;
	std::unordered_map< ir::BasicBlock::Pointer, ir::BasicBlock::Pointer> blockMapping;
	
	_analyzeExternalEdges(source, internalEdges, blockMapping);
	_analyzeDivergentControlFlow(source, internalEdges, blockMapping);
}

//! creates external edges for subkernel entries and exits
void analysis::KernelPartitioningPass::Subkernel::_analyzeExternalEdges(
	ir::PTXKernel *source, EdgeVector &internalEdges, BasicBlockMap &blockMapping) {
	
	report("");
	report(" _analyzeExternalEdges()");
	
	ir::ControlFlowGraph *subkernelCfg = subkernel->cfg();
	
	for (BasicBlockSet::iterator bb_it = sourceBlocks.begin();
		bb_it != sourceBlocks.end(); ++bb_it) {
		
		ir::BasicBlock newBlock((*bb_it)->label, (*bb_it)->id, (*bb_it)->instructions, 
			(*bb_it)->comment );
		
		report(" adding block " << newBlock.label);
		
		blockMapping[*bb_it] = subkernelCfg->insert_block(newBlock);
	}
	
	typedef std::pair<std::string, std::string> LabelPair;
	std::set< LabelPair > internalEdgeSet;
	
	for (BasicBlockSet::iterator bb_it = sourceBlocks.begin();
		bb_it != sourceBlocks.end(); ++bb_it) {
		
		for (ir::BasicBlock::EdgePointerVector::iterator edge_it = (*bb_it)->out_edges.begin();
			edge_it != (*bb_it)->out_edges.end(); ++edge_it ) {
		
			bool isExitEdge = (*edge_it)->tail == source->cfg()->get_exit_block();
			bool isBarrierExit = doesBarrierTerminateBlock((*edge_it)->head);
			bool isExternalEdge = sourceBlocks.find((*edge_it)->tail) == sourceBlocks.end();
			
			if (isExitEdge) {
				report("  this block exits");
			}
			
			if (isExternalEdge || isBarrierExit) {
				
				ir::BasicBlock handler;
				
				std::string suffix = ((*edge_it)->tail->label != "" ? "_to_" : "");
				handler.label = (*edge_it)->head->label + "_exit_handler" + suffix + 
					(*edge_it)->tail->label.substr(4);
				
				int flags = (isBarrierExit ? ExternalEdge::F_barrier: 0) | (isExternalEdge ? ExternalEdge::F_external: 0);
				ThreadExitType entryStatus;
				
				if (isBarrierExit) {
					entryStatus = Thread_barrier;
				}
				else if (isExitEdge) {
					entryStatus = Thread_exit;
					handler.label = (*edge_it)->head->label + "_thread_exit";
				}
				else {
					entryStatus = Thread_subkernel;
				}
				
				ir::ControlFlowGraph::iterator handlerBlock = subkernelCfg->insert_block(handler);
				
				outEdges.push_back(ExternalEdge(**edge_it, handlerBlock, 0, entryStatus, flags));
				
				report("  adding EXTERNAL OUT-Edge " << (*edge_it)->head->label << " -> " 
					<< (*edge_it)->tail->label);
			}
			else {
				report("  - replicating internal edge " << (*edge_it)->head->label << " -> " 
					<< (*edge_it)->tail->label);
				
				LabelPair blockPair((*edge_it)->head->label, (*edge_it)->tail->label);
				if (internalEdgeSet.find(blockPair) == internalEdgeSet.end()) {
					internalEdgeSet.insert(blockPair);
					internalEdges.push_back(**edge_it);
				}
			}
		}
		
		for (ir::BasicBlock::EdgePointerVector::iterator edge_it = (*bb_it)->in_edges.begin();
			edge_it != (*bb_it)->in_edges.end(); ++edge_it) {
			
			bool isEntryEdge = (*edge_it)->head == source->cfg()->get_entry_block();
			bool isBarrierExit = doesBarrierTerminateBlock((*edge_it)->head);
			bool isExternalEdge = sourceBlocks.find((*edge_it)->head) == sourceBlocks.end();
			
			if (!isEntryEdge && (isExternalEdge || isBarrierExit)) {
			
				ir::BasicBlock handler;
				std::string suffix = ((*edge_it)->head->label != "" ? "_from_" : "");
				handler.label = (*edge_it)->tail->label + "_entry_handler" + suffix +
					(*edge_it)->head->label.substr(4);
				ir::ControlFlowGraph::iterator handlerBlock = subkernelCfg->insert_block(handler);
				
				// assign unique entryId 
				SubkernelId entryId = ExternalEdge::getEncodedEntry(id, (SubkernelId)(inEdges.size() + 1));
				
				int flags = (isBarrierExit ? ExternalEdge::F_barrier: 0) | (isExternalEdge ? ExternalEdge::F_external: 0);
				ThreadExitType entryStatus = (isBarrierExit ? Thread_barrier : Thread_subkernel);
				inEdges.push_back(ExternalEdge(**edge_it, handlerBlock, entryId, entryStatus, flags));
				
				report("  adding EXTERNAL IN-Edge " << (*edge_it)->head->label << " -> " 
					<< (*edge_it)->tail->label << " with entry ID " << entryId);
			}
			if (isEntryEdge) {
				report(" ENTRY EDGE: " << (*edge_it)->head->label << " -> " << (*edge_it)->tail->label);
				LabelPair blockPair((*edge_it)->head->label, (*edge_it)->tail->label);
				if (internalEdgeSet.find(blockPair) == internalEdgeSet.end()) {
					internalEdgeSet.insert(blockPair);
					internalEdges.push_back(**edge_it);
				}
			}
		}
	}
	
	blockMapping[source->cfg()->get_entry_block()] = subkernelCfg->get_entry_block();
	blockMapping[source->cfg()->get_exit_block()] = subkernelCfg->get_exit_block();
	
	// create internal edges
	report("Creating internal edges");
	
	for (std::vector< ir::BasicBlock::Edge >::iterator edge_it = internalEdges.begin();
		edge_it != internalEdges.end(); ++edge_it) {
		
		report(" looking in block mapping: " << edge_it->head->label << " -> " << edge_it->tail->label);
		
		bool isBarrierExit = doesBarrierTerminateBlock(edge_it->head);
		
		report("  examined terminator");
		
		if (!isBarrierExit) {
			if (blockMapping.find(edge_it->head) == blockMapping.end()) {
				assert(0 && "Failed to find predecessor block in mapping");
			}
			if (blockMapping.find(edge_it->tail) == blockMapping.end()) {
				report("  failed to find successor block '" << edge_it->tail->label << "' in mapping");
				assert(0 && "Failed to find successor block in mapping");
			}
		
			report("  instantiating internal edge");
		
			ir::BasicBlock::Edge internalEdge(blockMapping[edge_it->head], 
				blockMapping[edge_it->tail], edge_it->type);
			
			report("  adding internal edge: " << internalEdge.head->label << " -> " 
				<< internalEdge.tail -> label << " type: " << ir::ControlFlowGraph::toString(edge_it->type));
			subkernelCfg->insert_edge(internalEdge);
		}
	}
	
	// identify frontier blocks along in eges
	report(" identifying targets of external IN edges");
	for (ExternalEdgeVector::iterator edge_it = inEdges.begin();
		edge_it != inEdges.end(); ++edge_it) {
		
		edge_it->frontierBlock = blockMapping[edge_it->sourceEdge.tail];
		
		ir::BasicBlock::Edge handlerEdge(edge_it->handler, edge_it->frontierBlock, 
			ir::BasicBlock::Edge::Branch);
		subkernelCfg->insert_edge(handlerEdge);
	}
	
	// identify frontier blocks along out eges
	report(" identifying sources of external OUT edges");
	for (ExternalEdgeVector::iterator edge_it = outEdges.begin();
		edge_it != outEdges.end(); ++edge_it) {
		
		edge_it->frontierBlock = blockMapping[edge_it->sourceEdge.head];
		
		ir::BasicBlock::Edge handlerEdge(edge_it->frontierBlock, edge_it->handler, 
			edge_it->sourceEdge.type);
		subkernelCfg->insert_edge(handlerEdge);
	}
}

//! \brief identifies divergent control flow and constructs unreachable handlers for entries and exits
void analysis::KernelPartitioningPass::Subkernel::_analyzeBarriers(
	ir::PTXKernel *source, EdgeVector &internalEdges, BasicBlockMap &blockMapping) {
	report(" _analyzeBarriers()");
}

//! \brief identifies divergent control flow and constructs unreachable handlers for entries and exits
void analysis::KernelPartitioningPass::Subkernel::_analyzeDivergentControlFlow(
	ir::PTXKernel *source, EdgeVector &internalEdges, BasicBlockMap &blockMapping) {
	report(" _analyzeDivergentControlFlow()");
	
	// enumerate blocks with conditional branches
	std::unordered_set< ir::BasicBlock::Pointer > divergentBlocks;
	
	std::unordered_set< ir::BasicBlock::Pointer > frontierBlockSet;
	for (ExternalEdgeVector::iterator ext_it = outEdges.begin(); 
		ext_it != outEdges.end(); ++ext_it) {
	
		frontierBlockSet.insert(ext_it->frontierBlock);
	}
	
	// collect blocks with conditional terminators
	ir::ControlFlowGraph *cfg = subkernel->cfg();
	for (ir::ControlFlowGraph::iterator bb_it = cfg->begin(); bb_it != cfg->end(); ++bb_it) {
		if (bb_it->instructions.size()) {
			ir::PTXInstruction *terminator = static_cast<ir::PTXInstruction*>(bb_it->instructions.back());
			if (terminator->opcode == ir::PTXInstruction::Bra && terminator->pg.type == ir::PTXOperand::pred &&
				(terminator->pg.condition == ir::PTXOperand::Pred || terminator->pg.condition == ir::PTXOperand::InvPred) &&
				terminator->pg.addressMode == ir::PTXOperand::Register) {
	
				// is it already an external edge? If so, ignore it.
				if (frontierBlockSet.find(bb_it) == frontierBlockSet.end()) {
					// if it's potentially divergent and an internal edge, add to list of divergence sites		
					divergentBlocks.insert(bb_it);
				}
			}
		}
	}
	
	report("as a reminder, this partition contains " << sourceBlocks.size() << " blocks:");
	BasicBlockMap inverseBlockMap;
	for (auto p_it = sourceBlocks.begin(); p_it != sourceBlocks.end(); ++p_it){ 
		report("  " << (*p_it)->label);
		
		inverseBlockMap[blockMapping[*p_it]] = *p_it;
	}
	
	report("  " << divergentBlocks.size() << " divergent blocks");
	for (auto bb_it = divergentBlocks.begin(); bb_it != divergentBlocks.end(); ++bb_it) {
		report("   " << (*bb_it)->label);

		_createDivergentBranch(inverseBlockMap, *bb_it);
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////////

/*! \brief performs divergence analysis and creates explicit handlers for divergent branches

1.) divergent branches with two internal out edges receive an additional handler block
	according to method described in CGO paper
	
2.) divergent branch with one external out edge
	- two successors: subkernel exit, uniform-internal-taken
	- subkernel exit: conditional select for resume point

3.) divergent branch with two external out edges
	- merge successive handlers into single handler
	- conditional select for resume point		
	
	\param inverseBlockMapping maps subkernel blocks onto the original kernel
	\param bb pointer to block terminated by a divergent branch
*/
void analysis::KernelPartitioningPass::Subkernel::_createDivergentBranch(
	BasicBlockMap &inverseBlockMapping, ir::BasicBlock::Pointer bb) {

	report("createDivergentBranch(" << bb->label << ")");

	// create a divergentbranch entry
	ir::PTXInstruction *terminator = static_cast<ir::PTXInstruction*>(bb->instructions.back());
	ir::ControlFlowGraph *subkernelCfg = subkernel->cfg();
	
	assert(bb->successors.size() == 2);
	
	//
	// classify successors as external or internal
	//
	DivergentBranch::Flags divergenceFlags[] = {
		DivergentBranch::Diverge_true_external,
		DivergentBranch::Diverge_true_internal,
		DivergentBranch::Diverge_false_external,
		DivergentBranch::Diverge_false_internal,
	};
	
	DivergentBranch divergence(0, bb, 0);
	
	int successorIndex[] = {0, 1};	// [0] is true target, [1] is false target
	for (ir::BasicBlock::EdgePointerVector::iterator out_it = bb->out_edges.begin();
		out_it != bb->out_edges.end(); ++out_it) {
		
		if ((*out_it)->type == ir::BasicBlock::Edge::Branch) {
			successorIndex[0] = (int)(out_it - bb->out_edges.begin());
		}
		else {
			successorIndex[1] = (int)(out_it - bb->out_edges.begin());
		}
	}
	for (int i = 0; i < 2; i++) {
		if (bb->out_edges.at(successorIndex[i])->tail != bb->successors.at(successorIndex[i])) {
			std::swap(successorIndex[0], successorIndex[1]);
		}
	}
		
	int flags = 0;
	bool completelyInternal = true;
	for (int i = 0; i < 2; i++) {
		if (sourceBlocks.find(inverseBlockMapping[bb->successors[ successorIndex[i] ]]) == sourceBlocks.end()) {
			flags |= divergenceFlags[i*2];
			completelyInternal = false;
			report("  successor(" << i << ") " << bb->successors[successorIndex[i]]->label << " NOT in partition");
		}
		else {
			flags |= divergenceFlags[i*2+1];
			
			ir::BasicBlock handler;
			handler.label = bb->label + "_to_" + bb->successors[successorIndex[i]]->label + "_divergentEntry";
			ir::ControlFlowGraph::iterator handlerTaken = subkernelCfg->insert_block(handler);
			
			SubkernelId entryId = ExternalEdge::getEncodedEntry(id, (SubkernelId)(inEdges.size() + 1));
		
			ExternalEdge takenInEdge(inverseBlockMapping[bb], bb->successors[successorIndex[i]], handlerTaken, entryId);
			inEdges.insert(inEdges.end(), takenInEdge);
			ir::BasicBlock::Edge takenEntryEdge(handlerTaken, bb->successors[successorIndex[i]], ir::BasicBlock::Edge::Branch);		
			subkernelCfg->insert_edge(takenEntryEdge);
		
			int entryIndex = i;
			if (terminator->pg.condition == ir::PTXOperand::nPT) {
				entryIndex = 1 - i;
			}
			divergence.targetEntryIds[i] = entryId;
			
			report("  successor(" << i << ") " << bb->successors[successorIndex[i]]->label << " in partition");
		}
	}

	//
	// Construct handler blocks for the divergent branch
	//
	std::string prefix = bb->label + "_to_" + terminator->d.identifier;
	SubkernelId entryId = 0;
	
	ir::ControlFlowGraph::iterator handlerBlock;
	
	ir::BasicBlock handler;
	handler.label = prefix + "_divergentYield";
	handlerBlock = subkernelCfg->insert_block(handler);
	
	subkernelCfg->insert_edge(ir::BasicBlock::Edge(bb, handlerBlock, ir::BasicBlock::Edge::Dummy));
	
	ExternalEdge externalEdge(inverseBlockMapping[bb], handlerBlock, entryId, 
		Thread_branch, ExternalEdge::F_divergence);
		
	externalEdge.frontierBlock = bb;
	outEdges.insert(outEdges.end(), externalEdge);
	
	divergence.flags = flags;
	divergence.outEdgeIndex = outEdges.size() - 1;
	divergentBranches.push_back(divergence);
	
	report(" adding divergent branch out-edge");

}

////////////////////////////////////////////////////////////////////////////////////////////////////

void analysis::KernelPartitioningPass::Subkernel::_determineRegisterUses(
	analysis::DataflowGraph::RegisterSet &uses) {

	ir::ControlFlowGraph *cfg = subkernel->cfg();
	std::unordered_set< ir::BasicBlock::Pointer > handlerBlocks;
	
	for (ExternalEdgeVector::iterator edge_it = inEdges.begin(); edge_it != inEdges.end(); ++edge_it) {
		handlerBlocks.insert(edge_it->handler);
	}
	for (ExternalEdgeVector::iterator edge_it = outEdges.begin(); edge_it != outEdges.end(); ++edge_it) {
		handlerBlocks.insert(edge_it->handler);
	}
	for (ir::ControlFlowGraph::iterator block_it = cfg->begin(); block_it != cfg->end(); ++block_it) {
		if (handlerBlocks.find(block_it) != handlerBlocks.end()) {
			continue;
		}
		for (ir::BasicBlock::InstructionList::iterator inst_it = block_it->instructions.begin();
			inst_it != block_it->instructions.end(); ++inst_it) {
			ir::PTXInstruction *instr = static_cast<ir::PTXInstruction*>(*inst_it);
			
			ir::PTXOperand ir::PTXInstruction::*operands[] = {
				&ir::PTXInstruction::pg,
				&ir::PTXInstruction::pq,
				&ir::PTXInstruction::d,
				&ir::PTXInstruction::a,
				&ir::PTXInstruction::b,
				&ir::PTXInstruction::c
			};
			for (int i = 0; i < 6; i++) {
				ir::PTXOperand &operand = (instr->*operands[i]);
				if (operand.addressMode == ir::PTXOperand::Register || 
					operand.addressMode == ir::PTXOperand::Indirect) {
					uses.insert(operand.reg);
				}
			}
		}
	}	
}

////////////////////////////////////////////////////////////////////////////////////////////////////

/*!
	create a handler block for each in edge that restores values
*/
void analysis::KernelPartitioningPass::Subkernel::_createExternalHandlers(
	analysis::DataflowGraph *sourceDfg,
	analysis::DataflowGraph *subkernelDfg,
	const RegisterOffsetMap &registerOffsets) {
	
	assert(sourceDfg && subkernelDfg);
	
	report("Subkernel::_createExternalHandlers()");
	
	analysis::DataflowGraph::IteratorMap cfgToDfg = sourceDfg->getCFGtoDFGMap();
	analysis::DataflowGraph::IteratorMap subkernelCfgToDfg = subkernelDfg->getCFGtoDFGMap();
	
	analysis::DataflowGraph::RegisterSet usedRegisters;
	_determineRegisterUses(usedRegisters);
	
	report("  visiting external IN-edges");
	for (ExternalEdgeVector::iterator edge_it = inEdges.begin();
		edge_it != inEdges.end(); ++edge_it) {
		
		report("    in-edge");
		
		assert(subkernelCfgToDfg.find(edge_it->handler) != subkernelCfgToDfg.end());		
		assert(cfgToDfg.find(edge_it->criticalLiveness()) != cfgToDfg.end() && 
			"failed to find liveness block in DFG");
		
		// restore live values
		RegisterSet aliveValues = cfgToDfg[edge_it->criticalLiveness()]->aliveOut();
				
		assert(subkernelCfgToDfg.find(edge_it->handler) != subkernelCfgToDfg.end() && 
			"failed to find handler in subkernel DFG");
		
		auto handlerDfgBlock = subkernelCfgToDfg[edge_it->handler];
		
		report("    IN-edge: " << edge_it->handler->label << " -> " << edge_it->frontierBlock->label 
			<< " (" << aliveValues.size() << " live values");
		
		edge_it->handler->comment = boost::lexical_cast<std::string>(aliveValues.size()) + 
			" live-in values; entry-ID: " + boost::lexical_cast<std::string>(edge_it->entryId);

		_spillLiveValues(subkernelDfg, handlerDfgBlock, usedRegisters, aliveValues, registerOffsets, true);
		
		ir::PTXInstruction bra(ir::PTXInstruction::Bra);
		bra.d = ir::PTXOperand(ir::PTXOperand::Label, edge_it->frontierBlock->label);
		subkernelDfg->insert(handlerDfgBlock, bra);
	}
	
	std::unordered_map< ir::BasicBlock::Pointer, std::vector<ExternalEdge> > frontierExitBlocks;
	
	// create a handler block for each out-edge that stores values
	report("  visiting external OUT-edges");
	for (ExternalEdgeVector::iterator edge_it = outEdges.begin();
		edge_it != outEdges.end(); ++edge_it) {
		
		assert(subkernelCfgToDfg.find(edge_it->handler) != subkernelCfgToDfg.end());
		assert(cfgToDfg.find(edge_it->criticalLiveness()) != cfgToDfg.end() && 
			"failed to find critical block in DFG");
		assert(subkernelCfgToDfg.find(edge_it->handler) != subkernelCfgToDfg.end() && 
			"failed to find handler in subkernel DFG");
		
		// restore live values
		RegisterSet aliveValues = cfgToDfg[edge_it->criticalLiveness()]->aliveOut();
		auto handlerDfgBlock = subkernelCfgToDfg[edge_it->handler];
		
		report("    OUT-edge: " << edge_it->frontierBlock->label << " -> " << edge_it->handler->label
			<< " (" << aliveValues.size() << " live values");
		
		edge_it->handler->comment = boost::lexical_cast<std::string>(aliveValues.size()) 
			+ " live-out values";
		
		_spillLiveValues(subkernelDfg, handlerDfgBlock, usedRegisters, aliveValues, registerOffsets, false);

		ThreadExitType exitStatus = edge_it->exitStatus;
		if (edge_it->flags & ExternalEdge::F_barrier) {
			exitStatus = Thread_barrier;
		}
		
		ir::PTXOperand yieldTarget(edge_it->entryId, ir::PTXOperand::u32);
		size_t edgeIndex = (size_t)(size_t)(edge_it - outEdges.begin());
		
		report("is this a divergent handler? edgeIndex " << edgeIndex);
		
		for (auto divergence_it = divergentBranches.begin(); divergence_it != divergentBranches.end();
			++divergence_it) {
		
			report("divergent branch [frontier block " << divergence_it->frontierBlock->label << "]");
			report("  outEdgeIndex: " << divergence_it->outEdgeIndex);
		
			if (divergence_it->outEdgeIndex < outEdges.size()) {
				report("  it's a real ExternalEdge");
				report("    flags: " << outEdges.at(divergence_it->outEdgeIndex).exitStatus);
			}
		
			if (divergence_it->outEdgeIndex == edgeIndex) {
				ExternalEdge &outEdge = outEdges.at(divergence_it->outEdgeIndex);
				auto handlerDfgBlock = subkernelCfgToDfg[outEdge.handler];
		
				ir::PTXInstruction selp(ir::PTXInstruction::SelP);
				selp.type = ir::PTXOperand::u32;
				selp.d = ir::PTXOperand(ir::PTXOperand::Register, ir::PTXOperand::u32, subkernelDfg->newRegister());
				selp.a = ir::PTXOperand(divergence_it->targetEntryIds[0], ir::PTXOperand::u32);
				selp.b = ir::PTXOperand(divergence_it->targetEntryIds[1], ir::PTXOperand::u32);
				selp.c = getTerminator(outEdge.sourceEdge.head)->pg;
				subkernelDfg->insert(handlerDfgBlock, selp, 0);
				yieldTarget = selp.d;
				
				report("  found yield target");
				
				break;
			}
		}
	
		_createExit(handlerDfgBlock, subkernelDfg, exitStatus, yieldTarget);
		
		report("  adding " << edge_it->frontierBlock->label << " to frontierExitBlocks");
		
		if (!(edge_it->flags & ExternalEdge::F_divergence)) {
			frontierExitBlocks[edge_it->frontierBlock].push_back(*edge_it);
		}
	}
	
	
	
	_updateHandlerControlFlow(frontierExitBlocks, subkernelDfg);
}

void analysis::KernelPartitioningPass::Subkernel::_createExit(analysis::DataflowGraph::iterator block, 
	analysis::DataflowGraph *subkernelDfg, ThreadExitType type, const ir::PTXOperand & target) {
	
	report("  creating exit in block " << block->block()->label);
	
	ir::PTXInstruction move(ir::PTXInstruction::Mov);
	move.a = ir::PTXOperand(ir::PTXOperand::Address, ir::PTXOperand::u32, "_Zocelot_resume_status");
	move.d = ir::PTXOperand(ir::PTXOperand::Register, ir::PTXOperand::u32, subkernelDfg->newRegister());
	subkernelDfg->insert(block, move);
	
	ir::PTXInstruction store(ir::PTXInstruction::St);
	store.type = ir::PTXOperand::u32;
	store.addressSpace = ir::PTXInstruction::Local;
	store.d = ir::PTXOperand(ir::PTXOperand::Indirect, ir::PTXOperand::u32, move.d.reg, 0);
	store.a = ir::PTXOperand(type, ir::PTXOperand::u32);
	subkernelDfg->insert(block, store);
	
	if (type != Thread_exit) {
		move.a = ir::PTXOperand(ir::PTXOperand::Address, ir::PTXOperand::u32, "_Zocelot_resume_point");
		move.d = ir::PTXOperand(ir::PTXOperand::Register, ir::PTXOperand::u32, subkernelDfg->newRegister());
		subkernelDfg->insert(block, move);
	
		store.type = ir::PTXOperand::u32;
		store.addressSpace = ir::PTXInstruction::Local;
		store.d = ir::PTXOperand(ir::PTXOperand::Indirect, ir::PTXOperand::u32, move.d.reg, 0);
		store.a = target;
		subkernelDfg->insert(block, store);
	}
	
	ir::PTXInstruction exit(ir::PTXInstruction::Exit);
	subkernelDfg->insert(block, exit);
}

void analysis::KernelPartitioningPass::Subkernel::_spillLiveValues(
	analysis::DataflowGraph *subkernelDfg, 
	analysis::DataflowGraph::iterator handlerDfgBlock, 
	const analysis::DataflowGraph::RegisterSet &usedRegisters,
	const RegisterSet &aliveValues,
	const RegisterOffsetMap &registerOffsets,
	bool loadLive) {
	
	ir::PTXInstruction move(ir::PTXInstruction::Mov);
	
	size_t spilled = 0;
	for (RegisterSet::const_iterator alive_it = aliveValues.begin();
		alive_it != aliveValues.end(); ++alive_it) {
	
		if (usedRegisters.find(*alive_it) == usedRegisters.end()) {
			report("      skipping alive: " << alive_it->id << " [type: " 
				<< ir::PTXOperand::toString(alive_it->type) << "]");
			continue;
		}

		report("      alive: " << alive_it->id << " [type: " 
			<< ir::PTXOperand::toString(alive_it->type) << ", offset: " 
			<< registerOffsets.find(alive_it->id)->second << "]");
		
		if (!spilled++) {
			move.a = ir::PTXOperand(ir::PTXOperand::Address, ir::PTXOperand::u32, "_Zocelot_spill_area");
			move.d = ir::PTXOperand(ir::PTXOperand::Register, ir::PTXOperand::u32, subkernelDfg->newRegister());
			
			subkernelDfg->insert(handlerDfgBlock, move);
		}

		ir::PTXInstruction restore(ir::PTXInstruction::St);
		
		if (loadLive) {
			restore.opcode = ir::PTXInstruction::Ld;
			restore.type = alive_it->type;
			restore.addressSpace = ir::PTXInstruction::Local;
			restore.a = ir::PTXOperand(ir::PTXOperand::Indirect, ir::PTXOperand::u32, move.d.reg, 
				registerOffsets.find(alive_it->id)->second);
			restore.d = ir::PTXOperand(ir::PTXOperand::Register, alive_it->type, alive_it->id);
		}
		else {
			restore.opcode = ir::PTXInstruction::St;
			restore.type = alive_it->type;
			restore.addressSpace = ir::PTXInstruction::Local;
			restore.d = ir::PTXOperand(ir::PTXOperand::Indirect, ir::PTXOperand::u32, move.d.reg, 
				registerOffsets.find(alive_it->id)->second);
			restore.a = ir::PTXOperand(ir::PTXOperand::Register, alive_it->type, alive_it->id);
		}
		subkernelDfg->insert(handlerDfgBlock, restore);
	}
}

void analysis::KernelPartitioningPass::Subkernel::_updateHandlerControlFlow(
	ExternalEdgeMap &frontierExitBlocks, analysis::DataflowGraph *subkernelDfg) {

	report("Frontier exit blocks:");
	
	analysis::DataflowGraph::IteratorMap subkernelCfgToDfg = subkernelDfg->getCFGtoDFGMap();
	
	report("  obtained CFG-to-DFG mapping. Now visiting " << frontierExitBlocks.size() 
		<< " frontier exit blocks");
	
	for (auto block_it = frontierExitBlocks.begin(); 
		block_it != frontierExitBlocks.end(); ++block_it) {	
		
		report("   frontier exit block: " << block_it->first->label);
	
		// update control flow instructions
		ir::PTXInstruction *terminator = static_cast<ir::PTXInstruction *>(
			block_it->first->instructions.back());
		
		report(" block " << block_it->first->label << " (" << block_it->second.size() 
			<< " external edges) terminator: " << terminator->toString());
		
		if (terminator->opcode == ir::PTXInstruction::Bra) {
			report("   branch");
			for (ExternalEdgeVector::iterator edge_it = block_it->second.begin(); 
				edge_it != block_it->second.end(); ++edge_it) {
				
				ExternalEdge &externalEdge = *edge_it;
				if (externalEdge.sourceEdge.type == ir::BasicBlock::Edge::Branch) {
					report(" 1 external edge, modifying branch target to point to handler");
					terminator->d = ir::PTXOperand(ir::PTXOperand::Label, edge_it->handler->label);
				}
			}
		}
		else if (terminator->opcode == ir::PTXInstruction::Call) {
			assert(0 && "unhandled");
		}
		else if (terminator->opcode == ir::PTXInstruction::Bar) {
			report("   barrier");
			report("    block: " << block_it->first->label);

			auto dfgBlock = subkernelCfgToDfg[block_it->first];
			analysis::DataflowGraph::InstructionVector::iterator instr_it = dfgBlock->instructions().end();
			--instr_it;
			
			subkernelDfg->erase(dfgBlock, instr_it );
		}
		else if (terminator->opcode == ir::PTXInstruction::Exit) {
			report("   exit");
			ExternalEdge &externalEdge = block_it->second.front();
			terminator->opcode = ir::PTXInstruction::Bra;
			terminator->d = ir::PTXOperand(ir::PTXOperand::Label, externalEdge.handler->label);
		}
		else if (terminator->opcode == ir::PTXInstruction::Ret) {
			assert(0 && "unhandled return instruction");
		}
		else {
			// fall-through
			report(" fall-through non-control-flow instruction to external edge: " 
				<< terminator->toString());
		}
	}	
	
	report("end frontier exit blocks:");		
}


////////////////////////////////////////////////////////////////////////////////////////////////////

