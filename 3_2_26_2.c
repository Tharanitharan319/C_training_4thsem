#include <stdio.h>
#include <stdlib.h>

struct Node {
    int patientID;
    struct Node* next;
};

struct Queue {
    struct Node *front, *rear;
    int count;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    q->count = 0;
    return q;
}

void enqueue(struct Queue* q, int id) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->patientID = id;
    temp->next = NULL;
    
    if (q->rear == NULL) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
    q->count++;
    printf("Patient %d registered.\n", id);
}

int dequeue(struct Queue* q) {
    if (q->front == NULL) return -1;
    
    struct Node* temp = q->front;
    int id = temp->patientID;
    q->front = q->front->next;
    
    if (q->front == NULL) q->rear = NULL;
    
    free(temp);
    q->count--;
    return id;
}

int main() {
    struct Queue* hospitalQueue = createQueue();
    enqueue(hospitalQueue, 5001);
    enqueue(hospitalQueue, 5002);
    
    printf("Attending Patient: %d\n", dequeue(hospitalQueue));
    printf("Patients remaining: %d\n", hospitalQueue->count);
    
    return 0;
}