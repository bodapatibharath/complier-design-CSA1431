#include <stdio.h>
#include <ctype.h>
int expression();
int term();
int factor();
char input[100];
int position = 0;

int main() {
    printf("Enter an arithmetic expression: ");
    fgets(input, sizeof(input), stdin);

    int result = expression();

    if (input[position] == '\0') {
        printf("Parsing successful. Result: %d\n", result);
    } else {
        printf("Parsing error.\n");
    }

    return 0;
}
int expression() {
    int result = term();

    while (input[position] == '+' || input[position] == '-') {
        char op = input[position++];
        int nextTerm = term();

        if (op == '+') {
            result += nextTerm;
        } else {
            result -= nextTerm;
        }
    }

    return result;
}

int term() {
    int result = factor();

    while (input[position] == '*' || input[position] == '/') {
        char op = input[position++];
        int nextFactor = factor();

        if (op == '*') {
            result *= nextFactor;
        } else {
            if (nextFactor != 0) {
                result /= nextFactor;
            } else {
                printf("Error: Division by zero.\n");
                return 0;
            }
        }
    }

    return result;
}

int factor() {
    int result;

    if (isdigit(input[position])) {
        sscanf(input + position, "%d", &result);
        while (isdigit(input[position])) {
            position++;
        }
    } else if (input[position] == '(') {
        position++;
        result = expression();
        if (input[position] == ')') {
            position++;
        } else {
            printf("Error: Missing closing parenthesis.\n");
            return 0;
        }
    } else {
        printf("Error: Unexpected character.\n");
        return 0;
    }

    return result;
}

