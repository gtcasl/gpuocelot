/*!
	\file SharedComputationGenerator.h

	\author Andrew Kerr <arkerr@gatech.edu>

	\brief declares a SharedComputationGenerator class used in tracing memory operations in the
		emulator
*/

#ifndef TRACE_SHAREDCOMPUTATIONGENERATOR_H_INCLUDED
#define TRACE_SHAREDCOMPUTATIONGENERATOR_H_INCLUDED

#include <set>
#include <vector>
#include <string>
#include <fstream>

#include <ocelot/ir/interface/PTXInstruction.h>
#include <ocelot/trace/interface/TraceGenerator.h>
#include <traces/interface/KernelEntry.h>

#include <boost/serialization/split_member.hpp>

namespace boost
{
	namespace archive
	{
		class text_oarchive;
	}
}


namespace trace {

	class SharedComputationGenerator: public TraceGenerator {
	public:
	
		class Header {
		public:
			Header();
			~Header();
		
		public:
			TraceFormat format;

			ir::PTXU64 dynamic_instructions;

			/*!
				Number of ld.shared instructions in which the source data came from another
				thread.
			*/
			ir::PTXU64 sharedLoads;

			/*!
				Number of threads executing on the kernel
			*/
			ir::PTXU32 threadCount;
			
			/*!
				Number of accesses that are outside addressable shared memory
			*/
			ir::PTXU32 storeOutOfBoundsAccesses;
			
			/*!
				Number of accesses that are outside addressable shared memory
			*/
			ir::PTXU32 loadOutOfBoundsAccesses;
			
			/*!
				Number of bytes in shared memory
			*/
			ir::PTXU32 sharedMemorySize;
			
			/*!
				Number of shared stores
			*/
			ir::PTXU64 storeSharedCount;
			
			/*!
				Number of shared loads
			*/
			ir::PTXU64 loadSharedCount;
			
			/*! Number of cross CTA loads */
			ir::PTXU64 crossThreadLds;
		};
		
	private:
		
		/*!
			ar & header.outOfBoundsAccesses;
			\brief Counter for creating unique file names.
		*/
		static unsigned int _counter;
	
	public:

		/*!
			Constructs a trace generator with path './' recording *all* address spaces
		*/
		SharedComputationGenerator();

		/*!
			Destructs the trace generator
		*/
		~SharedComputationGenerator();

		/*!
			called when a traced kernel is launched to retrieve 
				some parameters from the kernel
		*/
		void initialize(const executive::ExecutableKernel& kernel);

		/*!
			Called whenever an event takes place.

			Note, the const reference 'event' is only valid until event() returns
		*/
		void event(const TraceEvent & event);
			
		void finish();

	protected:

			ir::PTXU32 SharedMemoryMask;
	
			/*!	\brief Entry for the current kernel */
			KernelEntry _entry;
			
			/*!	\brief Header for the current kernel */
			Header _header;

			/*!	Id of the current block */
			ir::PTXU32 blockId;

			/*!	Contains the threadID of the last thread to write to 
				each byte of shared memory */
			ir::PTXS32* sharedMemoryOwners;
			
	public:
			std::set< ir::PTXU32 > maskedStSet;
			
	private:
			void selectMaskedStSet(const executive::ExecutableKernel& kernel);
	};
}


namespace boost
{
	namespace serialization
	{		
		template< class Archive >
		void serialize( Archive& ar, 
			trace::SharedComputationGenerator::Header& header, 
			const unsigned int version )
		{
			ar & header.format;
			ar & header.dynamic_instructions;
			ar & header.sharedLoads;
			ar & header.threadCount;
			ar & header.storeOutOfBoundsAccesses;
			ar & header.loadOutOfBoundsAccesses;
			ar & header.sharedMemorySize;
			ar & header.storeSharedCount;
			ar & header.loadSharedCount;
			ar & header.crossThreadLds;
		}
	}
}

#endif

