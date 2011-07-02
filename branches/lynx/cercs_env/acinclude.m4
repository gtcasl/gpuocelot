dnl
dnl  examples
dnl  AC_DEFINE_DIR(DATADIR, datadir)
dnl  AC_DEFINE_DIR(PROG_PATH, bindir, [Location of installed binaries])
dnl
AC_DEFUN([AC_DEFINE_DIR], [
               ac_expanded=`(
                   test "x$prefix" = xNONE && prefix="$ac_default_prefix"
                   test "x$exec_prefix" = xNONE && exec_prefix="${prefix}"
                   eval echo \""[$]$2"\"
               )`
               ifelse($3, ,
                 AC_DEFINE_UNQUOTED($1, "$ac_expanded"),
                 AC_DEFINE_UNQUOTED($1, "$ac_expanded", $3))
       ])
AC_DEFUN([AC_COMPILE_WARNINGS],
       [AC_MSG_CHECKING(maximum warning verbosity option)
       if test -n "$CXX"
       then
         if test "$GXX" = "yes"
         then
           ac_compile_warnings_opt='-Wall'
         fi
         CXXFLAGS="$CXXFLAGS $ac_compile_warnings_opt"
         ac_compile_warnings_msg="$ac_compile_warnings_opt for C++"
       fi

       if test -n "$CC"
       then
         if test "$GCC" = "yes"
         then
           ac_compile_warnings_opt='-Wall'
         fi
         CFLAGS="$CFLAGS $ac_compile_warnings_opt"
         ac_compile_warnings_msg="$ac_compile_warnings_msg $ac_compile_warnings_opt for C"
       fi
       AC_MSG_RESULT($ac_compile_warnings_msg)
       unset ac_compile_warnings_msg
       unset ac_compile_warnings_opt
       ])
