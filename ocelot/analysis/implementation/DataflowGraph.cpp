/*! \file DataflowGraph.cpp
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Tuesday June 23, 2009
	\file The source file for the DataflowGraph class.
*/

#ifndef DATAFLOW_GRAPH_CPP_INCLUDED
#define DATAFLOW_GRAPH_CPP_INCLUDED

#include <ocelot/analysis/interface/DataflowGraph.h>
#include <ocelot/analysis/interface/SSAGraph.h>

#include <ocelot/ir/interface/IRKernel.h>

#include <hydrazine/implementation/string.h>

#include <unordered_map>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0
#define REPORT_CONVERT 0

namespace analysis
{

	DataflowGraph::Register::Register( RegisterId _id, Type _type ) 
		: type( _type ), id( _id )
	{
	
	}
	
	DataflowGraph::Register::Register( const RegisterPointer& r ) 
		: type( r.type ), id( *r.pointer )
	{
	
	}
	
	DataflowGraph::RegisterPointer::RegisterPointer( 
		RegisterId* _id, Type _type ) : type( _type ), pointer( _id )
	{
	
	}
	
	bool DataflowGraph::Register::operator==( const Register& r ) const
	{
		return id == r.id;
	}
	
	bool DataflowGraph::RegisterPointer::operator==( 
		const RegisterPointer& r ) const
	{
		return *pointer == *r.pointer;
	}

	DataflowGraph::NoProducerException::NoProducerException( 
		RegisterId reg )
	{
		std::stringstream message;
		message << "No producer exists for register " << reg;
		_message = message.str();
	}
	
	DataflowGraph::NoProducerException::~NoProducerException() throw()
	{
		
	}
	
	const char* DataflowGraph::NoProducerException::what() const throw()
	{
		return _message.c_str();
	}

	DataflowGraph::Instruction DataflowGraph::convert( ir::PTXInstruction& i )
	{
		Instruction result;
	
		reportE( REPORT_CONVERT, " Converting instruction \"" 
			<< i.toString() << "\"" );
	
		ir::PTXOperand ir::PTXInstruction::* sources[ 5 ] 
			= { &ir::PTXInstruction::pg, &ir::PTXInstruction::a, 
			&ir::PTXInstruction::b, &ir::PTXInstruction::c, 
			&ir::PTXInstruction::d };

		unsigned int limit = 4;

		if( ir::PTXInstruction::St == i.opcode )
		{
			limit = 5;
		}
		else if( ir::PTXInstruction::Bfi == i.opcode )
		{
			limit = 5;
			sources[ 4 ] = &ir::PTXInstruction::pq;
		}

		for( unsigned int j = 0; j < limit; ++j )
		{
			if( !( i.*sources[ j ] ).array.empty() )
			{
				for( ir::PTXOperand::Array::iterator 
					fi = ( i.*sources[ j ] ).array.begin(); 
					fi != ( i.*sources[ j ] ).array.end(); ++fi )
				{
					if( fi->addressMode != ir::PTXOperand::Register )
					{
						continue;
					}
					reportE( REPORT_CONVERT, "  Converting register \"" 
						<< fi->identifier << "\" to id " << fi->reg
						<< " type " << ir::PTXOperand::toString( fi->type ) );
					_maxRegister = std::max( _maxRegister, fi->reg );
					result.s.push_back( 
						RegisterPointer( &fi->reg, fi->type ) );
				}
			}			
			else if( ( i.*sources[ j ] ).addressMode == ir::PTXOperand::Register 
				|| ( i.*sources[ j ] ).addressMode == ir::PTXOperand::Indirect )
			{
				if( ( i.*sources[ j ] ).type == ir::PTXOperand::pred )
				{
					if( ( i.*sources[ j ] ).condition == ir::PTXOperand::PT
						|| ( i.*sources[ j ] ).condition 
						== ir::PTXOperand::nPT )
					{
						continue;
					}
				}

				reportE( REPORT_CONVERT, "  Converting register \"" 
					<< ( i.*sources[ j ] ).identifier 
					<< "\" to id " << ( i.*sources[ j ] ).reg << " type "
					<< ir::PTXOperand::toString( ( i.*sources[ j ] ).type ) );
				_maxRegister = std::max( _maxRegister, 
					( i.*sources[ j ] ).reg );
				result.s.push_back( 
					RegisterPointer( &( i.*sources[ j ] ).reg, 
					( i.*sources[ j ] ).type ) );
			}
		}

		ir::PTXOperand ir::PTXInstruction::* destinations[ 2 ] 
			= { &ir::PTXInstruction::pq, &ir::PTXInstruction::d };

		if( ir::PTXInstruction::St == i.opcode )
		{
			limit = 1;
		}
		else if( ir::PTXInstruction::Bfi == i.opcode )
		{
			limit = 1;
			destinations[ 0 ] = &ir::PTXInstruction::d;
		}
		else
		{
			limit = 2;
		}

		for( unsigned int j = 0; j < limit; ++j )
		{
			if( !( i.*destinations[ j ] ).array.empty() )
			{
				for( ir::PTXOperand::Array::iterator 
					fi =  ( i.*destinations[ j ] ).array.begin(); 
					fi != ( i.*destinations[ j ] ).array.end(); ++fi )
				{
					if( fi->addressMode != ir::PTXOperand::Register )
					{
						continue;
					}
					reportE( REPORT_CONVERT, "  Converting register \"" 
						<< fi->identifier 
						<< "\" to id " << fi->reg
						<< " type " << ir::PTXOperand::toString( fi->type ) );
					_maxRegister = std::max( _maxRegister, fi->reg );
					result.d.push_back( 
						RegisterPointer( &fi->reg, fi->type ) );
				}
			} 
			else if( ( i.*destinations[ j ] ).addressMode 
				== ir::PTXOperand::Register )
			{
				if( ( i.*destinations[ j ] ).type == ir::PTXOperand::pred )
				{
					if( ( i.*destinations[ j ] ).condition == ir::PTXOperand::PT
						|| ( i.*destinations[ j ] ).condition 
						== ir::PTXOperand::nPT )
					{
						continue;
					}
				}			

				_maxRegister = std::max( _maxRegister, 
					( i.*destinations[ j ] ).reg );
				if( ir::PTXInstruction::Cvt == i.opcode )
				{
					result.d.push_back( 
						RegisterPointer( &( i.*destinations[ j ] ).reg, 
						i.type ) );
				}
				else
				{
					result.d.push_back( 
						RegisterPointer( &( i.*destinations[ j ] ).reg, 
						( i.*destinations[ j ] ).type ) );
				}
				
				reportE( REPORT_CONVERT, "  Converting register \"" 
					<< ( i.*destinations[ j ] ).identifier 
					<< "\" to id " << *result.d.back().pointer << " type "
					<< ir::PTXOperand::toString(
						result.d.back().type ) );
			}

		}
		
		result.i = &i;
		result.label = i.toString();
		
		return result;
	}

	bool DataflowGraph::Block::_equal( const RegisterSet& one, 
		const RegisterSet& two )
	{
		if( one.size() != two.size() ) return false;
		
		for( RegisterSet::const_iterator fi = one.begin(); 
			fi != one.end(); ++fi )
		{
			RegisterSet::const_iterator ti = two.find( *fi );
			if( ti == two.end() ) return false;
			
			if( ti->type != fi->type ) return false;
		}
		
		return true;
	}

	DataflowGraph::Block::Block( DataflowGraph& dfg, 
		ir::ControlFlowGraph::iterator block ) : _fallthrough( dfg.end() ),
		_type( Body ), _block( block )
	{
		_fallthrough = dfg.end();
		for( ir::ControlFlowGraph::InstructionList::const_iterator 
			fi = block->instructions.begin(); 
			fi != block->instructions.end(); ++fi )
		{
			_instructions.push_back( dfg.convert( 
				*static_cast< ir::PTXInstruction* >( *fi ) ) );
		}
	
	}

	DataflowGraph::Block::Block( DataflowGraph& dfg, Type t ) :
		_fallthrough( dfg.end() ), _type( t )
	{
		
	}
	
	void DataflowGraph::Block::_resolveTypes( DataflowGraph::Type& d,
		const DataflowGraph::Type& s )
	{
		if( ir::PTXOperand::relaxedValid( d, s ) )
		{
			d = s;
		}
	}
	
	bool DataflowGraph::Block::compute( bool hasFallthrough )
	{
		if( type() != Body ) return false;
		
		report( " Block name " << label() );
		
		RegisterSet previousIn = std::move( _aliveIn );
		assert( _aliveIn.empty() );
		
		report( "  Scanning targets: " );
		
		if( hasFallthrough )
		{
			report( "   " << _fallthrough->label() );		
			_aliveOut = _fallthrough->_aliveIn;
		}
		
		bool isOwnPredecessor = false;
		
		for( BlockPointerSet::iterator bi = _targets.begin(); 
			bi != _targets.end(); ++bi )
		{
			isOwnPredecessor |= (this == &(**bi));
			report( "   " << (*bi)->label() );		
			for( RegisterSet::iterator ri = (*bi)->_aliveIn.begin(); 
				ri != (*bi)->_aliveIn.end(); ++ri )
			{
				_aliveOut.insert( *ri );
			}
		}
		
		_aliveIn = _aliveOut;
		
		for( InstructionVector::reverse_iterator ii = _instructions.rbegin(); 
			ii != _instructions.rend(); ++ii )
		{
			for( RegisterPointerVector::iterator di = ii->d.begin(); 
				di != ii->d.end(); ++di )
			{
				RegisterSet::iterator ai = _aliveIn.find( *di );
				if( ai != _aliveIn.end() )
				{
					_resolveTypes( di->type, ai->type );
					_aliveIn.erase( *ai );
				}
			}
			
			for( RegisterPointerVector::iterator si = ii->s.begin(); 
				si != ii->s.end(); ++si )
			{
				std::pair<RegisterSet::iterator, bool> insertion =
					_aliveIn.insert( *si );
				
				if( !insertion.second )
				{
					_resolveTypes( si->type, insertion.first->type );
				}
			}
		}
		
		if( isOwnPredecessor )
		{
			for( RegisterSet::iterator ri = _aliveIn.begin(); 
				ri != _aliveIn.end(); ++ri )
			{
				_aliveOut.insert( *ri );
			}
		}
		
		return !_equal( _aliveIn, previousIn );
	}

	const DataflowGraph::Block::RegisterSet& 
		DataflowGraph::Block::aliveIn() const
	{
		return _aliveIn;
	}
	
	const DataflowGraph::Block::RegisterSet& 
		DataflowGraph::Block::aliveOut() const
	{
		return _aliveOut;
	}
	
	DataflowGraph::BlockVector::iterator 
		DataflowGraph::Block::fallthrough() const
	{
		return _fallthrough;
	}
	
	const DataflowGraph::BlockPointerSet& 
		DataflowGraph::Block::targets() const
	{
		return _targets;
	}
	
	const DataflowGraph::BlockPointerSet& 
		DataflowGraph::Block::predecessors() const
	{
		return _predecessors;
	}
	
	DataflowGraph::Block::Type DataflowGraph::Block::type() const
	{
		return _type;
	}
	
	const DataflowGraph::InstructionVector& 
		DataflowGraph::Block::instructions() const
	{
		return _instructions;
	}
	
	const DataflowGraph::PhiInstructionVector& 
		DataflowGraph::Block::phis() const
	{
		return _phis;
	}

	const std::string& DataflowGraph::Block::label() const
	{
		return _block->label;
	}

	const std::string& DataflowGraph::Block::producer( const Register& r ) const
	{
		assertM( aliveIn().count( r ) != 0, "Register " << r.id 
			<< " is not in the alive-in set of block " << label() );

		BlockPointerSet::const_iterator predecessor = predecessors().end();

		for( BlockPointerSet::const_iterator pi = predecessors().begin();
			pi != predecessors().end(); ++pi )
		{
			if( (*pi)->aliveOut().count( r ) != 0 )
			{
	
				predecessor = pi;
				break;
			}
		}
		
		if( predecessor == predecessors().end() )
		{
			throw NoProducerException( r.id );
		}
		
		return (*predecessor)->label();
	}
	
	DataflowGraph::Block::RegisterSet DataflowGraph::Block::alive( 
		const InstructionVector::const_iterator& i )
	{
		RegisterSet alive( _aliveOut );
		
		InstructionVector::const_reverse_iterator 
			end = InstructionVector::const_reverse_iterator( i );
		
		for( InstructionVector::reverse_iterator ii = _instructions.rbegin(); 
			ii != end; ++ii )
		{
			for( RegisterPointerVector::iterator di = ii->d.begin(); 
				di != ii->d.end(); ++di )
			{
				alive.erase( *di );
			}
			
			for( RegisterPointerVector::iterator si = ii->s.begin(); 
				si != ii->s.end(); ++si )
			{
				alive.insert( *si );
			}
		}
		
		return alive;
	}

	ir::ControlFlowGraph::BasicBlock::Id DataflowGraph::Block::id() const
	{
		return _block->id;
	}

	ir::ControlFlowGraph::iterator DataflowGraph::Block::block()
	{
		return _block;
	}

	DataflowGraph::DataflowGraph()  
		: KernelAnalysis(Analysis::DataflowGraphAnalysis,
			"DataflowGraphAnalysis"), _cfg( 0 ), _consistent( false ), 
			_ssa( false ), _maxRegister( 0 )
	{
	}
	
	void DataflowGraph::analyze(ir::IRKernel& kernel)
	{
		_cfg        = kernel.cfg();
		_consistent = _cfg->empty();
		
		typedef std::unordered_map< ir::ControlFlowGraph::iterator, 
			iterator > BlockMap;
		BlockMap map;
		
		ir::ControlFlowGraph& cfg = *_cfg;
		
		ir::ControlFlowGraph::BlockPointerVector blocks 
			= cfg.executable_sequence();
		assert( blocks.size() >= 2 );
				
		report( "Importing " << blocks.size() << " blocks from CFG." );
		
		unsigned int count = 1;
		map.insert( std::make_pair( cfg.get_entry_block(), 
			_blocks.insert( _blocks.end(), Block( *this, Block::Entry ) ) ) );	
		for( ir::ControlFlowGraph::BlockPointerVector::iterator 
			bbi = blocks.begin(); bbi != blocks.end(); ++bbi, ++count )
		{
			if( *bbi == cfg.get_exit_block() ) continue;
			if( *bbi == cfg.get_entry_block() ) continue;
			Block newB( *this, *bbi );
			if( (*bbi)->label.empty() )
			{
				std::stringstream label;
				label << "$__Block_" << count;
				(*bbi)->label = label.str();
			}
			map.insert( std::make_pair( *bbi, 
				_blocks.insert( _blocks.end(), newB ) ) );	
		}
		map.insert( std::make_pair( cfg.get_exit_block(), 
			_blocks.insert( _blocks.end(), Block( *this, Block::Exit ) ) ) );	
		
		_blocks.front()._block = cfg.get_entry_block();
		_blocks.back()._block = cfg.get_exit_block();
		_blocks.back()._fallthrough = _blocks.end();

		report( "Adding edges from CFG" );
		ir::ControlFlowGraph::BlockPointerVector::iterator bbi = blocks.begin();
		for( ; bbi != blocks.end(); ++bbi )
		{
			BlockMap::iterator bi = map.find( *bbi );
			assert( bi != map.end() );
		
			report( " Adding edges into " << (*bbi)->label );
		
			for( ir::ControlFlowGraph::edge_pointer_iterator 
				ei = (*bbi)->in_edges.begin(); 
				ei != (*bbi)->in_edges.end(); ++ei )
			{
				BlockMap::iterator begin = map.find( (*ei)->head );
				assert( begin != map.end() );
				
				assert( (*ei)->head == begin->second->_block );
				assert( (*ei)->tail == bi->second->_block );
				
				if( (*ei)->type == ir::ControlFlowGraph::Edge::FallThrough )
				{
					report( "  fallthrough " << begin->second->label() << " -> "
						<< bi->second->label() );
					begin->second->_fallthrough = bi->second;
					bi->second->_predecessors.insert( begin->second );
				}
				else if( (*ei)->type == ir::ControlFlowGraph::Edge::Branch )
				{
					report( "  branch " << begin->second->label() << " -> "
						<< bi->second->label() );
					begin->second->_targets.insert( bi->second );
					bi->second->_predecessors.insert( begin->second );	
				}
				else
				{
					/* assertM( false, "Got invalid edge type between " 
						<< begin->second->label() << " and " 
						<< bi->second->label() );*/
					begin->second->_targets.insert( bi->second );
					bi->second->_predecessors.insert( begin->second );
				}
			}
		}
		
		compute();
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
	
	DataflowGraph::const_iterator DataflowGraph::end() const
	{
		return _blocks.end();
	}
	
	bool DataflowGraph::empty() const
	{
		return _blocks.empty();
	}
	
	DataflowGraph::size_type DataflowGraph::size() const
	{
		return _blocks.size();
	}
	
	DataflowGraph::size_type DataflowGraph::max_size() const
	{
		return _blocks.max_size();
	}
	
	DataflowGraph::iterator DataflowGraph::insert( iterator predecessor, 
		const std::string& label )
	{
		BlockVector::iterator successor = predecessor->_fallthrough;

		if(successor == end())
		{
			assert( !predecessor->_targets.empty() );
			successor = *predecessor->_targets.begin();
		}
		
		return insert( predecessor, successor, label );
	}
	
	DataflowGraph::iterator DataflowGraph::insert( iterator predecessor, 
		iterator successor, const std::string& label )
	{
		assert( predecessor->targets().count( successor ) != 0
			|| predecessor->_fallthrough == successor );

		_consistent = false;
		
		report( "Inserting new block " << label << " between " 
			<< predecessor->label() << " and " << successor->label() );
		
		assert( successor != begin() );
		
		BlockPointerSet::iterator fi 
			= successor->_predecessors.find( predecessor );
		assert( fi != successor->_predecessors.end() );
		successor->_predecessors.erase( fi );
		
		ir::ControlFlowGraph::edge_iterator edge = 
			predecessor->_block->get_edge( successor->_block );
		ir::BasicBlock::Edge::Type edgeType = edge->type;
		
		_cfg->remove_edge( edge );
		
		iterator current = _blocks.insert( successor, Block( *this, 
			Block::Body ) );
		current->_block = _cfg->insert_block(
			ir::ControlFlowGraph::BasicBlock( label, _cfg->newId() ) );
		
		_cfg->insert_edge( ir::ControlFlowGraph::Edge( predecessor->_block, 
			current->_block, edgeType ) );
		
		if( predecessor->_fallthrough == successor )
		{
			predecessor->_fallthrough = current;
			current->_fallthrough = successor;
		}
		else
		{
			BlockPointerSet::iterator ti
				= predecessor->_targets.find( successor );
			assert( ti != predecessor->_targets.end() );
			predecessor->_targets.erase( ti );

			predecessor->_targets.insert( current );
			current->_targets.insert( successor );
		}
		
		current->_predecessors.insert( predecessor );
		successor->_predecessors.insert( current );
		
		_cfg->insert_edge( ir::ControlFlowGraph::Edge( current->_block, 
			successor->_block, edgeType ) );
		
		return current;
	}
	
	void DataflowGraph::target( iterator block,
		iterator target, bool fallthrough )
	{
		report( "Adding branch from " << block->label() 
			<< " to " << target->label() );
		_consistent = false;
		std::pair< BlockPointerSet::iterator, bool > insertion 
			= block->_targets.insert( target );
		
		if( insertion.second )
		{
			assert( target->_predecessors.count( block ) == 0 );
			target->_predecessors.insert( block );
			
			if( fallthrough )
			{
				_cfg->insert_edge( ir::ControlFlowGraph::Edge( block->_block, 
					target->_block, ir::ControlFlowGraph::Edge::FallThrough ) );
				block->_fallthrough = target;
			}
			else
			{
				_cfg->insert_edge( ir::ControlFlowGraph::Edge( block->_block, 
					target->_block, ir::ControlFlowGraph::Edge::Branch ) );
			}
		}
	}

	DataflowGraph::iterator DataflowGraph::split( iterator block, 
		unsigned int instruction, bool isFallthrough )
	{
		report( "Splitting block " << block->label() 
			<< " at instruction " << instruction );
		_consistent = false;
		
		assertM( instruction <= block->_instructions.size(), 
			"Cannot split block of size " << block->_instructions.size() 
			<< " at instruction " << instruction );
		
		InstructionVector::iterator begin = block->_instructions.begin();
		std::advance( begin, instruction );
		InstructionVector::iterator end = block->_instructions.end();
		
		iterator added = _blocks.insert( ++iterator( block ), 
			Block( *this, Block::Body ) );

		if( isFallthrough )
		{
			added->_block = _cfg->split_block( block->_block, instruction, 
				ir::ControlFlowGraph::Edge::FallThrough );
		}
		else
		{
			added->_block = _cfg->split_block( block->_block, instruction, 
				ir::ControlFlowGraph::Edge::Branch );
		}
		
		added->_predecessors.insert( block );
		
		added->_instructions.insert( added->_instructions.end(), begin, end );
		block->_instructions.erase( begin, end );
		
		added->_fallthrough = block->_fallthrough;

		if( added->_fallthrough != this->end() )
		{
			BlockPointerSet::iterator predecessor = 
				added->_fallthrough->_predecessors.find( block );
			assert( predecessor != added->_fallthrough->_predecessors.end() );
			added->_fallthrough->_predecessors.erase( block );
			added->_fallthrough->_predecessors.insert( added );
		}
		
		for( BlockPointerSet::iterator target = block->_targets.begin(); 
			target != block->_targets.end(); ++target )
		{
			BlockPointerSet::iterator predecessor = 
				(*target)->_predecessors.find( block );
			assert( predecessor != (*target)->_predecessors.end() );
			(*target)->_predecessors.erase( block );
			(*target)->_predecessors.insert( added );
		}
		
		added->_targets = std::move( block->_targets );
		block->_targets.clear();
		
		if( isFallthrough )
		{
			report("  Joining block via a fallthrough edge.");
			block->_fallthrough = added;
		}
		else
		{
			report("  Joining block via a branch edge.");
			block->_fallthrough = this->end();
			block->_targets.insert( added );
		}
		
		return added;
	}

	void DataflowGraph::redirect( iterator source, 
		iterator destination, iterator newTarget )
	{
		_consistent = false;
	
		report( "Redirecting " << source->label() << " from " 
			<< destination->label() << " to " << newTarget->label() );
		BlockPointerSet::iterator 
			predecessor = destination->_predecessors.find( source );
		assertM( predecessor != destination->_predecessors.end(),
			"There is no edge between " << source->label() << " and " 
			<< destination->label() );
		destination->_predecessors.erase( predecessor );

		if( source->_fallthrough == destination )
		{
			report( " Redirecting fallthrough edge." );
			source->_fallthrough = newTarget;
		}
		else
		{
			report( " Redirecting branch edge." );
			BlockPointerSet::iterator 
				target = source->_targets.find( destination );
			assertM( target != source->_targets.end(), 
				"There is no edge between " << source->label() << " and " 
				<< destination->label() );
			source->_targets.erase( target );
			source->_targets.insert( newTarget );
		}

		newTarget->_predecessors.insert( source );

		ir::ControlFlowGraph::edge_iterator 
			existingEdge = source->_block->get_edge( destination->_block );

		ir::ControlFlowGraph::Edge edge( source->_block, newTarget->_block, 
			existingEdge->type );

		_cfg->remove_edge( existingEdge );
		_cfg->insert_edge( edge );
	}

	void DataflowGraph::insert( iterator block, 
		const ir::Instruction& instruction, unsigned int index )
	{
		_consistent = false;
		
		InstructionVector::iterator position = block->_instructions.begin();
		std::advance( position, index );
		
		ir::PTXInstruction* ptx = static_cast< ir::PTXInstruction* >( 
			instruction.clone() );
		
		block->_instructions.insert( position, convert( *ptx ) );
		
		ir::ControlFlowGraph::InstructionList::iterator 
			bbPosition = block->_block->instructions.begin();
		std::advance( bbPosition, index );
		
		block->_block->instructions.insert( bbPosition, ptx );
	}

	void DataflowGraph::insert( iterator block, 
		const ir::Instruction& instruction )
	{
		insert( block, instruction, block->instructions().size() );
	}
	
	DataflowGraph::iterator DataflowGraph::erase( iterator block )
	{
		_consistent = false;
		BlockVector::iterator fallthrough = block->_fallthrough;
		
		BlockPointerSet::iterator fi 
			= fallthrough->_predecessors.find( block );
		assert( fi != fallthrough->_predecessors.end() );
		fallthrough->_predecessors.erase( fi );
		
		fallthrough->_predecessors.insert( block->_predecessors.begin(), 
			block->_predecessors.end() );
		
		for( BlockPointerSet::iterator pi = block->_predecessors.begin(); 
			pi != block->_predecessors.end(); ++pi )		
		{
			if( (*pi)->_fallthrough == block )
			{
				(*pi)->_fallthrough = fallthrough;
			
				_cfg->insert_edge( ir::ControlFlowGraph::Edge( (*pi)->_block, 
					fallthrough->_block, 
					ir::ControlFlowGraph::Edge::FallThrough ) );
			}

			BlockPointerSet::iterator target 
				= (*pi)->_targets.find( block );

			if( target != (*pi)->_targets.end() )
			{
				(*pi)->_targets.erase( target );
				(*pi)->_targets.insert( fallthrough );
				
				_cfg->insert_edge( ir::ControlFlowGraph::Edge( (*pi)->_block, 
					fallthrough->_block, ir::ControlFlowGraph::Edge::Branch ) );
			}
		}
		
		_cfg->remove_block( block->_block );
		
		return fallthrough;
	}

	void DataflowGraph::clear()
	{
		_consistent = true;
		_blocks.clear();
		_blocks.push_back( Block( *this, Block::Entry ) );
		_blocks.push_back( Block( *this, Block::Exit ) );
		
		_cfg->clear();
		
		_blocks.front()._fallthrough = --_blocks.end();
		_blocks.front()._block = _cfg->get_entry_block();
		_blocks.back()._predecessors.insert( _blocks.begin() );
		_blocks.back()._fallthrough = end();
		_blocks.back()._block = _cfg->get_exit_block();
	}

	void DataflowGraph::erase( iterator block, unsigned int index )
	{
		assert( index < block->instructions().size() );
	
		_consistent = false;
		
		InstructionVector::iterator position = block->_instructions.begin();
		std::advance( position, index );
		
		block->_instructions.erase( position );
	}
	
	void DataflowGraph::compute()
	{
		if( _consistent ) return;		
		_consistent = true;
		
		if( _ssa ) fromSsa();
		
		BlockPointerSet worklist;
		
		for( iterator fi = begin(); fi != end(); ++fi )
		{
			if( fi->type() == Block::Body )
			{
				fi->_aliveIn.clear();
				fi->_aliveOut.clear();
				fi->_phis.clear();
				worklist.insert( fi );
			}
		}
		
		while( !worklist.empty() )
		{
			iterator block = *worklist.begin();
			worklist.erase( worklist.begin() );
			
			report( "Running dataflow for basic block " << block->label() );
			bool changed = block->compute( block->_fallthrough != end() );
			
			if( changed )
			{
				report( "  Block changed, adding predecessors:" );
				for( BlockPointerSet::iterator 
					fi = block->_predecessors.begin(); 
					fi != block->_predecessors.end(); ++fi )
				{
					report( "    " << (*fi)->label() );
					worklist.insert( *fi );
				}
			}
		}

		#if !defined(NDEBUG) && REPORT_BASE > 0
		report( "Final Report" );
		
		for( iterator fi = begin(); fi != end(); ++fi )
		{
			report( " Block " << fi->label() );
			report( "  Alive In" );
			for( Block::RegisterSet::iterator ri = fi->_aliveIn.begin(); 
				ri != fi->_aliveIn.end(); ++ri )
			{
				report( "   r" << ri->id << " "
					<< ir::PTXOperand::toString( ri->type ) );
			}
			report( "  Alive Out" );
			for( Block::RegisterSet::iterator ri = fi->_aliveOut.begin(); 
				ri != fi->_aliveOut.end(); ++ri )
			{
				report( "   r" << ri->id << " "
					<< ir::PTXOperand::toString( ri->type ) );
			}
		}
		#endif
		
	}

	DataflowGraph::RegisterId DataflowGraph::maxRegister() const
	{
		return _maxRegister;
	}

	DataflowGraph::RegisterId DataflowGraph::newRegister()
	{
		return ++_maxRegister;
	}

	void DataflowGraph::toSsa()
	{
		compute();
		SSAGraph graph( *this );
		graph.toSsa();		
	}

	void DataflowGraph::fromSsa()
	{
		SSAGraph graph( *this );
		graph.fromSsa();		
	}
	
	bool DataflowGraph::ssa() const
	{
		return _ssa;
	}

	DataflowGraph::BlockPointerVector DataflowGraph::executableSequence()
	{
		ir::ControlFlowGraph::BlockPointerVector 
			sequence = _cfg->executable_sequence();
		
		IteratorMap map = getCFGtoDFGMap();
		
		BlockPointerVector result;
		
		for( ir::ControlFlowGraph::pointer_iterator block = sequence.begin(); 
			block != sequence.end(); ++block )
		{
			IteratorMap::iterator mapping = map.find( *block );
			assert( mapping != map.end() );
			
			result.push_back( mapping->second );
		}
		
		return std::move( result );
	}

	DataflowGraph::IteratorMap DataflowGraph::getCFGtoDFGMap()
	{
		IteratorMap map;
		
		for( iterator block = begin(); block != end(); ++block )
		{
			map.insert( std::make_pair( block->block(), block ) );
		}
		
		return map;	
	}

	std::ostream& operator<<( std::ostream& out, const DataflowGraph& graph )
	{
		DataflowGraph& nonConstGraph = const_cast< DataflowGraph& >( graph );
		nonConstGraph.compute();
		
		out << "digraph DFG {\n";
		out << "\tb_0_AliveOut[ shape = Mdiamond, label = \"Entry\" ];\n";
		out << "\tb_" << ( graph.size() - 1 ) 
			<< "_AliveIn[ shape = Msquare, label = \"Exit\" ];\n";
		out << "\tb_0_AliveOut -> b_1_AliveIn[ " 
			<< "style = dotted ];\n";
		
		unsigned int blockCount = 1;
		for( DataflowGraph::const_iterator block = ++graph.begin(); 
			block != --graph.end(); ++block, ++blockCount )
		{
			typedef std::unordered_map< DataflowGraph::RegisterId, 
				std::string > RegisterMap;
			RegisterMap map;
						
			out << "\tsubgraph cluster" << blockCount << "{\n";
			out << "\t\tnode[ shape = record ];\n";
			out << "\t\tlabel=\"" << block->label() << "\";\n";
			
			std::stringstream aliveInPrefix;
			aliveInPrefix << "b_" << blockCount << "_AliveIn";
			out << "\t\t" << aliveInPrefix.str() 
				<< "[ shape = record, label = \"{ AliveIn ";
			if( !block->aliveIn().empty() )
			{
				out << " | { ";
				DataflowGraph::Block::RegisterSet::const_iterator 
					ri = block->aliveIn().begin();
				std::stringstream value;
				value << "r" << ri->id;
				out << "<" << value.str() << "> " << value.str();
				map[ ri->id ] = aliveInPrefix.str() + ":" + value.str();
				for( ++ri; ri != block->aliveIn().end(); ++ri )
				{
					std::stringstream stream;
					stream << "r" << ri->id;
					out << " | <" << stream.str() << "> " << stream.str();
					map[ ri->id ] = aliveInPrefix.str() 
						+ ":" + stream.str();
				}
				out << " }";
			}
			out << " }\"];\n";
			
			unsigned int count = 0;
			for( DataflowGraph::PhiInstructionVector::const_iterator 
				ii = block->phis().begin(); 
				ii != block->phis().end(); ++ii, ++count )
			{
				std::stringstream instructionPrefix;
				instructionPrefix << "b_" << blockCount << "_instruction" 
					<< count;

				for( DataflowGraph::RegisterVector::const_iterator 
					si = ii->s.begin(); si != ii->s.end(); ++si )
				{
					assert( map.count( si->id ) != 0 );
					out << "\t\t" << map[ si->id ] << "->" 
						<< instructionPrefix.str() << ":rs" << si->id 
						<< "[style = dashed, color = blue];\n";				
				}
				
				out << "\t\t" << instructionPrefix.str() 
					<< "[ label = \"{ phi | { ";
				
				DataflowGraph::RegisterVector::const_iterator 
				 	si = ii->s.begin();
				 	
				out << "<rs" << si->id << "> ";
				out << "rs" << si->id;
				++si;
				for( ; si != ii->s.end(); ++si )
				{
					out << " | ";
					out << "<rs" << si->id << "> ";
					out << "rs" << si->id;
				}
				
				out << " } | { ";
				std::stringstream value;
				value << "rd" << ii->d.id;
				out << "<" << value.str() << "> " << value.str();
				map[ ii->d.id ] = instructionPrefix.str() + ":" + value.str();
				out << " } }\"];\n";
			}
			
			count = 0;
			for( DataflowGraph::InstructionVector::const_iterator 
				ii = block->instructions().begin(); 
				ii != block->instructions().end(); ++ii, ++count )
			{
				std::stringstream instructionPrefix;
				instructionPrefix << "b_" << blockCount << "_instruction" 
					<< ( count + block->phis().size() );

				for( DataflowGraph::RegisterPointerVector::const_iterator 
					si = ii->s.begin(); si != ii->s.end(); ++si )
				{
					assert( map.count( *si->pointer ) != 0 );
					out << "\t\t" << map[ *si->pointer ] << "->" 
						<< instructionPrefix.str() << ":rs" << *si->pointer
						<< "[style = dashed, color = blue];\n";				
				}
				
				out << "\t\t" << instructionPrefix.str() << "[ label = \"{ " 
					<< hydrazine::toGraphVizParsableLabel( ii->label )
					<< " | { ";
				
				bool any = false;
				
				DataflowGraph::RegisterPointerVector::const_iterator 
				 	si = ii->s.begin();
				 	
				if( si != ii->s.end() )
				{
					out << "<rs" << *si->pointer << "> ";
					out << "rs" << *si->pointer;
					any = true;
					++si;
				}
				for( ; si != ii->s.end(); ++si )
				{
					if( any )
					{
						out << " | ";
					}
					out << "<rs" << *si->pointer << "> ";
					out << "rs" << *si->pointer;
					any = true;
				}
				
				DataflowGraph::RegisterPointerVector::const_iterator 
				 	di = ii->d.begin();
				
				if( di != ii->d.end() )
				{
					if( any )
					{
						out << " } | { ";
					}
					std::stringstream value;
					value << "rd" << *di->pointer;
					out << "<" << value.str() << "> " << value.str();
					map[ *di->pointer ] = instructionPrefix.str() 
						+ ":" + value.str();
					++di;
				}
				for( ; di != ii->d.end(); ++di )
				{
					std::stringstream value;
					value << "rd" << *di->pointer;
					out << " | <" << value.str() << "> " << value.str();
					map[ *di->pointer ] = instructionPrefix.str() + ":" 
						+ value.str();
				}
				
				out << " } }\"];\n"; 
			}

			out << "\t\tb_" << blockCount 
				<< "_AliveOut[ shape = record, label = \"{ AliveOut ";

			if( !block->aliveOut().empty() )
			{
				out << " | { ";
				DataflowGraph::Block::RegisterSet::const_iterator 
					ri = block->aliveOut().begin();
				out << "<r" << ri->id << "> ";
				out << "r" << ri->id;
				for( ++ri; ri != block->aliveOut().end(); ++ri )
				{
					out << " | <r" << ri->id << "> "; 
					out << "r" << ri->id << ""; 
				}
				out << " }";
			}
			out << " }\"];\n";
			
			for( DataflowGraph::Block::RegisterSet::const_iterator 
				ri = block->aliveOut().begin(); 
				ri != block->aliveOut().end(); ++ri )
			{
				assert( map.count( ri->id ) != 0 );
				out << "\t\t" << map[ ri->id ] << "->b_" << blockCount 
					<< "_AliveOut" << ":r" << ri->id 
					<< "[ style=dashed, color=blue];\n";
			}

			out << "\t}\n\n";
			out << "\tb_" << blockCount << "_AliveOut->" << "b_" 
				<< std::distance( graph.begin(), 
					DataflowGraph::const_iterator( block->fallthrough() ) )
				<< "_AliveIn[ style = dotted ];\n";
			
			for( DataflowGraph::BlockPointerSet::const_iterator 
				pi = block->targets().begin(); 
				pi != block->targets().end(); ++pi )
			{
				out << "\tb_" << blockCount << "_AliveOut->" << "b_" 
					<< std::distance( graph.begin(), 
					DataflowGraph::const_iterator( *pi ) ) 
					<< "_AliveIn[ color = red ];\n";
			}

		}
		out << "}";

		return out;
	}

}

#endif

