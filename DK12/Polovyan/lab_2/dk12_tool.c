#include "dk12_tool.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//====================================================================//
IntListElement* createIntListElement(int value) {
	IntListElement* result = (IntListElement*)malloc(sizeof(IntListElement));
	if (NULL != result) {
		result->value = value;
		result->next = NULL;
		result->prev = NULL;
	}
	return result;
}

void deleteIntListElement(IntListElement* element) {
	if (NULL != element) {
		free(element);
	}
}

void printIntListElement(IntListElement* element) {
	if (NULL != element) {
		printf("%d", element->value);
	}
}

int addIntValueToIntList(IntList* list, int value) {
	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
		return 0;
	}

	IntListElement* element = createIntListElement(value);
	if (NULL == element) {
		return 0;
	}

	if (NULL == list->head) {
		list->head = element;
		list->tail = list->head;
		return 1;
	}

	list->tail->next = element;
	element->prev = list->tail;
	list->tail = element;

	return 1;
}

IntList* createIntList(void) {
	IntList* result = (IntList*)malloc(sizeof(IntList));

	if (NULL != result) {

		memset(result, 0, sizeof(IntList));
	}
	return result;
}

void deleteIntList(IntList* list) {
	if (NULL == list) {
		return;
	}

	IntListElement* element = list->head;

	while (list->tail != element) {
		IntListElement* tmp = element->next;
		deleteIntListElement(element);
		element = tmp;
	}
	free(list);
}
//====================================================================//

void Search(IntList* list){
	
	int a = 0;		//initialize variables
	int b = 0;
	int c = 0;
	
	IntListElement* result = list->head;
	do{
		if (result->value == '{'){ a++; }        // count the number for the next step
		else if (result->value == '}') { a--; }
		
		if (result->value == '(') { b++; }
		else if (result->value == ')') { b--; }
		
		if (result->value == '[') { c++; }
		else if (result->value == ']') { c--; }
		
		result = result->next;
	}
	while (list->tail != result);

	if (a != 0){
		printf("Balance bracket '{}': false \n\n"); // checking every type of brackets
	}											  // if there is no brackets: balance = true
	else{
		printf("Balance bracket '{}': true\n\n");
	}

	if (b != 0){
		printf("Balance bracket '()': false\n\n");
	}
	else{
		printf("Balance bracket '()': true\n\n");
	}

	if (c != 0){
		printf("Balance bracket '[]': false\n\n");
	}
	else{
		printf("Balance bracket '[]': true\n\n"); 
	}
}
