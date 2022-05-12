/*
* puzzle.h - Module to establish puzzle structure and its getters/setters/printers
*
* Final Project Group: Order of the White Lotus
* Callie Moody CS 50
* Connor Coale 
* Vanessa Perez-Robles
* Vi Tran
* 8/22/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**************** struct sudoku_cell ****************/
/* a struct that holds the necessary data for one sudoku cell
 * contains:
 *      a value: the solved number saved into the cell- 0 if 'empty'
 *      a boolean array: holds which possible values are valid for the cell based on surrounding inputs in the board
 *      a backtrack depth: used to track what the most recent guessed cell value was, and how far to backtrack the board
 */
typedef struct cell sudoku_cell;


/**************** struct sudoku_board ****************/
/* a struct that holds the necessary data for one sudoku game
 * contains:
 *      a given board: the inputted array of integers recieved from stdin: the start state
 *      a solving board: the board containing cell structs that is modified throughout the solution
 */
typedef struct game sudoku_board;


/**************** create_game ****************/
/* recieve puzzle to solve from stdin, save into the sudoku_board struct
 *
 * We return:
 *   the filled and allocated sudoku_board
 * Caller is responsible for:
 *      later freeing all memory in the sudoku_board
 */
sudoku_board *create_game();


sudoku_board * create_blank_game();


/**************** delete_board ****************/
/* free all memory allocated during the solve
 *
 * Caller provides:
 *      board to empty
 */
void delete_board(sudoku_board *board);





/**************** save_solved ****************/
/* recieve completed solving_board and save into solved_board
 *
 * Caller provides:
 *      sudoku_board containing a complete solving_board
 */
void save_solved(sudoku_board *board);


/**************** get_solved_board ****************/
/* receive a completed sudoku_board return the solved_board int array
 * We receive:
 *  a sudoku_board struct
 * We return:
 *  the solved_board int array
 *  NULL is the board is null
 */
int ** get_solved_board(sudoku_board *board);

/**************** get_cell ****************/
/* receive a sudoku_board and cell coordinates, return a pointer to the cell
 * We receive:
 *  a sudoku_board struct
 * a row
 * a column
 * We return:
 *  a pointer to the cell at those coordinates of the solving_board
 */
sudoku_cell * get_cell(sudoku_board *board, int row, int col);

/**************** get_cell_value ****************/
/* receive a cell struct, return the saved cell value
 * We receive:
 *  a sudoku_cell struct
 * We return:
 * the cell value
 */
int get_cell_value(sudoku_cell * cell);

/**************** set_cell_value ****************/
/* receive a cell struct, input the given value
 * We receive:
 *  a sudoku_cell struct
 *  an intended input
 */
void set_cell_value(sudoku_cell * cell, int value);

/**************** get_pencil_mark****************/
/* receive a cell struct and an index, return the corresponding boolean in the pencil mark array
 * We receive:
 *  a sudoku_cell struct
 * an int to check fo in the pencil mark array
 * We return:
 * the boolean associated with the index in the cell’s pencil mark array
 */
bool get_pencil_mark(sudoku_cell * cell, int index);


/**************** set_pencil_mark ****************/
/* receive a cell struct, input the given boolean into the given index of the cell’s pencil mark array
 * We receive:
 *  a sudoku_cell struct
 *  an index
 *  a boolean to save
 */
void set_pencil_mark(sudoku_cell * cell, int index, bool val);


/**************** print_solving_board ****************/
/* print out the current state of the sudoku_board’s solving board
 * We receive:
 *  a sudoku_board
 */
void print_solving_board(sudoku_board * board);

/****************** set_given_board *******************/
/* Sets the given_board array within the board to the array passed 
 *     in by board_to_set
 * We receive: A valid sudoku_board pointer and a valid double pointer
 *     to an int array.
 *
*/
void set_given_board(sudoku_board * board, int ** board_to_set);

/****************** get_solving_board *****************/
/* Returns the array corresponding to the solving_board within the board 
 *    
 * We receive: A valid sudoku_board pointer 
 * We return: A malloc'd array of ints
 *
 * We assume: the array will be free'd later by the user.
*/
int ** get_solving_board(sudoku_board * board);

/****************** reset_board ***********************/
/* Sets the solving_board's cells within the board to the given_board 
 *     array's values
 * We receive: A valid sudoku_board pointer
 *
*/
void reset_board(sudoku_board * board);

/****************** print_given_puzzle ****************/
/* Prints the given puzzle
 * Assumes the board is not schedule
*/
void print_given_puzzle(sudoku_board * board);
