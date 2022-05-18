#define _CRT_SECURE_NO_WARNINGS

#include "dk_tool.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	List* myList = createList();

	int i1 = 0;
	int i2 = 1;

	char v1 = 'A';
	char v2 = 'B';
	char v3 = 'C';

	addEl(myList, v1);
	addEl(myList, v2); 
	insertEl(myList, i2, v3); 
	deleteEl(myList, i1); 
	printList(myList);
	sizeOfList(myList);
	deleteList(myList);
}
