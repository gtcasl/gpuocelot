/*!
	\file BranchEvent.h
	\date Friday July 24, 2009
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\brief The header file for the BranchEvent class.
*/

#ifndef BRANCH_EVENT_H_INCLUDED
#define BRANCH_EVENT_H_INCLUDED

#include <ocelot/trace/interface/TraceEvent.h>
#include <boost/serialization/split_member.hpp>

namespace trace
{
	/*!
		\brief Statistics associated with a specific branch
	*/
	class BranchEvent
	{
		private:
			friend class boost::serialization::access;

			template< class Archive >
			void save( Archive& ar,  
				const unsigned int version ) const
			{
				std::string takenString;
				std::string fallthroughString;

				boost::to_string( taken, takenString );
				boost::to_string( fallthrough, fallthroughString );

				ar & pc;
				ar & counter;
				ar & takenString;
				ar & fallthroughString;
			
			}

			template< class Archive >
			void load( Archive& ar, 
				const unsigned int version )
			{
				std::string takenString;
				std::string fallthroughString;

				ar & pc;
				ar & counter;
				ar & takenString;
				ar & fallthroughString;
			
				taken = TraceEvent::BitMask( takenString );
				fallthrough = TraceEvent::BitMask( fallthroughString );

			}
			BOOST_SERIALIZATION_SPLIT_MEMBER()

		public:
			BranchEvent();
			BranchEvent( const TraceEvent::BitMask& taken, 
				const TraceEvent::BitMask& fallthrough,
				const unsigned int pc,
				const unsigned int counter );
		public:
			TraceEvent::BitMask taken; //! Taken mask
			TraceEvent::BitMask fallthrough; //! Fall through mask
			long long unsigned int pc; //! The pc of the branch
			long long unsigned int counter; //! The instruction number

	};
	
}

#endif


