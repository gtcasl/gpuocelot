/* 
	\file DynamicMulticoreCPUDevice.h
	\author Andrew Kerr <arkerr@gatech.edu>, Gregory Diamos <gregory.diamos@gatech.edu>
	\date March 2011
	\brief implements a dynamic execution environment for multicore CPUs
*/

#ifndef OCELOT_EXECUTIVE_DYNAMICMULTICORECPUDEVICE_H_INCLUDED
#define OCELOT_EXECUTIVE_DYNAMICMULTICORECPUDEVICE_H_INCLUDED

// ocelot includes
#include <ocelot/executive/interface/EmulatorDevice.h>

namespace executive {

	/*! \brief A device to control all of the cores in a single CPU */
	class DynamicMulticoreCPUDevice: public EmulatorDevice {
		private:
			/*! \brief Specialization of EmulatorDevice::Module for LLVM */
			class Module : public EmulatorDevice::Module {
			public:
				/*! \brief Construct this based on a module */
				Module(const ir::Module* m = 0, Device* d = 0);
			
				/*! \brief Destroy this, unload the module from caches */
				~Module();
			
				/*! \brief Get a specific LLVMExecutableKernel or 0 */
				ExecutableKernel* getKernel(const std::string& name);
			};

		private:
			/*! \brief Number of worker threads to launch */
			unsigned int _workerThreads;
			/*! \brief The optimization level to use when translating kernels */
			translator::Translator::OptimizationLevel _optimizationLevel;

		public:
			/*! \brief Sets the device properties */
			DynamicMulticoreCPUDevice(unsigned int flags = 0);

		public:
			/*! \brief Load a module, must have a unique name */
			void load(const ir::Module* module);
			/*! \brief Get a translated kernel from the device */
			ExecutableKernel* getKernel(
				const std::string& module, 
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
			void launch(
				const std::string& module, 
				const std::string& kernel, 
				const ir::Dim3& grid, 
				const ir::Dim3& block,
				size_t sharedMemory, 
				const void* argumentBlock,
				size_t argumentBlockSize, 
				const trace::TraceGeneratorVector& 
				traceGenerators = trace::TraceGeneratorVector());
		
		public:
			/*! \brief Limit the worker threads used by this device */
			void limitWorkerThreads(unsigned int threads);
			/*! \brief Set the optimization level for kernels in this device */
			void setOptimizationLevel(
				translator::Translator::OptimizationLevel level);
	};

}

#endif

