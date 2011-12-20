/*!
	\file TemporalSIMTGenerator.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Dec 2011
	\brief counts dynamic instructions issued for a SIMT processor
*/

#ifndef TRACE_TEMPORALSIMTGENERATOR_H_INCLUDED
#define TRACE_TEMPORALSIMTGENERATOR_H_INCLUDED

#include <ocelot/trace/interface/TraceGenerator.h>

namespace trace {

	class TemporalSIMTGenerator: public TraceGenerator {
	
	public:
		TemporalSIMTGenerator();
		virtual ~TemporalSIMTGenerator();
		
	public:

		/*! \brief called when a traced kernel is launched to retrieve some 
				parameters from the kernel
		*/
		virtual void initialize(const executive::ExecutableKernel& kernel);

		/*! \brief Called whenever an event takes place.

			Note, the const reference 'event' is only valid until event() 
			returns
		*/
		virtual void event(const TraceEvent & event);
		
		/*! \brief called when an event is committed
		*/
		virtual void postEvent(const TraceEvent & event);
		
		/*! \brief Called when a kernel is finished. There will be no more 
				events for this kernel.
		*/
		virtual void finish();
	
	public:
	
		//! number of threads in a SIMT warp
		int warpSize;
		
		//! number of functional unit lanes per SIMD cluster (decoder+controller+simdWidthxALUs)
		int simdWidth;
		
		//! number of warps that can simultaneously issue instructions (total ALUs = simdIssueCount * simdWidth)
		int simdIssueCount;
		
	public:
	
		//
		// counters
		//

		//! every time a warp has at least one thread active, this is incremented
		size_t warpActiveCount;
		
		//! every time at least one of a consecutive set of <simdWidth> threads are active, this is incremented
		size_t warpIssueCount;
		
		//! every time a thread is active, this is incremented
		size_t threadActiveCount;
		
		//! kernel name
		std::string kernelName;
	};

}

#endif

