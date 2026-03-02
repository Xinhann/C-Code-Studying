/*
 * 01 - Variables and Data Types
 *
 * Core C data types and how to use them.
 * Compile: gcc 01_variables_and_types.c -o 01_variables_and_types
 */

#include <stdio.h>   // printf, scanf
#include <limits.h>   // INT_MAX, INT_MIN, etc.
#include <float.h>    // FLT_MAX, DBL_MAX, etc.

int main(void)
{
    // --- Integer types ---
    char letter = 'A';           // 1 byte, also stores small numbers (0-127)
    short small_num = 32000;     // 2 bytes
    int number = 42;             // 4 bytes (most common)
    long big_num = 1000000L;     // 4 or 8 bytes
    long long huge_num = 9999999999LL; // 8 bytes

    printf("=== Integer Types ===\n");
    printf("char:      %c  (as number: %d)\n", letter, letter);
    printf("short:     %hd\n", small_num);
    printf("int:       %d\n", number);
    printf("long:      %ld\n", big_num);
    printf("long long: %lld\n", huge_num);

    // --- Unsigned (no negative numbers, double the positive range) ---
    unsigned int positive_only = 4000000000U;
    printf("\nunsigned int: %u\n", positive_only);

    // --- Floating point types ---
    float pi_approx = 3.14f;        // 4 bytes, ~7 decimal digits precision
    double pi = 3.14159265358979;   // 8 bytes, ~15 decimal digits precision

    printf("\n=== Floating Point Types ===\n");
    printf("float:  %.2f\n", pi_approx);
    printf("double: %.14f\n", pi);

    // --- Size of each type (in bytes) ---
    printf("\n=== Sizes (bytes) ===\n");
    printf("char:      %zu\n", sizeof(char));
    printf("short:     %zu\n", sizeof(short));
    printf("int:       %zu\n", sizeof(int));
    printf("long:      %zu\n", sizeof(long));
    printf("long long: %zu\n", sizeof(long long));
    printf("float:     %zu\n", sizeof(float));
    printf("double:    %zu\n", sizeof(double));

    // --- Type limits ---
    printf("\n=== Type Limits ===\n");
    printf("int range:    %d to %d\n", INT_MIN, INT_MAX);
    printf("double max:   %g\n", DBL_MAX);

    // --- Type casting (converting between types) ---
    int a = 7, b = 2;
    printf("\n=== Type Casting ===\n");
    printf("7 / 2 (int division):    %d\n", a / b);           // Result: 3
    printf("7 / 2 (float division):  %.1f\n", (double)a / b); // Result: 3.5

    return 0;
}
