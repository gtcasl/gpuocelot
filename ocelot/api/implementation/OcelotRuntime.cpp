/*! \file OcelotRuntime.cpp
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
		if (c.trace.memoryChecker)
		{
			report( "Creating memory checker" );
			ocelot::addTraceGenerator( _memoryChecker, true );
		}
		if (c.trace.raceDetector.enabled)
		{
			report( "Creating memory race detector" );
			_raceDetector.checkAllWrites( 
				!c.trace.raceDetector.ignoreIrrelevantWrites );
			ocelot::addTraceGenerator( _raceDetector, true );
		}
		if (c.trace.debugger.enabled)
		{
				report("Creating interactive PTX debugger");
				_debugger.filter = c.trace.debugger.kernelFilter;
				_debugger.alwaysAttach = c.trace.debugger.alwaysAttach;
				ocelot::addTraceGenerator(_debugger, true);
		}

	}

}

#endif

