/*
 * 05 - Strings
 *
 * C doesn't have a string type — strings are just arrays of chars
 * ending with a null terminator '\0'.
 *
 * Compile: gcc 05_strings.c -o 05_strings
 */

#include <stdio.h>
#include <string.h>  // strlen, strcpy, strcmp, strcat, etc.
#include <ctype.h>   // toupper, tolower, isalpha, isdigit, etc.

int main(void)
{
    // --- String basics ---
    printf("=== String Basics ===\n");
    char greeting[] = "Hello";  // compiler adds '\0' automatically
    char name[50] = "World";    // 50-char buffer, mostly empty

    printf("greeting: %s (length: %zu)\n", greeting, strlen(greeting));
    printf("name:     %s (length: %zu)\n", name, strlen(name));

    // What a string looks like in memory:
    printf("\nMemory view of \"Hello\":\n");
    for (int i = 0; i <= 5; i++) {  // include the '\0'
        printf("  [%d] = '%c' (%d)\n", i, greeting[i] ? greeting[i] : '0', greeting[i]);
    }

    // --- String functions from <string.h> ---
    printf("\n=== String Functions ===\n");

    // strcpy: copy a string
    char dest[50];
    strcpy(dest, "Copied!");
    printf("strcpy:  %s\n", dest);

    // strcat: concatenate (append) strings
    char sentence[100] = "Hello";
    strcat(sentence, ", ");
    strcat(sentence, "World!");
    printf("strcat:  %s\n", sentence);

    // strcmp: compare strings (0 = equal)
    printf("strcmp(\"abc\", \"abc\") = %d\n", strcmp("abc", "abc"));
    printf("strcmp(\"abc\", \"xyz\") = %d\n", strcmp("abc", "xyz"));

    // strstr: find substring
    const char *hay = "Hello World";
    const char *found = strstr(hay, "World");
    if (found) {
        printf("strstr:  found \"%s\" at position %td\n", found, found - hay);
    }

    // --- Character functions from <ctype.h> ---
    printf("\n=== Character Functions ===\n");
    char text[] = "Hello 123!";
    printf("Original: %s\n", text);

    printf("Uppercase: ");
    for (int i = 0; text[i]; i++) {
        putchar(toupper(text[i]));
    }
    printf("\n");

    printf("Checking each char:\n");
    for (int i = 0; text[i]; i++) {
        printf("  '%c': alpha=%d digit=%d space=%d\n",
               text[i], isalpha(text[i]) != 0, isdigit(text[i]) != 0, isspace(text[i]) != 0);
    }

    // --- Reading user input ---
    printf("\n=== User Input ===\n");
    char user_input[100];
    printf("Enter your name: ");
    // fgets is safer than scanf for strings — it won't overflow the buffer
    if (fgets(user_input, sizeof(user_input), stdin)) {
        // fgets includes the newline, so remove it
        user_input[strcspn(user_input, "\n")] = '\0';
        printf("Hello, %s! Your name has %zu characters.\n",
               user_input, strlen(user_input));
    }

    return 0;
}
