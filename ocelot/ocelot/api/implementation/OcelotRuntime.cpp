/*!
	\file OcelotRuntime.cpp
	\author Gregory Diamos
	\date Tuesday August 11, 2009
	\brief The source file for the OcelotRuntime class.
*/

#ifndef OCELOT_RUNTIME_CPP_INCLUDED
#define OCELOT_RUNTIME_CPP_INCLUDED

#include <ocelot/api/interface/OcelotRuntime.h>
#include <ocelot/api/interface/ocelot.h>

#include <hydrazine/implementation/XmlParser.h>
#include <hydrazine/implementation/Exception.h>

#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace ocelot
{
	OcelotRuntime::OcelotRuntime() : _initialized( false )
	{
	
	}
	
	void OcelotRuntime::initialize()
	{
		if( !_initialized )
		{
			_initialized = true;
			Configuration config;
		
			try
			{
				report( "Loading config file config.ocelot" );
				hydrazine::XmlParser parser( "config.ocelot" );
				hydrazine::XmlTree tree = parser.tree();
				hydrazine::XmlTree::iterator fi = tree.begin();
			
				fi.descend("ocelot");
				fi.descend("OcelotRuntime");
			
				config = fi.map();
			}
			catch( const hydrazine::Exception& e )
			{
				report( "Failed to load config file" );
			}
		
			configure( config );
		}
	}
	
	void OcelotRuntime::configure( const Configuration& c )
	{
		bool memoryTrace;
		bool sharedTrace;
		bool branchTrace;
		bool parallelismTrace;
		bool instructionTrace;
		bool cacheSimulator;
		bool inPlaceTraces;
		std::string database;
		unsigned int threadLimit;
		
		report( "Parsing " << c.size() << " arguments" );
		
		parse( "TraceDatabase", database, "trace/database.db", c );
		parse( "UseMemoryTraceGenerator", memoryTrace, false, c );
		parse( "UseBranchTraceGenerator", branchTrace, false, c );
		parse( "UseSharedComputationGenerator", sharedTrace, false, c );
		parse( "UseParallelismTraceGenerator", parallelismTrace, false, c );
		parse( "UseInstructionTraceGenerator", instructionTrace, false, c);
		parse( "UseCacheSimulator", cacheSimulator, false, c );
		parse( "UseInPlaceTraces", inPlaceTraces, false, c );
		parse( "LimitWorkerThreads", threadLimit, -1, c );
		
		ocelot::limitWorkerThreads( threadLimit );
		
		if( memoryTrace )
		{
			report( "Creating memory trace generator" );
			_memoryTraceGenerator.database = database;
			_memoryTraceGenerator.headerOnly = inPlaceTraces;
			ocelot::addTraceGenerator( _memoryTraceGenerator, true, false );
		}
		if( sharedTrace )
		{
			report( "Creating shared computation trace generator" );
			_sharedComputationGenerator.database = database;
			ocelot::addTraceGenerator( _sharedComputationGenerator, 
				true, false );
		}
		if( branchTrace )
		{
			report( "Creating branch trace generator" );
			_branchTraceGenerator.database = database;
			ocelot::addTraceGenerator( _branchTraceGenerator, true, false );
		}
		if( parallelismTrace )
		{
			report( "Creating parallelism trace generator" );
			_parallelismTraceGenerator.database = database;
			ocelot::addTraceGenerator( _parallelismTraceGenerator, 
				true, false );
		}
		if (instructionTrace)
		{
			report("Creating instruction trace generator");
			_instructionTraceGenerator.database = database;
			ocelot::addTraceGenerator(_instructionTraceGenerator, true, false);
		}
		if( cacheSimulator )
		{
			report( "Creating cache simulator" );
			_cacheSimulator.database = database;
			ocelot::addTraceGenerator( _cacheSimulator, true, false );	
		}
		if (instructionTrace) {
			report("Creating instruction trace generator");
			_instructionTraceGenerator.database = database;
			ocelot::addTraceGenerator( _instructionTraceGenerator, true, false);
		}
	}

}

#endif

