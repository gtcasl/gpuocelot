/*! \file ATIGPUDevice.cpp
 *  \author Rodrigo Dominguez <rdomingu@ece.neu.edu>
 *  \cate April 7, 2010
 *  \brief The source file for the ATI GPU Device class.
 */

#include <ocelot/executive/interface/ATIGPUDevice.h>

executive::ATIGPUDevice::ATIGPUDevice() 
{
	CALresult result;

	result = cal::CalDriver::Instance()->calDeviceOpen(&device, 0);
	result = cal::CalDriver::Instance()->calDeviceGetInfo(&info, 0);
}

executive::ATIGPUDevice::~ATIGPUDevice() 
{
	CALresult result;

	result = cal::CalDriver::Instance()->calDeviceClose(device);
}
