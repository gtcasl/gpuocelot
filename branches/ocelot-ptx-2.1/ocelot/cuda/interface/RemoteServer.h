/*! \file   RemoteServer.h
	\date   Wednesday January 26, 2011
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief  The header file for the RemoteServer class.
*/

#ifndef REMOTE_SERVER_H_INCLUDED
#define REMOTE_SERVER_H_INCLUDED

// Forward Declarations
namespace executive { Device; }

namespace cuda
{

/*! \brief A class to manage local devices and */
class RemoteServer
{
public:
	/*! \brief A vector of created devices */
	typedef std::vector<executive::Device*> DeviceVector;

	/*! \brief The types of supported operations */
	enum RPCOpcode
	{
		
	};

public:
	/*! \brief The constructor creates the server object and initializes
		it from the Ocelot config file. */
	RemoteServer(unsigned int port, bool nvidia, bool ati,
		bool emulated, bool llvm, bool remote);

	/*! \brief Explicitly start the server, it will run forever */
	void start();

private:
	/*! \brief Reply back on the current connection */
	void _reply(const void* data, unsigned int bytes);

private:
	/*! \brief The port number to listen on */
	unsigned int _port;
	/*! \brief The set of local devices */
	DeviceVector _devices;
};

}

int main(int argc, char** argv);

#endif

