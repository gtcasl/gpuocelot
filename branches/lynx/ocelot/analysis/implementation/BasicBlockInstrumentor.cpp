/*! \file BasicBlockInstrumentor.cpp
	\date Monday November 15, 2010
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The source file for the BasicBlockInstrumentor class.
*/

#ifndef BASIC_BLOCK_INSTRUMENTOR_CPP_INCLUDED
#define BASIC_BLOCK_INSTRUMENTOR_CPP_INCLUDED

#include <ocelot/analysis/interface/BasicBlockInstrumentor.h>

#include <ocelot/cuda/interface/cuda_runtime.h>

#include <ocelot/transforms/interface/CToPTXInstrumentationPass.h>
#include <ocelot/transforms/interface/MemoryIntensityPass.h>
#include <ocelot/transforms/interface/DynamicInstructionCountPass.h>
#include <ocelot/transforms/interface/BasicBlockExecutionCountPass.h>
#include <ocelot/transforms/interface/BasicBlockInstrumentationPass.h>
#include <ocelot/ir/interface/Module.h>

#include <hydrazine/implementation/ArgumentParser.h>
#include <hydrazine/implementation/string.h>
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/Exception.h>

#include <fstream>

using namespace hydrazine;

namespace analysis
{

    void BasicBlockInstrumentor::checkConditions() {
        conditionsMet = true;
    }

    void BasicBlockInstrumentor::analyze(ir::Module &module) {
    
        basicBlocks = 0;
        if(!kernelName.empty()){
            basicBlocks = module.getKernel(kernelName)->cfg()->size() - 2;
        }
        else {
            for (ir::Module::KernelMap::const_iterator kernel = module.kernels().begin(); 
		        kernel != module.kernels().end(); ++kernel) {
                basicBlocks += (kernel->second)->cfg()->size();
            }
        }

        for( ir::ControlFlowGraph::const_iterator block = module.getKernel(kernelName)->cfg()->begin(); 
			block != module.getKernel(kernelName)->cfg()->end(); ++block ) {
            if(block->label == "entry" || block->label == "exit")
                continue;
            labels.push_back(block->label);
        }

        
    }

    void BasicBlockInstrumentor::initialize() {
        
        counter = 0;

        if(cudaMalloc((void **) &counter, entries * basicBlocks * threadBlocks * threads * sizeof(size_t)) != cudaSuccess){
            throw hydrazine::Exception( "Could not allocate sufficient memory on device (cudaMalloc failed)!" );
        }
        if(cudaMemset( counter, 0, entries * basicBlocks * threadBlocks * threads * sizeof( size_t )) != cudaSuccess){
            throw hydrazine::Exception( "cudaMemset failed!" );
        }
        
        if(cudaMemcpyToSymbol(symbol.c_str(), &counter, sizeof(size_t *), 0, cudaMemcpyHostToDevice) != cudaSuccess) {
            throw hydrazine::Exception( "cudaMemcpyToSymbol failed!");
        }
    }

    transforms::Pass *BasicBlockInstrumentor::createPass() {
        
        transforms::CToPTXInstrumentationPass *pass = new transforms::CToPTXInstrumentationPass("resources/dynamicInstructionCount.c");
        symbol = pass->baseAddress;
        entries = 1;
        return pass;
        
        /*
        
        transforms::BasicBlockInstrumentationPass *basicBlockPass;
        entries = 1;        

        switch(type) {
            case executionCount:
                basicBlockPass = new transforms::BasicBlockExecutionCountPass;
                break;
            case instructionCount:
                basicBlockPass = new transforms::DynamicInstructionCountPass;
                break;
            case memoryIntensity:
                basicBlockPass = new transforms::MemoryIntensityPass;
                entries = 2;
                break;
            default:
                throw hydrazine::Exception( "No basic block instrumentation pass specified!" );
        }
        

        basicBlockPass->entries = entries;
        return basicBlockPass;          
        */
    }

    void BasicBlockInstrumentor::extractResults(std::ostream *out) {

        size_t *info = new size_t[entries * basicBlocks * threads * threadBlocks];
        if(counter) {
            cudaMemcpy(info, counter, entries * basicBlocks * threads * threadBlocks * sizeof( size_t ), cudaMemcpyDeviceToHost);
            cudaFree(counter);
        }

        _kernelProfile.basicBlockExecutionCountMap.clear();
        _kernelProfile.memoryOperationsMap.clear();

        size_t i = 0;
        size_t j = 0;
        size_t k = 0;
        double totalMemOps = 0;
        double totalCount = 0;
        
        for(k = 0; k < threadBlocks; k++) {
            for(i = 0; i < basicBlocks; i++) {
                for(j = 0; j < (threads * entries); j = j + entries) {
                    _kernelProfile.basicBlockExecutionCountMap[i] += info[(i * entries * threads) + (k * basicBlocks * threads * entries) + j];
                    if(type == memoryIntensity)
                        _kernelProfile.memoryOperationsMap[i] += info[(i * entries * threads) + (k * basicBlocks * threads * entries) + (j + 1)];
                    
                }
            }   
        }

        switch(fmt) {

            case json:

                *out << "{\n\"kernel\": " << kernelName << ",\n";
                *out << "\n\"threadBlocks\": " << threadBlocks << ",\n";
                *out << "\n\"threads\": " << threads << ",\n";
                *out << "\n\"counters\": {\n";

                for(j = 0; j < basicBlocks; j++) {
                    *out << "\"" << labels[j] << "\": " << _kernelProfile.basicBlockExecutionCountMap[j] << ", ";
                    if(type == memoryIntensity)
                         *out << _kernelProfile.memoryOperationsMap[j];
                
                    *out << "\n";
                }
                
                *out << "\n}\n}\n";

            break;
            case text:

                if(!deviceInfoWritten){
                    deviceInfo(out);
                    deviceInfoWritten = true;
                }

                *out << "Kernel Name: " << kernelName << "\n";
                *out << "Thread Block Count: " << threadBlocks << "\n";
                *out << "Thread Count: " << threads << "\n";
                

                
                if(type == executionCount)
                    *out << "\nBasic Block Execution Count:\n\n";
                else
                    *out << "\nDynamic Instruction Count:\n\n";

                for(j = 0; j < basicBlocks; j++) {
                    *out << labels[j] << ": " << _kernelProfile.basicBlockExecutionCountMap[j] << "\n";
                    totalCount += _kernelProfile.basicBlockExecutionCountMap[j];
                    
                }

                if(type == memoryIntensity){
                    *out << "\nMemory Intensity:\n\n";

                    for(j = 0; j < basicBlocks; j++) {
                        *out << "\"" << labels[j] << "\": " << "[" << _kernelProfile.memoryOperationsMap[j] << ":" << _kernelProfile.basicBlockExecutionCountMap[j] << "]\n";
                        totalMemOps += _kernelProfile.memoryOperationsMap[j];
                    }
                }

                if(type == instructionCount || type == memoryIntensity){

                    *out << "\nTotal Dynamic Instruction Count: " << totalCount << "\n";
                }            
                if(type == memoryIntensity) {
                    *out << "Aggregate Memory Intensity: " << "[" << totalMemOps << ":" << totalCount << "] " << (totalMemOps / totalCount) * 100 << " %\n";
                }    

                *out << "\n\n";        

            break;
        }

        if(info)
            delete[] info;
            
    }

    BasicBlockInstrumentor::BasicBlockInstrumentor() : description("Basic Block Execution Count Per Thread") {
    }
    

}

#endif
