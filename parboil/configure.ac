################################################################################
#	\file configure.in
#	\author Gregory Diamos
#	\date Monday Auguest 3, 2009
# 	\brief Autoconf input file describing the checks that need to be performed 
#			to create a configure script for the parboil regression test
#			project.
################################################################################

################################################################################
## Package specification
# Revision scheme is MajorFeatureSet.MinorFeatureSet.SVNChangelistNumber
AC_PREREQ(2.61)
AC_INIT(parboil_Regression_Suite, 0.1.92, gregory.diamos@gatech.edu)
AM_INIT_AUTOMAKE([])
################################################################################

################################################################################
## Configure autoconf
AC_USE_SYSTEM_EXTENSIONS
AC_CONFIG_MACRO_DIR([m4])
################################################################################

################################################################################
## Package Configuration
AC_CONFIG_HEADER([configure.h])
################################################################################

################################################################################
# Check for non-compiler programs
AC_CHECK_PROG(HAVE_OCELOT_CONFIG, OcelotConfig, yes, no)

if test $HAVE_OCELOT_CONFIG = yes
then
	AC_DEFINE(HAVE_OCELOT, [1], ["Define to 1 if ocelot is installed"])
	AC_SUBST(OCELOT_LDFLAGS, "$(OcelotConfig -l | tr '\n' ' ')")
else
	AC_MSG_ERROR("Ocelot needs to be installed.")
fi
################################################################################

################################################################################
## Checks for programs.
AC_PROG_LIBTOOL
AC_PROG_CXX
AC_PROG_CC
################################################################################

################################################################################
# Checks for header files.
AC_CHECK_HEADERS([inttypes.h malloc.h stdlib.h string.h strings.h \
	sys/time.h unistd.h])
################################################################################

################################################################################
# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_UINT32_T
################################################################################

################################################################################
# Checks for library functions.
AC_CHECK_FUNCS([gettimeofday strdup])
################################################################################

################################################################################
## Output generation
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
################################################################################

