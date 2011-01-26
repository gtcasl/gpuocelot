/*!
	\file OcelotServer.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Jan 26, 2011
	\brief implements standalone version of Ocelot for remote devices
*/


#include <ocelot/api/interface/ocelot.h>
#include <ocelot/util/interface/OcelotServer.h>

// Boost includes
#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>


// hydrazine includes
#include <hydrazine/implementation/ArgumentParser.h>

/////////////////////////////////////////////////////////////////////////////////////////////////

remote::OcelotServer::OcelotServer() {

}

remote::OcelotServer::~OcelotServer() {

}
//! \brief starts Ocelot in server mode
void remote::OcelotServer::start() {
	std::cout << "OcelotServer::start()" << std::endl;
	
	try {
		boost::asio::io_service io_service;
		boost::asio::ip::tcp::acceptor acceptor(io_service, boost::asio::ip::tcp::endpoint(boost::asio::ip::tcp::v4(), port));

		while (true) {
			boost::asio::ip::tcp::socket socket(io_service);
			acceptor.accept(socket);
			
			// construct connection thread and push into list of connections
			OcelotServerConnection newConnection(socket);
			
			// right now, single threaded
		}

		io_service.run();
	}
	catch (std::exception& e) {
		std::cerr << "OcelotServer error:\n" << e.what() << std::endl;	
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////

int main(int argc, char *argv[]) {
	remote::OcelotServer ocelotServer;
	
	hydrazine::ArgumentParser parser(argc, argv);
	
	std::string configurationFile;
	bool displayHelp;
	int port;

	parser.parse("-c", "--configuration", configurationFile, "configure.ocelot", "Name of server configuration file.");
	parser.parse("-h", "--help", displayHelp, false, "Displays this message");
	parser.parse("-p", "--port", ocelotServer.port, 2011, "Listening port");
	
	parser.parse();

	if (displayHelp) {
		std::cout << parser.help() << std::endl;
		return 0;
	}
	
	ocelotServer.start();
	
	return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////

