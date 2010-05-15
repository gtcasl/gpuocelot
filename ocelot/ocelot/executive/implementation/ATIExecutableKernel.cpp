/*! \file ATIExecutableKernel.cpp
 *  \author Rodrigo Dominguez <rdomingu@ece.neu.edu>
 *  \date April 10, 2010
 *  \brief The source file for the ATI Executable Kernel class.
 */

// Ocelot includes
#include <ocelot/executive/interface/ATIExecutableKernel.h>

// Hydrazine includes
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/Exception.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

#define Throw(x) {std::stringstream s; s << x; \
	throw hydrazine::Exception(s.str()); }

namespace executive
{
	ATIExecutableKernel::ATIExecutableKernel(ir::Kernel &k,
			CALresource *cb0, CALresource *cb1)
		: ExecutableKernel(k), _cb0Resource(cb0), _cb1Resource(cb1)
	{
	}

	void ATIExecutableKernel::launchGrid(int width, int height)
	{
		assertM(false, "Not implemented yet");
	}

	void ATIExecutableKernel::setKernelShape(int x, int y, int z)
	{
		cb_t *cb0;
		CALuint pitch = 0;
		CALuint flags = 0;

		CalDriver()->calResMap((CALvoid **)&cb0, &pitch, *_cb0Resource, flags);

		cb_t temp = {x, y, z, 0};
		cb0[0] = temp;
		report("setKernelShape : cb0[0] = {" 
				<< cb0[0].x
				<< ", " << cb0[0].y
				<< ", " << cb0[0].z
				<< ", " << cb0[0].w
				<< "}");

		CalDriver()->calResUnmap(*_cb0Resource);
	}

	void ATIExecutableKernel::setExternSharedMemorySize(unsigned int)
	{
		assertM(false, "Not implemented yet");
	}

	void ATIExecutableKernel::setWorkerThreads(unsigned int workerThreadLimit)
	{
		assertM(false, "Not implemented yet");
	}

	void ATIExecutableKernel::updateParameterMemory()
	{
		report("updateParameterMemory() - size: " << parameters.size());

		if (parameters.size() == 0) return;

		cb_t *cb1;
		CALuint pitch = 0;
		CALuint flags = 0;

		CalDriver()->calResMap((CALvoid **)&cb1, &pitch, *_cb1Resource, flags);

		int i = 0;
		std::vector<ir::Parameter>::const_iterator it;
		for (it = parameters.begin() ; it != parameters.end(); it++) {
			assertM(it->arrayValues.size() == 1, 
					"Array parameters not supported yet");
			ir::Parameter::ValueType v = it->arrayValues[0];

			switch(it->type) {
				case ir::PTXOperand::u64:
				{
					// CUDA pointers are 32-bits
					assertM(v.val_u64 >> 32 == 0, "Pointer out of range");
					cb1[i].x = v.val_u32 - ATIGPUDevice::Uav0BaseAddr; 
					report("cb1[" << i << "] = {" << cb1[i].x << "}");
					i++;
					break;
				}
				case ir::PTXOperand::s32:
				{
					cb1[i].x = v.val_s32;
					report("cb1[" << i << "] = {" << cb1[i].x << "}");
					i++;
					break;
				}
				default:
				{
					Throw("Parameter type " 
							<< ir::PTXOperand::toString(it->type)
							<< " not supported");
				}
			}
		}

		CalDriver()->calResUnmap(*_cb1Resource);
	}

	void ATIExecutableKernel::updateMemory()
	{
		assertM(false, "Not implemented yet");
	}

	ExecutableKernel::TextureVector 
		ATIExecutableKernel::textureReferences() const
	{
		assertM(false, "Not implemented yet");
	}

	void ATIExecutableKernel::addTraceGenerator(trace::TraceGenerator* generator)
	{
		assertM(false, "Not implemented yet");
	}

	void ATIExecutableKernel::removeTraceGenerator(trace::TraceGenerator* generator)
	{
		assertM(false, "Not implemented yet");
	}

	inline const cal::CalDriver *ATIExecutableKernel::CalDriver()
	{
		return cal::CalDriver::Instance();
	}

}
