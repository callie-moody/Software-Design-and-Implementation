/*
* creatorUnitTest.c - 
*
* usage: ./solverUnitTest 
*   it is recommended to pipe an input file in for the one
*   test case which tests an input file.
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
#include <time.h>
#include "../creator/creator.h"
#include "solver.h"
#include "../common/puzzle.h"

int main(const int argc, char *argv[]){

    srand(time(NULL));

    printf("=================\nGenerate a random board: \n");
    sudoku_board * game1 = create_new_puzzle();
    printf("-----------------\n");
    //solve board from stdn
    printf("Randomly generated Sudoku Board is being solved by solve_main():\n");

    solve_main(game1);
    
    printf("=================\n");

    sudoku_board * game2 = create_blank_game();
    //solve blank board 
    printf("Solving Blank Sudoku Board with solve_recursive\n");
    solve_recursive(game2);

    int ** solution = get_solved_board(game2);
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

    printf("Uniquely filled board shown above.\n");
    
    printf("=================\n");

    printf("Reading in a puzzle from stdin... \n");
    sudoku_board * game3 = create_game();
    print_given_puzzle(game3);
    printf("-----------------\n");
    printf("Solving a the puzzle read from stdin: \n");
    solve_main(game3);
    
    printf("=================\n");




}
