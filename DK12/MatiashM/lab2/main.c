#include <stdio.h>
#include <stdlib.h>
#include "tools.h"

int main(void)
{
	int input = 0;
	List *list = list_create();

	printf("Type number (q to finish): ");
	while(scanf("%d", &input)) {
		list_add_node(list, input);
		printf("Type number(q to finish): ");
	}
	printf("List:\n");
	list_print(list);

	list_sort(list);
    printf("Result:\n");
	list_print(list);

	list_destroy(list);
	return 1;
}
