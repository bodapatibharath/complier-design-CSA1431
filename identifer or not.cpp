#include <stdio.h>
#include <ctype.h>

int isValidIdentifier(const char *s) {
    // Check if the first character is a letter or underscore
    if (!(isalpha(s[0]) || s[0] == '_')) {
        return 0; // Not a valid identifier
    }

    // Check the rest of the characters
    for (int i = 1; s[i] != '\0'; i++) {
        if (!(isalnum(s[i]) || s[i] == '_')) {
            return 0; // Not a valid identifier
        }
    }

    return 1; // Valid identifier
}

int main() {
    // Example usage:
    const char *identifier = "469465";
    if (isValidIdentifier(identifier)) {
        printf("%s is a valid identifier.\n", identifier);
    } else {
        printf("%s is not a valid identifier.\n", identifier);
    }

    return 0;
}

