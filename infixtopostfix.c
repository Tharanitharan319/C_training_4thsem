// (A + B) * (C - D / E) ^ F (INFIX → POSTFIX)

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

int main() {
    char infix[] = "(A+B)*(C-D/E)^F";
    char postfix[100];
    char stack[100];

    int i = 0, k = 0, top = -1;

    printf("Infix   : %s\n", infix);

    while (infix[i] != '\0') {
        char ch = infix[i];

        // Operand → output
        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        // Opening bracket
        else if (ch == '(') {
            stack[++top] = ch;
        }
        // Closing bracket
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = stack[top--];
            }
            top--; // remove '('
        }
        // Operator
        else {
            // Check lower or equal POP
            while (top != -1 &&
                   ((ch == '+' || ch == '-') &&
                    (stack[top] == '+' || stack[top] == '-' ||
                     stack[top] == '*' || stack[top] == '/' || stack[top] == '^')) ||
                   ((ch == '*' || ch == '/') &&
                    (stack[top] == '*' || stack[top] == '/' || stack[top] == '^')) ||
                   (ch == '^' && stack[top] == '^')) {
                postfix[k++] = stack[top--];
            }
            // Push new operator to stack
            stack[++top] = ch;
        }
        i++;
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[k++] = stack[top--];
    }

    postfix[k] = '\0';

    printf("Postfix : %s\n", postfix);
    return 0;
}


