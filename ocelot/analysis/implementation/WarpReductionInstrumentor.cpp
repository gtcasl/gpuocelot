/*! \file WarpReductionInstrumentor.cpp
	\date Monday July 30, 2011
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The source file for the WarpReductionInstrumentor class.
*/

#ifndef WARP_REDUCTION_INSTRUMENTOR_CPP_INCLUDED
#define WARP_REDUCTION_INSTRUMENTOR_CPP_INCLUDED

#include <ocelot/analysis/interface/WarpReductionInstrumentor.h>

#include <ocelot/cuda/interface/cuda_runtime.h>

#include <ocelot/transforms/interface/CToPTXInstrumentationPass.h>
#include <ocelot/transforms/interface/CToPTXModulePass.h>
#include <ocelot/ir/interface/Module.h>

#include <hydrazine/implementation/ArgumentParser.h>
#include <hydrazine/implementation/string.h>
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/Exception.h>

#include <fstream>

using namespace hydrazine;

namespace analysis
{

    void WarpReductionInstrumentor::checkConditions() {
        conditionsMet = true;
    }

    void WarpReductionInstrumentor::analyze(ir::Module &module) {
             
    }

    void WarpReductionInstrumentor::initialize() {
        
        counter = 0;

        if(cudaMalloc((void **) &counter, 2 * sizeof(size_t)) != cudaSuccess){
            throw hydrazine::Exception( "Could not allocate sufficient memory on device (cudaMalloc failed)!" );
        }
        if(cudaMemset( counter, 0, 2 * sizeof( size_t )) != cudaSuccess){
            throw hydrazine::Exception( "cudaMemset failed!" );
        }

        sharedMemSize = threads * 8;
        
        if(cudaMemcpyToSymbol(symbol.c_str(), &counter, sizeof(size_t *), 0, cudaMemcpyHostToDevice) != cudaSuccess) {
            throw hydrazine::Exception( "cudaMemcpyToSymbol failed!");
        }
    }

    void WarpReductionInstrumentor::createPasses() {

        switch(type){
            case memoryEfficiency:
            {
                transforms::CToPTXInstrumentationPass *pass = new transforms::CToPTXInstrumentationPass("resources/memoryEfficiency.c");
                symbol = pass->baseAddress;
                transforms::CToPTXModulePass *modulePass = new transforms::CToPTXModulePass(UNIQUE_ELEMENT_COUNT);
                modulePass->parameterMap = pass->parameterMap;
                
                passes[0] = pass;   
                passes[1] = modulePass;
            }
            break;
            case branchDivergence:
            {
                transforms::CToPTXInstrumentationPass *pass = new transforms::CToPTXInstrumentationPass("resources/branchDivergence.c");
                symbol = pass->baseAddress;
                transforms::CToPTXModulePass *modulePass = new transforms::CToPTXModulePass(UNIQUE_ELEMENT_COUNT);
                modulePass->parameterMap = pass->parameterMap;
                
                passes[0] = pass;   
                passes[1] = modulePass;
            }
            break;
            case instructionCount:
            {
                transforms::CToPTXInstrumentationPass *pass = new transforms::CToPTXInstrumentationPass("resources/optimizedDynamicInstructionCount.c");
                symbol = pass->baseAddress;
                
                passes[0] = pass;   
            }
            break;
            default:
                throw hydrazine::Exception("No instrumentation type specified!");
            break;
        }

        
    }

    void WarpReductionInstrumentor::extractResults(std::ostream *out) {

        size_t *info = new size_t[2];
        if(counter) {
            cudaMemcpy(info, counter, 2 * sizeof( size_t ), cudaMemcpyDeviceToHost);
            cudaFree(counter);
        }

        switch(fmt) {

            case json:

                *out << "{\n\"kernel\": " << kernelName << ",\n";
                *out << "\n\"threadBlocks\": " << threadBlocks << ",\n";
                *out << "\n\"threads\": " << threads << ",\n";
                *out << "\n\"counters\": {\n";
                
                *out << "\n}\n";

            break;
            case text:

                *out << "Thread Block Count: " << threadBlocks << "\n";
		        *out << "Kernel Name: " << kernelName << "\n";		
		        *out << "Thread Count: " << threads << "\n";
            
                switch(type)
                {
                    case memoryEfficiency:
                    {
                        *out << "Dynamic Warps Executing Global Memory Operations: " << info[1] << "\n";
                        *out << "Memory Transactions: " << info[0] << "\n\n";              
                        *out << "Memory Efficiency: " << ((double)info[1]/(double)info[0]) * 100 << "%\n\n";
                    }
                    break;
                    case branchDivergence:
                    {
                        *out << "Divergent Dynamic Branches: " << info[1] << "\n";
                        *out << "Total Dynamic Branches: " << info[0] << "\n\n";              
                        *out << "Branch Divergence: " << ((double)info[1]/(double)info[0]) * 100 << "%\n\n";
                    }
                    break;
                    case instructionCount:
                    {
                        *out << "Instruction Count: " << info[0] << "\n";
                    }                    
                    break;
                    default:
                    break;
                }

            break;
        }

        if(info)
            delete[] info;
            
    }

    WarpReductionInstrumentor::WarpReductionInstrumentor() : 
        description("Warp Reduction Instrumentor") {
    }
    

}

#endif
