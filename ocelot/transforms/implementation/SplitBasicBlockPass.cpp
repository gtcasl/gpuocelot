/*! \brief  SplitBasicBlockPass.cpp
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date   Friday August 12, 2011
	\brief  The source file for the SplitBasicBlockPass class.
*/

// Ocelot Includes
#include <ocelot/transforms/interface/SplitBasicBlockPass.h>

#include <ocelot/ir/interface/ControlFlowGraph.h>
#include <ocelot/ir/interface/IRKernel.h>

// Standard Library Includes
#include <cassert>

namespace transforms
{

SplitBasicBlockPass::SplitBasicBlockPass(unsigned int m)
: KernelPass(Analysis::NoAnalysis, "SplitBasicBlockPass"), _maxSize(m)
{
	assert(_maxSize > 0);
}

void splitBlock(ir::ControlFlowGraph& cfg,
	ir::ControlFlowGraph::iterator block, unsigned int maxSize)
{
	unsigned int count = 0;
	
	std::string label = block->label;
	
	while(block->instructions.size() > maxSize)
	{
		std::stringstream stream;
		
		stream << label << "_" << count++;
	
		block = cfg.split_block(block, maxSize - 1, ir::Edge::FallThrough,
			stream.str());
	}
}

void SplitBasicBlockPass::initialize(const ir::Module& m)
{

}

void SplitBasicBlockPass::runOnKernel(ir::IRKernel& k)
{
	for(ir::ControlFlowGraph::iterator block = k.cfg()->begin();
		block != k.cfg()->end(); ++block)
	{
		splitBlock(*k.cfg(), block, _maxSize);
	}
}

void SplitBasicBlockPass::finalize()
{

}

}

