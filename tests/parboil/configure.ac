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
AC_CHECK_PROG(HAVE_LLVM_CONFIG, llvm-config, 1, 0)

if test $HAVE_LLVM_CONFIG = 1
then
	AC_DEFINE(HAVE_LLVM, [], ["Define to 1 if llvm is installed"])
	AC_SUBST(LLVM_CFLAGS, $(llvm-config --cppflags))
	AC_SUBST(LLVM_LDFLAGS, $(llvm-config --ldflags --libs core jit native \
		asmparser | tr '\n' ' '))
else
	AC_SUBST(LLVM_CFLAGS, "")
	AC_SUBST(LLVM_LDFLAGS, "")	
fi
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
	AC_MSG_ERROR("libOcelotParser required"), \
	[-lOcelotIr -lOcelotAnalysis -lhydrazine])	
AC_CHECK_LIB([OcelotIr], [main], [AC_DEFINE(HAVE_OCELOT_IR, [], [""])], \
	AC_MSG_ERROR("libOcelotIr required"), \
	[-lOcelotAnalysis -lOcelotParser -lhydrazine])	
AC_CHECK_LIB([OcelotTrace], [main], [AC_DEFINE(HAVE_OCELOT_TRACE, [], [""])], \
	AC_MSG_ERROR("libOcelotTrace required"), \
	[ -lOcelotIr -lOcelotAnalysis -lOcelotParser -lhydrazine])	
AC_CHECK_LIB([OcelotTranslator], [main], \
	[AC_DEFINE(HAVE_OCELOT_TRANSLATOR, [], [""])], \
	AC_MSG_ERROR("libOcelotTranslator required"), \
	[-lOcelotTrace -lOcelotIr -lOcelotAnalysis -lOcelotParser -lhydrazine])
AC_CHECK_LIB([OcelotExecutive], [main], \
	[AC_DEFINE(HAVE_OCELOT_EXECUTIVE, [], [""])], \
	AC_MSG_ERROR("libOcelotExecutive required"), \
	[-lOcelotTranslator -lOcelotTrace -lOcelotIr -lOcelotAnalysis
	-lOcelotParser -lhydrazine $LLVM_LDFLAGS])	
AC_CHECK_LIB([OcelotAnalysis], [main], \
	[AC_DEFINE(HAVE_OCELOT_ANALYSIS, [], [""])], \
	AC_MSG_ERROR("libOcelotAnalysis required"), \
	[-lOcelotIr -lOcelotParser -lhydrazine])
AC_CHECK_LIB([cudart], [main], [AC_DEFINE(HAVE_CUDART, [], [""])], \
	AC_MSG_ERROR("libcudart required"), [-lOcelot -lOcelotExecutive \
	-lOcelotTranslator -lOcelotTrace -lOcelotIr -lOcelotAnalysis \
	-lOcelotParser -lhydrazine $LLVM_LDFLAGS])	
AC_CHECK_LIB([Ocelot], [main], [AC_DEFINE(HAVE_OCELOT, [], [""])], \
	AC_MSG_ERROR("libOcelot required"), [-lcudart -lOcelotExecutive \
	-lOcelotTranslator -lOcelotTrace -lOcelotIr -lOcelotAnalysis \
	-lOcelotParser -lhydrazine $LLVM_LDFLAGS])	
AC_CHECK_LIB([cufft], [main], [AC_DEFINE(HAVE_CUFFT, [], [""])], \
	AC_MSG_ERROR("libcufft required"), [-lcudart -lOcelot -lOcelotExecutive \
	-lOcelotTranslator -lOcelotTrace -lOcelotIr -lOcelotAnalysis \
	-lOcelotParser -lhydrazine $LLVM_LDFLAGS])
AC_CHECK_LIB([cublas], [main], [AC_DEFINE(HAVE_CUBLAS, [], [""])], \
	AC_MSG_ERROR("libcublas required"), [-lcudart -lOcelot -lOcelotExecutive \
	-lOcelotTranslator -lOcelotTrace -lOcelotIr -lOcelotAnalysis \
	-lOcelotParser -lhydrazine $LLVM_LDFLAGS])
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

