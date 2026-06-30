/* Today I learned basic syntax for C from w3schools.com 
I also made 2 mini projects using my python logic foundations.
I hope to make more and be good at this language soon! */

#include <stdio.h>

// int main(){
//     char name[] = "Meet";
//     printf("Hello %s", name);
//     return 0;
// }

// int main(){
//     char name[] = "C";
//     printf("Hello %s", name);
//     return 0;
// }

// using many printf statements to print things on the same line

// int main(){
//     printf("Hello");
//     printf("my name is");
//     printf("meet");
//     return 0;
// }

// using \n character to generate new lines

// int main(){
//     printf("Hello \n \tMy name is Meet.");
//     return 0;
// }





// challenge

// int main(){
//     printf("Hello World!\n");
//     printf("\nI am learning C.");
//     return 0;
// }



// mini project: asking the user for a radius input and printing area of the circle concerned.

//  #define PI 3.14159

// int main(){
//     float radius, container;
//     printf("Please enter the value of radius of the circle in cms: ");
//     scanf("%f", &radius);

//     container = PI*radius*radius;
//     printf("The required area is %f sq cms.", container);
//     return 0;
// }



// mini project: asking the user for two numbers and performing arithmetics. (using my logic building developed earlier from python)

int main(){
    int a, b, c;
    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);
    printf("Enter numbers according to the following breakdown. \n1. Addition \n2. Subtraction\n3. Multiplication\n4. Division:  ");
    scanf("%d", &c);

    if(c == 1){
        int e = a + b;
        printf("The addition of both the numbers is %d.", e);
    }

    else if(c == 2){
        int f = a - b;
        printf("The subtraction result of both the numbers (first - second) is %d." , f);
    }

    else if(c == 3){
        int g = a*b;
        printf("The multipication result of both the numbers is %d.", g);
    }

    else if(c == 4){
        if( b == 0){
            printf("The division isn't possible due to division by zero error. ");
        }
        else{
            float h = ((float) a)/((float) b);    // typecasting
            printf("The division result of both the numbers (first/second) is %f.", h);
        }
    }

    else{
        printf("Please choose between 1 to 4 only.");
    }
    return 0;

}