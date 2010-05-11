/*! \file ATIExecutableKernel.h
 *  \author Rodrigo Dominguez <rdomingu@ece.neu.edu>
 *  \date April 10, 2010
 *  \brief The header file for the ATI Executable Kernel class.
 */

#ifndef ATIEXECUTABLEKERNEL_H_INCLUDED
#define ATIEXECUTABLEKERNEL_H_INCLUDED

// Ocelot includes
#include <ocelot/executive/interface/ExecutableKernel.h>
#include <ocelot/executive/interface/ATIGPUDevice.h>

namespace executive 
{
	class ATIExecutableKernel : public executive::ExecutableKernel {
		public:
			/*! \brief Constructor */
			ATIExecutableKernel(ir::Kernel &k, CALresource *cb0, 
					CALresource *cb1);

			/*!	\brief Launch a kernel on a 2D grid */
			void launchGrid(int width, int height);

			/*!	\brief Sets the shape of a kernel */
			void setKernelShape(int x, int y, int z);

			/*! \brief Changes the amount of external shared memory */
			void setExternSharedMemorySize(unsigned int);

			/*! \brief Sets the max number of pthreads this kernel can use */
			void setWorkerThreads(unsigned int workerThreadLimit);

			/*! \brief Indicate that the kernels parameters have been updated */
			void updateParameterMemory();

			/*! \brief Indicate that other memory has been updated */
			void updateMemory();

			/*! \brief Get a vector of all textures references by the kernel */
			TextureVector textureReferences() const;

			/*!	\brief adds a trace generator to the EmulatedKernel */
			void addTraceGenerator(trace::TraceGenerator* generator);

			/*!	\brief removes a trace generator from an EmulatedKernel */
			void removeTraceGenerator(trace::TraceGenerator* generator);

		private:
			/*! \brief Type of the constant buffer (cb) */
			typedef struct { int32_t x, y, z, w; } cb_t;

			/********************************************************//**
			 * \name cb0 Memory Manager (ABI data)
			 ***********************************************************/
			//@{
			/*! \brief CAL cb1 resource */
			CALresource *_cb0Resource;
			//@}
			
			/********************************************************//**
			 * \name cb1 Memory Manager (param)
			 ***********************************************************/
			//@{
			/*! \brief CAL cb1 resource */
			CALresource *_cb1Resource;
			//@}
			
			CALprogramGrid pg;

			/*! \brief Returns a pointer to an instance to the 
				CalDriver singleton */
			static const cal::CalDriver *CalDriver();
	};
}

#endif

