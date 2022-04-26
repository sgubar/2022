#include <stdlib.h>
#include <stdio.h>

#include "list.h"

Node node_create(int value)
{
	Node tmp = (struct node*) malloc(sizeof(struct node)); 
	tmp->value = value;
	tmp->next = NULL;
	return tmp;
}

void node_destroy(Node nd)
{
	free(nd);
}

List list_create(void)
{
	List tmp = (struct list*) malloc(sizeof(struct list));
	tmp->head = NULL;
	tmp->tail = NULL;
	return tmp;
}

void list_destroy(List ls)
{
	Node tmp = NULL;
	while(ls->head != NULL) {
		tmp = ls->head;
		ls->head = ls->head->next; // Move head pointer to the next node.
		node_destroy(tmp);
	}
	free(ls); // Free the list structure itself.
}

void list_add_node(List ls, int value)
{
	/* List is empty */
	if(ls->head == NULL) {
		ls->head = node_create(value);
		ls->tail = ls->head;
		return;
	}

	Node curr = ls->head;
	while(curr->next != NULL) curr = curr->next; 	// Move curr to the last node.
	curr->next = node_create(value);		// When curr points to the last element, add a new node.
	ls->tail = curr->next;				// Tail now points to the newly created node.
}

void list_add_node_tail(List ls, int value)
{
	/* List is empty */
	if(ls->head == NULL) {
		ls->head = node_create(value);
		ls->tail = ls->head;
		return;
	}

	ls->tail->next = node_create(value);
	ls->tail = ls->tail->next; // Move tail to the newly created node.
}

void list_add_node_head(List ls, int value)
{
	/* List is empty */
	if(ls->head == NULL) {
		ls->head = node_create(value);
		ls->tail = ls->head;
		return;
	}	

	Node tmp = node_create(value);
	tmp->next = ls->head;		// Link newly created node to the beginning of the list.
	ls->head = tmp;			// Move the head pointer to the first node.
}

void list_sort_ascend(List ls)
{
	Node p1 = ls->head;
	Node p2 = ls->head->next;

	int tmp = 0;

	_Bool onemore = 0;

	while(p2 != NULL) {
		if(p1->value > p2->value) {
			onemore = 1;
			tmp = p1->value;
			p1->value = p2->value;
			p2->value = tmp;
		}
		p1 = p1->next;
		p2 = p2->next;
		if(p2 == NULL && onemore) {
			p1 = ls->head;
			p2 = ls->head->next;
			onemore = 0;
		}
	}
}

void list_sort_descend(List ls)
{
	Node p1 = ls->head;
	Node p2 = ls->head->next;

	int tmp = 0;

	_Bool onemore = 0;

	while(p2 != NULL) {
		if(p1->value < p2->value) {
			onemore = 1;
			tmp = p1->value;
			p1->value = p2->value;
			p2->value = tmp;
		}
		p1 = p1->next;
		p2 = p2->next;
		if(p2 == NULL && onemore) {
			p1 = ls->head;
			p2 = ls->head->next;
			onemore = 0;
		}
	}
}

void list_print(List ls)
{
	if(ls->head == NULL) {
		printf("[EMPTY]\n");
		return;
	}

	Node curr = ls->head;
	while(curr != NULL) {
		printf("%d ", curr->value);
		curr = curr->next;
		if(curr != NULL) printf("=> ");
	}
	printf("\n");
}
