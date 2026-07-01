/*Today, I spent my time to revise and apply some crucial maths concepts to code,
namely quadratic equations and vector algebra. My foundational logic building in
Python is helping me to understand syntax of C better through the mode of mini projects like these!*/


#include <stdio.h>
#include <math.h>

// mini project 1: get the user to input a quadratic equation using coefficients and constant term and return the roots of the equation.

/* int main(){
    double a, b, c, discriminant, root1, root2;
    printf("Enter the coefficient of x^2: ");
    scanf("%lf", &a);
    printf("Enter the coefficent of x: ");
    scanf("%lf", &b);
    printf("Enter the constant term: ");
    scanf("%lf", &c);    // learnt that throwing in %f as a format specifier gives a humungous error. this is pointer type mismatching, a thing i learnt by applying logic to problems.

    discriminant = b*b - 4*a*c;

    if(discriminant > 0){
        root1 = (-b + sqrt(discriminant))/(2*a);
        root2 = (-b - sqrt(discriminant))/(2*a);

        printf("The roots are real and disctinct. Roots are: %.2f and %.2f.", root1, root2);
    }

    else if(discriminant == 0){
        root1 = root2 = -b/(2*a);

        printf("Both roots are equal. Roots are: %.2f and %.2f.", root1, root2);
    }

    else{
        printf("Roots do not exist for the equation.");
    }
} */

// mini project: get the user to input 2 vectors and calculate the dot product.

double dot(double vector1[], double vector2[]); // Function prototype declaration absolutely necessary. I forgot it and faced error!

int main(){
    double vector_a[3], vector_b[3], result;
    printf("Enter the 3 components (i, j, k) of the vector A: \n");

    for(int i = 0; i < 3; i++){
        printf("Component %d: ", i+1);
        scanf("%lf", &vector_a[i]);
    }

    printf("Enter the 3 components (i, j, k) of the vector B: \n");

    for(int i = 0; i < 3; i++){
        printf("Component %d: ", i+1);
        scanf("%lf", &vector_b[i]);
    }
    
    result = dot(vector_a, vector_b);
    printf("The dot product of both the vectors is: %.2lf. ", result);

    if(result == 0){
        printf("\nBoth the vectors are perpendicular to each other.");
    }
}

double dot(double vector1[], double vector2[]){
    double dot_product = 0.0;

    for(int i=0; i<3; i++){
        dot_product += vector1[i]*vector2[i];
    }

    return dot_product;
}