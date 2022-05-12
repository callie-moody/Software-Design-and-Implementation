/*
* puzzle.c - Module to establish puzzle structure and its getters/setters/printers
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
#include "puzzle.h"

/**************** struct sudoku_cell ****************/
/* a struct that holds the necessary data for one sudoku cell
 * contains:
 *      a value: the solved number saved into the cell- 0 if 'empty'
 *      a boolean array: holds which possible values are valid for the cell based on surrounding inputs in the board
 *      a backtrack depth: used to track what the most recent guessed cell value was, and how far to backtrack the board
 */
typedef struct cell
{
    int value;
    bool pencil_marks[9];
} sudoku_cell;


/**************** struct sudoku_board ****************/
/* a struct that holds the necessary data for one sudoku game
 * contains:
 *      a given board: the inputted array of integers recieved from stdin: the start state
 *      a solving board: the board containing cell structs that is modified throughout the solution
 */
typedef struct game
{
    int given_board[9][9]; //stores the intial board
    sudoku_cell * solving_board[9][9]; //holds the board while solving
    int solved_board[9][9]; //holds the solution to the board
} sudoku_board;


/**************** create_game ****************/
/* recieve puzzle to solve from stdin, save into the sudoku_board struct
 *
 * We return:
 *   the filled and allocated sudoku_board
 * Caller is responsible for:
 *      later freeing all memory in the sudoku_board
 */
sudoku_board *create_game()
{
    
    sudoku_board *board= calloc(1, sizeof(sudoku_board)); //allocate and initialize memory
    
    //initialize given_board
    for (int row = 0; row < 9; row++) { //get board from stdin
        for (int col = 0; col < 9; col++) {
            fscanf(stdin, "%d ", &(board->given_board[row][col]));
        }
        
    }

    //set up solving_board
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){ //create each cell, allocate memory, and fill in variables
        sudoku_cell *cell= calloc(1, sizeof(sudoku_cell)); 
        cell->value=board->given_board[i][j];
            for(int k=0; k<9; k++){
                cell->pencil_marks[k]=false;
            }
        board->solving_board[i][j]=cell;
        }
    }
    return board;
}

sudoku_board * create_blank_game() 
{
    sudoku_board *board= calloc(1, sizeof(sudoku_board)); //allocate and initialize memory
    
    //initialize given_board
    for (int row = 0; row < 9; row++) { //get board from stdin
        for (int col = 0; col < 9; col++) {
            board->given_board[row][col] = 0;
        }
        
    }

    //set up solving_board
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){ //create each cell, allocate memory, and fill in variables
        sudoku_cell *cell= calloc(1, sizeof(sudoku_cell)); 
        cell->value=board->given_board[i][j];
            for(int k=0; k<9; k++){
                cell->pencil_marks[k]=false;
            }
        board->solving_board[i][j]=cell;
        }
    }
    return board;
}

/**************** delete_board ****************/
/* free all memory allocated during the solve
 *
 * Caller provides:
 *      board to empty
 */
void delete_board(sudoku_board *board)
{
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
                free(board->solving_board[row][col]); //free each cell
        }
    }
    free(board); //free the whole struct
}

/**************** save_solved ****************/
/* recieve completed solving_board and save into solved_board
 *
 * Caller provides:
 *      sudoku_board containing a complete solving_board
 */
void save_solved(sudoku_board *board)
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++) //cell by cell
        { 
            board->solved_board[row][col] = board->solving_board[row][col]->value; //saves cell int value into solved_board
        }
    }
}


/**************** get_solved_board ****************/
/* receive a completed sudoku_board return the solved_board int array
 * We receive:
 *  a sudoku_board struct
 * We return:
 *  the solved_board int array
 *  NULL is the board is null
 */
int ** get_solved_board(sudoku_board *board)
{
    if (board != NULL) { //check parameter validity
        int ** solved_board = malloc(9 * sizeof(int * )); // malloc nine int pointers (point to the start of each row)
        for (int i = 0; i < 9; i++) {
            solved_board[i] = malloc(9 * sizeof(int)); // malloc space for each of the nine rows filled with ints
        }
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                solved_board[i][j] = board->solved_board[i][j];  //fill the array cell by cell from the struct
            }
        }


        return solved_board;
    } else return NULL;
}

/**************** get_cell ****************/
/* receive a sudoku_board and cell coordinates, return a pointer to the cell
 * We receive:
 *  a sudoku_board struct
 * a row
 * a column
 * We return:
 *  a pointer to the cell at those coordinates of the solving_board
 */
sudoku_cell * get_cell(sudoku_board *board, int row, int col)
{
    if (board != NULL) {
        return board->solving_board[row][col];
    } else return NULL;
}

/**************** get_cell_value ****************/
/* receive a cell struct, return the saved cell value
 * We receive:
 *  a sudoku_cell struct
 * We return:
 * the cell value
 */
int get_cell_value(sudoku_cell * cell) 
{
    if (cell != NULL) { //check parameter validity
        return cell->value; 
    } else return 0; // I put NULL as an "error case"
}

/**************** set_cell_value ****************/
/* receive a cell struct, input the given value
 * We receive:
 *  a sudoku_cell struct
 *  an intended input
 */
void set_cell_value(sudoku_cell * cell, int value)
{
    if (cell != NULL) { //check parameter validity
        cell->value = value;
    }
}

/**************** get_pencil_mark****************/
/* receive a cell struct and an index, return the corresponding boolean in the pencil mark array
 * We receive:
 *  a sudoku_cell struct
 * an int to check fo in the pencil mark array
 * We return:
 * the boolean associated with the index in the cell’s pencil mark array
 */
bool get_pencil_mark(sudoku_cell * cell, int index) 
{
    if (cell != NULL) { //check parameter validity
        return (cell->pencil_marks[index]); //return bool at the index in the pencil mark strcut
    } else return NULL;
}

/**************** set_pencil_mark ****************/
/* receive a cell struct, input the given boolean into the given index of the cell’s pencil mark array
 * We receive:
 *  a sudoku_cell struct
 *  an index
 *  a boolean to save
 */
void set_pencil_mark(sudoku_cell * cell, int index, bool val) 
{
    //fprintf(stdout, "Entered set_pencil_mark\n");
    if (cell != NULL) { //check parameter validity
        cell->pencil_marks[index] = val;
    }
}

/**************** print_solving_board ****************/
/* print out the current state of the sudoku_board’s solving board
 * We receive:
 *  a sudoku_board
 */
void print_solving_board(sudoku_board * board) 
{
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) { //for each cell
            fprintf(stdout, "%d ", get_cell_value(get_cell(board,i,j))); //print the cell's current value
        }
        fprintf(stdout, "\n");
    }
}

/****************** set_given_board *******************/
/* Sets the given_board array within the board to the array passed 
 *     in by board_to_set
 * We receive: A valid sudoku_board pointer and a valid double pointer
 *     to an int array.
 *
*/
void set_given_board(sudoku_board * board, int ** board_to_set) 
{
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            board->given_board[i][j] = board_to_set[i][j];
        }
    }
}


/****************** get_solving_board *****************/
/* Returns the array corresponding to the solving_board within the board 
 *    
 * We receive: A valid sudoku_board pointer 
 * We return: A malloc'd array of ints
 *
 * We assume: the array will be free'd later by the user.
*/
int ** get_solving_board(sudoku_board * board) 
{
    if (board != NULL) { //check parameter validity
        int ** solving_board = malloc(9 * sizeof(int * )); // malloc nine int pointers (point to the start of each row)
        for (int i = 0; i < 9; i++) {
            solving_board[i] = malloc(9 * sizeof(int)); // malloc space for each of the nine rows filled with ints
        }
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                solving_board[i][j] = get_cell_value(get_cell(board, i, j));  //fill the array cell by cell from the struct
            }
        }


        return solving_board;
    } else return NULL;
}

/****************** reset_board ***********************/
/* Sets the solving_board's cells within the board to the given_board 
 *     array's values
 * We receive: A valid sudoku_board pointer
 *
*/
void reset_board(sudoku_board * board) 
{
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            set_cell_value(get_cell(board, i, j), board->given_board[i][j]);
        }
    }
}

/****************** print_given_puzzle ****************/
/* Prints the given puzzle
 * Assumes the board is not schedule
*/
void print_given_puzzle(sudoku_board * board) 
{
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", board->given_board[i][j]);
        }
        printf("\n");
    }
}
