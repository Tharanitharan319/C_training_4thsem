//  REVERSE A STACK USING RECURSION (No extra stack allowed)

// Problem Statement

// Reverse a stack without using another stack.
// Example:
// Input Stack (before reverse):
// 1 2 3 4   (1 at bottom, 4 at top)
// Output (after reverse):
// 1 2 3 4   (printed from top after reversal)

// Solution in C:

#include <stdio.h>

int stack[50], top = -1;

void insertBottom(int x)
{
    if (top == -1)
    {
        stack[++top] = x;
        return;
    }
    int temp = stack[top--];
    insertBottom(x);
    stack[++top] = temp;
}

void reverse()
{
    if (top == -1)
        return;
    int temp = stack[top--];
    reverse();
    insertBottom(temp);
}

int main()
{
    stack[++top] = 1;
    stack[++top] = 2;
    stack[++top] = 3;
    stack[++top] = 4;

    reverse();

    while (top != -1)
        printf("%d ", stack[top--]);

    return 0;
}