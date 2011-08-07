/*! \file MemoryEfficiencyInstrumentor.cpp
	\date Monday July 30, 2011
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The source file for the MemoryEfficiencyInstrumentor class.
*/

#ifndef MEMORY_EFFICIENCY_INSTRUMENTOR_CPP_INCLUDED
#define MEMORY_EFFICIENCY_INSTRUMENTOR_CPP_INCLUDED

#include <ocelot/analysis/interface/MemoryEfficiencyInstrumentor.h>

#include <ocelot/cuda/interface/cuda_runtime.h>

#include <ocelot/transforms/interface/CToPTXInstrumentationPass.h>
#include <ocelot/ir/interface/Module.h>

#include <hydrazine/implementation/ArgumentParser.h>
#include <hydrazine/implementation/string.h>
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/Exception.h>

#include <fstream>

using namespace hydrazine;

namespace analysis
{

    void MemoryEfficiencyInstrumentor::checkConditions() {
        conditionsMet = true;
    }

    void MemoryEfficiencyInstrumentor::analyze(ir::Module &module) {
        globalMemOps = 0;
        
        for( ir::ControlFlowGraph::const_iterator block = module.getKernel(kernelName)->cfg()->begin(); 
                        block != module.getKernel(kernelName)->cfg()->end(); ++block ) {
            
            for( ir::ControlFlowGraph::InstructionList::const_iterator instruction = block->instructions.begin();
                instruction != block->instructions.end(); ++instruction)
            {
                ir::PTXInstruction *ptxInst = (ir::PTXInstruction *)*instruction;
            
                if((ptxInst->opcode == ir::PTXInstruction::St || ptxInst->opcode == ir::PTXInstruction::Ld)
                    && ptxInst->addressSpace == ir::PTXInstruction::Global)
                {
                    globalMemOps++;
                }
            }
        }      
        /* subtract three global memory operations added by the instrumentation */
        globalMemOps -= 3;
    }

    void MemoryEfficiencyInstrumentor::initialize() {
        
        counter = 0;

        if(cudaMalloc((void **) &counter, 1 * sizeof(size_t)) != cudaSuccess){
            throw hydrazine::Exception( "Could not allocate sufficient memory on device (cudaMalloc failed)!" );
        }
        if(cudaMemset( counter, 0, 1 * sizeof( size_t )) != cudaSuccess){
            throw hydrazine::Exception( "cudaMemset failed!" );
        }
        
        sharedMemSize = threads * threadBlocks * 8;
        
        if(cudaMemcpyToSymbol(symbol.c_str(), &counter, sizeof(size_t *), 0, cudaMemcpyHostToDevice) != cudaSuccess) {
            throw hydrazine::Exception( "cudaMemcpyToSymbol failed!");
        }
    }

    transforms::Pass *MemoryEfficiencyInstrumentor::createPass() {

        transforms::CToPTXInstrumentationPass *pass = new transforms::CToPTXInstrumentationPass("resources/memoryEfficiency.c");
        symbol = pass->baseAddress;
        return pass;   
    }

    void MemoryEfficiencyInstrumentor::extractResults(std::ostream *out) {

        size_t *info = new size_t[1];
        if(counter) {
            cudaMemcpy(info, counter, 1 * sizeof( size_t ), cudaMemcpyDeviceToHost);
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

                *out << "Kernel Name: " << kernelName << "\n";
                *out << "Thread Block Count: " << threadBlocks << "\n";
                *out << "Thread Count: " << threads << "\n\n";
                
               std::cout << "Total Global Memory Transactions: " << info[0]  << "\n";
               std::cout << "Transactions / Global Memory Operations: " << info[0] << "/" << globalMemOps  << "\n\n";


            break;
        }

        if(info)
            delete[] info;
            
    }

    MemoryEfficiencyInstrumentor::MemoryEfficiencyInstrumentor() : description("Memory Efficiency") {
    }
    

}

#endif
