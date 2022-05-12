/*
 * words - take an input and print out all consecutive character sets
 *
 *usage: words -, filename
 *
 *CS50 Summer 2021
 *07/09/2021
 *Callie Moody
 */

#include <stdio.h>
#include <stdlib.h>

void readWrite(FILE *filepointer);

int main(const int argc, char* argv[]){
    int status=0;
    if(argc == 1){
        readWrite(stdin);
    }else{
        for (int i=1; i<argc; i++){
            char c = *argv[i];
            if(c == '-'){
                readWrite(stdin);
            }else{
                FILE* fp;
                fp=fopen(argv[i],"r");
                if(fp == NULL) {
                    printf("unable to open file");
                    status++;
                }else{
                    readWrite(fp);
                    fclose(fp);
                }
            }
        }
    }
    return status;
}

void readWrite(FILE *filepointer){

int input;
int lastinput;

    while( (input=fgetc(filepointer)) != EOF ){
        if ((input<91 && input>64) || (input<123 && input>96)){
            printf("%c", input);
        }else if((lastinput<91 && lastinput>64) || (lastinput<123 && lastinput>96)){
            printf("\n");
         }  
    lastinput=input; 
    }  
}