#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// real-life example

struct Car{
    char brand[20];
    char model[20];
    int engineParts;
};

int main(){
    struct Car c1 = {"BMW", "M5", 5};
    struct Car c2 = {"Porsche", "S7", 6};
    struct Car c3 = {"Bugatti", "Chiron", 9};

    printf("%s %s %d\n", c1.brand, c1.model, c1.engineParts);
    printf("%s %s %d\n", c2.brand, c2.model, c2.engineParts);
    printf("%s %s %d", c3.brand, c3.model, c3.engineParts);
    return 0;
}