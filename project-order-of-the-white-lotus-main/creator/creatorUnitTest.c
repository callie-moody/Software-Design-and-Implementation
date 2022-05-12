/*
* creatorUnitTest.c - unit testor 
*
* usage: ./creatorUnitTest
* 

*
* Final Project Group: Order of the White Lotus
* Callie Moody CS 50
* Connor Coale 
* Vanessa Perez-Robles
* Vi Tran
* 8/25/2021
*/

#include <stdio.h>
#include <stdlib.h> // random, srandom
#include <string.h> // strch
#include "creator.h"
#include "../solver/solver.h"
#include "../common/puzzle.h"
#include <time.h>

int main(const int argc, char *argv[]){
    srand(time(NULL));

    printf("Creating random, uniquely solvable board:\n");
    sudoku_board *game = create_new_puzzle();

    printf("Number solutions to board: %d\n", solve_recursive(game));
    


}
