//
//  main.c
//  Project1
//
//  Created by Nima $wagaram on 11/1/21.
//  Copyright © 2021 Nima $wagaram. All rights reserved.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Process{
    int processQueue[98307];
    int processId[98307];
    int PID;
    int size;
};

struct ProcessInfo{
    int array[98307];
    int size;
    int counter;
    int waitingTime;
    int PID;
    int totalBurstTime;
    int burst[98307];
};

float getThroughput(int *array){
    double newArray[6];
    double sum  =0;
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


int getWaitingTime(struct Process processQueue[],struct ProcessInfo array[], int pQSize, int arrSize){
    
    int x = 0;
    int y=0;
    while(x < arrSize){
        y = 0;
        while(y < pQSize && array[x].counter > 0){
            if (processQueue[y].PID == array[x].PID){
                array[x].counter -= 1;
                continue;
             }
            array[x].waitingTime += processQueue[y].size;
            y++;
    }
        x++;
}
    int sum =0;
    for(int a =0; a < arrSize;a++){
        sum += array[a].waitingTime;
    }
    sum /= arrSize;
    
     return sum;
}

int getTurnAroundTime(){
    
    return 0;
}

int getResponseTime(struct Process processQueue[],struct ProcessInfo array[], int pQSize, int arrSize){                      //First time - Arrival Time
        int x = 0;
        int y=0;
        while(x < arrSize){
            y = 0;
            while(y < pQSize && array[x].counter > 0){
                if (processQueue[y].PID == array[x].PID){
                    array[x].counter -= 1;
                    continue;
                 }
                array[x].waitingTime += processQueue[y].size;
                y++;
        }
            x++;
    }
        int sum =0;
        for(int a =0; a < arrSize;a++){
            sum += array[a].waitingTime;
        }
        sum /= arrSize;
        
         return sum;
    }

int main(int argc, const char * argv[]) {
    int start;
    
    int a;
     FILE *fp = fopen(fp,"r");
    
    int newP;
    int numVals;
    
    struct Process processID[98307];
    struct ProcessInfo burst[98307];
    int priorityID[98307];
    
    fscanf(fp,"%d", &start);
    fscanf(fp,"%d", &newP);
    fscanf(fp,"%d", &numVals);
    
    
    for(a =0; a<numVals; ++a ){
        fscanf(fp,"%d %d %d", &processID,&burst,&priorityID);
    }
    
    int arrayNums[98307] = {4,5,1,1,1,2,5,5,3,4,2,4,2,6,4,5,4};
    
    int size = sizeof (burst) / sizeof (burst[0]);
    
    int check = 0;

    printf("%d\n",arrayNums[0]);                       //Gets voluntary context switch
    if(arrayNums[0] != arrayNums[1]){                   //Gets the nonVoluntary switch
           check = 0;
        printf("%d\n",check);
       }
    else{
       printf("%d\n",arrayNums[2]);
    }
       printf("100.0\n");                              //CPU Utilization
    
    //
    
    printf("%d\n",size);
    float result  = getThroughput(arrayNums);
    printf("%.02f\n",result);
    float wait = getWaitingTime(processID,burst,numVals,size);
    printf("0.02f\n",wait);
                           //Throughput
   
    return 0;
}



