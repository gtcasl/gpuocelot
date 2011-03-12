/*! 
	\file HyperblockFormationPass.cpp
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

analysis::HyperblockFormationPass::HyperblockFormationPass() {

}

void analysis::HyperblockFormationPass::runOnModule(ir::Module& m) {

}

/////////////////////////////////////////////////////////////////////////////////////////////////

analysis::HyperblockFormationPass::ExtractHyperblocksPass::ExtractHyperblocksPass() {
}

void analysis::HyperblockFormationPass::ExtractHyperblocksPass::initialize(const ir::Module& m) {

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
void analysis::HyperblockFormationPass::ExtractHyperblocksPass::runOnKernel(ir::Kernel& parent) {
	//
	// construct a new subkernel for each sequence of basic blocks with provable convergence
	// properties
	//
	
	
	ir::PTXKernel& parentKernel = static_cast<ir::PTXKernel&>(parent);
	report("Run on kernel " << parentKernel.name);

	// Compute live register sets for each block
	KernelVector hyperblocks;
	
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
		DataflowGraph::IteratorMap::const_iterator dfgBlock = cfgToDfgMap.find(*bb_it);
		assert(dfgBlock != cfgToDfgMap.end() && "failed to find block in CFT-to-DFG mapping");
		
		ir::PTXKernel *subkernel = new ir::PTXKernel(
			parentKernel.name + "_hb_" + boost::lexical_cast<std::string>(blockIndex), 
			false, 
			parentKernel.module);

		ir::ControlFlowGraph::iterator computationalBlock = subkernel->cfg()->insert_new_block((*bb_it)->label);
		for (ir::BasicBlock::InstructionList::const_iterator inst_it = (*bb_it)->instructions.begin();
			inst_it != (*bb_it)->instructions.end();
			++inst_it) {
			computationalBlock->instructions.push_back((*inst_it)->clone());
		}

		ir::BasicBlock::Edge entryEdge(subkernel->cfg()->get_entry_block(), computationalBlock );
		ir::BasicBlock::Edge exitEdge(computationalBlock, subkernel->cfg()->get_exit_block() );
		ir::ControlFlowGraph::edge_iterator entryIterator = subkernel->cfg()->insert_edge(entryEdge);
		ir::ControlFlowGraph::edge_iterator exitIterator = subkernel->cfg()->insert_edge(exitEdge);
		
		// now create prologe/restore and epilog/store blocks
		ir::BasicBlock prologBlock;
		ir::BasicBlock epilogBlock;
		
		
		_createSpillRegion(*subkernel, parentKernel, prologBlock);
		_createRestore(*subkernel, parentKernel, prologBlock, dfgBlock);
		_createStore(*subkernel, parentKernel, epilogBlock, dfgBlock);
		_createHyperblockExit(*subkernel, parentKernel, **bb_it, *computationalBlock, epilogBlock);
		
		ir::ControlFlowGraph::EdgePair splitEntry = subkernel->cfg()->split_edge(entryIterator, prologBlock);
		ir::ControlFlowGraph::EdgePair splitExit = subkernel->cfg()->split_edge(exitIterator, epilogBlock);
		hyperblocks.push_back(subkernel);
	}
	
	kernels.insert(std::make_pair(&parentKernel, hyperblocks));
}

void analysis::HyperblockFormationPass::ExtractHyperblocksPass::finalize() {

}

/////////////////////////////////////////////////////////////////////////////////////////////////

void analysis::HyperblockFormationPass::ExtractHyperblocksPass::_createSpillRegion(
	ir::PTXKernel &subkernel, 
	ir::PTXKernel &parentKernel,
	ir::BasicBlock &restoreBlock) {
	
	unsigned int spillRegionSize = 10;

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

size_t analysis::HyperblockFormationPass::ExtractHyperblocksPass::_createRestore(
	ir::PTXKernel &hyperblock,
	ir::PTXKernel &parentKernel,
	ir::BasicBlock &restoreBlock,
	DataflowGraph::IteratorMap::const_iterator dfgBlock) {

	size_t bytes = 0;

	ir::PTXInstruction* move = new ir::PTXInstruction(ir::PTXInstruction::Mov);

	for(DataflowGraph::RegisterSet::const_iterator reg = dfgBlock->second->aliveIn().begin(); 
		reg != dfgBlock->second->aliveIn().end(); 
		++reg) {
	
		report("    restoring r" << reg->id << " (" << ir::PTXOperand::bytes(reg->type) << " bytes)");
		
		ir::PTXInstruction* load = new ir::PTXInstruction(ir::PTXInstruction::Ld);
		
		load->addressSpace = ir::PTXInstruction::Local;
		load->type = reg->type;

		load->a = std::move(ir::PTXOperand(ir::PTXOperand::Indirect, ir::PTXOperand::u32, move->d.reg, bytes));
		load->d = std::move(ir::PTXOperand(ir::PTXOperand::Register, reg->type, reg->id));
	
		restoreBlock.instructions.push_back(load);
	
		bytes += ir::PTXOperand::bytes(reg->type);
	}

	return bytes;
}

	
//! \brief stores live variables to local memory
size_t analysis::HyperblockFormationPass::ExtractHyperblocksPass::_createStore(
	ir::PTXKernel &hyperblock,
	ir::PTXKernel &parentKernel,
	ir::BasicBlock &exitBlock,
	DataflowGraph::IteratorMap::const_iterator dfgBlock) {
	
	size_t offset = 0;

	ir::PTXInstruction* move = new ir::PTXInstruction(ir::PTXInstruction::Mov);
	for(DataflowGraph::RegisterSet::const_iterator reg = dfgBlock->second->aliveOut().begin(); 
		reg != dfgBlock->second->aliveOut().end(); 
		++reg) {
		
		report("    saving r" << reg->id << " (" << ir::PTXOperand::bytes(reg->type) << " bytes)");
	
		ir::PTXInstruction* store =	new ir::PTXInstruction(ir::PTXInstruction::St);
	
		store->addressSpace = ir::PTXInstruction::Local;
		store->type = reg->type;

		store->d = std::move(ir::PTXOperand(ir::PTXOperand::Indirect,	ir::PTXOperand::u32, move->d.reg, offset));
		store->a = std::move(ir::PTXOperand(ir::PTXOperand::Register,	reg->type, reg->id));

		exitBlock.instructions.push_back(store);

		offset += ir::PTXOperand::bytes(reg->type);
	}
	
	return offset;
}
	
//! \brief stores a target block ID as well as exit code to the spill area
size_t analysis::HyperblockFormationPass::ExtractHyperblocksPass::_createHyperblockExit(
	ir::PTXKernel &subkernel,
	ir::PTXKernel &parentKernel,
	const ir::BasicBlock &parentBlock,
	ir::BasicBlock &clonedBlock,
	ir::BasicBlock &exitBlock) {

	// replace branch terminator instructions with stores to target hyperblocks
	// use selp for conditional branches
	ir::BasicBlock::InstructionList::iterator last = clonedBlock.instructions.end();
	--last;
	ir::PTXInstruction *terminator = static_cast<ir::PTXInstruction *>(*last);
	
	ir::PTXOperand::RegisterType targetRegister = 0;
	switch (terminator->opcode) {
		case ir::PTXInstruction::Bra:
		{
			if (terminator->pg.addressMode == ir::PTXOperand::Register && 
				terminator->pg.type == ir::PTXOperand::pred) {
				// conditional branch
				ir::PTXInstruction *selp = new ir::PTXInstruction(ir::PTXInstruction::SelP);
				selp->d = std::move(ir::PTXOperand(ir::PTXOperand::Register, ir::PTXOperand::u32, subkernel.dfg()->newRegister()));
				
				selp->a = std::move(ir::PTXOperand(ir::PTXOperand::Immediate, ir::PTXOperand::u32));
				selp->b = std::move(ir::PTXOperand(ir::PTXOperand::Immediate, ir::PTXOperand::u32));
				selp->a.imm_uint = 0;	// branch target hyperblock id
				selp->b.imm_uint = 0;	// fall through target hyperblock id
				selp->c = terminator->pg;
				
				targetRegister = selp->d.reg;
				
				exitBlock.instructions.push_back(selp);
				clonedBlock.instructions.erase(last);
			}
			else {
				// unconditional branch
			}
			// store 
			ir::PTXInstruction *move = new ir::PTXInstruction(ir::PTXInstruction::Mov);
			move->a = std::move(ir::PTXOperand(ir::PTXOperand::Address, ir::PTXOperand::u32, "_Zocelot_resume_point"));
			move->d = std::move(ir::PTXOperand(ir::PTXOperand::Register, ir::PTXOperand::u32, subkernel.dfg()->newRegister()));
			move->type = ir::PTXOperand::u32;
	
			ir::PTXInstruction *store = new ir::PTXInstruction(ir::PTXInstruction::St);
			store->addressSpace = ir::PTXInstruction::Local;
			store->type = ir::PTXOperand::u32;
			store->d = std::move(ir::PTXOperand(ir::PTXOperand::Indirect, ir::PTXOperand::u32, move->d.reg, 0));
			store->a = std::move(ir::PTXOperand(ir::PTXOperand::Register, ir::PTXOperand::u32, targetRegister));
	
			exitBlock.instructions.push_back(move);
		}
		break;
		case ir::PTXInstruction::Exit:
		{
			// nothing
		}
		default:
			break;
	}
	
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////

