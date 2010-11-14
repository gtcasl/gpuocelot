/*! \file PTXInstrumentor.cpp
	\date Saturday November 13, 2010
	\author Naila Farooqui <naila@cc.gatech.edu>
	\brief The source file for the PTXInstrumentor class.
*/

#ifndef PTX_INSTRUMENTOR_CPP_INCLUDED
#define PTX_INSTRUMENTOR_CPP_INCLUDED

#include <ocelot/analysis/interface/PTXInstrumentor.h>
#include <ocelot/api/interface/ocelot.h>

#include <ocelot/analysis/interface/PassManager.h>
#include <ocelot/ir/interface/Module.h>

#include <hydrazine/implementation/Exception.h>

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
}

#endif
