#! /bin/python

################################################################################
#	\file   SConscript
#	\author Gregory Diamos <gregory.diamos@gatech.edu>
#   \date   Monday March 26, 2012
#	\brief  The SCons script for the top level ocelot project
################################################################################

import sys

sys.path.append('../tests/scripts')	
import builder

#
#
## The script begins here
# create the test environment
testEnv = builder.InitializeEnvironment(Environment(), Builder)

# create the ocelot environment
exec open("../ocelot/scripts/which.py")
exec open("../ocelot/scripts/build_environment.py")
env = Environment()

testEnv.Replace(install_path = env['install_path'])

# create local test environments
testEnv2_2     = testEnv.Clone()
testEnv2_3     = testEnv.Clone()
testEnv3_2     = testEnv.Clone()
testEnv4_1     = testEnv.Clone()
testEnvRodinia = testEnv.Clone()
testEnvParboil = testEnv.Clone()

# The main ocelot project

env.Replace(OCELOT_BUILD_ROOT = os.path.join(env['BUILD_ROOT'], '.'))
ocelot = SConscript('ocelot/SConscript', exports=['env'])

## CUDA SDKs
testEnv2_2.Replace(CUDA_PATH=os.path.join(env['BUILD_ROOT'], 'tests/cuda2.2'))
testEnv2_3.Replace(CUDA_PATH=os.path.join(env['BUILD_ROOT'], 'tests/cuda2.3'))
testEnv3_2.Replace(CUDA_PATH=os.path.join(env['BUILD_ROOT'], 'tests/cuda3.2'))
testEnv4_1.Replace(CUDA_PATH=os.path.join(env['BUILD_ROOT'], 'tests/cuda4.1sdk'))
testEnvParboil.Replace(TEST_PATH=os.path.join(env['BUILD_ROOT'], 'tests/parboil'))

# Add the SDKs
cuda2_2 = SConscript('tests/cuda2.2/SConscript',    exports={'env' : testEnv2_2})
cuda2_3 = SConscript('tests/cuda2.3/SConscript',    exports={'env' : testEnv2_3})
cuda3_2 = SConscript('tests/cuda3.2/SConscript',    exports={'env' : testEnv3_2})
cuda4_1 = SConscript('tests/cuda4.1sdk/SConscript', exports={'env' : testEnv4_1})

# Benchmark suites
parboil = SConscript('tests/parboil/SConscript', exports={'env' : testEnvParboil})
#SConscript('tests/rodinia/SConscript')

# Explicit Dependencies
Depends(cuda2_2, ocelot)
Depends(cuda2_3, ocelot)
Depends(cuda3_2, ocelot)
Depends(cuda4_1, ocelot)
Depends(parboil, ocelot)

