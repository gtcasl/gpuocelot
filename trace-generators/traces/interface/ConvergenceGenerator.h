/*! \file ConvergenceGenerator.h

	\author Andrew Kerr <arkerr@gatech.edu>

	\brief identifies basic blocks that are warp convergent
*/

#ifndef TRACE_CONVERGENCEGENERATOR_H_INCLUDED
#define TRACE_CONVERGENCEGENERATOR_H_INCLUDED

// C++ includes
#include <fstream>
#include <map>

// Ocelot includes
#include <ocelot/trace/interface/TraceGenerator.h>
#include <traces/interface/KernelEntry.h>
#include <ocelot/api/interface/OcelotConfiguration.h>
#include <ocelot/executive/interface/EmulatedKernel.h>

namespace trace {

	/*!
		Base class for generating traces
	*/
	class ConvergenceGenerator: public TraceGenerator {	
	public:
	
		class Counter {
		public:
			Counter();
			
			Counter & operator += (const Counter &c) {
				dynInstructions += c.dynInstructions;
				warpInstructions += c.warpInstructions;
				return *this;
			}
			
		public:
		
			//! \brief true if block contains a synchthreads
			bool hasSync;
		
			//! \brief basic-block comment
			std::string comment;
			
			//! \brief number of threads per CTA
			size_t threads;
		
			//! \brief number of dynamic instructions (one instr per thread)
			size_t dynInstructions;
		
			//! \brief number of dynamic instructions (one instr per warp)
			size_t warpInstructions;
			
		};
		
		//! \brief maps basic block label to operation counters
		typedef std::map< std::string, Counter > OperationCounterMap;
	
	public:
		ConvergenceGenerator();
		virtual ~ConvergenceGenerator();

		/*! \brief called when a traced kernel is launched to retrieve some 
				parameters from the kernel
		*/
		virtual void initialize(const executive::ExecutableKernel& kernel);

		/*! \brief Called whenever an event takes place.

			Note, the const reference 'event' is only valid until event() 
			returns
		*/
		virtual void event(const TraceEvent & event);
		
		/*! \brief Called when a kernel is finished. There will be no more 
				events for this kernel.
		*/
		virtual void finish();
		
	protected:
	
		//! \brief visits each basic block and initializes a counter for each block
		void analyzeKernel(const executive::EmulatedKernel &kernel);
		
		//! \brief counts the number of warps are warp-synchronous
		size_t countSynchronousWarps(const trace::TraceEvent &event);
		
		//! \brief appends an entry per basic block
		void write(std::fstream &out);
		
		//! \brief writes a DOT-format CFG to an output stream
		void writeCFG();
	
	public:
			
		//! \brief kernel
		const executive::EmulatedKernel * kernel;

		/*! \brief Counter for creating unique file names. */
		static unsigned int _counter;
		
		/*!	\brief Entry for the current kernel	*/
		KernelEntry _entry;
		
		//! \brief maps basic blocks onto performance counters
		OperationCounterMap counterMap;
		
		//! \brief maps the PC of the last instruction of each block to the block's label
		std::map< int, std::string > PCsToBlocks;
	};
}

std::ostream & operator<<(std::ostream &out, const trace::ConvergenceGenerator::Counter &counter);

#endif

