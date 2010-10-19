/*!
	\file LoadBalanceGenerator.h
	\author Andrew Kerr <arkerr@gatech.edu>

*/

#ifndef OCELOT_TRACE_LOADBALANCEGENERATOR_H_INCLUDED
#define OCELOT_TRACE_LOADBALANCEGENERATOR_H_INCLUDED

// C++ includes
#include <fstream>

// Ocelot includes
#include <ocelot/trace/interface/TraceGenerator.h>
#include <ocelot/executive/interface/EmulatedKernel.h>

namespace trace {

	/*!
		\brief computes number of dynamic instructions executed by each thread for each CTA
	*/
	class LoadBalanceGenerator: public trace::TraceGenerator {
	public:
		class ThreadCounter {
		public:
			ThreadCounter(): dynInstr(0), memoryDemand(0) {}
			
			size_t dynInstr;
			size_t memoryDemand;
		};
	
		typedef std::vector< ThreadCounter > ThreadCounterVector;
		
		class CtaCounter {
		public:
			ir::Dim3 ctaId;
			ThreadCounterVector threads;
		};
		typedef std::vector< CtaCounter > CtaCounterVector;
	
	public:
	
		LoadBalanceGenerator();
		virtual ~LoadBalanceGenerator();

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
	
		/*! \brief Counter for creating unique file names. */
		static unsigned int _counter;
		
		std::string _kernelName;
		CtaCounterVector _ctas;
		
	};

}

#endif

