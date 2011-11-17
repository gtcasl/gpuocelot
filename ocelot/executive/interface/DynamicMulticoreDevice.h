/*!
	\file DynamicMulticoreDevice.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date November 11, 2011
	\brief demonstrates integrated concepts of subkernel formation and vectorization
*/

#ifndef OCELOT_EXECUTIVE_DYNAMICEXECUTIVE_H_INCLUDED
#define OCELOT_EXECUTIVE_DYNAMICEXECUTIVE_H_INCLUDED

// Ocelot includes
#include <ocelot/ir/interface/Module.h>
#include <ocelot/executive/interface/EmulatorDevice.h>
#include <ocelot/executive/interface/DynamicMulticoreKernel.h>

namespace executive {

	class DynamicMulticoreDevice: public EmulatorDevice {
	public:
	
		//! 
		class Configuration {
		public:
			enum ThreadScheduler {
				TS_StaticRoundRobin,
				TS_StaticThreadFrontiers,
				ThreadScheduler_invalid
			};
			
		public:
			Configuration();
			
		public:
			//! \brief indicates the maximum size of each warp
			int maximumWarpSize;
			
			//! \brief scheduling policy
			ThreadScheduler schedulingPolicy;
		};
		
		
		class Module {
		public:
			Module(const ir::Module *module);
			Module();
			
		public:
			//! pointer to baseline module
			const ir::Module *ptxModule;
			
			//! kernel map
			DynamicMulticoreKernelMap kernels;
		};
		typedef std::map< std::string, Module> ModuleMap;
	
	public:
	
		DynamicMulticoreDevice(int flags = 0);
		virtual ~DynamicMulticoreDevice();
	
	public:
		/*! \brief Load a module, must have a unique name */
		virtual void load(const ir::Module* module);
		
		/*! \brief Unload a module by name */
		void unload(const std::string& name);
		
		/*! \brief Get a translated kernel from the device */
		virtual ExecutableKernel* getKernel(const std::string& module, 
			const std::string& kernel);
	
		public:
			/*! \brief helper function for launching a kernel
				\param module module name
				\param kernel kernel name
				\param grid grid dimensions
				\param block block dimensions
				\param sharedMemory shared memory size
				\param argumentBlock array of bytes for parameter memory
				\param argumentBlockSize number of bytes in parameter memory
				\param traceGenerators vector of trace generators to add 
					and remove from kernel
			*/
			virtual void launch(const std::string& module, 
				const std::string& kernel, const ir::Dim3& grid, 
				const ir::Dim3& block, size_t sharedMemory, 
				const void* argumentBlock, size_t argumentBlockSize, 
				const trace::TraceGeneratorVector& 
				traceGenerators = trace::TraceGeneratorVector(),
				const ir::ExternalFunctionSet* externals = 0);
				
			/*! \brief Get the last error from this device */
			unsigned int getLastError();
			
			/*! \brief Wait until all asynchronous operations have completed */
			void synchronize();
			
		public:
			/*! \brief Limit the worker threads used by this device */
			virtual void limitWorkerThreads(unsigned int threads);			
			/*! \brief Set the optimization level for kernels in this device */
			virtual void setOptimizationLevel(
				translator::Translator::OptimizationLevel level);
		
		protected:
		
			//! \brief configures DynamicExecutive device
			Configuration configuration;
			
			//! \brief loaded modules
			ModuleMap modules;
	};

}

#endif

