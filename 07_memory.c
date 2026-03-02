/*
 * 07 - Dynamic Memory (malloc / free)
 *
 * Stack vs Heap:
 *   - Stack: automatic, limited size, freed when function returns
 *   - Heap:  manual, large, you control when it's freed
 *
 * Compile: gcc 07_memory.c -o 07_memory
 */

#include <stdio.h>
#include <stdlib.h>  // malloc, calloc, realloc, free
#include <string.h>

int main(void)
{
    // --- malloc: allocate memory ---
    printf("=== malloc ===\n");
    int *arr = malloc(5 * sizeof(int));  // allocate space for 5 ints

    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Fill and print
    for (int i = 0; i < 5; i++) {
        arr[i] = (i + 1) * 10;
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    // --- realloc: resize memory ---
    printf("\n=== realloc ===\n");
    arr = realloc(arr, 10 * sizeof(int));  // grow to 10 ints

    if (arr == NULL) {
        printf("Realloc failed!\n");
        return 1;
    }

    // Fill the new slots
    for (int i = 5; i < 10; i++) {
        arr[i] = (i + 1) * 10;
    }

    for (int i = 0; i < 10; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    free(arr);  // ALWAYS free what you malloc!
    arr = NULL; // good practice: avoid dangling pointer

    // --- calloc: allocate + zero-initialize ---
    printf("\n=== calloc ===\n");
    int *zeros = calloc(5, sizeof(int));  // all initialized to 0

    if (zeros == NULL) {
        printf("Calloc failed!\n");
        return 1;
    }

    printf("calloc values (should all be 0): ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", zeros[i]);
    }
    printf("\n");

    free(zeros);

    // --- Dynamic string ---
    printf("\n=== Dynamic String ===\n");
    const char *source = "Hello, dynamic world!";
    char *str = malloc(strlen(source) + 1);  // +1 for '\0'

    if (str == NULL) {
        printf("Malloc failed!\n");
        return 1;
    }

    strcpy(str, source);
    printf("Dynamic string: %s\n", str);

    free(str);

    /*
     * MEMORY RULES:
     * 1. Every malloc/calloc MUST have a matching free
     * 2. Never use memory after freeing it (use-after-free bug)
     * 3. Never free the same memory twice (double-free bug)
     * 4. Always check if malloc returns NULL
     * 5. Set pointers to NULL after freeing
     */

    return 0;
}
