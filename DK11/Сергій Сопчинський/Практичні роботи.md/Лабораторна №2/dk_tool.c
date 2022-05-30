#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "dk_tool.h"

void printPrompt(void)
{
    printf( "Ваш текст.\n" "Можливі дужки: () [] {}\n");
}
Node *createNode(Node *prev, char *s)
{ 
    Node *n = (Node*)malloc(sizeof(Node));
    n->prev = prev;
    n->symbol = s;
    n->next = NULL;
    return n;
} 

int openingdyzhka (char *symbol)
{
    if(*symbol == '(' || *symbol == '[' || *symbol == '{')
    	return 1;
    else 
	return 0;
}
int closingdyzhka (char *symbol)
{
    if(*symbol == ')' || *symbol == ']' || *symbol == '}')
    	return 1;
    else
	return 0;
}
int correctclosingdyzhka (Node *n, char *s)
{
    if( (*(n->symbol) == '(' && *s == ')') ||  (*(n->symbol) == '[' && *s == ']') ||  (*(n->symbol) == '{' && *s == '}'))
	return 1;
    else 
	notBalanced();
}
void notBalanced(void)
{
    printf("Not balanced\n");
    exit(EXIT_FAILURE);
}
void balanced(void)
{
    printf("Balanced\n");
    exit(EXIT_SUCCESS);
}
