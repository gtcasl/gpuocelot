/*! \file ATIGPUDevice.cpp
 *  \author Rodrigo Dominguez <rdomingu@ece.neu.edu>
 *  \cate April 7, 2010
 *  \brief The source file for the ATI GPU Device class.
 */

#include <ocelot/executive/interface/ATIGPUDevice.h>

namespace executive
{
    ATIGPUDevice::ATIGPUDevice() 
		: device(0), 
		  context(0), 
		  object(0), 
		  image(0), 
		  module(0)  
    {
        CALresult result;

        result = cal::CalDriver::Instance()->calDeviceOpen(&device, 0);
        result = cal::CalDriver::Instance()->calDeviceGetInfo(&info, 0);

        // multiple contexts per device is not supported yet
        // only one context per device so we can create it in the constructor
        result = cal::CalDriver::Instance()->calCtxCreate(&context, device);
    }

    ATIGPUDevice::~ATIGPUDevice() 
    {
        CALresult result;

        result = cal::CalDriver::Instance()->calCtxDestroy(context);
        result = cal::CalDriver::Instance()->calDeviceClose(device);
    }

    void ATIGPUDevice::load(const ir::Module *irModule)
    {
		// Use a fixed ILKernel for now (no PTX-to-IL translation yet)
		const cal::Char *ILKernel = 
			"il_cs_2_0\n"
			"dcl_num_thread_per_group 10\n"
			"dcl_raw_uav_id(0)\n"
			"dcl_raw_uav_id(1)\n"
			"dcl_literal l0, 4, 4, 4, 4\n"
			"dcl_literal l1, 2, 2, 2, 2\n"
			"mov r0.x, vAbsTidFlat.x\n"
			"ishl r0.x, r0.x, l0.x\n"
			"uav_raw_load_id(0) r1, r0.x\n"
			"imul r1, r1, l1\n"
			"uav_raw_store_id(1) mem.xyzw, r0.x, r1\n"
			"end\n";

		CALresult result;

		result = cal::CalDriver::Instance()->calclCompile(&object, CAL_LANGUAGE_IL, ILKernel, info.target);
		result = cal::CalDriver::Instance()->calclLink(&image, &object, 1);
		result = cal::CalDriver::Instance()->calModuleLoad(&module, context, image);
    }

    void ATIGPUDevice::unload(const std::string& name)
    {
		CALresult result;

		result = cal::CalDriver::Instance()->calModuleUnload(context, module);
		result = cal::CalDriver::Instance()->calclFreeImage(image);
		result = cal::CalDriver::Instance()->calclFreeObject(object);
    }

    void ATIGPUDevice::select()
    {
        // multiple devices is not supported yet
    }

    bool ATIGPUDevice::selected() const
    {
        // multiple devices is not supported yet
        return true;
    }

    void ATIGPUDevice::unselect()
    {
        // multiple devices is not supported yet
    }
}
