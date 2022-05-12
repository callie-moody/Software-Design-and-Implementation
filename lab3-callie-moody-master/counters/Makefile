# Makefile for 'counters' module
#
# CS50, Summer 2021
# Callie Moody

PROG = countertest
OBJS = countertest.o counters.o 
LIBS =

CFLAGS = -Wall -pedantic -std=c11 -ggdb $(TESTING) -I../lib
CC = gcc
MAKE = make

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

countertest.o: counters.h
counters.o: counters.h

.PHONY: test valgrind clean

test: $(PROG) test.keys
	./$(PROG) < test.keys

valgrind: $(PROG) test.keys
	valgrind ./$(PROG) < test.keys

clean:
	rm -rf *.dSYM
	rm -f *~ *.o
	rm -f $(PROG)