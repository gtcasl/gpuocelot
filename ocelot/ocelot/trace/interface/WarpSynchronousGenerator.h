/*!
	\file WarpSynchronousGenerator.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date 1 April 2010
	\brief detects suitability for kernels to execute in warp-synchronized regions
*/

#ifndef WARP_SYNCHRONOUS_GENERATOR_H_INCLUDED
#define WARP_SYNCHRONOUS_GENERATOR_H_INCLUDED

// C++ includes
#include <vector>
#include <map>

// Boost includes
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

// Ocelot includes
#include <ocelot/trace/interface/KernelEntry.h>
#include <ocelot/ir/interface/PTXInstruction.h>
#include <ocelot/ir/interface/Dim3.h>

//////////////////////////////////////////////////////////////////////////////////////////////////

namespace boost
{
	namespace archive
	{
		class text_oarchive;
	}
}

namespace trace
{
	
	/*!
		\brief For each kernel, identify a set of instructions potentially worth promoting to
			vectorized instructions, then measure the activity mask for each n-wide virtual warp
			that might execute them.

	*/
	class WarpSynchronousGenerator : public TraceGenerator {
		public:
			
			/*!
				\brief Header for a kernel trace
			*/
			class Header
			{
				public:
					TraceFormat format; //! The trace format stored

			};

			/*!
				\brief base class for counting warp-synchronous events
			*/
			class WarpCounter {
			public:

				WarpCounter();

				void event(int warpSize, const TraceEvent &event);

			public:

				//! \brief a warp-synchronous event took place
				size_t synchronous;

				//! \brief an event took place
				size_t events;
			};
			
			/*!
				\brief control-flow sensitive counter recording potentially vectorizable instructions
			*/
			class InstructionCounter: public WarpCounter {
			public:

				InstructionCounter();

			public:

			};
			
			typedef std::map< ir::PTXOperand::DataType, InstructionCounter> DataInstructionCounter;

			/*!
				\brief maps an opcode and data type onto an instruction counter
			*/
			typedef std::map< ir::PTXInstruction::Opcode, 
				 DataInstructionCounter > WarpInstructionCounter;
			
			/*!
				\brief special counter structure for load/store operations
			*/
			class LSInstructionCounter: public WarpCounter {
			public:

				LSInstructionCounter();

				void event(int warpSize, const TraceEvent &event);

			public:
				
			};

			/*!
				\brief counts number of times a warp diverges at a branch
			*/
			class BranchCounter: public WarpCounter {
			public:

				BranchCounter();

			public:

			};
			
			/*!
				\brief all such counters for a particular warp size
			*/
			class SynchronousInstructionCounter {
			public:
				SynchronousInstructionCounter();
				void event(int warpSize, const TraceEvent &event);

			public:
			
				LSInstructionCounter counterLoadStore;
				
				WarpInstructionCounter counterVectorizable;

				//! \brief maps a particular branch's PC to a branch counter
				std::map< int, BranchCounter > counterBranches;
			};
			
			/*! 
				\brief maps warp size to a particular structure of counters
			*/
			std::map< int, SynchronousInstructionCounter > WarpSynchronousCounters;
			
		private:
			/*! \brief Counter for creating unique file names. */
			static unsigned int _counter;
		
		private:
			/*!	\brief Entry for the current kernel	*/
			KernelEntry _entry;
			
			/*!	\brief Header for the current kernel */
			Header _header;
			
		private:
		
			/*!
				\brief identifies collection of warp sizes to compute results for
			*/
			std::vector<int> warpSizes;

			/*!
				\brief collection of counters mapped to by warp sizes
			*/
			std::map< int, SynchronousInstructionCounter > warpCounters;

			std::string kernelName;

			ir::Dim3 kernelBlockDim;
			
		public:
		
			/*!	\brief Initialize the file pointer to 0 */
			WarpSynchronousGenerator();
			
			~WarpSynchronousGenerator();
		
			/*!	\brief Initializes the trace generator when a new kernel is 
					about to be launched.
				\param kernel The kernel used to initialize the generator
			*/
			void initialize(const ir::ExecutableKernel& kernel);

			/*!
				\brief Called whenever an event takes place.

				\param even The TraceEvent that just occurred
				Note, the const reference 'event' is only valid until event() 
				returns
			*/
			void event( const TraceEvent& event );
			
			/*!	\brief Finalize the trace and dump the results to disk.
				
				Add a databse entry for the trace as well.
			*/
			void finish();
	};
	
}

namespace boost
{
	namespace serialization
	{		
		template< class Archive >
		void serialize( Archive& ar, 
			trace::WarpSynchronousGenerator::Header& header, 
			const unsigned int version ) {
			ar & header.format;
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////

#endif

