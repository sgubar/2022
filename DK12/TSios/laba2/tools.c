#include <stdlib.h>
#include <stdio.h>
#include "tools.h"

Node nodeCreate(int value)
{
    Node tmp = (struct tag_node *)malloc(sizeof(struct tag_node));
    tmp->value = value;
    tmp->next = NULL;
    return tmp;
}

void nodeDestroy(Node node)
{
    free(node);
}

List listCreate(void)
{
    List tmp = (struct tag_list *)malloc(sizeof(struct tag_list));
    tmp->head = NULL;
    tmp->tail = NULL;
    return tmp;
}

void listDestroy(List list)
{
    Node tmp = NULL;
    while (list->head != NULL)
    {
        tmp = list->head;
        list->head = list->head->next;
        nodeDestroy(tmp);
    }
    free(list);
}

void listAddNode(List list, int value)
{
    if (list->head == NULL)
    {
        list->head = nodeCreate(value);
        list->tail = list->head;
        return;
    }

    list->tail->next = nodeCreate(value);
    list->tail = list->tail->next;
}

void listSortAscend(List list)
{
    Node p1 = list->head;
    Node p2 = list->head->next;

    int tmp = 0;

    int onemore = 0;

    while (p2 != NULL)
    {
        if (p1->value > p2->value)
        {
            onemore = 1;
            tmp = p1->value;
            p1->value = p2->value;
            p2->value = tmp;
        }
        p1 = p1->next;
        p2 = p2->next;
        if (p2 == NULL && onemore)
        {
            p1 = list->head;
            p2 = list->head->next;
            onemore = 0;
        }
    }
}

void listPrint(List list)
{
    if (list->head == NULL)
    {
        printf("EMPTY\n");
        return;
    }

    Node curr = list->head;
    while (curr != NULL)
    {
        printf("%d ", curr->value);
        curr = curr->next;
        if (curr != NULL)
            printf("- ");
    }
    printf("\n");
}
