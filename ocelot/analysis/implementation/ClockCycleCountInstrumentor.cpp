/*! \file ClockCycleCountInstrumentor.cpp
	\date Monday November 15, 2010
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The source file for the ClockCycleCountInstrumentor class.
*/

#ifndef CLOCK_CYCLE_COUNT_INSTRUMENTOR_CPP_INCLUDED
#define CLOCK_CYCLE_COUNT_INSTRUMENTOR_CPP_INCLUDED

#include <ocelot/analysis/interface/ClockCycleCountInstrumentor.h>

#include <ocelot/cuda/interface/cuda_runtime.h>

#include <ocelot/transforms/interface/CToPTXInstrumentationPass.h>
#include <ocelot/transforms/interface/ClockCycleCountPass.h>
#include <ocelot/ir/interface/Module.h>

#include <hydrazine/implementation/ArgumentParser.h>
#include <hydrazine/implementation/string.h>
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/json.h>

#include <fstream>

using namespace hydrazine;

namespace analysis
{

    void ClockCycleCountInstrumentor::checkConditions() {
        conditionsMet = true;
    }

    void ClockCycleCountInstrumentor::analyze(ir::Module &module) {
        /* No static analysis necessary for this instrumentation */
    }

    void ClockCycleCountInstrumentor::initialize() {
        clock_sm_info = 0;

        cudaMalloc((void **) &clock_sm_info, 2 * threadBlocks * sizeof(size_t));
        cudaMemset( clock_sm_info, 0, 2 * threadBlocks * sizeof( size_t ));

        cudaMemcpyToSymbol(symbol.c_str(), &clock_sm_info, sizeof(size_t *), 0, cudaMemcpyHostToDevice);
    }

    transforms::Pass *ClockCycleCountInstrumentor::createPass() {
        transforms::CToPTXInstrumentationPass *pass = new transforms::CToPTXInstrumentationPass("resources/clockCycleCount.c");
        symbol = pass->baseAddress;
        return pass;
    }

    void ClockCycleCountInstrumentor::extractResults(std::ostream *out) {
            
        size_t *info = new size_t[2 * threadBlocks];
        
        if(clock_sm_info) {
            cudaMemcpy(info, clock_sm_info, 2 * threadBlocks * sizeof( size_t ), cudaMemcpyDeviceToHost);      
            cudaFree(clock_sm_info);
        }

        struct cudaDeviceProp properties;
        cudaGetDeviceProperties(&properties, 0);

        std::vector<size_t> threadBlockInfo;
        threadBlockInfo.resize(2, 0);

        size_t smid = 0;
        _kernelProfile.processorToThreadBlockCountMap.clear();
        _kernelProfile.threadBlockToProcessorMap.clear();
        _kernelProfile.processorToClockCyclesMap.clear();
        
        for(size_t i = 0; i < threadBlocks; i++) {
            smid = info[i*2+1];
            threadBlockInfo[0] = info[i*2];
            threadBlockInfo[1] = smid;
            _kernelProfile.processorToThreadBlockCountMap[smid]++;
            _kernelProfile.processorToClockCyclesMap[smid] += info[i*2];
            
            _kernelProfile.threadBlockToProcessorMap[i] = threadBlockInfo;        
        } 

        std::vector<double> clockCyclesPerSM;
        clockCyclesPerSM.clear();

        for(KernelProfile::ProcessorToClockCyclesMap::const_iterator it = _kernelProfile.processorToClockCyclesMap.begin();
            it != _kernelProfile.processorToClockCyclesMap.end(); ++it) {
            clockCyclesPerSM.push_back(it->second);
        }

        _kernelProfile.maxSMRuntime = *(std::max_element(clockCyclesPerSM.begin(), clockCyclesPerSM.end()))/properties.clockRate;
        _kernelProfile.name = kernelName;
    
        switch(fmt) {
    
            case json:

                *out << kernelName << "_maxSMRuntime = " << _kernelProfile.maxSMRuntime << "\n\n";
                *out << kernelName << "_threadBlockToProcessorMap = {";

                for (KernelProfile::ThreadBlockToProcessorMap::const_iterator it = _kernelProfile.threadBlockToProcessorMap.begin(); 
                    it != _kernelProfile.threadBlockToProcessorMap.end(); ++it) {
			        *out << it->first << ":(";
                    
                    for(std::vector<size_t>::const_iterator mappedIt = it->second.begin(); mappedIt != it->second.end(); ++mappedIt){
                        *out << *mappedIt << ","; 
                    }

                    *out << "),";
		        }
                
                *out << "}\n\n";   

                *out << kernelName << "_processorToThreadBlockCountMap = {";
                    for(KernelProfile::ProcessorToThreadBlockCountMap::const_iterator it = _kernelProfile.processorToThreadBlockCountMap.begin();
                        it != _kernelProfile.processorToThreadBlockCountMap.end(); ++it){
                        *out << it->first << ":" << it->second << ",";
                    }

                *out << "}\n\n";
            
            break;
            
            case text:   

                if(!deviceInfoWritten){
                    deviceInfo(out);
                    deviceInfoWritten = true;
                }

                *out << "Kernel Name: " << kernelName << "\n";
                *out << "Thread Block Count: " << threadBlocks << "\n";
                *out << "Thread Count: " << threads << "\n";
                

                *out << "Total Kernel Runtime: " << _kernelProfile.maxSMRuntime << " ms\n";
                
                *out << "\nSM to CTA Mapping [SM ID: (CTA ID, Clock Cycles)]:\n\n";
                
                for(KernelProfile::ThreadBlockToProcessorMap::const_iterator it = _kernelProfile.threadBlockToProcessorMap.begin();
            it != _kernelProfile.threadBlockToProcessorMap.end(); ++it) {
                    *out << "[" << it->first << ": (";

                    for(std::vector<size_t>::const_iterator mappedIt = it->second.begin(); mappedIt != it->second.end(); ++mappedIt){
                        *out << *mappedIt << ","; 
                    }

                    *out << ")\n";
                }

                *out << "\nCTAs per SM [SM ID: CTA Count]:\n\n";
                
                for(KernelProfile::ProcessorToThreadBlockCountMap::const_iterator it = _kernelProfile.processorToThreadBlockCountMap.begin();
            it != _kernelProfile.processorToThreadBlockCountMap.end(); ++it) {
                    *out << "[" << it->first << ":" << it->second << "]\n";
                }
    
                *out << "\n\n";
  
            
            break;

        }

        if(info)
            delete[] info;
            
    }

    ClockCycleCountInstrumentor::ClockCycleCountInstrumentor() : description("Clock Cycles and SM (Processor) ID") {

    }

}

#endif
