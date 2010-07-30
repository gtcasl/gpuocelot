/*!
	\file KernelEntry.h
	
	\author Gregory Diamos
	\date Wednesday April 15, 2009
	
	\brief The header file for the KernelEntry class
*/

#ifndef KERNEL_ENTRY_H_INCLUDED
#define KERNEL_ENTRY_H_INCLUDED

#include <ocelot/trace/interface/TraceGenerator.h>
#include <ocelot/ir/interface/Dim3.h>

namespace trace
{		
	/*!
		\brief Statistics associated with the trace for a specific 
		kernel
	*/
	class KernelEntry
	{
		private:
			/*!
				\brief Get a string representation of the program name
				\return The program name
			*/
			static std::string _program();
		
		public:
			TraceGenerator::TraceFormat format; //! The trace format stored
			std::string name; //! The name of the kernel
			std::string module; //! The module containing the kernel
			std::string path; //! The path to the kernel trace
			std::string header; //! Path to the header file
			std::string program; //! The program that generated the trace
			ir::Dim3 gridDim;	//! dimensions of grid that launched kernel
			ir::Dim3 blockDim;	//! dimensions of grid that launched kernel

		public:
			KernelEntry();
			KernelEntry( TraceGenerator::TraceFormat, const std::string&, 
				const std::string&, const std::string&, const std::string& );
			/*!
				\brief Add a kernel entry to the specified database
				\param name The database file path
			*/
			void updateDatabase( const std::string& name );
	};	
}

namespace boost
{
	namespace serialization
	{
		template< class Archive >
		void serialize( Archive& ar, 
			trace::KernelEntry& entry, 
			const unsigned int version )
		{
			ar & entry.format;
			ar & entry.name;
			ar & entry.module;
			ar & entry.path;
			ar & entry.header;
			ar & entry.program;
			ar & entry.gridDim.x & entry.gridDim.y & entry.gridDim.z;
			ar & entry.blockDim.x & entry.blockDim.y & entry.blockDim.z;
		}
	}
}

#endif

