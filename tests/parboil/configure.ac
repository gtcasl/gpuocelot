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
AC_CHECK_PROG(HAVE_LLVM_CONFIG, llvm-config, yes, no)

if test $HAVE_LLVM_CONFIG = yes
then
	LLVM_VERSION=$(llvm-config --version)
	if test $LLVM_VERSION = 2.7svn
	then
		AC_DEFINE(HAVE_LLVM, [], ["Define to 1 if llvm is installed"])
		AC_SUBST(LLVM_CFLAGS, $(llvm-config --cppflags))
		AC_SUBST(LLVM_LDFLAGS, "$(llvm-config --ldflags --libs core jit native \
			asmparser instcombine | tr '\n' ' ') -rdynamic")
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

AC_CHECK_LIB([ocelot], [main],[AC_DEFINE(HAVE_OCELOT, [], [""])], \
	AC_MSG_ERROR("libocelot required"), [$LLVM_LDFLAGS])
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

