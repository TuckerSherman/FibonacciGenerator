//
//  main.c
//  Fibonacci
//
//  Created by Tucker Sherman on 10/8/14.
//  Copyright (c) 2014 Tucker Sherman. All rights reserved.
//



#include <stdio.h>

        void makeFibo (int numberOfNumbers);

        int recursiveValueFibonacci(int remainingSteps, int previousNumber, int previousPreviousNumber);

        int recursiveReferenceFibonacci(int remainingSteps, int *previousnumber, int *previousPreviousNumber);

int main(int argc, const char * argv[]) {

    //make fibonacci with iteration
    printf("How many fibbonacci numbers would you like?:");
    
    int size;
    scanf("%d",&size);
    makeFibo(size);
    
    //make fibbonaci with recursion
    printf("How many fibonacci numbers would you like?:");
    int remainingSteps;
    scanf("%d",&remainingSteps);
    recursiveValueFibonacci(remainingSteps,1, 0);
    
    
    //make fibbonaci with recursion passing by reference
    
    printf("How many fibonacci numbers would you like?:");
    int remainingSteps2;
    scanf("%d",&remainingSteps2);
    int num1 = 0;
    int num2= 1;
    recursiveReferenceFibonacci(remainingSteps2, &num2, &num1);
    
    
    
    return 0;
}

int recursiveReferenceFibonacci(int remainingSteps, int *num2, int *num1){
    if (remainingSteps>0) {
        int newNumber = *num2 + *num1;
        printf("%d ,",*num2);
        recursiveReferenceFibonacci(remainingSteps-1, &newNumber, num2);
    };
    
    return 0;
}
int recursiveValueFibonacci(int remainingSteps, int previousNumber, int previousPreviousNumber){
    
    if (remainingSteps>0) {
            int newNumber = previousNumber + previousPreviousNumber;
            printf("%d ,",previousNumber);
            recursiveValueFibonacci(remainingSteps-1, newNumber, previousNumber);
        };
    
    return 0;
}

void makeFibo (int numberOfNumbers) {
    int number1 = 0;
    int number2 = 1;
    int *numberA = &number1;
    int *numberB = &number2;
    for (int i =0 ; i < numberOfNumbers; i++) {
        int sum = *numberA+*numberB;
        *numberA = *numberB;
        *numberB = sum;
        printf("%d ,",number1);
    }
    
    return;
}
