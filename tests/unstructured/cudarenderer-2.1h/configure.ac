AC_INIT([cudaRenderer], [2.1h], [ttsiod@softlab.ntua.gr])

AC_CONFIG_HEADERS([src/config.h])
AC_CONFIG_MACRO_DIR([ac-macros])

########################
# Check for CUDA
########################
AC_ARG_WITH([cuda],
    [  --with-cuda=PATH        prefix where cuda is installed])
if test "x$with_cuda" != x; then
  CUDA_CFLAGS="-I$with_cuda/include"
  CUDA_LIBS="-L$with_cuda/lib -lcudart"
  NVCC="$with_cuda/bin/nvcc"
else
  # Assume it is installed in global directories
  CUDA_CFLAGS=""
  CUDA_LIBS="-lcudart"
  NVCC="nvcc"
fi
NVCCFLAGS="-O2 -use_fast_math --compiler-options -fno-inline --compiler-options -fpermissive"

OLDCFLAGS="$CFLAGS"
OLDCPPFLAGS="$CPPFLAGS"
CFLAGS="$CUDA_CFLAGS"
CPPFLAGS="$CUDA_CFLAGS"
AC_CHECK_HEADER([cuda.h],,[AC_MSG_ERROR([Sorry, CUDA SDK appears to be missing])])
CFLAGS="$OLDCFLAGS"
CPPFLAGS="$OLDCPPFLAGS"
AC_SUBST(CUDA_CFLAGS)
AC_SUBST(CUDA_LIBS)
AC_SUBST(NVCC)
AC_SUBST(NVCCFLAGS)

# Detect the canonical host and target build environment
AC_CANONICAL_HOST
AC_CANONICAL_TARGET

AC_LANG(C++)

AM_INIT_AUTOMAKE([-Wall -Werror])
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

if test x"${CXXFLAGS}" = x ; then
    CXXFLAGS="-O3 -g -Wall"
fi

CXXFLAGS+=" ${CUDA_CFLAGS}"

AM_PROG_CC_C_O

AC_PROG_CXX

AC_CHECK_FUNCS([atexit])
AC_CHECK_HEADERS([stdlib.h string.h])
AC_FUNC_MALLOC
AC_FUNC_VPRINTF
AC_HEADER_STDC

AC_CONFIG_SUBDIRS([lib3ds-1.3.0])

# Best optimization flags for our compiler
if test x"${enable_debug}" = xyes ; then
	AC_MSG_NOTICE([Disabling optimizations])
	CXXFLAGS=`echo "$CXXFLAGS" | sed 's,-O3,,g'`
else
        AX_CXXFLAGS_GCC_OPTION(-Wall)
        AX_CXXFLAGS_GCC_OPTION(-Wextra)
#         AX_CXXFLAGS_GCC_OPTION(-pedantic)
        AX_CXXFLAGS_GCC_OPTION(-fomit-frame-pointer)
        AX_CXXFLAGS_GCC_OPTION(-ffast-math)
        AX_CXXFLAGS_GCC_OPTION(-funsafe-math-optimizations)
        AX_CXXFLAGS_GCC_OPTION(-mtune=native)

# GCC support for -flto is still buggy, internal compiler error triggered...
#        AX_CXXFLAGS_GCC_OPTION(-flto)
#	 AX_CHECK_LINKER_FLAGS(-fwhole-program,[WHOLEPROGRAM="-fwhole-program"],[])
#	 AC_SUBST(WHOLEPROGRAM)

	# SIMD detection - core logic from mplayer

	AC_MSG_CHECKING(for SSE)
	AC_RUN_IFELSE([#include <stdlib.h>
#include <signal.h>
void catchme(int) { exit(1); }
int main(void) {
signal(SIGILL, catchme);
__asm__ volatile ("xorps %%xmm0, %%xmm0":::"memory"); return 0;
}
	], [HAVESSE=yes], [HAVESSE=no])
	AC_MSG_RESULT($HAVESSE)
	if test x"${HAVESSE}" = xyes ; then
	    AC_DEFINE([SIMD_SSE], 1, [Define this to use SSE intrinsics.])
	fi

	AC_MSG_CHECKING(for SSE2)
	AC_RUN_IFELSE([#include <stdlib.h>
#include <signal.h>
void catchme(int) { exit(1); }
int main(void) {
signal(SIGILL, catchme);
__asm__ volatile ("xorpd %%xmm0, %%xmm0":::"memory"); return 0;
}
	], [HAVESSE2=yes], [HAVESSE2=no])
	AC_MSG_RESULT($HAVESSE2)

	AC_MSG_CHECKING(for SSSE3)
	AC_RUN_IFELSE([#include <stdlib.h>
#include <signal.h>
void catchme(int) { exit(1); }
int main(void) {
signal(SIGILL, catchme);
__asm__ volatile ("pabsd %%xmm0, %%xmm0":::"memory"); return 0;
}
	], [HAVESSSE3=yes], [HAVESSSE3=no])
	AC_MSG_RESULT($HAVESSSE3)

	if test x"${HAVESSE}" = xyes ; then
	    AX_CXXFLAGS_GCC_OPTION(-msse)
	    AX_CXXFLAGS_GCC_OPTION(-mrecip)
	    AX_CXXFLAGS_GCC_OPTION(-mfpmath=sse)
	fi
	if test x"${HAVESSE2}" = xyes ; then
	    AX_CXXFLAGS_GCC_OPTION(-msse2)
	fi
	if test x"${HAVESSSE3}" = xyes ; then
	    AX_CXXFLAGS_GCC_OPTION(-mssse3)
	fi
        CXXFLAGS="$CXXFLAGS -DNDEBUG"
fi


# Figure out which OpenGL and GLU libraries to use
case "$target" in
    *-*-cygwin* | *-*-mingw32*)
        SYS_GL_LIBS="-lopengl32 -lglu32 -lglut"
        ;;
    *-*-beos*)
        SYS_GL_LIBS="-lGL -lGLU -lGLEW -lglut"
        ;;
    *-*-aix*)
        if test x$ac_cv_prog_gcc = xyes; then
            CFLAGS="-mthreads"
        fi
        ;;
    *-*-darwin*)
    	CPPFLAGS="$CPPFLAGS -I/usr/X11R6/include"
	SYS_GL_LIBS="-L/usr/X11R6/lib -lGL -lGLU -lGLEW -lglut"
        ;;
    *)
        AC_PATH_X
        AC_PATH_XTRA
        if test x$have_x = xyes; then
            CPPFLAGS="$CPPFLAGS $X_CFLAGS"
            SYS_GL_LIBS="$X_LIBS -lGL -lGLU -lGLEW -lglut"
        else
            AC_MSG_ERROR([*** No X detected!])
        fi
        ;;
esac

# Check for OpenGL
AC_MSG_CHECKING(for OpenGL GLUT and GLEW support)
HAVE_OPENGL=no
AC_TRY_COMPILE([
 #include <GL/glew.h>
 #include <GL/gl.h>
 #include <GL/glut.h>
],[
],[
HAVE_OPENGL=yes
])
AC_MSG_RESULT($HAVE_OPENGL)
if test x$HAVE_OPENGL != xyes; then
    AC_MSG_ERROR([*** OpenGL GLEW and GLUT must be installed!])
fi
AC_SUBST(SYS_GL_LIBS)

# Check for SDL (minimum: 1.2.0)
SDL_VERSION=1.2.0
AM_PATH_SDL($SDL_VERSION, :,
            AC_MSG_ERROR([*** SDL version $SDL_VERSION or later was not found!]))
AC_SUBST(SDL_CFLAGS)
AC_SUBST(SDL_LIBS)

# Finally create all the generated files
AC_CONFIG_FILES([Makefile src/Makefile]) 
AC_OUTPUT
