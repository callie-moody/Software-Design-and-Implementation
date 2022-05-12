# CS50 Final Project: Sudoku
## CS50 Summer 2021, Order of the White Lotus
Vi Tran    
Vanessa Perez-Robles    
Callie Moody    
Connor Coale    

### Sudoku 
#### Overview
From the project page: 
> Sudoku is well known logic puzzle where numbers between 1 and 9 are placed on a 9x9 grid of cells. The placement of numbers has to follow certain rules. There are many variations of Sudoku, but for this project you will be looking at only the most common version of Sudoku. In this version the 9x9 grid is further divided into 9 square shaped regions of size 3x3 as shown below.

Rules:
> In a valid Sudoku grid every number from 1 to 9 must appear: 
>    
> - Only once in every row    
> - Only once in every column    
> - Only once in every 3x3 squared region
> 
> The puzzle is presented as a 9x9 valid grid with some numbers missing. A person or program solving the Sudoku puzzle should fill in the missing numbers without violating above mentioned rules. In the above given picture the numbers in red are filled by a solver.    

#### Project
We have created a C program which can both solve and create sudoku puzzles. The solver is able to read any puzzle in from `stdin`, and if the puzzle is solvable, it will print a solution to `stdout`. The number of solutions is not important as it will solve any solvable puzzle. If the puzzle is not solvable, nothing will be printed. The creator is able to generate a random puzzle with only a single valid solution. It prints this out to `stdout`. It is guaranteed that the puzzle will have 40 blanks and that there is only a single valid solution for the puzzle.

#### Usage
The solver and creator are used as following: 
```bash
$ ./sudoku solve

$ ./sudoku create
```

If the user wishes to more easily load in and save puzzles, he/she may use the following bash shortcuts for input/output redirection:
```bash
$ ./sudoku solve < <input_puzzle_file>

$ ./sudoku create > <output_puzzle_file>
```
\<input_puzzle_file\> and \<output_puzzle_file\> must be normal plaintext files.

#### Assumptions
It is assumed that any puzzle input through stdin to the solver is properly formatted, which is nine lines of nine numbers each separated by a space. As an example: 
> 0 0 0 0 0 3 0 0 0    
0 0 8 0 9 0 2 0 0    
0 3 0 4 0 0 0 5 0    
2 0 0 0 1 0 3 0 0    
0 8 0 9 0 7 0 4 0    
0 0 6 0 3 0 0 0 5    
0 4 0 0 0 8 0 6 0    
0 0 1 0 2 0 9 0 0    
0 0 0 5 0 0 0 0 0    

As an additional assumption for the creator, it is assumed that the the creator will not create multiple puzzles in the same second on the computer's clock. This is because the system's time is used to seed the random number generator. The system time is stored in seconds and returned as an int, so if multiple puzzles are created in the same second, then they will seem identical due to having the same seed. The seed is set in the main function, so this the reason for such performance.

It is assumed that the argument for fuzztester will be a valid integer, and only a valid integer. There is no argument parsing for that testing module.

#### Files
- `Makefile` - compilation procedure
- `sudoku.c` - top level c file, from which the executable is generated
- `DESIGN.md` - contains high level design explanations for the sudoku project
- `IMPLEMENTATION.md` - more specific design explanations and implementation for the sudoku project
- `fuzzsudoku.c` - fuzz tester for the system
- `testing.sh` - bash script to run all tests for sudoku project
- `testing.out` - output file from testing.sh
- `TESTING.md` - markdown file explaining methodology for testing
- `common`
    - `puzzle.h` - interface of puzzle structure
    - `puzzle.c` - implementation of puzzle structure and getter/setter functions
- `creator`
    - `creator.h` - interface of creator module
    - `creator.c` - implementation of creator module
    - `creatorUnitTest.c` - unit tester for creator module
- `solver`
    - `solver.h` - interface of solver module
    - `solver.c` - implementation of solver module
    - `solverUnitTest.c` - unit tester for solver module
- `gui`
    - `backend` - contains files for backend of web-based GUI
    - `frontend` - contains files for frontend of web-based GUI

#### Compilation
To compile, run `make` from the the `project-order-of-the-white-lotus` directory. This will also make all module components that have not yet been compiled into their respective object files. `make clean` will clear all executables, object, and other intermediary compilation files. 
To do fuzz testing, run `make fuzzsudoku`. To do solver unit testing, run `make solverUnitTest`. To do creator unit testing, run `make creatorUnitTest`. To run memory checks, use `make valgrind`.

#### Folder Structures
```
.
├── DESIGN.md
├── IMPLEMENTATION.md
├── Makefile
├── README.md
├── TESTING.md
├── common
│   ├── puzzle.c
│   ├── puzzle.h
│   └── puzzle.o
├── creator
│   ├── creator.c
│   ├── creator.h
│   ├── creator.o
│   └── creatorUnitTest.c
├── fuzzsudoku.c
├── gui
│   ├── backend
│   │   ├── Procfile
│   │   ├── README.md
│   │   ├── package-lock.json
│   │   ├── package.json
│   │   ├── src
│   │   │   ├── router.js
│   │   │   ├── server.js
│   │   │   └── services
│   │   │       └── passport.js
│   │   ├── static
│   │   │   └── style.css
│   │   └── tempSolveFile.txt
│   └── frontend
│       ├── README.md
│       ├── _redirects
│       ├── babel.config.json
│       ├── dist
│       │   ├── _redirects
│       │   ├── bundle.js
│       │   ├── bundle.js.LICENSE.txt
│       │   ├── bundle.js.map
│       │   ├── delete.png
│       │   ├── done.png
│       │   ├── edit.png
│       │   ├── index.html
│       │   ├── main.css
│       │   └── main.css.map
│       ├── package-lock.json
│       ├── package.json
│       ├── src
│       │   ├── 200.html
│       │   ├── actions
│       │   │   └── index.js
│       │   ├── components
│       │   │   ├── app.js
│       │   │   ├── sudoku.js
│       │   │   └── welcome.js
│       │   ├── img
│       │   │   ├── logo.png
│       │   │   └── miniLogo.png
│       │   ├── index.html
│       │   ├── index.js
│       │   ├── reducers
│       │   │   ├── boardReducer.js
│       │   │   ├── errorReducer.js
│       │   │   └── index.js
│       │   └── styles
│       │       ├── style.scss
│       │       ├── sudokuStyle.scss
│       │       └── welcomeStyle.scss
│       └── webpack.config.js
├── solver
│   ├── solver.c
│   ├── solver.h
│   ├── solver.o
│   └── solverUnitTest.c
├── sudoku
├── sudoku.c
├── sudoku.o
├── testing.out
└── testing.sh
```



