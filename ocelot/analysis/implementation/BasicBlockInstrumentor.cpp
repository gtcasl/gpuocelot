/*! \file BasicBlockInstrumentor.cpp
	\date Monday November 15, 2010
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The source file for the BasicBlockInstrumentor class.
*/

#ifndef BASIC_BLOCK_INSTRUMENTOR_CPP_INCLUDED
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
        cudaMalloc((void **) &counter, basicBlocks * threadBlocks * threads * sizeof(size_t));
        cudaMemset( counter, 0, basicBlocks * threadBlocks * threads * sizeof( size_t ));
        
        cudaMemcpyToSymbol(((BasicBlockInstrumentationPass *)pass)->basicBlockCounterBase().c_str(), &counter, sizeof(*counter), 0, cudaMemcpyHostToDevice);
    }

    analysis::Pass *BasicBlockInstrumentor::createPass() {
        return new analysis::BasicBlockExecutionCountPass;           
    }

    size_t* BasicBlockInstrumentor::extractResults(std::ostream *out) {

        size_t *info = new size_t[basicBlocks * threads * threadBlocks];
        if(counter) {
            cudaMemcpy(info, counter, basicBlocks * threads * threadBlocks * sizeof( size_t ), cudaMemcpyDeviceToHost);
            cudaFree(counter);
        }

        *out << "\n\n" << kernelName << ":\n";
        *out << "\n--------------- " << description << " ---------------\n\n";

        unsigned int i = 0;
        unsigned int j = 0;
        unsigned int k = 0;
        
        for(k = 1; k <= threadBlocks; k++) {
            *out << "CTA " << k << ":\n";
            for(i = 0; i < threads; i++) {
                *out << "Thread " << (i + 1) << ":\n";
                for(j = 0; j < basicBlocks; j++) {
                    *out << "basicBlock " << (j + 1) << ": " << info[basicBlocks] << "\n";
                }
            }   
        }
        
        return info;
    }

    void BasicBlockInstrumentor::emitJSON(size_t *info) {

    }

    BasicBlockInstrumentor::BasicBlockInstrumentor() : description("Basic Block Execution Count Per Thread") {

    }

}

#endif
