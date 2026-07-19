#include <stdio.h>
#include <string.h>

// Using typedef keyword with structs

typedef struct{
    char brand[20];
    char model[20];
    int year_of_issue;
}Car; // using typedef, the code can be simplified and better for everyday viewing

// example: using temperature as a typedef keyword for a floating point value.
typedef float Temperature;

int main(){
    // Temperature start_of_day_C = 37;
    // Temperature end_of_day_C = 28;

    // printf("Temperature at the start of the day is: %.2f *C\n", start_of_day_C);
    // printf("Temperature at the end of the day is: %.2f *C", end_of_day_C);

    Car c1 = {"BMW", "M5", 2025};
    // struct Car c1 = {"BMW", "M5", 2025}; // This is no longer allowed. Thus the code is better adjusted and easier to read.
    Car c2 = {"Ford", "Mustang", 1969};
    Car c3 = {"Toyota", "Corolla", 2011}; // It is now easier to work with different car brands.

    return 0;
}