#ifndef dk_tool_h
#define dk_tool_h

typedef struct tagListElement ListElement;
struct tagListElement
{
    int value;
    ListElement *prev;
    ListElement *next;
};

typedef struct tagList
{
    ListElement *head;
    ListElement *tail;
} List;

ListElement *createListElement(int value);
void deleteListElement(ListElement *element);
void printListElement(ListElement *element);

List *createList(void);
void deleteList(List *list);
void printList(List *list);
int addValueToList(List *list, int value);

void searchBracket(List *list);

#endif
