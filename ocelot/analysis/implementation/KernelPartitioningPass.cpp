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

#define REPORT_BASE 1

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
	
	_partition();
}

analysis::KernelPartitioningPass::KernelGraph::~KernelGraph() {
	subkernels.clear();
}

/*!
	\brief constructs a partitioning of the PTX kernel according to some heuristic
		then uses these to create subkernels
*/
void analysis::KernelPartitioningPass::KernelGraph::_partition() {
	//
	// come up with some partitioning
	//
}

/*!
	\brief visits each subkernel and adds handlers for in-edges
*/
void analysis::KernelPartitioningPass::KernelGraph::_createEntries() {

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

bool operator<(ir::BasicBlock::Pointer x, ir::BasicBlock::Pointer y) {
	return false;
}

void analysis::KernelPartitioningPass::Subkernel::create(ir::PTXKernel *source) {
	std::stringstream ss;
	ss << "_subkernel_" << source->name << "_" << id;
	
	subkernel = new ir::PTXKernel(ss.str(), false, source->module);
	ir::ControlFlowGraph *subkernelCfg = subkernel->cfg();
	
	std::vector< ir::BasicBlock::Edge > internalEdges;
	std::map< ir::BasicBlock::Pointer, ir::BasicBlock::Pointer> blockMapping;
	
	for (BasicBlockSet::iterator bb_it = sourceBlocks.begin();
		bb_it != sourceBlocks.end(); ++bb_it) {
		
		ir::BasicBlock newBlock((*bb_it)->label, (*bb_it)->id, (*bb_it)->instructions, 
			(*bb_it)->comment );
			
		blockMapping[*bb_it] = subkernelCfg->insert_block(newBlock);
		
		for (ir::BasicBlock::EdgePointerVector::iterator edge_it = (*bb_it)->out_edges.begin();
			edge_it != (*bb_it)->out_edges.end(); ++edge_it ) {
		
			if (sourceBlocks.find((*edge_it)->tail) == sourceBlocks.end()) {
				ir::BasicBlock handler;
				outEdges.push_back(ExternalEdge(**edge_it, subkernelCfg->insert_block(handler)));
			}
			else {
				internalEdges.push_back(**edge_it);
			}
		}
		
		for (ir::BasicBlock::EdgePointerVector::iterator edge_it = (*bb_it)->in_edges.begin();
			edge_it != (*bb_it)->in_edges.end(); ++edge_it) {
			if (sourceBlocks.find((*edge_it)->head) == sourceBlocks.end()) {
				ir::BasicBlock handler;
				inEdges.push_back(ExternalEdge(**edge_it, subkernelCfg->insert_block(handler)));
			}
		}
	}
	
	// create internal edges
	for (std::vector< ir::BasicBlock::Edge >::iterator edge_it = internalEdges.begin();
		edge_it != internalEdges.end(); ++edge_it) {
		ir::BasicBlock::Edge internalEdge(blockMapping[edge_it->head], 
			blockMapping[edge_it->tail], edge_it->type);
		subkernelCfg->insert_edge(internalEdge);
	}
	
	// identify frontier blocks along in eges
	for (ExternalEdgeVector::iterator edge_it = inEdges.begin();
		edge_it != inEdges.end(); ++edge_it) {
		edge_it->frontierBlock = blockMapping[edge_it->sourceEdge.tail];
		
		ir::BasicBlock::Edge handlerEdge(edge_it->handler, edge_it->frontierBlock, 
			ir::BasicBlock::Edge::Branch);
		subkernelCfg->insert_edge(handlerEdge);
	}
	
	// identify frontier blocks along out eges
	for (ExternalEdgeVector::iterator edge_it = outEdges.begin();
		edge_it != outEdges.end(); ++edge_it) {
		edge_it->frontierBlock = blockMapping[edge_it->sourceEdge.head];
		ir::BasicBlock::Edge handlerEdge(edge_it->frontierBlock, edge_it->handler,
			edge_it->sourceEdge.type);
		if (edge_it->sourceEdge.type == ir::BasicBlock::Edge::Branch) {
			// update branch instruction
		}
		subkernelCfg->insert_edge(handlerEdge);
	}
}

void analysis::KernelPartitioningPass::Subkernel::_createExternalHandlers() {
	// create a handler block for each in edge that restores values
	
	analysis::DataflowGraph *sourceDfg = 0; // TODO
	analysis::DataflowGraph *subkernelDfg = 0; // TODO
	
	analysis::DataflowGraph::IteratorMap cfgToDfg = sourceDfg->getCFGtoDFGMap();
	analysis::DataflowGraph::IteratorMap subkernelCfgToDfg = subkernelDfg->getCFGtoDFGMap();
	
	for (ExternalEdgeVector::iterator edge_it = inEdges.begin();
		edge_it != inEdges.end(); ++edge_it) {
	
		auto handlerDfgBlock = subkernelCfgToDfg[edge_it->handler];
		
		// restore live values
		RegisterSet aliveOut; // TODO = cfgToDfg[edge_it->sourceEdge.head].aliveOut();
		for (RegisterSet::iterator alive_it = aliveOut.begin();
			alive_it != aliveOut.end(); ++alive_it) {
			
			/*
			// create restore
			ir::PTXInstruction load(ir::PTXInstruction::Ld);
			//
			// TODO
			//
			subkernelDfg->insert(handlerDfgBlock, load);
			*/
		}
		
		ir::PTXInstruction bra(ir::PTXInstruction::Bra);
		bra.d = ir::PTXOperand(ir::PTXOperand::Label, edge_it->frontierBlock->label);
		subkernelDfg->insert(handlerDfgBlock, bra);
	}
	
	// create a handler block for each out-edge that stores values
	for (ExternalEdgeVector::iterator edge_it = outEdges.begin();
		edge_it != outEdges.end(); ++edge_it) {

		auto handlerDfgBlock = subkernelCfgToDfg[edge_it->handler];
		
		// restore live values
		RegisterSet aliveOut; // TODO = cfgToDfg[edge_it->sourceEdge.head].aliveOut();
		for (RegisterSet::iterator alive_it = aliveOut.begin();
			alive_it != aliveOut.end(); ++alive_it) {
			
			/*
			// create restore
			ir::PTXInstruction load(ir::PTXInstruction::Ld);
			//
			// TODO
			//
			subkernelDfg->insert(handlerDfgBlock, load);
			*/
		}
		
	}
}

void analysis::KernelPartitioningPass::Subkernel::_createDivergenceHandlers() {

}

void analysis::KernelPartitioningPass::Subkernel::_createExit(
	ir::BasicBlock::Pointer block, ThreadExitType type, SubkernelId target) {
	
}

////////////////////////////////////////////////////////////////////////////////////////////////////

