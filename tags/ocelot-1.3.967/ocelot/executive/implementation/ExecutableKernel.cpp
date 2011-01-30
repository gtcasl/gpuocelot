/*! \file ExecutableKernel.h
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date December 22, 2009
	\brief implements a kernel that is executable on some device
*/

#ifndef EXECUTABLE_KERNEL_CPP_INCLUDED
#define EXECUTABLE_KERNEL_CPP_INCLUDED

// C includes
#include <memory.h>

// Ocelot includes
#include <ocelot/executive/interface/ExecutableKernel.h>
#include <ocelot/trace/interface/TraceGenerator.h>

// Hydrazine includes
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/Exception.h>
#include <hydrazine/implementation/macros.h>

// Debugging messages
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

namespace executive 
{
ExecutableKernel::ExecutableKernel( const ir::Kernel& k, 
	executive::Device* d ) : ir::Kernel( k ), device( d ), 
	_constMemorySize( 0 ), _localMemorySize( 0 ), _maxThreadsPerBlock( 16384 ), 
	_registerCount( 0 ), _sharedMemorySize( 0 ), 
	_externSharedMemorySize( 0 ), _parameterMemorySize( 0 )
{
	mapParameterOffsets();
}

ExecutableKernel::ExecutableKernel( executive::Device* d ) :
	device( d ), _constMemorySize( 0 ), _localMemorySize( 0 ), 
	_maxThreadsPerBlock( 16384 ), _registerCount( 0 ), 
	_sharedMemorySize( 0 ), _externSharedMemorySize( 0 ), 
	_parameterMemorySize( 0 )
{
	mapParameterOffsets();
}

ExecutableKernel::~ExecutableKernel() 
{

}

bool ExecutableKernel::executable() 
{
	return true;
}

void ExecutableKernel::traceEvent(const trace::TraceEvent & event) const
{
	for(TraceGeneratorVector::const_iterator generator = _generators.begin(); 
		generator != _generators.end(); ++generator) {
		(*generator)->event(event);
	}
}

void ExecutableKernel::tracePostEvent(const trace::TraceEvent & event) const
{
	for(TraceGeneratorVector::const_iterator generator = _generators.begin(); 
		generator != _generators.end(); ++generator) {
		(*generator)->postEvent(event);
	}
}

unsigned int ExecutableKernel::constMemorySize() const
{
	return _constMemorySize; 
}

unsigned int ExecutableKernel::localMemorySize() const
{ 
	return _localMemorySize; 
}

unsigned int ExecutableKernel::maxThreadsPerBlock() const
{
	return _maxThreadsPerBlock; 
}

unsigned int ExecutableKernel::registerCount() const
{ 
	return _registerCount; 
}

unsigned int ExecutableKernel::sharedMemorySize() const 
{ 
	return _sharedMemorySize; 
}

unsigned int ExecutableKernel::externSharedMemorySize() const 
{ 
	return _externSharedMemorySize; 
}

unsigned int ExecutableKernel::totalSharedMemorySize() const
{
	return externSharedMemorySize() + sharedMemorySize();
}

unsigned int ExecutableKernel::parameterMemorySize() const 
{ 
	return _parameterMemorySize; 
}

const ir::Dim3& ExecutableKernel::blockDim() const
{
	return _blockDim;
}

const ir::Dim3& ExecutableKernel::gridDim() const
{
	return _gridDim;
}

/*!
	\brief compute parameter offsets for parameter data
*/
size_t ExecutableKernel::mapParameterOffsets() {
	unsigned int paramSize = 0;

	for (ParameterVector::iterator it = parameters.begin(); 
		it != parameters.end(); ++it) {
		ir::Parameter& parameter = *it;
		unsigned int misAlignment = paramSize % parameter.getAlignment();
		paramSize += misAlignment == 0 
			? 0 : parameter.getAlignment() - misAlignment;

		parameter.offset = paramSize;
		paramSize += parameter.getSize();
	}

	report("ExecutableKernels::mapParameterOffsets() - '" << name 
		<< "' - size: " << paramSize << " bytes");

	return paramSize;
}

/*!
	\brief given a block of parameter memory, sets the values of each parameter
	\param parameter pointer to parameter memory
	\param paramSize number of bytes to write to parameter memory
*/
void ExecutableKernel::setParameterBlock(const unsigned char *parameter, 
	size_t paramSize) {
	mapParameterOffsets();

	report("ExecutableKernel::setParameterBlock() - paramSize = " << paramSize);

	for (ParameterVector::iterator it = parameters.begin();
		it != parameters.end(); ++it) {
		const unsigned char *ptr = parameter + it->offset;
		for (ir::Parameter::ValueVector::iterator 
			val_it = it->arrayValues.begin();
			val_it != it->arrayValues.end(); 
			++val_it, ptr += it->getElementSize()) {
			assert((size_t)ptr - (size_t)parameter 
				+ it->getElementSize() < (size_t)paramSize);
			memcpy(&val_it->val_u64, ptr, it->getElementSize());
		}

		report("Configuring parameter " << it->name 
			<< " - offset: "  << it->offset
			<< " - type: " << it->arrayValues.size() << " x " 
			<< ir::PTXOperand::toString(it->type)
			<< " - value: " << ir::Parameter::value(*it));
	}
}

/*!
	\brief gets the values of each parameter as a block of binary data
	\param parameter pointer to parameter memory
	\param maxSize maximum number of bytes to write to parameter memory
	\return actual number of bytes required by parameter memory
*/
size_t ExecutableKernel::getParameterBlock(unsigned char* block, 
	size_t maxSize) const {
	size_t offset = 0;
	for (ParameterVector::const_iterator it = parameters.begin();
		it != parameters.end(); ++it) {
		const ir::Parameter& parameter = *it;
		report("Getting parameter " << parameter.name 
			<< " " 
			<< " - type: " << parameter.arrayValues.size() << " x " 
			<< ir::PTXOperand::toString(parameter.type)
			<< " - value: " << ir::Parameter::value(parameter));

		unsigned char *ptr = block + parameter.offset;
		for (ir::Parameter::ValueVector::const_iterator 
			val_it = parameter.arrayValues.begin();
			val_it != parameter.arrayValues.end(); 
			++val_it, ptr += parameter.getElementSize()) {
			
			memcpy(ptr, &val_it->val_u64, parameter.getElementSize());
		}
		offset = parameter.offset + parameter.getElementSize();
	}
	
	for (ParameterVector::const_iterator it = parameters.begin();
		it != parameters.end(); ++it) {
		const ir::Parameter& parameter = *it;
		report("Getting parameter " << parameter.name 
			<< " " 
			<< " - type: " << parameter.arrayValues.size() << " x " 
			<< ir::PTXOperand::toString(parameter.type)
			<< " - value: " << ir::Parameter::value(parameter));

		unsigned char *ptr = block + parameter.offset;
		for (ir::Parameter::ValueVector::const_iterator 
			val_it = parameter.arrayValues.begin();
			val_it != parameter.arrayValues.end(); 
			++val_it, ptr += parameter.getElementSize()) {
			
			memcpy(ptr, &val_it->val_u64, parameter.getElementSize());
		}
		offset = parameter.offset + parameter.getElementSize();
	}
	
	return offset;
}

}

#endif

