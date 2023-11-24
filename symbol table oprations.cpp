#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

struct Symbol {
    char name[30];
    int value;
};

struct Symbol symbolTable[MAX_SIZE];
int tableSize = 0;
void insertSymbol(char name[], int value) {
    if (tableSize < MAX_SIZE) {
        strcpy(symbolTable[tableSize].name, name);
        symbolTable[tableSize].value = value;
        tableSize++;
        printf("Symbol '%s' inserted into the table.\n", name);
    } else {
        printf("Error: Symbol table is full. Cannot insert more symbols.\n");
    }
}
int searchSymbol(char name[]) {
    for (int i = 0; i < tableSize; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            return symbolTable[i].value;
        }
    }
    return -1; 
}

int main() {
    
    insertSymbol("x", 10);
    insertSymbol("y", 20);
    char searchName[30];
    printf("Enter the name of the symbol to search: ");
    scanf("%s", searchName);

    int result = searchSymbol(searchName);
    if (result != -1) {
        printf("Value of '%s' is %d.\n", searchName, result);
    } else {
        printf("Symbol '%s' not found in the table.\n", searchName);
    }

    return 0;
}

