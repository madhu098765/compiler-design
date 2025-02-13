#include <stdio.h>
#include <ctype.h>

void countWhitespaceAndNewlines(const char *input) {
    int whitespaceCount = 0;
    int newlineCount = 0;

    while (*input) {
        if (isspace(*input)) {
            whitespaceCount++;
            if (*input == '\n') {
                newlineCount++;
            }
        }
        input++;
    }

    printf("Total Whitespace Characters: %d\n", whitespaceCount);
    printf("Total Newline Characters: %d\n", newlineCount);
}

int main() {
    const char *text = "Hello World!\nThis is a test.\n";
    countWhitespaceAndNewlines(text);
    return 0;
}

