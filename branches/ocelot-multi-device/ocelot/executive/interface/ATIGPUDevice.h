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
			/*! \brief ATI memory allocation */
			class MemoryAllocation : public Device::MemoryAllocation
			{
				public:
					/*! \brief Constructor */
					MemoryAllocation(CALdevice device, size_t size);
					/*! \brief Destructor */
					~MemoryAllocation();

					/*! \brief Get the flags if this is a host pointer */
					unsigned int flags() const;
					/*! \brief Get a host pointer if for a host allocation */
					void* mappedPointer() const;
					/*! \brief Get a device pointer to the base */
					void* pointer() const;
					/*! \brief The size of the allocation */
					size_t size() const;
					/*! \brief Copy from an external host pointer */
					void copy(size_t offset, const void* host, size_t size );
					/*! \brief Copy to an external host pointer */
					void copy(void* host, size_t offset, size_t size) const;
					/*! \brief Memset the allocation */
					void memset(size_t offset, int value, size_t size);
					/*! \brief Copy to another allocation */
					void copy(Device::MemoryAllocation* allocation, 
						size_t toOffset, size_t fromOffset, size_t size) const;

				private:
					/*! \brief CAL allocation */
					CALresource _resource;
					/*! \brief Size of the allocation (in byte) */
					size_t _size;
			};

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
			
			/*! \brief Get the allocation containing a pointer or 0 */
			MemoryAllocation* getMemoryAllocation(const void* address, 
				bool hostAllocation) const;
			/*! \brief Allocate some new dynamic memory on this device */
			MemoryAllocation* allocate(size_t size);
			/*! \brief Free an existing non-global allocation */
			void free(void* pointer);

		private:
			/*! \brief A map of memory allocations */
			typedef std::map<void*, MemoryAllocation*> AllocationMap;

			/*! \brief A map of memory allocations in device space */
			AllocationMap _allocations;

			/*! \brief CAL Device */
			CALdevice _device;
			/*! \brief CAL Device Info */
			CALdeviceinfo _info;
			/*! \brief CAL Context. Multiple contexts per device is not supported yet */
			CALcontext _context;
			/*! \brief CAL Object */
			CALobject _object;
			/*! \brief CAL Image */
			CALimage _image;
			/*! \brief CAL Module */
			CALmodule _module;
	};
}

#endif
