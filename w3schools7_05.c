#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Using arrays with structs and allocating memory

typedef struct{
    char brand[20];
    char model[20];
    int year_of_issue;
} Car;

int main(){
    Car *cars = (Car*)malloc(3*sizeof(Car));

    if(cars == NULL){
        printf("Memory Allocation Failed!");
    }

    strcpy(cars[0].brand, "BMW");
    strcpy(cars[0].model, "M5");
    cars[0].year_of_issue = 2025;

    strcpy(cars[1].brand, "Honda");
    strcpy(cars[1].model, "Hero");
    cars[1].year_of_issue = 2021;

    for(int i = 0; i < 2; i ++ ){
        printf("%s: %d\n", cars[i].brand, cars[i].year_of_issue);
    }

    free(cars);
    return 0;
}