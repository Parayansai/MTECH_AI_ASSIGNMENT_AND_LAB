#include <stdio.h>

int main() {
    double num1, num2;
    char op;

    // Input numbers
    printf("Enter first number: ");
    scanf("%lf", &num1);

    printf("Enter second number: ");
    scanf("%lf", &num2);

    // Input operator
    printf("Choose an operation (+, -, *, /): ");
    scanf(" %c", &op);   

    switch(op) {
        case '+':
            printf("Result = %.2lf\n", num1 + num2);
            break;

        case '-':
            printf("Result = %.2lf\n", num1 - num2);
            break;

        case '*':
            printf("Result = %.2lf\n", num1 * num2);
            break;

        case '/':
            if (num2 != 0)
                printf("Result = %.2lf\n", num1 / num2);
            else
                printf("Error: Division by zero!\n");
            break;

        default:
            printf("Invalid operator!\n");
    }

    return 0;
}
