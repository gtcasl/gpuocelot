/*! \file   SimpleAliasAnalysis.cpp
	\date   Thursday November 8, 2012
	\author Gregory Diamos <gdiamos@nvidia.com>
	\brief  The source file for the SimpleAliasAnalysis class.
*/

// Ocelot Includes
#include <ocelot/analysis/interface/SimpleAliasAnalysis.h>

#include <ocelot/ir/interface/IRKernel.h>
#include <ocelot/ir/interface/ControlFlowGraph.h>

namespace analysis
{

SimpleAliasAnalysis::SimpleAliasAnalysis()
: KernelAnalysis(Analysis::SimpleAliasAnalysis, "SimpleAliasAnalysis")
{

}

void SimpleAliasAnalysis::analyze(ir::IRKernel& kernel)
{
	// Functions can be called
	_aStoreCanReachThisFunction = !kernel.function();
	
	if(_aStoreCanReachThisFunction) return;
	
	for(auto block = kernel.cfg()->begin();
		block != kernel.cfg()->end(); ++block)
	{
		for(auto instruction = block->instructions.begin();
			instruction != block->instructions.end(); ++instruction)
		{
			auto ptx = static_cast<ir::PTXInstruction*>(*instruction);
			
			if(ptx->isStore())
			{
				_aStoreCanReachThisFunction = true;
				return;
			}
		}
	}
}

bool SimpleAliasAnalysis::cannotAliasAnyStore(const ir::Instruction* load)
{
	return !_aStoreCanReachThisFunction;
}

}

