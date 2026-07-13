/*Today, I completed all base concepts of pointers from w3schools. Hoping to apply them in future projects.*/

#include <stdio.h>

int main(){
    /*float pi = 3.14;
    float* ptr = &pi;

    printf("%f", *ptr);
    return 0;*/   // using float specifier for pointers



    // pointer subtraction = distance between the indices.

    /*int myNumbers[] = {1, 2, 3, 4};
    int* ptr1 = &myNumbers[0];
    int* ptr2 = &myNumbers[1];

    int result = ptr2 - ptr1;
    printf("%d\n", result);

    printf("Difference in last digits of memory: %d", result*sizeof(myNumbers[0]));
    return 0; */
    
    // Addition by n: ptr + n*sizeof(type).
    // Subraction: (ptr2 - ptr1)/sizeof(type)
    



    // Looping through pointers by using pointer itself
    /*  int myNum[] = {1, 20, 31, 4};
    int* p = myNum;
    for(int i = 0; i < (sizeof(myNum)/sizeof(myNum[0])); i++){
        printf("Element at index %d: %d\n", i, *(p));
        p++;
    }

    return 0; */



    // Pointer to Pointer

   /* int num = 5;
    int* ptr = &num;
    int** pptr = &ptr;

    printf("Value of num using pointer: %d\n", *ptr);
    printf("Value of num using pointer to pointer: %d\n", **pptr);

    **pptr = 20;

    printf("Value of num after changing value using pointer to pointer: %d", **pptr);
    return 0; */



    // Code Challenge
    /*Inside main(), complete the following steps:
    1. Declare an int variable named x and store 10 in it
    2. Declare a pointer named ptr that points to x
    3. Print the value of x by dereferencing ptr*/

    int x = 10;
    int* ptr = &x;
    printf("Value of variable x is: %d", *ptr);
    return 0;
}