/*Today, I practiced pointers again by making String Tokenizer mini project. Not much, but helpful in
making my concepts stronger. */

#include <stdio.h>

// mini project: String Tokenizer. 

void parser(char string[]);

int main(){
    char test[] = "int x = 99";
    parser(test);
    return 0;
}

void parser(char string[]){
    char* start = string;
    char* scout = string;
    while(*scout != '\0'){
        if(*(scout+1) == ' ' || *(scout+1) == '\0'){
            printf("Token found: %.*s\n", (scout-start) + 1, start); // .* used to explicitly ask the compiler to print the first (scout-start) + 1 chars beginning from start
            start = scout + 2;
            if (*(scout+1) == ' ') {
                scout++;
            }
        }
        scout++;
    }
}