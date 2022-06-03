#ifndef DK_TOOL_H
#define DK_TOOL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct intNode Node;
typedef struct intNode {
	char value;
	Node* prev;
	Node* next;
}Node;

typedef struct intList {
	int size;
	Node* first;
	Node* last;
}List;

List* createList();
Node* createNodeWithLetter(char letter);
void addEl(List* list, char letter);
void insertEl(List* list, int index, char letter);
void deleteEl(List* list, int index);
void printList(List* list);
void sizeOfList(List* list);
void deleteList(List* list);
Node* NodeAtIndex(List* list, int index);

#endif
