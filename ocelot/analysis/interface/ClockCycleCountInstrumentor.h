/*! \file ClockCycleCountInstrumentor.h
	\date Monday November 15, 2010
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The header file for ClockCycleCountInstrumentor
*/

#ifndef CLOCK_CYCLE_COUNT_INSTRUMENTOR_H_INCLUDED
#define CLOCK_CYCLE_COUNT_INSTRUMENTOR_H_INCLUDED

#include <string>
#include <map>
#include <algorithm>
#include <ocelot/ir/interface/Module.h>
#include <ocelot/analysis/interface/PTXInstrumentor.h>
#include <ocelot/transforms/interface/Pass.h>

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

            /*! \brief The checkConditions method verifies that the defined conditions are met for this instrumentation */
            void checkConditions();

            /*! \brief The analyze method performs any necessary static analysis */
            virtual void analyze(ir::Module &module);

            /*! \brief The initialize method performs any necessary CUDA runtime initialization prior to instrumentation */
            void initialize();

            /*! \brief The createPass method instantiates the instrumentation pass */
            transforms::Pass *createPass();

            /*! \brief The finalize method performs any necessary CUDA runtime actions after instrumentation */
            void finalize();	

            /*! \brief extracts results for the clock cycle count instrumentation */
            void extractResults(std::ostream *out);

        private:
            bool pred(const std::pair<size_t, size_t>& lhs, const std::pair<size_t, size_t>& rhs);
	};
}

#endif
