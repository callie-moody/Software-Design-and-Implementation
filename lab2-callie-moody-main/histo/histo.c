/*
 * histo - take a set of numbers with stdin, and sort into a 16 box histogram
 *
 *usage: input any amount or arguments, followed by an EOF. program will sort into histogram
 *
 *CS50 Summer 2021
 *07/08/2021
 *Callie Moody
 */

#include <stdio.h>
#include <stdlib.h>

static int histogram[16];
static int numBins= (sizeof(histogram)/sizeof(histogram[0]));
static int binSize=1;
void createHisto();
void printHisto();
void resizeHisto();

int main(){
    createHisto();
    printHisto();
return 0;
}
//Read in input, assign to bins
void createHisto(){
    int maxVal=numBins*binSize;
    int numIn;
    printf("%i bins of size %i for range [0,%i)\n",numBins, binSize, maxVal);
     int status=scanf("%i", &numIn);
    while ((status != EOF)&&(status!=0)){
        if (! (numIn < 0)){
            while (! (numIn < maxVal) ){
                resizeHisto();
                maxVal=numBins*binSize;
                printf("%i bins of size %i for range [0,%i)\n",numBins, binSize, maxVal);
            }
            int bin= (numIn-numIn%binSize)/binSize;
            histogram[bin]++;
        }
        status=scanf("%i", &numIn);
    }
}
//double histogram bin size
void resizeHisto(){
    binSize=2*binSize;
                for(int i=0; i<numBins; i++){
                    histogram[i]=histogram[2*i]+histogram[2*i+1];
                }
}
//print properly formatted data
void printHisto(){
    for (int i=0; i<numBins; i++){
        printf("[%3d:%3d] ", i*binSize, (i+1)*binSize-1);
        if (histogram[i]>0){
        printf("%d\n", histogram[i]);
        }else{
        printf("\n");
        }
    }
}
