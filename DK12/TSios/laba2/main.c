#include <stdio.h>
#include <stdlib.h>

#include "tools.h"

int main(void)
{
    int input = 0;
    List data = listCreate();

    printf("Введіть число (q для зупинки): ");
    while (scanf("%d", &input))
    {
        listAddNode(data, input);
        printf("Введіть число (q для зупинки): ");
    }
    
    printf("List:\n");
    listPrint(data);

    printf("Sorted list:\n");
    listSortAscend(data);
    listPrint(data);

    listDestroy(data);
    return 0;
}
