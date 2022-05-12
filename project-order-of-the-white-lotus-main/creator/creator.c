/* creator.c - creates a random sudoku board and prints to stdout
*
*
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
#include <string.h>
#include "../common/puzzle.h"
#include "../solver/solver.h"
#include "creator.h"

static void remove_cell(sudoku_board * board);


/****************** create_new_puzzle *****************/
/* Creates a new, random, solvable sudoku_board with 40 missing cells
 * We receive/return: nothing
 * We output: a properly formatted sudoku puzzle to stdout
 * All malloc'd items deleted within this function and dependents.
*/
sudoku_board * create_new_puzzle()
{
    //initialize the sudoku board values to zero (as a starting point)
    sudoku_board * board = create_blank_game();
     
    solve_recursive(board); // populate board with valid solution

    // Set the given board to the solution (just as a starting point)
    int ** temp_solving_board = get_solving_board(board);
    set_given_board(board, temp_solving_board); 

    // free the 2d array
    for (int row = 0; row < 9; row++) free(temp_solving_board[row]);
    free(temp_solving_board);

    
    reset_board(board); // Reset the board just in case
    remove_cell(board); // Depopulate the board 40 times to produce 
                        //   uniquely solvable puzzle.

    print_solving_board(board); // Print the board to stdout
    
    return board;
    
}

/****************** remove_cell ***********************/
/* Removes 40 cells from a fully solved sudoku board.
 * Ensures that the puzzle still has only a single valid
 *    solution.
*/
static void remove_cell(sudoku_board * board)
{
    
    // Just a redundant setting of the solving_board to the solved_board
    //   to make sure it is kicked off in the right state.
    int ** solution = get_solved_board(board);
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col <9; col++) {
            set_cell_value(get_cell(board,row,col), solution[row][col]);
        }
    }
    // Need to free the malloc'd array
    for (int row = 0; row < 9; row++) free(solution[row]);
    free(solution);


    for (int i = 0; i < 40; i++) { // iterate through 40 removals
        
        // Holds temp just in case a removal is invalid, can then reset.
        int ** last_board = get_solving_board(board); 
        bool removal_was_valid = false; // flag for thewhile

        while(!removal_was_valid) {
            // choosing random cell
            int rand_row = rand() % 9;
            int rand_col = rand() % 9;
            int ** potential_board = get_solving_board(board);

            // Only remove a cell if it has a value in it currently
            if (potential_board[rand_row][rand_col]) {
                potential_board[rand_row][rand_col] = 0;

                set_given_board(board, potential_board);
                reset_board(board);


                if (solve_recursive(board) != 1 ) {
                    // If #solns > 1 OR #solns == 0, then that was not a
                    //   valid removal
                    set_given_board(board, last_board);
                    reset_board(board);
                } else {
                    // Okay to remove this cell!
                    removal_was_valid = true;
                    set_given_board(board, potential_board);
                    reset_board(board);
                }
            }
            
        // Need to free all the arrays we malloc'd    
        for (int row = 0; row < 9; row++) free(potential_board[row]);
        free(potential_board);
        }
        for (int row = 0; row < 9; row++) free(last_board[row]);
        free(last_board);
    }
}





            







