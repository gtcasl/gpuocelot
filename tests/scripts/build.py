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
	
def InitializeEnvironment(env, builder, paths = ['-I./sdk',]):

	# get CUDA paths
	(cuda_exe_path, cuda_lib_path, cuda_inc_path)  = getCudaPaths()
	
	print "cuda_inc_path = ", cuda_inc_path
	
	env.Append(CPPFLAGS=['-Wall', '-O2', '-I.', '-I' + cuda_inc_path, '-std=c++0x'] + paths)
	
	# CUDA builder
	nvccPath = cuda_exe_path + ('/' if cuda_exe_path != '' else '')
	env.Append(BUILDERS = {'Cuda': builder(
		action= nvccPath + 'nvcc -I' + cuda_inc_path + ' -I./sdk -arch=sm_20 $SOURCE -c -o $TARGET',
		suffix = '.o',
		src_suffix = '.cu'
	)})
	env.Append(BUILDERS = {'CudaSM10': builder(
		action= nvccPath + 'nvcc -I' + cuda_inc_path + ' -I./sdk -arch=compute_10 -code=sm_20 $SOURCE -c -o $TARGET',
		suffix = '.o',
		src_suffix = '.cu'
	)})
	env.Append(BUILDERS = {'CudaSM11': builder(
		action= nvccPath + 'nvcc -I' + cuda_inc_path + ' -I./sdk -arch=compute_11 -code=sm_20 $SOURCE -c -o $TARGET',
		suffix = '.o',
		src_suffix = '.cu'
	)})
	env.Append(BUILDERS = {'CudaSM12': builder(
		action= nvccPath + 'nvcc -I' + cuda_inc_path + ' -I./sdk -arch=compute_12 -code=sm_20 $SOURCE -c -o $TARGET',
		suffix = '.o',
		src_suffix = '.cu'
	)})
	env.Append(BUILDERS = {'CudaSM13': builder(
		action= nvccPath + 'nvcc -I' + cuda_inc_path + ' -I./sdk -arch=compute_13 -code=sm_20 $SOURCE -c -o $TARGET',
		suffix = '.o',
		src_suffix = '.cu'
	)})
	return env

# 
# Applies build rules to CUDA sources
#
def MapSource(env, source):
	if len(source) > 8 and source[-8:].lower() == '_sm10.cu':
		return env.CudaSM10(source)
	if len(source) > 8 and source[-8:].lower() == '_sm11.cu':
		return env.CudaSM11(source)
	if len(source) > 8 and source[-8:].lower() == '_sm12.cu':
		return env.CudaSM12(source)
	if len(source) > 8 and source[-8:].lower() == '_sm13.cu':
		return env.CudaSM13(source)
	if source[-3:] == ".cu":
		return env.Cuda(source)
	return source

