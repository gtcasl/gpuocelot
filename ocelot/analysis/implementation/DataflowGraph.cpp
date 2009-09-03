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

	DataflowGraph::Instruction DataflowGraph::_convert( 
		ir::PTXInstruction& i, InstructionId id )
	{
		Instruction result;
	
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
						result.s.push_back( 
							RegisterPointer( &fi->reg, fi->type ) );
					}
				}
				else
				{
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
						result.d.push_back( 
							RegisterPointer( &fi->reg, fi->type ) );
					}
				}
				else
				{
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

	bool DataflowGraph::Block::compute()
	{
		if( type() != Body ) return false;
		
		report( " Block name " << _label );
		
		RegisterSet previousIn = std::move( _aliveIn );
		assert( _aliveIn.empty() );
		
		report( "  Scanning targets: " );
		report( "   " << _fallthrough->label() );		
		_aliveOut = _fallthrough->_aliveIn;
		
		for( BlockPointerSet::iterator bi = _targets.begin(); 
			bi != _targets.end(); ++bi )
		{
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
		
		return !_equal( _aliveIn, previousIn );
	}

	DataflowGraph::Block::Block( Type type ) : _type( type )
	{
		
	}
	
	DataflowGraph::Block::Block() : _type( Invalid )
	{
		
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
	
	DataflowGraph::DataflowGraph() : _consistent( true ), _ssa( false )
	{
		_blocks.push_back( Block( Block::Entry ) );
		_blocks.push_back( Block( Block::Exit ) );
		
		_blocks.front()._fallthrough = --_blocks.end();
		_blocks.front()._label = "entry";
		_blocks.back()._predecessors.insert( _blocks.begin() );
		_blocks.back()._fallthrough = end();
		_blocks.back()._label = "exit";
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
		BlockVector::iterator successor = predecessor->_fallthrough;

		assert( successor != begin() );
		Block b = _b;
		
		b._fallthrough = successor;
		
		BlockPointerSet::iterator fi 
			= successor->_predecessors.find( predecessor );
		assert( fi != successor->_predecessors.end() );
		successor->_predecessors.erase( fi );
		
		iterator current = _blocks.insert( successor, b );
		
		predecessor->_fallthrough = current;
		successor->_predecessors.insert( current );
		
		return current;
	}
	
	void DataflowGraph::target( iterator block, iterator target )
	{
		_consistent = false;
		std::pair< BlockPointerSet::iterator, bool > insertion 
			= block->_targets.insert( target );
		
		if( insertion.second )
		{
			assert( target->_predecessors.count( block ) == 0 );
			target->_predecessors.insert( block );
		}
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
			}

			BlockPointerSet::iterator target 
				= (*pi)->_targets.find( block );

			if( target != (*pi)->_targets.end() )
			{
				(*pi)->_targets.erase( target );
				(*pi)->_targets.insert( fallthrough );
			}
		}
		
		return _blocks.erase( block );
	}

	void DataflowGraph::clear()
	{
		_consistent = true;
		_blocks.clear();
		_blocks.push_back( Block( Block::Entry ) );
		_blocks.push_back( Block( Block::Exit ) );

		_blocks.front()._fallthrough = --_blocks.end();
		_blocks.front()._label = "entry";
		_blocks.back()._predecessors.insert( _blocks.begin() );
		_blocks.back()._fallthrough = end();
		_blocks.back()._label = "exit";
	}
	
	void DataflowGraph::compute()
	{
		if( _consistent ) return;		
		_consistent = true;
				
		BlockPointerSet worklist;
		
		for( iterator fi = begin(); fi != end(); ++fi )
		{
			if( !fi->instructions().empty() )
			{
				worklist.insert( fi );
			}
		}
		
		while( !worklist.empty() )
		{
			iterator block = *worklist.begin();
			worklist.erase( worklist.begin() );
			
			report( "Running dataflow for basic block " << block->label() );
			bool changed = block->compute();
			
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

