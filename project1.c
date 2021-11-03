//
//  main.c
//  Project1
//
//  Created by Nima $wagaram on 11/1/21.
//  Copyright © 2021 Nima $wagaram. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1111111
#include <string.h>


float getThroughput(int *array){
    
    int x;
    double newArray[6];
    double sum  =0;
    int count =0;
    int a = 0;
    
    for(int x = 3; a< 5;x = x+3){           //runs a for loop to get the the every third variable after
                                            // the first burst input
        newArray[a] = array[x];
        a++;
    }
    
    for(int b =0; b <= 4;b++){              //Adds all of them up together from the new array
        sum += newArray[b];
    }
    
    double test = a-1;
    test/=sum;                              //Divides them by the total number of elements

   int c, r, m;
     m = sum*1000;
     c = m%10; // c = 4
     r = m/10; //
     if(c>=5)
     r++;
     sum = (float)r/100;

    return  test;
}
    
int getWaitingTimeandTurn(int *array){
    double burstTimes[32000];
    int waitingTime[5];
    int turnAroundTimes[5];
    int a = 0;
    int totalTurnAroundTime[5];
    
    waitingTime[0] = 0;
      
      for(int x = 3; a< 5;x = x+3){           //runs a for loop to get the the every third variable after
                                              // the first burst input
          burstTimes[a] = array[x];
          a++;
      }
    
    for (int b = 1; b < 5 ; b++ ){                                  //Gets Waiting time array
            waitingTime[b] =  burstTimes[b-1] + waitingTime[b-1];
    }
   
    for (int  i = 0; i < 5 ; i++){
        turnAroundTimes[i] = burstTimes[i] + waitingTime[i];             //Gets turn around time array
        totalTurnAroundTime[i] = totalTurnAroundTime[i] + turnAroundTimes[i];
                
       }
          
    
    int totalWaitingTime = 0;
    int totalTime = 0;
    
    for (int i=0; i<6; i++){                                //Calculates waiting time
        totalWaitingTime = totalWaitingTime + waitingTime[i];
        totalTime = totalTime + totalTurnAroundTime[i];
    }
    
    
    int size =5;
    double totalWT = (float)totalWaitingTime / (float)size;
    double tat =(float)totalTime / (float)size;
    
    printf("%.02f\n",totalWT);
    printf("%.02f\n",tat);
    
    return 0;
}






int main(int argc, const char * argv[]) {
    int a;
    int newNum;
    int arrayNums[65536] = {4,5,1,1,1,2,5,5,3,4,2,4,2,6,4,5,4};
    int newArray[65536];
    
   
    //int size = sizeof arrayNums / sizeof arrayNums[2];
    
   
    
    
    int check = 0;
    //printf("%d\n",result);                          //P value
    printf("%d\n",arrayNums[0]);                       //Gets voluntary context switch
    if(arrayNums[0] != arrayNums[1]){                   //Gets the nonVoluntary switch
           check = 0;
        printf("%d\n",check);
       }
    else{
       printf("%d\n",arrayNums[2]);
    }
       printf("100.0\n");                              //CPU Utilization
    
    float result  = getThroughput(arrayNums);
    printf("%.02f\n",result);                          //Throughput
     
    getWaitingTimeandTurn(arrayNums);
    return 0;
}

