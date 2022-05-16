#ifndef signle_list_h
#define signle_list_h

#include <stdio.h>

typedef struct tag_Node{
    int value;
	struct tag_Node *next;
}Node;


typedef struct tag_IntSingleList{
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
int removeIntElementsWhichLessThenMN(IntSingleList *list, int MNumber);
int MNOfIntSingleList(IntSingleList *list);
IntSingleList *getIntElementToIntSingleList();

int insertIntElementToIntSingleListAtIndex(IntSingleList *list, int index, int value);

int removeIntElementFromIntSingleListAtIndex(IntSingleList *list, int index);

#endif 
