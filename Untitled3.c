#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_LEN 50
void identifyToken(char *token) 
{
    if (isalpha(token[0]) || token[0] == '_') 
	{
        printf("Identifier: %s\n", token);
    } 
    else if (isdigit(token[0])) 
	{
        printf("Constant: %s\n", token);
    } 
    else if (strchr("+-*/=<>!", token[0])) 
	{
        printf("Operator: %s\n", token);
    }
}
void lexicalAnalyzer(char *code) 
{
    char token[MAX_LEN];
    int index = 0;
    int i = 0;
    
    while (code[i] != '\0') 
	{
        if (isspace(code[i])) 
		{
            i++; 
            continue;
        }
        
        if (code[i] == '/' && code[i+1] == '/') 
		{ 
            while (code[i] != '\n' && code[i] != '\0') i++;
            continue;
        }
        
        if (code[i] == '/' && code[i+1] == '*') 
		{ 
            i += 2;
            while (code[i] != '*' || code[i+1] != '/') i++;
            i += 2;
            continue;
        }
        
        if (isalnum(code[i]) || code[i] == '_') 
		{ 
            index = 0;
            while (isalnum(code[i]) || code[i] == '_') 
			{
                token[index++] = code[i++];
            }
            token[index] = '\0';
            identifyToken(token);
        } 
        else if (strchr("+-*/=<>!", code[i])) 
		{ 
            token[0] = code[i++];
            token[1] = '\0';
            identifyToken(token);
        } 
        else 
		{
            i++; 
        }
    }
}

int main() {
    char code[] = "int x = 10; // This is a comment\nfloat y = 20.5; /* Multi-line\ncomment */ x = x + y;";
    printf("Lexical Analysis:\n");
    lexicalAnalyzer(code);
    return 0;
}
