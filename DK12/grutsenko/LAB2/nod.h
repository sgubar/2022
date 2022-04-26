#ifndef NOD_H
#define NOD_H

typedef struct node {
    struct node *prev;
    char *symbol;
    struct node *next;
} Node;

void printPrompt(void);

Node *createNode(Node *prev, char *s);

int openingBracket(char *symbol);
int closingBracket(char *symbol);

int correctClosingBracket(Node *n, char *s);

void notBalanced(void);
void balanced(void);

#endif
