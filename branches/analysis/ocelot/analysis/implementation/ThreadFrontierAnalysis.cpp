/*! \file   ThreadFrontierAnalysis.cpp
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date   Wednesday May 11, 2011
	\brief  The source file for the ThreadFrontierAnalysis class.
*/

#ifndef THREAD_FRONTIER_ANALYSIS_CPP_INCLUDED
#define THREAD_FRONTIER_ANALYSIS_CPP_INCLUDED

// Ocelot Incudes
#include <ocelot/analysis/interface/ThreadFrontierAnalysis.h>

// Hydrazine Includes
#include <hydrazine/implementation/debug.h>

namespace analysis
{

ThreadFrontierAnalysis::ThreadFrontierAnalysis(transforms::PassManager* m)
: KernelAnalysis(Analysis::ThreadFrontierAnalysis, "ThreadFrontierAnalysis",
	Analysis::NoAnalysis, m)
{

}

void ThreadFrontierAnalysis::analyze(ir::IRKernel& kernel)
{
	assertM(false, "Not implemented.");
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

}

#endif

