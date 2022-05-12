
## Structs

*sudoku_board* contains two `int[9][9]` that contain the intitial and final states of the sudoku board. additionally, it contains a `sudoku_cell[9][9]` that holds the board in progress.

*sudoku_cell* contains an `int` value that saves the filled value of the cell, and a `bool[9]` that holds the possible valid inputs for a cell.

## Functions

### in sudoku.c

*main* first calls `parse_arguments` to verify that all arguments are valid. Then, if the user commanded to solve, it calls `create_game` and then `solve_main`. if the user commanded to create, it calls `create_new_puzzle`

*parse_arguments* recieves the command line arguments. it verifies there are 2, and that the user commanded to either "create" or "solve". if these conditions are not met, it exits 1.

### in fuzzsudoku.c

*main* recieves the number of puzzle tests to generate from stdin. Then, it calls `create_new_puzzle` to test the creator, and uses solve_recursive to check if there is a unique solution. it also creates a new puzzle and solves it using `solve_main`. this repeats however many times the caller requests.

### in puzzle.h

*create_game* allocates memory for a `sudoku_board`. it next fills the `given_board` directly from stdin. finally, it fills the `solving_board` cells with the values from the `given_board`, allocating memory along the way. returns the completed board.

*create_blank_game()* allocates memory for a `sudoku_board`. it next fills the `given_board` with all zeroes. finally, it fills the `solving_board` cells with the values from the `given_board`, allocating memory along the way. returns the completed board.

*delete_board* recieves a `sudoku_board` and iterates through it, freeing each cell befor freeing the entire struct.

*save_solved* recieves a `sudoku_board` and fills each cell of the `solved_board` with the corresponding cell in the `solving_board`

*get_solved_board* allocates memory for an `int**` and fills it with the values in the `solved_board`. returns the filled `int**`

*get_cell* returns the pointer to a `sudoku_cell` at a given coordinate on a given `sudoku_board`

*get_cell_value* returns the value stored in a given `sudoku_cell`

*set_cell_value* saves a given `int` value into a given `sudoku_cell`

*get_pencil_mark* returns the `bool` saved into the given index of the pencil marks array of a given `sudoku_cell`. 

*set_pencil_mark* saves a given bool `bool` into the given index of the pencil marks array of a given `sudoku_cell`. 

*print_solving_board* recieves a `sudoku_board` and prints out the values stored in the solving_board

*set_given_board* receives an `int **` and saves each value from it into the given `sudoku_board`'s given_board.

*get_solving_board* recieves a `sudoku_board` and creates a new `int **` copied from the solving_board. returns the `int **`

*reset_board* recieves a `sudoku_board` and changes each value in the board to match the given_board associated. 

### in creator.h

*create_new_puzzle* creates an empty board using `create_blank_game`. It uses `solve_recursive` to fill the entire board. then, it loads the filled board into the given_board. 

*remove_cell* recieves a filled sudoku board. looping 40 times, it first saves the current board into a temp variable. then, it selects a random cell to remove from the board. it attempts to use `solve_recursive` to fill int the board from this state. if it reurns multiple or no solutions, use `reset_board` to return to the previous state. if it returns a unique solution, continue to the next cell to be removed.

### in solver.h

*solve_main* receives a `sudoku_board` containing a sudoku puzzle to solve. if the board is not yet solved (as determined by `is_solved`), we enter a while loop. This while loop calls the two logic functions: `fill_single_pencil` and `ill_unique_int_loc`. If either returns true (is able to insert cells), the board's possible inputs for each cell is updated (using `generate_pencil`) and the loop is continued. If both return false (neither have any cells to insert), the loop is exited and the program rechecks if the board `is_solved`. If the board is not solved, the function calls `solve_recursive` to continue solving the puzzle. Once the puzzle is solved, the function calls `get_solved_board` to get the soltuion, and then loops through and prints each cell's value. To terminate the function, the board memory is freed using `delete_board`.

*solve_recursive* receives a partially solved `sudoko_board` to complete solving. It finds the topmost and leftmost empty cell on the board. It generates an array of numbers 1 through 9 in a random order. In the order specified by the array, the function checks if the number `is_valid_insert` into the cell. If it is, it sets the cell to contain that value. If this move completes the board (check by calling `is_solved`), add 1 to the solutions count. If there are 0, 1 or 2 solutions so far, continue searching recursively for more. After completing the search, reset the cell value to be empty and return the number of solutions found. 

*generate_pencil* recieves a `sudoku_board`. It iterates through each cell, and if the cell is empty, readjusts the pencil marks to correspond to the current state of the board. Iterating from 1 to 9, it checks if the number `is_valid_insert`. If it is, it sets the index true in the array, if not, it is set false.

*is_valid_insert* retruns true if an insert results in a `valid_row` `valid_column` and `valid_box`. else, returns false.

*valid_row* iterates through each cell in the row and determines if the int is already saved in a cell in the row.

*valid_column* iterates through each cell in the column and determines if the int is already saved in a cell in the column.

*valid_box* iterates through each cell in the box and determines if the int is already saved in a cell in the box.

*fill_single_pencil* recieves a `sudoku_board` and iterates through each open cell in it. in each cell, it counts how many indexes of the pencil mark array hold true. if in any cell there is only one valid input in the pencil mark array, that vallue is saved as the cell's value. returns true if any cells are filled.

*fill_unique_int_loc* recieves a `sudoku_board`. It checks each column, row, and box to see if there are any values that only 1 cell can contain, using `num_valid_placements`. if a cell is found like this, it is filled with the value. returns true if any cells are filled.

*is_solved* recieves a solved `sudoku_board` and iterates through each cell. if every cell `is_valid_insert` back into its current location, the puzzle is solved. we `save_solved` the board, and return true. if any cell is not a valid insert back into itself, return false.

### in gui

*backend* 

Index Route: Call make file, get the executable files ready for other calls

Create Route: call ./sudoku creator to create a sudoku board file

Solve Route: Read in a board (array of array), convert it to a string, make a temp file with the string inside, call ./sudoku solver < file to get a solved board, then return it.

See backend README for more details

*frontend*
Axios calls:
1. startBE: call the index route of the backend to start the backend. This function will also result in the BE generating the makeFile
2. resetBoard: reset the board to an empty board by changing the board's state to an empty board
3. editBoard: take in the location of the number changed by the user, the number the user inputted, and the board from redux. Change the board accordingly
4. create: send a request to BE to create a sudoku board
5. solve: Take in a board to be solved, send a request to the BE to solve the sudoku board

*components*
1. Sudoku: the FE portion for the page with the sudoku board
2. Welcome: the FE portion for the page with a welcome message