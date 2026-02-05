// CIRCULAR QUEUE (VERY IMPORTANT)

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

        case 1:
            if ((rear + 1) % SIZE == front)
            {
                printf("Queue Full\n");
            }
            else
            {
                printf("Enter value: ");
                scanf("%d", &value);
                if (front == -1)
                    front = 0;
                rear = (rear + 1) % SIZE;
                queue[rear] = value;
            }
            break;

        case 2:
            if (front == -1)
            {
                printf("Queue Empty\n");
            }
            else
            {
                printf("Removed: %d\n", queue[front]);
                if (front == rear)
                    front = rear = -1;
                else
                    front = (front + 1) % SIZE;
            }
            break;

        case 3:
            if (front == -1)
            {
                printf("Queue Empty\n");
            }
            else
            {
                int i = front;
                while (1)
                {
                    printf("%d ", queue[i]);
                    if (i == rear)
                        break;
                    i = (i + 1) % SIZE;
                }
                printf("\n");
            }
            break;

        case 4:
            return 0;
        }
    }
}