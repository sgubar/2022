#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include "dk_tool.h"
#include <stdlib.h>
#include <stdio.h>

List* createList()
{
	List* list = (List*)malloc(sizeof(List));
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	return list;
}

void deleteList(List* list)
{
	Node* elem = list->head;
	Node* next = NULL;
	while (elem != NULL)
	{
		next = elem->next;
		free(elem);
		elem = next;
	}
	free(list);
}

Node* getNode(List* list, int index) // Get element from list by index
{
	Node* elem = list->head;
	int i = 0;
	while (elem != NULL && i < index)
	{
		elem = elem->next;
		i++;
	}
	return elem;
}

void addElement(List* list, int value) // Add element from the end of the list
{
	Node* elem = (Node*)malloc(sizeof(Node));
	if (elem == NULL)
	{
		return -1;
	}
	elem->value = value;
	elem->next = NULL;
	elem->prev = list->tail;
	if (list->tail != NULL)
	{
		list->tail->next = elem;
	}
	if (list->head == NULL)
	{
		list->head = elem;
	}
	list->tail = elem;
	list->size++;
}

void delElement(List* list) // Delete element from the end of the list
{
	Node* next;
	if (list->tail == NULL)
	{
		return -1;
	}
	next = list->tail;
	list->tail = list->tail->prev;
	if (list->tail != NULL)
	{
		list->tail->next = NULL;
	}
	if (next == list->head)
	{
		list->head = NULL;
	}
	free(next);
	list->size--;
	return 1;
}

void insertElement(List* list, int index, int value) // Insert an element into the list by index. If index >= list size -> add element at the end of the list
{
	Node* elem = NULL;
	Node* ins = (Node*)malloc(sizeof(Node));
	elem = getNode(list, index);
	if (elem == NULL)
	{
		free(ins);
		if (index >= list->size)
		{
			addElement(list, value);
		}
		return -1;
	}
	ins->value = value;
	ins->prev = elem->prev;
	ins->next = elem;
	if (elem->prev != NULL)
	{
		elem->prev->next = ins;
	}
	else
	{
		list->head = ins;
	}
	elem->prev = ins;
	list->size++;
}

void replaceElement(List* list, int index, int value) // Replace element in list by index. If index >= list size -> add element at the end of the list
{
	Node* elem = getNode(list, index);
	if (index < list->size && index >= 0)
	{
		elem->value = value;
	}
	if (index >= list->size)
	{
		addElement(list, value);
	}
	return 1;
}

void printList(List* list)
{
	printf("List size: %d\n", list->size);
	Node* elem = list->head;
	while (elem != NULL)
	{
		printf("\t%d\n", elem->value);
		elem = elem->next;
	}
	printf("\n");
}
