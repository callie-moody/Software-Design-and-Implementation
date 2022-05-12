/* 
 * hashtest.c - test program for CS50 hashtable module
 *
 * usage: read lines from stdin
 *
 * CS50, Summer 2021
 * Callie Moody
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"
#include "../lib/readlinep.h"

void print(FILE *fp, const char *key, void *item);
void delete(void *item);
void print2(void *arg, const char *key, void *item);


int main() 
{
  hashtable_t *hash;

  // create a bag
  hash = hashtable_new(5);
  if (hash == NULL) {
    fprintf(stderr, "hashtable_new failed\n");
    return 1;
  }

//insertion testing
  printf("testing hash_insert...\n");

  while (!feof(stdin)) {
    char *name = readlinep();
    char *item = readlinep();
    if (name != NULL && item!=NULL) {
	    hashtable_insert(hash, name, item);
    }
  free(name);
  }
    
  printf("test extranneous inserts..\n");
  hashtable_insert(NULL, "Dartmouth", "item1");
  hashtable_insert(hash, NULL, NULL); 
  
  //search and print testing
  printf("finding....\n");
  if(hashtable_find(hash, "findme")!=NULL){
  fprintf(stdout, "%s", (char *)hashtable_find(hash, "findme"));}
  printf("\nThe hash:\n");
  hashtable_print(hash, stdout, *print);
  printf("\n");


//iterate and delete testing
  printf("\nIterated Print:\n");
  hashtable_iterate(hash, stdout, *print2);

  printf("delete the hash...\n");
  hashtable_delete(hash, *delete);


  return 0;
}
//item print function
void print(FILE *fp, const char *key, void *item){
fprintf(fp,"Key %s   Item %s",key, (char *)item);
}

//item delete function
void delete(void *item){
free(item);
}

//iterate print function
void print2(void *arg, const char *key, void *item){
fprintf(arg,"Key %s   Item %s\n",key, (char *)item);
}

