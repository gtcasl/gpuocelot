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
        
        warpCount = (threads * threadBlocks)/32;

        if(cudaMalloc((void **) &counter, entries * warpCount * sizeof(size_t)) != cudaSuccess){
            throw hydrazine::Exception( "Could not allocate sufficient memory on device (cudaMalloc failed)!" );
        }
        if(cudaMemset( counter, 0, entries * warpCount  * sizeof( size_t )) != cudaSuccess){
            throw hydrazine::Exception( "cudaMemset failed!" );
        }
        
        if(cudaMemcpyToSymbol(symbol.c_str(), &counter, sizeof(size_t *), 0, cudaMemcpyHostToDevice) != cudaSuccess) {
            throw hydrazine::Exception( "cudaMemcpyToSymbol failed!");
        }
    }

    void WarpReductionInstrumentor::createPasses() {
        
        entries = 1;

        switch(type){
            case memoryEfficiency:
            {
                transforms::CToPTXInstrumentationPass *pass = new transforms::CToPTXInstrumentationPass("resources/memoryEfficiency.c");
                symbol = pass->baseAddress;
                transforms::CToPTXModulePass *modulePass = new transforms::CToPTXModulePass(UNIQUE_ELEMENT_COUNT);
                modulePass->parameterMap = pass->parameterMap;
                
                passes[0] = pass;   
                passes[1] = modulePass;
                
                entries = 2;
            }
            break;
            case branchDivergence:
            {
                transforms::CToPTXInstrumentationPass *pass = new transforms::CToPTXInstrumentationPass("resources/branchDivergence.c");
                symbol = pass->baseAddress;
                
                passes[0] = pass;   
                
                entries = 2;
            }
            break;
            case instructionCount:
            {
                transforms::CToPTXInstrumentationPass *pass = new transforms::CToPTXInstrumentationPass("resources/warpInstructionCount.c");
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

        size_t *info = new size_t[entries * warpCount];
        if(counter) {
            cudaMemcpy(info, counter, entries * warpCount * sizeof( size_t ), cudaMemcpyDeviceToHost);
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
                        unsigned int dynamicWarps = 0;
                        unsigned int memTransactions = 0;
                        
                        for(unsigned int i = 0; i < warpCount; i++)
                        {
                            memTransactions += info[i * entries];
                            dynamicWarps += info[i * entries + 1];
                        }
                    
                        *out << "Dynamic Warps Executing Global Memory Operations: " << dynamicWarps << "\n";
                        *out << "Memory Transactions: " << memTransactions << "\n\n";              
                        *out << "Memory Efficiency: " << ((double)dynamicWarps/(double)memTransactions) * 100 << "%\n\n";
                    }
                    break;
                    case branchDivergence:
                    {
                        unsigned int divergentBranches = 0;
                        unsigned int totalCondBranches = 0;
                        
                        for(unsigned int i = 0; i < warpCount; i++)
                        {
                            divergentBranches += info[i * entries];
                            totalCondBranches += info[i * entries + 1];
                        }
                    
                        *out << "Divergent Dynamic Branches: " << divergentBranches << "\n";
                        *out << "Total Dynamic Conditional Branches: " << totalCondBranches << "\n\n";              
                        *out << "Branch Divergence: " << ((double)divergentBranches/(double)totalCondBranches) * 100 << "%\n\n";
                    
                    }
                    break;
                    case instructionCount:
                    {
                        unsigned int instCount = 0;
                        for(unsigned int i = 0; i < warpCount; i++)
                            instCount += info[0];
                        
                        *out << "\nDynamic Instruction Count: " << instCount << "\n\n";
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
