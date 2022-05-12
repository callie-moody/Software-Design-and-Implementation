/* 
 * countertest.c - test program for CS50 counter module
 *
 * usage: read ints from stdin
 *
 * CS50, Summer 2021
 * Callie Moody
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "counters.h"

void printone(void *arg, const int key, int count);

int main() 
{
  counters_t *ctr;
  //initialize counter
  ctr = counters_new();
  if (ctr == NULL) {
    fprintf(stderr, "counters_new failed\n");
    return 1;
  }

  //insert testing
  printf("testing add...enter keys\n");
   int *key=malloc(sizeof(int));
    while (!feof(stdin)) {
    fscanf(stdin, "%i\n", key);
    if (key != NULL) {
      counters_add(ctr, *key);
    }
  }
  free(key);
  printf("testing add...entering null key\n");
    counters_add(ctr, -1);

  //set/get testing
  printf("set the 12 counter to 17...\n");
  counters_set(ctr, 12, 17);
  int got= counters_get(ctr, 12);
  fprintf(stdout, "get the 12 counter(should be 17)...%i \n", got);
 

 //iterate/print testing
  printf("iterate print the counter...\n");
  counters_iterate(ctr, 0, printone);

  printf("print the counter...\n");
  counters_print(ctr, stdout);
  

  //deletion test
  printf("\ndelete the counter...\n");
  counters_delete(ctr);
  return 0;
}

//print function used when iterating over counter
void printone(void *arg, const int key, int count){
fprintf(stdout, "%i=%i\n",key,count);
}





