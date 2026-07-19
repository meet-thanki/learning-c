#include <stdio.h>
#include <string.h>

// nested structures

struct Owner{
    char firstName[20];
    char lastName[20];
};

struct Car{
    char brand[20];
    char model[20];
    int year_of_issue;
    struct Owner owner; // car structure contains another structure Owner inside of it.
};

int main(){
    struct Owner p = {"Meet", "Thanki"};
    struct Car c1 = {"BMW", "M5", 2025, p};

    printf("The car is: %s\n", c1.brand);
    printf("The car model is: %s\n", c1.model);
    printf("The year of issue of the car is: %d\n", c1.year_of_issue);
    printf("The owner of the car is: %s %s", c1.owner.firstName, c1.owner.lastName);
    return 0;
}