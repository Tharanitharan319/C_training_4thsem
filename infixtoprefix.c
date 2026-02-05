// (A + B) * (C - D / E) ^ F (INFIX → PREFIX)

// Postfix = AB+CDE/-F^*
// Prefix = ^*+AB-C/DEF

// Rules
// 1. Operand        → Output immediately
// 2. (              → Push to stack
// 3. )              → Pop from stack to output
//                     until ( is found, then remove (
// 4. Operator       →
//     a) If stack is empty → Push operator
//     b) If incoming operator has
//        HIGHER precedence than stack top
//        → Push operator
//     c) If incoming operator has
//        LOWER OR EQUAL precedence than stack top
//        → Pop stack top to output
//          (repeat until lower precedence)
//        → Then push incoming operator
// 5. End of expression →
//    Pop all remaining operators from stack to output

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char infix[] = "(A+B)*(C-D/E)^F";
    char rev[100], postfix[100], prefix[100];
    char stack[100];

    int i, j, k = 0, top = -1;
    int len = strlen(infix);

    printf("Infix  : %s\n", infix);

    // Step 1: Reverse infix and swap brackets
    for (i = len - 1, j = 0; i >= 0; i--, j++)
    {
        if (infix[i] == '(')
            rev[j] = ')';
        else if (infix[i] == ')')
            rev[j] = '(';
        else
            rev[j] = infix[i];
    }
    rev[j] = '\0';

    // Step 2: Convert reversed infix to postfix
    i = 0;
    while (rev[i] != '\0')
    {
        char ch = rev[i];

        if (isalnum(ch))
        {
            postfix[k++] = ch;
        }
        else if (ch == '(')
        {
            stack[++top] = ch;
        }
        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[k++] = stack[top--];
            }
            top--;
        }
        else
        {
            while (top != -1 &&
                       ((ch == '+' || ch == '-') &&
                        (stack[top] == '+' || stack[top] == '-' ||
                         stack[top] == '*' || stack[top] == '/' || stack[top] == '^')) ||
                   ((ch == '*' || ch == '/') &&
                    (stack[top] == '*' || stack[top] == '/' || stack[top] == '^')) ||
                   (ch == '^' && stack[top] == '^'))
            {
                postfix[k++] = stack[top--];
            }
            stack[++top] = ch;
        }
        i++;
    }

    while (top != -1)
    {
        postfix[k++] = stack[top--];
    }
    postfix[k] = '\0';

    // Step 3: Reverse postfix → prefix
    for (i = 0, j = k - 1; j >= 0; i++, j--)
    {
        prefix[i] = postfix[j];
    }
    prefix[i] = '\0';

    printf("Prefix : %s\n", prefix);
    return 0;
}