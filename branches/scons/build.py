#!/usr/bin/python

################################################################################
#	\file   build.py
#	\author Gregory Diamos <gregory.diamos@gatech.edu>
#   \date   Sunday March 13, 2011
#	\brief  The Ocelot build script to direct scons builds and run unit tests
################################################################################

import os
from optparse import OptionParser

################################################################################
## Main
def main():
	parser = OptionParser()
	
	parser.add_option( "-c", "--clean", \
		default = False, action = "store_true" )
	parser.add_option( "-d", "--debug", \
		default = False, action = "store_true" )
	parser.add_option( "-t", "--test_level", default = "none" )
	parser.add_option( "-j", "--threads", default = "1" )
	
	( options, arguments ) = parser.parse_args()
	
	command = "scons"

	if options.clean:
		command += " -c"

	if options.debug:
		command += " mode=debug"

	command += " test_level=" + options.test_level
	command += " -j" + options.threads

	# Run SCons
	os.system(command)

	

################################################################################

################################################################################
## Guard Main
if __name__ == "__main__":
	main()

################################################################################


