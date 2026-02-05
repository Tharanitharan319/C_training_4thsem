// (a+b)        → VALID
// ((a+b)       → INVALID
// (a+b]*c)     → INVALID
// {[()]}       → VALID

#include <stdio.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char c)
{
    stack[++top] = c;
}

char pop()
{
    return stack[top--];
}

int isMatching(char open, char close)
{
    if (open == '(' && close == ')')
        return 1;
    if (open == '{' && close == '}')
        return 1;
    if (open == '[' && close == ']')
        return 1;
    return 0;
}

int isBalanced(char exp[])
{
    for (int i = 0; exp[i] != '\0'; i++)
    {

        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i]);

        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (top == -1)
                return 0;

            char open = pop();
            if (!isMatching(open, exp[i]))
                return 0;
        }
    }

    return top == -1;
}

int main()
{
    char exp[] = ")[[(a + b)}]}";

    if (isBalanced(exp))
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}