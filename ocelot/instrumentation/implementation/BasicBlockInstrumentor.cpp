/*! \file BasicBlockInstrumentor.cpp
	\date Monday November 15, 2010
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The source file for the BasicBlockInstrumentor class.
*/

#ifndef BASIC_BLOCK_INSTRUMENTOR_CPP_INCLUDED
#define BASIC_BLOCK_INSTRUMENTOR_CPP_INCLUDED

#include <ocelot/instrumentation/interface/BasicBlockInstrumentor.h>
#include <ocelot/instrumentation/interface/InstrumentationConfiguration.h>

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
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif 

#define REPORT_BASE 1

namespace instrumentation
{

    void BasicBlockInstrumentor::checkConditions() {
        conditionsMet = true;
    }

    void BasicBlockInstrumentor::analyze(ir::Module &module, const executive::Device &device) {
        
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

    void BasicBlockInstrumentor::initialize() {
		if(threadBlocks < 1 ) 
			threadBlocks = 1;
        
        counter = 0;
		report("allocating " << entries*kernelDataMap[kernelName] * threadBlocks * threads);
        if(cudaMalloc((void **) &counter, (entries * kernelDataMap[kernelName] * threadBlocks * threads) * sizeof(size_t)) != cudaSuccess){
            throw hydrazine::Exception( "Could not allocate sufficient memory on device (cudaMalloc failed)!" );
        }
        if(cudaMemset( counter, 0, (entries * kernelDataMap[kernelName] * threadBlocks * threads) * sizeof( size_t )) != cudaSuccess){
            throw hydrazine::Exception( "cudaMemset failed!" );
        }
        
        if(cudaMemcpyToSymbol(symbol.c_str(), &counter, sizeof(size_t *), 0, cudaMemcpyHostToDevice) != cudaSuccess) {
            throw hydrazine::Exception( "cudaMemcpyToSymbol failed!");
        }
    }

    void BasicBlockInstrumentor::createPasses() {
        
        entries = 1;
        //transforms::CToPTXInstrumentationPass *pass;
        
        switch(type) {
           /* if(0) //case orig_executionCount:  //FIXME add new variable for fine grain block execution count
            {
                pass = new transforms::CToPTXInstrumentationPass("resources/basicBlockExecutionCount.c");
                _profile.type = EXECUTION_COUNT;
                symbol = pass->baseAddress;
                break;
            }*/
			case executionCount:
			{
				transforms::BasicBlockExecutionCountPass *pass = new transforms::BasicBlockExecutionCountPass();
                symbol = pass->baseAddress;
                passes[0] = pass;   
                entries = pass->entries;
				break;
			}
            case instructionCount:
            {
                //pass = new transforms::CToPTXInstrumentationPass("resources/threadInstructionCount.c");
                //_profile.type = INST_COUNT;
                //symbol = pass->baseAddress;
                break;
            }
            default:
                throw hydrazine::Exception( "No basic block instrumentation pass specified!" );
        }
        
        //passes[0] = pass; 
    }

    void BasicBlockInstrumentor::extractResults(std::ostream *out) {

        size_t *info = new size_t[(entries * kernelDataMap[kernelName] * threadBlocks * threads)];
        if(counter) {
            cudaMemcpy(info, counter, (entries * kernelDataMap[kernelName] * threadBlocks * threads) * sizeof( size_t ), cudaMemcpyDeviceToHost);
            cudaFree(counter);
        }

        _kernelProfile.basicBlockExecutionCountMap.clear();
        _kernelProfile.memoryOperationsMap.clear();

        size_t j = 0;
    
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
                
                _kernelProfile.instructionCount = 0;
                
                for(j = 0; j < kernelDataMap[kernelName] * threads * threadBlocks; j++) {
                   
                    _kernelProfile.instructionCount += info[j];
                }

                *out << "\nDynamic Instruction Count: " << _kernelProfile.instructionCount << "\n";
              
                *out << "\n\n";        

            break;
        }
        
        _profile.data.instruction_count = _kernelProfile.instructionCount;
        
        sendKernelProfile(InstrumentationConfiguration::Singleton.messageQueue);

        if(info)
            delete[] info;
            
    }

    BasicBlockInstrumentor::BasicBlockInstrumentor() : description("Basic Block Execution Count Per Thread") {
    }
    

}

#endif
