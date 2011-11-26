## @file Makefile
## @author Naila Farooqui, naila@cc.gatech.edu
## @date 2011-11-26
## @brief Makefile to build the message queue test leader app

CC=gcc
CCFLAGS=-fPIC -ggdb -O0 -Wall -Werror -Wextra -Wno-unused-parameter -I/usr/local/include
LDFLAGS=-ggdb -lrt 

all:	leader

leader:	leader.o 
	$(CC) $(LDFLAGS) -o $@ $^
	
src/leader.o:	leader.c
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	rm -rf *.o leader
	
	
