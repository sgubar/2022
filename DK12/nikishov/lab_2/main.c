#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(void)
{
	int input = 0;
	List data = list_create();

	printf("Enter data(q to stop): ");
	while(scanf("%d", &input)) {
		list_add_node_tail(data, input);
		printf("Enter data(q to stop): ");
	}
	printf("List:\n");
	list_print(data);

	printf("Sorted list:\n");
	list_sort_ascend(data);
	list_print(data);

	list_destroy(data);
	return 0;
}
