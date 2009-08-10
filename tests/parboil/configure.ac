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
## Checks for libraries.
AC_CHECK_LIB([rt], [clock_gettime], [], \
	AC_MSG_ERROR("librt required"))
AC_CHECK_LIB([GL], [glIsTexture], [], \
	AC_MSG_ERROR("libGL required"))
AC_CHECK_LIB([GLEW], [glewInit], [], \
	AC_MSG_ERROR("libGLEW required"))
AC_CHECK_LIB([GLU], [gluGetString], [], \
	AC_MSG_ERROR("libGLU required"))
AC_CHECK_LIB([glut], [glutMainLoop], [], \
	AC_MSG_ERROR("libglut required"))
	
AC_CHECK_LIB([hydrazine], [main],[AC_DEFINE(HAVE_HYDRAZINE, [], [""])], \
	AC_MSG_ERROR("libhydrazine required"))
AC_CHECK_LIB([OcelotParser], [main], \
	[AC_DEFINE(HAVE_OCELOT_PARSER, [], [""])], \
	AC_MSG_ERROR("libOcelotParser required"), [-lOcelotIr -lhydrazine])	
AC_CHECK_LIB([OcelotIr], [main], [AC_DEFINE(HAVE_OCELOT_IR, [], [""])], \
	AC_MSG_ERROR("libOcelotIr required"), [-lOcelotParser -lhydrazine])	
AC_CHECK_LIB([OcelotTrace], [main], [AC_DEFINE(HAVE_OCELOT_TRACE, [], [""])], \
	AC_MSG_ERROR("libOcelotTrace required"), [-lhydrazine])	
AC_CHECK_LIB([OcelotExecutive], [main], \
	[AC_DEFINE(HAVE_OCELOT_EXECUTIVE, [], [""])], \
	AC_MSG_ERROR("libOcelotExecutive required"), \
	[-lOcelotTrace -lOcelotIr -lOcelotParser -lhydrazine])	
AC_CHECK_LIB([OcelotAnalysis], [main], \
	[AC_DEFINE(HAVE_OCELOT_ANALYSIS, [], [""])], \
	AC_MSG_ERROR("libOcelotAnalysis required"), \
	[-lOcelotIr -lOcelotParser -lhydrazine])
AC_CHECK_LIB([cudart], [main], [AC_DEFINE(HAVE_CUDART, [], [""])], \
	AC_MSG_ERROR("libcudart required"), \
	[-lOcelotExecutive -lOcelotTrace -lOcelotIr -lOcelotParser -lhydrazine])
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

