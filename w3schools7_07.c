#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// dynamically allocating memory using realloc() function

typedef struct{
    char brand[20];
    char model[20];
    int year_of_issue;
} Car;

int main(){
    int count = 2;
    Car *cars = (Car*)calloc(2, sizeof(Car));

    if(cars == NULL){
        printf("Memory allocation failed!");
        free(cars);
        return 1;
    }

    // initialising values of cars[0] and cars[1]
    strcpy(cars[0].brand, "ABC");
    strcpy(cars[0].model, "DEF");
    cars[0].year_of_issue = 1111;

    strcpy(cars[1].brand, "GHI");
    strcpy(cars[1].model, "JKL");
    cars[1].year_of_issue = 2222;

    int newCount = 3;
    Car *temp = (Car*)realloc(cars, newCount*sizeof(Car));

    if(temp == NULL){
        printf("Memory reallocation failed!");
        free(cars);
        return 1;
    }

    cars = temp; // Important statement

    strcpy(cars[2].brand, "MNO");
    strcpy(cars[2].model, "PQR");
    cars[2].year_of_issue = 3333;

    for(int i = 0; i < newCount; i ++){
        printf("For car %d\nBrand: %s\nModel: %s\nYear of Issue: %d", i+1, cars[i].brand, cars[i].model, cars[i].year_of_issue);
        printf("\n");
    }

    free(cars);
    return 0;
}