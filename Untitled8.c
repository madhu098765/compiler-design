#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

typedef struct Symbol {
    char name[50];
    int value;
    struct Symbol* next;
} Symbol;

typedef struct SymbolTable {
    Symbol* table[TABLE_SIZE];
} SymbolTable;

unsigned int hash(char* name) {
    unsigned int hash = 0;
    while (*name) {
        hash = (hash << 5) + *name++;
    }
    return hash % TABLE_SIZE;
}

SymbolTable* createSymbolTable() {
    SymbolTable* st = malloc(sizeof(SymbolTable));
    memset(st->table, 0, sizeof(st->table));
    return st;
}

void insert(SymbolTable* st, char* name, int value) {
    unsigned int index = hash(name);
    Symbol* newSymbol = malloc(sizeof(Symbol));
    strcpy(newSymbol->name, name);
    newSymbol->value = value;
    newSymbol->next = st->table[index];
    st->table[index] = newSymbol;
}

Symbol* lookup(SymbolTable* st, char* name) {
    unsigned int index = hash(name);
    Symbol* symbol = st->table[index];
    while (symbol) {
        if (strcmp(symbol->name, name) == 0) {
            return symbol;
        }
        symbol = symbol->next;
    }
    return NULL;
}

void deleteSymbol(SymbolTable* st, char* name) {
    unsigned int index = hash(name);
    Symbol* symbol = st->table[index];
    Symbol* prev = NULL;
    while (symbol) {
        if (strcmp(symbol->name, name) == 0) {
            if (prev) {
                prev->next = symbol->next;
            } else {
                st->table[index] = symbol->next;
            }
            free(symbol);
            return;
        }
        prev = symbol;
        symbol = symbol->next;
    }
}

int main() {
    SymbolTable* st = createSymbolTable();
    insert(st, "x", 10);
    Symbol* found = lookup(st, "x");
    if (found) {
        printf("Found: %s = %d\n", found->name, found->value);
    }
    deleteSymbol(st, "x");
    free(st);
    return 0;
}

