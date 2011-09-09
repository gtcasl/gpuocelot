/*! \file   DefaultProgramStructure.cpp
	\author Gregory Diamos <gdiamos@nvidia.com>
	\date   Friday September 9, 2011
	\brief  The source file for the DefaultProgramStructure class.
*/

// Ocelot Includes
#include <ocelot/analysis/interface/DefaultProgramStructure.h>

namespace analysis
{

DefaultProgramStructure::DefaultProgramStructure(ir::ControlFlowGraph& cfg)
{
	iterator entry = newBlock();

	entry->insert(cfg.get_entry_block());
	
	_entry = begin();

	for(ir::ControlFlowGraph::iterator block = cfg.begin();
		block != cfg.end(); ++block)
	{
		if(block == cfg.get_entry_block()) continue;
	
		iterator metaBlock = newBlock();
		
		metaBlock->insert(block);
	}
}

}


