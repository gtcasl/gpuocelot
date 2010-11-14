/*! \file BasicBlockExecutionCountInstrumentor.h
	\date Saturday November 13, 2010
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The header file for BasicBlockExecutionCountInstrumentor
*/

#ifndef BASIC_BLOCK_EXECUTION_COUNT_INSTRUMENTOR_H_INCLUDED
#define BASIC_BLOCK_EXECUTION_COUNT_INSTRUMENTOR_H_INCLUDED

#include <string>
#include <ocelot/ir/interface/Module.h>
#include <ocelot/analysis/interface/PTXInstrumentor.h>
#include <ocelot/analysis/interface/Pass.h>

namespace analysis
{
	/*! \brief Able to run the CountBasicBlockExecutionPass over PTX modules */
	class BasicBlockExecutionCountInstrumentor : public analysis::PTXInstrumentor
	{
		public:
			
            /*! \brief The basic block counter */
            size_t *counter;        

            /*! \brief The number of basic blocks */
            unsigned int basicBlocks;
			
		public:
			/*! \brief The default constructor */
			BasicBlockExecutionCountInstrumentor();

            /*! \brief The constructor that sets the defaults */
            BasicBlockExecutionCountInstrumentor(const std::string input, const std::string output, unsigned int ctas, unsigned int threads );

            /*! \brief The initialize method performs any necessary CUDA runtime initialization prior to instrumentation */
            void initialize();

            /*! \brief The createPass method instantiates the instrumentation pass */
            analysis::Pass *createPass();

            /*! \brief The finalize method performs any necessary CUDA runtime actions after instrumentation */
            void finalize();	
	};
}

#endif
