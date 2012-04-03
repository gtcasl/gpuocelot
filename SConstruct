################################################################################
#	\file   SConstruct
#	\author Gregory Diamos <gregory.diamos@gatech.edu>
#   \date   Monday March 26, 2012
#	\brief  The SCons master build script for all Ocelot projects and tests
################################################################################

import os

if ARGUMENTS.get('mode', 'release') == 'debug':
	if not os.path.isdir('.debug_build'):
		os.mkdir('.debug_build')
	SConscript('SConscript', variant_dir='.debug_build',   duplicate=0, 
		exports={'mode':'debug'})
else:
	if not os.path.isdir('.release_build'):
		os.mkdir('.release_build')
	SConscript('SConscript', variant_dir='.release_build', duplicate=0,
		exports={'mode':'release'})



