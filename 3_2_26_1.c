#include <stdio.h>
#include <stdbool.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

bool isEmpty() {
    return front == -1;
}

bool isFull() {
    return (rear + 1) % MAX == front;
}

void enqueue(int customerID) {
    if (isFull()) {
        printf("Queue Full! Cannot add ID: %d\n", customerID);
        return;
    }
    if (isEmpty()) front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = customerID;
    printf("Customer %d added to line.\n", customerID);
}

int dequeue() {
    if (isEmpty()) return -1;
    int data = queue[front];
    if (front == rear) { // Only one element was present
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
    return data;
}

void displayFront() {
    if (!isEmpty()) printf("Currently serving: %d\n", queue[front]);
}

int main() {
    enqueue(101);
    enqueue(102);
    enqueue(103);
    displayFront();
    printf("Served: %d\n", dequeue());
    displayFront();
    return 0;
}