/*! \file InstructionTraceAnalyzer.h
	\author Andrew Kerr
	\date Jan 2010
	\brief The header file for the InstructionTraceAnalyzer class
*/

#ifndef OCELOT_INTSTRUCTION_TRACE_ANALYZER_H_INCLUDED
#define OCELOT_INTSTRUCTION_TRACE_ANALYZER_H_INCLUDED

#include <traces/interface/InstructionTraceGenerator.h>
#include <map>
#include <deque>

namespace trace
{
	/*! \brief Provides the ability to inspect a database created by a 
		BranchTraceGenerator
	*/
	class InstructionTraceAnalyzer {
		private:

			typedef std::deque< KernelEntry > KernelVector;
			typedef std::map< std::string, KernelVector > KernelMap;
			
		private:
			KernelMap _kernels; //! Entries for the kernel traces
		
		public:
		
			/*! \brief The constructor loads a database */
			InstructionTraceAnalyzer(const std::string& database);
			
			/*!
				\brief List all of the kernel traces contained in the database.
			*/
			void list() const;
			
			/*!
				\brief compute the histogram of instructions by (functional unit, opcode) for each
					kernel
			*/
			void instructions_by_kernel(bool pyList = false) const;

			/*!
				\brief compute the histogram of instructions by (functional unit, opcode) for each
					application over all its kernels
			*/
			void instructions_by_application(bool pyList = false) const;
	
	};
}

int main( int argc, char** argv );

#endif

