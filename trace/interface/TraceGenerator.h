/*!
	\file TraceGenerator.h

	\author Andrew Kerr <arkerr@gatech.edu>

	\brief declares a TraceGenerator class to be the base class for application-dependent
		trace generators
*/

#ifndef TRACE_TRACEGENERATOR_H_INCLUDED
#define TRACE_TRACEGENERATOR_H_INCLUDED

#include <ocelot/trace/interface/TraceEvent.h>

// forward declare EmulatedKernel
namespace executive {
	class EmulatedKernel;
}

namespace trace {

	/*!
		Base class for generating traces
	*/
	class TraceGenerator {
	public:
		/*!
			\brief The different possible types of trace formats
		*/
		enum TraceFormat {
			ParallelismTraceFormat,
			BranchTraceFormat,
			MemoryTraceFormat,
			SharedComputationTraceFormat,
			InvalidTraceFormat
		};
		
	public:
		/*!
			\brief The name of the database file to store references 
				to kernel traces.
		*/
		std::string database;
	
	public:
		TraceGenerator();
		virtual ~TraceGenerator();

		/*!
			\brief called when a traced kernel is launched to retrieve some 
				parameters from the kernel
		*/
		virtual void initialize(const executive::EmulatedKernel *kernel);

		/*!
			\brief Called whenever an event takes place.

			Note, the const reference 'event' is only valid until event() 
			returns
		*/
		virtual void event(const TraceEvent & event);

	};

}

#endif

