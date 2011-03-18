/*! 
	\file HyperblockFormation.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date March 2011
	\brief Defines a hyperblock formation pass for convergent execution
*/


// C++ includes
#include <queue>
#include <boost/lexical_cast.hpp>

// Ocelot Includes
#include <ocelot/analysis/interface/DataflowGraph.h>
#include <ocelot/analysis/interface/HyperblockFormationPass.h>
#include <ocelot/ir/interface/Module.h>

// Hydrazine Includes
#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1

/////////////////////////////////////////////////////////////////////////////////////////////////

analysis::HyperblockFormation::HyperblockFormation() {

}

/////////////////////////////////////////////////////////////////////////////////////////////////

void analysis::HyperblockFormation::initialize(const ir::Module& m) {

}

/*!
	\brief construct hyperblocks as subkernels from each PTXkernel
	result appears in map<PTXKernel, vector<PTXKernel>> ExtractedHyperblocksPass::kernels
	
	For each basic block, 
		1.) construct a subkernel
		2.) add a copy of the basic block to this subkernel
		3.) add a new predecessor block declaring a .local spill region
			in the predecessor, store live values [assuming a global mapping of register ID to .local memory region]
		4.) add a successor block
			in the successor, store live out values [assuming a global mapping of register IDs to .local memory regions
			add a subkernel exit descriptor
*/
void analysis::HyperblockFormation::runOnKernel(KernelDecomposition &decomposition, ir::Kernel& parent, HyperblockId baseId) {
	//
	// construct a new subkernel for each sequence of basic blocks with provable convergence
	// properties
	//
	
	ir::PTXKernel& parentKernel = static_cast<ir::PTXKernel&>(parent);
	report("Run on kernel '" << parentKernel.name << "'");
#if REPORT_BASE > 0
	parentKernel.write(std::cout);
	report("\n\n");
#endif

	// Compute live register sets for each block
	
	parentKernel.dfg()->compute();
	analysis::DataflowGraph::IteratorMap cfgToDfgMap = parentKernel.dfg()->getCFGtoDFGMap();
	ir::ControlFlowGraph *cfg = parentKernel.cfg();
	
	int blockIndex = 0;
	ir::ControlFlowGraph::BlockPointerVector blocks = cfg->topological_sequence();
	for (ir::ControlFlowGraph::BlockPointerVector::const_iterator bb_it = blocks.begin(); 
		bb_it != blocks.end(); 
		++bb_it) {
		
		if (!(*bb_it)->instructions.size()) {
			continue;
		}
		
		++blockIndex;
		
		Hyperblock hyperblock;
		hyperblock.hyperblockId = (HyperblockId)decomposition.hyperblocks.size() + baseId;
		hyperblock.entryBlock = (*bb_it)->label;
		
		DataflowGraph::IteratorMap::const_iterator dfgBlock = cfgToDfgMap.find(*bb_it);
		assert(dfgBlock != cfgToDfgMap.end() && "failed to find block in CFT-to-DFG mapping");
		
		hyperblock.subkernel = new ir::PTXKernel(
			parentKernel.name + "_hb_" + boost::lexical_cast<std::string>(blockIndex), 
			false, 
			parentKernel.module);

		ir::ControlFlowGraph::iterator computationalBlock = hyperblock.subkernel->cfg()->insert_new_block((*bb_it)->label);
		for (ir::BasicBlock::InstructionList::const_iterator inst_it = (*bb_it)->instructions.begin();
			inst_it != (*bb_it)->instructions.end();
			++inst_it) {
			computationalBlock->instructions.push_back((*inst_it)->clone());
		}
		
		
		ir::BasicBlock::Edge entryEdge(hyperblock.subkernel->cfg()->get_entry_block(), computationalBlock );
		ir::BasicBlock::Edge exitEdge(computationalBlock, hyperblock.subkernel->cfg()->get_exit_block() );
		ir::ControlFlowGraph::edge_iterator entryIterator = hyperblock.subkernel->cfg()->insert_edge(entryEdge);
		ir::ControlFlowGraph::edge_iterator exitIterator = hyperblock.subkernel->cfg()->insert_edge(exitEdge);
		
		report(" visiting (" << (*bb_it)->in_edges.size() << ") in-edges of block '" << (*bb_it)->label << "'");
		
		for (ir::BasicBlock::EdgePointerVector::const_iterator edge_it = (*bb_it)->in_edges.begin();
			edge_it != (*bb_it)->in_edges.end(); ++edge_it) {
			Hyperblock::Edge edge;
			edge.liveValues = dfgBlock->second->aliveIn();
			hyperblock.in_edges.push_back(edge);
			
			report("  edge " << (*edge_it)->head->label << " -> " << (*edge_it)->tail->label << " (" << edge.liveValues.size() << " live values)");
		}
		
		report(" visitng (" << (*bb_it)->out_edges.size() << ") out edges");
		for (ir::BasicBlock::EdgePointerVector::const_iterator edge_it = (*bb_it)->out_edges.begin();
			edge_it != (*bb_it)->out_edges.end(); ++edge_it) {
			Hyperblock::Edge edge;
			edge.liveValues = dfgBlock->second->aliveOut();
			edge.externalBlock = (*bb_it);
			edge.type = (*edge_it)->type;
			
			hyperblock.out_edges.push_back(edge);
			
			report("  edge " << (*edge_it)->head->label << " -> " << (*edge_it)->tail->label << " (" << edge.liveValues.size() << " live values)");
		}
		
		decomposition.hyperblocks[hyperblock.hyperblockId] = hyperblock;
		decomposition.hyperblockEntries[hyperblock.entryBlock] = hyperblock.hyperblockId;
		hyperblock.subkernel->rebuildDfg()->compute();
	}
	
	// revisit all basic block terminators:
	//	- branches to blocks with multiple in-edges are hyperblock exits
	//	- branches in which both targets are hyperblock exits need only spill once
	for (KernelDecomposition::HyperblockMap::iterator hb_it = decomposition.hyperblocks.begin(); 
		hb_it != decomposition.hyperblocks.end(); ++hb_it) {
		
		Hyperblock &hyperblock = hb_it->second;
		
		report("visiting hyperblock " << hyperblock.subkernel->name);
		
		RegisterMap restoreSet;
		RegisterMap storeSet;
		
		// compute union of all live values incoming
		report("  " << hyperblock.in_edges.size() << " in edges");
		for (Hyperblock::EdgeVector::iterator edge_it = hyperblock.in_edges.begin();
			edge_it != hyperblock.in_edges.end(); ++edge_it) {
			
			for (analysis::DataflowGraph::RegisterSet::const_iterator live_it = edge_it->liveValues.begin();
				live_it != edge_it->liveValues.end(); ++live_it) {
				
				restoreSet[live_it->id] = *live_it;
			}
			report(" " << restoreSet.size() << " live in values");
		}
		
		//
		// compute union of all live values outgoing
		//
		report("  " << hyperblock.out_edges.size()<< " out edges");
		for (Hyperblock::EdgeVector::iterator edge_it = hyperblock.out_edges.begin();
			edge_it != hyperblock.out_edges.end(); ++edge_it) {
			
			for (analysis::DataflowGraph::RegisterSet::const_iterator live_it = edge_it->liveValues.begin();
				live_it != edge_it->liveValues.end(); ++live_it) {
				storeSet[live_it->id] = *live_it;
			}
			KernelDecomposition::HyperblockEntryMap::const_iterator 
				entry_it = decomposition.hyperblockEntries.find((edge_it->externalBlock)->label);
			if (entry_it != decomposition.hyperblockEntries.end()) {
				edge_it->externalHyperblock = entry_it->second;
				report("  assigning out edge to target " << edge_it->externalHyperblock << " [label " << (edge_it->externalBlock)->label << "]");
			}
			
			report(" " << restoreSet.size() << " live out values");
		}
		
		ir::BasicBlock epilogBlock;
		
		_createSpillRegion(*hyperblock.subkernel, parentKernel);
		_createRestore(*hyperblock.subkernel, restoreSet);
		_createHyperblockExit(hyperblock);
		_createStore(*hyperblock.subkernel, storeSet);
		
#if 0
		
		_createSpillRegion(*hyperblock.subkernel, parentKernel, prologBlock);
		_createRestore(*hyperblock.subkernel, parentKernel, prologBlock, dfgBlock);
		_createStore(*hyperblock.subkernel, parentKernel, epilogBlock, dfgBlock);
		_createHyperblockExit(*hyperblock.subkernel, parentKernel, **bb_it, *computationalBlock, epilogBlock);
		
		/* ir::ControlFlowGraph::EdgePair splitEntry = */hyperblock.subkernel->cfg()->split_edge(entryIterator, prologBlock);
		/* ir::ControlFlowGraph::EdgePair splitExit = */ hyperblock.subkernel->cfg()->split_edge(exitIterator, epilogBlock);
#endif

		hyperblock.subkernel->rebuildDfg()->compute();
	}
}

void analysis::HyperblockFormation::finalize() {

}


/////////////////////////////////////////////////////////////////////////////////////////////////

void analysis::HyperblockFormation::_createSpillRegion(
	ir::PTXKernel &subkernel, 
	ir::PTXKernel &parentKernel) {
	
	unsigned int spillRegionSize = parentKernel.dfg()->maxRegister()*4;

	subkernel.arguments  = parentKernel.arguments;
	subkernel.parameters = parentKernel.parameters;
	subkernel.locals     = parentKernel.locals;
	
	
	ir::PTXStatement resumeTarget(ir::PTXStatement::Local);
		
	resumeTarget.type = ir::PTXOperand::u32;
	resumeTarget.name = "_Zocelot_resume_point";
	
	subkernel.locals.insert(std::make_pair(resumeTarget.name, ir::Local(resumeTarget)));
	
	ir::PTXStatement resumeStatus(ir::PTXStatement::Local);
		
	resumeStatus.type = ir::PTXOperand::u32;
	resumeStatus.name = "_Zocelot_resume_status";
	
	subkernel.locals.insert(std::make_pair(resumeStatus.name, ir::Local(resumeStatus)));
	
	ir::PTXStatement spillRegion(ir::PTXStatement::Local);
		
	spillRegion.type = ir::PTXOperand::b8;
	spillRegion.name = "_Zocelot_spill_area";
	spillRegion.array.stride.push_back(spillRegionSize);
	
	subkernel.locals.insert(std::make_pair(spillRegion.name, ir::Local(spillRegion)));
		
	report("  Spill region size is " << spillRegionSize);
}

/////////////////////////////////////////////////////////////////////////////////////////////////

//! \brief restores live variables 
size_t analysis::HyperblockFormation::_createRestore(
	ir::PTXKernel &hyperblock,
	const RegisterMap &liveValues) {

	size_t bytes = 0;
	
	ir::BasicBlock::Pointer restoreBlock = hyperblock.cfg()->get_entry_block()->out_edges[0]->tail;
	
	ir::PTXInstruction* move = 0;
	for (RegisterMap::const_iterator reg_it = liveValues.begin(); reg_it != liveValues.end(); ++reg_it) {
		
		if (!move) {
			move = new ir::PTXInstruction(ir::PTXInstruction::Mov);
			move->a = std::move(ir::PTXOperand(ir::PTXOperand::Address, ir::PTXOperand::u32, "_Zocelot_spill_area"));
			move->d = std::move(ir::PTXOperand(ir::PTXOperand::Register, ir::PTXOperand::u32, hyperblock.dfg()->newRegister()));
			restoreBlock->instructions.push_front(move);
		}
		
		ir::PTXInstruction* load = new ir::PTXInstruction(ir::PTXInstruction::Ld);
		
		load->addressSpace = ir::PTXInstruction::Local;
		load->type = reg_it->second.type;

		load->a = std::move(ir::PTXOperand(ir::PTXOperand::Indirect, ir::PTXOperand::u32, move->d.reg, bytes));
		load->d = std::move(ir::PTXOperand(ir::PTXOperand::Register, reg_it->second.type, reg_it->first));
	
		ir::BasicBlock::InstructionList::iterator iterator = restoreBlock->instructions.begin();
		++iterator;
		restoreBlock->instructions.insert(iterator, load);
	
		bytes += ir::PTXOperand::bytes(reg_it->second.type);
	}

	return bytes;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
	
//! \brief stores live variables to local memory
size_t analysis::HyperblockFormation::_createStore(
	ir::PTXKernel &hyperblock,
	const RegisterMap &liveValues) {
	
	size_t offset = 0;

	size_t bytes = 0;
	
	ir::BasicBlock::Pointer storeBlock = hyperblock.cfg()->get_exit_block()->in_edges[0]->head;
	
	ir::PTXInstruction* move = 0;
	for (RegisterMap::const_iterator reg_it = liveValues.begin(); reg_it != liveValues.end(); ++reg_it) {
		
		if (!move) {
			move = new ir::PTXInstruction(ir::PTXInstruction::Mov);
			move->a = std::move(ir::PTXOperand(ir::PTXOperand::Address, ir::PTXOperand::u32, "_Zocelot_spill_area"));
			move->d = std::move(ir::PTXOperand(ir::PTXOperand::Register, ir::PTXOperand::u32, hyperblock.dfg()->newRegister()));
			storeBlock->instructions.push_back(move);
		}
		
		ir::PTXInstruction* store = new ir::PTXInstruction(ir::PTXInstruction::St);
		
		store->addressSpace = ir::PTXInstruction::Local;
		store->type = reg_it->second.type;

		store->a = std::move(ir::PTXOperand(ir::PTXOperand::Register, reg_it->second.type, reg_it->first));
		store->d = std::move(ir::PTXOperand(ir::PTXOperand::Indirect, ir::PTXOperand::u32, move->d.reg, bytes));
	
		storeBlock->instructions.push_back(store);
	
		bytes += ir::PTXOperand::bytes(reg_it->second.type);
	}
	
	return offset;
}
	
/////////////////////////////////////////////////////////////////////////////////////////////////

//! \brief stores a target block ID as well as exit code to the spill area
size_t analysis::HyperblockFormation::_createHyperblockExit(
	Hyperblock &hyperblock) {
	
	
	report("creating exit - " << hyperblock.out_edges.size() << " out edges");
		
	ir::BasicBlock::Pointer exitBlock = hyperblock.subkernel->cfg()->get_exit_block()->in_edges[0]->head;

	// replace branch terminator instructions with stores to target hyperblocks
	// use selp for conditional branches
	ir::BasicBlock::InstructionList::iterator last = exitBlock->instructions.end();
	--last;
	ir::PTXInstruction *terminator = static_cast<ir::PTXInstruction *>(*last);
	
	ir::PTXOperand::RegisterType targetRegister = 0;
	switch (terminator->opcode) {
		case ir::PTXInstruction::Bra:
		{
			if (terminator->pg.addressMode == ir::PTXOperand::Register && 
				terminator->pg.type == ir::PTXOperand::pred &&
				hyperblock.out_edges.size() >= 2) {
				
				report(" conditional branch");
				
				// conditional branch
				ir::PTXInstruction *selp = new ir::PTXInstruction(ir::PTXInstruction::SelP);
				selp->d = std::move(ir::PTXOperand(ir::PTXOperand::Register, ir::PTXOperand::u32, 
					hyperblock.subkernel->dfg()->newRegister()));
				
				selp->a = std::move(ir::PTXOperand(ir::PTXOperand::Immediate, ir::PTXOperand::u32));
				selp->b = std::move(ir::PTXOperand(ir::PTXOperand::Immediate, ir::PTXOperand::u32));
				
				HyperblockId branchTargetId = 0;
				HyperblockId fallthroughTargetId = 0;
				
				for (Hyperblock::EdgeVector::const_iterator edge_it = hyperblock.out_edges.begin();
					edge_it != hyperblock.out_edges.end(); ++edge_it) {
	
					if (edge_it->type == ir::BasicBlock::Edge::Branch) {
						branchTargetId = edge_it->externalHyperblock;
					}
					else {
						fallthroughTargetId = edge_it->externalHyperblock;
					}
				}
				
				report("  branch target id: " << branchTargetId);
				report("  fallthrough id: " << fallthroughTargetId);
				
				selp->a.imm_uint = branchTargetId;		// branch target
				selp->b.imm_uint = fallthroughTargetId;		// fallthrough target
				selp->c = std::move(ir::PTXOperand(ir::PTXOperand::Register, ir::PTXOperand::pred, terminator->pg.reg, 0));
								
				targetRegister = selp->d.reg;
				
				exitBlock->instructions.erase(last);
				exitBlock->instructions.push_back(selp);
			}
			else {
				// unconditional branch
				report(" unconditional branch");
				exitBlock->instructions.erase(last);
			}
		
			analysis::DataflowGraph::RegisterId addrRegister = hyperblock.subkernel->dfg()->newRegister();
			ir::PTXInstruction *move = new ir::PTXInstruction(ir::PTXInstruction::Mov);
			move->a = std::move(ir::PTXOperand(ir::PTXOperand::Address, ir::PTXOperand::u32, "_Zocelot_resume_point"));
			move->d = std::move(ir::PTXOperand(ir::PTXOperand::Register, ir::PTXOperand::u32, addrRegister));
			move->type = ir::PTXOperand::u32;
			
			ir::PTXInstruction *store = new ir::PTXInstruction(ir::PTXInstruction::St);
			store->addressSpace = ir::PTXInstruction::Local;
			store->type = ir::PTXOperand::u32;
			store->d = std::move(ir::PTXOperand(ir::PTXOperand::Indirect, ir::PTXOperand::u32, move->d.reg, 0));
			store->a = std::move(ir::PTXOperand(ir::PTXOperand::Register, ir::PTXOperand::u32, targetRegister, 0));
			
			exitBlock->instructions.push_back(move);
			exitBlock->instructions.push_back(store);
			
			// store 
			move = new ir::PTXInstruction(ir::PTXInstruction::Mov);
			move->a = std::move(ir::PTXOperand(ir::PTXOperand::Address, ir::PTXOperand::u32, "_Zocelot_resume_status"));
			move->d = std::move(ir::PTXOperand(ir::PTXOperand::Register, ir::PTXOperand::u32, addrRegister));
			move->type = ir::PTXOperand::u32;
	
			store = new ir::PTXInstruction(ir::PTXInstruction::St);
			store->addressSpace = ir::PTXInstruction::Local;
			store->type = ir::PTXOperand::u32;
			store->d = std::move(ir::PTXOperand(ir::PTXOperand::Indirect, ir::PTXOperand::u32, move->d.reg, 0));
			store->a = std::move(ir::PTXOperand(ir::PTXOperand::Immediate, ir::PTXOperand::u32));
			store->a.imm_uint = 1;
	
			exitBlock->instructions.push_back(move);
			exitBlock->instructions.push_back(store);
		}
		break;
		case ir::PTXInstruction::Exit:
		{
			// mov %rd0, _Zocelot_resume_status
			// store [%rd0], <exit code>
#if 0
			// store 
			ir::PTXInstruction *move = new ir::PTXInstruction(ir::PTXInstruction::Mov);
			move->a = std::move(ir::PTXOperand(ir::PTXOperand::Address, ir::PTXOperand::u32, "_Zocelot_resume_status", 0));
			move->d = std::move(ir::PTXOperand(ir::PTXOperand::Register, ir::PTXOperand::u32, subkernel.dfg()->newRegister()));
			move->type = ir::PTXOperand::u32;
	
			ir::PTXInstruction *store = new ir::PTXInstruction(ir::PTXInstruction::St);
			store->addressSpace = ir::PTXInstruction::Local;
			store->type = ir::PTXOperand::u32;
			store->d = std::move(ir::PTXOperand(ir::PTXOperand::Indirect, ir::PTXOperand::u32, move->d.reg, 0));
			store->a = std::move(ir::PTXOperand(ir::PTXOperand::Immediate, ir::PTXOperand::u32));
			store->a.imm_uint = 6;
	
			// need to insert these into the dfg
			clonedBlock.instructions.erase(last);
			clonedBlock.instructions.push_back(move);
			clonedBlock.instructions.push_back(store);
#endif
		}
		break;
		default:
			break;
	}
	
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////


