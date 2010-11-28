/*! \file PTXInstrumentor.h
	\date Saturday November 13, 2010
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The header file for the Ocelot PTX Instrumentor
*/

#ifndef PTX_INSTRUMENTOR_H_INCLUDED
#define PTX_INSTRUMENTOR_H_INCLUDED

#include <string>
#include <vector>
#include <ocelot/ir/interface/Module.h>
#include <ocelot/analysis/interface/Pass.h>
#include <hydrazine/implementation/json.h>

#include <ostream>

namespace analysis
{
	/*! \brief Able to run various instrumentation passes over PTX modules */
	class PTXInstrumentor
	{
		public:

			/*! \brief Enables automatic output as JSON */
			bool enableJSON;

			/*! \brief device name for JSON output */
			std::string deviceName;
			
			/*! \brief The input file being instrumented */
			std::string input;
			
			/*! \brief The output file being generated */
			std::string output;
            
            /*! \brief The PTX module being instrumented */
            ir::Module *module;
            
            /*! \brief The name of kernel being instrumented */
			std::string kernelName;        

            /*! \brief The instrumentation pass */
            analysis::Pass *pass;
            
            /*! \brief The number of thread blocks or CTAs specified for this execution */
            unsigned int threadBlocks;

            /*! \brief The number of threads specified for this execution */
            unsigned int threads;
			
			
		public:
		

            /*! \brief The analyze method performs any necessary static analysis */
            virtual void analyze(ir::Module &module) = 0;

            /*! \brief Performs the instrumentation */
			void instrument();		

            /*! \brief Performs the instrumentation */
            void instrument(ir::Module& module);	

            /*! \brief The initialize method performs any necessary CUDA runtime initialization prior to instrumentation */
            virtual void initialize() = 0;

            /*! \brief The finalize method performs any necessary CUDA runtime actions after instrumentation */
            void finalize();

            /*! \brief The createPass method instantiates the instrumentation pass */
            virtual analysis::Pass *createPass() = 0;

            /*! \brief The jsonEmitter method creates a JSON emitter to display JSON */
            void jsonEmitter(std::string metric, hydrazine::json::Object *stats);
			
            /*! \brief Instrumentation-specific JSON */
            virtual void emitJSON(size_t * info) = 0;

            /*! \brief Extracts instrumentation-specific data */
            virtual size_t* extractResults(std::ostream *out) = 0;
	};

    typedef std::vector< PTXInstrumentor *> PTXInstrumentorVector;
}

#endif
