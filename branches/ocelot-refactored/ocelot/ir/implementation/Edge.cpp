/*!
	\file Edge.cpp
	
	\author Andrew Kerr <arkerr@gatech.edu>
	
	\brief implementation for Edge class
	
	\date 28 September 2008
*/

#include <ocelot/ir/interface/Edge.h>

using namespace ir;

Edge::Edge(): head(0), tail(0), type(Edge::FallThrough) {
	
}

Edge::~Edge() {
	
}

