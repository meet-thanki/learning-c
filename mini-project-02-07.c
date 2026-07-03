#include <stdio.h>
#include <math.h>

// mini project: to input two vectors from user and calculate the cross product or calculate unit vector.
double cross(double vector1[], double vector2[]);
double unit(double vector[]);

int main(){
    double vector_a[3], vector_b[3];
    int select;
    int a_or_b;
    printf("Enter the components (i, j, k) of vector A: \n");
    for(int i = 0; i < 3; i++){
        printf("Component %d: ", i+1);
        scanf("%lf", &vector_a[i]);
    }

    printf("Enter the components (i, j, k) of vector B: \n");
    for(int i = 0; i < 3; i++){
        printf("Component %d: ", i+1);
        scanf("%lf", &vector_b[i]);
    }

    printf("Select which operation to apply on the vectors: \n1. Find unit vector.\n2. Calculate cross product (AxB).");
    scanf("%d", &select);

    if(select == 1){
        printf("Unit vector for vector A (press 1) or vector B (press 2)? ");
        scanf("%d", &a_or_b);

        if(a_or_b == 1){
            unit(vector_a);
        }

        else if(a_or_b == 2){
            unit(vector_b);
        }

        else{
            printf("Please enter a valid number. ");
        }
    }

    else if(select == 2){
        cross(vector_a, vector_b);
    }
    
    else{
        printf("Please enter a valid number.");
    }
}

double cross(double vector1[], double vector2[]){
    double resultant[3];
    resultant[0] = (vector1[1]*vector2[2] - vector2[1]*vector1[2]);
    resultant[1] = -(vector1[0]*vector2[2] - vector2[0]*vector1[2]);
    resultant[2] = (vector1[0]*vector2[1] - vector2[0]*vector1[1]);
    
    return printf("The cross product vector of the given vectors (A x B) is: (%.2lf, %.2lf, %.2lf)", resultant[0], resultant[1], resultant[2]);
}

double unit(double vector[]){
    double unit1[3], modulus;
    modulus = sqrt(pow(vector[0], 2) + pow(vector[1], 2) + pow(vector[2], 2));
    unit1[0] = vector[0]/(modulus);
    unit1[1] = vector[1]/(modulus);
    unit1[2] = vector[2]/(modulus);

    return printf("The unit vector of given vector is: (%.2lf, %.2lf, %.2lf)", unit1[0], unit1[1], unit1[2]);
}


// mini project 2: