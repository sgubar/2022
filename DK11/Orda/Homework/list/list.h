#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <stdio.h>

typedef struct tag_SingleListElement{
    struct tag_SingleListElement *next;
    float value;
}ListElement;

ListElement *createListElement(float value);
void deletListElement(ListElement *element);

void printListElement(ListElement *elemnt);

typedef struct tag_SingleList{
    ListElement *head;
}SingleList;

SingleList *createSingleList(void);
void deletSingleList(SingleList *list);

void printSingleList(SingleList *list);

long countOfSingleList(SingleList *list);
int addFloatValueToSingleList(SingleList *list, float value);
void removeLastElementFromSingleList(SingleList *list);
void removeFirsElementFromSingleList(SingleList *list);

int insertFloatElementToSingleListByIndex(SingleList *list, float value, int index);
int removetFloatElementToSingleListByIndex(SingleList *list, int index);

#endif // LIST_H_INCLUDED
