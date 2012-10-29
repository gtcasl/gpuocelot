#ifndef OCELOT_OPENCL_OBJECT_H_INCLUDED
#define OCELOT_OPENCL_OBJECT_H_INCLUDED

// C++ libs
#include <string>
#include <list>
#include <algorithm>

// Ocelot libs
#include <ocelot/opencl/interface/OpenCLRuntimeInterface.h>



namespace opencl {
	
	class Object {

public:
		//Object type
		typedef enum {
			OBJTYPE_PLATFORM,
			OBJTYPE_DEVICE,
			OBJTYPE_CONTEXT,
			OBJTYPE_PROGRAM,
			OBJTYPE_KERNEL,
			OBJTYPE_MEMORY,
			OBJTYPE_COMMANDQUEUE,
			OBJTYPE_EVENT
		}objT;

		typedef std::list<Object * > ObjectList;

		Object(objT type);
		virtual ~Object();

		//Check if is a object type
		bool isValidObject(objT type);	

		//Retain
		void retain();

		//Release
		bool release();

		//To string
		virtual std::string toString();

protected:
		//Object type
		const objT _objType;

		//Reference count
		unsigned int _references;
		
		
	};

}

#endif
