/*! \file KernelClockSMInstrumentor.cpp
	\date Monday November 15, 2010
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The source file for the KernelClockSMInstrumentor class.
*/

#ifndef KERNEL_CLOCK_SM_INSTRUMENTOR_CPP_INCLUDED
#define KERNEL_CLOCK_SM_INSTRUMENTOR_CPP_INCLUDED

#include <ocelot/analysis/interface/KernelClockSMInstrumentor.h>

#include <ocelot/cuda/interface/cuda_runtime.h>

#include <ocelot/analysis/interface/KernelClockSMPass.h>
#include <ocelot/ir/interface/Module.h>

#include <hydrazine/implementation/ArgumentParser.h>
#include <hydrazine/implementation/string.h>
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/Exception.h>

#include <fstream>

namespace analysis
{
    void KernelClockSMInstrumentor::initialize() {
              
        clock_sm_info = 0;

        cudaMalloc((void **) &clock_sm_info, 2 * ctas * sizeof(size_t));
        cudaMemset( clock_sm_info, 0, 2 * ctas * sizeof( size_t ));

        cudaMemcpyToSymbol(((KernelClockSMPass *)pass)->kernelClockSMInfo().c_str(), &clock_sm_info, sizeof(size_t *), 0, cudaMemcpyHostToDevice);

        cudaConfigureCall( dim3(ctas, 1, 1), dim3( threads, 1, 1), 0, 0 );             
    }

    analysis::Pass *KernelClockSMInstrumentor::createPass() {
        return new analysis::KernelClockSMPass();
    }

    void KernelClockSMInstrumentor::finalize() {

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

    KernelClockSMInstrumentor::KernelClockSMInstrumentor() : description("Kernel Clock Cycle and SM (Processor) ID") {

    }

    KernelClockSMInstrumentor::KernelClockSMInstrumentor(const std::string input, const std::string output, unsigned int ctas, unsigned int threads ) : 
        description("Kernel Clock Cycle and SM (Processor) ID")
    {
        PTXInstrumentor::input = input;
        PTXInstrumentor::output = output;
        PTXInstrumentor::ctas = ctas;
        PTXInstrumentor::threads = threads;    
    }

}

#endif
