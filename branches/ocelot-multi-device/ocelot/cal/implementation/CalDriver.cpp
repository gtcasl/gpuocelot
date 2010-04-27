/*! \file CalDriver.cpp
 *  \author Rodrigo Dominguez <rdomingu@ece.neu.edu>
 *  \date April 8, 2010
 *  \brief The source file for the CalDriver class.
 */

// Ocelot includes
#include <ocelot/cal/interface/CalDriver.h>

// hydrazine includes
#include <hydrazine/interface/Casts.h>
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/debug.h>

// Linux system headers
#include <dlfcn.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

#define checkError(x) if(x != CAL_RESULT_OK) { \
	throw hydrazine::Exception(calGetErrorString()); }

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
		hydrazine::bit_cast(_calResAllocRemote1D,  dlsym(_driver, "calResAllocRemote1D"));
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

		checkError(calInit());
	}

	CalDriver::~CalDriver()
	{
		checkError(calShutdown());

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
		CALresult result;
		result = (*_calInit)();

		report("calInit()");

		return result;
	}

	CALresult CalDriver::calShutdown()
	{
		CALresult result;
		result = (*_calShutdown)();

		report("calShutdown()");

		return result;
	}

	CALresult CalDriver::calDeviceOpen(CALdevice *dev, CALuint ordinal)
	{
		CALresult result;
		result = (*_calDeviceOpen)(dev, ordinal);

		report("calDeviceOpen("
				<< "*dev = " << std::hex << std::showbase << *dev
				<< ", ordinal = " << std::dec << ordinal
				<< ")");

		return result;
	}

	CALresult CalDriver::calDeviceClose(CALdevice dev)
	{
		CALresult result;
		result = (*_calDeviceClose)(dev);

		report("calDeviceClose("
				<< "dev = " << std::hex << std::showbase << dev
				<< ")");

		return result;
	}

	CALresult CalDriver::calDeviceGetInfo(CALdeviceinfo *info, CALuint ordinal)
	{
		CALresult result;
		result = (*_calDeviceGetInfo)(info, ordinal);
		
		report("calDeviceGetInfo("
				<< "info = " << std::hex << std::showbase << info
				<< ", ordinal = " << std::dec << ordinal
				<< ")");

		return result;
	}

	CALresult CalDriver::calCtxCreate(CALcontext *ctx, CALdevice dev)
	{
		CALresult result;
		result = (*_calCtxCreate)(ctx, dev);
		
		report("calCtxCreate("
				<< "*ctx = " << std::hex << std::showbase << *ctx
				<< ", dev = " << std::hex << std::showbase << dev
				<< ")");

		return result;
	}

	CALresult CalDriver::calCtxDestroy(CALcontext ctx)
	{
		CALresult result;
		result = (*_calCtxDestroy)(ctx);
		
		report("calCtxDestroy("
				<< "ctx = " << std::hex << std::showbase << ctx
				<< ")");

		return result;
	}

	CALresult CalDriver::calCtxGetMem(CALmem *mem, CALcontext ctx, CALresource res)
	{
		CALresult result;
		result = (*_calCtxGetMem)(mem, ctx, res);

		report("calCtxGetMem("
				<< "*mem = " << std::hex << std::showbase << *mem
				<< ", ctx = " << std::hex << std::showbase << ctx
				<< ", res = " << std::hex << std::showbase << res
				<< ")");

		return result;
	}

	CALresult CalDriver::calCtxReleaseMem(CALcontext ctx, CALmem mem)
	{
		CALresult result;
		result = (*_calCtxReleaseMem)(ctx, mem);

		report("calCtxReleaseMem("
				<< "ctx = " << std::hex << std::showbase << ctx
				<< ", mem = " << std::hex << std::showbase << mem
				<< ")");

		return result;
	}

	CALresult CalDriver::calCtxSetMem(CALcontext ctx, CALname name, CALmem mem)
	{
		CALresult result;
		result = (*_calCtxSetMem)(ctx, name, mem);

		report("calCtxSetMem("
				<< "ctx = " << std::hex << std::showbase << ctx
				<< ", name = " << std::hex << std::showbase << name
				<< ", mem = " << std::hex << std::showbase << mem
				<< ")");

		return result;
	}

	CALresult CalDriver::calModuleLoad(CALmodule* module, CALcontext ctx, CALimage image)
	{
		CALresult result;
		result = (*_calModuleLoad)(module, ctx, image);

		report("calModuleLoad("
				<< "*module = " << std::hex << std::showbase << *module
				<< ", ctx = " << std::hex << std::showbase << ctx
				<< ", image = " << std::hex << std::showbase << image
				<< ")");

		return result;
	}

	CALresult CalDriver::calModuleUnload(CALcontext ctx, CALmodule module)
	{
		CALresult result;
		result = (*_calModuleUnload)(ctx, module);

		report("calModuleUnLoad("
				<< "ctx = " << std::hex << std::showbase << ctx
				<< ", module = " << std::hex << std::showbase << module
				<< ")");

		return result;
	}

	CALresult CalDriver::calModuleGetEntry(CALfunc* func, CALcontext ctx, CALmodule module, const CALchar* procName)
	{
		CALresult result;
		result = (*_calModuleGetEntry)(func, ctx, module, procName);

		report("calModuleGetEntry("
				<< "*func = " << std::hex << std::showbase << *func
				<< ", ctx = " << std::hex << std::showbase << ctx
				<< ", module = " << std::hex << std::showbase << module
				<< ", procName = " << procName
				<< ")");

		return result;
	}

	CALresult CalDriver::calModuleGetName(CALname* name, CALcontext ctx, CALmodule module, const CALchar* varName)
	{
		CALresult result;
		result = (*_calModuleGetName)(name, ctx, module, varName);

		report("calModuleGetName("
				<< "*name = " << std::hex << std::showbase << *name
				<< ", ctx = " << std::hex << std::showbase << ctx
				<< ", module = " << std::hex << std::showbase << module
				<< ", varName = " << varName
				<< ")");

		return result;
	}

	CALresult CalDriver::calResAllocLocal1D(CALresource* res, CALdevice dev, CALuint width, CALformat format, CALuint flags)
	{
		CALresult result;
		result = (*_calResAllocLocal1D)(res, dev, width, format, flags);

		report("calResAllocLocal1D("
				<< "*res = " << std::hex << std::showbase << *res
				<< ", dev = " << dev
				<< ", width = " << std::dec << width
				<< ", format = " << std::dec << format
				<< ", flags = " << std::dec << flags 
				<< ")");

		return result;
	}

	CALresult CalDriver::calResAllocRemote1D(CALresource* res, CALdevice* dev, CALuint deviceCount, CALuint width, CALformat format, CALuint flags)
	{
		CALresult result;
		result = (*_calResAllocRemote1D)(res, dev, deviceCount, width, format, flags);

		report("calResAllocRemote1D("
				<< "*res = " << std::hex << std::showbase << *res
				<< ", *dev = " << *dev
				<< ", deviceCount = " << std::dec << deviceCount
				<< ", width = " << std::dec << width
				<< ", format = " << std::dec << format
				<< ", flags = " << std::dec << flags 
				<< ")");

		return result;
	}

	CALresult CalDriver::calResFree(CALresource res)
	{
		CALresult result;
		result = (*_calResFree)(res);

		report("calResFree("
				<< "res = " << std::hex << std::showbase << res
				<< ")");

		return result;
	}

	CALresult CalDriver::calResMap(CALvoid** pPtr, CALuint* pitch, CALresource res, CALuint flags)
	{
		CALresult result;
		result = (*_calResMap)(pPtr, pitch, res, flags);

		report("calResMap("
				<< "*pPtr = " << std::hex << std::showbase << *pPtr
				<< ", *pitch = " << std::hex << std::showbase << *pitch
				<< ", res = " << std::hex << std::showbase << res
				<< ", flags = " << std::dec << flags
				<< ")");

		return result;
	}

	CALresult CalDriver::calResUnmap(CALresource res)
	{
		CALresult result;
		result = (*_calResUnmap)(res);

		report("calResUnmap("
				<< "res = " << std::hex << std::showbase << res
				<< ")");

		return result;
	}

	CALresult CalDriver::calCtxRunProgramGrid(CALevent* event, CALcontext ctx, CALprogramGrid* pProgramGrid)
	{
		CALresult result;
		result = (*_calCtxRunProgramGrid)(event, ctx, pProgramGrid);

		report("calCtxRunProgramGrid("
				<< "event = " << std::hex << std::showbase << event
				<< ", ctx = " << std::hex << std::showbase << ctx
				<< ", pProgramGrid = " << std::hex << std::showbase << pProgramGrid
				<< ")");

		return result;
	}

	CALresult CalDriver::calCtxIsEventDone(CALcontext ctx, CALevent event)
	{
		CALresult result;
		result = (*_calCtxIsEventDone)(ctx, event);

		report("calCtxIsEventDone("
				<< "ctx = " << std::hex << std::showbase << ctx
				<< ", event = " << std::hex << std::showbase << event
				<< ")");

		return result;
	}

	CALresult CalDriver::calclCompile(CALobject* obj, CALlanguage language, const CALchar* source, CALtarget target)
	{
		CALresult result;
		result = (*_calclCompile)(obj, language, source, target);

		report("calclCompile("
				<< "*obj = " << std::hex << std::showbase << *obj
				<< ", language = " << std::dec << language
				<< ", source = \"" << std::string(source).substr(0, 10) << "...\""
				<< ", target = " << std::dec << target
				<< ")");

		return result;
	}

	CALresult CalDriver::calclLink(CALimage* image, CALobject* obj, CALuint objCount)
	{
		CALresult result;
		result = (*_calclLink)(image, obj, objCount);

		report("calclLink("
				<< "*image = " << std::hex << std::showbase << *image
				<< ", *obj = " << std::hex << std::showbase << *obj
				<< ", objCount = " << std::dec << objCount
				<< ")");

		return result;
	}

	CALresult CalDriver::calclFreeObject(CALobject obj)
	{
		CALresult result;
		result = (*_calclFreeObject)(obj);

		report("calclFreeObject("
				<< "obj = " << std::hex << std::showbase << obj
				<< ")");

		return result;
	}

	CALresult CalDriver::calclFreeImage(CALimage image)
	{
		CALresult result;
		result = (*_calclFreeImage)(image);

		report("calclFreeImage("
				<< "image = " << std::hex << std::showbase << image
				<< ")");

		return result;
	}

	const CALchar *CalDriver::calGetErrorString()
	{
		const CALchar *result;
		result = (*_calGetErrorString)();

		report("calGetErrorString()");

		return result;
	}
}
