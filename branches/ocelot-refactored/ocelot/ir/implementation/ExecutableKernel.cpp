/*! \file ExecutableKernel.h
	\author Gregory Diamos <gregory.diamos@gatech.edu>
	\date December 22, 2009
	\brief implements a kernel that is executable on some device
*/

#ifndef IR_EXECUTABLE_KERNEL_CPP_INCLUDED
#define IR_EXECUTABLE_KERNEL_CPP_INCLUDED

// C includes
#include <memory.h>

// Ocelot includes
#include <ocelot/ir/interface/ExecutableKernel.h>
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

namespace ir 
{
ExecutableKernel::ExecutableKernel( const Kernel& k, 
	const executive::Executive* c ) : Kernel( k ), context( c ), 
	_constMemorySize( 0 ), _localMemorySize( 0 ), _maxThreadsPerBlock( 0 ), 
	_registerCount( 0 ), _sharedMemorySize( 0 ), 
	_externSharedMemorySize( 0 ), _parameterMemorySize( 0 )
{
	mapParameterOffsets();
}

ExecutableKernel::ExecutableKernel( const executive::Executive* c ) :
	context( c ), _constMemorySize( 0 ), _localMemorySize( 0 ), _maxThreadsPerBlock( 0 ), 
	_registerCount( 0 ), _sharedMemorySize( 0 ), 	_externSharedMemorySize( 0 ), 
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

void ExecutableKernel::traceEvent( const trace::TraceEvent & event) const
{
	for( TraceGeneratorVector::const_iterator 
		generator = _generators.begin(); 
		generator != _generators.end(); ++generator ) 
	{
		(*generator)->event(event);
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
	std::vector< ir::Parameter >::iterator it = parameters.begin();
	unsigned int paramSize = 0;

	for (; it != parameters.end(); ++it) {
		if (it->getElementSize() == 8 && (paramSize % 8)) {
			paramSize += 8 - (paramSize % 8);
		}
		else if (it->getElementSize() == 4 && (paramSize % 4)) {
			paramSize += 4 - (paramSize % 4);
		}
		it->offset = paramSize;
		paramSize += it->getSize();
	}

	return paramSize;
}

/*!
	\brief given a block of parameter memory, sets the values of each parameter
	\param parameter pointer to parameter memory
	\param paramSize number of bytes to write to parameter memory
*/
void ExecutableKernel::setParameterBlock(const unsigned char *parameter, size_t paramSize) {
	mapParameterOffsets();

	report("ExecutableKernel::setParameterBlock() - paramSize = " << paramSize);

	std::vector< ir::Parameter >::iterator it = parameters.begin();
	for (it = parameters.begin(); it != parameters.end(); ++it) {

		switch (it->type) {
			case ir::PTXOperand::b8:	// fall through
			case ir::PTXOperand::s8:	// fall through
			case ir::PTXOperand::s16:	// fall through
			case ir::PTXOperand::u8:	// fall through
			case ir::PTXOperand::u16: // fall through
			case ir::PTXOperand::f32: // fall through
			case ir::PTXOperand::s32:	// fall through
			case ir::PTXOperand::u32:	// fall through
			case ir::PTXOperand::s64:	// fall through
			case ir::PTXOperand::u64:
			{
				const unsigned char *ptr = parameter + it->offset;
				for (ir::Parameter::ValueVector::iterator val_it = it->arrayValues.begin();
					val_it != it->arrayValues.end(); ++val_it, ptr += it->getElementSize()) {

					memcpy(&val_it->val_u64, ptr, it->getElementSize());
				}
				break;
			}

			default:
			{
				throw hydrazine::Exception(std::string("Parameter type ") + 
					ir::PTXOperand::toString(it->type) + " not supported for kernel " + name);
			}
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
size_t ExecutableKernel::getParameterBlock(unsigned char *parameter, size_t maxSize) const {
	size_t offset = 0;
	std::vector< ir::Parameter >::const_iterator it = parameters.begin();
	for (it = parameters.begin(); it != parameters.end(); ++it) {
		report("Getting parameter " << it->name 
			<< " " 
			<< " - type: " << it->arrayValues.size() << " x " 
			<< ir::PTXOperand::toString(it->type)
			<< " - value: " << ir::Parameter::value(*it));

		switch (it->type) {
			case ir::PTXOperand::b8:	// fall through
			case ir::PTXOperand::s8:	// fall through
			case ir::PTXOperand::s16:	// fall through
			case ir::PTXOperand::u8:	// fall through
			case ir::PTXOperand::u16: // fall through
			case ir::PTXOperand::f32: // fall through
			case ir::PTXOperand::s32:	// fall through
			case ir::PTXOperand::u32:	// fall through
			case ir::PTXOperand::s64:	// fall through
			case ir::PTXOperand::u64:
			{
				unsigned char *ptr = parameter + it->offset;
				for (ir::Parameter::ValueVector::const_iterator val_it = it->arrayValues.begin();
					val_it != it->arrayValues.end(); ++val_it, ptr += it->getElementSize()) {
					
					memcpy(ptr, &val_it->val_u64, it->getElementSize());
				}
				break;
			}

			default:
			{
				throw hydrazine::Exception(std::string("Parameter type ") + 
					ir::PTXOperand::toString(it->type) + " not supported for kernel " + name);
			}
		}
		offset = it->offset + it->getElementSize();
	}
	return offset;
}

}

#endif
