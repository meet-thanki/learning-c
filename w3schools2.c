/*Today, I learnt more C syntax in w3schools. Along with the below code, I also make handwritten notes, 
which helps me revise things later. The code lines are very simple compared to my previous projects, but
simple things eventually lead to extraordinary ones!*/

#include <stdio.h>


// changing the value of variables 

/*int main(){
    int num1 = 10, num2;
    printf("Current value of variable num1 is %d. \nEnter a new value for the variable num1: ", num1);
    scanf("%d", &num2);

    num1 = num2; // the change of value happens here
    printf("The new value of variable num1 is: %d.", num1);
    return 0;
}*/

// changing the value of variable using the variable itself.

/*int main(){
    int x, input;
    printf("Enter the value of integer you would like to have: ");
    scanf("%d", &x);

    printf("Select 1 to increase the value of varibale x by one.\nSelect 0 to decrease the value of x by one: ");
    scanf("%d", &input);

    if(input == 1){
        x = x + 1; // changing the variable using the variable value itself.
        printf("The updated value of the variable x is %d. ", x);
    }

    else if(input == 0){
        x = x - 1;
        printf("The updated value of the variable x is %d. ", x); 
    }

    else{
        printf("Please enter either 1 or 0 only.");
    }

    return 0;
} */

// handling student data using appropriate variable names

/*int main(){
    int studentID = 21;
    int studentAge = 18;
    char studentGrade = 'A';
    float studentFee = 37000.50;
    
    printf("Student ID: %d", studentID);
    printf("\nStudent Age: %d", studentAge);
    printf("\nStudent Grade: %c", studentGrade);
    printf("\nStudent Fee: %.2f", studentFee);
    return 0;
}*/

// calculate the area of a rectangle

double area(double l, double b); // function prototype declaration

int main(){
    double length, breadth;
    printf("Please enter the length of the rectangle: ");
    scanf("%lf", &length);
    
    printf("Please enter the breadth of the rectangle: ");
    scanf("%lf", &breadth);

    printf("The area of the rectangle is: %.2lf sq. units", area(length, breadth));
    return 0;
}

double area(double l, double b){
    return (l*b);
}