/*!
	\file OcelotServerConnection.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Jan 26, 2011
	\brief connection class for Ocelot server
*/

#ifndef OCELOTSERVERCONNECTION_H_INCLUDED
#define OCELOTSERVERCONNECTION_H_INCLUDED

// C++ includes
#include <string>

// Ocelot includes
#include <ocelot/executive/interface/Device.h>
#include <ocelot/util/interface/RemoteDeviceMessage.h>

// Boost includes
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>

namespace remote {

//	namespace boost_tcp = boost::asio::ip::tcp;

	typedef executive::DeviceVector DeviceVector;

	class OcelotServerConnection {
	public:
		OcelotServerConnection(boost::asio::ip::tcp::socket &socket);
		virtual ~OcelotServerConnection();
		
		//! \brief 
		void start();
		
		void operator()();
		
	private:
	
		//! \brief enumerates enabled devices
		void _enumerateDevices();
		
		//! \brief 
		void _handleMessage(RemoteDeviceMessage &message);
		
	private:
		
		//! \brief indicates whether devices have been loaded
		bool _devicesLoaded;
	
		//! \brief list of all devices
		DeviceVector _devices;
		
		//! \brief connection to client
		boost::asio::ip::tcp::socket &_socket;
	};

}

#endif

