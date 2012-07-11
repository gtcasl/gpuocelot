/*! \file   GlobalValueNumberingPass.cpp
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date   Tuesday July 10, 2012
	\brief  The source file for the GlobalValueNumberingPass class.
*/

// Ocelot Includes
#include <ocelot/transforms/interface/GlobalValueNumberingPass.h>

#include <ocelot/analysis/interface/DataflowGraph.h>

// Standard Library Includes
#include <cassert>

namespace transforms
{


GlobalValueNumberingPass::GlobalValueNumberingPass()
:  KernelPass(Analysis::DataflowGraphAnalysis |
	Analysis::StaticSingleAssignment, "GlobalValueNumberingPass")
{

}

void GlobalValueNumberingPass::initialize(const ir::Module& m)
{

}

void GlobalValueNumberingPass::runOnKernel(ir::IRKernel& k)
{
	// TODO, identify identical values

	// convert out of SSA, this renumbers registers
	auto analysis = getAnalysis(Analysis::DataflowGraphAnalysis);
	assert(analysis != 0);
	
	auto dfg = static_cast<analysis::DataflowGraph*>(analysis);

	assert(dfg->ssa() != analysis::DataflowGraph::None);
	
	dfg->fromSsa();
	
	invalidateAnalysis(Analysis::StaticSingleAssignment);
}

void GlobalValueNumberingPass::finalize()
{

}

}

