#include <stdio.h>
#include <string.h>

// small coding challenge: get the age of a variable derived from struct person.

struct Person{
    int age;
};

int main(){
    struct Person p;
    printf("Enter the age of person p: ");
    scanf("%d", &p.age);
    
    printf("The age of person p is: %d", p.age);
    return 0;
}