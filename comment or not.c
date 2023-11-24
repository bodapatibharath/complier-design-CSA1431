#include <stdio.h>
#include <string.h>

int isComment(const char *str) {
    
    if (strncmp(str, "//", 2) == 0) {
        return 1;  
        
    }

    
    if (strncmp(str, "/*", 2) == 0) {
        return 1;
    }

    return 0; 
}

int main() {
    char input[100];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    if (isComment(input)) {
        printf("The given string is a comment.\n");
    } else {
        printf("The given string is not a comment.\n");
    }

    return 0;
}
