/*!
	\file PTXKernel.cpp
	\author Gregory Diamos <gregory.diamos@gatech>
	\date Thursday September 17, 2009
	\brief The header file for the PTXKernel class
*/

#ifndef PTX_KERNEL_H_INCLUDED
#define PTX_KERNEL_H_INCLUDED

#include <ocelot/ir/interface/PTXKernel.h>
#include <ocelot/analysis/interface/DataflowGraph.h>
#include <ocelot/ir/interface/ControlFlowGraph.h>

#include <hydrazine/interface/Version.h>
#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace ir
{
	PTXKernel::PTXKernel( PTXStatementVector::const_iterator start,
		PTXStatementVector::const_iterator end): Kernel( Instruction::PTX ), 
		_version( start->version )
	{
		// get parameters/locals, extract kernel name
		for( PTXStatementVector::const_iterator it = start; it != end; ++it ) 
		{
			if( (*it).directive == PTXStatement::Param )
			{
				parameters.push_back( Parameter( *it ) );
			}
			else if( (*it).directive == PTXStatement::Local
				|| (*it).directive == PTXStatement::Shared )
			{
				locals.insert( std::make_pair( ( *it ).name, Local( *it ) ) );
			}
			else if( (*it).directive == PTXStatement::Entry )
			{
				name = (*it).name;
			}
		}
		_cfg = new ControlFlowGraph;
		constructCFG( *_cfg, instructions, start, end );
	}

	PTXKernel::PTXKernel( const PTXKernel& kernel ) : Kernel( kernel ), 
		_version( kernel._version ), instructions( kernel.instructions )
	{
		
	}

	const PTXKernel& PTXKernel::operator=(const PTXKernel &kernel) 
	{
		if( &kernel == this ) return *this;
		
		Kernel::operator=(kernel);
		
		_version = kernel._version;
		instructions = kernel.instructions;
		
		return *this;	
	}

	PTXInstruction::Version PTXKernel::version() const 
	{
		return _version;
	}

	analysis::DataflowGraph* PTXKernel::dfg() 
	{
		assertM(_cfg != 0, "Must create cfg before building dfg.");
		if(_dfg) return _dfg;
		_dfg = new analysis::DataflowGraph( *_cfg, instructions );
		return _dfg;
	}

	bool PTXKernel::executable() const {
		return false;
	}

	void PTXKernel::constructCFG( ControlFlowGraph &cfg,
		PTXInstructionVector &instructions,
		PTXStatementVector::const_iterator kernelStart,
		PTXStatementVector::const_iterator kernelEnd) 
	{
		
		typedef std::unordered_map< std::string, 
			BasicBlock* > BlockToLabelMap;
		typedef std::vector< BasicBlock* > BlockPointerVector;
	
		BlockToLabelMap blocksByLabel;
		BlockPointerVector branchBlocks;

		BasicBlock* last_inserted_block = 0;
		BasicBlock* block = new BasicBlock;
		Edge* edge = new Edge;
		edge->head = cfg.get_entry_block();
		edge->tail = block;
		edge->type = Edge::FallThrough;
	
		for( ; kernelStart != kernelEnd; ++kernelStart ) 
		{
			const PTXStatement &statement = *kernelStart;
		
			if( statement.directive == PTXStatement::Label ) 
			{
				// a label indicates the termination of a previous block
				//
				// This implementation of CFG does not store any empty basic blocks.
				if( block->instructions.size() ) {
					//
					// insert old block
					//
					cfg.insert_block( last_inserted_block = block );
					if( edge ) 
					{
						cfg.insert_edge(edge);
					}
				
					edge = new Edge;
					edge->head = block;
					block = new BasicBlock;
					edge->tail = block;
					edge->type = Edge::FallThrough;
				}
				else 
				{

				}
				block->label = statement.name;
				assertM( blocksByLabel.count( block->label ) == 0, 
					"Duplicate blocks with label " << block->label )
				blocksByLabel.insert( std::make_pair( block->label, block ) );
			}
			else if( statement.directive == PTXStatement::Instr ) 
			{
				block->instructions.push_back( ( int ) instructions.size() );
				instructions.push_back( statement.instruction );

				if (statement.instruction.opcode == PTXInstruction::Bra) 
				{
					cfg.insert_block(last_inserted_block = block);
					if (edge) {
						cfg.insert_edge(edge);
					}
					edge = new Edge;
					edge->head = block;
					branchBlocks.push_back(block);

					block = new BasicBlock;
					edge->tail = block;
					edge->type = Edge::FallThrough;
				}
				else if( statement.instruction.opcode == PTXInstruction::Exit )
				{
					cfg.insert_block( last_inserted_block = block );
					cfg.insert_edge( edge );
					edge = new Edge;
					edge->head = block;
					edge->tail = cfg.get_exit_block();
					edge->type = Edge::FallThrough;
					cfg.insert_edge( edge );

					block = new BasicBlock;
					edge = 0;
				}
				else if( statement.instruction.opcode == PTXInstruction::Call )
				{
					assertM(false, "Unhandled control flow instruction call");
				}
				else if( statement.instruction.opcode == PTXInstruction::Ret )
				{
					assertM(false, "Unhandled control flow instruction ret");
				}
				else 
				{
					// any special handling with respect to control flow?
				}
			}
		}

		if (block->instructions.size()) 
		{
			cfg.insert_block(block);
			if (edge) 
			{
				cfg.insert_edge(edge);
			}
			edge = new Edge;
			edge->head = block;
			edge->tail = cfg.get_exit_block();
			edge->type = Edge::FallThrough;
			cfg.insert_edge(edge);
		}
		else 
		{
			if( last_inserted_block ) 
			{
				// make sure there is a fall through edge from the last 
				// inserted block to the exit node
				BasicBlock::EdgeList out_edges 
					= last_inserted_block->get_out_edges();
				Edge *ft_e = 0;
				for( BasicBlock::EdgeList::iterator it = out_edges.begin(); 
					it != out_edges.end(); ++it )
				{
					if( (*it)->type == Edge::FallThrough 
						&& (*it)->tail == cfg.get_exit_block() )
					{
						ft_e = (*it);
						break;
					}
				}
				if( !ft_e )
				{
					Edge *edge = new Edge;
					edge->type = Edge::FallThrough;
					edge->head = last_inserted_block;
					edge->tail = cfg.get_exit_block();
					cfg.insert_edge(edge);
				}
			}
			delete block;
			if( edge )
			{
				delete edge;
			}
		}

		// go back and add edges for basic blocks terminating in branches
		for( BlockPointerVector::iterator it = branchBlocks.begin();
			it != branchBlocks.end(); ++it ) 
		{
			PTXInstruction bra = instructions[ (*it)->instructions.back() ];
			BlockToLabelMap::iterator labeledBlockIt = 
				blocksByLabel.find( bra.d.identifier );
		
			if( labeledBlockIt != blocksByLabel.end() ) 
			{
				Edge *edge = new Edge;
				edge->head = *it;
				edge->tail = labeledBlockIt->second;
				edge->type = Edge::Branch;
				cfg.insert_edge(edge);
			}
			else 
			{
				assertM(false, "undefined label " << bra.d.identifier);
			}
		}
	}

	PTXKernel::RegisterMap PTXKernel::assignRegisters( 
		PTXInstructionVector& instructions ) 
	{
		RegisterMap map;
	
		report( "Allocating registers" );
	
		for( PTXInstructionVector::iterator i_it = instructions.begin();
			i_it != instructions.end(); ++i_it ) 
		{
			PTXInstruction & instr = *i_it;
			PTXOperand PTXInstruction:: * operands[] = 
			{ &PTXInstruction::a, &PTXInstruction::b, &PTXInstruction::c, 
				&PTXInstruction::d, &PTXInstruction::pg, &PTXInstruction::pq };
		
			report( " For instruction '" << instr.toString() << "'" );
		
			for(int i = 0; i < 6; i++) 
			{
				if( (instr.*operands[ i ]).addressMode == PTXOperand::Invalid ) 
				{
					continue;
				}
				if( ( instr.*operands[ i ] ).type == PTXOperand::pred
					&& ( instr.*operands[ i ]).condition == PTXOperand::PT ) 
				{
					continue;
				}
				if( ( instr.*operands[ i ] ).addressMode == PTXOperand::Register
					|| ( instr.*operands[ i ] ).addressMode 
					== PTXOperand::Indirect )  
				{
					if( ( instr.*operands[ i ] ).vec != PTXOperand::v1 ) 
					{
						for( PTXOperand::Array::iterator 
							a_it = ( instr.*operands[ i ] ).array.begin(); 
							a_it != ( instr.*operands[ i ] ).array.end(); 
							++a_it ) 
						{
							RegisterMap::iterator it 
								= map.find( a_it->identifier );

							PTXOperand::RegisterType reg = 0;
							if( it == map.end() ) 
							{
								reg = ( PTXOperand::RegisterType ) map.size();
								map.insert( std::make_pair( 
									a_it->identifier, reg ) );
							}
							else 
							{
								reg = it->second;
							}
							a_it->reg = reg;
							report( "  Assigning register " << a_it->identifier 
								<< " to " << a_it->reg );
						}
					}
					RegisterMap::iterator it 
						= map.find( ( instr.*operands[ i ] ).identifier);

					PTXOperand::RegisterType reg = 0;
					if( it == map.end() ) 
					{
						reg = ( PTXOperand::RegisterType ) map.size();
						map.insert( std::make_pair( 
							( instr.*operands[i] ).identifier, reg ) );
					}
					else 
					{
						reg = it->second;
					}
					( instr.*operands[ i ] ).reg = reg;
					report( "  Assigning register " 
						<< ( instr.*operands[ i ] ).identifier 
						<< " to " << reg );
				}
			}
		}
		return std::move( map );
	}

	void PTXKernel::write(std::ostream& stream) const 
	{
		stream << "/*\n* Ocelot Version : " 
			<< hydrazine::Version().toString() << "\n";
		stream << "*/\n";
	
		assertM( false, "Write PTXKernel to stream not implemented" );
	}

}

#endif

