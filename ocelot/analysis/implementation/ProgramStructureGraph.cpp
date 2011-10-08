/*! \file   ProgramStructureGraph.cpp
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date   Monday August 1, 2011
	\brief  The source file for the ProgramStructureGraph class.
*/

// Ocelot Includes
#include <ocelot/analysis/interface/ProgramStructureGraph.h>
#include <ocelot/ir/interface/Instruction.h>

// Hydrazine Includes
#include <hydrazine/implementation/debug.h>

// Standard Library Includes
#include <unordered_set>
#include <algorithm>

// Preprocessor Macros
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1
#define REPORT_ITERATORS 0

namespace analysis
{

typedef ProgramStructureGraph::Block Block;

Block::block_iterator::block_iterator()
{

}

Block::block_iterator::block_iterator(
	const block_iterator& i)
: _iterator(i._iterator), _block(i._block)
{

}

Block::block_iterator::block_iterator(
	const bb_pointer_iterator& i, const pointer_iterator& b)
: _iterator(i), _block(b)
{

}

Block::block_iterator::reference Block::block_iterator::operator*() const
{
	return **_iterator;
}

Block::block_iterator::pointer Block::block_iterator::operator->() const
{
	return &**_iterator;
}

Block::block_iterator::self& Block::block_iterator::operator++()
{
	while(true)
	{
		if(_iterator != _block->_blocks.end())
		{
			reportE(REPORT_ITERATORS,
				"Advancing from block '" << (*_iterator)->id << "'");
			++_iterator;
			
			if(_iterator == _block->_blocks.end()) break;
			
			if(!(*_iterator)->instructions.empty()) break;
		}
		else
		{
			reportE(REPORT_ITERATORS,
				"Not advancing block iterator, already at the end");
			break;
		}
	}
	
	return *this;
}

Block::block_iterator::self
	Block::block_iterator::operator++(int)
{
	self copy = *this;
	
	++*this;
	
	return copy;
}

Block::block_iterator::self&
	Block::block_iterator::operator--()
{
	while(true)
	{
		if(_iterator != _block->_blocks.begin())
		{
			--_iterator;
			if(!(*_iterator)->instructions.empty())
			{
				break;
			}
		}
		else
		{
			break;
		}
	}
	
	return *this;
}

Block::block_iterator::self
	Block::block_iterator::operator--(int)
{
	self copy = *this;
	
	--*this;
	
	return copy;
}

bool Block::block_iterator::operator==(
	const self& i) const
{
	return i._iterator == _iterator && i._block == _block;
}

bool Block::block_iterator::operator!=(
	const self& i) const
{
	return !(i == *this);
}

bool Block::block_iterator::begin() const
{
	return _iterator == _block->_blocks.begin();
}

bool Block::block_iterator::end() const
{
	return _iterator == _block->_blocks.end();
}

Block::block_iterator::operator pointer_iterator()
{
	return _block;
}

Block::block_iterator::operator bb_pointer_iterator()
{
	return _iterator;
}

Block::const_block_iterator::const_block_iterator()
{

}

Block::const_block_iterator::const_block_iterator(
	const block_iterator& i)
: _iterator(i._iterator), _block(i._block)
{

}

Block::const_block_iterator::const_block_iterator(
	const const_block_iterator& i)
: _iterator(i._iterator), _block(i._block)
{

}

Block::const_block_iterator::const_block_iterator(
	const const_bb_pointer_iterator& i, const const_pointer_iterator& b)
: _iterator(i), _block(b)
{

}

Block::const_block_iterator::reference
	Block::const_block_iterator::operator*() const
{
	return **_iterator;
}

Block::const_block_iterator::pointer
	Block::const_block_iterator::operator->() const
{
	return &**_iterator;
}

Block::const_block_iterator::self&
	Block::const_block_iterator::operator++()
{
	while(true)
	{
		if(_iterator != _block->_blocks.end())
		{
			reportE(REPORT_ITERATORS,
				"Advancing from block '" << (*_iterator)->id << "'");
			++_iterator;
			
			if(_iterator == _block->_blocks.end()) break;
			
			if(!(*_iterator)->instructions.empty()) break;
		}
		else
		{
			reportE(REPORT_ITERATORS,
				"Not advancing block iterator, already at the end");
			break;
		}
	}
		
	return *this;
}

Block::const_block_iterator::self
	Block::const_block_iterator::operator++(int)
{
	self copy = *this;
	
	++*this;
	
	return copy;
}

Block::const_block_iterator::self&
	Block::const_block_iterator::operator--()
{
	while(true)
	{
		if(_iterator != _block->_blocks.begin())
		{
			--_iterator;
			if(!(*_iterator)->instructions.empty())
			{
				break;
			}
		}
		else
		{
			break;
		}
	}
	
	return *this;
}

Block::const_block_iterator::self
	Block::const_block_iterator::operator--(int)
{
	self copy = *this;
	
	--*this;
	
	return copy;
}

bool Block::const_block_iterator::operator==(
	const self& i) const
{
	return i._iterator == _iterator && i._block == _block;
}

bool Block::const_block_iterator::operator!=(
	const self& i) const
{
	return !(i == *this);
}

bool Block::const_block_iterator::begin() const
{
	return _iterator == _block->_blocks.begin();
}

bool Block::const_block_iterator::end() const
{
	return _iterator == _block->_blocks.end();
}

Block::const_block_iterator::operator
	const_pointer_iterator()
{
	return _block;
}

Block::const_block_iterator::operator
	const_bb_pointer_iterator()
{
	return _iterator;
}

Block::iterator::iterator()
{

}

Block::iterator::iterator( const block_iterator& b,
	const instruction_iterator& i)
: _instruction(i), _basicBlock(b)
{

}

Block::iterator::reference Block::iterator::operator*() const
{
	return *_instruction;
}

Block::iterator::pointer Block::iterator::operator->() const
{
	return &*_instruction;
}

Block::iterator::self& Block::iterator::operator++()
{
	if(!_basicBlock.end())
	{
		if(_instruction != _basicBlock->instructions.end())
		{
			reportE(REPORT_ITERATORS, "Advancing from instruction '"
				<< (*_instruction)->toString() << "'");
			
			++_instruction;
		}
	}

	align();
		
	return *this;
}

Block::iterator::self Block::iterator::operator++(int)
{
	self copy = *this;
	
	++*this;
	
	return copy;
}

Block::iterator::self& Block::iterator::operator--()
{
	if(_instruction != _basicBlock->instructions.begin())
	{
		--_instruction;
	}
	else
	{
		--_basicBlock;
		if(_basicBlock->instructions.empty())
		{
			_instruction = _basicBlock->instructions.begin();
		}
		else
		{
			_instruction = --_basicBlock->instructions.end();
		}
	}
	
	return *this;
}

Block::iterator::self Block::iterator::operator--(int)
{
	self copy = *this;
	
	--*this;
	
	return copy;
}

bool Block::iterator::operator==(const self& i) const
{
	bool bothEnd = (i._basicBlock.end() && _basicBlock.end());

	return bothEnd ||
		(i._instruction == _instruction && i._basicBlock == _basicBlock);
}

bool Block::iterator::operator!=(const self& i) const
{
	return !(i == *this);
}

void Block::iterator::align()
{
	if(!_basicBlock.end())
	{
		if(_instruction == _basicBlock->instructions.end())
		{
			++_basicBlock;
		
			if(_basicBlock.end())
			{
				reportE(REPORT_ITERATORS, " hit the end.");
				_instruction = instruction_iterator();
			}
			else
			{
				_instruction = _basicBlock->instructions.begin();
			}
		}
	}
}
		
Block::const_iterator::const_iterator()
{

}

Block::const_iterator::const_iterator(const iterator& i)
: _instruction(i._instruction), _basicBlock(i._basicBlock)
{

}

Block::const_iterator::const_iterator(const const_iterator& i)
: _instruction(i._instruction), _basicBlock(i._basicBlock)
{

}

Block::const_iterator::const_iterator(
	const const_block_iterator& b,
	const const_instruction_iterator& i)
: _instruction(i), _basicBlock(b)
{

}

Block::const_iterator::reference Block::const_iterator::operator*() const
{
	return const_cast<reference>(*_instruction);
}

Block::const_iterator::pointer Block::const_iterator::operator->() const
{
	return const_cast<pointer>(&*_instruction);
}

Block::const_iterator::self& Block::const_iterator::operator++()
{
	if(_instruction != _basicBlock->instructions.end())
	{
		++_instruction;
		
		if(_instruction == _basicBlock->instructions.end())
		{
			++_basicBlock;
			_instruction = _basicBlock->instructions.begin();
		}
	}
	
	return *this;
}

Block::const_iterator::self Block::const_iterator::operator++(int)
{
	self copy = *this;
	
	++*this;
	
	return copy;
}

Block::const_iterator::self& Block::const_iterator::operator--()
{
	if(_instruction != _basicBlock->instructions.begin())
	{
		--_instruction;
	}
	else
	{
		--_basicBlock;
		if(_basicBlock->instructions.empty())
		{
			_instruction = _basicBlock->instructions.begin();
		}
		else
		{
			_instruction = --_basicBlock->instructions.end();
		}
	}
	
	return *this;
}

Block::const_iterator::self Block::const_iterator::operator--(int)
{
	self copy = *this;
	
	--*this;
	
	return copy;
}

bool Block::const_iterator::operator==(const self& i) const
{
	return i._instruction == _instruction && i._basicBlock == _basicBlock;
}

bool Block::const_iterator::operator!=(const self& i) const
{
	return !(*this == i);
}

Block::successor_iterator::successor_iterator()
{
	
}

Block::successor_iterator::successor_iterator(
	const successor_iterator& i)
: _block(i._block), _successor(i._successor)
{

}

Block::successor_iterator::successor_iterator(
	const block_iterator& block, const cfg_pointer_iterator& successor)
: _block(block), _successor(successor)
{
	align();
	
	while(!_block.end() && _successor == _block->successors.end())
	{
		++_block;
		if(!_block.end())
		{
			_successor = _block->successors.begin();
		
			align();
		}
		else
		{
			_successor = cfg_pointer_iterator();
		}
	}
}

Block::successor_iterator::successor_iterator(const block_iterator& block)
: _block(block)
{

}

Block::successor_iterator::reference 
	Block::successor_iterator::operator*() const
{
	return **_successor;
}

Block::successor_iterator::pointer Block::successor_iterator::operator->() const
{
	return &**_successor;
}

Block::successor_iterator::self& Block::successor_iterator::operator++()
{
	++_successor;
	align();
	
	while(!_block.end() && _successor == _block->successors.end())
	{
		++_block;
		if(!_block.end())
		{
			_successor = _block->successors.begin();
		
			align();
		}
		else
		{
			_successor = cfg_pointer_iterator();
		}
	}
	
	return *this;
}

Block::successor_iterator::self Block::successor_iterator::operator++(int)
{
	self copy = *this;
	
	++*this;

	return copy;
}

Block::successor_iterator::self& Block::successor_iterator::operator--()
{
	if(_successor != _block->successors.begin())
	{
		--_successor;
	}
	else
	{
		while(!_block.begin() && _block->successors.empty())
		{
			--_block;
		}
		_successor = --_block->successors.end();
	}
	
	return *this;
}

Block::successor_iterator::self Block::successor_iterator::operator--(int)
{
	self copy = *this;
	
	--*this;
	
	return copy;
}

bool Block::successor_iterator::operator==(const self& i) const
{
	return (i._block.end() && _block.end()) ||
		(i._block == _block && i._successor == _successor);
}

bool Block::successor_iterator::operator!=(const self& i) const
{
	return !(i == *this);
}
		
Block::successor_iterator::operator pointer_iterator()
{
	assert(!_block.end());
	
	pointer_iterator block = _block;
	
	return block->findBlockWithBasicBlock(*_successor);
}
		
void Block::successor_iterator::align()
{
	if(_block.end()) return;
	
	while(_successor != _block->successors.end())
	{
		pointer_iterator block = _block;
	
		if(block->contains(*_successor))
		{
			// skip basic blocks contained within the same block
			report("    skipping successor " << (*_successor)->label);
			++_successor;
		}
		else
		{
			break;
		}
	}
}
				
Block::const_successor_iterator::const_successor_iterator()
{
	
}

Block::const_successor_iterator::const_successor_iterator(
	const const_successor_iterator& i)
: _block(i._block), _successor(i._successor)
{

}

Block::const_successor_iterator::const_successor_iterator(
	const successor_iterator& i)
: _block(i._block), _successor(i._successor)
{
	align();
}

Block::const_successor_iterator::const_successor_iterator(
	const const_block_iterator& block,
	const const_cfg_pointer_iterator& successor)
: _block(block), _successor(successor)
{

}

Block::const_successor_iterator::const_successor_iterator(
	const const_block_iterator& block)
: _block(block)
{

}

Block::const_successor_iterator::reference 
	Block::const_successor_iterator::operator*() const
{
	return **_successor;
}

Block::const_successor_iterator::pointer 
	Block::const_successor_iterator::operator->() const
{
	return &**_successor;
}

Block::const_successor_iterator::self& 
	Block::const_successor_iterator::operator++()
{
	++_successor;
	
	while(!_block.end() && _successor == _block->successors.end())
	{
		++_block;
		_successor = _block->successors.begin();
	}
	
	return *this;
}

Block::const_successor_iterator::self 
	Block::const_successor_iterator::operator++(int)
{
	self copy = *this;
	
	++*this;

	return copy;
}

Block::const_successor_iterator::self& 
	Block::const_successor_iterator::operator--()
{
	if(_successor != _block->successors.begin())
	{
		--_successor;
	}
	else
	{
		while(!_block.begin() && _block->successors.empty())
		{
			--_block;
		}
		_successor = --_block->successors.end();
	}
	
	return *this;
}

Block::const_successor_iterator::self 
	Block::const_successor_iterator::operator--(int)
{
	self copy = *this;
	
	--*this;
	
	return copy;
}

bool Block::const_successor_iterator::operator==(const self& i) const
{
	return (i._block.end() && _block.end()) ||
		(i._block == _block && i._successor == _successor);
}

bool Block::const_successor_iterator::operator!=(const self& i) const
{
	return !(i == *this);
}
		
Block::const_successor_iterator::operator const_pointer_iterator()
{
	return _block;
}
		
Block::const_successor_iterator::operator const_cfg_pointer_iterator()
{
	return _successor;
}
		
void Block::const_successor_iterator::align()
{
	if(_block.end()) return;
	
	while(_successor != _block->successors.end())
	{
		const_pointer_iterator block = _block;
	
		if(block->contains(*_successor))
		{
			// skip basic blocks contained within the same block
			report("    skipping successor " << (*_successor)->label);
			++_successor;
		}
		else
		{
			break;
		}
	}
}


Block::predecessor_iterator::predecessor_iterator()
{

}

Block::predecessor_iterator::predecessor_iterator(
	const predecessor_iterator& i)
: _block(i._block), _predecessor(i._predecessor)
{

}

Block::predecessor_iterator::predecessor_iterator(
	const block_iterator& b, const cfg_pointer_iterator& p)
: _block(b), _predecessor(p)
{
	align();
}

Block::predecessor_iterator::predecessor_iterator(const block_iterator& b)
: _block(b)
{

}

Block::predecessor_iterator::reference 
	Block::predecessor_iterator::operator*() const
{
	return **_predecessor;
}

Block::predecessor_iterator::pointer 
	Block::predecessor_iterator::operator->() const
{
	return &**_predecessor;
}

Block::predecessor_iterator::self& Block::predecessor_iterator::operator++()
{
	++_predecessor;
	align();
	
	while(!_block.end() && _predecessor == _block->predecessors.end())
	{
		++_block;
		if(!_block.end())
		{
			_predecessor = _block->predecessors.begin();
		
			align();
		}
		else
		{
			_predecessor = cfg_pointer_iterator();
		}
	}
	
	return *this;
}

Block::predecessor_iterator::self Block::predecessor_iterator::operator++(int)
{
	self copy = *this;
	
	++*this;
	
	return copy;
}

Block::predecessor_iterator::self& Block::predecessor_iterator::operator--()
{
	if(_predecessor != _block->predecessors.begin())
	{
		--_predecessor;
	}
	else
	{
		while(!_block.begin() && _block->predecessors.empty())
		{
			--_block;
		}
		_predecessor = --_block->predecessors.end();
	}

	return *this;
}

Block::predecessor_iterator::self Block::predecessor_iterator::operator--(int)
{
	self copy = *this;
	
	++*this;
	
	return copy;
}

bool Block::predecessor_iterator::operator==(const self& i) const
{
	return (i._block.end() && _block.end()) ||
		(i._block == _block && i._predecessor == _predecessor);
}

bool Block::predecessor_iterator::operator!=(const self& i) const
{
	return !(i == *this);
}

Block::predecessor_iterator::operator pointer_iterator()
{
	pointer_iterator block = _block;
	
	return block->findBlockWithBasicBlock(*_predecessor);
}

Block::predecessor_iterator::operator block_iterator()
{
	pointer_iterator block = _block;
	
	block = block->findBlockWithBasicBlock(*_predecessor);
	
	for(block_iterator bb = block->block_begin();
		bb != block->block_end(); ++bb)
	{
		bb_pointer_iterator bbPointer = bb;
		
		if(*bbPointer == *_predecessor) return bb;
	}
	
	assertM(false, "Inconsistent program structure graph.");
}

Block::predecessor_iterator::operator cfg_pointer_iterator()
{
	return _predecessor;
}

void Block::predecessor_iterator::align()
{
	if(_block.end()) return;
	
	while(_predecessor != _block->predecessors.end())
	{
		pointer_iterator block = _block;
	
		if(block->contains(*_predecessor))
		{
			// skip basic blocks contained within the same block
			report("    skipping predecessor " << (*_predecessor)->label);
			++_predecessor;
		}
		else
		{
			break;
		}
	}
}

Block::const_predecessor_iterator::const_predecessor_iterator()
{

}

Block::const_predecessor_iterator::const_predecessor_iterator(
	const predecessor_iterator& i)
: _block(i._block), _predecessor(i._predecessor)
{

}

Block::const_predecessor_iterator::const_predecessor_iterator(
	const const_predecessor_iterator& i)
: _block(i._block), _predecessor(i._predecessor)
{

}

Block::const_predecessor_iterator::const_predecessor_iterator(
	const const_block_iterator& b, const const_cfg_pointer_iterator& p)
: _block(b), _predecessor(p)
{
	align();
}

Block::const_predecessor_iterator::const_predecessor_iterator(
	const const_block_iterator& b)
: _block(b)
{

}

Block::const_predecessor_iterator::reference 
	Block::const_predecessor_iterator::operator*() const
{
	return **_predecessor;
}

Block::const_predecessor_iterator::pointer 
	Block::const_predecessor_iterator::operator->() const
{
	return &**_predecessor;
}

Block::const_predecessor_iterator::self& 
	Block::const_predecessor_iterator::operator++()
{
	++_predecessor;
	align();
	
	while(!_block.end() && _predecessor == _block->predecessors.end())
	{
		++_block;
		if(!_block.end())
		{
			_predecessor = _block->predecessors.begin();
		
			align();
		}
		else
		{
			_predecessor = cfg_pointer_iterator();
		}
	}
	
	return *this;
}

Block::const_predecessor_iterator::self 
	Block::const_predecessor_iterator::operator++(int)
{
	self copy = *this;
	
	++*this;
	
	return copy;
}

Block::const_predecessor_iterator::self& 
	Block::const_predecessor_iterator::operator--()
{
	if(_predecessor != _block->predecessors.begin())
	{
		--_predecessor;
	}
	else
	{
		while(!_block.begin() && _block->predecessors.empty())
		{
			--_block;
		}
		_predecessor = --_block->predecessors.end();
	}

	return *this;
}

Block::const_predecessor_iterator::self 
	Block::const_predecessor_iterator::operator--(int)
{
	self copy = *this;
	
	++*this;
	
	return copy;
}

bool Block::const_predecessor_iterator::operator==(const self& i) const
{
	return i._block == _block && i._predecessor == _predecessor;
}

bool Block::const_predecessor_iterator::operator!=(const self& i) const
{
	return !(i == *this);
}
		
Block::const_predecessor_iterator::operator const_pointer_iterator()
{
	const_pointer_iterator block = _block;
	
	return block->findBlockWithBasicBlock(*_predecessor);
}

void Block::const_predecessor_iterator::align()
{
	if(_block.end()) return;
	
	while(_predecessor != _block->predecessors.end())
	{
		const_pointer_iterator block = _block;
	
		if(block->contains(*_predecessor))
		{
			// skip basic blocks contained within the same block
			report("    skipping predecessor " << (*_predecessor)->label);
			++_predecessor;
		}
		else
		{
			break;
		}
	}
}

Block::iterator Block::begin()
{
	iterator it(block_begin(), block_begin()->instructions.begin());

	it.align();
	
	return it;
}

Block::iterator Block::end()
{
	return iterator(block_end(), instruction_iterator());
}

Block::const_iterator Block::begin() const
{
	return const_iterator(block_begin(), block_begin()->instructions.begin());
}

Block::const_iterator Block::end() const
{
	return const_iterator(block_end(), const_instruction_iterator());
}

Block::block_iterator Block::block_begin()
{
	return block_iterator(_blocks.begin(), _this);
}

Block::block_iterator Block::block_end()
{
	return block_iterator(_blocks.end(), _this);
}

Block::const_block_iterator Block::block_begin() const
{
	return const_block_iterator(_blocks.begin(), _this);
}

Block::const_block_iterator Block::block_end() const
{
	return const_block_iterator(_blocks.end(), _this);
}

Block::successor_iterator Block::successors_begin()
{
	return successor_iterator(block_begin(), block_begin()->successors.begin());
}
	
Block::successor_iterator Block::successors_end()
{
	return successor_iterator(block_end());
}

Block::const_successor_iterator Block::successors_begin() const
{
	return const_successor_iterator(block_begin(),
		block_begin()->successors.begin());
}

Block::const_successor_iterator Block::successors_end() const
{
	return const_successor_iterator(block_end());
}

Block::predecessor_iterator Block::predecessors_begin()
{
	return predecessor_iterator(block_begin(),
		block_begin()->predecessors.begin());
}

Block::predecessor_iterator Block::predecessors_end()
{
	return predecessor_iterator(block_end());
}

Block::const_predecessor_iterator Block::predecessors_begin() const
{
	return const_predecessor_iterator(block_begin(),
		block_begin()->predecessors.begin());
}

Block::const_predecessor_iterator Block::predecessors_end() const
{
	return const_predecessor_iterator(block_end());
}

Block::block_iterator Block::insert(ir::ControlFlowGraph::iterator block,
	block_iterator position)
{
	return block_iterator(_blocks.insert(position._iterator, block), _this);
}

Block::block_iterator Block::insert(ir::ControlFlowGraph::iterator block)
{
	return insert(block, block_end());
}

Block::iterator Block::insert(ir::Instruction* instruction, iterator position)
{
	return iterator(position._basicBlock,
		position._basicBlock->instructions.insert(
		position._instruction, instruction));
}

Block::iterator Block::insert(ir::Instruction* instruction)
{
	return insert(instruction, end());
}

bool Block::empty() const
{
	return _blocks.empty();
}

size_t Block::instructions() const
{
	size_t sum = 0;
	
	for(const_block_iterator i = block_begin(); i != block_end(); ++i)
	{
		sum += i->instructions.size();
	}
	
	return sum;
}

size_t Block::basicBlocks() const
{
	return _blocks.size();
}

bool Block::hasFallthroughEdge() const
{
	report("   checking for a fallthrough edge out of "
		<< block_begin()->label);
	
	if(_blocks.empty()) return false;
	
	return _blocks.back()->has_fallthrough_edge();
}

Block::block_iterator Block::getFallthrough()
{
	assert(hasFallthroughEdge());
	
	ir::ControlFlowGraph::edge_iterator fallthrough =
		_blocks.back()->get_fallthrough_edge();
	
	report("   getting the fallthrough edge out of " << block_begin()->label
		<< " which is bb " << fallthrough->tail->label);
	
	block_iterator result = block_end();
	
	for(ProgramStructureGraph::iterator metablock = _graph->begin();
		metablock != _graph->end(); ++metablock)
	{
		if(metablock == _this) continue;
	
		for(block_iterator block = metablock->block_begin();
			block != metablock->block_end(); ++block)
		{
			bb_pointer_iterator bb = block;
		
			if(*bb == fallthrough->tail)
			{
				report("    found tail block "
					<< metablock->block_begin()->label);
				result = block;
				
				break;
			}
		}
		
		if(result != block_end()) break;
	}

	assertM(result != block_end(), "No outgoing fallthrough edge found!");

	assertM(_this != result, "Block " << block_begin()->label
		<< " cannot be its own fallthrough target " << result->label << ".");
	
	return result;
}

bool Block::hasIncommingFallthrough() const
{
	report("   checking for an incomming fallthrough block to "
		<< block_begin()->label);
	
	for(const_predecessor_iterator predecessor = predecessors_begin();
		predecessor != predecessors_end(); ++predecessor)
	{
		if(predecessor->has_fallthrough_edge())
		{
			for(const_block_iterator block = block_begin();
				block != block_end(); ++block)
			{
				const_bb_pointer_iterator bb = block;
			
				if(predecessor->get_fallthrough_edge()->tail == *bb)
				{
					report("    found predecessor " << predecessor->label);
					return true;
				}
			}
		}
	}
	
	return false;
}

Block::block_iterator Block::getIncommingFallthrough()
{
	assert(hasIncommingFallthrough());
	
	report("   getting incomming fallthrough block to "
		<< block_begin()->label);
	
	block_iterator result = block_end();
	
	for(predecessor_iterator predecessor = predecessors_begin();
		predecessor != predecessors_end(); ++predecessor)
	{
		report("    checking predecessor " << predecessor->label);
		if(predecessor->has_fallthrough_edge())
		{
			report("     it has a fallthrough edge, checking to see if "
				"the target is the entry block.");
			for(block_iterator block = block_begin();
				block != block_end(); ++block)
			{
				bb_pointer_iterator bb = block;
			
				if(predecessor->get_fallthrough_edge()->tail == *bb)
				{
					report("      it is");
					result = predecessor;
				
					break;
				}
			}
	
			if(result != block_end()) break;
			
			report("      it is not");
		}
		
	}
	
	assertM(result != block_end(), "No incomming fallthrough edge found!");

	assertM(_this != result,"Block " << block_begin()->label
		<< " cannot be its own incomming fallthrough target "
		<< result->label << ".");
	
	return result;
}

bool Block::contains(const const_cfg_iterator& bb) const
{
	return std::find(_blocks.begin(), _blocks.end(), bb) != _blocks.end();
}

Block::pointer_iterator Block::findBlockWithBasicBlock(
	const const_cfg_iterator& target)
{
	for(ProgramStructureGraph::iterator metablock = _graph->begin();
		metablock != _graph->end(); ++metablock)
	{
		for(block_iterator block = metablock->block_begin();
			block != metablock->block_end(); ++block)
		{
			bb_pointer_iterator bb = block;
		
			if(target == *bb) return block;
		}
	}
	
	return _graph->end();
}

Block::const_pointer_iterator Block::findBlockWithBasicBlock(
	const const_cfg_iterator& target) const
{
	for(ProgramStructureGraph::const_iterator metablock = _graph->begin();
		metablock != _graph->end(); ++metablock)
	{
		for(const_block_iterator block = metablock->block_begin();
			block != metablock->block_end(); ++block)
		{
			const_bb_pointer_iterator bb = block;
		
			if(target == *bb) return block;
		}
	}
	
	return _graph->end();
}

Block::Id Block::id() const
{
	return _id;
}

Block::Block(ProgramStructureGraph* g, Id i)
: _graph(g), _id(i)
{

}

ProgramStructureGraph::ProgramStructureGraph()
: _nextId(0)
{

}

ProgramStructureGraph::iterator ProgramStructureGraph::begin()
{
	return _blocks.begin();
}

ProgramStructureGraph::iterator ProgramStructureGraph::end()
{
	return _blocks.end();
}

ProgramStructureGraph::const_iterator ProgramStructureGraph::begin() const
{
	return _blocks.begin();
}

ProgramStructureGraph::const_iterator ProgramStructureGraph::end() const
{
	return _blocks.end();
}

void ProgramStructureGraph::reorderIntoExecutableSequence()
{
	typedef std::unordered_set<iterator> BlockSet;
	
	BlockPointerVector sequence;
	BlockSet unscheduled;

	for(iterator i = begin(); i != end(); ++i)
	{
		unscheduled.insert(i);
	}

	report("Getting executable sequence.");

	sequence.push_back(_entry);
	unscheduled.erase(_entry);
	report(" added " << _entry->block_begin()->label << " ("
		<< _entry->block_begin()->id << ")");

	while(!unscheduled.empty()) 
	{
		if(sequence.back()->hasFallthroughEdge()) 
		{
			iterator fallthrough = sequence.back()->getFallthrough();
			report("  fallthrough of " << sequence.back()->block_begin()->label
				<< " is " << fallthrough->block_begin()->label);
			sequence.push_back(fallthrough);
			unscheduled.erase(fallthrough);
		}
		else 
		{
			// find a new block, favor branch targets over random blocks
			iterator next = *unscheduled.begin();
			
			for(Block::successor_iterator successor =
				sequence.back()->successors_begin();
				successor != sequence.back()->successors_end(); ++successor)
			{
				iterator successorBlock = successor;
				
				report("  checking successor of "
					<< sequence.back()->block_begin()->label
					<< ", " << successor->label);
				
				if(unscheduled.count(successorBlock) != 0)
				{
					next = successorBlock;
				}
			}
			
			// rewind through fallthrough edges to find the beginning of the 
			// next chain of fall throughs
			report("  restarting at " << next->block_begin()->label);
			bool rewinding = true;
			while (rewinding)
			{
				rewinding = false;
				if(next->hasIncommingFallthrough())
				{
					iterator incomming = next->getIncommingFallthrough();
					if(unscheduled.count(incomming) == 0) break;
					
					next = incomming;
					rewinding = true;
					report("   rewinding to " << next->block_begin()->label);
				}
			}
			
			sequence.push_back(next);
			unscheduled.erase(next);
		}
		
		report(" added " << sequence.back()->block_begin()->label << " ("
			<< sequence.back()->block_begin()->id << ")");
	}

	report("finished generating executale sequence");

	for(BlockPointerVector::reverse_iterator blockPointer = sequence.rbegin();
		blockPointer != sequence.rend(); ++blockPointer)
	{
		_blocks.splice(_blocks.begin(), _blocks, *blockPointer);
	}
	
	_entry = _blocks.begin();
}

size_t ProgramStructureGraph::size() const
{
	return _blocks.size();
}

bool ProgramStructureGraph::empty() const
{
	return _blocks.empty();
}

ProgramStructureGraph::iterator ProgramStructureGraph::newBlock()
{
	iterator block = _blocks.insert(_blocks.end(), Block(this, ++_nextId));
	block->_this = block;
	
	return block;
}

}


