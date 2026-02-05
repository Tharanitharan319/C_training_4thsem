// QUEUE USING TWO STACKS (Asked in Amazon)

// Problem Statement

// Implement a Queue (FIFO) using two Stacks (LIFO).

// Solution in C:

#include <stdio.h>

#define SIZE 50

int s1[SIZE], s2[SIZE];
int top1 = -1, top2 = -1;

// Push into stack
void push(int stack[], int *top, int x)
{
    stack[++(*top)] = x;
}

// Pop from stack
int pop(int stack[], int *top)
{
    return stack[(*top)--];
}

int main()
{
    int choice, x;

    while (1)
    {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1: // Enqueue
            printf("Enter value: ");
            scanf("%d", &x);
            push(s1, &top1, x);
            break;

        case 2: // Dequeue
            if (top1 == -1 && top2 == -1)
            {
                printf("Queue Empty\n");
            }
            else
            {
                if (top2 == -1)
                {
                    while (top1 != -1)
                        push(s2, &top2, pop(s1, &top1));
                }
                printf("Removed: %d\n", pop(s2, &top2));
            }
            break;

        case 3: // Display
            if (top2 != -1)
            {
                for (int i = top2; i >= 0; i--)
                    printf("%d ", s2[i]);
            }
            for (int i = 0; i <= top1; i++)
                printf("%d ", s1[i]);
            printf("\n");
            break;

        case 4:
            return 0;
        }
    }
}