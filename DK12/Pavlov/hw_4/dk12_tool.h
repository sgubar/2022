#ifndef dk12_tool_h
#define dk12_tool_h

#include <stdio.h>

typedef struct tagListElement ListElement;
struct tagListElement {
	ListElement *next;
	int value;
};

ListElement *createListElement(int value);
void deleteListElement(ListElement *element);
void printListElement(ListElement *element);

typedef struct tagintList {
	ListElement *head;
} intList;

intList *createintList(void);
void deleteintList(intList *list);

void printintList(intList *list);

long countOfintList(intList *list);

int addValueTointList(intList *list, int value);
void removeFirstElementFromintList(intList *list);
void removeLastElementFromintList(intList *list);


int insertElementTointListAtIndex(intList *list, int index, int value);
int removeElementFromintListAtIndex(intList *list, int index);


#endif