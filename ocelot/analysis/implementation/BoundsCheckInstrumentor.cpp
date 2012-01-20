/*! \file BoundsCheckInstrumentor.cpp
    \date Monday Sept 26, 2011
    \author Si Li
    \brief The source file for the BoundsCheckInstrumentor class.
*/

#ifndef BOUNDS_CHECK_INSTRUMENTOR_CPP_INCLUDED
#define BOUNDS_CHECK_INSTRUMENTOR_CPP_INCLUDED

#include <ocelot/analysis/interface/BoundsCheckInstrumentor.h>

#include <ocelot/cuda/interface/cuda_runtime.h>

#include <ocelot/transforms/interface/BoundsCheckPass.h>
#include <ocelot/ir/interface/Module.h>

#include <ocelot/executive/interface/Device.h>

#include <hydrazine/implementation/ArgumentParser.h>
#include <hydrazine/implementation/string.h>
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/Exception.h>

#include <ocelot/ir/interface/ControlFlowGraph.h>
#include <ocelot/ir/interface/PTXKernel.h>
#include <fstream>

using namespace hydrazine;

namespace analysis
{

    void BoundsCheckInstrumentor::checkConditions() 
    {
        conditionsMet = true;
    }
    /* for static analysis */
    void BoundsCheckInstrumentor::analyze(ir::Module &module, const executive::Device &device) 
    {
        //get memory allocations, populate dense allocation map with it 
        executive::Device::MemoryAllocationVector memVector = device.getAllAllocations();
        
        globalAllocationMap.resize( memVector.size()+1 );

        std::vector< size_t >::iterator it = globalAllocationMap.begin();
        *it++ = memVector.size();
        
        for (executive::Device::MemoryAllocationVector::iterator allocation = 
            memVector.begin(); allocation != memVector.end(); ++allocation)
        {
            size_t startAddr = (size_t) (*allocation)->pointer();
            *it++ = startAddr;
            *it++ = startAddr + (*allocation)->size();
        }
        
        globalAllocationMap.push_back( 0 );
        //*/
        
    }

    void BoundsCheckInstrumentor::initialize() 
    {
        //allocate global mem for reporting info
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
        
        
        //copy allocationMap to global memory
        allocMap = NULL;
        if(cudaMalloc((void **) &allocMap, entries * threads * sizeof(size_t)) != cudaSuccess)
        {
            throw hydrazine::Exception( "Could not allocate sufficient memory on device (cudaMalloc failed)!" );
        }
        if(cudaMemset( allocMap, 0, entries * threads  * sizeof( size_t )) != cudaSuccess)
        {
            throw hydrazine::Exception( "cudaMemset failed!" );
        }
        if( !globalAllocationMap.empty() ) 
        {
            cudaMemcpy(allocMap, &globalAllocationMap[0], globalAllocationMap.size() * sizeof( size_t ), cudaMemcpyHostToDevice);
        }
        int error = cudaMemcpyToSymbol(allocMapSymbol.c_str(), &allocMap, sizeof(size_t *), 0, cudaMemcpyHostToDevice);
        if(error != cudaSuccess) 
        {
            std::cout << "error code: " << error << "\n";
            throw hydrazine::Exception( "cudaMemcpyToSymbol failed!");
        }
    }

    void BoundsCheckInstrumentor::createPasses() 
    {
        transforms::BoundsCheckPass *pass = new transforms::BoundsCheckPass();
        symbol = pass->baseAddress;
        allocMapSymbol = pass->allocMapAddress;
        passes[0] = pass;   
        entries = 4;    //how many pieces of data for each error?
    }

    void BoundsCheckInstrumentor::extractResults(std::ostream *out) 
    {
        size_t *info = new size_t[entries * threads];
        if(counter) 
        {
            cudaMemcpy(info, counter, entries * threads * sizeof( size_t ), cudaMemcpyDeviceToHost);
            cudaFree(counter);
        }
        
        if(allocMap) 
        {
            cudaFree(allocMap);     //allocation map only for gpu kernel use
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

    BoundsCheckInstrumentor::BoundsCheckInstrumentor() : 
        description("Alignment Check Instrumentor") 
    {
    }
    
    std::string BoundsCheckInstrumentor::getAllocMap()
    {
        return "__global_allocation_map";
    }

}

#endif
