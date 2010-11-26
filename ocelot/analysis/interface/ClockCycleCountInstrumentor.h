/*! \file ClockCycleCountInstrumentor.h
	\date Monday November 15, 2010
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The header file for ClockCycleCountInstrumentor
*/

#ifndef CLOCK_CYCLE_COUNT_INSTRUMENTOR_H_INCLUDED
#define CLOCK_CYCLE_COUNT_INSTRUMENTOR_H_INCLUDED

#include <string>
#include <ocelot/ir/interface/Module.h>
#include <ocelot/analysis/interface/PTXInstrumentor.h>
#include <ocelot/analysis/interface/Pass.h>

namespace analysis
{
	/*! \brief Able to run the clock cycle count instrumentation pass over PTX modules */
	class ClockCycleCountInstrumentor : public analysis::PTXInstrumentor
	{
		public:       
            /*! \brief The description of the specified pass */
            std::string description;

            size_t *clock_sm_info;
			
		public:
			/*! \brief The default constructor */
			ClockCycleCountInstrumentor();

            /*! \brief The constructor that sets the defaults */
            ClockCycleCountInstrumentor(const std::string input, const std::string output, unsigned int ctas, unsigned int threads );

            /*! \brief The analyze method performs any necessary static analysis */
            virtual void analyze(ir::Module &module);

            /*! \brief The initialize method performs any necessary CUDA runtime initialization prior to instrumentation */
            void initialize();

            /*! \brief The createPass method instantiates the instrumentation pass */
            analysis::Pass *createPass();

            /*! \brief The finalize method performs any necessary CUDA runtime actions after instrumentation */
            void finalize();	

            void jsonEmitter(size_t* count, int ctaNum);
	};
}

#endif
