/*!	\file ArgumentParser.cpp
	\brief Source file for the ArgumentParser class.
*/

#ifndef ARGUMENT_PARSER_CPP_INCLUDED
#define ARGUMENT_PARSER_CPP_INCLUDED

#include "ArgumentParser.h"

namespace hydrazine
{

	////////////////////////////////////////////////////////////////////////////
	// Argument parser
	void ArgumentParser::format( std::stringstream& stream, 
		const std::string& firstPrefix, const std::string& prefix )
	{

		report( "Formating string." );
		report( " Input stream is \"" << stream.str() << "\"" );
		report( " First prefix is \"" << firstPrefix << "\"" );
		report( " Regular prefix is \"" << prefix << "\"" );
			
		char currentCharacter;
		
		std::string word;
		std::stringstream result;
		unsigned int currentIndex = firstPrefix.size();
		
		unsigned int streamSize = stream.str().size();
	
		result << firstPrefix;
	
		for( unsigned int i = 0; i < streamSize; i++ )
		{
		
			stream.get( currentCharacter );
			
			if
			( 
				currentCharacter == ' ' ||
				currentCharacter == '\t' ||
				currentCharacter == '\n'
			)
			{
			
				if( currentIndex + word.size() > SCREEN_WIDTH )
				{
					currentIndex = prefix.size();
					result << "\n";
					result << prefix;
				}
				
				result << word << " " ;
				++currentIndex;
				word.clear();
			
			}
			else
			{
				word.push_back( currentCharacter );
				currentIndex++;
			}
		}

		if( currentIndex + word.size() > SCREEN_WIDTH )
		{
		
			result << "\n";
		
		}
		
		result << word << "\n";
	
		stream.str( "" );
		stream << result.str();
	
		report(  "Formatted stream is \"" << stream.str() << "\"" );
	
	}

	
	ArgumentParser::ArgumentParser(int _argc, char* _argv[])
	{
		argc = _argc;
		argv = _argv;
		description( "No description provided." );
	}
	
	void ArgumentParser::description( const std::string& d )
	{
		std::string desc = " Description: ";
		std::stringstream stream( d + '\n' );
		int repetition = MESSAGE_OFFSET - ( int )desc.size();
		std::string prefix( MAX( repetition, 0 ), ' ' );
		std::string regularPrefix( MESSAGE_OFFSET, ' ' );
		
		format( stream, prefix, regularPrefix );
		
		_description = desc + stream.str() + "\n";
	}


	bool ArgumentParser::isPresent(const std::string& identifier)
	{
		bool found = false;
	
		report( "Searching for " << identifier );
	
		for(int i = 0; i < argc; i++)
		{
			std::string str = argv[i];
			size_t pos = str.find(identifier);
			if( pos == 0 && str.size() == identifier.size() )
			{
				report( "Found in " << str );
				found = true;
				break;
			}
		}
	
		return found;
	}
	
	std::string ArgumentParser::help() const
	{
		std::stringstream stream;
		stream << "\nProgram : " << argv[0] << "\n\n";
		stream << _description;
		stream << "Arguments : \n\n";		
		stream << arguments.str();
		stream << "\n";
		return stream.str();
	}
			
	void ArgumentParser::parse(const std::string& _identifier, bool& b, 
		bool starting, const std::string& string)
	{
		assert( _identifier.size() == 2 );
		assert( _identifier[0] == '-' );

		if( isPresent( _identifier ) )
		{
			report( " is present" );
			b = !starting;
		}
		else
		{
			b = starting;
		}
		
		std::string identifier( ' ' + _identifier );

		int prefixSpacing = MESSAGE_OFFSET - ( int )identifier.size();
		
		std::string prefix( MAX( prefixSpacing, 0 ), ' ' );
		std::string regularPrefix( MESSAGE_OFFSET, ' ' );

		std::stringstream secondStream( string + '\n' );
		
		format( secondStream, prefix, regularPrefix );
		secondStream << regularPrefix << "value = " << std::boolalpha 
			<< b << "\n";
	
		arguments << identifier << secondStream.str() << "\n";
	}

	void ArgumentParser::parse(const std::string& _identifier, 
		const std::string& _longIdentifier, bool& b, bool starting,
		const std::string& string)
	{
		assert( _identifier.size() == 2 );
		assert( _identifier[0] == '-' );

		if( isPresent( _identifier ) || isPresent( _longIdentifier ) )
		{
			report( " is present" );
			b = !starting;
		}
		else
		{
			b = starting;
		}
		
		std::string identifier( ' ' + _identifier + '(' 
			+ _longIdentifier + ')' );

		int prefixSpacing = MESSAGE_OFFSET - ( int )identifier.size();
		
		std::string prefix( MAX( prefixSpacing, 0 ), ' ' );
		std::string regularPrefix( MESSAGE_OFFSET, ' ' );

		std::stringstream secondStream( string + '\n' );
		
		format( secondStream, prefix, regularPrefix );
		secondStream << regularPrefix << "value = " << std::boolalpha 
			<< b << "\n";
	
		arguments << identifier << secondStream.str() << "\n";
	}
	
	void ArgumentParser::parse()
	{
		bool printHelp;
		parse( "-h", "--help", printHelp, false, "Print this help message." );
		if( printHelp )
		{
			std::cout << help();
			exit(0);
		}
	}
	////////////////////////////////////////////////////////////////////////////////

}

#endif

