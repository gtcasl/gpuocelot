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

static long long unsigned int align(long long unsigned int address,
	long long unsigned int alignment)
{
	long long unsigned int remainder = address % alignment;
	return remainder == 0 ? address : address + alignment - remainder;
}

template<typename T>
void parse(std::string& result, long long unsigned int& parameters,
	std::ios_base& (*format)(std::ios_base&) = std::dec)
{
	std::stringstream stream;
	parameters = align(parameters, sizeof(T));
	stream << format << *(T*)parameters;
	result.append(stream.str());
	parameters += sizeof(T);
}

static int printfWrapper(long long unsigned int string,
	long long unsigned int parameters)
{
	const char* format = (const char*)string;
	std::string result;

	bool escape = false;
	for(const char* f = format; *f != 0; ++f)
	{
		if(escape)
		{
			if(*f == 'c')
			{
				parse<char>(result, parameters);
			}
			else if(*f == 'd' || *f == 'i')
			{
				parse<int>(result, parameters);
			}
			else if (*f == 'f')
			{
				parse<float>(result, parameters);			
			}
			else if (*f == 'o')
			{
				parse<unsigned>(result, parameters, std::oct);			
			}
			else if (*f == 's')
			{
				std::string temp((const char*)parameters);
				result += temp;
				parameters += temp.size() + 1;
			}
			else if (*f == 'u')
			{
				parse<unsigned>(result, parameters);			
			}
			else if (*f == 'x')
			{
				parse<unsigned>(result, parameters, std::hex);			
			}
			else if (*f == 'p')
			{
				parse<void*>(result, parameters);			
			}
			else
			{
				result.push_back(*f);
			}

			escape = false;
		}
		else
		{
			if(*f == '%')
			{
				escape = true;
			}
			else
			{
				result.push_back(*f);
			}
		}
	}
	
	std::cout << result;
	
	return 0;
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
                    break;
                case api::OcelotConfiguration::Instrumentation::BasicBlockInstrumentor::memoryIntensity:
                    _basicBlockInstrumentor.type = analysis::BasicBlockInstrumentor::memoryIntensity;
                    break;
            }
             
            _basicBlockInstrumentor.output = c.instrument.basicBlockInstrumentor.logfile;
            ocelot::addInstrumentor(_basicBlockInstrumentor);    
        }

		if (c.optimizations.structuralTransform)
		{
			ocelot::addPTXPass(_structuralTransform);
		}
			
		if (c.optimizations.predicateToSelect)
		{
			ocelot::addPTXPass(_predicationToSelect);		
		}
		
		if (c.optimizations.linearScanAllocation)
		{
			ocelot::addPTXPass(_linearScanAllocation);		
		}
			
		if (c.optimizations.mimdThreadScheduling)
		{
			ocelot::addPTXPass(_mimdThreadScheduling);
		}
			
		if (c.optimizations.syncElimination)
		{
			ocelot::addPTXPass(_syncElimination);
		}

		// add built-in functions
		registerExternalFunction("malloc",  (void*)(cudaMallocWrapper));
		registerExternalFunction("free",    (void*)(cudaFreeWrapper));
		registerExternalFunction("vprintf", (void*)(printfWrapper));
	}

}

#endif

