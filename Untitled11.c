az#include <stdio.h>

int main() {
    int a = 10, b = 5, c = 2;
    int result;

    
    result = a + b * c; 
    printf("Result of a + b * c: %d\n", result); 

    result = (a + b) * c; 
    printf("Result of (a + b) * c: %d\n", result); 

    result = a - b + c; 
    printf("Result of a - b + c: %d\n", result); 

    return 0;
}

