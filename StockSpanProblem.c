// STOCK SPAN PROBLEM (Amazon, Flipkart, Paytm)

// Problem Statement

// Given stock prices, find how many consecutive days before today price was smaller.

// Example
// Input : 100 80 60 70 60 75 85
// Output: 1 1 1 2 1 4 6

// Prices:

// Day:     0   1   2   3   4   5   6
// Price: 100  80  60  70  60  75  85

// Day 0 → Price = 100

// Go backwards:
// 	•	Day 0 → 100 ≤ 100 ✅

// Stop (no more days)

// Span = 1

// Day 1 → Price = 80

// Go backwards:
// 	•	Day 1 → 80 ≤ 80 ✅
// 	•	Day 0 → 100 ≤ 80 ❌ (STOP)

// Span = 1

// Day 2 → Price = 60

// Go backwards:
// 	•	Day 2 → 60 ≤ 60 ✅
// 	•	Day 1 → 80 ≤ 60 ❌ (STOP)

// Span = 1

// Day 3 → Price = 70

// Go backwards:
// 	•	Day 3 → 70 ≤ 70 ✅
// 	•	Day 2 → 60 ≤ 70 ✅
// 	•	Day 1 → 80 ≤ 70 ❌ (STOP)

// Span = 2

// Day 4 → Price = 60

// Go backwards:
// 	•	Day 4 → 60 ≤ 60 ✅
// 	•	Day 3 → 70 ≤ 60 ❌ (STOP)

// Span = 1

// Day 5 → Price = 75

// Go backwards:
// 	•	Day 5 → 75 ≤ 75 ✅
// 	•	Day 4 → 60 ≤ 75 ✅
// 	•	Day 3 → 70 ≤ 75 ✅
// 	•	Day 2 → 60 ≤ 75 ✅
// 	•	Day 1 → 80 ≤ 75 ❌ (STOP)

// Span = 4

// Day 6 → Price = 85

// Go backwards:
// 	•	Day 6 → 85 ≤ 85 ✅
// 	•	Day 5 → 75 ≤ 85 ✅
// 	•	Day 4 → 60 ≤ 85 ✅
// 	•	Day 3 → 70 ≤ 85 ✅
// 	•	Day 2 → 60 ≤ 85 ✅
// 	•	Day 1 → 80 ≤ 85 ✅
// 	•	Day 0 → 100 ≤ 85 ❌ (STOP)

// Solution in C:

#include <stdio.h>

int main()
{
    int price[] = {100, 80, 60, 70, 60, 75, 85};
    int n = 7, span[50];
    int stack[50], top = -1;

    for (int i = 0; i < n; i++)
    {
        while (top != -1 && price[stack[top]] <= price[i])
            top--;

        span[i] = (top == -1) ? i + 1 : i - stack[top];
        stack[++top] = i;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", span[i]);

    return 0;
}