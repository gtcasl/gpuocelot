/*! \file ATIGPUDevice.h
 *  \author Rodrigo Dominguez <rdomingu@ece.neu.edu>
 *  \date April 7, 2010
 *  \brief The header file for the ATI GPU Device class.
 */

#ifndef ATIGPUDEVICE_H_INCLUDED
#define ATIGPUDEVICE_H_INCLUDED

// Ocelot includes
#include <ocelot/executive/interface/Device.h>
#include <ocelot/cal/interface/CalDriver.h>

namespace executive
{
	/*! \brief ATI GPU Device */
	class ATIGPUDevice : public Device 
	{
		public:
			/*! \brief Constructor */
			ATIGPUDevice();
			/*! \brief Destructor */
			~ATIGPUDevice();

		private:
			/*! \brief CAL Device */
			CALdevice device;
			/*! \brief CAL Device Info */
			CALdeviceinfo info;
	};
}

#endif
