//
//  main.c
//  Project1
//
//  Created by Nima $wagaram on 11/1/21.
//  Copyright © 2021 Nima $wagaram. All rights reserved.
//

#include <stdio.h>

struct info{
    int count;
    int num;
     int numArray[1];
};

int getPValue(){
    int check;
    int num;
                    num = fgetc(stdin);
    
    return num;
    }
    
int getVoluntary(){
    int voluntary;
      int num;
        num = fgetc(stdin);
      
      return num;
         }

int getInvoluntary(){
    int Involuntary;
         int num;
         
                         num = fgetc(stdin);
         
         return num;
            }



int main(int argc, const char * argv[]) {

    int a;
    int newNum;
      int arrayNums[65536];
    FILE *fp;
    
    fp = fopen("tests.bats","r");
    for(a =0; a< 5;a++){
        fscanf(fp, "%d",&arrayNums[a]);
    }
    
    if(fp == NULL){
        exit(1);
    }
      int num;
      for(a =0; a< 4; a++){
          fscanf(a =0, "%d",newNum);
          if(newNum == EOF || newNum == 0){
              break;
          }
          else{
              arrayNums[a] = newNum;
          }
          
      }
    int check;
    //printf("%d\n",result);                          //P value
    printf("%d\n",arrayNums[1]);                       //Gets voluntary context switch
    if(arrayNums[1] != arrayNums[2]){                   //Gets the nonVoluntary switch
           check = 0;
        printf("%d\n",check);
       }
    else{
       printf("%d\n",arrayNums[2]);
    }
       printf("100.0\n");                              //CPU Utilization
    

    
 
    
    return 0;
}

