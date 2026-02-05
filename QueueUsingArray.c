// Queue using Array

#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1: // Enqueue
            if (rear == SIZE - 1)
            {
                printf("Queue Overflow\n");
            }
            else
            {
                printf("Enter value: ");
                scanf("%d", &value);
                if (front == -1)
                    front = 0;
                queue[++rear] = value;
            }
            break;

        case 2: // Dequeue
            if (front == -1 || front > rear)
            {
                printf("Queue Underflow\n");
            }
            else
            {
                printf("Removed: %d\n", queue[front++]);
            }
            break;

        case 3: // Display
            if (front == -1 || front > rear)
            {
                printf("Queue Empty\n");
            }
            else
            {
                for (int i = front; i <= rear; i++)
                    printf("%d ", queue[i]);
                printf("\n");
            }
            break;

        case 4:
            return 0;
        }
    }
}