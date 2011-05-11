/*!
	\file KernelPartitioningPass.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date April 25, 2011
	\brief generalizes the hyperblock partitioning scheme 
*/

// C++ includes
#include <queue>
#include <boost/lexical_cast.hpp>
#include <algorithm>
#include <set>

// Ocelot Includes
#include <ocelot/analysis/interface/DataflowGraph.h>
#include <ocelot/analysis/interface/KernelPartitioningPass.h>
#include <ocelot/ir/interface/Module.h>

// Hydrazine Includes
#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_SUBKERNEL_PTX 1
#define REPORT_SUBKERNEL_BARE 1
#define REPORT_SUBKERNEL_CFG 1

#define REPORT_BASE 0

/////////////////////////////////////////////////////////////////////////////////////////////////

namespace analysis {

static size_t pad(size_t offset, size_t size) {
	if (offset % size) {
		offset += (size - (offset % size));
	}
	return offset;
}

std::string KernelPartitioningPass::toString(const ThreadExitCode &code) {
	switch (code) {
	case Thread_entry: return "entry";
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

/////////////////////////////////////////////////////////////////////////////////////////////////

/*!

*/
KernelPartitioningPass::KernelDecomposition::KernelDecomposition() {

}

/*!

*/
void KernelPartitioningPass::KernelDecomposition::runOnKernel(ir::PTXKernel *_kernel, EntryId _base) {

	kernel = _kernel;
	baseId = _base;
	
	// construct a mapping of registers to offset
	registerOffsets.clear();
	registerOffsets.resize(kernel->dfg()->maxRegister(), 0);
	for (analysis::DataflowGraph::RegisterId reg_id = 0; reg_id < kernel->dfg()->maxRegister(); ++reg_id) {
		registerOffsets[reg_id] = 8*reg_id;
	}
	size_t spillSize = (size_t)(8 * kernel->dfg()->maxRegister());
		
	_createSpillRegion(spillSize);
	
	// create transition points
	_initializeDecomposition();
	
	// partition blocks at barriers
	_partitionBlocksAtBarrier();
	
	// 
	_identifyTransitionPoints();
	
	_createDummyScheduler();
	
	kernel->rebuildDfg()->compute();
	
#if REPORT_BASE && REPORT_SUBKERNEL_PTX
	std::cout << "KernelPartitioningPass:\n";
	kernel->write(std::cout);
#endif

#if REPORT_BASE && REPORT_SUBKERNEL_CFG
	std::cout << "\n\n";
	kernel->cfg()->write(std::cout);
#endif
}

/*!

*/
void KernelPartitioningPass::KernelDecomposition::_initializeDecomposition() {

}

/*!
	\brief inserts local variable declarations for spill regions, resume points, and resume status
*/
void KernelPartitioningPass::KernelDecomposition::_createSpillRegion(size_t spillSize) {
	
	ir::PTXStatement resumeTarget(ir::PTXStatement::Local);
		
	resumeTarget.type = ir::PTXOperand::u32;
	resumeTarget.name = "_Zocelot_resume_point";
	
	kernel->locals.insert(std::make_pair(resumeTarget.name, ir::Local(resumeTarget)));
	
	ir::PTXStatement resumeStatus(ir::PTXStatement::Local);
		
	resumeStatus.type = ir::PTXOperand::u32;
	resumeStatus.name = "_Zocelot_resume_status";
	
	kernel->locals.insert(std::make_pair(resumeStatus.name, ir::Local(resumeStatus)));
	
	ir::PTXStatement spillRegion(ir::PTXStatement::Local);
		
	spillRegion.type = ir::PTXOperand::b8;
	spillRegion.name = "_Zocelot_spill_area";
	spillRegion.array.stride.push_back((unsigned int)spillSize);
	
	kernel->locals.insert(std::make_pair(spillRegion.name, ir::Local(spillRegion)));
		
	report("  Spill region size is " << spillSize);
}

/*!
	\brief partitions blocks in parent kernel such that bar.sync is last instruction
*/
void KernelPartitioningPass::KernelDecomposition::_partitionBlocksAtBarrier() {
	report("partitioning blocks at barriers");
	int barrierCount = 0;
	
	for (ir::ControlFlowGraph::iterator bb_it = kernel->cfg()->begin(); 
		bb_it != kernel->cfg()->end(); 
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
					kernel->cfg()->split_block(bb_it, n+1, ir::BasicBlock::Edge::FallThrough, label);
				}
				report("barrier in block " << bb_it->label << "(instruction " << n << ")");
				++barrierCount;
				break;
			}
		}
	}
	kernel->rebuildDfg()->compute();
}

/*!
	\brief identify all transition points and determine the set of values live at those points
*/
void KernelPartitioningPass::KernelDecomposition::_identifyTransitionPoints() {
	report("identifying transition points");
	
	analysis::DataflowGraph::IteratorMap cfgToDfgMap = kernel->dfg()->getCFGtoDFGMap();
	
	ir::ControlFlowGraph *cfg = kernel->cfg();
	ir::ControlFlowGraph::BlockPointerVector blocks = cfg->topological_sequence();
	for (ir::ControlFlowGraph::BlockPointerVector::const_iterator bb_it = blocks.begin(); 
		bb_it != blocks.end(); 
		++bb_it) {
		
		if (!(*bb_it)->instructions.size()) {
			continue;
		}
		
		report(" block " << (*bb_it)->label);
		
		DataflowGraph::IteratorMap::const_iterator dfgBlock = cfgToDfgMap.find(*bb_it);
		assert(dfgBlock != cfgToDfgMap.end() && "failed to find block in CFT-to-DFG mapping");
				
		// live in
		KernelTransitionPoint transitionEntry;
		transitionEntry.type = Thread_entry;
		transitionEntry.block = *bb_it;
		transitionEntry.liveValues = dfgBlock->second->aliveIn();
		transitionEntry.handler = kernel->cfg()->insert_new_block((*bb_it)->label + "_entry");
		transitionEntry.id = (EntryId)transitionPoints.size() + baseId;
		
		std::stringstream ss;
		ss << "entryId: " << transitionEntry.id;
		
		transitionEntry.handler->comment = ss.str();
		transitionPoints[transitionEntry.id] = transitionEntry;
		
		
		EntryId exitId = -1;
		
		// live out
		KernelTransitionPoint transitionExit;
		transitionExit.type = Thread_branch;
		transitionExit.block = *bb_it;
		transitionExit.liveValues = dfgBlock->second->aliveOut();
		transitionExit.handler = kernel->cfg()->insert_new_block((*bb_it)->label + "_exit");
		transitionExit.id = (EntryId)transitionPoints.size() + baseId;
		transitionPoints[transitionExit.id] = transitionExit;
		exitId = transitionExit.id;
		entryTransitions[(*bb_it)->label] = std::make_pair(transitionEntry.id, exitId);
	}
	
	// revisit transitions
	for (KernelTransitionPointMap::iterator transition_it = transitionPoints.begin();
		transition_it != transitionPoints.end(); ++transition_it) {
		
		_constructTransition(transition_it->second);
	}
}

/*!
	\brief inserts spill and restore code into each transition
*/
void KernelPartitioningPass::KernelDecomposition::_constructTransition(
	KernelTransitionPoint &transition) {

	switch (transition.type) {
	case Thread_entry:
	{
		// create restore point
		size_t bytes = 0;
		
		ir::PTXInstruction* move = 0;
		for (RegisterSet::const_iterator reg_it = transition.liveValues.begin(); 
			reg_it != transition.liveValues.end(); ++reg_it) {
		
			if (!move) {
				move = new ir::PTXInstruction(ir::PTXInstruction::Mov);
				move->a = std::move(ir::PTXOperand(ir::PTXOperand::Address, ir::PTXOperand::u32, "_Zocelot_spill_area"));
				move->d = std::move(ir::PTXOperand(ir::PTXOperand::Register, ir::PTXOperand::u32, kernel->dfg()->newRegister()));
				transition.handler->instructions.push_front(move);
			}
		
			ir::PTXInstruction* load = new ir::PTXInstruction(ir::PTXInstruction::Ld);
		
			bytes = pad(bytes, ir::PTXOperand::bytes(reg_it->type));
		
			load->addressSpace = ir::PTXInstruction::Local;
			load->type = reg_it->type;

			load->a = std::move(ir::PTXOperand(ir::PTXOperand::Indirect, ir::PTXOperand::u32, move->d.reg, 
				registerOffsets[reg_it->id]));
			load->d = std::move(ir::PTXOperand(ir::PTXOperand::Register, reg_it->type, reg_it->id));
			ir::BasicBlock::InstructionList::iterator iterator = transition.handler->instructions.begin();
			
			++iterator;
			transition.handler->instructions.insert(iterator, load);
			
			bytes += ir::PTXOperand::bytes(reg_it->type);
		}
				
		ir::PTXInstruction *branch = new ir::PTXInstruction(ir::PTXInstruction::Bra);
		branch->d.addressMode = ir::PTXOperand::Label;
		branch->d.identifier = transition.block->label;
		transition.handler->instructions.insert(transition.handler->instructions.end(), branch);
			
		// create edge from handler to block
		ir::BasicBlock::Edge edge(transition.handler, transition.block, ir::BasicBlock::Edge::Branch);
		transition.edge = kernel->cfg()->insert_edge(edge);
	}
	break;
	
	case ThreadExitCode_invalid:
	{
		assert(0 && "invalid exit code encountered");
	}
	
	default:
	{
		// all others are thread exits of various types
		size_t bytes = 0;
		
		ir::PTXInstruction* move = 0;
		for (RegisterSet::const_iterator reg_it = transition.liveValues.begin(); 
			reg_it != transition.liveValues.end(); ++reg_it) {
		
			if (!move) {
				move = new ir::PTXInstruction(ir::PTXInstruction::Mov);
				move->a = std::move(ir::PTXOperand(ir::PTXOperand::Address, ir::PTXOperand::u32, "_Zocelot_spill_area"));
				move->d = std::move(ir::PTXOperand(ir::PTXOperand::Register, ir::PTXOperand::u32, kernel->dfg()->newRegister()));
				transition.handler->instructions.push_back(move);
			}
			if (reg_it->id == move->d.reg) {
				continue;
			}
			ir::PTXInstruction* store = new ir::PTXInstruction(ir::PTXInstruction::St);
		
			store->addressSpace = ir::PTXInstruction::Local;
			store->type = reg_it->type;
		
			bytes = pad(bytes, ir::PTXOperand::bytes(reg_it->type));

			store->a = std::move(ir::PTXOperand(ir::PTXOperand::Register, reg_it->type, reg_it->id));
			store->d = std::move(ir::PTXOperand(ir::PTXOperand::Indirect, ir::PTXOperand::u32, move->d.reg, 
				registerOffsets[reg_it->id]));
	
			transition.handler->instructions.push_back(store);
	
			bytes += ir::PTXOperand::bytes(reg_it->type);
		}
		
		_transformExitTransitions(transition);
	}
		break;
	}
}

//! \brief 
void KernelPartitioningPass::KernelDecomposition::_transformExitTransitions(KernelTransitionPoint &transition) {

	// replace branch terminator instructions with stores to target hyperblocks
	// use selp for conditional branches
	ir::BasicBlock::InstructionList::iterator last = transition.block->instructions.end();
	--last;
	ir::PTXInstruction *terminator = static_cast<ir::PTXInstruction *>(*last);
	
	report("transformExitTransition() - terminator->opcode = " << ir::PTXInstruction::toString(terminator->opcode));
	report("  terminator->toString() = " << terminator->toString());
	
	ir::PTXOperand resumePointOperand;
	switch (terminator->opcode) {
		case ir::PTXInstruction::Bra:
		{
			if (terminator->pg.addressMode == ir::PTXOperand::Register && 
				terminator->pg.type == ir::PTXOperand::pred &&
				transition.block->out_edges.size() >= 2 &&
				!terminator->uni) {
				
				// identify branch target entry points
				EntryId branchTargetId = 0;
				EntryId fallthroughTargetId = 0;
				std::string fallthroughBlockLabel = "";
				
				
				for (ir::BasicBlock::EdgePointerVector::const_iterator edge_it = transition.block->out_edges.begin();
					edge_it != transition.block->out_edges.end(); ++edge_it) {
					
					EntryId targetId = entryTransitions[(*edge_it)->tail->label].first;
					if ((*edge_it)->type == ir::BasicBlock::Edge::Branch) {
						branchTargetId = targetId;
					}
					else {
						fallthroughTargetId = targetId;
						fallthroughBlockLabel = (*edge_it)->tail->label;
					}
				}
				
				// create a dummy edge
				ir::BasicBlock::Edge dummyEdge(transition.block, transition.handler, ir::BasicBlock::Edge::Dummy);
				kernel->cfg()->insert_edge(dummyEdge);
				
				// in cases of actual divergence, insert the thread exit into the handler block
				ir::PTXInstruction *selp = new ir::PTXInstruction(ir::PTXInstruction::SelP);
				selp->d = std::move(ir::PTXOperand(ir::PTXOperand::Register, ir::PTXOperand::u32, 
					kernel->dfg()->newRegister()));
				selp->a = std::move(ir::PTXOperand(ir::PTXOperand::Immediate, ir::PTXOperand::u32));
				selp->b = std::move(ir::PTXOperand(ir::PTXOperand::Immediate, ir::PTXOperand::u32));
				
				// if predicates are inverted...
				if (terminator->pg.condition == ir::PTXOperand::InvPred) {
					std::swap(branchTargetId, fallthroughTargetId);
				}
				else if (terminator->pg.condition != ir::PTXOperand::Pred) {
					std::cerr << terminator->toString() << std::endl;
					assert(0 && "invalid predicate condition for conditional branch");
				}
				
				selp->a.imm_uint = branchTargetId;		// branch target
				selp->b.imm_uint = fallthroughTargetId;		// fallthrough target
				selp->c = std::move(ir::PTXOperand(ir::PTXOperand::Register, ir::PTXOperand::pred, terminator->pg.reg, 0));
				transition.handler->instructions.push_back(selp);
				resumePointOperand = std::move(ir::PTXOperand(ir::PTXOperand::Register, ir::PTXOperand::u32, selp->d.reg, 0));
				transition.handler->comment = "divergent branch";
				
				_createExitCode(transition, resumePointOperand, Thread_branch);
			}
			else {
				// unconditional branches do not result in divergence
				kernel->cfg()->remove_block(transition.handler);
				transition.handler = kernel->cfg()->end();
			}
		}
		break;
		case ir::PTXInstruction::Bar:
		{
			resumePointOperand = std::move(ir::PTXOperand(ir::PTXOperand::Immediate, ir::PTXOperand::u32));
			for (ir::BasicBlock::EdgePointerVector::const_iterator edge_it = transition.block->out_edges.begin();
				edge_it != transition.block->out_edges.end(); ++edge_it) {
				resumePointOperand.imm_uint = entryTransitions[(*edge_it)->tail->label].first;
			}
			transition.block->instructions.erase(last);
			transition.type = Thread_barrier;
			
			ir::PTXInstruction *branch = new ir::PTXInstruction(ir::PTXInstruction::Bra);
			branch->d.addressMode = ir::PTXOperand::Label;
			branch->d.identifier = transition.handler->label;
			transition.block->instructions.insert(transition.block->instructions.end(), branch);
			transition.handler->comment = "barrier handler";
			
			// insert unconditional branch
			_createExitCode(transition, resumePointOperand, Thread_barrier);
		}
		break;
		case ir::PTXInstruction::Call:
		{
			assert(0 && "calls not implemented");
		}
		break;
		case ir::PTXInstruction::Exit:
		{
		
			ir::BasicBlock::InstructionList::iterator last = transition.block->instructions.end();
			--last;
			transition.block->instructions.erase(last);
			
			// create edge from block to handler
			ir::BasicBlock::Edge edge(transition.block, transition.handler, ir::BasicBlock::Edge::Branch);
			transition.edge = kernel->cfg()->insert_edge(edge);
		
			ir::PTXInstruction *branch = new ir::PTXInstruction(ir::PTXInstruction::Bra);
			branch->d.addressMode = ir::PTXOperand::Label;
			branch->d.identifier = transition.handler->label;
			transition.block->instructions.insert(transition.block->instructions.end(), branch);

			transition.handler->comment = "exit";
			
			_createExitCode(transition, Thread_exit);
		}
		break;
		default:
		{
			// only divergent control-flow instructions result in exits
		}
			break;
	};
}

/*!
	\brief 
*/
void KernelPartitioningPass::KernelDecomposition::_createExitCode(
	KernelTransitionPoint &transition,
	KernelPartitioningPass::ThreadExitCode exitCode) {
	
	ir::PTXOperand resumePointOperand;
	_createExitCode(transition, resumePointOperand, exitCode);
}

/*!
	\brief inserts the 
*/
void KernelPartitioningPass::KernelDecomposition::_createExitCode(
	KernelTransitionPoint &transition,
	const ir::PTXOperand &resumePointOperand,
	KernelPartitioningPass::ThreadExitCode exitCode) {

	analysis::DataflowGraph::RegisterId addrRegister = kernel->dfg()->newRegister();
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

		transition.handler->instructions.push_back(move);
		transition.handler->instructions.push_back(store);
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
	store->a.imm_uint = (unsigned int)exitCode;

	transition.handler->instructions.push_back(move);
	transition.handler->instructions.push_back(store);
	
	ir::PTXInstruction *exit = new ir::PTXInstruction(ir::PTXInstruction::Exit);
	transition.handler->instructions.push_back(exit);
	
	ir::BasicBlock::Edge exitEdge(transition.handler, kernel->cfg()->get_exit_block(), ir::BasicBlock::Edge::Dummy);
	kernel->cfg()->insert_edge(exitEdge);
	
	report("created exit in block '" << transition.handler->label << "' with code " << (int)exitCode);
}

void KernelPartitioningPass::KernelDecomposition::_createDummyScheduler() {

	ir::PTXInstruction *branch = new ir::PTXInstruction(ir::PTXInstruction::Bra);
	branch->d.addressMode = ir::PTXOperand::Label;
	branch->d.identifier = kernel->cfg()->get_entry_block()->out_edges[0]->tail->label;
	
	ir::BasicBlock schedulerBlock("$" + kernel->name + "_scheduler");
	ir::ControlFlowGraph::EdgePair edgePair = kernel->cfg()->split_edge(
		kernel->cfg()->get_entry_block()->out_edges[0], schedulerBlock);
	scheduler = edgePair.first->tail;
	edgePair.second->type = ir::BasicBlock::Edge::Branch;
		
	scheduler->instructions.push_back(branch);
	

	for (BlockEntryTransitionMap::const_iterator transition_it = entryTransitions.begin();
		transition_it != entryTransitions.end();
		++transition_it) {
		
		ir::BasicBlock::Edge edge(scheduler, transitionPoints[transition_it->second.first].handler, 
			ir::BasicBlock::Edge::Dummy);
		kernel->cfg()->insert_edge(edge);
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////

KernelPartitioningPass::KernelPartitioningPass() {

}


void KernelPartitioningPass::initialize(const ir::Module& m) {

}

void KernelPartitioningPass::runOnKernel(
	KernelDecomposition &decomposition, 
	ir::Kernel& parent, 
	EntryId baseId) {

	ir::PTXKernel& parentKernel = static_cast<ir::PTXKernel&>(parent);
	report("Run on kernel '" << parentKernel.name << "'");
#if REPORT_BASE > 0
	parentKernel.write(std::cout);
	report("\n\n");
#endif

	decomposition.runOnKernel(&parentKernel, baseId);
}

void KernelPartitioningPass::finalize() {

}


/////////////////////////////////////////////////////////////////////////////////////////////////

}

/////////////////////////////////////////////////////////////////////////////////////////////////
