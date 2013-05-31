/*! \file   SafeRegionAnalysis.h
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date   Friday May 4, 2012
	\brief  The header file for the SafeRegionAnalysis class.
*/

#pragma once

// Ocelot Incudes
#include <ocelot/analysis/interface/Analysis.h>

#include <ocelot/ir/interface/ControlFlowGraph.h>

// Standard Library Includes
#include <list>
#include <unordered_map>
#include <unordered_set>

namespace analysis
{

/*! \brief A class for assigning unique predicate mask variables to
	control flow graph regions.
*/
class SafeRegionAnalysis: public KernelAnalysis
{
public:
	typedef ir::ControlFlowGraph CFG;

	typedef CFG::const_iterator const_iterator;
	typedef CFG::iterator       iterator;

	typedef unsigned int RegionId;

	class Region
	{
	public:
		typedef std::list<Region> RegionList;
	
	public:
		Region(Region* parent = 0, RegionId = 0);
	
	public:
		Region*    parent;
		RegionList children;
		RegionId   id;
		iterator   block; // If this is a leaf node, the block
	
	public:
		bool doesNotDependOnSideEffects;
	};

public:
	/*! \brief Create the analysis */
	SafeRegionAnalysis();

	/*! \brief Computes an up to date set of regions */
	void analyze(ir::IRKernel& kernel);

public:
	/*! \brief Get the region of the specified block */
	const Region* getRegion(const_iterator block) const;
	
private:
	typedef std::unordered_map<const_iterator, Region*> RegionMap;
	typedef std::unordered_set<const_iterator> BlockSet;

private:
	void _formRegions(ir::IRKernel& kernel);
	void _findBlocksWithSideEffects(BlockSet& blocksWithSideEffects,
		ir::IRKernel& kernel);
	void _formRegionFromSeed(BlockSet& visited, iterator block,
		const BlockSet& blocksWithSideEffects);
	
	void _buildBlockToRegionMap(Region& region);

private:
	Region    _regionRoot;
	RegionMap _regions;
	
};

}

