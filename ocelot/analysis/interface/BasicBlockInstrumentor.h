/*! \file BasicBlockInstrumentor.h
	\date Monday November 15, 2010
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The header file for BasicBlockInstrumentor
*/

#ifndef BASIC_BLOCK_INSTRUMENTOR_H_INCLUDED
#define BASIC_BLOCK_INSTRUMENTOR_H_INCLUDED

#include <string>
#include <ocelot/ir/interface/Module.h>
#include <ocelot/analysis/interface/PTXInstrumentor.h>
#include <ocelot/analysis/interface/Pass.h>

namespace analysis
{
    /*! \brief Able to run the basic block instrumentation passes over PTX modules */
	class BasicBlockInstrumentor : public analysis::PTXInstrumentor
	{
		public:
			
            /*! \brief The basic block counter */
            size_t *counter;        

            /*! \brief The number of basic blocks */
            unsigned int basicBlocks;
        
            /*! \brief The description of the specified pass */
            std::string description;
			
		public:
			/*! \brief The default constructor */
			BasicBlockInstrumentor(); 

            /*! \brief The analyze method performs any necessary static analysis */
            virtual void analyze(ir::Module &module);

            /*! \brief The initialize method performs any necessary CUDA runtime initialization prior to instrumentation */
            void initialize();

            /*! \brief The createPass method instantiates the instrumentation pass */
            analysis::Pass *createPass();

            /*! \brief The finalize method performs any necessary CUDA runtime actions after instrumentation */
            void finalize();	

            /*! \brief extracts results for the basic block execution count instrumentation */
            size_t* extractResults(std::ostream *out);

            /*! \brief emits JSON for the basic block execution count instrumentation */
            void emitJSON(size_t* info);
	};

}

#endif
