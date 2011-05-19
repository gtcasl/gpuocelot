################################################################################
#	\file configure.ac
#	\author Gregory Diamos
#	\date Thursday July 29, 2010
# 	\brief Autoconf input file describing the checks that need to be performed 
#			to create a configure script for the ocelot trace generator project.
################################################################################

################################################################################
## Package specification
# Revision scheme is MajorFeatureSet.MinorFeatureSet.SVNChangelistNumber
AC_PREREQ(2.65)
AC_INIT(ocelot-trace-generators, 1.2.661, gregory.diamos@gatech.edu)
AM_INIT_AUTOMAKE([])
################################################################################

################################################################################
## Configure autoconf
AC_USE_SYSTEM_EXTENSIONS
AC_CONFIG_MACRO_DIR([m4])
################################################################################

################################################################################
## Package Configuration
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
AM_PROG_CC_C_O
################################################################################

################################################################################
# Check for libraries
AC_CHECK_LIB([z], [deflate], [], \
	AC_MSG_ERROR("libz required"))
AC_CHECK_LIB([boost_serialization-mt], [main], [], \
	AC_MSG_ERROR("libboost_serialization-mt required"))

################################################################################

################################################################################
# Checks for header files.
################################################################################

################################################################################
# Check for non-compiler programs
################################################################################

################################################################################
# Set variables in the configure.h file
################################################################################

################################################################################
# Checks for typedefs, structures, and compiler characteristics.
################################################################################

################################################################################
# Checks for library functions.
################################################################################

################################################################################
## Output generation
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
################################################################################

