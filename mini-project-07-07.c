/*Today, I wanted to make one last project with rand() function, which is manifested here as the first mini 
project. Next I recalled a 3D geometry concept of shortest distance between any 2 lines in 3D space, and made
the second mini project. Hoping to model more of theoretical math to code in the future!*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// mini project: using rand() function to make a fortune-teller game
/*int main()
{
    int randomPhraseIndex;
    char question[256];
    int press;
    char *fortunes[] = {"It is certain.", // pointer added to indicate an array of strings.
                        "Most likely.",
                        "Ask again later.",
                        "The future is unclear.",
                        "Don't count on it.",
                        "My reply is no.",
                        "Very doubtful.",
                        "Signs point to yes.",
                        "Concentrate and ask again.",
                        "Outlook not so good."};

    while (1)
    {
        srand(time(NULL));
        randomPhraseIndex = rand() % (sizeof(fortunes) / sizeof(fortunes[0]));

        printf("\n\nWelcome to the fortune teller machine!\nAsk any question about your future: ");
        fgets(question, sizeof(question), stdin); // used to read an entire sentence

        printf("Press 1 to lock your question and get an answer from the fortune teller.\nPress 0 to exit the game: ");
        scanf("%d", &press);

        if (press == 1)
        {
            printf("\nAnswer to your question is: %s", fortunes[randomPhraseIndex]);
        }

        else if(press == 0){
            break;
        }
        else
        {
            printf("Please lock your choice.");
        }
    }
    return 0;
}*/

// mini project: 3D geometry: To get the user to input vector equations of 2 lines and to find the least distance between them

double dotProduct(double vector1[3], double vector2[3]);
void crossProduct(double vector1[3], double vector2[3], double resultVector[3]);
void unitVector(double vector[3], double unit[3]);
void subtractVector(double vector2[3], double vector1[3], double resultVector[3]); // function prototype declaration

int main(){
    double vector_a1[3], vector_a2[3], vector_b1[3], vector_b2[3];
    double a2_a1[3], b1xb2[3], unit_b1xb2[3];
    printf("For line L1. Enter the components (i, j, k) of position vector a1 of a point on line L1: \n");
    for(int i = 0; i<3; i++){
        printf("Component %d: ", i +1);
        scanf("%lf", &vector_a1[i]);
    }

    printf("For line L1. Enter the components (i, j, k) of vector b1 along line L1: \n");
    for(int i = 0; i<3; i++){
        printf("Component %d: ", i +1);
        scanf("%lf", &vector_b1[i]);
    }

    printf("For line L2. Enter the components (i, j, k) of position vector a2 of a point on line L2: \n");
    for(int i = 0; i<3; i++){
        printf("Component %d: ", i +1);
        scanf("%lf", &vector_a2[i]);
    }

    printf("For line L2. Enter the components (i, j, k) of vector b2 along line L2: \n");
    for(int i = 0; i<3; i++){
        printf("Component %d: ", i +1);
        scanf("%lf", &vector_b2[i]);
    }

    subtractVector(vector_a2, vector_a1, a2_a1);
    crossProduct(vector_b1, vector_b2, b1xb2);
    unitVector(b1xb2, unit_b1xb2);

    printf("The shortest distance between lines L1 and L2 is: %.2lf.", fabs(dotProduct(a2_a1, unit_b1xb2)));
    return 0;
}

double dotProduct(double vector1[3], double vector2[3]){
    return (vector1[0]*vector2[0] + vector1[1]*vector2[1] + vector1[2]*vector2[2]);
}

void crossProduct(double vector1[3], double vector2[3], double resultVector[3]){
    resultVector[0] = vector1[1]*vector2[2] - vector1[2]*vector2[1];
    resultVector[1] = -(vector1[0]*vector2[2] - vector1[2]*vector2[0]);
    resultVector[2] = vector1[0]*vector2[1] - vector1[1]*vector2[0]; 
}

void unitVector(double vector[3], double unit[3]){
    double magnitude;
    magnitude = sqrt(pow(vector[0],2) + pow(vector[1], 2) + pow(vector[2], 2));
    unit[0] = vector[0]/magnitude;
    unit[1] = vector[1]/magnitude;
    unit[2] = vector[2]/magnitude;
}

void subtractVector(double vector2[3], double vector1[3], double resultVector[3]){
    resultVector[0] = vector2[0] - vector1[0];
    resultVector[1] = vector2[1] - vector1[1];
    resultVector[2] = vector2[2] - vector1[2];
}