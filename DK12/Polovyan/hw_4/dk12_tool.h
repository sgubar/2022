#ifndef dk12_tool_h
#define dk12_tool_h
#include <stdio.h>

typedef struct tagListElement ListElement;
struct tagListElement
{
	ListElement *next;
	float value;
};

ListElement *createListElement(float value);
void deleteListElement(ListElement *element);
void printListElement(ListElement *element);

typedef struct tagFloatList
{
	ListElement *head;
} FloatList;

FloatList *createFloatList(void);
void deleteFloatList(FloatList *list);

void printFloatList(FloatList *list);

long countOfFloatList(FloatList *list);

int addValueToFloatList(FloatList *list, float value);
void removeFirstElementFromFloatList(FloatList *list);
void removeLastElementFromFloatList(FloatList *list);

int insertElementToFloatListAtIndex(FloatList *list, int index, float value);
int removeElementFromFloatListAtIndex(FloatList *list, int index);

#endif
