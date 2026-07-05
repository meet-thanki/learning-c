/*Today again, I used the rand() function to make two mini projects, a password generator and a Casino style
rolling a pair of die game. The second project really tested my foundations. I shall be returning to practicing
C syntax from w3schools in the upcoming days' commits. See you then!*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// mini project: random password generator
/*
int main(){
    int length;
    char lowercasePool[] ="abcdefghijklmnopqrstuvwxyz";
    char uppercasePool[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int numeralPool[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    char specialPool[] = "`!@#$%^&*-_+=";

    srand(time(NULL));
    printf("Enter the preferred length of your password: (8-50)");
    scanf("%d", &length);

    if((length < 8) || (length > 50)){
        printf("Please enter a value in the above prescribed range.");
    }

    else{
        for(int i = 0; i < length; i++){
        int lowerRandomIndex, upperRandomIndex, numeralRandomIndex, specialRandomIndex;

        switch (i%4)        // switch case to ensure all types of characters, integers and special symbols are generated.
        {
        case 0:
            lowerRandomIndex = rand() % (sizeof(lowercasePool) - 1);
             printf("%c", lowercasePool[lowerRandomIndex]);
            break;

        case 1:
            upperRandomIndex = rand() % (sizeof(uppercasePool) - 1);
            printf("%c", uppercasePool[upperRandomIndex]);
            break;

        case 2:
            numeralRandomIndex = rand() % 10;
            printf("%d", numeralPool[numeralRandomIndex]);
            break;

        case 3:
            specialRandomIndex = rand() % (sizeof(specialPool) - 1);
            printf("%c", specialPool[specialRandomIndex]);
            break;
        }
    }
    }

}
*/

// mini project 2: casino crap game.
/* The player rolls a pair of die.
On the opening roll: getting a 7 or 11 is an instant win while getting 2, 3, or 12 is instant loss.
Rolling anything else besides becomes your target "The point".

On the succeeding throws: avoid getting 7 which is an instant loss.
The player wins by getting "The point" number on his roll. */

/*The logistics for the game took me half an hour to frame. This was indeed a step-up in the level of
mini projects that I am creating.*/

int main()
{   
    game_over_label:
    while (1)
    {
        int sum, firstThrow, secondThrow, firstResult, secondResult;
        srand(time(NULL));
        printf("\n\nWelcome to the Casino Crap game!\nPress 0 to exit the game. \n\nPress 1 to roll the first die: ");
        scanf("%d", &firstThrow);

        if(firstThrow == 0){
            break;
        }
        else if (firstThrow == 1)
        {
            firstResult = (rand() % 6) + 1;
            printf("You rolled %d on your first throw. ", firstResult);
        }

        else
        {
            printf("Please press 1 only.");
        }
        printf("\n\nPress 2 to roll the second die: ");
        scanf("%d", &secondThrow);

        if (secondThrow == 2)
        {
            secondResult = (rand() % 6) + 1;
            printf("You rolled %d on your second throw. ", secondResult);
        }

        else
        {
            printf("Please press 2 only.");
        }

        sum = firstResult + secondResult;
        printf("\n\nThe sum of numbers rolled on the pair of die is %d.\n", sum);

        if ((sum == 7) || (sum == 11))
        {
            printf("You won!");
            goto game_over_label;
        }
        else if ((sum == 2) || (sum == 3) || (sum == 12))
        {
            printf("You lost!");
            goto game_over_label;
        }

        else
        {
            printf("\nYou have rolled %d.\n%d is now THE POINT.", sum, sum);
            while (1)
            {
                int newSum, newFirstThrow, newSecondThrow, newFirstResult, newSecondResult;
                srand(time(NULL));
                printf("\n\nWelcome again to the Casino Crap game! \nFor your succeeding throws: \n\nPress 1 to roll the first die: ");
                scanf("%d", &newFirstThrow);

                if (newFirstThrow == 1)
                {
                    newFirstResult = (rand() % 6) + 1;
                    printf("You rolled %d on your first throw. ", newFirstResult);
                }

                else
                {
                    printf("\nPlease press 1 only.");
                }
                printf("\n\nPress 2 to roll the second die: ");
                scanf("%d", &newSecondThrow);

                if (newSecondThrow == 2)
                {
                    newSecondResult = (rand() % 6) + 1;
                    printf("You rolled %d on your second throw. ", newSecondResult);
                }

                else
                {
                    printf("\nPlease press 2 only.");
                }

                newSum = newFirstResult + newSecondResult;
                printf("\n\nThe sum of numbers rolled on the pair of die is %d.\n", newSum);

                if (newSum == sum)
                {
                    printf("Since you got the sum of next throw same as that of previous throw, you won!");
                    goto game_over_label;
                }

                else if (newSum == 7)
                {
                    printf("7 is not lucky anymore. You lose!");
                    goto game_over_label;
                }
                else
                {
                    continue;
                }
            }
        }
    }
    return 0;
} 