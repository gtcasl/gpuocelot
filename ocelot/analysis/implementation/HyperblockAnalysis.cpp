/*! \file   HyperblockAnalysis.cpp
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date   Saturday October 8, 2011
	\brief  The source file for the HyperblockAnalysis class.
*/

// Ocelot Includes
#include <ocelot/analysis/interface/HyperblockAnalysis.h>
#include <ocelot/ir/interface/IRKernel.h>

// Hydrazine Includes
#include <hydrazine/implementation/debug.h>

// Standard Library Includes
#include <unordered_set>

// Preprocessor Macros
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1

namespace analysis
{

HyperblockAnalysis::HyperblockAnalysis(unsigned int b)
: _cfg(0), _blockSize(b)
{

}

void HyperblockAnalysis::analyze(ir::IRKernel& kernel)
{
	_cfg = kernel.cfg();

	typedef std::unordered_set<ir::ControlFlowGraph::iterator> BlockSet;
	typedef std::list<ir::ControlFlowGraph::iterator>          BlockList;
		
	// Find all trivial hyperblocks, assume they were freed up previously
	//  by tail duplication, unrolling, and peeling.  Complex predicated
	//  blocks will be created by subsequent passes.
	report("Finding hyperblocks.");
	report(" Seeding hyperblocks.");
	BlockList hyperblocks;
	BlockSet  visited;
		
	report("  Starting a new hyperblock at " << _cfg->get_entry_block()->label
		<< " (" << _cfg->get_entry_block()->id << ")");
	hyperblocks.push_back(_cfg->get_entry_block());
	visited.insert(_cfg->get_entry_block());
	
	// Find successors with all predecessors in the hyperblock,
	//  these can be included
	report(" Adding successors.");
	for(BlockList::iterator block = hyperblocks.begin();
		block != hyperblocks.end(); ++block)
	{
		report("  For hyperblock " << (*block)->label << " ("
			<< (*block)->id << ")"); 
		iterator hyperblock = newBlock();
		
		// The set of blocks that have been added to the hyperblock,
		//  but not explored yet
		BlockSet frontier; 
		
		frontier.insert(*block);
		hyperblock->insert(*block);

		while(!frontier.empty())
		{
			ir::ControlFlowGraph::iterator current = *frontier.begin();
			frontier.erase(frontier.begin());
			
			for(ir::ControlFlowGraph::pointer_iterator successor =
				current->successors.begin();
				successor != current->successors.end(); ++successor)
			{
				// don't add the exit block!
				if(*successor == kernel.cfg()->get_exit_block()) continue;
				
				// add all blocks with all predecessors in the hyperblock
				bool allPredecessorsContained = true;

				for(ir::ControlFlowGraph::pointer_iterator predecessor =
					(*successor)->predecessors.begin();
					predecessor != (*successor)->predecessors.end();
					++predecessor)
				{
					if(!hyperblock->contains(*predecessor))
					{
						allPredecessorsContained = false;
						break;
					}
				}
				
				// and no successors that are already contained other than
				//  the entry point.  This prevents self-loops that do not
				//  enter at the entry point.
				bool noSuccessorsContained = true;

				for(ir::ControlFlowGraph::pointer_iterator nextSuccessor =
					(*successor)->successors.begin();
					nextSuccessor != (*successor)->successors.end();
					++nextSuccessor)
				{ 
					if(*nextSuccessor != *block &&
						hyperblock->contains(*successor))
					{
						noSuccessorsContained = false;
						break;
					}
				}

				if(allPredecessorsContained && noSuccessorsContained)
				{
					report("   Added successor " << (*successor)->label
						<< " (" << (*successor)->id << ")");
					hyperblock->insert(*successor);
					visited.insert(*successor);
					frontier.insert(*successor);
				}
			}
		}
		
		report("   hyperblock has " << hyperblock->instructions()
			<< " instructions");
		
		if(*block == _cfg->get_entry_block())
		{
			_entry = hyperblock;
		}
		
		// seed new hyperblocks from unvisited hyperblock successors
		for(Block::block_iterator contained = hyperblock->block_begin();
			contained != hyperblock->block_end(); ++contained)
		{
			for(ir::ControlFlowGraph::pointer_iterator successor =
				contained->successors.begin();
				successor != contained->successors.end(); ++successor)
			{
				if(visited.count(*successor) == 0)
				{
					report("  Starting a new hyperblock at "
						<< (*successor)->label
						<< " (" << (*successor)->id << ")");
					hyperblocks.push_back(*successor);
					visited.insert(*successor);
				}
			}
		}
	}
	
	// Add regular blocks to fill out the program structure
	report(" Adding stragglers.");
	for(ir::ControlFlowGraph::iterator block = _cfg->begin();
		block != _cfg->end(); ++block)
	{
		if(visited.count(block) == 0)
		{
			report("  Adding normal block " << block->label << " ("
				<< block->id << ")");
			
			iterator normalblock = newBlock();

			normalblock->insert(block);
		
			report("   basic block has " << normalblock->instructions()
				<< " instructions");
		}
	}
}

}

