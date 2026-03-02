/*
 * 04 - Pointers
 *
 * The most important (and trickiest) concept in C.
 * A pointer is a variable that stores a memory address.
 *
 * Compile: gcc 04_pointers.c -o 04_pointers
 */

#include <stdio.h>

int main(void)
{
    // --- Basics ---
    printf("=== Pointer Basics ===\n");
    int x = 42;
    int *ptr = &x;  // ptr stores the ADDRESS of x

    printf("x value:        %d\n", x);
    printf("x address:      %p\n", (void *)&x);   // %p prints addresses
    printf("ptr value:      %p\n", (void *)ptr);   // same address as &x
    printf("ptr dereference: %d\n", *ptr);          // *ptr gets the VALUE at the address

    // --- Modifying through a pointer ---
    printf("\n=== Modify via Pointer ===\n");
    *ptr = 100;  // change the value at the address ptr points to
    printf("x is now: %d\n", x);  // x changed!

    // --- Pointer arithmetic (used with arrays) ---
    printf("\n=== Pointer Arithmetic ===\n");
    int nums[] = {10, 20, 30, 40, 50};
    int *p = nums;  // array name decays to pointer to first element

    for (int i = 0; i < 5; i++) {
        printf("nums[%d] = %d  (via pointer: %d)\n", i, nums[i], *(p + i));
    }

    // p + 1 moves forward by sizeof(int) bytes, not 1 byte!
    printf("\nAddress of nums[0]: %p\n", (void *)p);
    printf("Address of nums[1]: %p\n", (void *)(p + 1));
    printf("Difference: %zu bytes (= sizeof(int))\n",
           (size_t)((char *)(p + 1) - (char *)p));

    // --- NULL pointer ---
    printf("\n=== NULL Pointer ===\n");
    int *safe_ptr = NULL;  // points to nothing — always initialize pointers!

    if (safe_ptr != NULL) {
        printf("Value: %d\n", *safe_ptr);
    } else {
        printf("Pointer is NULL, cannot dereference.\n");
    }

    // --- Pointer to pointer ---
    printf("\n=== Pointer to Pointer ===\n");
    int value = 7;
    int *p1 = &value;
    int **p2 = &p1;  // pointer to a pointer

    printf("value:  %d\n", value);
    printf("*p1:    %d\n", *p1);
    printf("**p2:   %d\n", **p2);  // dereference twice

    return 0;
}
