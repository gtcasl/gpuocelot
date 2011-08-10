/*! \file MemoryEfficiencyInstrumentor.h
	\date Saturday July 30, 2011
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The header file for MemoryEfficiencyInstrumentor
*/

#ifndef MEMORY_EFFICIENCY_INSTRUMENTOR_H_INCLUDED
#define MEMORY_EFFICIENCY_INSTRUMENTOR_H_INCLUDED

#include <string>
#include <ocelot/ir/interface/Module.h>
#include <ocelot/analysis/interface/PTXInstrumentor.h>
#include <ocelot/transforms/interface/Pass.h>

namespace analysis
{
    /*! \brief Able to run the memory efficiency instrumentation pass over PTX modules */
	class MemoryEfficiencyInstrumentor : public analysis::PTXInstrumentor
	{
		public:
		
            /*! \brief The memory efficiency counter */
            size_t *counter;        

            /*! \brief The description of the specified pass */
            std::string description;
        	
		public:
			/*! \brief The default constructor */
			MemoryEfficiencyInstrumentor();

            /*! \brief The checkConditions method verifies that the defined conditions are met for this instrumentation */
            void checkConditions();

            /*! \brief The analyze method performs any necessary static analysis */
            virtual void analyze(ir::Module &module);

            /*! \brief The initialize method performs any necessary CUDA runtime initialization prior to instrumentation */
            void initialize();

            /*! \brief The createPasses method instantiates the instrumentation passes */
            void createPasses();

            /*! \brief The finalize method performs any necessary CUDA runtime actions after instrumentation */
            void finalize();	

            /*! \brief extracts results for the instrumentation */
            void extractResults(std::ostream *out);
	};

}

#endif
