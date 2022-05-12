/* 
 * set.c - CS50 'set' module
 *
 * see set.h for more information.
 *
 * CS50 
 * Callie Moody
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "set.h"

typedef struct setnode{
    char *key;
    void *item;
    struct setnode *nextitem;
}setnode_t;

typedef struct set{
    setnode_t *head;
}set_t;

static setnode_t *setnode_new(const char *key, void *item){
    setnode_t *newnode = malloc(sizeof(setnode_t));
    if(newnode==NULL){
        return NULL;
    }else{
        newnode->item=item;
        newnode->key= malloc((sizeof(key)));
        strcpy(newnode->key,key);
        newnode->nextitem=NULL;
        return newnode;
    }
}

set_t *set_new(void){
 set_t *newset = malloc(sizeof(set_t));
    if(newset==NULL){
        return NULL;
    }else{
        newset->head=NULL;
        return newset;
    }
}


bool set_insert(set_t *set, const char *key, void *item){
if(set!=NULL && key!=NULL && item!=NULL){
    if(set->head==NULL){
        set->head=setnode_new(key, item);
    }
    else{
        setnode_t *temp= set->head;
	if(temp->key!=NULL){
        if(strcmp(temp->key,key)==0){
            return false;
        }}
        while(temp->nextitem!=NULL){
        temp=temp->nextitem;
        if(strcmp(temp->key,key)==0){
            return false;
        }
        }
        temp->nextitem=setnode_new(key, item);/////////NOT ADDING A SECOND NODE   
        return true;
    }
}

return false;
}

void *set_find(set_t *set, const char *key){
if(set!=NULL && key!=NULL){
        setnode_t *temp= set->head;
        while(temp!=NULL){
	if(temp->key!=NULL){
        if(strcmp(temp->key,key)==0){
            void *item=temp->item;
            return item;
        }}
	temp=temp->nextitem;
        }
        return NULL;
}
return NULL;
}


void set_print(set_t *set, FILE *fp, 
               void (*itemprint)(FILE *fp, const char *key, void *item) ){
if (fp!=NULL || itemprint==NULL){
    if(set==NULL || set->head==NULL){
        fprintf(fp, "(null)");
    }else{
        setnode_t *temp= set->head;
        fprintf(fp, "{");
        itemprint(fp,temp->key,temp->item);
        temp=temp->nextitem;
        while(temp!=NULL){
            fprintf(fp,",\n");
            itemprint(fp,temp->key,temp->item);
            temp=temp->nextitem;
        }
         fprintf(fp, "}");
    }
}
}


void set_iterate(set_t *set, void *arg,
                 void (*itemfunc)(void *arg, const char *key, void *item) ){
if(set!=NULL && itemfunc!=NULL){
        for (setnode_t *temp = set->head; temp != NULL;){
            itemfunc(arg,temp->key,temp->item);
            temp=temp->nextitem;
        }
    }
}


void set_delete(set_t *set, void (*itemdelete)(void *item) ){
    if( set!=NULL && itemdelete!=NULL){
        for (setnode_t *node = set->head; node != NULL; ) {
      setnode_t *next = node->nextitem;	   
      free(node->key);
      itemdelete(node->item);
      free(node);
      node = next;
    }
    free(set);
    }
}



