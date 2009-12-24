/*! \file BasicBlock.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief implementation of BasicBlock class
	\date 30 September 2008
*/

#include <ocelot/ir/interface/BasicBlock.h>
#include <ocelot/ir/interface/Edge.h>
#include <hydrazine/implementation/debug.h>

ir::BasicBlock::BasicBlock() {

}

ir::BasicBlock::~BasicBlock() {

}

ir::BasicBlock::ConstBlockList ir::BasicBlock::get_successors() const {
	using namespace std;
	using namespace ir;

	ConstBlockList blocks;
	BlockList::const_iterator it = successors.begin();
	for (; it != successors.end(); ++it) {
		blocks.push_back(*it);
	}

	return std::move( blocks );
}

ir::BasicBlock::ConstBlockList ir::BasicBlock::get_predecessors() const {
	using namespace ir;
	using namespace std;

	ConstBlockList blocks;
	BlockList::const_iterator it = predecessors.begin();
	for (; it != predecessors.end(); ++it) {
		blocks.push_back(*it);
	}

	return std::move( blocks );
}

ir::BasicBlock::ConstEdgeList ir::BasicBlock::get_in_edges() const {
	using namespace std;
	using namespace ir;

	ConstEdgeList edges;
	EdgeList::const_iterator it = in_edges.begin();
	for (; it != in_edges.end(); ++it) {
		edges.push_back(*it);
	}

	return std::move( edges );
}

ir::BasicBlock::ConstEdgeList ir::BasicBlock::get_out_edges() const {
	using namespace std;
	using namespace ir;

	ConstEdgeList edges;
	EdgeList::const_iterator it = out_edges.begin();
	for (; it != out_edges.end(); ++it) {
		edges.push_back(*it);
	}

	return std::move( edges );
}

ir::BasicBlock::BlockList ir::BasicBlock::get_successors() {
	using namespace std;
	using namespace ir;

	BlockList blocks;
	BlockList::const_iterator it = successors.begin();
	for (; it != successors.end(); ++it) {
		blocks.push_back(*it);
	}

	return std::move( blocks );
}

ir::BasicBlock::BlockList ir::BasicBlock::get_predecessors() {
	using namespace ir;
	using namespace std;

	BlockList blocks;
	BlockList::const_iterator it = predecessors.begin();
	for (; it != predecessors.end(); ++it) {
		blocks.push_back(*it);
	}

	return std::move( blocks );
}

ir::BasicBlock::EdgeList ir::BasicBlock::get_in_edges() {
	using namespace std;
	using namespace ir;

	EdgeList edges;
	EdgeList::const_iterator it = in_edges.begin();
	for (; it != in_edges.end(); ++it) {
		edges.push_back(*it);
	}

	return std::move( edges );
}

ir::BasicBlock::EdgeList ir::BasicBlock::get_out_edges() {
	using namespace std;
	using namespace ir;

	EdgeList edges;
	EdgeList::const_iterator it = out_edges.begin();
	for (; it != out_edges.end(); ++it) {
		edges.push_back(*it);
	}

	return std::move( edges );
}

ir::Edge* ir::BasicBlock::get_fallthrough_edge() {
	EdgeList::iterator it = out_edges.begin();
	for (; it != out_edges.end(); ++it) {
		if ((*it)->type == ir::Edge::FallThrough) {
			return *it;
		}
	}
	assertM( false, "Block " << label << " contains no fallthrough edge." );
}

const ir::Edge* ir::BasicBlock::get_fallthrough_edge() const {
	EdgeList::const_iterator it = out_edges.begin();
	for (; it != out_edges.end(); ++it) {
		if ((*it)->type == ir::Edge::FallThrough) {
			return *it;
		}
	}
	assertM( false, "Block " << label << " contains no fallthrough edge." );
}

ir::Edge* ir::BasicBlock::get_edge(BasicBlock* b) {
	EdgeList::iterator it = out_edges.begin();
	for (; it != out_edges.end(); ++it) {
		if ((*it)->tail == b) {
			return *it;
		}
	}
	assertM( false, "Block " << label 
		<< " is not connected to block " << b->label );
}

const ir::Edge* ir::BasicBlock::get_edge(BasicBlock* b) const {
	EdgeList::const_iterator it = out_edges.begin();
	for (; it != out_edges.end(); ++it) {
		if ((*it)->tail == b) {
			return *it;
		}
	}
	assertM( false, "Block " << label 
		<< " is not connected to block " << b->label );
}

