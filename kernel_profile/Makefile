## @file Makefile
## @author Naila Farooqui, naila@cc.gatech.edu
## @date 2011-11-17
## @brief Makefile to build the kernelprofile dynamic library

PREFIX=/usr/local
SONAME=libkernelprofile.so

CC=gcc
CCFLAGS=-fPIC -ggdb -Wall -Werror -Wextra -Wno-unused-parameter -Iinclude/ -I/usr/local/include
LDFLAGS=-lrt -lshmgrp -shared -Wl,-soname,$(SONAME)

all: lib/$(SONAME)

.PHONY: all

lib/$(SONAME):	src/kernel_profile.o 
	mkdir -p lib
	$(CC) $(LDFLAGS) -o $@ $^

src/kernel_profile.o:	src/kernel_profile.c
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	rm -rf lib/ src/*.o

.PHONY: clean

install: all
	install -m 0444 include/kernel_profile.h $(PREFIX)/include
	install -m 0555 lib/$(SONAME) $(PREFIX)/lib
	ldconfig

.PHONY: install

uninstall:
	rm -f $(PREFIX)/include/kernel_profile.h
	rm -f $(PREFIX)/lib/$(SONAME)
	ldconfig
