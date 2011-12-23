/*! \file   InstrumentationConfiguration.cpp
	\author Naila Farooqui <naila@cc.gatech.edu>
	\date   Tuesday November 22, 2011
	\brief  The source file for the InstrumentationConfiguration class.
*/

#ifndef INSTRUMENTATION_CONFIGURATION_CPP_INCLUDED
#define INSTRUMENTATION_CONFIGURATION_CPP_INCLUDED

// Trace includes
#include <instrumentation/interface/InstrumentationConfiguration.h>

// Ocelot includes
#include <ocelot/api/interface/ocelot.h>
#include <ocelot/analysis/interface/kernel_profile.h>

// Hydrazine includes
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/json.h>

#include <errno.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1

namespace instrumentation
{

InstrumentationConfiguration InstrumentationConfiguration::Singleton;

InstrumentationConfiguration::InstrumentationConfiguration()
{

    // Open a message queue for writing (sending data)
    messageQueue = mq_open (MSG_QUEUE, O_RDWR | O_NONBLOCK);
    if(messageQueue < 0)
    {
        report( "Failed to open message queue for writing" );       
        if(errno == EACCES)
            report("invalid permissions");
        if(errno == ENOENT)
            report("no queue with this name exists");
        if(errno == EEXIST)
            report("queue with this name already exists");
        if(errno == EINVAL)
            report("invalid attribute properties");
    }

	hydrazine::json::Parser parser;
	hydrazine::json::Object* object = 0;

	// initialize
	clockCycleCount = false;
	memoryEfficiency = false;
	branchDivergence = false;
	
	warpInstructionCount = false;
	threadInstructionCount = false;
	
	basicBlockExecutionCount = false;
	
	try
	{
		std::ifstream stream("configure.ocelot");
	
		object = parser.parse_object(stream);

		hydrazine::json::Visitor mainConfig(object);

		hydrazine::json::Visitor instrumentConfig = mainConfig["instrument"];
		
		if(!instrumentConfig.is_null())
		{
            // configuration for clock cycle instrumentor
			hydrazine::json::Visitor config = instrumentConfig["clockCycleCount"];
			
			if(!config.is_null()) 
			{
			    clockCycleCount = true;
			    
				clockCycleCountInstrumentor.enabled = config.parse<bool>(
					"enabled", true);
	
				clockCycleCountInstrumentor.logfile = config.parse<std::string>(
					"logfile", "");
			}
			
			// configuration for memory efficiency instrumentor
			config = instrumentConfig["memoryEfficiency"];
			
			if(!config.is_null()) 
			{
			    memoryEfficiency = true;
			    
				warpReductionInstrumentor.enabled = config.parse<bool>(
					"enabled", true);
	
				warpReductionInstrumentor.logfile = config.parse<std::string>(
					"logfile", "");
					
			    warpReductionInstrumentor.type = WarpReductionInstrumentor::memoryEfficiency;
			}
			
			// configuration for branch divergence instrumentor
			config = instrumentConfig["branchDivergence"];
			
			if(!config.is_null()) 
			{
			    branchDivergence = true;
			    
				warpReductionInstrumentor.enabled = config.parse<bool>(
					"enabled", true);
	
				warpReductionInstrumentor.logfile = config.parse<std::string>(
					"logfile", "");
			
		        warpReductionInstrumentor.type = WarpReductionInstrumentor::branchDivergence;
			}
			
			// configuration for warp instruction count instrumentor
			config = instrumentConfig["warpInstructionCount"];
			
			if(!config.is_null()) 
			{
			    warpInstructionCount = true;
			    
				warpReductionInstrumentor.enabled = config.parse<bool>(
					"enabled", true);
	
				warpReductionInstrumentor.logfile = config.parse<std::string>(
					"logfile", "");
			
		        warpReductionInstrumentor.type = WarpReductionInstrumentor::instructionCount;
			}
			
			// configuration for thread instruction count instrumentor
			config = instrumentConfig["threadInstructionCount"];
			
			if(!config.is_null()) 
			{
			    threadInstructionCount = true;
			    
				basicBlockInstrumentor.enabled = config.parse<bool>(
					"enabled", true);
	
				basicBlockInstrumentor.logfile = config.parse<std::string>(
					"logfile", "");
			
		        basicBlockInstrumentor.type = BasicBlockInstrumentor::instructionCount;
			}
			
			// configuration for basic block execution cound instrumentor
			config = instrumentConfig["basicBlockExecutionCount"];
			
			if(!config.is_null()) 
			{
			    basicBlockExecutionCount = true;
			    
				basicBlockInstrumentor.enabled = config.parse<bool>(
					"enabled", true);
	
				basicBlockInstrumentor.logfile = config.parse<std::string>(
					"logfile", "");
			
		        basicBlockInstrumentor.type = BasicBlockInstrumentor::executionCount;
			}
		}
	}
	catch(const hydrazine::Exception& exp) 
	{
		// do nothing
	}

	delete object;

   
	if(clockCycleCount)
	{
		report( "Creating clock cycle count instrumentor" );
		ocelot::addInstrumentor(_clockCycleCountInstrumentor);			
	}
	
	if(memoryEfficiency)
	{
	    report( "Creating memory efficiency instrumentor" );
	    _warpReductionInstrumentor.type = instrumentation::WarpReductionInstrumentor::memoryEfficiency;
	    ocelot::addInstrumentor(_warpReductionInstrumentor);
	}
	
	if(branchDivergence)
	{
	    report( "Creating branch divergence instrumentor" );
	    _warpReductionInstrumentor.type = instrumentation::WarpReductionInstrumentor::branchDivergence;
	    ocelot::addInstrumentor(_warpReductionInstrumentor);
	}
	
	if(warpInstructionCount)
	{
	    report( "Creating warp instruction count instrumentor" );
	    _warpReductionInstrumentor.type = instrumentation::WarpReductionInstrumentor::instructionCount;
	    ocelot::addInstrumentor(_warpReductionInstrumentor);
	}
	
	if(threadInstructionCount)
	{
	    report( "Creating thread instruction count instrumentor" );
	    _basicBlockInstrumentor.type = instrumentation::BasicBlockInstrumentor::instructionCount;
	    ocelot::addInstrumentor(_basicBlockInstrumentor);
	}
	
	if(basicBlockExecutionCount)
	{
	    report( "Creating basic block execution count instrumentor" );
	    _basicBlockInstrumentor.type = instrumentation::BasicBlockInstrumentor::executionCount;
	    ocelot::addInstrumentor(_basicBlockInstrumentor);
	}
}

InstrumentationConfiguration::~InstrumentationConfiguration()
{
    int err = mq_close(messageQueue);
    if(err < 0)
        report( "Failed to close message queue" );
}

}

#endif

