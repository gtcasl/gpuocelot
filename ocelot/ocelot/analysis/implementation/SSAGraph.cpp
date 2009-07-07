/*!
	\file SSAGraph.cpp
	\date Saturday June 27, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The source file for the SSAGraph class.	
*/

#ifndef SSA_GRAPH_CPP_INCLUDED
#define SSA_GRAPH_CPP_INCLUDED

#include <ocelot/analysis/interface/SSAGraph.h>

namespace analysis
{
	void SSAGraph::_initialize( Block& b, DataflowGraph::iterator block, 
		DataflowGraph::RegisterId& current )
	{
		b.regs.clear();
		for( DataflowGraph::Block::RegisterIdSet::iterator 
			reg = block->_aliveIn.begin(); 
			reg != block->_aliveIn.end(); ++reg )
		{
			b.regs.insert( std::make_pair( *reg, current++ ) );
		}
		
		for( DataflowGraph::InstructionVector::iterator 
			instruction = block->_instructions.begin(); 
			instruction != block->_instructions.end(); ++instruction )
		{
			for( DataflowGraph::RegisterVector::iterator 
				reg = instruction->s.begin(); 
				reg != instruction->s.end(); ++reg )
			{
				RegisterMap::iterator mapping = b.regs.find( **reg );
				assert( mapping != b.regs.end() );
				**reg = mapping->second;
			}
			
			
		}
	}
	
	SSAGraph::SSAGraph( DataflowGraph& graph ) : _graph( graph )
	{
	
	}
	
	void SSAGraph::toSsa()
	{
		assert( !_graph._ssa );
		_graph._ssa = true;
		_blocks.clear();
		DataflowGraph::RegisterId current = 0;
		
		for( DataflowGraph::iterator fi = _graph.begin(); 
			fi != _graph.end(); ++fi )
		{
			BlockMap::iterator block = _blocks.insert( 
				std::make_pair( fi, Block() ) ).first;
			_initialize( block->second, block->first, current );
		}
	}
	
	void SSAGraph::fromSsa()
	{
		assert( _graph._ssa );
		_graph._ssa = false;
	
	}
}

#endif

