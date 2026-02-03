#include <stdio.h>

void searchPrice(int arr[], int size, int target) {
    int found = 0; // A flag to track if we found it

    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            printf("Price %d found at position %d\n", target, i + 1);
            found = 1;
            break; // Stop searching once found
        }
    }

    if (!found) {
        printf("Price not found\n");
    }
}

int main() {
    int prices[] = {100, 250, 400, 150};
    int searchFor = 400;
    searchPrice(prices, 4, searchFor);
    return 0;
}