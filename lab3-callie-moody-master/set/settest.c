/* 
 * settest.c - test program for CS50 set module
 *
 * usage: read lines from stdin
 *
 * CS50, Summer 2021
 * Callie Moody
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"
#include "../lib/readlinep.h"

void print(FILE *fp, const char *key, void *item);
void delete(void *item);
void print2(void *arg, const char *key, void *item);

int main() 
{
  set_t *set;

  // create a set
  set = set_new();
  if (set == NULL) {
    fprintf(stderr, "set_new failed\n");
    return 1;
  }

//insertion testing
  printf("testing set_insert...\n");
  while (!feof(stdin)) {
    char *name = readlinep();
    char *item = readlinep();
    if (name != NULL&& item!=NULL) {
      set_insert(set, name, item);
      free(name);
    }
  }

  printf("testing extranneous set_insert...\n");
  set_insert(set, NULL, NULL);
  set_insert(NULL, NULL, NULL);

  //search , iterate, and print testing
  printf("finding....\n");
  if (set_find(set, "findme")!=NULL){
  fprintf(stdout, "%s", (char *)set_find(set, "findme"));}
 else{printf("notfound");}
  printf("\nThe set:\n");
  set_print(set, stdout,*print);
  printf("\n");
  printf("\nIterated Print:\n");
  set_iterate(set, stdout, *print2);
  printf("\n");

  //deletion test
  printf("delete the bag...\n");
  set_delete(set, *delete);
  return 0;
}
//print item function
void print(FILE *fp, const char *key, void *item){
fprintf(fp,"Key %s   Item %s",key, (char *)item);
}
//delete item function
void delete(void *item){
free(item);
}
//iterate print function
void print2(void *arg, const char *key, void *item){
fprintf(arg,"Key %s   Item %s\n",key, (char *)item);
}

