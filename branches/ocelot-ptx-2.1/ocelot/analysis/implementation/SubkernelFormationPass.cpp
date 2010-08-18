/*! \file SubkernelFormationPass.cpp
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Tuesday July 27, 2010
	\brief The source file for the SubkernelFormationPass class.

	Notes:
	The motivation here is fourfold:
		 1) Create natural boundaries for context switching between threads.
		 2) Enforce that all threads in a CTA execute loosely in lock-step to 
		 	improve data/instruction locality.
		 3) Coarsen regions between barriers to amortize their cost.
		 4) Create well-defined regions for performing local optimizations.  
		 	Reduce the complexity of subsequent operations with complexities 
		 	that depend on the kernel size.
*/

#ifndef SUBKERNEL_FORMATION_PASS_CPP_INCLUDED
#define SUBKERNEL_FORMATION_PASS_CPP_INCLUDED

// Ocelot Includes
#include <ocelot/analysis/interface/SubkernelFormationPass.h>
#include <ocelot/ir/interface/Module.h>

// Hydrazine Includes
#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1

// Standard Library Includes
#include <queue>

namespace analysis
{

SubkernelFormationPass::SubkernelFormationPass(unsigned int e, bool s)
	: ModulePass(false, "SubkernelFormationPass"), 
	_expectedRegionSize(e), _insertScheduler(s)
{

}

void SubkernelFormationPass::runOnModule(ir::Module& m)
{
	assertM(!_insertScheduler, "Not supported yet.");
	
	report("Running SubkernelFormationPass");
	// This pass requires all kernels to be loaded
	m.loadNow();

	ExtractKernelsPass pass(_expectedRegionSize, _insertScheduler);
	
	pass.initialize(m);

	for(ir::Module::KernelMap::const_iterator kernel = m.kernels().begin(); 
		kernel != m.kernels().end(); ++kernel)
	{
		pass.runOnKernel(*kernel->second);
	}

	pass.finalize();
	
	report(" Adding subkernels to the module.");
	for(ExtractKernelsPass::KernelVectorMap::const_iterator 
		kernel = pass.kernels.begin(); 
		kernel != pass.kernels.end(); ++kernel)
	{
		report("  Replacing kernel " << kernel->first);
		m.removeKernel(kernel->first);
		for(ExtractKernelsPass::KernelVector::const_iterator 
			subkernel = kernel->second.begin();
			subkernel != kernel->second.end(); ++subkernel)
		{
			report("   with " << (*subkernel)->name);
			m.insertKernel(*subkernel);
		}
	}
}

SubkernelFormationPass::ExtractKernelsPass::ExtractKernelsPass(
	unsigned int regionSize, bool s) : 
	KernelPass(false, "SubkernelFormationPass"), 
	_expectedRegionSize(regionSize), 
	_insertScheduler(s)
{

}

void SubkernelFormationPass::ExtractKernelsPass::initialize(const ir::Module& m)
{
	
}

typedef std::unordered_set<ir::ControlFlowGraph::iterator> BlockSet;

static ir::ControlFlowGraph::iterator _createRegion(unsigned int& scratchSize, 
	ir::PTXKernel& newKernel, ir::PTXKernel& ptx, const BlockSet& region, 
	const BlockSet& inEdges, ir::ControlFlowGraph::iterator entry)
{
	typedef std::vector<ir::Edge> EdgeVector;
	typedef std::unordered_map<ir::ControlFlowGraph::iterator, 
		ir::ControlFlowGraph::iterator> BlockMap;
	report("  Creating sub-kernel " << newKernel.name);
	
	ir::ControlFlowGraph::iterator exit = ptx.cfg()->get_exit_block();
	
	ir::BasicBlock::EdgePointerVector deletedEdges;
	EdgeVector newEdges;
	BlockMap oldToNewBlockMap;
	unsigned int localScratchSize = ir::PTXOperand::bytes(ir::PTXOperand::u32);

	// create the map of old to new blocks
	for(BlockSet::const_iterator block = region.begin(); 
		block != region.end(); ++block)
	{
		ir::ControlFlowGraph::iterator newBlock = newKernel.cfg()->insert_block(
			ir::BasicBlock((*block)->label, newKernel.cfg()->newId(), 
			(*block)->instructions));
	
		oldToNewBlockMap.insert(std::make_pair(*block, newBlock));
	}

	// Create the return block
	ir::ControlFlowGraph::iterator returnBlock = newKernel.cfg()->insert_block(
		ir::BasicBlock(newKernel.name + "_return", newKernel.cfg()->newId()));
	newKernel.cfg()->insert_edge(ir::Edge(returnBlock, 
		newKernel.cfg()->get_exit_block(), ir::Edge::Branch));
		
	returnBlock->instructions.insert(returnBlock->instructions.end(), 
		new ir::PTXInstruction(ir::PTXInstruction::Ret));
	
	for(BlockSet::const_iterator block = region.begin(); 
		block != region.end(); ++block)
	{
		report("   Adding block " << (*block)->label);

		for(ir::ControlFlowGraph::edge_pointer_iterator 
			edge = (*block)->out_edges.begin(); 
			edge != (*block)->out_edges.end(); ++edge)
		{
			ir::ControlFlowGraph::iterator tail = (*edge)->tail;

			// skip edges that exit the main kernel
			if(tail == ptx.cfg()->get_exit_block())
			{
				BlockMap::iterator head = oldToNewBlockMap.find((*edge)->head);
				assert(head != oldToNewBlockMap.end());
			
				newKernel.cfg()->insert_edge(ir::Edge(head->second, 
					newKernel.cfg()->get_exit_block(), (*edge)->type));
				deletedEdges.push_back(*edge);

				continue;
			}

			// skip edges that are contained in the region
			if(region.count(tail) != 0)
			{
				BlockMap::iterator tail = oldToNewBlockMap.find((*edge)->tail);
				BlockMap::iterator head = oldToNewBlockMap.find((*edge)->head);
				assert(tail != oldToNewBlockMap.end());
				assert(head != oldToNewBlockMap.end());
			
				newKernel.cfg()->insert_edge(ir::Edge(head->second, 
					tail->second, (*edge)->type));

				continue;
			}

			// edges that leave the region are directed to the save point
			BlockMap::iterator newHead = oldToNewBlockMap.find((*edge)->head);
			assert(newHead != oldToNewBlockMap.end());
			newKernel.cfg()->insert_edge(ir::Edge(newHead->second, 
				returnBlock, (*edge)->type));

			// Real edges to new blocks need to be searched next
			if(tail == ptx.cfg()->get_entry_block()) continue;

			if(exit == ptx.cfg()->get_exit_block())
			{
				report("   Creating exit point - " 
					<< ptx.name << "_split_entry" );
				exit = ptx.cfg()->insert_block(ir::BasicBlock(newKernel.name 
					+ "_split_entry", ptx.cfg()->newId()));			
			}
			
			ir::ControlFlowGraph::iterator head = (*edge)->head;
			report("    Redirecting edge from block_" << head->id 
				<< " -> block_" << tail->id << " to context save point" );
			
			deletedEdges.push_back(*edge);
			newEdges.push_back(ir::Edge(exit, tail, ir::Edge::Branch));
		}
	}
	
	report("   Setting edges in new kernel CFG.");
	for(ir::ControlFlowGraph::edge_pointer_iterator edge = deletedEdges.begin();
		edge != deletedEdges.end(); ++edge)
	{
		ir::ControlFlowGraph::iterator head = (*edge)->head;
		ir::ControlFlowGraph::iterator tail = (*edge)->tail;

		// insert instructions in the new kernel to save the context before
		// leaving the kernel
/*
		BlockMap::iterator newBlockPointer = oldToNewBlockMap.find(head);
		assert(newBlockPointer != oldToNewBlockMap.end());
		ir::ControlFlowGraph::iterator block = newBlockPointer->second;

		ir::BasicBlock::InstructionList::iterator instruction =
			block->instructions.end();
		if((*edge)->type == ir::Edge::Branch)
		{
			--instruction;
			ir::PTXInstruction* branch = 
				static_cast<ir::PTXInstruction*>(*instruction);
			assert(branch->opcode == ir::PTXInstruction::Bra);
			report("    Converting '" << branch->toString() << "' to return");
			branch->opcode = ir::PTXInstruction::Ret;
		}
		else
		{
			block = newKernel.cfg()->insert_block(ir::BasicBlock(
				block->label + "_fallthrough", newKernel.cfg()->newId()));
			newKernel.cfg()->insert_edge(ir::Edge(newBlockPointer->second, 
				block, ir::Edge::FallThrough));
			report("    Converting fallthrough branch to return");
			instruction = block->instructions.insert(block->instructions.end(), 
				new ir::PTXInstruction(ir::PTXInstruction::Ret));
		}
		
		newKernel.cfg()->insert_edge(ir::Edge(block, 
			newKernel.cfg()->get_exit_block(), ir::Edge::Branch));
		
		ir::PTXInstruction* st = new ir::PTXInstruction(
			ir::PTXInstruction::St);
		st->addressSpace = ir::PTXInstruction::Param;
		st->d.identifier = "_ZOcelot_subkernel_context";
		st->d.addressMode = ir::PTXOperand::Address;
		st->d.type = ir::PTXOperand::u64;
		st->a.addressMode = ir::PTXOperand::Immediate;
		st->a.type = ir::PTXOperand::u32;
		st->a.imm_uint = (*edge)->tail->id;
		st->type = ir::PTXOperand::u32;
		
		block->instructions.insert(instruction, st);
*/		
		// TODO finish this
	}
	
	report("   Merging entry points");
	for(BlockSet::const_iterator block = inEdges.begin(); 
		block != inEdges.end(); ++block)
	{
		report("    From block " << (*block)->label);
		for(ir::ControlFlowGraph::edge_pointer_iterator 
			edge = (*block)->out_edges.begin(); 
			edge != (*block)->out_edges.end(); ++edge)
		{
			// skip edges not entering the region
			ir::ControlFlowGraph::iterator tail = (*edge)->tail;
			if(region.count(tail) == 0) continue;
			
			ir::ControlFlowGraph::iterator head = (*edge)->head;
			report("     Replacing edge from block_" << head->id 
				<< " -> block_" << tail->id << " with scheduler block" );
			
			deletedEdges.push_back(*edge);
			newEdges.push_back(ir::Edge(head,
				ptx.cfg()->get_entry_block(), (*edge)->type));
			
			BlockMap::iterator newTail = oldToNewBlockMap.find(tail);
			assert(newTail != oldToNewBlockMap.end());
			
			newKernel.cfg()->insert_edge(ir::Edge(
				newKernel.cfg()->get_entry_block(),
				newTail->second, ir::Edge::Branch));
		}
	}

	if(entry == ptx.cfg()->get_entry_block())
	{
		BlockMap::iterator newTail = oldToNewBlockMap.find(
			entry->get_fallthrough_edge()->tail);
			assert(newTail != oldToNewBlockMap.end());

		newKernel.cfg()->insert_edge(ir::Edge(
			newKernel.cfg()->get_entry_block(),
			newTail->second, ir::Edge::FallThrough));
	}

	for(ir::ControlFlowGraph::edge_pointer_iterator edge = deletedEdges.begin();
		edge != deletedEdges.end(); ++edge)
	{
		ptx.cfg()->remove_edge(*edge);
	}

	for(EdgeVector::iterator edge = newEdges.begin();
		edge != newEdges.end(); ++edge)
	{
		ptx.cfg()->insert_edge(*edge);
	}

	report("   Kernel exit point is " << exit->label);

	scratchSize = std::max(scratchSize, localScratchSize);

	report("   Scratch requirement is " << scratchSize);
		
	return exit;
}

/* algorithm
    1) start at a kernel entry point that dominates all remaining blocks
    2) create a connected subgraph with N instructions and no barriers
      a) This is a new kernel
    3) For all edges leaving the graph
      a) save all live registers
      b) save the target block's id
      c) create a new scheduler block includes an indirect branch to each 
         of the targets
      d) redirect each edge to the kernel exit point
      e) create a new kernel rooted in the new scheduler block, goto 1
*/
void SubkernelFormationPass::ExtractKernelsPass::runOnKernel(ir::Kernel& k)
{
	typedef std::vector<ir::ControlFlowGraph::iterator> BlockQueue;
	report(" Splitting kernel '" << k.name << "' into sub-kernel regions.");
	
	BlockQueue queue;
	KernelVector splitKernels;
	BlockSet region;
	BlockSet encountered;
	BlockSet inEdges;

	unsigned int currentRegionSize = 0;
	unsigned int kernelId = 0;
	unsigned int scratchSize = 0;

	std::string originalName = k.name;
	
	ir::PTXKernel& ptx = static_cast<ir::PTXKernel&>(k);
	
	// This is the new kernel entry point
	splitKernels.push_back(new ir::PTXKernel(k.name, _insertScheduler));

	ir::PTXKernel* newKernel = splitKernels.back();

	report(" New kernel name is " << newKernel->name);

	// Start at the entry block	
	ir::ControlFlowGraph::iterator entry = ptx.cfg()->get_entry_block();
	queue.push_back(entry);
	
	while(true)
	{
		// The front of the queue becomes part of the region
		ir::ControlFlowGraph::iterator block = queue.back();
		queue.pop_back();

		// Remove this block from the entering list (if it exists)
		inEdges.erase(block);

		// Keep track of all blocks entering the region
		for(ir::ControlFlowGraph::const_edge_pointer_iterator 
			edge = block->in_edges.begin(); 
			edge != block->in_edges.end(); ++edge)
		{
			// skip already encountered blocks
			if(!encountered.insert((*edge)->head).second) continue;
			// skip the entry block
			if((*edge)->head == ptx.cfg()->get_entry_block()) continue;
			
			inEdges.insert((*edge)->head);
		}

		// Blocks leaving the region become candidates for the next block
		for(ir::ControlFlowGraph::const_edge_pointer_iterator 
			edge = block->out_edges.begin(); 
			edge != block->out_edges.end(); ++edge)
		{
			ir::ControlFlowGraph::iterator tail = (*edge)->tail;

			// skip the exit block
			if(tail == ptx.cfg()->get_exit_block()) continue;
			
			// blocks targetting the entry block are actually dummy blocks
			// that need to be directed to the context save block
			if(tail == ptx.cfg()->get_entry_block()) continue;
			
			// skip already encountered blocks
			if(!encountered.insert(tail).second) continue;
			
			// push successor blocks
			queue.push_back(tail);
		}

		// Add the block to the new kernel (skip the entry)
		if(block == entry) continue;

		currentRegionSize += block->instructions.size();
		region.insert(block);
		
		// create a new region if there are enough blocks
		if(currentRegionSize < _expectedRegionSize && !queue.empty()) continue;
		
		entry = _createRegion(scratchSize, *newKernel, ptx, 
			region, inEdges, entry);
		
		// restart with a new kernel if there are any blocks left
		if(entry == ptx.cfg()->get_exit_block()) break;

		currentRegionSize = 0;
		
		std::stringstream name;
		name << originalName << "_split_" << kernelId++;
		
		splitKernels.push_back(new ir::PTXKernel(name.str(), true));
		encountered.clear();
		inEdges.clear();
		region.clear();
		queue.clear();
		queue.push_back(entry);

		newKernel = splitKernels.back();
		report(" New kernel name is " << newKernel->name);
	}
	
	kernels.insert(std::make_pair(k.name, std::move(splitKernels)));
}

void SubkernelFormationPass::ExtractKernelsPass::finalize()
{
	
}

}

#endif

