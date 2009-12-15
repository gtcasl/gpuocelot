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
AC_CHECK_PROG(HAVE_LLVM_CONFIG, llvm-config, yes, no)

if test $HAVE_LLVM_CONFIG = yes
then
	LLVM_VERSION=$(llvm-config --version)
	if test $LLVM_VERSION = 2.7svn
	then
		AC_DEFINE(HAVE_LLVM, [], ["Define to 1 if llvm is installed"])
		AC_SUBST(LLVM_CFLAGS, $(llvm-config --cppflags))
		AC_SUBST(LLVM_LDFLAGS, "$(llvm-config --ldflags --libs core jit native \
			asmparser | tr '\n' ' ') -rdynamic")
	else
		AC_WARN(LLVM Support Not Enabled: version $LLVM_VERSION found but \
			requires 2.7svn )
		AC_SUBST(LLVM_CFLAGS, "")
		AC_SUBST(LLVM_LDFLAGS, "")
	fi
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

AC_CHECK_LIB([cuda], [cuInit], HAVE_CUDA_DRIVER_API=yes, \
	HAVE_CUDA_DRIVER_API=no)

gpu_default="yes"
AC_ARG_ENABLE(gpu, [  --enable-gpu=[no/yes] turn on NVIDIA GPU 
	support [default=$gpu_default]],, enable_gpu=$gpu_default)

if test "x$enable_gpu" = "xyes"; then
	if test $HAVE_CUDA_DRIVER_API = yes
	then
		AC_DEFINE(HAVE_CUDA_DRIVER_API, [1], \
			["Define to 1 if the cuda driver api is found"])
		AC_SUBST(CUDA_DRIVER_API_LIBARY, "-lcuda")
	else
		AC_DEFINE(HAVE_CUDA_DRIVER_API, [0], \
			["Define to 1 if the cuda driver api is found"])
		AC_SUBST(CUDA_DRIVER_API_LIBARY, "")
	fi
else
	AC_MSG_NOTICE(Disabled NVIDIA GPU support via libcuda)
	AC_DEFINE(HAVE_CUDA_DRIVER_API, [0], \
		["Define to 1 if the cuda driver api is found"])
	AC_SUBST(CUDA_DRIVER_API_LIBARY, "")
fi

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
	-lOcelotParser -lhydrazine $LLVM_LDFLAGS $CUDA_DRIVER_API_LIBARY])	
AC_CHECK_LIB([OcelotAnalysis], [main], \
	[AC_DEFINE(HAVE_OCELOT_ANALYSIS, [], [""])], \
	AC_MSG_ERROR("libOcelotAnalysis required"), \
	[-lOcelotIr -lOcelotParser -lhydrazine])
AC_CHECK_LIB([cudart], [main], [AC_DEFINE(HAVE_CUDART, [], [""])], \
	AC_MSG_ERROR("libcudart required"), [-lOcelot -lOcelotExecutive \
	-lOcelotTranslator -lOcelotTrace -lOcelotIr -lOcelotAnalysis \
	-lOcelotParser -lhydrazine $LLVM_LDFLAGS $CUDA_DRIVER_API_LIBARY])	
AC_CHECK_LIB([Ocelot], [main], [AC_DEFINE(HAVE_OCELOT, [], [""])], \
	AC_MSG_ERROR("libOcelot required"), [-lcudart -lOcelotExecutive \
	-lOcelotTranslator -lOcelotTrace -lOcelotIr -lOcelotAnalysis \
	-lOcelotParser -lhydrazine $LLVM_LDFLAGS $CUDA_DRIVER_API_LIBARY])	
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

