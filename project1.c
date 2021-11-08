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
    int PID;
    int burstTime;
    int priority;
};

struct ProcessInfo{
    int PID;
    int totalBurstTime;
    int waitingTime;
    int responseTime;
    int pCtr;
};

int calcContextSwitches(struct Process *processQueue, int numProcesses){
    //int prevID = 0;
    int totalCS;
    for (int i = 0; i < numProcesses - 1; i++){
        if (processQueue[i+1].PID != processQueue[i].PID){
            totalCS += 1;
        }
    }
    return totalCS;
}


int getTimeInfos(struct Process *processQueue,struct ProcessInfo *array, int numProcesses, int numPIDs){

    int totalContextSwitches = 0;
    int nonVoluntarySwitches;
    int x = 0;
    int y;
    int pFlag = 0;
    int volSwitches = 0;
    while(x < numPIDs){
        y = 0;
        pFlag = 0;
        while(y < numProcesses && array[x].pCtr > 0){
            if (processQueue[y].PID == array[x].PID){
                pFlag =1;
                array[x].pCtr -= 1;
            }
            else{
                array[x].waitingTime += processQueue[y].burstTime;
            }
            if (y != numProcesses - 1 && array[x].pCtr == 0){
                volSwitches += 1;
            }
            if (pFlag != 1){
                array[x].responseTime += processQueue[y].burstTime;
            }
            y++;
        }
        printf("%d\n",array[x].PID);
        printf("%d\n",array[x].responseTime);
        printf("%d\n",array[x].waitingTime);
        x++;
    }
    totalContextSwitches = calcContextSwitches(processQueue, numProcesses);
    nonVoluntarySwitches = totalContextSwitches - volSwitches;
    int allBurstTimes = 0;
    double avgThroughput = 0.0;
    double avgTurnAroundTime = 0.0;
    double avgWaitingTime = 0.0;
    double rTime = 0.0;

    for(int a =0; a < numPIDs;a++){

        allBurstTimes += array[a].totalBurstTime;

        // printf("%0.2d\n",array[a].totalBurstTime);                        //Throughput

        avgTurnAroundTime += array[a].waitingTime + array[a].totalBurstTime;

        // printf("%0.2d\n",array[a].waitingTime + array[a].totalBurstTime);                        //Throughput

        avgWaitingTime += array[a].waitingTime;

        //printf("%0.2d\n", array[a].waitingTime);                          //WaitingTime

        rTime += array[a].responseTime;

        //printf("%0.2d\n", array[a].responseTime);                          //rTime

    }

    avgThroughput = (float)numPIDs / (float)allBurstTimes;

    avgTurnAroundTime /= numPIDs;

    avgWaitingTime /= numPIDs;

    rTime /= numPIDs;

    printf("%d\n", numPIDs);

    printf("%d\n", nonVoluntarySwitches);                               //nonVoluntary

    printf("100.0\n");                                  //CPU Utilization

    printf("%0.02f\n",avgThroughput);                        //Throughput

    printf("%0.02f\n",avgTurnAroundTime);                         //TurnAround

    printf("%0.02f\n", avgWaitingTime);                          //WaitingTime

    printf("%0.02f\n", rTime);                          //rTime

    return 0;

    //nonVoluntarySwitches,avgThroughput,avgTurnAroundTime,avgWaitingTime,rTime;

}




int main(int argc, char * argv[]) {



    int start;

    int numPIDs;

    int numProcesses;

    FILE* fp;

    if (argc < 1) {

        fp = fopen(argv[1],"r");



    }

    else {

        fp = stdin;

    }

    fscanf(fp,"%d", &start);

    fscanf(fp,"%d", &numPIDs);

    fscanf(fp,"%d", &numProcesses);



    struct ProcessInfo* arrayStore = malloc(numPIDs*sizeof(arrayStore));

    struct Process* processQueue = malloc(numProcesses*sizeof(processQueue));
    for (int i = 0; i < numPIDs; i++){
        arrayStore[i].totalBurstTime= 0;
        arrayStore[i].waitingTime = 0;
        arrayStore[i].responseTime = 0;
        arrayStore[i].pCtr = 0;
    }

    int a;
    int PID,burstTime,priority;
    for(a = 0;  a < numProcesses; a++ ){

        fscanf(fp,"%d %d %d", &PID, &burstTime,&priority);
        processQueue[a].PID = PID;
        processQueue[a].burstTime = burstTime;
        processQueue[a].priority = priority;
        arrayStore[PID-1].PID = PID;

        arrayStore[PID-1].totalBurstTime += burstTime;

        arrayStore[PID-1].pCtr += 1;
    }
    getTimeInfos(processQueue,arrayStore,numProcesses,numPIDs);
    return 0;
}

int getTimeInfos(struct Process *processQueue,struct ProcessInfo *array, int numProcesses, int numPIDs){

    int totalContextSwitches = 0;
    int nonVoluntarySwitches;
    int x = 0;
    int y;
    int pFlag = 0;
    int volSwitches = 0;
    while(x < numPIDs){
        y = 0;
        pFlag = 0;
        while(y < numProcesses && array[x].pCtr > 0){
            if (processQueue[y].PID == array[x].PID){
                pFlag =1;
                array[x].pCtr -= 1;
            }
            else{
                array[x].waitingTime += processQueue[y].burstTime;
            }
            if (y != numProcesses - 1 && array[x].pCtr == 0){
                volSwitches += 1;
            }
            if (pFlag != 1){
                array[x].responseTime += processQueue[y].burstTime;
            }
            y++;
        }
        printf("%d\n",array[x].PID);
        printf("%d\n",array[x].responseTime);
        printf("%d\n",array[x].waitingTime);
        x++;
    }
    totalContextSwitches = calcContextSwitches(processQueue, numProcesses);
    nonVoluntarySwitches = totalContextSwitches - volSwitches;
    int allBurstTimes = 0;
    double avgThroughput = 0.0;
    double avgTurnAroundTime = 0.0;
    double avgWaitingTime = 0.0;
    double rTime = 0.0;

    for(int a =0; a < numPIDs;a++){

        allBurstTimes += array[a].totalBurstTime;

        // printf("%0.2d\n",array[a].totalBurstTime);                        //Throughput

        avgTurnAroundTime += array[a].waitingTime + array[a].totalBurstTime;

        // printf("%0.2d\n",array[a].waitingTime + array[a].totalBurstTime);                        //Throughput

        avgWaitingTime += array[a].waitingTime;

        //printf("%0.2d\n", array[a].waitingTime);                          //WaitingTime

        rTime += array[a].responseTime;

        //printf("%0.2d\n", array[a].responseTime);                          //rTime

    }

    avgThroughput = (float)numPIDs / (float)allBurstTimes;

    avgTurnAroundTime /= numPIDs;

    avgWaitingTime /= numPIDs;

    rTime /= numPIDs;



    printf("%d\n", nonVoluntarySwitches);                               //nonVoluntary

    printf("100.0\n");                                  //CPU Utilization

    printf("%0.02f\n",avgThroughput);                        //Throughput

    printf("%0.02f\n",avgTurnAroundTime);                         //TurnAround

    printf("%0.02f\n", avgWaitingTime);                          //WaitingTime

    printf("%0.02f\n", rTime);                          //rTime

    return 0;

    //nonVoluntarySwitches,avgThroughput,avgTurnAroundTime,avgWaitingTime,rTime;

}




int main(int argc, char * argv[]) {



    int start;

    int numPIDs;

    int numProcesses;

    FILE* fp;

    if (argc < 1) {

        fp = fopen(argv[1],"r");



    }

    else {

        fp = stdin;

    }

    fscanf(fp,"%d", &start);

    fscanf(fp,"%d", &numPIDs);

    fscanf(fp,"%d", &numProcesses);



    struct ProcessInfo* arrayStore = malloc(numPIDs*sizeof(arrayStore));

    struct Process* processQueue = malloc(numProcesses*sizeof(processQueue));
    for (int i = 0; i < numPIDs; i++){
        arrayStore[i].totalBurstTime= 0;
        arrayStore[i].waitingTime = 0;
        arrayStore[i].responseTime = 0;
        arrayStore[i].pCtr = 0;
    }

    int a;
    int PID,burstTime,priority;
    for(a = 0;  a < numProcesses; a++ ){

        fscanf(fp,"%d %d %d", &PID, &burstTime,&priority);
        processQueue[a].PID = PID;
        processQueue[a].burstTime = burstTime;
        processQueue[a].priority = priority;
        arrayStore[PID-1].PID = PID;

        arrayStore[PID-1].totalBurstTime += burstTime;

        arrayStore[PID-1].pCtr += 1;
    }
    getTimeInfos(processQueue,arrayStore,numProcesses,numPIDs);
    return 0;
}

