AC_DEFUN([AC_FPRINTF_DEFINED],
[AC_MSG_CHECKING(whether stdio.h declares fprintf)
AC_CACHE_VAL(ac_cv_fprintf_found,
[AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]fprintf[^a-zA-Z_]>>changequote([, ])dnl
, stdio.h, ac_cv_fprintf_found=yes, ac_cv_fprintf_found=no)
])
AC_MSG_RESULT($ac_cv_fprintf_found)
if test $ac_cv_fprintf_found = yes; then
   AC_DEFINE(FPRINTF_DEFINED,1, [define if stdio.h declares fprintf])
fi
])dnl
AC_DEFUN([AC_ALARM_DEFINED],
[AC_MSG_CHECKING(whether unistd.h declares alarm)
AC_CACHE_VAL(ac_cv_alarm_found,
[AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]alarm[^a-zA-Z_]>>changequote([, ])dnl
, unistd.h, ac_cv_alarm_found=yes, ac_cv_alarm_found=no)
])
AC_MSG_RESULT($ac_cv_alarm_found)
if test $ac_cv_alarm_found = yes; then
   AC_DEFINE(ALARM_DEFINED,1,[define if unistd.h declares alarm])
fi
])dnl
AC_DEFUN([AC_PUTENV_DEFINED],
[AC_MSG_CHECKING(whether unistd.h or stdlib.h declares putenv)
AC_CACHE_VAL(ac_cv_putenv_found,
[AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]putenv[^a-zA-Z_]>>changequote([, ])dnl
, stdlib.h, ac_cv_putenv_found=yes, ac_cv_putenv_found=no)
if test $ac_cv_putenv_found != yes; then
AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]putenv[^a-zA-Z_]>>changequote([, ])dnl
, unistd.h, ac_cv_putenv_found=yes, ac_cv_putenv_found=no)
fi
])
AC_MSG_RESULT($ac_cv_putenv_found)
if test $ac_cv_putenv_found = yes; then
   AC_DEFINE(PUTENV_DEFINED,1,[define if unistd.h or stdlib.h declares putenv])
fi
])dnl
dnl
AC_DEFUN([AC_FSCANF_DEFINED],
[AC_MSG_CHECKING(whether stdio.h declares fscanf)
AC_CACHE_VAL(ac_cv_fscanf_found,
[AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]fscanf[^a-zA-Z_]>>changequote([, ])dnl
, stdio.h, ac_cv_fscanf_found=yes, ac_cv_fscanf_found=no)
])
AC_MSG_RESULT($ac_cv_fscanf_found)
if test $ac_cv_fscanf_found = yes; then
   AC_DEFINE(FSCANF_DEFINED,1, [define if stdio.h declares fprintf])
fi
])dnl
AC_DEFUN([AC_PRINTF_DEFINED],
[AC_MSG_CHECKING(whether stdio.h declares printf)
AC_CACHE_VAL(ac_cv_printf_found,
[AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]printf[^a-zA-Z_]>>changequote([, ])dnl
, stdio.h, ac_cv_printf_found=yes, ac_cv_printf_found=no)
])
AC_MSG_RESULT($ac_cv_printf_found)
if test $ac_cv_printf_found = yes; then
   AC_DEFINE(PRINTF_DEFINED,1,[define if stdio.h declares printf])
fi
])dnl
AC_DEFUN([AC_WRITE_DEFINED],
[AC_MSG_CHECKING(whether unistd.h declares write)
AC_CACHE_VAL(ac_cv_write_found,
[AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]write[^a-zA-Z_]>>changequote([, ])dnl
, unistd.h, ac_cv_write_found=yes, ac_cv_write_found=no)
])
AC_MSG_RESULT($ac_cv_write_found)
if test $ac_cv_write_found = yes; then
   AC_DEFINE(WRITE_DEFINED,1,[define if unistd.h declares write])
fi
])dnl
AC_DEFUN([AC_WRITEV_DEFINED],
[AC_MSG_CHECKING(whether unistd.h or sys/uio.h declares writev)
AC_CACHE_VAL(ac_cv_writev_found,
[AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]writev[^a-zA-Z_]>>changequote([, ])dnl
, sys/uio.h, ac_cv_writev_found=yes, ac_cv_writev_found=no)
if test $ac_cv_writev_found != yes; then
AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]writev[^a-zA-Z_]>>changequote([, ])dnl
, unistd.h, ac_cv_writev_found=yes, ac_cv_writev_found=no)
fi
])
AC_MSG_RESULT($ac_cv_writev_found)
if test $ac_cv_writev_found = yes; then
   AC_DEFINE(WRITEV_DEFINED,1,[define if unistd.h or sys/uio.h declares writev])
fi
])dnl
AC_DEFUN([AC_READ_DEFINED],
[AC_MSG_CHECKING(whether unistd.h declares read)
AC_CACHE_VAL(ac_cv_read_found,
[AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]read[^a-zA-Z_]>>changequote([, ])dnl
, unistd.h, ac_cv_read_found=yes, ac_cv_read_found=no)
])
AC_MSG_RESULT($ac_cv_read_found)
if test $ac_cv_read_found = yes; then
   AC_DEFINE(READ_DEFINED,1,[define if unistd.h declares read])
fi
])dnl
AC_DEFUN([AC_READV_DEFINED],
[AC_MSG_CHECKING(whether unistd.h or sys/uio.h declares readv)
AC_CACHE_VAL(ac_cv_readv_found,
[AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]readv[^a-zA-Z_]>>changequote([, ])dnl
, sys/uio.h, ac_cv_readv_found=yes, ac_cv_readv_found=no)
if test $ac_cv_readv_found != yes; then
AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]readv[^a-zA-Z_]>>changequote([, ])dnl
, unistd.h, ac_cv_readv_found=yes, ac_cv_readv_found=no)
fi
])
AC_MSG_RESULT($ac_cv_readv_found)
if test $ac_cv_readv_found = yes; then
   AC_DEFINE(READV_DEFINED,1,[define if unistd.h or sys/uio.h declares readv])
fi
])dnl
dnl
])dnl
AC_DEFUN([AC_SSCANF_DEFINED],
[AC_MSG_CHECKING(whether stdio.h declares sscanf)
AC_CACHE_VAL(ac_cv_sscanf_found,
[AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]sscanf[^a-zA-Z_]>>changequote([, ])dnl
, stdio.h, ac_cv_sscanf_found=yes, ac_cv_sscanf_found=no)
])
AC_MSG_RESULT($ac_cv_sscanf_found)
if test $ac_cv_sscanf_found = yes; then
   AC_DEFINE(SSCANF_DEFINED,1,[define if stdio.h declares sscanf])
fi
])dnl
AC_DEFUN([AC_SPRINTF_DEFINED],
[AC_MSG_CHECKING(whether stdio.h declares sprintf)
AC_CACHE_VAL(ac_cv_sprintf_found,
[AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]sprintf[^a-zA-Z_]>>changequote([, ])dnl
, stdio.h, ac_cv_sprintf_found=yes, ac_cv_sprintf_found=no)
])
AC_MSG_RESULT($ac_cv_sprintf_found)
if test $ac_cv_sprintf_found = yes; then
   AC_DEFINE(SPRINTF_DEFINED,1,[define if sprintf is declared in stdio.h])
fi
])dnl
AC_DEFUN([AC_STRDUP_DEFINED],
[AC_MSG_CHECKING(whether string.h declares strdup)
AC_CACHE_VAL(ac_cv_strdup_found,
[AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]strdup[^a-zA-Z_]>>changequote([, ])dnl
, string.h, ac_cv_strdup_found=yes, ac_cv_strdup_found=no)
])
AC_MSG_RESULT($ac_cv_strdup_found)
if test $ac_cv_strdup_found = yes; then
   AC_DEFINE(STRDUP_DEFINED,1,[define if string.h declares strdup])
fi
])dnl
AC_DEFUN([AC_BZERO_DEFINED],
[AC_MSG_CHECKING(whether string.h declares bzero)
AC_CACHE_VAL(ac_cv_bzero_found,
[AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]bzero[^a-zA-Z_]>>changequote([, ])dnl
, string.h, ac_cv_bzero_found=yes, ac_cv_bzero_found=no)
])
AC_MSG_RESULT($ac_cv_bzero_found)
if test $ac_cv_bzero_found = yes; then
   AC_DEFINE(BZERO_DEFINED,1,[define if string.h declares bzero])
fi
])dnl
AC_DEFUN([AC_BCOPY_DEFINED],
[AC_MSG_CHECKING(whether string.h declares bcopy)
AC_CACHE_VAL(ac_cv_bcopy_found,
[AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]bcopy[^a-zA-Z_]>>changequote([, ])dnl
, string.h, ac_cv_bcopy_found=yes, ac_cv_bcopy_found=no)
])
AC_MSG_RESULT($ac_cv_bcopy_found)
if test $ac_cv_bcopy_found = yes; then
   AC_DEFINE(BCOPY_DEFINED,1,[define if string.h declares bcopy])
fi
])dnl
dnl
AC_DEFUN([AC_GETDOMAINNAME_DEFINED],
[AC_MSG_CHECKING(whether unistd.h declares getdomainname)
AC_CACHE_VAL(ac_cv_getdomainname_found,
[AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]getdomainname[^a-zA-Z_]>>changequote([, ])dnl
, unistd.h, ac_cv_getdomainname_found=yes, ac_cv_getdomainname_found=no)
])
AC_MSG_RESULT($ac_cv_getdomainname_found)
if test $ac_cv_getdomainname_found = yes; then
   AC_DEFINE(GETDOMAINNAME_DEFINED,1,[define if unistd.h declares getdomainname])
fi
])dnl
dnl
AC_DEFUN([AC_GETHOSTNAME_DEFINED],
[AC_MSG_CHECKING(whether unistd.h declares gethostname)
AC_CACHE_VAL(ac_cv_gethostname_found,
[AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]gethostname[^a-zA-Z_]>>changequote([, ])dnl
, unistd.h, ac_cv_gethostname_found=yes, ac_cv_gethostname_found=no)
])
AC_MSG_RESULT($ac_cv_gethostname_found)
if test $ac_cv_gethostname_found = yes; then
   AC_DEFINE(GETHOSTNAME_DEFINED,1,[define if unistd.h declares gethostname])
fi
])dnl
dnl
AC_DEFUN([AC_GETPEERNAME_DEFINED],
[AC_MSG_CHECKING(whether sys/socket.h declares getpeername)
AC_CACHE_VAL(ac_cv_getpeername_found,
[AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]getpeername[^a-zA-Z_]>>changequote([, ])dnl
, sys/socket.h, ac_cv_getpeername_found=yes, ac_cv_getpeername_found=no)
])
AC_MSG_RESULT($ac_cv_getpeername_found)
if test $ac_cv_getpeername_found = yes; then
   AC_DEFINE(GETPEERNAME_DEFINED,1,[define if sys/socket.h declares getpeername])
fi
])dnl
AC_DEFUN([AC_GETTIMEOFDAY_DEFINED],
[AC_MSG_CHECKING(whether sys/time.h declares gettimeofday)
AC_CACHE_VAL(ac_cv_gettimeofday_found,
[AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]gettimeofday[^a-zA-Z_]>>changequote([, ])dnl
, sys/time.h, ac_cv_gettimeofday_found=yes, ac_cv_gettimeofday_found=no)
])
AC_MSG_RESULT($ac_cv_gettimeofday_found)
if test $ac_cv_gettimeofday_found = yes; then
   AC_DEFINE(GETTIMEOFDAY_DEFINED,1,[define if sys/time.h declares gettimeofday])
fi
])dnl
AC_DEFUN([AC_ON_EXIT_DEFINED],
[AC_MSG_CHECKING(whether stdlib.h declares on_exit)
AC_CACHE_VAL(ac_cv_on_exit_found,
[AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]on_exit[^a-zA-Z_]>>changequote([, ])dnl
, stdlib.h, ac_cv_on_exit_found=yes, ac_cv_on_exit_found=no)
])
AC_MSG_RESULT($ac_cv_on_exit_found)
if test $ac_cv_on_exit_found = yes; then
   AC_DEFINE(ON_EXIT_DEFINED,1,[define if stdlib.h declares on_exit])
fi
])
dnl
dnl
AC_DEFUN([AC_RECV_DEFINED],
[AC_MSG_CHECKING(whether sys/socket.h declares recv)
AC_CACHE_VAL(ac_cv_recv_found,
[AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]recv[^a-zA-Z_]>>changequote([, ])dnl
, sys/socket.h, ac_cv_recv_found=yes, ac_cv_recv_found=no)
])
AC_MSG_RESULT($ac_cv_recv_found)
if test $ac_cv_recv_found = yes; then
   AC_DEFINE(RECV_DEFINED,1,[define if sys/socket.h declares recv])
fi
])dnl
dnl
AC_DEFUN([AC_RECVFROM_DEFINED],
[AC_MSG_CHECKING(whether sys/socket.h declares recvfrom)
AC_CACHE_VAL(ac_cv_recvfrom_found,
[AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]recvfrom[^a-zA-Z_]>>changequote([, ])dnl
, sys/socket.h, ac_cv_recvfrom_found=yes, ac_cv_recvfrom_found=no)
])
AC_MSG_RESULT($ac_cv_recvfrom_found)
if test $ac_cv_recvfrom_found = yes; then
   AC_DEFINE(RECVFROM_DEFINED,1,[define if sys/socket.h declares recvfrom])
fi
])dnl
dnl
AC_DEFUN([AC_SELECT_DEFINED],
[AC_MSG_CHECKING(whether unistd.h or sys/select.h declares select)
AC_CACHE_VAL(ac_cv_select_found,
[AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]select[^a-zA-Z_]>>changequote([, ])dnl
, sys/select.h, ac_cv_select_found=yes, ac_cv_select_found=no)
if test $ac_cv_select_found != yes; then
AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]select[^a-zA-Z_]>>changequote([, ])dnl
, unistd.h, ac_cv_select_found=yes, ac_cv_select_found=no)
fi
])
AC_MSG_RESULT($ac_cv_select_found)
if test $ac_cv_select_found = yes; then
   AC_DEFINE(SELECT_DEFINED,1,[define if unistd.h or sys/select.h declares select])
fi
])dnl
dnl
dnl
AC_DEFUN([AC_SEND_DEFINED],
[AC_MSG_CHECKING(whether sys/socket.h declares send)
AC_CACHE_VAL(ac_cv_send_found,
[AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]send[^a-zA-Z_]>>changequote([, ])dnl
, sys/socket.h, ac_cv_send_found=yes, ac_cv_send_found=no)
])
AC_MSG_RESULT($ac_cv_send_found)
if test $ac_cv_send_found = yes; then
   AC_DEFINE(SEND_DEFINED,1,[define if sys/socket.h declares send])
fi
])dnl
dnl
AC_DEFUN([AC_SENDTO_DEFINED],
[AC_MSG_CHECKING(whether sys/socket.h declares sendto)
AC_CACHE_VAL(ac_cv_sendto_found,
[AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]sendto[^a-zA-Z_]>>changequote([, ])dnl
, sys/socket.h, ac_cv_sendto_found=yes, ac_cv_sendto_found=no)
])
AC_MSG_RESULT($ac_cv_sendto_found)
if test $ac_cv_sendto_found = yes; then
   AC_DEFINE(SENDTO_DEFINED,1,[define if sys/socket.h declares sendto])
fi
])dnl
dnl
AC_DEFUN([AC_ACCEPT_DEFINED],
[AC_MSG_CHECKING(whether sys/socket.h declares accept)
AC_CACHE_VAL(ac_cv_accept_found,
[AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]accept[^a-zA-Z_]>>changequote([, ])dnl
, sys/socket.h, ac_cv_accept_found=yes, ac_cv_accept_found=no)
])
AC_MSG_RESULT($ac_cv_accept_found)
if test $ac_cv_accept_found = yes; then
   AC_DEFINE(ACCEPT_DEFINED,1,[define if sys/socket.h declares accept])
fi
])dnl
dnl
AC_DEFUN([AC_CONNECT_DEFINED],
[AC_MSG_CHECKING(whether sys/socket.h declares connect)
AC_CACHE_VAL(ac_cv_connect_found,
[AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]connect[^a-zA-Z_]>>changequote([, ])dnl
, sys/socket.h, ac_cv_connect_found=yes, ac_cv_connect_found=no)
])
AC_MSG_RESULT($ac_cv_connect_found)
if test $ac_cv_connect_found = yes; then
   AC_DEFINE(CONNECT_DEFINED,1,[define if sys/socket.h declares connect])
fi
])dnl
dnl
AC_DEFUN([AC_SOCKET_DEFINED],
[AC_MSG_CHECKING(whether sys/socket.h declares socket)
AC_CACHE_VAL(ac_cv_socket_found,
[AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]socket[^a-zA-Z_]>>changequote([, ])dnl
, sys/socket.h, ac_cv_socket_found=yes, ac_cv_socket_found=no)
])
AC_MSG_RESULT($ac_cv_socket_found)
if test $ac_cv_socket_found = yes; then
   AC_DEFINE(SOCKET_DEFINED,1,[define if sys/socket.h declares socket])
fi
])dnl
dnl
AC_DEFUN([AC_SETSOCKOPT_DEFINED],
[AC_MSG_CHECKING(whether sys/socket.h declares setsockopt)
AC_CACHE_VAL(ac_cv_setsockopt_found,
[AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]setsockopt[^a-zA-Z_]>>changequote([, ])dnl
, sys/socket.h, ac_cv_setsockopt_found=yes, ac_cv_setsockopt_found=no)
])
AC_MSG_RESULT($ac_cv_setsockopt_found)
if test $ac_cv_setsockopt_found = yes; then
   AC_DEFINE(SETSOCKOPT_DEFINED,1,[define if sys/socket.h declares setsockopt])
fi
])dnl
dnl
AC_DEFUN([AC_GETSOCKNAME_DEFINED],
[AC_MSG_CHECKING(whether sys/socket.h declares getsockname)
AC_CACHE_VAL(ac_cv_getsockname_found,
[AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]getsockname[^a-zA-Z_]>>changequote([, ])dnl
, sys/socket.h, ac_cv_getsockname_found=yes, ac_cv_getsockname_found=no)
])
AC_MSG_RESULT($ac_cv_getsockname_found)
if test $ac_cv_getsockname_found = yes; then
   AC_DEFINE(GETSOCKNAME_DEFINED,1,[define if sys/socket.h declares getsockname])
fi
])dnl
dnl
AC_DEFUN([AC_BIND_DEFINED],
[AC_MSG_CHECKING(whether sys/socket.h declares bind)
AC_CACHE_VAL(ac_cv_bind_found,
[AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]bind[^a-zA-Z_]>>changequote([, ])dnl
, sys/socket.h, ac_cv_bind_found=yes, ac_cv_bind_found=no)
])
AC_MSG_RESULT($ac_cv_bind_found)
if test $ac_cv_bind_found = yes; then
   AC_DEFINE(BIND_DEFINED,1,[define if sys/socket.h declares bind])
fi
])dnl
dnl
AC_DEFUN([AC_FFLUSH_DEFINED],
[AC_MSG_CHECKING(whether stdio.h declares fflush)
AC_CACHE_VAL(ac_cv_fflush_found,
[AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]fflush[^a-zA-Z_]>>changequote([, ])dnl
, stdio.h, ac_cv_fflush_found=yes, ac_cv_fflush_found=no)
])
AC_MSG_RESULT($ac_cv_fflush_found)
if test $ac_cv_fflush_found = yes; then
   AC_DEFINE(FFLUSH_DEFINED,1,[define if stdio.h declares fflush])
fi
])dnl
AC_DEFUN([AC_SCANF_DEFINED],
[AC_MSG_CHECKING(whether stdio.h declares scanf)
AC_CACHE_VAL(ac_cv_scanf_found,
[AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]scanf[^a-zA-Z_]>>changequote([, ])dnl
, stdio.h, ac_cv_scanf_found=yes, ac_cv_scanf_found=no)
])
AC_MSG_RESULT($ac_cv_scanf_found)
if test $ac_cv_scanf_found = yes; then
   AC_DEFINE(SCANF_DEFINED,1,[define if stdio.h declares scanf])
fi
])dnl
AC_DEFUN([AC_FCLOSE_DEFINED],
[AC_MSG_CHECKING(whether stdio.h declares fclose)
AC_CACHE_VAL(ac_cv_fclose_found,
[AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]fclose[^a-zA-Z_]>>changequote([, ])dnl
, stdio.h, ac_cv_fclose_found=yes, ac_cv_fclose_found=no)
])
AC_MSG_RESULT($ac_cv_fclose_found)
if test $ac_cv_fclose_found = yes; then
   AC_DEFINE(FCLOSE_DEFINED,1, [define if stdio.h declares fclose])
fi
])dnl
AC_DEFUN([AC_REWIND_DEFINED],
[AC_MSG_CHECKING(whether stdio.h declares rewind)
AC_CACHE_VAL(ac_cv_rewind_found,
[AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]rewind[^a-zA-Z_]>>changequote([, ])dnl
, stdio.h, ac_cv_rewind_found=yes, ac_cv_rewind_found=no)
])
AC_MSG_RESULT($ac_cv_rewind_found)
if test $ac_cv_rewind_found = yes; then
   AC_DEFINE(REWIND_DEFINED,1, [define if stdio.h declares rewind])
fi
])dnl
AC_DEFUN([AC_PUTS_DEFINED],
[AC_MSG_CHECKING(whether stdio.h declares puts)
AC_CACHE_VAL(ac_cv_puts_found,
[AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]puts[^a-zA-Z_]>>changequote([, ])dnl
, stdio.h, ac_cv_puts_found=yes, ac_cv_puts_found=no)
])
AC_MSG_RESULT($ac_cv_puts_found)
if test $ac_cv_puts_found = yes; then
   AC_DEFINE(PUTS_DEFINED,1,[define if stdio.h declares puts])
fi
])dnl
AC_DEFUN([AC_FPUTS_DEFINED],
[AC_MSG_CHECKING(whether stdio.h declares fputs)
AC_CACHE_VAL(ac_cv_fputs_found,
[AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]fputs[^a-zA-Z_]>>changequote([, ])dnl
, stdio.h, ac_cv_fputs_found=yes, ac_cv_fputs_found=no)
])
AC_MSG_RESULT($ac_cv_fputs_found)
if test $ac_cv_fputs_found = yes; then
   AC_DEFINE(FPUTS_DEFINED,1,[define if stdio.h declares fputs])
fi
])dnl
AC_DEFUN([AC_TIME_DEFINED],
[AC_MSG_CHECKING(whether time.h declares time)
AC_CACHE_VAL(ac_cv_time_found,
[AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]time[^a-zA-Z_]>>changequote([, ])dnl
, time.h, ac_cv_time_found=yes, ac_cv_time_found=no)
])
AC_MSG_RESULT($ac_cv_time_found)
if test $ac_cv_time_found = yes; then
   AC_DEFINE(TIME_DEFINED,1,[define if time.h declares time])
fi
])dnl
AC_DEFUN([AC_SETRLIMIT_DEFINED],
[AC_MSG_CHECKING(whether sys/resource.h declares setrlimit)
AC_CACHE_VAL(ac_cv_setrlimit_found,
[AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]setrlimit[^a-zA-Z_]>>changequote([, ])dnl
, sys/resource.h, ac_cv_setrlimit_found=yes, ac_cv_setrlimit_found=no)
])
AC_MSG_RESULT($ac_cv_setrlimit_found)
if test $ac_cv_setrlimit_found = yes; then
   AC_DEFINE(SETRLIMIT_DEFINED,1, [define if setrlimit is declared in sys/resource.h])
fi
])dnl
AC_DEFUN([AC_LISTEN_DEFINED],
[AC_MSG_CHECKING(whether sys/socket.h declares listen)
AC_CACHE_VAL(ac_cv_listen_found,
[AC_EGREP_HEADER(
changequote(<<, >>)dnl
<<[^a-zA-Z_]listen[^a-zA-Z_]>>changequote([, ])dnl
, sys/socket.h, ac_cv_listen_found=yes, ac_cv_listen_found=no)
])
AC_MSG_RESULT($ac_cv_listen_found)
if test $ac_cv_listen_found = yes; then
   AC_DEFINE(LISTEN_DEFINED,1, [define if listen is declared in sys/socket.h])
fi
])dnl
dnl
AC_DEFUN([AC_HAS_STRUCT_HOSTENT],
[AC_CACHE_CHECK([whether struct hostent is in netdb.h or winsock.h],
  ac_cv_struct_hostent,
[AC_TRY_COMPILE([#include <netdb.h>],
[struct hostent vec;],
  ac_cv_struct_hostent=yes, 
[AC_TRY_COMPILE([#include <winsock.h>],
[struct hostent vec;],
  ac_cv_struct_hostent=yes, ac_cv_struct_hostent=no)])
])]
if test $ac_cv_struct_hostent = yes; then
  AC_DEFINE(HAS_STRUCT_HOSTENT, 1,[define if struct hostent is declared in netdb.h or winsock.h])
fi)
])
AC_DEFUN([AC_STRUCT_FDS_BITS],
[AC_CACHE_CHECK([for fds_bits in fd_set], ac_cv_struct_fds_bits,
[AC_TRY_COMPILE([#include <sys/select.h>], [fd_set s; s.fds_bits[0];],
ac_cv_struct_fds_bits=yes, ac_cv_struct_fds_bits=no)])
if test $ac_cv_struct_fds_bits = yes; then
  AC_DEFINE(HAVE_FDS_BITS,1,[Define if fd_set has element fds_bits])
fi
])
AC_DEFUN([AC_STRUCT_IOVEC],
[AC_CACHE_CHECK([whether struct iovec is in sys/uio.h],
  ac_cv_struct_iovec,
[AC_TRY_COMPILE([#include <sys/types.h>
#include <sys/uio.h>],
[struct iovec *vec;],
  ac_cv_struct_iovec=yes, ac_cv_struct_iovec=no)])
if test $ac_cv_struct_iovec = no; then
  AC_DEFINE(NEED_IOVEC_DEFINE,1,[define if struct iovec is declared in sys/uio.h])
fi
])
