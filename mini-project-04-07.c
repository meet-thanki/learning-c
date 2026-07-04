/*Today, I tried learning rand() and time() functions in C and made two small games. I have had fascination for 
new module functions since my study in Python. Can't wait to learn more!*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// mini project 1: guess the number game.
/*int main(){
    int guess;
    srand(time(NULL)); // important statement to ensure different numbers generate each time
    int randomNumber = (rand() % 100) + 1; // limits the choices between 1-100

    while (1){          // using infinite loop to continually ask the user to input numbers till he gets it correct.
        printf("Guess a number between 1 to 100: ");
        scanf("%d", &guess);

        if(guess > randomNumber){
            printf("Lower number please.\n");
            continue;
        }

        else if(guess < randomNumber){
            printf("Higher number please.\n");
            continue;
        }

        else{
            printf("You guessed the number correct!\nThe number was: %d", randomNumber);
            break;
        }
    }
}*/

// mini project 2: rock, paper and scissors game
// enter taskkill /im mini-project-04-07.exe /f to refresh the terminal if infinite loop does not stop.

int main()
{
    int guess;
    srand(time(NULL)); // important statement so that different numbers generate
    char *choices[] = {"", "Rock", "Paper", "Scissors"}; // asterisk important here as to create array of string pointers.

    int randomNumber = (rand() % 3) + 1; // limits choices between 1-3

    while (1)
    {
        printf("The computer has locked its choice.\nChoose: Rock(1), Paper(2), or Scissors(3)?\nEnter your choice (1-3): \nPress 4 to exit the game. ");
        scanf("%d", &guess);
        if(guess == 4){
            printf("Exiting. Thank you for playing.");
            break;
        }

        else if (guess > 4 || guess < 1)
        {
            printf("Invalid choices. Exiting game.");
            break;
        }
        
        else
        {
            if (randomNumber == guess)
            {
                printf("It's a tie!.\nYou chose: %s\nComputer chose: %s\n\n", choices[guess], choices[randomNumber]);
            }

            else if ((randomNumber == 1 && guess == 2) || (randomNumber == 2 && guess == 3) || (randomNumber == 3 && guess == 1))
            {
                printf("You win!\nYou chose: %s\nComputer chose: %s\n\n", choices[guess], choices[randomNumber]);
            }

            else
            {
                printf("You lost!\nYou chose: %s\nComputer chose: %s\n\n", choices[guess], choices[randomNumber]);
            }
        }
    }
}