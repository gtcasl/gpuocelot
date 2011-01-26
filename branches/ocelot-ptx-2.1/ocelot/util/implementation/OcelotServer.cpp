/*!
	\file OcelotServer.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Jan 26, 2011
	\brief implements standalone version of Ocelot for remote devices
*/


#include <ocelot/api/interface/ocelot.h>
#include <ocelot/util/interface/OcelotServer.h>

#include <hydrazine/implementation/ArgumentParser.h>

/////////////////////////////////////////////////////////////////////////////////////////////////

server::OcelotServer::OcelotServer() {

}

server::OcelotServer::~OcelotServer() {

}
//! \brief starts Ocelot in server mode
void server::OcelotServer::start() {

}

/////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *arg[]) {
	server::OcelotServer ocelotServer;
	
	hydrazine::ArgumentParser parser(argc, argv);
	
	std::string configurationFile;
	bool displayHelp;

	parser.parse("-c", "--configuration", configurationFile, "configure.ocelot", "Name of server configuration file.");
	parser.parse("-h", "--help", displayHelp, false, "Displays this message");
	parser.parse("-p", "--port", ocelotServer.port, 2011, "Listening port");
	
	parser.parse();

	if (displayHelp) {
		std::cout << parser.help() << std::endl;
		return 0;
	}
	
	if (ocelotServer.configure()) {
		ocelotServer.start();
	}
	
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////

