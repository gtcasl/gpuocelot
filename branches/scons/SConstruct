################################################################################
#	\file   SConstruct
#	\author Gregory Diamos <gregory.diamos@gatech.edu>
#   \date   Tuesday March 8, 2011
#	\brief  The SCons master build script for Ocelot
################################################################################

if ARGUMENTS.get('mode', 'release') == 'debug':
	SConscript('SConscript', variant_dir='.debug_build',   duplicate=0, exports={'mode':'debug'})
else:
	SConscript('SConscript', variant_dir='.release_build', duplicate=0, exports={'mode':'release'})


