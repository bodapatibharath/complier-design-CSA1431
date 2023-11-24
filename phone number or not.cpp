#include <stdio.h>
#include <ctype.h>

int isPhoneNumber(char *str) {
    int count = 0;

    // Iterate through each character in the string
    while (*str) {
        // Check if the character is a digit
        if (isdigit(*str)) {
            count++;
        }
        // Move to the next character
        str++;
    }

    // Check if the count of digits is 10
    if (count == 10) {
        return 1; // It's a 10-digit phone number
    } else {
        return 0; // It's not a 10-digit phone number
    }
}

int main() {
    char phoneNumber[20]; // Assuming a maximum length of 20 characters for the phone number

    // Get input from the user
    printf("Enter a phone number: ");
    scanf("%s", phoneNumber);

    // Check if it's a 10-digit phone number
    if (isPhoneNumber(phoneNumber)) {
        printf("It's a 10-digit phone number.\n");
    } else {
        printf("It's not a 10-digit phone number.\n");
    }

    return 0;
}

