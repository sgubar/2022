#ifndef singlelist_h
#define singlelist_h

#include <stdio.h>
#include <stdlib.h>

typedef struct SingleListIntElement {
	struct SingleListIntElement *next;
	int value;
}SingleListIntElement;

SingleListIntElement *createSingleListIntElement(int value);
void deleteSingleListIntElement(SingleListIntElement *element);
void printSingleListIntElement(SingleListIntElement *element);

typedef struct tagIntSingleList {
	SingleListIntElement *head;
} IntSingleList;

IntSingleList *createIntSingleList(void);
void deleteIntSingleList(IntSingleList *list);

void printIntSingleList(IntSingleList *list);

long countOfIntSingleList(IntSingleList *list);

int addIntValueToIntSingleList(IntSingleList *list, int value);
void removeLastElementFromIntSingleList(IntSingleList *list);
void removeFirstElementFromIntSingleList(IntSingleList *list);

int insertIntElementToIntSingleListAtIndex(IntSingleList *list, int index, int value);

int removeIntElementFromIntSingleListAtIndex(IntSingleList *list, int index);

#endif

