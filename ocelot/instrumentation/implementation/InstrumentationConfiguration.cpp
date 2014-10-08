/*! \file   InstrumentationConfiguration.cpp
	\author Naila Farooqui <naila@cc.gatech.edu>
	\date   Tuesday November 22, 2011
	\brief  The source file for the InstrumentationConfiguration class.
*/

#ifndef INSTRUMENTATION_CONFIGURATION_CPP_INCLUDED
#define INSTRUMENTATION_CONFIGURATION_CPP_INCLUDED

// Instrumentation includes
#include <ocelot/instrumentation/interface/InstrumentationConfiguration.h>

// Ocelot includes
#include <ocelot/api/interface/ocelot.h>
#include <ocelot/instrumentation/interface/kernel_profile.h>

// Hydrazine includes
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/json.h>

#include <errno.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

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
	boundsCheck = false;
	clockCycleCount = false;
	memoryEfficiency = false;
	branchDivergence = false;
	
	warpInstructionCount = false;
	threadInstructionCount = false;
	
	basicBlockExecutionCount = false;
	
	controlFlowCheck = false;
	registerCheck = false;
	alignmentCheck = false;
	try
	{
		std::ifstream stream("configure.ocelot");
	
		object = parser.parse_object(stream);

		hydrazine::json::Visitor mainConfig(object);

		hydrazine::json::Visitor instrumentConfig = mainConfig["instrument"];
		
		if(!instrumentConfig.is_null())
		{
			// configuration for basic block execution cound instrumentor
			hydrazine::json::Visitor config = instrumentConfig["errorInjection"];
			
			if(!config.is_null()) 
			{
			    errorInjection = true;
			    
				errorInjectionInstrumentor.enabled = config.parse<bool>(
					"enabled", true);
	
				errorInjectionInstrumentor.logfile = config.parse<std::string>(
					"logfile", "");
			}
			// configuration for alignment check instrumentor
			config = instrumentConfig["alignmentCheck"];
			
			if(!config.is_null()) 
			{
			    alignmentCheck = true;
			    
				alignmentCheckInstrumentor.enabled = config.parse<bool>(
					"enabled", true);
	
				alignmentCheckInstrumentor.logfile = config.parse<std::string>(
					"logfile", "");
			}
			
			// configuration for alignment check instrumentor
			config = instrumentConfig["registerCheck"];
			
			if(!config.is_null()) 
			{
			    registerCheck = true;
			    
				registerCheckInstrumentor.enabled = config.parse<bool>(
					"enabled", true);
	
				registerCheckInstrumentor.lrThreshold= config.parse<int>(
					"threshold", 2);

				registerCheckInstrumentor.logfile = config.parse<std::string>(
					"logfile", "");
			}
			
			// configuration for alignment check instrumentor
			config = instrumentConfig["controlFlowCheck"];
			
			if(!config.is_null()) 
			{
			    controlFlowCheck = true;
			    
				controlFlowCheckInstrumentor.enabled = config.parse<bool>(
					"enabled", true);
	
				controlFlowCheckInstrumentor.logfile = config.parse<std::string>(
					"logfile", "");
			}
			
			// configuration for bounds check instrumentor
			config = instrumentConfig["boundsCheck"];
			
			if(!config.is_null()) 
			{
			    boundsCheck = true;
			    
				boundsCheckInstrumentor.enabled = config.parse<bool>(
					"enabled", true);
	
				boundsCheckInstrumentor.logfile = config.parse<std::string>(
					"logfile", "");
			}
			
            // configuration for clock cycle instrumentor
			config = instrumentConfig["clockCycleCount"];
			
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

	if(alignmentCheck)
	{
		report( "Creating alignment check instrumentor" );
		ocelot::addInstrumentor(_alignmentCheckInstrumentor);			
	}
		
	if(controlFlowCheck)
	{
		report( "Creating control check instrumentor" );
		ocelot::addInstrumentor(_controlFlowCheckInstrumentor);			
	}
	

	if(registerCheck)
	{
		report( "Creating register check instrumentor" );
		ocelot::addInstrumentor(_registerCheckInstrumentor);			
	}
	
	if(boundsCheck)
	{
		report( "Creating array bounds check instrumentor" );
		ocelot::addInstrumentor(_boundsCheckInstrumentor);			
	}
	
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
	
	if(errorInjection)
	{
	    report( "Creating error injection" );
	    ocelot::addInstrumentor(_errorInjectionInstrumentor);
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

