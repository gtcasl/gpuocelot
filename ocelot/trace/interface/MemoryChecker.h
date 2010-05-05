/*! \file MemoryChecker.h
	\date Wednesday March 17, 2010
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The header file for the MemoryChecker class.
*/

#ifndef MEMORY_CHECKER_H_INCLUDED
#define MEMORY_CHECKER_H_INCLUDED

// Ocelot includes
#include <ocelot/ir/interface/PTXOperand.h>
#include <ocelot/ir/interface/Dim3.h>
#include <ocelot/trace/interface/TraceGenerator.h>

namespace executive
{
	class Device;
	class EmulatedKernel;
}

namespace trace
{
	/*! \brief A trace generator for checking all memory accesses */
	class MemoryChecker : public TraceGenerator
	{
		public:
			/*! \brief A class for a cached memory allocation */
			class Allocation
			{
				public:
					bool valid; // is this a valid allocation?
					ir::PTXU64 base; // base allocation pointer
					ir::PTXU64 extent; // size of the allocation
			
				public:
					Allocation(bool valid = false, 
						ir::PTXU64 base = 0, ir::PTXU64 extent = 0);
			};
		
		private:
			/*! \brief The block dimensions */
			ir::Dim3 _dim;
		
			/*! \brief The last allocation referenced */
			Allocation _cache;
			
			/*! \brief Parameter memory allocation */
			Allocation _parameter;
			
			/*! \brief Shared memory allocation */
			Allocation _shared;
			
			/*! \brief Local memory allocation */
			Allocation _local;
			
			/*! \brief Constant memory allocation */
			Allocation _constant;
			
			/*! \brief A pointer to the executive class */
			const executive::Device* _device;
		
			/*! \brief A pointer to the executable kernel */
			const executive::EmulatedKernel* _kernel;
			
		private:
			/*! \brief Check the alignment of a memory access */
			void _checkAlignment(const TraceEvent& e);
			
			/*! \brief Check whether or not the access falls within 
				an allocated region */
			void _checkValidity(const TraceEvent& e);
			
			/*! \brief Check for an uninitialized memory access */
			void _checkInitialized(const TraceEvent& e);
			
		public:
			/*! \brief The constructor initializes the cached allocations */
			MemoryChecker();
			
			/*! \brief Set the cache and get a pointer to the memory mappings */
			virtual void initialize(const executive::ExecutableKernel& kernel);

			/*! \brief Called whenever an event takes place.

				Note, the const reference 'event' is only valid until event() 
				returns
			*/
			virtual void event(const TraceEvent& event);
			
			/*!  \brief Called when a kernel is finished. There will be no more 
					events for this kernel.
			*/
			virtual void finish();
		
	};
}

#endif

