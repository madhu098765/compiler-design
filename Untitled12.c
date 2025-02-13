#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generateTAC(char *expression) {
    char temp[10];
    int tempCount = 1;
    char *token = strtok(expression, " ");
    
    while (token != NULL) {
        if (strcmp(token, "+") == 0 || strcmp(token, "-") == 0 || 
            strcmp(token, "*") == 0 || strcmp(token, "/") == 0) {
            sprintf(temp, "t%d", tempCount++);
            printf("%s = %s %s %s\n", temp, token - 2, token, token + 1);
            token += 2; 
        } else {
            token++;
        }
    }
}

int main() {
    char expression[] = "a + b * c - d";
    printf("Three Address Code for the expression '%s':\n", expression);
    generateTAC(expression);
    return 0;
}

