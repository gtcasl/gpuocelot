/*! \file WindowsCompatibility.h
	\date Monday August 2, 2010
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The header file for hacked code required to assist windows 
		compilaiton
*/

#ifndef WINDOWS_COMPATIBILITY_CPP_INCLUDED
#define WINDOWS_COMPATIBILITY_CPP_INCLUDED

// Hydrazine includes
#include <hydrazine/interface/WindowsCompatibility.h>

#ifndef WIN32
#include <unistd.h> 
#include <sys/sysinfo.h>
#else
#include <windows.h>
#endif

namespace hydrazine
{
	unsigned int getHardwareThreadCount()
	{
	#ifdef WIN32
		SYSTEM_INFO sysinfo;
		GetSystemInfo( &sysinfo );

		return sysinfo.dwNumberOfProcessors;
	#else
		return sysconf(_SC_NPROCESSORS_ONLN);
	#endif
	}
}

#endif
