/*! \file   TraceConfiguration.cpp
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date   Saturday July 31, 2010
	\brief  The source file for the TraceConfiguration class.
*/

#ifndef TRACE_CONFIGURATION_CPP_INCLUDED
#define TRACE_CONFIGURATION_CPP_INCLUDED

// Trace includes
#include <traces/interface/TraceConfiguration.h>

// Ocelot includes
#include <ocelot/api/interface/ocelot.h>

// Hydrazine includes
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/json.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 1

namespace trace
{

TraceConfiguration TraceConfiguration::Singleton;

TraceConfiguration::TraceConfiguration()
{
	hydrazine::json::Parser parser;
	hydrazine::json::Object* object = 0;

	// initialize
	memory = false;
	sharedComputation = false;
	branch = false;
	parallelism = false;
	instruction = false;
	cacheSimulator = false;
	warpSynchronous.enabled = false; 
	performanceBound.enabled = false; 
	convergence.enabled = false;
	loadBalance = false;

	try
	{
		std::ifstream stream("configure.ocelot");
	
		object = parser.parse_object(stream);

		hydrazine::json::Visitor mainConfig(object);

		hydrazine::json::Visitor traceConfig = mainConfig["trace"];
		if(!traceConfig.is_null())
		{
			database = traceConfig.parse<std::string>(
				"database", "trace/database.trace");
			inPlaceTraces = traceConfig.parse<bool>("inPlaceTraces", true);
			memory = traceConfig.parse<bool>("memory", false);
			branch = traceConfig.parse<bool>("branch", false);
			sharedComputation = traceConfig.parse<bool>(
				"sharedComputation", false);
			instruction = traceConfig.parse<bool>("instruction", false);
			parallelism = traceConfig.parse<bool>("parallelism", false);
			cacheSimulator = traceConfig.parse<bool>("cacheSimulator", false);
			loadBalance = traceConfig.parse<bool>("loadBalance", false);

			// more detailed configuration for this trace generator
			hydrazine::json::Visitor warpSyncConfig =
				traceConfig["warpSynchronous"];
			if(!warpSyncConfig.is_null()) 
			{
				warpSynchronous.enabled = warpSyncConfig.parse<bool>(
					"enabled", false);
				warpSynchronous.emitHotPaths = warpSyncConfig.parse<bool>(
					"emitHotPaths", false);
			}
	
			hydrazine::json::Visitor perfConfig =
				traceConfig["performanceBound"];
			if(!perfConfig.is_null()) 
			{
				performanceBound.enabled = perfConfig.parse<bool>(
					"enabled", false);
				performanceBound.render = perfConfig.parse<bool>("render", false);
				std::string protocol = 
					perfConfig.parse<std::string>("protocol", "sm_20");
				std::string output = 
					perfConfig.parse<std::string>("output", "dot");
				
				
				performanceBound.outputFormat = PerformanceBoundGenerator::Output_dot;
				if (output == "dot") {
					performanceBound.outputFormat = PerformanceBoundGenerator::Output_dot;
				}
				else if (output == "csv") {
					performanceBound.outputFormat = PerformanceBoundGenerator::Output_append_csv;
				}
				
				performanceBound.protocol =
					PerformanceBoundGenerator::Protocol_ideal;
				if(protocol == "sm_10")
				{
					performanceBound.protocol =
						PerformanceBoundGenerator::Protocol_sm_10;
				}
				else if(protocol == "sm_11")
				{
					performanceBound.protocol =
						PerformanceBoundGenerator::Protocol_sm_11;
				}
				else if(protocol == "sm_12")
				{
					performanceBound.protocol =
						PerformanceBoundGenerator::Protocol_sm_12;
				}
				else if(protocol == "sm_13")
				{
					performanceBound.protocol =
						PerformanceBoundGenerator::Protocol_sm_13;
				}
				else if(protocol == "sm_20")
				{
					performanceBound.protocol =
						PerformanceBoundGenerator::Protocol_sm_20;
				}
				else if(protocol == "sm_ideal")
				{
					performanceBound.protocol =
						PerformanceBoundGenerator::Protocol_ideal;
				}
				else
				{
					std::cerr << "Invalid protocol '" << protocol << "'\n";
				}
				report("performanceBound.enabled = " << (performanceBound.enabled ? "true":"false"));
			}
	
			hydrazine::json::Visitor convConfig = traceConfig["convergence"];
			if(!convConfig.is_null())
			{
				convergence.enabled = convConfig.parse<bool>("enabled", false);
				convergence.logfile = convConfig.parse<std::string>(
					"logfile", "traces/convergence.csv");
				convergence.dot = convConfig.parse<bool>("dot", false);
				convergence.render = convConfig.parse<bool>("render", false);
			}
			
			hydrazine::json::Visitor cfgConfig = traceConfig["controlFlowVisualizer"];
			if (!cfgConfig.is_null()) {
				controlFlowVisualizer.enabled = cfgConfig.parse<bool>("enabled", false);
				controlFlowVisualizer.allInstructions = cfgConfig.parse<bool>("allInstructions", false);
			}
		}
	}
	catch(const hydrazine::Exception& exp) 
	{
		// do nothing
	}

	delete object;

	if(memory)
	{
		report( "Creating memory trace generator" );
		_memoryTraceGenerator.database = database;
		_memoryTraceGenerator.headerOnly = inPlaceTraces;
		ocelot::addTraceGenerator(_memoryTraceGenerator, true);			
	}
	
	if(sharedComputation)
	{
		report( "Creating shared computation trace generator" );
		_sharedComputationGenerator.database = database;
		ocelot::addTraceGenerator(_sharedComputationGenerator, true);
	}

	if(branch)
	{
		report( "Creating branch trace generator" );
		_branchTraceGenerator.database = database;
		ocelot::addTraceGenerator(_branchTraceGenerator, true);
	}

	if(parallelism)
	{
		report( "Creating parallelism trace generator" );
		_parallelismTraceGenerator.database = database;
		ocelot::addTraceGenerator(_parallelismTraceGenerator, true);
	}

	if(instruction)
	{
		report( "Creating instruction trace generator" );
		_instructionTraceGenerator.database = database;
		ocelot::addTraceGenerator(_instructionTraceGenerator, true);
	}

	if(cacheSimulator)
	{
		report( "Creating cache simulator" );
		_cacheSimulator.database = database;
		ocelot::addTraceGenerator(_cacheSimulator, true);	
	}

	if(warpSynchronous.enabled) 
	{
		report( "Creating warp synchronous detector" );
		_warpSynchronous.database = database;
		ocelot::addTraceGenerator(_warpSynchronous, true);
	}
	
	if(performanceBound.enabled) 
	{
		report("Creating performance bound trace generator");
		_performanceBound.database = database;
		_performanceBound.protocol = performanceBound.protocol;
		_performanceBound.render = performanceBound.render;
		_performanceBound.outputFormat = performanceBound.outputFormat;
		ocelot::addTraceGenerator(_performanceBound, true);
	}

	if(convergence.enabled) 
	{
		report("Creating convergence trace generator");
		_convergence.database = database;
		ocelot::addTraceGenerator(_convergence, true);
	}
	
	if (loadBalance)
	{
		report("Creating load balance generator");
		_loadBalance.database = database;
		ocelot::addTraceGenerator(_loadBalance, true);
	}
	
	if (controlFlowVisualizer.enabled) {
		report("Creating ControlFlowVisualizer generator");
		_controlFlowVisualizer.database = database;
		_controlFlowVisualizer.allInstructions = controlFlowVisualizer.allInstructions;
		ocelot::addTraceGenerator(_controlFlowVisualizer, true);
	}
}

}

#endif

