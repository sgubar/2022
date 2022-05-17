#ifndef list_h
#define list_h

#include <stdio.h>
#include <stdlib.h>

typedef struct tagIntListElement IntListElement;
struct tagIntListElement {
	double value;
	IntListElement* prev;
	IntListElement* next;
};

IntListElement* createIntListElement(int value);
void deleteIntListElement(IntListElement* element);
void printIntListElement(IntListElement* element);



typedef struct tagIntList {
	IntListElement* head;
	IntListElement* tail;

} IntList;

IntList* createIntList(void);
void deleteIntList(IntList* list);
void printIntList(IntList* list);

int addIntValueToIntList(IntList* list, int value);
void removeLastElementFromIntList(IntList* list);
void removeFirstElementFromIntList(IntList* list);
long countOfIntList(IntList* list);
int removeIntElementFromIntListAtIndex(IntList* list, int index);
void Search(IntList* list);
#endif
