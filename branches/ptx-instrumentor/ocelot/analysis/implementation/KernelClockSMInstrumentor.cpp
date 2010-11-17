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

        cudaConfigureCall( dim3(ctas, 1, 1), dim3( threads, 1, 1), 0, 0 );             
    }

    analysis::Pass *KernelClockSMInstrumentor::createPass() {
        return new analysis::KernelClockSMPass();
    }

    void KernelClockSMInstrumentor::finalize() {

        size_t *counterHost = new size_t[2];
        cudaMemcpyFromSymbol((void *) counterHost, ((KernelClockSMPass *)pass)->kernelClockSMCounter().c_str(), 2 * sizeof(size_t), 0, cudaMemcpyDeviceToHost);       
        
        std::cout << "\n\n" << kernelName << ":\n";
        std::cout << "\n--------------- " << description << " ---------------\n\n";

        std::cout << "Clock Cycles: " << counterHost[0] << std::endl;
        std::cout << "SM (Processor) ID: " << counterHost[1] << std::endl;

        delete[] counterHost;

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
