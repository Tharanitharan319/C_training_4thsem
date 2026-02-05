// QUEUE USING LINKED LIST

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node *front = NULL, *rear = NULL;
    int choice, value;

    while (1)
    {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:
        { // Enqueue
            struct Node *newNode = malloc(sizeof(struct Node));
            printf("Enter value: ");
            scanf("%d", &value);
            newNode->data = value;
            newNode->next = NULL;

            if (rear == NULL)
            {
                front = rear = newNode;
            }
            else
            {
                rear->next = newNode;
                rear = newNode;
            }
            break;
        }

        case 2: // Dequeue
            if (front == NULL)
            {
                printf("Queue Underflow\n");
            }
            else
            {
                struct Node *temp = front;
                printf("Removed: %d\n", temp->data);
                front = front->next;
                if (front == NULL)
                    rear = NULL;
                free(temp);
            }
            break;

        case 3:
        { // Display
            struct Node *temp = front;
            if (!temp)
            {
                printf("Queue Empty\n");
            }
            else
            {
                while (temp)
                {
                    printf("%d ", temp->data);
                    temp = temp->next;
                }
                printf("\n");
            }
            break;
        }

        case 4:
            return 0;
        }
    }
}