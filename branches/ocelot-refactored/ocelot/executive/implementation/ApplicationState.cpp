/*!
	\file ApplicationState.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief defines constructors and accessors for Ocelot application state objects
*/

// C++ includes
#include <sstream>

// Ocelot includes
#include <ocelot/executive/interface/ApplicationState.h>

//////////////////////////////////////////////////////////////////////////////////////////////////

executive::MemoryAllocation::MemoryAllocation():
	structure(Struct_linear),
	dimension(Dim_1D),
	affinity(Affinity_host),
	addressSpace(0),
	allocationSize(0),
	flags(0),
	internal(true) {

	pointer.offset = 0;
	pointer.ptr = 0;
	pointer.xsize = pointer.ysize = pointer.pitch = 0;
	extent.width = extent.height = extent.depth = 0;
}

std::string executive::MemoryAllocation::toString() const {
	std::stringstream ss;

	ss << "= " << (void *)pointer.ptr << " - " 
		<< (void *)((char*)pointer.ptr + allocationSize - 1) << "\n";

	ss << "= pointer: " << (void*)pointer.ptr << "\n";
	ss << "= " << allocationSize << " bytes\n";
	ss << "= device address space: " << addressSpace << "\n";
	switch (structure) {
		case Struct_linear:
			ss << "= linear structure, " << (int)dimension + 1 << "D\n";
			break;
		case Struct_array:
			ss << "= array structure, " << (int)dimension + 1 << "D\n";
			break;
		case Struct_pitch:
			ss << "= pitched structure, " << (int)dimension + 1 << "D\n";
			break;
		case Struct_invalid:
		default:
			ss << "= unknown structure\n";
	}

	ss << "= pitch: " << pointer.pitch << "\n";
	ss << "= width: " << pointer.width << "\n";
	ss << "= height: " << pointer.height << "\n";

	return ss.str();
}

//////////////////////////////////////////////////////////////////////////////////////////////////

executive::GlobalVariable::GlobalVariable():
	name("untitled") {

}

//////////////////////////////////////////////////////////////////////////////////////////////////
/*
executive::Texture::Texture():
	name(""),
	module(""),
	normalized(false),
	bound(false),
	offset(0),
	texRef(0),
	size(0) {

	device_pointer.ptr = 0;
	device_pointer.xsize = device_pointer.ysize = device_pointer.pitch = 0;
	
	desc.x = desc.y = desc.z = desc.w = 0;	
}
*/
//////////////////////////////////////////////////////////////////////////////////////////////////



