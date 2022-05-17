#define _CRT_SECURE_NO_WARNINGS
#include "dk_tool.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	List* myList = createList();

	char v1 = 'A';
	char v2 = 'B';
	char v3 = 'C';

	int ind1 = 0;
	int ind2 = 1;
	
	addElement(myList, v1); 
	addElement(myList, v2); // A B
	insertElement(myList, ind2, v3); // A C B
	deleteElement(myList, ind1); // C B
	printList(myList);
	sizeOfList(myList);
	deleteList(myList);
}
