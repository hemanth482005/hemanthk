#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    int rollNo;
    char name[50];
    int marks;
} Student;

// Function to compare two students for sorting
int compare(const void *a, const void *b) {
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;
    return studentB->marks - studentA->marks; // Descending order
}

// Function to perform binary search
int binarySearch(Student students[], int size, int rollNo) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (students[mid].rollNo == rollNo) {
            return mid; // Found
        } else if (students[mid].rollNo < rollNo) {
            right = mid - 1; // Search left
        } else {
            left = mid + 1; // Search right
        }
    }
    return -1; // Not found
}

// Function to display top 3 students
void displayTopStudents(Student students[], int size) {
    printf("Top 3 Students:\n");
    for (int i = 0; i < size && i < 3; i++) {
        printf("%s (Marks: %d)\n", students[i].name, students[i].marks);
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int n;

    // Input number of students
    printf("Enter number of students: ");
    scanf("%d", &n);

    // Input student records
    for (int i = 0; i < n; i++) {
        printf("Enter Roll No, Name and Marks for student %d: ", i + 1);
        scanf("%d %s %d", &students[i].rollNo, students[i].name, &students[i].marks);
    }

    // Sort students by marks in descending order
    qsort(students, n, sizeof(Student), compare);

    // Display sorted students
    printf("\nSorted by Marks:\n");
    for (int i = 0; i < n; i++) {
        printf("%s (%d)\n", students[i].name, students[i].marks);
    }

    // Search for a student's record
    int rollNoToSearch;
    printf("\nEnter Roll No to search: ");
    scanf("%d", &rollNoToSearch);
    int index = binarySearch(students, n, rollNoToSearch);
    if (index != -1) {
        printf("Found: %s (Marks: %d)\n", students[index].name, students[index].marks);
    } else {
        printf("Student with Roll No %d not found.\n", rollNoToSearch);
    }

    // Display top 3 students
    displayTopStudents(students, n);

    return 0;
}
