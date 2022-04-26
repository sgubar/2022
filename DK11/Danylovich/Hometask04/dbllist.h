#ifndef dbllist_h
#define dbllist_h

#include <stdio.h>

typedef struct tag_Node{
    int value;
	struct tag_Node *next;
    struct tag_Node *prev;
}Node;

typedef struct tag_IntDblList{
	Node *head;
    Node *tail;
}IntDblList;


Node *createDblListIntElement(int value);
void deleteDblListIntElement(Node *element);
void printDblListIntElement(Node *element);

IntDblList *createIntDblList(void);
void deleteIntDblList(IntDblList *list);

void printIntDblListFromHead(IntDblList *list);

long countOfIntSingleList(IntDblList *list);

int addIntValueToIntDblList(IntDblList *list, int value);
void removeLastElementFromIntDblList(IntDblList *list);
void removeFirstElementFromIntDblList(IntDblList *list);


int insertIntElementToIntDblListAtIndex(IntDblList *list, int index, int value);

int removeIntElementFromIntDblListAtIndex(IntDblList *list, int index);


#endif
