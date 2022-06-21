#ifndef list_h
#define list_h

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
	struct Node *next;
}Node;


typedef struct IntSingleList {
	Node *head;
}IntSingleList;

Node *createSingleListIntElement(int value);
void deleteSingleListIntElement(Node *element);
void printSingleListIntElement(Node *element);

IntSingleList *createIntSingleList(void);
void deleteIntSingleList(IntSingleList *list);

void printIntSingleList(IntSingleList *list);

long countOfIntSingleList(IntSingleList *list);

int addIntValueToIntSingleList(IntSingleList *list, int value);
void removeLastElementFromIntSingleList(IntSingleList *list);
void removeFirstElementFromIntSingleList(IntSingleList *list);
int removeIntElementsLessThanAverageValue(IntSingleList *list, int MNumber);
int averageValueOfIntSingleList(IntSingleList *list);
IntSingleList *getIntElementToIntSingleList();

int insertIntElementToIntSingleListAtIndex(IntSingleList *list, int index, int value);

int removeIntElementFromIntSingleListAtIndex(IntSingleList *list, int index);

#endif // LIST_H_INCLUDED

