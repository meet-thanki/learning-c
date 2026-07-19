/*Today, I learned structs in C. I have made 9 different files to organise my code better. This is to 
avoid the green lush comments of 100 lines that I used to have in my files before. I shall gain more
confidence in structs after some more mini projects.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// C Structures introduction

struct myStruct{
    int myNum;
    char myLetter;
    char myName[20];
};

int main(){
    struct myStruct s1 = {18, 'A', "Alice"};
    struct myStruct s2; 
    
    // struct myStruct s1 = {18, 'A', "Alice"}; // this works perfectly
    // s1.myName = "Alice"; //error. myName is a pointer to the first index of the string. it is not modifiable.

    strcpy(s1.myName, "Some Text");  // To use this function, include string.h
    // Using this line, the value of myName is modified to "Some Text"

    s2.myNum = 20;
    s2.myLetter = 'B';
    printf("In my structure s1, my number is %d\nand my letter is %c.\nMy name is %s.", s1.myNum, s1.myLetter, s1.myName);
    
    // Copy structures:
    /*struct myStruct s1 = {17, 'a', "Matt"};
      struct myStruct s2;
      s2 = s1; //valid */
    return 0;
}