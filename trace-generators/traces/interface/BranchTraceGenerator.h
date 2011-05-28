/*!
	\file BranchTraceGenerator.h
	\author Gregory Diamos
	\date Monday April 13, 2009
	\brief The header file for the BranchTraceGenerator class
*/

#ifndef BRANCH_TRACE_GENERATOR_H_INCLUDED
#define BRANCH_TRACE_GENERATOR_H_INCLUDED

#include <traces/interface/KernelEntry.h>

namespace boost
{
	namespace archive
	{
		class text_oarchive;
	}
}

namespace trace
{
	
	class BranchTraceAnalyzer;
	
	/*!
		\brief A class for creating a trace file containing branch 
			instructions as well as active masks for branch targets and fall
			through edges.
			
		This class should create a database file as well as a trace
		file for each kernel.  The database should contain references
		and statistics about all of the trace files.
		
		The idea is to eventually be able to say something about the 
		divergenece of each branch.
	*/
	class BranchTraceGenerator : public TraceGenerator
	{
		
		private:
			friend class BranchTraceAnalyzer;
			
			/*!
				\brief Header for a kernel trace
			*/
			class Header
			{
				public:
					TraceFormat format; //! The trace format stored
					long long unsigned int branches; //! Branch count
					long long unsigned int divergent; //! divergent branches
					long long unsigned int instructions; //! Instruction count
					double activeThreads; //! Total active threads 
					unsigned int threads; //! Threads in the cta
					//! maximum number of elements in the call stack
					unsigned int maxContextStackSize; 
					long long unsigned int totalContextStackSize;
			};
			
		private:
			/*! \brief Counter for creating unique file names. */
			static unsigned int _counter;
		
		private:
			/*!	\brief Entry for the current kernel	*/
			KernelEntry _entry;
			
			/*!	\brief Header for the current kernel */
			Header _header;
			
		public:
		
			/*!	\brief Initialize the file pointer to 0 */
			BranchTraceGenerator();
			
			~BranchTraceGenerator();
		
			/*!	\brief Initializes the trace generator when a new kernel is 
					about to be launched.
				\param kernel The kernel used to initialize the generator
			*/
			void initialize(const executive::ExecutableKernel& kernel);

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
			trace::BranchTraceGenerator::Header& header, 
			const unsigned int version )
		{
			ar & header.format;
			ar & header.branches;
			ar & header.divergent;
			ar & header.instructions;
			ar & header.threads;
			ar & header.activeThreads;
			ar & header.maxContextStackSize;
			ar & header.totalContextStackSize;
		}
	}
}

#endif

