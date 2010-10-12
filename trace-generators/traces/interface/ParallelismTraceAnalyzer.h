/*!
	\file ParallelismTraceAnalyzer.h
	
	\author Gregory Diamos
	\date Wednesday April 13, 2009
	
	\brief The header file for the ParallelismTraceAnalyzer class
*/

#ifndef PARALLELISM_TRACE_ANALYZER_H_INCLUDED
#define PARALLELISM_TRACE_ANALYZER_H_INCLUDED

#include <traces/interface/ParallelismTraceGenerator.h>
#include <unordered_map>
#include <deque>
#include <map>

namespace trace
{

	/*!
		\brief Provides the ability to inspect a database created by a 
		ParallelismTraceGenerator
	*/
	class ParallelismTraceAnalyzer
	{
		private:
			typedef std::deque< KernelEntry > KernelVector;
			typedef std::map< std::string, KernelVector > KernelMap;
		
		private:
			KernelMap _kernels; //! Entries for the kernel traces
		
		public:
		
			/*!
				\brief The constructor loads a database
			*/
			ParallelismTraceAnalyzer(const std::string& database);
			
			/*!
				\brief List all of the kernel traces contained in the database.
				
				Print the results to stdout
			*/
			void list() const;
			
			/*!
				\brief Compute the MIMD and SIMD for each trace.
				
				Print the results to stdout
			*/
			void parallelism() const;
	
	};

}

int main( int argc, char** argv );

#endif

