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

#include <ocelot/cuda/interface/cuda_runtime.h>

// Hydrazine includes
#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

static void* cudaMallocWrapper(long long unsigned int bytes)
{
	void* pointer = 0;
	cudaMalloc(&pointer, bytes);
	return pointer;
}

static void cudaFreeWrapper(void* pointer)
{
	cudaFree(pointer);
}

namespace ocelot
{
	OcelotRuntime::OcelotRuntime() : _initialized( false )
	{
	
	}
	
	void OcelotRuntime::configure( const api::OcelotConfiguration & c )
	{
		if (c.trace.memoryChecker.enabled)
		{
			report( "Creating memory checker" );
			_memoryChecker.setCheckInitialization(  
				c.trace.memoryChecker.checkInitialization );
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
        if(c.instrument.clockCycleCountInstrumentor.enabled)
        {   
            report("Creating clock cycle count instrumentor");
            _clockCycleCountInstrumentor.output = c.instrument.clockCycleCountInstrumentor.logfile;
            ocelot::addInstrumentor(_clockCycleCountInstrumentor);
        }
        if(c.instrument.basicBlockInstrumentor.enabled)
        {   
            report("Creating basic block execution count instrumentor");
            switch(c.instrument.basicBlockInstrumentor.type) {
                case api::OcelotConfiguration::Instrumentation::BasicBlockInstrumentor::executionCount:
                    _basicBlockInstrumentor.type = analysis::BasicBlockInstrumentor::executionCount;
                    break;
                case api::OcelotConfiguration::Instrumentation::BasicBlockInstrumentor::instructionCount:
                    _basicBlockInstrumentor.type = analysis::BasicBlockInstrumentor::instructionCount;
            }
             
            _basicBlockInstrumentor.output = c.instrument.basicBlockInstrumentor.logfile;
            ocelot::addInstrumentor(_basicBlockInstrumentor);    
        }

		// add built-in functions
		registerExternalFunction("malloc", (void*)(cudaMallocWrapper));
		registerExternalFunction("free",   (void*)(cudaFreeWrapper));
		registerExternalFunction("printf", (void*)(std::printf));
	}

}

#endif

