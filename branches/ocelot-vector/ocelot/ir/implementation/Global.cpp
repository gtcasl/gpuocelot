/*!
	\file Global.cpp
	
	\date Tuesday March 31, 2009
	\author Gregory Diamos
	
	\brief The source file for the Global class.	
*/

#ifndef GLOBAL_CPP_INCLUDED
#define GLOBAL_CPP_INCLUDED

// C++ stdlib includes
#include <cassert>
#include <cstring>

// Ocelot includes
#include <ocelot/ir/interface/Global.h>

// Hydrazine includes
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/macros.h>
#include <hydrazine/interface/Casts.h>

// Debugging messages
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace ir
{

	Global::Global() : local(false), pointer(0), registered(false)
	{
		
	}
	
	Global::Global( char* p ) : local(false), pointer(p), registered(false)
	{
	
	}

	Global::Global( const ir::PTXStatement& s ) : 
		local(!s.array.values.empty()), statement(s)
	{
		report("Global::Global(statement '" << statement.name << "')");
		if(local) 
		{
			assert(statement.bytes() == statement.initializedBytes());
			unsigned int size = statement.initializedBytes();
			pointer = new char[size];
			
			unsigned int elementsize = PTXOperand::bytes(statement.type);
			unsigned int step = elementsize;
			char* end = pointer + size;
			PTXStatement::ArrayVector::iterator 
				ai = statement.array.values.begin();

			report("  pointer: " << (void *)pointer);
			for(char* fi = pointer; fi < end; fi += step, ++ai )
			{
				assert(ai != statement.array.values.end());
				memcpy(fi, &ai->b8, elementsize);

				report("  " << std::hex << ((unsigned int)*fi & 0x0ff) << std::dec);
			}
		}
		else
		{
			pointer = 0;
		}
		registered = false;
	}

	Global::Global( const Global& g ) : local(g.local)
	{
		statement = g.statement;
		registered = g.registered;
		if(local)
		{
			unsigned int size = statement.initializedBytes();
			pointer = new char[size];
			memcpy(pointer, g.pointer, size);
			report("Global::Global(copy '" << statement.name << "') - g.pointer = " << (void *)g.pointer 
				<< ", new pointer = " << (void *)pointer);
		}
		else
		{
			pointer = g.pointer;
		}
	}
	
	Global::~Global()
	{
		if( local )
		{
			report("Global::~Global('" << statement.name << "') - deleting " << (void *)pointer);
			delete[] pointer;
		}
	}
	
	Global& Global::operator=(const Global& g)
	{
		if( &g != this )
		{
			if(local)
			{
				delete[] pointer;
			}

			local = g.local;
			statement = g.statement;
			registered = g.registered;
			if(local)
			{
				unsigned int size = statement.initializedBytes();
				pointer = new char[size];
				memcpy(pointer, g.pointer, size);
				report("Global::operator=('" << statement.name << "') - pointer = " << (void *)pointer);
			}
			else
			{
				pointer = g.pointer;
			}
			
		}
		return *this;
	}

	
	
}

#endif

