#include <stdio.h>

void generateAssembly(const char* ir) {
    printf("Generating assembly code for: %s\n", ir);
    printf("MOV R0, %s\n", ir);
    printf("ADD R0, R0, R1\n");
    printf("STORE R0, result\n");  
}

int main() {
    const char* intermediateRepresentation = "x + y";
    generateAssembly(intermediateRepresentation);
    return 0;
}

