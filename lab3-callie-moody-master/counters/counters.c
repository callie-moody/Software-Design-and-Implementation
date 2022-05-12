/* 
 * counters.c - CS50 'counter' module
 *
 * see counters.h for more information.
 *
 * CS50 
 * Callie Moody
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "counters.h"

typedef struct countersnode{
    int key;
    int counter;
    struct countersnode *nextcounter;
}countersnode_t;

typedef struct counters{
    countersnode_t *head;
}counters_t;

static countersnode_t *countersnode_new(int key){
    countersnode_t *newnode = malloc(sizeof(countersnode_t));
    if(newnode==NULL){
        return NULL;
    }else{
        newnode->counter=1;
        newnode->key=key;
        newnode->nextcounter=NULL;
        return newnode;
    }
}

counters_t *counters_new(void){
    counters_t *newcounter = malloc(sizeof(counters_t));
    if(newcounter==NULL){
        return NULL;
    }else{
        newcounter->head=NULL;
        return newcounter;
    }
}



int counters_add(counters_t *ctrs, const int key){
    if(ctrs!=NULL && key>=0){
        if(ctrs->head==NULL){
            ctrs->head=countersnode_new(key);
            return ctrs->head->counter;
            
        }else{
            countersnode_t *temp= ctrs->head;
            if(key==temp->key){
                    temp->counter++;
                    int count=temp->counter;
                    return count;
                 }
            while(temp->nextcounter!=NULL){
                temp=temp->nextcounter;
                if(key==temp->key){
                    temp->counter++;
                    int count=temp->counter;
                    return count;
                 }
            }
            temp->nextcounter=countersnode_new(key);
            return temp->nextcounter->counter;
        }
    }
    return 0;
}

int counters_get(counters_t *ctrs, const int key){
if(ctrs!=NULL && key>=0){
    for (countersnode_t *temp = ctrs->head; temp != NULL;){
            if(key==temp->key){
                int count= temp->counter;
                return count;
            }else{
                temp=temp->nextcounter;
            }
        }
    return 0;
}
return 0;
}


bool counters_set(counters_t *ctrs, const int key, const int count){
if(ctrs!=NULL && !(key<0) && !(count<0)){ //CHECK IF OUT OF MEMORY HOW
        if(ctrs->head==NULL){
            ctrs->head=countersnode_new(key);
            ctrs->head->counter=count;
            return true;
        }else{
            countersnode_t *temp= ctrs->head;
            if(key==temp->key){
                    temp->counter=count;
                    return true;
                 }
            while(temp->nextcounter!=NULL){
                temp=temp->nextcounter;
                if(key==temp->key){
                    temp->counter=count;
                    return true;
                 }
            }
        temp->nextcounter=countersnode_new(key);
        temp->nextcounter->counter=count;
        return true;
        }
    }
return false;

}


void counters_print(counters_t *ctrs, FILE *fp){
if (fp!=NULL){
    if(ctrs==NULL){
        fprintf(fp, "(null)");
    }else{
        countersnode_t *temp= ctrs->head;
        fprintf(fp, "{%i=%i", temp->key, temp->counter);
        temp=temp->nextcounter;
        while(temp!=NULL){
            fprintf(fp,",%i=%i",temp->key, temp->counter);
            temp=temp->nextcounter;
        }
         fprintf(fp, "}");
         free(temp);
    }
}
}

void counters_iterate(counters_t *ctrs, void *arg, 
                      void (*itemfunc)(void *arg, 
                                       const int key, const int count)){
    if(ctrs!=NULL && itemfunc!=NULL){
        for (countersnode_t *temp = ctrs->head; temp != NULL;){
            itemfunc(arg,temp->key,temp->counter);
            temp=temp->nextcounter;
        }
    }
}

void counters_delete(counters_t *ctrs){
     if (ctrs != NULL) {
    for (countersnode_t *node = ctrs->head; node != NULL; ) {
      countersnode_t *next = node->nextcounter;	   
      free(node);
      node = next;
    }
    free(ctrs);
  }

}
