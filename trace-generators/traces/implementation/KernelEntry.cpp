/*!
	\file KernelEntry.cpp
	
	\author Gregory Diamos
	\date Wednesday April 15, 2009
	
	\brief The source file for the KernelEntry class
*/

#ifndef KERNEL_ENTRY_CPP_INCLUDED
#define KERNEL_ENTRY_CPP_INCLUDED


#if (__GNUC__ == 4 && __GNUC_MINOR__ == 5)
#undef __GXX_EXPERIMENTAL_CXX0X__
#endif

#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <traces/interface/KernelEntry.h>
#include <fstream>
#include <hydrazine/interface/Exception.h>
#include <hydrazine/interface/debug.h>
#include <unistd.h>
#include <cstring>
#include <deque>
#include <boost/interprocess/sync/file_lock.hpp>

#include <hydrazine/interface/debug.h>

#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

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
		return hydrazine::stripReportPath<'/'>( result );
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
		
		int error = system( "touch KernelEntry_lock" );
		if( error < 0 )
		{
			throw hydrazine::Exception(
				"Failed to create KernelEntry_lock");
		}
		boost::interprocess::file_lock flock( "KernelEntry_lock" );
		
		report( "Updating databsse " << name );
		
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
				if( entry.header != header )
				{
					entries.push_back(entry);
				}
			}
		}
		
		ifile.close();
	
		std::ofstream file( name.c_str() );
	
		if( !file.is_open() )
		{		
			flock.unlock();
			throw hydrazine::Exception(
				"Failed to open trace database file " 
				+ name + " for writing" );
		}
		
		boost::archive::text_oarchive archive( file );
		
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

