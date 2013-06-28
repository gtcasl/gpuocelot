/*! \file   MIMDThreadSchedulingPass.cpp
	\date   Friday February 18, 2011
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief  The source file for the MIMDThreadSchedulingPass class.
*/

// Ocelot Includes
#include <ocelot/transforms/interface/MIMDThreadSchedulingPass.h>

#include <ocelot/ir/interface/PTXKernel.h>

#include <ocelot/analysis/interface/DominatorTree.h>
#include <ocelot/analysis/interface/PostdominatorTree.h>
#include <ocelot/analysis/interface/DataflowGraph.h>

// Preprocessor Macros
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1

namespace transforms
{

MIMDThreadSchedulingPass::MIMDThreadSchedulingPass()
	: KernelPass({"DataflowGraphAnalysis", "PostDominatorTreeAnalysis",
		"DominatorTreeAnalysis"}, 
		"MIMDThreadSchedulingPass")
{

}

void MIMDThreadSchedulingPass::runOnKernel(ir::IRKernel& k)
{
	
}

}


