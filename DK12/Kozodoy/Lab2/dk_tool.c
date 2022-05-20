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

int avgList(List* list)
{
	Node* elem = list->head;
	if (elem == NULL)
	{
		return -1;
	}
	int sum = list->head->value, i = 1, avg = 0;
	while (elem->next != NULL)
	{
		elem = elem->next;
		sum = sum + elem->value;
		i++;
	}
	avg = sum / i;
	printf("Average value: %d\n", avg);
	return avg;
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

void inputElement(List* list)
{
	int value = 1;
	while (value)
	{
		value = 0;
		printf("Enter integer element (0 or letter to exit): ");
		scanf("%d", &value);
		if (value == 0)
		{
			break;
		}
		addElement(list, value);
	}
}

void delAvgElement(List* list)
{
	Node* elem = list->head;
	if (elem == NULL || list->head == list->tail) 
	{
		printf("ERROR!Less than 2 elements in list!\n\n");
		return -1;
	}
	int avg = avgList(list);
	while (elem->next != NULL && elem->value > avg)
	{
		elem = elem->next;
	}
	printf("Removed element: %d\n\n", elem->value);
	if (elem->prev == NULL)
	{
		list->head = elem->next;
		elem->next->prev = elem->prev;
	}
	else if (elem->next == NULL)
	{
		list->tail = elem->prev;
		elem->prev->next = elem->next;
	}
	else
	{
		elem->prev->next = elem->next;
		elem->next->prev = elem->prev;
	}
	list->size--;
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