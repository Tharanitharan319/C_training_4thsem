// NEXT GREATER ELEMENT (NGE)

//  Problem Statement

// Given an array, for each element find the next greater element on the right.
// If none, print -1.

// Example
// Input :  4 5 2 25
// Output:  5 25 25 -1

// Solution in C:
#include <stdio.h>

int main()
{
    int arr[] = {4, 5, 2, 25};
    int n = 4;
    int stack[50], top = -1;
    int result[50];

    for (int i = n - 1; i >= 0; i--)
    {
        while (top != -1 && stack[top] <= arr[i])
            top--;

        result[i] = (top == -1) ? -1 : stack[top];
        stack[++top] = arr[i];
    }

    for (int i = 0; i < n; i++)
        printf("%d ", result[i]);

    return 0;
}