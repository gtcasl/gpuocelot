/*! \file   SuperblockAnalysis.cpp
	\author Gregory Diamos <gdiamos@nvidia.com>
	\date   Monday August 15, 2011
	\brief  The source file for the superblock analysis class.
*/

// Ocelot Includes
#include <ocelot/analysis/interface/SuperblockAnalysis.h>

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

SuperblockAnalysis::SuperblockAnalysis(ir::ControlFlowGraph& c, unsigned int b)
: _cfg(&c)
{
	typedef std::unordered_set<ir::ControlFlowGraph::iterator> BlockSet;
		
	// Find all trivial superblocks, assume they were freed up previously
	//  by tail duplication, unrolling, and peeling
	report("Finding superblocks.");
	report(" Seeding superblocks.");
	BlockSet superblocks;
	BlockSet visited;
		
	report("  Starting a new superblock at " << _cfg->get_entry_block()->label
		<< " (" << _cfg->get_entry_block()->id << ")");
	superblocks.insert(_cfg->get_entry_block());
	visited.insert(_cfg->get_entry_block());
	
	// Superblocks start from multiple-entry blocks
	for(ir::ControlFlowGraph::iterator block = _cfg->begin();
		block != _cfg->end(); ++block)
	{
		if(block->predecessors.size() > 1)
		{
			report("  Starting a new superblock at " << block->label
				<< " (" << block->id << ")");
			superblocks.insert(block);
			visited.insert(block);
		}
	}
	
	// Find successors with only one predecessor, these can be included
	report(" Adding successors.");
	for(BlockSet::iterator block = superblocks.begin();
		block != superblocks.end(); ++block)
	{
		report("  For superblock " << (*block)->label << " ("
			<< (*block)->id << ")"); 
		iterator superblock = newBlock();
		ir::ControlFlowGraph::iterator next = *block;
	
		superblock->insert(*block);

		while(next != _cfg->end())
		{
			ir::ControlFlowGraph::iterator current = next;
			next = _cfg->end();
			for(ir::ControlFlowGraph::pointer_iterator successor =
				current->successors.begin();
				successor != current->successors.end(); ++successor)
			{
				// right now we just pick the first one,
				// TODO: use profiling information
				if((*successor)->predecessors.size() == 1)
				{
					report("   Added successor " << (*successor)->label
						<< " (" << (*successor)->id << ")");
					superblock->insert(*successor);
					visited.insert(*successor);
					next = *successor;
					break;
				}
			}
		}
		
		if(*block == _cfg->get_entry_block())
		{
			_entry = superblock;
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
		}
	}
}

}


