#include "tool.h"
#include <stdlib.h>

ListElement *createListElement(double value)
{
    ListElement *result = (ListElement *)malloc(sizeof(ListElement));

    if (NULL != result)
    {
        result->value = value;
        result->next = NULL;
    }

    return result;
}

void deleteListElement(ListElement *element)
{
    if (NULL != element)
    {
        free(element);
    }
}

void printListElement(ListElement *element)
{
    if (NULL != element)
    {
        printf("%.3f", element->value);
    }
}

DoubleList *createDoubleList(void)
{
    DoubleList *result = (DoubleList *)malloc(sizeof(DoubleList));

    if (NULL != result)
    {
        result->head = NULL;
    }

    return result;
}

void deleteDoubleList(DoubleList *list)
{
    if (NULL == list)
    {
        return;
    }

    ListElement *element = list->head;

    while (NULL != element)
    {
        ListElement *tmp = element->next;
        deleteListElement(element);
        element = tmp;
    }

    free(list);
}

void printDoubleList(DoubleList *list)
{

    if (NULL == list)
    {
        printf("Invalid a pointer to the list\n");
        return;
    }

    printf("[");

    for (ListElement *element = list->head; element != NULL; element = element->next)
    {
        printListElement(element);
        if (element->next != NULL)
        {
            printf(",");
        }
    }

    printf("]\n");
}

long countOfDoubleList(DoubleList *list)
{
    if (NULL == list)
    {
        return 0;
    }

    long count = 0;

    for (ListElement *element = list->head; element != NULL; element = element->next, count++)
        ;

    return count;
}

int addValueToDoubleList(DoubleList *list, double value)
{
    if (NULL == list)
    {
        return 0;
    }

    ListElement *element = createListElement(value);
    if (NULL == element)
    {
        return 0;
    }

    if (NULL == list->head)
    {
        list->head = element;
        return 1;
    }

    ListElement *tail = list->head;

    while (NULL != tail->next)
    {
        tail = tail->next;
    }

    tail->next = element;
    return 1;
}

void removeLastElementFromDoubleList(DoubleList *list)
{
    if (NULL == list)
    {
        return;
    }

    if (NULL == list->head)
    {
        return;
    }

    ListElement *element = list->head;

    if (NULL == element->next)
    {
        list->head = NULL;
        deleteListElement(element);
        return;
    }

    while (NULL != element->next && NULL != element->next->next)
    {
        element = element->next;
    }
    deleteListElement(element->next);
    element->next = NULL;
}

void removeFirstElementFromDoubleList(DoubleList *list)
{
    if (NULL == list)
    {
        return;
    }

    if (NULL == list->head)
    {
        return;
    }

    ListElement *element = list->head->next;
    deleteListElement(list->head);
    list->head = element;
}

int insertElementToDoubleListAtIndex(DoubleList *list, int index, double value)
{

    if (NULL == list)
    {
        return 0;
    }

    long count = countOfDoubleList(list);

    if (count == index)
    {
        return addValueToDoubleList(list, value);
    }

    ListElement *element = createListElement(value);
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
        ListElement *ex_element = list->head;
        for (; ex_element != NULL && current < index - 1; ex_element = ex_element->next, current++)
            ;

        element->next = ex_element->next;
        ex_element->next = element;
    }

    return 1;
}

int removeElementFromDoubleListAtIndex(DoubleList *list, int index)
{
    if (NULL == list)
    {
        return 0;
    }

    long count = countOfDoubleList(list);
    if (index >= count)
    {
        return 0;
    }

    if (0 == index)
    {
        removeFirstElementFromDoubleList(list);
        return 1;
    }
    else if (index == (count - 1))
    {
        removeLastElementFromDoubleList(list);
        return 1;
    }
    else
    {
        int current = 0;
        ListElement *ex_element = list->head;
        for (; ex_element != NULL && current < index - 1; ex_element = ex_element->next, current++)
            ;

        ListElement *to_delete = ex_element->next;
        ex_element->next = to_delete->next;
        deleteListElement(to_delete);
    }

    return 1;
}
