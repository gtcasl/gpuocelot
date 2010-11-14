/*! \file ExecuteInstrumentedKernel.h
	\date Friday October 8, 2010
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The header file for the ExecuteInstrumentedKernel class.
*/

#ifndef EXECUTE_INSTRUMENTED_KERNEL_H_INCLUDED
#define EXECUTE_INSTRUMENTED_KERNEL_H_INCLUDED

#include <hydrazine/interface/Test.h>
#include <ocelot/ir/interface/Module.h>

namespace analysis
{
	/*! \brief A utility to run the instrumented PTX kernel. 
	*/
	class ExecuteInstrumentedKernel 
	{

        public:
            void execute( const std::string &input, const std::string &output, unsigned int ctas, unsigned int threads, const std::string& pass);
        		
	};
}

int main(int argc, char** argv);

#endif

