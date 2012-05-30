/*! \file MeasureWarpReductionInstrumentor.cpp
	\date Monday July 30, 2011
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The source file for the MeasureWarpReductionInstrumentor class.
*/

#ifndef MEASURE_WARP_REDUCTION_INSTRUMENTOR_CPP_INCLUDED
#define MEASURE_WARP_REDUCTION_INSTRUMENTOR_CPP_INCLUDED

#include <ocelot/analysis/interface/MeasureWarpReductionInstrumentor.h>

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

namespace instrumentation
{

    void MeasureWarpReductionInstrumentor::checkConditions() {
        conditionsMet = true;
    }

    void MeasureWarpReductionInstrumentor::analyze(ir::Module &module) {
             
    }

    void MeasureWarpReductionInstrumentor::initialize() {
        
        counter = 0;
        
        warpCount = (threads * threadBlocks)/32;
        if(warpCount == 0)
            warpCount = 1;

        if(cudaMalloc((void **) &counter, ((entries * warpCount) + (2 * threadBlocks)) * sizeof(size_t)) != cudaSuccess){
            throw hydrazine::Exception( "Could not allocate sufficient memory on device (cudaMalloc failed)!" );
        }
        if(cudaMemset( counter, 0, ((entries * warpCount) + (2 * threadBlocks))  * sizeof( size_t )) != cudaSuccess){
            throw hydrazine::Exception( "cudaMemset failed!" );
        }
        
        if(cudaMemcpyToSymbol(symbol.c_str(), &counter, sizeof(size_t *), 0, cudaMemcpyHostToDevice) != cudaSuccess) {
            throw hydrazine::Exception( "cudaMemcpyToSymbol failed!");
        }
    }

    void MeasureWarpReductionInstrumentor::createPasses() {
        
        entries = 1;

        switch(type){
            case memoryEfficiency:
            {
                transforms::CToPTXInstrumentationPass *pass = new transforms::CToPTXInstrumentationPass("resources/measureMemEfficiency.c");
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
                transforms::CToPTXInstrumentationPass *pass = new transforms::CToPTXInstrumentationPass("resources/measureBranchDivergence.c");
                symbol = pass->baseAddress;
                
                passes[0] = pass;   
                
                entries = 2;
            }
            break;
            case instructionCount:
            {
                transforms::CToPTXInstrumentationPass *pass = new transforms::CToPTXInstrumentationPass("resources/measureWarpIC.c");
                symbol = pass->baseAddress;
                
                passes[0] = pass;   
            }
            break;
            default:
                throw hydrazine::Exception("No instrumentation type specified!");
            break;
        }

        
    }

    void MeasureWarpReductionInstrumentor::extractResults(std::ostream *out) {

        size_t *info = new size_t[((entries * warpCount) + (2 * threadBlocks))];
        if(counter) {
            cudaMemcpy(info, counter, ((entries * warpCount) + (2 * threadBlocks)) * sizeof( size_t ), cudaMemcpyDeviceToHost);
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
    
                /*
                *out << "Thread Block Count: " << threadBlocks << "\n";
		        *out << "Kernel Name: " << kernelName << "\n";		
		        *out << "Thread Count: " << threads << "\n";
                */
            
                size_t smid = 0;
                _kernelProfile.processorToClockCyclesMap.clear();
                
                for(size_t i = 0; i < threadBlocks; i++) {
                    smid = info[ i*2 + 1 + warpCount];
                    _kernelProfile.processorToClockCyclesMap[smid] += info[i*2 + warpCount];
                } 

                std::vector<double> clockCyclesPerSM;
                clockCyclesPerSM.clear();

                for(KernelProfile::ProcessorToClockCyclesMap::const_iterator it = 
                    _kernelProfile.processorToClockCyclesMap.begin();
                    it != _kernelProfile.processorToClockCyclesMap.end(); ++it) {
                    clockCyclesPerSM.push_back(it->second);
                }

                struct cudaDeviceProp properties;
                cudaGetDeviceProperties(&properties, 0);

                _kernelProfile.maxSMRuntime = *(std::max_element(clockCyclesPerSM.begin(), 
                    clockCyclesPerSM.end()))/properties.clockRate;

                *out << "Clock Cycle Runtime: " << _kernelProfile.maxSMRuntime << " ms\n";

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
                    
                        /*
                        *out << "Dynamic Warps Executing Global Memory Operations: " << dynamicWarps << "\n";
                        *out << "Memory Transactions: " << memTransactions << "\n\n";              
                        *out << "Memory Efficiency: " << ((double)dynamicWarps/(double)memTransactions) * 100 << "%\n\n";
                        */
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
                    
                        /*
                        *out << "Divergent Dynamic Branches: " << divergentBranches << "\n";
                        *out << "Total Dynamic Conditional Branches: " << totalCondBranches << "\n\n";              
                        *out << "Branch Divergence: " << ((double)divergentBranches/(double)totalCondBranches) * 100 << "%\n\n";
                        */
                    
                    }
                    break;
                    case instructionCount:
                    {
                    
                        _kernelProfile.instructionCount = 0;
                        for(unsigned int i = 0; i < warpCount; i++)
                            _kernelProfile.instructionCount += info[i];
                        
                        //*out << "\nDynamic Instruction Count: " << _kernelProfile.instructionCount << "\n";
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

    MeasureWarpReductionInstrumentor::MeasureWarpReductionInstrumentor() : 
        description("Measure Warp Reduction Instrumentor") {
    }
    

}

#endif
