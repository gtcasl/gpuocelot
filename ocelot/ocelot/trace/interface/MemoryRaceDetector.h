/*! \file MemoryRaceDetector.h
	\date Wednesday March 24, 2010
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The header file for the MemoryRaceDetector class.
*/

#ifndef MEMORY_RACE_DETECTOR_H_INCLUDED
#define MEMORY_RACE_DETECTOR_H_INCLUDED

// Ocelot includes
#include <ocelot/ir/interface/Dim3.h>
#include <ocelot/trace/interface/TraceGenerator.h>

namespace executive
{
	class EmulatedKernel;
}

namespace trace
{
	/*! \brief A trace generator for checking memory races */
	class MemoryRaceDetector : public TraceGenerator
	{
		public:
			/*! \brief A vector of integers */
			typedef std::vector< int > IntVector;
			
		private:
			/*! \brief The block dimensions */
			ir::Dim3 _dim;
			/*! \brief The last writer to each byte in shared memory */
			IntVector _writers;
			/*! \brief The last reader from each byte in shared memory */
			IntVector _readers;
			/*! \brief A pointer to the executable kernel */
			const executive::EmulatedKernel* _kernel;
		
		private:
			/*! \brief Check a shared memory write */
			void _write( const TraceEvent& event );
			/*! \brief Check a shared memory read */
			void _read( const TraceEvent& event );
			/*! \brief Encounter a barrier */
			void _barrier();

		public:
			/*! \brief The constructor initializes the cached allocations */
			MemoryRaceDetector();
			
			/*! \brief Set the cache and get a pointer to the memory mappings */
			virtual void initialize( const ir::ExecutableKernel& kernel );

			/*! \brief Called whenever an event takes place.

				Note, the const reference 'event' is only valid until event() 
				returns
			*/
			virtual void event( const TraceEvent& event );
			
			/*!  \brief Called when a kernel is finished. There will be no more 
					events for this kernel.
			*/
			virtual void finish();
		
	};
}

#endif

