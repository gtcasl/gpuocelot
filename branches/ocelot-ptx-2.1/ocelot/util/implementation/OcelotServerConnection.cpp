/*!
	\file OcelotServerConnection.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\date Jan 26, 2011
	\brief connection class for Ocelot server
*/

// C++ includes
#include <iostream>


// Ocelot includes
#include <ocelot/util/interface/OcelotServerConnection.h>
#include <ocelot/api/interface/ocelot.h>
#include <ocelot/api/interface/OcelotConfiguration.h>
#include <ocelot/ir/interface/PTXInstruction.h>
#include <ocelot/executive/interface/RuntimeException.h>

// Hydrazine includes
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/string.h>
#include <hydrazine/implementation/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

////////////////////////////////////////////////////////////////////////////////

// whether CUDA runtime catches exceptions thrown by Ocelot
#define CATCH_RUNTIME_EXCEPTIONS 0

// whether verbose error messages are printed
#define CUDA_VERBOSE 0

// whether debugging messages are printed
#define REPORT_BASE 0

// report all ptx modules
#define REPORT_ALL_PTX 0

/////////////////////////////////////////////////////////////////////////////////////////////////

typedef api::OcelotConfiguration config;

remote::OcelotServerConnection::OcelotServerConnection(boost::asio::ip::tcp::socket &socket)
:
	_devicesLoaded(false),
	_socket(socket)
{
	report("OcelotServerConnection()");
	start();
}

remote::OcelotServerConnection::~OcelotServerConnection() {
	//
	// free things that need freeing
	//
	// devices
	for (DeviceVector::iterator device = _devices.begin(); 
		device != _devices.end(); ++device) {
		delete *device;
	}
	
	// mutex

	// thread contexts
	
	// textures
	
	// kernels
	
	// fat binaries
	
	// config
	config::destroy();
}

void remote::OcelotServerConnection::operator()() {
	start();
}

//! \brief 
void remote::OcelotServerConnection::start() {

	report("OcelotServerConnection::start()");
	
	_enumerateDevices();

	RemoteDeviceMessage message;
	bool running = true;
	while (running) {
		// clear message
		message.clear();
		
		// receive		
		running = message.receive(_socket);
		
		// dispatch
		_handleMessage(message);
	}
}

//! \brief 
void remote::OcelotServerConnection::_handleMessage(RemoteDeviceMessage &message) {
	report("OcelotServerConnection::_handleMessage() - message = " << 
		RemoteDeviceMessage::toString(message.header.operation));
		
	if (message.header.operation == RemoteDeviceMessage::Client_ping) {
		// return with data inverted
		if (message.size() >= 4) {
			*((int *)&message.message[0]) = ~(*((int *)&message.message[0]));
			message.send(_socket);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////


//! 
void remote::OcelotServerConnection::_enumerateDevices() {

	report("Creating devices.");
	
	if(_devicesLoaded) return;
	
	int _flags = 0;
	int _computeCapability = 2;
	
	if(config::get().executive.enableNVIDIA) {
		executive::DeviceVector d = 
			executive::Device::createDevices(ir::Instruction::SASS, _flags,
				_computeCapability);
		report(" - Added " << d.size() << " nvidia gpu devices." );
		_devices.insert(_devices.end(), d.begin(), d.end());
	}
	if(config::get().executive.enableEmulated) {
		executive::DeviceVector d = 
			executive::Device::createDevices(ir::Instruction::Emulated, _flags,
				_computeCapability);
		report(" - Added " << d.size() << " emulator devices." );
		_devices.insert(_devices.end(), d.begin(), d.end());
	}
	if(config::get().executive.enableLLVM) {
		executive::DeviceVector d = 
			executive::Device::createDevices(ir::Instruction::LLVM, _flags,
				_computeCapability);
		report(" - Added " << d.size() << " llvm-cpu devices." );
		_devices.insert(_devices.end(), d.begin(), d.end());
		
		if (config::get().executive.workerThreadLimit > 0) {
			for (executive::DeviceVector::iterator d_it = d.begin();
				d_it != d.end(); ++d_it) {
				(*d_it)->limitWorkerThreads(
					config::get().executive.workerThreadLimit);
			}
		}
	}
	if(config::get().executive.enableAMD) {
		executive::DeviceVector d =
			executive::Device::createDevices(ir::Instruction::CAL, _flags,
				_computeCapability);
		report(" - Added " << d.size() << " amd gpu devices." );
		_devices.insert(_devices.end(), d.begin(), d.end());
	}
	
	// Remote devices
	{
	
	}

	// done enumerating	
	_devicesLoaded = true;
	
	if(_devices.empty())
	{
		std::cerr << "==Ocelot== WARNING - No CUDA devices found or all " 
			<< "devices disabled!\n";
		std::cerr << "==Ocelot==  Consider enabling the emulator in " 
			<< "configure.ocelot.\n";
	}
}
/////////////////////////////////////////////////////////////////////////////////////////////////

