/*!
	\file ExecutableKernel.cpp
	\author Andrew Kerr <arkerr@gatech.edu>
	\brief implementation of the ExecutableKernel class
*/

// Hydrazine includes
#include <hydrazine/implementation/debug.h>
#include <hydrazine/implementation/Exception.h>

// Ocelot includes
#include <ocelot/ir/interface/PTXOperand.h>
#include <ocelot/ir/interface/ExecutableKernel.h>

//////////////////////////////////////////////////////////////////////////////////////////////////

// Debugging messages
#ifdef REPORT_BASE
#undef REPORT_BASE
#endif

#define REPORT_BASE 0

//////////////////////////////////////////////////////////////////////////////////////////////////

ir::ExecutableKernel::~ExecutableKernel() {

}

//////////////////////////////////////////////////////////////////////////////////////////////////

//! maps parameters to offsets in the block of parameter memory
size_t ir::ExecutableKernel::mapParameters() {
	ParameterVector::iterator it = parameters.begin();
	size_t paramSize = 0;
	for (; it != parameters.end(); ++it) {
		if (it->getElementSize() == 8 && (paramSize % 8)) {
			paramSize += 8 - (paramSize % 8);
		}
		it->offset = paramSize;
		paramSize += it->getSize();
	}
	return paramSize;
}

/*! 
	sets parameter values from a block of parameter data
*/
void ir::ExecutableKernel::setParameterBlock(const void *param, size_t size) {
	ParameterVector::iterator it = parameters.begin();
	for (; it != parameters.end(); ++it) {
		report("Configuring parameter " << it->name 
			<< " " 
			<< " - type: " << it->arrayValues.size() << " x " 
			<< ir::PTXOperand::toString(it->type)
			<< " - value: " << ir::Parameter::value(*it));

		const ir::PTXU8 *ptr = static_cast<const ir::PTXU8 *>(param) + it->offset;
		
		switch (it->type) {
			case ir::PTXOperand::b8:	// fall through
			case ir::PTXOperand::s8:	// fall through
			case ir::PTXOperand::s16:	// fall through
			case ir::PTXOperand::u8:	// fall through
			case ir::PTXOperand::u16:
			{
				for (size_t i = 0; i < it->arrayValues.size(); i++) {
					switch (it->getElementSize()) {
						case 2:
							it->arrayValues[i].val_u16 = 
								*reinterpret_cast<const unsigned short *>(ptr[i*it->getElementSize()]);
							break;
						case 1:
							it->arrayValues[i].val_u8 = ptr[i*it->getElementSize()];
							break;
						default:
						{
							report("*** Unsupported parameter size");
							throw hydrazine::Exception("unsupported parameter size");
						}
					}
				}
				break;
			}

			case ir::PTXOperand::s32:	// fall through
			case ir::PTXOperand::u32:	// fall through
			case ir::PTXOperand::f32:
			{
				const unsigned int *uint_ptr = reinterpret_cast<const unsigned int*>(ptr);
				for (ir::Parameter::ValueVector::iterator val_it = it->arrayValues.begin();
					val_it != it->arrayValues.end(); ++val_it) {
					val_it->val_u32 = *uint_ptr;
					uint_ptr ++;
				}
			}

			case ir::PTXOperand::s64:	// fall through
			case ir::PTXOperand::u64:	// fall through
			case ir::PTXOperand::f64:
			{
				const unsigned long *uint_ptr = reinterpret_cast<const unsigned long*>(ptr);
				for (ir::Parameter::ValueVector::iterator val_it = it->arrayValues.begin();
					val_it != it->arrayValues.end(); ++val_it) {
					val_it->val_u64 = *uint_ptr;
					uint_ptr ++;
				}			
			}

			default:
			{
				throw hydrazine::Exception(std::string("Parameter type ") + 
					ir::PTXOperand::toString(it->type) + " not supported for kernel " + name);
			}
		}
	}
}

//! gets a dense representation of parameter memory given current values of parameters
void ir::ExecutableKernel::getParameterBlock(void *param, size_t size) const {
	ParameterVector::const_iterator it = parameters.begin();
	for (; it != parameters.end(); ++it) {
		report("Configuring parameter " << it->name 
			<< " " 
			<< " - type: " << it->arrayValues.size() << " x " 
			<< ir::PTXOperand::toString(it->type)
			<< " - value: " << ir::Parameter::value(*it));

		ir::PTXU8 *ptr = reinterpret_cast<ir::PTXU8 *>(param) + it->offset;
		
		switch (it->type) {
			case ir::PTXOperand::b8:	// fall through
			case ir::PTXOperand::s8:	// fall through
			case ir::PTXOperand::u8:	// fall through
			case ir::PTXOperand::s16:	// fall through
			case ir::PTXOperand::b16: // fall through
			case ir::PTXOperand::u16:
			{
				for (size_t i = 0; i < it->arrayValues.size(); i++) {
					switch (it->getElementSize()) {
						case 2:
							ptr[i*it->getElementSize()+1] = (it->arrayValues[i].val_u16 >> 8);
						case 1:
							ptr[i*it->getElementSize()] = it->arrayValues[i].val_u8;
							break;
						default:
						{
							report("*** Unsupported parameter size");
							throw hydrazine::Exception("unsupported parameter size");
						}
					}
				}
				break;
			}

			case ir::PTXOperand::s32:	// fall through
			case ir::PTXOperand::u32:	// fall through
			case ir::PTXOperand::b32: // fall through
			case ir::PTXOperand::f32:
			{
				PTXU32 *uint_ptr = reinterpret_cast<PTXU32 *>(ptr);
				for (ir::Parameter::ValueVector::const_iterator val_it = it->arrayValues.begin();
					val_it != it->arrayValues.end(); ++val_it) {
					*uint_ptr = val_it->val_u32;
					uint_ptr ++;
				}
			}

			case ir::PTXOperand::s64:	// fall through
			case ir::PTXOperand::u64:	// fall through
			case ir::PTXOperand::b64: // fall through
			case ir::PTXOperand::f64:
			{
				ir::PTXU64 *uint_ptr = reinterpret_cast<PTXU64*>(ptr);
				for (ir::Parameter::ValueVector::const_iterator val_it = it->arrayValues.begin();
					val_it != it->arrayValues.end(); ++val_it) {
					*uint_ptr = val_it->val_u64;
					uint_ptr ++;
				}			
			}

			default:
			{
				throw hydrazine::Exception(std::string("Parameter type ") + 
					ir::PTXOperand::toString(it->type) + " not supported for kernel " + name);
			}
		}
	}
}


