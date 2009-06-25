/*!
	\file DataflowGraph.cpp
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Tuesday June 23, 2009
	\file The source file for the DataflowGraph class.
*/

#ifndef DATAFLOW_GRAPH_CPP_INCLUDED
#define DATAFLOW_GRAPH_CPP_INCLUDED

#include <ocelot/analysis/interface/DataflowGraph.h>
#include <unordered_map>

namespace analysis
{

	DataflowGraph::Instruction DataflowGraph::_convert( 
		const ir::PTXInstruction& i, InstructionId id )
	{
		Instruction result;
	
		unsigned int inputs = 0;
		unsigned int outputs = 0;

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
					for( ir::PTXOperand::Array::const_iterator 
						fi = ( i.*sources[ j ] ).array.begin(); 
						fi != ( i.*sources[ j ] ).array.end(); ++fi )
					{
						assert( inputs < MAX_INSTRUCTION_INPUTS );
						result.s[ inputs++ ] = fi->reg;
					}
				}
				else
				{
					assert( inputs < MAX_INSTRUCTION_INPUTS );
					result.s[ inputs++ ] = ( i.*sources[ j ] ).reg;
				}
			}
		}

		ir::PTXOperand ir::PTXInstruction::* destinations[ 2 ] 
			= { &ir::PTXInstruction::pq, &ir::PTXInstruction::d };

		limit = 2;
		
		if( ir::PTXInstruction::St == i.opcode )
		{
			limit = 1;
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
					for( ir::PTXOperand::Array::const_iterator 
						fi = ( i.*destinations[ j ] ).array.begin(); 
						fi != ( i.*destinations[ j ] ).array.end(); ++fi )
					{
						assert( outputs < MAX_INSTRUCTION_OUTPUTS );
						result.d[ outputs++ ] = fi->reg;
					}
				}
				else
				{
					assert( outputs < MAX_INSTRUCTION_OUTPUTS );
					result.d[ outputs++ ] = ( i.*destinations[ j ] ).reg;
				}
			}
		}

		for( ; outputs < MAX_INSTRUCTION_OUTPUTS; ++outputs )
		{
			result.d[ outputs ] = INVALID_REGISTER;
		}

		for( ; inputs < MAX_INSTRUCTION_INPUTS; ++inputs )
		{
			result.s[ inputs ] = INVALID_REGISTER;
		}
		
		result.id = id;
		result.label = i.toString();
		
		return result;
	}

	bool DataflowGraph::Block::_equal( const RegisterIdSet& one, 
		const RegisterIdSet& two )
	{
		if( one.size() != two.size() ) return false;
		
		for( RegisterIdSet::const_iterator fi = one.begin(); 
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
		
		RegisterIdSet previousIn = std::move( _aliveIn );
		assert( _aliveIn.empty() );
		
		report( "  Scanning targets: " );
		report( "   " << _fallthrough->label() );		
		_aliveOut = _fallthrough->_aliveIn;
		
		for( BlockPointerSet::iterator bi = _targets.begin(); 
			bi != _targets.end(); ++bi )
		{
			report( "   " << (*bi)->label() );		
			for( RegisterIdSet::iterator ri = (*bi)->_aliveIn.begin(); 
				ri != (*bi)->_aliveIn.end(); ++ri )
			{
				_aliveOut.insert( *ri );
			}
		}
		
		_aliveIn = _aliveOut;
		
		for( InstructionVector::reverse_iterator ii = _instructions.rbegin(); 
			ii != _instructions.rend(); ++ii )
		{
			for( unsigned int d = 0; d < MAX_INSTRUCTION_OUTPUTS; ++d )
			{
				if( ii->d[ d ] != INVALID_REGISTER )
				{
					_aliveIn.erase( ii->d[ d ] );
				}
			}

			for( unsigned int s = 0; s < MAX_INSTRUCTION_INPUTS; ++s )
			{
				if( ii->s[ s ] != INVALID_REGISTER )
				{
					_aliveIn.insert( ii->s[ s ] );
				}
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
	
	const DataflowGraph::Block::RegisterIdSet& 
		DataflowGraph::Block::aliveIn() const
	{
		return _aliveIn;
	}
	
	const DataflowGraph::Block::RegisterIdSet& 
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

	const std::string& DataflowGraph::Block::label() const
	{
		return _label;
	}
		
	DataflowGraph::DataflowGraph() : _consistent( true )
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
				DataflowGraph::Block::RegisterIdSet::const_iterator 
					ri = block->aliveIn().begin();
				std::stringstream value;
				value << "r" << *ri;
				out << "<" << value.str() << "> " << value.str();
				map[ *ri ] = aliveInPrefix.str() + ":" + value.str();
				for( ++ri; ri != block->aliveIn().end(); ++ri )
				{
					std::stringstream stream;
					stream << "r" << *ri;
					out << " | <" << stream.str() << "> " << stream.str();
					map[ *ri ] = aliveInPrefix.str() + ":" + stream.str();
				}
				out << " }";
			}
			out << " }\"];\n";

			for( DataflowGraph::InstructionVector::const_iterator 
				ii = block->instructions().begin(); 
				ii != block->instructions().end(); ++ii )
			{
				std::stringstream instructionPrefix;
				instructionPrefix << "b_" << blockCount << "_instruction" 
					<< ( ii - block->instructions().begin() );

				for( unsigned int s = 0; s < MAX_INSTRUCTION_INPUTS; ++s )
				{
					if( ii->s[ s ] != INVALID_REGISTER )
					{
						assert( map.count( ii->s[ s ] ) != 0 );
						out << "\t\t" << map[ ii->s[ s ] ] << "->" 
							<< instructionPrefix.str() << ":rs" << ii->s[ s ] 
							<< "[style = dashed, color = blue];\n";
					}
				}
				
				out << "\t\t" << instructionPrefix.str() << "[ label = \"{ " 
					<< ir::ControlFlowGraph::make_label_dot_friendly( 
					ii->label ) << " | { ";
				
				bool any = false;
				if( ii->s[ 0 ] != INVALID_REGISTER )
				{
					out << "<rs" << ii->s[ 0 ] << "> ";
					out << "rs" << ii->s[ 0 ];
					any = true;
				}
				for( unsigned int s = 1; s < MAX_INSTRUCTION_INPUTS; ++s )
				{
					if( ii->s[ s ] != INVALID_REGISTER )
					{
						if( any )
						{
							out << " | ";
						}
						out << "<rs" << ii->s[ s ] << "> ";
						out << "rs" << ii->s[ s ];
						any = true;
					}
				}
				
				if( ii->d[ 0 ] != INVALID_REGISTER )
				{
					if( any )
					{
						out << " } | { ";
					}
					std::stringstream value;
					value << "rd" << ii->d[ 0 ];
					out << "<" << value.str() << "> " << value.str();
					map[ ii->d[ 0 ] ] = instructionPrefix.str() 
						+ ":" + value.str();
				}
				for( unsigned int d = 1; d < MAX_INSTRUCTION_OUTPUTS; ++d )
				{
					if( ii->d[ d ] != INVALID_REGISTER )
					{
						std::stringstream value;
						value << "rd" << ii->d[ d ];
						out << " | <" << value.str() << "> " << value.str();
						map[ ii->d[ d ] ] = instructionPrefix.str() + ":" 
							+ value.str();
					}
				}
				
				out << " } }\"];\n"; 
			}

			out << "\t\tb_" << blockCount 
				<< "_AliveOut[ shape = record, label = \"{ AliveOut ";

			if( !block->aliveOut().empty() )
			{
				out << " | { ";
				DataflowGraph::Block::RegisterIdSet::const_iterator 
					ri = block->aliveOut().begin();
				out << "<r" << *ri << "> ";
				out << "r" << *ri;
				for( ++ri; ri != block->aliveIn().end(); ++ri )
				{
					out << " | <r" << *ri << "> "; 
					out << "r" << *ri << ""; 
				}
				out << " }";
			}
			out << " }\"];\n";
			
			for( DataflowGraph::Block::RegisterIdSet::const_iterator 
				ri = block->aliveOut().begin(); 
				ri != block->aliveOut().end(); ++ri )
			{
				assert( map.count( *ri ) != 0 );
				out << "\t\t" << map[ *ri ] << "->b_" << blockCount 
					<< "_AliveOut" << ":r" << *ri 
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

