/*! \file OcelotConfig.cpp
	\author Gregory Diamos
	\date Sunday January 24, 2010
	\brief The source file for the OcelotConfig class.
*/

#ifndef OCELOT_CONFIG_CPP_INCLUDED
#define OCELOT_CONFIG_CPP_INCLUDED

#include <ocelot/util/interface/OcelotConfig.h>
#include <configure.h>

#include <hydrazine/implementation/ArgumentParser.h>

namespace util
{

	std::string OcelotConfig::_flags() const
	{
		return OCELOT_CXXFLAGS;
	}

	std::string OcelotConfig::_version() const
	{
		return PACKAGE_VERSION;
	}

	std::string OcelotConfig::_prefix() const
	{
		return OCELOT_PREFIX_PATH;
	}

	std::string OcelotConfig::_libs() const
	{
		return OCELOT_LDFLAGS;
	}

	std::string OcelotConfig::_includedir() const
	{
		return OCELOT_INCLUDE_PATH;
	}

	std::string OcelotConfig::_libdir() const
	{
		return OCELOT_LIB_PATH;
	}

	std::string OcelotConfig::_bindir() const
	{
		return OCELOT_BIN_PATH;
	}

	std::string OcelotConfig::_tracelibs() const
	{
		return "-locelotTrace";
	}

	std::string OcelotConfig::string() const
	{
		std::string result;
		if( version )
		{
			result = _version();
		}
		else if( flags )
		{
			result = _flags();
		}
		else if( prefix )
		{
			result = _prefix();
		}
		else if( libs )
		{
			result = _libs();
		}
		else if( includedir )
		{
			result = _includedir();
		}
		else if( libdir )
		{
			result = _libdir();
		}
		else if( bindir )
		{
			result = _bindir();
		}
		else
		{
			return "";
		}

		if( trace )
		{
			result += _tracelibs();
		}
		
		return result + "\n";
	}

	OcelotConfig::OcelotConfig()
	{
	
	}
	
}

int main(int argc, char** argv)
{
	hydrazine::ArgumentParser parser(argc, argv);
	util::OcelotConfig config;
	
	parser.parse( "-l", "--libs", config.libs, false,
		"Libraries needed to link against Ocelot." );
	parser.parse( "-t", "--trace", config.trace, false,
		"Link against ocelot trace generators." );
	parser.parse( "-x", "--cxxflags", config.flags, false,
		"C++ flags for programs that include Ocelot headers." );
	parser.parse( "-L", "--libdir", config.libdir,  false,
		"Directory containing Ocelot libraries." );
	parser.parse( "-i", "--includedir", config.includedir, false,
		"Directory containing Ocelot headers." );
	parser.parse( "-b", "--bindir", config.bindir, false,
		"Directory containing Ocelot executables." );
	parser.parse( "-v", "--version", config.version, false,
		"Print Ocelot version." );
	parser.parse( "-p", "--prefix", config.prefix, false,
		"Print the install prefix." );
	parser.parse();

	std::cout << config.string();
	
	return 0;
}

#endif

