#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

typedef struct node {
	int val;
	struct node* next;
}List;

List* addElement(List* lst, int number);
List* input(int* listSize);
List* init(int i);

void destroyList(List* head);
void swapNodes(List* node1, List* node2);
void printList(List* myList);

#endif 

