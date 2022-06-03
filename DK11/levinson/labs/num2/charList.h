#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct charListElement Element, *ElementPtr;
struct charListElement
{
    char value;
    ElementPtr next;
    ElementPtr prev;
};

typedef struct charList
{
    ElementPtr first;
    ElementPtr last;
    int length;
} List, *ListPtr;

ListPtr init_list(char* elements);
void free_list(ListPtr list);

void print_list(ListPtr list);
int delete_nth(ListPtr list, int index);
int append_elements(ListPtr list, char* elements);
int insert_elements(ListPtr list, char* element, int index);
int duplicate_element(ListPtr list, char* element);
