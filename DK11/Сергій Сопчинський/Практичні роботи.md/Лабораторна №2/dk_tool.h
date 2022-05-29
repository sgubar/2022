#ifndef dk_tool_h
#define dk_tool_h

typedef struct node
{
    struct node *prev;
    char *symbol;
    struct node *next;
}
void printPrompt(void);

Node *createNode(Node *prev, char *s);

int openingdyzhka(char *symbol);
int closingdyzhka(char *symbol);

int correctclosingdyzhka(Node *n, char *s);

void notBalanced(void);
void balanced(void);

#endif
