/*!
	\file OcelotRuntime.cpp
	\author Gregory Diamos
	\date Tuesday August 11, 2009
	\brief The source file for the OcelotRuntime class.
*/

#ifndef OCELOT_RUNTIME_CPP_INCLUDED
#define OCELOT_RUNTIME_CPP_INCLUDED

// Ocelot includes
#include <ocelot/api/interface/OcelotRuntime.h>
#include <ocelot/api/interface/ocelot.h>

// Hydrazine includes
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
	
	void OcelotRuntime::configure( const api::OcelotConfiguration & c )
	{
		if( c.trace.memory )
		{
			report( "Creating memory trace generator" );
			_memoryTraceGenerator.database = c.trace.database;
			_memoryTraceGenerator.headerOnly = c.trace.inPlaceTraces;
			ocelot::addTraceGenerator( _memoryTraceGenerator, true, false );
		}
		if( c.trace.sharedComputation )
		{
			report( "Creating shared computation trace generator" );
			_sharedComputationGenerator.database = c.trace.database;
			ocelot::addTraceGenerator( _sharedComputationGenerator, 
				true, false );
		}
		if( c.trace.branch )
		{
			report( "Creating branch trace generator" );
			_branchTraceGenerator.database = c.trace.database;
			ocelot::addTraceGenerator( _branchTraceGenerator, true, false );
		}
		if( c.trace.parallelism )
		{
			report( "Creating parallelism trace generator" );
			_parallelismTraceGenerator.database = c.trace.database;
			ocelot::addTraceGenerator( _parallelismTraceGenerator, true, false );
		}
		if (c.trace.instruction)
		{
			report( "Creating instruction trace generator" );
			_instructionTraceGenerator.database = c.trace.database;
			ocelot::addTraceGenerator( _instructionTraceGenerator, true, false );
		}
		if (c.trace.cacheSimulator)
		{
			report( "Creating cache simulator" );
			_cacheSimulator.database = c.trace.database;
			ocelot::addTraceGenerator( _cacheSimulator, true, false );	
		}
		if (c.trace.memoryChecker)
		{
			report( "Creating memory checker" );
			ocelot::addTraceGenerator( _memoryChecker, true, false );
		}
		if (c.trace.raceDetector)
		{
			report( "Creating memory race detector" );
			ocelot::addTraceGenerator( _raceDetector, true, false );
		}
		if (c.trace.warpSynchronous) {
			report( "Creating warp synchronous detector" );
			_warpSynchronous.database = c.trace.database;
			ocelot::addTraceGenerator(_warpSynchronous, true, false);
		}
	}

}

#endif

