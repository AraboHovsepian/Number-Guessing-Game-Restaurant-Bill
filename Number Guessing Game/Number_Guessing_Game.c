/*
Show a menu consisting of three options. If option 1 is selected then the program
will prompt the user to enter a number and in case of win the program will let the user know
otherwise it will tell the user that the number was low or high and this will continue until the user wins.
q can cause the game to end and return to main. In case the user chooses the 2nd option, the user is going to be
prompted about the max allowable value and then the program will prevent any negative value insertation.
In case of option 3, the program will thank the user and print out the result for the game and number of guesses and quit
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

int main()
{
    int randomNum, menuSelection, maxValue = 10, numGuesses = 0, numGames = 0, numWins = 0, numInt;
    bool won = false;
    char num[100];
    time_t t;

    srand((unsigned)time(&t));

    do
    {
        printf("Press 1 to play a game\nPress 2 to change the max number\nPress 3 to quit\n");
        scanf("%d", &menuSelection);
        fflush(stdin);

        switch (menuSelection)
        {
        case 1:
            numGames += 1;
            randomNum = (rand() % maxValue) + 1;

            do
            {
                printf("Enter a number: ");
                scanf("%s", &num);
                fflush(stdin);

                won = false;

                numInt = atoi(num);
                
                if (isdigit(num[0]))
                {
                    if (numInt == randomNum)
                    {
                        printf("You won!\n");
                        won = true;
                        numWins += 1;
                        numGuesses += 1;
                    }
                    else if (numInt < 1)
                    {
                        printf("Your guess is too low! Guess again.\n");
                        numGuesses += 1;
                    }
                    else if (numInt > maxValue)
                    {
                        printf("Your guess is too high! Guess again.\n");
                        numGuesses += 1;
                    }
                    else if (numInt > 0 && numInt < 11)
                    {
                        printf("Guess again.\n");
                        numGuesses += 1;
                    }
                }
            } while (num[0] != 'q' && won == false);
            break;

        case 2:
            do
            {
                printf("Max value that can be set is 10. Please set the max value: ");
                scanf("%d", &maxValue);
                fflush(stdin);

                if (maxValue > 10 || maxValue < 1)
                {
                    printf("Invalid input.\n");
                }
            } while (maxValue > 10 || maxValue < 1);
            break;

        case 3:
            printf("Thank you for playing the game.");
            if (numWins > 0)
            {
                printf("\nYou've played %d game(s) and won by %d guesse(s) :)", numGames, numGuesses);
            }
            else
            {
                printf("\nYou lost :(");
            }
            break;
        }
    } while (menuSelection != 3);

    return (0);
}