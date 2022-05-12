/*
* solver.c - Module to solve sudoku puzzles input by stdin
*
*
* Final Project Group: Order of the White Lotus
* Callie Moody CS 50
* Connor Coale 
* Vanessa Perez-Robles
* Vi Tran
* 8/23/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "../common/puzzle.h"
#include "solver.h"
#include <unistd.h>

static int num_valid_placements_in_row(sudoku_board * board, int row, int to_insert);
static int num_valid_placements_in_col(sudoku_board * board, int col, int to_insert);
static int num_valid_placements_in_box(sudoku_board * board, int row, int col, int to_insert);
static void generate_pencil(sudoku_board *board);
static bool is_valid_insert(sudoku_board *board, int column, int row, int to_insert);
static bool valid_row(sudoku_board *board, int row, int column, int to_insert);
static bool valid_column(sudoku_board *board, int row, int column, int to_insert);
static bool valid_box(sudoku_board *board, int column, int row, int to_insert);
static bool fill_single_pencil(sudoku_board *board);
static bool fill_unique_int_loc(sudoku_board *board);
static bool is_solved(sudoku_board *board);
/**************** solve_main ****************/
/* recieve puzzle to solve, loop through logical steps, trigger recursion, then print and delete
 *
 * Caller provides:
 *      board to solve
 */
void solve_main(sudoku_board *board)
{
    bool logic = true;
    if (!is_solved(board)) {
        while (logic) //for as long as there are clear, nonrandom, logical inputs
        {
            generate_pencil(board); //update the valid inputs for each empty cell
            if (fill_single_pencil(board) || fill_unique_int_loc(board)) //input all logical inputs
            {
                logic = true;
                generate_pencil(board); //update the valid inputs for all cells
            }
            else
            {
                logic = false;  //if no more logical steps could be made, exit the loop
            }

        }

        if (!is_solved(board)){
            int num_solns = solve_recursive(board);
            if (num_solns==0)     //if the board is not solvable
            { 
                
                delete_board(board);        //clean up memory and exit
                exit(2);
            }
            
        }

    }
    int ** solution = get_solved_board(board);
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {

            fprintf(stdout, "%i ", solution[row][col]); //print the solved board to stdout
        }
        fprintf(stdout, "\n");
        free(solution[row]);
    }
    free(solution);
    delete_board(board); //clean up memory
}


/**************** solve_recursive ****************/
/* recieve puzzle to solve, recursively find and save a solution, count number of possible solutions
 *
 * Caller provides:
 *      board to solve
 * We return:
 *      the number of possible solutions to the current board
 */
int solve_recursive(sudoku_board *board)
{
    
    int solns = 0;
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        { 
            if (get_cell_value(get_cell(board, row, col)) == 0)  //finds the topmost leftmost empty cell on the board
            { 
                int shuffled[9] = {1,2,3,4,5,6,7,8,9};
                for (int i = 0; i < 100; i++)  //randomly swap numbers 100 times
                {

                    int rand1 = rand() % 9; //choose two random numbers to swap
                    int rand2 = rand() % 9;

                    int temp = shuffled[rand1]; //perform the swap
                    shuffled[rand1] = shuffled[rand2];
                    shuffled[rand2] = temp;
                }

                for (int i = 0; i < 9; i++) {
                    
                    if (is_valid_insert(board, col, row, shuffled[i])) {
                        
                        set_cell_value(get_cell(board, row, col), shuffled[i]);
                        
                        if (is_solved(board)) solns++;
                        
                        if (solns <= 2) solns += solve_recursive(board);
                        
                    }
                    
                }  
                set_cell_value(get_cell(board, row, col), 0);
                
                return solns;
                
            }
        }
    }

    
    return solns;
}



/**************** generate_pencil ****************/
/* update valid values for all the empty cells on the board
 *
 * Caller provides:
 *      board to update
 */
static void generate_pencil(sudoku_board *board)
{
    
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        { //iterates through each cell
            
            if (get_cell_value(get_cell(board, row, col)) == 0)
            { //only updates empty cells
                
                for (int num = 1; num <= 9; num++)
                { //checks validity of numbers 1-9
                    if (is_valid_insert(board, col, row, num))
                    {
                        set_pencil_mark(get_cell(board, row, col), num - 1, true); //save true in the cell's array if a valid input
                    }
                    else
                    {
                        set_pencil_mark(get_cell(board, row, col), num - 1, false);//save false in the cell's array if an invalid input
                    }
                }
            } else {
               
                for (int i = 0; i < 9; i++) {
                    
                    set_pencil_mark(get_cell(board, row, col), i, false);
                }
                
                set_pencil_mark(get_cell(board, row, col), get_cell_value(get_cell(board, row, col)) - 1, true);
                
            }
        }
    }
}

/**************** is_valid_insert ****************/
/* check validity of an input for a value for a single cell
 *
 * Caller provides:
 *      board to check values for
 *      column and row of cell to check
 *      intended value to check
 * We return:
 *      true if a valid potential input
 *      false if surrounding cells make the input invalid
 */

static bool is_valid_insert(sudoku_board *board, int column, int row, int to_insert)
{
    return (valid_row(board, row, column, to_insert) && valid_column(board, row, column, to_insert) && valid_box(board, column, row, to_insert)); //checks column, row, and box for validity
}

/**************** valid_row ****************/
/* check is a value is preexisting in a row
 *
 * Caller provides:
 *      board to check values for
 *      row to check
 *      intended value to check
 * We return:
 *      true if the int does not already appear in the row
 *      false if the int does already appear in the row
 */

static bool valid_row(sudoku_board *board, int row, int column, int to_insert)
{
    for (int i = 0; i < 9; i++)
    {                                                  //for each cell in the row
        if (get_cell_value(get_cell(board, row, i)) == to_insert) //check if the test value is saved
        {
            if (i != column) return false;
        }
    }
    return true;
}

/**************** valid_column ****************/
/* check is a value is preexisting in a column
 *
 * Caller provides:
 *      board to check values for
 *      column to check
 *      intended value to check
 * We return:
 *      true if the int does not already appear in the column
 *      false if the int does already appear in the column
 */
static bool valid_column(sudoku_board *board, int row, int column, int to_insert)
{
    for (int i = 0; i < 9; i++)
    {                                                     //for each cell in the row
        if (get_cell_value(get_cell(board, i, column)) == to_insert) //check if the test value is saved
        {
            if (i != row) return false;
        }
    }
    return true;
}

/**************** valid_box ****************/
/* check is a value is preexisting in a 3x3 box
 *
 * Caller provides:
 *      board to check values for
 *      cell coordinates to check surrounding box for
 *      intended value to check
 * We return:
 *      true if the int does not already appear in the box
 *      false if the int does already appear in the box
 */
static bool valid_box(sudoku_board *board, int column, int row, int to_insert)
{
    int col_start = column - column % 3; //find the top left coordinates of the 3x3 box
    int row_start = row - row % 3;
    for (int i = col_start; i < col_start + 3; i++)
    {
        for (int j = row_start; j < row_start + 3; j++)
        {                                                //for each cell in the box
            if (get_cell_value(get_cell(board, j, i)) == to_insert) //check if the test value is saved
            {
                if (!(i == column && j == row)) return false;
            }
        }
    }
    return true;
}

/**************** fill_single_pencil ****************/
/* finds cells with only one valid input in their pencil marks, and fills them in
 *
 * Caller provides:
 *      board to check and fill
 *      
 * We return:
 *      true if we insert any new values into cells
 *      false if we could not insert into any cells
 */
static bool fill_single_pencil(sudoku_board *board)
{
    bool inserted = false; //initialize boolean that tracks whether there was an insertion
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        { //for each cell on the board
            sudoku_cell *cell = get_cell(board, row, col);
            if (get_cell_value(cell) == 0)
            {                     //if the cell is empty
                int numvalid = 0; //check how many valid inputs there are in the pencil mark array
                for (int mark = 0; mark < 9; mark++)
                {
                    if (get_pencil_mark(cell, mark))
                    {
                        numvalid++; //increment to store the number found
                    }
                }
                if (numvalid == 1)
                { //if there is only one valid input
                    for (int mark = 0; mark < 9; mark++)
                    {
                        if (get_pencil_mark(cell, mark))
                        {
                            set_cell_value(cell, mark + 1); //save the input as the permanent value
                            inserted = true;        //mark a successful insertion
    
                        }
                    }
                }
            }
        }
    }

    return inserted;
}

/**************** fill_unique_int_loc ****************/
/* finds rows/cols/boxes that have only 1 cell that can hold a value, and fills that cell
 *
 * Caller provides:
 *      board to check and fill
 *      
 * We return:
 *      true if we insert any new values into cells
 *      false if we could not insert into any cells
 */
static bool fill_unique_int_loc(sudoku_board *board)
{

    for (int i = 1; i <= 9; i++) { // Iterate through each possible input (1-9)
        for (int row = 0; row < 9; row ++) { // Iterate through each row
            if (num_valid_placements_in_row(board, row, i) == 1) { // see if only 1 cell in row can accept a certain value
                for (int j = 0; j < 9; j++) {
                    if (!get_cell_value(get_cell(board, row, j))) { // fill only valid cell with that value
                        if (is_valid_insert(board, j, row, i)) {
                            set_cell_value(get_cell(board, row, j), i);
                            generate_pencil(board);
                            return true;

                        }
                    }
                }
            }
        }

        // works the same as the prior chunk which handles rows, but this does columns
        for (int col = 0; col < 9; col++) {
            if (num_valid_placements_in_col(board, col, i) == 1) {
                for (int j = 0; j < 9; j++) {
                    if (!get_cell_value(get_cell(board, j, col))) {
                        if (is_valid_insert(board, col, j, i)) {
                            set_cell_value(get_cell(board, j, col), i);
                            generate_pencil(board);
                            return true;

                        }
                    }
                }
            }
        }

        // works the same as the prior chunk which handles rows, but this does boxes
        for (int row = 0; row < 9; row += 3) {
            for (int col = 0; col < 9; col += 3) {
                if (num_valid_placements_in_box(board,row,col,i) == 1) {
                    for (int m = row; m < row+3; m++) {
                        for (int n = col; n < col+3; n++) {
                            if (!get_cell_value(get_cell(board, m, n))) {
                                if (is_valid_insert(board, n, m, i)) {
                                set_cell_value(get_cell(board, m, n), i);
                                generate_pencil(board);
                                return true;

                                }
                            }
                        }   
                    }
                }
            }
        }
    }

    return false;
}

/*************** num_valid_placements_in_row ***********************/
/* returns the number of cells in a row which can accept the given value legally
 *
 */
static int num_valid_placements_in_row(sudoku_board * board, int row, int to_insert) 
{
    int num_valid_spots = 0;
    for (int i = 0; i < 9; i++) {
        if (!get_cell_value(get_cell(board, row, i))) {
            if (is_valid_insert(board, i, row, to_insert)) {
                num_valid_spots++;
 
            }
        }
    }
    return num_valid_spots;
}

/*************** num_valid_placements_in_col ***********************/
/* returns the number of cells in a col which can accept the given value legally
 *
 */
static int num_valid_placements_in_col(sudoku_board * board, int col, int to_insert) 
{
    int num_valid_spots = 0;
    for (int i = 0; i < 9; i++) {
        if (!get_cell_value(get_cell(board, i, col))) {
            if (is_valid_insert(board, col, i, to_insert)) num_valid_spots++;
        }
    }
    return num_valid_spots;
}

/*************** num_valid_placements_in_box ***********************/
/* returns the number of cells in a box which can accept the given value legally
 *
 */
static int num_valid_placements_in_box(sudoku_board * board, int row, int col, int to_insert) 
{
    int num_valid_spots = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (!get_cell_value(get_cell(board, row+i, col+j))) {
                if (is_valid_insert(board, col+j, row+i, to_insert)) num_valid_spots++;
            }
        }
    }
    return num_valid_spots;
}



/**************** is_solved ****************/
/* check if the puzzle is completed
 *
 * Caller provides:
 *      board to check
 * We return:
 *      true if the solution is complete
 *      false if the solution is incomplete or incorrect
 */
static bool is_solved(sudoku_board *board)
{
    
    generate_pencil(board);
    for (int row = 0; row < 9; row++){
        for (int col = 0; col < 9; col++){ //iterates through each cell

            if (get_cell_value(get_cell(board, row, col)) == 0){ //not solved if there are any empty cells
                return false;
            }
            if (!is_valid_insert(board, col, row, get_cell_value(get_cell(board, row, col)))){ //improperly solved if any cell values are invalid
                
                return false;
            }
        }
    }
    save_solved(board);
    return true;
}
