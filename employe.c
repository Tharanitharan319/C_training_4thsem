#include <stdio.h>
#include <string.h>
struct Department {
    char name[50];
    int id;
};
struct Employee {
    int id;
    char name[50];
    struct Department department;
};

int main() {
    struct Employee emp1;
    emp1.id = 101;
    strcpy(emp1.name, "DEEPAK");
    strcpy(emp1.department.name, "Engineering");
    emp1.department.id = 106;
    struct Employee *empPtr;
    empPtr = &emp1;
    printf("Employee Details :\n");
    printf("--------------------------------------------\n");
    printf("Employee ID:     %d\n", empPtr->id);
    printf("Employee Name:   %s\n", empPtr->name);
    printf("Department Name: %s\n", empPtr->department.name);
    printf("Department ID:   %d\n", empPtr->department.id);

    return 0;
}