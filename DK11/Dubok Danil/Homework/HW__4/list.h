#ifndef list_h
#define list_h

#include <stdio.h>

typedef struct Element
{
      int value;
      struct Element *next;
} Element;

typedef struct List
{
      Element *head;
      Element *tail;
} IntList;

Element *createElement(int value);
void deleteElement(Element *element);
void printElement(Element *element);

IntList *createIntList(void);
void deleteIntList(IntList *list);

void printIntList(IntList *list);

long countOfIntList(IntList *list);

void addValueToList(IntList *list, int value);

void insertElementToListAtIndex(IntList *list, int index, int value);


#endif 