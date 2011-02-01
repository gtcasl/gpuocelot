/*!
	\file ExtractedDeviceState.h
	\author Andrew Kerr <arkerr@gatech.edu>
	\date 31 Jan 2011
	\brief Data structure describing device state with serialization and deserialization procedures
*/

#include <ocelot/util/interface/ExtractedDeviceState.h>

/////////////////////////////////////////////////////////////////////////////////////////////////

//! \brief constructs from an istream - input must be JSON document
util::ExtractedDeviceState::ExtractedDeviceState(std::istream &in) {
	deserialize(in);
}

util::ExtractedDeviceState::ExtractedDeviceState() {

}

util::ExtractedDeviceState::~ExtractedDeviceState() {

}

//! \brief store data in host memory to file
void util::ExtractedDeviceState::serialize(std::ostream &out) {
	
}

//! \brief load data from JSON file to host memory
void util::ExtractedDeviceState::deserialize(std::istream &in) {

}

//! \brief clear all data structures
void util::ExtractedDeviceState::clear() {

}

