/*! \file   ReadableLayoutPass.cpp
	\author Gregory Diamos <diamos@nvidia.com>
	\date   Wednesday July 11, 2012
	\brief  The source file for the ReadableLayoutPass class.
*/

// Ocelot Includes
#include <ocelot/transforms/interface/ReadableLayoutPass.h>
#include <ocelot/analysis/interface/DominatorTree.h>
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
: KernelPass(Analysis::DominatorTreeAnalysis, "ReadableLayoutPass")
{

}

void ReadableLayoutPass::initialize(const ir::Module& m)
{

}


void ReadableLayoutPass::runOnKernel(ir::IRKernel& k)
{
	blocks.clear();

	typedef ir::ControlFlowGraph::iterator iterator;
	typedef std::list<iterator>            BlockChain;
	typedef std::list<BlockChain>          BlockChainList;
	typedef BlockChainList::iterator       chain_iterator;
	typedef std::unordered_set<iterator>   BlockSet;
	typedef std::unordered_map<iterator,
		chain_iterator> BlockToChainMap;
	
	// Form chains of basic blocks
	BlockChainList  chains;
	BlockToChainMap blockToChains;
	
	for(auto block = k.cfg()->begin(); block != k.cfg()->end(); ++block)
	{
		auto chain = chains.insert(chains.end(), BlockChain(1, block));
		blockToChains.insert(std::make_pair(block, chain));
	}
	
	bool changed = true;
	
	while(changed)
	{
		changed = false;
		
		for(auto chain = blockToChains.begin();
			chain != blockToChains.end(); ++chain)
		{
			auto chainTail = chain->second->back();
			
			if(chainTail->successors.size() != 1) continue;
			
			for(auto successor = chainTail->successors.begin();
				successor != chainTail->successors.end(); ++chainTail)
			{
				if((*successor)->predecessors.size() != 1) continue;
			
				auto successorChain = blockToChains.find(*successor);
				assert(successorChain != blockToChains.end());
				
				auto chainHead = successorChain->second->front();
				
				if(chainHead != *successor) continue;
				
				chain->second->splice(chain->second->end(),
					*successorChain->second);
				
				blockToChains.erase(successorChain);
				
				changed = true;
			}
			
			if(changed) break;
		}
	}
	
	// Topologically schedule the chains
	BlockSet scheduled;
	BlockSet ready;
	
	ready.insert(k.cfg()->get_entry_block());
	
	while(!ready.empty())
	{
		auto node = *ready.begin();
		ready.erase(*ready.begin());

		auto chain = blockToChains.find(node);
		assert(chain != blockToChains.end());
		
		// emit the blocks in the chain, in order
		for(auto block = chain->second->begin();
			block != chain->second->end(); ++block)
		{
			scheduled.insert(*block);
			blocks.push_back(*block);
		}
		
		// free up any dependent blocks
		for(auto block = chain->second->begin();
			block != chain->second->end(); ++block)
		{
			for(auto successor = (*block)->successors.begin();
				successor != (*block)->successors.end(); ++successor)
			{
				// are all dependencies satisfied
				bool allDependenciesSatisfied = true;
				
				for(auto predecessor = (*successor)->predecessors.begin();
					predecessor != (*successor)->predecessors.end();
					++predecessor)
				{
					if(_isCyclicDependency(*predecessor, *successor)) continue;
					
					if(scheduled.count(*predecessor) == 0)
					{
						allDependenciesSatisfied = false;
						break;
					}
				}
				
				if(allDependenciesSatisfied)
				{
					ready.insert(*successor);
				}
			}
		}
	}
}

void ReadableLayoutPass::finalize()
{

}

bool ReadableLayoutPass::_isCyclicDependency(iterator predecessor,
	iterator successor)
{
	auto domAnalysis = getAnalysis(Analysis::DominatorTreeAnalysis);
	assert(domAnalysis != 0);
	
	auto dominatorTree = static_cast<analysis::DominatorTree&>(*domAnalysis);
	
	return dominatorTree.dominates(successor, predecessor);	
}

}


