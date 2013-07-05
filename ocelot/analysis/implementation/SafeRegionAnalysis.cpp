/*! \file   SafeRegionAnalysis.cpp
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date   Friday May 4, 2012
	\brief  The source file for the SafeRegionAnalysis class.
*/

// Ocelot Incudes
#include <ocelot/analysis/interface/SafeRegionAnalysis.h>

#include <ocelot/ir/interface/IRKernel.h>

// Standard Library Includes
#include <cassert>

namespace analysis
{

SafeRegionAnalysis::SafeRegionAnalysis()
: KernelAnalysis("SafeRegionAnalysis",
	{"DominatorTreeAnalysis", "PostDominatorTreeAnalysis", "CycleAnalysis"})
{

}

void SafeRegionAnalysis::analyze(ir::IRKernel& kernel)
{

}

const SafeRegionAnalysis::SafeRegion* SafeRegionAnalysis::getRegion(
	const_iterator block) const
{
	auto region = _regions.find(block);
	assert(region != _regions.end());
	
	return region->second;
}

SafeRegionAnalysis::SafeRegion::SafeRegion(SafeRegion* p)
: parent(p), doesNotDependOnSideEffects(false)
{

}

}


