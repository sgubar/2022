#ifndef doublelist_h
#define doublelist_h

#include <stdio.h>

typedef struct tag_Node{
    int value;
	struct tag_Node *next;
    struct tag_Node *previous;
}Node;

typedef struct tag_IntDoubleList{
	Node *head;
    Node *tail;
}IntDoubleList;


Node *createDoubleListIntElement(int value);
void deleteDoubleListIntElement(Node *element);
void printDoubleListIntElement(Node *element);

IntDoubleList *createIntDoubleList(void);
void deleteIntDoubleList(IntDoubleList *list);

void printIntDoubleListFromHead(IntDoubleList *list);

long countOfIntSingleList(IntDoubleList *list);

int addIntValueToIntDoubleList(IntDoubleList *list, int value);
void removeLastElementFromIntDoubleList(IntDoubleList *list);
void removeFirstElementFromIntDoubleList(IntDoubleList *list);

int insertIntElementToIntDoubleListAtIndex(IntDoubleList *list, int index, int value);
int removeIntElementFromIntDoubleListAtIndex(IntDoubleList *list, int index);


#endif
