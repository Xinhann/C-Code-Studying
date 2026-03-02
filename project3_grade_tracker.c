/*
 * PROJECT 3 - Student Grade Tracker
 *
 * Add students, record grades, and view statistics.
 * Concepts used: structs, arrays, functions, dynamic memory, strings.
 *
 * Compile: gcc project3_grade_tracker.c -o grade_tracker
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STUDENTS 20
#define MAX_GRADES   10
#define NAME_LEN     50

typedef struct {
    char name[NAME_LEN];
    double grades[MAX_GRADES];
    int grade_count;
} Student;

// Function prototypes
void add_student(Student students[], int *count);
void add_grade(Student students[], int count);
void view_all(Student students[], int count);
void view_stats(Student students[], int count);
double average(double grades[], int count);
char letter_grade(double avg);

int main(void)
{
    Student students[MAX_STUDENTS];
    int student_count = 0;
    int choice;

    printf("================================\n");
    printf("   Student Grade Tracker\n");
    printf("================================\n");

    do {
        printf("\n--- Menu ---\n");
        printf("1. Add student\n");
        printf("2. Add grade\n");
        printf("3. View all students\n");
        printf("4. View statistics\n");
        printf("0. Exit\n");
        printf("Choice: ");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');  // clear newline

        switch (choice) {
            case 1: add_student(students, &student_count); break;
            case 2: add_grade(students, student_count);     break;
            case 3: view_all(students, student_count);      break;
            case 4: view_stats(students, student_count);    break;
            case 0: printf("Goodbye!\n");                   break;
            default: printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}

void add_student(Student students[], int *count)
{
    if (*count >= MAX_STUDENTS) {
        printf("Maximum students reached!\n");
        return;
    }

    printf("Enter student name: ");
    fgets(students[*count].name, NAME_LEN, stdin);
    students[*count].name[strcspn(students[*count].name, "\n")] = '\0';
    students[*count].grade_count = 0;

    printf("Added: %s (ID: %d)\n", students[*count].name, *count);
    (*count)++;
}

void add_grade(Student students[], int count)
{
    if (count == 0) {
        printf("No students yet! Add a student first.\n");
        return;
    }

    printf("Enter student ID (0-%d): ", count - 1);
    int id;
    scanf("%d", &id);

    if (id < 0 || id >= count) {
        printf("Invalid ID.\n");
        return;
    }

    Student *s = &students[id];

    if (s->grade_count >= MAX_GRADES) {
        printf("Maximum grades reached for %s!\n", s->name);
        return;
    }

    printf("Enter grade for %s (0-100): ", s->name);
    double grade;
    scanf("%lf", &grade);

    if (grade < 0 || grade > 100) {
        printf("Grade must be between 0 and 100.\n");
        return;
    }

    s->grades[s->grade_count++] = grade;
    printf("Added grade %.1f for %s.\n", grade, s->name);
}

void view_all(Student students[], int count)
{
    if (count == 0) {
        printf("No students yet.\n");
        return;
    }

    printf("\n%-4s %-20s %-8s %-6s  Grades\n", "ID", "Name", "Average", "Grade");
    printf("-----------------------------------------------------------\n");

    for (int i = 0; i < count; i++) {
        Student *s = &students[i];
        double avg = average(s->grades, s->grade_count);

        printf("%-4d %-20s", i, s->name);

        if (s->grade_count > 0) {
            printf(" %-8.1f %-6c ", avg, letter_grade(avg));
            for (int j = 0; j < s->grade_count; j++) {
                printf("%.0f ", s->grades[j]);
            }
        } else {
            printf(" %-8s %-6s", "N/A", "N/A");
        }
        printf("\n");
    }
}

void view_stats(Student students[], int count)
{
    if (count == 0) {
        printf("No students yet.\n");
        return;
    }

    double highest_avg = -1;
    double lowest_avg = 101;
    double class_total = 0;
    int students_with_grades = 0;
    const char *top_student = "";
    const char *bottom_student = "";

    for (int i = 0; i < count; i++) {
        if (students[i].grade_count == 0) continue;

        double avg = average(students[i].grades, students[i].grade_count);
        class_total += avg;
        students_with_grades++;

        if (avg > highest_avg) {
            highest_avg = avg;
            top_student = students[i].name;
        }
        if (avg < lowest_avg) {
            lowest_avg = avg;
            bottom_student = students[i].name;
        }
    }

    if (students_with_grades == 0) {
        printf("No grades recorded yet.\n");
        return;
    }

    printf("\n=== Class Statistics ===\n");
    printf("Students with grades: %d\n", students_with_grades);
    printf("Class average:        %.1f (%c)\n",
           class_total / students_with_grades,
           letter_grade(class_total / students_with_grades));
    printf("Highest average:      %.1f - %s\n", highest_avg, top_student);
    printf("Lowest average:       %.1f - %s\n", lowest_avg, bottom_student);
}

double average(double grades[], int count)
{
    if (count == 0) return 0;
    double sum = 0;
    for (int i = 0; i < count; i++) {
        sum += grades[i];
    }
    return sum / count;
}

char letter_grade(double avg)
{
    if (avg >= 90) return 'A';
    if (avg >= 80) return 'B';
    if (avg >= 70) return 'C';
    if (avg >= 60) return 'D';
    return 'F';
}
