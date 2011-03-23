/*! 
	\file HyperblockFormation.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date March 2011
	\brief Defines a hyperblock formation pass for convergent execution
*/


// C++ includes
#include <queue>
#include <boost/lexical_cast.hpp>
#include <algorithm>
#include <set>

// Ocelot Includes
#include <ocelot/analysis/interface/DataflowGraph.h>
#include <ocelot/analysis/interface/HyperblockFormationPass.h>
#include <ocelot/ir/interface/Module.h>

// Hydrazine Includes
#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

/////////////////////////////////////////////////////////////////////////////////////////////////

static size_t pad(size_t offset, size_t size) {
	if (offset % size) {
		offset += (size - (offset % size));
	}
	return offset;
}

std::string analysis::HyperblockFormation::toString(const ThreadExitCode &code) {
	switch (code) {
	case Thread_fallthrough: return "fallthrough";
	case Thread_branch: return "branch";
	case Thread_tailcall: return "tailcall";
	case Thread_call: return "call";
	case Thread_barrier: return "barrier";
	case Thread_exit: return "exit";
	case Thread_exit_other: return "other";
	case ThreadExitCode_invalid: break;
	default: break;
	}
	return "invalid";
}

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
	_partitionAtBarrier(parentKernel);
	
	parentKernel.dfg()->compute();
	analysis::DataflowGraph::IteratorMap cfgToDfgMap = parentKernel.dfg()->getCFGtoDFGMap();
	ir::ControlFlowGraph *cfg = parentKernel.cfg();
	
	ir::ControlFlowGraph::BlockPointerVector blocks = cfg->topological_sequence();
	for (ir::ControlFlowGraph::BlockPointerVector::const_iterator bb_it = blocks.begin(); 
		bb_it != blocks.end(); 
		++bb_it) {
		
		if (!(*bb_it)->instructions.size()) {
			continue;
		}
		
		Hyperblock hyperblock;
		hyperblock.hyperblockId = (HyperblockId)decomposition.hyperblocks.size() + baseId;
		hyperblock.entryBlock = (*bb_it)->label;
		
		DataflowGraph::IteratorMap::const_iterator dfgBlock = cfgToDfgMap.find(*bb_it);
		assert(dfgBlock != cfgToDfgMap.end() && "failed to find block in CFT-to-DFG mapping");
		
		hyperblock.subkernel = new ir::PTXKernel(
			parentKernel.name + "_hb_" + boost::lexical_cast<std::string>(hyperblock.hyperblockId), 
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
			
			report("  edge " << (*edge_it)->head->label << " -> " << (*edge_it)->tail->label 
				<< " (" << edge.liveValues.size() << " live values)");
		}
		
		report(" visitng (" << (*bb_it)->out_edges.size() << ") out edges");
		for (ir::BasicBlock::EdgePointerVector::const_iterator edge_it = (*bb_it)->out_edges.begin();
			edge_it != (*bb_it)->out_edges.end(); ++edge_it) {
			Hyperblock::Edge edge;
			edge.liveValues = dfgBlock->second->aliveOut();
			edge.externalBlock = (*bb_it);
			edge.type = (*edge_it)->type;
			edge.label = (*edge_it)->tail->label ;
			hyperblock.out_edges.push_back(edge);
			
			report("  edge " << (*edge_it)->head->label << " -> " << (*edge_it)->tail->label 
				<< " (" << edge.liveValues.size() << " live values)");
		}
		
		decomposition.hyperblocks[hyperblock.hyperblockId] = hyperblock;
		decomposition.hyperblockEntries[hyperblock.entryBlock] = hyperblock.hyperblockId;
		hyperblock.subkernel->rebuildDfg()->compute();
	}
		
	OffsetVector registerOffsets;
	registerOffsets.resize(parentKernel.dfg()->maxRegister(), 0);
	for (analysis::DataflowGraph::RegisterId reg_id = 0; reg_id < parentKernel.dfg()->maxRegister();
		reg_id++) {
		registerOffsets[reg_id] = 8*reg_id;
	}
	size_t spillSize = (size_t)(8 * parentKernel.dfg()->maxRegister());
	
	// revisit all basic block terminators:
	//	- branches to blocks with multiple in-edges are hyperblock exits
	//	- branches in which both targets are hyperblock exits need only spill once
	for (KernelDecomposition::HyperblockMap::iterator hb_it = decomposition.hyperblocks.begin(); 
		hb_it != decomposition.hyperblocks.end(); ++hb_it) {
		
		Hyperblock &hyperblock = hb_it->second;
		
		report("visiting hyperblock " << hyperblock.subkernel->name);
		
		RegisterSet restoreSet;
		RegisterSet storeSet;
		RegisterSet produced;
		RegisterSet used;
		
		_determineRegisterUses(produced, used, *hyperblock.subkernel);
		
		
		// compute union of all live values incoming
		report("  " << hyperblock.in_edges.size() << " in edges");
		for (Hyperblock::EdgeVector::iterator edge_it = hyperblock.in_edges.begin();
			edge_it != hyperblock.in_edges.end(); ++edge_it) {
			
			for (analysis::DataflowGraph::RegisterSet::const_iterator live_it = edge_it->liveValues.begin();
				live_it != edge_it->liveValues.end(); ++live_it) {
				
				//restoreSet[live_it->id] = *live_it;
				if (true || used.find(live_it->id) != used.end()) {
					restoreSet.insert(*live_it);
				}
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
				//storeSet[live_it->id] = *live_it;
				if (true || produced.find(live_it->id) != produced.end()) {
					storeSet.insert(*live_it);
				}
			}
			KernelDecomposition::HyperblockEntryMap::const_iterator 
				entry_it = decomposition.hyperblockEntries.find(edge_it->label);
			if (entry_it != decomposition.hyperblockEntries.end()) {
				edge_it->externalHyperblock = entry_it->second;
				report(" --  assigning out edge to target " << edge_it->externalHyperblock 
					<< " [label " << edge_it->label << "]");
			}
			
			report(" " << storeSet.size() << " live out values");
		}
		
		ir::BasicBlock epilogBlock;
		
		_createSpillRegion(*hyperblock.subkernel, parentKernel, spillSize);
		
		_createRestore(*hyperblock.subkernel, restoreSet, registerOffsets);
		_createHyperblockExit(hyperblock);
		_createStore(*hyperblock.subkernel, storeSet, registerOffsets);

		hyperblock.subkernel->rebuildDfg()->compute();
	}
}

void analysis::HyperblockFormation::finalize() {

}

void analysis::HyperblockFormation::_determineRegisterUses(
	RegisterSet &produced, 
	RegisterSet &used, 
	ir::PTXKernel &subkernel) {
	
	report("determineRegisterUses(" << subkernel.name << ")");
	
	analysis::DataflowGraph *dfg = subkernel.rebuildDfg();
	dfg->compute();
		
	for (analysis::DataflowGraph::const_iterator dfgb_it = dfg->begin();
		dfgb_it != dfg->end();
		++dfgb_it) {
		
		const analysis::DataflowGraph::InstructionVector &instructions = dfgb_it->instructions();
		for (analysis::DataflowGraph::InstructionVector::const_iterator inst_it = instructions.begin();
			inst_it != instructions.end(); ++inst_it) {
			
			// produced
			for (analysis::DataflowGraph::RegisterPointerVector::const_iterator d_it = inst_it->d.begin();
				d_it != inst_it->d.end(); ++d_it) {
				
				analysis::DataflowGraph::Register reg(*d_it->pointer, d_it->type);
				produced.insert( reg );
			}
			
			// used
			for (analysis::DataflowGraph::RegisterPointerVector::const_iterator s_it = inst_it->s.begin();
				s_it != inst_it->s.end(); ++s_it) {
				
				analysis::DataflowGraph::Register reg(*s_it->pointer, s_it->type);
				used.insert( reg );
			}
		}
	}
	for (RegisterSet::const_iterator prod_it = produced.begin(); prod_it != produced.end(); ++prod_it) {
		RegisterSet::iterator d_it = used.find(*prod_it);
		if (d_it != used.end()) {
			used.erase(d_it);
		}
	}
	
	for (RegisterSet::const_iterator r_it = produced.begin(); r_it != produced.end(); ++r_it) {
		report("produced: " << r_it->id);
	}
	for (RegisterSet::const_iterator r_it = used.begin(); r_it != used.end(); ++r_it) {
		report("used: " << r_it->id);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////

void analysis::HyperblockFormation::_createSpillRegion(
	ir::PTXKernel &subkernel, 
	ir::PTXKernel &parentKernel,
	size_t spillRegionSize) {

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
	spillRegion.array.stride.push_back((unsigned int)spillRegionSize);
	
	subkernel.locals.insert(std::make_pair(spillRegion.name, ir::Local(spillRegion)));
		
	report("  Spill region size is " << spillRegionSize);
}

/////////////////////////////////////////////////////////////////////////////////////////////////

//! \brief restores live variables 
size_t analysis::HyperblockFormation::_createRestore(
	ir::PTXKernel &hyperblock,
	const RegisterSet &liveValues,
	OffsetVector &offsets) {

	size_t bytes = 0;
	
	ir::BasicBlock::Pointer restoreBlock = hyperblock.cfg()->get_entry_block()->out_edges[0]->tail;
	
	ir::PTXInstruction* move = 0;
	for (RegisterSet::const_iterator reg_it = liveValues.begin(); reg_it != liveValues.end(); ++reg_it) {
		
		if (!move) {
			move = new ir::PTXInstruction(ir::PTXInstruction::Mov);
			move->a = std::move(ir::PTXOperand(ir::PTXOperand::Address, ir::PTXOperand::u32, "_Zocelot_spill_area"));
			move->d = std::move(ir::PTXOperand(ir::PTXOperand::Register, ir::PTXOperand::u32, hyperblock.dfg()->newRegister()));
			restoreBlock->instructions.push_front(move);
		}
		
		ir::PTXInstruction* load = new ir::PTXInstruction(ir::PTXInstruction::Ld);
		
		bytes = pad(bytes, ir::PTXOperand::bytes(reg_it->type));
		
		load->addressSpace = ir::PTXInstruction::Local;
		load->type = reg_it->type;

		load->a = std::move(ir::PTXOperand(ir::PTXOperand::Indirect, ir::PTXOperand::u32, move->d.reg, offsets[reg_it->id]));
		load->d = std::move(ir::PTXOperand(ir::PTXOperand::Register, reg_it->type, reg_it->id));
	
		ir::BasicBlock::InstructionList::iterator iterator = restoreBlock->instructions.begin();
		++iterator;
		restoreBlock->instructions.insert(iterator, load);
	
		bytes += ir::PTXOperand::bytes(reg_it->type);
	}

	return bytes;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
	
//! \brief stores live variables to local memory
size_t analysis::HyperblockFormation::_createStore(
	ir::PTXKernel &hyperblock,
	const RegisterSet &liveValues,
	OffsetVector &offsets) {
	
	size_t offset = 0;

	size_t bytes = 0;
	
	ir::BasicBlock::Pointer storeBlock = hyperblock.cfg()->get_exit_block()->in_edges[0]->head;
	
	ir::PTXInstruction* move = 0;
	for (RegisterSet::const_iterator reg_it = liveValues.begin(); reg_it != liveValues.end(); ++reg_it) {
		
		if (!move) {
			move = new ir::PTXInstruction(ir::PTXInstruction::Mov);
			move->a = std::move(ir::PTXOperand(ir::PTXOperand::Address, ir::PTXOperand::u32, "_Zocelot_spill_area"));
			move->d = std::move(ir::PTXOperand(ir::PTXOperand::Register, ir::PTXOperand::u32, hyperblock.dfg()->newRegister()));
			storeBlock->instructions.push_back(move);
		}
		if (reg_it->id == move->d.reg) {
			continue;
		}
		ir::PTXInstruction* store = new ir::PTXInstruction(ir::PTXInstruction::St);
		
		store->addressSpace = ir::PTXInstruction::Local;
		store->type = reg_it->type;
		
		bytes = pad(bytes, ir::PTXOperand::bytes(reg_it->type));

		store->a = std::move(ir::PTXOperand(ir::PTXOperand::Register, reg_it->type, reg_it->id));
		store->d = std::move(ir::PTXOperand(ir::PTXOperand::Indirect, ir::PTXOperand::u32, move->d.reg, offsets[reg_it->id]));
	
		storeBlock->instructions.push_back(store);
	
		bytes += ir::PTXOperand::bytes(reg_it->type);
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
	
	ir::PTXOperand resumePointOperand;
	
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
								
				resumePointOperand = std::move(ir::PTXOperand(ir::PTXOperand::Register, ir::PTXOperand::u32, selp->d.reg, 0));
				
				exitBlock->instructions.erase(last);
				exitBlock->instructions.push_back(selp);
			}
			else {
				// unconditional branch
				report(" unconditional branch");
				resumePointOperand = std::move(ir::PTXOperand(ir::PTXOperand::Immediate, ir::PTXOperand::u32));
				
				for (Hyperblock::EdgeVector::const_iterator edge_it = hyperblock.out_edges.begin();
					edge_it != hyperblock.out_edges.end(); ++edge_it) {
					resumePointOperand.imm_uint = edge_it->externalHyperblock;
				}
				
				exitBlock->instructions.erase(last);
			}
			
			_createExit(hyperblock, exitBlock, resumePointOperand, Thread_branch);
		}
		break;
		case ir::PTXInstruction::Bar:
		{
			resumePointOperand = std::move(ir::PTXOperand(ir::PTXOperand::Immediate, ir::PTXOperand::u32));
			for (Hyperblock::EdgeVector::const_iterator edge_it = hyperblock.out_edges.begin();
				edge_it != hyperblock.out_edges.end(); ++edge_it) {
				resumePointOperand.imm_uint = edge_it->externalHyperblock;
			}
			exitBlock->instructions.erase(last);
			_createExit(hyperblock, exitBlock, resumePointOperand, Thread_barrier);
		}
		break;
		case ir::PTXInstruction::Call:
		{
			assert(0 && "calls not implemented");
		}
		break;
		case ir::PTXInstruction::Exit:
		{			
			exitBlock->instructions.erase(last);
			_createExit(hyperblock, exitBlock, Thread_exit);
		}
		break;
		default:
		{
			ir::PTXOperand resumePointOperand = std::move(ir::PTXOperand(ir::PTXOperand::Immediate, ir::PTXOperand::u32));
			
			for (Hyperblock::EdgeVector::const_iterator edge_it = hyperblock.out_edges.begin();
				edge_it != hyperblock.out_edges.end(); ++edge_it) {
				resumePointOperand.imm_uint = edge_it->externalHyperblock;
			}
			_createExit(hyperblock, exitBlock, resumePointOperand, Thread_fallthrough);
		}
			break;
	}
	
	return 0;
}


void analysis::HyperblockFormation::_createExit(
	Hyperblock &hyperblock, 
	ir::BasicBlock::Pointer exitBlock,
	unsigned int exitCode) {
	
	ir::PTXOperand resumePointOperand;
	_createExit(hyperblock, exitBlock, resumePointOperand, exitCode);
}

void analysis::HyperblockFormation::_createExit(
	Hyperblock &hyperblock, 
	ir::BasicBlock::Pointer exitBlock, 
	const ir::PTXOperand &resumePointOperand,
	unsigned int exitCode) {

	analysis::DataflowGraph::RegisterId addrRegister = hyperblock.subkernel->dfg()->newRegister();
	ir::PTXInstruction *move = 0;
	ir::PTXInstruction *store = 0;
	if (exitCode != Thread_exit) {
		move = new ir::PTXInstruction(ir::PTXInstruction::Mov);
		move->a = std::move(ir::PTXOperand(ir::PTXOperand::Address, ir::PTXOperand::u32, "_Zocelot_resume_point"));
		move->d = std::move(ir::PTXOperand(ir::PTXOperand::Register, ir::PTXOperand::u32, addrRegister));
		move->type = ir::PTXOperand::u32;

		store = new ir::PTXInstruction(ir::PTXInstruction::St);
		store->addressSpace = ir::PTXInstruction::Local;
		store->type = ir::PTXOperand::u32;
		store->d = std::move(ir::PTXOperand(ir::PTXOperand::Indirect, ir::PTXOperand::u32, move->d.reg, 0));
		store->a = resumePointOperand;

		exitBlock->instructions.push_back(move);
		exitBlock->instructions.push_back(store);
	}

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
	store->a.imm_uint = exitCode;

	exitBlock->instructions.push_back(move);
	exitBlock->instructions.push_back(store);
	
	report("created exit in block '" << exitBlock->label << "' with code " << (int)exitCode);
}

/////////////////////////////////////////////////////////////////////////////////////////////////


void analysis::HyperblockFormation::_partitionAtBarrier(ir::PTXKernel &parentKernel) {

	typedef std::map< std::string, std::vector< unsigned int > > Barriers;
	Barriers barriers;

	report("partitioning blocks at barriers");
	int barrierCount = 0;
	
	for (ir::ControlFlowGraph::iterator bb_it = parentKernel.cfg()->begin(); 
		bb_it != parentKernel.cfg()->end(); 
		++bb_it) {

		report(" block " << bb_it->label);

		unsigned int n = 0;
		for (ir::BasicBlock::InstructionList::iterator inst_it = (bb_it)->instructions.begin();
			inst_it != (bb_it)->instructions.end();
			++inst_it, n++) {

			const ir::PTXInstruction *inst = static_cast<const ir::PTXInstruction *>(*inst_it);
			if (inst->opcode == ir::PTXInstruction::Bar) {
				if (n + 1 < (unsigned int)(bb_it)->instructions.size()) {
					std::string label = (bb_it)->label + "_bar";
					parentKernel.cfg()->split_block(bb_it, n+1, ir::BasicBlock::Edge::FallThrough, label);
				}
				report("barrier in block " << bb_it->label << "(instruction " << n << ")");
				++barrierCount;
				break;
			}
		}
	}
}


