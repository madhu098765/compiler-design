#include <stdio.h>

int main() {
    int a = 5, b = 10;
    
    int result1 = a * b + a * b;
    printf("Result without optimization: %d\n", result1);
    
    int common = a * b; 
    int result2 = common + common;
    printf("Result with optimization: %d\n", result2);
    
    return 0;
}

