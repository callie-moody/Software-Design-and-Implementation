/* 
 * hashtable.c - CS50 'hashtable' module
 *
 * see hashtable.h for more information.
 *
 * CS50 
 * Callie Moody
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "../set/set.h"
#include "jhash.h"

typedef struct hashtable{
    set_t** array;
    int slots;
}hashtable_t;  

hashtable_t *hashtable_new(const int num_slots){
    hashtable_t *hashnew= malloc(sizeof(hashtable_t));
    if(hashnew==NULL || num_slots<=0){
        return NULL;
    }else{
        hashnew->array=malloc(num_slots*sizeof(set_t*));
        for(int i=0; i<num_slots; i++){
        hashnew->array[i]= set_new();}
        hashnew->slots=num_slots;
        return hashnew;
    }
    return NULL;
}

bool hashtable_insert(hashtable_t *ht, const char *key, void *item){
if(ht!=NULL && key!=NULL && item!=NULL){
        unsigned long keyhash= JenkinsHash(key,ht->slots);
            set_t *node= ht->array[keyhash];
            return set_insert(node, key, item);
}
return false;
}


void *hashtable_find(hashtable_t *ht, const char *key){
if(ht!=NULL && key!=NULL){
    unsigned long keyhash= JenkinsHash(key,ht->slots);
        set_t *node= ht->array[keyhash];
        if(node!=NULL){
            return set_find(node,key);
        }
}
return NULL;
}


void hashtable_print(hashtable_t *ht, FILE *fp, 
                     void (*itemprint)(FILE *fp, const char *key, void *item)){
if (fp!=NULL){
    if(ht==NULL){
        fprintf(fp, "(null)");
    }else if(itemprint==NULL){
        for(int i=0; i<ht->slots; i++){
        fprintf(fp,"\n");
        }
    }else{
        for(int i=0; i<ht->slots; i++){
        set_print(ht->array[i],fp,itemprint);
            fprintf(fp,"\n");
        }
    }
}
}


void hashtable_iterate(hashtable_t *ht, void *arg,
                       void (*itemfunc)(void *arg, const char *key, void *item) ){
if(ht!=NULL && itemfunc!=NULL){
        for(int i=0; i<ht->slots; i++){
            set_iterate(ht->array[i],arg,itemfunc);
        }
    }
}

void hashtable_delete(hashtable_t *ht, void (*itemdelete)(void *item) ){
if( ht!=NULL && itemdelete!=NULL){
     for(int i=0; i<ht->slots; i++) {  
      set_delete(ht->array[i], itemdelete);
    }
    free(ht->array);
    free(ht);
    }
}
