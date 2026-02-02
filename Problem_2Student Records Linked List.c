#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for student details
struct StudentDetails {
    char name[50];
    char dept[50];
};

// Structure for student record
struct StudentRecord {
    int roll;
    struct StudentDetails details;
    struct StudentRecord* next;
};

// Function to create a new student node
struct StudentRecord* createStudent(int roll, char name[], char dept[]) {
    struct StudentRecord* newStudent = (struct StudentRecord*)malloc(sizeof(struct StudentRecord));
    newStudent->roll = roll;
    strcpy(newStudent->details.name, name);
    strcpy(newStudent->details.dept, dept);
    newStudent->next = NULL;
    return newStudent;
}

// Function to display all students
void displayStudents(struct StudentRecord* head) {
    struct StudentRecord* current = head;
    while (current != NULL) {
        printf("%d %s %s", current->roll, current->details.name, current->details.dept);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf(" -> NULL\n");
}

int main() {
    // Create student nodes manually
    struct StudentRecord* student1 = createStudent(1, "Arun", "CSE");
    struct StudentRecord* student2 = createStudent(2, "Meena", "IT");
    
    // Link the nodes
    student1->next = student2;
    
    // Display the student list
    printf("Student Records:\n");
    displayStudents(student1);
    
    // Free memory
    free(student1);
    free(student2);
    
    return 0;
}