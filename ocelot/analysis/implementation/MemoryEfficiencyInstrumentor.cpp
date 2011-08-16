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

    void MemoryEfficiencyInstrumentor::checkConditions() {
        conditionsMet = true;
    }

    void MemoryEfficiencyInstrumentor::analyze(ir::Module &module) {
             
    }

    void MemoryEfficiencyInstrumentor::initialize() {
        
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

    void MemoryEfficiencyInstrumentor::createPasses() {

        transforms::CToPTXInstrumentationPass *pass = new transforms::CToPTXInstrumentationPass("resources/memoryEfficiency.c");
        symbol = pass->baseAddress;
        transforms::CToPTXModulePass *modulePass = new transforms::CToPTXModulePass;
        
        passes[0] = pass;   
        passes[1] = modulePass;
    }

    void MemoryEfficiencyInstrumentor::extractResults(std::ostream *out) {

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

                *out << "Kernel Name: " << kernelName << "\n";
                *out << "Thread Block Count: " << threadBlocks << "\n";
                *out << "Thread Count: " << threads << "\n\n";

	       std::cout << "Dynamic Warps Executing Global Memory Operations: " << 2 * info[1] << "\n";
	       std::cout << "Memory Transactions: " << info[0] << "\n\n";
               std::cout << "Memory Efficiency: " << (2 * info[1]) << "/" << info[0] << "\n\n";
           
            break;
        }

        if(info)
            delete[] info;
            
    }

    MemoryEfficiencyInstrumentor::MemoryEfficiencyInstrumentor() : description("Memory Efficiency") {
    }
    

}

#endif
