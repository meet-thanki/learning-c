/*Today I made one mini project to have my pointers fundamentals challenged. It is still quite a new
concept to me, and it will take time for me to get used to it.*/

#include <stdio.h>

// mini project: custom string manipulation library with the use of pointers

int str_length(char string[]); // function prototype declaration
void str_copy(char source[], char destination[]);
void str_reverse(char string[]);

int main(){
    char name[] = "Meet Thanki";
    int length = str_length(name);
    printf("The length of the string is: %d\n", length);

    char source[] = "Copy-Me!";
    char destination[20];
    str_copy(source, destination);
    printf("The destination string is: %s\n", destination);

    char word[] = "mar";
    printf("The original word is: %s\n", word);
    str_reverse(word);
    printf("The reversed word is: %s\n", word);

    return 0;
}

int str_length(char string[]){
    int count = 0; // initialisation important always
    char* pointer_index = string;

    while(1){
        if(*pointer_index == '\0'){
            break;
        }

        pointer_index++;
        count++;
    }  
    
    return count;
}

void str_copy(char source[], char destination[]){
    while(*source != '\0'){
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
}

void str_reverse(char string[]){
    char* start = string;
    char* end = string + str_length(string) - 1; // -1 to skip \0 at the end of the string

    while(start < end){
        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}