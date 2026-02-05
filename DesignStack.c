// DESIGN STACK THAT SUPPORTS GETMIN() IN O(1) (Asked in Amazon, Microsoft)

// Problem Statement

// Design stack with:
// 	•	push
// 	•	pop
// 	•	getMin → O(1)

// Program Menu:
// 1.Push  2.Pop  3.GetMin  4.Exit

// SAMPLE INPUT (User Actions)

// 1
// 5
// 1
// 3
// 1
// 7
// 3
// 2
// 3
// 4

// FULL CONSOLE VIEW (AS USER SEES)

// 1.Push 2.Pop 3.GetMin 4.Exit
// 1
// 5

// 1.Push 2.Pop 3.GetMin 4.Exit
// 1
// 3

// 1.Push 2.Pop 3.GetMin 4.Exit
// 1
// 7

// 1.Push 2.Pop 3.GetMin 4.Exit
// 3
// Min = 3

// 1.Push 2.Pop 3.GetMin 4.Exit
// 2

// 1.Push 2.Pop 3.GetMin 4.Exit
// 3
// Min = 3

// 1.Push 2.Pop 3.GetMin 4.Exit
// 4

// Solution in C:

#include <stdio.h>

int stack[50], minStack[50];
int top = -1, minTop = -1;

int main()
{
    int choice, x;

    while (1)
    {
        printf("\n1.Push 2.Pop 3.GetMin 4.Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            scanf("%d", &x);
            stack[++top] = x;
            if (minTop == -1 || x <= minStack[minTop])
                minStack[++minTop] = x;
            break;

        case 2:
            if (stack[top] == minStack[minTop])
                minTop--;
            top--;
            break;

        case 3:
            printf("Min = %d\n", minStack[minTop]);
            break;

        case 4:
            return 0;
        }
    }
}