# Makefile for 'set' module
#
# CS50, Summer 2021
# Callie Moody

PROG = settest
OBJS = settest.o set.o ../lib/readlinep.o
LIBS =

CFLAGS = -Wall -pedantic -std=c11 -ggdb $(TESTING) -I../lib
CC = gcc
MAKE = make

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(PROG)

settest.o: set.h ../lib/readlinep.h
set.o: set.h
../lib/readlinep.o: ../lib/readlinep.h

.PHONY: test valgrind clean

test: $(PROG) test.keys
	./$(PROG) < test.keys

valgrind: $(PROG) test.keys
	valgrind ./$(PROG) < test.keys

clean:
	rm -rf *.dSYM
	rm -f *~ *.o
	rm -f $(PROG)