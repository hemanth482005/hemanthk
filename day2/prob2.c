#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store student details
struct Student {
    char name[50];
    int marks;
};

int main() {
    int n;
    printf("Enter number of students: ");
    scanf("%d", &n);

    // Dynamically allocate memory for n students
    struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));

    // Input student details
    for (int i = 0; i < n; i++) {
        printf("Enter Student %d Name: ", i + 1);
        scanf("%s", students[i].name);
        printf("Enter Marks: ");
        scanf("%d", &students[i].marks);
    }

    // Print student details
    printf("Student Records:\n");
    for (int i = 0; i < n; i++) {
        printf("%s - %d\n", students[i].name, students[i].marks);
    }

    // Free the allocated memory
    free(students);

    return 0;
}
