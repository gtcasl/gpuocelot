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
        
        predCount = 0;
        
        struct cudaDeviceProp properties;
        cudaGetDeviceProperties(&properties, 0);
        
        warpCount = (unsigned long)ceil((threads/threadBlocks)/properties.warpSize);
        if(warpCount == 0)
            warpCount = 1;
        
        for( ir::ControlFlowGraph::const_iterator block = module.getKernel(kernelName)->cfg()->begin(); 
			block != module.getKernel(kernelName)->cfg()->end(); ++block ) {
            
            for( ir::ControlFlowGraph::InstructionList::const_iterator instruction = block->instructions.begin();
                instruction != block->instructions.end(); ++instruction)
            {
                ir::PTXInstruction *ptxInst = (ir::PTXInstruction *)*instruction;
            
                if(ptxInst->opcode == ir::PTXInstruction::SetP)
                    predCount++;
            }
        }        
    }

    void BranchDivergenceInstrumentor::initialize() {
        branchDivInfo = 0;

        if(predCount == 0 || warpCount == 0)
            return;

        cudaMalloc((void **) &branchDivInfo, predCount * warpCount * sizeof(size_t));
        cudaMemset( branchDivInfo, 0, predCount * warpCount * sizeof( size_t ));
    
        cudaMemcpyToSymbol(symbol.c_str(), &branchDivInfo, sizeof(size_t *), 0, cudaMemcpyHostToDevice);   
    }

    transforms::Pass *BranchDivergenceInstrumentor::createPass() {
        transforms::CToPTXInstrumentationPass *pass = new transforms::CToPTXInstrumentationPass("resources/branchDivergence.c");
        symbol = pass->baseAddress;
        return pass;
    }

    void BranchDivergenceInstrumentor::extractResults(std::ostream *out) {
            
        if(predCount == 0 || warpCount == 0)
        {
            std::cout << "No conditional branches in this kernel.\n";    
            return;
        }    
        
        size_t *info = new size_t[predCount * warpCount];
        
        if(branchDivInfo) {
            cudaMemcpy(info, branchDivInfo, predCount * warpCount * sizeof( size_t ), cudaMemcpyDeviceToHost);      
            cudaFree(branchDivInfo);
        }

        struct cudaDeviceProp properties;
        cudaGetDeviceProperties(&properties, 0);

        unsigned long divergentBranches = 0;
        unsigned long divergentWarps = 0;
        
        for(size_t i = 0; i < predCount; i++) {
            for(size_t j = 0; j < warpCount; j++) {
                if(info[warpCount * i + j] == 0) {
                    divergentBranches++;
                    divergentWarps++;
                }    
                    
            }
        } 

        
    
        switch(fmt) {
    
            case json:

                
            
            break;
            
            case text:   

                if(!deviceInfoWritten){
                    deviceInfo(out);
                    deviceInfoWritten = true;
                }

                *out << "Kernel Name: " << kernelName << "\n";
                *out << "Thread Block Count: " << threadBlocks << "\n";
                *out << "Thread Count: " << threads << "\n";
                

                *out << "\n% Branch Divergence: " << (divergentBranches/predCount) * 100 << "%\n";
                *out << "Number of Divergent Warps: " << divergentWarps << "\n\n";
                
            
            break;

        }

        if(info)
            delete[] info;
            
    }

    BranchDivergenceInstrumentor::BranchDivergenceInstrumentor() : description("Branch Divergence"), predCount(0), warpCount(0) {

    }

}

#endif
