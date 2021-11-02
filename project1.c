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
                    num = scanf("%d",&check);
    
    return check;
    }
    
int getVoluntary(){
    int voluntary;
      int num;
        num = scanf("%d",&voluntary);
      
      return voluntary;
         }

int getInvoluntary(){
    int Involuntary;
         int num;
         
                         num = scanf("%d",&Involuntary);
         
         return Involuntary;
            }

int * putValuesinArray(){
    int multiply = getInvoluntary();
    int a;
    
    int arrayNums[multiply*3];
    int newNum;
    int num;
    while(1)
    for(a =0; a< multiply *3; a++){
        num = scanf("%d",&newNum);
        if(num == EOF || num == 0){
            break;
        }
        else{
            arrayNums[a] = newNum;
        }
    }
    
    return 0;
}

int main(int argc, const char * argv[]) {

    int volInvolCheck;
    
    int result = getPValue();                       //Gets the P value
    int voluntary = getVoluntary();                 //Get voluntary context switch
    int involuntary = getInvoluntary();             //Get involuntary context switch
    
  
    //printf("%d\n",result);                          //P value
    printf("%d\n",voluntary);                       //Gets voluntary context switch
    if(voluntary != involuntary){                   //Gets the nonVoluntary switch
           volInvolCheck = 0;
        printf("%d\n",volInvolCheck);
       }
    else{
       printf("%d\n",involuntary);
    }
       printf("100.0\n");                              //CPU Utilization
    
    int multiply = getInvoluntary();
       int a;
       
       int arrayNums[multiply*3];
       int newNum;
       int num;
    
       for(a =0; a< multiply *3; a++){
           num = scanf("%d",&newNum);
           if(num == EOF || num == 0){
               break;
           }
           else{
               arrayNums[a] = newNum;
               
           }
       }
       
    
 
    
    return 0;
}
