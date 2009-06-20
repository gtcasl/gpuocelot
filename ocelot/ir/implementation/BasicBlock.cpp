/*!
	\file BasicBlock.cpp

	\author Andrew Kerr <arkerr@gatech.edu>

	\brief implementation of BasicBlock class

	\date 30 September 2008
*/

#include <ocelot/ir/interface/BasicBlock.h>

ir::BasicBlock::BasicBlock() {

}

ir::BasicBlock::~BasicBlock() {
	instructions.clear();
}

std::list< const ir::BasicBlock * > ir::BasicBlock::get_successors() const {
	using namespace std;
	using namespace ir;

	list< const BasicBlock *> blocks;
	list< BasicBlock *>::const_iterator it = successors.begin();
	for (; it != successors.end(); ++it) {
		blocks.push_back(*it);
	}

	return blocks;
}

std::list< const ir::BasicBlock *> ir::BasicBlock::get_predecessors() const {
	using namespace ir;
	using namespace std;

	list< const BasicBlock *> blocks;
	list< BasicBlock *>::const_iterator it = predecessors.begin();
	for (; it != predecessors.end(); ++it) {
		blocks.push_back(*it);
	}

	return blocks;
}

std::list< const ir::Edge *> ir::BasicBlock::get_in_edges() const {
	using namespace std;
	using namespace ir;

	list< const Edge *> edges;
	list< Edge *>::const_iterator it = in_edges.begin();
	for (; it != in_edges.end(); ++it) {
		edges.push_back(*it);
	}

	return edges;
}

std::list< const ir::Edge *> ir::BasicBlock::get_out_edges() const {
	using namespace std;
	using namespace ir;

	list< const Edge *> edges;
	list< Edge *>::const_iterator it = out_edges.begin();
	for (; it != out_edges.end(); ++it) {
		edges.push_back(*it);
	}

	return edges;
}

std::list< ir::BasicBlock * > ir::BasicBlock::get_successors() {
	using namespace std;
	using namespace ir;

	list< BasicBlock *> blocks;
	list< BasicBlock *>::const_iterator it = successors.begin();
	for (; it != successors.end(); ++it) {
		blocks.push_back(*it);
	}

	return blocks;
}

std::list< ir::BasicBlock *> ir::BasicBlock::get_predecessors() {
	using namespace ir;
	using namespace std;

	list< BasicBlock *> blocks;
	list< BasicBlock *>::const_iterator it = predecessors.begin();
	for (; it != predecessors.end(); ++it) {
		blocks.push_back(*it);
	}

	return blocks;
}

std::list< ir::Edge *> ir::BasicBlock::get_in_edges() {
	using namespace std;
	using namespace ir;

	list< Edge *> edges;
	list< Edge *>::const_iterator it = in_edges.begin();
	for (; it != in_edges.end(); ++it) {
		edges.push_back(*it);
	}

	return edges;
}

std::list< ir::Edge *> ir::BasicBlock::get_out_edges() {
	using namespace std;
	using namespace ir;

	list< Edge *> edges;
	list< Edge *>::const_iterator it = out_edges.begin();
	for (; it != out_edges.end(); ++it) {
		edges.push_back(*it);
	}

	return edges;
}




