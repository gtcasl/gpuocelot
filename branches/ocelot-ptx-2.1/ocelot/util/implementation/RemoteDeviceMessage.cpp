/*!
	\file RemoteDeviceMessage.h
	\author Andrew Kerr <arkerr@gatech.edu>, Gregory Diamos <gregory.diamos@gatech.edu>
	\date 26 Jan 2011
	\brief serialized message object for executive::Device interface
*/

// C++ includes
#include <iostream>

// Ocelot includes
#include <ocelot/util/interface/RemoteDeviceMessage.h>

// Boost includes

// Hydrazine includes
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/string.h>
#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

// whether debugging messages are printed
#define REPORT_BASE 0

/////////////////////////////////////////////////////////////////////////////////////////////////

std::string remote::RemoteDeviceMessage::toString(const Operation &op) {
	switch (op) {
	case Memory_allocate: return "Memory_allocate";
		case Memory_allocateHost: return "Memory_allocateHost";
		case Memory_free: return "Memory_free";
		case Device_clearMemory: return "Device_clearMemory";
		case Device_load: return "Device_load";
		case Device_unload: return "Device_unload";
		case Device_getKernel: return "Device_getKernel";
		case Device_properties: return "Device_properties";
		case Device_createEvent: return "Device_createEvent";
		case Device_queryEvent: return "Device_queryEvent";
		case Device_recordEvent: return "Device_recordEvent";
		case Device_synchronizeEvent: return "Device_synchronizeEvent";
		case Device_getEventTime: return "Device_getEventTime";
		case Device_createStream: return "Device_createStream";
		case Device_destroyStream: return "Device_destroyStream";
		case Device_queryStream: return "Device_queryStream";
		case Device_synchronizeStream: return "Device_synchronizeStream";
		case Device_setStream: return "Device_setStream";
		case Device_bindTexture: return "Device_bindTexture";
		case Device_unbindTexture: return "Device_unbindTexture";
		case Device_getTextureReference: return "Device_getTextureReference";
		case Device_driverVersion: return "Device_driverVersion";
		case Device_runtimeVersion: return "Device_runtimeVersion";
		case Device_launch: return "Device_launch";
		case Device_getAttributes: return "Device_getAttributes";
		case Device_getLastError: return "Device_getLastError";
		case Device_synchronize: return "Device_synchronize";
		case Device_limitWorkerThreads: return "Device_limitWorkerThreads";
		case Device_setOptimizationLevel: return "Device_setOptimizationLevel";
		case Server_enumerateDevices: return "Server_enumerateDevices";
		
		case Client_acknowledge: return "Client_acknowledge";
		case Client_ping: return "Client_ping";
		case Operation_invalid: return "Operation_invalid";
	}
	return "Operation unknown";
}

/////////////////////////////////////////////////////////////////////////////////////////////////

static std::ostream &operator<<(std::ostream &out, remote::RemoteDeviceMessage::Header header) {
	out << "{ operation: " << remote::RemoteDeviceMessage::toString(header.operation) 
		<< ", deviceId: " << header.deviceId << ", messageSize: " << header.messageSize << " }";
	return out;
}

remote::RemoteDeviceMessage::RemoteDeviceMessage() {
	header.operation = Operation_invalid;
}

remote::RemoteDeviceMessage::~RemoteDeviceMessage() {

}

/*! \brief sends this message on the indicated socket
	\return false if connection disconnected */
bool remote::RemoteDeviceMessage::send(boost::asio::ip::tcp::socket &socket) {
	report("OcelotServerConnection::send() - " << header);
	try {
		boost::system::error_code error;
		
		size_t len = socket.send( boost::asio::buffer((char *)&header, sizeof(header)), 0, error);
		if (error == boost::asio::error::eof) {
		  return false; // Connection closed cleanly by peer.
		}
		else if (error) {
			report(" failed to read header");
		  throw boost::system::system_error(error); // Some other error.
		}
		assert(len == sizeof(header));
		
		len = socket.send( boost::asio::buffer(message), 0, error);
		if (error == boost::asio::error::eof) {
		  return false; // Connection closed cleanly by peer.
		}
		else if (error) {
			report(" failed to read header");
		  throw boost::system::system_error(error); // Some other error.
		}
	}
	catch (std::exception &exp) {
		std::cerr << "RemoteDeviceMessage::send() - " << exp.what() << std::endl;
	}
	return true;
}

/*! \brief receives this message on indicated socket
	\return false if connection disconnected */
bool remote::RemoteDeviceMessage::receive(boost::asio::ip::tcp::socket &socket) {
	report("OcelotServerConnection::receive()");
	
	try {
		boost::array<char, sizeof(RemoteDeviceMessage::Header)> headerBuffer;
		boost::system::error_code error;

		size_t len = socket.read_some(boost::asio::buffer(headerBuffer), error);
		if (error == boost::asio::error::eof) {
		  return false; // Connection closed cleanly by peer.
		}
		else if (error) {
			report(" failed to read header");
		  throw boost::system::system_error(error); // Some other error.
		}
		std::memcpy(&header, headerBuffer.data(), len);
		
		report("  header: " << header);
		
		resize();
		len = socket.read_some(boost::asio::buffer(message), error);
		if (error == boost::asio::error::eof) {
			if (len != message.size()) {
				return false;
			}
		}
		else if (error) {
			report(" failed to read payload");
		  throw boost::system::system_error(error); // Some other error.
		}
	}
	catch (std::exception &exp) {
		std::cerr << "RemoteDeviceMessage::receive() - " << exp.what() << std::endl;
		return false;
	}
	
	report("Received message: " << RemoteDeviceMessage::toString(header.operation) 
		<< " [device " << header.deviceId << "]");
	
	return true;
}

/////////////////////////////////////////////////////////////////////////////////////////////////

