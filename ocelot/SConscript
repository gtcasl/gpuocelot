#! /bin/python

################################################################################
#	\file   SConscript
#	\author Gregory Diamos <gregory.diamos@gatech.edu>
#   \date   Tuesday March 8, 2011
#	\brief  The SCons master build script for Ocelot
################################################################################

import os
import inspect

## Hepler functions
def config_h_build(target, source, env):

	config_h_defines = env.Dictionary()

	for a_target, a_source in zip(target, source):
		config_h = file(str(a_target), "w")
		config_h_in = file(str(a_source), "r")
		config_h.write(config_h_in.read() % config_h_defines)
		config_h_in.close()
		config_h.close()


## The script begins here
# try to import an environment first
try:
	Import('env')
except:
	try:
		exec open("../scripts/which.py")
		prefix = '../'
	except:
		exec open("scripts/which.py")
		prefix = './'
	exec open(prefix + "scripts/build_environment.py")
	env = Environment()
  
# on mac we have to tell the linker to link against the C++ library
if env['PLATFORM'] == "darwin":
	env.Append(LINKFLAGS = "-lstdc++")

# Create configure.h
env.AlwaysBuild(env.Command('configure.h', 'configure.h.in', config_h_build))

# find all source files in the source tree
sources = []
intermediate_headers = []
directories = ['ocelot/ir/implementation', 
	'ocelot/analysis/implementation',
	'ocelot/api/implementation',
	'ocelot/cal/implementation',
	'ocelot/cuda/implementation',
	'ocelot/executive/implementation',
	'ocelot/graphs/implementation',
	'ocelot/parser/implementation',
	'ocelot/trace/implementation',
	'ocelot/transforms/implementation',
	'ocelot/translator/implementation', 
	'ocelot/util/implementation', 
	'hydrazine/implementation', 
	'hydrazine/interface' ]
extensions = ['*.cpp']

for dir in directories:
	for ext in extensions:
		regexp = os.path.join(dir, ext)
		sources.extend(env.Glob(regexp))

# find all flex/bison sources
flex_extensions  = ['*.ll']
bison_extensions = ['*.yy']

flex_sources  = []
bison_sources = []

for dir in directories:
	for ext in flex_extensions:
		regexp = os.path.join(dir, ext)
		flex_sources.extend(env.Glob(regexp))
	for ext in bison_extensions:
		regexp = os.path.join(dir, ext)
		bison_sources.extend(env.Glob(regexp))
	
# Generate the flex/bison .c/.cpp files
for source in flex_sources:
	lex = env.CXXFile(os.path.splitext(os.path.basename(str(source)))[0] \
		+ '.cpp', str(source))
	sources.append(lex[0])

for source in bison_sources:
	bison = env.CXXFile(os.path.splitext(os.path.basename(str(source)))[0] \
		+ '.cpp', str(source))
	sources.append(bison[0])
	bison_header = bison[1]
	intermediate_headers.append(os.path.basename(str(bison_header)))

# Create the ocelot library
ocelot_dep_libs = env['EXTRA_LIBS']
ocelot_dep_libs.extend(env['LLVM_LIBS'])

if env['library'] == 'shared':
	libocelot = env.SharedLibrary('ocelot', sources, LIBS=ocelot_dep_libs)
else:
	libocelot = env.StaticLibrary('ocelot', sources, LIBS=ocelot_dep_libs)

if 'install' in COMMAND_LINE_TARGETS:
	libocelot = env.Install(os.path.join(env['install_path'], "lib"), libocelot)

# Create ocelot built-in programs
if os.name == 'nt':
	ocelot_libs = ['ocelot.lib', 'opengl32.lib']
else:
	ocelot_libs = ['-locelot']

OcelotConfig = env.Program('OcelotConfig', \
	['ocelot/tools/OcelotConfig.cpp'], LIBS=ocelot_libs, \
	CXXFLAGS = env['OCELOT_CONFIG_FLAGS'])
env.Depends(OcelotConfig, libocelot)

PTXOptimizer = env.Program('PTXOptimizer', \
	['ocelot/tools/PTXOptimizer.cpp'], LIBS=ocelot_libs)
env.Depends(PTXOptimizer, libocelot)

ocelot_server_libs = ['']

if os.name != 'nt':
	ocelot_server_libs = ['-lboost_system-mt', '-lpthread']

OcelotServer = env.Program('OcelotServer', \
	['ocelot/tools/OcelotServer.cpp'],
	LIBS=ocelot_libs + ocelot_server_libs)
env.Depends(OcelotServer, libocelot)

OcelotHarness = env.Program('OcelotKernelTestHarness', \
	['ocelot/tools/KernelTestHarness.cpp'], LIBS=ocelot_libs)
env.Depends(OcelotHarness, libocelot)

CFG = env.Program('CFG', ['ocelot/tools/CFG.cpp'], LIBS=ocelot_libs)
env.Depends(CFG, libocelot)

Default(OcelotConfig)

# Create the ocelot unit tests

test_libs = ['-lboost_system-mt', '-lboost_filesystem-mt']

tests = []
tests.append(('TestLexer',  'ocelot/parser/test/TestLexer.cpp', 'basic',
	test_libs))
tests.append(('TestParser', 'ocelot/parser/test/TestParser.cpp', 'basic',
	test_libs))
tests.append(('TestInstructions', \
	'ocelot/executive/test/TestInstructions.cpp', 'basic'))
tests.append(('TestDataflowGraph', \
	'ocelot/analysis/test/TestDataflowGraph.cpp', 'basic', test_libs))
tests.append(('TestLLVMInstructions', \
	'ocelot/ir/test/TestLLVMInstructions.cpp', 'basic'))
tests.append(('TestKernels', \
	'ocelot/executive/test/TestKernels.cpp', 'basic'))
tests.append(('TestLLVMKernels', \
	'ocelot/executive/test/TestLLVMKernels.cpp', 'basic'))
tests.append(('TestEmulator', \
	'ocelot/executive/test/TestEmulator.cpp', 'basic'))
tests.append(('TestPTXToLLVMTranslator', \
	'ocelot/translator/test/TestPTXToLLVMTranslator.cpp', 'basic', test_libs))
tests.append(('TestCudaSequence', \
	'ocelot/cuda/test/kernels/sequence.cu.cpp', 'full', ['-ldl']))
tests.append(('TestCudaGenericMemory', \
	'ocelot/cuda/test/memory/generic.cpp', 'full'))
tests.append(('TestCudaMalloc', \
	'ocelot/cuda/test/memory/malloc.cu.cpp', 'full'))
tests.append(('TestCudaGlobals', \
	'ocelot/cuda/test/globals/global.cu.cpp', 'full'))
tests.append(('TestCudaTexture2D', \
	'ocelot/cuda/test/textures/texture2D.cu.cpp', 'full'))
tests.append(('TestCudaTexture3D', \
	'ocelot/cuda/test/textures/texture3D.cu.cpp', 'full'))
tests.append(('TestCudaTextureArray', \
	'ocelot/cuda/test/textures/textureArray.cu.cpp', 'full'))
tests.append(('TestFunctionCall', \
	'ocelot/cuda/test/functions/simpleFunc.cu.cpp', 'full'))
tests.append(('TestIndirectFunctionCall', \
	'ocelot/cuda/test/functions/indirectCall.cu.cpp', 'full'))
tests.append(('TestIndirectFunctionCallOcelot', \
	'ocelot/cuda/test/functions/indirectCallOcelot.cpp', 'full'))
tests.append(('TestCalVectorScale', \
	'ocelot/cal/test/vectorScale.cu.cpp', 'full'))
tests.append(('TestDeviceSwitching', \
	'ocelot/api/test/TestDeviceSwitching.cpp', 'full'))
tests.append(('TestExternalFunctions', \
	'ocelot/api/test/TestExternalFunctions.cpp', 'full'))
tests.append(('TestPTXAssembly', \
	'ocelot/ir/test/TestPTXAssembly.cpp', 'full'))

for test in tests:
	libs = ocelot_libs
	if len(test) > 3:
		libs = libs + test[3]
	Test = env.Program(test[0], [test[1]], LIBS=libs)
	env.Depends(Test, libocelot)

if env['test_level'] != 'none':
	print 'Adding unit tests to the build...'

level_map = { 'none' : 0, 'basic' : 1, 'full' : 2 }

for test in tests:
	if level_map[env['test_level']] >= level_map[test[2]]:
		print 'Adding test ' + test[0]
		Default(test[0])

# find all header files in the source tree
headers = []
directories = ['ocelot/ir/interface', 
	'ocelot/analysis/interface',
	'ocelot/api/interface', 
	'ocelot/cal/interface', 
	'ocelot/cuda/interface', 
	'ocelot/executive/interface', 
	'ocelot/graphs/interface', 
	'ocelot/parser/interface', 
	'ocelot/trace/interface', 
	'ocelot/transforms/interface',
	'ocelot/translator/interface',
	'ocelot/util/interface', 
	'hydrazine/implementation', 
	'hydrazine/interface' ]
extensions = ['*.h', '*.hpp']

for dir in directories:
	for ext in extensions:
		regexp = os.path.join(dir, ext)
		headers.extend(env.Glob(regexp))

# Install rules

if 'install' in COMMAND_LINE_TARGETS:
	print 'Installing ocelot...'
	installed = []
	installed.append(libocelot)
	installed.append(env.Install(os.path.join( \
		env['install_path'], "bin"), OcelotConfig))
	installed.append(env.Install(os.path.join( \
		env['install_path'], "bin"), PTXOptimizer))
	installed.append(env.Install(os.path.join( \
		env['install_path'], "bin"), OcelotServer))
	installed.append(env.Install(os.path.join( \
		env['install_path'], "bin"), OcelotHarness))

	for header in headers:
		(directoryPath, headerName) = os.path.split( \
			os.path.relpath(str(header), prefix))
		installed.append(env.Install(os.path.join( \
			env['install_path'], "include", directoryPath), header))

	for header in intermediate_headers:
		(directoryPath, headerName) = os.path.split( \
			os.path.relpath(str(header), '.'))
		installed.append(env.Install(os.path.join( \
			env['install_path'], "include", directoryPath), header))

	for i in installed:
		env.AddPostAction(str(i), Chmod(str(i), 0644))
	
	env.Alias('install', env['install_path'])

	env.Replace(installed_files = installed)

	Export('env')
	SConscript('deb/DebSConscript')

