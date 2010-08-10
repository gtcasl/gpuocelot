/*! \file ATIExecutableKernel.cpp
 *  \author Rodrigo Dominguez <rdomingu@ece.neu.edu>
 *  \date April 10, 2010
 *  \brief The source file for the ATI Executable Kernel class.
 */

// Ocelot includes
#include <ocelot/executive/interface/ATIExecutableKernel.h>
#include <ocelot/translator/interface/PTXToILTranslator.h>

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
	ATIExecutableKernel::ATIExecutableKernel(ir::Kernel &k, CALcontext *context,
			CALevent *event, CALresource *uav0, CALresource *cb0, CALresource *cb1)
		: 
			ExecutableKernel(k), 
			_context(context),
			_event(event),
			_info(),
			_module(0), 
			_object(0), 
			_image(0), 
			_uav0Resource(uav0),
			_uav0Mem(0),
			_uav0Name(0),
			_uav1Name(0),
			_cb0Resource(cb0), 
			_cb0Mem(0),
			_cb0Name(0),
			_cb1Resource(cb1),
			_cb1Mem(0),
			_cb1Name(0)
	{
	}

	void ATIExecutableKernel::launchGrid(int width, int height)
	{
		// initialize ABI data
		cb_t *cb0;
		CALuint pitch = 0;
		CALuint flags = 0;

		cb_t blockDim = {_blockDim.x, _blockDim.y, _blockDim.z, 0};
		cb_t gridDim = {width, height, 1, 0};

		CalDriver()->calResMap((CALvoid **)&cb0, &pitch, *_cb0Resource, flags);
		cb0[0] = blockDim;
		cb0[1] = gridDim;
		CalDriver()->calResUnmap(*_cb0Resource);

		// translate ptx kernel
		report("Running IL Translator");
		translator::PTXToILTranslator translator;
		ir::ILKernel *ilKernel = 
			static_cast<ir::ILKernel*>(translator.translate(this));

		report("Assembling il module");
		ilKernel->assemble();

		// query device info
		CalDriver()->calDeviceGetInfo(&_info, 0);

		// compile, link, and load module
		CalDriver()->calclCompile(&_object, CAL_LANGUAGE_IL, 
				ilKernel->code().c_str(), _info.target);

		CalDriver()->calclLink(&_image, &_object, 1);
		CalDriver()->calModuleLoad(&_module, *_context, _image);

		// bind memory handles to module names
		CalDriver()->calCtxGetMem(&_uav0Mem, *_context, *_uav0Resource);
		CalDriver()->calModuleGetName(&_uav0Name, *_context, _module, "uav0");
		CalDriver()->calCtxSetMem(*_context, _uav0Name, _uav0Mem);

		// uav1Name is binded to uav0Mem (for less-than-32bits memory ops)
		CalDriver()->calModuleGetName(&_uav1Name, *_context, _module, "uav1");
		CalDriver()->calCtxSetMem(*_context, _uav1Name, _uav0Mem);

		CalDriver()->calCtxGetMem(&_cb0Mem, *_context, *_cb0Resource);
		CalDriver()->calModuleGetName(&_cb0Name, *_context, _module, "cb0");
		CalDriver()->calCtxSetMem(*_context, _cb0Name, _cb0Mem);

		CalDriver()->calCtxGetMem(&_cb1Mem, *_context, *_cb1Resource);
		CalDriver()->calModuleGetName(&_cb1Name, *_context, _module, "cb1");
		CalDriver()->calCtxSetMem(*_context, _cb1Name, _cb1Mem);

		// get module entry
		CALfunc func = 0;
		CalDriver()->calModuleGetEntry(&func, *_context, _module, "main");

		// invoke kernel
		CALdomain3D gridBlock = {_blockDim.x, _blockDim.y, _blockDim.z};
		CALdomain3D gridSize = {width, height, 1};

		CALprogramGrid pg;
		pg.func      = func;
		pg.flags     = 0;
		pg.gridBlock = gridBlock;
		pg.gridSize  = gridSize;
		CalDriver()->calCtxRunProgramGrid(_event, *_context, &pg);

		// clean up
		// release memory handles
		CalDriver()->calCtxReleaseMem(*_context, _uav0Mem);
		CalDriver()->calCtxReleaseMem(*_context, _cb0Mem);
		CalDriver()->calCtxReleaseMem(*_context, _cb1Mem);

		// unload module
		CalDriver()->calModuleUnload(*_context, _module);

		// free object and image
		CalDriver()->calclFreeImage(_image);
		CalDriver()->calclFreeObject(_object);

		delete ilKernel;
	}

	void ATIExecutableKernel::setKernelShape(int x, int y, int z)
	{
		_blockDim.x = x;
		_blockDim.y = y;
		_blockDim.z = z;
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
		ParameterVector::const_iterator it;
		for (it = arguments.begin(); it != arguments.end(); it++) {
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
