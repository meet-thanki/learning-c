#include <stdio.h>

// creating and writing to files in C

int main(){
    FILE *fptr; // pointer declared of the data type FILE
    // fptr = fopen("filename.txt", "w"); // use only double quotation here // if not already present, it creates a file of the given name
    fptr = fopen("filename.txt", "a"); // append mode
    
    // writing to the file
    fprintf(fptr, "\nSome Text Here");

    // appending to the file, this means that old content is not deleted
    fprintf(fptr, "\nThis text has been appended.");
    fclose(fptr); // used to close the file entirely
    return 0;
}