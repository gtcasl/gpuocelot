/*! \file   ReadableLayoutPass.cpp
	\author Gregory Diamos <diamos@nvidia.com>
	\date   Wednesday July 11, 2012
	\brief  The source file for the ReadableLayoutPass class.
*/

// Ocelot Includes
#include <ocelot/transforms/interface/ReadableLayoutPass.h>
#include <ocelot/ir/interface/IRKernel.h>

// Hydrazine Includes
#include <hydrazine/interface/debug.h>

// Standard Library Includes
#include <stack>
#include <unordered_set>

// Preprocessor Macros
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

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
	blocks.clear();
	
	typedef ir::ControlFlowGraph::iterator iterator;
	typedef std::unordered_set<iterator>   BlockSet;
	typedef std::stack<iterator>           Stack;
	
	BlockSet visited;
	BlockSet scheduled;
	Stack    stack;
	
	if(!k.cfg()->empty())
	{
		stack.push(k.cfg()->get_entry_block());
		visited.insert(k.cfg()->get_entry_block());
	}
	
	while(!stack.empty())
	{
		iterator current = stack.top();
		stack.pop();
		
		report("  starting at " << current->label);
		
		// Make sure no unscheduled blocks that fallthrough into this one
		bool rewinding = true;
		while(rewinding)
		{
			rewinding = false;
			for(auto edge = current->in_edges.begin(); 
				edge != current->in_edges.end(); ++edge)
			{
				if((*edge)->type == ir::Edge::FallThrough)
				{
					if(scheduled.count((*edge)->head) == 0)
					{
						visited.erase(current);
						current = (*edge)->head;
						report("   rewinding to " << current->label );
						rewinding = true;
					}
					break;
				}
			}
		}
		
		if(scheduled.insert(current).second)
		{
			// Accept the block
			blocks.push_back(current);
			visited.insert(current);
		}
		else
		{
			continue;
		}
		
		// Now queue up successors for exploration
		//  favor the fallthrough
		iterator fallthrough = k.cfg()->end();
		
		if(current->has_fallthrough_edge())
		{
			auto fallthroughEdge = blocks.back()->get_fallthrough_edge();
			
			fallthrough = fallthroughEdge->tail;
			
			assert(scheduled.count(fallthrough) == 0);
			
			visited.insert(fallthrough);
		}
		
		// Explore the remaining targets
		for(auto block = current->successors.begin(); 
			block != current->successors.end(); ++block)
		{
			if(visited.insert(*block).second)
			{
				stack.push(*block);
			}
		}
		
		if(fallthrough != k.cfg()->end())
		{
			stack.push(fallthrough);
		}
	}
}

void ReadableLayoutPass::finalize()
{

}

}


