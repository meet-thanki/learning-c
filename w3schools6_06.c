#include <stdio.h>
#include <string.h>

// C Unions

/*In a union, all members share the same memory and hence only one of them can be used at a time.*/

struct myStruct{
    int myNum;
    char myLetter;
    char myName[20];
};

union myUnion {
    int myNum;
    char myLetter;
    char myName[20];
};


int main(){
    union myUnion u1; 
   // union myUnion u1 = {1000}; // This works perfectly 
   // union myUnion u1 = {"Alice"} // cannot be done as myName string is not declared first in union
   // union myUnion u1 = {1000, 'a', "Alice"}; // compilation error as all have same memory address, hence only one can be used at a time.
    union myUnion *uptr = &u1;

    struct myStruct s1 = {1000, 'A', "Alex"}; 
    struct myStruct *sptr = &s1;

    u1.myNum = 1000;

    u1.myLetter = 'A'; // This is the last value written to u1, hence myNum no longer holds 1000, and is valued as invalid.

    printf("%d\n", u1.myNum); // gives unreliable, unchanging output
    printf("%c\n", u1.myLetter);

    // Size of union: It is equal to the size of the largest member.
    printf("The size of the union is: %zu\n", sizeof(u1)); // returns 20 due to the string myName. each char stores 1 byte and hence 20 bytes is the size of the string.
    printf("The size of the struct is: %zu\n", sizeof(s1)); // returns 28 due to struct padding

    // Memory addresses of members of a union
    printf("%p\n", uptr->myNum);
    printf("%p\n", uptr->myLetter);

    // Memory addresses of members of a struct
    printf("\n%p\n", sptr->myNum); // Each one has a different memory adddress
    printf("%p\n", sptr->myLetter);
    printf("%p\n", sptr->myName); 
    return 0;
}