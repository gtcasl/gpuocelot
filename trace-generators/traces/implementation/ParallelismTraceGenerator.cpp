/*!
	\file ParallelismTraceGenerator.cpp
	
	\author Gregory Diamos
	\date Wednesday April 15, 2009
	
	\brief The source file for the ParallelismTraceGenerator class
*/

#ifndef PARALLELISM_TRACE_GENERATOR_CPP_INCLUDED
#define PARALLELISM_TRACE_GENERATOR_CPP_INCLUDED

#include <traces/interface/ParallelismTraceGenerator.h>
#include <ocelot/executive/interface/EmulatedKernel.h>
#include <ocelot/ir/interface/Module.h>
#include <hydrazine/interface/Exception.h>
#include <boost/filesystem.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <fstream>
#include <cfloat>

#include <hydrazine/interface/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace trace
{
	
	unsigned int ParallelismTraceGenerator::ParallelismTraceGenerator::_counter 
		= 0;
	
	ParallelismTraceGenerator::ParallelismTraceGenerator()
	{
		_file = 0;
	}
	
	ParallelismTraceGenerator::~ParallelismTraceGenerator()
	{
	}

	void ParallelismTraceGenerator::initialize( 
		const executive::ExecutableKernel& kernel )
	{
		_entry.name = kernel.name;
		_entry.module = kernel.module->path();
		_entry.format = ParallelismTraceFormat;

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
			+ ".trace";
		path = boost::filesystem::system_complete( path );
		
		_entry.path = path.string();
		
		path = path.parent_path();
		path /= _entry.program + "_" + name + "_" + stream.str() 
			+ ".header";
		path = boost::filesystem::system_complete( path );
		
		_entry.header = path.string();
		
		if( _file != 0 )
		{
			delete _archive;
			delete _file;
		}
		
		_file = new std::ofstream( _entry.path.c_str() );
		
		if( !_file->is_open() )
		{
			throw hydrazine::Exception(
				"Failed to open ParallelismTraceGenerator kernel trace file " 
				+ _entry.path );
		}
		
		_archive = new boost::archive::text_oarchive( *_file );
		
		_header.format = ParallelismTraceFormat;
		_header.dimensions = kernel.gridDim().x * kernel.gridDim().y 
			* kernel.gridDim().z;
		report("CTA Dimensions are " << _header.dimensions);
		_header.threads = kernel.maxThreadsPerBlock();
		
		_event.ctaid = 0;
		_event.instructions = 0;
		_event.activity = 0;
	}

	void ParallelismTraceGenerator::event( const TraceEvent& event )
	{
		if( event.instruction->opcode == ir::PTXInstruction::Exit )
		{
			_event.activity /= ( _event.instructions + DBL_EPSILON );
			*_archive << _event;
			++_event.ctaid;
			_event.instructions = 0;
			_event.activity = 0;
		}
		else
		{
			_event.activity += event.active.count();
			++_event.instructions;
		}		
	}	
	
	void ParallelismTraceGenerator::finish()
	{
		if( _file != 0 )
		{
			_entry.updateDatabase( database );
			delete _archive;

			_file->close();	
			delete _file;
			_file = 0;
			
			std::ofstream hfile( _entry.header.c_str() );
			boost::archive::text_oarchive harchive( hfile );
		
			if( !hfile.is_open() )
			{
				throw hydrazine::Exception(
					"Failed to open ParallelismTraceGenerator header file " 
					+ _entry.header );
			}
			
			harchive << _header;
			
			hfile.close();
			
			assert( _event.instructions == 0 );
			assert( _event.activity == 0 );
			assert( _event.ctaid == _header.dimensions );
		}	
	}
}

#endif

