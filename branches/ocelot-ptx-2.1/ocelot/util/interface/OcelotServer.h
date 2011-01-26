/*!
	\file OcelotServer.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Jan 26, 2011
	\brief implements standalone version of Ocelot for remote devices
*/

#ifndef OCELOTSERVER_H_INCLUDED
#define OCELOTSERVER_H_INCLUDED

#include <fstream>

#include <ocelot/api/interface/ocelot.h>

namespace server {

	class OcelotServer {
	public:
		
	public:
		OcelotServer();
		~OcelotServer();
				
		//! \brief starts Ocelot in server mode
		void start();
	
	private:
	
		//! \biref loads configuration information
		bool configure();
		
		
	};

}

#endif

