# Testing of chill.c
## Connor Coale, cs50, 21X

### Testing Methodology
We test a few separate modules to ensure our sudoku project is working as intended:
- Arguments parsing
- Fuzz testing
- Solver unit testing
- Creator unit testing
- Memory leak testing

#### Test 1: Arguments parsing
```bash
./sudoku solve too many args &> testing.out # too many args

./sudoku &>> testing.out # not enough args

./sudoku bad_arg &>> testing.out # bad argument
```

#### Test 2: Fuzz testing
```bash
./fuzzsudoku ${NUMFUZZTESTS} >> testing.out
```

#### Test 3: Solver unit testing
```bash
./solverUnitTest < testpuzzle1.txt >> testing.out
```

#### Test 4: Creator unit testing
```bash
./creatorUnitTest >> testing.out
```

#### Test 5: Memory leak testing
```bash
make valgrind &>> testing.out
```
### Testing output
```
usage: ./sudoku solve or ./sudoku create
usage: ./sudoku solve or ./sudoku create
The prior lines demonstrate that running ./sudoku with invalid args correctly throws an error
##############################
Fuzz testing for sudoku generation
Fuzzsudoku Testing Creator and Solver
Running 10 tests.
=================
Test #1:
Creating a random board:

3 0 6 0 7 0 9 8 5 
4 7 0 9 5 0 6 0 0 
0 8 5 3 6 0 0 0 7 
0 1 0 0 0 0 7 6 4 
6 0 7 2 0 0 5 0 8 
0 9 0 6 0 0 0 0 1 
8 5 0 0 0 9 0 1 6 
1 0 0 0 0 6 0 0 9 
7 0 0 1 8 0 0 5 3 

Number of solutions to the generated puzzle (as determined by solve_recursive(): 1 
-----------------
Creating another random board to be sovled by solve_main

3 0 1 8 0 0 2 6 7 
2 0 0 3 0 5 0 8 1 
0 8 0 0 0 7 0 0 0 
6 7 0 0 0 0 3 0 8 
0 2 0 4 8 0 6 0 9 
0 9 0 0 0 6 5 1 4 
7 6 8 9 5 0 1 0 0 
0 1 9 0 0 8 0 0 2 
5 0 0 0 4 0 8 0 6 

Solving board:

3 5 1 8 9 4 2 6 7 
2 4 7 3 6 5 9 8 1 
9 8 6 1 2 7 4 3 5 
6 7 4 5 1 9 3 2 8 
1 2 5 4 8 3 6 7 9 
8 9 3 2 7 6 5 1 4 
7 6 8 9 5 2 1 4 3 
4 1 9 6 3 8 7 5 2 
5 3 2 7 4 1 8 9 6 
Success!

=================
Test #2:
Creating a random board:

7 0 0 0 0 5 0 0 2 
4 5 3 1 0 8 6 7 0 
0 0 0 7 0 0 1 0 3 
0 0 6 2 0 7 5 1 8 
0 0 8 0 0 0 0 0 0 
3 7 5 8 0 0 9 2 0 
1 0 0 0 0 0 3 6 7 
6 3 0 0 7 1 8 4 0 
5 0 7 4 6 3 0 0 0 

Number of solutions to the generated puzzle (as determined by solve_recursive(): 1 
-----------------
Creating another random board to be sovled by solve_main

9 4 0 8 5 1 0 3 0 
0 5 0 0 0 0 2 1 8 
0 0 8 0 0 0 4 9 0 
8 0 3 0 6 4 5 0 0 
1 7 0 0 2 8 3 6 9 
2 0 0 9 3 0 8 0 0 
0 3 0 6 0 0 9 0 0 
0 2 9 4 1 0 0 8 0 
4 8 0 0 0 3 0 0 2 

Solving board:

9 4 2 8 5 1 7 3 6 
6 5 7 3 4 9 2 1 8 
3 1 8 2 7 6 4 9 5 
8 9 3 1 6 4 5 2 7 
1 7 4 5 2 8 3 6 9 
2 6 5 9 3 7 8 4 1 
5 3 1 6 8 2 9 7 4 
7 2 9 4 1 5 6 8 3 
4 8 6 7 9 3 1 5 2 
Success!

=================
Test #3:
Creating a random board:

5 0 0 0 6 4 0 0 0 
2 0 0 5 0 0 0 0 0 
7 4 6 2 8 0 5 1 3 
9 3 1 6 0 0 0 7 8 
0 2 0 1 0 7 3 0 6 
6 7 0 0 0 0 1 2 0 
0 8 7 0 0 0 6 5 9 
4 6 2 0 0 0 8 0 0 
0 0 0 0 3 0 2 4 7 

Number of solutions to the generated puzzle (as determined by solve_recursive(): 1 
-----------------
Creating another random board to be sovled by solve_main

6 7 2 0 0 1 3 5 4 
0 0 0 0 2 5 7 0 1 
0 0 1 0 0 0 2 9 8 
0 0 0 2 0 0 8 4 9 
0 4 8 0 0 0 0 0 7 
7 0 9 6 8 0 0 3 0 
0 3 0 5 4 0 9 8 6 
0 0 0 9 0 8 0 0 3 
9 0 0 3 6 0 5 1 0 

Solving board:

6 7 2 8 9 1 3 5 4 
8 9 3 4 2 5 7 6 1 
4 5 1 7 3 6 2 9 8 
5 1 6 2 7 3 8 4 9 
3 4 8 1 5 9 6 2 7 
7 2 9 6 8 4 1 3 5 
1 3 7 5 4 2 9 8 6 
2 6 5 9 1 8 4 7 3 
9 8 4 3 6 7 5 1 2 
Success!

=================
Test #4:
Creating a random board:

9 0 0 3 6 7 5 0 1 
5 0 0 8 9 4 0 3 2 
4 3 0 1 0 0 8 6 0 
8 0 2 7 0 9 3 0 0 
3 0 1 0 8 0 0 9 0 
0 0 0 5 0 0 0 0 7 
0 0 4 9 0 8 0 0 0 
7 0 5 6 0 3 9 2 0 
1 0 3 0 5 2 0 0 0 

Number of solutions to the generated puzzle (as determined by solve_recursive(): 1 
-----------------
Creating another random board to be sovled by solve_main

6 0 3 0 4 2 5 9 0 
9 8 0 3 0 0 4 0 1 
0 0 0 9 0 7 0 6 3 
0 2 0 0 0 9 3 0 0 
7 9 4 8 0 1 0 5 0 
3 0 5 0 0 6 0 0 0 
1 0 7 6 9 4 0 0 0 
0 0 8 0 0 0 7 4 0 
2 0 9 7 0 8 1 0 6 

Solving board:

6 7 3 1 4 2 5 9 8 
9 8 2 3 6 5 4 7 1 
4 5 1 9 8 7 2 6 3 
8 2 6 5 7 9 3 1 4 
7 9 4 8 3 1 6 5 2 
3 1 5 4 2 6 9 8 7 
1 3 7 6 9 4 8 2 5 
5 6 8 2 1 3 7 4 9 
2 4 9 7 5 8 1 3 6 
Success!

=================
Test #5:
Creating a random board:

0 0 0 0 4 0 0 0 3 
7 0 8 1 0 0 5 4 6 
2 0 0 8 0 0 1 0 9 
3 7 1 0 0 5 0 6 0 
0 0 0 0 1 0 9 0 5 
9 0 5 2 0 0 0 3 1 
8 0 0 0 2 0 0 5 7 
1 5 7 0 3 8 6 9 2 
0 4 0 0 7 9 0 0 8 

Number of solutions to the generated puzzle (as determined by solve_recursive(): 1 
-----------------
Creating another random board to be sovled by solve_main

2 0 7 3 0 0 9 5 0 
0 0 0 0 5 0 4 0 1 
3 0 5 0 0 0 0 0 6 
6 5 0 7 0 0 0 0 9 
7 2 9 0 1 4 5 6 0 
8 3 1 6 0 5 0 2 4 
0 9 0 0 0 0 0 1 0 
1 7 0 4 0 2 6 9 5 
0 0 2 0 8 0 0 0 7 

Solving board:

2 4 7 3 6 1 9 5 8 
9 8 6 2 5 7 4 3 1 
3 1 5 9 4 8 2 7 6 
6 5 4 7 2 3 1 8 9 
7 2 9 8 1 4 5 6 3 
8 3 1 6 9 5 7 2 4 
4 9 3 5 7 6 8 1 2 
1 7 8 4 3 2 6 9 5 
5 6 2 1 8 9 3 4 7 
Success!

=================
Test #6:
Creating a random board:

0 9 0 0 4 3 0 0 2 
3 0 2 7 6 0 5 1 4 
4 7 5 0 2 0 0 6 0 
1 0 4 0 0 0 0 8 9 
0 3 6 0 0 4 0 5 0 
9 5 0 0 0 0 7 4 6 
0 0 0 9 0 1 4 0 0 
0 0 9 4 0 0 0 3 7 
0 4 0 0 3 6 1 0 8 

Number of solutions to the generated puzzle (as determined by solve_recursive(): 1 
-----------------
Creating another random board to be sovled by solve_main

0 1 2 3 4 0 9 5 7 
0 5 6 0 2 9 0 0 0 
0 0 0 5 0 1 2 6 3 
0 9 7 0 1 3 5 0 6 
5 0 0 0 7 0 0 0 0 
1 3 0 2 0 5 0 0 9 
4 0 1 6 0 2 7 3 5 
0 0 3 0 0 0 0 8 4 
0 7 5 0 0 0 0 0 0 

Solving board:

8 1 2 3 4 6 9 5 7 
3 5 6 7 2 9 4 1 8 
7 4 9 5 8 1 2 6 3 
2 9 7 8 1 3 5 4 6 
5 6 8 9 7 4 3 2 1 
1 3 4 2 6 5 8 7 9 
4 8 1 6 9 2 7 3 5 
9 2 3 1 5 7 6 8 4 
6 7 5 4 3 8 1 9 2 
Success!

=================
Test #7:
Creating a random board:

0 0 0 3 0 9 7 8 2 
0 1 9 4 0 7 6 0 0 
0 0 0 2 0 0 1 0 0 
8 3 5 9 4 1 2 0 0 
7 2 0 6 5 0 0 0 0 
0 9 4 8 0 0 0 3 0 
0 0 0 0 9 0 3 2 5 
0 5 3 7 0 0 8 0 9 
9 0 0 0 3 6 4 0 7 

Number of solutions to the generated puzzle (as determined by solve_recursive(): 1 
-----------------
Creating another random board to be sovled by solve_main

8 0 0 0 0 7 4 2 0 
0 0 5 0 4 0 6 0 0 
0 0 6 9 0 3 0 8 0 
0 2 7 3 0 6 9 1 0 
9 1 8 2 7 0 3 0 0 
3 6 0 5 9 0 0 7 0 
0 0 2 0 1 0 5 6 3 
0 0 1 6 0 8 0 0 0 
0 0 9 0 2 0 8 4 1 

Solving board:

8 9 3 1 6 7 4 2 5 
1 7 5 8 4 2 6 3 9 
2 4 6 9 5 3 1 8 7 
5 2 7 3 8 6 9 1 4 
9 1 8 2 7 4 3 5 6 
3 6 4 5 9 1 2 7 8 
7 8 2 4 1 9 5 6 3 
4 5 1 6 3 8 7 9 2 
6 3 9 7 2 5 8 4 1 
Success!

=================
Test #8:
Creating a random board:

0 0 5 3 7 0 0 1 6 
1 0 6 4 0 0 0 8 9 
8 0 3 9 1 6 0 0 0 
0 0 4 0 9 2 0 3 0 
0 2 7 0 0 0 8 4 0 
0 0 1 8 5 4 0 0 2 
0 1 0 5 8 3 2 6 0 
0 0 0 0 6 0 9 0 8 
0 5 8 2 0 0 1 0 0 

Number of solutions to the generated puzzle (as determined by solve_recursive(): 1 
-----------------
Creating another random board to be sovled by solve_main

0 0 6 0 0 9 7 5 0 
5 0 8 4 0 0 1 0 0 
3 2 9 5 7 0 8 6 0 
0 9 0 1 4 0 2 7 5 
8 4 0 3 5 2 0 0 0 
0 5 0 0 0 0 0 4 0 
2 0 4 7 8 0 9 0 1 
7 0 0 9 3 4 5 0 6 
0 0 5 0 0 0 0 0 0 

Solving board:

4 1 6 8 2 9 7 5 3 
5 7 8 4 6 3 1 9 2 
3 2 9 5 7 1 8 6 4 
6 9 3 1 4 8 2 7 5 
8 4 7 3 5 2 6 1 9 
1 5 2 6 9 7 3 4 8 
2 6 4 7 8 5 9 3 1 
7 8 1 9 3 4 5 2 6 
9 3 5 2 1 6 4 8 7 
Success!

=================
Test #9:
Creating a random board:

9 6 0 5 0 8 2 4 1 
0 1 0 0 0 6 3 8 0 
0 0 0 4 2 0 0 9 0 
0 4 3 0 9 0 7 5 0 
0 0 0 7 0 3 0 6 2 
7 0 0 8 1 0 0 0 0 
5 0 4 0 8 0 9 1 6 
6 0 9 1 0 4 0 0 0 
0 8 1 0 6 0 5 0 4 

Number of solutions to the generated puzzle (as determined by solve_recursive(): 1 
-----------------
Creating another random board to be sovled by solve_main

0 6 4 1 0 2 0 9 5 
0 0 0 4 0 0 0 0 0 
3 0 5 0 0 6 2 0 0 
8 3 0 0 0 0 9 1 7 
5 4 1 9 0 3 8 0 2 
9 7 0 6 1 0 5 0 0 
0 5 0 8 0 9 1 0 0 
0 0 8 3 2 7 0 0 0 
2 0 3 0 0 0 7 8 6 

Solving board:

7 6 4 1 8 2 3 9 5 
1 2 9 4 3 5 6 7 8 
3 8 5 7 9 6 2 4 1 
8 3 6 2 5 4 9 1 7 
5 4 1 9 7 3 8 6 2 
9 7 2 6 1 8 5 3 4 
4 5 7 8 6 9 1 2 3 
6 1 8 3 2 7 4 5 9 
2 9 3 5 4 1 7 8 6 
Success!

=================
Test #10:
Creating a random board:

0 0 6 9 2 0 8 0 3 
0 3 0 0 0 0 1 0 6 
5 8 0 0 3 0 7 0 9 
7 1 8 4 0 3 0 6 0 
2 6 3 8 5 7 0 9 1 
4 0 0 0 1 6 0 0 7 
3 2 7 5 0 0 6 0 0 
0 9 0 0 0 4 2 0 0 
6 0 0 0 0 0 0 0 8 

Number of solutions to the generated puzzle (as determined by solve_recursive(): 1 
-----------------
Creating another random board to be sovled by solve_main

2 0 0 6 8 0 0 0 1 
0 7 5 0 0 0 2 0 0 
0 0 8 5 7 0 9 0 0 
3 8 0 0 0 7 5 2 0 
5 4 7 0 9 0 0 3 0 
1 2 9 0 0 8 0 0 6 
0 0 4 8 1 0 0 9 2 
0 6 0 0 2 3 0 4 0 
8 5 0 0 6 9 3 1 0 

Solving board:

2 9 3 6 8 4 7 5 1 
6 7 5 9 3 1 2 8 4 
4 1 8 5 7 2 9 6 3 
3 8 6 1 4 7 5 2 9 
5 4 7 2 9 6 1 3 8 
1 2 9 3 5 8 4 7 6 
7 3 4 8 1 5 6 9 2 
9 6 1 7 2 3 8 4 5 
8 5 2 4 6 9 3 1 7 
Success!

##############################
Unit testing for solver
=================
Generate a random board: 
0 0 9 0 0 0 0 0 0 
0 0 0 2 0 0 1 8 3 
0 0 0 5 0 8 4 9 7 
7 0 4 0 0 0 3 0 0 
0 5 1 6 3 4 0 7 0 
8 9 3 7 0 0 6 1 4 
0 2 0 3 0 6 5 4 1 
6 0 5 4 0 0 9 2 0 
1 0 8 9 0 2 0 0 0 
-----------------
Randomly generated Sudoku Board is being solved by solve_main():
4 8 9 1 7 3 2 6 5 
5 7 6 2 4 9 1 8 3 
3 1 2 5 6 8 4 9 7 
7 6 4 8 9 1 3 5 2 
2 5 1 6 3 4 8 7 9 
8 9 3 7 2 5 6 1 4 
9 2 7 3 8 6 5 4 1 
6 3 5 4 1 7 9 2 8 
1 4 8 9 5 2 7 3 6 
=================
Solving Blank Sudoku Board with solve_recursive
8 2 4 7 5 6 3 1 9 
3 6 1 8 2 9 7 4 5 
7 5 9 4 3 1 2 8 6 
1 9 2 3 6 5 4 7 8 
4 3 6 2 7 8 5 9 1 
5 7 8 1 9 4 6 2 3 
6 4 5 9 1 2 8 3 7 
2 1 7 6 8 3 9 5 4 
9 8 3 5 4 7 1 6 2 
Uniquely filled board shown above.
=================
Reading in a puzzle from stdin... 
0 0 0 0 0 3 0 0 0 
0 0 8 0 9 0 2 0 0 
0 3 0 4 0 0 0 5 0 
2 0 0 0 1 0 3 0 0 
0 8 0 9 0 7 0 4 0 
0 0 6 0 3 0 0 0 5 
0 4 0 0 0 8 0 6 0 
0 0 1 0 2 0 9 0 0 
0 0 0 5 0 0 0 0 0 
-----------------
Solving a the puzzle read from stdin: 
6 2 9 7 5 3 4 1 8 
4 5 8 6 9 1 2 3 7 
1 3 7 4 8 2 6 5 9 
2 9 4 8 1 5 3 7 6 
3 8 5 9 6 7 1 4 2 
7 1 6 2 3 4 8 9 5 
9 4 2 1 7 8 5 6 3 
5 7 1 3 2 6 9 8 4 
8 6 3 5 4 9 7 2 1 
=================
##############################
Unit testing for creator
Creating random, uniquely solvable board:
0 0 9 0 0 0 0 0 0 
0 0 0 2 0 0 1 8 3 
0 0 0 5 0 8 4 9 7 
7 0 4 0 0 0 3 0 0 
0 5 1 6 3 4 0 7 0 
8 9 3 7 0 0 6 1 4 
0 2 0 3 0 6 5 4 1 
6 0 5 4 0 0 9 2 0 
1 0 8 9 0 2 0 0 0 
Number solutions to board: 1
##############################
Memory leak testing
gcc -Wall -pedantic -std=c11 -ggdb     -c -o sudoku.o sudoku.c
gcc -Wall -pedantic -std=c11 -ggdb   sudoku.o common/puzzle.o creator/creator.o solver/solver.o  -o sudoku
valgrind --leak-check=full --show-leak-kinds=all ./sudoku solve < testpuzzle1.txt
==48295== Memcheck, a memory error detector
==48295== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==48295== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==48295== Command: ./sudoku solve
==48295== 
6 2 9 7 5 3 4 1 8 
4 5 8 6 9 1 2 3 7 
1 3 7 4 8 2 6 5 9 
2 9 4 8 1 5 3 7 6 
3 8 5 9 6 7 1 4 2 
7 1 6 2 3 4 8 9 5 
9 4 2 1 7 8 5 6 3 
5 7 1 3 2 6 9 8 4 
8 6 3 5 4 9 7 2 1 
==48295== 
==48295== HEAP SUMMARY:
==48295==     in use at exit: 0 bytes in 0 blocks
==48295==   total heap usage: 94 allocs, 94 frees, 19,380 bytes allocated
==48295== 
==48295== All heap blocks were freed -- no leaks are possible
==48295== 
==48295== For counts of detected and suppressed errors, rerun with: -v
==48295== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
valgrind --leak-check=full --show-leak-kinds=all ./sudoku solve < blankpuzzle.txt
==48318== Memcheck, a memory error detector
==48318== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==48318== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==48318== Command: ./sudoku solve
==48318== 
3 2 9 7 5 6 1 4 8 
1 4 5 8 2 9 7 6 3 
7 8 6 4 3 1 2 5 9 
5 6 1 3 4 7 8 9 2 
4 9 7 6 8 2 5 3 1 
2 3 8 9 1 5 4 7 6 
6 7 2 1 9 4 3 8 5 
8 1 4 5 6 3 9 2 7 
9 5 3 2 7 8 6 1 4 
==48318== 
==48318== HEAP SUMMARY:
==48318==     in use at exit: 0 bytes in 0 blocks
==48318==   total heap usage: 94 allocs, 94 frees, 19,380 bytes allocated
==48318== 
==48318== All heap blocks were freed -- no leaks are possible
==48318== 
==48318== For counts of detected and suppressed errors, rerun with: -v
==48318== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
valgrind --leak-check=full --show-leak-kinds=all ./sudoku create
==48330== Memcheck, a memory error detector
==48330== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==48330== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==48330== Command: ./sudoku create
==48330== 
0 0 0 4 1 5 0 0 7 
0 4 0 2 0 3 5 0 9 
0 0 0 0 0 0 4 2 6 
0 0 0 3 7 0 9 0 0 
9 6 7 0 0 0 3 0 2 
8 0 0 0 2 6 0 0 5 
4 7 2 0 8 0 6 5 0 
3 5 9 0 0 7 2 8 0 
0 8 0 5 3 0 7 0 4 
==48330== 
==48330== HEAP SUMMARY:
==48330==     in use at exit: 0 bytes in 0 blocks
==48330==   total heap usage: 1,023 allocs, 1,023 frees, 48,016 bytes allocated
==48330== 
==48330== All heap blocks were freed -- no leaks are possible
==48330== 
==48330== For counts of detected and suppressed errors, rerun with: -v
==48330== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
Done with all tests!

```
