#!/bin/bash
#
# testing.sh: script to test the sudoku solver/creator
#


NUMFUZZTESTS=10



make clean
make

echo "0 0 0 0 0 3 0 0 0 
0 0 8 0 9 0 2 0 0 
0 3 0 4 0 0 0 5 0 
2 0 0 0 1 0 3 0 0 
0 8 0 9 0 7 0 4 0 
0 0 6 0 3 0 0 0 5
0 4 0 0 0 8 0 6 0 
0 0 1 0 2 0 9 0 0
0 0 0 5 0 0 0 0 0" > testpuzzle1.txt

echo "0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0" > blankpuzzle.txt

# Testing bad inputs

./sudoku solve too many args  # too many args

./sudoku  # not enough args

./sudoku bad_arg # bad argument
make clean

# The prior lines demonstrate that running ./sudoku with invalid args correctly throws an error
##############################"
# Fuzz testing for sudoku generation 

make clean
make fuzzsudoku

./fuzzsudoku ${NUMFUZZTESTS} 
make clean

##############################
# Unit testing for solver

make solverUnitTest
./solverUnitTest < testpuzzle1.txt 
make clean

##############################
# Unit testing for creator


make creatorUnitTest

./creatorUnitTest
make clean

##############################
# Memory leak testing

make
make valgrind

rm -f testpuzzle1.txt
rm -f blankpuzzle.txt
make clean

# Done with all tests!


exit 0