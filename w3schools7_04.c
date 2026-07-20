#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char brand[20];
    char model[20];
    int year_of_issue;
} Car;

int main(){
    Car *ptr = (Car*)malloc(sizeof(Car)); // Size of car should be around 44 bytes

    if(ptr == NULL){ // malloc returns NULL if allocation of dynamic memory was unsuccessful
        printf("Memory Allocation Failed!");
        return 1; // throw compilation error code
    }
    
    strcpy(ptr->brand, "BMW");
    ptr->year_of_issue = 2025;

    printf("Brand: %s\n", ptr->brand);
    printf("Year of Issue: %d\n", ptr->year_of_issue);
    printf("%zu", sizeof(Car));

    free(ptr);

    return 0;
}