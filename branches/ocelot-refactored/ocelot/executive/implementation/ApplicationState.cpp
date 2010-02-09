/*!
	\file ApplicationState.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief defines constructors and accessors for Ocelot application state objects
*/

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

	pointer.ptr = 0;
	pointer.xsize = pointer.ysize = pointer.pitch = 0;
	extent.width = extent.height = extent.depth = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////

executive::GlobalVariable::GlobalVariable():
	name("untitled"), size(0), host_pointer(0) {

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



