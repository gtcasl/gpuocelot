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

#define REPORT_BASE 0

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

typedef std::unordered_set<ir::BasicBlock::Id> BlockSet;
typedef std::unordered_map<ir::BasicBlock::Id,
	ir::ControlFlowGraph::const_iterator> BlockIdMap;
	
static void addFallthroughs(ThreadFrontierAnalysis::PriorityMap& priorities,
	ThreadFrontierAnalysis::Priority& priority,
	BlockSet& visitedBlocks, ir::ControlFlowGraph::const_iterator block,
	BlockIdMap& unstructuredBranches);
	
static void addUnstructuredGraph(
	ThreadFrontierAnalysis::PriorityMap& priorities,
	ThreadFrontierAnalysis::Priority& priority,
	BlockSet& visitedBlocks, ir::ControlFlowGraph::const_iterator block,
	BlockIdMap& unstructuredBranches)
{
	// can this block reach another via an unstructured branch?
	BlockIdMap::const_iterator unstructuredBranch =
		unstructuredBranches.find(block->id);
	if(unstructuredBranch != unstructuredBranches.end())
	{
		block = unstructuredBranch->second;
		
		if(visitedBlocks.count(block->id) == 1) return;
		
		// are all predecessors scheduled?
		for(ir::BasicBlock::BlockPointerVector::const_iterator predecessor =
			block->predecessors.begin(); predecessor !=
			block->predecessors.end(); ++predecessor)
		{
			if(visitedBlocks.count((*predecessor)->id) == 0)
			{
				return;
			}
		}
		
		report("  block " << block->label << " is (unstructured)");
		
		unstructuredBranches.erase(unstructuredBranch);
		addFallthroughs(priorities, priority, visitedBlocks, block,
			unstructuredBranches);
	}
}

static unsigned int rewind(ir::ControlFlowGraph::const_iterator& block)
{
	// rewind back to the start of the fallthrough chain
	bool rewind = true;
	
	unsigned int count = 1;
	
	while(rewind)
	{
		rewind = false;
		for(ir::BasicBlock::BlockPointerVector::const_iterator predecessor =
			block->predecessors.begin(); predecessor !=
			block->predecessors.end(); ++predecessor)
		{
			if((*predecessor)->has_fallthrough_edge())
			{
				if((*predecessor)->get_fallthrough_edge()->tail->id
					== block->id)
				{
					block = *predecessor;
					rewind = true;
					++count;
					break;
				}
			}
		}
	}
	
	return count;
}

static void addFallthroughs(
	ThreadFrontierAnalysis::PriorityMap& priorities,
	ThreadFrontierAnalysis::Priority& priority,
	BlockSet& visitedBlocks, ir::ControlFlowGraph::const_iterator block,
	BlockIdMap& unstructuredBranches)
{
	ThreadFrontierAnalysis::BlockVector found;

	rewind(block);
	
	report("   setting block " << block->label
			<< " priority to " << priority);
	priorities.insert(std::make_pair(block, priority--));
	assert(visitedBlocks.count(block->id) == 0);
	visitedBlocks.insert(block->id);
	found.push_back(block);
	
	// set chains of fallthrough blocks at once
	while(block->has_fallthrough_edge())
	{
		block = block->get_fallthrough_edge()->tail;
		report("   setting block " << block->label
			<< " priority to " << priority << " (fallthrough)");
		priorities.insert(std::make_pair(block, priority--));
		assert(visitedBlocks.count(block->id) == 0);
		visitedBlocks.insert(block->id);
		found.push_back(block);
	}

	// Check for unstructured branches that can reach other blocks
	for(ThreadFrontierAnalysis::BlockVector::const_iterator block =
		found.begin(); block != found.end(); ++block)
	{
		addUnstructuredGraph(priorities, priority, visitedBlocks, *block,
			unstructuredBranches);
	}
}

static void addExitChain(
	ThreadFrontierAnalysis::PriorityMap& priorities,
	BlockSet& visitedBlocks, ir::ControlFlowGraph::const_iterator block)
{
	unsigned int chainLength = rewind(block);
	
	report(" Assigning exit nodes.");
	
	// set chains of fallthrough blocks at the same time
	for(unsigned int i = 0; i < chainLength; ++i)
	{
		if(i != 0) block = block->get_fallthrough_edge()->tail;
		report("  setting block " << block->label
			<< " priority to " << (chainLength - i) << " (exit)");
		priorities.insert(std::make_pair(block, chainLength - i));
		assert(visitedBlocks.count(block->id) == 0);
		visitedBlocks.insert(block->id);
	}
}

static void depthFirstTraversal(ThreadFrontierAnalysis::PriorityMap& priorities,
	ThreadFrontierAnalysis::Priority& priority,
	BlockSet& visitedBlocks, StructuralAnalysis::Node* entryNode,
	BlockIdMap& unstructuredBranches)
{
	typedef std::stack<StructuralAnalysis::Node*> NodeStack;
	typedef std::set<StructuralAnalysis::Node*>   NodeSet;

	NodeStack  nextNode;
	NodeSet    visited;

	nextNode.push(entryNode);
	visited.insert(nextNode.top());

	while(!nextNode.empty())
	{
		StructuralAnalysis::Node* node = nextNode.top();
		nextNode.pop();

		if(!node->isCombined)
		{
			if(visitedBlocks.count(node->BB->id) == 0)
			{		
				report("  block " << node->BB->label << " is (structured)");
				
				addFallthroughs(priorities, priority, visitedBlocks, node->BB,
					unstructuredBranches);
				addUnstructuredGraph(priorities, priority,
					visitedBlocks, node->BB, unstructuredBranches);
			}
		}
		else
		{
			// Make sure the entry is visited first
			bool insertEntry = visited.insert(node->entryNode).second;
			
			for(NodeSet::const_iterator child = node->childNode.begin();
				child != node->childNode.end(); ++child)
			{
				if(visited.insert(*child).second)
				{
					nextNode.push(*child);
				}
			}

			if(insertEntry)
			{
				nextNode.push(node->entryNode);
			}
		}
	}
}


void ThreadFrontierAnalysis::_computePriorities(ir::IRKernel& kernel)
{
	report("Setting basic block priorities.");
	
	Analysis* analysis = getAnalysis(Analysis::StructuralAnalysis);
	assert(analysis != 0);
	
	analysis::StructuralAnalysis* structuralAnalysis
		= static_cast<analysis::StructuralAnalysis*>(analysis);

	#if (REPORT_BASE != 0)
	structuralAnalysis->write(std::cout);
	#endif

	BlockSet   visitedBlocks;
	BlockIdMap unstructuredBranches;
	
	// create a set of blocks that are reachable from unstructured branches
	for(analysis::StructuralAnalysis::EdgeVecTy::const_iterator edge =
		structuralAnalysis->unstructuredBRVec.begin(); edge !=
		structuralAnalysis->unstructuredBRVec.end(); ++edge)
	{
		unstructuredBranches.insert(std::make_pair(edge->first->id,
			edge->second));
	}

	Priority priority = kernel.cfg()->size();

	// Add the exit chain first	
	addExitChain(_priorities, visitedBlocks,
		kernel.cfg()->get_exit_block());
	
	// do a depth first traversal of the control tree, set priorities
	report(" Traversing the control tree.");
	assert(!structuralAnalysis->Net.empty());
	
	depthFirstTraversal(_priorities, priority, visitedBlocks,
		*structuralAnalysis->Net.begin(), unstructuredBranches);
	
	// assign any remaining unstructured blocks
	report(" Adding unstructured blocks.");
	if(visitedBlocks.size() != kernel.cfg()->size())
	{
		for(BlockIdMap::const_iterator unstructuredBranch =
			unstructuredBranches.begin(); 
			unstructuredBranch != unstructuredBranches.end();
			++unstructuredBranch)
		{
			ir::ControlFlowGraph::const_iterator block =
				unstructuredBranch->second;
			if(visitedBlocks.count(block->id) == 0)
			{
				report("  block " << block->label << " is (unstructured)");
				
				addFallthroughs(_priorities, priority, visitedBlocks, block,
					unstructuredBranches);
			}
		}
	}
	
	// assign any unreachable blocks
	if(!structuralAnalysis->unreachableNodeSet.empty())
	{
		depthFirstTraversal(_priorities, priority, visitedBlocks,
			*structuralAnalysis->unreachableNodeSet.begin(),
			unstructuredBranches);
	}
	
	assert(visitedBlocks.size() == kernel.cfg()->size());
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

