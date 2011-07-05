/*! \file PTXInstrumentor.cpp
	\date Saturday November 13, 2010
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The source file for the PTXInstrumentor class.
*/

#ifndef PTX_INSTRUMENTOR_CPP_INCLUDED
#define PTX_INSTRUMENTOR_CPP_INCLUDED

#include <ocelot/analysis/interface/PTXInstrumentor.h>
#include <ocelot/api/interface/ocelot.h>

#include <ocelot/cuda/interface/cuda_runtime.h>

#include <ocelot/transforms/interface/PassManager.h>
#include <ocelot/ir/interface/Module.h>

#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/json.h>

#include <fstream>

namespace analysis
{

    void PTXInstrumentor::instrument()
	{ 
		module = new ir::Module( input );

        pass = createPass();

        if(pass != NULL) {
            transforms::PassManager manager( module );
		    manager.addPass( *pass );

		    manager.runOnModule();
            manager.destroyPasses();
        }

		std::fstream out( output.c_str() );
		
		if( !out.is_open() )
		{
			throw hydrazine::Exception( "Could not open output file " 
				+ output + " for writing." );
		}
		
		module->writeIR( out );

        ocelot::reset();
        ocelot::registerPTXModule(out, module->path());

        for( ir::Module::KernelMap::const_iterator 
			kernel = module->kernels().begin(); 
			kernel != module->kernels().end(); ++kernel ) 
        {
            kernelName = kernel->first;
            initialize();

            ocelot::launch( module->path(), kernel->first );

            finalize();            
        }

        ocelot::unregisterModule(module->path());

        delete module;

	}

    void PTXInstrumentor::instrument(ir::Module& module) {

        pass = createPass();

        if(pass != NULL) {

            transforms::PassManager manager( &module );

		    manager.addPass( *pass );

		    manager.runOnModule();

            manager.destroyPasses();
        }
    }

    void PTXInstrumentor::finalize() {

        if(out == NULL) {
            if(!output.empty()){
                out = new std::ofstream(output.c_str(), std::fstream::app);
		    }
            else {
			       out = &std::cout;
		    }
        }

        extractResults(out);
    }

    void PTXInstrumentor::jsonEmitter(std::string metric, hydrazine::json::Object *stats) {
   
		std::ofstream outFile;

		std::string tmp = "." + metric;
		int i = 1;
		bool alreadyExists = true;
		do {
			outFile.open((kernelName + tmp + ".json").c_str(), std::ios::in);	
			if( outFile.is_open() )
			{
				std::stringstream out;
				out << "." << metric << "." << i;
				tmp = out.str();
				i++;
			} else {
				alreadyExists = false;
			}
            outFile.close();
		} while(alreadyExists);
	
		outFile.open((kernelName + tmp + ".json").c_str());
		hydrazine::json::Emitter emitter;
		emitter.use_tabs = false;
		emitter.emit_pretty(outFile, stats, 2);
        outFile.close();

    }

    analysis::KernelProfile PTXInstrumentor::kernelProfile() {
        return this->_kernelProfile;
    }

    void PTXInstrumentor::deviceInfo(std::ostream *out) {

        if(out == NULL) {
            return;
        }

        struct cudaDeviceProp properties;
        cudaGetDeviceProperties(&properties, 0);
    
        *out << "DEVICE INFO:\n\n";
        *out << "Multiprocessor Count: " << properties.multiProcessorCount << "\n"; 
        
        *out << "Total amount of global memory: " << properties.totalGlobalMem << "\n";
        
        *out << "Total amount of constant memory: " << properties.totalConstMem << "\n";
        *out << "Total amount of shared memory per block: " << properties.sharedMemPerBlock << "\n";
        *out << "Total number of registers available per block: " << properties.regsPerBlock << "\n";
        
        *out << "Warp size: " << properties.warpSize << "\n";
        *out << "Maximum number of threads per block: " << properties.maxThreadsPerBlock << "\n";
        *out << "Maximum sizes of each dimension of a block: " << properties.maxThreadsDim[0] << " x " << properties.maxThreadsDim[1] << " x " << 
                properties.maxThreadsDim[2] << "\n";     
        *out << "Maximum sizes of each dimension of a grid: " << properties.maxGridSize[0] << " x " << properties.maxGridSize[1] << " x " << 
                properties.maxGridSize[2] << "\n";     
        
        *out << "Clock rate: " << properties.clockRate * 1e-6f << " GHz\n";

        *out << "\n\n";

    }
    
    PTXInstrumentor::PTXInstrumentor() : conditionsMet(false), fmt(text), deviceInfoWritten(false) {
        out = NULL;
    }

    PTXInstrumentor::~PTXInstrumentor() {
        if(out != &std::cout && out != NULL){
            delete out;
        }
    }

}

#endif
