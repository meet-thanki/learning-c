#include <stdio.h>
#include <string.h>

// using typedef keyword in nested structs
typedef struct{
    char firstName[20];
    char lastName[20];
} Owner;

typedef struct{
    char brand[20];
    char model[20];
    int year_of_issue;
    Owner owner;
} Car;

typedef struct{
    char name[20];
    Car featuredCar;
} Dealership;

int main(){
    Owner o1 = {"Meet", "Thanki"};
    Car c1 = {"BMW", "M5", 2025, o1};
    Dealership d1 = {"Amar Motor", c1};

    printf("The dealership is: %s\n", d1.name);
    printf("The car brand is: %s\n", d1.featuredCar.brand);
    printf("The car model is: %s\n", d1.featuredCar.model);
    printf("The year of issue of the car is: %d\n", d1.featuredCar.year_of_issue);
    printf("The first name of the car owner is: %s\n", d1.featuredCar.owner.firstName);
    printf("The last name of the car owner is: %s\n", d1.featuredCar.owner.lastName);
}