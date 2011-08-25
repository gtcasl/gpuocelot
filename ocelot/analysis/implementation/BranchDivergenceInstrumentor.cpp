/*! \file BranchDivergenceInstrumentor.cpp
	\date Monday July 18, 2011
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The source file for the BranchDivergenceInstrumentor class.
*/

#ifndef BRANCH_DIVERGENCE_INSTRUMENTOR_CPP_INCLUDED
#define BRANCH_DIVERGENCE_INSTRUMENTOR_CPP_INCLUDED

#include <ocelot/analysis/interface/BranchDivergenceInstrumentor.h>

#include <ocelot/cuda/interface/cuda_runtime.h>

#include <ocelot/transforms/interface/CToPTXInstrumentationPass.h>
#include <ocelot/transforms/interface/CToPTXModulePass.h>
#include <ocelot/ir/interface/Module.h>

#include <hydrazine/implementation/ArgumentParser.h>
#include <hydrazine/implementation/string.h>
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/json.h>

#include <fstream>
#include <math.h>

using namespace hydrazine;

namespace analysis
{

    void BranchDivergenceInstrumentor::checkConditions() {
        conditionsMet = true;
    }

    void BranchDivergenceInstrumentor::analyze(ir::Module &module) {
       
    }

    void BranchDivergenceInstrumentor::initialize() {
        
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

    void BranchDivergenceInstrumentor::createPasses() 
    {
        transforms::CToPTXInstrumentationPass *pass = new transforms::CToPTXInstrumentationPass("resources/branchDivergence.c");
        symbol = pass->baseAddress;
        transforms::CToPTXModulePass *modulePass = new transforms::CToPTXModulePass;
        modulePass->parameterMap = pass->parameterMap;
        
        passes[0] = pass;   
        passes[1] = modulePass;
    }

    void BranchDivergenceInstrumentor::extractResults(std::ostream *out) {
            
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
		
                *out << "Divergent Dynamic Branches: " << info[1] << "\n";
                *out << "Total Dynamic Branches: " << info[0] << "\n\n";              
                *out << "Branch Divergence: " << ((double)info[1]/(double)info[0]) * 100 << "%\n\n";
		
            break;
        }

        if(info)
            delete[] info;
            
    }

    BranchDivergenceInstrumentor::BranchDivergenceInstrumentor() : description("Branch Divergence") {

    }

}

#endif
