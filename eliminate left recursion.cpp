#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_PRODUCTIONS 10
#define MAX_PROD_LENGTH 20
void eliminateLeftRecursion(char* nonTerminal, char productions[MAX_PRODUCTIONS][MAX_PROD_LENGTH], int numProductions) {
    char newNonTerminal[MAX_PROD_LENGTH];
    strcpy(newNonTerminal, nonTerminal);
    strcat(newNonTerminal, "'");
    printf("%s -> epsilon | ", newNonTerminal);
    for (int i = 0; i < numProductions; i++) {
        if (productions[i][0] == nonTerminal[0]) {
            printf("%s %s' | ", productions[i] + 1, newNonTerminal);
        } else {
            printf("%s | ", productions[i]);
        }
    }
    printf("epsilon\n");
    printf("%s' -> ", nonTerminal);
    for (int i = 0; i < numProductions; i++) {
        if (productions[i][0] == nonTerminal[0]) {
            printf("%s' %s | ", productions[i] + 1, newNonTerminal);
        }
    }
    printf("epsilon\n");
}

int main() {
    char nonTerminal[MAX_PROD_LENGTH];
    char productions[MAX_PRODUCTIONS][MAX_PROD_LENGTH];
    int numProductions;
    printf("Enter the non-terminal: ");
    scanf("%s", nonTerminal);
    printf("Enter the number of productions: ");
    scanf("%d", &numProductions);
    printf("Enter the productions:\n");
    for (int i = 0; i < numProductions; i++) {
        printf("Production %d: ", i + 1);
        scanf("%s", productions[i]);
    }
     eliminateLeftRecursion(nonTerminal, productions, numProductions);
    return 0;
}

