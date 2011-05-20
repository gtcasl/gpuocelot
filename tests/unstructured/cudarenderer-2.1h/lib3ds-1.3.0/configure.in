dnl Process this file with autoconf to produce a configure script.
AC_INIT(Makefile.am)
AC_CONFIG_MACRO_DIR([m4])

LIB3DS_MAJOR_VERSION=1
LIB3DS_MINOR_VERSION=3
LIB3DS_MICRO_VERSION=0
LIB3DS_VERSION=$LIB3DS_MAJOR_VERSION.$LIB3DS_MINOR_VERSION.$LIB3DS_MICRO_VERSION
AC_SUBST(LIB3DS_MAJOR_VERSION)
AC_SUBST(LIB3DS_MINOR_VERSION)
AC_SUBST(LIB3DS_MICRO_VERSION)
AC_SUBST(LIB3DS_VERSION)

AM_CONFIG_HEADER(config.h)
AM_INIT_AUTOMAKE(lib3ds, $LIB3DS_VERSION)
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

AC_PROG_CC
AC_PROG_LIBTOOL

AC_MSG_CHECKING([for debugging mode])
AC_ARG_ENABLE(debug-mode,   
  [  --enable-debug-mode     enable debugging mode],
  [
    LIB3DS_DEBUG_MODE=yes
  ]
)
if test "$LIB3DS_DEBUG_MODE" = yes; then
  AC_MSG_RESULT(yes)
  CFLAGS="$CFLAGS -D_DEBUG"
else
  AC_MSG_RESULT(no)
fi

AC_CHECK_FUNCS([floor])
AC_CHECK_FUNCS([memset])
AC_CHECK_FUNCS([pow])
AC_CHECK_FUNCS([sqrt])
AC_CHECK_FUNCS([strrchr])
AC_CHECK_HEADERS([float.h])
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_PROG_CXX
LT_INIT
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_INT8_T
AC_TYPE_SIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT8_T


AC_OUTPUT([ \
  lib3ds-config \
  lib3ds-config.1 \
  Makefile \
  lib3ds/Makefile \
  tools/Makefile \
  tools/3dsdump.1 \
  lib3ds.spec \
  3ds-utils.spec \
],[chmod a+x lib3ds-config])
