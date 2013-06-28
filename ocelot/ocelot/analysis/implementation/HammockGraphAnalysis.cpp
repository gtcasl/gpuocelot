/*! \file   HammockGraphAnalysis.cpp
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date   Friday May 31, 2013
	\brief  The source file for the HammockGraphAnalysis class.
*/

// Ocelot Incudes
#include <ocelot/analysis/interface/HammockGraphAnalysis.h>

#include <ocelot/analysis/interface/PostdominatorTree.h>
#include <ocelot/analysis/interface/DominatorTree.h>

#include <ocelot/ir/interface/IRKernel.h>

// Standard Library Includes
#include <cassert>

namespace analysis
{

typedef HammockGraphAnalysis::Hammock  Hammock;
typedef HammockGraphAnalysis::iterator iterator;

typedef HammockGraphAnalysis::HammockList      HammockList;
typedef HammockGraphAnalysis::hammock_iterator hammock_iterator;

HammockGraphAnalysis::HammockGraphAnalysis()
: KernelAnalysis("HammockGraphAnalysis",
	{"DominatorTreeAnalysis", "PostDominatorTreeAnalysis"})
{

}

static void splitHammock(Hammock& hammock, DominatorTree* dominatorTree,
	PostdominatorTree* postDominatorTree);
	
void HammockGraphAnalysis::analyze(ir::IRKernel& kernel)
{
	_root.entry = kernel.cfg()->get_entry_block();
	_root.exit  = kernel.cfg()->get_exit_block();
	
	// Start with a single hammock containing the entire function
	for(auto block = kernel.cfg()->begin();
		block != kernel.cfg()->end(); ++block)
	{
		if(block == _root.entry) continue;
		if(block == _root.exit)  continue;
	
		_root.children.push_back(Hammock(&_root, block, block));
	}
	
	auto dom = static_cast<DominatorTree*>(
		getAnalysis("DominatorTreeAnalysis"));
	auto pdom = static_cast<PostdominatorTree*>(
		getAnalysis("PostDominatorTreeAnalysis"));
	
	// Recursively split the hammock
	splitHammock(_root, dom, pdom);
}

const Hammock* HammockGraphAnalysis::getHammock(const_iterator block) const
{
	auto hammock = _blockToHammockMap.find(block);

	if(hammock != _blockToHammockMap.end()) return hammock->second;

	return 0;
}

Hammock::Hammock(Hammock* p, iterator e, iterator ex)
: parent(p), entry(e), exit(ex)
{

}

typedef std::unordered_map<iterator, hammock_iterator> BlockToHammockMap;

static iterator getPostDominator(PostdominatorTree* postDominatorTree,
	iterator dominator)
{
	auto postdominator = postDominatorTree->getPostDominator(
			dominator);
			
	// chase through straight-line successors
	while(true)
	{
		if(postdominator->successors.size() != 1) break;

		auto next = postdominator->successors.back();
	
		if(next->predecessors.size() != 1) break;
		
		postdominator = next;
	}
	
	return postdominator;
}

static Hammock createNewHammock(BlockToHammockMap& unvisited,
	hammock_iterator hammock,
	DominatorTree* dominatorTree, PostdominatorTree* postDominatorTree)
{
	// Find the maximal containing hammock
	auto entry = hammock->entry;
	auto exit  = hammock->entry;
	
	while(true)
	{
		auto dominator = dominatorTree->getDominator(entry);
		
		if(dominator == hammock->parent->entry)
		{
			if(entry == hammock->entry)
			{
				return Hammock(hammock->parent, entry, entry);
			}
			
			break;
		}

		auto postdominator = getPostDominator(postDominatorTree, dominator);
		
		if(postdominator == hammock->parent->exit)
		{
			if(entry == hammock->entry)
			{
				return Hammock(hammock->parent, entry, entry);
			}
		
			break;
		}
		
		entry = dominator;
		exit  = postdominator;
	}
	
	// Create the new hammock
	Hammock newHammock(hammock->parent, entry, exit);
	
	// Remove the entry and exit from the parent
	auto entryHammock = unvisited.find(entry);
	assert(entryHammock != unvisited.end());
	
	hammock->parent->children.erase(entryHammock->second);
	unvisited.erase(entryHammock);
	
	auto exitHammock = unvisited.find(exit);
	assert(exitHammock != unvisited.end());
	
	hammock->parent->children.erase(exitHammock->second);
	unvisited.erase(exitHammock);
	
	// Move all contained children into the new hammock
	typedef std::list<hammock_iterator>  HammockIteratorList;
	
	HammockIteratorList unvisitedIterators;
	
	for(auto unvisitedIterator = unvisited.begin();
		unvisitedIterator != unvisited.end(); ++unvisitedIterator)
	{
		unvisitedIterators.push_back(unvisitedIterator->second);
	}
	
	for(auto unvisitedIterator = unvisitedIterators.begin();
		unvisitedIterator != unvisitedIterators.end(); ++unvisitedIterator)
	{
		if(!dominatorTree->dominates(entry, (*unvisitedIterator)->entry))
		{
			continue;
		}
		
		newHammock.children.splice(newHammock.children.end(),
			hammock->parent->children, *unvisitedIterator);
	
		auto oldHammock = unvisited.find((*unvisitedIterator)->entry);
		assert(oldHammock != unvisited.end());
		
		unvisited.erase(oldHammock);
	}
	
	return newHammock;
}

static void splitHammock(Hammock& hammock, DominatorTree* dominatorTree,
	PostdominatorTree* postDominatorTree)
{
	BlockToHammockMap unvisited;
	
	for(auto child = hammock.children.begin();
		child != hammock.children.end(); ++child)
	{
		unvisited.insert(std::make_pair(child->entry, child));
	}
	
	// Attempt to pull out hammocks until there is no change
	bool changed = true;
	
	while(changed)
	{
		changed = false;
	
		// check child blocks
		for(auto child = unvisited.begin(); child != unvisited.end(); ++child)
		{
			auto newHammock = createNewHammock(unvisited, child->second,
				dominatorTree, postDominatorTree);
		
			bool isNewHammockASubset = newHammock.entry != hammock.entry;
			
			if(isNewHammockASubset)
			{
				hammock.children.push_back(newHammock);
				
				splitHammock(newHammock, dominatorTree, postDominatorTree);

				changed = true;
				break;
			}
		}
	}
}


}

