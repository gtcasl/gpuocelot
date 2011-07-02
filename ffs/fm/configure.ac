# Process this file with autoconf to produce a configure script.
#
AC_INIT([ffs],[1.0],[eisen@cc.gatech.edu])
AC_CONFIG_SRCDIR([fm.h])
AC_CONFIG_AUX_DIR(../config)
AC_CONFIG_MACRO_DIR([../config])
AM_INIT_AUTOMAKE([ffs],[1.0])
AM_MAINTAINER_MODE
AM_CONFIG_HEADER(config.h)

#

AC_ARG_WITH(--with-authentication, 
[ --with-authentication            Find gcrypt and do encrypted authenticated.],with_authentication=yes,with_authentication=no)

IO_FILE_NAME=unix_io

# checks for programs
AC_PROG_INSTALL
AC_LN_S
test x"$ac_cv_prog_gcc" = xyes && CWARNFLAGS="-Wall"
AC_SUBST(CWARNFLAGS)
AC_CHECK_PROGS(MAKEDEPEND, makedepend, :)
#
# checks for libraries
CERCS_REQUIRE_PACKAGE(cercs_env,cercs_env.h,libcercs_env.la)

CPPFLAGS="$CPPFLAGS"
#
checkBoth=0
AC_CHECK_FUNC(connect, checkSocket=0, checkSocket=1)
if test "$checkSocket" = 1; then
    AC_CHECK_LIB(socket, connect, LIBS="$LIBS -lsocket", checkBoth=1)
fi
if test "$checkBoth" = 1; then
    oldLibs=$LIBS
    LIBS="$LIBS -lsocket -lnsl"
    AC_CHECK_FUNC(accept, checkNsl=0, [LIBS=$oldLibs;NO_SOCKET=true;
AC_DEFINE(NO_SOCKET,1,[Define if there is no socket support])])
fi
AC_CHECK_FUNC(gethostbyname, , AC_CHECK_LIB(nsl, getdomainname, [LIBS="$LIBS -lnsl"]))
AM_CONDITIONAL(NO_SOCKETS, test x$NO_SOCKET = xtrue)
AC_CHECK_FUNCS(getdomainname gethostbyname)
oldLibs=$LIBS
LIBS=""
AC_CHECK_FUNCS(strtof strtod strtold)
LIBS=$oldLibs

LT_INIT

# checks for header files
AC_HEADER_STDC
AC_CHECK_HEADERS(string.h memory.h malloc.h sys/select.h sys/socket.h \
		sys/time.h sys/times.h unistd.h sys/uio.h windows.h \
		sys/un.h netdb.h netinet/in.h winsock.h sockLib.h)
AC_SUBST(IO_FILE_NAME)

if test x"$with_authentication" = xyes; then
CERCS_REQUIRE_OTHER_PACKAGE(gcrypt,gcrypt.h,libgcrypt.a)
fi
#
# Configuration for format server authentication
#
AC_ARG_ENABLE(passphrase-authentication,AC_HELP_STRING([--enable-passphrase-authentication],[Enable passphrase-based authentication for the format server]),
[ 
case "$enableval" in
   yes) passphrase_authentication=true ;;
   no)  passphrase_authentication=false ;;
   *)   AC_MSG_ERROR("Invalid value $enableval for --enable-passphrase-authentication")  ;;
esac
],[passphrase_authentication=false])

if test x"$with_authentication" = xyes; then
echo "check authentication $with_authentication"
#  Find OpenSSL and test it for our encryption functions
AC_MSG_CHECKING(for gcry_cipher_close() in libgcrypt)
TMP_LIBS=$LIBS
LIBS="-lgcrypt"
AC_LANG_PUSH([C])
AC_TRY_LINK([
        #include "gcrypt.h"
        ],[
	gcry_cipher_hd_t handle;
	gcry_cipher_close( handle );
        ],[
        AC_MSG_RESULT(yes)
        LIBS="-lgcrypt $TMP_LIBS"
        AC_DEFINE(USE_ENCRYPTED_AUTHENTICATOR,1,[Use encryption-based authentication for the format server])
        ],[
        AC_MSG_RESULT([not found])
        passphrase_authentication=false
        LIBS="$TMP_LIBS"
        ])
AC_LANG_POP([C])
fi

# checks for typedefs, structures and compiler characteristics
AC_C_CONST
AC_C_BIGENDIAN_CROSS($bigendian_default)
AC_HAS_STRUCT_HOSTENT
AC_COMPILE_CHECK_SIZEOF(int)
AC_COMPILE_CHECK_SIZEOF(long)
AC_COMPILE_CHECK_SIZEOF(long long)
AC_COMPILE_CHECK_SIZEOF(long double)
AC_COMPILE_CHECK_SIZEOF(float)
AC_COMPILE_CHECK_SIZEOF(double)
AC_TYPE_PID_T
LIBS="$LIBS -lcercs_env"
AC_ARG_WITH(format_server, [  --with-format-server=HOST    Which host will run the format server.],FORMAT_SERVER_HOST=$withval)

if test "x$FORMAT_SERVER_HOST" = "x"; then
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
      FORMAT_SERVER_HOST="formathost.cercs.gatech.edu";
      FORMAT_SERVICE_DOMAIN=".edu:.com:.gov:.mil:.net:.org:.us";
   else
      # They didn't specify a format host, they're not in a Tech domain
      # use a local proxy, or fallback to formathost.cercs.gatech.edu
      FORMAT_SERVER_HOST=localhost
   fi
fi
AC_ARG_WITH(service_domain, [  --with-service-domain=DOMAINNAME	What domain the server will serve.],FORMAT_SERVICE_DOMAIN=$withval)
AC_DEFINE_UNQUOTED(FORMAT_SERVER_HOST, "$FORMAT_SERVER_HOST", [Define with the name of the host which will run the format server])
AC_DEFINE_UNQUOTED(FORMAT_SERVICE_DOMAIN, "$FORMAT_SERVICE_DOMAIN", [Define with the name of the domain which the format server will service])

AC_CONFIG_FILES([Makefile progs/Makefile tests/Makefile])
AC_OUTPUT

