#include <stdio.h>
#include <stdlib.h>
#include "single_list.h"

SingleListElement *createSingleListElement(double value) 
{
    SingleListElement *result = (SingleListElement *)malloc(sizeof(SingleListElement));
    if (NULL != result) 
    {
        result->value = value;
        result->next = NULL;
    }
    return result;
}

void deleteSingleListElement(SingleListElement *element) 
{
    if (NULL != element) 
    {
        free(element);
    }
}

void printSingleListElement(SingleListElement *element) 
{
    if (NULL != element) 
    {
        printf("%f", element->value);
    }
}

DoubleSingleList *createDoubleSingleList(void) 
{
    DoubleSingleList *result = (DoubleSingleList *)malloc(sizeof(DoubleSingleList));
    if (NULL != result) 
    {
        result->head = NULL;
    }
    return result;
}

void deleteDoubleSingleList(DoubleSingleList *list) 
{
    if (NULL == list) 
    {
        return;
    }
    SingleListElement *element = list->head;
    while(NULL != element) 
    {
        SingleListElement *tmp = element->next;
        deleteSingleListElement(element);
        element = tmp;
    }
    free(list);
}

void printDoubleSingleList(DoubleSingleList *list) 
{
    if (NULL == list) 
    {
        printf("Invalid a pointer to the list\n");
        return;
    }
    printf("[");
    for (SingleListElement *element = list->head; element != NULL; element = element->next) 
    {
        printSingleListElement(element);
        if (element->next != NULL) 
        {
            printf(",");
        }
    }
    printf("]\n");
}

long countOfDoubleSingleList(DoubleSingleList *list) 
{
    if (NULL == list) 
    {
        return 0;
    }
    long count = 0;
    for (SingleListElement *element = list->head; element != NULL; element = element->next, count ++);
    return count;
}

int addDoubleValueToSingleList(DoubleSingleList *list, double value) 
{
    if (NULL == list) 
    {
        return 0;
    }
    SingleListElement *element = createSingleListElement(value);
    if (NULL == element) 
    {
        return 0;
    }
    if (NULL == list->head) 
    {
        list->head = element;
        return 1;
    }
    SingleListElement *tail = list->head;
    while(NULL != tail->next) 
    {
        tail = tail->next;
    }
    tail->next = element;
    return 1;
}

void removeLastElementFromDoubleSingleList(DoubleSingleList *list) 
{
    if (NULL == list) 
    {
        return;
    }
    if (NULL == list->head) 
    {
        return;
    }
    SingleListElement *element = list->head;
    if (NULL == element->next) 
    {
        list->head = NULL;
        deleteSingleListElement(element);
        return;
    }
    while(NULL != element->next && NULL != element->next->next) 
    {
        element = element->next;
    }
    deleteSingleListElement(element->next);
    element->next = NULL;
}

void removeFirstElementFromDoubleSingleList(DoubleSingleList *list) 
{
    if (NULL == list) 
    {
        return;
    }
    if (NULL == list->head) 
    {
        return;
    }
    SingleListElement *element = list->head->next;
    deleteSingleListElement(list->head);
    list->head = element;
}

int insertElementToDoubleSingleListAtIndex(DoubleSingleList *list, int index, double value) 
{
    if (NULL == list) 
    {
        return 0;
    }
    long count = countOfDoubleSingleList(list);
    if (count == index) 
    {
        return addDoubleValueToSingleList(list, value);
    }

    SingleListElement *element = createSingleListElement(value);
    if (NULL == element) 
    {
        return 0;
    }
    if (0 == index) 
    {
        element->next = list->head;
        list->head = element;
    } 
    else 
    {
    int current = 0;
    SingleListElement *ex_element = list->head;
    for (; ex_element != NULL && current < index - 1; ex_element = ex_element->next, current ++)
        element->next = ex_element->next;
    ex_element->next = element;
  }

  return 1;
}

int removeElementFromDoubleSingleListAtIndex(DoubleSingleList *list, int index) 
{
    if (NULL == list) 
    {
        return 0;
    }
    
    long count = countOfDoubleSingleList(list);
    if (index >= count) 
    {
        return 0;
    }
    if (0 == index) 
    {
        removeFirstElementFromDoubleSingleList(list);
        return 1;
    } 
    else if (index == (count - 1)) 
    {
        removeLastElementFromDoubleSingleList(list);
        return 1;
    } 
    else 
    {
        int current = 0;
        SingleListElement *ex_element = list->head;
        for (; ex_element != NULL && current < index - 1; ex_element = ex_element->next, current ++)
        {
            SingleListElement *to_delete = ex_element->next;
            ex_element->next = to_delete->next;
            deleteSingleListElement(to_delete);
        }
    } 
    return 1;
}
