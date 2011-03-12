/*!
	\file LLVMDynamicExecutionManager.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief orchestrates the execution of a collection of CTAs through a decomposition of PTX kernels
	\date March 2011
*/

#ifndef OCELOT_LLVMDYNAMICEXECUTIONMANAGER_H_INCLUDED
#define OCELOT_LLVMDYNAMICEXECUTIONMANAGER_H_INCLUDED

namespace executive {

	class LLVMDynamicExecutableKernel;

	/*! \brief Controls the execution of worker threads */
	class LLVMDynamicExecutionManager {
	public:
		/*! \brief Launches a kernel on a grid using a context */
		static void launch(const LLVMDynamicExecutableKernel& kernel);
	
		/*! \brief Changes the number of worker threads */
		static void setWorkerThreadCount(unsigned int threads);

		/*! \brief Gets the current number of threads */
		static unsigned int threads();
		
		/*! \brief Flush references to translated kernels */
		static void flushTranslatedKernels();

	private:
		/*! \brief A vector of created threads */
		typedef std::vector< LLVMDynamicExecutableKernel *> WorkerVector;

	private:
	
		class Manager {
		public:
			/*! \brief Destroy all active threads */
			Manager();
			~Manager();
	
		public:
			/*! \brief Launches a kernel on a grid using a context */
			void launch(const DynamicExecutableKernel& kernel);
	
			/*! \brief Changes the number of worker threads */
			void setWorkerThreadCount(unsigned int threads);

			/*! \brief Gets the current number of threads */
			unsigned int threads() const;
		
			/*! \brief Flush references to translated kernels */
			void flushTranslatedKernels();
	
		private:
			/*! \brier The currently active worker threads */
			WorkerVector _workers;
		};
	
	private:
		/*! \brief The global singleton execution manager */
		static Manager _manager;
	};

}

#endif

