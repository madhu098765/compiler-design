#include <stdio.h>
#include <string.h>

void eliminateLeftRecursion(char *prod) {
    char nonTerminal = prod[0];
    char *alpha = strchr(prod, '>') + 1; // Get the production part
    char *beta = strtok(alpha, "|"); // Split productions

    printf("%c -> %s%c' \n", nonTerminal, beta, nonTerminal);
    printf("%c' -> %s%c' | e\n", nonTerminal, alpha + strlen(beta) + 1, nonTerminal);
}

int main() {
    char production[50];
    printf("Enter a production (e.g., A -> Aa | ß): ");
    fgets(production, sizeof(production), stdin);
    eliminateLeftRecursion(production);
    return 0;
}

