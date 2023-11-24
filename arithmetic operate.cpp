#include <stdio.h>

int main() {
    char arithmeticOperator;
    printf("Enter an operator (+, -, *, /, %%): ");
scanf(" %c", "&operator");
    if (operator == '+' || operator == '-' || operator == '*' || operator == '/' || operator == '%') {
        printf("%c is an arithmetic operator.\n", operator);
    } else {
        printf("%c is not an arithmetic operator.\n", operator);
    }

    return 0;
}

