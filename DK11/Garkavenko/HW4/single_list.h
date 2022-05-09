#ifndef SINGLE_LIST_H_INCLUDED
#define SINGLE_LIST_H_INCLUDED

#include <stdio.h>

typedef struct tagSingleListCharElement SingleListCharElement;

   struct tagSingleListCharElement{
   SingleListCharElement *next;
   char value;
   };
SingleListCharElement *createSingleListCharElement(char value);
void deleteSingleListCharElement(SingleListCharElement *element);
void printSingleListCharElement(SingleListCharElement *element);

typedef struct CharSingleList{
    SingleListCharElement *head;
    //long count
} CharSingleList;

CharSingleList *createCharSingleList(void);
void deleteCharSingleList(CharSingleList *list);

void printCharSingleList(CharSingleList *list);

long countOfCharSingleList(CharSingleList *list);
int addCharValueToSingleList(CharSingleList *list, char value);
void removeLastElementFromCharSingleList(CharSingleList *list);
void removeFirstElementFromCharSingleList(CharSingleList *list);

int insertCharElementToCharSingleListAtIndex(CharSingleList *list,int index, char value);
int removeCharElementToCharSingleListAtIndex(CharSingleList *list, int index);

#endif

