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

#include <ocelot/analysis/interface/PassManager.h>
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
            analysis::PassManager manager( module );
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

            analysis::PassManager manager( &module );

		    manager.addPass( *pass );

		    manager.runOnModule();

            manager.destroyPasses();
        }

    }

    void PTXInstrumentor::finalize() {

        size_t *info = 0;
        std::ostream *out;

        if(!output.empty()){
            out = new std::ofstream(output.c_str(), std::fstream::app);
		}
        else {
			   out = &std::cout;
		}

        info = extractResults(out);
		
        if(info)
            delete[] info;

        if(out != &std::cout && out != NULL){
            delete out;
        }
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

}

#endif
