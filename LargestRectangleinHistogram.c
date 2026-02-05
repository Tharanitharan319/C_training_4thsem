// LARGEST RECTANGLE IN HISTOGRAM (EXTREMELY IMPORTANT – Product companies)

// Problem Statement

// Given bar heights, find largest rectangular area.

// Example
// Input : 6 2 5 4 5 1 6
// Output: 12

// Solution in C:

#include <stdio.h>

int main()
{
    int hist[] = {6, 2, 5, 4, 5, 1, 6};
    int n = 7;
    int stack[50], top = -1;
    int maxArea = 0, i = 0;

    while (i < n)
    {
        if (top == -1 || hist[stack[top]] <= hist[i])
            stack[++top] = i++;
        else
        {
            int h = hist[stack[top--]];
            int w = (top == -1) ? i : i - stack[top] - 1;
            int area = h * w;
            if (area > maxArea)
                maxArea = area;
        }
    }

    while (top != -1)
    {
        int h = hist[stack[top--]];
        int w = (top == -1) ? i : i - stack[top] - 1;
        int area = h * w;
        if (area > maxArea)
            maxArea = area;
    }

    printf("Max Area = %d", maxArea);
    return 0;
}