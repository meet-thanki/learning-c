#include <stdio.h>
#include <string.h>

// Using pointers with structures

/*Struct pointers are particularly useful when:
1. You want to avoid copying large amounts of data.
2. You want to change values inside a function (illustrated below).
3. You want to creat structs dynamically using memory allocation (remaining, to be done after struct tutorial is completed for me)*/

struct Car{
    char brand[20];
    char model[20];
    int year_of_issue;
};

void updateYear(struct Car *c){
    printf("\nTo what year would you like to change the year of issue? ");
    scanf("%d", &c->year_of_issue); // c->year_of_issue actually evaluates to the stored integer value itself, and we need & to pass its existing memory address to scanf
    printf("\nThe new year of issue is: %d",c->year_of_issue);
}

int main(){
    struct Car c1 = {"BMW", "M5", 2025};
    struct Car *ptr = &c1; // pointer declared of the structure. it is called structure pointer.

    printf("%s\n", ptr->brand); // a kind of dereferencing of a normal pointer
    printf("%s\n", ptr->model);
    printf("%d", ptr->year_of_issue);

    updateYear(ptr);

    return 0;
}