#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
    char patientID[10];
    struct Node* next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
    int count;
} HospitalQueue;
void init(HospitalQueue* q) {
    q->front = q->rear = NULL;
    q->count = 0;
}
int isEmpty(HospitalQueue* q) {
    return q->front == NULL;
}
void enqueue(HospitalQueue* q, char id[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return;
    }
    strcpy(newNode->patientID, id);
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->count++;
    printf("Patient registered: %s\n", id);
}
void dequeue(HospitalQueue* q) {
    if (isEmpty(q)) {
        printf("No patients in queue.\n");
        return;
    }
    Node* temp = q->front;
    printf("Patient attended → %s\n", temp->patientID);
    
    q->front = q->front->next;
    
  
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    free(temp);
    q->count--;
}

// Show the patient currently being attended
void front(HospitalQueue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
    } else {
        printf("Next patient → %s\n", q->front->patientID);
    }
}

int main() {
    HospitalQueue q;
    init(&q);

    // Sample Use Case
    enqueue(&q, "P1");
    enqueue(&q, "P2");
    enqueue(&q, "P3");

    dequeue(&q);    // P1 goes to doctor
    front(&q);      // Shows P2
    
    printf("Total patients waiting: %d\n", q.count);

    return 0;
}