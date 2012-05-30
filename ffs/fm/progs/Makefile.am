## Process this file with automake to produce Makefile.in

AUTOMAKE_OPTIONS = no-dependencies foreign

LDADD = ../libfm.la

INCLUDES = -I$(srcdir)/..

if !NO_SOCKETS
bin_PROGRAMS = format_server format_dump format_cmd format_info
endif

all-local:
install-exec-local:

format_cmd_LDFLAGS = -static-libtool-libs
format_dump_LDFLAGS = -static-libtool-libs
format_server_LDFLAGS = -static-libtool-libs
