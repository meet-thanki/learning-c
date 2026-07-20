#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// mini project (related to the w3schools topic): dynamically asking the user for input and registering struct car members

typedef struct{
    char brand[20];
    char model[20];
    int year_of_issue;
} Car;

int main(){
    int specified_size;
    int i = 0;
    printf("How many cars would you like to register? ");
    scanf("%d", &specified_size);

    Car *cars = (Car*)calloc(specified_size, sizeof(Car));

    while(i < specified_size){
        
        printf("Enter brand for car %d:", i+1);
        scanf("%s", cars[i].brand); // Here, & is not to be used as string is being concerned.

        printf("Enter model for car %d:", i+1);
        scanf("%s", cars[i].model); 

        printf("Enter year of issue for car %d:", i+1);
        scanf("%d", &cars[i].year_of_issue);
        
        i++;
    }

    for(int j = 0; j < specified_size; j++){
        printf("For car %d:\nBrand: %s\nModel: %s\nYear of issue: %d", j+1, cars[j].brand, cars[j].model, cars[j].year_of_issue);
    }

    free(cars);
    return 0;
}