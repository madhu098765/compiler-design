#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_IDENTIFIER_LENGTH 32

void analyze(const char *input) {
    char identifier[MAX_IDENTIFIER_LENGTH];
    int i = 0, j = 0;

    while (input[i] != '\0') {
        // Ignore spaces, tabs, and new lines
        if (isspace(input[i])) {
            i++;
            continue;
        }

        // Ignore comments
        if (input[i] == '/' && input[i + 1] == '/') {
            break; // Ignore everything after //
        }

        // Identify identifiers
        if (isalpha(input[i]) || input[i] == '_') {
            j = 0;
            while (isalnum(input[i]) || input[i] == '_') {
                if (j < MAX_IDENTIFIER_LENGTH - 1) {
                    identifier[j++] = input[i];
                }
                i++;
            }
            identifier[j] = '\0';
            printf("Identifier: %s\n", identifier);
            continue;
        }

        // Identify constants
        if (isdigit(input[i])) {
            j = 0;
            while (isdigit(input[i])) {
                if (j < MAX_IDENTIFIER_LENGTH - 1) {
                    identifier[j++] = input[i];
                }
                i++;
            }
            identifier[j] = '\0';
            printf("Constant: %s\n", identifier);
            continue;
        }

        // Identify operators
        if (strchr("+-*/=<>!", input[i])) {
            printf("Operator: %c\n", input[i]);
            i++;
            continue;
        }

        i++;
    }
}

int main() {
    const char *code = "int main() { // This is a comment\n int a = 5;\n return a; }";
    analyze(code);
    return 0;
}
