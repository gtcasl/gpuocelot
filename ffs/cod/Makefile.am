## Process this file with automake to produce Makefile.in

AUTOMAKE_OPTIONS = no-dependencies foreign
ACLOCAL_AMFLAGS = -I ../config

SUBDIRS = . tests

INCLUDES = -I$(srcdir)/../fm
include_HEADERS = cod.h
all-local:
check-local:
install-exec-local:
lib_LTLIBRARIES = libcod.la

noinst_HEADERS = assert.h config.h cod.tab.h cod_internal.h structs.h

DCG_LIBS=@DCG_LIBS@

libcod_la_SOURCES = cod.c cod_node.c cg.c standard.c
libcod_la_LIBADD = $(DCG_LIBS) $(KERNEL_OBJS) 
libcod_la_DEPENDENCIES = $(KERNEL_OBJS)
libcod_la_LDFLAGS =

EXTRA_libcod_la_SOURCES = kcod.c

lex.yy.c: $(srcdir)/cod.l
	@LEX@ $(SPECIAL_LEX_ARGS) $(srcdir)/cod.l

cod.tab.h cod.c: $(srcdir)/cod.y
	$(YACC) -d $(srcdir)/cod.y
	mv y.tab.h cod.tab.h
	mv y.tab.c cod.c

structs.h : $(srcdir)/struct.pl $(srcdir)/cod.structs
	@PERL@ $(srcdir)/struct.pl $(srcdir)/cod.structs

cod_node.c : $(srcdir)/struct.pl $(srcdir)/cod.structs

cod.lo: structs.h lex.yy.c
cod_node.lo: structs.h

LDADD = libcod.la

EXTRA_PROGRAMS = t1 t2 t3 t4 t5 t6

clean-local:
	rm -f lex.yy.c cod.c cod_node.c structs.h

depend:
	makedepend -- $(CPPFLAGS) -- *.c
	etags cg.c cod.y cod_node.c

#
# Below this point are targets used for linux kernel build.
#
kernel_check_target: cod_module.o kernel/undefined_syms
	nm cod_module.o | grep U > /tmp/cur_undefined_syms
	cmp /tmp/cur_undefined_syms kernel/undefined_syms
	rm /tmp/cur_undefined_syms

cod_module.o:	libcod.la
	rm -fr /tmp/cod_build
	mkdir /tmp/cod_build
	cp .libs/libcod.a /tmp/cod_build
	cd /tmp/cod_build ; ar x libcod.a
	cd /tmp/cod_build ; rm libcod.a
	cd /tmp/cod_build ; ld -r *.o -o $@
	cp /tmp/cod_build/cod_module.o .
	rm -fr /tmp/cod_build 

kcod.c:
	rm -f kcod.c
	$(LN_S) kernel/kcod.c kcod.c
