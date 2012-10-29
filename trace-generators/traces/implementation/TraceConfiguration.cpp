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
#include <hydrazine/interface/Exception.h>
#include <hydrazine/interface/debug.h>
#include <hydrazine/interface/json.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace trace
{

void ForceTraceConfiguration() {
}

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
	warpSynchronous.enabled = false; 
	performanceBound.enabled = false; 
	convergence.enabled = false;
	loadBalance = false;
	basicBlockCount = false;
	x86trace = false;

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
			loadBalance = traceConfig.parse<bool>("loadBalance", false);
			basicBlockCount = traceConfig.parse<bool>("basicBlockCount", false);
			x86trace = traceConfig.parse<bool>("x86Trace", false);

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
			
			hydrazine::json::Visitor cacheConfig =
				traceConfig["cacheSimulator"];
			if(!cacheConfig.is_null()) 
			{
				cacheSimulator.enabled = cacheConfig.parse<bool>(
					"enabled", false);
				
				cacheSimulator.writebackTime = cacheConfig.parse<int>(
					"writebackTime", 50);
				cacheSimulator.cacheSize = cacheConfig.parse<int>(
					"cacheSize", 8192);
				cacheSimulator.lineSize = cacheConfig.parse<int>(
					"lineSize", 64);
				cacheSimulator.hitTime = cacheConfig.parse<int>(
					"hitTime", 1);
				cacheSimulator.missTime = cacheConfig.parse<int>(
					"missTime", 200);
				cacheSimulator.associativity = cacheConfig.parse<int>(
					"associativity", 1);
				cacheSimulator.instructionMemory = cacheConfig.parse<bool>(
					"instructionMemory", false);
			}
			
			hydrazine::json::Visitor perfConfig =
				traceConfig["performanceBound"];
			if(!perfConfig.is_null()) 
			{
				performanceBound.enabled = perfConfig.parse<bool>(
					"enabled", false);
				performanceBound.render =
					perfConfig.parse<bool>("render", false);
				std::string protocol = 
					perfConfig.parse<std::string>("protocol", "sm_20");
				std::string output = 
					perfConfig.parse<std::string>("output", "dot");
				
				
				performanceBound.outputFormat =
					PerformanceBoundGenerator::Output_dot;
				if (output == "dot") {
					performanceBound.outputFormat =
						PerformanceBoundGenerator::Output_dot;
				}
				else if (output == "csv") {
					performanceBound.outputFormat =
						PerformanceBoundGenerator::Output_append_csv;
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
				report("performanceBound.enabled = "
					<< (performanceBound.enabled ? "true":"false"));
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
			
			hydrazine::json::Visitor cfgConfig =
				traceConfig["controlFlowVisualizer"];
			if(!cfgConfig.is_null())
			{
				controlFlowVisualizer.enabled =
					cfgConfig.parse<bool>("enabled", false);
				controlFlowVisualizer.allInstructions =
					cfgConfig.parse<bool>("allInstructions", false);
			}
			
			hydrazine::json::Visitor temporalSimtConfig = traceConfig["temporalSIMT"];
			if (!traceConfig.is_null()) {
				temporalSIMT.enabled = traceConfig.parse<bool>("enabled", false);
				temporalSIMT.warpSize = traceConfig.parse<int>("warpSize", 32);
				temporalSIMT.simdWidth = traceConfig.parse<int>("simdWidth", 16);
				temporalSIMT.simdIssueCount = traceConfig.parse<int>("simdIssueCount", 2);
			}
			
			activityFactor = traceConfig.parse<bool>("activityFactor", false);
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

	if(cacheSimulator.enabled)
	{
		report( "Creating cache simulator" );
		_cacheSimulator.database = database;

		_cacheSimulator.writebackTime     = cacheSimulator.writebackTime;
		_cacheSimulator.cacheSize         = cacheSimulator.cacheSize;
		_cacheSimulator.lineSize          = cacheSimulator.lineSize;
		_cacheSimulator.hitTime           = cacheSimulator.hitTime;
		_cacheSimulator.missTime          = cacheSimulator.missTime;
		_cacheSimulator.associativity     = cacheSimulator.associativity;
		_cacheSimulator.instructionMemory = cacheSimulator.instructionMemory;

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
	
	if (controlFlowVisualizer.enabled)
	{
		report("Creating ControlFlowVisualizer generator");
		_controlFlowVisualizer.database = database;
		_controlFlowVisualizer.allInstructions =
			controlFlowVisualizer.allInstructions;
		ocelot::addTraceGenerator(_controlFlowVisualizer, true);
	}
	
	if (temporalSIMT.enabled) {
		report("create SIMT generator");
		_temporalSIMTGenerator.warpSize = temporalSIMT.warpSize;
		_temporalSIMTGenerator.simdWidth = temporalSIMT.simdWidth;
		_temporalSIMTGenerator.simdIssueCount = temporalSIMT.simdIssueCount;
		
		ocelot::addTraceGenerator(_temporalSIMTGenerator);
	}
	
	if (basicBlockCount)
	{
		report("Creating basic block counter generator");
		_basicBlockCountGenerator.database = database;
		ocelot::addTraceGenerator(_basicBlockCountGenerator, true);
	}

	if(x86trace)
	{
		report("Creating x86 trace generator");
		_x86TraceGenerator.database = database;
		ocelot::addTraceGenerator(_x86TraceGenerator, true);
	}
	
	if (activityFactor) {
		report("Creating Activity Factor Generator");
		ocelot::addTraceGenerator(_activityFactorGenerator, true);
	}
}

}

#endif

