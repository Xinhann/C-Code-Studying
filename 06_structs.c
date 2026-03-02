/*
 * 06 - Structs
 *
 * Structs let you group related data together —
 * like a simple version of classes (but without methods).
 *
 * Compile: gcc 06_structs.c -o 06_structs
 */

#include <stdio.h>
#include <string.h>

// --- Define a struct ---
struct Point {
    double x;
    double y;
};

// --- Using typedef for cleaner syntax ---
typedef struct {
    char name[50];
    int age;
    float gpa;
} Student;

// --- Functions that work with structs ---
void print_student(Student s)
{
    printf("  Name: %s, Age: %d, GPA: %.2f\n", s.name, s.age, s.gpa);
}

// Pass by pointer to modify the original (and avoid copying large structs)
void birthday(Student *s)
{
    s->age++;  // arrow operator: shorthand for (*s).age++
}

double distance(struct Point a, struct Point b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return dx * dx + dy * dy;  // squared distance (no sqrt for simplicity)
}

int main(void)
{
    // --- Basic struct usage ---
    printf("=== Basic Struct ===\n");
    struct Point origin = {0.0, 0.0};
    struct Point p = {3.0, 4.0};

    printf("Origin: (%.1f, %.1f)\n", origin.x, origin.y);
    printf("Point:  (%.1f, %.1f)\n", p.x, p.y);
    printf("Squared distance: %.1f\n", distance(origin, p));

    // --- Typedef struct ---
    printf("\n=== Students ===\n");
    Student students[3] = {
        {"Alice",   20, 3.8f},
        {"Bob",     22, 3.5f},
        {"Charlie", 19, 3.9f}
    };

    for (int i = 0; i < 3; i++) {
        printf("Student %d:\n", i + 1);
        print_student(students[i]);
    }

    // --- Modify via pointer ---
    printf("\n=== After Birthday ===\n");
    birthday(&students[0]);  // Alice gets older
    printf("Alice:\n");
    print_student(students[0]);

    // --- Nested structs ---
    printf("\n=== Nested Struct ===\n");
    typedef struct {
        char street[100];
        char city[50];
        int zip;
    } Address;

    typedef struct {
        char name[50];
        Address home;
    } Person;

    Person john = {
        "John",
        {"123 Main St", "Springfield", 62704}
    };

    printf("%s lives at %s, %s %d\n",
           john.name, john.home.street, john.home.city, john.home.zip);

    return 0;
}
