/*!
	\file DataflowGraph.cpp
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Tuesday June 23, 2009
	\file The source file for the DataflowGraph class.
*/

#ifndef DATAFLOW_GRAPH_CPP_INCLUDED
#define DATAFLOW_GRAPH_CPP_INCLUDED

#include <analysis/interface/DataflowGraph.h>

namespace analysis
{

	DataflowGraph::Block::Block( Type type ) : _fallthrough( 0 ), _target( 0 ), 
		_type( type )
	{
		
	}
	
	DataflowGraph::Block::Block() : _fallthrough( 0 ), _target( 0 ), 
		_type( Invalid )
	{
		
	}
	
	const DataflowGraph::RegisterIdSet& 
		DataflowGraph::Block::aliveIn() const
	{
		return _aliveIn;
	}
	
	const DataflowGraph::RegisterIdSet& 
		DataflowGraph::Block::aliveOut() const
	{
		return _aliveOut;
	}
	
	DataflowGraph::Block* DataflowGraph::Block::fallthrough() const
	{
		return _fallthrough;
	}
	
	DataflowGraph::Block* DataflowGraph::Block::target() cons
	{
		return _target;
	}
	
	const DataflowGraph::BlockPoitnerVector& 
		DataflowGraph::Block::predecessors() const
	{
		return _predecessors;
	}
	
	Type DataflowGraph::Block::type() const
	{
		return _type;
	}
	
	const DataflowGraph::InstructionVector& 
		DataflowGraph::Block::instructions() const
	{
		return _instructions;
	}
		
	DataflowGraph::DataflowGraph() : _consistent( true )
	{
		_blocks.push_back( Block( Block::Entry ) );
		_blocks.push_back( Block( Block::Exit ) );
		
		_blocks.front()._fallthrough = &_blocks.back();
		_blocks.back()._predecessors.insert( &_blocks.front() );
	}
	
	DataflowGraph::iterator DataflowGraph::begin()
	{
		return _blocks.begin();
	}
	
	DataflowGraph::const_iterator DataflowGraph::begin() const
	{
		return _blocks.begin();
	}
	
	DataflowGraph::iterator DataflowGraph::end()
	{
		return _blocks.end();
	}
	
	DataflowGraph::const_iterator DataflowGraph::end()
	{
		return _blocks.end();
	}
	
	bool DataflowGraph::empty() const
	{
		return _blocks.empty();
	}
	
	DataflowGraph::size_type size() const
	{
		return _blocks.size();
	}
	
	DataflowGraph::size_type max_size() const
	{
		return _blocks.max_size();
	}
	
	DataflowGraph::iterator DataflowGraph::insert( iterator predecessor, 
		const Block& b )
	{
		Block* successor = predecessor->_fallthrough;

		assert( successor != 0 );
		b._fallthrough = successor;
		
		BlockPointerSet::iterator fi 
			= successor->_predecessors.find( &( *predecessor ) );
		assert( fi != successor->_predecessors.end() );
		successor->_predecessors.erase( fi );
		
		iterator current = _blocks.insert( successor, b );
		
		predecessor->_fallthrough = &( *current );
		successor->_predecessors.insert( &( *current ) );
		
		return current;
	}
	
	void DataflowGraph::target( iterator block, iterator target )
	{
		if( block->_target != 0 )
		{
			Block* previous = block->_target;
			BlockPointerSet::iterator fi 
				= previous->_predecessors.find( &( *block ) );
			assert( fi != previous->_predecessors.end() );
			previous->_predecessors.erase( fi );
		}
		
		block->_target = &( *target );
		assert( target->_predecessors.count( &( *block ) ) == 0 );
		
		target->_predecessors.insert( &( *block ) );
	}

	DataflowGraph::iterator erase( iterator block )
	{
		Block* fallthrough = block->_fallthrough;
		
		BlockPointerSet::iterator fi 
			= fallthrough->_predecessors.find( &( *block ) );
		assert( fi != fallthrough->_predecessors.end() );
		fallthrough->_predecessors.erase( fi );
		
		fallthrough->_predecessors.insert( block->_predecessors.begin(), 
			block->_predecessors.end() );
		
		for( BlockPointerSet::iterator pi = block->_predecessors.begin(); 
			pi != block->_predecessors.end(); ++pi )		
		{
			if( (*pi)->_target == &( *block ) )
			{
				(*pi)->_target = fallthrough;
			}
			else
			{
				assert( (*pi)->_fallthrough == &( *block ) );
				(*pi)->_fallthrough = fallthrough;
			}			
		}
		
		return _blocks.erase( block );
	}

	void DataflowGraph::clear()
	{
		_blocks.clear();
		_blocks.push_back( Block( Block::Entry ) );
		_blocks.push_back( Block( Block::Exit ) );
		_blocks.front()._fallthrough = &_blocks.back();
		_blocks.back()._predecessors.insert( &_blocks.front() );
	}
	
	void DataflowGraph::compute();
	

}

#endif

