#ifndef SINGLE_LIST_H_INCLUDED
#define SINGLE_LIST_H_INCLUDED

#include <stdio.h>

typedef struct tagSingleListFloatElement SingleListFloatElement;

   struct tagSingleListFloatElement{
       SingleListFloatElement  *next;
        float value;


};

SingleListFloatElement *createSingleListFloatElement (float value);
void deleteSingleListFloatElement (SingleListFloatElement *element);
void printSingleListFloatElement(SingleListFloatElement  *element);

typedef struct FloatSingleList {

 SingleListFloatElement *head;
 //long count;

}FloatSingleList;

FloatSingleList *createFloatSingleList(void);
void deleteFloatSingleList(FloatSingleList *list);

void printFloatSingleList(FloatSingleList  *list);

long countOfFloatSingleList(FloatSingleList *list);

//1 - success, 0 - fail
int addFloatValueToSingleList(FloatSingleList *list, float value);
void removeLastElementFromFloatSingleList(FloatSingleList *list);
void removeFirstElementFromFloatSingleList(FloatSingleList *list);

//1 - success, 0 - fail
 int insertIntElementToFloatSingleListAtIndex(FloatSingleList *list, int index, float value);
int removeIntElementFromFloatSingleListAtIndex(FloatSingleList *list, int index);




#endif // SINGLE_LIST_H_INCLUDED
