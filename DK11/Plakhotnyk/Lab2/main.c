#include <stdio.h>
#include "dk_tool.h"

int main()
{
    List *list = createList();

    FILE *fp;
    fp = fopen("check_file.c", "r+");

    if (fp == NULL)
    {
        printf("Error open file\n");
        return 0;
    }

    char val;
    while ((val = getc(fp)) != EOF)
    {
        addValueToList(list, val);
    }

    fclose(fp);
    searchBracket(list);
    deleteList(list);

    return 1;
}
