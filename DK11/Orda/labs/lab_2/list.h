#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#define CB_MAX   1024
#define WORD_LEN 35

typedef struct tag_element{
    struct tag_element *next;
    char w[WORD_LEN];
    int count;
}CharList, *CharListPtr;

void listFill(CharListPtr* list, char* s);
void deleteList(CharListPtr list);

void displayList(CharListPtr list);
CharListPtr sortList(CharListPtr list);
int maxCount(CharListPtr list);
void displayMaxList(CharListPtr list, int maxCount);

#endif
