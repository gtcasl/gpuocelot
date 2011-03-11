/*! 
	\file HyperblockFormationPass.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date March 2011
	\brief Defines a hyperblock formation pass for convergent execution
*/


// C++ includes
#include <queue>

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

analysis::HyperblockFormationPass::HyperblockFormationPass() {

}

void analysis::HyperblockFormationPass::runOnModule(ir::Module& m) {

}

/////////////////////////////////////////////////////////////////////////////////////////////////

void analysis::HyperblockFormationPass::ExtractHyperblocksPass::initialize(const ir::Module& m) {

}

void analysis::HyperblockFormationPass::ExtractHyperblocksPass::runOnKernel(ir::Kernel& parent) {
	//
	// construct a new subkernel for each sequence of basic blocks with provable convergence
	// properties
	//
	
	/*
		For each basic block, 
			1.) construct a subkernel
			2.) add a copy of the basic block to this subkernel
			3.) add a new predecessor block declaring a .local spill region
				in the predecessor, store live values [assuming a global mapping of register ID to .local memory region]
			4.) add a successor block
				in the successor, store live out values [assuming a global mapping of register IDs to .local memory regions
				add a subkernel exit descriptor
	*/
	
	ir::PTXKernel& parentKernel = static_cast<ir::PTXKernel&>(parent);

	// Compute live register sets for each block
	KernelVector hyperblocks;
	
	parentKernel.dfg()->compute();
	analysis::DataflowGraph::IteratorMap cfgToDfgMap = parentKernel.dfg()->getCFGtoDFGMap();
	ir::ControlFlowGraph *cfg = parentKernel.cfg();
	
	ir::ControlFlowGraph::BlockPointerVector blocks = cfg->topological_sequence();
	for (ir::ControlFlowGraph::BlockPointerVector::const_iterator bb_it = blocks.begin(); 
		bb_it != blocks.end(); 
		++bb_it) {
		
		DataflowGraph::IteratorMap::const_iterator dfgBlock = cfgToDfgMap.find(*bb_it);
		assert(dfgBlock != cfgToDfgMap.end() && "failed to find block in CFT-to-DFG mapping");
		
		ir::PTXKernel *subkernel = new ir::PTXKernel(parentKernel.name, false, parentKernel.module);
		ir::BasicBlock clonedBlock;
		
		ir::ControlFlowGraph::iterator computationalBlock = subkernel->cfg()->insert_new_block((*bb_it)->label);
		for (ir::BasicBlock::InstructionList::const_iterator inst_it = (*bb_it)->instructions.begin();
			inst_it != (*bb_it)->instructions.end();
			++inst_it) {
			
			computationalBlock->instructions.push_back((*inst_it)->clone());
		}
		/*
		ir::BasicBlock::Edge entryEdge(subkernel->cfg()->get_entry_block(), clonedBlock );
		ir::BasicBlock::Edge exitEdge( );
		*/
		
		
		hyperblocks.push_back(subkernel);
	}
	
	kernels.insert(std::make_pair(&parentKernel, hyperblocks));
}

void analysis::HyperblockFormationPass::ExtractHyperblocksPass::finalize() {

}

/////////////////////////////////////////////////////////////////////////////////////////////////

void analysis::HyperblockFormationPass::ExtractHyperblocksPass::_createSpillRegion(
	ir::PTXKernel &subkernel, 
	ir::PTXKernel &parentKernel) {
	
	unsigned int spillRegionSize = 10;

	subkernel.arguments  = parentKernel.arguments;
	subkernel.parameters = parentKernel.parameters;
	subkernel.locals     = parentKernel.locals;
	
	ir::PTXStatement resume(ir::PTXStatement::Local);
		
	resume.type = ir::PTXOperand::u32;
	resume.name = "_Zocelot_resume_point";
	
	subkernel.locals.insert(std::make_pair(resume.name, ir::Local(resume)));
	
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
	const analysis::DataflowGraph::RegisterSet &aliveIn) {

	size_t bytes = 0;

	ir::PTXInstruction* move = new ir::PTXInstruction(ir::PTXInstruction::Mov);
	for(DataflowGraph::RegisterSet::const_iterator reg = aliveIn.begin(); reg != aliveIn.end(); ++reg) {
	
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
	const analysis::DataflowGraph::RegisterSet &aliveOut) {
	
	size_t offset = 0;

	ir::PTXInstruction* move = new ir::PTXInstruction(ir::PTXInstruction::Mov);
	for(DataflowGraph::RegisterSet::const_iterator reg = aliveOut.begin(); reg != aliveOut.end(); ++reg) {
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
	ir::PTXKernel &hyperblock,
	ir::PTXKernel &parentKernel,
	ir::BasicBlock &exitBlock,
	unsigned int nextBlockId,
	unsigned int exitCode) {

/*	
	ir::PTXInstruction* move = new ir::PTXInstruction(ir::PTXInstruction::Mov);

	move->a = std::move(ir::PTXOperand(ir::PTXOperand::Address, ir::PTXOperand::u32, "_Zocelot_spill_area"));
	move->d = std::move(ir::PTXOperand(ir::PTXOperand::Register, ir::PTXOperand::u32, ptx.dfg()->newRegister()));
	move->type = ir::PTXOperand::u32;
	exitBlock.instructions.push_back(move);
	*/
	
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////

