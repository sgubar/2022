#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main() {
	IntList* list = createIntList();
	FILE* fp;
	fopen_s(&fp, "code.c", "r+");
	char z;
	if (fp == NULL) {
		printf("Error. fp == NULL\n");
		return 0;
	}
	while ((z = getc(fp)) != EOF)
	{
		addIntValueToIntList(list, z);
	}

	fclose(fp);

	Search(list);

	deleteIntList(list);

	return 0;
}
