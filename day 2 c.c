#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n, i;
    int *age = NULL;
    long sum = 0;
    double average;

    printf("Enter number of persons: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Invalid number of persons.\n");
        return 1;
    }

    age = malloc((size_t)n * sizeof(int));
    if (!age) {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    printf("Enter ages (separated by spaces or newlines):\n");
    for (i = 0; i < n; i++) {
        if (scanf("%d", &age[i]) != 1) {
            fprintf(stderr, "Invalid age input.\n");
            free(age);
            return 1;
        }
        if (age[i] < 0) {
            fprintf(stderr, "Age cannot be negative.\n");
            free(age);
            return 1;
        }
        sum += age[i];
    }

    average = (double)sum / n;
    printf("Average age = %.2f\n", average);

    free(age);
    return 0;
}