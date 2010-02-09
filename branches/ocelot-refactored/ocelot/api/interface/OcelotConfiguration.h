/*!
	\file OcelotConfiguration.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief defines a configuration class for GPU Ocelot

	By centralizing the configuration object, it should be fairly clear what the structure of an
	Ocelot configuration is and how to extend it.
*/

#ifndef GPUOCELOT_API_OCELOTCONFIGURATION_H_INCLUDED
#define GPUOCELOT_API_OCELOTCONFIGURATION_H_INCLUDED

// C++ stdlib includes
#include <string>
#include <fstream>

namespace api {

	//! \brief configuration object structure for GPU Ocelot
	class OcelotConfiguration {
	public:

		//! Configuration for trace generation facilities
		class TraceGeneration {
		public:
			TraceGeneration();

		public:

			//! \brief master flag for trace generation
			bool enabled;

			//! \brief path to trace generation database
			std::string database;

			//! \brief indicates traces are in place
			bool inPlaceTraces;

			//! \brief trace::MemoryTraceGenerator
			bool memory;

			//! \brief trace::BranchTraceGenerator
			bool branch;

			//! \brief trace::SharedComputationTraceGenerator
			bool sharedComputation;

			//! \brief trace::ParallelismTraceGenerator
			bool parallelism;

			//! \brief trace::InstructionTraceGenerator
			bool instruction;

			//! \brief trace::CacheSimulator
			bool cacheSimulator;
		};

		class CudaRuntimeImplementation {
		public:
			CudaRuntimeImplementation();

		public:

			//! \brief names particular CUDA Runtime implementation to instantiate
			std::string implementation;
			
			//! \brief for TraceGeneratingRuntime, path to output file
			std::string runtimeApiTrace;
		};

		class Executive {
		public:
			Executive();

		public:
			
			//! \brief ID of device to select by default
			int defaultDeviceID;

			/*! \brief selects preferred ISA [if multiple are available] - cast to 
				ir::Instruction::Architecture
			*/
			int preferredISA;

			/*! 
				\brief selects optimization level - cast to translator::Translator::OptimizationLevel
			*/
			int optimizationLevel;

			//! \brief if true, Ocelot will either choose only the preferred ISA or die
			bool required;

			//! \brief filter enabling LLVM devices if present
			bool enableLLVM;

			//! \brief filter enbabling Emulated PTX devices if present
			bool enableEmulated;

			//! \brief filter enabling CUDA GPU devices if present
			bool enableGPU;

			//! \brief maximum number of worker threads - a non-positive number indicates no limit
			int workerThreadLimit;
		};

	public:

		//! \brief construct with default configuration
		OcelotConfiguration();

		//! \brief load configuration from stream as JSON
		OcelotConfiguration(std::istream &stream);

		//! \brief loads the configuration object from a path
		OcelotConfiguration(const std::string &path);

		//! \brief initializes configuration object from a stream as JSON
		void initialize(std::istream &stream);

		//! \brief gets singleton configuration object or constructs from 'configure.ocelot'
		static const OcelotConfiguration & get();

		//! \brief gets singleton config object's .executive member
		static const Executive & getExecutive();

		//! \brief gets singleton config object's .cuda member
		static const CudaRuntimeImplementation & getCuda();

		//! \brief gets singleton config object's .trace member
		static const TraceGeneration & getTrace();

	public:

		//! \brief path to configuration file for reparsing 
		std::string path;

		//! \brief name of Ocelot implementation
		std::string ocelot;

		//! \brief version of current Ocelot configuration
		std::string version;

		//! \brief configuration for trace generator
		TraceGeneration trace;

		//! \brief configuration for CUDA runtime implementation
		CudaRuntimeImplementation cuda;

		//! \brief configuration for Ocelot Executive
		Executive executive;
	};

}

#endif

