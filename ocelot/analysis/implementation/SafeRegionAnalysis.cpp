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
: KernelAnalysis(Analysis::SafeRegionAnalysis, "SafeRegionAnalysis",
	Analysis::DominatorTreeAnalysis | Analysis::PostDominatorTreeAnalysis)
{

}

void SafeRegionAnalysis::analyze(ir::IRKernel& kernel)
{
	_regions.clear();
	
	_formRegions(kernel);
	
	_buildBlockToRegionMap(_regionRoot);
}

void SafeRegionAnalysis::_formRegions(ir::IRKernel& kernel)
{
	BlockSet visited;
	BlockSet blocksWithSideEffects;
	
	_findBlocksWithSideEffects(blocksWithSideEffects, kernel);
	
	_formRegionFromSeed(visited, kernel.cfg()->begin(), blocksWithSideEffects);
}

void SafeRegionAnalysis::_findBlocksWithSideEffects(
	BlockSet& blocksWithSideEffects, ir::IRKernel& kernel)
{
	
}

void SafeRegionAnalysis::_formRegionFromSeed(
	BlockSet& visited, iterator block, const BlockSet& blocksWithSideEffects)
{

}

void SafeRegionAnalysis::_buildBlockToRegionMap(Region& region)
{
	if(region.children.empty())
	{
		_regions.insert(std::make_pair(region.block, &region));
		
		return;
	}

	for(auto child = region.children.begin();
		child != region.children.end(); ++child)
	{
		_buildBlockToRegionMap(*child);
	}
}

const SafeRegionAnalysis::Region* SafeRegionAnalysis::getRegion(
	const_iterator block) const
{
	auto region = _regions.find(block);
	assert(region != _regions.end());
	
	return region->second;
}

SafeRegionAnalysis::Region::Region(Region* p, RegionId i)
: parent(p), id(i), doesNotDependOnSideEffects(false)
{

}

}


