################################################################################
#	\file configure.ac
#	\author Gregory Diamos
#	\date Monday November 23, 2009
# 	\brief Autoconf input file describing the checks that need to be performed 
#			to create a configure script for the rodinia regression test
#			project.
################################################################################

################################################################################
## Package specification
# Revision scheme is MajorFeatureSet.MinorFeatureSet.SVNChangelistNumber
AC_PREREQ(2.61)
AC_INIT(Rodinia_Regression_Suite, 0.9.251, gregory.diamos@gatech.edu)
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
## Checks for libraries.
AC_CHECK_LIB([glut], [glutMainLoop], [], \
	AC_MSG_ERROR("libglut required"))
################################################################################

################################################################################
## Checks for programs.
AC_PROG_LIBTOOL
AC_PROG_CXX
AC_PROG_CC
AM_PROG_CC_C_O
################################################################################

################################################################################
# Checks for header files.
AC_CHECK_HEADERS([fcntl.h float.h inttypes.h limits.h malloc.h stddef.h \
	stdlib.h string.h sys/time.h unistd.h])
################################################################################

################################################################################
# Checks for typedefs, structures, and compiler characteristics.
AC_C_INLINE
AC_TYPE_SIZE_T
AC_HEADER_STDBOOL
AC_TYPE_UINT64_T
################################################################################

################################################################################
# Checks for library functions.
AC_FUNC_ERROR_AT_LINE
AC_CHECK_FUNCS([floor ftruncate gettimeofday isascii memset pow sqrt \
	strerror strncasecmp])
################################################################################

################################################################################
## Output generation
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
################################################################################

