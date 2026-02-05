#include <stdio.h>
#define SIZE 5

int stack[SIZE];
int top = -1;

/* Push operation */
void push(int value) {
    if (top == SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = value;
    printf("%d pushed into stack\n", value);
}

/* Pop operation */
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return;
    }
    printf("%d popped from stack\n", stack[top]);
    top--;
}

/* Peek operation */
void peek() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }
    printf("Top element is %d\n", stack[top]);
}



/* Display stack */
void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}

int main() {
    push(10);
    push(20);
    push(30);

    peek();
    display();

    pop();
    pop();

    display();

    return 0;
}