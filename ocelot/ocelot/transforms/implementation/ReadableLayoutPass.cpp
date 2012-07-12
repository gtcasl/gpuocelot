/*! \file   ReadableLayoutPass.cpp
	\author Gregory Diamos <diamos@nvidia.com>
	\date   Wednesday July 11, 2012
	\brief  The source file for the ReadableLayoutPass class.
*/

// Ocelot Includes
#include <ocelot/transforms/interface/ReadableLayoutPass.h>
#include <ocelot/ir/interface/IRKernel.h>

namespace transforms
{

ReadableLayoutPass::ReadableLayoutPass()
: KernelPass(Analysis::NoAnalysis, "ReadableLayoutPass")
{

}

void ReadableLayoutPass::initialize(const ir::Module& m)
{

}

void ReadableLayoutPass::runOnKernel(ir::IRKernel& k)
{
	blocks = k.cfg()->pre_order_sequence();
}

void ReadableLayoutPass::finalize()
{

}

}


