#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "nod.h"

void printPrompt(void) {
    printf( "Enter text to check brackets balance.\n"
            "Supported brackets: () [] {}\n"
            );
}

Node *createNode(Node *prev, char *s) { 
    Node *n = (Node*)malloc(sizeof(Node));
    n->prev = prev;
    n->symbol = s;
    n->next = NULL;
    return n;
} 

int openingBracket(char *symbol) {
    if(*symbol == '('
    || *symbol == '['
    || *symbol == '{')
    return 1;
    else return 0;
}

int closingBracket(char *symbol) {
    if(*symbol == ')'
    || *symbol == ']'
    || *symbol == '}')
    return 1;
    else return 0;
}

int correctClosingBracket(Node *n, char *s) {
    if( (*(n->symbol) == '(' && *s == ')')
    ||  (*(n->symbol) == '[' && *s == ']')
    ||  (*(n->symbol) == '{' && *s == '}')    
    ) return 1;
    else notBalanced();
}

void notBalanced(void) {
    printf("Not balanced\n");
    exit(EXIT_FAILURE);
}

void balanced(void) {
    printf("Balanced\n");
    exit(EXIT_SUCCESS);
}