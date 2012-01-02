/*!
	\file KernelPartitioningPass.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date November 17, 2011
	\brief implements kernel partitioning
*/

// Boost includes
#include <boost/lexical_cast.hpp>

// Ocelot includes
#include <ocelot/ir/interface/Kernel.h>
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

#define REPORT_EMIT_SUBKERNEL_PTX 1

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
	// data flow analysis
	_sourceKernelDfg = new analysis::DataflowGraph;
	_sourceKernelDfg->analyze(*ptxKernel);
	
	size_t spillRegionSize = _computeRegisterOffsets();
	
	_createSpillRegion(spillRegionSize);
	_partition(baseId);
	
		/*
	_createExits();
	_createScheduler();
	_createDivergenceHandlers();
	*/
}

analysis::KernelPartitioningPass::KernelGraph::~KernelGraph() {
	if (_sourceKernelDfg) {
		delete _sourceKernelDfg;
	}
	subkernels.clear();
}


void analysis::KernelPartitioningPass::KernelGraph::_partitionMaximumSize(SubkernelId baseId) {

	report("KernelGraph::_partitionMaximumSize()");
	
	Subkernel subkernel(baseId);
	entrySubkernelId = baseId;
	
	// add all blocks to subkernel
	ir::ControlFlowGraph *cfg = ptxKernel->cfg();
	for (ir::ControlFlowGraph::iterator bb_it = cfg->begin(); bb_it != cfg->end(); ++bb_it) {
		subkernel.sourceBlocks.insert(bb_it);
	}
	
	subkernel.create(ptxKernel, _sourceKernelDfg, registerOffsets);
	subkernels.insert(std::make_pair(subkernel.id, subkernel));
}

void analysis::KernelPartitioningPass::KernelGraph::_partitionMinimumSize(SubkernelId baseId) {

	report("KernelGraph::_partitionMinimumSize()");
	
	// add all blocks to subkernel
	ir::ControlFlowGraph *cfg = ptxKernel->cfg();
	for (ir::ControlFlowGraph::iterator bb_it = cfg->begin(); bb_it != cfg->end(); ++bb_it) {
		if (!bb_it->instructions.size()) {
			continue;
		}
		
		Subkernel subkernel(baseId + subkernels.size());
		subkernel.sourceBlocks.insert(bb_it);
		subkernel.create(ptxKernel, _sourceKernelDfg, registerOffsets);
		subkernels.insert(std::make_pair(subkernel.id, subkernel));
		
		if (subkernels.size() == 1) {
			entrySubkernelId = subkernel.id;
		}
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
	/*
	if (api::OcelotConfiguration::get().executive.yieldOverheadInstrumentation) {
		ir::PTXStatement entryCycles(ir::PTXStatement::Local);
		entryCycles.type = ir::PTXOperand::u64;
		entryCycles.name = "_Zocelot_entry_cycles";
		ptxKernel->locals.insert(std::make_pair(entryCycles.name, ir::Local(entryCycles)));	// offset 8
		
		ir::PTXStatement entryId(ir::PTXStatement::Local);
		entryId.type = ir::PTXOperand::u32;
		entryId.name = "_Zocelot_entry_id";
		ptxKernel->locals.insert(std::make_pair(entryId.name, ir::Local(entryId)));	// offset 16
		
		ir::PTXStatement entryLiveness(ir::PTXStatement::Local);
		entryLiveness.type = ir::PTXOperand::u32;
		entryLiveness.name = "_Zocelot_entry_liveness";
		ptxKernel->locals.insert(std::make_pair(entryLiveness.name, ir::Local(entryLiveness)));	// offset 20
	
		ir::PTXStatement exitCycles(ir::PTXStatement::Local);
		exitCycles.type = ir::PTXOperand::u64;
		exitCycles.name = "_Zocelot_exit_cycles";
		ptxKernel->locals.insert(std::make_pair(exitCycles.name, ir::Local(exitCycles)));	// offset 24
	
		ir::PTXStatement exitId(ir::PTXStatement::Local);
		exitId.type = ir::PTXOperand::u32;
		exitId.name = "_Zocelot_exit_id";
		ptxKernel->locals.insert(std::make_pair(exitId.name, ir::Local(exitId)));	// offset 32
		
		ir::PTXStatement exitLiveness(ir::PTXStatement::Local);
		exitLiveness.type = ir::PTXOperand::u32;
		exitLiveness.name = "_Zocelot_exit_liveness";
		ptxKernel->locals.insert(std::make_pair(exitLiveness.name, ir::Local(exitLiveness)));	// offset 36
		
		ir::PTXStatement subkernelCycles(ir::PTXStatement::Local);
		subkernelCycles.type = ir::PTXOperand::u64;
		subkernelCycles.name = "_Zocelot_subkernel_cycles";
		ptxKernel->locals.insert(std::make_pair(subkernelCycles.name, ir::Local(subkernelCycles))); // offset 40
	}
	*/
	
	ir::PTXStatement spillRegion(ir::PTXStatement::Local);
		
	spillRegion.type = ir::PTXOperand::b8;
	spillRegion.name = "_Zocelot_spill_area";
	spillRegion.array.stride.push_back((unsigned int)spillSize);
	
	ptxKernel->locals.insert(std::make_pair(spillRegion.name, ir::Local(spillRegion)));
		
	report("  Spill region size is " << spillSize);
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

*/
void analysis::KernelPartitioningPass::KernelGraph::_createDivergenceHandlers() {

}


analysis::KernelPartitioningPass::SubkernelId 
	analysis::KernelPartitioningPass::KernelGraph::getEntrySubkernel() const {
	
	return entrySubkernelId;
}
			
////////////////////////////////////////////////////////////////////////////////////////////////////			
analysis::KernelPartitioningPass::Subkernel::Subkernel(SubkernelId _id): id(_id) {

}

void analysis::KernelPartitioningPass::Subkernel::create(ir::PTXKernel *source,
	analysis::DataflowGraph *sourceDfg,
	const RegisterOffsetMap &registerOffsets) {

	report("Subkernel::create(" << source->name << ")");
	
	_create(source);
	
	analysis::DataflowGraph subkernelDfg;
	subkernelDfg.analyze(*subkernel);
	
	_createExternalHandlers(sourceDfg, &subkernelDfg, registerOffsets);
	
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
	for (ir::Kernel::LocalMap::const_iterator local_it = source->locals.begin(); 
		local_it != source->locals.end(); ++local_it) {
		subkernel->locals.insert(std::make_pair(local_it->first, local_it->second));
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
				handler.label = (*edge_it)->head->label + "_external_out_handler_" + (*edge_it)->tail->label.substr(4);
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
				handler.label = (*edge_it)->tail->label + "_external_in_handler_" + 
					(*edge_it)->head->label.substr(4);
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
	\brief compute basic mapping
*/
size_t analysis::KernelPartitioningPass::KernelGraph::_computeRegisterOffsets() {
	typedef analysis::DataflowGraph::RegisterId RegisterId;
	
	size_t bytes = 0;
	RegisterId maxRegister = _sourceKernelDfg->maxRegister();
	for (RegisterId id = 0; id <= maxRegister; id++) {
		size_t offset = sizeof(int*) * id;
		registerOffsets[id] = offset;
		bytes = offset;
	}
	return bytes;
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
		
		edge_it->handler->comment = boost::lexical_cast<std::string>(aliveValues.size()) 
			+ " live-in values";
		for (RegisterSet::iterator alive_it = aliveValues.begin();
			alive_it != aliveValues.end(); ++alive_it) {
			
			report("      alive-in: " << alive_it->id << " [type: " 
				<< ir::PTXOperand::toString(alive_it->type) << "]");
			
			if (alive_it == aliveValues.begin()) {
				move.a = ir::PTXOperand(ir::PTXOperand::Address, ir::PTXOperand::u32, "_Zocelot_spill_area");
				move.d = ir::PTXOperand(ir::PTXOperand::Register, ir::PTXOperand::u32, subkernelDfg->newRegister());
				
				subkernelDfg->insert(handlerDfgBlock, move);
			}

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
	
	std::unordered_map< ir::BasicBlock::Pointer, std::vector<ExternalEdge> > frontierExitBlocks;
	
	// create a handler block for each out-edge that stores values
	report("  visiting external OUT-edges");
	for (ExternalEdgeVector::iterator edge_it = outEdges.begin();
		edge_it != outEdges.end(); ++edge_it) {
		
		assert(subkernelCfgToDfg.find(edge_it->handler) != subkernelCfgToDfg.end());
		
		// restore live values
		RegisterSet aliveValues = cfgToDfg[edge_it->sourceEdge.head]->aliveOut();
		auto handlerDfgBlock = subkernelCfgToDfg[edge_it->handler];
		auto frontierDfgBlock = cfgToDfg[edge_it->frontierBlock];
		
		report("    OUT-edge: " << edge_it->frontierBlock->label << " -> " << edge_it->handler->label
			<< " (" << aliveValues.size() << " live values");
		
		ir::PTXInstruction move(ir::PTXInstruction::Mov);
		
		edge_it->handler->comment = boost::lexical_cast<std::string>(aliveValues.size()) 
			+ " live-out values";
		
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
		
		SubkernelId target = edge_it->destinationId;
		_createExit(handlerDfgBlock, subkernelDfg, Thread_subkernel, target);
		
		frontierExitBlocks[edge_it->frontierBlock].push_back(*edge_it);
	}

	_updateHandlerControlFlow(frontierExitBlocks);
}


void analysis::KernelPartitioningPass::Subkernel::_updateHandlerControlFlow(
	ExternalEdgeMap &frontierExitBlocks) {

	report("Frontier exit blocks:");
	
//	ir::ControlFlowGraph *subkernelCfg = subkernel->cfg();
	
	for (auto block_it = frontierExitBlocks.begin(); block_it != frontierExitBlocks.end(); ++block_it) {	
	
		// update control flow instructions
		ir::PTXInstruction *terminator = static_cast<ir::PTXInstruction *>(block_it->first->instructions.back());
		
		report(" block " << block_it->first->label << " (" << block_it->second.size() 
			<< " external edges) terminator: " << terminator->toString());
		
		if (terminator->opcode == ir::PTXInstruction::Bra) {
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
		else if (terminator->opcode == ir::PTXInstruction::Exit) {
			ExternalEdge &externalEdge = block_it->second.front();
			terminator->opcode = ir::PTXInstruction::Bra;
			terminator->d = ir::PTXOperand(ir::PTXOperand::Label, externalEdge.handler->label);
		}
		else {
			// fall-through
			report(" fall-through non-control-flow instruction to external edge: " << terminator->toString());
		}
	}			
}

/*!
	\brief inserts a scheduler block 
*/
void analysis::KernelPartitioningPass::Subkernel::_createScheduler() {
	//
	// insert a block into the entry of a subkernel
	//	
}

void analysis::KernelPartitioningPass::Subkernel::_createDivergenceHandlers() {

}

void analysis::KernelPartitioningPass::Subkernel::_createExit(analysis::DataflowGraph::iterator block, 
	analysis::DataflowGraph *subkernelDfg, ThreadExitType type, SubkernelId target) {
	
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
	
	move.a = ir::PTXOperand(ir::PTXOperand::Address, ir::PTXOperand::u32, "_Zocelot_resume_point");
	move.d = ir::PTXOperand(ir::PTXOperand::Register, ir::PTXOperand::u32, subkernelDfg->newRegister());
	subkernelDfg->insert(block, move);
	
	store.type = ir::PTXOperand::u32;
	store.addressSpace = ir::PTXInstruction::Local;
	store.d = ir::PTXOperand(ir::PTXOperand::Indirect, ir::PTXOperand::u32, move.d.reg, 0);
	store.a = ir::PTXOperand(target, ir::PTXOperand::u32);
	subkernelDfg->insert(block, store);
	
	ir::PTXInstruction exit(ir::PTXInstruction::Exit);
	subkernelDfg->insert(block, exit);
}

////////////////////////////////////////////////////////////////////////////////////////////////////

