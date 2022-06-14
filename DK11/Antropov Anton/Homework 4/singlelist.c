#include "singlelist.h"

SingleListIntElement *createSingleListIntElement(int value) {

	SingleListIntElement *result = (SingleListIntElement *)malloc(sizeof(SingleListIntElement));

	if (result != NULL) {
		result->value = value;
		result->next = NULL;
	}

	return result;
}

void deleteSingleListIntElement(SingleListIntElement *element) {

	if (element != NULL) {
		free(element);
	}
}

void printSingleListIntElement(SingleListIntElement *element) {

	if (element != NULL) {
		printf("%d", element->value);
	}
}

IntSingleList *createIntSingleList(void) {

	IntSingleList *result = (IntSingleList *)malloc(sizeof(IntSingleList));

	if (result != NULL) {
		result->head = NULL;
	}

	return result;
}

void deleteIntSingleList(IntSingleList *list) {

	if (list == NULL) {
		return;
	}

	SingleListIntElement *element = list->head;

	while(element != NULL) {
		SingleListIntElement *temp = element->next;

		deleteSingleListIntElement(element);
		element = temp;
	}

	free(list);
}

void printIntSingleList(IntSingleList *list) {

	if (list == NULL) {
		return;
	}

	printf("[");

	for(SingleListIntElement *element = list->head; element != NULL; element = element->next) {

		printSingleListIntElement(element);

		if (element->next != NULL) {
			printf(",");
		}
	}

	printf("]\n");
}

long countOfIntSingleList(IntSingleList *list) {
	if (list == NULL) {
 		return 0;
	}

	long count = 0;

	for (SingleListIntElement *element = list->head; element != NULL; element = element->next, count ++);

	return count;
}

int addIntValueToIntSingleList(IntSingleList *list, int value) {
	if (list == NULL) {
 		return 0;
	}

	SingleListIntElement *element = createSingleListIntElement(value);
	if (element == NULL) {
		return 0;
	}

	if (list->head == NULL) {
		list->head = element;
		return 1;
	}

	SingleListIntElement *tail = list->head;

	while(tail->next != NULL) {
		tail = tail->next;
	}

	tail->next = element;
	return 1;
}

void removeLastElementFromIntSingleList(IntSingleList *list) {
	if (list == NULL) {
 		return;
	}

	if (list->head == NULL) {
		return;
	}

	SingleListIntElement *element = list->head;

	if (element->next == NULL) {
		list->head = NULL;
		deleteSingleListIntElement(element);
		return;
	}

	while(element->next != NULL && element->next->next != NULL) {
		element = element->next;
	}
	deleteSingleListIntElement(element->next);
	element->next = NULL;
}

void removeFirstElementFromIntSingleList(IntSingleList *list) {
	if (list == NULL) {
 		return;
	}

	if (list->head == NULL) {
		return;
	}

	SingleListIntElement *element = list->head->next;

	deleteSingleListIntElement(list->head);

	list->head = element;
}

int insertIntElementToIntSingleListAtIndex(IntSingleList *list, int index, int value) {

	if (list == NULL) {
 		return 0;
	}

	long count = countOfIntSingleList(list);

	if (count == index) {
		return addIntValueToIntSingleList(list, value);
	}

	SingleListIntElement *element = createSingleListIntElement(value);
	if (element == NULL) {
		return 0;
	}

	if (index == 0) {
		element->next = list->head;
		list->head = element;
	} else {
		int current = 0;
		SingleListIntElement *ex_element = list->head;
		for (; ex_element != NULL && current < index - 1; ex_element = ex_element->next, current ++);

		element->next = ex_element->next;
		ex_element->next = element;
	}

	return 1;
}

int removeIntElementFromIntSingleListAtIndex(IntSingleList *list, int index) {
	if (list == NULL) {
 		return 0;
	}

	long count = countOfIntSingleList(list);
	if (index >= count) {
		return 0;
	}

	if (index == 0) {
		removeFirstElementFromIntSingleList(list);
		return 1;
	} else if (index == (count - 1)) {
		removeLastElementFromIntSingleList(list);
		return 1;
	} else {
		int current = 0;
		SingleListIntElement *ex_element = list->head;
		for (; ex_element != NULL && current < index - 1; ex_element = ex_element->next, current ++);

		SingleListIntElement *to_delete = ex_element->next;
		ex_element->next = to_delete->next;
		deleteSingleListIntElement(to_delete);
	}

	return 1;
}
