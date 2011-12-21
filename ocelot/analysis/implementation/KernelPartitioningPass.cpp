/*!
	\file KernelPartitioningPass.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date November 17, 2011
	\brief implements kernel partitioning
*/

// Ocelot includes
#include <ocelot/analysis/interface/DataflowGraph.h>
#include <ocelot/analysis/interface/KernelPartitioningPass.h>

// Hydrazine includes
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/math.h>

//////////////////////////////////////////////////////////////////////////////////////////////////

#define Ocelot_Exception(x) { std::stringstream ss; ss << x; std::cerr << x << std::endl; \
	throw hydrazine::Exception(ss.str()); }
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif
////////////////////////////////////////////////////////////////////////////////////////////////////

#define REPORT_BASE 1

#define REPORT_EMIT_SUBKERNEL_PTX 0

////////////////////////////////////////////////////////////////////////////////////////////////////

analysis::KernelPartitioningPass::KernelPartitioningPass() {

}

analysis::KernelPartitioningPass::~KernelPartitioningPass() {
}

analysis::KernelPartitioningPass::KernelGraph *
 analysis::KernelPartitioningPass::runOnFunction(ir::PTXKernel &ptxKernel, SubkernelId baseId) {
	report("KernelPartitioningPass::runOnFunction(" << ptxKernel.name << ")");
	
	return new KernelGraph(&ptxKernel, baseId);
}

////////////////////////////////////////////////////////////////////////////////////////////////////

analysis::KernelPartitioningPass::KernelGraph::KernelGraph(
	ir::PTXKernel *_kernel, 
	SubkernelId baseId)
: 
	ptxKernel(_kernel) 
{
	
	_partition(baseId);
	
		/*
	_createExits();
	_createSchedulers();
	_createDivergenceHandlers();
	*/
}

analysis::KernelPartitioningPass::KernelGraph::~KernelGraph() {
	subkernels.clear();
}


void analysis::KernelPartitioningPass::KernelGraph::_partitionMaximumSize(SubkernelId baseId) {

	report("KernelGraph::_partitionMaximumSize()");
	
	Subkernel subkernel(baseId);
	
	// add all blocks to subkernel
	ir::ControlFlowGraph *cfg = ptxKernel->cfg();
	for (ir::ControlFlowGraph::iterator bb_it = cfg->begin(); bb_it != cfg->end(); ++bb_it) {
		subkernel.sourceBlocks.insert(bb_it);
	}
	
	subkernel.create(ptxKernel, registerOffsets);
	subkernels.insert(std::make_pair(subkernel.id, subkernel));
}

void analysis::KernelPartitioningPass::KernelGraph::_partitionMinimumSize(SubkernelId baseId) {

	report("KernelGraph::_partitionMinimumSize()");
	
	// add all blocks to subkernel
	ir::ControlFlowGraph *cfg = ptxKernel->cfg();
	for (ir::ControlFlowGraph::iterator bb_it = cfg->begin(); bb_it != cfg->end(); ++bb_it) {
		Subkernel subkernel(baseId + subkernels.size());
		subkernel.sourceBlocks.insert(bb_it);
		subkernel.create(ptxKernel, registerOffsets);
		subkernels.insert(std::make_pair(subkernel.id, subkernel));
	}
}


/*!
	\brief constructs a partitioning of the PTX kernel according to some heuristic
		then uses these to create subkernels
*/
void analysis::KernelPartitioningPass::KernelGraph::_partition(SubkernelId baseId) {
	//
	// select partitioning heuristic here
	//
	// A partitioning constructs a set of basic-block sets. The edges are then
	// classified as internal if they do not cross partitions and external if they do.
	// External edges are further classified as in-edges or out-edges from the perspective
	// of each subkernel.
	//
	
	// construct subkernels according to one of several partitioning heuristics
	_partitionMinimumSize(baseId);
}

/*!
	\brief visits each subkernel and adds handlers for in-edges
*/
void analysis::KernelPartitioningPass::KernelGraph::_createEntries() {
	// for 
}

/*!
	\brief visits each subkernel and adds handlers for out-edges
*/
void analysis::KernelPartitioningPass::KernelGraph::_createExits() {

}

/*!
	\brief inserts a scheduler block 
*/
void analysis::KernelPartitioningPass::KernelGraph::_createSchedulers() {

}

/*!

*/
void analysis::KernelPartitioningPass::KernelGraph::_createDivergenceHandlers() {

}
			
////////////////////////////////////////////////////////////////////////////////////////////////////			
analysis::KernelPartitioningPass::Subkernel::Subkernel(SubkernelId _id): id(_id) {

}

void analysis::KernelPartitioningPass::Subkernel::create(ir::PTXKernel *source,
	const RegisterOffsetMap &registerOffsets) {

	report("Subkernel::create(" << source->name << ")");
	
	analysis::DataflowGraph sourceDfg;
	sourceDfg.analyze(*source);
	
	_create(source);
	
	analysis::DataflowGraph subkernelDfg;
	subkernelDfg.analyze(*subkernel);
	
	_createExternalHandlers(&sourceDfg, &subkernelDfg, registerOffsets);
	
	#if REPORT_BASE && REPORT_EMIT_SUBKERNEL_PTX
	subkernel->write(std::cout);
	#endif
}


void analysis::KernelPartitioningPass::Subkernel::_create(ir::PTXKernel *source) {

	report("Subkernel::_create(" << source->name << ")");
	
	std::stringstream ss;
	ss << "_subkernel_" << source->name << "_" << id;
	
	subkernel = new ir::PTXKernel(ss.str(), false, source->module);
	for (ir::Kernel::ParameterVector::const_iterator arg_it = source->arguments.begin();
		arg_it != source->arguments.end(); ++arg_it) {
		
		subkernel->arguments.push_back(*arg_it);
	}
	
	ir::ControlFlowGraph *subkernelCfg = subkernel->cfg();
	
	std::vector< ir::BasicBlock::Edge > internalEdges;
	std::unordered_map< ir::BasicBlock::Pointer, ir::BasicBlock::Pointer> blockMapping;
	
	for (BasicBlockSet::iterator bb_it = sourceBlocks.begin();
		bb_it != sourceBlocks.end(); ++bb_it) {
		
		ir::BasicBlock newBlock((*bb_it)->label, (*bb_it)->id, (*bb_it)->instructions, 
			(*bb_it)->comment );
		
		report(" adding block " << newBlock.label);
		
		blockMapping[*bb_it] = subkernelCfg->insert_block(newBlock);
		
		for (ir::BasicBlock::EdgePointerVector::iterator edge_it = (*bb_it)->out_edges.begin();
			edge_it != (*bb_it)->out_edges.end(); ++edge_it ) {
		
			if (sourceBlocks.find((*edge_it)->tail) == sourceBlocks.end()) {
				ir::BasicBlock handler;
				handler.label = (*edge_it)->head->label + "_external_out_handler";
				ir::ControlFlowGraph::iterator handlerBlock = subkernelCfg->insert_block(handler);
				
				outEdges.push_back(ExternalEdge(**edge_it, handlerBlock));
				report("  adding EXTERNAL OUT-Edge " << (*edge_it)->head->label << " -> " 
					<< (*edge_it)->tail->label);
			}
			else {
				report("  replicating internal edge " << (*edge_it)->head->label << " -> " 
					<< (*edge_it)->tail->label);
				internalEdges.push_back(**edge_it);
			}
		}
		
		for (ir::BasicBlock::EdgePointerVector::iterator edge_it = (*bb_it)->in_edges.begin();
			edge_it != (*bb_it)->in_edges.end(); ++edge_it) {
			if (sourceBlocks.find((*edge_it)->head) == sourceBlocks.end()) {
				ir::BasicBlock handler;
				handler.label = (*edge_it)->tail->label + "_external_in_handler";
				ir::ControlFlowGraph::iterator handlerBlock = subkernelCfg->insert_block(handler);
				inEdges.push_back(ExternalEdge(**edge_it, handlerBlock));
				report("  adding EXTERNAL IN-Edge " << (*edge_it)->head->label << " -> " 
					<< (*edge_it)->tail->label);
			}
		}
	}
	
	// create internal edges
	report(" creating internal edges");
	for (std::vector< ir::BasicBlock::Edge >::iterator edge_it = internalEdges.begin();
		edge_it != internalEdges.end(); ++edge_it) {
		ir::BasicBlock::Edge internalEdge(blockMapping[edge_it->head], 
			blockMapping[edge_it->tail], edge_it->type);
		subkernelCfg->insert_edge(internalEdge);
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
		if (edge_it->sourceEdge.type == ir::BasicBlock::Edge::Branch) {
			// update branch instruction
			report(" TODO: update branch instruction");
		}		
		subkernelCfg->insert_edge(handlerEdge);
	}
}

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
	
	report("  visiting external IN-edges");
	for (ExternalEdgeVector::iterator edge_it = inEdges.begin();
		edge_it != inEdges.end(); ++edge_it) {
		
		assert(subkernelCfgToDfg.find(edge_it->handler) != subkernelCfgToDfg.end());
		
		// restore live values
		RegisterSet aliveValues = cfgToDfg[edge_it->sourceEdge.head]->aliveOut();
		auto handlerDfgBlock = subkernelCfgToDfg[edge_it->handler];
		
		report("    IN-edge: " << edge_it->handler->label << " -> " << edge_it->frontierBlock->label 
			<< " (" << aliveValues.size() << " live values");
		
		ir::PTXInstruction move(ir::PTXInstruction::Mov);
		
		for (RegisterSet::iterator alive_it = aliveValues.begin();
			alive_it != aliveValues.end(); ++alive_it) {
			
			report("      alive-in: " << alive_it->id << " [type: " 
				<< ir::PTXOperand::toString(alive_it->type) << "]");
			
			if (alive_it == aliveValues.begin()) {
				move.a = ir::PTXOperand(ir::PTXOperand::Address, ir::PTXOperand::u32, "_Zocelot_spill_area");
				move.d = ir::PTXOperand(ir::PTXOperand::Register, ir::PTXOperand::u32, subkernelDfg->newRegister());
				
				subkernelDfg->insert(handlerDfgBlock, move);
			}
				
			// int offset = alive_it->id * sizeof(int*);

			// create restore
			ir::PTXInstruction load(ir::PTXInstruction::Ld);
			load.type = alive_it->type;
			load.addressSpace = ir::PTXInstruction::Local;
			load.a = ir::PTXOperand(ir::PTXOperand::Indirect, ir::PTXOperand::u32, move.d.reg, 
				registerOffsets.find(alive_it->id)->second);
			load.d = ir::PTXOperand(ir::PTXOperand::Register, alive_it->type, alive_it->id);

			subkernelDfg->insert(handlerDfgBlock, load);
		}
		
		ir::PTXInstruction bra(ir::PTXInstruction::Bra);
		bra.d = ir::PTXOperand(ir::PTXOperand::Label, edge_it->frontierBlock->label);
		subkernelDfg->insert(handlerDfgBlock, bra);
	}
	
	// create a handler block for each out-edge that stores values
	report("  visiting external OUT-edges");
	for (ExternalEdgeVector::iterator edge_it = outEdges.begin();
		edge_it != outEdges.end(); ++edge_it) {
		
		assert(subkernelCfgToDfg.find(edge_it->handler) != subkernelCfgToDfg.end());
		
		// restore live values
		RegisterSet aliveValues = cfgToDfg[edge_it->sourceEdge.head]->aliveOut();
		auto handlerDfgBlock = subkernelCfgToDfg[edge_it->handler];
		
		report("    OUT-edge: " << edge_it->frontierBlock->label << " -> " << edge_it->handler->label
			<< " (" << aliveValues.size() << " live values");
		
		ir::PTXInstruction move(ir::PTXInstruction::Mov);
		
		for (RegisterSet::iterator alive_it = aliveValues.begin();
			alive_it != aliveValues.end(); ++alive_it) {
			
			report("      alive-out: " << alive_it->id << " [type: " 
				<< ir::PTXOperand::toString(alive_it->type) << "]");
			
			if (alive_it == aliveValues.begin()) {
				move.a = ir::PTXOperand(ir::PTXOperand::Address, ir::PTXOperand::u32, "_Zocelot_spill_area");
				move.d = ir::PTXOperand(ir::PTXOperand::Register, ir::PTXOperand::u32, subkernelDfg->newRegister());
				
				subkernelDfg->insert(handlerDfgBlock, move);
			}

			// create restore
			ir::PTXInstruction store(ir::PTXInstruction::St);
			store.type = alive_it->type;
			store.addressSpace = ir::PTXInstruction::Local;
			store.d = ir::PTXOperand(ir::PTXOperand::Indirect, ir::PTXOperand::u32, move.d.reg, 
				registerOffsets.find(alive_it->id)->second);
			store.a = ir::PTXOperand(ir::PTXOperand::Register, alive_it->type, alive_it->id);

			subkernelDfg->insert(handlerDfgBlock, store);
		}
	}
}

void analysis::KernelPartitioningPass::Subkernel::_createDivergenceHandlers() {

}

void analysis::KernelPartitioningPass::Subkernel::_createExit(
	ir::BasicBlock::Pointer block, ThreadExitType type, SubkernelId target) {
	
}

////////////////////////////////////////////////////////////////////////////////////////////////////

