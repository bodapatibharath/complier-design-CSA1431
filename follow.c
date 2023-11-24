#include <stdio.h>
#include <ctype.h>

typedef enum {
    IDENTIFIER,
    OPERATOR,
    CONSTANT,
    INVALID
} TokenType;

TokenType classifyToken(const char *token) {
    if (isalpha(token[0]) || token[0] == '_') {
        return IDENTIFIER;
    } else if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
        return CONSTANT;
    } else if (strchr("+-*/=<>!&|", token[0]) != NULL) {
        return OPERATOR;
    } else {
        return INVALID;
    }
}

void printToken(TokenType type, const char *value) {
    const char *typeStrings[] = {"IDENTIFIER", "OPERATOR", "CONSTANT", "INVALID"};
    printf("Type: %s, Value: %s\n", typeStrings[type], value);
}
void tokenize(const char *input) {
    char buffer[100];
    int bufferIndex = 0;

    for (int i = 0; input[i] != '\0'; ++i) {
        if (isspace(input[i]) || strchr("+-*/=<>!&|", input[i]) != NULL) {
            if (bufferIndex > 0) {
                buffer[bufferIndex] = '\0'; 
                TokenType tokenType = classifyToken(buffer);
                printToken(tokenType, buffer);
                bufferIndex = 0;
            }
        } else {
            buffer[bufferIndex++] = input[i];
        }
    }
}

int main() {
    const char *input = "int main() { x = 10 + y; return -42; }";
    tokenize(input);

    return 0;
}
