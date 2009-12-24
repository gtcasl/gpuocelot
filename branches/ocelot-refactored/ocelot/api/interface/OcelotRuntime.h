/*!
	\file OcelotRuntime.h
	\author Gregory Diamos
	\date Tuesday August 11, 2009
	\brief The header file for the OcelotRuntime class.
*/

#ifndef OCELOT_RUNTIME_H_INCLUDED
#define OCELOT_RUNTIME_H_INCLUDED

#include <hydrazine/interface/Configurable.h>
#include <ocelot/trace/interface/MemoryTraceGenerator.h>
#include <ocelot/trace/interface/ParallelismTraceGenerator.h>
#include <ocelot/trace/interface/SharedComputationGenerator.h>
#include <ocelot/trace/interface/BranchTraceGenerator.h>
#include <ocelot/trace/interface/CacheSimulator.h>

namespace ocelot
{
	/*! \brief This is an interface for managing state associated with Ocelot */
	class OcelotRuntime : private hydrazine::Configurable
	{
		private:
			trace::MemoryTraceGenerator _memoryTraceGenerator;
			trace::SharedComputationGenerator 
				_sharedComputationGenerator;
			trace::BranchTraceGenerator _branchTraceGenerator;
			trace::ParallelismTraceGenerator _parallelismTraceGenerator;
			trace::CacheSimulator _cacheSimulator;
		
			bool _initialized;
			
		public:
			/*! \brief The constructor loads config data */
			OcelotRuntime();
			/*! \brief Initialize the state */
			void initialize();
		
		private:
			void configure( const Configuration& c );
						
	};
}

#endif

