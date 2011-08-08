/*! \file ModulePassTestInstrumentor.h
	\date Saturday July 30, 2011
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The header file for ModulePassTestInstrumentor
*/

#ifndef MODULE_PASS_TEST_INSTRUMENTOR_H_INCLUDED
#define MODULE_PASS_TEST_INSTRUMENTOR_H_INCLUDED

#include <string>
#include <ocelot/ir/interface/Module.h>
#include <ocelot/analysis/interface/PTXInstrumentor.h>
#include <ocelot/transforms/interface/Pass.h>

namespace analysis
{
    /*! \brief Test instrumentor for inserting kernels in a module */
	class ModulePassTestInstrumentor : public analysis::PTXInstrumentor
	{
		public:

            /*! \brief The description of the specified pass */
            std::string description;
        	
		public:
			/*! \brief The default constructor */
			ModulePassTestInstrumentor();

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

            /*! \brief extracts results for the instrumentation */
            void extractResults(std::ostream *out);
	};

}

#endif
