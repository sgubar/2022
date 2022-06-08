#include "dk_tool.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

ListElement *createListElement(int value)
{
    ListElement *result = (ListElement *)malloc(sizeof(ListElement));
    if (NULL != result)
    {
        result->value = value;
        result->next = NULL;
        result->prev = NULL;
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
        printf("%d", element->value);
    }
}

int addValueToList(List *list, int value)
{
    if (NULL == list || (list->head == NULL && list->head != list->tail))
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
        list->tail = list->head;
        return 1;
    }

    list->tail->next = element;
    element->prev = list->tail;
    list->tail = element;

    return 1;
}

List *createList(void)
{
    List *result = (List *)malloc(sizeof(List));

    if (NULL != result)
    {

        memset(result, 0, sizeof(List));
    }
    return result;
}

void deleteList(List *list)
{
    if (NULL == list)
    {
        return;
    }

    ListElement *element = list->head;

    while (list->tail != element)
    {
        ListElement *tmp = element->next;
        deleteListElement(element);
        element = tmp;
    }
    free(list);
}

void searchBracket(List *list)
{

    int a = 0;
    int b = 0;
    int c = 0;

    ListElement *result = list->head;
    do
    {
        if (result->value == '{')
        {
            a++;
        }
        else if (result->value == '}')
        {
            a--;
        }

        if (result->value == '(')
        {
            b++;
        }
        else if (result->value == ')')
        {
            b--;
        }

        if (result->value == '[')
        {
            c++;
        }
        else if (result->value == ']')
        {
            c--;
        }

        result = result->next;
    } while (list->tail != result);

    printf("\n\nBalance bracket '{}': ");
    printf(a != 0 ? "false" : "true");

    printf("\n\nBalance bracket '()': ");
    printf(b != 0 ? "false" : "true");

    printf("\n\nBalance bracket '[]': ");
    printf(c != 0 ? "false" : "true");

    printf("\n\n");
}
