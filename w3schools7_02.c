#include <stdio.h>

// reading files and printing the content

int main(){
    FILE *fptr;
    char myString[100];

    fptr = fopen("filename.txt", "r");
    // fgets(myString, 100, fptr); // this stores the data of the file. fgets only stores the first line.

    // To read only one line
    // printf("%s\n\n", myString);

    // To read multiple lines
    while(fgets(myString, 100, fptr)){ // Hidden condition: while(fgets(myString, 100, fptr) != NULL) or while(//condition is true)
        printf("%s", myString);
    }

    fclose(fptr);
    return 0;
}