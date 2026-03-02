/*
 * 03 - Control Flow
 *
 * if/else, switch, loops, and break/continue.
 * Compile: gcc 03_control_flow.c -o 03_control_flow
 */

#include <stdio.h>
#include <stdbool.h>  // gives us 'true' and 'false' keywords

int main(void)
{
    // --- if / else if / else ---
    printf("=== If/Else ===\n");
    int score = 75;

    if (score >= 90) {
        printf("Grade: A\n");
    } else if (score >= 80) {
        printf("Grade: B\n");
    } else if (score >= 70) {
        printf("Grade: C\n");
    } else if (score >= 60) {
        printf("Grade: D\n");
    } else {
        printf("Grade: F\n");
    }

    // --- Ternary operator (shorthand if/else) ---
    int age = 20;
    const char *status = (age >= 18) ? "adult" : "minor";
    printf("Age %d is: %s\n", age, status);

    // --- Switch statement ---
    printf("\n=== Switch ===\n");
    int day = 3;

    switch (day) {
        case 1: printf("Monday\n");    break;
        case 2: printf("Tuesday\n");   break;
        case 3: printf("Wednesday\n"); break;
        case 4: printf("Thursday\n");  break;
        case 5: printf("Friday\n");    break;
        case 6: printf("Saturday\n");  break;
        case 7: printf("Sunday\n");    break;
        default: printf("Invalid day\n");
    }

    // --- While loop ---
    printf("\n=== While Loop ===\n");
    int count = 5;
    while (count > 0) {
        printf("Countdown: %d\n", count);
        count--;
    }
    printf("Liftoff!\n");

    // --- Do-while loop (runs at least once) ---
    printf("\n=== Do-While Loop ===\n");
    int num = 1;
    do {
        printf("%d ", num);
        num *= 2;
    } while (num <= 64);
    printf("\n");

    // --- For loop ---
    printf("\n=== For Loop ===\n");
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }

    // --- Break and Continue ---
    printf("\n=== Break & Continue ===\n");
    for (int i = 1; i <= 20; i++) {
        if (i % 3 == 0) continue;  // skip multiples of 3
        if (i > 15) break;          // stop at 15
        printf("%d ", i);
    }
    printf("\n");

    // --- Boolean logic ---
    printf("\n=== Boolean Logic ===\n");
    bool is_sunny = true;
    bool is_warm = false;

    if (is_sunny && is_warm) {
        printf("Go to the beach!\n");
    } else if (is_sunny || is_warm) {
        printf("Go for a walk.\n");
    } else {
        printf("Stay inside.\n");
    }

    return 0;
}
