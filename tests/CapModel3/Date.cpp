/*!

	\file Date.cpp
	
	\author Gregory Diamos
	
	\date Saturday December 13, 2008
	
	\brief The source file for the Date class.

*/

#ifndef DATE_CPP_INCLUDED
#define DATE_CPP_INCLUDED

#include "Date.h"
#include <cassert>
#include <common/implementation/macros.h>

namespace sim
{

	Date::Day Date::_days( Month m, Year y )
	{
	
		assert( m < 13 );
		
		switch( m )
		{
		
			case January:
			{
			
				return 31;
				break;
							
			}
			
			case February:
			{
			
				if( _leapYear( y ) )
				{
				
					return 29;
				
				}
				else
				{
				
					return 28;
				
				}
				
				break;
							
			}
			
			case March:
			{
			
				return 31;
				break;
							
			}
			 
			case April:
			{
			
				return 30;
				break;
							
			}
			
			case May:
			{
			
				return 31;
				break;
							
			}
			
			case June:
			{
			
				return 30;
				break;
							
			}
			
			case July:
			{
			
				return 31;
				break;
							
			}
			
			case August:
			{
			
				return 31;
				break;
							
			}
			
			case September:
			{
			
				return 31;
				break;
							
			}
			
			case October:
			{
			
				return 31;
				break;
							
			}
			
			case November:
			{
			
				return 30;
				break;
							
			}
			
			case December:
			{
			
				return 31;
				break;
							
			}
		
		}
		
		return 31;
	
	}

	bool Date::_leapYear( Year y )
	{
	
		return ( y % 4 ) == 0;
	
	}

	Date::Date( Year y, Month m, Day d ):
		day(d),
		month(m),
		year(y)
	{
	
	
	}

	Date::Date():
		day(0),
		month(0),
		year(0)
	{
	
	
	}
	
	void Date::addMonths( Month months )
	{
	
		for( unsigned int i = 0; i < months; ++i )
		{
		
			++month;
			
			if( month > 12 )
			{
			
				month = 1;
				++year;
			
			}
		
		}
		
		day = MAX( day, _days( month, year ) );
	
	}

	const Date& Date::operator=( const std::string& string )
	{
	
		std::stringstream stream;
				
		for( std::string::const_iterator fi = string.begin(); 
			fi != string.end(); ++fi )
		{
		
			if( *fi == '-' )
			{
			
				stream << ' ';
							
			}
			else
			{
			
				stream << *fi;
			
			}
		
		}
		
		assert( !stream.str().empty() );
		stream >> year;
		
		assert( !stream.str().empty() );
		
		stream >> month;
		
		assert( !stream.str().empty() );
		stream >> day;
		
		assert( valid() );
		
		return *this;
	
	}

	Date Date::operator+( const Date& d )
	{
	
		Date result;
		result.value( this->value() + d.value() );
		return result;
	
	}
	
	Date Date::operator-( const Date& d )
	{
	
		Date result;
		result.value( this->value() - d.value() );
		return result;
	
	}
	
	std::string Date::toString() const
	{

		assert( valid() );
	
		std::stringstream stream;
		
		stream << year << "-" << month << "-" << day;
		
		return stream.str();
	
	}
	
	bool Date::operator<( const Date& d ) const
	{
	
		assert( valid() );
		assert( d.valid() );
	
		if( year < d.year )
		{
		
			return true;
		
		}
		else if( year == d.year )
		{
		
			if( month < d.month )
			{
			
				return true;
			
			}
			else if( month == d.month )
			{
			
				if( day < d.day )
				{
				
					return true;
				
				}
				else
				{
				
					return false;
				
				}
			
			}
			else
			{
			
				return false;
			
			}
			
		}
		else
		{
		
			return false;
		
		}
	
	}
	
	bool Date::operator==( const Date& d ) const
	{

		assert( valid() );
		assert( d.valid() );
	
		return ( d.day == day ) && ( month == d.month ) && ( year == d.year );
	
	}

	bool Date::valid() const
	{
	
		return ( day < 32 ) && ( month < 13 );
	
	}

	unsigned int Date::value() const
	{
	
		unsigned int value = 0;
		
		value += day;
		
		for( unsigned int i = 0; i < month; ++i )
		{
		
			value += _days( month, year );
		
		}
		
		value += 365 * year;
		value += year / 4;
		
		return value;
	
	}

	void Date::value( unsigned int value )
	{
	
		year = (unsigned int) ( value / 365.25 );
	
		value -= year / 4;
		value -= 365 * year;
		
		month = 1;
		
		while( value > _days( month, year ) )
		{
		
			value -= _days( month++, year );
		
		}
		
		day = value;
	
	}

}

#endif

