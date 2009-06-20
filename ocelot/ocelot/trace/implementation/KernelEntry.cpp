/*!
	\file KernelEntry.cpp
	
	\author Gregory Diamos
	\date Wednesday April 15, 2009
	
	\brief The source file for the KernelEntry class
*/

#ifndef KERNEL_ENTRY_CPP_INCLUDED
#define KERNEL_ENTRY_CPP_INCLUDED

#include <ocelot/trace/interface/KernelEntry.h>
#include <fstream>
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/debug.h>
#include <unistd.h>
#include <cstring>
#include <boost/interprocess/sync/file_lock.hpp>

namespace trace
{
	std::string KernelEntry::_program()
	{
		char buffer[1024];
		memset( buffer, 0, 1024 );
		int error = readlink( "/proc/self/exe", buffer, 1024 );
		if( error < 0 )
		{
			throw hydrazine::Exception("Could not read /proc/self/exe");
		}
		std::string result( buffer );
		return hydrazine::stripReportPath( result );
	}
	
	KernelEntry::KernelEntry() : format( TraceGenerator::InvalidTraceFormat ),
		program( _program() )
	{
	
	}
	
	KernelEntry::KernelEntry( TraceGenerator::TraceFormat f, 
		const std::string& n, const std::string& m, const std::string& p, 
		const std::string& h ) :
		format( f ), name( n ), module( m ), path( p ), header( h ),
		program( _program() )
	{
	
	}
	
	void KernelEntry::updateDatabase( const std::string& name )
	{
	
		typedef std::deque< KernelEntry > EntryVector;
		
		int error = system( "touch trace_KernelEntry_lock" );
		if( error < 0 )
		{
			throw hydrazine::Exception("Failed to create trace_KernelEntry_lock");
		}
		boost::interprocess::file_lock flock( "trace_KernelEntry_lock" );
		
		flock.lock();
		std::ifstream ifile( name.c_str() );
	
		EntryVector entries;
	
		if( ifile.is_open() )
		{
			
			boost::archive::text_iarchive archive( ifile );
			
			unsigned int count;
			
			archive >> count;
			
			for( unsigned int i = 0; i < count; ++i )
			{
				KernelEntry entry;
				archive >> entry;
				if( entry.path != path )
				{
					entries.push_back(entry);
				}
			}
		}
		
		ifile.close();
	
		std::ofstream file( name.c_str() );
		boost::archive::text_oarchive archive( file );
	
		if( !file.is_open() )
		{
			throw hydrazine::Exception(
				"Failed to open trace database file " 
				+ name );
		}
		
		unsigned int count = entries.size() + 1;
		
		archive << count;
		
		for( EntryVector::iterator entry = entries.begin(); 
			entry != entries.end(); ++entry )
		{
			archive << *entry;
		}
		
		archive << *this;
		
		file.flush();
		flock.unlock();
	
	}
	
}

#endif

