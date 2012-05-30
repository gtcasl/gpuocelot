dnl @synopsis AC_COMPILE_CHECK_SIZEOF(TYPE [, HEADERS [, EXTRA_SIZES...]])
dnl
dnl This macro checks for the size of TYPE using compile checks, not
dnl run checks. You can supply extra HEADERS to look into. the check
dnl will cycle through 1 2 4 8 16 and any EXTRA_SIZES the user
dnl supplies. If a match is found, it will #define SIZEOF_`TYPE' to
dnl that value. Otherwise it will emit a configure time error
dnl indicating the size of the type could not be determined.
dnl
dnl The trick is that C will not allow duplicate case labels. While
dnl this is valid C code:
dnl
dnl      switch (0) case 0: case 1:;
dnl
dnl The following is not:
dnl
dnl      switch (0) case 0: case 0:;
dnl
dnl Thus, the AC_TRY_COMPILE will fail if the currently tried size
dnl does not match.
dnl
dnl Here is an example skeleton configure.in script, demonstrating the
dnl macro's usage:
dnl
dnl      AC_PROG_CC
dnl      AC_CHECK_HEADERS(stddef.h unistd.h)
dnl      AC_TYPE_SIZE_T
dnl      AC_CHECK_TYPE(ssize_t, int)
dnl
dnl      headers='#ifdef HAVE_STDDEF_H
dnl      #include <stddef.h>
dnl      #endif
dnl      #ifdef HAVE_UNISTD_H
dnl      #include <unistd.h>
dnl      #endif
dnl      '
dnl
dnl      AC_COMPILE_CHECK_SIZEOF(char)
dnl      AC_COMPILE_CHECK_SIZEOF(short)
dnl      AC_COMPILE_CHECK_SIZEOF(int)
dnl      AC_COMPILE_CHECK_SIZEOF(long)
dnl      AC_COMPILE_CHECK_SIZEOF(unsigned char *)
dnl      AC_COMPILE_CHECK_SIZEOF(void *)
dnl      AC_COMPILE_CHECK_SIZEOF(size_t, $headers)
dnl      AC_COMPILE_CHECK_SIZEOF(ssize_t, $headers)
dnl      AC_COMPILE_CHECK_SIZEOF(ptrdiff_t, $headers)
dnl      AC_COMPILE_CHECK_SIZEOF(off_t, $headers)
dnl
dnl @author Kaveh Ghazi <ghazi@caip.rutgers.edu>
dnl @version $Id: acinclude.m4,v 1.2 2008-11-18 21:36:49 eisen Exp $
dnl
AC_DEFUN([AC_COMPILE_CHECK_SIZEOF],
[changequote(<<, >>)dnl
dnl The name to #define.
define(<<AC_TYPE_NAME>>, translit(sizeof_$1, [a-z *], [A-Z_P]))dnl
dnl The cache variable name.
define(<<AC_CV_NAME>>, translit(ac_cv_sizeof_$1, [ *], [_p]))dnl
changequote([, ])dnl
AC_MSG_CHECKING(size of $1)
AC_CACHE_VAL(AC_CV_NAME,
[for ac_size in 4 8 1 2 16 $2 ; do # List sizes in rough order of prevalence.
  AC_TRY_COMPILE([#include "confdefs.h"
#include <sys/types.h>
$2
], [switch (0) case 0: case (sizeof ($1) == $ac_size):;], AC_CV_NAME=$ac_size)
  if test x$AC_CV_NAME != x ; then break; fi
done
])
if test x$AC_CV_NAME = x ; then
  AC_CV_NAME=0;
fi
AC_MSG_RESULT($AC_CV_NAME)
AC_DEFINE_UNQUOTED(AC_TYPE_NAME, $AC_CV_NAME, [The number of bytes in type $1])
undefine([AC_TYPE_NAME])dnl
undefine([AC_CV_NAME])dnl
])
dnl
dnl AC_C_BIGENDIAN_CROSS([CROSS-BIGENIAN])
dnl
AC_DEFUN([AC_C_BIGENDIAN_CROSS],
[AC_CACHE_CHECK(whether byte ordering is bigendian, ac_cv_c_bigendian,
[ac_cv_c_bigendian=unknown
# See if sys/param.h defines the BYTE_ORDER macro.
AC_TRY_COMPILE([#include <sys/types.h>
#include <sys/param.h>], [
#if !BYTE_ORDER || !BIG_ENDIAN || !LITTLE_ENDIAN
 bogus endian macros
#endif], [# It does; now see whether it defined to BIG_ENDIAN or not.
AC_TRY_COMPILE([#include <sys/types.h>
#include <sys/param.h>], [
#if BYTE_ORDER != BIG_ENDIAN
 not big endian
#endif], ac_cv_c_bigendian=yes, ac_cv_c_bigendian=no)])
if test $ac_cv_c_bigendian = unknown; then
AC_TRY_RUN([main () {
  /* Are we little or big endian?  From Harbison&Steele.  */
  union
  {
    long l;
    char c[sizeof (long)];
  } u;
  u.l = 1;
  exit (u.c[sizeof (long) - 1] == 1);
}], ac_cv_c_bigendian=no, ac_cv_c_bigendian=yes, ac_cv_c_bigendian=$1)
fi])
if test $ac_cv_c_bigendian = yes; then
  AC_DEFINE(WORDS_BIGENDIAN,1,[Define if byteorder is bigendian])
fi
])

AC_DEFUN([ECL_SET_DIS_VARS],
[AS_VAR_PUSHDEF([ecl_dis],[ecl_cv_print_insn_$1])
LIBS="$LIBS -lopcodes";
	ecl_cv_disassembly_libs=""
	AC_TRY_LINK([
	char xmalloc(){};
	int bfd_get_arch (void *abfd){};
	void*	bfd_getb32	   (const unsigned char *a){};
	void*	bfd_getl32	   (const unsigned char *a){};
	extern int print_insn_$1	(void*, void*);
	int (*f) (void*,void**);],[f = print_insn_$1;]
	,[AS_VAR_SET(ecl_dis,yes)
	  ecl_cv_disassembly_libs="-lopcodes"],[AS_VAR_SET(ecl_dis,no)])
AS_IF([test AS_VAR_GET(ecl_dis) = no],
	LIBS="$LIBS -lopcodes -lbfd";
	AC_TRY_LINK([
	#include "dis-asm.h"
	char xmalloc(){};
	char xstrdup(){};
	extern int print_insn_$1	PARAMS ((bfd_vma, disassemble_info*));
	int (*f) PARAMS ((bfd_vma, disassemble_info*));],[f = print_insn_$1;],
		[AS_VAR_SET(ecl_dis,yes)
		ecl_cv_disassembly_libs="-lopcodes -lbfd"],
		[AS_VAR_SET(ecl_dis,no)]))
AS_IF([test AS_VAR_GET(ecl_dis) = no],
	LIBS="$LIBS -lopcodes -lbfd -lintl";
	AC_TRY_LINK([
	#include "dis-asm.h"
	char xmalloc(){};
	char xstrdup(){};
	extern int print_insn_$1	PARAMS ((bfd_vma, disassemble_info*));
	int (*f) PARAMS ((bfd_vma, disassemble_info*));],[f = print_insn_$1;],
		[AS_VAR_SET(ecl_dis,yes)
		ecl_cv_disassembly_libs="-lopcodes -lbfd -lintl"],
		[AS_VAR_SET(ecl_dis,no)]))
AS_IF([test AS_VAR_GET(ecl_dis) = no], AC_DEFINE(NO_DISASSEMBLER, 1, [Define if there is no disassembler]))
AS_VAR_POPDEF([ecl_dis])dnl
])

AC_DEFUN([ECL_CHECK_DISASSEMBLER],
[AS_VAR_PUSHDEF([ecl_dis],[ecl_cv_print_insn_$1])
CACHE_LIBS=$LIBS
AC_CACHE_CHECK([if print_insn_$1 is found], [ecl_cv_print_insn_$1],
	ECL_SET_DIS_VARS($1))
AS_IF([test AS_VAR_GET(ecl_dis) = yes],
      [AC_DEFINE_UNQUOTED(AS_TR_CPP(HAVE_PRINT_INSN_$1), 1, [Define if you have the `print_insn_$1' function.])])
AC_CACHE_CHECK([what disassembly libraries to use],[ecl_cv_disassembly_libs],
	ECL_SET_DIS_VARS($1))
DIS_LIBS="$ecl_cv_disassembly_libs"
LIBS=$CACHE_LIBS
AS_VAR_POPDEF([ecl_dis])dnl
])

AC_DEFUN([ECL_CHECK_BFD_ARGS],
[
AC_CACHE_CHECK([bfd functions use bfd_byte typed args],[ecl_cv_bfd_byte],
[AC_COMPILE_IFELSE([AC_LANG_SOURCE([#include "dis-asm.h"
bfd_vma
bfd_getl64 (addr)
register const bfd_byte *addr;
{return 1;}])],[ecl_cv_bfd_byte=yes],[ecl_cv_bfd_byte=no])
])
if test $ecl_cv_bfd_byte = yes; then
   AC_DEFINE([BFD_BYTE], 1,
             [Define if bfd functions use bfd_byte arguments.])
fi
])
