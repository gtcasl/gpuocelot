/*!

	\file Date.h
	
	\author Gregory Diamos
	
	\date Saturday December 13, 2008
	
	\brief The header file for the Date class.

*/

#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <common/interface/Stringable.h>

namespace sim
{

	class Date: public common::Stringable
	{
	
		public:
		
			typedef unsigned int Day;
			typedef unsigned int Month;
			typedef unsigned int Year;
			
			enum Months
			{
				
				January = 1,
				February = 2,
				March = 3, 
				April = 4,
				May = 5,
				June = 6,
				July = 7,
				August = 8,
				September = 9,
				October = 10,
				November = 11,
				December = 12
			
			};
	
		private:
		
			static Day _days( Month, Year );
			static bool _leapYear( Year );
	
		public:
		
			Day day;
			Month month;
			Year year;
		
		public:
		
			Date( Year, Month, Day );
			Date();
			
			void addMonths( Month months );
			
			const Date& operator=( const std::string& string );
			Date operator+( const Date& );
			Date operator-( const Date& );
			
			std::string toString() const;
			
			bool operator<( const Date& ) const;
			bool operator==( const Date& ) const;
			
			bool valid() const;
			
			unsigned int value() const;
			void value( unsigned int );
	
	};

}

#endif

