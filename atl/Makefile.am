## Process this file with automake to produce Makefile.in

AUTOMAKE_OPTIONS = no-dependencies foreign
ACLOCAL_AMFLAGS = -I config
INSTALL_HEADER = ${srcdir}/config/install-sh -m 644

noinst_HEADERS = unix_defs.h

libatl_la_SOURCES = atom.c attr.c lookup3.c tclHash.c
libatl_la_DEPENDENCIES = @KERNEL_OBJS@
libatl_la_LIBADD = @KERNEL_OBJS@ @CERCS_ENV_LIB@
libatl_la_LDFLAGS = -no-undefined $(SOCKET_LIBS) $(THREAD_LIBS)

EXTRA_PROGRAMS = atom_check
TESTS = atom_check

atom_check_SOURCES= atom_check.c
atom_check_LDADD= libatl.la

if KERNEL
bin_PROGRAMS = 
BUILT_SOURCES = strtol.c env.c katl.c
install-exec-local: atl_module.o
		install -d /lib/modules/@KERNEL_VERSION@/kernel/misc
		install -c atl_module.o /lib/modules/@KERNEL_VERSION@/kernel/misc
all-local: atl_module.o
check-local: kernel_check_target
MOSTLYCLEANFILES = atl_module.o
else
lib_LTLIBRARIES = libatl.la
bin_PROGRAMS = attr_test atom_test atom_server attr_dump
include_HEADERS = atl.h
all-local:
check-local:
install-exec-local:
endif

LIBS = @LIBS@

kernel_check_target: atl_module.o kernel/undefined_syms
	nm atl_module.o | grep U > /tmp/cur_undefined_syms
	cmp /tmp/cur_undefined_syms kernel/undefined_syms
	rm /tmp/cur_undefined_syms

atl_module.o:	libatl.la
	rm -fr /tmp/atl_build
	mkdir /tmp/atl_build
	cp .libs/libatl.a /tmp/atl_build
	cd /tmp/atl_build ; ar x libatl.a
	cd /tmp/atl_build ; rm libatl.a
	cd /tmp/atl_build ; ld -r *.o -o $@
	cp /tmp/atl_build/atl_module.o .
	rm -fr /tmp/atl_build 

strtol.c:
	rm -f strtol.c
	$(LN_S) kernel/strtol.c strtol.c

env.c: katl.h
	rm -f env.c
	$(LN_S) kernel/env.c env.c

katl.c: katl.h
	rm -f katl.c
	$(LN_S) kernel/katl.c katl.c

katl.h:
	rm -f katl.h
	$(LN_S) kernel/katl.h katl.h

attr_test_SOURCES = attr_test.c
attr_test_LDADD =  libatl.la
attr_test_LDFLAGS = 
attr_test_DEPENDENCIES = libatl.la

atom_test_SOURCES = atom_test.c
atom_test_LDADD =  libatl.la
atom_test_LDFLAGS = 
atom_test_DEPENDENCIES = libatl.la

attr_dump_LDADD =  libatl.la
attr_dump_DEPENDENCIES =  libatl.la

atom_server_SOURCES = atom_server.c
atom_server_LDADD =  $(SOCKET_LIBS) tclHash.$(OBJEXT) @CERCS_ENV_LIB@
atom_server_LDFLAGS = -static
atom_server_DEPENDENCIES = tclHash.$(OBJEXT)

libtool: $(LIBTOOL_DEPS)
	$(SHELL) ./config.status --recheck
