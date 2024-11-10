#include <stdio.h>

float addition(float a, float b) {
    return a + b;
}

float subtraction(float a, float b) {
    return a - b;
}

float multiplication(float a, float b) {
    return a * b;
}

float division(float a, float b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: Division by zero is not allowed.\n");
        return 0;
    }
}

int main() {
    char operator;
    float a, b, result;

    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &operator);

    printf("Enter two numbers: ");
    scanf("%f %f", &a, &b);

    if (operator == '+') {
        result = addition(a, b);
        printf("%.2f + %.2f = %.2f\n", a, b, result);
    }
    else if (operator == '-') {
        result = subtraction(a, b);
        printf("%.2f - %.2f = %.2f\n", a, b, result);
    }
    else if (operator == '*') {
        result = multiplication(a, b);
        printf("%.2f * %.2f = %.2f\n", a, b, result);y8
    }
    else if (operator == '/') {
        result = division(a, b);
        if (b != 0) {  
            printf("%.2f / %.2f = %.2f\n", a, b, result);
        }
    }
    else {
        printf("Invalid operator. Please use +, -, *, or /.\n");
    }

    return 0;
}