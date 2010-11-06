/*! \file ExecuteInstrumentedKernel.h
	\date Friday October 8, 2010
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The header file for the ExecuteInstrumentedKernel class.
*/

#ifndef EXECUTE_INSTRUMENTED_KERNEL_H_INCLUDED
#define EXECUTE_INSTRUMENTED_KERNEL_H_INCLUDED

#include <hydrazine/interface/Test.h>

namespace test
{
	/*! \brief A utility to output the results of the
        instrumented PTX kernel generated from PTX Optimizer. 
	*/
	class ExecuteInstrumentedKernel : public Test
	{
		private:
			/*! \brief Execution of the instrumented kernel */
			bool execute();
	
			/*! \brief Dispatch function fot the unit tests */
			bool doTest();
	
		public:
			/*! \brief The constructor sets the description */
			ExecuteInstrumentedKernel();
        
            std::string moduleName;
            std::string kernelName;
            std::string input;
	};
}

int main(int argc, char** argv);

#endif

