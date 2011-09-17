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
	typedef std::list<ir::ControlFlowGraph::iterator>          BlockList;
		
	// Find all trivial superblocks, assume they were freed up previously
	//  by tail duplication, unrolling, and peeling
	report("Finding superblocks.");
	report(" Seeding superblocks.");
	BlockList superblocks;
	BlockSet  visited;
		
	report("  Starting a new superblock at " << _cfg->get_entry_block()->label
		<< " (" << _cfg->get_entry_block()->id << ")");
	superblocks.push_back(_cfg->get_entry_block());
	visited.insert(_cfg->get_entry_block());
	
	// Superblocks start from multiple-entry blocks
	for(ir::ControlFlowGraph::iterator block = _cfg->begin();
		block != _cfg->end(); ++block)
	{
		if(block->predecessors.size() > 1)
		{
			report("  Starting a new superblock at " << block->label
				<< " (" << block->id << ")");
			superblocks.push_back(block);
			visited.insert(block);
		}
	}
	
	// Find successors with only one predecessor, these can be included
	report(" Adding successors.");
	for(BlockList::iterator block = superblocks.begin();
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
				if(next == _cfg->end())
				{
					if((*successor)->predecessors.size() == 1)
					{
						report("   Added successor " << (*successor)->label
							<< " (" << (*successor)->id << ")");
						superblock->insert(*successor);
						visited.insert(*successor);
						next = *successor;
					}
				}
				else
				{
					// seed new superblocks at the exit points
					if(visited.insert(*successor).second)
					{
						superblocks.push_back(*successor);
					}
				}
			}
		}
		
		report("   superblock has " << superblock->instructions()
			<< " instructions");
		
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
		
			report("   basic block has " << normalblock->instructions()
				<< " instructions");
		}
	}
}

}


