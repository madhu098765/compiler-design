#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char lookahead;

void match(char expected) {
    if (lookahead == expected) {
        lookahead = getchar();
    } else {
        printf("Syntax error: expected '%c'\n", expected);
        exit(1);
    }
}

void expression();
void term();
void factor();

void expression() {
    term();
    while (lookahead == '+' || lookahead == '-') {
        match(lookahead);
        term();
    }
}

void term() {
    factor();
    while (lookahead == '*' || lookahead == '/') {
        match(lookahead);
        factor();
    }
}

void factor() {
    if (isdigit(lookahead)) {
        match(lookahead);
    } else if (lookahead == '(') {
        match('(');
        expression();
        match(')');
    } else {
        printf("Syntax error: unexpected '%c'\n", lookahead);
        exit(1);
    }
}

int main() {
    lookahead = getchar();
    expression();
    if (lookahead != '\n') {
        printf("Syntax error: unexpected '%c'\n", lookahead);
    } else {
        printf("Input is valid.\n");
    }
    return 0;
}

