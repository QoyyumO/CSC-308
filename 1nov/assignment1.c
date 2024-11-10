#include <stdio.h>

int main() {
    char type;
    printf("Enter the type of input (c for character, f for float, i for integer): ");
    scanf(" %c", &type);

    switch (type) {
        case 'c': {
            char inputedChar;
            printf("Enter a character: ");
            scanf(" %c", &inputedChar);

            printf("ASCII code: %d\n", (int)inputedChar);
            printf("Size of char: %zu bytes\n", sizeof(inputedChar));

            printf("Next four characters in multiples of 3:\n");
            for (int i = 1; i <= 4; i++) {
                char nextChar = inputedChar + (i * 3);
                printf("%c (ASCII: %d) ", nextChar, (int)nextChar);
            }
            printf("\n");
            break;
        }
        case 'f': {
            float inputedFloat;
            printf("Enter a float: ");
            scanf("%f", &inputedFloat);

            printf("Size of float: %zu bytes\n", sizeof(inputedFloat));

            printf("Next four floats in multiples of 3:\n");
            for (int i = 1; i <= 4; i++) {
                float nextFloat = inputedFloat + (i * 3);
                printf("%.2f ", nextFloat);
            }
            printf("\n");
            break;
        }
        case 'i': {
            int inputedInt;
            printf("Enter an integer: ");
            scanf("%d", &inputedInt);

            printf("ASCII code of the integer (if applicable): %d\n", inputedInt);  // Only useful for small integers representing characters
            printf("Size of int: %zu bytes\n", sizeof(inputedInt));

            printf("Next four integers in multiples of 3:\n");
            for (int i = 1; i <= 4; i++) {
                int nextInt = inputedInt + (i * 3);
                printf("%d ", nextInt);
            }
            printf("\n");
            break;
        }
        default:
            printf("Invalid input type.\n");
            break;
    }

    return 0;
}
