/*! \file CalDriver.h
 *  \author Rodrigo Dominguez <rdomingu@ece.neu.edu>
 *  \date April 8, 2010
 *  \brief The header file for the CalDriver class
 */

#ifndef CAL_DRIVER_H_INCLUDED
#define CAL_DRIVER_H_INCLUDED

// CAL includes
#include <ocelot/cal/include/cal.h>
#include <ocelot/cal/include/calcl.h>

namespace cal
{
	/*! \brief Provides access to the CAL runtime/driver
	 *
	 * Implemented as a Singleton. It is non-thread-safe for now (is CAL
	 * thread-safe?)
	 */
	class CalDriver
	{
		public:
			/*! \brief Singleton instance getter */
			static CalDriver *Instance();

			/*****************************//**
			 * \name Initialization
			 ********************************/
			//@{
			CALresult calInit();
			CALresult calShutdown();
			//@}

			/*****************************//**
			 * \name Device Management
			 ********************************/
			//@{
			CALresult calDeviceOpen(CALdevice *dev, CALuint ordinal);
			CALresult calDeviceClose(CALdevice dev);
			CALresult calDeviceGetInfo(CALdeviceinfo *info, CALuint ordinal);
			//@}

			/*****************************//**
			 * \name Context Management
			 ********************************/
			//@{
			CALresult calCtxCreate(CALcontext *ctx, CALdevice dev);
			CALresult calCtxDestroy(CALcontext ctx);
			CALresult calCtxGetMem(CALmem *mem, CALcontext ctx, CALresource res);
			CALresult calCtxReleaseMem(CALcontext ctx, CALmem mem);
			CALresult calCtxSetMem(CALcontext ctx, CALname name, CALmem mem);
			//@}

			/*****************************//**
			 * \name Module Management
			 ********************************/
			//@{
			CALresult calModuleLoad(CALmodule* module, CALcontext ctx, CALimage image);
			CALresult calModuleUnload(CALcontext ctx, CALmodule module);
			CALresult calModuleGetEntry(CALfunc* func, CALcontext ctx, CALmodule module, const CALchar* procName);
			CALresult calModuleGetName(CALname* name, CALcontext ctx, CALmodule module, const CALchar* varName);
			//@}

			/*****************************//**
			 * \name Memory Management
			 ********************************/
			//@{
			CALresult calResAllocLocal1D(CALresource* res, CALdevice dev, CALuint width, CALformat format, CALuint flags);
			CALresult calResAllocRemote1D(CALresource* res, CALdevice* dev, CALuint deviceCount, CALuint width, CALformat format, CALuint flags);
			CALresult calResFree(CALresource res);
			CALresult calResMap(CALvoid** pPtr, CALuint* pitch, CALresource res, CALuint flags);
			CALresult calResUnmap(CALresource res);
			//@}

			/*****************************//**
			 * \name Execution Management
			 ********************************/
			//@{
			CALresult calCtxRunProgramGrid(CALevent* event, CALcontext ctx, CALprogramGrid* pProgramGrid);
			CALresult calCtxIsEventDone(CALcontext ctx, CALevent event);
			//@}

			/*****************************//**
			 * \name Compiler Interface
			 ********************************/
			//@{
			CALresult calclCompile(CALobject* obj, CALlanguage language, const CALchar* source, CALtarget target);
			CALresult calclLink(CALimage* image, CALobject* obj, CALuint objCount);
			CALresult calclFreeObject(CALobject obj);
			CALresult calclFreeImage(CALimage image);
			//@}

			/*****************************//**
			 * \name Error Reporting
			 ********************************/
			//@{
			const CALchar *calGetErrorString();
			//@}
		
		private:
			/*! \brief Singleton instance */
			static CalDriver *_instance;
			/*! \brief Runtime/Driver library (libaticalrt.so) handle */
            void *_driver;
			/*! \brief Compiler library (libaticalcl.so) handle */
            void *_compiler;

			/*****************************//**
			 * \name CAL function pointers
			 ********************************/
			//@{
			CALresult (*_calInit)();
			CALresult (*_calShutdown)();
			CALresult (*_calDeviceOpen)(CALdevice *dev, CALuint ordinal);
			CALresult (*_calDeviceClose)(CALdevice dev);
			CALresult (*_calDeviceGetInfo)(CALdeviceinfo *info, CALuint ordinal);
			CALresult (*_calCtxCreate)(CALcontext *ctx, CALdevice dev);
			CALresult (*_calCtxDestroy)(CALcontext ctx);
			CALresult (*_calCtxGetMem)(CALmem *mem, CALcontext ctx, CALresource res);
			CALresult (*_calCtxReleaseMem)(CALcontext ctx, CALmem mem);
			CALresult (*_calCtxSetMem)(CALcontext ctx, CALname name, CALmem mem);
			CALresult (*_calModuleLoad)(CALmodule* module, CALcontext ctx, CALimage image);
			CALresult (*_calModuleUnload)(CALcontext ctx, CALmodule module);
			CALresult (*_calModuleGetEntry)(CALfunc* func, CALcontext ctx, CALmodule module, const CALchar* procName);
			CALresult (*_calModuleGetName)(CALname* name, CALcontext ctx, CALmodule module, const CALchar* varName);
			CALresult (*_calResAllocLocal1D)(CALresource* res, CALdevice dev, CALuint width, CALformat format, CALuint flags);
			CALresult (*_calResAllocRemote1D)(CALresource* res, CALdevice* dev, CALuint deviceCount, CALuint width, CALformat format, CALuint flags);
			CALresult (*_calResFree)(CALresource res);
			CALresult (*_calResMap)(CALvoid** pPtr, CALuint* pitch, CALresource res, CALuint flags);
			CALresult (*_calResUnmap)(CALresource res);
			CALresult (*_calCtxRunProgramGrid)(CALevent* event, CALcontext ctx, CALprogramGrid* pProgramGrid);
			CALresult (*_calCtxIsEventDone)(CALcontext ctx, CALevent event);
			CALresult (*_calclCompile)(CALobject* obj, CALlanguage language, const CALchar* source, CALtarget target);
			CALresult (*_calclLink)(CALimage* image, CALobject* obj, CALuint objCount);
			CALresult (*_calclFreeObject)(CALobject obj);
			CALresult (*_calclFreeImage)(CALimage image);
			const CALchar *(*_calGetErrorString)();
			//@}

			/*! \brief Constructor */
			CalDriver();
			/*! \brief Destructor */
			~CalDriver();
	};
}

#endif
