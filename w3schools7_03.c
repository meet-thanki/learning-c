#include <stdio.h>

int main(){
    FILE *fptr;
    char myString[100];
    fptr = fopen("filename.txt", "r"); // If I misspell the filename, it would immediately return NULL to the pointer.

    if(fptr != NULL){ // This means the file exists
        while(fgets(myString, 100, fptr) != NULL){ // fgets() function returns NULL when there is no more text to be read after last line.
            printf("%s", myString);
        }
    } 

    else{
        printf("The file does not exist."); // If the file does not exist, this is printed.
    }

    fclose(fptr);
}