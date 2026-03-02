/*
 * 02 - Functions
 *
 * How to write reusable functions in C.
 * Compile: gcc 02_functions.c -o 02_functions
 */

#include <stdio.h>

// --- Function declarations (prototypes) ---
// Declare functions before main() so the compiler knows they exist.
int add(int a, int b);
int factorial(int n);
void print_line(char ch, int length);
void swap(int *a, int *b);  // uses pointers — preview of lesson 04!

int main(void)
{
    // --- Basic function calls ---
    printf("=== Basic Functions ===\n");
    printf("add(3, 5) = %d\n", add(3, 5));
    printf("add(100, -30) = %d\n", add(100, -30));

    // --- Recursive function ---
    printf("\n=== Recursion ===\n");
    for (int i = 1; i <= 8; i++) {
        printf("%d! = %d\n", i, factorial(i));
    }

    // --- Void functions (no return value) ---
    printf("\n=== Void Functions ===\n");
    print_line('=', 30);
    printf("  Section Title\n");
    print_line('=', 30);

    // --- Pass by pointer (modifying values in the caller) ---
    printf("\n=== Pass by Pointer ===\n");
    int x = 10, y = 20;
    printf("Before swap: x=%d, y=%d\n", x, y);
    swap(&x, &y);  // pass addresses with &
    printf("After swap:  x=%d, y=%d\n", x, y);

    return 0;
}

// --- Function definitions ---

// Returns the sum of two integers
int add(int a, int b)
{
    return a + b;
}

// Returns n! using recursion (a function that calls itself)
int factorial(int n)
{
    if (n <= 1) return 1;       // base case: stop recursion
    return n * factorial(n - 1); // recursive case
}

// Prints a line of characters (returns nothing)
void print_line(char ch, int length)
{
    for (int i = 0; i < length; i++) {
        putchar(ch);
    }
    putchar('\n');
}

// Swaps two integers using pointers
void swap(int *a, int *b)
{
    int temp = *a;  // dereference: get the value at address a
    *a = *b;
    *b = temp;
}
