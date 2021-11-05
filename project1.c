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
    int bVar;
    int priorID;
    int sum;
};

struct ProcessInfo{
    int array[98307];
    int size;
    int counter;
    int waitingTime;
    int turnAroundTime;
    int PID;
    int totalBurstTime;
    int bVar;
    int sum;
    int priorID;
};

double getThroughput(struct ProcessInfo *array, int size){
    struct ProcessInfo newArray[size];
    double sum =0;;
    int a = 0;
    
    for(int x = 0; a< size;x++){           //runs a for loop to get the the every third variable after
                                            // the first burst input
        newArray[a].bVar = array[x].bVar;
        a++;
    }
    
    for(int b =0; b <= size;b++){              //Adds all of them up together from the new array
        sum += newArray[b].bVar;
    }
    
    double test = a-1;
    test/=sum;                              //Divides them by the total number of elements

  return  test;
}


int getWaitingTime(struct Process processQueue[],struct ProcessInfo array[], int pQSize, int arrSize){
    int x = 0;
    int y=0;
    while(x < arrSize){
        y = 0;
        while(y < arrSize && array[x].counter > 0){
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

int getTurnAroundTime(struct ProcessInfo array[], int arrSize){     //Total burst + total wait time / total execution
    int sum =0;;
    for(int a =0; a < arrSize;a++){
        sum += array[a].waitingTime;
    }
    for(int a =0; a < arrSize;a++){
        sum += array[a].bVar;
    }
    
    sum /= arrSize;
    
    return sum;
}

    
int getResponseTime(struct ProcessInfo array[], int size, int pVal){          //First time - Arrival Time
    
    int count =0;
    for(int x =0; x< size; x++){
            if(pVal == array[x].PID){
                count++;
            }
        }
    int sum =0;
    for(int idx =0; idx < size; idx++){
        sum += array[idx].bVar;
    }
    
    sum /= count;
    
    return sum;
    
    }

int main(int argc, const char * argv[]) {
    int start;
    
    int a;
    FILE *fp;
      struct ProcessInfo arrayStore[98307];
    
    int newP;
       int numVals;

    if(argc != 1){
           fp = fopen(argv[1],"r");
                fscanf(fp,"%d", &start);
                fscanf(fp,"%d", &newP);
                fscanf(fp,"%d", &numVals);
                
                for(a =0; a<numVals; ++a ){
                    fscanf(fp,"%d %d %d", &arrayStore[a].PID, &arrayStore[a].bVar,&arrayStore[a].priorID);
                }
        }
    else{
          scanf("%d", &start);
                   scanf("%d",&newP);
                   scanf("%d",&numVals);
                   for(a =0; a<numVals; ++a ){
                   scanf("%d %d %d", &arrayStore[a].PID, &arrayStore[a].bVar,&arrayStore[a].priorID);
    }
    
    
    printf("%d\n",start);                       //Gets voluntary context switch
 
    printf("100.0\n");                              //CPU Utilization
    
    float result = getThroughput(arrayStore, numVals);      //Gets throughput
    printf("%.02f\n",result);
    
    double answer = getTurnAroundTime(arrayStore, numVals); //Gets turnaround time
    printf("%.02f\n", answer);
    
   //float wait = getWaitingTime(arrayStore,numVals);
    getResponseTime(arrayStore,numVals,newP);

    return 0;
    }
    
}


