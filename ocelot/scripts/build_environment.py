EnsureSConsVersion(1,2)

import os

import inspect
import platform
import re
import subprocess
from SCons import SConf

def getDebianArchitecture():
	"""Determines the debian architecture
	
	return {deb_arch}
	"""

	# check for supported OS
	if os.name != 'posix':
		raise ValueError, 'Error: unknown OS.  Can only build .deb on linux.'
	
	try:
		dpkg_arch_path = which('dpkg-architecture')
	except:
		raise ValueError, "Failed to find 'dpkg-architecture' needed for .deb" \
			". Try installing dpkg-dev"

	# setup .deb environment variables
	arch = os.popen( \
		'dpkg-architecture -c \'echo $DEB_BUILD_ARCH\'').read().split()

	if len(arch) == 0:
		raise ValueError, 'Failed to get architecture from dpkg-architecture'

	return arch[0]

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

def getBoostPaths():
	"""Determines BOOST {bin,lib,include} paths
	
	returns (bin_path,lib_path,inc_path)
	"""

	# determine defaults
	if os.name == 'posix':
		bin_path = '/usr/bin'
		lib_path = '/usr/lib'
		inc_path = '/usr/include'
	else:
		raise ValueError, 'Error: unknown OS.  Where is boost installed?'

	# override with environement variables
	if 'BOOST_BIN_PATH' in os.environ:
		bin_path = os.path.abspath(os.environ['BOOST_BIN_PATH'])
	if 'BOOST_LIB_PATH' in os.environ:
		lib_path = os.path.abspath(os.environ['BOOST_LIB_PATH'])
	if 'BOOST_INC_PATH' in os.environ:
		inc_path = os.path.abspath(os.environ['BOOST_INC_PATH'])

	return (bin_path,lib_path,inc_path)

def getGLEWPaths(env):
	"""Determines GLEW {bin,lib,include} paths and is it installed?

	returns (have_glew,bin_path,lib_path,inc_path)
	"""

	configure = Configure(env)
	glew = configure.CheckLib('GLEW')		
		
	# determine defaults
	if os.name == 'posix':
		bin_path = '/usr/bin'
		lib_path = '/usr/lib'
		inc_path = '/usr/include'
	else:
		raise ValueError, 'Error: unknown OS.  Where is GLEW installed?'

	# override with environement variables
	if 'GLEW_BIN_PATH' in os.environ:
		bin_path = os.path.abspath(os.environ['GLEW_BIN_PATH'])
	if 'GLEW_LIB_PATH' in os.environ:
		lib_path = os.path.abspath(os.environ['GLEW_LIB_PATH'])
	if 'GLEW_INC_PATH' in os.environ:
		inc_path = os.path.abspath(os.environ['GLEW_INC_PATH'])

	return (glew,bin_path,lib_path,inc_path)

def getLLVMPaths(enabled):
	"""Determines LLVM {have,bin,lib,include,cflags,lflags,libs} paths
	
	returns (have,bin_path,lib_path,inc_path,cflags,lflags,libs)
	"""
	
	if not enabled:
		return (False, [], [], [], [], [], [])
	
	try:
		llvm_config_path = which('llvm-config')
	except:
		print 'Failed to find llvm-config'
		return (False, [], [], [], [], [], [])
	
	# determine defaults
	if os.name == 'posix':
		bin_path = os.popen('llvm-config --bindir').read().split()
		lib_path = os.popen('llvm-config --libdir').read().split()
		inc_path = os.popen('llvm-config --includedir').read().split()
		cflags   = os.popen('llvm-config --cppflags').read().split()
		lflags   = os.popen('llvm-config --ldflags').read().split()
		libs     = os.popen('llvm-config --libs core jit native \
			asmparser instcombine').read().split()
	else:
		raise ValueError, 'Error: unknown OS.  Where is LLVM installed?'
	
	# remove -DNDEBUG
	if '-DNDEBUG' in cflags:
		cflags.remove('-DNDEBUG')

	# remove lib_path from libs
	for lib in libs:
		if lib[0:2] == "-L":
			libs.remove(lib)

	return (True,bin_path,lib_path,inc_path,cflags,lflags,libs)
	
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

def getVersion(base):
	try:
		svn_path = which('svn')
	except:
		print 'Failed to get subversion revision'
		return base + '.0'

	process = subprocess.Popen('svn info ..', shell=True,
		stdout=subprocess.PIPE, stderr=subprocess.PIPE)

	(svn_info, std_err_data) = process.communicate()
	
	match = re.search('Last Changed Rev: ', svn_info)
	revision = 'unknown'
	if match:
		end = re.search('\n', svn_info[match.end():])
		if end:
			revision = svn_info[match.end():match.end()+end.start()]
	else:
		print 'Failed to get SVN repository version!'

	return base + '.' + revision

def defineConfigFlags(env):
	
	include_path = os.path.join(env['INSTALL_PATH'], "include")
	library_path = os.path.join(env['INSTALL_PATH'], "lib")
	bin_path     = os.path.join(env['INSTALL_PATH'], "bin")

	configFlags =  '-DOCELOT_CXXFLAGS="\\"' + env['CXXFLAGS'] + '\\""' \
		+ ' -DPACKAGE="\\"ocelot\\""' \
		+ ' -DVERSION="\\"' + env['VERSION'] + '\\""' \
		+ ' -DOCELOT_PREFIX_PATH="\\"' + env['INSTALL_PATH'] + '\\""' \
		+ ' -DOCELOT_LDFLAGS="\\"' + env['OCELOT_LDFLAGS'] + '\\""' \
		+ ' -DOCELOT_INCLUDE_PATH="\\"'+ include_path + '\\""' \
		+ ' -DOCELOT_LIB_PATH="\\"' + library_path + '\\""' \
		+ ' -DOCELOT_BIN_PATH="\\"' + bin_path + '\\""'

	env.Replace(OCELOT_CONFIG_FLAGS = configFlags)

def importEnvironment():
	env = {  }
	
	if 'PATH' in os.environ:
		env['PATH'] = os.environ['PATH']

	if 'LD_LIBRARY_PATH' in os.environ:
		env['LD_LIBRARY_PATH'] = os.environ['LD_LIBRARY_PATH']

	return env

def Environment():
	vars = Variables()

	# allow the user discretion to choose the MSVC version
	if os.name == 'nt':
		vars.Add(EnumVariable('MSVC_VERSION', 'MS Visual C++ version', \
			None, allowed_values=('8.0', '9.0', '10.0')))

	# add a variable to handle RELEASE/DEBUG mode
	vars.Add(EnumVariable('mode', 'Release versus debug mode', 'release',
		allowed_values = ('release', 'debug')))

	# add a variable to handle warnings
	vars.Add(BoolVariable('Wall', 'Enable all compilation warnings', 1))

	# add a variable to treat warnings as errors
	vars.Add(BoolVariable('Werror', 'Treat warnings as errors', 1))

	# add a variable to treat warnings as errors
	vars.Add(BoolVariable('enable_llvm', \
		'Compile in support for LLVM if available', 1))
	
	# add a variable to compile the ocelot unit tests
	vars.Add(EnumVariable('test_level', \
		'Build the ocelot unit tests at the given test level', 'none', \
		allowed_values = ('none', 'basic', 'full')))

	# add a variable to determine the install path
	vars.Add(PathVariable('install_path', 'The ocelot install path', \
		'/usr/local'))

	# create an Environment
	env = OldEnvironment(ENV = importEnvironment(), \
		tools = getTools(), variables = vars)

	# set the version
	env.Replace(VERSION = getVersion("2.1"))

	# get the absolute path to the directory containing
	# this source file
	thisFile = inspect.getabsfile(Environment)
	thisDir = os.path.dirname(thisFile)

	# get C compiler switches
	env.AppendUnique(CFLAGS = getCFLAGS(env['mode'], env['Wall'], \
		env['Werror'], env.subst('$CC')))

	# get CXX compiler switches
	env.AppendUnique(CXXFLAGS = getCXXFLAGS(env['mode'], env['Wall'], \
		env['Werror'], env.subst('$CXX')))

	# get linker switches
	env.AppendUnique(LINKFLAGS = getLINKFLAGS(env['mode'], env.subst('$LINK')))

	# get bison switches
	env.AppendUnique(YACCFLAGS = "-d")
	
	# Install paths
	if 'install' in COMMAND_LINE_TARGETS:
		env.Replace(INSTALL_PATH = os.path.abspath(env['install_path']))
	else:
		env.Replace(INSTALL_PATH = os.path.abspath('.'))

	# Set the debian architecture
	if 'debian' in COMMAND_LINE_TARGETS:
		env.Replace(deb_arch = getDebianArchitecture())
	else:
		env.Replace(deb_arch = 'unknown')
		
	# get CUDA paths
	(cuda_exe_path,cuda_lib_path,cuda_inc_path) = getCudaPaths()

	# get boost paths
	(boost_exe_path,boost_lib_path,boost_inc_path) = getBoostPaths()
	env.AppendUnique(LIBPATH = [boost_lib_path])
	env.AppendUnique(CPPPATH = [boost_inc_path])

	# get GLEW paths
	(glew,glew_exe_path,glew_lib_path,glew_inc_path) = getGLEWPaths(env)
	if glew:
		env.AppendUnique(LIBPATH = [glew_lib_path])
		env.AppendUnique(CPPPATH = [glew_inc_path])
	env.Replace(HAVE_GLEW = glew)

	# get llvm paths
	(llvm, llvm_exe_path,llvm_lib_path,llvm_inc_path,llvm_cflags,\
		llvm_lflags,llvm_libs) = getLLVMPaths(env['enable_llvm'])
	env.AppendUnique(LIBPATH = llvm_lib_path)
	env.AppendUnique(CPPPATH = llvm_inc_path)
	env.AppendUnique(CXXFLAGS = llvm_cflags)
	env.AppendUnique(LINKFLAGS = llvm_lflags)
	env.Replace(HAVE_LLVM = llvm)
	env.Replace(LLVM_LIBS = llvm_libs)

	# set ocelot include path
	env.Prepend(CPPPATH = os.path.dirname(thisDir))
	env.AppendUnique(LIBPATH = os.path.abspath('.'))
	
	# set extra libs 
	env.Replace(EXTRA_LIBS=['-lboost_system-mt', '-lboost_filesystem-mt', \
		'-lboost_thread-mt'])
	if glew:
		env.AppendUnique(EXTRA_LIBS = ['-lGLEW'])
	
	# we need libdl on linux
	if os.name == 'posix':
		env.AppendUnique(EXTRA_LIBS = ['-ldl']) 
	
	# set ocelot libs
	ocelot_libs = '-locelot'
	env.Replace(OCELOT_LDFLAGS=ocelot_libs)
	
	# include the build directory in case of generated files
	env.Prepend(CPPPATH = env.Dir('.'))

	# generate OcelotConfig flags
	defineConfigFlags(env)

	# generate help text
	Help(vars.GenerateHelpText(env))

	return env

