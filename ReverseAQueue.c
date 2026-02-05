// REVERSE A QUEUE

#include <stdio.h>

int main()
{
    int queue[5] = {1, 2, 3, 4, 5};
    int stack[5], top = -1;
    int front = 0, rear = 4;

    while (front <= rear)
        stack[++top] = queue[front++];

    front = 0;
    while (top != -1)
        queue[front++] = stack[top--];

    for (int i = 0; i < 5; i++)
        printf("%d ", queue[i]);

    return 0;
}