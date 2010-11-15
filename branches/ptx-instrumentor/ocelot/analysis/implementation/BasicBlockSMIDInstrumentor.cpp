/*! \file BasicBlockSMIDInstrumentor.cpp
	\date Sunday November 14, 2010
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The source file for the BasicBlockSMIDInstrumentor class.
*/

#ifndef BASIC_BLOCK_SMID_INSTRUMENTOR_CPP_INCLUDED
#define BASIC_BLOCK_SMID_INSTRUMENTOR_CPP_INCLUDED

#include <ocelot/analysis/interface/BasicBlockSMIDInstrumentor.h>

#include <ocelot/cuda/interface/cuda_runtime.h>

#include <ocelot/analysis/interface/BasicBlockSMIDPass.h>
#include <ocelot/ir/interface/Module.h>

#include <hydrazine/implementation/ArgumentParser.h>
#include <hydrazine/implementation/string.h>
#include <hydrazine/implementation/debug.h>

#include <fstream>

namespace analysis
{
    void BasicBlockSMIDInstrumentor::initialize() {
        

        basicBlocks = module->getKernel(kernelName)->cfg()->size();
      
        counter = 0;

        cudaMalloc((void **) &counter, basicBlocks * ctas * threads * sizeof(size_t));
        cudaMemset( counter, 0, basicBlocks * ctas * threads * sizeof( size_t ));

        cudaMemcpyToSymbol(((BasicBlockSMIDPass *)pass)->basicBlockCounterBase().c_str(), &counter, sizeof(*counter), 0, cudaMemcpyHostToDevice);

        cudaConfigureCall( dim3(ctas, 1, 1), dim3( threads, 1, 1), 0, 0 );      
    }

    analysis::Pass *BasicBlockSMIDInstrumentor::createPass() {
        return new analysis::BasicBlockSMIDPass;
    }

    void BasicBlockSMIDInstrumentor::finalize() {

        size_t *counterHost = new size_t[basicBlocks * threads * ctas];
        cudaMemcpy(counterHost, counter, basicBlocks * threads * ctas * sizeof( size_t ), cudaMemcpyDeviceToHost);
        
        std::cout << "\n\n" << kernelName << ":\n";
        std::cout << "\n--------------- Basic Block SM (Processor) ID Per Thread ---------------\n\n";

        unsigned int i = 0;
        unsigned int j = 0;
        unsigned int k = 0;
        
        for(k = 1; k <= ctas; k++) {
            std::cout << "CTA " << k << ":\n";
            for(i = 0; i < threads; i++) {
                std::cout << "Thread " << (i + 1) << ":\n";
                for(j = 0; j < basicBlocks; j++) {
                    std::cout << "basicBlock " << (j + 1) << ": " << counterHost[(i*basicBlocks * ctas) + j] << "\n";
                }
            }   
        }

        delete[] counterHost;
        cudaFree(counter);
    }

    BasicBlockSMIDInstrumentor::BasicBlockSMIDInstrumentor() {

    }

    BasicBlockSMIDInstrumentor::BasicBlockSMIDInstrumentor(const std::string input, const std::string output, unsigned int ctas, unsigned int threads )
    {
        PTXInstrumentor::input = input;
        PTXInstrumentor::output = output;
        PTXInstrumentor::ctas = ctas;
        PTXInstrumentor::threads = threads;    
    }

}

#endif
