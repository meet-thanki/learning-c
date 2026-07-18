/*Today, I practiced dynamic (heap) memory management concepts in w3schools. I shall be doing mini projects
on these concepts in my later commits.*/

#include <stdio.h>
#include <stdlib.h>

// mini project: memory management

int main(){
    // int students[20];
    // printf("%zu", sizeof(students)); // to print the total bytes stored in students array, 4*20 = 80

    // int *ptr1, *ptr2;
    // ptr1 = malloc(sizeof(*ptr1));
    // ptr2 = calloc(1, sizeof(*ptr2));

    // example

    // int *students;
    // int numStudents = 15;
    // students = calloc(numStudents, sizeof(*students));
    // printf("%d", numStudents*sizeof(*students));

    // reading and writing memory
    // int *ptr;
    // ptr = calloc(4, sizeof(*ptr));

    // *ptr = 5; // writing to the dynamic memory
    // *(ptr + 1) = 12;
    // *(ptr + 2) = 19;
    // *(ptr + 3) = 26;

    // for(int i = 0; i < 4; i ++){ // reading from the dynamic memory
    //     printf("The element %d of dynamic memory ptr is: %d.\n", i+1, *(ptr+i)); 
    // }

    
    // pointer typecasting
    /*int num = 780;
    int *ptr = &num;
    char *mod_ptr = (char*)ptr;

    printf("int pointer %p\n", (void*)ptr); // void* is always the expected argument when %p format specifier is used.
    printf("char pointer %p\n", (void*)mod_ptr);
    printf("physically num is at: %p\n", (void*)&num);
    printf("%p", mod_ptr);*/

    // pointer typecasting
    /*int *ptr1 = malloc(4);  // 4 can be interpreted both as int and char 
    char *ptr2 = (char*)ptr1;

    *ptr1 = 1684234849;
    printf("%d is %c %c %c %c equivalenty.", *ptr1, *ptr2, *(ptr2+1), *(ptr2+2), *(ptr2+3));

    return 0;*/

   
    // Reallocation of memory

   /* int *ptr1 = malloc(sizeof(*ptr1));
    int size = 5*sizeof(*ptr1);
    int *ptr2 = realloc(ptr1, size);

    if(ptr2 == NULL){
        printf("Failed! Reallocation not possible due to lack of memory.\n"); 
        return 1; // very unlikely, return 1 gives an error code and exits the program
    }

    else{
        printf("Success! %d bytes allocated to new memory address pointer ptr2.\n", size);
    } */

   /* printf("ptr1 is at: %p\n", (void*)ptr1); // pointer typecasting to (void*) is essential to be passed to %p
    printf("ptr2 is at: %p\n", (void*)ptr2);  */

   /* free(ptr1);

    printf("ptr1 is at: %p\n", (void*)ptr1); // pointer typecasting to (void*) is essential to be passed to %p
    printf("ptr2 is at: %p\n", (void*)ptr2);  // even after freeing the pointers, their address does not change where they point.
    printf("%d", *ptr1); // dangerous, undefined behaviour */
    

    // memory leaks
    
    // case 1: Overwritten pointer
    /*int x = 5;
    int *ptr = (int*)calloc(3, sizeof(*ptr));
    ptr = &x;*/ // this overwrites the dynamic memory to the memory address of variable x.

    // case 2: pointer exists inside a function

    /* this code is for example purpose only:
    
    void myFunc(){
        int *ptr;
        ptr = calloc(2, sizeof(*ptr)); // Here the pointer scope is limited within the function itself.
    }

    int main(){
        myFunc();
        return 0;
    }
    */

    // case 3: Pointer gets lost when reallocation fails
    
    int *ptr;
    ptr = malloc(sizeof(*ptr));
    ptr = realloc(ptr, 2*sizeof(*ptr)); // if this fails, I would have overwritten my only reference to my original block.
    // Thus, it is a better practice to define another pointer.

    return 0;
}