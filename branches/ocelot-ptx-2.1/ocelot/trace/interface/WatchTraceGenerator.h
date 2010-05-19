/*!
	\file WatchTraceGenerator.h

	\author Andrew Kerr <arkerr@gatech.edu>

	\brief trace generator for watching particular addresses
*/

#ifndef TRACE_WATCHTRACEGENERATOR_H_INCLUDED
#define TRACE_WATCHTRACEGENERATOR_H_INCLUDED

// C++ includes
#include <map>

// Ocelot includes
#include <ocelot/ir/interface/PTXInstruction.h>
#include <ocelot/trace/interface/TraceGenerator.h>

namespace trace {

	/*!
		Base class for generating traces
	*/
	class WatchTraceGenerator {
	public:
	
		class Location {
		public:
			Location();
			Location(const void *base, size_t size, ir::PTXInstruction::AddressSpace space);
			
		public:
		
			const void *base;
			size_t size;
			ir::PTXInstruction::AddressSpace space;
		};
		
		typedef std::map< const void *, Location > LocationMap;
		typedef std::vector< LocationMap > LocationSpaceVector;
	
	public:
	
		LocationSpaceVector locations;
		
		ir::Dim3 blockDim;
	
	public:
	
		WatchTraceGenerator();
		virtual ~WatchTraceGenerator();

		/*!
			\brief called when a traced kernel is launched to retrieve some 
				parameters from the kernel
		*/
		virtual void initialize(const executive::ExecutableKernel& kernel);

		/*!
			\brief Called whenever an event takes place.

			Note, the const reference 'event' is only valid until event() 
			returns
		*/
		virtual void event(const TraceEvent & event);
		
		/*! 
			\brief Called when a kernel is finished. There will be no more 
				events for this kernel.
		*/
		virtual void finish();
		
		/*!
			\brief registers a particular address to watch
			\param base pointer to start of memory
			\param size number of bytes
			\param space indicates which state space to examine
		*/
		virtual void registerAddress(const void *base, size_t size, 
			ir::PTXInstruction::AddressSpace space);
		
		virtual void unregisterAddress(const void *base, ir::PTXInstruction::AddressSpace space);
		
		/*!
			\brief a watched address has been loaded
		*/
		virtual void loadAccess(size_t PC, const ir::PTXInstruction &instruction, 
			const void *address, size_t size, ir::Dim3 block, ir::Dim3 threadIdx, int threadID, 
			const trace::WatchTraceGenerator::Location &location);
			
		/*!
			\brief a watched address has been stored to
		*/
		virtual void storeAccess(size_t PC, const ir::PTXInstruction &instruction, 
			const void *address, size_t size, ir::Dim3 block, ir::Dim3 threadIdx, int threadID, 
			const trace::WatchTraceGenerator::Location &location);
		
		/*!
			\brief examines the registered addresses and finds the location that includes address
			\param address the base address accessed
			\param space address space accessed
		*/
		virtual Location findLocation(const void *address, ir::PTXInstruction::AddressSpace space);
		
		/*!
			\brief computes the threadIdx structure from a threadID for the running kernel
		*/
		ir::Dim3 threadIdxFromThreadID(int threadID);
	};

}

#endif

