/*! \file CalDriver.cpp
 *  \author Rodrigo Dominguez <rdomingu@ece.neu.edu>
 *  \date April 8, 2010
 *  \brief The source file for the CalDriver class.
 */

// Ocelot includes
#include <ocelot/cal/interface/CalDriver.h>

// hydrazine includes
#include <hydrazine/interface/Casts.h>

// Linux system headers
#include <dlfcn.h>

namespace cal
{
	// start with an uninitialized singleton
	CalDriver *CalDriver::_instance = 0;

	CalDriver::CalDriver() : _driver(0), _compiler(0)
	{
		_driver   = dlopen("libaticalrt.so", RTLD_LAZY);
		_compiler = dlopen("libaticalcl.so", RTLD_LAZY);

		hydrazine::bit_cast(_calInit,              dlsym(_driver, "calInit"));
		hydrazine::bit_cast(_calShutdown,          dlsym(_driver, "calShutdown"));
		hydrazine::bit_cast(_calDeviceOpen,        dlsym(_driver, "calDeviceOpen"));
		hydrazine::bit_cast(_calDeviceClose,       dlsym(_driver, "calDeviceClose"));
		hydrazine::bit_cast(_calDeviceGetInfo,     dlsym(_driver, "calDeviceGetInfo"));
		hydrazine::bit_cast(_calCtxCreate,         dlsym(_driver, "calCtxCreate"));
		hydrazine::bit_cast(_calCtxDestroy,        dlsym(_driver, "calCtxDestroy"));
		hydrazine::bit_cast(_calCtxGetMem,         dlsym(_driver, "calCtxGetMem"));
		hydrazine::bit_cast(_calCtxReleaseMem,     dlsym(_driver, "calCtxReleaseMem"));
		hydrazine::bit_cast(_calCtxSetMem,         dlsym(_driver, "calCtxSetMem"));
		hydrazine::bit_cast(_calModuleLoad,        dlsym(_driver, "calModuleLoad"));
		hydrazine::bit_cast(_calModuleUnload,      dlsym(_driver, "calModuleUnload"));
		hydrazine::bit_cast(_calModuleGetEntry,    dlsym(_driver, "calModuleGetEntry"));
		hydrazine::bit_cast(_calModuleGetName,     dlsym(_driver, "calModuleGetName"));
		hydrazine::bit_cast(_calResAllocLocal1D,   dlsym(_driver, "calResAllocLocal1D"));
		hydrazine::bit_cast(_calResFree,           dlsym(_driver, "calResFree"));
		hydrazine::bit_cast(_calResMap,            dlsym(_driver, "calResMap"));
		hydrazine::bit_cast(_calResUnmap,          dlsym(_driver, "calResUnmap"));
		hydrazine::bit_cast(_calCtxRunProgramGrid, dlsym(_driver, "calCtxRunProgramGrid"));
		hydrazine::bit_cast(_calCtxIsEventDone,    dlsym(_driver, "calCtxIsEventDone"));
		hydrazine::bit_cast(_calGetErrorString,    dlsym(_driver, "calGetErrorString"));

		hydrazine::bit_cast(_calclCompile,    dlsym(_compiler, "calclCompile"));
		hydrazine::bit_cast(_calclLink,       dlsym(_compiler, "calclLink"));
		hydrazine::bit_cast(_calclFreeObject, dlsym(_compiler, "calclFreeObject"));
		hydrazine::bit_cast(_calclFreeImage,  dlsym(_compiler, "calclFreeImage"));

		CALresult result;
		result = calInit();
	}

	CalDriver::~CalDriver()
	{
		CALresult result;
		result = calShutdown();

		if (_driver) {
			dlclose(_driver);
		}

		if (_compiler) {
			dlclose(_compiler);
		}

        // don't delete _instance as this would call the destructor again
        // let the memory be reclaimed when the program terminates
	}

	CalDriver *CalDriver::Instance()
	{
		if (_instance == 0) {
			_instance = new CalDriver;
		}

		return _instance;
	}

	
	CALresult CalDriver::calInit()
	{
		return (*_calInit)();
	}

	CALresult CalDriver::calShutdown()
	{
		return (*_calShutdown)();
	}

	CALresult CalDriver::calDeviceOpen(CALdevice *dev, CALuint ordinal)
	{
		return (*_calDeviceOpen)(dev, ordinal);
	}

	CALresult CalDriver::calDeviceClose(CALdevice dev)
	{
		return (*_calDeviceClose)(dev);
	}

	CALresult CalDriver::calDeviceGetInfo(CALdeviceinfo *info, CALuint ordinal)
	{
		return (*_calDeviceGetInfo)(info, ordinal);
	}

	CALresult CalDriver::calCtxCreate(CALcontext *ctx, CALdevice dev)
	{
		return (*_calCtxCreate)(ctx, dev);
	}

	CALresult CalDriver::calCtxDestroy(CALcontext ctx)
	{
		return (*_calCtxDestroy)(ctx);
	}

	CALresult CalDriver::calCtxGetMem(CALmem *mem, CALcontext ctx, CALresource res)
	{
		return (*_calCtxGetMem)(mem, ctx, res);
	}

	CALresult CalDriver::calCtxReleaseMem(CALcontext ctx, CALmem mem)
	{
		return (*_calCtxReleaseMem)(ctx, mem);
	}

	CALresult CalDriver::calCtxSetMem(CALcontext ctx, CALname name, CALmem mem)
	{
		return (*_calCtxSetMem)(ctx, name, mem);
	}

	CALresult CalDriver::calModuleLoad(CALmodule* module, CALcontext ctx, CALimage image)
	{
		return (*_calModuleLoad)(module, ctx, image);
	}

	CALresult CalDriver::calModuleUnload(CALcontext ctx, CALmodule module)
	{
		return (*_calModuleUnload)(ctx, module);
	}

	CALresult CalDriver::calModuleGetEntry(CALfunc* func, CALcontext ctx, CALmodule module, const CALchar* procName)
	{
		return (*_calModuleGetEntry)(func, ctx, module, procName);
	}

	CALresult CalDriver::calModuleGetName(CALname* name, CALcontext ctx, CALmodule module, const CALchar* varName)
	{
		return (*_calModuleGetName)(name, ctx, module, varName);
	}

	CALresult CalDriver::calResAllocLocal1D(CALresource* res, CALdevice dev, CALuint width, CALformat format, CALuint flags)
	{
		return (*_calResAllocLocal1D)(res, dev, width, format, flags);
	}

	CALresult CalDriver::calResFree(CALresource res)
	{
		return (*_calResFree)(res);
	}

	CALresult CalDriver::calResMap(CALvoid** pPtr, CALuint* pitch, CALresource res, CALuint flags)
	{
		return (*_calResMap)(pPtr, pitch, res, flags);
	}

	CALresult CalDriver::calResUnmap(CALresource res)
	{
		return (*_calResUnmap)(res);
	}

	CALresult CalDriver::calCtxRunProgramGrid(CALevent* event, CALcontext ctx, CALprogramGrid* pProgramGrid)
	{
		return (*_calCtxRunProgramGrid)(event, ctx, pProgramGrid);
	}

	CALresult CalDriver::calCtxIsEventDone(CALcontext ctx, CALevent event)
	{
		return (*_calCtxIsEventDone)(ctx, event);
	}

	CALresult CalDriver::calclCompile(CALobject* obj, CALlanguage language, const CALchar* source, CALtarget target)
	{
		return (*_calclCompile)(obj, language, source, target);
	}

	CALresult CalDriver::calclLink(CALimage* image, CALobject* obj, CALuint objCount)
	{
		return (*_calclLink)(image, obj, objCount);
	}

	CALresult CalDriver::calclFreeObject(CALobject obj)
	{
		return (*_calclFreeObject)(obj);
	}

	CALresult CalDriver::calclFreeImage(CALimage image)
	{
		return (*_calclFreeImage)(image);
	}

	const CALchar *CalDriver::calGetErrorString()
	{
		return (*_calGetErrorString)();
	}
}
