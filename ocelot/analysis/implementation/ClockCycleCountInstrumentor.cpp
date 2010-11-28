/*! \file ClockCycleCountInstrumentor.cpp
	\date Monday November 15, 2010
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The source file for the ClockCycleCountInstrumentor class.
*/

#ifndef CLOCK_CYCLE_COUNT_INSTRUMENTOR_CPP_INCLUDED
#define CLOCK_CYCLE_COUNT_INSTRUMENTOR_CPP_INCLUDED

#include <ocelot/analysis/interface/ClockCycleCountInstrumentor.h>

#include <ocelot/cuda/interface/cuda_runtime.h>

#include <ocelot/analysis/interface/ClockCycleCountPass.h>
#include <ocelot/ir/interface/Module.h>

#include <hydrazine/implementation/ArgumentParser.h>
#include <hydrazine/implementation/string.h>
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/json.h>

#include <fstream>
#include <string>

using namespace hydrazine;

namespace analysis
{

    void ClockCycleCountInstrumentor::analyze(ir::Module &module) {
        /* No static analysis necessary for this instrumentation */
    }

    void ClockCycleCountInstrumentor::initialize() {
              
        clock_sm_info = 0;

        cudaMalloc((void **) &clock_sm_info, 2 * threadBlocks * sizeof(size_t));
        cudaMemset( clock_sm_info, 0, 2 * threadBlocks * sizeof( size_t ));

        cudaMemcpyToSymbol(((ClockCycleCountPass *)pass)->kernelClockSMInfo().c_str(), &clock_sm_info, sizeof(size_t *), 0, cudaMemcpyHostToDevice);
    }

    analysis::Pass *ClockCycleCountInstrumentor::createPass() {
        return new analysis::ClockCycleCountPass();
    }

    size_t* ClockCycleCountInstrumentor::extractResults(std::ostream *out) {
                
        size_t *info = new size_t[2 * threadBlocks];
        if(clock_sm_info) {
            cudaMemcpy(info, clock_sm_info, 2 * threadBlocks * sizeof( size_t ), cudaMemcpyDeviceToHost);      
            cudaFree(clock_sm_info);
        }

        *out << "\n\n" << kernelName << ":\n";
        *out << "\n--------------- " << description << " ---------------\n\n";

        for(unsigned int i = 0; i < threadBlocks; i++) {
            *out << "CTA " << i << ":\n";
            *out << "Clock Cycles: " << info[i*2] << std::endl;
            *out << "SM (Processor) ID: " << info[i*2 + 1] << std::endl;
        } 
        
        return info;
    }

    void ClockCycleCountInstrumentor::emitJSON(size_t* info)
	{
        if(info == NULL)
            return;

		json::Object *clockCyclesStat = new json::Object;
		json::Object *column;
	
		column = new json::Object;
		json::Number *valueCC;
		clockCyclesStat->dictionary["per_CTA_clock_cycle_count"] = column;
		
		for(unsigned int i = 0; i < threadBlocks; i++)
		{
			std::stringstream thread;
			thread << i << "." << info[i*2+1];
			valueCC = new json::Number((int)info[i*2+0]);
			column->dictionary[thread.str()] = valueCC;
		}

		jsonEmitter("clockCycleCount", clockCyclesStat);

        delete clockCyclesStat;
	}


    ClockCycleCountInstrumentor::ClockCycleCountInstrumentor() : description("Clock Cycles and SM (Processor) ID") {

    }

}

#endif
