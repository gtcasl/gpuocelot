/*!

*/

#ifndef REMOTEDEVICEMESSAGE_H_INCLUDED
#ifndef REMOTEDEVICEMESSAGE_H_INCLUDED

#include <vector>

namespace remote {

	class RemoteDeviceMessage {
	public:
		typedef std::vector<char> ByteVector;
		typedef unsigned int DeviceId;
		
		//!
		enum Operation {
			Memory_allocate,
			Memory_allocateHost,
			Memory_free,
			
			Device_clearMemory,
			Device_load,
			Device_unload,
			Device_getKernel,
			Device_properties,
			Device_createEvent,
			Device_queryEvent,
			Device_recordEvent,
			Device_synchronizeEvent,
			Device_getEventTime,
			Device_createStream,
			Device_destroyStream,
			Device_queryStream,
			Device_synchronizeStream,
			Device_setStream,
			Device_bindTexture,
			Device_unbindTexture,
			Device_getTextureReference,
			Device_driverVersion,
			Device_runtimeVersion,
			Device_launch,
			Device_getAttributes,
			Device_getLastError,
			Device_synchronize,
			Device_limitWorkerThreads,
			Device_setOptimizationLevel,

			Server_enumerateDevices,

		};
	
	public:
		RemoteDeviceMessage();
		~RemoteDeviceMessage();
		
		//! \brief selects memory operation
		Operation operation;
				
		//! unique identifier of bound device
		DeviceId deviceId;
		
		//! \brief size in bytes of message payload
		size_t messageSize;
		
		//! \brief pointer to message payload
		char *message;
	};
}

#endif

