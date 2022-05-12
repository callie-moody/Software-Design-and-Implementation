# Makefile for 'sudoku'
#
# CS50, Summer 2021

PROG = sudoku
OBJS = sudoku.o common/puzzle.o creator/creator.o solver/solver.o
LIBS = 

CFLAGS = -Wall -pedantic -std=c11 -ggdb $(TESTING) #-I../common -I../creator -I../solver
CC = gcc
MAKE = make

TESTINPUTPUZZLE1 = testpuzzle1.txt
BLANKINPUTPUZZLE = blankpuzzle.txt



# $(OBJS): sudoku.c common/puzzle.h solver/solver.h # i added this but have no idea if its right


.PHONY: all test valgrind clean

all: $(PROG)

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

fuzzsudoku: fuzzsudoku.o common/puzzle.o solver/solver.o creator/creator.o
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

solverUnitTest: solver/solverUnitTest.o common/puzzle.o solver/solver.o creator/creator.o
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

creatorUnitTest: creator/creatorUnitTest.o common/puzzle.o solver/solver.o creator/creator.o
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@

solver/solverUnitTest.o: puzzle.o solver.o creator.o

creator/creatorUnitTest.o: puzzle.o solver.o creator.o

fuzzsudoku.o: puzzle.o creator.o solver.o

sudoku.o: puzzle.o solver.o creator.o

puzzle.o: common/puzzle.h

solver.o: solver/solver.h puzzle.o

creator.o: creator/creator.h puzzle.o solver.o



test: 
	bash -v testing.sh &> testing.out

valgrind: $(PROG) testing/input/testpuzzle1.txt
	valgrind --leak-check=full --show-leak-kinds=all ./$(PROG) solve < $(TESTINPUTPUZZLE1)
	valgrind --leak-check=full --show-leak-kinds=all ./$(PROG) solve < $(BLANKINPUTPUZZLE)
	valgrind --leak-check=full --show-leak-kinds=all ./$(PROG) create


clean:
	rm -rf *.dSYM  # MacOS debugger info
	rm -f *~ *.o *.a
	rm -f common/*.[oa]
	rm -f creator/*.[oa]
	rm -f solver/*.[oa]
	rm -f $(PROG)
	rm -f fuzzsudoku
	rm -f creatorUnitTest
	rm -f solverUnitTest

