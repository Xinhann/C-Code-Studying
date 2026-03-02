/*
 * PROJECT 1 - Calculator
 *
 * A simple calculator that reads two numbers and an operator.
 * Concepts used: functions, switch, scanf, input validation.
 *
 * Compile: gcc project1_calculator.c -o calculator
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>  // for fabs (floating point absolute value)

// Function prototypes
double calculate(double a, double b, char op, bool *success);
void print_menu(void);

int main(void)
{
    printf("===========================\n");
    printf("   Simple C Calculator\n");
    printf("===========================\n");

    char choice;

    do {
        print_menu();

        double a, b;
        char op;

        printf("Enter expression (e.g. 5 + 3): ");
        if (scanf("%lf %c %lf", &a, &op, &b) != 3) {
            printf("Invalid input! Try again.\n");
            // Clear the input buffer
            while (getchar() != '\n');
            continue;
        }

        bool success;
        double result = calculate(a, b, op, &success);

        if (success) {
            printf("  %.4g %c %.4g = %.4g\n", a, op, b, result);
        } else {
            printf("  Error: invalid operation or division by zero.\n");
        }

        printf("\nAnother calculation? (y/n): ");
        scanf(" %c", &choice);  // space before %c skips whitespace

    } while (choice == 'y' || choice == 'Y');

    printf("Goodbye!\n");
    return 0;
}

double calculate(double a, double b, char op, bool *success)
{
    *success = true;

    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/':
            if (fabs(b) < 1e-10) {  // check for division by zero
                *success = false;
                return 0;
            }
            return a / b;
        case '%':
            if ((int)b == 0) {
                *success = false;
                return 0;
            }
            return (int)a % (int)b;
        case '^':
            return pow(a, b);
        default:
            *success = false;
            return 0;
    }
}

void print_menu(void)
{
    printf("\nOperators: + - * / %% ^ (power)\n");
}
