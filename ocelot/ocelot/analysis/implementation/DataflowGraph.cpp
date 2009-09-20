/*!
	\file DataflowGraph.cpp
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Tuesday June 23, 2009
	\file The source file for the DataflowGraph class.
*/

#ifndef DATAFLOW_GRAPH_CPP_INCLUDED
#define DATAFLOW_GRAPH_CPP_INCLUDED

#include <ocelot/analysis/interface/DataflowGraph.h>
#include <ocelot/analysis/interface/SSAGraph.h>
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

	DataflowGraph::Instruction DataflowGraph::convert( 
		ir::PTXInstruction& i, InstructionId id )
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

		for( unsigned int j = 0; j < limit; ++j )
		{
			if( ( i.*sources[ j ] ).addressMode == ir::PTXOperand::Register 
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
			
				if( !( i.*sources[ j ] ).array.empty() )
				{
					for( ir::PTXOperand::Array::iterator 
						fi = ( i.*sources[ j ] ).array.begin(); 
						fi != ( i.*sources[ j ] ).array.end(); ++fi )
					{
						reportE( REPORT_CONVERT, "  Converting register \"" 
							<< fi->identifier 
							<< "\" to id " << fi->reg );
						_maxRegister = std::max( _maxRegister, fi->reg );
						result.s.push_back( 
							RegisterPointer( &fi->reg, fi->type ) );
					}
				}
				else
				{
					reportE( REPORT_CONVERT, "  Converting register \"" 
						<< ( i.*sources[ j ] ).identifier 
						<< "\" to id " << ( i.*sources[ j ] ).reg );
					_maxRegister = std::max( _maxRegister, 
						( i.*sources[ j ] ).reg );
					result.s.push_back( 
						RegisterPointer( &( i.*sources[ j ] ).reg, 
						( i.*sources[ j ] ).type ) );
				}
			}
		}

		ir::PTXOperand ir::PTXInstruction::* destinations[ 2 ] 
			= { &ir::PTXInstruction::pq, &ir::PTXInstruction::d };

		if( ir::PTXInstruction::St == i.opcode )
		{
			limit = 1;
		}
		else
		{
			limit = 2;
		}

		for( unsigned int j = 0; j < limit; ++j )
		{
			if( ( i.*destinations[ j ] ).addressMode 
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
			
				if( !( i.*destinations[ j ] ).array.empty() )
				{
					for( ir::PTXOperand::Array::iterator 
						fi = ( i.*destinations[ j ] ).array.begin(); 
						fi != ( i.*destinations[ j ] ).array.end(); ++fi )
					{
						reportE( REPORT_CONVERT, "  Converting register \"" 
							<< fi->identifier 
							<< "\" to id " << fi->reg );
						_maxRegister = std::max( _maxRegister, fi->reg );
						result.d.push_back( 
							RegisterPointer( &fi->reg, fi->type ) );
					}
				}
				else
				{
					reportE( REPORT_CONVERT, "  Converting register \"" 
						<< ( i.*destinations[ j ] ).identifier 
						<< "\" to id " << ( i.*destinations[ j ] ).reg );
					_maxRegister = std::max( _maxRegister, 
						( i.*destinations[ j ] ).reg );
					result.d.push_back( 
						RegisterPointer( &( i.*destinations[ j ] ).reg, 
						( i.*destinations[ j ] ).type ) );
				}
			}
		}
		
		result.id = id;
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
			if( two.count( *fi ) == 0 ) return false;
		}
		
		return true;
	}

	bool DataflowGraph::Block::compute( bool hasFallthrough )
	{
		if( type() != Body ) return false;
		
		report( " Block name " << _label );
		
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
				_aliveIn.erase( *di );
			}
			
			for( RegisterPointerVector::iterator si = ii->s.begin(); 
				si != ii->s.end(); ++si )
			{
				_aliveIn.insert( *si );
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

	DataflowGraph::Block::Block( Type t ) : _type( t )
	{
		
	}
	
	DataflowGraph::Block::Block( const std::string& name ) : 
		_type( Body ), _label( name )
	{
	
	}
	
	DataflowGraph::Block::Block( ir::BasicBlock& bb )
	{
		assert( bb.instructions.empty() );
		assert( bb.get_successors().empty() );
		assert( bb.get_predecessors().empty() );
		assert( bb.get_in_edges().empty() );
		assert( bb.get_out_edges().empty() );
	
		_block = &bb;
		_label = bb.label;
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
		return _label;
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
		
		return std::move( alive );
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
		const Block& _b )
	{
		_consistent = false;
		assert( _b._phis.empty() );
		assert( _b._instructions.empty() );
		
		BlockVector::iterator successor = predecessor->_fallthrough;

		report( "Inserting new block " << _b.label() << " between " 
			<< predecessor->label() << " and " << successor->label() );
		
		assert( successor != begin() );
		Block b = _b;
		
		BlockPointerSet::iterator fi 
			= successor->_predecessors.find( predecessor );
		assert( fi != successor->_predecessors.end() );
		successor->_predecessors.erase( fi );
		_cfg->remove_edge( predecessor->_block->get_fallthrough_edge() );
		
		iterator current = _blocks.insert( successor, b );
		current->_block = new ir::BasicBlock;
		current->_block->label = b.label();
		_cfg->insert_block( current->_block );
		
		ir::Edge* predecessorToCurrent = new ir::Edge;
		predecessorToCurrent->type = ir::Edge::FallThrough;
		predecessorToCurrent->head = predecessor->_block;
		predecessorToCurrent->tail = current->_block;
		
		_cfg->insert_edge( predecessorToCurrent );
		
		predecessor->_fallthrough = current;
		current->_predecessors.insert( predecessor );
		current->_fallthrough = successor;
		successor->_predecessors.insert( current );
		
		ir::Edge* currentToSuccessor = new ir::Edge;
		currentToSuccessor->type = ir::Edge::FallThrough;
		currentToSuccessor->head = current->_block;
		currentToSuccessor->tail = successor->_block;
		
		_cfg->insert_edge( currentToSuccessor );
		
		return current;
	}
	
	void DataflowGraph::target( iterator block, iterator target )
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
			
			ir::Edge* edge = new ir::Edge;
			
			edge->type = ir::Edge::Branch;
			edge->head = block->_block;
			edge->tail = target->_block;
			
			_cfg->insert_edge( edge );
		}
	}

	DataflowGraph::iterator DataflowGraph::split( iterator block, 
		unsigned int instruction )
	{
		report( "Splitting block " << block->label() 
			<< " at instruction " << instruction );
		_consistent = false;
		
		assert( instruction < block->_instructions.size() );
		
		InstructionVector::iterator begin = block->_instructions.begin();
		std::advance( begin, instruction );
		InstructionVector::iterator end = block->_instructions.end();
		
		iterator added = _blocks.insert( ++iterator( block ), Block() );

		added->_block = _cfg->split_block( block->_block, instruction );
		added->_label = added->_block->label;
		added->_predecessors.insert( block );
		
		added->_instructions.insert( added->_instructions.end(), begin, end );
		block->_instructions.erase( begin, end );
		
		added->_fallthrough = block->_fallthrough;
		block->_fallthrough = added;
		
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
		
		return added;		
	}

	void DataflowGraph::redirect( iterator source, 
		iterator destination, iterator newTarget )
	{
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

		ir::Edge* existingEdge = source->_block->get_edge( 
			destination->_block );

		ir::Edge* edge = new ir::Edge;
		edge->type = ir::Edge::Branch;
		edge->head = source->_block;
		edge->tail = newTarget->_block;

		_cfg->remove_edge( existingEdge );
		_cfg->insert_edge( edge );
	}

	void DataflowGraph::insert( iterator block, 
		const Instruction& instruction, unsigned int index )
	{
		_consistent = false;
		
		InstructionVector::iterator position = block->_instructions.begin();
		std::advance( position, index );
		
		block->_instructions.insert( position, instruction );
		
		ir::BasicBlock::InstructionList::iterator 
			bbPosition = block->_block->instructions.begin();
		std::advance( bbPosition, index );
		
		block->_block->instructions.insert( bbPosition, instruction.id );
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
			
				ir::Edge* edge = new ir::Edge;
				edge->type = ir::Edge::FallThrough;
				edge->head = (*pi)->_block;
				edge->tail = fallthrough->_block;
				
				_cfg->insert_edge( edge );
			}

			BlockPointerSet::iterator target 
				= (*pi)->_targets.find( block );

			if( target != (*pi)->_targets.end() )
			{
				(*pi)->_targets.erase( target );
				(*pi)->_targets.insert( fallthrough );
				
				ir::Edge* edge = new ir::Edge;
				edge->type = ir::Edge::Branch;
				edge->head = (*pi)->_block;
				edge->tail = fallthrough->_block;
			
				_cfg->insert_edge( edge );
			}
		}
		
		_cfg->remove_block( block->_block );
		
		return fallthrough;
	}

	void DataflowGraph::clear()
	{
		_consistent = true;
		_blocks.clear();
		_blocks.push_back( Block( Block::Entry ) );
		_blocks.push_back( Block( Block::Exit ) );
		
		_cfg->clear();
		
		_blocks.front()._fallthrough = --_blocks.end();
		_blocks.front()._label = "entry";
		_blocks.front()._block = _cfg->get_entry_block();
		_blocks.back()._predecessors.insert( _blocks.begin() );
		_blocks.back()._fallthrough = end();
		_blocks.back()._label = "exit";
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
		compute();
		SSAGraph graph( *this );
		graph.fromSsa();		
	}
	
	bool DataflowGraph::ssa() const
	{
		return _ssa;
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
			
			for( DataflowGraph::PhiInstructionVector::const_iterator 
				ii = block->phis().begin(); 
				ii != block->phis().end(); ++ii )
			{
				std::stringstream instructionPrefix;
				instructionPrefix << "b_" << blockCount << "_instruction" 
					<< ( ii - block->phis().begin() );

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
			
			for( DataflowGraph::InstructionVector::const_iterator 
				ii = block->instructions().begin(); 
				ii != block->instructions().end(); ++ii )
			{
				std::stringstream instructionPrefix;
				instructionPrefix << "b_" << blockCount << "_instruction" 
					<< ( ii - block->instructions().begin() 
					+ block->phis().size() );

				for( DataflowGraph::RegisterPointerVector::const_iterator 
					si = ii->s.begin(); si != ii->s.end(); ++si )
				{
					assert( map.count( *si->pointer ) != 0 );
					out << "\t\t" << map[ *si->pointer ] << "->" 
						<< instructionPrefix.str() << ":rs" << *si->pointer
						<< "[style = dashed, color = blue];\n";				
				}
				
				out << "\t\t" << instructionPrefix.str() << "[ label = \"{ " 
					<< ir::ControlFlowGraph::make_label_dot_friendly( 
					ii->label ) << " | { ";
				
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
				for( ++ri; ri != block->aliveIn().end(); ++ri )
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

