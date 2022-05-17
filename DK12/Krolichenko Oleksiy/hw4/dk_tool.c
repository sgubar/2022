#define _CRT_SECURE_NO_WARNINGS

#include "dk_tool.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

List* createList() {

	List* list = malloc(sizeof(List));
	if (list != NULL) {

		list->size = 0;
		list->first = NULL;
		list->last = NULL;
	}

	return list;
}

Node* createNodeWithLetter(char letter) {

	Node* theNode = malloc(sizeof(Node));

	if (theNode != NULL) {

		theNode->value = letter;
		theNode->prev = NULL;
		theNode->next = NULL;
	}

	return theNode;
}

void addElement(List* list, char letter) {

	if (list != NULL) {

		Node* theNode = createNodeWithLetter(letter);

		if (theNode != NULL) {

			if (list->first == NULL && list->first == list->last) {

				list->first = list->last = theNode;
			}

			else {

				Node* thelast = list->last;
				list->last = theNode;
				thelast->next = theNode;
				theNode->prev = thelast;
			}
			list->size++;
		}
	}
}

void insertElement(List* list, int index, char letter) {

	int theResult = -1;

	if (NULL == list || index >= list->size || index < 0) {
		return theResult;
	}

	Node* theNode = list->first;

	int i = 0;
	do {
		if (i == index) {
			break;
		}
		theNode = theNode->next;
		i++;

	} while (NULL != theNode);

	Node* theNewNode = createNodeWithLetter(letter);

	if (NULL == theNewNode) {
		return theResult;
	}

	Node* theBeforeNode = theNode;

	if (NULL != theBeforeNode->prev) {

		theBeforeNode->prev->next = theNewNode;
		theNewNode->prev = theBeforeNode->prev;
	}

	theNewNode->next = theBeforeNode;
	theBeforeNode->prev = theNewNode;
	list->size++;

	theResult = 0;
	return theResult;
}

void deleteElement(List* list, int index) {

	int i = 0;

	if ((list->first == NULL) || (index >= list->size)) {
		return;
	}

	Node* theNode = list->first, * temp;

	if (index == 0) {

		list->first = list->first->next;
		temp = theNode;
		list->size--;
	}

	else {
		for (i; i < index - 1; ++i) {

			if (theNode != NULL) {
				theNode = theNode->next;
			}
		}
		temp = theNode->next;
		theNode->next = theNode->next->next;

		if (temp == list->last) {
			list->last = theNode;
		}
		list->size--;
	}
	free(temp);
}

void printList(List* list) {

	if (list == NULL) {
		return;
	}

	else {

		Node* theNode = list->first;
		printf("\n");
		do {
			printf("%c ", theNode->value);
			theNode = theNode->next;
		} while (theNode != NULL);
		printf("\n");
	}
}

void sizeOfList(List* list) {

	if (list != NULL) {
		printf("\nРозмір списку: %d \n", list->size);
	}
}

void deleteList(List* list) {

	int i = 0;

	if (list == NULL) {
		return;
	}

	Node* theNode = list->first;

	for (i; i < list->size; i++) {
		if (theNode == NULL) {
			break;
		}

		Node* theNodeToDelete = theNode;
		theNode = theNode->next;
		free(theNodeToDelete);
	}
	free(list);
}

Node* NodeAtIndex(List * thelist, int index) {

	Node* res = NULL;

	if (NULL != thelist && index < thelist->size) {

		int i = 0;
		Node* theNode = thelist->first;

		do {
			if (i == index) {

				res = theNode;
				break;
			}

			theNode = theNode->next;
			i++;
		} while (NULL != theNode);
	}

	return res;
}