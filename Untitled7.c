#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTIONS 10
#define MAX_LENGTH 100

void leftFactor(char productions[MAX_PRODUCTIONS][MAX_LENGTH], int numProductions) {
    char commonPrefix[MAX_LENGTH];
    int i, j, k;

    for (i = 0; i < numProductions; i++) {
        for (j = i + 1; j < numProductions; j++) {
            
            int prefixLength = 0;
            while (productions[i][prefixLength] == productions[j][prefixLength] && 
                   productions[i][prefixLength] != '\0' && 
                   productions[j][prefixLength] != '\0') {
                prefixLength++;
            }

            if (prefixLength > 0) {
                
                strncpy(commonPrefix, productions[i], prefixLength);
                commonPrefix[prefixLength] = '\0';

                
                printf("Left Factored Productions:\n");
                printf("%s -> %s\n", productions[i], commonPrefix);
                printf("%s -> %s\n", productions[j], productions[i] + prefixLength);
                printf("%s' -> %s\n", commonPrefix, productions[j] + prefixLength);
                
                
                strcpy(productions[i], commonPrefix);
                strcpy(productions[j], productions[i] + prefixLength);
                break; 
            }
        }
    }
}

int main() {
    char productions[MAX_PRODUCTIONS][MAX_LENGTH];
    int numProductions, i;

    printf("Enter the number of productions: ");
    scanf("%d", &numProductions);
    getchar();
    printf("Enter the productions (one per line):\n");
    for (i = 0; i < numProductions; i++) {
        fgets(productions[i], MAX_LENGTH, stdin);
        productions[i][strcspn(productions[i], "\n")] = 0; 
    }

    leftFactor(productions, numProductions);

    return 0;
}
