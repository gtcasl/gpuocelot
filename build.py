#!/usr/bin/env python

################################################################################
#	\file   build.py
#	\author Gregory Diamos <gregory.diamos@gatech.edu>
#   \date   Thursday March 29, 2012
#	\brief  The top level Ocelot build script to direct scons builds
#           and run unit tests 
################################################################################

import os
import re
import subprocess
import time
from optparse import OptionParser
import sys

################################################################################
## Build Ocelot
def build(options):
	command = "scons -Q "

	if options.clean:
		command += " -c"

	if options.debug:
		command += " mode=debug"
	
        if options.no_werr:
                command += " Werror=false"

	if options.no_llvm:
		command += " enable_llvm=false"

	if options.build_deb:
		if not options.install:
			print "Install must be set for a debian build, setting it"
			options.install = True
		command += " debian"

	if options.install:
		command += " install"

	command += " install_path=" + options.install_prefix

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

	scons = subprocess.Popen(command, shell=True)

	return scons.wait() == 0
	
################################################################################

################################################################################
## Run Standard Tests
def runStandardTests(options, directory, name):
	# Run Cuda 2.2 tests
	command = "cd tests/" + directory + "; hydrazine/python/RunRegression.py -v"
	
	if options.debug:
		command += " -p ../../.debug_build/tests/" + directory
	else:
		command += " -p ../../.release_build/tests/" + directory
	
	command += ' -t regression/tests.txt -l regression/tests.log; cd ..'
	
	print '\nRunning ' + name + ' Unit Tests...'
	status = os.popen(command).read()
	print status
	
	# Check for any failing/missing tests
	if re.search('Failing tests|Non-Existent tests', status):
		return False
		
	return True
################################################################################

################################################################################
## Run Unit Tests
def runUnitTests(options, buildSucceeded):
	if options.clean:
		return False
	
	if options.test_level == 'none':
		return False

	if not buildSucceeded:
		print "Build failed..."
		return False
	
	# run Ocelot tests
	command = "cd ocelot; hydrazine/python/RunRegression.py -v"

	if options.debug:
		command += " -p ../.debug_build/ocelot"
		prefix = "debug"
	else:
		command += " -p ../.release_build/ocelot"
		prefix = "release"

	if options.test_level == 'basic':
		log = "regression/" + prefix + "-basic.log"
		command += " -t regression/basic.level"
	elif options.test_level == 'full':
		log = "regression/" + prefix + "-full.log"
		command += " -t regression/full.level"

	command += " -l " + log + "; cd .."

	print '\nRunning Ocelot Unit Tests...'
	status = os.popen(command).read()
	print status

	# Check for any failing/missing tests
	if re.search('Failing tests|Non-Existent tests', status):
		return False
	elif options.test_level == 'basic':
		return True

	# Run standard tests
	if not runStandardTests(options, 'cuda2.2', 'CUDA SDK 2.2'):
		return False
	if not runStandardTests(options, 'cuda2.3', 'CUDA SDK 2.3'):
		return False
	if not runStandardTests(options, 'cuda3.2', 'CUDA SDK 3.2'):
		return False
	if not runStandardTests(options, 'parboil', 'Parboil'):
		return False
	if not runStandardTests(options, 'cuda4.1sdk', 'CUDA SDK 4.1'):
		return False
	
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
	defaultInstallPath = '/usr/local'
	
	if 'OCELOT_INSTALL_PATH' in os.environ:
		defaultInstallPath = os.environ['OCELOT_INSTALL_PATH']

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
	parser.add_option( "-i", "--install", \
		default = False, action = "store_true", help = "Install ocelot." )
	parser.add_option( "-b", "--build_target", \
		default = "", help = "build a specific target." )
	parser.add_option( "-w", "--no_werr", \
		default = False, action = "store_true",
		help = "don't turn warnings into errors." )
	parser.add_option( "-p", "--install_prefix", \
		default = defaultInstallPath,
		help = "The base path to install ocelot in." )
	parser.add_option( "--build_deb", \
		default = False, action = "store_true",
		help = "Build a .deb package of Ocelot." )
	parser.add_option( "--no_llvm", \
		default = False, action = "store_true", help = "Disable llvm support." )
	parser.add_option( "-m", "--message", default = "", \
		help = "the message describing the changes being committed." )
	
	( options, arguments ) = parser.parse_args()
	
	if options.submit:
		if options.test_level != 'full':
			print "Full test level required for a submit."
		options.test_level = 'full'
		options.build_target = ''

	# Do the build
	buildSucceeded = build(options)

	# Run unit tests
	testsPassed = runUnitTests(options, buildSucceeded)

	# Submit if the tests pass
	submit(options, testsPassed)
	
	if buildSucceeded and ((options.test_level == 'none') or testsPassed):
		sys.exit(0)
	else:
		print "Build failed"
		sys.exit(1)

################################################################################

################################################################################
## Guard Main
if __name__ == "__main__":
	main()

################################################################################

