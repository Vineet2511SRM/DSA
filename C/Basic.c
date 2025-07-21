#include <stdio.h>

int main() {
    // Declare variables
    int num1, num2;
    float f1, f2;
    double d1, d2;
    char ch;

    // Taking integer input
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    // Taking float input
    printf("Enter two float numbers: ");
    scanf("%f %f", &f1, &f2);

    // Taking double input
    printf("Enter two double numbers: ");
    scanf("%lf %lf", &d1, &d2);

    // Taking character input
    printf("Enter a character: ");
    scanf(" %c", &ch); // Space before %c to consume leftover newline

    // Perform operations
    int sum = num1 + num2;
    float diff = f1 - f2;
    double product = d1 * d2;

    // Displaying results
    printf("\n--- Output ---\n");
    printf("Sum of integers: %d\n", sum);
    printf("Difference of floats: %.2f\n", diff);
    printf("Product of doubles: %.4lf\n", product);
    printf("Character entered: %c\n", ch);

    return 0;
}


// Sample Input/Output
// Input:
// Enter two integers: 5 10
// Enter two float numbers: 3.5 1.2
// Enter two double numbers: 2.718 3.14159
// Enter a character: A
// Output:
//Sum of integers: 15
// Difference of floats: 2.30
// Product of doubles: 8.5397
// Character entered: A