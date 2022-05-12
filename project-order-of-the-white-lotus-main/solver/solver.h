/*
* solver.h - Module to solve sudoku puzzles input by stdin
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

/**************** solve_main ****************/
/* recieve puzzle to solve, loop through logical steps, trigger recursion, then print and delete
 *
 * Caller provides:
 *      board to solve
 */
void solve_main(sudoku_board *board);


/**************** solve_recursive ****************/
/* recieve puzzle to solve, recursively find and save a solution, count number of possible solutions
 *
 * Caller provides:
 *      board to solve
 * We return:
 *      the number of possible solutions to the current board
 */
int solve_recursive(sudoku_board *board);


