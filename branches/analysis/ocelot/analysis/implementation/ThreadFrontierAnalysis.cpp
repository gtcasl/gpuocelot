/*! \file   ThreadFrontierAnalysis.cpp
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date   Wednesday May 11, 2011
	\brief  The source file for the ThreadFrontierAnalysis class.
*/

#ifndef THREAD_FRONTIER_ANALYSIS_CPP_INCLUDED
#define THREAD_FRONTIER_ANALYSIS_CPP_INCLUDED

// Ocelot Incudes
#include <ocelot/analysis/interface/ThreadFrontierAnalysis.h>
#include <ocelot/analysis/interface/StructuralAnalysis.h>

// Hydrazine Includes
#include <hydrazine/implementation/debug.h>

// Standard Library Includes
#include <stack>
#include <unordered_set>
#include <set>

// Preprocessor Macros
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1

namespace analysis
{

ThreadFrontierAnalysis::ThreadFrontierAnalysis()
: KernelAnalysis(Analysis::ThreadFrontierAnalysis, "ThreadFrontierAnalysis",
	Analysis::StructuralAnalysis)
{

}

void ThreadFrontierAnalysis::analyze(ir::IRKernel& kernel)
{
	_computePriorities(kernel);
	_computeFrontiers(kernel);
}

ThreadFrontierAnalysis::BlockVector ThreadFrontierAnalysis::getThreadFrontier(
	const_iterator block) const
{
	BlockMap::const_iterator frontier = _frontiers.find(block);
	assert(frontier != _frontiers.end());

	return frontier->second;
}

ThreadFrontierAnalysis::Priority ThreadFrontierAnalysis::getPriority(
	const_iterator block) const
{
	PriorityMap::const_iterator priority = _priorities.find(block);
	assert(priority != _priorities.end());

	return priority->second;
}

void ThreadFrontierAnalysis::_computePriorities(ir::IRKernel& kernel)
{
	typedef std::stack<StructuralAnalysis::Node*>  NodeStack;
	typedef std::unordered_set<ir::BasicBlock::Id> BlockSet;
	typedef std::set<StructuralAnalysis::Node*>    NodeSet;

	report("Setting basic block priorities.");
	
	Analysis* analysis = getAnalysis(Analysis::StructuralAnalysis);
	assert(analysis != 0);
	
	analysis::StructuralAnalysis* structuralAnalysis
		= static_cast<analysis::StructuralAnalysis*>(analysis);

	NodeStack nextNode;
	NodeSet   visited;

	nextNode.push(*structuralAnalysis->Net.begin());
	visited.insert(nextNode.top());

	// do a depth first traversal of the control tree, set priorities
	Priority priority = kernel.cfg()->size();
	while(!nextNode.empty())
	{
		StructuralAnalysis::Node* node = nextNode.top();
		nextNode.pop();

		if(!node->isCombined)
		{
			report(" setting block " << node->BB->label
				<< " priority to " << priority);
	
			assert(priority != 0);
			_priorities.insert(std::make_pair(node->BB, priority--));
		}
	
		for(NodeSet::const_iterator child = node->childNode.begin();
			child != node->childNode.end(); ++child)
		{
			if(visited.insert(*child).second)
			{
				nextNode.push(*child);
			}
		}
	}

}

void ThreadFrontierAnalysis::_computeFrontiers(ir::IRKernel& kernel)
{
	typedef std::map<Priority, const_iterator,
		std::greater<Priority>> ReversePriorityMap;
	typedef std::unordered_set<const_iterator> BlockSet;

	ReversePriorityMap priorityToBlocks;

	report("Computing basic block thread frontiers.");
	
	// sort by priority (high to low)
	for(PriorityMap::iterator priority = _priorities.begin();
		priority != _priorities.end(); ++priority)
	{
		priorityToBlocks.insert(std::make_pair(priority->second,
			priority->first));
	}
	
	BlockSet outstandingWarps;
	
	// walk the list in priority order, track possibly divergent warps
	for(ReversePriorityMap::const_iterator
		priorityAndBlock = priorityToBlocks.begin();
		priorityAndBlock != priorityToBlocks.end(); ++priorityAndBlock)
	{
		const_iterator block = priorityAndBlock->second;

		// this block can no longer have a divergent warp
		outstandingWarps.erase(block);
		
		report(" " << block->label);
		
		BlockVector frontier;
		
		for(BlockSet::const_iterator b = outstandingWarps.begin();
			b != outstandingWarps.end(); ++b)
		{
			report("  " << (*b)->label);
			frontier.push_back(*b);	
		}
		
		_frontiers.insert(std::make_pair(block, frontier));
		
		// add block successors if they have not already been scheduled
		for(ir::BasicBlock::BlockPointerVector::const_iterator
			successor = block->successors.begin();
			successor != block->successors.end(); ++successor)
		{
			if(getPriority(*successor) < priorityAndBlock->first)
			{
				outstandingWarps.insert(*successor);
			}
		}
	}
}

}

#endif

