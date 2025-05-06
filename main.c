#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

// Linked list for subjects and marks
typedef struct Subject {
    char name[30];
    int marks;
    struct Subject *next;
} Subject;

// Student structure
typedef struct {
    int id;
    char name[NAME_LENGTH];
    Subject *subjects; // linked list head
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

// Function to add a student
void addStudent(int id, const char *name) {
    if (studentCount >= MAX_STUDENTS) {
        printf("Max student limit reached.\n");
        return;
    }
    students[studentCount].id = id;
    strcpy(students[studentCount].name, name);
    students[studentCount].subjects = NULL;
    studentCount++;
}

// Function to add/update subject marks for a student
void updateSubjectMarks(int studentId, const char *subjectName, int marks) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == studentId) {
            Subject *current = students[i].subjects;
            // Search for the subject
            while (current != NULL) {
                if (strcmp(current->name, subjectName) == 0) {
                    current->marks = marks; // update marks
                    return;
                }
                current = current->next;
            }
            // Add new subject
            Subject *newSubject = (Subject *)malloc(sizeof(Subject));
            strcpy(newSubject->name, subjectName);
            newSubject->marks = marks;
            newSubject->next = students[i].subjects;
            students[i].subjects = newSubject;
            return;
        }
    }
    printf("Student with ID %d not found.\n", studentId);
}

// Display all student records
void displayStudents() {
    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d, Name: %s\n", students[i].id, students[i].name);
        Subject *current = students[i].subjects;
        while (current != NULL) {
            printf("  Subject: %s, Marks: %d\n", current->name, current->marks);
            current = current->next;
        }
    }
}

int main() {
    int n;
    int id,marks;
    char name[NAME_LENGTH],subject[NAME_LENGTH];
    bool choice = true;
    while(choice){
        printf("enter your choice\n");
        printf("1. Add Student\n");
        printf("2. Update Subject Marks\n");
        printf("3. Dispaly Students\n");
        printf("4. Exit\n");
        scanf("%d",&n);
        
        switch(n){
            case 1: 
            printf("enter the Student ID and Name\n");
            scanf("%d",&id);
            scanf(" %[^\n]", name);
            addStudent(id,name);
            break;
            case 2:
            printf("enter the student ID, subject and marks\n");
            scanf("%d",&id);
            scanf(" %[^\n]", subject);
            scanf("%d",&marks);
            updateSubjectMarks(id,subject,marks);
            break;
            case 3:
            displayStudents();
            break;
            case 4:
            printf("Code Exit from the loop\n");
            choice = false;
            break;
            default:
            printf("Invalid choice. Try again.\n");
        }
        
    }
    
    /*addStudent(1, "Alice");
    addStudent(2, "Bob");

    updateSubjectMarks(1, "Math", 90);
    updateSubjectMarks(1, "Science", 85);
    updateSubjectMarks(2, "DS", 75);
    updateSubjectMarks(1, "physics", 95); // update marks

    displayStudents();*/

    return 0;
}
