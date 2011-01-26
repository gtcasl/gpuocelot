/*!
	\file RemoteDeviceMessage.h
	\author Andrew Kerr <arkerr@gatech.edu>, Gregory Diamos <gregory.diamos@gatech.edu>
	\date 26 Jan 2011
	\brief serialized message object for executive::Device interface
*/

#ifndef REMOTEDEVICEMESSAGE_H_INCLUDED
#define REMOTEDEVICEMESSAGE_H_INCLUDED

// C++ includes
#include <vector>
#include <string>

// Boost includes
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>

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
			
			Client_acknowledge,
			Client_ping,

			Operation_invalid
		};
		
		class Header {
		public:
		
			//! \brief selects memory operation
			Operation operation;
				
			//! unique identifier of bound device
			DeviceId deviceId;
		
			//! \brief size of message
			unsigned int messageSize;
		};
	
	public:
		RemoteDeviceMessage();
		~RemoteDeviceMessage();
		
		static std::string toString(const Operation &op);
		
		void clear() { message.clear(); }
		
		void resize() { message.resize(header.messageSize, 0); }
		
		char *data() { return &message[0]; }
		
		int size() { return header.messageSize; }
		
		/*! \brief sends this message on the indicated socket
			\return false if connection disconnected */
		bool send(boost::asio::ip::tcp::socket &socket);
		
		/*! \brief receives this message on indicated socket
			\return false if connection disconnected */
		bool receive(boost::asio::ip::tcp::socket &socket);
		
	public:
		//! \brief message header
		Header header;
		
		//! \brief pointer to message payload
		ByteVector message;
	};
}

#endif

