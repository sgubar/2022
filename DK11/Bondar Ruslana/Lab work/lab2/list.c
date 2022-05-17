#include "list.h"
#include <stdlib.h>
#include <string.h>

IntListElement* createIntListElement(int value) {
	IntListElement* result = (IntListElement*)malloc(sizeof(IntListElement));

	if (NULL != result) {
		//bzero (result, sizeof(IntListElement));
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
void removeLastElementFromIntList(IntList* list){

if (NULL == list || (list->head == NULL && list->head != list->tail)) {
		return;
	}

	if (NULL == list->head) {
		return;
	}

	if (list->head == list->tail) {
		deleteIntListElement(list->head);
		list->head = NULL;
		list->tail = NULL;
		return;
	}

	IntListElement* toDelete = list->tail;
	list->tail = toDelete->prev;
	list->tail->next = NULL;

	deleteIntListElement(toDelete);
}
void removeFirstElementFromIntList(IntList* list){
if (NULL == list || (list->head == NULL && list->head != list->tail)) {
		return;
	}

	if (NULL == list->head) {
		return;
	}

	if (list->head == list->tail) {
		deleteIntListElement(list->head);
		list->head = list->tail = NULL;
		return;
	}

	IntListElement* toDelete = list->head;
	list->head = toDelete->next;
	list->head->prev = NULL;

	deleteIntListElement(toDelete);
}
long countOfIntList(IntList* list){
if (NULL == list) {
		return 0;
	}
	long count = 0;

	IntListElement* element = list->head;
	for (; element != NULL; element = element->next, count++);

	return count;
}
int removeIntElementFromIntListAtIndex(IntList* list, int index){
if (NULL == list || (list->head == NULL && list->head != list->tail)) {
		return 0;
	}

	long count = countOfIntList(list);
	if (index >= count) {
		return 0;
	}

	if (0 == index) {
		removeFirstElementFromIntList(list);
		return 1;
	}
	else if(index == count - 1){
		removeLastElementFromIntList(list);
		return 1;
	}
	else {
		int current = 0;
		IntListElement* ex_element = list->head;
		for (; ex_element != NULL && current != index;
			ex_element = ex_element->next, current++);

		ex_element->prev->next = ex_element->next;
		ex_element->next->prev = ex_element->prev;

		deleteIntListElement(ex_element);
	}

	return 1;
}
void Search(IntList* list)
{
int a = 0, b = 0, c = 0;
IntListElement* result = list->head;
do
{

		if (result->value == '{') { a++; }
		else if (result->value == '}') { a--; }
		if (result->value == '(') { b++; }
		else if (result->value == ')') { b--; }
		if (result->value == '[') { c++; }
		else if (result->value == ']') { c--; }

	result = result->next;
} while (list->tail != result);

if (a != 0)
{
	printf("FALSE BALANCE\n Bracket '{}' : %d\n", a);
}
else
{
	printf("Balance bracket '{}': true\n");
}

if (b != 0)
{
	printf("FALSE BALANCE\n Bracket '()' : %d\n", b);
}
else
{
	printf("Balance bracket '()': true\n");
}

if (c != 0)
{
	printf("FALSE BALANCE\n Bracket '[]' : %d\n", c);
}
else
{
	printf("Balance bracket '[]': true");
}
}
