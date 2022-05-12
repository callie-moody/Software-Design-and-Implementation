/*
* fuzzsudoku.c - fuzz tester for the sudoku final project
*
* usage: fuzzsudoku 
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
#include "creator/creator.h"
#include "solver/solver.h"
#include "common/puzzle.h"


int main(const int argc, char *argv[]){

    // read the integer input at the command line
    int puzzle_num = atoi(argv[1]);
    printf("Fuzzsudoku Testing Creator and Solver\nRunning %d tests.\n", puzzle_num); 

    
    for( int i = 0; i < puzzle_num; i++){
        printf("=================\nTest #%d:\n",i+1);

        printf("Creating a random board:\n\n");
        sudoku_board *game = create_new_puzzle();
        fprintf(stdout, "\nNumber of solutions to the generated puzzle (as determined by solve_recursive(): %d \n", solve_recursive(game));

        printf("-----------------\nCreating another random board to be sovled by solve_main\n\n");
        sudoku_board *game2 = create_new_puzzle();
        printf("\nSolving board:\n\n");
        solve_main(game2);
        printf("Success!\n\n");


    }





}
