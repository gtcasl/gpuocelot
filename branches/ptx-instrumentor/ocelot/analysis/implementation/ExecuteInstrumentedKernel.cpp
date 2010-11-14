/*! \file ExecuteInstrumentedKernel.cpp
	\date Monday October 4, 2010
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The source file for the ExecuteInstrumentedKernel class.
*/

#ifndef EXECUTE_INSTRUMENTED_KERNEL_CPP_INCLUDED
#define EXECUTE_INSTRUMENTED_KERNEL_CPP_INCLUDED

#include <ocelot/analysis/interface/ExecuteInstrumentedKernel.h>

#include <ocelot/analysis/interface/PTXInstrumentor.h>
#include <ocelot/analysis/interface/BasicBlockExecutionCountInstrumentor.h>

#include <hydrazine/implementation/ArgumentParser.h>
#include <hydrazine/implementation/string.h>
#include <hydrazine/implementation/debug.h>

#include <fstream>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace analysis
{
    void ExecuteInstrumentedKernel::execute( const std::string &input, const std::string &output, unsigned int ctas, unsigned int threads, const std::string& pass)
    {
        analysis::PTXInstrumentor *instrumentor;
	    if( pass == "basic-block-count" )
	    {
		    report( "  Matched basic-block-count." );
		    instrumentor = new analysis::BasicBlockExecutionCountInstrumentor(input, output, ctas, threads);
	    }
	    else 
	    {
		    std::cout << "==Ocelot== Warning: Unknown pass name - '" << pass 
			    << "'\n";
            return;
	    }

        instrumentor->instrument();    
        delete instrumentor;
    }
}

int main(int argc, char** argv)
{

    hydrazine::ArgumentParser parser( argc, argv );
	parser.description( "The Ocelot PTX Instrumentor." );
    analysis::ExecuteInstrumentedKernel instrumentedKernel;
    std::string pass;
    std::string input;
    std::string output;
    unsigned int ctas;
    unsigned int threads;

	parser.parse( "-i", "--input", input, "",
		"The ptx file to be insrumented." );
	parser.parse( "-o", "--output", output, 
		"_instrumented_" + input, "The resulting instrumented file." );
	parser.parse( "-c", "--ctas", ctas, 1,
		"The number of CTAs for this instrumentation." );
	parser.parse( "-t", "--threads", threads, 1, 
		"The number of threads for this instrumentation." );
    parser.parse( "-p", "--passes", pass, "", 
		"The instrumentation pass to perform." );
	parser.parse();

    instrumentedKernel.execute(input, output, ctas, threads, pass);

	return 0;	
}


#endif

