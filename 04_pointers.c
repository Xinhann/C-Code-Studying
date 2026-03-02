/*
 * 04 - Pointers
 *
 * The most important (and trickiest) concept in C.
 * A pointer is a variable that stores a memory address.
 *
 * Compile: gcc 04_pointers.c -o 04_pointers
 */

#include <stdio.h>
#include <stdlib.h>

// --- Functions that demonstrate pointer-to-pointer usage ---

// This function can change WHERE a pointer points to (not just the value)
void allocate_and_set(int **ptr, int val)
{
    *ptr = malloc(sizeof(int));  // modifies the caller's pointer
    if (*ptr != NULL) {
        **ptr = val;             // sets the value at the new address
    }
}

// Without double pointer: can only change the VALUE, not the pointer itself
void try_allocate_broken(int *ptr)
{
    // This only changes the LOCAL copy of the pointer — caller won't see it!
    ptr = malloc(sizeof(int));
    if (ptr != NULL) {
        *ptr = 999;
    }
    // Memory leak: we can't free this, and caller still has NULL
}

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

    // --- Pointer to pointer: the basics ---
    printf("\n=== Pointer to Pointer (Basics) ===\n");
    int value = 7;
    int *p1 = &value;
    int **p2 = &p1;  // pointer to a pointer

    /*
     * Memory layout:
     *
     *   p2          p1          value
     *   [addr3]     [addr2]     [addr1]
     *   ┌───────┐   ┌───────┐   ┌───┐
     *   │ addr2 │──>│ addr1 │──>│ 7 │
     *   └───────┘   └───────┘   └───┘
     *
     *   p2   = addr2  (address of p1)
     *   *p2  = addr1  (what p1 holds = address of value)
     *   **p2 = 7      (follow the chain twice to get value)
     */

    printf("value address:  %p\n", (void *)&value);
    printf("p1 value:       %p  (= address of value)\n", (void *)p1);
    printf("p1 address:     %p\n", (void *)&p1);
    printf("p2 value:       %p  (= address of p1)\n", (void *)p2);
    printf("\n");
    printf("*p1  = %d  (dereference once: get value)\n", *p1);
    printf("*p2  = %p  (dereference once: get what p1 holds)\n", (void *)*p2);
    printf("**p2 = %d  (dereference twice: follow chain to value)\n", **p2);

    // --- Modifying through double pointer ---
    printf("\n=== Modify via Double Pointer ===\n");
    **p2 = 99;
    printf("After **p2 = 99 → value is now: %d\n", value);

    // --- Real-world use: function that allocates memory ---
    printf("\n=== Double Pointer in Functions ===\n");

    // The BROKEN way (single pointer)
    int *broken = NULL;
    try_allocate_broken(broken);
    printf("After try_allocate_broken: broken is %s\n",
           broken == NULL ? "still NULL (didn't work!)" : "allocated");

    // The CORRECT way (double pointer)
    int *working = NULL;
    allocate_and_set(&working, 42);
    if (working != NULL) {
        printf("After allocate_and_set:   *working = %d (it works!)\n", *working);
        free(working);
        working = NULL;
    }

    /*
     * WHY does the broken version fail?
     *
     *   int *broken = NULL;
     *   try_allocate_broken(broken);
     *
     *   C passes everything by VALUE. So the function gets a COPY of
     *   the pointer. Changing the copy inside the function doesn't
     *   affect the original pointer in main().
     *
     *   allocate_and_set(&working, 42);
     *
     *   By passing the ADDRESS of the pointer (int **), the function
     *   can modify the original pointer through *ptr = malloc(...).
     *
     *   This is the #1 reason double pointers exist in C.
     */

    // --- Array of strings (array of pointers) ---
    printf("\n=== Array of Pointers (char **) ===\n");
    const char *colors[] = {"red", "green", "blue", "yellow"};
    int num_colors = sizeof(colors) / sizeof(colors[0]);

    // colors is effectively a char ** (pointer to array of char pointers)
    for (int i = 0; i < num_colors; i++) {
        printf("colors[%d] = \"%s\"  (address: %p)\n",
               i, colors[i], (void *)colors[i]);
    }

    /*
     * SUMMARY — When do you need pointer-to-pointer?
     *
     * 1. Functions that allocate/reassign a pointer (most common)
     * 2. Arrays of strings (char **)
     * 3. 2D dynamic arrays
     * 4. Linked list operations (insert/delete that change head)
     */

    return 0;
}
