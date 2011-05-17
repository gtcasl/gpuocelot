/*! \file   ThreadFrontierAnalysis.h
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date   Monday May 9, 2011
	\brief  The header file for the ThreadFrontierAnalysis class.

	Note: This analysis is covered by Intel Patents (pending), be very careful
		about commercial reuse.  This module is provided for research use only,
		care was taken such that only the code in this compilation unit is
		covered by the patents.
*/

#ifndef THREAD_FRONTIER_ANALYSIS_H_INCLUDED
#define THREAD_FRONTIER_ANALYSIS_H_INCLUDED

// Ocelot Incudes
#include <ocelot/analysis/interface/Analysis.h>

#include <ocelot/ir/interface/ControlFlowGraph.h>

namespace analysis
{

/*! \brief A class for determining thread frontiers for all basic blocks.

	Thread frontiers defines a scheduling order of threads and identifies
	re-convergence points.  The approach has two main steps:
		1) Assign a priority order to basic blocks.
		2) For each basic block, determine all other possible blocks where
			stalled threads may be waiting.

	The intersection of this set and the current block's successors is the
	thread frontier of that block. The algorithm used here is taken directly
	from [1].
	
	[1] - "SIMD Reconvergence at Thread Frontiers" by Diamos et al. 
*/
class ThreadFrontierAnalysis: public KernelAnalysis
{
public:
	typedef ir::ControlFlowGraph::BlockPointerVector BlockVector;
	typedef ir::ControlFlowGraph::iterator           iterator;
	typedef ir::ControlFlowGraph::const_iterator     const_iterator;
	typedef unsigned int Priority;

public:
	/*! \brief Create the analysis */
	ThreadFrontierAnalysis();

	/*! \brief Computes an up to date set of thread frontiers */
	void analyze(ir::IRKernel& kernel);

public:
	/*! \brief Get the blocks in the thread frontier of a specified block */
	BlockVector getThreadFrontier(const_iterator block) const;
	/*! \brief Get the scheduling priorty of a specified block */
	Priority getPriority(const_iterator block) const;

private:
	void _computePriorities(ir::IRKernel& kernel);
	void _computeFrontiers(ir::IRKernel& kernel);

private:
	typedef std::unordered_map<iterator, Priority>    PriorityMap;
	typedef std::unordered_map<iterator, BlockVector> BlockMap;

private:
	PriorityMap _priorities;
	BlockMap    _frontiers;
	
};

}

#endif

