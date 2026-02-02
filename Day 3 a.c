#include <stdio.h>
#include <math.h>
int main() {
    float area;
    printf("Enter the area of the square: ");
    scanf("%f", &area);
    double side_length = sqrt((double)area);
    printf("The side length is: %f\n", side_length);
    return 0;
}