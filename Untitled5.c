#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isValidIdentifier(char *identifier) {
    int len = strlen(identifier);
    
    // Check if the first character is a letter or underscore
    if (!isalpha(identifier[0]) && identifier[0] != '_') {
        return 0; // Invalid identifier
    }
    
    // Declare loop variable outside of the for loop
    int i;
    // Check the remaining characters
    for (i = 1; i < len; i++) {
        if (!isalnum(identifier[i]) && identifier[i] != '_') {
            return 0; // Invalid identifier
        }
    }
    
    return 1; // Valid identifier
}

int main() {
    char identifier[100];
    
    printf("Enter an identifier: ");
    scanf("%s", identifier);
    
    if (isValidIdentifier(identifier)) {
        printf("Valid identifier\n");
    } else {
        printf("Invalid identifier\n");
    }
    
    return 0;
}
