## Process this file with automake to produce Makefile.in

AUTOMAKE_OPTIONS = no-dependencies foreign

noinst_HEADERS = test_funcs.h

INCLUDES = -I$(srcdir)/..

LDADD = ../libfm.la

TESTS = align_test compat_test

if NO_SOCKETS
bin_PROGRAMS = 
else
bin_PROGRAMS = format_test self_format_test align_test compat_test
endif

all-local:
install-exec-local:

format_test_SOURCES = format_test.c test_funcs.c
self_format_test_SOURCES = self_format_test.c test_funcs.c
align_test_SOURCES = align_test.c test_funcs.c
compat_test_SOURCES = compat_test.c test_funcs.c

check_target:

VALGRIND= ../libtool --mode=execute valgrind --tool=memcheck --error-exitcode=1 --quiet --trace-children=yes

valgrind: align_test.valgrind compat_test.valgrind

align_test.valgrind:  align_test@EXEEXT@
	$(VALGRIND) ./align_test 1>/dev/null  2>&1

compat_test.valgrind:  compat_test@EXEEXT@
	$(VALGRIND) ./compat_test 1>/dev/null  2>&1

