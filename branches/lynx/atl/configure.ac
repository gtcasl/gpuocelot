dnl Process this file with autoconf to produce a configure script.
AC_INIT([atl],[3.0],[eisen@cc.gatech.edu])
AC_CONFIG_SRCDIR([atom.c])
AC_CONFIG_AUX_DIR([config])
AC_CONFIG_MACRO_DIR([config])
AM_INIT_AUTOMAKE(AC_PACKAGE_TARNAME,AC_PACKAGE_VERSION)
AM_MAINTAINER_MODE
AC_CONFIG_HEADERS([config.h])

dnl Checks for programs.
AC_PROG_CC
AC_EXEEXT
AC_PROG_INSTALL

AC_CANONICAL_HOST

kernel_build=false
dnl
dnl This has to go *after* AC_PROG_CC and before AC_PROG_LIBTOOL
dnl
AC_ARG_ENABLE(kernel-build,[Build for inclusion in the kernel],
[
case "${host_os}" in
linux-gnu*)
	AC_MSG_WARN([
		-- building as a Linux kernel module --
])
	CPPFLAGS="$CPPFLAGS -I/usr/src/linux/include"
	if test $ac_cv_c_compiler_gnu = yes; then
		CFLAGS="-fomit-frame-pointer -g -O2"
	fi
	KERNEL_VERSION=`awk -F\" '/REL/ {print $$2}' /usr/src/linux/include/linux/version.h`
	KERNEL_OBJS="katl.lo env.lo strtol.lo"
	AC_DEFINE(LINUX_KERNEL_MODULE,1,[Define if compiling for linux kernel])
	kernel_build=true
	enable_shared=no
	;;
*)
	AC_MSG_WARN("--enable-kernel-build ignored on non Linux platforms")
	;;
esac
])
AM_CONDITIONAL(KERNEL, test x$kernel_build = xtrue)

dnl Configure libtool
AC_LIBTOOL_WIN32_DLL
AM_PROG_LIBTOOL
LIBTOOL="$LIBTOOL --silent"
AC_SUBST(LIBTOOL_DEPS)

CPPFLAGS="$CPPFLAGS -DATL_SOURCE"
LIB_PRE=lib
LIB_POST=.a
case "$host_os" in
  winnt* | cygwin | mingw* )
    if test "$GCC" = no ; then
	LIB_POST=".lib"
	LIB_PRE=""
    fi
    SOCKET_LIBS="$LIBS -lwsock32 -luser32 -ladvapi32"
    ;;
esac

AC_SUBST(KERNEL_OBJS)
AC_SUBST(KERNEL_VERSION)

dnl Checks for libraries.
CERCS_REQUIRE_PACKAGE(cercs_env, cercs_env.h,libcercs_env.la)
if test -n "$cercs_cv_cercs_env_link_dir"; then
LDFLAGS="$LDFLAGS -L$cercs_cv_cercs_env_link_dir"
CERCS_ENV_LIB="-lcercs_env"
fi
if test -n "$cercs_cv_gen_thread_link_arg"; then
THREAD_LIBS="-lgen_thread"
fi

checkBoth=0
AC_CHECK_FUNCS(fork gethostname)
AC_CHECK_FUNC(connect, checkSocket=0, checkSocket=1)
save_libs=$LIBS;
if test "$checkSocket" = 1; then
    AC_CHECK_LIB(socket, connect, LIBS="$LIBS -lsocket", checkBoth=1)
    if test "$checkBoth" = 1; then
        oldLibs=$LIBS
        LIBS="$LIBS -lsocket -lnsl"
        AC_CHECK_FUNC(accept, checkNsl=0, [LIBS=$oldLibs])
    fi
   AC_CHECK_FUNC(gethostbyname, , AC_CHECK_LIB(nsl, getdomainname, [LIBS="$LIBS -lnsl"]))
fi
SOCKET_LIBS="$SOCKET_LIBS $LIBS"
LIBS=$save_libs
AC_SUBST(SOCKET_LIBS)
dnl Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS(malloc.h sys/time.h unistd.h windows.h)

dnl Checks for typedefs, structures, and compiler characteristics.
AC_C_BIGENDIAN_CROSS($bigendian_default)
AC_COMPILE_CHECK_SIZEOF(int)
AC_COMPILE_CHECK_SIZEOF(short)
AC_COMPILE_CHECK_SIZEOF(float)
AC_COMPILE_CHECK_SIZEOF(double)
AC_C_CONST
AC_PUTENV_DEFINED
AC_SSCANF_DEFINED

dnl Checks for library functions.
AC_TYPE_SIGNAL

AC_ARG_WITH(atom_server, [  --with-atom-server=HOST    Which host will run the atom server.],ATOM_SERVER_HOST=$withval)

if test "x$ATOM_SERVER_HOST" = "x"; then
   hostname=`hostname`
   domainname=""
   host_no_domain=`hostname|sed 's/\..*//g'`
   if test "$hostname" != "$host_no_domain"; then
      # A fully qualified hostname?
      domainname=`hostname|sed "s/$host_no_domain.//"`
      hostname=$host_no_domain
   fi
   if test x"$domainname" = "x"; then
	if eval dnsdomainname 2>/dev/null 1>/dev/null; then
	    # dnsdomainname command, try it
	    domainname=`dnsdomainname`
	fi
   fi
   if test x"$domainname" = "x"; then
	if eval domainname 2>/dev/null 1>/dev/null; then
	    domainname=`domainname`
	fi
   fi
   if test x"$hostname" = "x"; then
	hostname="localhost"
   fi
   if test x"$domainname" = "x"; then
      # domainname is still not set, try this
      domainname=[`nslookup $hostname 2>/dev/null | grep Name: | sed 's/.*: *[^.]*.//g'`]
   fi

   highdomain=`echo $domainname | sed 's/\./\\
./g' | tail -2 `
    highdomain=`echo $highdomain | sed 's/ //g'`
   if test "x$highdomain" = "x.gatech.edu"; then
      ATOM_SERVER_HOST="atomhost.cercs.gatech.edu";
      ATOM_SERVICE_DOMAIN="gt.atl.ga.us:gatech.edu";
   else
      if test "x$domainname" != "x"; then
          ATOM_SERVER_HOST=$hostname.$domainname
      else
          ATOM_SERVER_HOST=$hostname
      fi
   fi
fi
AC_ARG_WITH(service_domain, [  --with-service-domain=DOMAINNAME	What domain the server will serve.],ATOM_SERVER_DOMAIN=$withval)
AC_DEFINE_UNQUOTED(ATOM_SERVER_HOST, "$ATOM_SERVER_HOST", [Define with the name of the host which will run the atom server])
AC_DEFINE_UNQUOTED(ATOM_SERVICE_DOMAIN, "$ATOM_SERVICE_DOMAIN", [Define with the name of the domain which the atom server will service])
SERVER_LIBS=$LIBS
AC_SUBST(SERVER_LIBS)
AC_SUBST(THREAD_LIBS)
AC_SUBST(CERCS_ENV_LIB)

AC_CONFIG_FILES(Makefile)
AC_OUTPUT
