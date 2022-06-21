#ifndef TOOL_H
#define TOOL_H
#include <stdio.h>

typedef struct tagListElement ListElement;
struct tagListElement
{
    ListElement *next;
    float value;
};

ListElement *createListElement(float value);
void deleteListElement(ListElement *element);
void printListElement(ListElement *element);

typedef struct tagList
{
    ListElement *head;
} List;

List *createList(void);
void deleteList(List *list);

void printList(List *list);

long countOfList(List *list);

int addValueToList(List *list, float value);
void removeFirstElementFromList(List *list);
void removeLastElementFromList(List *list);

int insertElementToListAtIndex(List *list, int index, float value);
int removeElementFromListAtIndex(List *list, int index);

#endif