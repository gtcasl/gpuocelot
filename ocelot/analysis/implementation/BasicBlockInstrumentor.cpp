/*! \file BasicBlockInstrumentor.cpp
	\date Monday November 15, 2010
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The source file for the BasicBlockInstrumentor class.
*/

#ifndef BASIC_BLOCK_EXECUTION_INSTRUMENTOR_CPP_INCLUDED
#define BASIC_BLOCK_INSTRUMENTOR_CPP_INCLUDED

#include <ocelot/analysis/interface/BasicBlockInstrumentor.h>

#include <ocelot/cuda/interface/cuda_runtime.h>

#include <ocelot/analysis/interface/BasicBlockInstrumentationPass.h>
#include <ocelot/analysis/interface/BasicBlockExecutionCountPass.h>
#include <ocelot/ir/interface/Module.h>

#include <hydrazine/implementation/ArgumentParser.h>
#include <hydrazine/implementation/string.h>
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/Exception.h>

#include <fstream>

namespace analysis
{

    void BasicBlockInstrumentor::analyze(ir::Module &module) {
        basicBlocks = 0;
        for (ir::Module::KernelMap::const_iterator kernel = module.kernels().begin(); 
		    kernel != module.kernels().end(); ++kernel) {
            basicBlocks += (kernel->second)->dfg()->size();
        }
    }

    void BasicBlockInstrumentor::initialize() {
        
        counter = 0;
        cudaMalloc((void **) &counter, basicBlocks * ctas * threads * sizeof(size_t));
        cudaMemset( counter, 0, basicBlocks * ctas * threads * sizeof( size_t ));
        
        cudaMemcpyToSymbol(((BasicBlockInstrumentationPass *)pass)->basicBlockCounterBase().c_str(), &counter, sizeof(*counter), 0, cudaMemcpyHostToDevice);
    }

    analysis::Pass *BasicBlockInstrumentor::createPass() {
        return new analysis::BasicBlockExecutionCountPass;           
    }

    void BasicBlockInstrumentor::finalize() {

        size_t *counterHost = new size_t[basicBlocks * threads * ctas];
        cudaMemcpy(counterHost, counter, basicBlocks * threads * ctas * sizeof( size_t ), cudaMemcpyDeviceToHost);
       
        std::cout << "\n\n" << kernelName << ":\n";
        std::cout << "\n--------------- " << description << " Per Thread ---------------\n\n";

        unsigned int i = 0;
        unsigned int j = 0;
        unsigned int k = 0;
        
        for(k = 1; k <= ctas; k++) {
            std::cout << "CTA " << k << ":\n";
            for(i = 0; i < threads; i++) {
                std::cout << "Thread " << (i + 1) << ":\n";
                for(j = 0; j < basicBlocks; j++) {
                    std::cout << "basicBlock " << (j + 1) << ": " << counterHost[basicBlocks] << "\n";
                }
            }   
        }

        delete[] counterHost;
        cudaFree(counter);
    }

    BasicBlockInstrumentor::BasicBlockInstrumentor() : description("Basic Block Execution Count") {

    }

    BasicBlockInstrumentor::BasicBlockInstrumentor(const std::string input, const std::string output, unsigned int ctas, unsigned int threads ) :
        description("Basic Block Execution Count")
    {
        PTXInstrumentor::input = input;
        PTXInstrumentor::output = output;
        PTXInstrumentor::ctas = ctas;
        PTXInstrumentor::threads = threads;    
    }

}

#endif
