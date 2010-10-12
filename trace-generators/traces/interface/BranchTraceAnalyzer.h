/*!
	\file BranchTraceAnalayzer.h
	
	\author Gregory Diamos
	\date Monday April 13, 2009
	
	\brief The header file for the BranchTraceAnalayzer class
*/

#ifndef BRANCH_TRACE_ANALYZER_H_INCLUDED
#define BRANCH_TRACE_ANALYZER_H_INCLUDED

#include <traces/interface/BranchTraceGenerator.h>
#include <map>
#include <deque>

namespace trace
{

	/*!
		\brief Provides the ability to inspect a database created by a 
		BranchTraceGenerator
	*/
	class BranchTraceAnalyzer
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
			BranchTraceAnalyzer(const std::string& database);
			
			/*!
				\brief List all of the kernel traces contained in the database.
				
				Print the results to stdout
			*/
			void list() const;
			
			/*!
				\brief Compute the branch divergence for each trace.
				
				Print the results to stdout
			*/
			void divergence() const;
	
	};

}

int main( int argc, char** argv );

#endif

