EnsureSConsVersion(1,2)

import os

import inspect
import platform

def getCudaPaths():
	"""Determines CUDA {bin,lib,include} paths
	
	returns (bin_path,lib_path,inc_path)
	"""

	# determine defaults
	if os.name == 'nt':
		bin_path = 'C:/CUDA/bin'
		lib_path = 'C:/CUDA/lib'
		inc_path = 'C:/CUDA/include'
	elif os.name == 'posix':
		bin_path = '/usr/local/cuda/bin'
		lib_path = '/usr/local/cuda/lib'
		inc_path = '/usr/local/cuda/include'
	else:
		raise ValueError, 'Error: unknown OS.  Where is nvcc installed?'
	 
	if platform.machine()[-2:] == '64':
		lib_path += '64'

	# override with environement variables
	if 'CUDA_BIN_PATH' in os.environ:
		bin_path = os.path.abspath(os.environ['CUDA_BIN_PATH'])
	if 'CUDA_LIB_PATH' in os.environ:
		lib_path = os.path.abspath(os.environ['CUDA_LIB_PATH'])
	if 'CUDA_INC_PATH' in os.environ:
		inc_path = os.path.abspath(os.environ['CUDA_INC_PATH'])

	return (bin_path,lib_path,inc_path)

def getLLVMPaths():
	"""Determines LLVM {bin,lib,include} paths
	
	returns (bin_path,lib_path,inc_path)
	"""
	
	llvm_config_path = which.which('llvm-config')
	
	# determine defaults
	if os.name == 'posix':
		if os.path.isfile(llvm_config_path):
			bin_path = os.popen('llvm-config --bindir').read().split()
			lib_path = os.popen('llvm-config --libdir').read().split()
			inc_path = os.popen('llvm-config --includedir').read().split()
		else:
			bin_path = '/usr/local/bin'
			lib_path = '/usr/local/lib'
			inc_path = '/usr/local/include/llvm'
	else:
		raise ValueError, 'Error: unknown OS.  Where is LLVM installed?'
	
	return (bin_path,lib_path,inc_path)

def getTools():
	result = []
	if os.name == 'nt':
		result = ['default', 'msvc']
	elif os.name == 'posix':
		result = ['default', 'gcc']
	else:
		result = ['default']
	return result;


OldEnvironment = Environment;


# this dictionary maps the name of a compiler program to a dictionary mapping the name of
# a compiler switch of interest to the specific switch implementing the feature
gCompilerOptions = {
		'gcc' : {'warn_all' : '-Wall', 'warn_errors' : '-Werror', 'optimization' : '-O2', 'debug' : '-g',  'exception_handling' : '', 'standard': ''},
		'g++' : {'warn_all' : '-Wall', 'warn_errors' : '-Werror', 'optimization' : '-O2', 'debug' : '-g',  'exception_handling' : '', 'standard': '-std=c++0x'},
		'cl'  : {'warn_all' : '/Wall', 'warn_errors' : '/WX',     'optimization' : '/Ox', 'debug' : ['/Zi', '-D_DEBUG', '/MTd'], 'exception_handling' : '/EHsc', 'standard': ''}
	}


# this dictionary maps the name of a linker program to a dictionary mapping the name of
# a linker switch of interest to the specific switch implementing the feature
gLinkerOptions = {
		'gcc' : {'debug' : ''},
		'g++' : {'debug' : ''},
		'link'  : {'debug' : '/debug'}
	}


def getCFLAGS(mode, warn, warnings_as_errors, CC):
	result = []
	if mode == 'release':
		# turn on optimization
		result.append(gCompilerOptions[CC]['optimization'])
	elif mode == 'debug':
		# turn on debug mode
		result.append(gCompilerOptions[CC]['debug'])
		result.append('-DOCELOT_DEBUG')

	if warn:
		# turn on all warnings
		result.append(gCompilerOptions[CC]['warn_all'])

	if warnings_as_errors:
		# treat warnings as errors
		result.append(gCompilerOptions[CC]['warn_errors'])

	result.append(gCompilerOptions[CC]['standard'])

	return result


def getCXXFLAGS(mode, warn, warnings_as_errors, CXX):
	result = []
	if mode == 'release':
		# turn on optimization
		result.append(gCompilerOptions[CXX]['optimization'])
	elif mode == 'debug':
		# turn on debug mode
		result.append(gCompilerOptions[CXX]['debug'])
	# enable exception handling
	result.append(gCompilerOptions[CXX]['exception_handling'])

	if warn:
		# turn on all warnings
		result.append(gCompilerOptions[CXX]['warn_all'])

	if warnings_as_errors:
		# treat warnings as errors
		result.append(gCompilerOptions[CXX]['warn_errors'])

	result.append(gCompilerOptions[CXX]['standard'])

	return result

def getLINKFLAGS(mode, LINK):
	result = []
	if mode == 'debug':
		# turn on debug mode
		result.append(gLinkerOptions[LINK]['debug'])

	return result


def Environment():
	# allow the user discretion to choose the MSVC version
	vars = Variables()
	if os.name == 'nt':
		vars.Add(EnumVariable('MSVC_VERSION', 'MS Visual C++ version', None, allowed_values=('8.0', '9.0', '10.0')))

	# add a variable to handle RELEASE/DEBUG mode
	vars.Add(EnumVariable('mode', 'Release versus debug mode', 'release',
		allowed_values = ('release', 'debug')))

	# add a variable to handle warnings
	if os.name == 'posix':
		vars.Add(BoolVariable('Wall', 'Enable all compilation warnings', 1))
	else:
		vars.Add(BoolVariable('Wall', 'Enable all compilation warnings', 0))

	# add a variable to treat warnings as errors
	vars.Add(BoolVariable('Werror', 'Treat warnings as errors', 0))

	# create an Environment
	env = OldEnvironment(tools = getTools(), variables = vars)

	# get the absolute path to the directory containing
	# this source file
	thisFile = inspect.getabsfile(Environment)
	thisDir = os.path.dirname(thisFile)

	# get C compiler switches
	env.Append(CFLAGS = getCFLAGS(env['mode'], env['Wall'], env['Werror'], env.subst('$CC')))

	# get CXX compiler switches
	env.Append(CXXFLAGS = getCXXFLAGS(env['mode'], env['Wall'], env['Werror'], env.subst('$CXX')))

	# get linker switches
	env.Append(LINKFLAGS = getLINKFLAGS(env['mode'], env.subst('$LINK')))
	 
	# get CUDA paths
	(cuda_exe_path,cuda_lib_path,cuda_inc_path) = getCudaPaths()
	env.Append(LIBPATH = [cuda_lib_path])
	env.Append(CPPPATH = [cuda_inc_path])

	# set ocelot include path
	env.Prepend(CPPPATH = os.path.dirname(thisDir))

	# import the LD_LIBRARY_PATH so we can run commands which depend
	# on shared libraries
	# XXX we should probably just copy the entire environment
	if os.name == 'posix':
		if env['PLATFORM'] == "darwin":
			env['ENV']['DYLD_LIBRARY_PATH'] = os.environ['DYLD_LIBRARY_PATH']
		else:
			env['ENV']['LD_LIBRARY_PATH'] = os.environ['LD_LIBRARY_PATH']

	# generate help text
	Help(vars.GenerateHelpText(env))

	return env

