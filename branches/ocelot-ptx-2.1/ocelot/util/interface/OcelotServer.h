/*!
	\file OcelotServer.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Jan 26, 2011
	\brief implements standalone version of Ocelot for remote devices
*/

#ifndef OCELOTSERVER_H_INCLUDED
#define OCELOTSERVER_H_INCLUDED

// C++ includes
#include <fstream>
#include <algorithm>
#include <cstdlib>
#include <deque>
#include <list>
#include <set>

// Ocelot includes
#include <ocelot/api/interface/ocelot.h>
#include <ocelot/util/interface/OcelotServerConnection.h>

// Boost includes
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>

/////////////////////////////////////////////////////////////////////////////////////////////////

namespace remote {

	class OcelotServer {
	public:
		typedef std::list< OcelotServerConnection *> OcelotServerConnectionList;
	
		
	public:
		OcelotServer();
		~OcelotServer();
				
		//! \brief starts Ocelot in server mode
		void start();
		
	public:
	
		int port;
			
	private:
	
		//! \brief
		OcelotServerConnectionList _connections;

	};

}

/////////////////////////////////////////////////////////////////////////////////////////////////

#endif

