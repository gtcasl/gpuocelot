#!/usr/bin/python

################################################################################
#	\file   build.py
#	\author Gregory Diamos <gregory.diamos@gatech.edu>
#   \date   Sunday March 13, 2011
#	\brief  The Ocelot build script to direct scons builds and run unit tests
################################################################################

import os
import re
from optparse import OptionParser

################################################################################
## Run Unit Tests
def runUnitTests(options):
	if options.test_level == 'none':
		return False
	
	command = "hydrazine/python/RunRegression.py -v"
	
	if options.debug:
		command += " -p .debug_build/"
		prefix = "debug"
	else:
		command += " -p .release_build/"
		prefix = "release"

	if options.test_level == 'basic':
		log = "regression/" + prefix + "-basic.log"
		command += " -t regression/basic.level"
	elif options.test_level == 'full':
		log = "regression/" + prefix + "-full.log"
		command += " -t regression/full.level"

	command += " -l " + log
	
	print '\nRunning Ocelot Unit Tests...'
	status = os.popen(command).read()
	print status
	
	# Check for any failing/missing tests
	if re.search('Failing tests|Non-Existent tests', status):
		return False
	else:
		return True
		
################################################################################

################################################################################
## Submit to SVN
def submit(options, testPassed):
	if not options.submit:
		return
		
	if len(options.message) == 0:
		print "Log message not specified (use -m)"
		return
	
	if not testPassed:
		print "Regression tests failed, commit prohibited."
		return
		
	command = "svn commit -m \"" + options.message + "\""
	
	os.system(command)
################################################################################

################################################################################
## Main
def main():
	parser = OptionParser()
	
	parser.add_option( "-c", "--clean", \
		default = False, action = "store_true" )
	parser.add_option( "-d", "--debug", \
		default = False, action = "store_true", \
		help = "build Ocelot in debug mode." )
	parser.add_option( "-t", "--test_level", default = "none", \
		help = "set the test level (none, basic, full)" )
	parser.add_option( "-j", "--threads", default = "1" )
	parser.add_option( "-s", "--submit", \
		default = False, action = "store_true" )
	parser.add_option( "-b", "--build_target", \
		default = "", help = "build a specific target." )
	parser.add_option( "-m", "--message", default = "", \
		help = "the message describing the changes being committed." )
	
	( options, arguments ) = parser.parse_args()
	
	command = "scons"

	if options.submit:
		if options.test_level != 'full':
			print "Full test level required for a submit."
		options.test_level = 'full'
		options.build_target = ''

	if options.clean:
		command += " -c"

	if options.debug:
		command += " mode=debug"

	if options.build_target != '':
		if options.debug:
			command += " .debug_build/"
		else:
			command += " .release_build/"
		command += options.build_target
		
	command += " test_level=" + options.test_level
	command += " -j" + options.threads

	# Run SCons
	print command
	os.system(command)

	# Run unit tests
	testsPassed = runUnitTests(options)

	# Submit if the tests pass
	submit(options, testsPassed)

################################################################################

################################################################################
## Guard Main
if __name__ == "__main__":
	main()

################################################################################


