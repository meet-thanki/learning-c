/*Today, instead of the usual 2 mini projects per day, I did a quality single project. The user gets to input
system of equations of his choice, and the code calculates the values of the variables using matrix method.
The code is still incomplete, as I still havent taken into account for inconsistent set of equations. I will keep
updating this project later.*/

#include <stdio.h>

// mini project: To find the solution of a system of 3 equations in 3 variables using matrix method

void getMatrix(double matrix[3][3]);
void getConstantMatrix(double matrix[3][1]);
void matMultiplication(double matrix_a_inv[3][3], double matrix_b[3][1], double result[3][1]);
double determinant(double matrix[3][3]);
void multiplyByConst(double matrix[3][3], double num, double result[3][3]);
void transposeMatrix(double matrix[3][3], double transpose_matrix[3][3]);
void getCofactorMatrix(double matrix_a[3][3], double cof_a[3][3]);

int main(){
    double matrix_a[3][3], matrix_b[3][1], cofactor_a[3][3], adj_a[3][3], inverse_a[3][3];
    double result[3][1] = {0}; // initialisation
    getMatrix(matrix_a);
    getConstantMatrix(matrix_b);
    
    getCofactorMatrix(matrix_a, cofactor_a);
    transposeMatrix(cofactor_a, adj_a);
    multiplyByConst(adj_a, 1/(determinant(matrix_a)), inverse_a);
    matMultiplication(inverse_a, matrix_b, result);

    printf("The determinant of coeffienct matrix is: %.2lf", determinant(matrix_a));
    printf("\nThe solution of the system of equations is:\nx = %.2lf\ny = %.2lf\nz = %.2lf", result[0][0], result[1][0], result[2][0]);
    return 0;
}

void getMatrix(double matrix[3][3]){
    for(int i = 0; i < 3; i ++){
        for(int j = 0; j <3; j++){
            switch(j){
                case 0:
                    printf("For equation %d:\nEnter the coefficient of x term: ", i+1);
                    scanf("%lf", &matrix[i][j]);
                    break;
                
                case 1:
                    printf("For equation %d:\nEnter the coefficient of y term: ", i+1);
                    scanf("%lf", &matrix[i][j]);
                    break;
                
                case 2:
                    printf("For equation %d:\nEnter the coefficient of z term: ", i+1);
                    scanf("%lf", &matrix[i][j]);
                    break;
            }
            
        }
    }
}

void getConstantMatrix(double matrix[3][1]){
    for(int i = 0; i < 3; i ++){
        printf("For equation %d:\nEnter the constant term: ", i +1);
        scanf("%lf", &matrix[i][0]);
    }
}

void matMultiplication(double matrix_a_inv[3][3], double matrix_b[3][1], double result[3][1]){
    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 3; j ++){
            result[i][0] += matrix_a_inv[i][j]*matrix_b[j][0];
        }
    }
}

double determinant(double matrix[3][3]){
    double det =  (matrix[0][0]*(matrix[1][1]*matrix[2][2] - matrix[2][1]*matrix[1][2]) - matrix[0][1]*(matrix[1][0]*matrix[2][2] - matrix[2][0]*matrix[1][2]) + matrix[0][2]*(matrix[1][0]*matrix[2][1] - matrix[2][0]*matrix[1][1]));
    return det;
} 

void multiplyByConst(double matrix[3][3], double num, double result[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            result[i][j] = num*matrix[i][j];
        }
    }
}
void transposeMatrix(double matrix[3][3], double transpose_matrix[3][3]){
    for(int i = 0; i < 3; i ++){
        for(int j = 0; j < 3; j ++){
            transpose_matrix[i][j] = matrix[j][i];
        }
    }
}
void getCofactorMatrix(double matrix_a[3][3], double cof_a[3][3]){
    cof_a[0][0] = (matrix_a[1][1]*matrix_a[2][2] - matrix_a[2][1]*matrix_a[1][2]); 
    cof_a[0][1] = -1*(matrix_a[1][0]*matrix_a[2][2] - matrix_a[2][0]*matrix_a[1][2]); 
    cof_a[0][2] = (matrix_a[1][0]*matrix_a[2][1] - matrix_a[2][0]*matrix_a[1][1]); 
    cof_a[1][0] = -1*(matrix_a[0][1]*matrix_a[2][2] - matrix_a[2][1]*matrix_a[0][2]); 
    cof_a[1][1] = (matrix_a[0][0]*matrix_a[2][2] - matrix_a[2][0]*matrix_a[0][2]); 
    cof_a[1][2] = -1*(matrix_a[0][0]*matrix_a[2][1] - matrix_a[2][0]*matrix_a[0][1]); 
    cof_a[2][0] = (matrix_a[0][1]*matrix_a[1][2] - matrix_a[1][1]*matrix_a[0][2]); 
    cof_a[2][1] = -1*(matrix_a[0][0]*matrix_a[1][2] - matrix_a[1][0]*matrix_a[0][2]); 
    cof_a[2][2] = (matrix_a[0][0]*matrix_a[1][1] - matrix_a[1][0]*matrix_a[0][1]); 
}