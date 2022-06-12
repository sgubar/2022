#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "dk_tool.h"
#include <conio.h>
#define MAX_VALUE 15

int main()
{
	int array[MAX_VALUE];
	int pos, i;
	char symbol[MAX_VALUE];

	memcpy(array, random(), sizeof(array));

	for (pos = 0; pos < MAX_VALUE; pos++) {
		symbol[pos] = array[pos];
		printf("%c", symbol[pos]);
	}

	CharList* theList = SLCreateList();

	printf("\n=>\n");

	printf("\n<=\n");
	doPrintSLListConversely(theList);

	printf("\n=>\n");
	doPrintSLList(theList);

	printf("\n<=\n");
	doPrintSLListConversely(theList);

	SLFreeList(theList);

	return 0;
}
