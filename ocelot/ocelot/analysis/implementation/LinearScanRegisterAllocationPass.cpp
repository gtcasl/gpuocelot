/*! \file LinearScanRegisterAllocationPass.cpp
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date Monday December 28, 2009
	\brief The source file for the LinearScanRegisterAllocationPass class.
*/

#ifndef LINEAR_SCAN_REGISTER_ALLOCATION_PASS_CPP_INCLUDED
#define LINEAR_SCAN_REGISTER_ALLOCATION_PASS_CPP_INCLUDED

#include <ocelot/analysis/interface/LinearScanRegisterAllocationPass.h>
#include <ocelot/ir/interface/Module.h>

#include <stack>
#include <algorithm>

#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE 
#endif

#define REPORT_BASE 0

namespace analysis
{

	LinearScanRegisterAllocationPass::CoalescedRegister::CoalescedRegister() 
		: offset( 0 )
	{
	
	}
	
	void LinearScanRegisterAllocationPass::_coalesce()
	{
		typedef std::unordered_map< RegisterId, DataflowGraph::Type > TypeMap;
		typedef std::vector< RegisterId > Connections;
		typedef std::unordered_map< RegisterId, Connections > Graph;
		typedef std::unordered_set< RegisterId > RegisterSet;
		typedef std::vector< RegisterId > RegisterVector;
		typedef std::stack< RegisterId > Stack;
		
		report( " Coalescing SSA registers into single values." );
		
		Graph graph;
		TypeMap types;
		_reserved = 0;
		
		for( DataflowGraph::iterator block = _kernel->dfg()->begin(); 
			block != _kernel->dfg()->end(); ++block )
		{
			for( DataflowGraph::PhiInstructionVector::const_iterator 
				phi = block->phis().begin(); phi != block->phis().end(); 
				++phi )
			{
				graph[ phi->d.id ].push_back( phi->d.id );
				report( "  " << phi->d.id << " <- " << phi->d.id );
				for( DataflowGraph::RegisterVector::const_iterator 
					r = phi->s.begin(); r != phi->s.end(); ++r )
				{
					graph[ phi->d.id ].push_back( r->id );
					graph[ r->id ].push_back( phi->d.id );
					report( "  " << phi->d.id << " <- " << r->id );
					types[ r->id ] = r->type;
				}
			}
			
			for( DataflowGraph::InstructionVector::const_iterator 
				i = block->instructions().begin(); 
				i != block->instructions().end(); ++i )
			{
				for( DataflowGraph::RegisterPointerVector::const_iterator 
					d = i->d.begin(); d != i->d.end(); ++d )
				{
					graph[ *d->pointer ].push_back( *d->pointer );
					report( "  " << *d->pointer << " <- " << *d->pointer );
					types[ *d->pointer ] = d->type;
				}
				_reserved = std::max((size_t) _reserved, i->d.size() );
				_reserved = std::max((size_t) _reserved, i->s.size() );
			}
		}
		
		RegisterSet allocated;
		
		for( Graph::iterator node = graph.begin(); node != graph.end(); ++node )
		{
			if( allocated.insert( node->first ).second )
			{
				report( "  Examining node " << node->first 
					<< " it is connected to: " );
				
				RegisterVector vector( 1, node->first );
				Stack stack;
				stack.push( node->first );
				
				while( !stack.empty() )
				{
					Graph::iterator next = graph.find( stack.top() );
					assert( next != graph.end() );
					stack.pop();
					
					for( Connections::iterator 
						connection = next->second.begin(); 
						connection != next->second.end(); ++connection )
					{
						if( allocated.insert( *connection ).second )
						{
							report( "   " << *connection );
							stack.push( *connection );
							vector.push_back( *connection );
						}
					}
				}
				
				for( RegisterVector::iterator r = vector.begin(); 
					r != vector.end(); ++r )
				{
					_ssa.insert( std::make_pair( *r, _coalesced.size() ) );
				}
				
				_coalesced.resize( _coalesced.size() + 1 );
				_coalesced.back().reg = _coalesced.size() - 1;				
				_coalesced.back().type = types[ vector.front() ];
			}
		}
	}

	void LinearScanRegisterAllocationPass::_computeIntervals()
	{
		typedef std::unordered_set< RegisterId > RegisterSet;
		report( "Computing live intervals." );
		
		_sequence = _kernel->dfg()->executableSequence();
		
		unsigned int count = 0;
		for( DataflowGraph::pointer_iterator block = _sequence.begin(); 
			block != _sequence.end(); ++block )
		{
			for( DataflowGraph::InstructionVector::const_iterator 
				instruction = (*block)->instructions().begin(); 
				instruction != (*block)->instructions().end(); 
				++instruction, ++count )
			{
				for( DataflowGraph::RegisterPointerVector::const_iterator 
					d = instruction->d.begin(); d != instruction->d.end(); ++d )
				{
					CoalescedRegisterMap::iterator 
						index = _ssa.find( *d->pointer );
					assert( index != _ssa.end() );
					assert( index->second < _coalesced.size() );
					_intervals.insert( std::make_pair( count, index->second ) );
					_coalesced[ index->second ].interval.begin = count;
				}
			}
		}
		
		RegisterSet encountered;
		
		for( DataflowGraph::reverse_pointer_iterator block = _sequence.rbegin(); 
			block != _sequence.rend(); ++block )
		{
			for( DataflowGraph::InstructionVector::const_reverse_iterator 
				instruction = (*block)->instructions().rbegin(); 
				instruction != (*block)->instructions().rend(); 
				++instruction, --count )
			{
				for( DataflowGraph::RegisterPointerVector::const_reverse_iterator 
					s = instruction->s.rbegin(); 
					s != instruction->s.rend(); ++s )
				{
					CoalescedRegisterMap::iterator 
						index = _ssa.find( *s->pointer );
					assert( index != _ssa.end() );
					assert( index->second < _coalesced.size() );
					if( encountered.insert( index->second ).second )
					{
						_coalesced[ index->second ].interval.end = count;
					}
				}
			}
		}
	}

	void LinearScanRegisterAllocationPass::_allocate()
	{
		typedef std::multimap< unsigned int, unsigned int > RegisterMap;
		typedef std::stack< RegisterId > RegisterStack;
		
		RegisterStack available;
		RegisterMap active;
		
		report( "Allocating registers, " << registers << " total, " 
			<< _reserved << " reserved" );

		assert( _reserved <= registers );
		
		_bytes = 0;
		
		if( registers == _reserved )
		{
			report( "Spilling everything!" );
			for( SortedRegisterMap::iterator interval = _intervals.begin(); 
				interval != _intervals.end(); ++interval )
			{
				CoalescedRegister& current = _coalesced[ interval->second ];
				report(" Spilling register " << current.reg 
					<< ", interval (" << current.interval.begin << ", " 
					<< current.interval.end << ")" );
				current.spilled = true;
				current.offset = _bytes;
				_bytes += ir::PTXOperand::bytes( current.type );			
			}
			
			return;
		}
		
		report( "These registers are availabale: " );
		
		for( RegisterId r = 0; r != registers - _reserved; ++r )
		{
			report( " " << r );
			available.push( r );
		}
		
		report( "Checking intervals:" );
		
		for( SortedRegisterMap::iterator interval = _intervals.begin(); 
			interval != _intervals.end(); ++interval )
		{
			CoalescedRegister& current = _coalesced[ interval->second ];
			report(" Checking register " << current.reg 
				<< ", interval (" << current.interval.begin << ", " 
				<< current.interval.end << ")" );
			
			report( " Checking for expired intervals" );
			for( RegisterMap::iterator a = active.begin(); a != active.end(); )
			{
				report( "  Checking endpoint " << a->first );
				if( a->first >= current.interval.begin ) break;
				report( "   Register " << _coalesced[ a->second ].reg 
					<< " expired." );
				available.push( _coalesced[ a->second ].allocated );
				report( "    Freeing physical register " 
					<< _coalesced[ a->second ].allocated );
				
				RegisterMap::iterator current = a; ++a;
				active.erase( current );
			}
			
			report( " Checking for spills." );
			if( active.size() == registers - _reserved )
			{
				report( "  Out of free registers, spill required." );
				RegisterMap::iterator _spilled = active.begin();
				++_spills;
				CoalescedRegister& spilled = _coalesced[ _spilled->second ];
				report( "   Comparing " << current.reg 
					<< " (" << current.interval.end 
					<< ") with longest interval " << spilled.reg << " (" 
					<< spilled.interval.end << ")" );
				if( spilled.interval.end > current.interval.end )
				{
					report( "   Spilled " << spilled.reg 
						<< " assigning physical register " 
						<< spilled.allocated << " to current register " 
						<< current.reg );
					current.allocated = spilled.allocated;
					spilled.spilled = true;
					spilled.offset = _bytes;
					_bytes += ir::PTXOperand::bytes( spilled.type );
					active.erase( _spilled );
					active.insert( std::make_pair( current.interval.end, 
						interval->second ) );
				}
				else
				{
					report( "   Spilled " << current.reg );
					current.spilled = true;
					current.offset = _bytes;
					_bytes += ir::PTXOperand::bytes( current.type );
				}
			}
			else
			{
				assert(!available.empty());
				current.spilled = false;
				current.allocated = available.top();
				report( "  No spills, assigning physical register " 
					<< current.allocated << " to current register " 
					<< current.reg );
				available.pop();
				active.insert( std::make_pair( current.interval.end, 
					interval->second ) );
			}
		}
	}

	void LinearScanRegisterAllocationPass::_spill()
	{
		report( "Inserting spill code" );
		for( DataflowGraph::iterator block = _kernel->dfg()->begin(); 
			block != _kernel->dfg()->end(); ++block )
		{
			for( DataflowGraph::InstructionVector::const_iterator 
				i = block->instructions().begin(); 
				i != block->instructions().end(); ++i )
			{
				RegisterId temp = _kernel->dfg()->newRegister();
				unsigned int index = std::distance( 
					block->instructions().begin(), i );
				report( " For instruction " << i->i->toString() );
				
				for( DataflowGraph::RegisterPointerVector::const_iterator 
					s = i->s.begin(); s != i->s.end(); ++s )
				{
					CoalescedRegisterMap::iterator 
						mapping = _ssa.find( *s->pointer );
					assert( mapping != _ssa.end() );
					
					CoalescedRegister& coalesced 
						= _coalesced[ mapping->second ];

					report( "  Register " << coalesced.reg );
					if( coalesced.spilled )
					{
						report( "   Was spilled, inserting fill code." );
						ir::PTXInstruction load( ir::PTXInstruction::Ld );
						*s->pointer = temp;
						load.type = coalesced.type;
						load.addressSpace = ir::PTXInstruction::Local;
						load.a = ir::PTXOperand( ir::PTXOperand::Address, 
							coalesced.type, 0, coalesced.offset );
						load.a.identifier =
							"_Zocelot_linear_scan_register_allocation_stack";
						load.d = ir::PTXOperand( ir::PTXOperand::Register, 
							coalesced.type, temp );
						report( "    " << load.toString() );
						_kernel->dfg()->insert( block, load, index );
						++index;
						++temp;
					}
					else
					{
						report( "   No spill required, assigning to " 
							<< coalesced.allocated );
					}
				}

				unsigned int count = 0;
				for( DataflowGraph::RegisterPointerVector::const_iterator 
					d = i->d.begin(); d != i->d.end(); ++d )
				{
					CoalescedRegisterMap::iterator 
						mapping = _ssa.find( *d->pointer );
					assert( mapping != _ssa.end() );
					assert( mapping->second < _coalesced.size() );
					CoalescedRegister& coalesced 
						= _coalesced[ mapping->second ];
					report( "  Register " << coalesced.reg );
					if( coalesced.spilled )
					{
						report( "   Was spilled, inserting spill code." );
						*d->pointer = temp;
						ir::PTXInstruction store( ir::PTXInstruction::St );
						store.type = coalesced.type;
						store.addressSpace = ir::PTXInstruction::Local;
						store.d = ir::PTXOperand( ir::PTXOperand::Address, 
							coalesced.type, coalesced.allocated, 
							coalesced.offset );
						store.d.identifier = 
							"_Zocelot_linear_scan_register_allocation_stack";
						store.a = ir::PTXOperand( ir::PTXOperand::Register, 
							coalesced.type, temp );
						report( "    " << store.toString() );
						_kernel->dfg()->insert( block, store, index + 1 );
						++count;
						++temp;
					}
					else
					{
						report( "   No spill required, assigning to " 
							<< coalesced.allocated );
					}
				}

				std::advance( i, count );

				report( "  Modified instruction to " << i->i->toString() );
			}
		}
	}

	void LinearScanRegisterAllocationPass::_extendStack()
	{
		if( _bytes == 0 ) return;
		ir::PTXStatement stack( ir::PTXStatement::Local );
		
		stack.type = ir::PTXOperand::u8;
		stack.name = "_Zocelot_linear_scan_register_allocation_stack";
		stack.array.stride.push_back( _bytes );
		
		_kernel->locals.insert( std::make_pair( stack.name,
			ir::Local( stack ) ) );
	}

	LinearScanRegisterAllocationPass::LinearScanRegisterAllocationPass( 
		unsigned int regs )
		: KernelPass( DataflowGraphAnalysis | StaticSingleAssignment, 
			"LinearScanRegisterAllocationPass" ), 
		registers( regs )
	{

	}

	void LinearScanRegisterAllocationPass::initialize( const ir::Module& m )
	{
		report( "Initializing linear scan register allocation pass for module " 
			<< m.path() );
	}

	void LinearScanRegisterAllocationPass::runOnKernel( ir::Kernel& k )
	{
		report( "Running on kernel " << k.name );
		_kernel = &k;

		_coalesce();
		_computeIntervals();
		_allocate();
		_spill();
		_extendStack();
		
		_coalesced.clear();
		_ssa.clear();
		_intervals.clear();
	}

	void LinearScanRegisterAllocationPass::finalize( )
	{
		report( "Finalizing linear scan pass." );
	}

}

#endif

