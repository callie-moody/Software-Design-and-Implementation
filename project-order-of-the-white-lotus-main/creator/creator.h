/* creator.h - creates a random sudoku board and prints to stdout
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
#include "../common/puzzle.h"
#include "../solver/solver.h"



/****************** create_new_puzzle *****************/
/* Creates a new, random, solvable sudoku_board with 40 missing cells
 * We receive/return: nothing
 * We output: a properly formatted sudoku puzzle to stdout
 * All malloc'd items deleted within this function and dependents.
*/
sudoku_board * create_new_puzzle();

