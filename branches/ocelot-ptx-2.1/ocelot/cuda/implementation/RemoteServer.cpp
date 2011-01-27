/*! \file   RemoteServer.cpp
	\date   Wednesday January 26, 2011
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief  The header file for the RemoteServer class.
*/

#ifndef REMOTE_SERVER_CPP_INCLUDED
#define REMOTE_SERVER_CPP_INCLUDED

// Ocelot Includes
#include <ocelot/cuda/interface/RemoteServer.h>

// Hydrazine Includes
#include <hydrazine/implementation/ArgumentParser.h>

namespace cuda
{

RemoteServer::RemoteServer(unsigned int port, bool nvidia, bool ati,
	bool emulated, bool llvm, bool remote)
{
	devices = createDevices(nvidia, ati, emulated, llvm, remote);
}

void RemoteServer::start()
{
	
}

void RemoteServer::_reply(const void* data, unsigned int bytes)
{
	assertM(false, "Not implemented.");
}

}

int main(int argc, char** argv)
{
	unsigned int port = 0;
	bool noNvidia   = false;
	bool noATI      = false;
	bool noEmulated = false;
	bool noLLVM     = false;
	bool noRemote   = false;


	hydrazine::ArgumentParser parser(argc, argv);

	parser.parse("-p", "--port", port, 7777, "The port number to listen on.");
	parser.parse("-n", "--no-nvidia",   noNvidia, false,
		"Do not expose nvidia devices.");
	parser.parse("-a", "--no-ati",      noATI, false,
		"Do not expose ati devices.");
	parser.parse("-e", "--no-emulated", noEmulated, false,
		"Do not expose emulated devices.");
	parser.parse("-l", "--no-llvm",     noLLVM, false,
		"Do not expose llvm devices.");
	parser.parse("-r", "--no-remote",   noRemote, false,
		"Do not expose remote devices.");
	
	parser.parse();

	RemoteServer server(port, !noNvidia, !noATI,
		!noEmulated, !noLLVM, !noRemote);
	
	server.start();

	return 0;
}

#endif

