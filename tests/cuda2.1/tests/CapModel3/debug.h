
/*!	\file debug.h
*
*	\brief Header file for common debug macros
*
*	\author Gregory Diamos
*
*	\date : Sunday November 16, 2008
*
*/


#ifndef DEBUG_H_INCLUDED
#define DEBUG_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <sstream>
#include "Timer.h"

namespace hydrazine
{

	/*!
		\brief Global report timer
	*/
	extern Timer _ReportTimer;

	/*!

		\brief Convert an iterable range to a string
		
		T must implement the concept of a forward iterator and the object being
			pointed to must be able to be accepted by operator<<
		
		\param begin Iterator to the start of the range
		\param end Iterator to the end of the range
		\param space The string used as a space
		
		\return A string representation of the specified range.

	*/
	template < typename T > std::string toString( T begin, T end, 
		std::string space = " ", unsigned int limit = 80 )
	{
		std::stringstream stream;
		
		if( begin != end )
		{
			stream << *begin;
			++begin;
		}
		
		for( T iterator = begin; iterator != end; ++iterator )
		{
			stream << space;			
			stream << *iterator;
			if( stream.str().size() > limit )
			{
				break;
			}
		}
		
		return stream.str();
	}

	/*!

		\brief Convert an iterable range to a string using a formatting functor
		
		T must implement the concept of a forward iterator and the object being
			pointed to must be able to be accepted 
			by operator<< format( object )
		
		\param begin Iterator to the start of the range
		\param end Iterator to the end of the range
		\param space The string used as a space
		
		\return A string representation of the specified range.

	*/
	template < typename T, typename Format > std::string toFormattedString( 
		T begin, T end, Format format, std::string space = " ", 
		unsigned int limit = 80 )
	{
		std::stringstream stream;
		
		if( begin != end )
		{
			stream << format( begin );
			++begin;
		}
		
		for( T iterator = begin; iterator != end; ++iterator )
		{
			stream << space;			
			stream << format( iterator );
			if( stream.str().size() > limit )
			{
				break;
			}
		}
		
		return stream.str();
	}

	/*!
		\brief Strip the front of a file	
	*/
	template< char delimiter >
	std::string stripReportPath( const std::string& string )
	{
	
		size_t found = string.find_last_of(delimiter);
		std::string result = string.substr(found+1);
		return result;
	
	}

}

/*!

	\def REPORT_ERROR_LEVEL
	
	\brief The threshold to print out the debugging message.
	
	If the debugging error levels is less than this, it will not be printed out.

*/

#ifndef REPORT_ERROR_LEVEL
#define REPORT_ERROR_LEVEL 1
#endif

/*!

	\def EXIT_ERROR_LEVEL
	
	\brief The threshold exit the program.
	
	If the debugging error levels is greater than this, the program will exit.

*/
#ifndef EXIT_ERROR_LEVEL
#define EXIT_ERROR_LEVEL 100
#endif

#ifndef REPORT_BASE
#define REPORT_BASE 11
#endif



/*!
	\def printg(x)
	\brief a MACRO that prints a string to stdio 
	
			If MPI_DEBUG is defined, it appends the rank to the beginning 
			of the error message.
	
	\param x The string to print to std::cout

*/

#ifdef MPI_DEFINED

	#undef SEEK_SET
	#undef SEEK_CUR
	#undef SEEK_END
	#include <mpi.h>
	#define printg(x) \
		{ 	int rank; \
			MPI_Comm_rank(MPI_COMM_WORLD, &rank);\
			\
			\
			{\
			std::cout << "Rank: " << rank <<" " << x << "\n";\
			}\
		 \
		}\
		

#else
	#define printg(x) \
		{ 	\
			\
			{\
			std::cout << x << "\n";\
			}\
		 \
		}\

#endif



/*!
	\def reportE(x,y)
	\brief a MACRO that prints a string to stdio if DEBUG is defined and x is 
	greater than REPORT_ERROR_LEVEL, or exits the program if the error level 
	is greater than EXIT_ERROR_LEVEL.  
	
	If MPI_DEBUG is defined, it appends the rank to the beginning of the error 
	message.
	
	\param x The error level
	\param y The message to print.  You can use the << operators to send 
		multiple arguments
*/

#ifndef NDEBUG

	#ifdef DONT_STRIP_REPORT_PATH

	#define reportE(x, y) \
		if(REPORT_BASE >= REPORT_ERROR_LEVEL && (x) >= REPORT_ERROR_LEVEL)\
		{ \
			{\
			std::cout << "(" << hydrazine::_ReportTimer.seconds() << ") " \
				<< __FILE__ << ":" << __LINE__ << ": " << y << "\n";\
			}\
		 \
		}\
		else if( (x) >= EXIT_ERROR_LEVEL)\
		{ \
			std::cout << "(" << hydrazine::_ReportTimer.seconds() << ") " \
				<< __FILE__ << ":" << __LINE__ << ": This error level " \
				<< "is critical, exiting!\n";\
			exit( x ); \
		}

	#else
	
		#define reportE(x, y) \
			if(REPORT_BASE >= REPORT_ERROR_LEVEL && (x) >= REPORT_ERROR_LEVEL)\
			{ \
				{\
				std::cout << "(" << hydrazine::_ReportTimer.seconds() << ") " \
					<< hydrazine::stripReportPath<'/'>(__FILE__) << ":" \
					<< __LINE__ << ": " << y << "\n";\
				}\
			 \
			}\
			else if( (x) >= EXIT_ERROR_LEVEL)\
			{ \
				std::cout << "(" << hydrazine::_ReportTimer.seconds() << ") " \
					<< hydrazine::stripReportPath<'/'>(__FILE__)\
					<< ":" << __LINE__ << ": This error level " \
					<< "is critical, exiting!\n";\
				exit( x ); \
			}	
	#endif

#else

	#define reportE(x, y)
	
#endif

/*!
	\def REPORT(y)
	\brief a MACRO that prints a string to stdio if NDEBUG is not defined and y
	is greater than REPORT_ERROR_LEVEL, or exits the program if the error 
	level is greater than EXIT_ERROR_LEVEL.  If MPI_DEBUG is defined, it 
	appends the rank to the beginning of the error message.
	
	\param y The message to print.  You can use the << operators to send 
		multiple arguments
*/

#ifndef NDEBUG

	#ifdef MPI_DEFINED

		#undef SEEK_SET
		#undef SEEK_CUR
		#undef SEEK_END
		#include <mpi.h>
		#define REPORT(y) \
			if(REPORT_BASE >= REPORT_ERROR_LEVEL)\
			{ 	int rank; \
				MPI_Comm_rank(MPI_COMM_WORLD, &rank);\
				\
				\
				{\
				std::cout << "Rank: " << rank <<"(" << REPORT_BASE  << ") : " \
					<< y << "\n";\
				}\
			 \
			}\
			if(REPORT_BASE  >= EXIT_ERROR_LEVEL)\
			{ \
				std::cout << "(" << REPORT_BASE  << ") : This error level is "\
					<< "critical, exiting!\n";\
				exit( REPORT_BASE ); \
			}

	#else
	
		#define REPORT(y) \
			if(REPORT_BASE >= REPORT_ERROR_LEVEL)\
			{ \
				{\
				std::cout << "(" << REPORT_BASE  << ") : " << y << "\n";\
				}\
			 \
			}\
			if(REPORT_BASE  >= EXIT_ERROR_LEVEL)\
			{ \
				std::cout << "(" << REPORT_BASE  << ") : This error level " \
					<< "is critical, exiting!\n";\
				exit( REPORT_BASE ); \
			}

	#endif

#else

	#define REPORT(y)
	
#endif

/*!
	
	\def COND_MPI_INIT(x,y)
	\brief A macro to initialize MPI if it has not already been initialized and 
			MPI_DEFINED is defined.
	\param x This should be the pointer to argc
	\param y This should be the pointer to argv

*/

#ifdef MPI_DEFINED
	#define COND_MPI_INIT(x,y)\
		{ \
			int init;\
			MPI_Initialized(&init);\
			if(!init)\
			{\
				MPI_Init((x), (y));\
			}\
		}
#else
	#define COND_MPI_INIT(x,y)

#endif

/*!
	\def report(a)
	\brief a MACRO that prints a string to stdio if DEBUG is defined
	\param a a string
*/

#ifndef NDEBUG

	#ifdef DONT_STRIP_REPORT_PATH

	#define report(y) \
		if(REPORT_BASE >= REPORT_ERROR_LEVEL)\
		{ \
			{\
			std::cout << "(" << hydrazine::_ReportTimer.seconds() << ") " \
				<< __FILE__ << ":" << __LINE__ << ": " << y << "\n";\
			}\
		 \
		}\
		else if(REPORT_BASE  >= EXIT_ERROR_LEVEL)\
		{ \
			std::cout << "(" << hydrazine::_ReportTimer.seconds() << ") " \
				<< __FILE__ << ":" << __LINE__ << ": This error level " \
				<< "is critical, exiting!\n";\
			exit( REPORT_BASE ); \
		}

	#else
	
		#define report(y) \
			if(REPORT_BASE >= REPORT_ERROR_LEVEL)\
			{ \
				{\
				std::cout << "(" << hydrazine::_ReportTimer.seconds() << ") " \
					<< hydrazine::stripReportPath<'/'>(__FILE__) << ":" \
					<< __LINE__ << ": " << y << "\n";\
				}\
			 \
			}\
			else if(REPORT_BASE  >= EXIT_ERROR_LEVEL)\
			{ \
				std::cout << "(" << hydrazine::_ReportTimer.seconds() << ") " \
					<< hydrazine::stripReportPath<'/'>(__FILE__)\
					<< ":" << __LINE__ << ": This error level " \
					<< "is critical, exiting!\n";\
				exit( REPORT_BASE ); \
			}	
	#endif

#else

	#define report(y)
	
#endif



/*! \def reportf(...)

	\brief a MACRO for printing a string to stdio id debug is defined, similar 
		to printf

*/

#if __STDC_VERSION__ >= 199901L

	#ifndef NDEBUG
		#define reportf(...) {printf("[%s]:",__FUNCTION);printf(__VA_ARGS__);\
			printf("\n");}
	#else
		#define reportf
	#endif

#else 

	#define reportf

#endif

/*!

	\brief A cast along the lines of static_cast that selectively inserts 
		runtime checks for validity depending on the definition of NDEBUG.

*/
#ifdef NDEBUG
	#define debug_cast static_cast
#else
	#define debug_cast dynamic_cast
#endif

#endif
