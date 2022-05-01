#ifndef dk12_tool_h
#define dk12_tool_h

#include <stdio.h>

typedef struct tagListElement ListElement;
struct tagListElement {
	ListElement *next;
	double value;
};

ListElement *createListElement(double value);
void deleteListElement(ListElement *element);
void printListElement(ListElement *element);

typedef struct tagDoubleList {
	ListElement *head;
} DoubleList;

DoubleList *createDoubleList(void);
void deleteDoubleList(DoubleList *list);

void printDoubleList(DoubleList *list);

long countOfDoubleList(DoubleList *list);

int addValueToDoubleList(DoubleList *list, double value);
void removeFirstElementFromDoubleList(DoubleList *list);
void removeLastElementFromDoubleList(DoubleList *list);


int insertElementToDoubleListAtIndex(DoubleList *list, int index, double value);
int removeElementFromDoubleListAtIndex(DoubleList *list, int index);


#endif