#ifndef single_list_h
#define single_list_h

#include <stdio.h>
#include <stdlib.h>

typedef struct tagSingleListElement SingleListElement;
struct tagSingleListElement {
  SingleListElement *next;
  double value;
};

SingleListElement *createSingleListElement(double value);
void deleteSingleListElement(SingleListElement *element);
void printSingleListElement(SingleListElement *element);

typedef struct tagDoubleSingleList {
  SingleListElement *head;
} DoubleSingleList;

DoubleSingleList *createDoubleSingleList(void);
void deleteDoubleSingleList(DoubleSingleList *list);

void printDoubleSingleList(DoubleSingleList *list);

long countOfDoubleSingleList(DoubleSingleList *list);

int addDoubleValueToSingleList(DoubleSingleList *list, double value);
void removeFirstElementFromDoubleSingleList(DoubleSingleList *list);
void removeLastElementFromDoubleSingleList(DoubleSingleList *list);

int insertElementToDoubleSingleListAtIndex(DoubleSingleList *list, int index, double value);
int removeElementFromDoubleSingleListAtIndex(DoubleSingleList *list, int index);

#endif
