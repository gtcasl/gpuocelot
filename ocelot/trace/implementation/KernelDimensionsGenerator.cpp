/*!
	\file KernelDimensionsGenerator.cpp
	\author Gregory Diamos
	\date Monday April 13, 2009
	\brief The source file for the KernelDimensionsGenerator class
*/

// C++ stdlib includes
#include <fstream>

// Ocelot includes
#include <ocelot/trace/interface/KernelDimensionsGenerator.h>
#include <ocelot/trace/interface/TraceEvent.h>
#include <ocelot/executive/interface/EmulatedKernel.h>
#include <ocelot/ir/interface/Module.h>

// Hydrazine includes
#include <hydrazine/implementation/Exception.h>

// Boost includes
#include <boost/filesystem.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

namespace trace
{
		
	unsigned int KernelDimensionsGenerator::KernelDimensionsGenerator::_counter = 0;

	KernelDimensionsGenerator::KernelDimensionsGenerator()
	{
	}
	
	KernelDimensionsGenerator::~KernelDimensionsGenerator()
	{
		
	}

	void KernelDimensionsGenerator::initialize(const ir::ExecutableKernel& kernel)
	
	{
		_entry.name = kernel.name;
		_entry.module = kernel.module->modulePath;
		_entry.format = KernelDimensionsFormat;

		std::string name = kernel.name;
		
		if( name.size() > 20 )
		{
			name.resize( 20 );
		}

		std::stringstream stream;
		stream << _entry.format << "_" << _counter++;

		boost::filesystem::path path( database );
		path = path.parent_path();
		path /= _entry.program + "_" + name + "_" + stream.str() 
			+ ".header";
		path = boost::filesystem::system_complete( path );
		
		_entry.header = path.string();
		
		_header.format = KernelDimensionsFormat;
		
		{
			//
			// this may not be strictly safe - a better solution is to improve the interface to
			// Executable kernel
			//
			const ir::EmulatedKernel & emuKernel = static_cast<const ir::EmulatedKernel & >(kernel);
			_header.block = emuKernel.blockDim;
			_header.grid = emuKernel.gridDim;
		}
	}

	void KernelDimensionsGenerator::event( const TraceEvent& event )
	{
	}
	
	void KernelDimensionsGenerator::finish()
	{
		_entry.updateDatabase( database );

		std::ofstream hfile( _entry.header.c_str() );
		boost::archive::text_oarchive harchive( hfile );
	
		if( !hfile.is_open() )
		{
			throw hydrazine::Exception(
				"Failed to open KernelDimensionsGenerator header file " 
				+ _entry.header );
		}
		
		harchive << _header;
		
		hfile.close();
	}
	
}

#endif

