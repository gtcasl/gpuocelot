/*!
	\file BranchTraceGenerator.cpp
	\author Gregory Diamos
	\date Monday April 13, 2009
	\brief The source file for the BranchTraceGenerator class
*/

#ifndef BRANCH_TRACE_GENERATOR_CPP_INCLUDED
#define BRANCH_TRACE_GENERATOR_CPP_INCLUDED

#include <traces/interface/BranchTraceGenerator.h>
#include <ocelot/trace/interface/TraceEvent.h>
#include <ocelot/executive/interface/EmulatedKernel.h>
#include <ocelot/ir/interface/Module.h>
#include <hydrazine/interface/Exception.h>
#include <boost/filesystem.hpp>
#include <fstream>

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

namespace trace
{
		
	unsigned int BranchTraceGenerator::BranchTraceGenerator::_counter = 0;

	BranchTraceGenerator::BranchTraceGenerator()
	{
	}
	
	BranchTraceGenerator::~BranchTraceGenerator()
	{
		
	}

	void BranchTraceGenerator::initialize(
		const executive::ExecutableKernel& kernel)
	{
		_entry.name = kernel.name;
		_entry.module = kernel.module->path();
		_entry.format = BranchTraceFormat;

		std::string name = kernel.name;
		
		if( name.size() > 20 )
		{
			name.resize( 20 );
		}

		std::stringstream stream;
		stream << _entry.format << "_" << _counter++;

		boost::filesystem::path path( database );
		path = path.parent_path();
		path /= _entry.program + "_" + name + "_" + stream.str() 
			+ ".header";
		path = boost::filesystem::system_complete( path );
		
		_entry.header = path.string();
		
		_header.format = BranchTraceFormat;
		_header.instructions = 0;
		_header.branches = 0;
		_header.divergent = 0;
		_header.threads =
			kernel.blockDim().x*kernel.blockDim().y*kernel.blockDim().z;
		_header.activeThreads = 0;
		_header.maxContextStackSize = 0;
		_header.totalContextStackSize = 0;
	}

	void BranchTraceGenerator::event( const TraceEvent& event )
	{
		if (event.contextStackSize > _header.maxContextStackSize) 
		{
			_header.maxContextStackSize = event.contextStackSize;
		}
		
		_header.totalContextStackSize += event.contextStackSize;

		if( event.instruction->opcode == ir::PTXInstruction::Bra )
		{
			_header.divergent = ( event.taken.count() != 0 
				&& event.fallthrough.count() != 0 ) 
				? _header.divergent + 1 : _header.divergent;
			++_header.branches;
		}
		++_header.instructions;
		_header.activeThreads += event.active.count();
	}
	
	void BranchTraceGenerator::finish()
	{
		_entry.updateDatabase( database );

		std::ofstream hfile( _entry.header.c_str() );
		boost::archive::text_oarchive harchive( hfile );
	
		if( !hfile.is_open() )
		{
			throw hydrazine::Exception(
				"Failed to open BranchTraceGenerator header file " 
				+ _entry.header );
		}
		
		harchive << _header;
		
		hfile.close();
	}
	
}

#endif

