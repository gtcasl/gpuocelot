AC_INIT
AC_CONFIG_SRCDIR([base.ops])
AC_CONFIG_AUX_DIR(config)
AC_CONFIG_MACRO_DIR([config])
AM_INIT_AUTOMAKE(dill,1.0)

AM_MAINTAINER_MODE
AC_CANONICAL_HOST
AC_PROG_CC
AC_PROG_CXX

kernel_build=false
dnl
dnl  This has to go *after* AC_PROG_CC and before AC_PROG_LIBTOOL
dnl
AC_ARG_ENABLE(kernel-build,[  --enable-kernel-build    Build for inclusion in the kernel],
[
case "${host_os}" in
linux-gnu*)
	AC_MSG_WARN([
		--  building as a Linux kernel module  --  
])
	CPPFLAGS="$CPPFLAGS -I$srcdir/kernel -I/usr/src/linux/include"
	if test $ac_cv_prog_gcc = yes; then
		CFLAGS="-fomit-frame-pointer -g -O2"
	fi
	KERNEL_VERSION=`awk -F\" '/REL/ {print $$2}' /usr/src/linux/include/linux/version.h`
	AC_DEFINE(LINUX_KERNEL_MODULE,1,[Define if compiling for linux kernel])
	kernel_build=true
	enable_shared=no
	;;
*)
	AC_MSG_WARN("--enable-kernel-build ignored on non Linux platforms")
	;;
esac
])

kplugins_integration=false
AC_ARG_ENABLE(kplugins-integration,[  --enable-kplugins-integration    Include glue logic to integrate with the Kernel Plugins infrastructure],
[
	AC_DEFINE(KPLUGINS_INTEGRATION,1,[Define if integrating with kernel plugins])
        AC_MSG_WARN([
		--  integrating with Kernel Plugins  --
])
	kplugins_integration=true
])

AM_CONDITIONAL(KERNEL, test x$kernel_build = xtrue)
AC_SUBST(KERNEL_VERSION)

case "${host_os}" in
linux-gnu*|darwin*)
    AC_DEFINE(USE_MMAP_CODE_SEG, 1, [Define this is mmap should be used instead of malloc() for code memory])
    ;;
esac

dnl Checks for programs.
AC_PATH_PROG(PERL, perl5 perl, perl)
AC_PROG_INSTALL
AC_PROG_LN_S
AM_PROG_LIBTOOL

dnl     checks for libraries
AC_ARG_ENABLE(disassembly,AC_HELP_STRING([--enable-disassembly],
                            [enable binutils-based disassembly (default is NO)]),,enable_disassembly="no")

if test x$enable_disassembly = xyes; then
CERCS_REQUIRE_OTHER_PACKAGE(binutils, dis-asm.h, libopcodes.la)
if test x$cercs_cv_binutils_link_dir = x; then
dnl libtool archive not found
unset cercs_cv_binutils_link_dir
unset cercs_cv_binutils_link_arg
CERCS_REQUIRE_OTHER_PACKAGE(binutils,, libopcodes.a)
if test x$cercs_cv_binutils_link_dir = x; then
  for tmp_lib_value in $sys_lib_search_path_spec; do
     tmp=`ls $tmp_lib_value/libopcodes*.so 2> /dev/null`
     if test "x$tmp" != "x"; then 
        cercs_cv_binutils_link_dir=$tmp_lib_value;
     fi
  done
fi
if test "${cercs_cv_binutils_link_dir+set}" != "set"; then
DUMMY_LIBOPCODES_TARGET=libopcodes.la
LIBOPCODES_DIR=$cercs_cv_binutils_link_dir
cercs_cv_binutils_link_dir=.
cercs_cv_binutils_link_arg="-L."
AC_SUBST(DUMMY_LIBOPCODES_TARGET)
AC_SUBST(LIBOPCODES_DIR)
else
NO_DISASSEMBLER="yes"
fi
fi
else
NO_DISASSEMBLER="yes"
fi
if test x$kernel_build = xtrue; then
   NO_DISASSEMBLER="yes"
fi
AM_CONDITIONAL(INSTALL_DUMMY_OPCODES, test x$DUMMY_LIBOPCODES_TARGET != x)
AC_CHECK_LIB(m,sqrt,[MATH_LIB=-lm])
AC_SUBST(MATH_LIB)
CERCS_REQUIRE_OTHER_PACKAGE(ffcall, avcall.h, libavcall.la)
AC_CHECK_HEADER(avcall.h)
if test $ac_cv_header_avcall_h = yes -a -n "$cercs_cv_ffcall_link_dir"; then
AC_DEFINE(BUILD_EMULATOR,1,[Define to 1 if the emulator should be built])
emulation_possible="true"
else
emulation_possible="false"
fi

dnl     checks for header files
if test x$enable_disassembly = xyes; then
AC_CHECK_HEADER(dis-asm.h,AC_DEFINE(HAVE_DIS_ASM_H,1,[Define to 1 if you have the <dis-asm.h> header file.]),
AC_MSG_WARN("No include file dis-asm.h found, no disassembler included");
NO_DISASSEMBLER="yes")

AC_TRY_CPP([#include "dis-asm.h"
extern int tmp() {
struct disassemble_info info;
INIT_DISASSEMBLE_INFO(info, stdout, fprintf);
}
],AC_DEFINE(INIT_DISASSEMBLE_INFO_THREE_ARG,1,[Define if INIT_DISASSEMBLE_INFO takes three arguments instead of two]))
fi

dnl     checks for types
AC_COMPILE_CHECK_SIZEOF(long)
AC_C_BIGENDIAN_CROSS($bigendian_default)
CONFIG_SIZEOF_LONG=$ac_cv_sizeof_long
AC_SUBST(CONFIG_SIZEOF_LONG)

dnl     checks for structures
AC_CHECK_HEADERS(malloc.h)

dnl     checks for compiler characteristics
AC_C_INLINE

dnl     checks for library functions
dnl     checks for system services

native_cg="true"
case $host_cpu in
     sparc* )
        if test x$ac_cv_sizeof_long == x8 ; then
          AC_DEFINE(HOST_SPARCV9, 1, [Define if the host processor is a sparcv9])
          NATIVE_ARCH=sparcv9
        else 
          AC_DEFINE(HOST_SPARC, 1, [Define if the host processor is a sparc])
          NATIVE_ARCH=sparc
        fi
	DIS_ROUTINE=sparc
	AC_TRY_COMPILE([],[asm("membar #Sync");],AC_DEFINE(USE_MEMBAR,1,[Define if the membar instruction should be used to sync Icache and Dcache]))
	ARCH_FILE=sparc
	;;
     powerpc* )
        if test x$ac_cv_sizeof_long == x8 ; then
          AC_DEFINE(HOST_POWERPC64, 1, [Define if the host processor is a powerpc64])
          NATIVE_ARCH=powerpc64
        else 
          AC_DEFINE(HOST_POWERPC, 1, [Define if the host processor is a powerpc])
          NATIVE_ARCH=powerpc
        fi
	DIS_ROUTINE=big_powerpc
	ARCH_FILE=powerpc
	;;
     i*86 )
        if test x$ac_cv_sizeof_long == x8 ; then
	  NATIVE_ARCH=x86_64
	  AC_DEFINE(HOST_X86_64, 1, [Define if the host processor is an x86_64])
	  TEST_PERL_FLAGS="-max_arg=4"
	  ARCH_FILE=x86_64
	else
	  NATIVE_ARCH=x86
	  AC_DEFINE(HOST_X86, 1, [Define if the host processor is an x86])
	  TEST_PERL_FLAGS="-no_float -max_arg=2"
	  ARCH_FILE=x86
	fi
	DIS_ROUTINE=i386
	;;
     x86_64 )
	NATIVE_ARCH=x86_64
	DIS_ROUTINE=i386
	AC_DEFINE(HOST_X86_64, 1, [Define if the host processor is an x86_64])
	TEST_PERL_FLAGS="-max_arg=4"
	ARCH_FILE=x86_64
	;;
     ia64 )
	NATIVE_ARCH=ia64
	DIS_ROUTINE=ia64
	AC_DEFINE(HOST_IA64, 1, [Define if the host processor is an ia64])
	AC_DEFINE(NO_INLINED_BFD_PROCS, 1, [Define if we should not use inlined procedures from BFD])
	ARCH_FILE=ia64
	;;
     arm*5* )
	AC_DEFINE(HOST_ARM, 1, [Define if the host processor is ARM])
	NATIVE_ARCH=arm5
	DIS_ROUTINE=little_arm
        ARCH_FILE=arm5
	TEST_PERL_FLAGS="-max_arg=4"
	;;
      * )
 	NATIVE_ARCH=$host_cpu
        native_cg="false"
	;;
esac
AC_CACHE_SAVE
AC_ARG_ENABLE(multitarget,
[  --enable-multitarget    Turn on non-native target builds],
[case "${enableval}" in
  yes) multitarget=true;
  AC_DEFINE(MULTI_TARGET, 1, [Define if you want more than just native target])
  ;;
  no)  multitarget=false ;;
  *) AC_MSG_ERROR(bad value ${enableval} for --enable-multitarget) ;;
esac],[multitarget=false])
AM_CONDITIONAL(MULTI_TARGET, test x$multitarget = xtrue)
if test x$multitarget = xtrue -o x$native_cg = xtrue -o x$emulation_possible = xtrue; then
   build_library=true
   if test x$emulation_possible = xtrue; then
	LIBS="$LIBS -lavcall"
   fi
   if test x$multitarget = xfalse -a x$native_cg = xfalse; then
	AC_MSG_WARN([
	Configure has detected no native dynamic code generation support 
	for this architecture ("$NATIVE_ARCH").  However, the avcall
	library was found, so library configure for emulation will be built.])
	AC_DEFINE(EMULATION_ONLY,1,[Define if dill should attempt to DCG])
    fi
else
   build_library=false
   AC_MSG_WARN([

	Configure has detected no native dynamic code generation support 
	for this architecture ("$NATIVE_ARCH"), --enable-multitarget 
	was not specified, and no emulation is possible (avcall library 
	not found)
		       NO LIBRARY WILL BE BUILT

])
fi

AM_CONDITIONAL(BUILD_LIBRARY, test x$build_library = xtrue)
AM_CONDITIONAL(NATIVE_CG, test x$native_cg = xtrue)
if (test "$NO_DISASSEMBLER" != "yes") then
if test "x$multitarget" = xfalse; then
  ECL_CHECK_DISASSEMBLER($DIS_ROUTINE)
else
  ECL_CHECK_DISASSEMBLER(sparc)
  ECL_CHECK_DISASSEMBLER(big_powerpc)
  ECL_CHECK_DISASSEMBLER(ia64)
  ECL_CHECK_DISASSEMBLER(i386)
  ECL_CHECK_DISASSEMBLER(arm)
  ECL_CHECK_DISASSEMBLER(little_arm)
fi
ECL_CHECK_BFD_ARGS
fi
if (test "$NO_DISASSEMBLER" = "yes") then
    DIS_LIBS=""
    DUMMY_LIBOPCODES_TARGET=""
    AC_DEFINE(NO_DISASSEMBLER, 1, [Define if there is no disassembler])
fi
AC_SUBST(DIS_LIBS)
AC_SUBST(TEST_PERL_FLAGS)
AC_SUBST(ARCH_FILE)
AC_DEFINE_UNQUOTED(NATIVE_ARCH, "$NATIVE_ARCH",[Define for the host architecture type])

dnl if we're using gcc, add -WALL to CFLAGS
test "$CC" = "gcc" && CFLAGS="-Wall $CFLAGS"
NOOPT_CFLAGS=`echo $CFLAGS | sed 's/-O[[^ ]]//g'`
AC_SUBST(NOOPT_CFLAGS)

AC_CONFIG_FILES([Makefile vtests/Makefile tests/Makefile])
AM_CONFIG_HEADER([config.h])
AC_OUTPUT
