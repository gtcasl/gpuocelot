/*!
	\file SharedComputationAnalyzer.h

	\author Andrew Kerr <arkerr@gatech.edu>

	\brief 
*/

#ifndef TRACE_SHAREDCOMPUTATIONANALYZER_H_INCLUDED
#define TRACE_SHAREDCOMPUTATIONANALYZER_H_INCLUDED

#include <traces/interface/SharedComputationGenerator.h>
#include <string>
#include <deque>
#include <map>

namespace trace {

	/*!
		\brief Provides the ability to inspect a database created by a SharedComputationGenerator
	*/
	class SharedComputationAnalyzer {
	private:
		typedef std::deque< KernelEntry > KernelVector;
		typedef std::map< std::string, KernelVector > KernelMap;
		
	private:
		KernelMap _kernels; //! Entries for the kernel traces
	
	public:

		~SharedComputationAnalyzer();
	
		/*!
			\brief The constructor loads a database
		*/
		SharedComputationAnalyzer(const std::string& database);

		/*!
			\brief List all of the kernel traces contained in the database.
			
			Print the results to stdout
		*/
		void list() const;

		/*!
			Returns statistics from the trace file.
		*/
		void shared_computation(bool machine_readable = false);
		
	public:
		
		bool verbose;	//! prints an unmanagable amount of output to stdout
	};

}

int main( int argc, char** argv );

#endif

