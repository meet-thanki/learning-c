// The title was intended to be: Translating 3D Geometry, Matrices and Determinants to coding.

/*Today, I made 2 mini projects, one on 3D geometry and one on Matrices and Determinants. I have always loved
mathematics and I really wanted to experience it in coding. Along the way, I learnt about 2D arrays too.
This is one of the best mini projects I believe I have done so far. Thank you for reading!*/

#include <stdio.h>
#include <math.h>
#define PI 3.14

// mini project: 3D geometry: to find the angle between two 3D straight lines.

/*void getVector(double vector[3]);
double dotProduct(double vector1[3], double vector2[2]);
double getMagnitude(double vector[3]);
double getAngle(double vector1[3], double vector2[3]);

int main(){
    double vector_a1[3], vector_a2[3], vector_b1[3], vector_b2[3];

    printf("For line L1:\nEnter the components (i, j, k) of position vector a1 of point on line L1: \n");
    getVector(vector_a1);

    printf("For line L1:\nEnter the components (i, j, k) of vector b1 along line L1: \n");
    getVector(vector_b1);

    printf("For line L2:\nEnter the components (i, j, k) of position vector a2 of point on line L2: \n");
    getVector(vector_a2);

    printf("For line L2:\nEnter the components (i, j, k) of vector b2 along line L2: \n");
    getVector(vector_b2);

    printf("The angle between lines L1 and L2 is: %.2lf degrees.", (getAngle(vector_b1, vector_b2))*180/PI);

    return 0;
}

void getVector(double vector[3]){
    for(int i = 0; i < 3; i++){
        printf("Component %d: ", i + 1);
        scanf("%lf", &vector[i]);
    }
}

double dotProduct(double vector1[3], double vector2[2]){
   return (vector1[0]*vector2[0] + vector1[1]*vector2[1] + vector1[2]*vector2[2]);
}

double getMagnitude(double vector[3]){
    return (sqrt(pow(vector[0], 2) + pow(vector[1], 2) + pow(vector[2], 2)));
}

double getAngle(double vector1[3], double vector2[3]){
    double dot, mag1, mag2;
    dot = dotProduct(vector1, vector2);
    mag1 = getMagnitude(vector1);
    mag2 = getMagnitude(vector2);

    return (acos(dot/(mag1 * mag2))); // use of inverse cosine to find the angle using the well-known dot product formula
} */

// mini project: Matrices and Determinants: To get the user to input a matrix, display it and calculate its determinant.

void fillMatrix(double mat[3][3]);
void displayMatrix(double mat[3][3]);
double determinant(double mat[3][3]);

int main()
{
    double matrix[3][3]; // specifying the order of the matrix 3x3 --> square matrix
    char choice;
    printf("Please fill the matrix as per the instructions: \n");
    fillMatrix(matrix);

    printf("Would you like to calculate the determinant of this matrix? (y/n) (Typing n would display the matrix)\n");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y')
    {
        printf("The determinant of this matrix is: %.2lf.", determinant(matrix));
    }

    else if (choice == 'n' || choice == 'N')
    {
        printf("The matrix is as shown below: \n");
        displayMatrix(matrix);
    }

    else
    {
        printf("Please enter either y or n.");
    }
    return 0;
}

void fillMatrix(double mat[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("Enter the element a(%d, %d): ", i + 1, j + 1);
            scanf("%lf", &mat[i][j]);
        }
    }
}

void displayMatrix(double mat[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%.lf ", mat[i][j]);
        }
        printf("\n");
    }
}

double determinant(double mat[3][3])
{
    return (mat[0][0] * (mat[1][1] * mat[2][2] - mat[2][1] * mat[1][2]) - mat[0][1] * (mat[1][0] * mat[2][2] - mat[2][0] * mat[0][2]) + mat[0][2] * (mat[1][0] * mat[2][1] - mat[2][0] * mat[1][1]));
}
