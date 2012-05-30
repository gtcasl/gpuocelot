/*! \file MeasureBasicBlockInstrumentor.cpp
	\date Monday November 15, 2010
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The source file for the MeasureBasicBlockInstrumentor class.
*/

#ifndef BASIC_BLOCK_INSTRUMENTOR_CPP_INCLUDED
#define BASIC_BLOCK_INSTRUMENTOR_CPP_INCLUDED

#include <ocelot/instrumentation/interface/MeasureBasicBlockInstrumentor.h>

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

namespace instrumentation
{

    void MeasureBasicBlockInstrumentor::checkConditions() {
        conditionsMet = true;
    }

    void MeasureBasicBlockInstrumentor::analyze(ir::Module &module) {
        
        for (ir::Module::KernelMap::const_iterator kernel = module.kernels().begin(); 
	        kernel != module.kernels().end(); ++kernel) {
	        kernelDataMap[kernel->first] = kernel->second->cfg()->size() - 2;
        
            for( ir::ControlFlowGraph::const_iterator block = kernel->second->cfg()->begin(); 
			block != kernel->second->cfg()->end(); ++block ) {
                if(block->label == "entry" || block->label == "exit")
                    continue;
                kernelLabelsMap[kernel->first].push_back(block->label);
            }
        }
        
    }

    void MeasureBasicBlockInstrumentor::initialize() {
        
        counter = 0;

        if(cudaMalloc((void **) &counter, ((entries * kernelDataMap[kernelName] * threadBlocks * threads) + (2 * threadBlocks)) * sizeof(size_t)) != cudaSuccess){
            throw hydrazine::Exception( "Could not allocate sufficient memory on device (cudaMalloc failed)!" );
        }
        if(cudaMemset( counter, 0, ((entries * kernelDataMap[kernelName] * threadBlocks * threads) + (2 * threadBlocks)) * sizeof( size_t )) != cudaSuccess){
            throw hydrazine::Exception( "cudaMemset failed!" );
        }
        
        if(cudaMemcpyToSymbol(symbol.c_str(), &counter, sizeof(size_t *), 0, cudaMemcpyHostToDevice) != cudaSuccess) {
            throw hydrazine::Exception( "cudaMemcpyToSymbol failed!");
        }
    }

    void MeasureBasicBlockInstrumentor::createPasses() {
        
        entries = 1;
        transforms::CToPTXInstrumentationPass *pass;
        
        switch(type) {
            case executionCount:
            {
                pass = new transforms::CToPTXInstrumentationPass("resources/basicBlockExecutionCount.c");
                symbol = pass->baseAddress;
                break;
            }
            case instructionCount:
            {
                pass = new transforms::CToPTXInstrumentationPass("resources/measureThreadIC.c");
                symbol = pass->baseAddress;
                break;
            }
            default:
                throw hydrazine::Exception( "No basic block instrumentation pass specified!" );
        }
        
        passes[0] = pass; 
    }

    void MeasureBasicBlockInstrumentor::extractResults(std::ostream *out) {

        size_t *info = new size_t[((entries * kernelDataMap[kernelName] * threadBlocks * threads) + (2 * threadBlocks))];
        if(counter) {
            cudaMemcpy(info, counter, ((entries * kernelDataMap[kernelName] * threadBlocks * threads) + (2 * threadBlocks)) * sizeof( size_t ), cudaMemcpyDeviceToHost);
            cudaFree(counter);
        }

        _kernelProfile.basicBlockExecutionCountMap.clear();
        _kernelProfile.memoryOperationsMap.clear();

        size_t j = 0;
 
        _kernelProfile.instructionCount = 0;
    

        switch(fmt) {

            case json:

                *out << "{\n\"kernel\": " << kernelName << ",\n";
                *out << "\n\"threadBlocks\": " << threadBlocks << ",\n";
                *out << "\n\"threads\": " << threads << ",\n";
                *out << "\n\"counters\": {\n";

                *out << "\n}\n}\n";

            break;
            case text:

                if(!deviceInfoWritten){
                    deviceInfo(out);
                    deviceInfoWritten = true;
                }

                *out << "Kernel Name: " << kernelName << "\n";
                *out << "Thread Block Count: " << threadBlocks << "\n";
                *out << "Thread Count: " << threads << "\n\n";

                for(j = 0; j < kernelDataMap[kernelName] * threads * threadBlocks; j++) {
                   
                    _kernelProfile.instructionCount += info[j];
                    
                }

                size_t smid = 0;
                _kernelProfile.processorToClockCyclesMap.clear();
                size_t totalSize = kernelDataMap[kernelName] * threads * threadBlocks; 
                
                for(size_t i = 0; i < threadBlocks; i++) {
                    smid = info[ i*2 + 1 + totalSize];
                    _kernelProfile.processorToClockCyclesMap[smid] += info[i*2 + totalSize];
                } 

                std::vector<double> clockCyclesPerSM;
                clockCyclesPerSM.clear();

                for(instrumentation::KernelProfile::ProcessorToClockCyclesMap::const_iterator it = 
                    _kernelProfile.processorToClockCyclesMap.begin();
                    it != _kernelProfile.processorToClockCyclesMap.end(); ++it) {
                    clockCyclesPerSM.push_back(it->second);
                }

                struct cudaDeviceProp properties;
                cudaGetDeviceProperties(&properties, 0);

                _kernelProfile.maxSMRuntime = *(std::max_element(clockCyclesPerSM.begin(), 
                    clockCyclesPerSM.end()))/properties.clockRate;

                *out << "\nDynamic Instruction Count: " << _kernelProfile.instructionCount << "\n";
                *out << "\nClock Cycle Runtime: " << _kernelProfile.maxSMRuntime << " ms\n\n";
              
                *out << "\n\n";        

            break;
        }

        if(info)
            delete[] info;
            
    }

    MeasureBasicBlockInstrumentor::MeasureBasicBlockInstrumentor() : description("Measure Basic Block Instrumentor") {
    }
    

}

#endif
