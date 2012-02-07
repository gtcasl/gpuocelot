/*! \file   DefaultProgramStructure.cpp
	\author Gregory Diamos <gdiamos@nvidia.com>
	\date   Friday September 9, 2011
	\brief  The source file for the DefaultProgramStructure class.
*/

// Ocelot Includes
#include <ocelot/analysis/interface/DefaultProgramStructure.h>
#include <ocelot/ir/interface/IRKernel.h>

// Hydrazine Includes
#include <hydrazine/implementation/debug.h>

// Preprocessor Macros
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace analysis
{

DefaultProgramStructure::DefaultProgramStructure()
{

}

void DefaultProgramStructure::analyze(ir::IRKernel& kernel)
{
	ir::ControlFlowGraph& cfg = *kernel.cfg();

	iterator entry = newBlock();

	entry->insert(cfg.get_entry_block());
	
	_entry = begin();

	for(ir::ControlFlowGraph::iterator block = cfg.begin();
		block != cfg.end(); ++block)
	{
		if(block == cfg.get_entry_block()) continue;
	
		iterator metaBlock = newBlock();
		
		metaBlock->insert(block);
		
		report("   basic block has " << metaBlock->instructions()
			<< " instructions");
	}
}

}


