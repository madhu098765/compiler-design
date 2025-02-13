#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isValidGrammar(const char *str) {
    int length = strlen(str);
    if (length == 0) return 0; 
    if (!isupper(str[0])) return 0; 
    if (str[length - 1] != '.') return 0; 
    return 1; // Valid grammar
}

int main() {
    const char *input = "Hello, world.";
    if (isValidGrammar(input)) {
        printf("The string 
		satisfies the grammar rules.\n");
    } else {
        printf("The string does not satisfy the grammar rules.\n");
    }
    return 0;
}

