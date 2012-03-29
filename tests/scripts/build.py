# \file build.py
#
# \author Andrew Kerr <arkerr@gatech.edu>
# \date December 13, 2011
#
# \brief Common elements of SConstruct files for GPU Ocelot regression tests
#

import SCons
import os
import sys
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
	
def InitializeEnvironment(env, builder):

	# get CUDA paths
	(cuda_exe_path, cuda_lib_path, cuda_inc_path)  = getCudaPaths()
	
	env.Append(CPPFLAGS=['-Wall', '-O2', '-g', '-I.', '-I' + cuda_inc_path, '-std=c++0x'])

	env.Replace(CUDA_PATHS=getCudaPaths())

	nvccPath = cuda_exe_path + ('/' if cuda_exe_path != '' else '')
	for shaderModel in ('10', '11', '12', '13', '20'):
		options = "-arch=sm_20 $OPTIONS"
		env.Append(BUILDERS = {'Cuda' + ('SM' + shaderModel if shaderModel != '20' else ''): builder(
			action = nvccPath + 'nvcc -I. -I' + cuda_inc_path + ' ' + options + ' $SOURCE -cuda -o $TARGET',
			suffix = '.cu.cpp',
			src_suffix = '.cu'
		)})
	return env

# 
# Applies build rules to CUDA sources
#
def MapSource(env, source, options=''):
	if len(source) > 8:
		suffix = source[-8:].lower()
		builder = {'_sm10.cu': env.CudaSM10, '_sm11.cu': env.CudaSM11, '_sm12.cu': env.CudaSM12, 
			'_sm13.cu': env.CudaSM13 }
		if suffix in builder.keys():
			return (builder[suffix])(source, OPTIONS=options)
	if source[-3:] == ".cu":
		return env.Cuda(source, OPTIONS=options)
	return source

