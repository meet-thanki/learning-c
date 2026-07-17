// Today, I practiced pointers again with the help of pass by reference to a function mini project.

#include <stdio.h>

// mini project: pass by reference swapper and calculator

void swap(int* a, int* b);
void compute(int* a, int* b, int *sum, int *diff);

int main(){
    int num1, num2, sumResult, diffResult;
    int* no1 = &num1;
    int* no2 = &num2;
    sumResult = 0;
    diffResult = 0;

    printf("Enter number 1: ");
    scanf("%d", &num1);

    printf("Enter number 2: ");
    scanf("%d", &num2);

    swap(no1, no2);
    compute(no1, no2, &sumResult, &diffResult); // passing the memory address directly to the function reduces the load of making copies inside the function, hence consuming less memory.
    return 0;
}

void swap(int* a, int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void compute(int* a, int* b, int* sum, int* diff){
    *sum = *a + *b;
    *diff = *a - *b;

    printf("The sum of both the numbers num1 and num2 after swapping is: %d.", *sum);
    printf("\nThe difference of both the numbers num1 and num2 after swapping (num1 - num2) is: %d.", *diff);
}