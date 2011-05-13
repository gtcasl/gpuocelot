/*! \file IntraThreadCoalescingPass.cpp
 *  \author Rodrigo Dominguez <rdomingu@ece.neu.edu>
 *  \date March 24, 2010
 *  \brief The source file for the IntraThreadCoalescingPass class.
 */

// Ocelot includes
#include <ocelot/transforms/interface/IntraThreadCoalescingPass.h>

#include <ocelot/ir/interface/PTXKernel.h>

// Hydrazine includes
#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace transforms
{
	void IntraThreadCoalescingPass::initialize(const ir::Module& m)
	{
	}

	void IntraThreadCoalescingPass::_runOnBlock(
		analysis::DataflowGraph::iterator block)
	{
	}

	void IntraThreadCoalescingPass::runOnKernel(ir::IRKernel& k)
	{
		report("Running IntraThreadCoalescingPass on " << k.name);

		assertM( k.ISA == ir::Instruction::PTX, 
			"This pass is valid for PTX kernels only." );
		_kernel = static_cast< ir::PTXKernel* >( &k );
		
		Analysis* dfg_structure = getAnalysis(Analysis::DataflowGraphAnalysis);
		assert(dfg_structure != 0);
	
		analysis::DataflowGraph* dfg
			= static_cast<analysis::DataflowGraph*>(dfg_structure);

		dfg->compute();
		
		for(analysis::DataflowGraph::iterator block = dfg->begin(); 
			block != dfg->end(); ++block)
		{
			_runOnBlock( block );
		}
	}

	void IntraThreadCoalescingPass::finalize()
	{
	}
}

