/*
 * chill - print out wind chill corresponding to temperature and wind velocity
 *
 *usage: 0 arguments: prints a table of values T -10 to 40, and V 5 to 15
 *       1 argument: take in command-line temperature value, print values V 5 to 15
 *       2 arguments: take in commandline temp windVel and print corresponding chill
*
 *CS50 Summer 2021
 *07/08/2021
 *Callie Moody
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float calculateChill(float temp, float windVel);

int main(const int argc,char* argv[]){
    float temp;
    float windVel;
    if (argc==1){
        printf("Temp    Wind   Chill\n----    ----    ----\n");
        for(temp=-10; temp<=40; temp+=10){
            for(windVel=5; windVel<=15; windVel+=5){
                calculateChill(temp, windVel);
            }
            printf("\n");
        }
    }else if (argc>3){
        fprintf(stderr, "Too many arguments\nUsage: Inputs: Temp(optional) WindVelocity(optional), prints Wind Chill\n");
	return 1;
    }else{
        temp=atof(argv[1]);
        if (temp>50){
            printf("Temperature must be less than 50 degrees Fahrenheit\n");
            return 2;
        }else if (temp<-99){
            printf("Temperature must be above -99 degrees Fahrenheit\n");
            return 3;
        }
        if (argc==2){
            printf("Temp    Wind   Chill\n----    ----    ----\n");
            for(windVel=5; windVel<=15; windVel+=5){
                calculateChill(temp, windVel);
            }
        }
        if (argc==3){
            windVel=atof(argv[2]);
            if (windVel<0.5){
                 printf("Wind Velocity must be greater than or equal to 0.5 MPH\n");
                return 4;
            } 
            printf("Temp    Wind   Chill\n----    ----    ----\n");
            calculateChill(temp, windVel);
        } 
    }
    return 0;
}

//Mathematical calculation and printing of individual lines
float calculateChill(float temp, float windVel){
    float windChill=35.74 + 0.6215*temp - 35.75*(pow(windVel,0.16)) + 0.4275*temp*(pow(windVel,0.16));
    printf("%4.1f   %4.1f     %4.1f\n", temp, windVel, windChill); 
    return windChill;
}
