/*Tried learning pointers today. The lines of code is few compared to what I have uploaded before, probably
because of facing a block due to learning a foreign concept entirely from w3schools. I shall try to gain mastery
over pointers in a few days.*/

#include <stdio.h>

// int main(){
//     int myAge = 17;
//     int* ptr = &myAge;

//     printf("%d\n", myAge);
//     printf("%p\n", &myAge);
//     printf("%d", *ptr);
//     return 0;
// }

int main(){
    int numbers[] = {1, 5, 7, 8, 9, 10};

    for(int i = 0; i < (sizeof(numbers)/sizeof(numbers[0])); i ++){
        printf("%d\n", *(numbers + i));
    }
}