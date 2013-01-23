// C standard library includes

// C++ standard library includes

// Ocelot includes
#include <ocelot/opencl/interface/Program.h>

#undef REPORT_BASE
#define REPORT_BASE 0

unsigned int opencl::Program::_id = 0;


std::string opencl::Program::_loadBackDoor() {

	//Temorarily load ptx file as built binary
	std::cerr << "Ocelot-OpenCL: using backdoor PTX now...\n";
	std::ifstream binary("buildout.ptx"); 
	if(binary.fail()) {
		assertM(false, "using build backdoor but buildout.ptx not found");
		throw CL_BUILD_PROGRAM_FAILURE;
	}
	

	//Get file size
	binary.seekg(0, std::ios::end);
	size_t size = binary.tellg();
	binary.seekg(0, std::ios::beg);
	
	if(!size) {
		assertM(false, "buildout.ptx is empty!");
		throw CL_BUILD_PROGRAM_FAILURE;
	}

	//Read file to temporary buffer	
	std::string temp;
	temp.resize(size);
	binary.read((char*)temp.data(), size);

	return temp;

}

/// _compileToBinary (modifed by <pwh@gatech.edu> 02-Oct-12
///
/// I've rewritten the file read to string logic to make it more concise.
/// I've changed some OUT_OF_MEMORY conditions to generic FAILURE because
/// C++ stream fail() can mean lots of things (e.g. permission failure, etc.).
/// Simplified some string operations using + and constructor parameters.
/// Added using statements for concision.
/// Changed c_str() to data() to be consistent throughout. This assumes
/// C++11 (re)definition of data().
/// Eliminated error-prone NEWLINE escapes in compileCommand definition.

// Seems to use strange names like "__clmodule_##".
std::string opencl::Program::_compileToBinary()
{
	std::string clName (_name + ".cl");
	std::string ptxName(_name + ".ptx"); 
	
	// Write CL to tmp file
	// Need to check fail() after every op if you want to be consistent
	// (Silly, isn't it?)
	std::ofstream clFile(clName.data());
	if (clFile.fail()) throw CL_BUILD_PROGRAM_FAILURE;
	clFile << _source;
	if (clFile.fail()) throw CL_BUILD_PROGRAM_FAILURE;
	clFile.close();
	if (clFile.fail()) throw CL_BUILD_PROGRAM_FAILURE;
	
	  // Compile cl to ptx
	// Eliminated NEWLINE escapes, relying instead on implicit concatenation
	std::string compileCommand("clang -ccc-host-triple nvptx64--nvidiacl "
	 "-Xclang -mlink-bitcode-file "
	 "-Xclang $HOME/libclc/nvptx64--nvidiacl/lib/builtins.bc "
	 "-I$HOME/libclc/generic/include -I$HOME/libclc/ptx-nvidiacl/include "
	 "-include clc/clc.h -Dcl_clang_storage_class_specifiers "
	 "-Dcl_khr_fp64 -O3 " + clName + " -S -o " + ptxName);
	report(compileCommand);
	int result = system(compileCommand.data());
	if (result) throw CL_BUILD_PROGRAM_FAILURE;
	
	/// Read in PTX and return as string (concisely)
	std::ifstream ifs(ptxName.data());
	if (ifs.fail()) throw CL_BUILD_PROGRAM_FAILURE;
	std::stringstream ss;
	ss << ifs.rdbuf();
	if (ss.fail())  throw CL_BUILD_PROGRAM_FAILURE;
	return ss.str();
}

bool opencl::Program::_isBuiltOnDevice(Device * device) {
	
	if(_deviceBuiltInfo.find(device) == _deviceBuiltInfo.end())
		return false;

	if(_deviceBuiltInfo[device]._status == STATUS_EXECUTABLE)
		return true;

	return false;
}

bool opencl::Program::_isAllBuilt() {

	for(std::map<Device *, deviceBuiltInfoT>::iterator it = _deviceBuiltInfo.begin();
		it != _deviceBuiltInfo.end(); it++) {

		if(it->second._status != STATUS_EXECUTABLE)
			return false;
	}

	return true;

}

bool opencl::Program::_hasModuleOnDevice(Device * device, std::string moduleName) {
	if(_deviceBuiltInfo.find(device) == _deviceBuiltInfo.end())
		return false;

	if(_deviceBuiltInfo[device]._moduleName == moduleName)
		return true;

	return false;
}

bool opencl::Program::_hasBinaryOnDevice(Device * device) {
	if(_deviceBuiltInfo.find(device) == _deviceBuiltInfo.end())
		return false;

	if(_deviceBuiltInfo[device]._binary.empty())
		return false;

	return true;
}

void opencl::Program::_loadBinaryOnDevice(Device * device, const size_t length, 
	const char * binary) {

	report("load binary on device " << device);
	std::stringstream binaryStr;
	binaryStr.write(binary, std::min(length, strlen(binary)));
	_deviceBuiltInfo[device]._binary = std::move(binaryStr.str());
}

void opencl::Program::_buildOnDevice(Device * device, std::string binary) {

	std::stringstream moduleName;
	moduleName << _name;
	report("Loading module (ptx) - " << moduleName.str());

	try {

		if(!_hasModuleOnDevice(device, moduleName.str())) {

			_deviceBuiltInfo[device]._moduleName = moduleName.str();
			_deviceBuiltInfo[device]._module = new ir::Module();
		}

		if(_deviceBuiltInfo[device]._binary.empty()) {
			assert(!binary.empty());
			_deviceBuiltInfo[device]._binary = binary;
		}

		std::string binaries = _deviceBuiltInfo[device]._binary;
		_deviceBuiltInfo[device]._module->lazyLoad(binaries,
			moduleName.str());

		device->load(_deviceBuiltInfo[device]._module);
				
		_deviceBuiltInfo[device]._status = STATUS_EXECUTABLE;
	}
	catch(...) {
		throw CL_BUILD_PROGRAM_FAILURE;
	}

}

char * opencl::Program::_getBinarySizes(size_t & bufferLen) {

	char * sizes;
	size_t entries;

	if(_type == PROGRAM_SOURCE) {
		Device::DeviceList & validDevices = _context->getValidDevices();
		entries = validDevices.size();
		report("Find " << entries << " binary entries.");
		sizes = new char[entries * sizeof(size_t)];
	
		size_t i = 0;
		for(Device::DeviceList::iterator device = validDevices.begin();
				device != validDevices.end(); device++) {
		
			if(_deviceBuiltInfo.find(*device) != _deviceBuiltInfo.end()) {
				report("Find device " << *device);
				((size_t *)sizes)[i] = _deviceBuiltInfo[*device]._binary.size();
				report("binary size " << ((size_t *)sizes)[i]);
			}
			else
				((size_t *)sizes)[i] = 0;
			i++;
		}
		bufferLen = entries * sizeof(size_t);
		return sizes;
	}

	else { //binary

		entries = _deviceBuiltInfo.size();
		sizes = new char[entries * sizeof(size_t)];

		size_t i = 0;
		for(std::map <Device *, deviceBuiltInfoT> ::iterator it = _deviceBuiltInfo.begin();
			it != _deviceBuiltInfo.end(); it++) {
			((size_t *)sizes)[i] = it->second._binary.size();
			i++;
		}
		bufferLen = entries * sizeof(size_t);
		return sizes;
	}
}

char * opencl::Program::_getBinaries(size_t & bufferLen) {

	char * binaries;
	size_t entries;

	if(_type == PROGRAM_SOURCE) {
		Device::DeviceList & validDevices = _context->getValidDevices();
		entries = validDevices.size();
		binaries = new char[entries * sizeof(unsigned char *)];
	
		size_t i = 0;
		for(Device::DeviceList::iterator device = validDevices.begin();
				device != validDevices.end(); device++) {
		
			if(_deviceBuiltInfo.find(*device) != _deviceBuiltInfo.end())
				((const char **)binaries)[i] = _deviceBuiltInfo[*device]._binary.c_str();
			else
				((const char **)binaries)[i] = NULL;
			i++;
		}
		bufferLen = entries * sizeof(unsigned char *);
		return binaries;
	}

	else { //binary

		entries = _deviceBuiltInfo.size();
		binaries = new char [entries * sizeof(unsigned char *)];

		size_t i = 0;
		for(std::map <Device *, deviceBuiltInfoT> ::iterator it = _deviceBuiltInfo.begin();
			it != _deviceBuiltInfo.end(); it++) {
			((const char **)binaries)[i] = it->second._binary.c_str();
			i++;
		}
		bufferLen = entries * sizeof(unsigned char *);
		return binaries;
	}
}

bool opencl::Program::_hasKernelAll(const char * kernelName) {

	for(std::map < Device *, deviceBuiltInfoT>::iterator it = _deviceBuiltInfo.begin();
		it != _deviceBuiltInfo.end(); it++) {

		if(it->second._module->getKernel(kernelName) == 0) { //kernel not found
			return false;
		}
	}

	return true;

}

opencl::Program::Program(Context * context, cl_uint count, const char ** strings, 
	const size_t * lengths, programT type):
	Object(OBJTYPE_PROGRAM), 
	_type(type), _context(context) {

	//program name = __clmodule_id
	std::stringstream name;
	name << "__clmodule_" << _id;
	_name = std::move(name.str());
	_id++;

	//put all sources together
	std::stringstream sources;
	for(cl_uint i = 0; i < count; i++) {

		if(strings[i] == 0)
			throw CL_INVALID_VALUE;

		if(lengths == 0 || lengths[i] == 0)
			sources << strings[i];
		else
			sources.write(strings[i], std::min(lengths[i], strlen(strings[i])));

		_source = std::move(sources.str());

	}

	_context->retain();
}

opencl::Program::Program(Context * context, 
	cl_uint num_devices, 
	const cl_device_id * device_list,
	const size_t * lengths, 
	const unsigned char ** binaries, 
	cl_int * binary_status, 
	programT type):
	Object(OBJTYPE_PROGRAM), 
	_type(type), _context(context) {

	//program name = __clmodule_id
	std::stringstream name;
	name << "__clmodule_" << _id;
	_name = std::move(name.str());
	_id++;

	//setup devices
	if(!setupDevices(num_devices, device_list))
		throw CL_INVALID_DEVICE;

	//copy binary
	for(cl_uint i = 0; i < num_devices; i++) {
		if(lengths[i] == 0 || binaries[i] == 0) {
			if(binary_status)
				binary_status[i] = CL_INVALID_VALUE;
			throw CL_INVALID_VALUE;
		}
		_loadBinaryOnDevice((Device *)(device_list[i]), lengths[i], (const char *)binaries[i]);
		if(binary_status)
			binary_status[i] = CL_SUCCESS;
	}

	_context->retain();
}

opencl::Program::Program(Context * context, 
                cl_uint num_devices,
                const cl_device_id * device_list,
                const char * kernel_names):
	Object(OBJTYPE_PROGRAM), 
	_type(PROGRAM_BUILTIN), _context(context) {

	//program name = __clmodule_id
	std::stringstream name;
	name << "__clmodule_" << _id;
	_name = std::move(name.str());
	_id++;

	//setup devices
	if(!setupDevices(num_devices, device_list))
		throw CL_INVALID_DEVICE;

	report("Current impelmentation does not support built-in kernels\n");
	throw(CL_UNIMPLEMENTED);

	_context->retain();
}

opencl::Program::~Program() {
	
	report("Delete Program object");

}

void opencl::Program::release() {
	if(Object::release()) {
	
		for(std::map <Device *, deviceBuiltInfoT>::iterator it = _deviceBuiltInfo.begin();
			it != _deviceBuiltInfo.end(); it++) {
			report("Delete Program module");
			delete it->second._module;
		}

		_context->release();
		delete this;
	}
}

bool opencl::Program::isValidContext(Context * context) {
	return (_context == context);
}

opencl::Context * opencl::Program::getContext() {
	return _context;
}

bool opencl::Program::setupDevices(cl_uint num_devices, const cl_device_id * device_list) {

	_buildDevices.clear();

	if(num_devices == 0) { //build on all devices
		_buildDevices = _context->getValidDevices();
		return true;
	}

	for(cl_uint i = 0; i < num_devices; i++) {
		if(!_context->isValidDevice((Device *)device_list[i])) {//Not found
			_buildDevices.clear();
			return false;
		}
		_buildDevices.push_back((Device *)device_list[i]);

	}

	return true;
}

void opencl::Program::build(const char * options,
		void (CL_CALLBACK * pfn_notify)(cl_program, void *),
		void * user_data) {

	if(!_kernels.empty())
		throw CL_INVALID_OPERATION;

	assert(!_buildDevices.empty());

	if(_type == PROGRAM_SOURCE) {//source code
		
		// Load backdoor ptx
//		std::string binary = _loadBackDoor();	
		std::string binary = _compileToBinary();	

		for(Device::DeviceList::iterator d = _buildDevices.begin(); d != _buildDevices.end(); d++) {

			if(!_isBuiltOnDevice(*d)) {
				_buildOnDevice(*d, binary);
			}
		}
	}
	else { //binary code
		
		for(Device::DeviceList::iterator d = _buildDevices.begin(); d != _buildDevices.end(); d++) {

			if(_hasBinaryOnDevice(*d)) //binary not availble for device
				throw CL_INVALID_BINARY;

			if(!_isBuiltOnDevice(*d)) {
				_buildOnDevice(*d);
			}
		}
	}
}


void opencl::Program::getInfo(cl_program_info param_name,
	size_t param_value_size,
	void * param_value,
	size_t * param_value_size_ret) {

	union infoUnion {
		cl_uint uint;
		cl_context context;
		size_t size;
	};

	infoUnion info;
	char * ptr = (char *)&info;
	size_t infoLen = 0;
	bool isMalloc = false;

	switch(param_name) {
		case CL_PROGRAM_BINARY_SIZES: 
			ptr = _getBinarySizes(infoLen);
			isMalloc = true;
			break;

		case CL_PROGRAM_BINARIES:
			ptr = _getBinaries(infoLen);
			isMalloc = true;
			break;
		
		default:
			assertM(false, "unsupported program info");
			throw CL_UNIMPLEMENTED;
			break;
	}
	
	if(param_value_size < infoLen)
		throw CL_INVALID_VALUE;

	if(param_value)
		std::memcpy(param_value, ptr, infoLen);

	if(param_value_size_ret)
		*param_value_size_ret = infoLen;

	if(isMalloc)
		delete[] ptr;
}

opencl::Kernel * opencl::Program::createKernel(const char * kernelName) {
	if(!_isAllBuilt())
		throw CL_INVALID_PROGRAM_EXECUTABLE;

	if(!kernelName)
		throw CL_INVALID_VALUE;

	if(!_hasKernelAll(kernelName))
		throw CL_INVALID_KERNEL_NAME;

	report("Registered kernel - " << kernelName
		<< " in program '" << _name << "'");

	Kernel * kernel = NULL;
	kernel = new Kernel(kernelName, this);
	_kernels.push_back(kernel);

	//add device info to kernel
	for(std::map < Device *, deviceBuiltInfoT>::iterator it = _deviceBuiltInfo.begin();
		it != _deviceBuiltInfo.end(); it++) {

		ir::Kernel * irKernel = it->second._module->getKernel(kernelName);

		kernel->addDeviceInfo(it->first, it->second._moduleName, it->second._module, irKernel);
	}

	return kernel;

}

void opencl::Program::createAllKernels(cl_uint num_kernels, 
		cl_kernel * kernels, 
		cl_uint * num_kernels_ret) {
	if(!_isAllBuilt())
		throw CL_INVALID_PROGRAM_EXECUTABLE;

	const ir::Module::KernelMap &irKernels = _deviceBuiltInfo.begin()->second._module->kernels();
	const cl_uint kernelCount = irKernels.size();

	if(kernels != NULL && num_kernels < kernelCount)
		throw CL_INVALID_VALUE;

	report("Register all kernels in program '" << _name << "'");

	cl_uint i = 0;
	for(ir::Module::KernelMap::const_iterator it = irKernels.begin(); it != irKernels.end(); it++) {
		std::string kernelName = it->first;
		if(!_hasKernelAll(kernelName.c_str()))
			throw CL_INVALID_PROGRAM_EXECUTABLE;
		Kernel * kernel = new Kernel(kernelName, this);
		_kernels.push_back(kernel);

		for(std::map < Device *, deviceBuiltInfoT>::iterator dIt = _deviceBuiltInfo.begin();
			dIt != _deviceBuiltInfo.end(); dIt++) {
			ir::Kernel * irKernel = dIt->second._module->getKernel(kernelName);
			kernel->addDeviceInfo(dIt->first, dIt->second._moduleName, dIt->second._module, irKernel);
		}
		kernels[i++] = (cl_kernel)kernel;
	}

	if(num_kernels_ret)
		*num_kernels_ret = kernelCount;
}

void opencl::Program::removeKernel(Kernel * kernel) {
	KernelList::iterator it = std::find(_kernels.begin(), _kernels.end(), kernel);
	assert(it != _kernels.end());
	_kernels.erase(it);
}
