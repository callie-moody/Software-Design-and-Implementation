# Makefile for 'set' module
#
# CS50, Summer 2021
# Callie Moody

PROG = hashtest
OBJS = hashtest.o hashtable.o ../lib/readlinep.o ../set/set.o jhash.o
LIBS =

CFLAGS = -Wall -pedantic -std=c11 -ggdb $(TESTING) -I../lib
CC = gcc
MAKE = make

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(PROG)

hashtest.o: hashtable.h ../lib/readlinep.h
hashtable.o: hashtable.h ../set/set.h jhash.h
../lib/readlinep.o: ../lib/readlinep.h
../set/set.o: ../set/set.h
jhash.o: jhash.h

.PHONY: test valgrind clean

test: $(PROG) test.keys
	./$(PROG) < test.keys

valgrind: $(PROG) test.keys
	valgrind ./$(PROG) < test.keys

clean:
	rm -rf *.dSYM
	rm -f *~ *.o
	rm -f $(PROG)
