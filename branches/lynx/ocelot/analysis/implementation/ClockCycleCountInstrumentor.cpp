/*! \file ClockCycleCountInstrumentor.cpp
	\date Monday November 15, 2010
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The source file for the ClockCycleCountInstrumentor class.
*/

#ifndef KERNEL_CLOCK_SM_INSTRUMENTOR_CPP_INCLUDED
#define KERNEL_CLOCK_SM_INSTRUMENTOR_CPP_INCLUDED

#include <ocelot/analysis/interface/ClockCycleCountInstrumentor.h>

#include <ocelot/cuda/interface/cuda_runtime.h>

#include <ocelot/analysis/interface/ClockCycleCountPass.h>
#include <ocelot/ir/interface/Module.h>

#include <hydrazine/implementation/ArgumentParser.h>
#include <hydrazine/implementation/string.h>
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/Exception.h>

#include <fstream>

namespace analysis
{

    void ClockCycleCountInstrumentor::analyze(ir::Module &module) {
        /* no static analysis necessary for this instrumentation */
    }

    void ClockCycleCountInstrumentor::initialize() {
              
        clock_sm_info = 0;

        cudaMalloc((void **) &clock_sm_info, 2 * ctas * sizeof(size_t));
        cudaMemset( clock_sm_info, 0, 2 * ctas * sizeof( size_t ));

        cudaMemcpyToSymbol(((ClockCycleCountPass *)pass)->kernelClockSMInfo().c_str(), &clock_sm_info, sizeof(size_t *), 0, cudaMemcpyHostToDevice);
    }

    analysis::Pass *ClockCycleCountInstrumentor::createPass() {
        return new analysis::ClockCycleCountPass();
    }

    void ClockCycleCountInstrumentor::finalize() {

        size_t *clockSMInfoHost = new size_t[2 * ctas];
        cudaMemcpy(clockSMInfoHost, clock_sm_info, 2 * ctas * sizeof( size_t ), cudaMemcpyDeviceToHost);      
        
        std::cout << "\n\n" << kernelName << ":\n";
        std::cout << "\n--------------- " << description << " ---------------\n\n";

        for(unsigned int i = 0; i < ctas; i++) {
            std::cout << "CTA " << i << ":\n";
            std::cout << "Clock Cycles: " << clockSMInfoHost[(i * ctas) + 0] << std::endl;
            std::cout << "SM (Processor) ID: " << clockSMInfoHost[(i * ctas) + 1] << std::endl;
        }

        delete[] clockSMInfoHost;
        cudaFree(clock_sm_info);
    }

    ClockCycleCountInstrumentor::ClockCycleCountInstrumentor() : description("Clock Cycles and SM (Processor) ID") {

    }

    ClockCycleCountInstrumentor::ClockCycleCountInstrumentor(const std::string input, const std::string output, unsigned int ctas, unsigned int threads ) : 
        description("Clock Cycles and SM (Processor) ID")
    {
        PTXInstrumentor::input = input;
        PTXInstrumentor::output = output;
        PTXInstrumentor::ctas = ctas;
        PTXInstrumentor::threads = threads;    
    }

}

#endif
