/*! \file AlignmentCheckInstrumentor.cpp
    \date Monday Sept 26, 2011
    \author Si Li
    \brief The source file for the AlignmentCheckInstrumentor class.
*/

#ifndef ALIGNMENT_CHECK_INSTRUMENTOR_CPP_INCLUDED
#define ALIGNMENT_CHECK_INSTRUMENTOR_CPP_INCLUDED

#include <ocelot/instrumentation/interface/AlignmentCheckInstrumentor.h>

#include <ocelot/cuda/interface/cuda_runtime.h>

#include <ocelot/transforms/interface/AlignmentCheckPass.h>
#include <ocelot/ir/interface/Module.h>

#include <ocelot/executive/interface/Device.h>

#include <hydrazine/implementation/ArgumentParser.h>
#include <hydrazine/implementation/string.h>
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/Exception.h>

#include <fstream>

using namespace hydrazine;

namespace instrumentation
{

    void AlignmentCheckInstrumentor::checkConditions() 
    {
        conditionsMet = true;
    }
    /* for static analysis */
    void AlignmentCheckInstrumentor::analyze(ir::Module &module, const executive::Device &device) 
    {
        //create map of allocations (base address and last valid address+1)
        std::vector< size_t > globalAllocationMap;
        //get memory allocations, populate dense allocation map with it 
        executive::Device::MemoryAllocationVector memVector 
            = device.getAllAllocations();
        
        for (executive::Device::MemoryAllocationVector::iterator allocation = 
            memVector.begin(); allocation != memVector.end(); ++allocation)
        {
            size_t startAddr = (size_t) (*allocation)->pointer();
            globalAllocationMap.push_back( startAddr );
            globalAllocationMap.push_back( startAddr + (*allocation)->size() );
        }
        //*/
    }

    void AlignmentCheckInstrumentor::initialize() 
    {
        
        counter = 0;
        

        if(cudaMalloc((void **) &counter, entries * threads * sizeof(size_t)) != cudaSuccess)
        {
            throw hydrazine::Exception( "Could not allocate sufficient memory on device (cudaMalloc failed)!" );
        }
        if(cudaMemset( counter, 0, entries * threads  * sizeof( size_t )) != cudaSuccess)
        {
            throw hydrazine::Exception( "cudaMemset failed!" );
        }
        
        if(cudaMemcpyToSymbol(symbol.c_str(), &counter, sizeof(size_t *), 0, cudaMemcpyHostToDevice) != cudaSuccess) 
        {
            throw hydrazine::Exception( "cudaMemcpyToSymbol failed!");
        }
    }

    void AlignmentCheckInstrumentor::createPasses() 
    {
        
        entries = 1;

        switch(type)
        {
            case alignmentCheck:
            {
                transforms::AlignmentCheckPass *pass = new transforms::AlignmentCheckPass();
                symbol = pass->baseAddress;
                
                passes[0] = pass;   
                
                entries = pass->entries;
            }
            break;
//            case raceDetection:
//            {
//                transforms::CToPTXInstrumentationPass *pass = new transforms::CToPTXInstrumentationPass("resources/intraWarpRaceDetection.c");
//                symbol = pass->baseAddress;
//                passes[0] = pass;   
//                
//                entries = 2;
//            }
//            break;
            default:
                throw hydrazine::Exception("No instrumentation type specified!");
            break;
        }

        
    }

    void AlignmentCheckInstrumentor::extractResults(std::ostream *out) 
    {
        size_t *info = new size_t[entries * threads];
        if(counter) 
        {
            cudaMemcpy(info, counter, entries * threads * sizeof( size_t ), cudaMemcpyDeviceToHost);
            cudaFree(counter);
        }
        
        
        switch(fmt) 
        {

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
            
                switch(type)
                {
                    case alignmentCheck:
                    {
                        for( unsigned int i=0; i < threads; ++i)
                        {
                            *out << "Error: \n tid: " << info[i*entries+0] << " ";
                            *out << "Address: " << info[i*entries+1] << " ";
                            *out << "Offset: " << info[i*entries+2] << " ";
                            *out << "Address Space: " << info[i*entries+3] << "\n";
                        }
                    }
                    break;
                    case raceDetection:
                    {
                        
                        *out << "Intra-warp races detected: \n";
                        
                        for(unsigned int i = 0; i < threads; i++)
                        {
                            *out << info[i * entries];
                        }
                    
                    }
                    break;
                    default:
                    break;
                }

            break;
        }
        if(info)
            delete[] info;
            
    }

    AlignmentCheckInstrumentor::AlignmentCheckInstrumentor() : 
        description("Alignment Check Instrumentor") 
    {
    }
    

}

#endif
