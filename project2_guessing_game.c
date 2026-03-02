/*
 * PROJECT 2 - Number Guessing Game
 *
 * The computer picks a random number, you try to guess it.
 * Concepts used: loops, conditionals, random numbers, user input.
 *
 * Compile: gcc project2_guessing_game.c -o guessing_game
 */

#include <stdio.h>
#include <stdlib.h>  // rand, srand
#include <time.h>    // time (for seeding random)
#include <stdbool.h>

int main(void)
{
    // Seed the random number generator with current time
    srand((unsigned int)time(NULL));

    printf("=============================\n");
    printf("   Number Guessing Game\n");
    printf("=============================\n");

    char play_again;

    do {
        int max_range = 100;
        int secret = (rand() % max_range) + 1;  // random number 1-100
        int guess;
        int attempts = 0;
        int max_attempts = 7;
        bool won = false;

        printf("\nI'm thinking of a number between 1 and %d.\n", max_range);
        printf("You have %d attempts. Good luck!\n\n", max_attempts);

        while (attempts < max_attempts) {
            attempts++;
            printf("Attempt %d/%d - Your guess: ", attempts, max_attempts);

            if (scanf("%d", &guess) != 1) {
                printf("Please enter a valid number!\n");
                while (getchar() != '\n');
                attempts--;  // don't count invalid input
                continue;
            }

            if (guess < 1 || guess > max_range) {
                printf("Out of range! Guess between 1 and %d.\n", max_range);
                attempts--;
                continue;
            }

            if (guess == secret) {
                printf("\nYou got it in %d attempt%s!\n",
                       attempts, attempts == 1 ? "" : "s");

                if (attempts <= 3) printf("Incredible!\n");
                else if (attempts <= 5) printf("Well done!\n");
                else printf("Just in time!\n");

                won = true;
                break;
            } else if (guess < secret) {
                printf("Too low!");
            } else {
                printf("Too high!");
            }

            // Give a hint about how close they are
            int diff = abs(secret - guess);
            if (diff <= 3)       printf(" (Very close!)\n");
            else if (diff <= 10) printf(" (Getting warm)\n");
            else if (diff <= 25) printf(" (Not bad)\n");
            else                 printf(" (Way off)\n");
        }

        if (!won) {
            printf("\nOut of attempts! The number was %d.\n", secret);
        }

        printf("\nPlay again? (y/n): ");
        scanf(" %c", &play_again);

    } while (play_again == 'y' || play_again == 'Y');

    printf("Thanks for playing!\n");
    return 0;
}
