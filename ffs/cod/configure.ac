AC_INIT
AC_CONFIG_SRCDIR([cod.y])

AC_CONFIG_HEADERS([config.h])
AC_CONFIG_AUX_DIR(../config)
AC_CONFIG_MACRO_DIR([../config])
AM_INIT_AUTOMAKE(cod,1.0)

AM_MAINTAINER_MODE

AC_PROG_CC
AC_CANONICAL_HOST
CERCS_SET_ARCHIVE
ARCH=$cercs_cv_archive
AC_SUBST(ARCH)

segmented_pointers=false
AC_ARG_ENABLE(segmented-pointers,[Allow segmented pointers],
[
	AC_MSG_WARN([
		  --  building segmented pointer capability --  
	])
	AC_DEFINE(SEGMENTED_POINTERS,1,[Define to enable pointers dereferenced through a non-default segment])
	segmented_pointers=true
])

kernel_build=false
dnl
dnl  This has to go *after* AC_PROG_CC and before AC_PROG_LIBTOOL
dnl
AC_ARG_ENABLE(kernel-build,[Build for inclusion in the kernel],
[
case "${host_os}" in
linux-gnu*)
	AC_MSG_WARN([
		--  building as a Linux kernel module  --  
])
	CPPFLAGS="$CPPFLAGS -I$srcdir/kernel -I/usr/src/linux/include"
	if test $ac_cv_c_compiler_gnu = yes; then
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

dnl Checks for programs.
AC_PATH_PROG(AR, ar)
AC_PATH_PROG(LD, ld)
AC_PATH_PROG(RM, rm)
AC_PATH_PROG(NM, nm)
AC_PATH_PROGS(PERL, perl5 perl, perl)
AC_PROG_INSTALL
AC_PROG_YACC
AM_PROG_LEX
AC_PROG_LN_S
AM_PROG_LIBTOOL

AC_C_INLINE

CERCS_REQUIRE_PACKAGE(atl,atl.h,libatl.la)
CERCS_REQUIRE_PACKAGE(cercs_env,cercs_env.h,libcercs_env.la)
CERCS_REQUIRE_PACKAGE(dill,dill.h,libdill.la)
DCG_LIBS="-ldill"
GENERAL_TEST=./general$ac_exeext

AC_SUBST(GENERAL_TEST)
AC_CHECK_LIB(m,sqrt)
AC_SUBST(DCG_LIBS)
if test -n "$cercs_cv_cercs_env_link_dir" -o -n "$with_local_specified"; then
    LIBS="$LIBS -lcercs_env"
fi
if test -n "$cercs_cv_atl_link_dir" -o -n "$with_local_specified"; then
    LIBS="$LIBS -latl"
fi
LIBS="$LIBS \$(top_builddir)/../fm/libfm.la"
if test -n "$with_local_specified" -o -n "$with_rpm_build_specified -o -n "$with_deb_build_specified; then
   cercs_cv_dill_include_arg='-I${abs_top_srcdir}../dill';
   ac_cv_header_dill_h=yes
fi

dnl checks for header files
AC_HEADER_STDC
AC_CHECK_HEADERS(atl.h cercs_env.h malloc.h)
AC_CHECK_HEADER(dill.h, [test_sub=run_time_tests
AC_DEFINE(HAVE_DILL_H,1,[Define to 1 if you have the <dill.h> header file.])],
AC_DEFINE(NO_CODE_GENERATION,1,[Define if neither icode nor dill are available for this platform]))
AC_SUBST(test_sub)

dnl checks for typedefs, structures and compiler characteristics
AC_PRINTF_DEFINED

AC_CONFIG_FILES([Makefile tests/Makefile])
AC_OUTPUT
