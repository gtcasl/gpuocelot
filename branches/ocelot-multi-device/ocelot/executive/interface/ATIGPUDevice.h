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

			/*! \brief Load a module, must have a unique name */
			void load(const ir::Module* irModule);
			/*! \brief Unload a module by name */
			void unload(const std::string& name);

			/*! \brief Select this device as the current device.
			 *  Only one device is allowed to be selected at any time. */
			void select();
			/*! \brief Is this device selected? */
			bool selected() const;
			/*! \brief Deselect this device */
			void unselect();

		private:
			/*! \brief CAL Device */
			cal::Device device;
			/*! \brief CAL Device Info */
			cal::DeviceInfo info;
            /*! \brief CAL Context. Multiple contexts per device is not supported yet */
			cal::Context context;
			/*! \brief CAL Object */
			cal::Object object;
			/*! \brief CAL Image */
			cal::Image image;
			/*! \brief CAL Module */
			cal::Module module;
	};
}

#endif
