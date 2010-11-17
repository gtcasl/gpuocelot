/*! \file KernelClockSMInstrumentor.h
	\date Monday November 15, 2010
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The header file for KernelClockSMInstrumentor
*/

#ifndef KERNEL_CLOCK_SM_INSTRUMENTOR_H_INCLUDED
#define KERNEL_CLOCK_SM_INSTRUMENTOR_H_INCLUDED

#include <string>
#include <ocelot/ir/interface/Module.h>
#include <ocelot/analysis/interface/PTXInstrumentor.h>
#include <ocelot/analysis/interface/Pass.h>

namespace analysis
{
	/*! \brief Able to run the kernel clock SM instrumentation pass over PTX modules */
	class KernelClockSMInstrumentor : public analysis::PTXInstrumentor
	{
		public:       
            /*! \brief The description of the specified pass */
            std::string description;

            size_t *clock_sm_info;
			
		public:
			/*! \brief The default constructor */
			KernelClockSMInstrumentor();

            /*! \brief The constructor that sets the defaults */
            KernelClockSMInstrumentor(const std::string input, const std::string output, unsigned int ctas, unsigned int threads );

            /*! \brief The initialize method performs any necessary CUDA runtime initialization prior to instrumentation */
            void initialize();

            /*! \brief The createPass method instantiates the instrumentation pass */
            analysis::Pass *createPass();

            /*! \brief The finalize method performs any necessary CUDA runtime actions after instrumentation */
            void finalize();	
	};
}

#endif
