#include <stdio.h>
#include <string.h>

void checkComment(const char *line) {
    // Check for single-line comment
    if (strstr(line, "//") != NULL) {
        printf("Single-line comment detected: %s\n", line);
    }
    // Check for multi-line comment
    else if (strstr(line, "/*") != NULL && strstr(line, "*/") != NULL) {
        printf("Multi-line comment detected: %s\n", line);
    }
    else if (strstr(line, "/*") != NULL) {
        printf("Start of multi-line comment detected: %s\n", line);
    }
    else if (strstr(line, "*/") != NULL) {
        printf("End of multi-line comment detected: %s\n", line);
    }
    else {
        printf("No comment detected: %s\n", line);
    }
}

int main() {
    const char *testLine1 = "This is a test line // with a comment";
    const char *testLine2 = "/* This is a multi-line comment */";
    const char *testLine3 = "int main() { /* Start of comment";
    const char *testLine4 = "End of comment */ return 0; }";

    checkComment(testLine1);
    checkComment(testLine2);
    checkComment(testLine3);
    checkComment(testLine4);

    return 0;
}

