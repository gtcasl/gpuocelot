/*!
	\file SSAGraph.cpp
	\date Saturday June 27, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The source file for the SSAGraph class.	
*/

#ifndef SSA_GRAPH_CPP_INCLUDED
#define SSA_GRAPH_CPP_INCLUDED

#include <ocelot/analysis/interface/SSAGraph.h>

#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace analysis
{
	void SSAGraph::_initialize( Block& b, DataflowGraph::iterator block, 
		DataflowGraph::RegisterId& current )
	{
		report( "  Initializing block: " << block->label() );
		b.regs.clear();
		for( DataflowGraph::Block::RegisterSet::iterator 
			reg = block->_aliveIn.begin(); 
			reg != block->_aliveIn.end(); ++reg )
		{
			report( "   Mapping alive in register " << reg->id 
				<< " to " << current );
			b.regs.insert( std::make_pair( *reg, 
				DataflowGraph::Register( current++, reg->type ) ) );
		}
		
		b.aliveInMap = b.regs;
		
		for( DataflowGraph::InstructionVector::iterator 
			instruction = block->_instructions.begin(); 
			instruction != block->_instructions.end(); ++instruction )
		{
			report( "   Initializing instruction: " << instruction->label );
			for( DataflowGraph::RegisterPointerVector::iterator 
				reg = instruction->s.begin(); 
				reg != instruction->s.end(); ++reg )
			{
				RegisterMap::iterator mapping = b.regs.find( *reg->pointer );
				assert( mapping != b.regs.end() );
				report( "    Mapping source register " << *reg->pointer 
					<< " to " << mapping->second.id );
				*reg->pointer = mapping->second.id;
			}
			
			for( DataflowGraph::RegisterPointerVector::iterator 
				reg = instruction->d.begin(); 
				reg != instruction->d.end(); ++reg )
			{
				RegisterMap::iterator mapping = b.regs.find( *reg->pointer );
				if( mapping == b.regs.end() )
				{
					report( "    Mapping destination register " << *reg->pointer 
						<< " to " << current );
					mapping = b.regs.insert( std::make_pair( *reg, 
						DataflowGraph::Register( current++, 
						reg->type ) ) ).first;
				}
				else
				{
					report( "   ReMapping destination register " 
						<< *reg->pointer 
						<< " from " << mapping->second.id << " to " << current );
					mapping->second.id = current++;
				}
				*reg->pointer = mapping->second.id;
			}
		}
	}
	
	void SSAGraph::_insertPhis()
	{
		typedef std::vector< DataflowGraph::Register > IdVector;
		typedef std::unordered_map< DataflowGraph::Register, IdVector > IdMap;
		
		report( " Inserting Phi instructions." );
		
		for( BlockMap::iterator block = _blocks.begin(); 
			block != _blocks.end(); ++block )
		{
			IdMap map;
			
			report( "  For block " << block->first->label() );
			report( "   Processing " << block->first->_predecessors.size() 
				<< " predecessors." );
			
			for( DataflowGraph::BlockPointerSet::iterator 
				predecessor = block->first->_predecessors.begin(); 
				predecessor != block->first->_predecessors.end(); 
				++predecessor )
			{
				report( "    For predecessor " << (*predecessor)->label() );
				BlockMap::iterator predecessorBlock 
					= _blocks.find( *predecessor );
				assert( predecessorBlock != _blocks.end() );
						
				for( DataflowGraph::Block::RegisterSet::iterator 
					reg = (*predecessor)->_aliveOut.begin(); 
					reg != (*predecessor)->_aliveOut.end(); ++reg )
				{
					DataflowGraph::Block::RegisterSet::iterator in 
						= block->first->_aliveIn.find( reg->id );
					if( in != block->first->_aliveIn.end() )
					{
						RegisterMap::iterator mapping 
							= block->second.aliveInMap.find( reg->id );
						assert( mapping != block->second.aliveInMap.end() );
						IdMap::iterator phi = map.find( mapping->second.id );
						if( phi == map.end() )
						{
							phi = map.insert( std::make_pair( 
								mapping->second, IdVector() ) ).first;
						}
						RegisterMap::iterator remapping 
							= predecessorBlock->second.regs.find( *reg );
						assert( remapping 
							!= predecessorBlock->second.regs.end() );
						report( "     Mapping phi source " 
							<< remapping->second.id 
							<< " to destination " << mapping->second.id );
						phi->second.push_back( remapping->second );
					}
				}
			}
			
			report( "     Mapping phis with no producer." );
			
			for( DataflowGraph::Block::RegisterSet::iterator 
				reg = block->first->_aliveIn.begin(); 
				reg != block->first->_aliveIn.end(); ++reg )
			{
				RegisterMap::iterator mapping 
					= block->second.aliveInMap.find( reg->id );
				assert( mapping != block->second.aliveInMap.end() );
				IdMap::iterator phi = map.find( mapping->second );
				if( phi == map.end() )
				{
					phi = map.insert( std::make_pair( mapping->second, 
						IdVector() ) ).first;
					report( "      Mapping phi source " << mapping->second.id 
						<< " to destination " << mapping->second.id );
					phi->second.push_back( mapping->second );
				}
			}
			
			for( IdMap::iterator phi = map.begin(); phi != map.end(); ++phi )
			{
				DataflowGraph::PhiInstruction instruction;
				instruction.d = phi->first;
				for( IdVector::iterator source = phi->second.begin(); 
					source != phi->second.end(); ++source )
				{
					instruction.s.push_back( *source );
				}
				block->first->_phis.push_back( instruction );
			}
		}
	}

	void SSAGraph::_updateIn()
	{
		report( " Updating AliveIn for " << _blocks.size() << " blocks." );
		for( BlockMap::iterator block = _blocks.begin(); 
			block != _blocks.end(); ++block )
		{
			report( "  Updating AliveIn for block " << block->first->label() );
			block->first->_aliveIn.clear();
			
			for( DataflowGraph::PhiInstructionVector::iterator 
				phi = block->first->_phis.begin(); 
				phi != block->first->_phis.end(); ++phi )
			{
				for( DataflowGraph::RegisterVector::iterator 
					reg = phi->s.begin(); reg != phi->s.end(); ++reg )
				{
					report( "   Adding register " << reg->id );
					block->first->_aliveIn.insert( *reg );
				}
			}
		}
	}
	
	void SSAGraph::_updateOut()
	{
		report( " Updating AliveOut for " << _blocks.size() << " blocks." );
		for( BlockMap::iterator block = _blocks.begin(); 
			block != _blocks.end(); ++block )
		{
			report( "  Updating AliveOut for block " << block->first->label() );
			DataflowGraph::Block::RegisterSet newAliveOut;
			for( DataflowGraph::Block::RegisterSet::iterator 
				reg = block->first->_aliveOut.begin(); 
				reg != block->first->_aliveOut.end(); ++reg )
			{
				RegisterMap::iterator mapping = block->second.regs.find( *reg );
				assert( mapping != block->second.regs.end() );
				report( "   Mapping alive out register " << mapping->first.id 
					<< " to " << mapping->second.id );
				newAliveOut.insert( mapping->second );
			}
			block->first->_aliveOut = std::move( newAliveOut );
		}
	}
	
	SSAGraph::SSAGraph( DataflowGraph& graph ) : _graph( graph )
	{
	}
	
	void SSAGraph::toSsa()
	{
		report( "Converting dataflow graph to pure SSA form" );
	
		assert( !_graph._ssa );
		_graph._ssa = true;
		_blocks.clear();
		DataflowGraph::RegisterId current = 0;
		
		report( " Initializing " << _graph.size() << " blocks" );
		for( DataflowGraph::iterator fi = _graph.begin(); 
			fi != _graph.end(); ++fi )
		{
			BlockMap::iterator block = _blocks.insert( 
				std::make_pair( fi, Block() ) ).first;
			_initialize( block->second, block->first, current );
		}
		
		_insertPhis();
		_updateIn();
		_updateOut();
		
		report( " Graph is now in full SSA form." );
	}
	
	void SSAGraph::fromSsa()
	{
		assert( _graph._ssa );
		_graph._ssa = false;
		
		RegisterMap map;
		
		for( DataflowGraph::iterator fi = _graph.begin(); 
			fi != _graph.end(); ++fi )
		{
			for( DataflowGraph::PhiInstructionVector::iterator 
				phi = fi->_phis.begin(); phi != fi->_phis.end(); ++phi )
			{
				map.insert( std::make_pair( phi->d, *phi->s.begin() ) );
			}
			
			fi->_phis.clear();
		}

		for( DataflowGraph::iterator fi = _graph.begin(); 
			fi != _graph.end(); ++fi )
		{
			for( DataflowGraph::InstructionVector::iterator 
				instruction = fi->_instructions.begin(); 
				instruction != fi->_instructions.end(); ++instruction )
			{
				for( DataflowGraph::RegisterPointerVector::iterator 
					reg = instruction->s.begin(); 
					reg != instruction->s.end(); ++reg )
				{
					RegisterMap::iterator mapping = map.find( *reg->pointer );
					if( mapping != map.end() )
					{
						*reg->pointer = mapping->second.id;
					}
				}

				for( DataflowGraph::RegisterPointerVector::iterator 
					reg = instruction->d.begin(); 
					reg != instruction->d.end(); ++reg )
				{
					RegisterMap::iterator mapping = map.find( *reg->pointer );
					if( mapping != map.end() )
					{
						*reg->pointer = mapping->second.id;
					}
				}
			}
			
			DataflowGraph::Block::RegisterSet newAlive;
			
			for( DataflowGraph::Block::RegisterSet::iterator 
				reg = fi->_aliveOut.begin(); 
				reg != fi->_aliveOut.end(); ++reg )
			{
				RegisterMap::iterator mapping = map.find( *reg );
				if( mapping != map.end() )
				{
					newAlive.insert( mapping->second );
				}
				else
				{
					newAlive.insert( *reg );
				}
			}
			fi->_aliveOut = std::move( newAlive );
		}		
		
	}
}

#endif

